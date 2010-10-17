/*****************************************************************************
*
* Copyright (c) 2000 - 2010, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-442911
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

// ************************************************************************* //
//                       avtStateRecorderIntegralCurve.h                     //
// ************************************************************************* //

#ifndef AVT_STATE_RECORDER_INTEGRAL_CURVE_H
#define AVT_STATE_RECORDER_INTEGRAL_CURVE_H

#include <avtIntegralCurve.h>

// ****************************************************************************
//  Class: avtStateRecorderIntegralCurve
//
//  Purpose:
//      A derived type of avtIntegralCurve.  This class records the state for
//      every step of the integral curve.  As the steps may occur on separate
//      processors, it also contains code to collect the steps and reconstitute 
//      them on the originating processor.
//
//  Programmer: Hank Childs (refactoring of work from others)
//  Creation:   June 4, 2010
//
//  Modifications:
//
//    Hank Childs, Tue Jun  8 09:30:45 CDT 2010
//    Place sequence tracking code from base class into this class.
//
//    Christoph Garth, Tue July 10 17:34:33 PDT 2010
//    Major rewrite around removing avtIVPStep storage.
//
// ****************************************************************************

class IVP_API avtStateRecorderIntegralCurve : public avtIntegralCurve
{
public:

    // Caution: If you modify these flags, also check 
    // historyMask and the *Sample* member functions.
    enum Attribute
    {
        SAMPLE_TIME       = 1,
        SAMPLE_POSITION   = 2,
        SAMPLE_VELOCITY   = 4,
        SAMPLE_VORTICITY  = 8,
        SAMPLE_ARCLENGTH  = 16,
        SAMPLE_SCALAR0    = 32,
        SAMPLE_SCALAR1    = 64,
        SAMPLE_UNUSED     = 128,
    };

    struct Sample
    {
        double    time;
        avtVector position;
        avtVector velocity;
        double    vorticity;
        double    arclength;
        double    scalar0;
        double    scalar1;
    };

    // ----

    avtStateRecorderIntegralCurve( unsigned char mask,
                                   const avtIVPSolver* model, 
                                   Direction dir,
                                   const double& t_start, 
                                   const avtVector &p_start, int ID );

    avtStateRecorderIntegralCurve();
    virtual ~avtStateRecorderIntegralCurve();

    void          SetIntersectionObject(vtkObject *obj);

    virtual void  Serialize(MemStream::Mode mode, MemStream &buff, 
                                avtIVPSolver *solver);
    virtual void  PrepareForSend(void)
                           { serializeFlags |= SERIALIZE_INC_SEQ; };
    virtual bool  SameCurve(avtIntegralCurve *ic);

    static avtIntegralCurve* MergeIntegralCurveSequence(
                              std::vector<avtIntegralCurve *> &v);
    static bool IdSeqCompare(const avtIntegralCurve *slA,
                             const avtIntegralCurve *slB);
    static bool IdRevSeqCompare(const avtIntegralCurve *slA,
                                const avtIntegralCurve *slB);

    typedef std::vector<float>::const_iterator iterator;

    size_t  GetNumberOfSamples() const;
    Sample  GetSample( size_t n ) const;
    

  protected:
    avtStateRecorderIntegralCurve( const avtStateRecorderIntegralCurve& );
    avtStateRecorderIntegralCurve& operator=( const avtStateRecorderIntegralCurve& );
    
    size_t    GetSampleStride() const;

    void      HandleIntersections(const avtIVPStep& step);
    bool      IntersectPlane(const avtVector &p0, const avtVector &p1);

  public:

    unsigned long serializeFlags;
    long          sequenceCnt;


  protected:

    unsigned char      historyMask;
    std::vector<float> history;

    void RecordStep( const avtIVPField* field, 
                     const avtIVPStep& step, 
                     double t );

    virtual void AnalyzeStep( avtIVPStep& step,
                              avtIVPField* field );

    // Intersection points.
    bool   intersectionsSet;
    int    numIntersections;
    double intersectPlaneEq[4];

    double       distance;
    unsigned int numSteps;
};


#endif 


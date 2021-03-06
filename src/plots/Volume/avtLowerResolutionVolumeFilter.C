/*****************************************************************************
*
* Copyright (c) 2000 - 2019, Lawrence Livermore National Security, LLC
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
//                              avtLowerResolutionVolumeFilter.C             //
// ************************************************************************* //

#include <avtLowerResolutionVolumeFilter.h>
#include <vtkDataSet.h>
#include <vtkPointData.h>
#include <vtkFloatArray.h>

#include <StackTimer.h>
#include <PlotInfoAttributes.h>

#include <DebugStream.h>

#include <VolumeFunctions.h>
#include <VolumeRLEFunctions.h>

// ****************************************************************************
//  Method: avtLowerResolutionVolumeFilter constructor
//
//  Programmer: Brad Whitlock
//  Creation:   Thu Dec 18 14:13:27 PST 2008
//
//  Modifications:
//
// ****************************************************************************

avtLowerResolutionVolumeFilter::avtLowerResolutionVolumeFilter() : avtPluginDataTreeIterator()
{
    hist = 0;
    hist_size = 256;
}

// ****************************************************************************
//  Method: avtLowerResolutionVolumeFilter destructor
//
//  Programmer: Brad Whitlock
//  Creation:   Thu Dec 18 14:13:27 PST 2008
//
//  Modifications:
//
// ****************************************************************************

avtLowerResolutionVolumeFilter::~avtLowerResolutionVolumeFilter()
{
    if(hist != 0)
    {
        delete [] hist;
        hist = 0;
    }
}

// ****************************************************************************
//  Method: avtLowerResolutionVolumeFilter::SetAtts
//
//  Purpose:
//      Sets the attributes of the software override filter.
//
//  Arguments:
//      a       The attributes for the filter.
//
//  Programmer: Brad Whitlock
//  Creation:   Thu Dec 18 14:13:27 PST 2008
//
// ****************************************************************************

void
avtLowerResolutionVolumeFilter::SetAtts(const AttributeGroup *a)
{
    VolumeAttributes *v = (VolumeAttributes *)a;
    atts = *v;
}

// ****************************************************************************
// Method: avtLowerResolutionVolumeFilter::CalculateHistograms
//
// Purpose: 
//   Calculates the histogram data that we'll later put into the plot info.
//
// Arguments:
//   ds : The dataset that contains the variables of interest.
//
// Programmer: Brad Whitlock
// Creation:   Fri Dec 19 14:08:43 PST 2008
//
// Modifications:
//   Brad Whitlock, Tue Jan 31 12:08:09 PST 2012
//   Call the SPH version of the gradient for non-rectilinear meshes.
//
//   Brad Whitlock, Wed Jun  6 14:16:06 PDT 2012
//   Skip SPH gradient for 1D transfer functions.
//
// ****************************************************************************

void
avtLowerResolutionVolumeFilter::CalculateHistograms(vtkDataSet *ds)
{
    const char *mName = "avtLowerResolutionVolumeFilter::CalculateHistograms: ";
    vtkDataArray *data = 0, *opac = 0;
    if(VolumeGetScalars(atts, ds, data, opac))
    {
        debug5 << mName << "Computing histograms" << endl;
        int nels = data->GetNumberOfTuples();

        // Get the opacity variable's extents.
        float omin = 0.f, omax = 0.f, osize = 0.f;
        VolumeGetOpacityExtents(atts, opac, omin, omax, osize);
        float ghostval = omax+osize;

        //
        // In this mode, we calculate "gm" so we can do the histogram and then
        // we throw away "gm". It's not that big a deal anymore because the
        // gradient calculation is much faster than it used to be.
        //
        vtkFloatArray *gm = vtkFloatArray::New();
        gm->SetNumberOfTuples(nels);
        gm->SetName("gm");
        if(ds->GetDataObjectType() == VTK_RECTILINEAR_GRID)
        {
            VolumeCalculateGradient(atts, (vtkRectilinearGrid *)ds, opac, 
                                0, // gx
                                0, // gy
                                0, // gz
                                (float *)gm->GetVoidPointer(0),
                                0, // gmn
                                ghostval);
        }
        else
        {
            memset(gm->GetVoidPointer(0), 0, sizeof(float)*nels);
        }

        if(hist == 0)
            delete [] hist;
        hist = new float[hist_size];
        VolumeHistograms(atts, data, gm, hist, hist_size);
        gm->Delete();

        data->Delete();
        opac->Delete();
    }
    else
    {
         debug5 << mName << "Could not get scalars or opacity needed to "
                            "calculate the histogram"
                << endl;
    }
}

// ****************************************************************************
// Method: avtLowerResolutionVolumeFilter::ExecuteData
//
// Purpose: 
//   ds
//
// Arguments:
//   in_dr :   The input data representation.
//
// Returns:    The output data representation.
//
// Note:       This filter assumes that there will only be 1 domain. This is
//             fine because we call it after the resample filter.
// 
// Programmer: Brad Whitlock
// Creation:   Thu Dec 18 14:13:43 PST 2008
//
// Modifications:
//   Brad Whitlock, Mon Aug 20 16:31:01 PDT 2012
//   Get the color variable by passing NULL into VolumeGetScalar.
//
//   Eric Brugger, Tue Aug 19 14:06:17 PDT 2014
//   Modified the class to work with avtDataRepresentation.
//
// ****************************************************************************

avtDataRepresentation *
avtLowerResolutionVolumeFilter::ExecuteData(avtDataRepresentation *in_dr)
{
    StackTimer t("avtLowerResolutionVolumeFilter::ExecuteData");

    //
    // Get the VTK data set.
    //
    vtkDataSet *ds = in_dr->GetDataVTK();

    vtkDataSet *rv = ds;
    // If we're not doing linear scaling then we have to create a copy dataset
    // whose scalars are transformed by the appropriate scaling rule.
    if(atts.GetScaling() != VolumeAttributes::Linear)
    {
        // Get the array that we're "scaling".
        vtkDataArray *src = VolumeGetScalar(ds, NULL);
        if(src == 0)
        {
            EXCEPTION0(ImproperUseException);
        }

        // Create a dataset copy and a new data array that we can store
        // the transformed values in.
        rv = ds->NewInstance();
        rv->ShallowCopy(ds);
        vtkDataArray *dest = src->NewInstance();
        dest->SetNumberOfTuples(src->GetNumberOfTuples());
        dest->SetName(src->GetName());

        // Transform the data.
        if (atts.GetScaling() == VolumeAttributes::Log)
        {
            TRY
            {
                VolumeLogTransform(atts, src, dest);
            }
            CATCH(VisItException)
            {
                dest->Delete();
                rv->Delete();
                RETHROW;
            }
            ENDTRY
        }
        else if (atts.GetScaling() == VolumeAttributes::Skew)
            VolumeSkewTransform(atts, src, dest);

        // Add the new data to the return dataset's point data, replacing
        // the old version.
        rv->GetPointData()->AddArray(dest);
        dest->Delete();
    }

    CalculateHistograms(rv);

    avtDataRepresentation *out_dr = new avtDataRepresentation(rv,
        in_dr->GetDomain(), in_dr->GetLabel());

    if (rv != ds)
        rv->Delete();

    return out_dr;
}

// ****************************************************************************
// Method: avtLowerResolutionVolumeFilter::PostExecute
//
// Purpose: 
//   This method stores the histogram into the contract's plot info atts.
//
// Programmer: Brad Whitlock
// Creation:   Thu Dec 18 14:15:14 PST 2008
//
// Modifications:
//   Brad Whitlock, Fri Jan 16 13:54:49 PST 2009
//   Return early if the histogram data does not exist.
//
// ****************************************************************************

void
avtLowerResolutionVolumeFilter::PostExecute()
{
    StackTimer t("avtLowerResolutionVolumeFilter::PostExecute");

    if(hist == 0)
        return;

    floatVector        h1;
    h1.reserve(hist_size);
    for(int i = 0; i < hist_size; ++i)
        h1.push_back(hist[i]);


    MapNode vhist;
    vhist["histogram_size"] = hist_size;
    vhist["histogram_1d"] = h1;

    GetOutput()->GetInfo().GetAttributes().AddPlotInformation("VolumeHistogram", vhist);
}

// ****************************************************************************
//  Method:  avtLowerResolutionVolumeFilter::FilterUnderstandsTransformedRectMesh
//
//  Purpose:
//    If this filter returns true, this means that it correctly deals
//    with rectilinear grids having an implied transform set in the
//    data attributes.  It can do this conditionally if desired.
//
//  Arguments:
//    none
//
//  Programmer:  Jeremy Meredith
//  Creation:    February 15, 2007
//
// ****************************************************************************

bool
avtLowerResolutionVolumeFilter::FilterUnderstandsTransformedRectMesh()
{
    // The resampling and raycasting algorithms now all understand
    // these kinds of grids, so we can now safely return true.
    return true;
}


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

#ifndef MINMAXINFO_H
#define MINMAXINFO_H
#include <query_exports.h>
#include <AttributeSubject.h>

#include <avtMatrix.h>

#include <string>

// ****************************************************************************
// Class: MinMaxInfo
//
// Purpose:
//    Results storage for MinMaxQuery.
//
// Notes:      Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

class QUERY_API MinMaxInfo : public AttributeSubject
{
    using AttributeSubject::SetValue;
    using AttributeSubject::GetValue;
public:
    // These constructors are for objects of this class
    MinMaxInfo();
    MinMaxInfo(const MinMaxInfo &obj);
protected:
    // These constructors are for objects derived from this class
    MinMaxInfo(private_tmfs_t tmfs);
    MinMaxInfo(const MinMaxInfo &obj, private_tmfs_t tmfs);
public:
    virtual ~MinMaxInfo();

    virtual MinMaxInfo& operator = (const MinMaxInfo &obj);
    virtual bool operator == (const MinMaxInfo &obj) const;
    virtual bool operator != (const MinMaxInfo &obj) const;
private:
    void Init();
    void Copy(const MinMaxInfo &obj);
public:

    virtual const std::string TypeName() const;
    virtual bool CopyAttributes(const AttributeGroup *);
    virtual AttributeSubject *CreateCompatible(const std::string &) const;
    virtual AttributeSubject *NewInstance(bool) const;

    // Property selection methods
    virtual void SelectAll();
    void SelectCoord();
    void SelectType();
    void SelectMatName();

    // Property setting methods
    void SetElementNum(int elementNum_);
    void SetDomain(int domain_);
    void SetValue(double value_);
    void SetCoord(const double *coord_);
    void SetType(const std::string &type_);
    void SetMatName(const std::string &matName_);

    // Property getting methods
    int               GetElementNum() const;
    int               GetDomain() const;
    double            GetValue() const;
    const double      *GetCoord() const;
          double      *GetCoord();
    const std::string &GetType() const;
          std::string &GetType();
    const std::string &GetMatName() const;
          std::string &GetMatName();


    // Keyframing methods
    virtual std::string               GetFieldName(int index) const;
    virtual AttributeGroup::FieldType GetFieldType(int index) const;
    virtual std::string               GetFieldTypeName(int index) const;
    virtual bool                      FieldsEqual(int index, const AttributeGroup *rhs) const;

    // User-defined methods
    void Initialize(const double, const std::string &);
    void TransformCoord(const avtMatrix *trans);
    bool  EquivalentForOutput (const MinMaxInfo &obj) const;

    // IDs that can be used to identify fields in case statements
    enum {
        ID_elementNum = 0,
        ID_domain,
        ID_value,
        ID_coord,
        ID_type,
        ID_matName,
        ID__LAST
    };

private:
    int         elementNum;
    int         domain;
    double      value;
    double      coord[3];
    std::string type;
    std::string matName;

    // Static class format string for type map.
    static const char *TypeMapFormatString;
    static const private_tmfs_t TmfsStruct;
};
#define MINMAXINFO_TMFS "iidDss"

#endif

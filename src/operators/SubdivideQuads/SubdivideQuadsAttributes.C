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

#include <SubdivideQuadsAttributes.h>
#include <DataNode.h>

// ****************************************************************************
// Method: SubdivideQuadsAttributes::SubdivideQuadsAttributes
//
// Purpose: 
//   Init utility for the SubdivideQuadsAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void SubdivideQuadsAttributes::Init()
{
    threshold = 0.500002;
    maxSubdivs = 4;
    fanOutPoints = true;
    doTriangles = false;

    SubdivideQuadsAttributes::SelectAll();
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::SubdivideQuadsAttributes
//
// Purpose: 
//   Copy utility for the SubdivideQuadsAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void SubdivideQuadsAttributes::Copy(const SubdivideQuadsAttributes &obj)
{
    threshold = obj.threshold;
    maxSubdivs = obj.maxSubdivs;
    fanOutPoints = obj.fanOutPoints;
    doTriangles = obj.doTriangles;
    variable = obj.variable;

    SubdivideQuadsAttributes::SelectAll();
}

// Type map format string
const char *SubdivideQuadsAttributes::TypeMapFormatString = SUBDIVIDEQUADSATTRIBUTES_TMFS;
const AttributeGroup::private_tmfs_t SubdivideQuadsAttributes::TmfsStruct = {SUBDIVIDEQUADSATTRIBUTES_TMFS};


// ****************************************************************************
// Method: SubdivideQuadsAttributes::SubdivideQuadsAttributes
//
// Purpose: 
//   Default constructor for the SubdivideQuadsAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

SubdivideQuadsAttributes::SubdivideQuadsAttributes() : 
    AttributeSubject(SubdivideQuadsAttributes::TypeMapFormatString),
    variable("default")
{
    SubdivideQuadsAttributes::Init();
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::SubdivideQuadsAttributes
//
// Purpose: 
//   Constructor for the derived classes of SubdivideQuadsAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

SubdivideQuadsAttributes::SubdivideQuadsAttributes(private_tmfs_t tmfs) : 
    AttributeSubject(tmfs.tmfs),
    variable("default")
{
    SubdivideQuadsAttributes::Init();
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::SubdivideQuadsAttributes
//
// Purpose: 
//   Copy constructor for the SubdivideQuadsAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

SubdivideQuadsAttributes::SubdivideQuadsAttributes(const SubdivideQuadsAttributes &obj) : 
    AttributeSubject(SubdivideQuadsAttributes::TypeMapFormatString)
{
    SubdivideQuadsAttributes::Copy(obj);
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::SubdivideQuadsAttributes
//
// Purpose: 
//   Copy constructor for derived classes of the SubdivideQuadsAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

SubdivideQuadsAttributes::SubdivideQuadsAttributes(const SubdivideQuadsAttributes &obj, private_tmfs_t tmfs) : 
    AttributeSubject(tmfs.tmfs)
{
    SubdivideQuadsAttributes::Copy(obj);
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::~SubdivideQuadsAttributes
//
// Purpose: 
//   Destructor for the SubdivideQuadsAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

SubdivideQuadsAttributes::~SubdivideQuadsAttributes()
{
    // nothing here
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::operator = 
//
// Purpose: 
//   Assignment operator for the SubdivideQuadsAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

SubdivideQuadsAttributes& 
SubdivideQuadsAttributes::operator = (const SubdivideQuadsAttributes &obj)
{
    if (this == &obj) return *this;

    SubdivideQuadsAttributes::Copy(obj);

    return *this;
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::operator == 
//
// Purpose: 
//   Comparison operator == for the SubdivideQuadsAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

bool
SubdivideQuadsAttributes::operator == (const SubdivideQuadsAttributes &obj) const
{
    // Create the return value
    return ((threshold == obj.threshold) &&
            (maxSubdivs == obj.maxSubdivs) &&
            (fanOutPoints == obj.fanOutPoints) &&
            (doTriangles == obj.doTriangles) &&
            (variable == obj.variable));
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::operator != 
//
// Purpose: 
//   Comparison operator != for the SubdivideQuadsAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

bool
SubdivideQuadsAttributes::operator != (const SubdivideQuadsAttributes &obj) const
{
    return !(this->operator == (obj));
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::TypeName
//
// Purpose: 
//   Type name method for the SubdivideQuadsAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

const std::string
SubdivideQuadsAttributes::TypeName() const
{
    return "SubdivideQuadsAttributes";
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::CopyAttributes
//
// Purpose: 
//   CopyAttributes method for the SubdivideQuadsAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

bool
SubdivideQuadsAttributes::CopyAttributes(const AttributeGroup *atts)
{
    if(TypeName() != atts->TypeName())
        return false;

    // Call assignment operator.
    const SubdivideQuadsAttributes *tmp = (const SubdivideQuadsAttributes *)atts;
    *this = *tmp;

    return true;
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::CreateCompatible
//
// Purpose: 
//   CreateCompatible method for the SubdivideQuadsAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

AttributeSubject *
SubdivideQuadsAttributes::CreateCompatible(const std::string &tname) const
{
    AttributeSubject *retval = 0;
    if(TypeName() == tname)
        retval = new SubdivideQuadsAttributes(*this);
    // Other cases could go here too. 

    return retval;
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::NewInstance
//
// Purpose: 
//   NewInstance method for the SubdivideQuadsAttributes class.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

AttributeSubject *
SubdivideQuadsAttributes::NewInstance(bool copy) const
{
    AttributeSubject *retval = 0;
    if(copy)
        retval = new SubdivideQuadsAttributes(*this);
    else
        retval = new SubdivideQuadsAttributes;

    return retval;
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::SelectAll
//
// Purpose: 
//   Selects all attributes.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
SubdivideQuadsAttributes::SelectAll()
{
    Select(ID_threshold,    (void *)&threshold);
    Select(ID_maxSubdivs,   (void *)&maxSubdivs);
    Select(ID_fanOutPoints, (void *)&fanOutPoints);
    Select(ID_doTriangles,  (void *)&doTriangles);
    Select(ID_variable,     (void *)&variable);
}

///////////////////////////////////////////////////////////////////////////////
// Persistence methods
///////////////////////////////////////////////////////////////////////////////

// ****************************************************************************
// Method: SubdivideQuadsAttributes::CreateNode
//
// Purpose: 
//   This method creates a DataNode representation of the object so it can be saved to a config file.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

bool
SubdivideQuadsAttributes::CreateNode(DataNode *parentNode, bool completeSave, bool forceAdd)
{
    if(parentNode == 0)
        return false;

    SubdivideQuadsAttributes defaultObject;
    bool addToParent = false;
    // Create a node for SubdivideQuadsAttributes.
    DataNode *node = new DataNode("SubdivideQuadsAttributes");

    if(completeSave || !FieldsEqual(ID_threshold, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("threshold", threshold));
    }

    if(completeSave || !FieldsEqual(ID_maxSubdivs, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("maxSubdivs", maxSubdivs));
    }

    if(completeSave || !FieldsEqual(ID_fanOutPoints, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("fanOutPoints", fanOutPoints));
    }

    if(completeSave || !FieldsEqual(ID_doTriangles, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("doTriangles", doTriangles));
    }

    if(completeSave || !FieldsEqual(ID_variable, &defaultObject))
    {
        addToParent = true;
        node->AddNode(new DataNode("variable", variable));
    }


    // Add the node to the parent node.
    if(addToParent || forceAdd)
        parentNode->AddNode(node);
    else
        delete node;

    return (addToParent || forceAdd);
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::SetFromNode
//
// Purpose: 
//   This method sets attributes in this object from values in a DataNode representation of the object.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

void
SubdivideQuadsAttributes::SetFromNode(DataNode *parentNode)
{
    if(parentNode == 0)
        return;

    DataNode *searchNode = parentNode->GetNode("SubdivideQuadsAttributes");
    if(searchNode == 0)
        return;

    DataNode *node;
    if((node = searchNode->GetNode("threshold")) != 0)
        SetThreshold(node->AsDouble());
    if((node = searchNode->GetNode("maxSubdivs")) != 0)
        SetMaxSubdivs(node->AsInt());
    if((node = searchNode->GetNode("fanOutPoints")) != 0)
        SetFanOutPoints(node->AsBool());
    if((node = searchNode->GetNode("doTriangles")) != 0)
        SetDoTriangles(node->AsBool());
    if((node = searchNode->GetNode("variable")) != 0)
        SetVariable(node->AsString());
}

///////////////////////////////////////////////////////////////////////////////
// Set property methods
///////////////////////////////////////////////////////////////////////////////

void
SubdivideQuadsAttributes::SetThreshold(double threshold_)
{
    threshold = threshold_;
    Select(ID_threshold, (void *)&threshold);
}

void
SubdivideQuadsAttributes::SetMaxSubdivs(int maxSubdivs_)
{
    maxSubdivs = maxSubdivs_;
    Select(ID_maxSubdivs, (void *)&maxSubdivs);
}

void
SubdivideQuadsAttributes::SetFanOutPoints(bool fanOutPoints_)
{
    fanOutPoints = fanOutPoints_;
    Select(ID_fanOutPoints, (void *)&fanOutPoints);
}

void
SubdivideQuadsAttributes::SetDoTriangles(bool doTriangles_)
{
    doTriangles = doTriangles_;
    Select(ID_doTriangles, (void *)&doTriangles);
}

void
SubdivideQuadsAttributes::SetVariable(const std::string &variable_)
{
    variable = variable_;
    Select(ID_variable, (void *)&variable);
}

///////////////////////////////////////////////////////////////////////////////
// Get property methods
///////////////////////////////////////////////////////////////////////////////

double
SubdivideQuadsAttributes::GetThreshold() const
{
    return threshold;
}

int
SubdivideQuadsAttributes::GetMaxSubdivs() const
{
    return maxSubdivs;
}

bool
SubdivideQuadsAttributes::GetFanOutPoints() const
{
    return fanOutPoints;
}

bool
SubdivideQuadsAttributes::GetDoTriangles() const
{
    return doTriangles;
}

const std::string &
SubdivideQuadsAttributes::GetVariable() const
{
    return variable;
}

std::string &
SubdivideQuadsAttributes::GetVariable()
{
    return variable;
}

///////////////////////////////////////////////////////////////////////////////
// Select property methods
///////////////////////////////////////////////////////////////////////////////

void
SubdivideQuadsAttributes::SelectVariable()
{
    Select(ID_variable, (void *)&variable);
}

///////////////////////////////////////////////////////////////////////////////
// Keyframing methods
///////////////////////////////////////////////////////////////////////////////

// ****************************************************************************
// Method: SubdivideQuadsAttributes::GetFieldName
//
// Purpose: 
//   This method returns the name of a field given its index.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

std::string
SubdivideQuadsAttributes::GetFieldName(int index) const
{
    switch (index)
    {
    case ID_threshold:    return "threshold";
    case ID_maxSubdivs:   return "maxSubdivs";
    case ID_fanOutPoints: return "fanOutPoints";
    case ID_doTriangles:  return "doTriangles";
    case ID_variable:     return "variable";
    default:  return "invalid index";
    }
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::GetFieldType
//
// Purpose: 
//   This method returns the type of a field given its index.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

AttributeGroup::FieldType
SubdivideQuadsAttributes::GetFieldType(int index) const
{
    switch (index)
    {
    case ID_threshold:    return FieldType_double;
    case ID_maxSubdivs:   return FieldType_int;
    case ID_fanOutPoints: return FieldType_bool;
    case ID_doTriangles:  return FieldType_bool;
    case ID_variable:     return FieldType_variablename;
    default:  return FieldType_unknown;
    }
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::GetFieldTypeName
//
// Purpose: 
//   This method returns the name of a field type given its index.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

std::string
SubdivideQuadsAttributes::GetFieldTypeName(int index) const
{
    switch (index)
    {
    case ID_threshold:    return "double";
    case ID_maxSubdivs:   return "int";
    case ID_fanOutPoints: return "bool";
    case ID_doTriangles:  return "bool";
    case ID_variable:     return "variablename";
    default:  return "invalid index";
    }
}

// ****************************************************************************
// Method: SubdivideQuadsAttributes::FieldsEqual
//
// Purpose: 
//   This method compares two fields and return true if they are equal.
//
// Note:       Autogenerated by xml2atts.
//
// Programmer: xml2atts
// Creation:   omitted
//
// Modifications:
//   
// ****************************************************************************

bool
SubdivideQuadsAttributes::FieldsEqual(int index_, const AttributeGroup *rhs) const
{
    const SubdivideQuadsAttributes &obj = *((const SubdivideQuadsAttributes*)rhs);
    bool retval = false;
    switch (index_)
    {
    case ID_threshold:
        {  // new scope
        retval = (threshold == obj.threshold);
        }
        break;
    case ID_maxSubdivs:
        {  // new scope
        retval = (maxSubdivs == obj.maxSubdivs);
        }
        break;
    case ID_fanOutPoints:
        {  // new scope
        retval = (fanOutPoints == obj.fanOutPoints);
        }
        break;
    case ID_doTriangles:
        {  // new scope
        retval = (doTriangles == obj.doTriangles);
        }
        break;
    case ID_variable:
        {  // new scope
        retval = (variable == obj.variable);
        }
        break;
    default: retval = false;
    }

    return retval;
}

///////////////////////////////////////////////////////////////////////////////
// User-defined methods.
///////////////////////////////////////////////////////////////////////////////


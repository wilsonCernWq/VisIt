// ************************************************************************* //
//  File: TransformPluginInfo.h
// ************************************************************************* //

#ifndef TRANSFORM_PLUGIN_INFO_H
#define TRANSFORM_PLUGIN_INFO_H
#include <OperatorPluginInfo.h>
#include <operator_plugin_exports.h>

class TransformAttributes;

// ****************************************************************************
//  Class: TransformPluginInfo
//
//  Purpose:
//    Five classes that provide all the information about an Transform operator
//
//  Programmer: kbonnell -- generated by xml2info
//  Creation:   Tue Sep 9 16:06:12 PST 2003
//
//  Modifications:
//
// ****************************************************************************

class TransformGeneralPluginInfo : public virtual GeneralOperatorPluginInfo
{
  public:
    virtual char *GetName() const;
    virtual char *GetVersion() const;
    virtual char *GetID() const;
};

class TransformCommonPluginInfo : public virtual CommonOperatorPluginInfo, public virtual TransformGeneralPluginInfo
{
  public:
    virtual AttributeSubject *AllocAttributes();
    virtual void CopyAttributes(AttributeSubject *to, AttributeSubject *from);
};

class TransformGUIPluginInfo : public virtual GUIOperatorPluginInfo, public virtual TransformCommonPluginInfo
{
  public:
    virtual const char *GetMenuName() const;
    virtual QvisPostableWindowObserver *CreatePluginWindow(int type,
        AttributeSubject *attr, QvisNotepadArea *notepad);
    virtual const char **XPMIconData() const;
};

class TransformViewerPluginInfo : public virtual ViewerOperatorPluginInfo, public virtual TransformCommonPluginInfo
{
  public:
    virtual AttributeSubject *GetClientAtts();
    virtual AttributeSubject *GetDefaultAtts();
    virtual void SetClientAtts(AttributeSubject *atts);
    virtual void GetClientAtts(AttributeSubject *atts);

    virtual void InitializeOperatorAtts(AttributeSubject *atts,
                                        const ViewerPlot *plot,
                                        const bool fromDefault);
    virtual const char **XPMIconData() const;

    static void InitializeGlobalObjects();
  private:
    static TransformAttributes *defaultAtts;
    static TransformAttributes *clientAtts;
};

class TransformEnginePluginInfo : public virtual EngineOperatorPluginInfo, public virtual TransformCommonPluginInfo
{
  public:
    virtual avtPluginFilter *AllocAvtPluginFilter();
};

class TransformScriptingPluginInfo : public virtual ScriptingOperatorPluginInfo, public virtual TransformCommonPluginInfo
{
  public:
    virtual void InitializePlugin(AttributeSubject *subj, FILE *log);
    virtual void *GetMethodTable(int *nMethods);
    virtual bool TypesMatch(void *pyobject);
    virtual void SetLogging(bool val);
    virtual void SetDefaults(const AttributeSubject *atts);
};

#endif

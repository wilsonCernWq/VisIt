// ************************************************************************* //
//                             VisWindowTypes.h                              
//
//  Modifications:
//    Kathleen Bonnell, Fri Jun 27 16:25:01 PDT 2003  
//    For INTERACTION_MODE, renamed PICK to ZONE_PICK, added NODE_PICK.
//    Removed QUERY_TYPE, no longer needed.
//
// ************************************************************************* //


#ifndef VIS_WINDOW_TYPES_H
#define VIS_WINDOW_TYPES_H

#include <avtVector.h>

typedef enum
{
    NAVIGATE         = 0,
    ZONE_PICK,      /* 1 */
    NODE_PICK,      /* 2 */
    ZOOM,           /* 3 */
    LINEOUT         /* 4 */
}  INTERACTION_MODE;

typedef enum
{
    WINMODE_2D        = 0,
    WINMODE_3D,      /* 1 */
    WINMODE_CURVE,   /* 2 */
    WINMODE_NONE     /* 3 */
}  WINDOW_MODE;

typedef enum {
    CB_START         = 0,
    CB_MIDDLE,      /* 1 */
    CB_END          /* 2 */
}  CB_ENUM;

// Forward declaration.
class VisitInteractiveTool;

typedef void (hotPointCallback)(VisitInteractiveTool *,CB_ENUM,int,int,int,int);

struct HotPoint
{
    avtVector             pt;
    double                radius;
    VisitInteractiveTool *tool;
    hotPointCallback     *callback;
};

// ****************************************************************************
//  Function: ValidMode
//
//  Purpose: Determines if the argument represents a "valid" mode.  A "valid"
//           mode means WINMODE_2D or WINMODE_3D.
//
//  Arguments:
//     mode     The mode to check.
//
//  Returns:    True if a valid mode was specified, false otherwise.
//
//  Programmer: Hank Childs
//  Creation:   June 9, 2000
//
// ****************************************************************************

inline bool
ValidMode(WINDOW_MODE mode)
{
    if (mode == WINMODE_2D || mode == WINMODE_3D || mode == WINMODE_CURVE) 
    {
        return true;
    }

    return false;
}


#endif



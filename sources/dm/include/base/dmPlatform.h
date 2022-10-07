/*
-----------------
 Persistent info
-----------------
 Copyright:: (C) 2022 Dm library. Marat Sungatullin.

.........
License:
.........
 Type:     dmLib licence (GPL with exceptions)
 Location: is in the "LICENSE" file.

......
 Web:
......

 + https://sourceforge.net/projects/dmlib (for questions and help)
 + https://dmlib.sourceforge.io

------
 Desc
------
Purpose: define the OS and compiler related macros.

----------------------
 for developers notes
----------------------
 Author:        Marat Sungatullin
 Created:      2022-10-07
*/
#ifndef DMLIB_PLATFORM_H_INCL
#define DMLIB_PLATFORM_H_INCL

#include "base/dmCompiler.h"

//-----------------------------------------------------------------------------
//#############################################################################
// OS identification --{

//=============================================================================
// Microsoft Windows --{

//-- MS Windows detection in GCC ---------------------------------------------[
#if defined DM_COMPILER_GCC

#   if defined(_WIN32) || defined(__WIN32) || defined(__WIN32__) || defined(WIN32)
#       ifndef DM_OS_MSWINDOWS
/** Defined if compiler is to build a Microsoft Windows software. */
#           define DM_OS_MSWINDOWS 1 // 1 is used as windows OS value in DmLib
#           define DM_OS_MSWINDOWS_STRING "Microsoft Windows"
#       endif // !DM_OS_MSWINDOWS

#       if !defined DM_OS
#           define DM_OS DM_OS_MSWINDOWS
#           define DM_OS_STRING DM_OS_MSWINDOWS_STRING
#       endif

#   endif // GCC standard symbol indicating Windows

#endif // DM_COMPILER_GCC
//----------------------------------------------------------------------------]

#if defined(DM_OS_MSWINDOWS)



#endif // DM_OS_MSWINDOWS

// }-- Microsoft Windows
//=============================================================================

//-- We need some OS. So lets check we have some one. ------------------------[
#if !defined(DM_OS)
#   error "DM: no any OS detected"
#endif // !DM_OS_MSWINDOWS
//----------------------------------------------------------------------------]

// }-- OS identification
//#############################################################################
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//#############################################################################
// Hardware architecture identification --{


// }-- Hardware architecture identification
//#############################################################################
//-----------------------------------------------------------------------------





#endif // DMLIB_PLATFORM_H_INCL


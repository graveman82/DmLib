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
Purpose: compiler-specific macros.

----------------------
 for developers notes
----------------------
 Author:        Marat Sungatullin
 Created:       2022-10-07
*/

#ifndef DMLIB_COMPILER_H_INCL
#define DMLIB_COMPILER_H_INCL
//=============================================================================
// Compiler detection --{

//-- GCC ---------------------------------------------------------------------[
#ifdef __GNUC__
/** DM_COMPILER_GCC defined only if your compiler is GCC.*/
#   define DM_COMPILER_GCC __GNUC__
/** Test for GCC >= (major.minor.pl)
   This macro can be used to test the gcc version like this:
    @code
#    if DM_CHECK_GCC_VERSION(8, 1, 0)
     //   ... we have gcc 8.1.0 or later ...
#    else
     //   ... no gcc at all or gcc < 8.1.0 ...
#    endif
    @endcode
*/
#   define DM_CHECK_GCC_VERSION(major, minor, pl)   \
    (\
        (__GNUC__ > major) ||                       \
        (\
            (__GNUC__ == major) &&                  \
            (\
                (__GNUC_MINOR__ > minor) ||         \
                (\
                    (__GNUC_MINOR__ == minor) &&    \
                    (__GNUC_PATCHLEVEL__ >= pl)     \
                )\
            )\
        )\
    )
//-------------------------------------
// Verify for minimal supported version of gcc
#   if !DM_CHECK_GCC_VERSION(8,1,0)
#       error "DM: minimal supported version of GCC is 8.1.0"
#   endif

#else
    #define DM_CHECK_GCC_VERSION(major, minor, pl)  ((void)0)

#endif // __GNUC__

//----------------------------------------------------------------------------]

// }-- Compiler detection
//=============================================================================

#endif // DMLIB_COMPILER_H_INCL

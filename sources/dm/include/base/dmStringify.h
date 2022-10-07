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
Purpose: .

----------------------
 for developers notes
----------------------
 Author:        Marat Sungatullin
 Created:      2022-10-07
*/

#ifndef DMLIB_STRINGIFY_H_INCL
#define DMLIB_STRINGIFY_H_INCL

/** Stringify tools.
Example of using:
    @code
    #include <stdio.h>
    #include <iostream>
    #include <vector>
    #include <string>
    void WaitKeyAndQuit()
    {
        std::string q;
        std::cout << "Press any key followed Enter to quit..." << std::endl;
        std::cin >> q;
    }

    void Test01();
    int main()
    {
        Test01();
        WaitKeyAndQuit();
        return 0;
    }

    #define DM_CHARTYPE_WIDE
    #define DM_DEBUG_CHARTYPE_WIDE
    #include "base/dmStringify.h"

    #define DUMMY_YEAR 2022
    class Dummy
    {
        Dummy(const char* name) : m_name(name) {}
        std::string m_name;
    };
    void Test01()
    {
        std::vector<Dummy> dummies01;


        wprintf(L"%s\n", DM_STRINGIFY_SIMPLE(dummies01.push_back(Dummy("Pupkin"));));
        wprintf(L"%s\n", DM_STRINGIFY(dummies01.push_back(Dummy("Pupkin")); return DUMMY_YEAR));

        wprintf(L"%s\n", DM_FILE_AND_LINE);
        wprintf(L"%s\n", DM_DEBUG_STRINGIFY(dummies01.push_back(Dummy("Pupkin")); return DUMMY_YEAR));
    }
    @endcode
*/

//-- L concatenators ---------------------------------------------------------[
#define DM_WIDECHAR(expr)       DM_WIDECHAR_(expr)
#define DM_WIDECHAR_(expr)      L ## expr
#define DM_NARROWCHAR(expr)     expr
//----------------------------------------------------------------------------]

//-- Simple stringification for code without macros --------------------------[
#ifdef DM_CHARTYPE_WIDE
#   define DM_STRINGIFY_SIMPLE(expr) L ## #expr
#else
#   define DM_STRINGIFY_SIMPLE(expr) #expr
#endif
//----------------------------------------------------------------------------]

//-- Make a string literal from expression which can include macros ----------[
#define DM_STRINGIFY_INTERNAL(expr, LConcatenatorIfW)     DM_STRINGIFY_INTERNAL_(expr, LConcatenatorIfW)
#define DM_STRINGIFY_INTERNAL_(expr, LConcatenatorIfW) LConcatenatorIfW(#expr)

#ifdef DM_CHARTYPE_WIDE
#   define DM_STRINGIFY(expr)  DM_STRINGIFY_INTERNAL(expr,DM_WIDECHAR)
#else
#   define DM_STRINGIFY(expr)  DM_STRINGIFY_INTERNAL(expr,DM_NARROWCHAR)
#endif
//----------------------------------------------------------------------------]

//-- Debug stringify tools ---------------------------------------------------[
#define DM_FILE_AND_LINE_(LConcatenatorIfW)\
  LConcatenatorIfW(__FILE__) LConcatenatorIfW("[") DM_STRINGIFY_INTERNAL(__LINE__, LConcatenatorIfW) LConcatenatorIfW("]")

#ifdef DM_DEBUG_CHARTYPE_WIDE
#   define DM_FILE_AND_LINE       DM_FILE_AND_LINE_(DM_WIDECHAR)
#   define DM_DEBUG_STRINGIFY(expr)  DM_STRINGIFY_INTERNAL(expr,DM_WIDECHAR)
#else
#   define DM_FILE_AND_LINE       DM_FILE_AND_LINE_(DM_NARROWCHAR)
#   define DM_DEBUG_STRINGIFY(expr)  DM_STRINGIFY_INTERNAL(expr,DM_NARROWCHAR)
#endif
//----------------------------------------------------------------------------]

#endif // DMLIB_STRINGIFY_H_INCL

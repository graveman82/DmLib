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
Purpose: test gcc compiler macro.

----------------------
 for developers notes
----------------------
 Author:        Marat Sungatullin
 Created:      2022-10-07
 Note: include only this file for project build. Any other cpp-files isnot allowed for this test.
*/

#include <stdio.h>
#include <iostream>

#include "base/dmCompiler.h"

void WaitKeyAndQuit()
{
    std::string q;
    std::cout << "Press any key followed Enter to quit..." << std::endl;
    std::cin >> q;
}

int main()
{
#define major 7
#define minor 9
#define pl 0

#if DM_CHECK_GCC_VERSION(major, minor, pl)
    printf("we have gcc %d.%d.%d\n", major, minor, pl);
#else
    printf("we don't have gcc >= %d.%d.%d\n", major, minor, pl);
#endif

    WaitKeyAndQuit();
    return 0;
}

// testDll.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "testDll.h"


// This is an example of an exported variable
TESTDLL_API int ntestDll=0;

// This is an example of an exported function.
TESTDLL_API int fntestDll(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CtestDll::CtestDll()
{
    return;
}

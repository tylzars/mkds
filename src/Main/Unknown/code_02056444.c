#include "Main/Unknown/code_02056444.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/unk_02165000.h"

#pragma thumb on

Unk0205fd2c *func_02056444(void *a) {
    Unk0205fd2c *p;
    p = HeapAlloc(a, 4);
    p->mUnk_00 = FindFileInLoadedArchives(data_0216526c);
    return p;
}

#pragma thumb off

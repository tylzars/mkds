#include "Main/Unknown/code_020cefa0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020cef1c.h"
#include "00/code_02181f98.h"

#pragma thumb on

void func_020cefa0(u32 a) {
    u32 v1;
    v1 = ((u32) HeapAlloc((void *) a, (u32) (((u32) 0x00000130u))));
    *(u32 *) &data_0217b488 = v1;
    func_020cef1c();
}

#pragma thumb off

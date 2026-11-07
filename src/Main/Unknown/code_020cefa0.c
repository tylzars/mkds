#include "Main/Unknown/code_020cefa0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020cef1c.h"
#include "00/code_02181f98.h"

#pragma thumb on

void func_020cefa0(void *heap) {
    u32 allocation;
    allocation = ((u32) HeapAlloc(heap, (0x00000130u)));
    *(u32 *) &data_0217b488 = allocation;
    func_020cef1c();
}

#pragma thumb off

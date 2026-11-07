#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_02036820.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0207a000.h"

#pragma thumb on

void func_020ea55c(void **a, void *b, u32 c) {
    *a = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x74);
    InitShadowModel(*a, b, (u8) c);
}

#pragma thumb off

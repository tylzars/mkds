#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_02036820.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0207a000.h"

#pragma thumb on

void CreateShadowModel(void **slot, void *file, u32 c) {
    *slot = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x74);
    InitShadowModel(*slot, file, (u8) c);
}

#pragma thumb off

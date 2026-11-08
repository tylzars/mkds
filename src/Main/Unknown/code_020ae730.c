#include "Main/Unknown/code_020ae730.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ae754.h"
#include "Main/Unknown/code_02036bec.h"

#pragma optimize_for_size on

#pragma thumb on

void *AllocArrayFromCurrentHeap(s32 count, s32 elementSize) {
    void *memory;

    memory = NULL;
    if (count > 0) {
        memory = HeapAlloc((void *) GetCurrentHeap(), elementSize * count);
    }
    return memory;
}

#pragma thumb off

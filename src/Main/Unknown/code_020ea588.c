#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020e66e4.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020e6000.h"

void func_020ea5b0(Unk020e6488 *a, u32 b, Vec3 *position) {
    Vec3 shiftedPosition;

    if (position != NULL) {
        shiftedPosition.x = position->x >> 4;
        shiftedPosition.y = position->y >> 4;
        shiftedPosition.z = position->z >> 4;
        func_020e6854(a, &shiftedPosition, 1, b);
    } else {
        func_020e6854(a, NULL, 0, b);
    }
}

#pragma thumb on

void CreateNsbmd(void **slot, void *file, void *unused) {
    *slot = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x6c);
    InitNsbmd(*slot, file);
}

#pragma thumb off

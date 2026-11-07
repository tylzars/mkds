#include "Main/Unknown/code_02111118.h"
#include "Main/Unknown/code_0202a360.h"

#include "Main/Unknown/code_02111158.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0211127c.h"
#include "Main/Unknown/code_021112fc.h"

void func_021112fc(u32 arg0) {
    u32 copy = arg0;
    u32 unused;
    data_0217d32c.mUnk_0c = copy;
}

u32 func_0211127c(void) {
    u32 selector;
    u32 result;
    result = 0xffffffff;
    selector = func_0202a360();
    switch (selector) {
        case 0:
            result = 0x43;
            break;
        case 1:
            result = 0x44;
            break;
        case 2:
            result = 0x3f;
            break;
        case 3:
            result = 0x41;
            break;
        case 4:
            result = 0x40;
            break;
        case 5:
            result = 0x3f;
            break;
        case 6:
            result = 0x41;
            break;
        case 7:
            result = 0x40;
    }
    return result;
}

void CreateSeqRowHeap(void *heapMemory, u32 heapSize) {
    data_0217d32c.mUnk_04 = NNS_SndHeapCreate(heapMemory, heapSize);
    data_0217d32c.mUnk_08 = NULL;
}

// Loads the sequences of the row for index a unless that row is already loaded; returns 0 if a load fails.
u32 LoadSeqRowIfChanged(s32 index) {
    Unk0217d32c *state;
    u32 *row;
    NNSSndHeap *savedHeap;
    s32 i;
    savedHeap = data_0217d130;
    state = &data_0217d32c;
    if (index == 4 && (gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableColumn : -1) == 9) {
        row = data_0216cbc0;
    } else {
        row = data_0216cbd8[index];
    }
    if (state->mUnk_08 == row) {
        return 1;
    }
    data_0217d130 = data_0217d32c.mUnk_04;
    NNS_SndHeapClear(state->mUnk_04);
    for (i = 0; i < 6; i++) {
        if (row[i] != 0xff) {
            if (NNS_SndArcLoadSeq(row[i], data_0217d130) == 0) {
                data_0217d130 = savedHeap;
                return 0;
            }
        }
    }
    state->mUnk_00 = index;
    state->mUnk_08 = row;
    data_0217d130 = savedHeap;
    return 1;
}

u32 func_02111144(void) {
    u32 value;
    value = (u32) &data_0217d32c;
    value = *(const u32 *) ((value) + (8));
    value = *(const u32 *) ((value) + (20));
    return value;
}

u32 func_02111118(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    value2 = (u32) &data_0217d328;
    value3 = 0u;
    value1 = (u32) &data_0217d324;
    value0 = (u32) &data_0217d320;
    *(u32 *) ((value2) + (0)) = value3;
    *(u32 *) ((value1) + (0)) = value3;
    *(u32 *) ((value0) + (0)) = value3;
    return value0;
}

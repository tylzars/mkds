#include "Main/Unknown/code_020ffc08.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020ea670.h"

#include "Main/Unknown/code_020ffc4c.h"
#include "Main/Unknown/code_020ffcf8.h"
#include "Main/Unknown/code_020ffd04.h"
#include "Main/Unknown/code_020ffd3c.h"
#include "Main/Unknown/code_020ffd40.h"
#include "Main/Unknown/code_020ffd94.h"
#include "Main/Unknown/code_020ffda0.h"
#include "Main/Unknown/code_020ffdc0.h"
#include "Main/Unknown/code_020ffdc4.h"
#include "Main/Unknown/code_020ffdd4.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0215a000.h"
#include "code_02146cbc.h"

Unk02100004 *func_02100004(void) {
    Unk02100004 *block;

    block = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    {
        Unk02100004 zeroBlock = {0};

        *block = zeroBlock;
    }
    return block;
}

Unk020fffa8 *func_020fffa8(void) {
    Unk020fffa8 *block;

    block = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    data_0217c624 = block;
    *block = data_0215a12c;
    SetUpdateListSlot(&data_0217c624);
    return data_0217c624;
}

Unk020fff4c *func_020fff4c(void) {
    Unk020fff4c *block;

    block = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    data_0217c62c = block;
    *block = data_0215a100;
    func_020d49d8(&data_0217c62c);
    return data_0217c62c;
}

void DrawDram(void *a, Dram *dram, void *c, s32 maxAlpha) {
    MtxFx43 *matrix;
    s32 angleIndex;

    matrix = &dram->mUnk_00.mMatrix;
    angleIndex = (u16) (-(s32) dram->mUnk_a6) >> 4;
    MTX_RotX33_((s32 *) matrix, gPairsByAngle[angleIndex * 2], gPairsByAngle[angleIndex * 2 + 1]);
    matrix->mUnk_00[3].x = dram->mUnk_00.mPos.x >> 4;
    matrix->mUnk_00[3].y = dram->mUnk_00.mPos.y >> 4;
    matrix->mUnk_00[3].z = dram->mUnk_00.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gDram, matrix, &dram->mUnk_00.mScale, maxAlpha);
}

void func_020ffdd4(MapObjectList *list) {
    Unk020f41c4_B *random;
    void **dramObjects;
    Dram *dram;
    u16 *row;
    s32 count, index;
    u16 rowIndex;

    count = list->mMapObjectCount;
    dramObjects = list->mMapObjects;
    for (index = 0; index < count; index++) {
        dram = dramObjects[index];
        if (dram->mUnk_00.mStateMachine.mState != 1) {
            return;
        }
    }
    random = GetMapObjectRandom();
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    rowIndex = ((u64) (u32) (random->mValue >> 32) * 6) >> 32;
    for (index = 0; index < count; index++) {
        dram = dramObjects[index];
        row = (u16 *) data_0215a0a8[rowIndex];
        dram->mUnk_a8 = dram->mUnk_b4[row[index]];
        dram->mUnk_00.mStateMachine.mNextState = 0;
        dram->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void UpdateDram(u32 arg0, u32 dram) {
    u32 value0;
    u32 dramAddress = dram;
    u32 value12;
    value0 = (dramAddress) + (0x80u);
    AdvanceStateMachine((void *) value0);
}

u32 func_020ffdc0(u32 value) {
    return value;
}

void UpdateDramState0(Dram *dram) {
    if (dram->mUnk_00.mStateMachine.mStateFrames > dram->mUnk_a4) {
        dram->mUnk_00.mStateMachine.mNextState = 2;
        dram->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterDramState2(Unk020ffd94 *dram) {
    dram->mUnk_ac = 0x0u;
}

void UpdateDramState2(Dram *dram) {
    dram->mUnk_ac += dram->mUnk_b0;
    dram->mUnk_a6 += (s16) ((s32) (((s64) dram->mUnk_ac * dram->mUnk_a8) >> 12));
    if (dram->mUnk_00.mStateMachine.mStateFrames > dram->mUnk_a0) {
        dram->mUnk_00.mStateMachine.mNextState = 3;
        dram->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u32 func_020ffd3c(u32 value) {
    return value;
}

void UpdateDramState3(Dram *dram) {
    dram->mUnk_a6 += dram->mUnk_a8;
    if (dram->mUnk_a2 == 0) {
        return;
    }
    if (dram->mUnk_00.mStateMachine.mStateFrames > dram->mUnk_a2) {
        dram->mUnk_00.mStateMachine.mNextState = 4;
        dram->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterDramState4(Unk020ffcf8 *dram) {
    dram->mUnk_ac = 0x1000u;
}

void UpdateDramState4(Dram *dram) {
    s16 angleStep;

    dram->mUnk_ac -= dram->mUnk_b0;
    angleStep = (s32) (((s64) dram->mUnk_ac * dram->mUnk_a8) >> 12);
    if (angleStep <= 0x96) {
        angleStep = 0x96;
    }
    dram->mUnk_a6 += angleStep;
    if (dram->mUnk_00.mStateMachine.mStateFrames > dram->mUnk_a0) {
        dram->mUnk_00.mStateMachine.mNextState = 5;
        dram->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterDramState5(Dram *dram) {
    s32 angle;

    angle = dram->mUnk_a6;
    dram->mUnk_bc = 0x1999 - angle % 0x1999;
}

// Raw stores of 1 at +0x90 and +0x92 are mNextState and mNextStateRequested (MapObject +0x80 + 0x10 / 0x12): it asks
// for state 1.
void UpdateDramState5(u32 dram) {
    u32 dramAddress = dram;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 anglePointer;
    s32 compareLeft0;
    s32 zero;
    value1 = *(const u16 *) ((dramAddress) + (166));
    anglePointer = (dramAddress) + (0xa6u);
    value1 = (value1) + (0x96u);
    *(u16 *) ((dramAddress) + (166)) = value1;
    value1 = *(const u32 *) ((dramAddress) + (188));
    value1 = (value1) - (0x96u);
    *(u32 *) ((dramAddress) + (188)) = value1;
    value3 = *(const u32 *) ((dramAddress) + (188));
    compareLeft0 = value3;
    zero = 0u;
    if (compareLeft0 >= zero) {
        return;
    }
    value2 = *(const u16 *) ((anglePointer) + (0));
    value1 = 1u;
    value2 = (value2) + (value3);
    *(u16 *) ((anglePointer) + (0)) = value2;
    *(u16 *) ((dramAddress) + (144)) = value1;
    *(u16 *) ((dramAddress) + (146)) = value1;
}

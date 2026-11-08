#include "Main/Unknown/code_02028d9c.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_0201e000.h"

#include "Main/Unknown/code_0214d000.h"
#include "code_0201ea30.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02027e78.h"

void *func_02028f08(s32 index, Unk0201ea30 *cellLayout) {
    return func_0201ea30(cellLayout, index);
}

#pragma thumb on

void SetKartMenuParamElementOffset(s32 elementIndex, s32 endCellIndex, s32 paramValue, CellFileSet *parts) {
    Unk0201ea84 *startCell = func_02028f08(elementIndex, parts->mCellLayout);
    Unk0201ea84 *endCell = func_02028f08(endCellIndex, parts->mCellLayout);
    parts->mCellTable[elementIndex].mOffsetX = (100 - paramValue) * (endCell->mUnk_00_0 - startCell->mUnk_00_0) / 100;
}

#pragma thumb off

#pragma thumb on

void RefreshKartMenuParamElements(void) {
    int result;
    CellFileSet *parts;
    short *params;
    result = func_020280dc();
    if (result == 0) {
        params = ComputeKartMenuParams(gSelectKart->mKartIndex, gSelectKart->mCharacterIndex);
        parts = (CellFileSet *) &gSelectKart->mSelectKartSParts;
        SetKartMenuParamElementOffset(10, 0x10, *params, parts);
        SetKartMenuParamElementOffset(9, 0xf, params[1], parts);
        SetKartMenuParamElementOffset(8, 0xe, params[2], parts);
        SetKartMenuParamElementOffset(7, 0xd, params[3], parts);
        SetKartMenuParamElementOffset(6, 0xc, params[4], parts);
        SetKartMenuParamElementOffset(5, 0xb, params[5], parts);
    }
}

#pragma thumb off

void func_02028e14(void *destination, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, destination, size);
}

void func_02028e00(void *destination, u32 size) {
    func_02028e14(destination, 0, size);
}

u16 func_02028dd4(void) {
    int index;
    if (data_0217aa00->mUnk_0000 == 2) {
        index = data_0217aa00->mOwnIndex;
    } else {
        index = 0;
    }
    return index;
}

u32 GetParticipantEntryIndex(u32 participantIndex) {
    return (data_0217aa00->mUnk_1e52[participantIndex].mEntryIndex);
}

u32 GetOwnEntryIndex(void) {
    u32 value0;
    value0 = func_02028dd4();
    value0 = GetParticipantEntryIndex(value0);
    return value0;
}

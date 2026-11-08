#include "Main/Unknown/code_02027e78.h"

#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/unk_02174000.h"
#include "registers.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_02128000.h"
#include "Main/Unknown/code_0212b000.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_0202b604.h"

u32 func_0202811c(void) {
    return (data_021759d0->mUnk_20);
}

u16 *func_02028110(void) {
    return (u16 *) 0x27ffc40;
}

u32 func_020280e8(void) {
    if (*func_02028110() == 2) {
        return 1;
    }
    return 0;
}

u32 func_020280dc(void) {
    return func_020280e8();
}

#pragma thumb on

void ReleaseSelectKart(void) {
    int result;
    if ((gSelectKart->mResult == 1) && (result = ((u32) func_0202811c()), result == 2)) {
        ClearSelectReturnDisplayBitOn();
    }
    result = func_020280dc();
    if (result == 0) {
        ClearPaletteBlendPointer();
    } else {
        func_0211f498();
    }
    HeapDestroy(gSelectKart->mHeap);
    *&gSelectKart = NULL;
}

#pragma thumb off

u32 func_02028074(u32 bits) {
    u32 value0 = bits;
    u32 maskedRegister;
    u32 registerAddress;
    registerAddress = 0x4000000u;
    maskedRegister = *(const u32 *) ((registerAddress) + (0));
    maskedRegister = (maskedRegister) & ~(0x1f00u);
    value0 = (maskedRegister) | ((value0 << 8));
    *(u32 *) ((registerAddress) + (0)) = value0;
    return value0;
}

u32 func_02028058(u32 bits) {
    u32 value0 = bits;
    u32 maskedRegister;
    u32 registerAddress;
    registerAddress = 0x4001000u;
    maskedRegister = *(const u32 *) ((registerAddress) + (0));
    maskedRegister = (maskedRegister) & ~(0x1f00u);
    value0 = (maskedRegister) | ((value0 << 8));
    *(u32 *) ((registerAddress) + (0)) = value0;
    return value0;
}

void func_0202802c(u32 offsetX, u32 offsetY) {
    reg_G2S_DB_BG3OFS = (offsetX & 0x1ff) | ((offsetY << 16) & 0x1ff0000);
}

void WriteSubBg3CntBits(u32 bits) {
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | bits;
}

void WriteSubBlendAlpha(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, firstPlane, secondPlane, firstCoefficient, secondCoefficient);
}

u32 func_02027fb8(u32 bits) {
    u32 value0 = bits;
    u32 maskedRegister;
    u32 registerAddress;
    registerAddress = 0x4001000u;
    maskedRegister = *(const u32 *) ((registerAddress) + (0));
    maskedRegister = (maskedRegister) & ~(0xe000u);
    value0 = (maskedRegister) | ((value0 << 13));
    *(u32 *) ((registerAddress) + (0)) = value0;
    return value0;
}

u32 WriteSubWinInBits(u32 lowBits, u32 extraBitFlag) {
    u32 value0 = lowBits;
    u32 value1 = extraBitFlag;
    u32 registerAddress;
    u32 flagCopy;
    u32 zero;
    registerAddress = 0x4001048u;
    flagCopy = value1;
    zero = 0u;
    value1 = *(const u16 *) ((registerAddress) + (0));
    value1 = (value1) & ~(0x3fu);
    value1 = (value1) | (value0);
    value0 = 0x4001048u;
    if (flagCopy != zero) {
        value1 = (value1) | (0x20u);
    }
    *(u16 *) ((value0) + (0)) = value1;
    return value0;
}

u32 WriteSubWinOutBits(u32 lowBits, u32 extraBitFlag) {
    u32 value0 = lowBits;
    u32 value1 = extraBitFlag;
    u32 registerAddress;
    u32 flagCopy;
    u32 zero;
    registerAddress = 0x400104au;
    flagCopy = value1;
    zero = 0u;
    value1 = *(const u16 *) ((registerAddress) + (0));
    value1 = (value1) & ~(0x3fu);
    value1 = (value1) | (value0);
    value0 = 0x400104au;
    if (flagCopy != zero) {
        value1 = (value1) | (0x20u);
    }
    *(u16 *) ((value0) + (0)) = value1;
    return value0;
}

void WriteSubWin0HV(u32 startX, u32 startY, u32 endX, u32 endY) {
    reg_G2S_DB_WIN0H = ((startX << 8) & 0xff00) | (endX & 0xff);
    reg_G2S_DB_WIN0V = ((startY << 8) & 0xff00) | (endY & 0xff);
}

#pragma thumb on

void WriteSelectKartRegisters(void) {
    u32 displayBits = 0x16;
    s32 interpolatedValue = GetInterpolatedValue(&gSelectKart->mInterpolations[4]);
    if (gSelectKart->mState != 8) {
        displayBits |= 8;
    }
    func_02028074(0x19);
    func_02028058(displayBits);
    func_0202802c(0, -interpolatedValue);
    WriteSubBg3CntBits(2);
    WriteSubBlendAlpha(0, 0x3f, 6, 10);
    if (interpolatedValue != 0 && gSelectKart->mState != 8) {
        func_02027fb8(1);
        WriteSubWinInBits(0x1f, 1);
        WriteSubWinOutBits(7, 1);
        WriteSubWin0HV(0, 0, 0xff, interpolatedValue + 0xc0);
    } else {
        func_02027fb8(0);
    }
    if (gSelectKart->mUnk_104 != FALSE) {
        WritePlayerEntryListRegisters();
    }
}

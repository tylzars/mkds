#include "01/code_02180b14.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0214d000.h"
#include "registers.h"

#pragma thumb off

void func_ov001_02180c6c(u32 bits) {
    vu32 *reg = &reg_GXS_DB_DISPCNT;
    *reg = (*reg & ~0x1f00) | (bits << 8);
}

void WriteSubBg0Offset(u32 offsetX, u32 offsetY) {
    reg_G2S_DB_BG0OFS = (offsetX & 0x1ff) | ((offsetY << 16) & 0x1ff0000);
}

void WriteSubBg0CntBits(u32 bits) {
    vu16 *reg = &reg_G2S_DB_BG0CNT;
    *reg = (*reg & ~3) | bits;
}

void WriteSubBg0CntBit6(u32 bit6Value) {
    vu16 *reg = &reg_G2S_DB_BG0CNT;
    if (bit6Value != 0) {
        *reg |= 0x40;
    } else {
        *reg &= ~0x40;
    }
}

void SetSubBg0Cnt(u32 cntVal14, u32 cntVal7, u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    vu16 *reg = &reg_G2S_DB_BG0CNT;
    *reg = (*reg & 0x43) | (cntVal14 << 14) | (cntVal7 << 7) | (cntVal8 << 8) | (cntVal2 << 2) | (cntVal13 << 13);
}

void WriteSubBg1Offset(u32 offsetX, u32 offsetY) {
    reg_G2S_DB_BG1OFS = (offsetX & 0x1ff) | ((offsetY << 16) & 0x1ff0000);
}

void WriteSubBg1CntBits(u32 bits) {
    vu16 *reg = &reg_G2S_DB_BG1CNT;
    *reg = (*reg & ~3) | bits;
}

void WriteSubBg1CntBit6(u32 bit6Value) {
    vu16 *reg = &reg_G2S_DB_BG1CNT;
    if (bit6Value != 0) {
        *reg |= 0x40;
    } else {
        *reg &= ~0x40;
    }
}

void func_ov001_02180b14(u32 cntVal14, u32 cntVal7, u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    vu16 *reg = &reg_G2S_DB_BG1CNT;
    *reg = (*reg & 0x43) | (cntVal14 << 14) | (cntVal7 << 7) | (cntVal8 << 8) | (cntVal2 << 2) | (cntVal13 << 13);
}

#pragma thumb on

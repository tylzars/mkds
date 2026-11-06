#include "01/code_02180b14.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0214d000.h"
#include "registers.h"

#pragma thumb off

void func_ov001_02180c6c(u32 p0) {
    vu32 *reg = &reg_GXS_DB_DISPCNT;
    *reg = (*reg & ~0x1f00) | (p0 << 8);
}

void func_ov001_02180c40(u32 p0, u32 p1) {
    reg_G2S_DB_BG0OFS = (p0 & 0x1ff) | ((p1 << 16) & 0x1ff0000);
}

void func_ov001_02180c24(u32 p0) {
    vu16 *reg = &reg_G2S_DB_BG0CNT;
    *reg = (*reg & ~3) | p0;
}

void func_ov001_02180bf8(u32 p0) {
    vu16 *reg = &reg_G2S_DB_BG0CNT;
    if (p0 != 0) {
        *reg |= 0x40;
    } else {
        *reg &= ~0x40;
    }
}

void func_ov001_02180bc0(u32 p0, u32 p1, u32 p2, u32 p3, u32 p4) {
    vu16 *reg = &reg_G2S_DB_BG0CNT;
    *reg = (*reg & 0x43) | (p0 << 14) | (p1 << 7) | (p2 << 8) | (p3 << 2) | (p4 << 13);
}

void func_ov001_02180b94(u32 p0, u32 p1) {
    reg_G2S_DB_BG1OFS = (p0 & 0x1ff) | ((p1 << 16) & 0x1ff0000);
}

void func_ov001_02180b78(u32 p0) {
    vu16 *reg = &reg_G2S_DB_BG1CNT;
    *reg = (*reg & ~3) | p0;
}

void func_ov001_02180b4c(u32 p0) {
    vu16 *reg = &reg_G2S_DB_BG1CNT;
    if (p0 != 0) {
        *reg |= 0x40;
    } else {
        *reg &= ~0x40;
    }
}

void func_ov001_02180b14(u32 p0, u32 p1, u32 p2, u32 p3, u32 p4) {
    vu16 *reg = &reg_G2S_DB_BG1CNT;
    *reg = (*reg & 0x43) | (p0 << 14) | (p1 << 7) | (p2 << 8) | (p3 << 2) | (p4 << 13);
}

#pragma thumb on

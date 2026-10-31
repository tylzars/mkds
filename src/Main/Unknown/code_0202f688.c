#include "Main/Unknown/code_0202f688.h"
#include "Main/Unknown/unk_02174000.h"
#include "registers.h"

#pragma thumb on

void func_0202f688(void) {
    u32 v = 0x16;
    s32 y;

    if (data_02174e50->mUnk_4c != 4) {
        v |= 8;
    }
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (v << 8);
    reg_G2S_DB_BG3OFS = (-data_02174e50->mUnk_90 << 16) & 0x1ff0000;
    if (data_02174e50->mUnk_90 != 0) {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        y = data_02174e50->mUnk_90 + 0xc0;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = y & 0xff;
    } else {
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

#pragma thumb off

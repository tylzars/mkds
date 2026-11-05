#include "code_02021764.h"

#include "code_02020eb0.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_0200e000.h"

Unk020217b4 *data_02174e00;

u32 func_020218bc(void) {
    DC_InvalidateRange(&data_02174e00->mUnk_004, 4);
    return data_02174e00->mUnk_004;
}

s16 func_02021868(s32 a, s32 b) {
    DC_InvalidateRange(&data_02174e00->mUnk_020[a].mUnk_00[b], 2);
    return data_02174e00->mUnk_020[a].mUnk_00[b];
}

u32 func_02021834(void) {
    DC_InvalidateRange(data_02174e00, 4);
    return data_02174e00->mUnk_000;
}

void func_020217b4(Unk020217b4 *p) {
    s32 i;
    s32 j;

    p->mUnk_004 = 0;
    p->mUnk_008 = 0;
    p->mUnk_00a = 0;
    p->mUnk_000 = 0;
    for (i = 0; i < 16; i++) {
        p->mUnk_020[i].mUnk_20 = 0;
        for (j = 0; j < 16; j++) {
            p->mUnk_020[i].mUnk_00[j] = -1;
        }
    }
    for (j = 0; j < 16; j++) {
        p->mUnk_260[j] = -1;
    }
    DC_FlushRange(p, 0x280);
}

void func_02021784(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        data_02174da0[i].mUnk_00 = 0;
        data_02174da0[i].mUnk_04 = 0;
        data_02174da0[i].mUnk_08 = 0;
    }
}

u32 func_02021764(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_02174da0;
    value1 = 0xcu;
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u8 *) ((value1) + (8));
    value0 = (value0) + (1u);
    *(u8 *) ((value1) + (8)) = (u8) value0;
    return value0;
}

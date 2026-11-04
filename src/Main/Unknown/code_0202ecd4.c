#include "Main/Unknown/code_0202ecd4.h"
#include "code_02016468.h"
#include "Main/Unknown/code_0202edfc.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on

u16 func_0202ecd4(u32 a, u32 b) {
    return func_0202ecf0(&data_02175628[a], b);
}

u16 func_0202ecf0(Unk02175628 *a, u32 b) {
    return a->mUnk_00 & b;
}

#pragma thumb on

void func_0202ed04(void) {
    if (data_02174e48->mUnk_658 != 0) {
        if (data_02174e48->mUnk_65c == 0) {
            func_0202ed50(0);
            data_02174e48->mUnk_658 = 0;
        } else {
            data_02174e48->mUnk_65c = data_02174e48->mUnk_65c - 1;
        }
    } else {
        data_02174e48->mUnk_65c = 0;
    }
}

void func_0202ed50(s32 a) {
    s32 j;
    s32 i;
    for (i = 1; i < 0x13; i++) {
        for (j = 0x1c; j < 0x20; j++) {
            u8 *q = (u8 *) data_02174e48 + (j + i * 0x20) * 2;
            q += 0x58;
            *(u16 *) q = *(u16 *) q & 0xfff;
            q = (u8 *) data_02174e48 + (j + i * 0x20) * 2;
            q += 0x58;
            *(u16 *) q = *(u16 *) q | (a << 12);
        }
    }
    data_02174e48->mUnk_65c = 5;
    data_02174e48->mUnk_658 = a;
    CallQueueAppend(0x1b, 0, data_02174e48->mUnk_058, 0x600);
}

void func_0202edd0(void) {
    Unk02174e48 *p = data_02174e48;
    s32 k;
    s16 v;
    k = p->mUnk_004[0] + func_0202edfc();
    v = p->mUnk_008[k].mUnk_0e;
    p->mUnk_008[p->mUnk_02c].mUnk_0e = v;
}

#pragma thumb off

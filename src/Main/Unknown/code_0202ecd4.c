#include "Main/Unknown/code_0202ecd4.h"
#include "code_02016468.h"
#include "Main/Unknown/code_0202edfc.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on

#pragma thumb on

void func_0202edd0(void) {
    ScrollList *p = gScrollList;
    s32 k;
    s16 v;
    k = p->mUnk_004[0] + GetScrollListSelectedSlot();
    v = p->mUnk_008[k].mUnk_0e;
    p->mUnk_008[p->mUnk_02c].mUnk_0e = v;
}

void func_0202ed50(s32 a) {
    s32 j;
    s32 i;
    for (i = 1; i < 0x13; i++) {
        for (j = 0x1c; j < 0x20; j++) {
            u8 *q = (u8 *) gScrollList + (j + i * 0x20) * 2;
            q += 0x58;
            *(u16 *) q = *(u16 *) q & 0xfff;
            q = (u8 *) gScrollList + (j + i * 0x20) * 2;
            q += 0x58;
            *(u16 *) q = *(u16 *) q | (a << 12);
        }
    }
    gScrollList->mUnk_65c = 5;
    gScrollList->mUnk_658 = a;
    CallQueueAppend(0x1b, 0, gScrollList->mUnk_058, 0x600);
}

void func_0202ed04(void) {
    if (gScrollList->mUnk_658 != 0) {
        if (gScrollList->mUnk_65c == 0) {
            func_0202ed50(0);
            gScrollList->mUnk_658 = 0;
        } else {
            gScrollList->mUnk_65c = gScrollList->mUnk_65c - 1;
        }
    } else {
        gScrollList->mUnk_65c = 0;
    }
}

#pragma thumb off

u16 func_0202ecf0(InputSlot *a, u32 b) {
    return a->mUnk_00 & b;
}

u16 func_0202ecd4(u32 a, u32 b) {
    return func_0202ecf0(&data_02175628[a], b);
}

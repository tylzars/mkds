#include "Main/Unknown/code_0202e68c.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0202ecac.h"
#include "Main/Unknown/code_0202ecd4.h"
#include "Main/Unknown/code_0202edfc.h"
#include "Main/Unknown/code_0202ee3c.h"
#include "Main/Unknown/code_0202ee68.h"
#include "Main/Unknown/code_0202f0a8.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_0214d018.h"

#pragma optimize_for_size on

u16 func_0202ec98(InputSlot *a, u32 b) {
    return a->mBits & b;
}

u16 func_0202ec7c(u32 a, u32 b) {
    return func_0202ec98(&data_02175628[a], b);
}

#pragma thumb on

void func_0202e9f0(void) {
    u32 a = func_020435bc();
    BOOL f;
    if (gScrollList->mEnabled == 0) {
        return;
    }
    gScrollList->mUnk_048 = gScrollList->mUnk_04c > 2 ? 5 : 0xf;
    if (func_0202ecd4(a, PAD_KEY_A) != 0) {
        gScrollList->mState = 5;
        gScrollList->mUnk_024 = gScrollList->mSelectedVisibleRow;
        gScrollList->mUnk_008[gScrollList->mUnk_02c].mUnk_00 = 0;
        gScrollList->mUnk_038 = 10;
        gScrollList->mUnk_054 = 0;
        gScrollList->mUnk_050 = gScrollList->mUnk_054;
        gScrollList->mUnk_04c = 0;
        func_0202edd0();
        func_0202f120(0, -1, -1, -1);
        return;
    }
    if (gScrollList->mUnk_018 <= gScrollList->mUnk_020 && gScrollList->mUnk_020 < gScrollList->mUnk_018 + 5 &&
        gScrollList->mUnk_020 - gScrollList->mUnk_018 < gScrollList->mRowCount) {
        gScrollList->mState = 5;
        gScrollList->mUnk_024 = gScrollList->mUnk_020 - gScrollList->mUnk_018;
        f = gScrollList->mUnk_024 != gScrollList->mSelectedVisibleRow;
        gScrollList->mUnk_008[gScrollList->mUnk_02c].mUnk_00 = f;
        gScrollList->mUnk_038 = 10;
        gScrollList->mUnk_054 = 0;
        gScrollList->mUnk_050 = gScrollList->mUnk_054;
        gScrollList->mUnk_04c = 0;
        gScrollList->mSelectedRow =
            gScrollList->mSelectedRow + (gScrollList->mUnk_024 - gScrollList->mSelectedVisibleRow);
        gScrollList->mSelectedVisibleRow = gScrollList->mUnk_024;
        func_0202edd0();
        func_0202f120(0, -1, -1, f != FALSE ? GetScrollListSelectedSlot() : -1);
        return;
    }
    if ((func_0202ecd4(a, PAD_KEY_UP) != 0 || gScrollList->mUnk_020 == gScrollList->mUnk_010 ||
         gScrollList->mUnk_050 > gScrollList->mUnk_048) &&
        gScrollList->mSelectedRow > 0) {
        if (gScrollList->mSelectedVisibleRow == 0) {
            gScrollList->mUnk_038 = gScrollList->mUnk_048;
            gScrollList->mUnk_008[gScrollList->mUnk_02c].mUnk_00 = 0;
            gScrollList->mState = 3;
            func_0202ee3c(gScrollList->mHiddenTopSlot, 1);
            func_0202f120(0, -1, -1, -1);
            func_0202f120(2, gScrollList->mHiddenTopSlot,
                          gScrollList->mSelectedRow - gScrollList->mSelectedVisibleRow - 1, -1);
        } else {
            gScrollList->mState = 1;
        }
        gScrollList->mUnk_050 = 0;
        gScrollList->mUnk_04c = gScrollList->mUnk_04c + 1;
        if (gScrollList->mUnk_01c == gScrollList->mUnk_010) {
            func_0202ed50(1);
        }
        func_0202ecac(3);
        return;
    }
    if ((func_0202ecd4(a, PAD_KEY_DOWN) != 0 || gScrollList->mUnk_020 == gScrollList->mUnk_014 ||
         gScrollList->mUnk_054 > gScrollList->mUnk_048) &&
        gScrollList->mSelectedRow < gScrollList->mRowCount - 1) {
        if (gScrollList->mSelectedVisibleRow == 4) {
            gScrollList->mUnk_038 = gScrollList->mUnk_048;
            gScrollList->mUnk_008[gScrollList->mUnk_02c].mUnk_00 = 0;
            gScrollList->mState = 4;
            func_0202ee3c(GetScrollListHiddenBottomSlot(), 1);
            func_0202f120(0, -1, -1, -1);
            {
                ScrollList *q = gScrollList;
                func_0202f120(2, GetScrollListHiddenBottomSlot(), q->mSelectedRow - q->mSelectedVisibleRow + 5, -1);
            }
        } else {
            gScrollList->mState = 2;
        }
        gScrollList->mUnk_054 = 0;
        gScrollList->mUnk_04c = gScrollList->mUnk_04c + 1;
        if (gScrollList->mUnk_01c == gScrollList->mUnk_014) {
            func_0202ed50(2);
        }
        func_0202ecac(3);
        return;
    }
    if (func_0202ec7c(a, PAD_KEY_UP | PAD_KEY_DOWN) == 0 && gScrollList->mUnk_01c != gScrollList->mUnk_010 &&
        gScrollList->mUnk_01c != gScrollList->mUnk_014) {
        gScrollList->mUnk_04c = 0;
    }
}

void func_0202e9ac(void) {
    gScrollList->mSelectedVisibleRow = gScrollList->mSelectedVisibleRow - 1;
    gScrollList->mSelectedRow = gScrollList->mSelectedRow - 1;
    func_0202edd0();
    func_0202f120(0, -1, -1, GetScrollListSelectedSlot());
    gScrollList->mState = 0;
}

void func_0202e968(void) {
    gScrollList->mSelectedVisibleRow = gScrollList->mSelectedVisibleRow + 1;
    gScrollList->mSelectedRow = gScrollList->mSelectedRow + 1;
    func_0202edd0();
    func_0202f120(0, -1, -1, GetScrollListSelectedSlot());
    gScrollList->mState = 0;
}

void func_0202e84c(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 a;
    Unk02124b1c *p;
    BOOL z = FALSE;
    s32 t = GetScrollListHiddenBottomSlot();
    gScrollList->mUnk_038 = gScrollList->mUnk_038 - 1;
    for (i = 0; i < gScrollList->mUnk_000; i++) {
        for (j = z; j < 7; j++) {
            k = gScrollList->mUnk_004[i];
            a = func_0202ee20(j + k, (j + 1) % 7 + k);
            p = &gScrollList->mUnk_008[j + k];
            if (j == t) {
                p->mUnk_06 = a;
            } else {
                p->mUnk_06 = InterpolateS16(1, a, z, gScrollList->mUnk_038, gScrollList->mUnk_048);
            }
        }
    }
    if (gScrollList->mUnk_038 == 0) {
        for (i = 0; i < gScrollList->mUnk_000; i++) {
            for (j = z; j < 7; j++) {
                p = &gScrollList->mUnk_008[j + gScrollList->mUnk_004[i]];
                p->mUnk_0e = p->mUnk_0e + p->mUnk_06;
                p->mUnk_06 = 0;
            }
        }
        gScrollList->mUnk_008[gScrollList->mUnk_02c].mUnk_00 = 1;
        gScrollList->mSelectedRow = gScrollList->mSelectedRow - 1;
        gScrollList->mHiddenTopSlot = t;
        func_0202f120(1, gScrollList->mHiddenTopSlot, gScrollList->mSelectedRow - 1, -1);
        {
            ScrollList *q = gScrollList;
            func_0202f120(0, q->mHiddenTopSlot, q->mSelectedRow - 1, GetScrollListSelectedSlot());
        }
        gScrollList->mState = 0;
        func_0202ee3c(gScrollList->mHiddenTopSlot, 0);
    }
}

void func_0202e72c(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 a;
    Unk02124b1c *p;
    BOOL z = FALSE;
    gScrollList->mUnk_038 = gScrollList->mUnk_038 - 1;
    for (i = 0; i < gScrollList->mUnk_000; i++) {
        for (j = z; j < 7; j++) {
            k = gScrollList->mUnk_004[i];
            a = func_0202ee20(j + k, (j + 6) % 7 + k);
            p = &gScrollList->mUnk_008[j + k];
            if (j == gScrollList->mHiddenTopSlot) {
                p->mUnk_06 = a;
            } else {
                p->mUnk_06 = InterpolateS16(1, a, z, gScrollList->mUnk_038, gScrollList->mUnk_048);
            }
        }
    }
    if (gScrollList->mUnk_038 == 0) {
        for (i = 0; i < gScrollList->mUnk_000; i++) {
            for (j = z; j < 7; j++) {
                p = &gScrollList->mUnk_008[j + gScrollList->mUnk_004[i]];
                p->mUnk_0e = p->mUnk_0e + p->mUnk_06;
                p->mUnk_06 = 0;
            }
        }
        gScrollList->mUnk_008[gScrollList->mUnk_02c].mUnk_00 = 1;
        gScrollList->mSelectedRow = gScrollList->mSelectedRow + 1;
        func_0202f120(1, gScrollList->mHiddenTopSlot, gScrollList->mSelectedRow + 1, -1);
        {
            ScrollList *q = gScrollList;
            q->mHiddenTopSlot = (q->mHiddenTopSlot + 1) % 7;
        }
        {
            ScrollList *q = gScrollList;
            func_0202f120(0, q->mHiddenTopSlot, q->mSelectedRow - 1, GetScrollListSelectedSlot());
        }
        gScrollList->mState = 0;
        func_0202ee3c(GetScrollListHiddenBottomSlot(), 0);
    }
}

void func_0202e6c4(void) {
    if (gScrollList->mUnk_038 == 10) {
        gScrollList->mPickStarted = 1;
    }
    gScrollList->mUnk_038 = gScrollList->mUnk_038 - 1;
    if (gScrollList->mUnk_038 == 0) {
        func_0202f120(0, -1, -1, GetScrollListSelectedSlot());
        gScrollList->mUnk_008[gScrollList->mUnk_02c].mUnk_00 = 1;
        gScrollList->mState = 0;
        gScrollList->mPickFinished = 1;
    }
}

#pragma thumb off

void func_0202e6a0(void *a, u32 b, u32 c) {
    volatile u32 v = b;
    MIi_CpuClearFast(v, a, c);
}

void func_0202e68c(void *a, u32 b) {
    func_0202e6a0(a, 0, b);
}

#include "Main/Unknown/code_0202ee88.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_0202e68c.h"
#include "Main/Unknown/code_0202f020.h"
#include "Main/Unknown/code_0202f028.h"
#include "Main/Unknown/code_0202f058.h"
#include "Main/Unknown/code_0202f0a8.h"
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
#include "Main/Unknown/code_0202edfc.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on

u32 func_0202efe8(InputSlotPair *a) {
    u32 r;
    if (func_0202f028(a) != 0 || func_0202f020(a) != 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

u32 func_0202efc8(u32 a) {
    return func_0202efe8((InputSlotPair *) &data_02175628[a].mPairX);
}

#pragma thumb on

void func_0202eec0(void) {
    u32 a = func_020435bc();
    u32 b;
    u32 c;
    s32 d;
    if (func_0202f0a8(a) != 0) {
        b = func_0202f080(a);
        c = func_0202f058(a);
        gScrollList->mUnk_01c = FindRectContainingPoint(b, c, gScrollList->mUnk_00c);
        gScrollList->mUnk_020 = gScrollList->mUnk_01c;
        gScrollList->mUnk_66c = TRUE;
    } else {
        gScrollList->mUnk_020 = -1;
    }
    if (gScrollList->mUnk_66c != FALSE) {
        if (func_0202efc8(a) != 0) {
            b = func_0202f080(a);
            c = func_0202f058(a);
            d = FindRectContainingPoint(b, c, gScrollList->mUnk_00c);
            if (d != gScrollList->mUnk_01c) {
                gScrollList->mUnk_01c = -1;
                gScrollList->mUnk_66c = FALSE;
            }
        } else {
            gScrollList->mUnk_01c = -1;
            gScrollList->mUnk_66c = FALSE;
        }
    }
    if (func_0202ec7c(a, PAD_KEY_UP) != 0 || gScrollList->mUnk_01c == gScrollList->mUnk_010) {
        gScrollList->mUnk_050 = gScrollList->mUnk_050 + 1;
    } else {
        gScrollList->mUnk_050 = 0;
    }
    if (func_0202ec7c(a, PAD_KEY_DOWN) != 0 || gScrollList->mUnk_01c == gScrollList->mUnk_014) {
        gScrollList->mUnk_054 = gScrollList->mUnk_054 + 1;
    } else {
        gScrollList->mUnk_054 = 0;
    }
}

void func_0202ee88(void) {
    if (gScrollList->mUnk_008[gScrollList->mUnk_02e].mUnk_00 != 0) {
        gScrollList->mUnk_008[gScrollList->mUnk_02e].mUnk_06 =
            gScrollList->mUnk_030 * (gScrollList->mSelectedRow - gScrollList->mSelectedVisibleRow) /
            (gScrollList->mRowCount - 5);
    }
}

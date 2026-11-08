#include "Main/Unknown/code_020291f0.h"
#include "Main/Unknown/code_02025e28.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02025df4.h"
#include "Main/Unknown/code_02028774.h"
#include "Main/Unknown/code_0202881c.h"
#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02025da4.h"
#include "Main/Unknown/code_0202a820.h"
#include "Main/Unknown/code_0202b604.h"

#pragma optimize_for_size on

#pragma thumb on

void func_0202941c(s32 a) {
    if (gSelectKart->mUnk_104 != FALSE) {
        func_0202b7c0(a);
    }
}

void func_02029330(void) {
    s32 a;
    s32 b;
    SelectKart *d;
    Unk02174e50_24 *p;
    if (func_020280dc() == 0) {
        d = gSelectKart;
        a = func_02025da4(d->mUnk_098, d->mCharacterIndex, d->mKartIndex);
        b = func_02025df4(gSelectKart->mUnk_098, gSelectKart->mCharacterIndex);
        d = gSelectKart;
        if (d->mUnk_104 != FALSE) {
            WriteKartPositionAndCount(a, b);
        } else {
            p = &d->mSelectCharacterGpMParts;
            p->mUnk_18[5].mVisible = (a >= 10);
            func_02025c48(5, a / 10 % 10 + 10, p->mUnk_0c);
            func_02025c48(6, a % 10 + 10, p->mUnk_0c);
            if (b >= 10) {
                func_02025c48(8, b / 10 % 10 + 20, p->mUnk_0c);
                func_02025c48(9, b % 10 + 20, p->mUnk_0c);
            } else {
                p->mUnk_18[9].mVisible = 0;
                func_02025c48(8, b % 10 + 20, p->mUnk_0c);
            }
        }
    }
}

void MoveSelectKartNext(void) {
    SelectKart *d;
    s32 index;
    index = gSelectKart->mKartTableIndex + 1;
    if (index >= 0x24) {
        index = 0;
    }
    while (d = gSelectKart, index != d->mKartTableIndex) {
        if (IsKartAppearWithinLimit(d->mUnk_098, d->mCharacterIndex, GetKartIndexAtTableIndex(index)) != 0) {
            gSelectKart->mKartTableIndex = index;
            gSelectKart->mKartIndex = GetKartIndexAtTableIndex(gSelectKart->mKartTableIndex);
        } else {
            index++;
            if (index >= 0x24) {
                index = 0;
            }
        }
    }
    func_02029330();
}

void MoveSelectKartPrev(void) {
    SelectKart *d;
    s32 index;
    index = gSelectKart->mKartTableIndex - 1;
    if (index < 0) {
        index = 0x23;
    }
    while (d = gSelectKart, index != d->mKartTableIndex) {
        if (IsKartAppearWithinLimit(d->mUnk_098, d->mCharacterIndex, GetKartIndexAtTableIndex(index)) != 0) {
            gSelectKart->mKartTableIndex = index;
            gSelectKart->mKartIndex = GetKartIndexAtTableIndex(gSelectKart->mKartTableIndex);
        } else {
            index--;
            if (index < 0) {
                index = 0x23;
            }
        }
    }
    func_02029330();
}

#pragma thumb off

u32 func_02029210(InputSlotPair *pair) {
    u32 result;

    if (func_020287ec(pair) != 0 || func_0202881c(pair) != 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

u32 func_020291f0(u32 slot) {
    return func_02029210((InputSlotPair *) &data_02175628[slot].mPairX);
}

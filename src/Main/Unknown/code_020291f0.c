#include "Main/Unknown/code_020291f0.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02025df4.h"
#include "Main/Unknown/code_02028774.h"
#include "Main/Unknown/code_0202881c.h"
#include "Main/Unknown/code_02027f68.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_0205ee14.h"

#pragma optimize_for_size on

u32 func_020291f0(u32 a) {
    return func_02029210((Unk02175628_48 *) &data_02175628[a].mUnk_48);
}

u32 func_02029210(Unk02175628_48 *a) {
    u32 r;

    if (func_020287ec(a) != 0 || func_0202881c(a) != 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

#pragma thumb on
void func_02029248(void) {
    Unk02174e18 *d;
    s32 i;
    i = gSelectKart->mUnk_09c - 1;
    if (i < 0) {
        i = 0x23;
    }
    while (d = gSelectKart, i != d->mUnk_09c) {
        if (func_0205fd2c(d->mUnk_098, d->mUnk_0a4, func_02025e28(i)) != 0) {
            gSelectKart->mUnk_09c = i;
            gSelectKart->mUnk_0a8 = func_02025e28(gSelectKart->mUnk_09c);
        } else {
            i--;
            if (i < 0) {
                i = 0x23;
            }
        }
    }
    func_02029330();
}

void func_020292bc(void) {
    Unk02174e18 *d;
    s32 i;
    i = gSelectKart->mUnk_09c + 1;
    if (i >= 0x24) {
        i = 0;
    }
    while (d = gSelectKart, i != d->mUnk_09c) {
        if (func_0205fd2c(d->mUnk_098, d->mUnk_0a4, func_02025e28(i)) != 0) {
            gSelectKart->mUnk_09c = i;
            gSelectKart->mUnk_0a8 = func_02025e28(gSelectKart->mUnk_09c);
        } else {
            i++;
            if (i >= 0x24) {
                i = 0;
            }
        }
    }
    func_02029330();
}

void func_02029330(void) {
    s32 a;
    s32 b;
    Unk02174e18 *d;
    Unk02174e50_24 *p;
    if (func_020280dc() == 0) {
        d = gSelectKart;
        a = func_02025da4(d->mUnk_098, d->mUnk_0a4, d->mUnk_0a8);
        b = func_02025df4(gSelectKart->mUnk_098, gSelectKart->mUnk_0a4);
        d = gSelectKart;
        if (d->mUnk_104 != 0) {
            func_0202b554(a, b);
        } else {
            p = &d->mUnk_048;
            p->mUnk_18[5].mUnk_00 = (a >= 10);
            func_02025c48(5, a / 10 % 10 + 10, p->mUnk_0c);
            func_02025c48(6, a % 10 + 10, p->mUnk_0c);
            if (b >= 10) {
                func_02025c48(8, b / 10 % 10 + 20, p->mUnk_0c);
                func_02025c48(9, b % 10 + 20, p->mUnk_0c);
            } else {
                p->mUnk_18[9].mUnk_00 = 0;
                func_02025c48(8, b % 10 + 20, p->mUnk_0c);
            }
        }
    }
}

void func_0202941c(s32 a) {
    if (gSelectKart->mUnk_104 != 0) {
        func_0202b7c0(a);
    }
}
#pragma thumb off

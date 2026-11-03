#include "Main/Unknown/code_02029008.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02028724.h"
#include "Main/Unknown/code_02028774.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_020291f0.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on
#pragma thumb on
s32 func_020290fc(void) {
    s32 r = -1;
    Unk02174e50_24 *p = &gSelectKart->mUnk_064;
    u16 t = func_020435bc();
    s32 x;
    s32 y;
    s32 z;
    if (gSelectKart->mUnk_108 != 0) {
        if (func_020291f0(t) != 0) {
            x = func_0202874c(t);
            y = func_02028724(t);
            z = func_020291c4(x, y, p->mUnk_10);
            if (z != gSelectKart->mUnk_110) {
                gSelectKart->mUnk_108 = 0;
                gSelectKart->mUnk_10c = 0;
            } else {
                gSelectKart->mUnk_10c++;
                r = z;
            }
        } else {
            gSelectKart->mUnk_108 = 0;
            gSelectKart->mUnk_10c = 0;
        }
    } else if (func_02028774(t) != 0) {
        r = func_020291c4(func_0202874c(t), func_02028724(t), p->mUnk_10);
        gSelectKart->mUnk_108 = 1;
        gSelectKart->mUnk_10c = 0;
    }
    return r;
}

u32 func_020290ac(s32 a) {
    u32 r = 0;
    u32 t;
    Unk02174e18 *d = gSelectKart;
    s32 n;
    if (d->mUnk_110 == a) {
        n = d->mUnk_10c;
        r |= (n == 0);
        t = 0;
        if (n >= 0x3c) {
            if ((n - 0x3c) % 0xf == 0) {
                t = 1;
            }
        }
        r |= t;
    }
    return r;
}

void func_02029008(void) {
    Unk02174e18 *d = gSelectKart;
    Unk02174e50_24 *p;
    if (d->mUnk_104 == FALSE) {
        p = &d->mUnk_048;
        p->mUnk_18[1].mUnk_04 = func_02025ebc(&d->mUnk_0ac[0]);
        p->mUnk_18[2].mUnk_04 = p->mUnk_18[1].mUnk_04;
        p->mUnk_18[0].mUnk_06 = func_02025ebc(&gSelectKart->mUnk_0ac[1]);
        p->mUnk_18[3].mUnk_06 = func_02025ebc(&gSelectKart->mUnk_0ac[2]);
        p->mUnk_18[9].mUnk_06 = func_02025ebc(&gSelectKart->mUnk_0ac[3]);
        p->mUnk_18[8].mUnk_06 = p->mUnk_18[9].mUnk_06;
        p->mUnk_18[7].mUnk_06 = p->mUnk_18[8].mUnk_06;
        p->mUnk_18[6].mUnk_06 = p->mUnk_18[7].mUnk_06;
        p->mUnk_18[5].mUnk_06 = p->mUnk_18[6].mUnk_06;
        p->mUnk_18[4].mUnk_06 = p->mUnk_18[5].mUnk_06;
    }
}
#pragma thumb off

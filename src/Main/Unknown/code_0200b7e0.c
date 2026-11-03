#include "Main/Unknown/code_020091fc.h"
#include "Main/Unknown/code_0200b7e0.h"
#include "Main/Unknown/code_0200b6e8.h"
#include "Main/Unknown/code_0200b70c.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020091e0.h"
#include "Main/Unknown/code_02008e10.h"
#include "code_0200eddc.h"

#pragma thumb on

void func_0200b934(void) {
    s32 r;
    Unk0216fde8 *d;
    u8 *p;
    u8 *q;
    d = data_0216fde8;
    if (d->mUnk_5f00 != 0) {
        d->mUnk_0580.mUnk_06 = 0xdc;
    } else {
        p = d->mUnk_0580.mUnk_08;
        q = data_usa_02152be4;
        p[0] = q[0];
        p[1] = q[1];
        p[2] = q[2];
        p[3] = q[3];
        p[4] = q[4];
        p[5] = q[5];
        data_0216fde8->mUnk_0580.mUnk_06 = 10;
        if (func_0200b72c() == 0) {
            func_0200b820(0x1e, 0);
            return;
        }
    }
    if (data_0216fde8->mUnk_0580.mUnk_04 == 0) {
        data_0216fde8->mUnk_0580.mUnk_04 = 1;
    }
    r = func_02143a78(func_0200b894, &data_0216fde8->mUnk_0580);
    if (r != 2) {
        func_0200b820(0xa, r);
    }
}

void func_0200b894(Unk021425e8 *a) {
    if (a->mUnk_02 != 0) {
        func_0200b820(0xa, a->mUnk_02);
        return;
    }
    switch (a->mUnk_08_0) {
        case 3:
            break;
        case 5:
            if (a->mUnk_38.mUnk_00[1] == data_0216fde8->mUnk_05e4) {
                func_0200ee3c(data_0216fde8->mUnk_04c0, 0xc0);
                func_0200921c(func_0200b794, a->mUnk_12, (Unk02007ec4 *) data_0216fde8->mUnk_04c0);
                func_02008f00(func_0200b794, 1);
            }
        case 4:
            func_02008f00(func_0200b794, 0);
            if (data_0216fde8->mUnk_5ef8 != 0) {
                func_0200b934();
            } else {
                func_0200b6e8();
            }
            break;
        default:
            func_0200b820(0xa, 1);
            break;
    }
}

void func_0200b850(u32 a, Unk02008934 *b, u32 c) {
    Unk0200b850 v;
    Unk0216fde8 *d;
    d = data_0216fde8;
    if (d->mUnk_05dc != NULL) {
        v.mUnk_00 = c;
        if (b != NULL) {
            v.mUnk_04 = b;
            v.mUnk_08 = b->mUnk_4c0;
        } else {
            v.mUnk_04 = NULL;
            v.mUnk_08 = NULL;
        }
        d->mUnk_05dc(a, &v);
    }
}

void func_0200b820(u16 a, u16 b) {
    Unk0200b820 v;
    if (data_0216fde8->mUnk_05dc != NULL) {
        v.mUnk_00 = a;
        v.mUnk_02 = b;
        data_0216fde8->mUnk_05dc(2, &v);
    }
}

void func_0200b7e0(const u8 *a) {
    u8 *p;
    data_0216fde8->mUnk_5f00 = 1;
    p = data_0216fde8->mUnk_0580.mUnk_08;
    p[0] = a[0];
    p[1] = a[1];
    p[2] = a[2];
    p[3] = a[3];
    p[4] = a[4];
    p[5] = a[5];
}

#pragma thumb off

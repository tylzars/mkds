#include "Main/Unknown/code_0200b6e8.h"
#include "code_0200fc8c.h"

#include "Main/Unknown/code_0200b200.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_020091fc.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020091e0.h"
#include "Main/Unknown/code_02008e10.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_0200bae0.h"

#pragma thumb on

void func_0200bab0(void) {
    *(u16 *) &data_0216fde4 = 0;
    data_0216fde8->mUnk_5f04 = 0;
    func_0200bc0c();
    func_0200ba44((u32) 0x14, (u32) 0);
}

u32 func_0200baa8(void) {
    return 0x5f20u;
}

void func_0200ba84(UnkFunc *p0) {
    u32 v1 = (u32) p0;
    u32 v2 = ((u32) IrqDisable());
    u32 v3 = ((u32) (&data_0216fde8));
    u32 v4 = ((u32) * (u32 *) ((v3) + (0)));
    u32 v5 = 0x5e0u;
    u32 v7;
    *(u32 *) ((v4) + (0 + (v5))) = v1;
    v7 = ((u32) IrqRestore(v2));
}

#pragma thumb off

#pragma thumb on

void func_0200ba44(u32 a, u32 b) {
    u32 v1;
    v1 = IrqDisable();
    data_0216fde8->mUnk_5f0e = a;
    IrqRestore(v1);
    if (data_0216fde8->mUnk_05e0 != NULL) {
        data_0216fde8->mUnk_05e0(a, (void *) b);
    }
}

#pragma thumb off

#pragma thumb on

void func_0200b9e0(UnkFunc *a, u32 b) {
    data_0216fde8->mUnk_05dc = a;
    data_0216fde8->mUnk_05e4 = b;
    data_0216fde8->mUnk_0580.mUnk_04 = 0;
    data_0216fde8->mUnk_0580.mUnk_00 = data_0216fde8->mUnk_04c0;
    data_0216fde8->mUnk_5ef8 = 1;
    data_0216fde8->mUnk_5f00 = 0;
    data_0216fde8->mUnk_05ee = 0;
    func_0200b934();
}

#pragma thumb off

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

#pragma thumb on
u32 func_0200b7cc(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    value0 = (u32) &data_0216fde8;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 0x5f00u;
    *(u32 *) ((value1) + (value0)) = value2;
    return value0;
}
#pragma thumb off

#pragma thumb on

void func_0200b794(u32 a, void *b, u32 c) {
    switch (a) {
        case 0:
        case 2:
        case 4:
            break;
        case 1:
            func_0200b850(0, b, c);
            break;
        case 3:
            func_0200b850(1, b, c);
            break;
    }
}

u32 func_0200b72c(void) {
    u16 a;
    a = func_02143280();
    if (a == 0x8000 || a == 0) {
        return 0;
    }
    data_0216fde8->mUnk_0580.mUnk_04++;
    do {
        data_0216fde8->mUnk_0580.mUnk_04++;
        if (data_0216fde8->mUnk_0580.mUnk_04 > 0x10) {
            data_0216fde8->mUnk_0580.mUnk_04 = 1;
        }
    } while ((a & (1 << (data_0216fde8->mUnk_0580.mUnk_04 - 1))) == 0);
    return 1;
}

void func_0200b70c(void) {
    data_0216fde8->mUnk_5ef8 = 0;
    data_0216fde8->mUnk_5efc = 1;
}

#pragma thumb off

#pragma thumb on

void func_0200b6e8(void) {
    u32 v1;
    v1 = func_021438a8(func_0200b698);
    if (v1 != 2) {
        func_0200b820((u16) 0xb, (u16) (v1 & 0xffff));
    }
}

#pragma thumb off

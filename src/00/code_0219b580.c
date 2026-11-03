#include "00/code_0219b580.h"
#include "00/code_0219b000.h"
#include "00/code_0219c954.h"
#include "00/unk_021b5000.h"

#include "00/code_0219b8a8.h"
#include "00/code_021a10b0.h"
#include "00/code_021a17bc.h"
#include "00/code_0219c000.h"
#include "00/code_021a01dc.h"

u32 func_ov000_0219b868(u32 a) {
    void *b;
    s32 d;
    s32 e;

    d = func_ov000_021a158c(&b);
    for (e = 0; e < d; e++) {
        if (a == ((u8 *) b)[e]) {
            break;
        }
    }
    if (e == d) {
        return 0;
    }
    return func_ov000_021a1620(e, d);
}

u32 func_ov000_0219b844(const u8 *values, s32 count) {
    u32 mask = 0;
    s32 i;
    for (i = 0; i < count; i++) {
        mask |= 1 << values[i];
    }
    return mask;
}

int func_ov000_0219b77c(int c) {
    s32 a;
    s32 b;

    if (c == 0) {
        return 0;
    }
    switch (c) {
        case 1:
            a = 0xb;
            b = -1;
            break;
        case 2:
            a = 0xb;
            b = -2;
            break;
        case 3:
            a = 6;
            b = -10;
            break;
        case 4:
            a = 6;
            b = -20;
            break;
    }
    switch (data_ov000_021b54c8->mUnk_24) {
        case 1:
            b -= 0xee48;
            func_ov000_0219c990(a, b);
            break;
        case 2:
            b -= 0xee48;
            func_ov000_0219c990(a, b);
            break;
        case 5:
            b -= 0x13c68;
            func_ov000_021a1a38(a, b);
            break;
        case 4:
            b -= 0x11558;
            break;
        default:
            b -= 0x16378;
            break;
    }
    func_ov000_0219d734(a, b);
    return c;
}

u32 func_ov000_0219b704(u32 a) {
    s32 b;
    s32 c;

    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 0xb;
            c = -1;
            break;
        case 2:
        case 5:
            b = 0;
            c = 0;
            a = 0;
            break;
        case 3:
            b = 6;
            c = -10;
            break;
        case 4:
            b = 6;
            c = -30;
            break;
        case 6:
            b = 6;
            c = -70;
            break;
        case 7:
            b = 6;
            c = -80;
            break;
    }
    if (b != 0) {
        func_ov000_0219c990(b, c - 0x105b8);
    }
    return a;
}

void func_ov000_0219b6c0(int a, u32 b) {
    UnkFunc *v1;
    if (a == 0) {
        data_ov000_021b54c8->mUnk_30 = b;
        func_ov000_0219b8a8(3);
        func_ov000_0219d5bc();
    } else {
        func_ov000_0219b8a8(0);
    }
    v1 = data_ov000_021b54c8->mUnk_5c;
    if (v1 != NULL) {
        (*v1)(a, b, data_ov000_021b54c8->mUnk_60);
    }
    return;
}

void func_ov000_0219b694(u32 a, u32 b) {
    func_ov000_0219b8a8((u32) (data_ov000_021b54c8->mUnk_28));
    data_ov000_021b54c8->mUnk_64(a, b, data_ov000_021b54c8->mUnk_68);
    return;
}

void func_ov000_0219b5a8(u32 a, u32 b, u32 c, u32 d, u32 e) {
    s32 f;
    Unk021b54c8 *h;

    if (a == 0 && b != 0) {
        if (data_ov000_021b54c8->mUnk_33c.mUnk_198 == 0) {
            func_ov000_021a1a10();
            func_ov000_0219b8a8(3);
        }
    } else if (a == 0) {
        func_ov000_0219b8a8(6);
        for (f = 0; f <= data_ov000_021b54c8->mUnk_33c.mUnk_0d; f++) {
            if (data_ov000_021b54c8->mUnk_30 == data_ov000_021b54c8->mUnk_33c.mUnk_f4[f]) {
                data_ov000_021b54c8->mUnk_2c = data_ov000_021b54c8->mUnk_33c.mUnk_2b8[f];
                break;
            }
        }
    }
    data_ov000_021b54c8->mUnk_33c.mUnk_2d8 =
        func_ov000_0219b844(data_ov000_021b54c8->mUnk_33c.mUnk_2b8, data_ov000_021b54c8->mUnk_33c.mUnk_0d + 1);
    func_ov000_021a15b0();
    h = data_ov000_021b54c8;
    if (h->mUnk_33c.mUnk_15 == 2 || h->mUnk_33c.mUnk_15 == 3) {
        h = data_ov000_021b54c8;
        h->mUnk_74(a, b, c, d, e, h->mUnk_78);
    } else {
        h->mUnk_6c(a, b, h->mUnk_70);
    }
}

void func_ov000_0219b580(u32 a, int b) {
    if ((*(s32 *) (b + 4) != 0x603) && (*(s32 *) (b + 4) != 0x901)) {
        func_ov000_0219b77c(3);
    }
}

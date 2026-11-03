#include "00/code_0219a654.h"
#include "00/code_0219b580.h"
#include "00/code_0219b8bc.h"
#include "00/code_02188720.h"
#include "00/code_0219b1f8.h"
#include "00/code_02198a8c.h"
#include "00/unk_021b5000.h"

#include "00/code_0219887c.h"
#include "00/code_0219b000.h"
#include "00/code_0219b8a8.h"
#include "00/code_0219a000.h"
#include "00/code_021a3264.h"
#include "00/code_02198a84.h"
#include "00/code_021a1ae0.h"
#include "code_0214d018.h"
#include "00/code_021a10b0.h"

s32 func_ov000_0219bb04(u8 **a) {
    if (data_ov000_021b54c8 == NULL) {
        return 0;
    }
    *a = data_ov000_021b54c8->mUnk_33c.mUnk_2b8;
    if (data_ov000_021b54c8->mUnk_33c.mUnk_15 == 2 || data_ov000_021b54c8->mUnk_33c.mUnk_15 == 3) {
        return func_ov000_021a1514((void **) a);
    }
    return func_ov000_021a158c((void **) a);
}

s32 func_ov000_0219bac8(u32 a) {
    if (data_ov000_021b54c8 == NULL) {
        return 0;
    }
    if ((data_ov000_021b54c8->mUnk_33c.mUnk_2d8 & (1 << a)) != 0) {
        return func_ov000_0219b8bc(a);
    }
    return 0;
}

u32 func_ov000_0219bab4(void) {
    if (data_ov000_021b54c8 != NULL) {
        return data_ov000_021b54c8->mUnk_24;
    }
    return 0;
}

s32 func_ov000_0219ba20(void) {
    Unk021b54c8 *p;
    u32 v;
    s32 r;
    if (data_ov000_021b54c8->mUnk_00 != NULL) {
        return 0;
    }
    v = (u16) (func_ov000_021a3448(0x4000) + 0xc000);
    p = data_ov000_021b54c8;
    r = func_ov000_02198ac4((Unk02197e8c **) data_ov000_021b54c8, (const u8 *) func_ov000_0219a760(0, v, 0), p->mUnk_14,
                            p->mUnk_18, (u32) func_ov000_0219b240);
    if (func_ov000_0219b704(r) != 0) {
        return r;
    }
    func_ov000_02198a84(data_ov000_021b54c8->mUnk_00, func_ov000_021a1ca8);
    func_ov000_021988d4((s32) data_ov000_021b54c8->mUnk_00, (u32) func_ov000_021a1e40);
    return r;
}

u32 func_ov000_0219b9d4(u32 a) {
    s32 i;
    void **p;
    if (data_ov000_021b54c8 == NULL) {
        return 0;
    }
    i = 0;
    p = data_ov000_021b54d0;
    for (; i < 32; p++, i++) {
        if (*p != NULL && a == func_ov000_0219887c(*p)[1]) {
            return (u32) data_ov000_021b54d0[i];
        }
    }
    return 0;
}

u8 func_ov000_0219b9c4(Unk0219887c *object) {
    return func_ov000_0219887c(object)[1];
}

u32 func_ov000_0219b9b4(Unk0219887c *object) {
    return func_ov000_0219887c(object)[0];
}

s32 func_ov000_0219b998(void) {
    s32 i = 0;
    void **slot = data_ov000_021b54d0;
    for (; i < 32; slot++, i++) {
        if (*slot == NULL) {
            return i;
        }
    }
    return -1;
}

void func_ov000_0219b964(void) {
    func_0214d018_inline(data_ov000_021b54d0, 0x80);
    func_0214d018_inline(data_ov000_021b5550, 0x100);
}

void **func_ov000_0219b958(s32 index) {
    return &data_ov000_021b54d0[index];
}

void **func_ov000_0219b8fc(u32 a, s32 b) {
    u8 c;

    for (c = 0; c < b; c++) {
        if (a == data_ov000_021b54c8->mUnk_33c.mUnk_f4[c]) {
            break;
        }
    }
    if (c >= b) {
        return NULL;
    }
    return func_ov000_0219b958(
        func_ov000_0219b9b4((Unk0219887c *) func_ov000_0219b9d4(data_ov000_021b54c8->mUnk_33c.mUnk_2b8[c])));
}

Unk021b5550 *func_ov000_0219b8f0(s32 index) {
    return &data_ov000_021b5550[index];
}

BOOL func_ov000_0219b8bc(u32 a) {
    s32 b;

    for (b = 0; b < 0x20; b++) {
        if (data_ov000_021b54d0[b] != NULL && a == func_ov000_0219887c(data_ov000_021b54d0[b])[1]) {
            return TRUE;
        }
    }
    return FALSE;
}

#include "code_02152500.h"
#include "code_02152934.h"
#include "code_02152a24.h"
#include "code_02152a7c.h"
#include "code_02152ab4.h"
#include "code_02152ac8.h"
#include "code_020205b0.h"
#include "Main/Unknown/code_02000b44.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02152ab0.h"

#pragma thumb on

u64 func_02152500(const void *a) {
    const Unk02152500 *p = a;
    u64 r;

    r = 0;
    if (p->mUnk_1c != 0) {
        r = func_02152988(p->mUnk_1c, p->mUnk_24);
    }
    return r;
}

u32 func_02152520(void *a, void *b) {
    Unk02152500 *p = a;
    Unk02152490 *q = b;
    u64 r;

    switch (func_02152a58(q)) {
        case 2:
            r = func_02152ab4(q);
            if (func_02152950(r, p->mUnk_24) != 0) {
                return func_02152934(r, p->mUnk_24);
            }
            return 0;
        case 3:
            return func_02152ab0(q);
        case 1:
            return -1;
        default:
            return 0;
    }
}

u64 func_02152584(const void *a) {
    const Unk02152490 *p = a;

    if (func_02152a58(p) == 2) {
        return func_02152ab4(p);
    }
    return 0;
}

void func_021525a8(void *a) {
    Unk02152500 *p = a;
    u32 t[0x100];

    p->mUnk_20 &= ~1;
    func_02020694(t, 0xedb88320);
    p->mUnk_3c = func_020205b0(t, p, 0x3c);
}

s32 func_021525e0(void *a) {
    Unk02152500 *p = a;

    if ((p->mUnk_20 & 1) == 1) {
        return 1;
    }
    return 0;
}

void func_021525f0(Unk02152500 *a, const Unk02152490 *b, u32 c) {
    u32 t[0x100];

    a->mUnk_10 = *b;
    a->mUnk_1c = c;
    func_02020694(t, 0xedb88320);
    a->mUnk_3c = func_020205b0(t, a, 0x3c);
    a->mUnk_20 |= 1;
}

s32 func_02152638(const void *a) {
    const Unk02152500 *p = a;
    Unk02151ddc s;

    if (func_02152a58(&p->mUnk_10) == 0) {
        return 1;
    }
    func_02151ddc(&s);
    if (s.mUnk_10 == 0) {
        return 0;
    }
    if (s.mUnk_00 == func_02152ac8(&p->mUnk_10)) {
        return 1;
    }
    return 0;
}

void func_02152690(void *a, u32 b) {
    func_021527ac(a, b);
}

#pragma thumb off

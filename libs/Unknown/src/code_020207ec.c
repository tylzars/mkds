#include "code_020207ec.h"
#include "code_02020eb0.h"
#include "code_02021764.h"

void func_02020e10(u32 a) {
    func_020207ec(1, a, 0, 0, 0);
}

void func_02020ddc(u32 a, u32 b, u32 c, u32 d) {
    func_020207ec(2, a, b, c, d);
}

void func_02020db0(u32 a) {
    func_020207ec(3, a, 0, 0, 0);
}

void func_02020d98(u32 a, u32 b) {
    func_020208a4(a, 0x1a, b, 2);
}

void func_02020d80(u32 a, u32 b) {
    func_020208a4(a, 6, b, 2);
}

void func_02020d68(u32 a, u32 b) {
    func_020208a4(a, 4, b, 1);
}

void func_02020d34(u32 a, u32 b, u32 c) {
    func_020207ec(0xa, a, b, c, 0);
}

void func_02020d0c(u32 a, u32 b, u32 c) {
    func_02020870(a, b, 0xa, c, 2);
}

void func_02020ce4(u32 a, u32 b, u32 c) {
    func_02020870(a, b, 0xc, c, 2);
}

void func_02020cbc(u32 a, u32 b, u32 c) {
    func_02020870(a, b, 9, c, 1);
}

void func_02020c94(u32 a, u32 b, u32 c) {
    func_02020870(a, b, 0x19, c, 1);
}

void func_02020c60(u32 a, u32 b, u32 c) {
    func_020207ec(9, a, b, c, 0);
}

void func_02020c2c(u32 a, u32 b, u32 c, u32 d) {
    func_020207ec(0xc, a, b, c, d);
}

void func_02020bbc(u32 a, u32 b, u32 c, u32 d) {
    int i;
    u32 m;

    m = c;
    for (i = 0; i < 8 && m != 0; i++, m >>= 1) {
        if (m & 1) {
            func_02021764(i);
        }
    }
    func_020207ec(0xd, a, b, c, d);
}

void func_02020b70(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    func_020207ec(0x11, c, d, (a << 31) | (b << 30) | (e << 29) | (f << 28) | (g << 27), 0);
}

void func_02020b2c(s32 a, u32 b, u32 c, UnkFunc *d, void *e) {
    u32 t;

    t = func_02021734(a, d, e);
    func_020207ec(0x12, a, b, c, t);
}

void func_02020af8(u32 a, u32 b, u32 c) {
    func_020207ec(8, a, b, c, 0);
}

void func_02020acc(u32 a, u32 b) {
    func_020207ec(0x1a, a, b, 0, 0);
}

void func_02020aa0(u32 a, u32 b) {
    func_020207ec(0x1b, a, b, 0, 0);
}

void func_02020a6c(u32 a, u32 b, u32 c) {
    func_020207ec(0x14, a, b, c, 0);
}

void func_02020a14(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j) {
    func_020207ec(0xe, a | (i << 16), c, (g << 24) | (h << 22) | f, (d << 26) | (b << 24) | (j << 16) | e);
}

void func_020209e8(void *a, void *b) {
    func_020207ec(0x1e, (u32) a, (u32) b, 0, 0);
}

void func_020209bc(void *a, void *b) {
    func_020207ec(0x1f, (u32) a, (u32) b, 0, 0);
}

void func_02020990(void *a, void *b) {
    func_020207ec(0x20, (u32) a, (u32) b, 0, 0);
}

void func_02020964(u32 a) {
    func_020207ec(0x17, a, 0, 0, 0);
}

void func_02020930(u32 a, u32 b, u32 c, u32 d) {
    func_020207ec(0x19, a, b, c, d);
}

void func_02020904(u32 a) {
    func_020207ec(0x18, a, 0, 0, 0);
}

void func_020208d8(void) {
    func_020207ec(0x18, 0xffffffff, 0, 0, 0);
}

void func_020208a4(u32 a, u32 b, u32 c, u32 d) {
    func_020207ec(6, a, b, c, d);
}

void func_02020870(u32 a, u32 b, u32 c, u32 d, u32 e) {
    func_020207ec(7, a | (e << 24), b, c, d);
}

void func_02020844(u32 a) {
    func_020207ec(0x16, a, 0, 0, 0);
}

void func_020207ec(u32 a, u32 b, u32 c, u32 d, u32 e) {
    Unk020207ec *p;

    p = func_020213ec(1);
    if (p == 0) {
        return;
    }
    p->mUnk_04 = a;
    p->mUnk_08 = b;
    p->mUnk_0c = c;
    p->mUnk_10 = d;
    p->mUnk_14 = e;
    func_020213a4(p);
}

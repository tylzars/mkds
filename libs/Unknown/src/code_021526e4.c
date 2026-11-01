#include "code_021526e4.h"
#include "code_02152500.h"
#include "code_02152a7c.h"
#include "code_02152ac8.h"
#include "code_020205b0.h"
#include "code_0200d118.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02152ac4.h"
#include "code_0200f5ac.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma thumb on

s32 func_021526e4(const Unk02152490 *a) {
    Unk02151ddc s;

    func_02151ddc(&s);
    if (s.mUnk_10 != 0) {
        if (func_02152ac8(a) == s.mUnk_00) {
            return 1;
        }
        return 0;
    }
    if (func_02152ac8(a) == s.mUnk_08) {
        return 1;
    }
    return 0;
}

void func_02152744(Unk02152490 *a) {
    u64 t;
    u64 r;
    Unk02151ddc s;

    t = func_0200f5ac();
    func_02151ddc(&s);
    if (s.mUnk_10 != 0) {
        func_02152a8c(a, ((u32 *) &s)[0], ((u32 *) &s)[1]);
    } else {
        func_02152a8c(a, ((u32 *) &s)[2], ((u32 *) &s)[3]);
    }
    r = t * 0x5d588b656c078965ull + 0x269ec3;
    func_02152a88(a, r >> 32);
    func_021529e0(a, 1);
}

void func_021527ac(Unk02152500 *a, u32 b) {
    u32 t[0x100];

    func_0214d168(a, 0, 0x40);
    a->mUnk_00 = 0x40;
    a->mUnk_1c = 0;
    a->mUnk_24 = b;
    func_02152744(&a->mUnk_04);
    func_021529e0(&a->mUnk_10, 0);
    func_02020694(t, 0xedb88320);
    a->mUnk_3c = func_020205b0(t, a, 0x3c);
    a->mUnk_20 |= 1;
}

void func_02152808(const Unk02152490 *a, u32 b, char *c) {
    char d[0x15];
    char e[0x15];

    func_0215286c(func_02152ac8(a), 0x2b, d);
    func_0215286c(func_02152ac4(a), 0x20, e);
    func_0200d9e0(c, 0x15, data_0216f2a0, d, (u8) (b >> 24), (u8) (b >> 16), (u8) (b >> 8), (u8) b, e);
}

void func_0215286c(u64 a, s32 n, char *c) {
    s32 i;
    s32 len;
    const s8 *t;

    len = (n + 4) / 5;
    t = data_0216f2b0;
    for (i = 0; i < len; i++) {
        *(c + len - 1 - i) = t[a & 0x1f];
        a = a >> 5;
    }
    c[len] = 0;
}

u64 func_021528bc(const void *a) {
    const s8 *p = a;
    u64 s;
    u64 m;
    s32 i;

    s = 0;
    m = 1;
    for (i = 0; i < 12; i++) {
        s += m * (s64) (*(p + 11 - i) - 0x30);
        m *= 10;
    }
    return s;
}

#pragma thumb off

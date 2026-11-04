#include "code_021510a4.h"
#include "code_02151fc4.h"
#include "code_021519d4.h"
#include "code_02151868.h"
#include "code_0200f5ac.h"
#include "code_0214d018.h"
#include "code_0214d93c.h"
#include "code_0200fc8c.h"
#include "code_021522a0.h"
#include "Main/Unknown/code_0215228c.h"

#pragma thumb on

s64 func_02152244(const u32 *a, const u32 *b) {
    s32 c;
    s32 d;
    c = func_021522a0(a);
    if (c == -1) {
        return -1;
    }
    d = func_0215228c((u32) b);
    return (s64) d + (s64) c * 0x15180;
}

u64 func_0215211c(u32 a, u32 b, u32 c, u32 d) {
    union {
        u64 v;
        u8 b[8];
    } e;
    u8 f[8];
    s32 h;
    u8 *i;
    u8 *k;
    const u8 *j;
    e.v = (((u64) a & 0xffff) << 27) | ((((u64) b & 0xffffff) << 3) | (((u64) d & 3) | (((u64) c & 1) << 2)));
    i = e.b;
    for (h = 0; h < 6; h++) {
        *i ^= 0xd6;
        i++;
    }
    h = 0;
    i = e.b;
    for (; h < 5; h++) {
        *i = (data_usa_02161738[(*i >> 4) & 0xf] << 4) | data_usa_02161738[*i & 0xf];
        i++;
    }
    MemCopy(e.b, f, 8);
    h = 0;
    k = f;
    j = data_usa_02161730;
    for (; h < 5; h++) {
        e.b[*j] = *k;
        k++;
        j++;
    }
    e.b[7] = 0;
    e.b[6] = 0;
    e.b[5] &= 7;
    e.v <<= 1;
    e.b[0] |= (e.b[5] >> 3) & 1;
    i = e.b;
    for (h = 0; h < 6; h++) {
        *i ^= 0x67;
        i++;
    }
    e.b[7] = 0;
    e.b[6] = 0;
    e.b[5] &= 7;
    return e.v;
}

u32 func_02151fc4(Unk021510a4 *a) {
    u32 b;
    u32 c;
    u8 d[6];
    u32 e[4];
    u32 f[3];
    s64 g;
    u32 h;
    func_02151910(a);
    func_0214e0f4();
    if (func_0214e038(e) != 0) {
        return 0;
    }
    if (func_0214df78(f) != 0) {
        return 0;
    }
    g = func_02152244(e, f);
    h = g;
    if (g < 0) {
        return 0;
    }
    if (func_0200f6e4() != 0) {
        h += (u32) func_0200f5ac;
    }
    func_0200fe58(d);
    b = (u8) ((d[0] << 16 | d[1] << 8 | d[2]) != 0x9bf);
    c = d[5];
    c |= (d[3] << 16 | d[4] << 8);
    h = h * 0x5d588b65 + 0x269ec3;
    a->mUnk_10 = ((h >> 16) * 1000) >> 16;
    a->mUnk_00 = 0;
    if (a->mUnk_12 == 0) {
        a->mUnk_08 = 0;
        while (a->mUnk_08 == 0) {
            h = h * 0x5d588b65 + 0x269ec3;
            while (h == 0) {
                h = h * 0x5d588b65 + 0x269ec3;
            }
            a->mUnk_12 = h;
            a->mUnk_08 = func_0215211c(a->mUnk_12, c, b, 0);
        }
    } else {
        a->mUnk_08 = 0;
        while (a->mUnk_08 == 0) {
            a->mUnk_12++;
            a->mUnk_08 = func_0215211c(a->mUnk_12, c, b, 0);
        }
    }
    return 1;
}

#pragma thumb off

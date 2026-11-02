#include "00/code_021967b4.h"
#include "00/unk_021b3000.h"
#include "code_0213442c.h"
#include "code_02139f70.h"
#include "code_0213a460.h"

s32 func_ov000_021967b4(const u8 *a, const void *v1, void *v2, s32 d) {
    const u8 *b = v1;
    u8 *c = v2;
    const u8 *p;
    const u8 *q;
    s32 i;
    s8 f;
    s8 g;

    if (a == 0) {
        func_0213442c(data_ov000_021b3ad4, data_ov000_021b3a1c, 0, 0x10d);
    }
    if (b == 0) {
        func_0213442c(data_ov000_021b3a2c, data_ov000_021b3a1c, 0, 0x10e);
    }
    if (c == 0) {
        func_0213442c(data_ov000_021b3a38, data_ov000_021b3a1c, 0, 0x10f);
    }
    if (d <= 0) {
        func_0213442c(data_ov000_021b3ae4, data_ov000_021b3a1c, 0, 0x110);
    }
    f = (s8) *b;
    p = strstr(a, b);
    if (p == 0) {
        return 0;
    }
    q = p + strlen(b);
    for (i = 0; i < d - 1 && (g = (s8) q[i]) != 0 && g != f; i++) {
        c[i] = g;
    }
    c[i] = 0;
    return 1;
}

s32 func_ov000_02196870(Unk0218f960 *a, const u8 *b, s32 c) {
    Unk0218f960_00 *r;
    s32 t;
    u8 d[0x10];

    r = a->mUnk_00;
    if (strncmp(b, data_ov000_021b3aec, 7) == 0) {
        if (func_ov000_021967b4(b, data_ov000_021b3af4, d, 0x10) != 0) {
            r->mUnk_418 = func_0213bf90(d);
        }
        if (func_ov000_021967b4(b, data_ov000_021b3afc, r->mUnk_000, 0x100) == 0) {
            r->mUnk_000[0] = 0;
        }
        if (c != 0) {
            t = (strstr(b, data_ov000_021b3b08) != 0);
            func_ov000_02190f4c(a, 4, (t != 0) ? 1 : 0);
        }
        return 1;
    }
    return 0;
}

void func_ov000_0219690c(Unk0218f960 *a, const u8 *b, ...) {}

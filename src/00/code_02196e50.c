#include "00/code_02196e50.h"

s32 func_ov000_02197064(const s8 *a, u32 b, u8 *c, Unk021a8f84 **d) {
    Unk021a8f84 *f = 0;
    u16 e = b;
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;
    c[3] = 0;
    c[4] = 0;
    c[5] = 0;
    c[6] = 0;
    c[7] = 0;
    c[1] = 2;
    *(u16 *) (c + 2) = ((e >> 8) & 0xff) | ((e << 8) & 0xff00);
    if (a == 0) {
        *(u32 *) (c + 4) = 0;
    } else {
        *(u32 *) (c + 4) = func_ov000_0218e374((u32) a);
    }
    if (*(u32 *) (c + 4) == -1) {
        f = func_ov000_021a8f84((const u8 *) a);
        if (f == 0) {
            return 0;
        }
        *(u32 *) (c + 4) = **f->mUnk_0c;
    }
    if (d != 0) {
        *d = f;
    }
    return 1;
}

void func_ov000_02197020(s32 a, s32 b, s32 c, s32 d, s32 e, UnkFunc *f, s32 g) {
    Unk02197020 h;
    h.mUnk_18 = f;
    h.mUnk_14 = g;
    h.mUnk_04 = b;
    h.mUnk_00 = a;
    h.mUnk_08 = c;
    h.mUnk_0c = d;
    h.mUnk_10 = e;
    if (data_ov000_021b4e5c == 0) {
        data_ov000_021b4e5c = (int *) func_ov000_0218dc94(0x1c, 2, 0);
    }
    func_ov000_0218dbc0(data_ov000_021b4e5c, &h);
}

void func_ov000_02196f8c(s8 *a, s32 b, s32 c, UnkFunc *d, s32 e) {
    s32 g = 0;
    Unk021b3b68 f = data_ov000_021b3b68;
    if (data_ov000_021b3b2c != -1) {
        g = func_ov000_02197220(a, b);
    }
    if (g <= 0) {
        func_ov000_02197634();
        data_ov000_021b3b30 = data_ov000_021b3b98;
        func_ov000_021971ec(f.mUnk_00, 0xf);
        if (d != 0) {
            d(c, 0, 0, f.mUnk_00, e);
        }
    } else {
        func_ov000_02197020(0, c, 0, 0, 0, d, e);
    }
}

void func_ov000_02196e50(s32 a, s32 b, s32 c, s32 d, const u8 *e, s32 f, UnkFunc *g, s32 h, s32 i) {
    Unk021b3c08 j = data_ov000_021b3c08;
    s8 k[0x200];
    s32 m;
    s8 *n;
    s32 l;
    data_ov000_021b3b30 = data_ov000_021b3b98;
    func_ov000_021971ec(j.mUnk_00, 0x3e);
    if (c == 0 || c == 2) {
        if (g != 0) {
            g(a, b, c, d, 0, 0, h);
        }
        return;
    }
    m = func_02135014((u8 *) k, (const u8 *) j.mUnk_00, b, c, d, i, a, f);
    l = m + f;
    if (l < 0x1e0) {
        func_02134eb8(k + m, e, f);
        n = k;
    } else {
        n = (s8 *) func_ov000_021a3690(l + 0x100);
        func_02134eb8(n, k, m);
        func_02134eb8(n + m, e, f);
    }
    if (data_ov000_021b3b2c != -1) {
        m = func_ov000_02197220(n, l);
    }
    if (m <= 0) {
        func_ov000_02197634();
        if (g != 0) {
            g(a, b, c, d, 0, 0, h);
        }
    } else {
        func_ov000_02197020(2, a, b, c, d, g, h);
    }
    if (n != k) {
        func_ov000_021a3668(n);
    }
}

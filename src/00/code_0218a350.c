#include "00/code_0218a350.h"
#include "code_02150228.h"
#include "code_02133048.h"
#include "code_0214d018.h"
#include "code_021507c8.h"

void func_ov000_0218a5b0(const u8 *a, u8 *b) {
    Unk0218a5b0 t = data_ov000_021b2118;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 m;
    u32 v;
    u32 w;
    u8 *p;
    func_ov000_0218a350(a, b, 32, 24);
    for (j = 0; j < 24; j++) {
        b[j] ^= data_ov000_021b20f4[j];
    }
    for (i = 0; i < 24; i++) {
        k = (u8) i;
        l = k;
        v = b[i];
        while (t.mUnk_00[l] != 0xff) {
            p = &t.mUnk_00[l];
            l = t.mUnk_00[l];
            w = b[l];
            b[t.mUnk_00[k]] = v;
            k = l;
            *p = 0xff;
            v = w;
        }
    }
    for (m = 0; m < 24; m++) {
        b[m] ^= data_ov000_021b20e8[m];
    }
}

void func_ov000_0218a57c(const u8 *a, u8 *b) {
    Hash16State c;
    u8 d[20];
    Hash16Init((u32) &c);
    Hash16Update(&c, a, 24);
    Hash16Final(d, &c);
    MI_CpuCopy8(d + 3, b, 13);
}

void func_ov000_0218a48c(const u8 *a, u8 *b) {
    u8 t[13];
    u8 *p;
    const u8 *q;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 m;
    s32 n;
    s32 o;
    for (i = 0; i < 13; i++) {
        b[i] = a[i] ^ a[i % 7 + 13];
    }
    for (j = 0; j < 7; j++) {
        b[j + 3] ^= a[j + 13];
    }
    for (k = 0; k < 13; k++) {
        b[k] ^= data_ov000_021b20ec[k];
    }
    MI_CpuCopy8(b, t, 13);
    l = 0;
    p = t;
    q = data_ov000_021b0790;
    for (; l < 13; l++) {
        b[*q] = *p;
        p++;
        q++;
    }
    for (m = 0; m < 13; m++) {
        b[m] ^= data_ov000_021b20f0[m];
    }
    for (n = 0; n < 13; n++) {
        u8 v = b[n];
        b[n] = (data_ov000_021b07a0[(v >> 4) & 15] << 4) | data_ov000_021b07a0[v & 15];
    }
    for (o = 0; o < 3; o++) {
        b[o] ^= b[o + 6];
        b[o + 3] ^= b[o + 9];
        b[o + 6] ^= b[o + 3];
        b[o + 9] ^= b[o];
        b[12] ^= b[o];
    }
}

s32 func_ov000_0218a444(u32 c) {
    s32 d;
    if (c >= 0x41 && c <= 0x5a) {
        return c - 0x41;
    }
    if (c >= 0x61 && c <= 0x7a) {
        d = c - 0x61;
        return d + 0x1a;
    }
    if (c >= 0x30 && c <= 0x39) {
        d = c - 0x30;
        return d + 0x34;
    }
    if (c == 0x2b) {
        return 0x3e;
    }
    if (c == 0x2f) {
        return 0x3f;
    }
    return -(c != 0x3d);
}

s32 func_ov000_0218a350(const u8 *a, u8 *b, s32 c, u32 d) {
    s32 f;
    s32 g;
    s32 h;
    u32 t;
    s32 i;
    u32 w;
    u32 x;
    s32 m;
    if (d >= (u32) (c * 3) >> 2) {
        f = c & 3;
        g = c - f;
    } else {
        return -1;
    }
    h = 0;
    for (; h < g; h += 4) {
        t = 0;
        for (i = 0; i < 4; i++) {
            t |= func_ov000_0218a444(a[h + i]) << ((3 - i) * 6);
        }
        w = t;
        for (m = 0; m < 3; m++) {
            b[h / 4 * 3 + m] = ((u8 *) &w)[2 - m];
        }
    }
    if (f != 0) {
        t = 0;
        x = 0;
        for (i = 0; i < f; i++) {
            t |= func_ov000_0218a444(a[g + i]) << ((3 - i) * 6);
            x |= t;
        }
        for (i = 0; i < f; i++) {
            b[g * 3 / 4 + i] = ((u8 *) &x)[2 - i];
        }
    }
    return (u32) (c * 3) >> 2;
}

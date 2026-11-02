#include "00/code_0218e0fc.h"
#include "00/code_0218e2a4.h"
#include "00/code_021acee0.h"
#include "00/code_021acee8.h"
#include "00/code_021acef0.h"
#include "00/unk_021b0000.h"
#include "00/unk_021b2000.h"
#include "code_02135014.h"

s32 func_ov000_0218e284(s32 b, s32 c) {
    s32 a = c - b;
    s32 r;
    if (a == 0) {
        return b;
    }
    r = func_ov000_0218e2c0() % a;
    return r + b;
}

void func_ov000_0218e220(const s8 *c, u8 *d, s32 e) {
    u8 a[3];
    s32 b = 0;
    for (; b < e; b++) {
        a[b] = c[b];
    }
    for (; b < 3; b++) {
        a[b] = 0;
    }
    d[0] = a[0] >> 2;
    d[1] = ((a[0] & 3) << 4) | (a[1] >> 4);
    d[2] = ((a[1] & 0xf) << 2) | (a[2] >> 6);
    d[3] = a[2] & 0x3f;
}

void func_ov000_0218e15c(const void *h, void *l, s32 m, s32 n) {
    const s8 *a = h;
    s8 *b = l;
    s8 *g = b;
    const s8 *c;
    s32 d = m;
    s8 *e;
    s8 f;
    switch (n) {
        case 1:
            c = data_ov000_021b07b0;
            break;
        case 2:
            c = data_ov000_021b07b4;
            break;
        default:
            c = data_ov000_021b07b8;
            break;
    }
    while (d > 0) {
        func_ov000_0218e220(a, (u8 *) b, m >= 3 ? 3 : m);
        b += 4;
        a += 3;
        d -= 3;
    }
    e = b;
    if (m % 3 == 1) {
        e = b - 2;
    } else if (m % 3 == 2) {
        e = b - 1;
    }
    *b = 0;
    while (b > g) {
        b--;
        if (b >= e) {
            *b = c[2];
        } else {
            f = *b;
            if (f <= 25) {
                *b = f + 65;
            } else if (f <= 51) {
                *b = f + 71;
            } else if (f <= 61) {
                *b = f - 4;
            } else if (f == 62) {
                *b = c[0];
            } else if (f == 63) {
                *b = c[1];
            }
        }
    }
}

void func_ov000_0218e130(const u8 *c, u8 *d) {
    u32 a;
    s32 b;
    a = 0;
    b = 0;
    for (; a < 16; a++) {
        sprintf(d + b, data_ov000_021b23a4, c[a]);
        b += 2;
    }
}

void func_ov000_0218e0fc(const u8 *c, s32 d, u8 *e) {
    u8 a[16];
    Unk02150610 b;
    func_ov000_021acef0(&b);
    func_ov000_021acee8(&b, c, d);
    func_ov000_021acee0(a, &b);
    func_ov000_0218e130(a, e);
}

#include "00/code_021a44a0.h"
#include "00/code_021a4610.h"

void func_ov000_021a4578(const u8 *a, s32 b, u8 *c) {
    u8 d[7];
    s32 e;
    s32 f;
    u8 *g;
    s32 h;
    u8 i;
    u8 j;

    e = 0;
    if (b > 0) {
        do {
            for (f = 0, g = d; f <= 2; f++, e++) {
                if (e < b) {
                    *g = *a++;
                } else {
                    *g = 0;
                }
                g++;
            }
            i = d[0];
            d[3] = i >> 2;
            j = d[1];
            d[4] = ((i & 3) << 4) + (j >> 4);
            i = d[2];
            d[5] = ((j & 0xf) << 2) + (i >> 6);
            d[6] = i & 0x3f;
            for (h = 0, g = &d[3]; h <= 3; h++) {
                *c++ = func_ov000_021a4610(*g);
                g++;
            }
        } while (e < b);
    }
    *c = 0;
}

void func_ov000_021a44a0(u8 *a, s32 b, u8 *c, s32 d) {
    u8 e[0x100];
    s16 o;
    u8 *n;
    u8 g;
    u8 h;
    u8 i;
    u8 j;
    s16 k;
    s16 l;
    u8 *m;

    for (k = 0; k < 0x100; k++) {
        e[k] = k;
    }
    g = 0;
    h = 0;
    l = 0;
    m = e;
    do {
        h = (m[0] + a[g] + h) % 0x100;
        g = (g + 1) % b;
        func_ov000_021a4648(m, e + h);
        m++;
        l++;
    } while (l < 0x100);
    i = 0;
    h = 0;
    o = 0;
    if (d > 0) {
        do {
            i = (i + c[o] + 1) % 0x100;
            n = e + i;
            h = (*n + h) % 0x100;
            func_ov000_021a4648(n, e + h);
            j = (*n + e[h]) % 0x100;
            c[o] ^= e[j];
            o++;
        } while (o < d);
    }
}

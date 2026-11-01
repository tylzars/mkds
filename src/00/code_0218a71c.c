#include "00/code_0218a71c.h"
#include "code_02133048.h"

u8 func_ov000_0218a71c(Unk0218a71c *p, u8 x) {
    u8 a;
    u8 b;
    u8 c;
    u32 e;
    a = p->mUnk_100;
    p->mUnk_100 = a + 1;
    p->mUnk_101 = p->mUnk_101 + p->mUnk_000[a];
    c = p->mUnk_104;
    b = p->mUnk_000[c];
    p->mUnk_000[c] = p->mUnk_000[p->mUnk_101];
    p->mUnk_000[p->mUnk_101] = p->mUnk_000[p->mUnk_103];
    p->mUnk_000[p->mUnk_103] = p->mUnk_000[p->mUnk_100];
    p->mUnk_000[p->mUnk_100] = b;
    p->mUnk_102 = p->mUnk_102 + p->mUnk_000[b];
    e = x ^ p->mUnk_000[(p->mUnk_000[p->mUnk_102] + p->mUnk_000[p->mUnk_100]) & 0xff];
    p->mUnk_103 =
        e ^ p->mUnk_000[p->mUnk_000[(p->mUnk_000[p->mUnk_101] + (p->mUnk_000[p->mUnk_103] + p->mUnk_000[p->mUnk_104])) &
                                    0xff]];
    p->mUnk_104 = x;
    return p->mUnk_103;
}

void func_ov000_0218a7bc(Unk0218a71c *p, const u8 *v1, u32 n) {
    u8 j;
    u32 k;
    s32 i;
    u32 l;
    u8 t;
    if (n < 1) {
        func_ov000_0218a854(p);
        return;
    }
    for (i = 0; i < 256; i++) {
        p->mUnk_000[i] = i;
    }
    k = 0;
    j = 0;
    for (l = 255; (s32) l >= 0; l--) {
        u8 r = func_ov000_0218a898(p, l, v1, n, &j, &k);
        t = p->mUnk_000[l];
        p->mUnk_000[l] = p->mUnk_000[r];
        p->mUnk_000[r] = t;
    }
    p->mUnk_100 = p->mUnk_000[1];
    p->mUnk_101 = p->mUnk_000[3];
    p->mUnk_102 = p->mUnk_000[5];
    p->mUnk_103 = p->mUnk_000[7];
    p->mUnk_104 = p->mUnk_000[j];
    j = 0;
    k = 0;
}

void func_ov000_0218a854(Unk0218a71c *p) {
    s32 i;
    u32 v;
    p->mUnk_100 = 1;
    p->mUnk_101 = 3;
    p->mUnk_102 = 5;
    p->mUnk_103 = 7;
    p->mUnk_104 = 11;
    i = 0;
    v = 255;
    for (; i < 256; i++, v--) {
        p->mUnk_000[i] = v;
    }
}

u8 func_ov000_0218a898(Unk0218a71c *p, u32 n, const u8 *v1, u32 m, u8 *j, u32 *k) {
    u32 v2;
    u32 v;
    u32 c;
    if (n == 0) {
        return 0;
    }
    c = 0;
    for (v2 = 1; v2 < n; v2 = v2 * 2 + 1) {
    }
    do {
        u32 q = (*k)++;
        *j = p->mUnk_000[*j] + v1[q];
        if (*k >= m) {
            *k = 0;
            *j = *j + m;
        }
        v = v2 & *j;
        c++;
        if (c > 11) {
            v = v % n;
        }
    } while (v > n);
    return v;
}

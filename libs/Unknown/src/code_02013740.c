#include "code_02013740.h"
#include "code_02013bdc.h"

void *func_02013b00(void *a, u32 b) {
    u8 *p;
    u8 *t;

    p = (u8 *) a + 8;
    t = p + *(u16 *) ((u8 *) a + 0xe);
    return (u8 *) a + *(u32 *) (t + *(u16 *) t * b + 4);
}

void *func_02013ae4(void *a) {
    return func_02013c18(a, 0x30505442, 0x30544150);
}

void *func_02013ac4(void *a, u32 b) {
    u8 *p;
    u8 *t;

    p = (u8 *) a + 8;
    t = p + *(u16 *) ((u8 *) a + 0xe);
    return (u8 *) a + *(u32 *) (t + *(u16 *) t * b + 4);
}

void *func_02013aa8(void *a) {
    return func_02013c18(a, 0x30415442, 0x30545253);
}

void *func_02013a88(void *a, u32 b) {
    u8 *p;
    u8 *t;

    p = (u8 *) a + 8;
    t = p + *(u16 *) ((u8 *) a + 0xe);
    return (u8 *) a + *(u32 *) (t + *(u16 *) t * b + 4);
}

void *func_02013a6c(void *a) {
    return func_02013c18(a, 0x30414d42, 0x3054414d);
}

void *func_02013a4c(void *a, u32 b) {
    u8 *p;
    u8 *t;

    p = (u8 *) a + 8;
    t = p + *(u16 *) ((u8 *) a + 0xe);
    return (u8 *) a + *(u32 *) (t + *(u16 *) t * b + 4);
}

void *func_02013a30(void *a) {
    return func_02013c18(a, 0x30414342, 0x30544e4a);
}

void *func_020138b4(const void *a, const u32 *key) {
    const Unk02013754 *p;
    const u8 *t;
    const u8 *n;
    const u8 *e;
    const u8 *tab;
    u32 i;
    u32 j;
    u8 c;
    u8 d;
    u32 k0;
    u32 k1;
    u32 k2;
    u32 k3;

    p = a;
    if (p->mUnk_01 < 0x10) {
        k0 = key[0];
        k1 = key[1];
        k2 = key[2];
        k3 = key[3];
        for (i = 0; i < p->mUnk_01; i++) {
            e = (const u8 *) p + p->mUnk_06;
            tab = e + *(u16 *) (e + 2);
            e = tab + i * 16;
            if (*(u32 *) e == k0 && *(u32 *) (e + 4) == k1 && *(u32 *) (e + 8) == k2 && *(u32 *) (e + 12) == k3) {
                tab = (const u8 *) p + p->mUnk_06;
                return (void *) (tab + 4 + *(u16 *) tab * i);
            }
        }
    } else {
        t = p->mUnk_08;
        i = t[1];
        if (i != 0) {
            n = t + i * 4;
            c = n[0];
            d = t[0];
            while (d > c) {
                j = (n + ((key[c >> 5] >> (c & 0x1f)) & 1))[1];
                c = t[j * 4];
                d = n[0];
                n = t + j * 4;
            }
            tab = (const u8 *) p + p->mUnk_06;
            tab += *(u16 *) (tab + 2);
            e = tab + n[3] * 16;
            if (*(u32 *) e == key[0] && *(u32 *) (e + 4) == key[1] && *(u32 *) (e + 8) == key[2] &&
                *(u32 *) (e + 12) == key[3]) {
                tab = (const u8 *) p + p->mUnk_06;
                return (void *) (tab + 4 + *(u16 *) tab * n[3]);
            }
        }
    }
    return 0;
}

int func_02013754(const void *a, const u32 *key) {
    const Unk02013754 *p;
    const u8 *t;
    const u8 *n;
    const u8 *e;
    const u8 *tab;
    u32 i;
    u32 j;
    u8 c;
    u8 d;
    u32 k0;
    u32 k1;
    u32 k2;
    u32 k3;

    p = a;
    if (p->mUnk_01 < 0x10) {
        k0 = key[0];
        k1 = key[1];
        k2 = key[2];
        k3 = key[3];
        for (i = 0; i < p->mUnk_01; i++) {
            e = (const u8 *) p + p->mUnk_06;
            tab = e + *(u16 *) (e + 2);
            e = tab + i * 16;
            if (*(u32 *) e == k0 && *(u32 *) (e + 4) == k1 && *(u32 *) (e + 8) == k2 && *(u32 *) (e + 12) == k3) {
                return i;
            }
        }
    } else {
        t = p->mUnk_08;
        i = t[1];
        if (i != 0) {
            n = t + i * 4;
            c = n[0];
            d = t[0];
            while (d > c) {
                j = (n + ((key[c >> 5] >> (c & 0x1f)) & 1))[1];
                c = t[j * 4];
                d = n[0];
                n = t + j * 4;
            }
            tab = (const u8 *) p + p->mUnk_06;
            tab += *(u16 *) (tab + 2);
            e = tab + n[3] * 16;
            if (*(u32 *) e == key[0] && *(u32 *) (e + 4) == key[1] && *(u32 *) (e + 8) == key[2] &&
                *(u32 *) (e + 12) == key[3]) {
                return n[3];
            }
        }
    }
    return -1;
}

void *func_02013740(void *a, u32 b) {
    u8 *p;

    p = (u8 *) a + *(u16 *) ((u8 *) a + 0xc);
    return (u8 *) a + *(u32 *) (p + b * 4);
}

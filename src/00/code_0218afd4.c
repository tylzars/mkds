#include "00/code_0218afd4.h"
#include "00/code_0218b280.h"
#include "00/code_0218cdc4.h"
#include "code_02133274.h"
#include "code_02135014.h"
#include "code_02139f70.h"
#include "code_0214177c.h"

u32 func_ov000_0218b1e0(const char *s) {
    Unk021b21ac t;
    u32 i;
    const char **p;
    t = data_ov000_021b21ac;
    p = t.mUnk_00;
    for (i = 0; i < 2; i++) {
        if (strcmp(s, *p) == 0) {
            return 0;
        }
        p++;
    }
    return 1;
}

s8 *func_ov000_0218b19c(s8 *s, s32 c) {
    s8 *a;
    s8 *b;
    s32 d;
    if (s != NULL) {
        data_ov000_021b4d14 = s;
    }
    a = data_ov000_021b4d14;
    while ((d = *(b = data_ov000_021b4d14)) != 0 && d != c) {
        data_ov000_021b4d14++;
    }
    if (b == a) {
        a = NULL;
    }
    if (d != 0) {
        data_ov000_021b4d14++;
        *b = 0;
    }
    return a;
}

void func_ov000_0218b148(Unk0218af28 *e, s8 *v1) {
    s8 *a;
    s8 *b;
    a = func_ov000_0218b19c(v1 + 1, 0x5c);
    while (a != NULL) {
        b = func_ov000_0218b19c(NULL, 0x5c);
        if (b == NULL) {
            b = data_ov000_021b21c4;
        }
        if (func_ov000_0218b1e0((const char *) a) != 0) {
            func_ov000_0218b380(e, (const char *) a, (const char *) b);
        }
        a = func_ov000_0218b19c(NULL, 0x5c);
    }
}

void func_ov000_0218b010(Unk0218af28 *e, s8 *v1, s32 n) {
    Unk0218b010 t;
    s8 *s;
    s8 *p;
    s8 *v;
    s32 a;
    s32 i;
    s32 b;
    s32 c;
    s32 d;
    s32 f;
    u16 w;
    while (*v1 != 0) {
        f = func_ov000_0218d0c8(v1, n);
        if (f < 0) {
            return;
        }
        p = v1;
        v1 += f;
        n -= f;
        f = func_ov000_0218d0c8(v1, n);
        if (f < 0) {
            return;
        }
        v = v1;
        v1 += f;
        n -= f;
        func_ov000_0218b380(e, (const char *) p, (const char *) v);
    }
    v1++;
    n--;
    for (i = 0; i < 2; i++) {
        if (n < 2) {
            return;
        }
        __memcpy(t.mUnk_00, v1, 2);
        w = *(u16 *) t.mUnk_00;
        *(u16 *) t.mUnk_00 = ((w >> 8) & 0xff) | ((w << 8) & 0xff00);
        v1 += 2;
        n -= 2;
        s = v1;
        a = 0;
        while (*v1 != 0) {
            f = func_ov000_0218d0c8(v1, n);
            if (f < 0 || f > 100) {
                return;
            }
            a++;
            v1 += f;
            n -= f;
        }
        v1++;
        n--;
        b = 0;
        while (b < *(u16 *) t.mUnk_00) {
            p = s;
            c = 0;
            while (c < a) {
                d = func_ov000_0218d0c8(v1, n);
                if (d < 0) {
                    return;
                }
                sprintf(t.mUnk_02, data_ov000_021b21bc, p, b);
                func_ov000_0218b380(e, t.mUnk_02, (const char *) v1);
                v1 += d;
                n -= d;
                p += strlen((const char *) p) + 1;
                c++;
            }
            b++;
        }
    }
}

u32 func_ov000_0218afd4(const s8 *v1, u32 v2) {
    s32 c;
    u32 a;
    a = 0;
    c = *v1;
    while (c != 0) {
        if (c >= 0 && c < 0x80) {
            c = data_0215d184[c];
        }
        a *= 0x9ccf9319;
        a += c;
        v1++;
        c = *v1;
    }
    return a % v2;
}

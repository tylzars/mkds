#include "00/code_0218afd4.h"
#include "00/code_0218b280.h"
#include "00/code_0218d0c8.h"
#include "code_02133274.h"
#include "code_02135014.h"
#include "code_02139f70.h"
#include "code_0214177c.h"

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

// non-matching: the original recomputes the stack address of the count halfword (add r0, sp, #44) before its ldrh, ours
// reuses r0 from the two byte stores (one add fewer, later words shift by 2 bytes)
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
        f = func_ov000_0218d0c8((int) v1, n);
        if (f < 0) {
            return;
        }
        p = v1;
        v1 += f;
        n -= f;
        f = func_ov000_0218d0c8((int) v1, n);
        if (f < 0) {
            return;
        }
        v = v1;
        v1 += f;
        n -= f;
        func_ov000_0218b380(e, (u8 *) p, (u8 *) v);
    }
    v1++;
    n--;
    for (i = 0; i < 2; i++) {
        if (n < 2) {
            return;
        }
        t.mUnk_00[0] = ((u8 *) v1)[0];
        t.mUnk_00[1] = ((u8 *) v1)[1];
        w = *(u16 *) t.mUnk_00;
        *(u16 *) t.mUnk_00 = ((w >> 8) & 0xff) | ((w << 8) & 0xff00);
        v1 += 2;
        n -= 2;
        s = v1;
        a = 0;
        while (*v1 != 0) {
            f = func_ov000_0218d0c8((int) v1, n);
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
                d = func_ov000_0218d0c8((int) v1, n);
                if (d < 0) {
                    return;
                }
                func_02135014(t.mUnk_02, data_ov000_021b21bc, p, b);
                func_ov000_0218b380(e, t.mUnk_02, (u8 *) v1);
                v1 += d;
                n -= d;
                p += func_0213a434((u8 *) p) + 1;
                c++;
            }
            b++;
        }
    }
}

void func_ov000_0218b148(Unk0218af28 *e, s8 *v1) {
    s8 *a;
    s8 *b;
    a = func_ov000_0218b19c(v1 + 1, 0x5c);
    while (a != 0) {
        b = func_ov000_0218b19c(0, 0x5c);
        if (b == 0) {
            b = (s8 *) data_ov000_021b21c4;
        }
        if (func_ov000_0218b1e0((u8 *) a) != 0) {
            func_ov000_0218b380(e, (u8 *) a, (u8 *) b);
        }
        a = func_ov000_0218b19c(0, 0x5c);
    }
}

s8 *func_ov000_0218b19c(s8 *s, s32 c) {
    s8 *a;
    s8 *b;
    s32 d;
    if (s != 0) {
        data_ov000_021b4d14 = s;
    }
    a = data_ov000_021b4d14;
    while ((d = *(b = data_ov000_021b4d14)) != 0 && d != c) {
        data_ov000_021b4d14++;
    }
    if (b == a) {
        a = 0;
    }
    if (d != 0) {
        data_ov000_021b4d14++;
        *b = 0;
    }
    return a;
}

u32 func_ov000_0218b1e0(const u8 *s) {
    Unk021b21ac t;
    u32 i;
    const u8 **p;
    t = data_ov000_021b21ac;
    p = t.mUnk_00;
    for (i = 0; i < 2; i++) {
        if (func_0213a074(s, *p) == 0) {
            return 0;
        }
        p++;
    }
    return 1;
}

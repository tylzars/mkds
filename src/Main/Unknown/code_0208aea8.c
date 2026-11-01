#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020478bc.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_02062eb0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"

static inline u32 func_0208b190_inline(Unk020f41c4_B *b, u32 n) {
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    if (n == 0) {
        return (u32) (b->mUnk_00 >> 32);
    }
    return (u32) (((b->mUnk_00 >> 32) * n) >> 32);
}

void func_0208aea8(u32 a, u32 b, u32 c) {
    u8 *p = data_0217b038->mUnk_0c;
    u8 *q = data_0217b038->mUnk_10;
    if (func_02062eb0() != 0) {
        c = 0;
        b = c;
    } else if (data_021759c0->mUnk_08 == 2) {
        b = (u16) (c + 0x25);
    }
    func_0214d1fc(p + b * 0x98, data_0217b038->mUnk_00 + a * 0x98, 0x98);
    func_0214d1fc(q + c * 8, data_0217b038->mUnk_04 + a * 8, 8);
}

void func_0208af40(void *a, u32 b) {
    data_0217b038 = func_02036bec(a, 0x14);
    data_0217b038->mUnk_00 = func_02036bec(a, b * 0x98);
    data_0217b038->mUnk_04 = func_02036bec(a, b * 8);
    data_0217b038->mUnk_0c = (u8 *) func_020478bc(data_usa_021660c8);
    data_0217b038->mUnk_10 = (u8 *) func_020478bc(data_usa_021660e0);
    data_0217b038->mUnk_08 = *(s32 *) (data_0217b038->mUnk_0c + 0x10);
}

// non-matching: 0x198 bytes, original 0x1ac; stack frame 0x5c in the original, 0x54 here; the loop locals and the saved
// x differ
void func_0208afe4(void) {
    Unk02166108 a = data_usa_02166108;
    Unk021660f8 b = data_usa_021660f8;
    s32 x = data_usa_02155fc0.x;
    s32 y = data_usa_02155fc0.y;
    s32 z = data_usa_02155fc0.z;
    u16 i;
    u16 j;
    Unk0217b050Func *f = data_0217b050;

    for (i = 0; i < 2; i++) {
        s32 e;
        Vec3 v;
        Unk0201ca6c *q;
        Unk020184e4 *p = f(&e, b.mUnk_00[i]);
        v.x = x >> 4;
        v.y = y >> 4;
        v.z = z >> 4;
        q = func_02018600(p, e, &v);
        if (q != 0) {
            if (q->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
                q->mUnk_80_16 = 1;
            } else if (q->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
                q->mUnk_80_16 = 2;
            }
        }
    }
    for (j = 0; j < 0x18; j++) {
        s32 e;
        Vec3 v;
        Unk0201ca6c *q;
        Unk020184e4 *p = f(&e, a.mUnk_00[j]);
        v.x = x >> 4;
        v.y = y >> 4;
        v.z = z >> 4;
        q = func_02018600(p, e, &v);
        if (q != 0) {
            if (q->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
                q->mUnk_80_16 = 1;
            } else if (q->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
                q->mUnk_80_16 = 2;
            }
        }
    }
}

// non-matching: 0x2b4 bytes, original 0x2c8; literal order and registers differ from the first load of data_0217b048
void func_0208b190(void) {
    s32 v1 = -0x1000;
    s32 v2 = -1;
    Vec3 v3;
    s32 w[6];
    s32 u[6];
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 n;
    Unk0217b050Func *f;
    Unk02061808 *g;

    data_0217b048->mUnk_60--;
    if (data_0217b048->mUnk_60 > 0) {
        return;
    }
    g = func_02061808();
    v3 = g->mUnk_15c;
    for (i = 0; i < 6; i++) {
        if (data_0217b048->mUnk_48[i] != 0) {
            s32 e;
            f = data_0217b050;
            func_020184e4(f(&e, 0), data_0217b048->mUnk_48[i]);
            data_0217b048->mUnk_48[i] = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        s32 d = func_0214848c(&v3, &data_0217b048->mUnk_00[i]);
        if (d >= v1) {
            v1 = d;
            v2 = i;
        }
    }
    j = v2 - 1;
    if (j < 0) {
        j = 5;
    }
    k = v2 + 1;
    if (k >= 6) {
        k = 0;
    }
    u[0] = data_usa_02155f48[j * 2];
    u[1] = data_usa_02155f48[j * 2 + 1];
    u[2] = data_usa_02155f48[v2 * 2];
    u[3] = data_usa_02155f48[v2 * 2 + 1];
    u[4] = data_usa_02155f48[k * 2];
    u[5] = data_usa_02155f48[k * 2 + 1];
    w[0] = j;
    w[1] = j;
    w[2] = v2;
    w[3] = v2;
    w[4] = k;
    w[5] = k;
    for (m = 0; m < 6; m++) {
        s32 e;
        Vec3 v;
        Unk0201ca6c *q;
        Unk020184e4 *p;
        Vec3 *t = &data_usa_02155f78[w[m]];
        f = data_0217b050;
        p = f(&e, u[m]);
        v.x = t->x >> 4;
        v.y = t->y >> 4;
        v.z = t->z >> 4;
        q = func_02018600(p, e, &v);
        if (q != 0) {
            if (q->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
                q->mUnk_80_16 = 1;
            } else if (q->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
                q->mUnk_80_16 = 2;
            }
        }
        data_0217b048->mUnk_48[m] = q;
    }
    n = func_0208b190_inline(&data_0217561c->mUnk_498, 0x19);
    data_0217b048->mUnk_60 = (u16) n + 0x14;
}

Unk020184e4 *func_0208b458(s32 *a, s32 b) {
    if (b >= 0x3e8) {
        b -= 0x3e8;
        *a = b;
        return data_0217b03c;
    }
    *a = b;
    return data_0217b044;
}

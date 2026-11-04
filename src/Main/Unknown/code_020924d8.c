#include "Main/Unknown/code_0209219c.h"
#include "Main/Unknown/code_020924d8.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020e6b58.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_02166000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"

u8 func_0209297c(Unk0209219c *a, Unk0209297c *b, void *c, u8 *d) {
    Vec3 u;
    Vec3 t;
    s32 k;
    s32 x;
    s32 z;
    u8 r;
    u8 m;
    s64 q;

    m = 1 << b->mUnk_74;
    r = *d;
    if ((a->mUnk_d0 & m) == 0) {
        Vec3Sub(&b->mUnk_80, &a->mUnk_00.mPos, &t);
        k = ((s64) a->mUnk_00.mMatrix.mUnk_00[2].x * t.x + (s64) a->mUnk_00.mMatrix.mUnk_00[2].z * t.z) >> 12;
        x = t.x - (s32) (((s64) a->mUnk_00.mMatrix.mUnk_00[2].x * k) >> 12);
        z = t.z - (s32) (((s64) a->mUnk_00.mMatrix.mUnk_00[2].z * k) >> 12);
        q = (s64) x * x + (s64) u.y * u.y + (s64) z * z;
        u.x = x;
        u.z = z;
        if (q < 0x10) {
            a->mUnk_00.mUnk_10.x = (s32) (((s64) a->mUnk_00.mMatrix.mUnk_00[2].x * 0x1333) >> 12);
            a->mUnk_00.mUnk_10.y = (s32) (((s64) a->mUnk_00.mMatrix.mUnk_00[2].y * 0x1333) >> 12);
            a->mUnk_00.mUnk_10.z = (s32) (((s64) a->mUnk_00.mMatrix.mUnk_00[2].z * 0x1333) >> 12);
        } else {
            func_02039860(&u, &u);
            a->mUnk_00.mUnk_10.x = (s32) (((s64) u.x * 0x1333) >> 12);
            a->mUnk_00.mUnk_10.y = (s32) (((s64) u.y * 0x1333) >> 12);
            a->mUnk_00.mUnk_10.z = (s32) (((s64) u.z * 0x1333) >> 12);
        }
        a->mUnk_d0 |= m;
    }
    return r;
}

void CreateBasabasa(void *a) {
    gBasabasa = func_0209bc74(a, gBasabasaNsbmdName, gBasabasaNsbtpName);
    func_0209b940(gBasabasa, 0x3f);
}

void func_02092928(void *a) {
    func_0209bbd0(a, gBasabasa);
}

void func_0209280c(void *a, Unk0209219c *b) {
    s32 s;
    s32 m[9];
    s32 d;

    d = 0x1fe0 - b->mUnk_c4;
    s = 0x1e;
    func_01ff9048(0x14, &s, 1);
    func_01ff9048(0x19, func_020e6cf8(&b->mUnk_00.mPos), 0xc);
    if (b->mUnk_cc != 0) {
        func_02146d60(m, data_0215d4b4[((u16) -d >> 4) * 2], data_0215d4b4[((u16) -d >> 4) * 2 + 1]);
    } else {
        func_02146d60(m, data_0215d4b4[((u16) d >> 4) * 2], data_0215d4b4[((u16) d >> 4) * 2 + 1]);
    }
    func_01ff9048(0x1a, m, 9);
    func_01ff9048(0x1b, &b->mUnk_00.mUnk_1c, 3);
    func_0209b688(gBasabasa, b->mUnk_ac);
    func_0209bb2c(a, gBasabasa, b);
}

void func_020924d8(void *a, Unk0209219c *b) {
    s32 v;

    b->mUnk_c4 += b->mUnk_c8;
    b->mUnk_c8 += 0x3c;
    if (b->mUnk_c4 == 0) {
        b->mUnk_c4 += b->mUnk_c8;
        b->mUnk_c8 += 0x3c;
    } else if (b->mUnk_c4 >= 0x1fe0) {
        b->mUnk_c8 = 0x3c - b->mUnk_c8;
        b->mUnk_cc = b->mUnk_cc == 0;
    }
    switch (b->mUnk_d4) {
        case 0:
            if (b->mUnk_b0-- > 0) {
                break;
            }
            b->mUnk_00.mFlags &= ~1;
            b->mUnk_00.mFlags &= ~2;
            b->mUnk_00.mFlags &= ~8;
            b->mUnk_00.mUnk_66 = 0x1f;
            b->mUnk_a0.x += (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[2].x * 0x19a) >> 12);
            b->mUnk_a0.y += -0x19a;
            b->mUnk_a0.z += (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[2].z * 0x19a) >> 12);
            Vec3Add(&b->mUnk_00.mPos, &b->mUnk_a0, &b->mUnk_00.mPos);
            if (b->mUnk_b4-- <= 0) {
                b->mUnk_d4 = 1;
            }
            break;
        case 1:
            b->mUnk_a0.x += (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[2].x * 0x19a) >> 12);
            b->mUnk_a0.y += 0x19a;
            b->mUnk_a0.z += (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[2].z * 0x19a) >> 12);
            Vec3Add(&b->mUnk_00.mPos, &b->mUnk_a0, &b->mUnk_00.mPos);
            if (b->mUnk_a0.y > 0) {
                b->mUnk_a0.y = 0;
                b->mUnk_d4 = 2;
            }
            break;
        case 2:
            Vec3Add(&b->mUnk_00.mPos, &b->mUnk_a0, &b->mUnk_00.mPos);
            if (b->mUnk_b8-- <= 0) {
                b->mUnk_d4 = 3;
            }
            break;
        case 3:
            b->mUnk_a0.x -= (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[2].x * 0xcd) >> 12);
            b->mUnk_a0.y += 0x1000;
            b->mUnk_a0.z -= (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[2].z * 0xcd) >> 12);
            Vec3Add(&b->mUnk_00.mPos, &b->mUnk_a0, &b->mUnk_00.mPos);
            if (b->mUnk_00.mPos.y >= 0x1b8000) {
                func_020d2398(&b->mUnk_00);
            }
            break;
    }
    if (b->mUnk_b0 > 0) {
        return;
    }
    v = b->mUnk_ac + 1;
    if (v >= func_0209b634(gBasabasa)) {
        v = 0;
    }
    b->mUnk_ac = v;
    if (b->mUnk_bc == 0) {
        return;
    }
    func_020d275c(&b->mUnk_00, 0x165);
}

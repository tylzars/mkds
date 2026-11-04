#include "Main/Unknown/code_0209a748.h"
#include "code_02146d78.h"

#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020d88fc.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e6b58.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "code_02146cbc.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8ddc.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d7da8.h"

void func_0209b5f4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value12 = (u32) &func_020d7da8;
    value1 = (u32) * (const u32 *) ((value0) + (156));
    value0 = (value0) + (0xf0u);
    value2 = 0u;
    func_020d7da8((Unk020e0144 *) value0, (Unk020fa294 *) value1, (s32) value2);
}

static inline u32 func_0209b388_inline(Unk020f41c4_B *r, u32 c) {
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    if (c == 0) {
        return (u32) (r->mUnk_00 >> 32);
    } else {
        return (u32) (((r->mUnk_00 >> 32) * c) >> 32);
    }
}

void func_0209b388(Unk0209a7dc *a, Vec3 *b, Vec3 *c, Vec3 *d) {
    Vec3 v;
    Unk020f41c4_B *r;
    s32 x;
    s32 z;

    if (b != NULL && c != NULL) {
        Vec3Sub(&a->mUnk_000.mPos, b, &v);
        z = c->z;
        x = c->x;
        if ((s64) v.z * x - (s64) v.x * z < 0) {
            v.z = -x;
            v.x = z;
            v.y = 0;
            a->mUnk_0a0 = 0x71c;
        } else {
            v.z = x;
            v.x = -z;
            v.y = 0;
            a->mUnk_0a0 = 0xf8e4;
        }
        a->mUnk_000.mUnk_10.x = ((s64) v.x * 0x1800) >> 12;
        a->mUnk_000.mUnk_10.y = ((s64) v.y * 0x1800) >> 12;
        a->mUnk_000.mUnk_10.z = ((s64) v.z * 0x1800) >> 12;
    } else {
        r = func_020d22d0();
        z = (u16) func_0209b388_inline(r, 0x10000);
        x = gPairsByAngle[((u16) z >> 4) * 2 + 1];
        x = ((s64) x * 0x1800) >> 12;
        a->mUnk_000.mUnk_10.x = x;
        a->mUnk_000.mUnk_10.z = x;
        r = func_020d22d0();
        if ((u16) func_0209b388_inline(r, 2) != 0) {
            a->mUnk_0a0 = 0x71c;
        } else {
            a->mUnk_0a0 = 0xf8e4;
        }
    }
    if (d != NULL) {
        a->mUnk_000.mUnk_10.x += d->x / 2;
        a->mUnk_000.mUnk_10.z += d->z / 2;
    }
    a->mUnk_000.mUnk_10.y = 0x4000;
    a->mUnk_0a4 = 0x12c;
    a->mUnk_114 = 2;
    a->mUnk_000.mFlags |= data_usa_0215659c;
}

u8 func_0209b344(Unk0209a7dc *a, Kart *b, u8 *c, u8 *d) {
    u32 e;

    e = *d;
    if (*c == 1) {
        func_0209b388(a, &b->mUnk_80, &b->mUnk_68, &b->mUnk_a4);
        func_020d26f8(&a->mUnk_000, b);
    }
    return e;
}

u8 func_0209b270(Unk0209a7dc *a, Kart *b, u8 *c, u8 *d) {
    Vec3 v;
    Kart *t;
    u32 e;

    e = *d;
    if (*c == 1) {
        if (b != NULL) {
            if ((s64) b->mUnk_05c.x * b->mUnk_05c.x + (s64) b->mUnk_05c.y * b->mUnk_05c.y +
                    (s64) b->mUnk_05c.z * b->mUnk_05c.z >=
                0x10) {
                func_02039860(&b->mUnk_05c, &v);
                func_0209b388(a, &b->mUnk_50, &v, NULL);
            } else {
                func_0209b388(a, NULL, NULL, NULL);
            }
            func_020f8ddc(b);
        } else {
            t = GetKart((u16) data_021759c0->mEntryIndex);
            func_0209b388(a, &t->mUnk_80, &t->mUnk_68, &t->mUnk_a4);
        }
    }
    return e;
}

void CreateCrabAndCrabHand(void *a) {
    gCrab = func_0209bc74(a, "crab.nsbmd", "crab.nsbtp");
    gCrabHand = func_0209bc74(a, "crab_hand.nsbmd", "crab_hand.nsbtp");
    func_0209b940(gCrab, 0x3f);
    func_0209b940(gCrabHand, 0x3f);
}

u32 func_0209b1f8(u32 p0) {
    return p0;
}

void func_0209b088(void *a, Unk0209a7dc *b) {
    s32 w;
    s32 f0[9];
    s32 f1[9];

    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_020e6d88(&b->mUnk_000.mMatrix.mUnk_00[1]);
    func_01ff9048(0x19, func_020e6bd0(&b->mUnk_000.mPos), 0xc);
    if (b->mUnk_0a2 != 0) {
        Matrix3x3FromPairZ(f0, gPairsByAngle[(b->mUnk_0a2 >> 4) * 2], gPairsByAngle[(b->mUnk_0a2 >> 4) * 2 + 1]);
        func_01ff9048(0x1a, f0, 9);
    }
    func_01ff9048(0x1b, &b->mUnk_000.mUnk_1c, 3);
    func_0209b688(gCrab, (u16) (b->mUnk_0a8 >> 12));
    func_0209bbd0(a, gCrab);
    func_0209bb2c(a, gCrab, b);
    Matrix3x3FromPairZ(f1, gPairsByAngle[((u16) b->mUnk_0d0.mUnk_04 >> 4) * 2],
                       gPairsByAngle[((u16) b->mUnk_0d0.mUnk_04 >> 4) * 2 + 1]);
    func_01ff9048(0x1a, f1, 9);
    func_0209b688(gCrabHand, (u16) (b->mUnk_0ac >> 12));
    func_0209bbd0(a, gCrabHand);
    func_0209bb2c(a, gCrabHand, b);
}

void func_0209af98(Unk0209af98 *p) {
    s32 i;
    Unk0209a7dc *o;
    Unk020f41c4_B *r;

    if (p == NULL) {
        return;
    }
    for (i = 0; i < p->mUnk_04 && (o = p->mUnk_00[i]) != NULL; i++) {
        o->mUnk_0d0.mUnk_00 = 0;
        o->mUnk_0d0.mUnk_0c = 0;
        o->mUnk_0d0.mUnk_10 = 0x1c7;
        o->mUnk_0d0.mUnk_14 = 0;
        o->mUnk_0d0.mUnk_18 = 0xe39;
        o->mUnk_0d0.mUnk_1c = 0;
        r = func_020d22d0();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        o->mUnk_0a4 = (u16) ((u16) (((u64) (u32) (r->mUnk_00 >> 32) * 60) >> 32) + 30);
        o->mUnk_114 = 0;
    }
}

s16 func_0209af80(s32 a) {
    return gPairsByAngle[(a >> 4) * 2];
}

s32 func_0209af64(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

static inline void func_0209a7dc_inline(Unk0209a7dc_b0 *b) {
    s32 t;

    b->mUnk_00 += b->mUnk_18;
    b->mUnk_08 = b->mUnk_0c + func_0209af64(b->mUnk_10, func_0209af80(b->mUnk_00)) - b->mUnk_04;
    b->mUnk_04 += b->mUnk_08;
    if (b->mUnk_10 > 0) {
        t = b->mUnk_10 + b->mUnk_14;
        if (t <= 0) {
            t = 0;
        }
        b->mUnk_10 = t;
    } else if (b->mUnk_10 < 0) {
        t = b->mUnk_10 + b->mUnk_14;
        if (t >= 0) {
            t = 0;
        }
        b->mUnk_10 = t;
    }
    if (b->mUnk_18 > 0) {
        t = b->mUnk_18 + b->mUnk_1c;
        if (t <= 0) {
            t = 0;
        }
        b->mUnk_18 = t;
    } else if (b->mUnk_18 < 0) {
        t = b->mUnk_18 + b->mUnk_1c;
        if (t >= 0) {
            t = 0;
        }
        b->mUnk_18 = t;
    }
}

void func_0209a7dc(void *a, Unk0209a7dc *b) {
    Vec3 v;
    Unk020f41c4_B *r;

    switch (b->mUnk_114) {
        case 0:
            b->mUnk_0ac += 0x200;
            if (b->mUnk_0ac >= (s32) (func_0209b634(gCrabHand) > 0 ? 0.5f + (float) (func_0209b634(gCrabHand) << 12)
                                                                   : (float) (func_0209b634(gCrabHand) << 12) - 0.5f)) {
                b->mUnk_0ac = 0;
            }
            if (b->mUnk_0a4-- > 0) {
                return;
            }
            if (b->mUnk_0ac == 0) {
                b->mUnk_114 = 1;
            }
            break;
        case 1:
            b->mUnk_0f0.mUnk_04 = 0x800;
            b->mUnk_0f0.mUnk_10 = ((s64) b->mUnk_0f0.mUnk_00->mUnk_00[b->mUnk_0f0.mUnk_0c].mUnk_34 * 0x800) >> 12;
            if (func_020d8cc8(&b->mUnk_0f0) != 0) {
                b->mUnk_0d0.mUnk_00 = 0;
                b->mUnk_0d0.mUnk_0c = 0;
                b->mUnk_0d0.mUnk_10 = 0x1c7;
                b->mUnk_0d0.mUnk_14 = 0;
                b->mUnk_0d0.mUnk_18 = 0xe39;
                b->mUnk_0d0.mUnk_1c = 0;
                r = func_020d22d0();
                r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                b->mUnk_0a4 = (u16) ((u16) (((u64) (u32) (r->mUnk_00 >> 32) * 60) >> 32) + 30);
                b->mUnk_114 = 0;
            }
            b->mUnk_0a8 += 0x200;
            if (b->mUnk_0a8 >= (s32) (func_0209b634(gCrab) > 0 ? 0.5f + (float) (func_0209b634(gCrab) << 12)
                                                               : (float) (func_0209b634(gCrab) << 12) - 0.5f)) {
                b->mUnk_0a8 = 0;
            }
            func_0209a7dc_inline(&b->mUnk_0d0);
            func_020d8a5c(&b->mUnk_0f0, &b->mUnk_000.mPos);
            v = *func_020d88fc(&b->mUnk_0f0);
            Vec3Sub(&v, &b->mUnk_000.mMatrix.mUnk_00[1], &v);
            v.x = ((s64) v.x * 0x800) >> 12;
            v.y = ((s64) v.y * 0x800) >> 12;
            v.z = ((s64) v.z * 0x800) >> 12;
            Vec3Add(&b->mUnk_000.mMatrix.mUnk_00[1], &v, &b->mUnk_000.mMatrix.mUnk_00[1]);
            if ((s64) b->mUnk_000.mMatrix.mUnk_00[1].x * b->mUnk_000.mMatrix.mUnk_00[1].x +
                    (s64) b->mUnk_000.mMatrix.mUnk_00[1].y * b->mUnk_000.mMatrix.mUnk_00[1].y +
                    (s64) b->mUnk_000.mMatrix.mUnk_00[1].z * b->mUnk_000.mMatrix.mUnk_00[1].z >=
                0x10) {
                func_02039860(&b->mUnk_000.mMatrix.mUnk_00[1], &b->mUnk_000.mMatrix.mUnk_00[1]);
            }
            break;
        case 2:
            if (b->mUnk_0a4-- > 0) {
                b->mUnk_000.mUnk_10.y -= 0x400;
                Vec3Add(&b->mUnk_000.mPos, &b->mUnk_000.mUnk_10, &b->mUnk_000.mPos);
                b->mUnk_0a2 += b->mUnk_0a0;
                return;
            }
            func_020d90a8(&b->mUnk_0f0, 0, 0);
            func_020d879c(&b->mUnk_0f0, &b->mUnk_000.mPos);
            b->mUnk_000.mPos.y = b->mUnk_000.mCourseMapRow->mUnk_00.y - 0x5000;
            b->mUnk_0b0.mUnk_00 = 0;
            b->mUnk_0b0.mUnk_0c = 0;
            b->mUnk_0b0.mUnk_10 = 0x2aab;
            b->mUnk_0b0.mUnk_14 = -0xb6;
            b->mUnk_0b0.mUnk_18 = 0x71c;
            b->mUnk_0b0.mUnk_1c = 0;
            func_0209a7dc_inline(&b->mUnk_0b0);
            b->mUnk_0a2 = b->mUnk_0b0.mUnk_04;
            b->mUnk_114 = 3;
            break;
        case 3:
            b->mUnk_0ac += 0x200;
            if (b->mUnk_0ac >= (s32) (func_0209b634(gCrabHand) > 0 ? 0.5f + (float) (func_0209b634(gCrabHand) << 12)
                                                                   : (float) (func_0209b634(gCrabHand) << 12) - 0.5f)) {
                b->mUnk_0ac = 0;
            }
            func_0209a7dc_inline(&b->mUnk_0b0);
            b->mUnk_0a2 = b->mUnk_0b0.mUnk_04;
            b->mUnk_000.mPos.y += 0x200;
            if (b->mUnk_000.mPos.y < b->mUnk_000.mCourseMapRow->mUnk_00.y) {
                return;
            }
            b->mUnk_000.mPos.y = b->mUnk_000.mCourseMapRow->mUnk_00.y;
            b->mUnk_000.mUnk_10.x = 0;
            b->mUnk_000.mUnk_10.y = 0;
            b->mUnk_000.mUnk_10.z = 0;
            b->mUnk_0a2 = 0;
            b->mUnk_0d0.mUnk_00 = 0;
            b->mUnk_0d0.mUnk_0c = 0;
            b->mUnk_0d0.mUnk_10 = 0x1c7;
            b->mUnk_0d0.mUnk_14 = 0;
            b->mUnk_0d0.mUnk_18 = 0xe39;
            b->mUnk_0d0.mUnk_1c = 0;
            r = func_020d22d0();
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            b->mUnk_0a4 = (u16) ((u16) (((u64) (u32) (r->mUnk_00 >> 32) * 60) >> 32) + 30);
            b->mUnk_114 = 0;
            b->mUnk_000.mFlags &= ~1;
            break;
    }
}

void func_0209a78c(void) {
    Unk0209bf70 *o;

    o = func_0209bf70(func_0209b344, func_0209b270, NULL, 2, 1, 0x10e);
    o->mUnk_28 = 0x10f;
}

void *func_0209a768(void) {
    return (void *) func_0209bef0(CreateCrabAndCrabHand, func_0209b088, func_0209b1f8);
}

void *func_0209a748(void) {
    return (void *) func_0209bf48(func_0209af98, func_0209a7dc, NULL);
}

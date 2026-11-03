#include "Main/Unknown/code_0209a748.h"
#include "Main/Unknown/code_0209b1fc.h"

#include "code_02147cd8.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8ddc.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"

void CreateCrabAndCrabHand(void *a) {
    gCrab = func_0209bc74(a, "crab.nsbmd", "crab.nsbtp");
    gCrabHand = func_0209bc74(a, "crab_hand.nsbmd", "crab_hand.nsbtp");
    func_0209b940(gCrab, 0x3f);
    func_0209b940(gCrabHand, 0x3f);
}

u8 func_0209b270(Unk0209a7dc *a, Unk0206bcb0 *b, u8 *c, u8 *d) {
    Vec3 v;
    Unk0206bcb0 *t;
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
            t = func_0207a974((u16) data_021759c0->mUnk_62);
            func_0209b388(a, &t->mUnk_80, &t->mUnk_68, &t->mUnk_a4);
        }
    }
    return e;
}

u8 func_0209b344(Unk0209a7dc *a, Unk0206bcb0 *b, u8 *c, u8 *d) {
    u32 e;

    e = *d;
    if (*c == 1) {
        func_0209b388(a, &b->mUnk_80, &b->mUnk_68, &b->mUnk_a4);
        func_020d26f8(&a->mUnk_000, b);
    }
    return e;
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
        func_021484d0(&a->mUnk_000.mPos, b, &v);
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
        x = data_0215d4b4[((u16) z >> 4) * 2 + 1];
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

#include "Main/Unknown/code_0209a748.h"

#include "Main/Unknown/code_0209b1fc.h"
#include "Main/Unknown/code_0209bef0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020d88fc.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e6b58.h"
#include "ITCM/code_01ff9000.h"
#include "code_02146cbc.h"
#include "Main/Unknown/unk_0215d000.h"

u32 func_0209b1f8(u32 p0) {
    return p0;
}

void func_0209b088(void *a, Unk0209a7dc *b) {
    s32 w;
    s32 f0[9];
    s32 f1[9];

    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_020e6d88(&b->mUnk_000.mUnk_28.mUnk_0c);
    func_01ff9048(0x19, func_020e6bd0(&b->mUnk_000.mUnk_04), 0xc);
    if (b->mUnk_0a2 != 0) {
        func_02146d60(f0, data_0215d4b4[(b->mUnk_0a2 >> 4) * 2], data_0215d4b4[(b->mUnk_0a2 >> 4) * 2 + 1]);
        func_01ff9048(0x1a, f0, 9);
    }
    func_01ff9048(0x1b, &b->mUnk_000.mUnk_1c, 3);
    func_0209b688(data_usa_0217b158, (u16) (b->mUnk_0a8 >> 12));
    func_0209bbd0(a, data_usa_0217b158);
    func_0209bb2c(a, data_usa_0217b158, b);
    func_02146d60(f1, data_0215d4b4[((u16) b->mUnk_0d0.mUnk_04 >> 4) * 2],
                  data_0215d4b4[((u16) b->mUnk_0d0.mUnk_04 >> 4) * 2 + 1]);
    func_01ff9048(0x1a, f1, 9);
    func_0209b688(data_usa_0217b154, (u16) (b->mUnk_0ac >> 12));
    func_0209bbd0(a, data_usa_0217b154);
    func_0209bb2c(a, data_usa_0217b154, b);
}

void func_0209af98(Unk0209af98 *p) {
    s32 i;
    Unk0209a7dc *o;
    Unk020f41c4_B *r;

    if (p == 0) {
        return;
    }
    for (i = 0; i < p->mUnk_04 && (o = p->mUnk_00[i]) != 0; i++) {
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
    return data_0215d4b4[(a >> 4) * 2];
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
            if (b->mUnk_0ac >= (s32) (func_0209b634(data_usa_0217b154) > 0
                                          ? 0.5f + (float) (func_0209b634(data_usa_0217b154) << 12)
                                          : (float) (func_0209b634(data_usa_0217b154) << 12) - 0.5f)) {
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
            if (b->mUnk_0a8 >= (s32) (func_0209b634(data_usa_0217b158) > 0
                                          ? 0.5f + (float) (func_0209b634(data_usa_0217b158) << 12)
                                          : (float) (func_0209b634(data_usa_0217b158) << 12) - 0.5f)) {
                b->mUnk_0a8 = 0;
            }
            func_0209a7dc_inline(&b->mUnk_0d0);
            func_020d8a5c(&b->mUnk_0f0, &b->mUnk_000.mUnk_04);
            v = *func_020d88fc(&b->mUnk_0f0);
            func_021484d0(&v, &b->mUnk_000.mUnk_28.mUnk_0c, &v);
            v.x = ((s64) v.x * 0x800) >> 12;
            v.y = ((s64) v.y * 0x800) >> 12;
            v.z = ((s64) v.z * 0x800) >> 12;
            func_02148504(&b->mUnk_000.mUnk_28.mUnk_0c, &v, &b->mUnk_000.mUnk_28.mUnk_0c);
            if ((s64) b->mUnk_000.mUnk_28.mUnk_0c.x * b->mUnk_000.mUnk_28.mUnk_0c.x +
                    (s64) b->mUnk_000.mUnk_28.mUnk_0c.y * b->mUnk_000.mUnk_28.mUnk_0c.y +
                    (s64) b->mUnk_000.mUnk_28.mUnk_0c.z * b->mUnk_000.mUnk_28.mUnk_0c.z >=
                0x10) {
                func_02039860(&b->mUnk_000.mUnk_28.mUnk_0c, &b->mUnk_000.mUnk_28.mUnk_0c);
            }
            break;
        case 2:
            if (b->mUnk_0a4-- > 0) {
                b->mUnk_000.mUnk_10.y -= 0x400;
                func_02148504(&b->mUnk_000.mUnk_04, &b->mUnk_000.mUnk_10, &b->mUnk_000.mUnk_04);
                b->mUnk_0a2 += b->mUnk_0a0;
                return;
            }
            func_020d90a8(&b->mUnk_0f0, 0, 0);
            func_020d879c(&b->mUnk_0f0, &b->mUnk_000.mUnk_04);
            b->mUnk_000.mUnk_04.y = b->mUnk_000.mUnk_9c->mUnk_00.y - 0x5000;
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
            if (b->mUnk_0ac >= (s32) (func_0209b634(data_usa_0217b154) > 0
                                          ? 0.5f + (float) (func_0209b634(data_usa_0217b154) << 12)
                                          : (float) (func_0209b634(data_usa_0217b154) << 12) - 0.5f)) {
                b->mUnk_0ac = 0;
            }
            func_0209a7dc_inline(&b->mUnk_0b0);
            b->mUnk_0a2 = b->mUnk_0b0.mUnk_04;
            b->mUnk_000.mUnk_04.y += 0x200;
            if (b->mUnk_000.mUnk_04.y < b->mUnk_000.mUnk_9c->mUnk_00.y) {
                return;
            }
            b->mUnk_000.mUnk_04.y = b->mUnk_000.mUnk_9c->mUnk_00.y;
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
            b->mUnk_000.mUnk_02 &= ~1;
            break;
    }
}

void func_0209a78c(void) {
    Unk0209bf70 *o;

    o = func_0209bf70(func_0209b344, func_0209b270, 0, 2, 1, 0x10e);
    o->mUnk_28 = 0x10f;
}

void *func_0209a768(void) {
    return (void *) func_0209bef0(func_0209b1fc, func_0209b088, func_0209b1f8);
}

void *func_0209a748(void) {
    return (void *) func_0209bf48(func_0209af98, func_0209a7dc, 0);
}

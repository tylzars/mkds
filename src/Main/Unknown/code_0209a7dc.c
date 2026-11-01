#include "Main/Unknown/code_0209a7dc.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0209af64.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020d88fc.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0217b000.h"

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

void func_0209a7dc(void *param_1, Unk0209a7dc *param_2) {
    Vec3 v;
    Unk020f41c4_B *r;

    switch (param_2->mUnk_114) {
        case 0:
            param_2->mUnk_0ac += 0x200;
            if (param_2->mUnk_0ac >= (s32) (func_0209b634(data_usa_0217b154) > 0
                                                ? 0.5f + (float) (func_0209b634(data_usa_0217b154) << 12)
                                                : (float) (func_0209b634(data_usa_0217b154) << 12) - 0.5f)) {
                param_2->mUnk_0ac = 0;
            }
            if (param_2->mUnk_0a4-- > 0) {
                return;
            }
            if (param_2->mUnk_0ac == 0) {
                param_2->mUnk_114 = 1;
            }
            break;
        case 1:
            param_2->mUnk_0f0.mUnk_04 = 0x800;
            param_2->mUnk_0f0.mUnk_10 =
                ((s64) param_2->mUnk_0f0.mUnk_00->mUnk_00[param_2->mUnk_0f0.mUnk_0c].mUnk_34 * 0x800) >> 12;
            if (func_020d8cc8(&param_2->mUnk_0f0) != 0) {
                param_2->mUnk_0d0.mUnk_00 = 0;
                param_2->mUnk_0d0.mUnk_0c = 0;
                param_2->mUnk_0d0.mUnk_10 = 0x1c7;
                param_2->mUnk_0d0.mUnk_14 = 0;
                param_2->mUnk_0d0.mUnk_18 = 0xe39;
                param_2->mUnk_0d0.mUnk_1c = 0;
                r = func_020d22d0();
                r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                param_2->mUnk_0a4 = (u16) ((u16) (((u64) (u32) (r->mUnk_00 >> 32) * 60) >> 32) + 30);
                param_2->mUnk_114 = 0;
            }
            param_2->mUnk_0a8 += 0x200;
            if (param_2->mUnk_0a8 >= (s32) (func_0209b634(data_usa_0217b158) > 0
                                                ? 0.5f + (float) (func_0209b634(data_usa_0217b158) << 12)
                                                : (float) (func_0209b634(data_usa_0217b158) << 12) - 0.5f)) {
                param_2->mUnk_0a8 = 0;
            }
            func_0209a7dc_inline(&param_2->mUnk_0d0);
            func_020d8a5c(&param_2->mUnk_0f0, &param_2->mUnk_000.mUnk_04);
            v = *func_020d88fc(&param_2->mUnk_0f0);
            func_021484d0(&v, &param_2->mUnk_000.mUnk_28.mUnk_0c, &v);
            v.x = ((s64) v.x * 0x800) >> 12;
            v.y = ((s64) v.y * 0x800) >> 12;
            v.z = ((s64) v.z * 0x800) >> 12;
            func_02148504(&param_2->mUnk_000.mUnk_28.mUnk_0c, &v, &param_2->mUnk_000.mUnk_28.mUnk_0c);
            if ((s64) param_2->mUnk_000.mUnk_28.mUnk_0c.x * param_2->mUnk_000.mUnk_28.mUnk_0c.x +
                    (s64) param_2->mUnk_000.mUnk_28.mUnk_0c.y * param_2->mUnk_000.mUnk_28.mUnk_0c.y +
                    (s64) param_2->mUnk_000.mUnk_28.mUnk_0c.z * param_2->mUnk_000.mUnk_28.mUnk_0c.z >=
                0x10) {
                func_02039860(&param_2->mUnk_000.mUnk_28.mUnk_0c, &param_2->mUnk_000.mUnk_28.mUnk_0c);
            }
            break;
        case 2:
            if (param_2->mUnk_0a4-- > 0) {
                param_2->mUnk_000.mUnk_10.y -= 0x400;
                func_02148504(&param_2->mUnk_000.mUnk_04, &param_2->mUnk_000.mUnk_10, &param_2->mUnk_000.mUnk_04);
                param_2->mUnk_0a2 += param_2->mUnk_0a0;
                return;
            }
            func_020d90a8(&param_2->mUnk_0f0, 0, 0);
            func_020d879c(&param_2->mUnk_0f0, &param_2->mUnk_000.mUnk_04);
            param_2->mUnk_000.mUnk_04.y = param_2->mUnk_000.mUnk_9c->mUnk_00.y - 0x5000;
            param_2->mUnk_0b0.mUnk_00 = 0;
            param_2->mUnk_0b0.mUnk_0c = 0;
            param_2->mUnk_0b0.mUnk_10 = 0x2aab;
            param_2->mUnk_0b0.mUnk_14 = -0xb6;
            param_2->mUnk_0b0.mUnk_18 = 0x71c;
            param_2->mUnk_0b0.mUnk_1c = 0;
            func_0209a7dc_inline(&param_2->mUnk_0b0);
            param_2->mUnk_0a2 = param_2->mUnk_0b0.mUnk_04;
            param_2->mUnk_114 = 3;
            break;
        case 3:
            param_2->mUnk_0ac += 0x200;
            if (param_2->mUnk_0ac >= (s32) (func_0209b634(data_usa_0217b154) > 0
                                                ? 0.5f + (float) (func_0209b634(data_usa_0217b154) << 12)
                                                : (float) (func_0209b634(data_usa_0217b154) << 12) - 0.5f)) {
                param_2->mUnk_0ac = 0;
            }
            func_0209a7dc_inline(&param_2->mUnk_0b0);
            param_2->mUnk_0a2 = param_2->mUnk_0b0.mUnk_04;
            param_2->mUnk_000.mUnk_04.y += 0x200;
            if (param_2->mUnk_000.mUnk_04.y < param_2->mUnk_000.mUnk_9c->mUnk_00.y) {
                return;
            }
            param_2->mUnk_000.mUnk_04.y = param_2->mUnk_000.mUnk_9c->mUnk_00.y;
            param_2->mUnk_000.mUnk_10.x = 0;
            param_2->mUnk_000.mUnk_10.y = 0;
            param_2->mUnk_000.mUnk_10.z = 0;
            param_2->mUnk_0a2 = 0;
            param_2->mUnk_0d0.mUnk_00 = 0;
            param_2->mUnk_0d0.mUnk_0c = 0;
            param_2->mUnk_0d0.mUnk_10 = 0x1c7;
            param_2->mUnk_0d0.mUnk_14 = 0;
            param_2->mUnk_0d0.mUnk_18 = 0xe39;
            param_2->mUnk_0d0.mUnk_1c = 0;
            r = func_020d22d0();
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            param_2->mUnk_0a4 = (u16) ((u16) (((u64) (u32) (r->mUnk_00 >> 32) * 60) >> 32) + 30);
            param_2->mUnk_114 = 0;
            param_2->mUnk_000.mUnk_02 &= ~1;
            break;
    }
}

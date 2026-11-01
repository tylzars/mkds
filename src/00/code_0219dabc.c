#include "00/code_0219dabc.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "00/code_021988e8.h"
#include "00/code_0219a000.h"
#include "00/code_0219e138.h"
#include "00/code_0219f000.h"
#include "00/code_0219f9bc.h"
#include "00/code_021a01dc.h"
#include "00/code_021a17bc.h"
#include "code_0200d118.h"

u32 func_ov000_0219dabc(void) {
    if (data_ov000_021b566c->mUnk_15 == 2) {
        return 1;
    }
    if (data_ov000_021b566c->mUnk_15 != 3) {
        data_ov000_021b566c->mUnk_174[1]++;
    }
    if (data_ov000_021b566c->mUnk_15 == 3 || data_ov000_021b566c->mUnk_174[1] >= 5) {
        func_ov000_021a1a38(6, -0x15194);
        return 0;
    }
    return 1;
}

void func_ov000_0219db18(s32 a, s32 b, s32 c, void *d) {
    s32 e;
    s32 f;
    u32 g;
    u32 h;
    char i[12];
    if (data_ov000_021b566c->mUnk_198 != 6 && data_ov000_021b566c->mUnk_198 != 0xb) {
        return;
    }
    if (d == 0) {
        return;
    }
    if (a == 0) {
        ((Unk0219db18 *) d)->mUnk_08 = 0;
        data_ov000_021b566c->mUnk_14++;
        e = data_ov000_021b566c->mUnk_14;
        if (((Unk0219db18 *) d)->mUnk_00 != 0) {
            data_ov000_021b566c->mUnk_1f8[e] = ((Unk021a01dc *) c)->mUnk_04;
            data_ov000_021b566c->mUnk_278[e] =
                (u16) ((((Unk021a01dc *) c)->mUnk_02 >> 8) & 0xff | (((Unk021a01dc *) c)->mUnk_02 << 8) & 0xff00);
            data_ov000_021b566c->mUnk_174[0] = 0;
            data_ov000_021b566c->mUnk_178 = 0;
            data_ov000_021b566c->mUnk_17c = 0;
            if (data_ov000_021b566c->mUnk_198 == 0xb) {
                data_ov000_021b566c->mUnk_198 = 0xc;
            } else {
                data_ov000_021b566c->mUnk_198 = 7;
            }
            data_ov000_021b566c->mUnk_0c = 0;
            func_0200d9e0(i, 12, data_ov000_021b40b8, data_ov000_021b566c->mUnk_1e8);
            if (func_ov000_0219e3e4(func_ov000_02198968(
                    *data_ov000_021b566c->mUnk_04, 0,
                    func_ov000_0219a760(data_ov000_021b566c->mUnk_1f8[e], data_ov000_021b566c->mUnk_278[e], 0), i, -1,
                    0x1388, data_ov000_021b566c->mUnk_08, 0)) != 0) {
                return;
            }
            return;
        }
        if (c != 0) {
            data_ov000_021b566c->mUnk_1f8[e - 1] = ((Unk021a01dc *) c)->mUnk_04;
            data_ov000_021b566c->mUnk_278[e - 1] =
                (u16) ((((Unk021a01dc *) c)->mUnk_02 >> 8) & 0xff | (((Unk021a01dc *) c)->mUnk_02 << 8) & 0xff00);
        }
        data_ov000_021b566c->mUnk_184 = func_ov000_021a350c();
        data_ov000_021b566c->mUnk_198 = 7;
        return;
    }
    if (((Unk0219db18 *) d)->mUnk_08 == 0) {
        return;
    }
    f = func_ov000_0219e45c(a);
    if (f != 2 && f != 1) {
        return;
    }
    if (((Unk0219db18 *) d)->mUnk_00 == 0) {
        if (f == 1 || (f == 2 && ((Unk0219db18 *) d)->mUnk_01 >= 1)) {
            ((Unk0219db18 *) d)->mUnk_08 = 0;
            if (func_ov000_0219dabc() != 0) {
                if (func_ov000_0219f938(data_ov000_021b566c->mUnk_f4[data_ov000_021b566c->mUnk_0d]) != 0) {
                    return;
                }
            }
            return;
        }
        ((Unk0219db18 *) d)->mUnk_01++;
        if (func_ov000_0219e4a0(func_ov000_021a0c30(d)) != 0) {
            return;
        }
        return;
    }
    data_ov000_021b566c->mUnk_17c = func_ov000_021a350c();
    if (f == 1 || (f == 2 && data_ov000_021b566c->mUnk_174[0] >= 1)) {
        ((Unk0219db18 *) d)->mUnk_08 = 0;
        if (func_ov000_0219dabc() != 0) {
            data_ov000_021b566c->mUnk_174[0] = 0;
            data_ov000_021b566c->mUnk_178 = 0;
            data_ov000_021b566c->mUnk_17c = 0;
            if (func_ov000_0219f9bc(data_ov000_021b566c->mUnk_f4[data_ov000_021b566c->mUnk_0d + 1]) != 0) {
                return;
            }
        }
    }
}

#include "00/code_0219cb00.h"
#include "00/code_0219d934.h"

#pragma opt_propagation off

void func_ov000_0219cb64(u32 a, u32 b, s32 c, u32 d, s32 e, u32 f, u32 g) {
    u32 t;
    t = g;
    func_ov000_0219cb00();
    if (t == 0x80000001) {
        if (e != 0) {
            if (data_ov000_021b5664->mUnk_00 == 1) {
                data_ov000_021b5664->mUnk_1f++;
            } else {
                t = 0;
            }
        } else {
            func_ov000_0219d734(6, -72220);
        }
    }
    if ((t & 0x80000000) == 0) {
        if (e != 0) {
            if (data_ov000_021b5664->mUnk_4c != NULL) {
                data_ov000_021b5664->mUnk_4c(1, (u32) (c - 2) <= 1 ? 1 : 0, g);
            }
        } else {
            func_ov000_0219d734(6, -72220);
            if (data_ov000_021b5664->mUnk_4c != NULL) {
                data_ov000_021b5664->mUnk_4c(0, 0, g);
            }
        }
    }
}

void func_ov000_0219cb30(void) {
    Unk021b5664 *p = data_ov000_021b5664;
    if (p->mUnk_20 == -1) {
        func_ov000_0219d734(0xb, -70009);
        return;
    }
    p->mUnk_20++;
}

void func_ov000_0219cb00(void) {
    Unk021b5664 *p = data_ov000_021b5664;
    if (p->mUnk_20 == 0) {
        func_ov000_0219d734(0xb, -70009);
        return;
    }
    p->mUnk_20--;
}

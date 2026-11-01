#include "00/code_021a17bc.h"

u32 func_ov000_021a17bc(s32 param_1, s32 param_2, s32 param_3) {
    Unk021b566c *p;
    if (func_ov000_0219bab4() != 5) {
        return 0;
    }
    p = data_ov000_021b566c;
    if (p->mUnk_15 == 2) {
        return 1;
    }
    if (param_1 != 0) {
        func_ov000_021a1a38(param_1, param_2 - 80000);
        return 1;
    }
    p->mUnk_2b8[0] = 0;
    p = data_ov000_021b566c;
    if (p->mUnk_1a1 == 1 || p->mUnk_1a0 == 1 || p->mUnk_1a0 == 2) {
        return 1;
    }
    if (p->mUnk_194 != 0) {
        func_ov000_0219ac50(p->mUnk_194);
        data_ov000_021b566c->mUnk_194 = 0;
    }
    p = data_ov000_021b566c;
    if (p->mUnk_0d != 0) {
        if (p->mUnk_1a0 == 0) {
            p->mUnk_1a0 = 3;
            func_ov000_021988e8(*data_ov000_021b566c->mUnk_04);
        }
    } else if (p->mUnk_15 == 3) {
        func_ov000_021a1a38(6, -80430);
    } else if (p->mUnk_1f0 != 0) {
        func_ov000_0219f184();
    } else if (p->mUnk_198 == 1) {
        p->mUnk_198 = 18;
        data_ov000_021b566c->mUnk_1e0 = func_ov000_021a350c();
    } else {
        func_ov000_0219f23c(1);
    }
    return 1;
}

// non-matching: original reads p->mUnk_15 twice (ldrb, cmp #0, beq, ldrb, cmp #1, bne) with the data pointer in r2,
// ours reuses the byte (cmp #1 only) and uses r1; 0x12c bytes against the original 0x130
void func_ov000_021a18e0(s32 param_1, s32 param_2, u8 *param_3) {
    Unk021b566c *p;
    s32 i;
    u32 *q;
    s32 v;
    switch (param_2) {
        case 2:
            p = data_ov000_021b566c;
            if (p->mUnk_198 == 1) {
                if (param_3[0] == 1) {
                    p->mUnk_1f4 = 0;
                }
                i = param_3[1];
                data_ov000_021b566c->mUnk_2b8[i] = param_3[2];
                data_ov000_021b566c->mUnk_f4[i] = data_ov000_021b566c->mUnk_1e8;
                p = data_ov000_021b566c;
                if (p->mUnk_15 == 0 || p->mUnk_15 == 1) {
                    p = data_ov000_021b566c;
                    p->mUnk_16 = p->mUnk_0d;
                }
                data_ov000_021b566c->mUnk_198 = 9;
            }
            func_ov000_0219ef68(param_1, 3);
            break;
        case 3:
            p = data_ov000_021b566c;
            if (p->mUnk_198 == 16) {
                q = &p->mUnk_1c8;
                *q = *q | (1 << param_1);
                v = param_3[0] | (param_3[1] << 8);
                if (v > data_ov000_021b566c->mUnk_1a6) {
                    data_ov000_021b566c->mUnk_1a6 = v;
                }
                if (data_ov000_021b566c->mUnk_1c8 == func_ov000_0219e8fc(0)) {
                    p = data_ov000_021b566c;
                    for (i = 1; i <= p->mUnk_0d; i++) {
                        func_ov000_0219ef68(p->mUnk_2b8[i], 4);
                        p = data_ov000_021b566c;
                    }
                    p->mUnk_198 = 17;
                }
            } else {
                func_ov000_0219ef68(param_1, 4);
            }
            break;
        case 4:
            if (data_ov000_021b566c->mUnk_198 == 9) {
                func_ov000_0219f544(4);
            }
            break;
    }
}

void func_ov000_021a1a10(void) {
    Unk021b566c *p;
    p = data_ov000_021b566c;
    if (p->mUnk_15 != 2) {
        p->mUnk_14 = 0;
        data_ov000_021b566c->mUnk_16 = 0;
        func_ov000_021a4818(data_ov000_021b566c->mUnk_10);
    }
}

void func_ov000_021a1a38(s32 param_1, s32 param_2) {
    Unk021b566c *p;
    u32 a;
    u32 b;
    u32 c;
    if (data_ov000_021b566c != 0 && param_1 != 0) {
        func_ov000_0219f0f4();
        func_ov000_0219c384(param_1, param_2);
        func_ov000_0219d558(0, data_ov000_021b4114, 0);
        p = data_ov000_021b566c;
        a = p->mUnk_15 == 2 ? 1 : 0;
        c = data_ov000_021b566c->mUnk_1f4;
        b = c == 0 ? 1 : 0;
        data_ov000_021b566c->mUnk_44c(param_1, 0, b, a, func_ov000_0219d5e4(c), p->mUnk_450);
        func_ov000_021a104c();
    }
}

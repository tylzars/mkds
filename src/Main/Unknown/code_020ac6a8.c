#include "Main/Unknown/code_020ac6a8.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"

void func_020ac9c8(void *a) {
    void *p;

    p = func_0209bd08(a, "shine_balloon.nsbmd");
    data_0217b33c = p;
    func_0209b940(p, 0x3f);
}

void func_020ac9b0(void *a) {
    func_0209bbd0(a, data_0217b33c);
}

void func_020ac890(void *a, Unk020ac5e4 *b) {
    s32 s0;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 v4;
    s32 t;
    s32 v5;

    if (b->mUnk_ac->mUnk_384 == 0) {
        return;
    }
    s0 = 0x1e;
    func_01ff9048(0x14, &s0, 1);
    func_01ff9048(0x19, func_020e6cf8(&b->mUnk_00.mUnk_04), 0xc);
    v2.y = func_020a23a0(b->mUnk_ac) >> 4;
    v2.x = 0;
    v2.z = 0;
    func_01ff9048(0x1c, &v2, 3);
    t = b->mUnk_a0;
    if (t != 0x1000) {
        v3.x = t;
        v3.y = t;
        v3.z = t;
        func_01ff9048(0x1b, &v3, 3);
    }
    func_01ff9048(0x1b, &b->mUnk_00.mUnk_1c, 3);
    func_021484d0(&b->mUnk_00.mUnk_04, &((Unk02061808 *) func_02061808())->mUnk_024, &v1);
    v5 = func_021482cc(&v1);
    v4.x = v5;
    v4.y = v5;
    v4.z = v5;
    func_01ff9048(0x1b, &v4, 3);
    func_0209bb2c(a, data_0217b33c, b);
}

void func_020ac6a8(void *a, Unk020ac5e4 *b) {
    switch (b->mUnk_b0) {
        case 0:
            if (func_020a1154(b->mUnk_ac->mUnk_74) == 0) {
                return;
            }
            b->mUnk_a8 = 0x1e;
            b->mUnk_a4 = 0x19;
            b->mUnk_b0 = 1;
            b->mUnk_00.mUnk_02 &= ~2;
            b->mUnk_00.mUnk_02 &= ~8;
            b->mUnk_00.mUnk_66 = 0x1f;
            break;
        case 1:
            if (b->mUnk_a8-- > 0) {
                return;
            }
            b->mUnk_a8 = 0;
            b->mUnk_a0 += b->mUnk_a4;
            b->mUnk_a4 -= 4;
            if (b->mUnk_a4 < 0) {
                if (b->mUnk_a0 <= 0x4a) {
                    b->mUnk_a0 = 0x4a;
                    b->mUnk_b0 = 2;
                }
            }
            b->mUnk_00.mUnk_04 = b->mUnk_ac->mUnk_80;
            break;
        case 2:
            if (func_020a1154(b->mUnk_ac->mUnk_74) == 0) {
                b->mUnk_a8 = 0x1e;
                b->mUnk_a4 = 8;
                b->mUnk_b0 = 3;
            }
            b->mUnk_00.mUnk_04 = b->mUnk_ac->mUnk_80;
            break;
        case 3:
            if (b->mUnk_a8-- <= 0) {
                b->mUnk_a8 = 0;
                b->mUnk_a0 += b->mUnk_a4;
                b->mUnk_a4 -= 4;
                if (b->mUnk_a4 < 0) {
                    if (b->mUnk_a0 <= 0) {
                        b->mUnk_a0 = 0;
                        b->mUnk_b0 = 0;
                        b->mUnk_00.mUnk_02 |= data_02156838;
                        b->mUnk_00.mUnk_02 |= data_0215683c;
                    }
                }
            }
            b->mUnk_00.mUnk_04 = b->mUnk_ac->mUnk_80;
            break;
    }
}

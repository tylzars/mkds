#include "01/code_02182f98.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0209bef0.h"

void *func_ov001_021830e8(void) {
    return (void *) func_0209bf1c((u32) (func_ov001_021831f0), (u32) (func_ov001_02183138),
                                  (u32) (func_ov001_02187098));
}

void *func_ov001_021830cc(void) {
    return (void *) func_0209bf1c((u32) (func_ov001_02183158), (u32) (func_ov001_02183138),
                                  (u32) (func_ov001_02187098));
}

void *func_ov001_021830b4(void) {
    return (void *) func_0209bf48((u32) (func_ov001_02183450), (u32) (func_ov001_021832cc), (u32) (0));
}

void func_ov001_021830a8(void) {
    data_ov001_021a9b94 = 0;
}

void func_ov001_02183090(void) {
    s32 v = data_ov001_021a9b94 + 1;
    if (v >= 3) {
        v = 0;
    }
    data_ov001_021a9b94 = v;
}

void func_ov001_02182f98(void *param_1, Unk02181c3c *param_2, void *param_3, u32 param_4) {
    s32 a;
    s32 e;
    Vec3 b;
    s32 m[9];
    Vec3 c;
    Vec3 d;

    if (param_2->mUnk_0b0 > 0 && param_2->mUnk_0a0 != 0 && (param_2->mUnk_000.mUnk_02 & 1) == 0 &&
        (s32) (param_2->mUnk_000.mUnk_78 & 0x3fffffe0) < 0x3d090) {
        b.x = param_2->mUnk_000.mUnk_04.x;
        b.y = param_2->mUnk_000.mUnk_04.y - 0x16000;
        b.z = param_2->mUnk_000.mUnk_04.z;
        a = 0x1e;
        func_01ff9048(0x14, &a, 1);
        func_01ff9048(0x19, func_020e6cbc(&b), 0xc);
        e = param_2->mUnk_0b0;
        if (e < 0x1000) {
            c.x = e;
            c.y = e;
            c.z = e;
            func_01ff9048(0x1b, &c, 3);
        }
        func_01ff9048(0x1b, &param_2->mUnk_000.mUnk_1c, 3);
        func_02146d44(m, data_0215d4b4[(data_ov001_021a656c[data_ov001_021a9b94] >> 4) * 2 + 1],
                      data_0215d4b4[(data_ov001_021a656c[data_ov001_021a9b94] >> 4) * 2]);
        func_01ff9048(0x1a, m, 9);
        d.x = 0x199a;
        d.y = 0x2000;
        d.z = 0x199a;
        func_01ff9048(0x1b, &d, 3);
        func_020e5348(8, param_4);
    }
}

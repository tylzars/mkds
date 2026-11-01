#include "01/code_02185f04.h"
#include "01/code_0219e000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020eb000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_02118000.h"
#include "Main/Unknown/code_0211e000.h"
#include "code_02147cd8.h"

s32 func_ov001_021860cc(Unk02188950 *param_1, Vec3 *param_2, s32 param_3, Vec3 *param_4) {
    s32 d1;
    s32 d2;
    s32 d3;

    switch (param_1->mUnk_234) {
        case 0:
            param_3 += param_1->mUnk_25c;
            d1 = param_2->x - param_1->mUnk_238.x;
            d2 = param_2->y - param_1->mUnk_238.y;
            d3 = param_2->z - param_1->mUnk_238.z;
            if ((s64) d3 * d3 + ((s64) d1 * d1 + (s64) d2 * d2) < (s64) param_3 * param_3) {
                func_020eb3f0(param_2, &param_1->mUnk_238, param_3, param_4);
                return 1;
            }
            return 0;
        case 2:
            return func_020ead80(param_2, &param_1->mUnk_238, &param_1->mUnk_000.mUnk_28.mUnk_00, param_1->mUnk_25c,
                                 param_1->mUnk_260, param_1->mUnk_260, param_3, param_4);
        case 1:
            return func_020eafc4(param_2, &param_1->mUnk_238, &param_1->mUnk_000.mUnk_28.mUnk_00,
                                 (Vec3 *) &param_1->mUnk_25c, (Vec3 *) &param_1->mUnk_25c, param_3, param_4);
        default:
            return 0;
    }
}

s32 func_ov001_02185fb0(Unk02188950 *param_1, Unk02185fb0_1 *param_2, u8 *param_3, u8 *param_4) {
    Vec3 v;
    s64 k;
    u32 mode;
    UnkFunc *fn;

    mode = *param_3;
    param_1->mUnk_2d8 = *param_4;
    param_1->mUnk_000.mUnk_10.x = 0;
    param_1->mUnk_000.mUnk_10.y = 0;
    param_1->mUnk_000.mUnk_10.z = 0;
    if (mode == 1) {
        v.x = param_1->mUnk_000.mUnk_04.x - param_2->mUnk_80;
        v.y = 0;
        v.z = param_1->mUnk_000.mUnk_04.z - param_2->mUnk_88;
        if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
            func_02039860(&v, &v);
            k = -param_1->mUnk_0a0->mUnk_024;
            param_1->mUnk_000.mUnk_10.x = (s32) (((s64) v.x * k) >> 12);
            param_1->mUnk_000.mUnk_10.y = (s32) (((s64) v.y * k) >> 12);
            param_1->mUnk_000.mUnk_10.z = (s32) (((s64) v.z * k) >> 12);
            func_02147fd8(param_1->mUnk_0a0->mUnk_028, &v, &param_1->mUnk_1c8, &param_1->mUnk_1c8);
        }
        fn = param_1->mUnk_2d4;
        param_1->mUnk_2d4 = 0;
        if (fn) {
            fn(param_1, param_2);
        }
    }
    if (param_1->mUnk_2d0 == 0) {
        param_1->mUnk_2d0 = 0x1f;
    }
    return param_1->mUnk_2d8;
}

s32 func_ov001_02185f04(Unk02188950 *param_1, Unk02185f04_1 *param_2, u8 *param_3, u8 *param_4) {
    Vec3 v;
    UnkFunc *fn;

    param_1->mUnk_2e0 = *param_4;
    v.x = param_1->mUnk_000.mUnk_04.x - param_2->mUnk_50;
    v.y = 0;
    v.z = param_1->mUnk_000.mUnk_04.z - param_2->mUnk_58;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        func_02039860(&v, &v);
        func_02147fd8(param_1->mUnk_0a0->mUnk_02c, &v, &param_1->mUnk_1c8, &param_1->mUnk_1c8);
    }
    fn = param_1->mUnk_2dc;
    param_1->mUnk_2dc = 0;
    if (fn) {
        fn(param_1, param_2);
    }
    return param_1->mUnk_2e0;
}

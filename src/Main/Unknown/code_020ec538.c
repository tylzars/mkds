#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020e43a8.h"
#include "Main/Unknown/code_020ec538.h"

#include "Main/Unknown/code_020d6000.h"
#include "code_02147cd8.h"

const Vec3 data_0215957c = {0x1000, 0, 0};
const Vec3 data_02159588 = {0x1000, 0, 0};
const Vec3 data_02159594 = {0, 0, 0};

void func_020ec854(Unk020e43a8 *param_1, s32 param_2, u32 param_3, u16 param_4, u32 param_5, s32 param_6) {
    param_1->mUnk_0a0 = param_2;
    param_1->mUnk_0a4 = param_3;
    param_1->mUnk_0a8 = 1;
    param_1->mUnk_0ac = 0;
    param_1->mUnk_0ae = param_4;
    param_1->mUnk_0b0 = param_5;
    param_1->mUnk_0b4 = param_6;
}

BOOL func_020ec7e8(Unk020e43a8 *param_1) {
    if (param_1->mUnk_0a8) {
        param_1->mUnk_0ac = param_1->mUnk_0ac + param_1->mUnk_0ae;
    } else {
        param_1->mUnk_0ac = param_1->mUnk_0ac - param_1->mUnk_0ae;
    }
    param_1->mUnk_00.mUnk_10.y = param_1->mUnk_00.mUnk_10.y - param_1->mUnk_0a4;
    Vec3Add(&param_1->mUnk_00.mPos, &param_1->mUnk_00.mUnk_10, &param_1->mUnk_00.mPos);
    return param_1->mUnk_00.mPos.y < param_1->mUnk_0a0;
}

void func_020ec6e4(Unk020e43a8 *param_1, Unk020ec6e4 *param_2) {
    Vec3 v;
    s32 s;

    Vec3Sub(&param_1->mUnk_00.mPos, &param_2->mUnk_080, &v);
    if ((s64) v.z * param_2->mUnk_0a4 - (s64) v.x * param_2->mUnk_0ac < 0) {
        s32 x = param_2->mUnk_050.x;
        s32 z = param_2->mUnk_050.z;
        v.z = -x;
        v.x = z;
        v.y = 0;
        param_1->mUnk_0a8 = 1;
    } else {
        s32 x = param_2->mUnk_050.x;
        s32 z = -param_2->mUnk_050.z;
        v.z = x;
        v.x = z;
        v.y = 0;
        param_1->mUnk_0a8 = 0;
    }
    s = param_1->mUnk_0b4;
    param_1->mUnk_00.mUnk_10.x = (s32) (((s64) v.x * s) >> 12);
    param_1->mUnk_00.mUnk_10.y = (s32) (((s64) v.y * s) >> 12);
    param_1->mUnk_00.mUnk_10.z = (s32) (((s64) v.z * s) >> 12);
    param_1->mUnk_00.mUnk_10.x = param_1->mUnk_00.mUnk_10.x + (param_2->mUnk_0a4 >> 1);
    param_1->mUnk_00.mUnk_10.z = param_1->mUnk_00.mUnk_10.z + (param_2->mUnk_0ac >> 1);
    param_1->mUnk_00.mUnk_10.y = param_1->mUnk_0b0;
}

void func_020ec538(Unk020e43a8 *param_1, const Unk020ec6e4 *param_2) {
    Vec3 out;
    Vec3 a;
    Vec3 b;
    s32 s;

    a = param_2 ? param_2->mUnk_050 : param_1->mUnk_00.mPos;
    b = param_2 ? param_2->mUnk_05c : data_02159594;
    Vec3Sub(&param_1->mUnk_00.mPos, &a, &out);
    if ((s64) out.z * b.x - (s64) out.x * b.z < 0) {
        if (func_020d6f78(&b, &out) == 0) {
            out = data_0215957c;
        } else {
            s32 x = out.x;
            s32 z = out.z;
            out.z = -x;
            out.x = z;
            out.y = 0;
        }
        param_1->mUnk_0a8 = 1;
    } else {
        if (func_020d6f78(&b, &out) == 0) {
            out = data_02159588;
        } else {
            s32 x = out.x;
            s32 z = -out.z;
            out.z = x;
            out.x = z;
            out.y = 0;
        }
        param_1->mUnk_0a8 = 0;
    }
    s = param_1->mUnk_0b4;
    param_1->mUnk_00.mUnk_10.x = (s32) (((s64) out.x * s) >> 12);
    param_1->mUnk_00.mUnk_10.y = (s32) (((s64) out.y * s) >> 12);
    param_1->mUnk_00.mUnk_10.z = (s32) (((s64) out.z * s) >> 12);
    param_1->mUnk_00.mUnk_10.x = param_1->mUnk_00.mUnk_10.x + (b.x >> 1);
    param_1->mUnk_00.mUnk_10.z = param_1->mUnk_00.mUnk_10.z + (b.z >> 1);
    param_1->mUnk_00.mUnk_10.y = param_1->mUnk_0b0;
}

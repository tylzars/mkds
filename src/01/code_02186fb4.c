#include "01/code_02186fb4.h"
#include "Main/Unknown/code_02148000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02021000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020e6000.h"

u16 func_ov001_02187024(Vec3 *param_1, Vec3 *param_2, s32 param_3, s32 param_4) {
    s32 diff = (u16) (func_02148714(param_1->x - param_2->x, param_1->z - param_2->z) - param_4);
    s32 res;

    if (param_3 < 0) {
        param_3 = -param_3;
    }
    if (diff > 0x8000) {
        diff -= 0x10000;
    }
    res = -param_3;
    if (diff >= res) {
        if (diff <= param_3) {
            param_3 = diff;
        }
        res = param_3;
    }
    return param_4 + res;
}

u16 func_ov001_02186fb4(Vec3 *param_1, Vec3 *param_2, s32 param_3, s32 param_4, s32 param_5) {
    s32 diff = (u16) (func_02148714(param_1->x - param_2->x, param_1->z - param_2->z) - param_5);
    s32 limit;
    s32 res;
    s32 target;

    if (param_3 < 0) {
        limit = -param_3;
    } else {
        limit = param_3;
    }
    if (diff > 0x8000) {
        diff -= 0x10000;
    }
    if (param_3 < 0) {
        diff += param_4;
        target = diff - 0x4000;
    } else {
        diff -= param_4;
        target = diff + 0x4000;
    }
    res = -limit;
    if (target >= res) {
        if (target <= limit) {
            limit = target;
        }
        res = limit;
    }
    return param_5 + res;
}

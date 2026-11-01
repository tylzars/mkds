#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d94dc.h"

s32 func_020d3e34(Vec3 *param_1, s32 param_2, Unk020e71a0 *param_3, Vec3 *param_4) {
    s32 t;
    s32 u;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 r;
    s32 n;
    if (param_3->mUnk_02 & 1) {
        return 0;
    }
    switch (param_3->mUnk_98->mUnk_08) {
        case 1:
            t = param_2 + param_3->mUnk_58.x;
            n = -t;
            dz = param_1->z - param_3->mUnk_04.z;
            if (dz > t || dz < n) {
                r = 0;
            } else {
                dx = param_1->x - param_3->mUnk_04.x;
                if (dx > t || dx < n) {
                    r = 0;
                } else {
                    dy = param_1->y - param_3->mUnk_04.y;
                    if (dy > t || dy < n) {
                        r = 0;
                    } else {
                        r = (s64) dx * dx + (s64) dy * dy + (s64) dz * dz < (s64) t * t;
                    }
                }
            }
            if (r == 0) {
                return 0;
            }
            func_020eb3f0(param_1, &param_3->mUnk_04, t, param_4);
            return 1;
        case 2:
            t = param_2 + param_3->mUnk_58.x;
            u = param_2 + param_3->mUnk_58.y;
            n = -t;
            dz = param_1->z - param_3->mUnk_04.z;
            if (dz > t || dz < n) {
                r = 0;
            } else {
                dx = param_1->x - param_3->mUnk_04.x;
                if (dx > t || dx < n) {
                    r = 0;
                } else {
                    dy = param_1->y - param_3->mUnk_04.y;
                    if (dy > u || dy < -u) {
                        r = 0;
                    } else {
                        r = (s64) dx * dx + (s64) dz * dz < (s64) t * t;
                    }
                }
            }
            if (r == 0) {
                return 0;
            }
            func_020eb2a0(param_1, &param_3->mUnk_04, t, u, param_4);
            return 1;
        case 3:
            return func_020ead80(param_1, &param_3->mUnk_04, &param_3->mUnk_28.mUnk_00, param_3->mUnk_58.x,
                                 param_3->mUnk_58.y, param_3->mUnk_58.y, param_2, param_4) != 0;
        case 4:
            return func_020eafc4(param_1, &param_3->mUnk_04, &param_3->mUnk_28.mUnk_00, &param_3->mUnk_58,
                                 &param_3->mUnk_58, param_2, param_4) != 0;
        case 0:
            return 0;
        case 5:
            if (param_3->mUnk_98->mUnk_18 != 0) {
                return param_3->mUnk_98->mUnk_18(param_3, param_1, param_2, param_4) != 0;
            }
            return 0;
        default:
            return 0;
    }
}

s32 func_020d3e18(void) {
    return data_0217b4e4 != 0;
}

s32 func_020d3df4(s32 param_1) {
    return data_0217b4e4 != 0 ? param_1 - data_0217b4e4->mUnk_04 : 0x270f000;
}

s32 func_020d3dd8(void) {
    return data_0217b4e4 != 0 ? data_0217b4e4->mUnk_30 : 0;
}

u32 func_020d3dbc(void) {
    return data_0217b4e4 != 0 ? data_0217b4e4->mUnk_2c : 0;
}

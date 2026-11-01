#include "00/code_02193634.h"
#include "00/code_02192e04.h"
#include "00/code_02196000.h"
#include "00/unk_021b2000.h"
#include "00/unk_021b3000.h"
#include "code_0213442c.h"

u32 func_ov000_02193634(int param_1, int param_2, int param_3) {
    if (param_1 == 0 && param_2 == 0 && param_3 == 0) {
        return 1;
    }
    if (param_1 < 0 || param_2 < 0 || param_3 < 0) {
        return 0;
    }
    switch (param_2) {
        case 0:
            if (param_1 != 0) {
                return 0;
            }
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (param_1 > 0x1f) {
                return 0;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (param_1 > 0x1e) {
                return 0;
            }
            break;
        case 2:
            if ((param_3 % 4 == 0 && param_3 % 100 != 0) || param_3 % 400 == 0) {
                if (param_1 > 0x1d) {
                    return 0;
                }
            } else if (param_1 > 0x1c) {
                return 0;
            }
            break;
        default:
            return 0;
    }
    if (param_3 < 0x76c) {
        return 0;
    }
    if (param_3 > 0x81f) {
        return 0;
    }
    if (param_3 == 0x81f) {
        if (param_2 > 6) {
            return 0;
        }
        if (param_2 == 6 && param_1 > 6) {
            return 0;
        }
    }
    return 1;
}

s32 func_ov000_02193748(Unk0218f960 *param_1, Unk021937c0Node *param_2, const u8 *param_3) {
    s32 a = 0;
    u32 b = param_2->mUnk_00;

    switch (b) {
        case 0:
            a = func_ov000_02191284(param_1, param_2, param_3);
            break;
        case 1:
            a = func_ov000_02194a0c(param_1, param_2, param_3);
            break;
        case 2:
            a = func_ov000_02192e04(param_1, param_2, param_3);
            break;
        case 4:
            a = func_ov000_021964e4(param_1, param_2, param_3);
            break;
        default:
            func_ov000_0219690c(param_1, data_ov000_021b3264, b);
            func_0213442c(data_ov000_021b32ac, data_ov000_021b32b0, 0, 0x146);
            break;
    }
    if (a != 0) {
        param_2->mUnk_1c = a;
    }
    return a;
}

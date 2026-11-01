#include "00/code_0218e68c.h"
#include "00/code_0218e3b8.h"
#include "00/code_0218e3c4.h"
#include "00/code_021a8b20.h"

s32 func_ov000_0218e7dc(s32 param_1, u32 param_2) {
    return func_ov000_0218e3b8(param_1, 0xffff, 0x1002, &param_2, 4) != -1 ? 1 : 0;
}

s32 func_ov000_0218e7ac(s32 param_1, u32 param_2) {
    return func_ov000_0218e3b8(param_1, 0xffff, 0x1001, &param_2, 4) != -1 ? 1 : 0;
}

s32 func_ov000_0218e77c(s32 param_1) {
    s32 a;
    s32 b = 4;
    s32 c = func_ov000_0218e3c4(param_1, 0xffff, 0x1002, &a, &b);
    return c != -1 ? a : -1;
}

s32 func_ov000_0218e74c(s32 param_1) {
    s32 a;
    s32 b = 4;
    s32 c = func_ov000_0218e3c4(param_1, 0xffff, 0x1001, &a, &b);
    return c != -1 ? a : -1;
}

s32 func_ov000_0218e68c(s32 param_1, u32 *param_2, u32 *param_3, u32 *param_4) {
    Unk0218e68c a;
    s32 b;
    a.mUnk_00 = param_1;
    a.mUnk_04 = 0;
    if (param_2 != 0) {
        a.mUnk_04 |= 1;
    }
    if (param_3 != 0) {
        a.mUnk_04 |= 8;
    }
    a.mUnk_06 = 0;
    b = func_ov000_021a8b20(&a, 1, 0);
    if (b < 0) {
        return -1;
    }
    if (param_2 != 0) {
        if (b > 0 && (a.mUnk_06 & 0x41) != 0) {
            *param_2 = 1;
        } else {
            *param_2 = 0;
        }
    }
    if (param_3 != 0) {
        if (b > 0 && (a.mUnk_06 & 8) != 0) {
            *param_3 = 1;
        } else {
            *param_3 = 0;
        }
    }
    if (param_4 != 0) {
        if (b > 0 && (a.mUnk_06 & 0x20) != 0) {
            *param_4 = 1;
        } else {
            *param_4 = 0;
        }
    }
    return b;
}

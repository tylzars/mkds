#include "00/code_0218b220.h"

u32 func_ov000_0218b27c(u32 *param_1) {
    return *param_1;
}

u32 func_ov000_0218b260(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value1 = (u32) * (const u16 *) ((value0) + 4u);
    value2 = ((u32) ((s32) value1 >> 8));
    value0 = 255u;
    value2 = (value2) & (value0);
    value1 = (value1 << 8);
    value0 = 0xff00u;
    value1 = (value1) & (value0);
    value2 = (value2) | (value1);
    value0 = (value2 << 16);
    value0 = (value0 >> 16);
    return value0;
}

u16 func_ov000_0218b25c(int param_1) {
    return *(u16 *) (param_1 + 4);
}

u32 func_ov000_0218b248(int param_1) {
    if ((*(u8 *) (param_1 + 0x15) & 2) == 2) {
        return 1;
    }
    return 0;
}

u32 func_ov000_0218b244(int param_1) {
    return *(u32 *) (param_1 + 8);
}

u32 func_ov000_0218b228(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value1 = (u32) * (const u16 *) ((value0) + 12u);
    value2 = ((u32) ((s32) value1 >> 8));
    value0 = 255u;
    value2 = (value2) & (value0);
    value1 = (value1 << 8);
    value0 = 0xff00u;
    value1 = (value1) & (value0);
    value2 = (value2) | (value1);
    value0 = (value2 << 16);
    value0 = (value0 >> 16);
    return value0;
}

void func_ov000_0218b224(int param_1, u32 param_2) {
    *(u32 *) (param_1 + 0x20) = param_2;
    return;
}

u32 func_ov000_0218b220(int param_1) {
    return *(u32 *) (param_1 + 0x20);
}

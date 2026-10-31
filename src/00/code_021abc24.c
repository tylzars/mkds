#include "00/code_021abc24.h"

void func_ov000_021abc4c(int param_1, u32 param_2) {
    int v1;
    int v2;
    func_ov000_021ac37c((u8 *) ((u8 *) (u32) (param_2)), (u32 *) ((u32 *) (u32) (param_1 + 0x14)), 8);
    v1 = *(u32 *) (param_1 + 0x18) >> 3 & 0x3f;
    if (v1 < 0x38) {
        v2 = 0x38 - v1;
    } else {
        v2 = 0x78 - v1;
    }
    func_ov000_021abca0((void *) param_1, data_ov000_021b4be4, v2);
    func_ov000_021abca0((void *) param_1, (const u8 *) param_2, 8);
    func_ov000_021ac37c((u8 *) ((u8 *) (u32) (param_2)), (u32 *) ((u32 *) (u32) (param_1)), 0x14);
    return;
}

void func_ov000_021abc24(u32 param_1, u32 param_2) {
    func_ov000_021abca0((void *) param_1, data_ov000_021b4be5, 0x2c);
    func_ov000_021ac37c((u8 *) ((u8 *) (u32) (param_2)), (u32 *) ((u32 *) (u32) (param_1)), 0x14);
    return;
}

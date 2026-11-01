#include "00/code_02188694.h"

#pragma opt_common_subs off

void func_ov000_021886fc(int param_1, u32 param_2) {
    int v1;
    v1 = func_ov000_02188584(0x10);
    func_0214d02c((u32 *) ((u32 *) (u32) (param_2)), (u32 *) ((u32 *) (u32) (v1 + param_1 * 0x100)), 0xf0);
    return;
}

void *func_ov000_021886c4(u8 param_1, u32 param_2) {
    u32 *v1;
    u32 v2;
    v1 = (u32 *) func_ov000_02188584(1);
    if ((*(u8 *) (v1 + 2) & param_1) == 0) {
        *(u8 *) (v1 + 2) = *(u8 *) (v1 + 2) | (u8) param_1;
        v2 = (*(UnkWordFunc *) *v1)(param_1, param_2);
        return (void *) v2;
    }
    return 0;
}

void func_ov000_02188694(u8 param_1, void *param_2, u32 param_3) {
    u32 v1 = func_ov000_02188584(1);
    if ((*(u8 *) (v1 + 8) & param_1) != 0) {
        *(u8 *) (v1 + 8) = *(u8 *) (8 + (u32) v1) & ~param_1;
        v1 = 4 + v1;
        (**(UnkFunc **) v1)(param_1, (u32) param_2, param_3);
    }
    return;
}

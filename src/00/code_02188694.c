#include "00/code_02188694.h"
#include "00/code_021884d8.h"
#include "code_0214d018.h"

#pragma opt_common_subs off

void func_ov000_021886fc(int param_1, void *param_2) {
    int v1;
    v1 = func_ov000_02188584(0x10);
    MIi_CpuCopy32(param_2, ((u32 *) (u32) (v1 + param_1 * 0x100)), 0xf0);
    return;
}

void *func_ov000_021886c4(u8 param_1, u32 param_2) {
    Unk021884e4 *v1;
    void *v2;
    v1 = (Unk021884e4 *) func_ov000_02188584(1);
    if ((v1->mUnk_08 & param_1) == 0) {
        v1->mUnk_08 = v1->mUnk_08 | (u8) param_1;
        v2 = v1->mUnk_00(param_1, param_2);
        return v2;
    }
    return NULL;
}

void func_ov000_02188694(u8 param_1, void *param_2, u32 param_3) {
    Unk021884e4 *v1 = (Unk021884e4 *) func_ov000_02188584(1);
    if ((v1->mUnk_08 & param_1) != 0) {
        v1->mUnk_08 = v1->mUnk_08 & ~param_1;
        v1->mUnk_04(param_1, (u32) param_2, param_3);
    }
    return;
}

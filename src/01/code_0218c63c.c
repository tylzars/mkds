#include "01/code_0218c63c.h"

void func_ov001_0218c728(Unk02188950 *param_1) {
    s32 *v1;
    Unk02188950_a0 *v2;
    v2 = param_1->mUnk_0a0;
    func_ov001_0218875c(param_1, (s32) (v2->mUnk_008), (s32) (v2->mUnk_00c), (s32) (v2->mUnk_214));
    func_ov001_021888a4(param_1, 0, (s32) (param_1->mUnk_0a0->mUnk_00c));
    v1 = &param_1->mUnk_2a4;
    *v1 = ((u32) 0x00011800u);
    param_1->mUnk_298 = *v1;
    v1 = &param_1->mUnk_2ac;
    *v1 = ((u32) 0x0000c000u);
    param_1->mUnk_2a0 = *v1;
}

void func_ov001_0218c6b4(Unk02188950 *param_1) {
    u32 v1;
    u32 v2;
    int v3;
    Unk02188950_a0 *v4;
    int v5;
    v4 = param_1->mUnk_0a0;
    v3 = v4->mUnk_00c;
    v5 = v4->mUnk_008;
    v1 = _s32_div_f(v5, 0x14);
    v2 = _s32_div_f(v3, 0x14);
    func_ov001_021886f8(param_1, (u32) (v5 << 1), v1, (u32) (v3 << 1), (int) (v4->mUnk_214 << 1), v2);
    func_ov001_0218883c(param_1, 0, (u32) 0, (u32) 0, (u32) (((u32) 0x00000e00u)));
    param_1->mUnk_2a4 = ((u32) 0x00023000u);
    param_1->mUnk_2ac = ((u32) 0x00018000u);
}

void func_ov001_0218c63c(Unk02188950 *param_1) {
    u32 v1;
    u32 v2;
    int v3;
    Unk02188950_a0 *v4;
    int v5;
    v4 = param_1->mUnk_0a0;
    v3 = v4->mUnk_00c;
    v5 = v4->mUnk_008;
    v1 = _s32_div_f(v5, 0x14);
    v2 = _s32_div_f(v3, 0x14);
    func_ov001_021886f8(param_1, (u32) (v5 * 3), v1, (u32) (v3 * 3), (int) (v4->mUnk_214 * 3), v2);
    func_ov001_0218883c(param_1, 0, (u32) 0, (u32) 0, (u32) (((u32) 0x00000e00u)));
    param_1->mUnk_2a4 = ((u32) 0x00034800u);
    param_1->mUnk_2ac = ((u32) 0x00024000u);
}

#include "01/code_0218c63c.h"

void func_ov001_0218c728(int param_1) {
    u32 *v1;
    int v2;
    v2 = *(int *) (param_1 + 0xa0);
    func_ov001_0218875c((Unk02188950 *) param_1, (s32) (*(u32 *) (v2 + 8)), (s32) (*(u32 *) (v2 + 0xc)), (s32) (*(u32 *) (v2 + 0x214)));
    func_ov001_021888a4((Unk02188950 *) param_1, 0, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0xc)));
    v1 = (u32 *) (param_1 + 0x2a4);
    *v1 = ((u32) 0x00011800u);
    *(u32 *) (param_1 + 0x298) = *v1;
    v1 = (u32 *) (param_1 + 0x2ac);
    *v1 = ((u32) 0x0000c000u);
    *(u32 *) (param_1 + 0x2a0) = *v1;
}

void func_ov001_0218c6b4(int param_1) {
    u32 v1;
    u32 v2;
    int v3;
    int v4;
    int v5;
    v4 = *(int *) (param_1 + 0xa0);
    v3 = *(int *) (v4 + 0xc);
    v5 = *(int *) (v4 + 8);
    v1 = _s32_div_f(v5, 0x14);
    v2 = _s32_div_f(v3, 0x14);
    func_ov001_021886f8(param_1, (u32) (v5 << 1), v1, (u32) (v3 << 1),
                        (int) (*(int *) (v4 + 0x214) << 1), v2);
    func_ov001_0218883c(param_1, 0, (u32) 0, (u32) 0, (u32) (((u32) 0x00000e00u)));
    *(u32 *) (param_1 + 0x2a4) = ((u32) 0x00023000u);
    *(u32 *) (param_1 + 0x2ac) = ((u32) 0x00018000u);
}

void func_ov001_0218c63c(int param_1) {
    u32 v1;
    u32 v2;
    int v3;
    int v4;
    int v5;
    v4 = *(int *) (param_1 + 0xa0);
    v3 = *(int *) (v4 + 0xc);
    v5 = *(int *) (v4 + 8);
    v1 = _s32_div_f(v5, 0x14);
    v2 = _s32_div_f(v3, 0x14);
    func_ov001_021886f8(param_1, (u32) (v5 * 3), v1, (u32) (v3 * 3),
                        (int) (*(int *) (v4 + 0x214) * 3), v2);
    func_ov001_0218883c(param_1, 0, (u32) 0, (u32) 0, (u32) (((u32) 0x00000e00u)));
    *(u32 *) (param_1 + 0x2a4) = ((u32) 0x00034800u);
    *(u32 *) (param_1 + 0x2ac) = ((u32) 0x00024000u);
}

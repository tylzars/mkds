#include "01/code_02188950.h"
#include "01/code_0218c63c.h"
#include "code_02133048.h"

void func_ov001_0218c728(Unk02188950 *a) {
    s32 *v1;
    Unk02188950_a0 *v2;
    v2 = a->mPrm;
    func_ov001_0218875c(a, (s32) (v2->mUnk_008), (s32) (v2->mUnk_00c), (s32) (v2->mUnk_214));
    func_ov001_021888a4(a, 0, (s32) (a->mPrm->mUnk_00c));
    v1 = &a->mUnk_2a4;
    *v1 = ((u32) 0x00011800u);
    a->mUnk_298 = *v1;
    v1 = &a->mUnk_2ac;
    *v1 = ((u32) 0x0000c000u);
    a->mUnk_2a0 = *v1;
}

void func_ov001_0218c6b4(Unk02188950 *a) {
    u32 v1;
    u32 v2;
    int v3;
    Unk02188950_a0 *v4;
    int v5;
    v4 = a->mPrm;
    v3 = v4->mUnk_00c;
    v5 = v4->mUnk_008;
    v1 = _s32_div_f(v5, 0x14);
    v2 = _s32_div_f(v3, 0x14);
    func_ov001_021886f8(a, v5 << 1, v1, v3 << 1, v4->mUnk_214 << 1, v2);
    func_ov001_0218883c(a, 0, (u32) 0, (u32) 0, (u32) (((u32) 0x00000e00u)));
    a->mUnk_2a4 = ((u32) 0x00023000u);
    a->mUnk_2ac = ((u32) 0x00018000u);
}

void func_ov001_0218c63c(Unk02188950 *a) {
    u32 v1;
    u32 v2;
    int v3;
    Unk02188950_a0 *v4;
    int v5;
    v4 = a->mPrm;
    v3 = v4->mUnk_00c;
    v5 = v4->mUnk_008;
    v1 = _s32_div_f(v5, 0x14);
    v2 = _s32_div_f(v3, 0x14);
    func_ov001_021886f8(a, v5 * 3, v1, v3 * 3, v4->mUnk_214 * 3, v2);
    func_ov001_0218883c(a, 0, (u32) 0, (u32) 0, (u32) (((u32) 0x00000e00u)));
    a->mUnk_2a4 = ((u32) 0x00034800u);
    a->mUnk_2ac = ((u32) 0x00024000u);
}

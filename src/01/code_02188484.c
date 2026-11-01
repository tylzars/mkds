#include "01/code_02188484.h"

void func_ov001_021888a4(Unk02188950 *param_1, s32 param_2, s32 param_3) {
    if (param_2 == 0) {
        param_1->mUnk_27c = 1;
    } else {
        param_1->mUnk_27c = 2;
    }
    param_1->mUnk_280 = param_1->mUnk_28c = 0;
    param_1->mUnk_284 = param_1->mUnk_290 = param_2;
    param_1->mUnk_288 = param_1->mUnk_294 = 0;
    param_1->mUnk_2b0 = 0;
    param_1->mUnk_298 = param_1->mUnk_2a4 = param_3;
    param_1->mUnk_29c = param_1->mUnk_2a8 = 0xa000;
    param_1->mUnk_2a0 = param_1->mUnk_2ac = param_3;
    param_1->mUnk_2b4 = 0;
}

void func_ov001_0218883c(Unk02188950 *param_1, int param_2, u32 param_3, u32 param_4, u32 param_5) {
    if (param_2 == 0) {
        param_1->mUnk_27c = 1;
    } else {
        param_1->mUnk_27c = 2;
    }
    param_1->mUnk_28c = 0;
    param_1->mUnk_290 = param_2;
    param_1->mUnk_294 = 0;
    param_1->mUnk_2b0 = param_3;
    param_1->mUnk_2a4 = param_4;
    param_1->mUnk_2a8 = ((u32) 0x0000a000u);
    param_1->mUnk_2ac = param_4;
    param_1->mUnk_2b4 = param_5;
}

void func_ov001_0218875c(Unk02188950 *param_1, s32 param_2, s32 param_3, s32 param_4) {
    if (param_4 == 0) {
        param_1->mUnk_234 = 0;
    } else {
        param_1->mUnk_234 = 2;
    }
    param_1->mUnk_244 = param_1->mUnk_250 = 0;
    param_1->mUnk_248 = param_1->mUnk_254 = param_2;
    param_1->mUnk_24c = param_1->mUnk_258 = 0;
    param_1->mUnk_274 = 0;
    param_1->mUnk_25c = param_1->mUnk_268 = param_3;
    param_1->mUnk_260 = param_1->mUnk_26c = param_4;
    param_1->mUnk_264 = param_1->mUnk_270 = param_3;
    param_1->mUnk_278 = 0;
    param_1->mUnk_238.x = param_1->mUnk_000.mUnk_04.x + param_1->mUnk_244;
    param_1->mUnk_238.y = param_1->mUnk_000.mUnk_04.y + param_1->mUnk_248;
    param_1->mUnk_238.z = param_1->mUnk_000.mUnk_04.z + param_1->mUnk_24c;
}

void func_ov001_021886f8(Unk02188950 *param_1, u32 param_2, u32 param_3, u32 param_4, int param_5, u32 param_6) {
    if (param_5 == 0) {
        param_1->mUnk_234 = 0;
    } else {
        param_1->mUnk_234 = 2;
    }
    param_1->mUnk_250 = 0;
    param_1->mUnk_254 = param_2;
    param_1->mUnk_258 = 0;
    param_1->mUnk_274 = param_3;
    param_1->mUnk_268 = param_4;
    param_1->mUnk_26c = param_5;
    param_1->mUnk_270 = param_4;
    param_1->mUnk_278 = param_6;
}

void func_ov001_02188644(Unk02188950 *param_1, int param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6,
                         u32 param_7) {
    int *v1;
    int *v2;
    param_1->mUnk_27c = 0;
    if ((param_1->mUnk_000.mUnk_02 & ((u32) 0x00000400u)) != 0) {
        param_2 = -param_2;
    }
    v2 = &param_1->mUnk_28c;
    *v2 = param_2;
    param_1->mUnk_280 = *v2;
    v1 = &param_1->mUnk_290;
    *v1 = param_3;
    param_1->mUnk_284 = *v1;
    v1 = &param_1->mUnk_294;
    *v1 = param_4;
    param_1->mUnk_288 = *v1;
    param_1->mUnk_2b0 = 0;
    v1 = &param_1->mUnk_2a4;
    *v1 = param_5;
    param_1->mUnk_298 = *v1;
    v1 = &param_1->mUnk_2a8;
    *v1 = ((u32) 0x0000a000u);
    param_1->mUnk_29c = *v1;
    v1 = &param_1->mUnk_2ac;
    *v1 = param_7;
    param_1->mUnk_2a0 = *v1;
    param_1->mUnk_2b4 = 0;
}

void func_ov001_021885d4(Unk02188950 *param_1, int param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6,
                         u32 param_7, u32 param_8, u32 param_9) {
    param_1->mUnk_27c = 0;
    if ((param_1->mUnk_000.mUnk_02 & ((u32) 0x00000400u)) != 0) {
        param_2 = -param_2;
    }
    param_1->mUnk_28c = param_2;
    param_1->mUnk_290 = param_3;
    param_1->mUnk_294 = param_4;
    param_1->mUnk_2b0 = param_5;
    param_1->mUnk_2a4 = param_6;
    param_1->mUnk_2a8 = ((u32) 0x0000a000u);
    param_1->mUnk_2ac = param_8;
    param_1->mUnk_2b4 = param_9;
}

void func_ov001_021884f0(Unk02188950 *param_1, int param_2, int param_3, int param_4, u32 param_5, u32 param_6,
                         u32 param_7) {
    int *v1;
    int *v2;
    int *v3;
    int *v4;
    int *v5;
    param_1->mUnk_234 = 1;
    if ((param_1->mUnk_000.mUnk_02 & ((u32) 0x00000400u)) != 0) {
        param_2 = -param_2;
    }
    v2 = &param_1->mUnk_250;
    *v2 = param_2;
    v1 = &param_1->mUnk_244;
    *v1 = *v2;
    v3 = &param_1->mUnk_254;
    *v3 = param_3;
    v2 = &param_1->mUnk_248;
    *v2 = *v3;
    v4 = &param_1->mUnk_258;
    *v4 = param_4;
    v3 = &param_1->mUnk_24c;
    *v3 = *v4;
    param_1->mUnk_274 = 0;
    v5 = &param_1->mUnk_268;
    *v5 = param_5;
    param_1->mUnk_25c = *v5;
    v5 = &param_1->mUnk_26c;
    *v5 = param_6;
    param_1->mUnk_260 = *v5;
    v5 = &param_1->mUnk_270;
    *v5 = param_7;
    param_1->mUnk_264 = *v5;
    param_1->mUnk_278 = 0;
    param_1->mUnk_238.x = param_1->mUnk_000.mUnk_04.x + *v1;
    param_1->mUnk_238.y = param_1->mUnk_000.mUnk_04.y + *v2;
    param_1->mUnk_238.z = param_1->mUnk_000.mUnk_04.z + *v3;
}

void func_ov001_02188484(Unk02188950 *param_1, int param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6,
                         u32 param_7, u32 param_8, u32 param_9) {
    param_1->mUnk_234 = 1;
    if ((param_1->mUnk_000.mUnk_02 & ((u32) 0x00000400u)) != 0) {
        param_2 = -param_2;
    }
    param_1->mUnk_250 = param_2;
    param_1->mUnk_254 = param_3;
    param_1->mUnk_258 = param_4;
    param_1->mUnk_274 = param_5;
    param_1->mUnk_268 = param_6;
    param_1->mUnk_26c = param_7;
    param_1->mUnk_270 = param_8;
    param_1->mUnk_278 = param_9;
}

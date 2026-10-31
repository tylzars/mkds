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

void func_ov001_0218883c(int param_1, int param_2, u32 param_3, u32 param_4, u32 param_5) {
    if (param_2 == 0) {
        *(u32 *) (param_1 + 0x27c) = 1;
    } else {
        *(u32 *) (param_1 + 0x27c) = 2;
    }
    *(u32 *) (param_1 + 0x28c) = 0;
    *(int *) (param_1 + 0x290) = param_2;
    *(u32 *) (param_1 + 0x294) = 0;
    *(u32 *) (param_1 + 0x2b0) = param_3;
    *(u32 *) (param_1 + 0x2a4) = param_4;
    *(u32 *) (param_1 + 0x2a8) = ((u32) 0x0000a000u);
    *(u32 *) (param_1 + 0x2ac) = param_4;
    *(u32 *) (param_1 + 0x2b4) = param_5;
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

void func_ov001_021886f8(int param_1, u32 param_2, u32 param_3, u32 param_4, int param_5, u32 param_6) {
    if (param_5 == 0) {
        *(u32 *) (param_1 + 0x234) = 0;
    } else {
        *(u32 *) (param_1 + 0x234) = 2;
    }
    *(u32 *) (param_1 + 0x250) = 0;
    *(u32 *) (param_1 + 0x254) = param_2;
    *(u32 *) (param_1 + 0x258) = 0;
    *(u32 *) (param_1 + 0x274) = param_3;
    *(u32 *) (param_1 + 0x268) = param_4;
    *(int *) (param_1 + 0x26c) = param_5;
    *(u32 *) (param_1 + 0x270) = param_4;
    *(u32 *) (param_1 + 0x278) = param_6;
}

void func_ov001_02188644(int param_1, int param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7) {
    u32 *v1;
    int *v2;
    *(u32 *) (param_1 + 0x27c) = 0;
    if ((*(u16 *) (param_1 + 2) & ((u32) 0x00000400u)) != 0) {
        param_2 = -param_2;
    }
    v2 = (int *) (param_1 + 0x28c);
    *v2 = param_2;
    *(int *) (param_1 + 0x280) = *v2;
    v1 = (u32 *) (param_1 + 0x290);
    *v1 = param_3;
    *(u32 *) (param_1 + 0x284) = *v1;
    v1 = (u32 *) (param_1 + 0x294);
    *v1 = param_4;
    *(u32 *) (param_1 + 0x288) = *v1;
    *(u32 *) (param_1 + 0x2b0) = 0;
    v1 = (u32 *) (param_1 + 0x2a4);
    *v1 = param_5;
    *(u32 *) (param_1 + 0x298) = *v1;
    v1 = (u32 *) (param_1 + 0x2a8);
    *v1 = ((u32) 0x0000a000u);
    *(u32 *) (param_1 + 0x29c) = *v1;
    v1 = (u32 *) (param_1 + 0x2ac);
    *v1 = param_7;
    *(u32 *) (param_1 + 0x2a0) = *v1;
    *(u32 *) (param_1 + 0x2b4) = 0;
}

void func_ov001_021885d4(int param_1, int param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7,
                         u32 param_8, u32 param_9) {
    *(u32 *) (param_1 + 0x27c) = 0;
    if ((*(u16 *) (param_1 + 2) & ((u32) 0x00000400u)) != 0) {
        param_2 = -param_2;
    }
    *(int *) (param_1 + 0x28c) = param_2;
    *(u32 *) (param_1 + 0x290) = param_3;
    *(u32 *) (param_1 + 0x294) = param_4;
    *(u32 *) (param_1 + 0x2b0) = param_5;
    *(u32 *) (param_1 + 0x2a4) = param_6;
    *(u32 *) (param_1 + 0x2a8) = ((u32) 0x0000a000u);
    *(u32 *) (param_1 + 0x2ac) = param_8;
    *(u32 *) (param_1 + 0x2b4) = param_9;
}

void func_ov001_021884f0(int param_1, int param_2, int param_3, int param_4, u32 param_5, u32 param_6, u32 param_7) {
    int *v1;
    int *v2;
    int *v3;
    int *v4;
    u32 *v5;
    *(u32 *) (param_1 + 0x234) = 1;
    if ((*(u16 *) (param_1 + 2) & ((u32) 0x00000400u)) != 0) {
        param_2 = -param_2;
    }
    v2 = (int *) (param_1 + 0x250);
    *v2 = param_2;
    v1 = (int *) (param_1 + 0x244);
    *v1 = *v2;
    v3 = (int *) (param_1 + 0x254);
    *v3 = param_3;
    v2 = (int *) (param_1 + 0x248);
    *v2 = *v3;
    v4 = (int *) (param_1 + 0x258);
    *v4 = param_4;
    v3 = (int *) (param_1 + 0x24c);
    *v3 = *v4;
    *(u32 *) (param_1 + 0x274) = 0;
    v5 = (u32 *) (param_1 + 0x268);
    *v5 = param_5;
    *(u32 *) (param_1 + 0x25c) = *v5;
    v5 = (u32 *) (param_1 + 0x26c);
    *v5 = param_6;
    *(u32 *) (param_1 + 0x260) = *v5;
    v5 = (u32 *) (param_1 + 0x270);
    *v5 = param_7;
    *(u32 *) (param_1 + 0x264) = *v5;
    *(u32 *) (param_1 + 0x278) = 0;
    *(int *) (param_1 + 0x238) = *(int *) (param_1 + 4) + *v1;
    *(int *) (param_1 + 0x23c) = *(int *) (param_1 + 8) + *v2;
    *(int *) (param_1 + 0x240) = *(int *) (param_1 + 0xc) + *v3;
}

void func_ov001_02188484(int param_1, int param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7,
                         u32 param_8, u32 param_9) {
    *(u32 *) (param_1 + 0x234) = 1;
    if ((*(u16 *) (param_1 + 2) & ((u32) 0x00000400u)) != 0) {
        param_2 = -param_2;
    }
    *(int *) (param_1 + 0x250) = param_2;
    *(u32 *) (param_1 + 0x254) = param_3;
    *(u32 *) (param_1 + 0x258) = param_4;
    *(u32 *) (param_1 + 0x274) = param_5;
    *(u32 *) (param_1 + 0x268) = param_6;
    *(u32 *) (param_1 + 0x26c) = param_7;
    *(u32 *) (param_1 + 0x270) = param_8;
    *(u32 *) (param_1 + 0x278) = param_9;
}

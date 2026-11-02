#include "01/code_02188484.h"

void func_ov001_021888a4(Unk02188950 *a, s32 b, s32 c) {
    if (b == 0) {
        a->mUnk_27c = 1;
    } else {
        a->mUnk_27c = 2;
    }
    a->mUnk_280 = a->mUnk_28c = 0;
    a->mUnk_284 = a->mUnk_290 = b;
    a->mUnk_288 = a->mUnk_294 = 0;
    a->mUnk_2b0 = 0;
    a->mUnk_298 = a->mUnk_2a4 = c;
    a->mUnk_29c = a->mUnk_2a8 = 0xa000;
    a->mUnk_2a0 = a->mUnk_2ac = c;
    a->mUnk_2b4 = 0;
}

void func_ov001_0218883c(Unk02188950 *a, int b, u32 c, u32 d, u32 e) {
    if (b == 0) {
        a->mUnk_27c = 1;
    } else {
        a->mUnk_27c = 2;
    }
    a->mUnk_28c = 0;
    a->mUnk_290 = b;
    a->mUnk_294 = 0;
    a->mUnk_2b0 = c;
    a->mUnk_2a4 = d;
    a->mUnk_2a8 = ((u32) 0x0000a000u);
    a->mUnk_2ac = d;
    a->mUnk_2b4 = e;
}

void func_ov001_0218875c(Unk02188950 *a, s32 b, s32 c, s32 d) {
    if (d == 0) {
        a->mUnk_234 = 0;
    } else {
        a->mUnk_234 = 2;
    }
    a->mUnk_244 = a->mUnk_250 = 0;
    a->mUnk_248 = a->mUnk_254 = b;
    a->mUnk_24c = a->mUnk_258 = 0;
    a->mUnk_274 = 0;
    a->mUnk_25c = a->mUnk_268 = c;
    a->mUnk_260 = a->mUnk_26c = d;
    a->mUnk_264 = a->mUnk_270 = c;
    a->mUnk_278 = 0;
    a->mUnk_238.x = a->mUnk_000.mUnk_04.x + a->mUnk_244;
    a->mUnk_238.y = a->mUnk_000.mUnk_04.y + a->mUnk_248;
    a->mUnk_238.z = a->mUnk_000.mUnk_04.z + a->mUnk_24c;
}

void func_ov001_021886f8(Unk02188950 *a, u32 b, u32 c, u32 d, int e, u32 f) {
    if (e == 0) {
        a->mUnk_234 = 0;
    } else {
        a->mUnk_234 = 2;
    }
    a->mUnk_250 = 0;
    a->mUnk_254 = b;
    a->mUnk_258 = 0;
    a->mUnk_274 = c;
    a->mUnk_268 = d;
    a->mUnk_26c = e;
    a->mUnk_270 = d;
    a->mUnk_278 = f;
}

void func_ov001_02188644(Unk02188950 *a, int b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    int *v1;
    int *v2;
    a->mUnk_27c = 0;
    if ((a->mUnk_000.mUnk_02 & ((u32) 0x00000400u)) != 0) {
        b = -b;
    }
    v2 = &a->mUnk_28c;
    *v2 = b;
    a->mUnk_280 = *v2;
    v1 = &a->mUnk_290;
    *v1 = c;
    a->mUnk_284 = *v1;
    v1 = &a->mUnk_294;
    *v1 = d;
    a->mUnk_288 = *v1;
    a->mUnk_2b0 = 0;
    v1 = &a->mUnk_2a4;
    *v1 = e;
    a->mUnk_298 = *v1;
    v1 = &a->mUnk_2a8;
    *v1 = ((u32) 0x0000a000u);
    a->mUnk_29c = *v1;
    v1 = &a->mUnk_2ac;
    *v1 = g;
    a->mUnk_2a0 = *v1;
    a->mUnk_2b4 = 0;
}

void func_ov001_021885d4(Unk02188950 *a, int b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 l) {
    a->mUnk_27c = 0;
    if ((a->mUnk_000.mUnk_02 & ((u32) 0x00000400u)) != 0) {
        b = -b;
    }
    a->mUnk_28c = b;
    a->mUnk_290 = c;
    a->mUnk_294 = d;
    a->mUnk_2b0 = e;
    a->mUnk_2a4 = f;
    a->mUnk_2a8 = ((u32) 0x0000a000u);
    a->mUnk_2ac = h;
    a->mUnk_2b4 = l;
}

void func_ov001_021884f0(Unk02188950 *a, int b, int c, int d, u32 e, u32 f, u32 g) {
    int *v1;
    int *v2;
    int *v3;
    int *v4;
    int *v5;
    a->mUnk_234 = 1;
    if ((a->mUnk_000.mUnk_02 & ((u32) 0x00000400u)) != 0) {
        b = -b;
    }
    v2 = &a->mUnk_250;
    *v2 = b;
    v1 = &a->mUnk_244;
    *v1 = *v2;
    v3 = &a->mUnk_254;
    *v3 = c;
    v2 = &a->mUnk_248;
    *v2 = *v3;
    v4 = &a->mUnk_258;
    *v4 = d;
    v3 = &a->mUnk_24c;
    *v3 = *v4;
    a->mUnk_274 = 0;
    v5 = &a->mUnk_268;
    *v5 = e;
    a->mUnk_25c = *v5;
    v5 = &a->mUnk_26c;
    *v5 = f;
    a->mUnk_260 = *v5;
    v5 = &a->mUnk_270;
    *v5 = g;
    a->mUnk_264 = *v5;
    a->mUnk_278 = 0;
    a->mUnk_238.x = a->mUnk_000.mUnk_04.x + *v1;
    a->mUnk_238.y = a->mUnk_000.mUnk_04.y + *v2;
    a->mUnk_238.z = a->mUnk_000.mUnk_04.z + *v3;
}

void func_ov001_02188484(Unk02188950 *a, int b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 l) {
    a->mUnk_234 = 1;
    if ((a->mUnk_000.mUnk_02 & ((u32) 0x00000400u)) != 0) {
        b = -b;
    }
    a->mUnk_250 = b;
    a->mUnk_254 = c;
    a->mUnk_258 = d;
    a->mUnk_274 = e;
    a->mUnk_268 = f;
    a->mUnk_26c = g;
    a->mUnk_270 = h;
    a->mUnk_278 = l;
}

#include "01/code_02188950.h"

void func_ov001_02188c90(Unk02188950 *a) {
    a->mUnk_180 = 0;
    a->mUnk_194 = 0;
    a->mUnk_198 = 0;
    a->mUnk_19c = 0;
    a->mUnk_1a4 = 1;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = 0;
    a->mUnk_1c0 = 0;
}

void func_ov001_02188c48(Unk02188950 *a, s32 b, s32 c) {
    a->mUnk_180 = 2;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mUnk_1a4 = 1;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = 0;
    a->mUnk_1c0 = 0;
}

void func_ov001_02188c0c(Unk02188950 *a, s32 b, s32 c) {
    a->mUnk_180 = 2;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mUnk_1a4 = 2;
    a->mUnk_1bc = b;
    a->mUnk_1c0 = c;
}

void func_ov001_02188bc4(Unk02188950 *a, s32 b, s32 c) {
    a->mUnk_180 = 3;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mUnk_1a4 = 1;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = 0;
    a->mUnk_1c0 = 0;
}

void func_ov001_02188b78(Unk02188950 *a, s32 b, s32 c) {
    a->mUnk_180 = 0;
    a->mUnk_194 = 0;
    a->mUnk_198 = 0;
    a->mUnk_19c = 0;
    a->mUnk_1a4 = 3;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = b;
    a->mUnk_1c0 = c;
}

void func_ov001_02188b2c(Unk02188950 *a, s32 b, s32 c, s32 d) {
    a->mUnk_180 = 4;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mUnk_1a0 = d;
    a->mUnk_1a4 = 1;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = 0;
    a->mUnk_1c0 = 0;
}

void func_ov001_02188adc(Unk02188950 *a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    a->mUnk_180 = 2;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mUnk_1a4 = 4;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = d;
    a->mUnk_1c0 = e;
    a->mUnk_1c4 = f;
}

void func_ov001_02188a8c(Unk02188950 *a, s32 b, s32 c) {
    a->mUnk_180 = 5;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mUnk_1a0 = 0;
    a->mUnk_1a4 = 0;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = 0;
    a->mUnk_1c0 = 0;
}

void func_ov001_02188a30(Unk02188950 *a, s32 b, s32 c, s32 d, s32 e) {
    s32 value;

    if (a->mUnk_180 == 7) {
        value = 7;
    } else if (a->mUnk_180 == 8) {
        value = 8;
    } else {
        value = 6;
    }
    a->mUnk_180 = value;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mUnk_1a0 = 0;
    a->mUnk_1a4 = 2;
    a->mUnk_1bc = d;
    a->mUnk_1c0 = e;
}

void func_ov001_021889ec(Unk02188950 *a, s32 b, s32 c, s32 d, s32 e) {
    a->mUnk_180 = 2;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mUnk_1a0 = 0;
    a->mUnk_1a4 = 2;
    a->mUnk_1bc = d;
    a->mUnk_1c0 = e;
}

void func_ov001_021889c8(Unk02188950 *a) {
    a->mUnk_1a4 = 0;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = 0;
    a->mUnk_1c0 = 0;
}

void func_ov001_02188998(Unk02188950 *a, Vec3 *b) {
    if (b != NULL) {
        a->mUnk_1ac = *b;
        a->mUnk_188 = *b;
    }
}

void func_ov001_02188980(Unk02188950 *a, Vec3 *b) {
    if (b != NULL) {
        a->mUnk_1ac = *b;
    }
}

void func_ov001_02188968(Unk02188950 *a, Vec3 *b) {
    if (b != NULL) {
        a->mUnk_188 = *b;
    }
}

void func_ov001_02188950(Unk02188950 *a, Vec3 *b) {
    if (b != NULL) {
        a->mUnk_1c8 = *b;
    }
}

#include "01/code_02188950.h"

void func_ov001_02188c90(Unk02188950 *a) {
    a->mAngleState = 0;
    a->mUnk_194 = 0;
    a->mUnk_198 = 0;
    a->mUnk_19c = 0;
    a->mMoveAngleMode = 1;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = 0;
    a->mUnk_1c0 = 0;
}

void func_ov001_02188c48(Unk02188950 *a, s32 b, s32 c) {
    a->mAngleState = 2;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mMoveAngleMode = 1;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = 0;
    a->mUnk_1c0 = 0;
}

void func_ov001_02188c0c(Unk02188950 *a, s32 b, s32 c) {
    a->mAngleState = 2;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mMoveAngleMode = 2;
    a->mUnk_1bc = b;
    a->mUnk_1c0 = c;
}

void func_ov001_02188bc4(Unk02188950 *a, s32 b, s32 c) {
    a->mAngleState = 3;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mMoveAngleMode = 1;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = 0;
    a->mUnk_1c0 = 0;
}

void func_ov001_02188b78(Unk02188950 *a, s32 b, s32 c) {
    a->mAngleState = 0;
    a->mUnk_194 = 0;
    a->mUnk_198 = 0;
    a->mUnk_19c = 0;
    a->mMoveAngleMode = 3;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = b;
    a->mUnk_1c0 = c;
}

void func_ov001_02188b2c(Unk02188950 *a, s32 b, s32 c, s32 d) {
    a->mAngleState = 4;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mUnk_1a0 = d;
    a->mMoveAngleMode = 1;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = 0;
    a->mUnk_1c0 = 0;
}

void func_ov001_02188adc(Unk02188950 *a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    a->mAngleState = 2;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mMoveAngleMode = 4;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = d;
    a->mUnk_1c0 = e;
    a->mUnk_1c4 = f;
}

void func_ov001_02188a8c(Unk02188950 *a, s32 b, s32 c) {
    a->mAngleState = 5;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mUnk_1a0 = 0;
    a->mMoveAngleMode = 0;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = 0;
    a->mUnk_1c0 = 0;
}

void func_ov001_02188a30(Unk02188950 *a, s32 b, s32 c, s32 d, s32 e) {
    s32 value;

    if (a->mAngleState == 7) {
        value = 7;
    } else if (a->mAngleState == 8) {
        value = 8;
    } else {
        value = 6;
    }
    a->mAngleState = value;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mUnk_1a0 = 0;
    a->mMoveAngleMode = 2;
    a->mUnk_1bc = d;
    a->mUnk_1c0 = e;
}

void func_ov001_021889ec(Unk02188950 *a, s32 b, s32 c, s32 d, s32 e) {
    a->mAngleState = 2;
    a->mUnk_198 = b;
    a->mUnk_19c = c;
    a->mUnk_1a0 = 0;
    a->mMoveAngleMode = 2;
    a->mUnk_1bc = d;
    a->mUnk_1c0 = e;
}

void func_ov001_021889c8(Unk02188950 *a) {
    a->mMoveAngleMode = 0;
    a->mUnk_1b8 = 0;
    a->mUnk_1bc = 0;
    a->mUnk_1c0 = 0;
}

void SetAnglePointAndMoveAnglePoint(Unk02188950 *a, Vec3 *b) {
    if (b != NULL) {
        a->mMoveAnglePoint = *b;
        a->mAnglePoint = *b;
    }
}

void SetMoveAnglePoint(Unk02188950 *a, Vec3 *b) {
    if (b != NULL) {
        a->mMoveAnglePoint = *b;
    }
}

void SetAnglePoint(Unk02188950 *a, Vec3 *b) {
    if (b != NULL) {
        a->mAnglePoint = *b;
    }
}

void SetVelocity(Unk02188950 *a, Vec3 *b) {
    if (b != NULL) {
        a->mVelocity = *b;
    }
}

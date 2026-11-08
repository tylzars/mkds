#include "01/code_02188950.h"

void func_ov001_02188c90(Unk02188950 *mapObject) {
    mapObject->mAngleState = 0;
    mapObject->mAnglePerCall = 0;
    mapObject->mAnglePerCallTarget = 0;
    mapObject->mAnglePerCallIncrement = 0;
    mapObject->mMoveAngleMode = 1;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void func_ov001_02188c48(Unk02188950 *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement) {
    mapObject->mAngleState = 2;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mMoveAngleMode = 1;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void func_ov001_02188c0c(Unk02188950 *mapObject, s32 perCallTarget, s32 perCallIncrement) {
    mapObject->mAngleState = 2;
    mapObject->mAnglePerCallTarget = perCallTarget;
    mapObject->mAnglePerCallIncrement = perCallIncrement;
    mapObject->mMoveAngleMode = 2;
    mapObject->mMoveAnglePerCallTarget = perCallTarget;
    mapObject->mMoveAnglePerCallIncrement = perCallIncrement;
}

void func_ov001_02188bc4(Unk02188950 *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement) {
    mapObject->mAngleState = 3;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mMoveAngleMode = 1;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void func_ov001_02188b78(Unk02188950 *mapObject, s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement) {
    mapObject->mAngleState = 0;
    mapObject->mAnglePerCall = 0;
    mapObject->mAnglePerCallTarget = 0;
    mapObject->mAnglePerCallIncrement = 0;
    mapObject->mMoveAngleMode = 3;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = moveAnglePerCallTarget;
    mapObject->mMoveAnglePerCallIncrement = moveAnglePerCallIncrement;
}

void func_ov001_02188b2c(Unk02188950 *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement, s32 d) {
    mapObject->mAngleState = 4;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mUnk_1a0 = d;
    mapObject->mMoveAngleMode = 1;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void func_ov001_02188adc(Unk02188950 *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                         s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement, s32 f) {
    mapObject->mAngleState = 2;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mMoveAngleMode = 4;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = moveAnglePerCallTarget;
    mapObject->mMoveAnglePerCallIncrement = moveAnglePerCallIncrement;
    mapObject->mUnk_1c4 = f;
}

void func_ov001_02188a8c(Unk02188950 *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement) {
    mapObject->mAngleState = 5;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mUnk_1a0 = 0;
    mapObject->mMoveAngleMode = 0;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void func_ov001_02188a30(Unk02188950 *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                         s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement) {
    s32 angleState;

    if (mapObject->mAngleState == 7) {
        angleState = 7;
    } else if (mapObject->mAngleState == 8) {
        angleState = 8;
    } else {
        angleState = 6;
    }
    mapObject->mAngleState = angleState;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mUnk_1a0 = 0;
    mapObject->mMoveAngleMode = 2;
    mapObject->mMoveAnglePerCallTarget = moveAnglePerCallTarget;
    mapObject->mMoveAnglePerCallIncrement = moveAnglePerCallIncrement;
}

void func_ov001_021889ec(Unk02188950 *mapObject, s32 anglePerCallTarget, s32 anglePerCallIncrement,
                         s32 moveAnglePerCallTarget, s32 moveAnglePerCallIncrement) {
    mapObject->mAngleState = 2;
    mapObject->mAnglePerCallTarget = anglePerCallTarget;
    mapObject->mAnglePerCallIncrement = anglePerCallIncrement;
    mapObject->mUnk_1a0 = 0;
    mapObject->mMoveAngleMode = 2;
    mapObject->mMoveAnglePerCallTarget = moveAnglePerCallTarget;
    mapObject->mMoveAnglePerCallIncrement = moveAnglePerCallIncrement;
}

void func_ov001_021889c8(Unk02188950 *mapObject) {
    mapObject->mMoveAngleMode = 0;
    mapObject->mMoveAnglePerCall = 0;
    mapObject->mMoveAnglePerCallTarget = 0;
    mapObject->mMoveAnglePerCallIncrement = 0;
}

void SetAnglePointAndMoveAnglePoint(Unk02188950 *mapObject, Vec3 *point) {
    if (point != NULL) {
        mapObject->mMoveAnglePoint = *point;
        mapObject->mAnglePoint = *point;
    }
}

void SetMoveAnglePoint(Unk02188950 *mapObject, Vec3 *point) {
    if (point != NULL) {
        mapObject->mMoveAnglePoint = *point;
    }
}

void SetAnglePoint(Unk02188950 *mapObject, Vec3 *point) {
    if (point != NULL) {
        mapObject->mAnglePoint = *point;
    }
}

void SetVelocity(Unk02188950 *mapObject, Vec3 *velocity) {
    if (velocity != NULL) {
        mapObject->mVelocity = *velocity;
    }
}

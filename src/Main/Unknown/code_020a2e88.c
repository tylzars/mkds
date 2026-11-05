#include "Main/Unknown/code_020a2e88.h"

void func_020a2ebc(Balloon *a, Vec3 *b) {
    a->mNoKartTimer = 0x1e;
    a->mKartIndex = -1;
    a->mDrawCount = 1;
    a->mDrawList = NULL;
    if (b == NULL) {
        return;
    }
    a->mUnk_00.mPos.x = b->x;
    a->mUnk_00.mPos.y = b->y + 0xf666;
    a->mUnk_00.mPos.z = b->z;
}

// Copies the two vectors into mTargetPos and mTargetVelocity.
void SetBalloonTargetPosAndVelocity(Balloon *a, Vec3 *b, Vec3 *c) {
    a->mTargetPos = *b;
    a->mTargetVelocity = *c;
}

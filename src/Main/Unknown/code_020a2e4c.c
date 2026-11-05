#include "Main/Unknown/code_020a2e4c.h"

void func_020a2e68(Balloon *p0) {
    p0->mUnk_e0 = 0;
}

// Returns mScaleFactor.
s32 GetBalloonScaleFactor(Balloon *p0) {
    return p0->mScaleFactor;
}

// Stores mKartIndex.
void SetBalloonKartIndex(Balloon *p0, u16 p1) {
    p0->mKartIndex = p1;
}

// Stores mDrawCount and mDrawList.
void SetBalloonDrawCountAndList(Balloon *p0, u16 p1, void *p2) {
    p0->mDrawCount = p1;
    p0->mDrawList = p2;
}

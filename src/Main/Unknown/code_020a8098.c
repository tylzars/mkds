#include "Main/Unknown/code_020a8098.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020a826c.h"
#include "Main/Unknown/code_020a8a6c.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_0215d000.h"

void *func_020a824c(void) {
    return CreateMapObjectUpdateList(func_020a8a6c, func_020a826c, NULL);
}

void StartSanboLaunch(Sanbo *p) {
    s32 i;
    RandomState64 *r;
    u16 v1;
    u16 v2;

    for (i = 0; i < p->mPieceCount; i++) {
        r = GetMapObjectRandom();
        r->mValue = (s64) r->mMultiplier * (s64) r->mValue + r->mIncrement;
        v1 = ((u64) (u32) (r->mValue >> 32) * 0x10000) >> 32;
        p->mPieces[i].mPos.x = p->mUnk_000.mPos.x;
        p->mPieces[i].mPos.y = p->mUnk_000.mPos.y + i * 0x14000;
        p->mPieces[i].mPos.z = p->mUnk_000.mPos.z;
        p->mPieces[i].mVelocity.x = ((s64) gPairsByAngle[(v1 >> 4) * 2] * 0x2000) >> 12;
        p->mPieces[i].mVelocity.y = 0x4000;
        p->mPieces[i].mVelocity.z = ((s64) gPairsByAngle[(v1 >> 4) * 2 + 1] * 0x2000) >> 12;
        r = GetMapObjectRandom();
        r->mValue = (s64) r->mMultiplier * (s64) r->mValue + r->mIncrement;
        v2 = ((u64) (u32) (r->mValue >> 32) * 2) >> 32;
        p->mPieces[i].mRotateZAnglePerFrame = (v2 != 0 ? 1 : -1) * 0xaab;
    }
    p->mState2Timer = 300;
    p->mState = 2;
}

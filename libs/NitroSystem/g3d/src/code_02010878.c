#include "code_02010878.h"

void NNS_G3dTexReleaseTexKey(NNSG3dResTex *pTex, NNSG3dTexKey *texKey, NNSG3dTexKey *tex4x4Key) {
    pTex->mTexInfo.mFlag &= ~1;
    pTex->mTex4x4Info.mFlag &= ~1;
    *texKey = pTex->mTexInfo.mVramKey;
    pTex->mTexInfo.mVramKey = 0;
    *tex4x4Key = pTex->mTex4x4Info.mVramKey;
    pTex->mTex4x4Info.mVramKey = 0;
}

u32 NNS_G3dPlttGetRequiredSize(const NNSG3dResTex *pTex) {
    return pTex->mPlttInfo.mSizePltt << 3;
}

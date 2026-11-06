#include "code_020109ac.h"

u32 NNS_G3dTexGetRequiredSize(const NNSG3dResTex *pTex) {
    return pTex->mTexInfo.mSizeTex << 3;
}

u32 NNS_G3dTex4x4GetRequiredSize(const NNSG3dResTex *pTex) {
    return pTex->mTex4x4Info.mSizeTex << 3;
}

#include "code_02010804.h"
#include "gx_load3d.h"

void NNS_G3dPlttSetPlttKey(NNSG3dResTex *pTex, NNSG3dPlttKey plttKey) {
    pTex->mPlttInfo.mVramKey = plttKey;
}

void NNS_G3dPlttLoad(NNSG3dResTex *pTex, BOOL execBeginEnd) {
    if (execBeginEnd != 0) {
        GX_BeginLoadTexPltt();
    }
    GX_LoadTexPltt((u8 *) pTex + pTex->mPlttInfo.mOfsPlttData, (pTex->mPlttInfo.mVramKey & 0xffff) << 3,
                   pTex->mPlttInfo.mSizePltt << 3);
    pTex->mPlttInfo.mFlag |= 1;
    if (execBeginEnd != 0) {
        GX_EndLoadTexPltt();
    }
}

#include "code_020107e4.h"

NNSG3dPlttKey NNS_G3dPlttReleasePlttKey(NNSG3dResTex *pTex) {
    NNSG3dPlttKey plttKey;

    pTex->mPlttInfo.mFlag &= ~1;
    plttKey = pTex->mPlttInfo.mVramKey;
    pTex->mPlttInfo.mVramKey = 0;
    return plttKey;
}

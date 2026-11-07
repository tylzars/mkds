#include "code_02010998.h"

void NNS_G3dTexSetTexKey(NNSG3dResTex *pTex, NNSG3dTexKey texKey, NNSG3dTexKey tex4x4Key) {
    if (texKey != 0) {
        pTex->mTexInfo.mVramKey = texKey;
    }
    if (tex4x4Key != 0) {
        pTex->mTex4x4Info.mVramKey = tex4x4Key;
    }
}

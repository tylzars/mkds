#include "code_020108bc.h"
#include "code_0214c1bc.h"

void NNS_G3dTexLoad(NNSG3dResTex *pTex, BOOL execBeginEnd) {
    u32 texSize;
    u32 tex4x4Size;
    u32 keyAddr;
    u32 vramAddr;
    u8 *plttIdxData;

    if (execBeginEnd != 0) {
        GX_BeginLoadTex();
    }
    texSize = pTex->mTexInfo.mSizeTex << 3;
    if (texSize != 0) {
        GX_LoadTex((u8 *) pTex + pTex->mTexInfo.mOfsTex, (pTex->mTexInfo.mVramKey & 0xffff) << 3, texSize);
        pTex->mTexInfo.mFlag |= 1;
    }
    tex4x4Size = pTex->mTex4x4Info.mSizeTex << 3;
    if (tex4x4Size != 0) {
        keyAddr = pTex->mTex4x4Info.mVramKey & 0xffff;
        vramAddr = keyAddr << 3;
        plttIdxData = (u8 *) pTex + pTex->mTex4x4Info.mOfsTexPlttIdx;
        GX_LoadTex((u8 *) pTex + pTex->mTex4x4Info.mOfsTex, vramAddr, tex4x4Size);
        GX_LoadTex(plttIdxData, 0x20000 + (((keyAddr << 3) & 0x1ffff) >> 1) + ((vramAddr & 0x40000) >> 2),
                   tex4x4Size >> 1);
        pTex->mTex4x4Info.mFlag |= 1;
    }
    if (execBeginEnd != 0) {
        GX_EndLoadTex();
    }
}

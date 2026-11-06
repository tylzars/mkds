#include "code_02010c84.h"

#include "code_02147288.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02170000.h"
#include "00/code_02188720.h"
#include "code_02012b30.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_021479b4.h"
#include "code_0214a4dc.h"
#include "code_0214a748.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_02171000.h"
#include "registers.h"
#include "code_021471bc.h"
#include "code_02147954.h"

// Draws one shape of the model, first sending the material and the texture matrix when sendMat is set.
void NNS_G3dDraw1Mat1Shp(NNSG3dResMdl *resMdl, u32 matId, u32 shpId, BOOL sendMat) {
    u32 words[7];
    NNSG3dMatAnmResult texResult;
    s32 scale[3];
    s32 invScale[3];
    u8 *texMtx;
    NNSG3dResMat *matBlock;
    NNSG3dResShp *shpBlock;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *matData;
    NNSG3dResShpData *shpData;
    s32 posScale;
    void (*sendTexSRT)(NNSG3dMatAnmResult *);
    u32 polyAttr;

    posScale = resMdl->mInfo.mPosScale;
    if (posScale != 0x1000) {
        scale[0] = posScale;
        scale[1] = posScale;
        scale[2] = posScale;
        func_01ff9048(0x1b, scale, 3);
    }
    if (sendMat != 0) {
        matBlock = (NNSG3dResMat *) ((u8 *) resMdl + resMdl->mOfsMat);
        entries = (NNSG3dResDictEntryHeader *) ((u8 *) &matBlock->mDict + matBlock->mDict.mOfsEntry);
        matData = (NNSG3dResMatData *) ((u8 *) matBlock + *(u32 *) (entries->mData + entries->mSizeUnit * matId));
        if (!(matData->mPolyAttr & 0x1f0000)) {
            return;
        }
        words[0] = 0x293130;
        words[1] = matData->mDiffAmb;
        words[2] = matData->mSpecEmi;
        polyAttr = matData->mPolyAttr;
        words[3] = polyAttr;
        if (matData->mFlag & 0x20) {
            words[3] = polyAttr & ~0x1f0000;
        }
        words[4] = 0x2b2a;
        words[5] = matData->mTexImageParam;
        words[6] = matData->mTexPlttBase;
        func_01ff9048(words[0], &words[1], 6);
        if (matData->mFlag & 1) {
            sendTexSRT = data_0216185c[resMdl->mInfo.mTexMtxMode];
            texResult.mUnk_00 = 8;
            texResult.mUnk_2c = matData->mOrigWidth;
            texResult.mUnk_2e = matData->mOrigHeight;
            texResult.mUnk_30 = matData->mMagW;
            texResult.mUnk_34 = matData->mMagH;
            texMtx = matData->mTexMtxData;
            if (!(matData->mFlag & 2)) {
                texResult.mUnk_18[0] = ((u32 *) texMtx)[0];
                texResult.mUnk_18[1] = ((u32 *) texMtx)[1];
                texMtx += 8;
            } else {
                texResult.mUnk_00 |= 1;
            }
            if (!(matData->mFlag & 4)) {
                texResult.mUnk_20[0] = ((s16 *) texMtx)[0];
                texResult.mUnk_20[1] = ((s16 *) texMtx)[1];
                texMtx += 4;
            } else {
                texResult.mUnk_00 |= 2;
            }
            if (!(matData->mFlag & 8)) {
                texResult.mUnk_24[0] = ((u32 *) texMtx)[0];
                texResult.mUnk_24[1] = ((u32 *) texMtx)[1];
            } else {
                texResult.mUnk_00 |= 4;
            }
            sendTexSRT(&texResult);
        }
    }
    shpBlock = (NNSG3dResShp *) ((u8 *) resMdl + resMdl->mOfsShp);
    entries = (NNSG3dResDictEntryHeader *) ((u8 *) &shpBlock->mDict + shpBlock->mDict.mOfsEntry);
    shpData = (NNSG3dResShpData *) ((u8 *) shpBlock + *(u32 *) (entries->mData + entries->mSizeUnit * shpId));
    func_01ff9144((u8 *) shpData + shpData->mOfsDL, shpData->mSizeDL);
    posScale = resMdl->mInfo.mInvPosScale;
    if (posScale != 0x1000) {
        invScale[0] = posScale;
        invScale[1] = posScale;
        invScale[2] = posScale;
        func_01ff9048(0x1b, invScale, 3);
    }
}

// SBC command for a billboard node.
void NNSi_G3dFuncSbc_BB(NNSG3dRS *state, u32 mode) {
    u32 restoreIdx;
    u32 storeIdx;
    s32 clipMtx[16];
    s32 invWV[16];
    s32 camMtx[16];
    u32 timing;
    u32 n = 2;
    Vec3 *pos = &data_0216190c;
    Vec3 *scale = &data_02161918;

    if (state->mFlag & 0x200) {
        if (mode == 0x40 || mode == 0x60) {
            n++;
        }
        if (mode == 0x20 || mode == 0x60) {
            n++;
        }
        state->mC += n;
        return;
    }
    if (mode == 0x40 || mode == 0x60) {
        n++;
        if (!(state->mFlag & 0x100)) {
            if (mode == 0x40) {
                restoreIdx = state->mC[2];
            } else {
                restoreIdx = state->mC[3];
            }
            func_01ff9048(0x14, &restoreIdx, 1);
        }
    }
    if (state->mCbVecFunc[7] != 0) {
        timing = state->mCbVecTiming[7];
    } else {
        timing = 0;
    }
    if (!(state->mFlag & 0x100)) {
        func_01ff9234();
        reg_G3X_GXFIFO = 0x151110;
        reg_G3X_GXFIFO = 0;
        reg_G3X_GXFIFO = 0;
        while (G3X_GetClipMtx(clipMtx) != 0) {
        }
        if (data_0217029c.mFlag & 1) {
            MTX_Copy43To44_(NNS_G3dGlbGetWV(), invWV);
            MTX_Concat44(clipMtx, invWV, clipMtx);
        } else if (data_0217029c.mFlag & 2) {
            MTX_Copy43To44_(&data_0217029c.mCameraMtx, camMtx);
            MTX_Concat44(clipMtx, camMtx, clipMtx);
        }
        pos->x = clipMtx[12];
        pos->y = clipMtx[13];
        pos->z = clipMtx[14];
        scale->x = VEC_Mag((Vec3 *) &clipMtx[0]);
        scale->y = VEC_Mag((Vec3 *) &clipMtx[4]);
        scale->z = VEC_Mag((Vec3 *) &clipMtx[8]);
        if (data_0217029c.mFlag & 1) {
            reg_G3X_GXFIFO = 0x171012;
            MIi_CpuSend32(data_021618e0, &reg_G3X_GXFIFO, 8);
            MIi_CpuSend32(NNS_G3dGlbGetInvWV(), &reg_G3X_GXFIFO, 0x30);
            reg_G3X_GXFIFO = 0x1b19;
            MIi_CpuSend32(data_021618e8, &reg_G3X_GXFIFO, 0x3c);
        } else if (data_0217029c.mFlag & 2) {
            reg_G3X_GXFIFO = 0x171012;
            MIi_CpuSend32(data_021618e0, &reg_G3X_GXFIFO, 8);
            MIi_CpuSend32(NNS_G3dGlbGetInvV(), &reg_G3X_GXFIFO, 0x30);
            reg_G3X_GXFIFO = 0x1b19;
            MIi_CpuSend32(data_021618e8, &reg_G3X_GXFIFO, 0x3c);
        } else {
            MIi_CpuSend32(data_021618dc, &reg_G3X_GXFIFO, 0x48);
        }
    }
    if (timing == 3) {
        state->mFlag &= ~0x40;
        state->mCbVecFunc[7](state);
        timing = state->mFlag & 0x40;
    } else {
        timing = 0;
    }
    if (mode == 0x20 || mode == 0x60) {
        n++;
        if (timing == 0 && !(state->mFlag & 0x100)) {
            storeIdx = state->mC[2];
            func_01ff9048(0x13, &storeIdx, 1);
        }
    }
    state->mC += n;
}

// SBC command for a billboard node that turns about the Y axis only.
void NNSi_G3dFuncSbc_BBY(NNSG3dRS *state, u32 mode) {
    u32 restoreIdx;
    u32 storeIdx;
    s32 clipMtx[16];
    s32 invWV[16];
    s32 camMtx[16];
    u32 timing;
    u32 n = 2;
    Vec3 *pos = &data_02161954;
    Vec3 *scale = &data_02161960;
    Vec3 *axes = data_02161930;

    if (state->mFlag & 0x200) {
        if (mode == 0x40 || mode == 0x60) {
            n++;
        }
        if (mode == 0x20 || mode == 0x60) {
            n++;
        }
        state->mC += n;
        return;
    }
    if (mode == 0x40 || mode == 0x60) {
        n++;
        if (!(state->mFlag & 0x100)) {
            if (mode == 0x40) {
                restoreIdx = state->mC[2];
            } else {
                restoreIdx = state->mC[3];
            }
            func_01ff9048(0x14, &restoreIdx, 1);
        }
    }
    if (state->mCbVecFunc[8] != 0) {
        timing = state->mCbVecTiming[8];
    } else {
        timing = 0;
    }
    if (!(state->mFlag & 0x100)) {
        func_01ff9234();
        reg_G3X_GXFIFO = 0x151110;
        reg_G3X_GXFIFO = 0;
        reg_G3X_GXFIFO = 0;
        while (G3X_GetClipMtx(clipMtx) != 0) {
        }
        if (data_0217029c.mFlag & 1) {
            MTX_Copy43To44_(NNS_G3dGlbGetWV(), invWV);
            MTX_Concat44(clipMtx, invWV, clipMtx);
        } else if (data_0217029c.mFlag & 2) {
            MTX_Copy43To44_(&data_0217029c.mCameraMtx, camMtx);
            MTX_Concat44(clipMtx, camMtx, clipMtx);
        }
        pos->x = clipMtx[12];
        pos->y = clipMtx[13];
        pos->z = clipMtx[14];
        scale->x = VEC_Mag((Vec3 *) &clipMtx[0]);
        scale->y = VEC_Mag((Vec3 *) &clipMtx[4]);
        scale->z = VEC_Mag((Vec3 *) &clipMtx[8]);
        if (clipMtx[5] != 0 || clipMtx[6] != 0) {
            VEC_Normalize((Vec3 *) &clipMtx[4], &axes[1]);
            axes[2].y = -axes[1].z;
            axes[2].z = axes[1].y;
        } else {
            VEC_Normalize((Vec3 *) &clipMtx[8], &axes[2]);
            axes[1].z = -axes[2].y;
            axes[1].y = axes[2].z;
        }
        if (data_0217029c.mFlag & 1) {
            reg_G3X_GXFIFO = 0x171012;
            MIi_CpuSend32(data_02161928, &reg_G3X_GXFIFO, 8);
            MIi_CpuSend32(NNS_G3dGlbGetInvWV(), &reg_G3X_GXFIFO, 0x30);
            reg_G3X_GXFIFO = 0x1b19;
            MIi_CpuSend32(data_02161930, &reg_G3X_GXFIFO, 0x3c);
        } else if (data_0217029c.mFlag & 2) {
            reg_G3X_GXFIFO = 0x171012;
            MIi_CpuSend32(data_02161928, &reg_G3X_GXFIFO, 8);
            MIi_CpuSend32(NNS_G3dGlbGetInvV(), &reg_G3X_GXFIFO, 0x30);
            reg_G3X_GXFIFO = 0x1b19;
            MIi_CpuSend32(data_02161930, &reg_G3X_GXFIFO, 0x3c);
        } else {
            MIi_CpuSend32(data_02161924, &reg_G3X_GXFIFO, 0x48);
        }
    }
    if (timing == 3) {
        state->mFlag &= ~0x40;
        state->mCbVecFunc[8](state);
        timing = state->mFlag & 0x40;
    } else {
        timing = 0;
    }
    if (mode == 0x20 || mode == 0x60) {
        n++;
        if (timing == 0 && !(state->mFlag & 0x100)) {
            storeIdx = state->mC[2];
            func_01ff9048(0x13, &storeIdx, 1);
        }
    }
    state->mC += n;
}

// SBC command that blends several joint matrices by weight into one node matrix.
void NNSi_G3dFuncSbc_NODEMIX(NNSG3dRS *state) {
    u8 *invMtx;
    u32 count;
    u32 cached;
    s64 weight;
    u8 *p;
    u32 i;
    NNSG3dResMdl *resMdl;
    s32 *clip;
    s32 *vec;
    u32 jntIdx;
    struct {
        s32 pos[12];
        s32 nrm[9];
    } sum;

    resMdl = state->mRenderObj->mResMdl;
    count = state->mC[2];
    invMtx = (u8 *) resMdl + resMdl->mOfsEvpMtx;
    weight = 0;
    p = state->mC + 3;
    MemFillWordsByBlock_inline(&sum, sizeof(sum));
    func_01ff9234();
    reg_G3_MTX_MODE = 0;
    reg_G3_MTX_STORE = 1;
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_MODE = 2;
    for (i = 0; i < count; i++) {
        jntIdx = p[1];
        cached = ((s32 *) state->mIsEvpCached)[jntIdx >> 5] & (1 << (jntIdx & 0x1f));
        clip = data_02171904[jntIdx];
        if (!cached) {
            state->mIsEvpCached[jntIdx >> 5] |= 1 << (jntIdx & 0x1f);
            reg_G3_MTX_RESTORE = p[0];
            reg_G3_MTX_MODE = 1;
            G3_MultMtx43(invMtx + jntIdx * 0x54);
        }
        if (i != 0) {
            sum.nrm[0] += (weight * vec[0]) >> 12;
            sum.nrm[1] += (weight * vec[1]) >> 12;
            sum.nrm[2] += (weight * vec[2]) >> 12;
            sum.nrm[3] += (weight * vec[3]) >> 12;
            sum.nrm[4] += (weight * vec[4]) >> 12;
            sum.nrm[5] += (weight * vec[5]) >> 12;
            sum.nrm[6] += (weight * vec[6]) >> 12;
            sum.nrm[7] += (weight * vec[7]) >> 12;
            sum.nrm[8] += (weight * vec[8]) >> 12;
        }
        if (!cached) {
            while (G3X_GetClipMtx(clip) != 0) {
            }
            reg_G3_MTX_MODE = 2;
            G3_MultMtx33(invMtx + jntIdx * 0x54 + 0x30);
        }
        vec = data_02171944[jntIdx];
        weight = p[2] << 4;
        sum.pos[0] += (weight * clip[0]) >> 12;
        sum.pos[1] += (weight * clip[1]) >> 12;
        sum.pos[2] += (weight * clip[2]) >> 12;
        sum.pos[3] += (weight * clip[4]) >> 12;
        sum.pos[4] += (weight * clip[5]) >> 12;
        sum.pos[5] += (weight * clip[6]) >> 12;
        sum.pos[6] += (weight * clip[8]) >> 12;
        sum.pos[7] += (weight * clip[9]) >> 12;
        sum.pos[8] += (weight * clip[10]) >> 12;
        sum.pos[9] += (weight * clip[12]) >> 12;
        sum.pos[10] += (weight * clip[13]) >> 12;
        sum.pos[11] += (weight * clip[14]) >> 12;
        p += 3;
        if (!cached) {
            while (G3X_GetVectorMtx(vec) != 0) {
            }
        }
    }
    sum.nrm[0] += (weight * vec[0]) >> 12;
    sum.nrm[1] += (weight * vec[1]) >> 12;
    sum.nrm[2] += (weight * vec[2]) >> 12;
    sum.nrm[3] += (weight * vec[3]) >> 12;
    sum.nrm[4] += (weight * vec[4]) >> 12;
    sum.nrm[5] += (weight * vec[5]) >> 12;
    sum.nrm[6] += (weight * vec[6]) >> 12;
    sum.nrm[7] += (weight * vec[7]) >> 12;
    sum.nrm[8] += (weight * vec[8]) >> 12;
    G3_LoadMtx43(sum.nrm);
    reg_G3_MTX_MODE = 1;
    G3_LoadMtx43(sum.pos);
    reg_G3_MTX_MODE = 0;
    reg_G3_MTX_RESTORE = 1;
    reg_G3_MTX_MODE = 2;
    reg_G3_MTX_STORE = state->mC[1];
    state->mC += (state->mC[2] + 1) * 3;
}

// SBC command that sends a display list.
void NNSi_G3dFuncSbc_CALLDL(NNSG3dRS *state) {
    u8 *p;
    u32 timing;

    if (state->mCbVecFunc[10] != 0) {
        timing = state->mCbVecTiming[10];
    } else {
        timing = 0;
    }
    if (!(state->mFlag & 0x100)) {
        p = state->mC;
        func_01ff9144(p + (p[1] | (p[2] << 8) | (p[3] << 16) | (p[4] << 24)),
                      p[5] | (p[6] << 8) | (p[7] << 16) | (p[8] << 24));
    }
    if (timing == 3) {
        state->mFlag &= ~0x40;
        state->mCbVecFunc[10](state);
    }
    state->mC += 9;
}

// SBC command that sets up environment-mapped texture coordinates.
void NNSi_G3dFuncSbc_ENVMAP(NNSG3dRS *state) {
    u32 texMode;
    u32 texCoord;
    u32 vecMode;
    u32 texMode2;
    u32 vecMode2;
    MtxFx43 nrm;
    u32 timing;
    u8 *texMtx;
    NNSG3dResMatData *matData;
    NNSG3dResDictEntryHeader *entries;
    u16 flag;
    s32 width;
    s32 height;

    if (!(state->mFlag & 0x200) && (state->mFlag & 1)) {
        if ((state->mMatAnmResult->mUnk_10 & 0xc0000000) != 0x80000000) {
            state->mMatAnmResult->mUnk_10 &= ~0xc0000000;
            state->mMatAnmResult->mUnk_10 |= 0x80000000;
            data_02161874[1] = state->mMatAnmResult->mUnk_10;
            func_01ff9048(data_02161874[0], &data_02161874[1], 1);
        }
        texMode = 3;
        func_01ff9048(0x10, &texMode, 1);
        if (state->mCbVecFunc[12] != 0) {
            timing = state->mCbVecTiming[12];
        } else {
            timing = 0;
        }
        width = state->mMatAnmResult->mUnk_2c;
        height = state->mMatAnmResult->mUnk_2e;
        nrm.mUnk_00[3].x = width << 15;
        nrm.mUnk_00[3].y = -height << 15;
        nrm.mUnk_00[3].z = 0x10000;
        func_01ff9048(0x1b, &nrm.mUnk_00[3], 3);
        texCoord = (u16) (s16) (width << 3) | ((u16) (s16) (height << 3) << 16);
        func_01ff9048(0x22, &texCoord, 1);
        entries = (NNSG3dResDictEntryHeader *) ((u8 *) &state->mResMat->mDict + state->mResMat->mDict.mOfsEntry);
        matData = (NNSG3dResMatData *) ((u8 *) state->mResMat +
                                        *(u32 *) (entries->mData + entries->mSizeUnit * state->mC[1]));
        flag = matData->mFlag;
        if (flag & 0x2000) {
            texMtx = matData->mTexMtxData;
            if (!(flag & 2)) {
                texMtx += 8;
            }
            if (!(flag & 4)) {
                texMtx += 4;
            }
            if (!(flag & 8)) {
                texMtx += 8;
            }
            func_01ff9048(0x18, texMtx, 0x10);
        }
        if (timing == 3) {
            state->mFlag &= ~0x40;
            state->mCbVecFunc[12](state);
            timing = state->mFlag & 0x40;
        } else {
            timing = 0;
        }
        if (timing == 0) {
            vecMode = 2;
            func_01ff9048(0x10, &vecMode, 1);
            NNS_G3dGetCurrentMtx(0, &nrm);
            texMode2 = 3;
            func_01ff9048(0x10, &texMode2, 1);
            if (data_0217029c.mFlag & 1) {
                func_01ff9048(0x1a, &data_0217029c.mCameraMtx, 9);
                func_01ff9048(0x1a, data_0217029c.mPrmBaseRot, 9);
                func_01ff9048(0x1a, &nrm, 9);
            } else if (data_0217029c.mFlag & 2) {
                func_01ff9048(0x1a, &data_0217029c.mCameraMtx, 9);
                func_01ff9048(0x1a, &nrm, 9);
            } else {
                func_01ff9048(0x1a, &nrm, 9);
            }
        }
        vecMode2 = 2;
        func_01ff9048(0x10, &vecMode2, 1);
    }
    state->mC += 3;
}

// SBC command that sets up projection-mapped texture coordinates.
void NNSi_G3dFuncSbc_PRJMAP(NNSG3dRS *state) {
    u32 storeIdx;
    u32 texCoord;
    u32 vecMode;
    u32 restoreIdx;
    MtxFx43 curMatrix;
    s32 texMtx[16];
    u32 timing;
    u8 *effectMtx;
    NNSG3dResMatData *matData;
    NNSG3dResDictEntryHeader *entries;
    u16 flag;
    s32 width;
    s32 height;
    s32 x;
    s32 y;

    if (!(state->mFlag & 0x200) && (state->mFlag & 1)) {
        NNS_G3dGetCurrentMtx(&curMatrix, 0);
        storeIdx = 0x1e;
        func_01ff9048(0x13, &storeIdx, 1);
        if ((state->mMatAnmResult->mUnk_10 & 0xc0000000) != 0xc0000000) {
            state->mMatAnmResult->mUnk_10 &= ~0xc0000000;
            state->mMatAnmResult->mUnk_10 |= 0xc0000000;
            data_0216186c[1] = state->mMatAnmResult->mUnk_10;
            func_01ff9048(data_0216186c[0], &data_0216186c[1], 1);
        }
        if (state->mCbVecFunc[13] != 0) {
            timing = state->mCbVecTiming[13];
        } else {
            timing = 0;
        }
        height = state->mMatAnmResult->mUnk_2e;
        width = state->mMatAnmResult->mUnk_2c;
        data_0216189c[0] = width << 15;
        data_0216189c[5] = -height << 15;
        data_0216189c[12] = width << 15;
        data_0216189c[13] = height << 15;
        func_01ff9048(0x16, data_0216189c, 0x10);
        entries = (NNSG3dResDictEntryHeader *) ((u8 *) &state->mResMat->mDict + state->mResMat->mDict.mOfsEntry);
        matData = (NNSG3dResMatData *) ((u8 *) state->mResMat +
                                        *(u32 *) (entries->mData + entries->mSizeUnit * state->mC[1]));
        flag = matData->mFlag;
        if (flag & 0x2000) {
            effectMtx = matData->mTexMtxData;
            if (!(flag & 2)) {
                effectMtx += 8;
            }
            if (!(flag & 4)) {
                effectMtx += 4;
            }
            if (!(flag & 8)) {
                effectMtx += 8;
            }
            func_01ff9048(0x18, effectMtx, 0x10);
        }
        if (timing == 3) {
            state->mFlag &= ~0x40;
            state->mCbVecFunc[13](state);
            timing = state->mFlag & 0x40;
        } else {
            timing = 0;
        }
        if (timing == 0) {
            if (data_0217029c.mFlag & 1) {
                func_01ff9048(0x1c, &data_0217029c.mPrmBaseTrans, 3);
                func_01ff9048(0x1a, data_0217029c.mPrmBaseRot, 9);
                func_01ff9048(0x19, &curMatrix, 0xc);
            } else if (data_0217029c.mFlag & 2) {
                func_01ff9048(0x19, &curMatrix, 0xc);
            } else {
                func_01ff9048(0x19, NNS_G3dGlbGetInvV(), 0xc);
                func_01ff9048(0x19, &curMatrix, 0xc);
            }
            func_01ff9234();
            reg_G3_MTX_MODE = 0;
            reg_G3_MTX_PUSH = 0;
            reg_G3_MTX_IDENTITY = 0;
            while (G3X_GetClipMtx(texMtx) != 0) {
            }
            reg_G3_MTX_POP = 1;
            reg_G3_MTX_MODE = 3;
            func_01ff9048(0x16, texMtx, 0x10);
            x = texMtx[12] >> 4;
            y = texMtx[13] >> 4;
            texCoord = (u16) (s16) (x >> 8) | ((u16) (s16) (y >> 8) << 16);
            func_01ff9048(0x22, &texCoord, 1);
        }
        vecMode = 2;
        func_01ff9048(0x10, &vecMode, 1);
        restoreIdx = 0x1e;
        func_01ff9048(0x14, &restoreIdx, 1);
    }
    state->mC += 3;
}

// Calls the animation functions of every animation object of the list that has data for the material.
BOOL NNSi_G3dAnmBlendMat(NNSG3dMatAnmResult *result, NNSG3dAnmObj *anmObj, u32 matId) {
    BOOL ret = FALSE;

    do {
        u32 mapValue = anmObj->mMapData[matId];

        if (mapValue & 0x100) {
            anmObj->mFuncAnm(result, anmObj, mapValue & 0xff);
            ret = TRUE;
        }
        anmObj = anmObj->mNext;
    } while (anmObj != 0);
    return ret;
}

// Adds ratio times v1 to v0, or just ratio when v1 is one.
void blendScaleVec_(Vec3 *dest, const Vec3 *src, s32 weight, u32 srcIsOne) {
    if (srcIsOne != 0) {
        dest->x += weight;
        dest->y += weight;
        dest->z += weight;
    } else {
        dest->x += (weight * src->x) >> 12;
        dest->y += (weight * src->y) >> 12;
        dest->z += (weight * src->z) >> 12;
    }
}

// Blends the joint animations of every animation object of the list for one node.
BOOL NNSi_G3dAnmBlendJnt(NNSG3dJntAnmResult *result, NNSG3dAnmObj *anmObj, u32 nodeId) {
    NNSG3dJntAnmResult r;
    NNSG3dAnmObj *p;
    s32 count;
    s32 totalWeight;
    NNSG3dAnmObj *last;
    s32 weight;
    u32 mapValue;

    if (anmObj->mNext == 0) {
        mapValue = anmObj->mMapData[nodeId];
        if ((mapValue & 0x300) != 0x100) {
            return 0;
        }
        anmObj->mFuncAnm(result, anmObj, mapValue & 0xff);
        return 1;
    }
    totalWeight = 0;
    count = 0;
    p = anmObj;
    do {
        if ((p->mMapData[nodeId] & 0x300) == 0x100) {
            last = p;
            totalWeight += p->mRatio;
            count++;
        }
        p = p->mNext;
    } while (p != 0);
    if (totalWeight == 0) {
        return 0;
    }
    if (count == 1) {
        last->mFuncAnm(result, last, last->mMapData[nodeId] & 0xff);
        return 1;
    }
    MemFillWordsByBlock_inline(result, sizeof(*result));
    result->mFlag = -1;
    do {
        mapValue = anmObj->mMapData[nodeId];
        if ((mapValue & 0x300) == 0x100 && anmObj->mRatio > 0) {
            anmObj->mFuncAnm(&r, anmObj, mapValue & 0xff);
            if (totalWeight == 0x1000) {
                weight = anmObj->mRatio;
            } else {
                weight = FX_Div(anmObj->mRatio, totalWeight);
            }
            blendScaleVec_(&result->mScale, &r.mScale, weight, r.mFlag & 1);
            blendScaleVec_(&result->mScaleEx0, &r.mScaleEx0, weight, r.mFlag & 8);
            blendScaleVec_(&result->mScaleEx1, &r.mScaleEx1, weight, r.mFlag & 0x10);
            if (!(r.mFlag & 4)) {
                result->mTrans.x += (s32) (((s64) weight * r.mTrans.x) >> 12);
                result->mTrans.y += (s32) (((s64) weight * r.mTrans.y) >> 12);
                result->mTrans.z += (s32) (((s64) weight * r.mTrans.z) >> 12);
            }
            if (!(r.mFlag & 2)) {
                result->mRot[0].x += (weight * r.mRot[0].x) >> 12;
                result->mRot[0].y += (weight * r.mRot[0].y) >> 12;
                result->mRot[0].z += (weight * r.mRot[0].z) >> 12;
                result->mRot[1].x += (weight * r.mRot[1].x) >> 12;
                result->mRot[1].y += (weight * r.mRot[1].y) >> 12;
                result->mRot[1].z += (weight * r.mRot[1].z) >> 12;
            } else {
                result->mRot[0].x += weight;
                result->mRot[1].y += weight;
            }
            result->mFlag &= r.mFlag;
        }
        anmObj = anmObj->mNext;
    } while (anmObj != 0);
    VEC_CrossProduct(&result->mRot[0], &result->mRot[1], &result->mRot[2]);
    VEC_Normalize(&result->mRot[0], &result->mRot[0]);
    VEC_Normalize(&result->mRot[2], &result->mRot[2]);
    VEC_CrossProduct(&result->mRot[2], &result->mRot[0], &result->mRot[1]);
    return 1;
}

// Combines the visibility animations of every animation object of the list for one node.
BOOL NNSi_G3dAnmBlendVis(NNSG3dVisAnmResult *result, NNSG3dAnmObj *anmObj, u32 nodeId) {
    NNSG3dVisAnmResult tmp;
    BOOL ret = FALSE;

    result->mIsVisible = 0;
    do {
        u32 mapValue = anmObj->mMapData[nodeId];

        if (mapValue & 0x100) {
            anmObj->mFuncAnm(&tmp, anmObj, mapValue & 0xff);
            result->mIsVisible |= tmp.mIsVisible;
            ret = TRUE;
        }
        anmObj = anmObj->mNext;
    } while (anmObj != 0);
    return ret;
}

// Sets the global state to its defaults: command words, identity matrices, lights, colors, viewport and base transform.
void NNS_G3dGlbInit(void) {
    data_0217029c.mCmd0 = 0x17101610;
    data_0217029c.mMtxModeProj = 0;
    data_0217029c.mMtxModePosVec = 2;
    data_0217029c.mCmd1 = 0x32323232;
    data_0217029c.mCmd2 = 0x60293130;
    data_0217029c.mCmd3 = 0x33333333;
    data_0217029c.mCmd4 = 0x2a1b19;
    MTX_Identity43_(&data_0217029c.mCameraMtx);
    MTX_Identity44_(data_0217029c.mProjMtx);
    data_0217029c.mLightVec[0] = 0x2d8b62d8;
    data_0217029c.mLightVec[1] = 0x40000200;
    data_0217029c.mLightVec[2] = 0x800001ff;
    data_0217029c.mLightVec[3] = 0xc0080000;
    data_0217029c.mPrmMatColor0 = 0x4210c210;
    data_0217029c.mPrmMatColor1 = 0x4210c210;
    data_0217029c.mPrmPolygonAttr = 0x1f008f;
    data_0217029c.mPrmViewPort = 0xbfff0000;
    data_0217029c.mLightColor[0] = 0x7fff;
    data_0217029c.mLightColor[1] = 0x4000001f;
    data_0217029c.mLightColor[2] = 0x800003e0;
    data_0217029c.mLightColor[3] = 0xc0007c00;
    data_0217029c.mPrmBaseTrans.x = 0;
    data_0217029c.mPrmBaseTrans.y = 0;
    data_0217029c.mPrmBaseTrans.z = 0;
    MTX_Identity33_((MtxFx43 *) data_0217029c.mPrmBaseRot);
    data_0217029c.mPrmBaseScale.x = 0x1000;
    data_0217029c.mPrmBaseScale.y = 0x1000;
    data_0217029c.mPrmBaseScale.z = 0x1000;
    data_0217029c.mPrmTexImageParam = 0;
    data_0217029c.mFlag = 0;
    data_0217029c.mCamPos.z = 0;
    data_0217029c.mCamPos.y = 0;
    data_0217029c.mCamPos.x = 0;
    data_0217029c.mCamUp.z = 0;
    data_0217029c.mCamUp.x = 0;
    data_0217029c.mCamUp.y = 0x1000;
    data_0217029c.mCamTarget.y = 0;
    data_0217029c.mCamTarget.x = 0;
    data_0217029c.mCamTarget.z = -0x1000;
}

// Sends the matrices, lights, colors, viewport and base transform to the geometry engine as one block.
void NNS_G3dGlbFlushP(void) {
    u32 *p = (u32 *) &data_0217029c;
    u32 c = *p++;

    func_01ff9048(c, p, 0x3e);
    data_0217029c.mFlag &= ~1;
    data_0217029c.mFlag &= ~2;
}

// Sets the base translation and drops the cached matrices that depend on it.
void NNS_G3dGlbSetBaseTrans(const Vec3 *trans) {
    data_0217029c.mPrmBaseTrans = *trans;
    data_0217029c.mFlag &= ~0xa4;
}

// Sets the base scale and drops the cached matrices that depend on it.
void NNS_G3dGlbSetBaseScale(const Vec3 *scale) {
    data_0217029c.mPrmBaseScale = *scale;
    data_0217029c.mFlag &= ~0xa4;
}

// Sets the direction of a light.
void NNS_G3dGlbLightVector(u32 lightId, s32 x, s32 y, s32 z) {
    data_0217029c.mLightVec[lightId] =
        ((x >> 3) & 0x3ff) | (((y >> 3) & 0x3ff) << 10) | (((z >> 3) & 0x3ff) << 20) | (lightId << 30);
}

// Sets the color of a light.
void NNS_G3dGlbLightColor(u32 lightId, u32 rgb) {
    data_0217029c.mLightColor[lightId] = rgb | (lightId << 30);
}

// Sets the diffuse and ambient colors.
void NNS_G3dGlbMaterialColorDiffAmb(u32 diffuse, u32 ambient, u32 vtxColor) {
    data_0217029c.mPrmMatColor0 = diffuse | (ambient << 16) | ((vtxColor != 0) << 15);
}

// Sets the specular and emission colors.
void NNS_G3dGlbMaterialColorSpecEmi(u32 specular, u32 emission, u32 shininess) {
    data_0217029c.mPrmMatColor1 = specular | (emission << 16) | ((shininess != 0) << 15);
}

// Sets the polygon attributes.
void NNS_G3dGlbPolygonAttr(u32 light, u32 polyMode, u32 cullMode, u32 polygonId, u32 alpha, u32 extra) {
    data_0217029c.mPrmPolygonAttr =
        (extra | (light | (polyMode << 4) | (cullMode << 6))) | (polygonId << 24) | (alpha << 16);
}

// Returns the inverse of the camera matrix, computing it when it is out of date.
MtxFx43 *NNS_G3dGlbGetInvV(void) {
    if (!(data_0217029c.mFlag & 0x8)) {
        MTX_Inverse43(&data_0217029c.mCameraMtx, &data_0217029c.mInvCameraMtx);
        data_0217029c.mFlag |= 0x8;
    }
    return &data_0217029c.mInvCameraMtx;
}

// Computes the camera matrix with the base transform applied, and its inverse.
void calcSrtCameraMtx_(void) {
    MTX_Concat43((MtxFx43 *) data_0217029c.mPrmBaseRot, &data_0217029c.mCameraMtx, &data_0217029c.mSrtCameraMtx);
    MTX_ScaleApply43(&data_0217029c.mSrtCameraMtx, &data_0217029c.mSrtCameraMtx, data_0217029c.mPrmBaseScale.x,
                     data_0217029c.mPrmBaseScale.y, data_0217029c.mPrmBaseScale.z);
    MTX_Inverse43(&data_0217029c.mSrtCameraMtx, &data_0217029c.mInvSrtCameraMtx);
}

// Returns the camera matrix with the base transform applied, computing it when it is out of date.
MtxFx43 *NNS_G3dGlbGetWV(void) {
    if (!(data_0217029c.mFlag & 0x80)) {
        calcSrtCameraMtx_();
        data_0217029c.mFlag |= 0x80;
    }
    return &data_0217029c.mSrtCameraMtx;
}

// Returns the inverse of the camera matrix with the base transform applied, computing it when it is out of date.
MtxFx43 *NNS_G3dGlbGetInvWV(void) {
    if (!(data_0217029c.mFlag & 0x80)) {
        calcSrtCameraMtx_();
        data_0217029c.mFlag |= 0x80;
    }
    return &data_0217029c.mInvSrtCameraMtx;
}

// Returns the size of an animation object for the animation and the model.
u32 NNS_G3dAnmObjCalcSizeRequired(const void *anm, const NNSG3dResMdl *mdl) {
    switch (((const NNSG3dResAnmHeader *) anm)->mCategory0) {
        case 'M':
            return ((mdl->mInfo.mNumMat << 1) + 0x1c) & ~3;
        case 'J':
        case 'V':
            return ((mdl->mInfo.mNumNode << 1) + 0x1c) & ~3;
        default:
            return 0;
    }
}

// Starts an animation object for the animation and selects the init function of its format.
void NNS_G3dAnmObjInit(NNSG3dAnmObj *anmObj, void *resAnm, const NNSG3dResMdl *resMdl, void *resTex) {
    const NNSG3dResAnmHeader *animHeader;
    u32 i;

    anmObj->mFrame = 0;
    anmObj->mResAnm = resAnm;
    anmObj->mNext = 0;
    anmObj->mPriority = 0x7f;
    anmObj->mRatio = 0x1000;
    anmObj->mResTex = resTex;
    animHeader = resAnm;
    for (i = 0; i < data_021617d0; i++) {
        if (animHeader->mCategory0 == data_021617f4[i].mCategory0 &&
            animHeader->mCategory1 == data_021617f4[i].mCategory1) {
            data_021617f4[i].mFunc(anmObj, resAnm, resMdl);
            return;
        }
    }
}

// Clears the render object and sets the default blend functions and the model.
void NNS_G3dRenderObjInit(NNSG3dRenderObj *renderObj, NNSG3dResMdl *resMdl) {
    volatile u32 zero = 0;

    MIi_CpuClear32(zero, renderObj, 0x54);
    renderObj->mFuncBlendMat = data_021617f0;
    renderObj->mFuncBlendJnt = data_021617ec;
    renderObj->mFuncBlendVis = data_021617e8;
    renderObj->mResMdl = resMdl;
}

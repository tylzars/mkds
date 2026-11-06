#include "code_02013bdc.h"
#include "code_02013740.h"
#include "code_02013b3c.h"
#include "code_02147cd8.h"
#include "code_02013bbc.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_02152000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02170000.h"

void NNSi_G3dAnmObjInitNsBva(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl) {
    u32 i;

    pAnmObj->mFuncAnm = data_021617d4;
    pAnmObj->mNumMapData = pResMdl->mInfo.mNumNode;
    pAnmObj->mResAnm = pResAnm;
    for (i = 0; i < pAnmObj->mNumMapData; i++) {
        pAnmObj->mMapData[i] = i | 0x100;
    }
}

void NNSi_G3dAnmCalcNsBva(u32 *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx) {
    NNSG3dResVisAnm *visAnim;
    u32 bitPos;

    visAnim = pAnmObj->mResAnm;
    bitPos = (pAnmObj->mFrame >> 12) * visAnim->mNumNode + dataIdx;
    *pResult = visAnim->mVisData[bitPos >> 5] & (1 << (bitPos & 0x1f));
}

void NNSi_G3dAnmObjInitNsBtp(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl) {
    volatile u16 zero;
    NNSG3dResTexPatAnm *patAnim;
    u8 *matBlock;
    NNSG3dResDictEntryHeader *dictEntries;
    s32 matIdx;
    u32 i;

    patAnim = pResAnm;
    matBlock = (u8 *) pResMdl + pResMdl->mOfsMat;
    pAnmObj->mFuncAnm = data_021617e0;
    pAnmObj->mNumMapData = pResMdl->mInfo.mNumMat;
    pAnmObj->mResAnm = patAnim;
    zero = 0;
    MIi_CpuClear16(zero, pAnmObj->mMapData, pAnmObj->mNumMapData * 2);
    for (i = 0; i < patAnim->mDict.mNumEntry; i++) {
        dictEntries = (NNSG3dResDictEntryHeader *) ((u8 *) &patAnim->mDict + patAnim->mDict.mOfsEntry);
        matIdx = NNS_G3dGetResDictIdxByName(matBlock + 4,
                                            (const u32 *) ((u8 *) dictEntries + dictEntries->mOfsName + i * 16));
        if (matIdx >= 0) {
            pAnmObj->mMapData[matIdx] = i | 0x100;
        }
    }
}

void SetTexParamaters_(const NNSG3dResTex *pTex, const u32 *pTexName, NNSG3dMatAnmResult *pResult) {
    const NNSG3dResDictTexData *texEntry;
    u32 imageParam;
    u32 keyOffset;
    s32 w;
    s32 h;

    texEntry = NNS_G3dGetResDataByName(&pTex->mDict, pTexName);
    imageParam = pResult->mUnk_10;
    if ((texEntry->mTexImageParam & 0x1c000000) != 0x14000000) {
        keyOffset = pTex->mTexInfo.mVramKey & 0xffff;
    } else {
        keyOffset = pTex->mTex4x4Info.mVramKey & 0xffff;
    }
    pResult->mUnk_10 = imageParam & 0xc00f0000;
    pResult->mUnk_10 = pResult->mUnk_10 | (texEntry->mTexImageParam + keyOffset);
    pResult->mUnk_2c = texEntry->mExtraParam & 0x7ff;
    pResult->mUnk_2e = (texEntry->mExtraParam & 0x3ff800) >> 11;
    w = texEntry->mExtraParam & 0x7ff;
    h = 0x7ff & (texEntry->mExtraParam >> 11);
    if (w == pResult->mUnk_2c) {
        w = 0x1000;
    } else {
        w = FX_Div(w << 12, pResult->mUnk_2c << 12);
    }
    pResult->mUnk_30 = w;
    if (h == pResult->mUnk_2e) {
        h = 0x1000;
    } else {
        h = FX_Div(h << 12, pResult->mUnk_2e << 12);
    }
    pResult->mUnk_34 = h;
}

void SetPlttParamaters_(const NNSG3dResTex *pTex, const u32 *pPlttName, NNSG3dMatAnmResult *pResult) {
    const NNSG3dResDictPlttData *plttEntry;
    u32 keyOffset;
    u32 base;

    plttEntry = NNS_G3dGetResDataByName((u8 *) pTex + pTex->mPlttInfo.mOfsDict, pPlttName);
    keyOffset = (u16) pTex->mPlttInfo.mVramKey;
    base = plttEntry->mOffset;
    if (!(plttEntry->mFlag & 1)) {
        base = (u16) (base >> 1);
        keyOffset = (u16) (keyOffset >> 1);
    }
    pResult->mUnk_14 = base + keyOffset;
}

void NNSi_G3dAnmCalcNsBtp(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx) {
    NNSG3dResTexPatAnmFV *frameEntry;
    NNSG3dResTexPatAnm *patAnim;

    patAnim = pAnmObj->mResAnm;
    frameEntry = NNSi_G3dGetTexPatAnmFV(patAnim, (u16) dataIdx, (u32) (pAnmObj->mFrame << 4) >> 16);
    SetTexParamaters_(pAnmObj->mResTex, NNSi_G3dGetTexPatAnmTexNameByIdx(patAnim, frameEntry->mIdTex), pResult);
    if (frameEntry->mIdPltt == 0xff) {
        return;
    }
    SetPlttParamaters_(pAnmObj->mResTex, NNSi_G3dGetTexPatAnmPlttNameByIdx(patAnim, frameEntry->mIdPltt), pResult);
}

// Blends the two stored values when the frame falls between them.
s32 GetTexSRTAnmVectorVal_(const NNSG3dResTexSRTAnm *pTexAnm, u32 info, s32 data, u32 frame) {
    const u8 *values;
    u32 lastStep;
    u32 sample;
    s32 first;
    s32 second;

    if (info & 0x20000000) {
        return data;
    }
    values = (const u8 *) pTexAnm;
    values += data;
    if (info & 0xc0000000) {
        lastStep = info & 0xffff;
        if (info & 0x40000000) {
            if (frame & 1) {
                if (frame > lastStep) {
                    frame = (lastStep >> 1) + 1;
                    goto single;
                }
                frame >>= 1;
                goto half;
            }
            frame >>= 1;
            goto single;
        }
        if (frame & 3) {
            if (frame > lastStep) {
                frame = (frame & 3) + (lastStep >> 2);
                goto single;
            }
            if (frame & 1) {
                if (frame & 2) {
                    frame >>= 2;
                    sample = frame + 1;
                } else {
                    sample = frame >> 2;
                    frame = sample + 1;
                }
                if (info & 0x10000000) {
                    first = ((const s16 *) values)[sample];
                    second = ((const s16 *) values)[frame];
                } else {
                    first = ((const s32 *) values)[sample];
                    second = ((const s32 *) values)[frame];
                }
                return (first * 3 + second) >> 2;
            }
            frame >>= 2;
            goto half;
        }
        frame >>= 2;
    }
single:
    if (info & 0x10000000) {
        return ((const s16 *) values)[frame];
    }
    return ((const s32 *) values)[frame];
half:
    if (info & 0x10000000) {
        first = ((const s16 *) values)[frame];
        second = (&((const s16 *) values)[frame])[1];
    } else {
        first = ((const s32 *) values)[frame];
        second = (&((const s32 *) values)[frame])[1];
    }
    return (first + second) >> 1;
}

// Returns sine in the low halfword and cosine in the high halfword.
u32 GetTexSRTAnmSinCosVal_(const NNSG3dResTexSRTAnm *pTexAnm, u32 info, u32 data, u32 frame) {
    const u8 *values;
    u32 lastStep;
    u32 sample;
    s32 s;
    s32 sSub;
    s32 c;
    s32 cSub;

    if (info & 0x20000000) {
        return data;
    }
    values = (const u8 *) pTexAnm;
    values += data;
    if (info & 0xc0000000) {
        lastStep = info & 0xffff;
        if (info & 0x40000000) {
            if (frame & 1) {
                if (frame > lastStep) {
                    frame = (lastStep >> 1) + 1;
                    goto single;
                }
                sample = frame >> 1;
                goto half;
            }
            frame >>= 1;
            goto single;
        }
        if (frame & 3) {
            if (frame > lastStep) {
                frame = (frame & 3) + (lastStep >> 2);
                goto single;
            }
            if (frame & 1) {
                if (frame & 2) {
                    lastStep = frame >> 2;
                    sample = lastStep + 1;
                } else {
                    sample = frame >> 2;
                    lastStep = sample + 1;
                }
                s = ((const FxPairS16 *) values)[sample].mFirst;
                sSub = ((const FxPairS16 *) values)[lastStep].mFirst;
                c = ((const FxPairS16 *) values)[sample].mSecond;
                cSub = ((const FxPairS16 *) values)[lastStep].mSecond;
                s = s * 3 + sSub;
                c = c * 3 + cSub;
                return (s >> 2 & 0xffff) | (c >> 2 << 16);
            }
            sample = frame >> 2;
            goto half;
        }
        frame >>= 2;
    }
single:
    return ((const u32 *) values)[frame];
half:
    s = ((const FxPairS16 *) values)[sample].mFirst;
    sSub = ((const FxPairS16 *) values + sample)[1].mFirst;
    c = ((const FxPairS16 *) values + sample)->mSecond;
    cSub = ((const FxPairS16 *) values + sample)[1].mSecond;
    return (((s + sSub) >> 1) & 0xffff) | ((c + cSub) >> 1 << 16);
}

void GetTexSRTAnm_(const NNSG3dResTexSRTAnm *pTexAnm, u16 idx, u32 frame, NNSG3dMatAnmResult *pResult) {
    const NNSG3dResDictEntryHeader *dictEntries;
    const NNSG3dResDictTexSRTAnmData *srtData;
    u32 flag;
    s32 x;
    s32 y;
    u32 z;

    dictEntries = (const NNSG3dResDictEntryHeader *) ((const u8 *) &pTexAnm->mDict + pTexAnm->mDict.mOfsEntry);
    srtData = (const NNSG3dResDictTexSRTAnmData *) (dictEntries->mData + dictEntries->mSizeUnit * idx);
    flag = pResult->mUnk_00;
    x = GetTexSRTAnmVectorVal_(pTexAnm, srtData->mTransS, srtData->mTransSEx, frame);
    y = GetTexSRTAnmVectorVal_(pTexAnm, srtData->mTransT, srtData->mTransTEx, frame);
    if (x == 0 && y == 0) {
        flag |= 4;
    } else {
        pResult->mUnk_24[0] = x;
        pResult->mUnk_24[1] = y;
        flag &= ~4;
    }
    z = GetTexSRTAnmSinCosVal_(pTexAnm, srtData->mRot, srtData->mRotEx, frame);
    if (z == 0x10000000) {
        flag |= 2;
    } else {
        pResult->mUnk_20[0] = z;
        pResult->mUnk_20[1] = z >> 16;
        flag &= ~2;
    }
    x = GetTexSRTAnmVectorVal_(pTexAnm, srtData->mScaleS, srtData->mScaleSEx, frame);
    y = GetTexSRTAnmVectorVal_(pTexAnm, srtData->mScaleT, srtData->mScaleTEx, frame);
    if (x == 0x1000 && y == 0x1000) {
        flag |= 1;
    } else {
        pResult->mUnk_18[0] = x;
        pResult->mUnk_18[1] = y;
        flag &= ~1;
    }
    pResult->mUnk_00 = flag;
}

void NNSi_G3dAnmObjInitNsBta(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl) {
    volatile u16 zero;
    NNSG3dResTexSRTAnm *srtAnim;
    u8 *matBlock;
    NNSG3dResDictEntryHeader *dictEntries;
    s32 matIdx;
    u32 i;

    srtAnim = pResAnm;
    matBlock = (u8 *) pResMdl + pResMdl->mOfsMat;
    pAnmObj->mFuncAnm = data_021617dc;
    pAnmObj->mNumMapData = pResMdl->mInfo.mNumMat;
    zero = 0;
    MIi_CpuClear16(zero, pAnmObj->mMapData, pAnmObj->mNumMapData * 2);
    for (i = 0; i < srtAnim->mDict.mNumEntry; i++) {
        dictEntries = (NNSG3dResDictEntryHeader *) ((u8 *) &srtAnim->mDict + srtAnim->mDict.mOfsEntry);
        matIdx = NNS_G3dGetResDictIdxByName(matBlock + 4,
                                            (const u32 *) ((u8 *) dictEntries + dictEntries->mOfsName + i * 16));
        if (matIdx >= 0) {
            pAnmObj->mMapData[matIdx] = i | 0x100;
        }
    }
}

void NNSi_G3dAnmCalcNsBta(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx) {
    GetTexSRTAnm_(pAnmObj->mResAnm, dataIdx, pAnmObj->mFrame >> 12, pResult);
    pResult->mUnk_10 &= ~0xc0000000;
    pResult->mUnk_10 |= 0x40000000;
    pResult->mUnk_00 |= 8;
}

// Blends the two stored colors when the frame falls between them.
u16 GetMatColAnmValue_(const NNSG3dResMatCAnm *pAnm, u32 info, u32 frame) {
    u32 color;
    u32 sampleNext;
    u32 sample;
    u32 colorNext;
    const u16 *values;
    const u8 *base;
    u32 lastStep;

    if (info & 0x20000000) {
        return info;
    }
    base = (const u8 *) pAnm;
    values = (const u16 *) (base + (info & 0xffff));
    if (!(info & 0xc0000000)) {
        return values[frame];
    }
    lastStep = (info & 0x1fff0000) >> 16;
    if (info & 0x40000000) {
        if (frame & 1) {
            if (frame > lastStep) {
                return (&values[lastStep >> 1])[1];
            }
            sample = frame >> 1;
            goto half;
        }
        return values[frame >> 1];
    }
    if (frame & 3) {
        if (frame > lastStep) {
            return (&values[lastStep >> 2])[frame & 3];
        }
        if (frame & 1) {
            if (frame & 2) {
                sampleNext = frame >> 2;
                frame = sampleNext + 1;
            } else {
                frame >>= 2;
                sampleNext = frame + 1;
            }
            color = values[frame];
            return ((color & 0x7c1f) * 3 + ((u32) values[sampleNext] & 0x7c1f)) >> 2 & 0x7c1f |
                   ((color & 0x3e0) * 3 + ((u32) values[sampleNext] & 0x3e0)) >> 2 & 0x3e0;
        }
        sample = frame >> 2;
        goto half;
    }
    return values[frame >> 2];
half:
    color = values[sample];
    colorNext = (&values[sample])[1];
    return ((color & 0x7c1f) + (colorNext & 0x7c1f)) >> 1 & 0x7c1f |
           ((color & 0x3e0) + (colorNext & 0x3e0)) >> 1 & 0x3e0;
}

u16 GetMatColAnmuAlphaValue_(const NNSG3dResMatCAnm *pAnm, u32 info, u32 frame) {
    const u8 *values;
    u32 sampleNext;
    u32 lastStep;

    if (info & 0x20000000) {
        return info;
    }
    values = (const u8 *) pAnm;
    values += info & 0xffff;
    if (!(info & 0xc0000000)) {
        return values[frame];
    }
    lastStep = (info & 0x1fff0000) >> 16;
    if (info & 0x40000000) {
        if (frame & 1) {
            if (frame > lastStep) {
                return (&values[lastStep >> 1])[1];
            }
            return (values[frame >> 1] + (&values[frame >> 1])[1]) >> 1;
        }
        return values[frame >> 1];
    }
    if (frame & 3) {
        if (frame > lastStep) {
            return (&values[lastStep >> 2])[frame & 3];
        }
        if (frame & 1) {
            if (frame & 2) {
                sampleNext = frame >> 2;
                frame = sampleNext + 1;
            } else {
                frame >>= 2;
                sampleNext = frame + 1;
            }
            lastStep = values[sampleNext];
            frame = values[frame];
            return (frame * 3 + lastStep) >> 2;
        }
        return (values[frame >> 2] + (&values[frame >> 2])[1]) >> 1;
    }
    return values[frame >> 2];
}

void NNSi_G3dAnmObjInitNsBma(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl) {
    volatile u16 zero;
    NNSG3dResMatCAnm *colorAnim;
    u8 *matBlock;
    NNSG3dResDictEntryHeader *dictEntries;
    s32 matIdx;
    u32 i;

    colorAnim = pResAnm;
    matBlock = (u8 *) pResMdl + pResMdl->mOfsMat;
    pAnmObj->mFuncAnm = data_021617e4;
    pAnmObj->mNumMapData = pResMdl->mInfo.mNumMat;
    zero = 0;
    MIi_CpuClear16(zero, pAnmObj->mMapData, pAnmObj->mNumMapData * 2);
    for (i = 0; i < colorAnim->mDict.mNumEntry; i++) {
        dictEntries = (NNSG3dResDictEntryHeader *) ((u8 *) &colorAnim->mDict + colorAnim->mDict.mOfsEntry);
        matIdx = NNS_G3dGetResDictIdxByName(matBlock + 4,
                                            (const u32 *) ((u8 *) dictEntries + dictEntries->mOfsName + i * 16));
        if (matIdx >= 0) {
            pAnmObj->mMapData[matIdx] = i | 0x100;
        }
    }
}

void NNSi_G3dAnmCalcNsBma(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx) {
    u32 x;
    u8 *t;
    NNSG3dResMatCAnm *colorAnim;
    u32 frame;
    NNSG3dResDictMatCAnmData *colorData;

    colorAnim = pAnmObj->mResAnm;
    frame = pAnmObj->mFrame >> 12;
    t = (u8 *) colorAnim + 8 + colorAnim->mDict.mOfsEntry;
    colorData = (NNSG3dResDictMatCAnmData *) (t + 4 + *(u16 *) t * (u16) dataIdx);
    x = GetMatColAnmValue_(colorAnim, colorData->mDiffuse, frame);
    pResult->mUnk_04 =
        (pResult->mUnk_04 & 0x8000) | x | (GetMatColAnmValue_(colorAnim, colorData->mAmbient, frame) << 16);
    x = GetMatColAnmValue_(colorAnim, colorData->mEmission, frame);
    pResult->mUnk_08 =
        (pResult->mUnk_08 & 0x8000) | GetMatColAnmValue_(colorAnim, colorData->mSpecular, frame) | (x << 16);
    pResult->mUnk_0c =
        (pResult->mUnk_0c & ~0x1f0000) | (GetMatColAnmuAlphaValue_(colorAnim, colorData->mPolygonAlpha, frame) << 16);
}

void NNSi_G3dAnmObjInitNsBca(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl) {
    volatile u16 zero;
    u32 i;
    u16 *tagOffsets;
    NNSG3dResJntAnm *anim;

    anim = pResAnm;
    pAnmObj->mResAnm = pResAnm;
    pAnmObj->mFuncAnm = data_021617d8;
    pAnmObj->mNumMapData = pResMdl->mInfo.mNumNode;
    zero = 0;
    MIi_CpuClear16(zero, pAnmObj->mMapData, pAnmObj->mNumMapData * 2);
    tagOffsets = anim->mUnk_14;
    for (i = 0; i < anim->mNumNode; i++) {
        pAnmObj->mMapData[i] = (*(u32 *) ((u8 *) anim + tagOffsets[i]) >> 24) | 0x100;
    }
}

void NNSi_G3dAnmCalcNsBca(NNSG3dJntAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, int dataIdx) {
    s32 frame;
    s32 end;
    NNSG3dResJntAnm *jntAnim;

    jntAnim = pAnmObj->mResAnm;
    frame = pAnmObj->mFrame;
    end = jntAnim->mNumFrame << 12;
    if (frame >= end) {
        frame = end - 1;
    } else if (frame < 0) {
        frame = 0;
    }
    getJntSRTAnmResult_(jntAnim, dataIdx, frame, pResult);
}

void getMdlTrans_(NNSG3dJntAnmResult *out) {
    Unk02170500 *rs;
    Unk02170500_d4 *nodeInfo;
    u8 *table;
    NNSG3dResNodeData *node;
    const u32 *src;

    rs = data_02170500;
    nodeInfo = rs->mUnk_d4;
    table = (u8 *) nodeInfo + nodeInfo->mUnk_06;
    node = (NNSG3dResNodeData *) ((u8 *) nodeInfo + *(u32 *) (table + *(u16 *) table * rs->mUnk_00[1] + 4));
    if (node->mFlag & 1) {
        out->mFlag |= 4;
        return;
    }
    src = (const u32 *) node->mUnk_04;
    out->mTrans.x = src[0];
    out->mTrans.y = src[1];
    out->mTrans.z = src[2];
}

void getMdlScale_(NNSG3dJntAnmResult *out) {
    u32 flags;
    Unk02170500_d4 *nodeInfo;
    u8 *table;
    Unk02170500 *rs;
    u32 nodeOfs;
    u8 *scalePtr;
    u8 *cmd;

    rs = data_02170500;
    nodeInfo = rs->mUnk_d4;
    cmd = rs->mUnk_00;
    table = (u8 *) nodeInfo + nodeInfo->mUnk_06;
    nodeOfs = *(u32 *) (table + *(u16 *) table * cmd[1] + 4);
    flags = *(u16 *) ((u8 *) nodeInfo + nodeOfs);
    scalePtr = (u8 *) nodeInfo + nodeOfs + 4;
    if (!(flags & 1)) {
        scalePtr += 0xc;
    }
    if (!(flags & 2)) {
        if (flags & 8) {
            scalePtr += 4;
        } else {
            scalePtr += 0x10;
        }
    }
    rs->mUnk_e8(out, scalePtr, cmd, flags);
}

void getMdlRot_(NNSG3dJntAnmResult *out) {
    s32 first;
    Unk02170500 *rs;
    s32 second;
    u8 *table;
    Unk02170500_d4 *nodeInfo;
    s32 pivot;
    NNSG3dResNodeData *node;
    const s16 *vals;

    rs = data_02170500;
    nodeInfo = rs->mUnk_d4;
    table = (u8 *) nodeInfo + nodeInfo->mUnk_06;
    node = (NNSG3dResNodeData *) ((u8 *) nodeInfo + *(u32 *) (table + *(u16 *) table * rs->mUnk_00[1] + 4));
    vals = node->mUnk_04;
    if (!(node->mFlag & 1)) {
        vals += 6;
    }
    if (!(node->mFlag & 2)) {
        if (node->mFlag & 8) {
            pivot = (node->mFlag & 0xf0) >> 4;
            first = vals[0];
            second = vals[1];
            MI_Zero36B((s32 *) out->mRot);
            ((s32 *) out->mRot)[pivot] = (node->mFlag & 0x100) ? -0x1000 : 0x1000;
            ((s32 *) out->mRot)[data_02152c30[pivot][0]] = first;
            ((s32 *) out->mRot)[data_02152c31[pivot][0]] = second;
            if (node->mFlag & 0x200) {
                second = -second;
            }
            ((s32 *) out->mRot)[data_02152c32[pivot][0]] = second;
            if (node->mFlag & 0x400) {
                first = -first;
            }
            ((s32 *) out->mRot)[data_02152c33[pivot][0]] = first;
        } else {
            ((s32 *) out->mRot)[0] = node->mUnk_02;
            ((s32 *) out->mRot)[1] = vals[0];
            ((s32 *) out->mRot)[2] = vals[1];
            ((s32 *) out->mRot)[3] = vals[2];
            ((s32 *) out->mRot)[4] = vals[3];
            ((s32 *) out->mRot)[5] = vals[4];
            ((s32 *) out->mRot)[6] = vals[5];
            ((s32 *) out->mRot)[7] = vals[6];
            ((s32 *) out->mRot)[8] = vals[7];
        }
    } else {
        out->mFlag |= 2;
    }
}

void getJntSRTAnmResult_(const NNSG3dResJntAnm *jntAnm, int node, s32 frame, NNSG3dJntAnmResult *out) {
    s32 scaleTmp[3][2];
    s32 scaleOut[2][3];
    int interp;
    u32 flags;
    const u32 *cursor;
    const u32 *tag;
    s32 r0;
    s32 r1;
    s32 r2;
    s32 r3;
    s32 r4;
    s32 r5;

    tag = (const u32 *) ((u8 *) jntAnm + jntAnm->mUnk_14[node]);
    flags = tag[0];
    if (flags & 1) {
        out->mFlag = 7;
    } else {
        cursor = tag + 1;
        if ((frame & 0xfff) && (jntAnm->mFlag & 1)) {
            interp = 1;
        } else {
            interp = 0;
        }
        out->mFlag = 0;
        if (!(flags & 6)) {
            if (!(flags & 8)) {
                if (interp) {
                    getTransDataEx_(&out->mTrans.x, frame, cursor, jntAnm);
                } else {
                    getTransData_(&out->mTrans.x, frame, cursor, jntAnm);
                }
                cursor += 2;
            } else {
                out->mTrans.x = *cursor++;
            }
            if (!(flags & 0x10)) {
                if (interp) {
                    getTransDataEx_(&out->mTrans.y, frame, cursor, jntAnm);
                } else {
                    getTransData_(&out->mTrans.y, frame, cursor, jntAnm);
                }
                cursor += 2;
            } else {
                out->mTrans.y = *cursor++;
            }
            if (!(flags & 0x20)) {
                if (interp) {
                    getTransDataEx_(&out->mTrans.z, frame, cursor, jntAnm);
                } else {
                    getTransData_(&out->mTrans.z, frame, cursor, jntAnm);
                }
                cursor += 2;
            } else {
                out->mTrans.z = *cursor++;
            }
        } else if (flags & 2) {
            out->mFlag |= 4;
        } else {
            getMdlTrans_(out);
        }
        if (!(flags & 0xc0)) {
            if (!(flags & 0x100)) {
                if (interp) {
                    getRotDataEx_((s32 *) out->mRot, frame, cursor, jntAnm);
                } else {
                    getRotData_((s32 *) out->mRot, frame, cursor, jntAnm);
                }
                cursor += 2;
            } else {
                if (getRotDataByIdx_((s32 *) out->mRot, (const s16 *) ((u8 *) jntAnm + jntAnm->mOfsRot3),
                                     (const s16 *) ((u8 *) jntAnm + jntAnm->mOfsRot5), *cursor)) {
                    r5 = ((s32 *) out->mRot)[5];
                    r0 = ((s32 *) out->mRot)[0];
                    r3 = ((s32 *) out->mRot)[3];
                    r2 = ((s32 *) out->mRot)[2];
                    r1 = ((s32 *) out->mRot)[1];
                    r4 = ((s32 *) out->mRot)[4];
                    ((s32 *) out->mRot)[6] = (r1 * r5 - r2 * r4) >> 12;
                    ((s32 *) out->mRot)[7] = (r2 * r3 - r0 * r5) >> 12;
                    ((s32 *) out->mRot)[8] = (r0 * r4 - r1 * r3) >> 12;
                }
                cursor += 1;
            }
        } else if (flags & 0x40) {
            out->mFlag |= 2;
        } else {
            getMdlRot_(out);
        }
        if (!(flags & 0x600)) {
            if (!(flags & 0x800)) {
                if (interp) {
                    getScaleDataEx_(scaleTmp[0], frame, cursor, jntAnm);
                } else {
                    getScaleData_(scaleTmp[0], frame, cursor, jntAnm);
                }
                scaleOut[0][0] = scaleTmp[0][0];
                scaleOut[1][0] = scaleTmp[0][1];
            } else {
                scaleOut[0][0] = cursor[0];
                scaleOut[1][0] = cursor[1];
            }
            if (!(flags & 0x1000)) {
                if (interp) {
                    getScaleDataEx_(scaleTmp[1], frame, cursor + 2, jntAnm);
                } else {
                    getScaleData_(scaleTmp[1], frame, cursor + 2, jntAnm);
                }
                scaleOut[0][1] = scaleTmp[1][0];
                scaleOut[1][1] = scaleTmp[1][1];
            } else {
                scaleOut[0][1] = cursor[2];
                scaleOut[1][1] = cursor[3];
            }
            if (!(flags & 0x2000)) {
                if (interp) {
                    getScaleDataEx_(scaleTmp[2], frame, cursor + 4, jntAnm);
                } else {
                    getScaleData_(scaleTmp[2], frame, cursor + 4, jntAnm);
                }
                scaleOut[0][2] = scaleTmp[2][0];
                scaleOut[1][2] = scaleTmp[2][1];
            } else {
                scaleOut[0][2] = cursor[4];
                scaleOut[1][2] = cursor[5];
            }
        } else if (flags & 0x200) {
            out->mFlag |= 1;
        } else {
            getMdlScale_(out);
            return;
        }
    }
    data_02170500->mUnk_e8(out, scaleOut, data_02170500->mUnk_00, (out->mFlag & 1) ? 4 : 0);
}

void getTransData_(s32 *out, s32 frame, const u32 *desc, const NNSG3dResJntAnm *jntAnm) {
    s32 x;
    u32 lastStep;
    const u8 *values;
    u32 info;
    u32 k;
    u32 i;
    s32 y;
    u32 j;

    i = frame >> 12;
    values = (const u8 *) jntAnm + desc[1];
    info = desc[0];
    if (info & 0xc0000000) {
        lastStep = (info & 0x1fff0000) >> 16;
        if (info & 0x40000000) {
            if (i & 1) {
                if (i > lastStep) {
                    i = (lastStep >> 1) + 1;
                    goto single;
                }
                k = i >> 1;
            } else {
                i >>= 1;
                goto single;
            }
        } else {
            if (i & 3) {
                if (i > lastStep) {
                    i = (i & 3) + (lastStep >> 2);
                    goto single;
                }
                if (i & 1) {
                    if (i & 2) {
                        j = i >> 2;
                        k = j + 1;
                    } else {
                        k = i >> 2;
                        j = k + 1;
                    }
                    if (info & 0x20000000) {
                        x = ((const s16 *) values)[k];
                        y = ((const s16 *) values)[j];
                        *out = (x + x + x + y) >> 2;
                    } else {
                        x = ((const s32 *) values)[k];
                        y = ((const s32 *) values)[j];
                        *out = ((s64) x + x + x + y) >> 2;
                    }
                    return;
                }
                k = i >> 2;
            } else {
                i >>= 2;
                goto single;
            }
        }
        if (info & 0x20000000) {
            x = ((const s16 *) values)[k];
            y = (&((const s16 *) values)[k])[1];
            *out = (x + y) >> 1;
        } else {
            x = ((const s32 *) values)[k];
            y = (&((const s32 *) values)[k])[1];
            *out = (x >> 1) + (y >> 1);
        }
        return;
    }
single:
    if (info & 0x20000000) {
        *out = ((const s16 *) values)[i];
    } else {
        *out = ((const s32 *) values)[i];
    }
}

void getTransDataEx_(s32 *out, s32 frame, const u32 *desc, const NNSG3dResJntAnm *jntAnm) {
    u32 lastStep;
    const u8 *values;
    s32 q;
    s32 y;
    s32 sh;
    u32 info;
    s32 m;
    u32 i;
    s32 x;

    i = frame >> 12;
    values = (const u8 *) jntAnm + desc[1];
    info = desc[0];
    if (i == jntAnm->mNumFrame - 1) {
        if (info & 0xc0000000) {
            if (info & 0x40000000) {
                i = (i & 1) + (i >> 1);
            } else {
                i = (i & 3) + (i >> 2);
            }
        }
        if (jntAnm->mFlag & 2) {
            sh = frame & 0xfff;
            if (info & 0x20000000) {
                x = ((const s16 *) values)[i];
                q = ((const s16 *) values)[0];
            } else {
                x = ((const s32 *) values)[i];
                q = ((const s32 *) values)[0];
            }
            *out = x + ((sh * (q - x)) >> 12);
        } else {
            if (info & 0x20000000) {
                *out = ((const s16 *) values)[i];
            } else {
                *out = ((const s32 *) values)[i];
            }
        }
        return;
    }
    if (info & 0xc0000000) {
        lastStep = (info & 0x1fff0000) >> 16;
        if (info & 0x40000000) {
            if (i >= lastStep) {
                i = lastStep >> 1;
                goto last;
            }
            i >>= 1;
            q = frame & 0x1fff;
            m = 2;
            sh = 1;
        } else {
            if (i >= lastStep) {
                i = (i & 3) + (i >> 2);
                goto last;
            }
            i >>= 2;
            q = frame & 0x3fff;
            m = 4;
            sh = 2;
        }
    } else {
    last:
        q = frame & 0xfff;
        m = 1;
        sh = 0;
    }
    if (info & 0x20000000) {
        x = ((const s16 *) values)[i];
        y = (&((const s16 *) values)[i])[1];
    } else {
        x = ((const s32 *) values)[i];
        y = (&((const s32 *) values)[i])[1];
    }
    *out = (x * m + ((q * (y - x)) >> 12)) >> sh;
}

void getScaleData_(s32 *out, s32 frame, const u32 *desc, const NNSG3dResJntAnm *jntAnm) {
    u32 info;
    const u8 *values;
    u32 k;
    s32 y;
    u32 lastStep;
    s32 x;
    const FxPairS16 *e16;
    const FxPairS32 *e32;
    u32 i;

    i = frame >> 12;
    values = (const u8 *) jntAnm + desc[1];
    info = desc[0];
    if (info & 0xc0000000) {
        lastStep = (info & 0x1fff0000) >> 16;
        if (info & 0x40000000) {
            if (i & 1) {
                if (i > lastStep) {
                    i = (lastStep >> 1) + 1;
                    goto single;
                }
                k = i >> 1;
                goto half;
            }
            i >>= 1;
            goto single;
        }
        if (i & 3) {
            if (i > lastStep) {
                i = (i & 3) + (lastStep >> 2);
                goto single;
            }
            if (i & 1) {
                if (i & 2) {
                    i >>= 2;
                    k = i + 1;
                } else {
                    k = i >> 2;
                    i = k + 1;
                }
                if (info & 0x20000000) {
                    e16 = (const FxPairS16 *) values + k;
                    x = ((const FxPairS16 *) values)[k].mFirst;
                    y = ((const FxPairS16 *) values)[i].mFirst;
                    out[0] = (x + (x << 1) + y) >> 2;
                    x = e16->mSecond;
                    y = ((const FxPairS16 *) values + i)->mSecond;
                    out[1] = (x + (x << 1) + y) >> 2;
                } else {
                    e32 = (const FxPairS32 *) values + k;
                    x = ((const FxPairS32 *) values)[k].mFirst;
                    y = ((const FxPairS32 *) values)[i].mFirst;
                    out[0] = ((s64) x + x + x + y) >> 2;
                    x = e32->mSecond;
                    y = ((const FxPairS32 *) values + i)->mSecond;
                    out[1] = ((s64) x + x + x + y) >> 2;
                }
                return;
            }
            k = i >> 2;
            goto half;
        }
        i >>= 2;
    }
single:
    if (info & 0x20000000) {
        out[0] = ((const FxPairS16 *) values)[i].mFirst;
        out[1] = ((const FxPairS16 *) values)[i].mSecond;
    } else {
        out[0] = ((const FxPairS32 *) values)[i].mFirst;
        out[1] = ((const FxPairS32 *) values)[i].mSecond;
    }
    return;
half:
    if (info & 0x20000000) {
        e16 = (const FxPairS16 *) values + k;
        out[0] = (e16->mFirst + e16[1].mFirst) >> 1;
        out[1] = (e16->mSecond + e16[1].mSecond) >> 1;
    } else {
        e32 = (const FxPairS32 *) values + k;
        out[0] = (e32->mFirst + e32[1].mFirst) >> 1;
        out[1] = (e32->mSecond + e32[1].mSecond) >> 1;
    }
}

void getScaleDataEx_(s32 *out, s32 frame, const u32 *desc, const NNSG3dResJntAnm *jntAnm) {
    const u8 *values;
    u32 info;
    s32 y0;
    u32 i;
    u32 j;
    s32 q;
    s32 m;
    s32 sh;
    s32 y1;
    s32 x0;
    s32 x1;
    u32 lastStep;

    i = frame >> 12;
    values = (const u8 *) jntAnm + desc[1];
    info = desc[0];
    if (i == jntAnm->mNumFrame - 1) {
        if (info & 0xc0000000) {
            if (info & 0x40000000) {
                i = (i & 1) + (i >> 1);
            } else {
                i = (i & 3) + (i >> 2);
            }
        }
        if (jntAnm->mFlag & 2) {
            j = 0;
            goto last;
        }
        if (info & 0x20000000) {
            out[0] = ((const FxPairS16 *) values)[i].mFirst;
            out[1] = ((const FxPairS16 *) values)[i].mSecond;
        } else {
            out[0] = ((const FxPairS32 *) values)[i].mFirst;
            out[1] = ((const FxPairS32 *) values)[i].mSecond;
        }
        return;
    }
    if (info & 0xc0000000) {
        lastStep = (info & 0x1fff0000) >> 16;
        if (info & 0x40000000) {
            if (i >= lastStep) {
                i = lastStep >> 1;
                j = i + 1;
                goto last;
            }
            i >>= 1;
            j = i + 1;
            q = frame & 0x1fff;
            m = 2;
            sh = 1;
        } else {
            if (i >= lastStep) {
                i = (i & 3) + (i >> 2);
                j = i + 1;
                goto last;
            }
            i >>= 2;
            j = i + 1;
            q = frame & 0x3fff;
            m = 4;
            sh = 2;
        }
    } else {
        j = i + 1;
    last:
        q = frame & 0xfff;
        m = 1;
        sh = 0;
    }
    if (info & 0x20000000) {
        x0 = ((const FxPairS16 *) values)[i].mFirst;
        x1 = ((const FxPairS16 *) values)[i].mSecond;
        y0 = ((const FxPairS16 *) values)[j].mFirst;
        y1 = ((const FxPairS16 *) values)[j].mSecond;
    } else {
        x0 = ((const FxPairS32 *) values)[i].mFirst;
        x1 = ((const FxPairS32 *) values)[i].mSecond;
        y0 = ((const FxPairS32 *) values)[j].mFirst;
        y1 = ((const FxPairS32 *) values)[j].mSecond;
    }
    out[0] = (x0 * m + ((q * (y0 - x0)) >> 12)) >> sh;
    out[1] = (x1 * m + ((q * (y1 - x1)) >> 12)) >> sh;
}

void getRotData_(s32 *out, s32 frame, const u32 *desc, const NNSG3dResJntAnm *jntAnm) {
    s32 t[9];
    s32 u[9];
    const s16 *s0;
    const s16 *s1;
    u32 info;
    const u16 *values;
    u32 i;
    u32 lastStep;
    int k;
    u32 i0;
    u32 i1;
    int f;
    s32 x0;
    s32 x1;
    s32 x2;
    s32 x3;
    s32 x4;
    s32 x5;

    i = frame >> 12;
    s0 = (const s16 *) ((u8 *) jntAnm + jntAnm->mOfsRot3);
    s1 = (const s16 *) ((u8 *) jntAnm + jntAnm->mOfsRot5);
    info = desc[0];
    values = (const u16 *) ((u8 *) jntAnm + desc[1]);
    if (info & 0xc0000000) {
        lastStep = (info & 0x1fff0000) >> 16;
        if (info & 0x40000000) {
            if (i & 1) {
                if (i > lastStep) {
                    i = (lastStep >> 1) + 1;
                    goto single;
                }
                k = i >> 1;
            } else {
                i >>= 1;
                goto single;
            }
        } else {
            if (i & 3) {
                if (i > lastStep) {
                    i = (i & 3) + (lastStep >> 2);
                    goto single;
                }
                if (i & 1) {
                    f = 0;
                    if (i & 2) {
                        i1 = i >> 2;
                        i0 = i1 + 1;
                    } else {
                        i0 = i >> 2;
                        i1 = i0 + 1;
                    }
                    f |= getRotDataByIdx_(out, s0, s1, values[i0]);
                    f |= getRotDataByIdx_(t, s0, s1, values[i1]);
                    out[0] = out[0] * 3 + t[0];
                    out[1] = out[1] * 3 + t[1];
                    out[2] = out[2] * 3 + t[2];
                    out[3] = out[3] * 3 + t[3];
                    out[4] = out[4] * 3 + t[4];
                    out[5] = out[5] * 3 + t[5];
                    VEC_Normalize((Vec3 *) out, (Vec3 *) out);
                    VEC_Normalize((Vec3 *) (out + 3), (Vec3 *) (out + 3));
                    if (f == 0) {
                        out[6] = out[6] * 3 + t[6];
                        out[7] = out[7] * 3 + t[7];
                        out[8] = out[8] * 3 + t[8];
                        VEC_Normalize((Vec3 *) (out + 6), (Vec3 *) (out + 6));
                    } else {
                        x5 = out[5];
                        x0 = out[0];
                        x3 = out[3];
                        x2 = out[2];
                        x1 = out[1];
                        x4 = out[4];
                        out[6] = (x1 * x5 - x2 * x4) >> 12;
                        out[7] = (x2 * x3 - x0 * x5) >> 12;
                        out[8] = (x0 * x4 - x1 * x3) >> 12;
                    }
                    return;
                }
                k = i >> 2;
            } else {
                i >>= 2;
                goto single;
            }
        }
        f = 0;
        f |= getRotDataByIdx_(out, s0, s1, values[k]);
        f |= getRotDataByIdx_(u, s0, s1, *(values + k + 1));
        out[0] += u[0];
        out[1] += u[1];
        out[2] += u[2];
        out[3] += u[3];
        out[4] += u[4];
        out[5] += u[5];
        VEC_Normalize((Vec3 *) out, (Vec3 *) out);
        VEC_Normalize((Vec3 *) (out + 3), (Vec3 *) (out + 3));
        if (f == 0) {
            out[6] += u[6];
            out[7] += u[7];
            out[8] += u[8];
            VEC_Normalize((Vec3 *) (out + 6), (Vec3 *) (out + 6));
        } else {
            x5 = out[5];
            x0 = out[0];
            x3 = out[3];
            x2 = out[2];
            x1 = out[1];
            x4 = out[4];
            out[6] = (x1 * x5 - x2 * x4) >> 12;
            out[7] = (x2 * x3 - x0 * x5) >> 12;
            out[8] = (x0 * x4 - x1 * x3) >> 12;
        }
        return;
    }
single:
    if (getRotDataByIdx_(out, s0, s1, values[i]) == 0) {
        return;
    }
    x5 = out[5];
    x0 = out[0];
    x3 = out[3];
    x2 = out[2];
    x1 = out[1];
    x4 = out[4];
    out[6] = (x1 * x5 - x2 * x4) >> 12;
    out[7] = (x2 * x3 - x0 * x5) >> 12;
    out[8] = (x0 * x4 - x1 * x3) >> 12;
}

void getRotDataEx_(s32 *out, s32 frame, const u32 *desc, const NNSG3dResJntAnm *jntAnm) {
    s32 r;
    s32 x1;
    u32 lastStep;
    s32 t[9];
    s32 u[9];
    u32 f;
    s32 x5;
    s32 x3;
    s32 x4;
    u32 info;
    const s16 *s0;
    s32 h;
    const s16 *s1;
    u32 i;
    s32 q;
    s32 m;
    s32 x0;
    const u16 *values;
    s32 x2;
    u32 j;

    i = frame >> 12;
    s0 = (const s16 *) ((u8 *) jntAnm + jntAnm->mOfsRot3);
    s1 = (const s16 *) ((u8 *) jntAnm + jntAnm->mOfsRot5);
    info = desc[0];
    values = (const u16 *) ((u8 *) jntAnm + desc[1]);
    if (i == jntAnm->mNumFrame - 1) {
        if (info & 0xc0000000) {
            if (info & 0x40000000) {
                i = (i & 1) + (i >> 1);
            } else {
                i = (i & 3) + (i >> 2);
            }
        }
        if (jntAnm->mFlag & 2) {
            j = 0;
            goto interp1;
        }
        if (getRotDataByIdx_(out, s0, s1, values[i]) == 0) {
            return;
        }
        x5 = out[5];
        x0 = out[0];
        x3 = out[3];
        x1 = out[1];
        x2 = out[2];
        x4 = out[4];
        out[6] = (x1 * x5 - x2 * x4) >> 12;
        out[7] = (x2 * x3 - x0 * x5) >> 12;
        out[8] = (x0 * x4 - x1 * x3) >> 12;
        return;
    }
    if (info & 0xc0000000) {
        lastStep = (info & 0x1fff0000) >> 16;
        if (info & 0x40000000) {
            if (i >= lastStep) {
                i = lastStep >> 1;
                j = i + 1;
                goto interp1;
            }
            i >>= 1;
            j = i + 1;
            m = 2;
            q = frame & 0x1fff;
        } else {
            if (i >= lastStep) {
                i = (i & 3) + (i >> 2);
                j = i + 1;
                goto interp1;
            }
            i >>= 2;
            j = i + 1;
            q = frame & 0x3fff;
            m = 4;
        }
        goto interp;
    } else {
        j = i + 1;
    }
interp1:
    m = 1;
    q = frame & 0xfff;
interp:
    f = 0;
    f |= getRotDataByIdx_(t, s0, s1, values[i]);
    f |= getRotDataByIdx_(u, s0, s1, values[j]);
    out[0] = t[0] * m + ((q * (u[0] - t[0])) >> 12);
    out[1] = t[1] * m + ((q * (u[1] - t[1])) >> 12);
    out[2] = t[2] * m + ((q * (u[2] - t[2])) >> 12);
    out[3] = t[3] * m + ((q * (u[3] - t[3])) >> 12);
    out[4] = t[4] * m + ((q * (u[4] - t[4])) >> 12);
    out[5] = t[5] * m + ((q * (u[5] - t[5])) >> 12);
    VEC_Normalize((Vec3 *) out, (Vec3 *) out);
    VEC_Normalize((Vec3 *) (out + 3), (Vec3 *) (out + 3));
    if (f == 0) {
        out[6] = t[6] * m + ((q * (u[6] - t[6])) >> 12);
        out[7] = t[7] * m + ((q * (u[7] - t[7])) >> 12);
        r = t[8];
        out[8] = t[8] * m + ((q * (u[8] - r)) >> 12);
        VEC_Normalize((Vec3 *) (out + 6), (Vec3 *) (out + 6));
    } else {
        h = out[5];
        x0 = out[0];
        x2 = out[2];
        x5 = h;
        x3 = out[3];
        x1 = out[1];
        x4 = out[4];
        out[6] = (x1 * x5 - x2 * x4) >> 12;
        out[7] = (x2 * x3 - x0 * x5) >> 12;
        out[8] = (x0 * x4 - x1 * x3) >> 12;
    }
}

BOOL getRotDataByIdx_(s32 *pRot, const s16 *rot3, const s16 *rot5, u32 info) {
    s32 x;
    s32 y;
    s32 v;
    const s16 *w;
    s16 t;
    u32 k;
    s32 z;

    if (info & 0x8000) {
        pRot[0] = pRot[1] = pRot[2] = pRot[3] = pRot[4] = pRot[5] = pRot[6] = pRot[7] = pRot[8] = 0;
        info = (info & 0x7fff) * 3;
        w = rot3 + info;
        z = rot3[info];
        k = z & 0xf;
        x = w[1];
        y = w[2];
        pRot[k] = (z & 0x10) ? -0x1000 : 0x1000;
        pRot[data_02152c30[k][0]] = x;
        pRot[data_02152c31[k][0]] = y;
        if (w[0] & 0x20) {
            y = -y;
        }
        pRot[data_02152c32[k][0]] = y;
        if (w[0] & 0x40) {
            x = -x;
        }
        pRot[data_02152c33[k][0]] = x;
        return 0;
    }
    info = (info & 0x7fff) * 5;
    w = rot5 + info;
    v = w[4];
    pRot[4] = v >> 3;
    t = v & 7;
    v = rot5[info];
    pRot[0] = v >> 3;
    t = (t << 3) | (v & 7);
    v = w[1];
    pRot[1] = v >> 3;
    t = (t << 3) | (v & 7);
    v = w[2];
    pRot[2] = v >> 3;
    t = (t << 3) | (v & 7);
    v = w[3];
    pRot[3] = v >> 3;
    t = (t << 3) | (v & 7);
    pRot[5] = (t << 19) >> 19;
    return 1;
}

void *NNSi_G3dGetBinaryBlockFromFile(const u8 *pFileHead, u32 fileSignature, u32 blockSignature) {
    const NNSG3dResFileHeader *fileHeader;
    NNSG3dResDataBlockHeader *blockHeader;
    u32 i;

    fileHeader = (const NNSG3dResFileHeader *) pFileHead;
    if (fileHeader->mSigVal == fileSignature) {
        for (i = 0; i < fileHeader->mDataBlocks; i++) {
            blockHeader = NNS_G3dGetDataBlockHeaderByIdx(fileHeader, i);
            if (blockHeader->mSignature == blockSignature) {
                return blockHeader;
            }
        }
    }
    return 0;
}

NNSG3dResVisAnm *NNS_G3dGetVisAnmByIdx(NNSG3dResVisAnmSet *pAnmSet, u8 idx) {
    NNSG3dResDictEntryHeader *dictEntries;
    NNSG3dResDictAnmSetData *setEntry;

    dictEntries = (NNSG3dResDictEntryHeader *) ((u8 *) &pAnmSet->mDict + pAnmSet->mDict.mOfsEntry);
    setEntry = (NNSG3dResDictAnmSetData *) (dictEntries->mData + dictEntries->mSizeUnit * idx);
    return (NNSG3dResVisAnm *) ((u8 *) pAnmSet + setEntry->mOffset);
}

NNSG3dResVisAnmSet *NNS_G3dGetVisAnmSet(const u8 *pFileHead) {
    return NNSi_G3dGetBinaryBlockFromFile(pFileHead, 0x30415642, 0x30534956);
}

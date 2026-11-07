#pragma once

#include "types.h"
#include "code_02010c84.h"

typedef struct NNSG3dResDictAnmSetData {
    /* 00 */ u32 mOffset;
} NNSG3dResDictAnmSetData;

typedef struct NNSG3dResAnmSet {
    /* 00 */ NNSG3dResDataBlockHeader mHeader;
    /* 08 */ NNSG3dResDict mDict;
} NNSG3dResAnmSet;

typedef struct NNSG3dResVisAnm {
    /* 00 */ NNSG3dResAnmHeader mAnmHeader;
    /* 04 */ u16 mNumFrame;
    /* 06 */ u16 mNumNode;
    /* 08 */ u16 mSize;
    /* 0a */ u16 mDummy_;
    /* 0c */ u32 mVisData[1];
} NNSG3dResVisAnm;

typedef struct NNSG3dResDictMatCAnmData {
    /* 00 */ u32 mDiffuse;
    /* 04 */ u32 mAmbient;
    /* 08 */ u32 mSpecular;
    /* 0c */ u32 mEmission;
    /* 10 */ u32 mPolygonAlpha;
} NNSG3dResDictMatCAnmData;

typedef struct NNSG3dResMatCAnm {
    /* 00 */ NNSG3dResAnmHeader mAnmHeader;
    /* 04 */ u16 mNumFrame;
    /* 06 */ u16 mFlag;
    /* 08 */ NNSG3dResDict mDict;
} NNSG3dResMatCAnm;

typedef struct NNSG3dResTexPatAnmFV {
    /* 00 */ u16 mIdxFrame;
    /* 02 */ u8 mIdTex;
    /* 03 */ u8 mIdPltt; // 0xff when the palette does not change
} NNSG3dResTexPatAnmFV;

typedef struct NNSG3dResDictTexPatAnmData {
    /* 00 */ u16 mNumFV;
    /* 02 */ u16 mFlag;
    /* 04 */ s16 mRatioDataFrame;
    /* 06 */ u16 mOffset;
} NNSG3dResDictTexPatAnmData;

typedef struct NNSG3dResTexPatAnm {
    /* 00 */ NNSG3dResAnmHeader mAnmHeader;
    /* 04 */ u16 mNumFrame;
    /* 06 */ u8 mNumTex;
    /* 07 */ u8 mNumPltt;
    /* 08 */ u16 mOfsTexName;
    /* 0a */ u16 mOfsPlttName;
    /* 0c */ NNSG3dResDict mDict;
} NNSG3dResTexPatAnm;

typedef struct NNSG3dResDictTexSRTAnmData {
    /* 00 */ u32 mScaleS;
    /* 04 */ u32 mScaleSEx;
    /* 08 */ u32 mScaleT;
    /* 0c */ u32 mScaleTEx;
    /* 10 */ u32 mRot;
    /* 14 */ u32 mRotEx;
    /* 18 */ u32 mTransS;
    /* 1c */ u32 mTransSEx;
    /* 20 */ u32 mTransT;
    /* 24 */ u32 mTransTEx;
} NNSG3dResDictTexSRTAnmData;

typedef struct NNSG3dResTexSRTAnm {
    /* 00 */ NNSG3dResAnmHeader mAnmHeader;
    /* 04 */ u16 mNumFrame;
    /* 06 */ u8 mFlag;
    /* 07 */ u8 mTexMtxMode;
    /* 08 */ NNSG3dResDict mDict;
} NNSG3dResTexSRTAnm;

typedef struct NNSG3dResJntAnm {
    /* 00 */ NNSG3dResAnmHeader mAnmHeader;
    /* 04 */ u16 mNumFrame;
    /* 06 */ u16 mNumNode;
    /* 08 */ u32 mFlag;
    /* 0c */ u32 mOfsRot3;
    /* 10 */ u32 mOfsRot5;
    /* 14 */ u16 mUnk_14[1]; // byte offsets from this struct, one per node
} NNSG3dResJntAnm;

typedef NNSG3dResAnmSet NNSG3dResVisAnmSet;
typedef NNSG3dResAnmSet NNSG3dResMatCAnmSet;
typedef NNSG3dResAnmSet NNSG3dResTexPatAnmSet;
typedef NNSG3dResAnmSet NNSG3dResTexSRTAnmSet;
typedef NNSG3dResAnmSet NNSG3dResJntAnmSet;

NNSG3dResDataBlockHeader *NNS_G3dGetDataBlockHeaderByIdx(const NNSG3dResFileHeader *header, u32 idx);
int NNS_G3dGetResDictIdxByName(const void *dict, const u32 *name);
void *NNS_G3dGetResDataByName(const void *dict, const u32 *name);
NNSG3dResJntAnmSet *NNS_G3dGetJntAnmSet(const u8 *pFileHead);
NNSG3dResJntAnm *NNS_G3dGetJntAnmByIdx(NNSG3dResJntAnmSet *pJntAnmSet, int idx);
NNSG3dResMatCAnmSet *NNS_G3dGetMatCAnmSet(const u8 *pFileHead);
NNSG3dResMatCAnm *NNS_G3dGetMatCAnmByIdx(NNSG3dResMatCAnmSet *pAnmSet, u8 idx);
NNSG3dResTexSRTAnmSet *NNS_G3dGetTexSRTAnmSet(const u8 *pFileHead);
NNSG3dResTexSRTAnm *NNS_G3dGetTexSRTAnmByIdx(NNSG3dResTexSRTAnmSet *pTexSRTSet, u8 idx);
NNSG3dResTexPatAnmSet *NNS_G3dGetTexPatAnmSet(const u8 *pFileHead);
NNSG3dResTexPatAnm *NNS_G3dGetTexPatAnmByIdx(NNSG3dResTexPatAnmSet *pAnmSet, u8 idx);

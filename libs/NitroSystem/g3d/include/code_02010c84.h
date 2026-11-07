#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43, NNSG3dResMdl, NNSG3dResMatData, NNSG3dResShpData

typedef struct NNSG3dAnmObj NNSG3dAnmObj;
typedef struct NNSG3dRS NNSG3dRS;
typedef struct NNSG3dResTex NNSG3dResTex;
typedef struct NNSG3dMatAnmResult NNSG3dMatAnmResult;

// Result of a visibility animation.
typedef struct NNSG3dVisAnmResult {
    /* 00 */ BOOL mIsVisible;
} NNSG3dVisAnmResult;

// Result of a joint animation for one node. Bit 0 of mFlag says the scale is one, bit 1 that the rotation is zero,
// bit 2 that the translation is zero, bits 3 and 4 that mScaleEx0 and mScaleEx1 are one.
typedef struct NNSG3dJntAnmResult {
    /* 00 */ u32 mFlag;
    /* 04 */ Vec3 mScale;
    /* 10 */ Vec3 mScaleEx0;
    /* 1c */ Vec3 mScaleEx1;
    /* 28 */ Vec3 mRot[3];
    /* 4c */ Vec3 mTrans;
} NNSG3dJntAnmResult;

// Result of a material animation: the colors, polygon attributes and texture parameters of one material.
struct NNSG3dMatAnmResult {
    /* 00 */ u32 mUnk_00; // bit 3 set means the texture matrix is set from this result
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10; // bits 30 and 31 are read and set
    /* 14 */ u32 mUnk_14;
    /* 18 */ s32 mUnk_18[2];
    /* 20 */ s16 mUnk_20[2];
    /* 24 */ u32 mUnk_24[2];
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
};

typedef BOOL (*NNSG3dFuncAnmBlendMat)(NNSG3dMatAnmResult *, const NNSG3dAnmObj *, u32);
typedef BOOL (*NNSG3dFuncAnmBlendJnt)(NNSG3dJntAnmResult *, const NNSG3dAnmObj *, u32);
typedef BOOL (*NNSG3dFuncAnmBlendVis)(NNSG3dVisAnmResult *, const NNSG3dAnmObj *, u32);
typedef void (*NNSG3dSbcCallBackFunc)(NNSG3dRS *);

// Animation object. Several are linked through mNext; bit 8 and bit 9 of mMapData[n] are tested and the low byte is
// passed on to the function at mFuncAnm, which is called with a pointer to its result, this object and that byte.
struct NNSG3dAnmObj {
    /* 00 */ s32 mFrame;
    /* 04 */ s32 mRatio;
    /* 08 */ void *mResAnm;
    /* 0c */ void (*mFuncAnm)(void *, NNSG3dAnmObj *, u32);
    /* 10 */ NNSG3dAnmObj *mNext;
    /* 14 */ const NNSG3dResTex *mResTex;
    /* 18 */ u8 mPriority;
    /* 19 */ u8 mNumMapData;
    /* 1a */ u16 mMapData[1];
};

// Render object: the model and the animation objects drawn with it.
typedef struct NNSG3dRenderObj {
    /* 00 */ u32 mFlag;
    /* 04 */ NNSG3dResMdl *mResMdl;
    /* 08 */ NNSG3dAnmObj *mAnmMat;
    /* 0c */ NNSG3dFuncAnmBlendMat mFuncBlendMat;
    /* 10 */ NNSG3dAnmObj *mAnmJnt;
    /* 14 */ NNSG3dFuncAnmBlendJnt mFuncBlendJnt;
    /* 18 */ NNSG3dAnmObj *mAnmVis;
    /* 1c */ NNSG3dFuncAnmBlendVis mFuncBlendVis;
    /* 20 */ NNSG3dSbcCallBackFunc mCbFunc;
    /* 24 */ u8 mCbCmd;
    /* 25 */ u8 mCbTiming;
    /* 26 */ u16 mDummy_;
    /* 28 */ NNSG3dSbcCallBackFunc mCbInitFunc;
    /* 2c */ void *mPtrUser;
    /* 30 */ u8 *mPtrUserSbc;
    /* 34 */ NNSG3dJntAnmResult *mRecJntAnm;
    /* 38 */ NNSG3dMatAnmResult *mRecMatAnm;
    /* 3c */ u32 mHintMatAnmExist[2];
    /* 44 */ u32 mHintJntAnmExist[2];
    /* 4c */ u32 mHintVisAnmExist[2];
    /* 54 */ u8 mUnk_54[4];
    /* 58 */ s32 mUnk_58;
    /* 5c */ u8 mUnk_5c[0xc];
    /* 68 */ u32 mUnk_68;
} NNSG3dRenderObj;

// Render state of the SBC interpreter. mC points into the byte sequence that the SBC functions advance.
struct NNSG3dRS {
    /* 00 */ u8 *mC;
    /* 04 */ NNSG3dRenderObj *mRenderObj;
    /* 08 */ u32 mFlag; // bit 0, bit 6, bit 8 and bit 9 are tested
    /* 0c */ NNSG3dSbcCallBackFunc mCbVecFunc[32];
    /* 8c */ u8 mCbVecTiming[32];
    /* ac */ u8 mCurrentNode;
    /* ad */ u8 mCurrentMat;
    /* ae */ u8 mCurrentNodeDesc;
    /* af */ u8 mDummy_;
    /* b0 */ NNSG3dMatAnmResult *mMatAnmResult;
    /* b4 */ NNSG3dJntAnmResult *mJntAnmResult;
    /* b8 */ NNSG3dVisAnmResult *mVisAnmResult;
    /* bc */ u32 mIsMatCached[2];
    /* c4 */ u32 mIsScaleCacheOne[2];
    /* cc */ u32 mIsEvpCached[2]; // bit set indexed by a node number (word = number >> 5)
    /* d4 */ void *mResNodeInfo;
    /* d8 */ NNSG3dResMat *mResMat;
    /* dc */ void *mResShp;
};

// Entry of the table of animation formats (8 bytes).
typedef struct NNSG3dAnmObjInitFunc {
    /* 00 */ u8 mCategory0;
    /* 01 */ u8 mDummy_;
    /* 02 */ u16 mCategory1;
    /* 04 */ void (*mFunc)(NNSG3dAnmObj *, void *, const NNSG3dResMdl *);
} NNSG3dAnmObjInitFunc;

// Header of an animation resource.
typedef struct NNSG3dResAnmHeader {
    /* 00 */ u8 mCategory0;
    /* 01 */ u8 mRevision;
    /* 02 */ u16 mCategory1;
} NNSG3dResAnmHeader;

// Global state of the G3D library; the leading part is sent to the geometry engine as one command block.
typedef struct NNSG3dGlb {
    /* 000 */ u32 mCmd0;
    /* 004 */ u32 mMtxModeProj;
    /* 008 */ s32 mProjMtx[16];
    /* 048 */ u32 mMtxModePosVec;
    /* 04c */ MtxFx43 mCameraMtx;
    /* 07c */ u32 mCmd1;
    /* 080 */ u32 mLightVec[4];
    /* 090 */ u32 mCmd2;
    /* 094 */ u32 mPrmMatColor0;
    /* 098 */ u32 mPrmMatColor1;
    /* 09c */ u32 mPrmPolygonAttr;
    /* 0a0 */ u32 mPrmViewPort;
    /* 0a4 */ u32 mCmd3;
    /* 0a8 */ u32 mLightColor[4];
    /* 0b8 */ u32 mCmd4;
    /* 0bc */ Vec3 mPrmBaseRot[3];
    /* 0e0 */ Vec3 mPrmBaseTrans;
    /* 0ec */ Vec3 mPrmBaseScale;
    /* 0f8 */ u32 mPrmTexImageParam;
    /* 0fc */ u32 mFlag;
    /* 100 */ MtxFx43 mInvCameraMtx;
    /* 130 */ MtxFx43 mSrtCameraMtx;
    /* 160 */ MtxFx43 mInvSrtCameraMtx;
    /* 190 */ u8 mUnk_190[0xb0]; // inverse base matrix, inverse projection matrix and inverse camera-projection matrix
    /* 240 */ Vec3 mCamPos;
    /* 24c */ Vec3 mCamUp;
    /* 258 */ Vec3 mCamTarget;
} NNSG3dGlb;

void NNS_G3dRenderObjInit(NNSG3dRenderObj *renderObj, NNSG3dResMdl *resMdl);
void NNS_G3dAnmObjInit(NNSG3dAnmObj *anmObj, void *resAnm, const NNSG3dResMdl *resMdl, void *resTex);
u32 NNS_G3dAnmObjCalcSizeRequired(const void *anm, const NNSG3dResMdl *mdl);
MtxFx43 *NNS_G3dGlbGetInvWV(void);
MtxFx43 *NNS_G3dGlbGetWV(void);
void calcSrtCameraMtx_(void);
MtxFx43 *NNS_G3dGlbGetInvV(void);
void NNS_G3dGlbPolygonAttr(u32 light, u32 polyMode, u32 cullMode, u32 polygonId, u32 alpha, u32 extra);
void NNS_G3dGlbMaterialColorSpecEmi(u32 specular, u32 emission, u32 shininess);
void NNS_G3dGlbMaterialColorDiffAmb(u32 diffuse, u32 ambient, u32 vtxColor);
void NNS_G3dGlbLightColor(u32 lightId, u32 rgb);
void NNS_G3dGlbLightVector(u32 lightId, s32 x, s32 y, s32 z);
void NNS_G3dGlbSetBaseScale(const Vec3 *scale);
void NNS_G3dGlbSetBaseTrans(const Vec3 *trans);
void NNS_G3dGlbFlushP(void);
void NNS_G3dGlbInit(void);
BOOL NNSi_G3dAnmBlendVis(NNSG3dVisAnmResult *result, NNSG3dAnmObj *anmObj, u32 nodeId);
BOOL NNSi_G3dAnmBlendJnt(NNSG3dJntAnmResult *result, NNSG3dAnmObj *anmObj, u32 nodeId);
void blendScaleVec_(Vec3 *dest, const Vec3 *src, s32 weight, u32 srcIsOne);
BOOL NNSi_G3dAnmBlendMat(NNSG3dMatAnmResult *result, NNSG3dAnmObj *anmObj, u32 matId);
void NNSi_G3dFuncSbc_PRJMAP(NNSG3dRS *state);
void NNSi_G3dFuncSbc_ENVMAP(NNSG3dRS *state);
void NNSi_G3dFuncSbc_CALLDL(NNSG3dRS *state);
void NNSi_G3dFuncSbc_NODEMIX(NNSG3dRS *state);
void NNSi_G3dFuncSbc_BBY(NNSG3dRS *state, u32 mode);
void NNSi_G3dFuncSbc_BB(NNSG3dRS *state, u32 mode);
void NNS_G3dDraw1Mat1Shp(NNSG3dResMdl *resMdl, u32 matId, u32 shpId, BOOL sendMat);

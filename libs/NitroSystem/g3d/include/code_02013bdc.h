#pragma once

#include "types.h"
#include "code_02010c84.h"
#include "code_02013740.h"
#include "code_02010804.h"

// Two samples read together by getScaleDataEx_.
typedef struct FxPairS16 {
    /* 00 */ s16 mFirst;
    /* 02 */ s16 mSecond;
} FxPairS16;

typedef struct FxPairS32 {
    /* 00 */ s32 mFirst;
    /* 04 */ s32 mSecond;
} FxPairS32;

// Node info block of a model.
typedef struct Unk02170500_d4 {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u16 mUnk_06;
} Unk02170500_d4;

typedef struct Unk02170500_04_04 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u8 mUnk_10[5];
    /* 15 */ u8 mUnk_15;
    /* 16 */ u8 mUnk_16;
    /* 17 */ u8 mUnk_17;
    /* 18 */ u8 mUnk_18[4];
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} Unk02170500_04_04;

struct Unk02170500;

typedef struct Unk02170500_04 {
    /* 00 */ u32 mUnk_00; // bit 0 and bit 4 are tested
    /* 04 */ Unk02170500_04_04 *mUnk_04;
    /* 08 */ NNSG3dAnmObj *mUnk_08;
    /* 0c */ s32 (*mUnk_0c)(NNSG3dMatAnmResult *, NNSG3dAnmObj *, u32);
    /* 10 */ NNSG3dAnmObj *mUnk_10;
    /* 14 */ s32 (*mUnk_14)(NNSG3dJntAnmResult *, NNSG3dAnmObj *, u32);
    /* 18 */ NNSG3dAnmObj *mUnk_18;
    /* 1c */ s32 (*mUnk_1c)(u32 *, NNSG3dAnmObj *, u32);
    /* 20 */ void (*mUnk_20)(struct Unk02170500 *);
    /* 24 */ u8 mUnk_24;
    /* 25 */ u8 mUnk_25;
    /* 28 */ void (*mUnk_28)(struct Unk02170500 *);
    /* 2c */ u8 mUnk_2c[4];
    /* 30 */ u8 *mUnk_30;
    /* 34 */ NNSG3dJntAnmResult *mUnk_34;
    /* 38 */ NNSG3dMatAnmResult *mUnk_38;
    /* 3c */ u32 mUnk_3c[2];
    /* 44 */ u32 mUnk_44[2];
    /* 4c */ u32 mUnk_4c[2];
} Unk02170500_04;

typedef struct Unk02170500 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ Unk02170500_04 *mUnk_04;
    /* 08 */ u32 mUnk_08; // bits 0-4, 6, 7 to 10 are tested
    /* 0c */ void (*mUnk_0c[0x20])(struct Unk02170500 *);
    /* 8c */ u8 mUnk_8c[0x20];
    /* ac */ u8 mUnk_ac;
    /* ad */ u8 mUnk_ad;
    /* ae */ u8 mUnk_ae;
    /* af */ u8 mUnk_af;
    /* b0 */ NNSG3dMatAnmResult *mUnk_b0;
    /* b4 */ NNSG3dJntAnmResult *mUnk_b4;
    /* b8 */ u32 *mUnk_b8;
    /* bc */ u32 mUnk_bc[2];
    /* c4 */ u32 mUnk_c4[4];
    /* d4 */ Unk02170500_d4 *mUnk_d4;
    /* d8 */ u8 *mUnk_d8;
    /* dc */ u8 *mUnk_dc;
    /* e0 */ s32 mUnk_e0;
    /* e4 */ s32 mUnk_e4;
    /* e8 */ UnkFunc *mUnk_e8; // called with four arguments by getJntSRTAnmResult_ and getMdlScale_
    /* ec */ void (*mUnk_ec)(NNSG3dJntAnmResult *);
    /* f0 */ void (*mUnk_f0)(NNSG3dMatAnmResult *);
    /* f4 */ NNSG3dMatAnmResult mUnk_f4;
    /* 12c */ NNSG3dJntAnmResult mUnk_12c;
    /* 184 */ u32 mUnk_184;
} Unk02170500;

typedef struct NNSG3dResNodeData {
    /* 00 */ u16 mFlag;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04[8];
} NNSG3dResNodeData;

void *NNSi_G3dGetBinaryBlockFromFile(const u8 *pFileHead, u32 fileSignature, u32 blockSignature);
NNSG3dResVisAnmSet *NNS_G3dGetVisAnmSet(const u8 *pFileHead);
NNSG3dResVisAnm *NNS_G3dGetVisAnmByIdx(NNSG3dResVisAnmSet *pAnmSet, u8 idx);
BOOL getRotDataByIdx_(s32 *pRot, const s16 *pArrayRot3, const s16 *pArrayRot5, u32 info);
void getRotDataEx_(s32 *pRot, s32 frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm);
void getRotData_(s32 *pRot, s32 frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm);
void getScaleDataEx_(s32 *sInvs, s32 frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm);
void getScaleData_(s32 *sInvs, s32 frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm);
void getTransDataEx_(s32 *pVal, s32 frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm);
void getTransData_(s32 *pVal, s32 frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm);
void getJntSRTAnmResult_(const NNSG3dResJntAnm *pJntAnm, int dataIdx, s32 frame, NNSG3dJntAnmResult *pResult);
void getMdlRot_(NNSG3dJntAnmResult *pResult);
void getMdlScale_(NNSG3dJntAnmResult *pResult);
void getMdlTrans_(NNSG3dJntAnmResult *pResult);
void NNSi_G3dAnmCalcNsBca(NNSG3dJntAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, int dataIdx);
void NNSi_G3dAnmObjInitNsBca(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl);
void NNSi_G3dAnmCalcNsBma(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void NNSi_G3dAnmObjInitNsBma(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl);
u16 GetMatColAnmuAlphaValue_(const NNSG3dResMatCAnm *pAnm, u32 info, u32 frame);
u16 GetMatColAnmValue_(const NNSG3dResMatCAnm *pAnm, u32 info, u32 frame);
void NNSi_G3dAnmCalcNsBta(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void NNSi_G3dAnmObjInitNsBta(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl);
void GetTexSRTAnm_(const NNSG3dResTexSRTAnm *pTexAnm, u16 idx, u32 frame, NNSG3dMatAnmResult *pResult);
u32 GetTexSRTAnmSinCosVal_(const NNSG3dResTexSRTAnm *pTexAnm, u32 info, u32 data, u32 frame);
s32 GetTexSRTAnmVectorVal_(const NNSG3dResTexSRTAnm *pTexAnm, u32 info, s32 data, u32 frame);
void NNSi_G3dAnmCalcNsBtp(NNSG3dMatAnmResult *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void SetPlttParamaters_(const NNSG3dResTex *pTex, const u32 *pPlttName, NNSG3dMatAnmResult *pResult);
void SetTexParamaters_(const NNSG3dResTex *pTex, const u32 *pTexName, NNSG3dMatAnmResult *pResult);
void NNSi_G3dAnmObjInitNsBtp(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl);
void NNSi_G3dAnmCalcNsBva(u32 *pResult, const NNSG3dAnmObj *pAnmObj, u32 dataIdx);
void NNSi_G3dAnmObjInitNsBva(NNSG3dAnmObj *pAnmObj, void *pResAnm, const NNSG3dResMdl *pResMdl);

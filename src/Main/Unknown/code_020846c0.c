#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02036820.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0205e090.h"
#include "code_020109ac.h"
#include "code_02010878.h"
#include "code_02010998.h"
#include "res_struct_accessor.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200fe74.h"
#include "code_020108bc.h"
#include "code_02010804.h"
#include "code_02010c84.h"
#include "code_020172d0.h"

// Appends the entry for file b, uploads the texture of file c, and binds the model set of b to it when there is one.
void AddResFileEntry(ResFileEntry *entry, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile) {
    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *texture;

    modelSet = NNS_G3dGetMdlSet(modelFile);
    texture = NNS_G3dGetTex(textureFile);
    entry->mTexture = NULL;
    entry->mFile = NULL;
    NNS_FndAppendListObject(&gResFileEntries, entry);
    entry->mFile = modelFile;
    if (texture == NULL) {
        return;
    }
    texture->mTexInfo.mFlag &= ~1;
    texture->mTex4x4Info.mFlag &= ~1;
    texture->mTexInfo.mVramKey = 0;
    texture->mTex4x4Info.mVramKey = 0;
    texture->mPlttInfo.mFlag &= ~1;
    texture->mPlttInfo.mVramKey = 0;
    UploadResTexture(texture);
    entry->mTexture = texture;
    if (modelSet->mHeader.mSignature == 0x304c444d) {
        NNS_G3dBindMdlSet(modelSet, texture);
    }
}

// Gets VRAM for the texture, 4x4 texture and palette blocks and loads them; 0 if loaded already or a block fails.
u32 UploadResTexture(NNSG3dResTex *texture) {
    u32 v1;
    u32 v0;
    u32 v2;
    u32 result = 1;
    u32 texOk = 1;
    u32 tex4x4Ok = 1;
    u32 plttOk = 1;

    if ((texture->mTexInfo.mFlag & 1) != 0 || (texture->mTex4x4Info.mFlag & 1) != 0 ||
        (texture->mPlttInfo.mFlag & 1) != 0) {
        result = 0;
    } else {
        v0 = NNS_G3dTexGetRequiredSize(texture);
        v1 = NNS_G3dTex4x4GetRequiredSize(texture);
        v2 = NNS_G3dPlttGetRequiredSize(texture);
        if (v0 != 0) {
            v0 = data_021619ec(v0, 0, 0);
            if (v0 == 0) {
                texOk = 0;
            }
        } else {
            v0 = 0;
        }
        if (v1 != 0) {
            v1 = data_021619ec(v1, 1, 0);
            if (v1 == 0) {
                tex4x4Ok = 0;
            }
        } else {
            v1 = 0;
        }
        if (v2 != 0) {
            v2 = data_021619f4(v2, texture->mTex4x4Info.mFlag & 0x8000, 0);
            if (v2 == 0) {
                plttOk = 0;
            }
        } else {
            v2 = 0;
        }
        if (texOk == 0 || tex4x4Ok == 0 || plttOk == 0) {
            data_021619f8((void *) v2);
            data_021619f0((void *) v1);
            data_021619f0((void *) v0);
            return 0;
        }
        NNS_G3dTexSetTexKey(texture, v0, v1);
        NNS_G3dPlttSetPlttKey(texture, v2);
        NNS_G3dTexLoad(texture, 1);
        NNS_G3dPlttLoad(texture, 1);
    }
    return result;
}

// With c non-zero and scene number 2 it swaps cull modes 1 and 2 when byte 0x57 of the game record is set.
void InitNsbmdRenderObj(Nsbmd *nsbmd, NNSG3dResMdl *resMdl, u32 allowCullSwap) {
    u32 i;
    NNSG3dResMdl *objResMdl;

    if (allowCullSwap != 0 && GetCurrentSceneNumber() == 2) {
        nsbmd->mCullModesSwapped = gRaceSetup->mMirrorMode;
    } else {
        nsbmd->mCullModesSwapped = 0;
    }
    if (resMdl->mInfo.mNumMat == 1 && resMdl->mInfo.mNumShp == 1) {
        nsbmd->mDrawKind = 1;
    } else {
        nsbmd->mDrawKind = 0;
    }
    NNS_G3dRenderObjInit((NNSG3dRenderObj *) nsbmd, resMdl);
    if (nsbmd->mCullModesSwapped != 0) {
        objResMdl = nsbmd->mResMdl;
        for (i = 0; i < objResMdl->mInfo.mNumMat; i++) {
            if (NNS_G3dMdlGetMdlCullMode(objResMdl, i) == 1) {
                NNS_G3dMdlSetMdlCullMode(objResMdl, i, 2);
            } else if (NNS_G3dMdlGetMdlCullMode(objResMdl, i) == 2) {
                NNS_G3dMdlSetMdlCullMode(objResMdl, i, 1);
            }
        }
    }
}

void func_02084f68(Nsbmd *nsbmd) {
    u32 i;
    NNSG3dResMdl *resMdl;

    resMdl = nsbmd->mResMdl;
    for (i = 0; i < resMdl->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlCullMode(resMdl, i, 1);
    }
}

void func_02084f20(Nsbmd *nsbmd) {
    u32 i;
    NNSG3dResMdl *resMdl;

    resMdl = nsbmd->mResMdl;
    for (i = 0; i < resMdl->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlCullMode(resMdl, i, 2);
    }
}

void func_02084f10(Nsbmd *nsbmd, NNSG3dResMdl *resMdl) {
    InitNsbmdRenderObj(nsbmd, resMdl, 1);
}

NNSG3dResMdl *InitNsbmd(void *object, NNSG3dResFileHeader *file) {
    Nsbmd *nsbmd = object;

    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *texture;
    u8 *modelSetBytes;

    modelSet = NNS_G3dGetMdlSet(file);
    texture = NNS_G3dGetTex(file);
    nsbmd->mResFileEntry.mTexture = NULL;
    nsbmd->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&gResFileEntries, &nsbmd->mResFileEntry);
    nsbmd->mResFileEntry.mFile = file;
    if (texture != NULL) {
        texture->mTexInfo.mFlag &= ~1;
        texture->mTex4x4Info.mFlag &= ~1;
        texture->mTexInfo.mVramKey = 0;
        texture->mTex4x4Info.mVramKey = 0;
        texture->mPlttInfo.mFlag &= ~1;
        texture->mPlttInfo.mVramKey = 0;
        UploadResTexture(texture);
        nsbmd->mResFileEntry.mTexture = texture;
        if (modelSet->mHeader.mSignature == 0x304c444d) {
            NNS_G3dBindMdlSet(modelSet, texture);
        }
    }
    modelSetBytes = (u8 *) NNS_G3dGetMdlSet(file);
    InitNsbmdRenderObj(
        nsbmd, (NNSG3dResMdl *) (modelSetBytes + *(u32 *) (modelSetBytes + *(u16 *) (modelSetBytes + 14) + 12)), 1);
    return nsbmd->mResMdl;
}

NNSG3dResMdl *InitNsbmdWithTextureFile(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile) {
    Nsbmd *o = nsbmd;

    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *texture;
    u8 *modelSetBytes;

    modelSet = NNS_G3dGetMdlSet(modelFile);
    texture = NNS_G3dGetTex(textureFile);
    o->mResFileEntry.mTexture = NULL;
    o->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&gResFileEntries, &o->mResFileEntry);
    o->mResFileEntry.mFile = modelFile;
    if (texture != NULL) {
        texture->mTexInfo.mFlag &= ~1;
        texture->mTex4x4Info.mFlag &= ~1;
        texture->mTexInfo.mVramKey = 0;
        texture->mTex4x4Info.mVramKey = 0;
        texture->mPlttInfo.mFlag &= ~1;
        texture->mPlttInfo.mVramKey = 0;
        UploadResTexture(texture);
        o->mResFileEntry.mTexture = texture;
        if (modelSet->mHeader.mSignature == 0x304c444d) {
            NNS_G3dBindMdlSet(modelSet, texture);
        }
    }
    modelSetBytes = (u8 *) NNS_G3dGetMdlSet(modelFile);
    InitNsbmdRenderObj(
        o, (NNSG3dResMdl *) (modelSetBytes + *(u32 *) (modelSetBytes + *(u16 *) (modelSetBytes + 14) + 12)), 1);
    return o->mResMdl;
}

NNSG3dResMdl *InitNsbmdWithoutCullSwap(Nsbmd *nsbmd, NNSG3dResFileHeader *file) {
    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *texture;
    u8 *modelSetBytes;

    modelSet = NNS_G3dGetMdlSet(file);
    texture = NNS_G3dGetTex(file);
    nsbmd->mResFileEntry.mTexture = NULL;
    nsbmd->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&gResFileEntries, &nsbmd->mResFileEntry);
    nsbmd->mResFileEntry.mFile = file;
    if (texture != NULL) {
        texture->mTexInfo.mFlag &= ~1;
        texture->mTex4x4Info.mFlag &= ~1;
        texture->mTexInfo.mVramKey = 0;
        texture->mTex4x4Info.mVramKey = 0;
        texture->mPlttInfo.mFlag &= ~1;
        texture->mPlttInfo.mVramKey = 0;
        UploadResTexture(texture);
        nsbmd->mResFileEntry.mTexture = texture;
        if (modelSet->mHeader.mSignature == 0x304c444d) {
            NNS_G3dBindMdlSet(modelSet, texture);
        }
    }
    modelSetBytes = (u8 *) NNS_G3dGetMdlSet(file);
    InitNsbmdRenderObj(
        nsbmd, (NNSG3dResMdl *) (modelSetBytes + *(u32 *) (modelSetBytes + *(u16 *) (modelSetBytes + 14) + 12)), 0);
    return nsbmd->mResMdl;
}

// Fills the object from model file c and texture file d, then keeps a heap copy of the texture block's header part.
NNSG3dResMdl *InitNsbmdWithTextureInfoCopy(void *heap, Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile,
                                           NNSG3dResFileHeader *textureFile) {
    NNSG3dResMdlSet *modelSet;
    NNSG3dResTex *texture;
    u8 *modelSetBytes;
    NNSG3dResTex *loadedTexture;
    u32 headerSize;
    ResFileEntry *entry;
    NNSG3dResMdl *resMdl;

    modelSet = NNS_G3dGetMdlSet(modelFile);
    texture = NNS_G3dGetTex(textureFile);
    nsbmd->mResFileEntry.mTexture = NULL;
    nsbmd->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&gResFileEntries, &nsbmd->mResFileEntry);
    nsbmd->mResFileEntry.mFile = modelFile;
    if (texture != NULL) {
        texture->mTexInfo.mFlag &= ~1;
        texture->mTex4x4Info.mFlag &= ~1;
        texture->mTexInfo.mVramKey = 0;
        texture->mTex4x4Info.mVramKey = 0;
        texture->mPlttInfo.mFlag &= ~1;
        texture->mPlttInfo.mVramKey = 0;
        UploadResTexture(texture);
        nsbmd->mResFileEntry.mTexture = texture;
        if (modelSet->mHeader.mSignature == 0x304c444d) {
            NNS_G3dBindMdlSet(modelSet, texture);
        }
    }
    modelSetBytes = (u8 *) NNS_G3dGetMdlSet(modelFile);
    InitNsbmdRenderObj(
        nsbmd, (NNSG3dResMdl *) (modelSetBytes + *(u32 *) (modelSetBytes + *(u16 *) (modelSetBytes + 14) + 12)), 1);
    entry = &nsbmd->mResFileEntry;
    loadedTexture = entry->mTexture;
    resMdl = nsbmd->mResMdl;
    if (loadedTexture != NULL) {
        headerSize = loadedTexture->mTexInfo.mOfsTex;
        entry->mTexture = HeapAlloc(heap, headerSize);
        MI_CpuCopy8(loadedTexture, entry->mTexture, headerSize);
    }
    return resMdl;
}

void func_02084ad8(void *object, u8 alpha) {
    Nsbmd *nsbmd = object;

    NNSG3dResMdl *resMdl = nsbmd->mResMdl;
    u32 cullMode;

    if (nsbmd->mCullModesSwapped != 0) {
        cullMode = 2;
    } else {
        cullMode = 1;
    }
    NNS_G3dMdlSetMdlPolygonID(resMdl, 0, 0);
    NNS_G3dMdlSetMdlCullMode(resMdl, 0, cullMode);
    NNS_G3dMdlSetMdlAlpha(resMdl, 0, alpha);
}

void func_02084a88(void *object, u8 alpha, u8 polygonId) {
    Nsbmd *nsbmd = object;

    NNSG3dResMdl *resMdl = nsbmd->mResMdl;
    u32 cullMode;

    if (nsbmd->mCullModesSwapped != 0) {
        cullMode = 1;
    } else {
        cullMode = 2;
    }
    NNS_G3dMdlSetMdlPolygonID(resMdl, 0, polygonId);
    NNS_G3dMdlSetMdlCullMode(resMdl, 0, cullMode);
    NNS_G3dMdlSetMdlAlpha(resMdl, 0, alpha);
}

// Draws with matrix b; when c is not NULL its three words (a scale, 0x1000 = 1.0) are sent first.
void DrawNsbmdWithMatrix(void *object, MtxFx43 *matrix, u32 *scale) {
    s32 commandParam = 30;
    u32 scaleCopy[3];

    func_01ff9048(20, &commandParam, 1);
    func_01ff9048(25, matrix, 12);
    if (scale != NULL) {
        u32 z = scale[2];
        u32 y = scale[1];
        u32 x = scale[0];
        scaleCopy[0] = x;
        scaleCopy[1] = y;
        scaleCopy[2] = z;
        func_01ff9048(27, &scaleCopy, 3);
    }
    gNsbmdDrawFunctions[((Nsbmd *) object)->mDrawKind](object);
}

void DrawNsbmd(void *object) {
    Nsbmd *nsbmd = object;

    gNsbmdDrawFunctions[nsbmd->mDrawKind](nsbmd);
}

void SetNsbmdPolygonIdAll(void *object, u32 polygonId) {
    Nsbmd *nsbmd = object;

    NNS_G3dMdlSetMdlPolygonIDAll(nsbmd->mResMdl, polygonId);
}

void SetNsbmdLightEnableFlagAll(void *object, u32 light) {
    Nsbmd *nsbmd = object;

    NNS_G3dMdlSetMdlLightEnableFlagAll(nsbmd->mResMdl, light);
}

void SetNsbmdEmiAll(void *object, u32 color) {
    Nsbmd *nsbmd = object;

    NNS_G3dMdlSetMdlEmiAll(nsbmd->mResMdl, color);
}

void func_02084968(void *object, u32 polygonId, u32 light, u32 color) {
    Nsbmd *nsbmd = object;

    NNS_G3dMdlSetMdlPolygonIDAll(nsbmd->mResMdl, polygonId);
    NNS_G3dMdlSetMdlLightEnableFlagAll(nsbmd->mResMdl, light);
    NNS_G3dMdlSetMdlEmiAll(nsbmd->mResMdl, color);
}

void SetNsbmdCullModeAll(void *object, u32 cullMode) {
    Nsbmd *nsbmd = object;

    NNS_G3dMdlSetMdlCullModeAll(nsbmd->mResMdl, cullMode);
}

// Frees the texture and palette memory of the file of every entry of gResFileEntries; the entries stay in the list.
void ReleaseAllResFiles(void) {
    ResFileEntry *entry;

    for (entry = NNS_FndGetNextListObject(&gResFileEntries, NULL); entry != NULL;
         entry = NNS_FndGetNextListObject(&gResFileEntries, entry)) {
        if (entry->mFile != NULL) {
            NNS_G3dResDefaultRelease(entry->mFile);
        }
    }
}

void func_020846c0(void *heap) {
    u32 kartCount;
    u16 i;
    u16 j;

    kartCount = gRaceSetup->mKartCount;
    gKartEffectIdSetIndex = HeapAlloc(heap, kartCount * 2);
    gKartStarEffects = HeapAlloc(heap, kartCount * 12);
    data_0217ae94 = HeapAlloc(heap, kartCount * 4);
    data_0217ae74 = HeapAlloc(heap, kartCount * 4);
    for (i = 0; i < kartCount; i++) {
        for (j = 0; j < 3; j++) {
            gKartStarEffects[i].mEffects[j] = NULL;
        }
        data_0217ae94[i] = NULL;
        data_0217ae74[i] = NULL;
        if (i == gRaceSetup->mEntryIndex) {
            gKartEffectIdSetIndex[i] = 0;
        } else {
            gKartEffectIdSetIndex[i] = 1;
        }
    }
    data_0217ae6c = 0x7fff;
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_MANSION:
        case COURSE_ID_KOOPA:
            data_0217ae6c = 0x1667;
            break;
        case COURSE_ID_TOWN:
            data_0217ae6c = 0x2ff;
            break;
        case COURSE_ID_GARDEN:
            data_0217ae6c = 0x3e67;
            break;
    }
    gOtherKartFullPairCount = (gRaceSetup->mKartCount - 1) / 2;
    gOtherKartOddCount = (gRaceSetup->mKartCount - 1) % 2;
    data_02165948 = 0x1000;
    switch (gRaceSetup->mEngineIndex) {
        case 0:
            data_02165948 = 0xb33;
            break;
        case 1:
            data_02165948 = 0xd9a;
            break;
    }
}

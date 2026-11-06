#include "code_02012b30.h"
#include "code_02010804.h"
#include "code_02010c84.h"
#include "code_0200fe74.h"
#include "code_020108bc.h"
#include "code_0214a748.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "code_020107e4.h"
#include "code_02010878.h"
#include "code_02010998.h"
#include "code_020109ac.h"
#include "code_02013730.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_02161000.h"
#include "registers.h"
#include "code_02147954.h"

// Returns the texture block of a model or texture file, or NULL when the file has none.
NNSG3dResTex *NNS_G3dGetTex(NNSG3dResFileHeader *file) {
    u32 *blocks;

    blocks = OFFSET_PTR(u32, file, file->mHeaderSize);
    if (file->mDataBlocks == 1) {
        if (file->mSigVal == 0x30585442) {
            return OFFSET_PTR(NNSG3dResTex, file, blocks[0]);
        }
        return 0;
    }
    return OFFSET_PTR(NNSG3dResTex, file, blocks[1]);
}

// Sets the diffuse color of one material.
void NNS_G3dMdlSetMdlDiff(NNSG3dResMdl *mdl, u32 matId, u32 color) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mDiffAmb = (data->mDiffAmb & -0x8000) | color;
}

// Sets the ambient color of one material.
void NNS_G3dMdlSetMdlAmb(NNSG3dResMdl *mdl, u32 matId, u32 color) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mDiffAmb = (data->mDiffAmb & 0x8000ffff) | (color << 16);
}

// Sets the specular color of one material.
void NNS_G3dMdlSetMdlSpec(NNSG3dResMdl *mdl, u32 matId, u32 color) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mSpecEmi = (data->mSpecEmi & -0x8000) | color;
}

// Sets the emission color of one material.
void NNS_G3dMdlSetMdlEmi(NNSG3dResMdl *mdl, u32 matId, u32 color) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mSpecEmi = (data->mSpecEmi & 0x8000ffff) | (color << 16);
}

// Sets the light enable mask of one material.
void NNS_G3dMdlSetMdlLightEnableFlag(NNSG3dResMdl *mdl, u32 matId, u32 light) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mPolyAttr = (data->mPolyAttr & ~0xf) | light;
}

// Sets the polygon mode of one material.
void NNS_G3dMdlSetMdlPolygonMode(NNSG3dResMdl *mdl, u32 matId, u32 polyMode) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mPolyAttr = (data->mPolyAttr & ~0x30) | (polyMode << 4);
}

// Sets the cull mode of one material.
void NNS_G3dMdlSetMdlCullMode(NNSG3dResMdl *mdl, u32 matId, u32 cullMode) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mPolyAttr = (data->mPolyAttr & ~0xc0) | (cullMode << 6);
}

// Sets the polygon ID of one material.
void NNS_G3dMdlSetMdlPolygonID(NNSG3dResMdl *mdl, u32 matId, u32 polygonId) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mPolyAttr = (data->mPolyAttr & ~0x3f000000) | (polygonId << 24);
}

// Sets the alpha of one material.
void NNS_G3dMdlSetMdlAlpha(NNSG3dResMdl *mdl, u32 matId, u32 alpha) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    data->mPolyAttr = (data->mPolyAttr & ~0x1f0000) | (alpha << 16);
}

// Turns fog on or off for one material.
void NNS_G3dMdlSetMdlFogEnableFlag(NNSG3dResMdl *mdl, u32 matId, s32 flag) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    if (flag != 0) {
        data->mPolyAttr |= 0x8000;
    } else {
        data->mPolyAttr &= ~0x8000;
    }
}

// Turns the depth update of translucent polygons on or off for one material.
void NNS_G3dMdlSetMdlXLDepthUpdate(NNSG3dResMdl *mdl, u32 matId, s32 flag) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    if (flag != 0) {
        data->mPolyAttr |= 0x800;
    } else {
        data->mPolyAttr &= ~0x800;
    }
}

// Returns the cull mode of one material.
u32 NNS_G3dMdlGetMdlCullMode(NNSG3dResMdl *mdl, u32 matId) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    return (data->mPolyAttr & 0xc0) >> 6;
}

// Returns the polygon ID of one material.
u32 NNS_G3dMdlGetMdlPolygonID(NNSG3dResMdl *mdl, u32 matId) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    return (data->mPolyAttr & 0x3f000000) >> 24;
}

// Returns the alpha of one material.
u32 NNS_G3dMdlGetMdlAlpha(NNSG3dResMdl *mdl, u32 matId) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    return (data->mPolyAttr & 0x1f0000) >> 16;
}

// Returns whether fog is on for one material.
u32 NNS_G3dMdlGetMdlFogEnableFlag(NNSG3dResMdl *mdl, u32 matId) {
    NNSG3dResMat *mat;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *data;

    mat = OFFSET_PTR(NNSG3dResMat, mdl, mdl->mOfsMat);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &mat->mDict, mat->mDict.mOfsEntry);
    data = OFFSET_PTR(NNSG3dResMatData, mat, *(u32 *) (entries->mData + entries->mSizeUnit * matId));
    return data->mPolyAttr & 0x8000;
}

// Sets the diffuse color of every material.
void NNS_G3dMdlSetMdlDiffAll(NNSG3dResMdl *mdl, u32 color) {
    u32 i;

    for (i = 0; i < mdl->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlDiff(mdl, i, color);
    }
}

// Sets the ambient color of every material.
void NNS_G3dMdlSetMdlAmbAll(NNSG3dResMdl *mdl, u32 color) {
    u32 i;

    for (i = 0; i < mdl->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlAmb(mdl, i, color);
    }
}

// Sets the specular color of every material.
void NNS_G3dMdlSetMdlSpecAll(NNSG3dResMdl *mdl, u32 color) {
    u32 i;

    for (i = 0; i < mdl->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlSpec(mdl, i, color);
    }
}

// Sets the emission color of every material.
void NNS_G3dMdlSetMdlEmiAll(NNSG3dResMdl *mdl, u32 color) {
    u32 i;

    for (i = 0; i < mdl->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlEmi(mdl, i, color);
    }
}

// Sets the light enable mask of every material.
void NNS_G3dMdlSetMdlLightEnableFlagAll(NNSG3dResMdl *mdl, u32 light) {
    u32 i;

    for (i = 0; i < mdl->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlLightEnableFlag(mdl, i, light);
    }
}

// Sets the polygon mode of every material.
void NNS_G3dMdlSetMdlPolygonModeAll(NNSG3dResMdl *mdl, u32 polyMode) {
    u32 i;

    for (i = 0; i < mdl->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlPolygonMode(mdl, i, polyMode);
    }
}

// Sets the cull mode of every material.
void NNS_G3dMdlSetMdlCullModeAll(NNSG3dResMdl *mdl, u32 cullMode) {
    u32 i;

    for (i = 0; i < mdl->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlCullMode(mdl, i, cullMode);
    }
}

// Sets the polygon ID of every material.
void NNS_G3dMdlSetMdlPolygonIDAll(NNSG3dResMdl *mdl, u32 polygonId) {
    u32 i;

    for (i = 0; i < mdl->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlPolygonID(mdl, i, polygonId);
    }
}

// Sets the alpha of every material.
void NNS_G3dMdlSetMdlAlphaAll(NNSG3dResMdl *mdl, u32 alpha) {
    u32 i;

    for (i = 0; i < mdl->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlAlpha(mdl, i, alpha);
    }
}

// Sets the fog flag of every material.
void NNS_G3dMdlSetMdlFogEnableFlagAll(NNSG3dResMdl *mdl, u32 flag) {
    u32 i;

    for (i = 0; i < mdl->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlFogEnableFlag(mdl, i, flag);
    }
}

// Sets the translucent depth update flag of every material.
void NNS_G3dMdlSetMdlXLDepthUpdateAll(NNSG3dResMdl *mdl, u32 flag) {
    u32 i;

    for (i = 0; i < mdl->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlXLDepthUpdate(mdl, i, flag);
    }
}

// Reads the current position and vector matrices back from the geometry engine; either pointer may be NULL.
void NNS_G3dGetCurrentMtx(MtxFx43 *pos, void *vec) {
    s32 clipMtx[16];

    func_01ff9234();
    reg_G3_MTX_MODE = 0;
    reg_G3_MTX_PUSH = 0;
    reg_G3_MTX_IDENTITY = 0;
    if (pos != 0) {
        while (G3X_GetClipMtx(clipMtx) != 0) {
        }
        MTX_Copy44To43_(clipMtx, pos);
    }
    if (vec != 0) {
        while (G3X_GetVectorMtx(vec) != 0) {
        }
    }
    reg_G3_MTX_POP = 1;
    reg_G3_MTX_MODE = 2;
}

// Initializes the geometry engine and the global state.
void NNS_G3dInit(void) {
    G3X_Init();
    NNS_G3dGlbInit();
    reg_G3X_GXSTAT = (reg_G3X_GXSTAT & ~0xc0000000) | 0x80000000;
}

// Allocates texture and palette memory for a model or texture file, loads them and binds them to the models. The key
// variables first hold the required size.
s32 NNS_G3dResDefaultSetup(NNSG3dResFileHeader *file) {
    s32 texOk;
    NNSG3dResTex *tex;
    u32 texKey;
    u32 tex4x4Key;
    u32 plttKey;
    s32 tex4x4Ok;
    s32 plttOk;
    NNSG3dResMdlSet *mdlSet;

    switch (file->mSigVal) {
        case 0x30444d42:
        case 0x30585442:
            texOk = 1;
            tex4x4Ok = 1;
            plttOk = 1;
            tex = NNS_G3dGetTex(file);
            if (tex != 0) {
                texKey = NNS_G3dTexGetRequiredSize(tex);
                tex4x4Key = NNS_G3dTex4x4GetRequiredSize(tex);
                plttKey = NNS_G3dPlttGetRequiredSize(tex);
                if (texKey != 0) {
                    texKey = data_021619ec(texKey, 0, 0);
                    if (texKey == 0) {
                        texOk = 0;
                    }
                } else {
                    texKey = 0;
                }
                if (tex4x4Key != 0) {
                    tex4x4Key = data_021619ec(tex4x4Key, 1, 0);
                    if (tex4x4Key == 0) {
                        tex4x4Ok = 0;
                    }
                } else {
                    tex4x4Key = 0;
                }
                if (plttKey != 0) {
                    plttKey = data_021619f4(plttKey, tex->mTex4x4Info.mFlag & 0x8000, 0);
                    if (plttKey == 0) {
                        plttOk = 0;
                    }
                } else {
                    plttKey = 0;
                }
                if (texOk == 0 || tex4x4Ok == 0 || plttOk == 0) {
                    data_021619f8((void *) plttKey);
                    data_021619f0((void *) tex4x4Key);
                    data_021619f0((void *) texKey);
                    return 0;
                }
                NNS_G3dTexSetTexKey(tex, texKey, tex4x4Key);
                NNS_G3dPlttSetPlttKey(tex, plttKey);
                NNS_G3dTexLoad(tex, 1);
                NNS_G3dPlttLoad(tex, 1);
            }
            if (file->mSigVal == 0x30444d42) {
                mdlSet = NNS_G3dGetMdlSet(file);
                if (tex != 0) {
                    NNS_G3dBindMdlSet(mdlSet, tex);
                }
            }
            return 1;
        case 0x30415642:
        case 0x30414d42:
        case 0x30414342:
        case 0x30415442:
        case 0x30505442:
            return 1;
        default:
            return 0;
    }
}

// Frees the texture and palette memory of a model or texture file and releases the models bound to it.
void NNS_G3dResDefaultRelease(NNSG3dResFileHeader *file) {
    NNSG3dResMdlSet *mdlSet;
    NNSG3dResTex *tex;
    NNSG3dTexKey texKey;
    NNSG3dTexKey tex4x4Key;
    u32 plttKey;

    switch (file->mSigVal) {
        case 0x30415642:
        case 0x30414d42:
        case 0x30414342:
        case 0x30415442:
        case 0x30505442:
            return;
        case 0x30444d42:
            mdlSet = NNS_G3dGetMdlSet(file);
            if (NNS_G3dGetTex(file) != 0) {
                NNS_G3dReleaseMdlSet(mdlSet);
            }
            break;
        case 0x30585442:
            break;
        default:
            return;
    }
    tex = NNS_G3dGetTex(file);
    if (tex == 0) {
        return;
    }
    plttKey = NNS_G3dPlttReleasePlttKey(tex);
    NNS_G3dTexReleaseTexKey(tex, &texKey, &tex4x4Key);
    if (plttKey != 0) {
        data_021619f8((void *) plttKey);
    }
    if (tex4x4Key != 0) {
        data_021619f0((void *) tex4x4Key);
    }
    if (texKey != 0) {
        data_021619f0((void *) texKey);
    }
}

#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02036820.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0205e090.h"
#include "code_020109ac.h"
#include "code_02010878.h"
#include "code_02010998.h"
#include "code_02013730.h"
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
void AddResFileEntry(ResFileEntry *a, NNSG3dResFileHeader *b, NNSG3dResFileHeader *c) {
    NNSG3dResMdlSet *v1;
    NNSG3dResTex *v2;

    v1 = NNS_G3dGetMdlSet(b);
    v2 = NNS_G3dGetTex(c);
    a->mTexture = NULL;
    a->mFile = NULL;
    NNS_FndAppendListObject(&gResFileEntries, a);
    a->mFile = b;
    if (v2 == NULL) {
        return;
    }
    v2->mTexInfo.mFlag &= ~1;
    v2->mTex4x4Info.mFlag &= ~1;
    v2->mTexInfo.mVramKey = 0;
    v2->mTex4x4Info.mVramKey = 0;
    v2->mPlttInfo.mFlag &= ~1;
    v2->mPlttInfo.mVramKey = 0;
    UploadResTexture(v2);
    a->mTexture = v2;
    if (v1->mHeader.mSignature == 0x304c444d) {
        NNS_G3dBindMdlSet(v1, v2);
    }
}

// Gets VRAM for the texture, 4x4 texture and palette blocks and loads them; 0 if loaded already or a block fails.
u32 UploadResTexture(NNSG3dResTex *a) {
    u32 v1;
    u32 v0;
    u32 v2;
    u32 v3 = 1;
    u32 f0 = 1;
    u32 f1 = 1;
    u32 f2 = 1;

    if ((a->mTexInfo.mFlag & 1) != 0 || (a->mTex4x4Info.mFlag & 1) != 0 || (a->mPlttInfo.mFlag & 1) != 0) {
        v3 = 0;
    } else {
        v0 = NNS_G3dTexGetRequiredSize(a);
        v1 = NNS_G3dTex4x4GetRequiredSize(a);
        v2 = NNS_G3dPlttGetRequiredSize(a);
        if (v0 != 0) {
            v0 = data_021619ec(v0, 0, 0);
            if (v0 == 0) {
                f0 = 0;
            }
        } else {
            v0 = 0;
        }
        if (v1 != 0) {
            v1 = data_021619ec(v1, 1, 0);
            if (v1 == 0) {
                f1 = 0;
            }
        } else {
            v1 = 0;
        }
        if (v2 != 0) {
            v2 = data_021619f4(v2, a->mTex4x4Info.mFlag & 0x8000, 0);
            if (v2 == 0) {
                f2 = 0;
            }
        } else {
            v2 = 0;
        }
        if (f0 == 0 || f1 == 0 || f2 == 0) {
            data_021619f8((void *) v2);
            data_021619f0((void *) v1);
            data_021619f0((void *) v0);
            return 0;
        }
        NNS_G3dTexSetTexKey(a, v0, v1);
        NNS_G3dPlttSetPlttKey(a, v2);
        NNS_G3dTexLoad(a, 1);
        NNS_G3dPlttLoad(a, 1);
    }
    return v3;
}

// With c non-zero and scene number 2 it swaps cull modes 1 and 2 when byte 0x57 of the game record is set.
void InitNsbmdRenderObj(Nsbmd *a, NNSG3dResMdl *b, u32 c) {
    u32 i;
    NNSG3dResMdl *p;

    if (c != 0 && GetCurrentSceneNumber() == 2) {
        a->mCullModesSwapped = gRaceSetup->mMirrorMode;
    } else {
        a->mCullModesSwapped = 0;
    }
    if (b->mInfo.mNumMat == 1 && b->mInfo.mNumShp == 1) {
        a->mDrawKind = 1;
    } else {
        a->mDrawKind = 0;
    }
    NNS_G3dRenderObjInit((NNSG3dRenderObj *) a, b);
    if (a->mCullModesSwapped != 0) {
        p = a->mResMdl;
        for (i = 0; i < p->mInfo.mNumMat; i++) {
            if (NNS_G3dMdlGetMdlCullMode(p, i) == 1) {
                NNS_G3dMdlSetMdlCullMode(p, i, 2);
            } else if (NNS_G3dMdlGetMdlCullMode(p, i) == 2) {
                NNS_G3dMdlSetMdlCullMode(p, i, 1);
            }
        }
    }
}

void func_02084f68(Nsbmd *a) {
    u32 i;
    NNSG3dResMdl *p;

    p = a->mResMdl;
    for (i = 0; i < p->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlCullMode(p, i, 1);
    }
}

void func_02084f20(Nsbmd *a) {
    u32 i;
    NNSG3dResMdl *p;

    p = a->mResMdl;
    for (i = 0; i < p->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlCullMode(p, i, 2);
    }
}

void func_02084f10(Nsbmd *a, NNSG3dResMdl *b) {
    InitNsbmdRenderObj(a, b, 1);
}

NNSG3dResMdl *InitNsbmd(void *a, NNSG3dResFileHeader *b) {
    Nsbmd *o = a;

    NNSG3dResMdlSet *v1;
    NNSG3dResTex *v2;
    u8 *v3;

    v1 = NNS_G3dGetMdlSet(b);
    v2 = NNS_G3dGetTex(b);
    o->mResFileEntry.mTexture = NULL;
    o->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&gResFileEntries, &o->mResFileEntry);
    o->mResFileEntry.mFile = b;
    if (v2 != NULL) {
        v2->mTexInfo.mFlag &= ~1;
        v2->mTex4x4Info.mFlag &= ~1;
        v2->mTexInfo.mVramKey = 0;
        v2->mTex4x4Info.mVramKey = 0;
        v2->mPlttInfo.mFlag &= ~1;
        v2->mPlttInfo.mVramKey = 0;
        UploadResTexture(v2);
        o->mResFileEntry.mTexture = v2;
        if (v1->mHeader.mSignature == 0x304c444d) {
            NNS_G3dBindMdlSet(v1, v2);
        }
    }
    v3 = (u8 *) NNS_G3dGetMdlSet(b);
    InitNsbmdRenderObj(o, (NNSG3dResMdl *) (v3 + *(u32 *) (v3 + *(u16 *) (v3 + 14) + 12)), 1);
    return o->mResMdl;
}

NNSG3dResMdl *InitNsbmdWithTextureFile(Nsbmd *a, NNSG3dResFileHeader *b, NNSG3dResFileHeader *c) {
    Nsbmd *o = a;

    NNSG3dResMdlSet *v1;
    NNSG3dResTex *v2;
    u8 *v3;

    v1 = NNS_G3dGetMdlSet(b);
    v2 = NNS_G3dGetTex(c);
    o->mResFileEntry.mTexture = NULL;
    o->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&gResFileEntries, &o->mResFileEntry);
    o->mResFileEntry.mFile = b;
    if (v2 != NULL) {
        v2->mTexInfo.mFlag &= ~1;
        v2->mTex4x4Info.mFlag &= ~1;
        v2->mTexInfo.mVramKey = 0;
        v2->mTex4x4Info.mVramKey = 0;
        v2->mPlttInfo.mFlag &= ~1;
        v2->mPlttInfo.mVramKey = 0;
        UploadResTexture(v2);
        o->mResFileEntry.mTexture = v2;
        if (v1->mHeader.mSignature == 0x304c444d) {
            NNS_G3dBindMdlSet(v1, v2);
        }
    }
    v3 = (u8 *) NNS_G3dGetMdlSet(b);
    InitNsbmdRenderObj(o, (NNSG3dResMdl *) (v3 + *(u32 *) (v3 + *(u16 *) (v3 + 14) + 12)), 1);
    return o->mResMdl;
}

NNSG3dResMdl *InitNsbmdWithoutCullSwap(Nsbmd *a, NNSG3dResFileHeader *b) {
    NNSG3dResMdlSet *v1;
    NNSG3dResTex *v2;
    u8 *v3;

    v1 = NNS_G3dGetMdlSet(b);
    v2 = NNS_G3dGetTex(b);
    a->mResFileEntry.mTexture = NULL;
    a->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&gResFileEntries, &a->mResFileEntry);
    a->mResFileEntry.mFile = b;
    if (v2 != NULL) {
        v2->mTexInfo.mFlag &= ~1;
        v2->mTex4x4Info.mFlag &= ~1;
        v2->mTexInfo.mVramKey = 0;
        v2->mTex4x4Info.mVramKey = 0;
        v2->mPlttInfo.mFlag &= ~1;
        v2->mPlttInfo.mVramKey = 0;
        UploadResTexture(v2);
        a->mResFileEntry.mTexture = v2;
        if (v1->mHeader.mSignature == 0x304c444d) {
            NNS_G3dBindMdlSet(v1, v2);
        }
    }
    v3 = (u8 *) NNS_G3dGetMdlSet(b);
    InitNsbmdRenderObj(a, (NNSG3dResMdl *) (v3 + *(u32 *) (v3 + *(u16 *) (v3 + 14) + 12)), 0);
    return a->mResMdl;
}

// Fills the object from model file c and texture file d, then keeps a heap copy of the texture block's header part.
NNSG3dResMdl *InitNsbmdWithTextureInfoCopy(void *a, Nsbmd *b, NNSG3dResFileHeader *c, NNSG3dResFileHeader *d) {
    NNSG3dResMdlSet *v1;
    NNSG3dResTex *v2;
    u8 *v3;
    NNSG3dResTex *m;
    u32 v4;
    ResFileEntry *e;
    NNSG3dResMdl *q;

    v1 = NNS_G3dGetMdlSet(c);
    v2 = NNS_G3dGetTex(d);
    b->mResFileEntry.mTexture = NULL;
    b->mResFileEntry.mFile = NULL;
    NNS_FndAppendListObject(&gResFileEntries, &b->mResFileEntry);
    b->mResFileEntry.mFile = c;
    if (v2 != NULL) {
        v2->mTexInfo.mFlag &= ~1;
        v2->mTex4x4Info.mFlag &= ~1;
        v2->mTexInfo.mVramKey = 0;
        v2->mTex4x4Info.mVramKey = 0;
        v2->mPlttInfo.mFlag &= ~1;
        v2->mPlttInfo.mVramKey = 0;
        UploadResTexture(v2);
        b->mResFileEntry.mTexture = v2;
        if (v1->mHeader.mSignature == 0x304c444d) {
            NNS_G3dBindMdlSet(v1, v2);
        }
    }
    v3 = (u8 *) NNS_G3dGetMdlSet(c);
    InitNsbmdRenderObj(b, (NNSG3dResMdl *) (v3 + *(u32 *) (v3 + *(u16 *) (v3 + 14) + 12)), 1);
    e = &b->mResFileEntry;
    m = e->mTexture;
    q = b->mResMdl;
    if (m != NULL) {
        v4 = m->mTexInfo.mOfsTex;
        e->mTexture = HeapAlloc(a, v4);
        MI_CpuCopy8(m, e->mTexture, v4);
    }
    return q;
}

void func_02084ad8(void *a, u8 b) {
    Nsbmd *o = a;

    NNSG3dResMdl *p = o->mResMdl;
    u32 n;

    if (o->mCullModesSwapped != 0) {
        n = 2;
    } else {
        n = 1;
    }
    NNS_G3dMdlSetMdlPolygonID(p, 0, 0);
    NNS_G3dMdlSetMdlCullMode(p, 0, n);
    NNS_G3dMdlSetMdlAlpha(p, 0, b);
}

void func_02084a88(void *a, u8 b, u8 c) {
    Nsbmd *o = a;

    NNSG3dResMdl *p = o->mResMdl;
    u32 n;

    if (o->mCullModesSwapped != 0) {
        n = 1;
    } else {
        n = 2;
    }
    NNS_G3dMdlSetMdlPolygonID(p, 0, c);
    NNS_G3dMdlSetMdlCullMode(p, 0, n);
    NNS_G3dMdlSetMdlAlpha(p, 0, b);
}

// Draws with matrix b; when c is not NULL its three words (a scale, 0x1000 = 1.0) are sent first.
void DrawNsbmdWithMatrix(void *a, MtxFx43 *b, u32 *c) {
    s32 v0 = 30;
    u32 v[3];

    func_01ff9048(20, &v0, 1);
    func_01ff9048(25, b, 12);
    if (c != NULL) {
        u32 z = c[2];
        u32 y = c[1];
        u32 x = c[0];
        v[0] = x;
        v[1] = y;
        v[2] = z;
        func_01ff9048(27, &v, 3);
    }
    data_02155a20[((Nsbmd *) a)->mDrawKind](a);
}

void DrawNsbmd(void *a) {
    Nsbmd *o = a;

    data_02155a20[o->mDrawKind](o);
}

void SetNsbmdPolygonIdAll(void *a, u32 b) {
    Nsbmd *o = a;

    NNS_G3dMdlSetMdlPolygonIDAll(o->mResMdl, b);
}

void SetNsbmdLightEnableFlagAll(void *a, u32 b) {
    Nsbmd *o = a;

    NNS_G3dMdlSetMdlLightEnableFlagAll(o->mResMdl, b);
}

void SetNsbmdEmiAll(void *a, u32 b) {
    Nsbmd *o = a;

    NNS_G3dMdlSetMdlEmiAll(o->mResMdl, b);
}

void func_02084968(void *a, u32 b, u32 c, u32 d) {
    Nsbmd *o = a;

    NNS_G3dMdlSetMdlPolygonIDAll(o->mResMdl, b);
    NNS_G3dMdlSetMdlLightEnableFlagAll(o->mResMdl, c);
    NNS_G3dMdlSetMdlEmiAll(o->mResMdl, d);
}

void SetNsbmdCullModeAll(void *a, u32 b) {
    Nsbmd *o = a;

    NNS_G3dMdlSetMdlCullModeAll(o->mResMdl, b);
}

// Frees the texture and palette memory of the file of every entry of gResFileEntries; the entries stay in the list.
void ReleaseAllResFiles(void) {
    ResFileEntry *p;

    for (p = NNS_FndGetNextListObject(&gResFileEntries, NULL); p != NULL;
         p = NNS_FndGetNextListObject(&gResFileEntries, p)) {
        if (p->mFile != NULL) {
            NNS_G3dResDefaultRelease(p->mFile);
        }
    }
}

void func_020846c0(void *a) {
    u32 n;
    u16 i;
    u16 j;

    n = gRaceSetup->mKartCount;
    gKartEffectIdSetIndex = HeapAlloc(a, n * 2);
    gKartStarEffects = HeapAlloc(a, n * 12);
    data_0217ae94 = HeapAlloc(a, n * 4);
    data_0217ae74 = HeapAlloc(a, n * 4);
    for (i = 0; i < n; i++) {
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

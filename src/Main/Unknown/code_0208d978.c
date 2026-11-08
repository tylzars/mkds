#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0208b000.h"
#include "res_struct_accessor.h"
#include "Main/Unknown/code_020d2b78.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02012b30.h"
#include "code_0201750c.h"
#include "code_02147288.h"
#include "g3imm.h"
#include "code_020172d0.h"
#include "code_021471bc.h"
#include "registers.h"

void UpdatePosStrip(PosStrip *a) {
    PosStripPoint *p;
    PosStripPoint *q;
    PosStripPoint *r;
    u32 f;

    p = NNS_FndGetNextListObject(&a->mPoints, NULL);
    if (p != NULL) {
        do {
            q = NNS_FndGetNextListObject(&a->mPoints, p);
            p->mSinceAddedFrames = p->mSinceAddedFrames + 1;
            if (p->mSinceAddedFrames > gPosStripMaxAgeFrames) {
                f = 1;
            } else {
                p->mHeight = p->mHeight - gPosStripHeightDecreasePerFrame;
                f = 0;
            }
            if (f != 0) {
                NNS_FndRemoveListObject(&a->mPoints, p);
                NNS_FndAppendListObject(&gPosStrips->mLists[2], p);
                if (q == NULL) {
                    break;
                }
                p = q;
            }
            p = NNS_FndGetNextListObject(&a->mPoints, p);
        } while (p != NULL);
    }
    if (a->mStopped == 0) {
        r = NNS_FndGetNthListObject(&gPosStrips->mLists[2], 0);
        NNS_FndRemoveListObject(&gPosStrips->mLists[2], r);
        NNS_FndAppendListObject(&a->mPoints, r);
        gSetPosStripPointFunction(r, a);
        return;
    }
    if (a->mPoints.mCount != 0) {
        return;
    }
    NNS_FndRemoveListObject(&gPosStrips->mLists[0], a);
    NNS_FndAppendListObject(&gPosStrips->mLists[1], a);
}

void DrawPosStripQuad(const MtxFx43 *a, PosStripPoint *b, PosStripPoint *c, PosStripTexture *d) {
    MtxFx43 m;
    MtxFx43 n;

    MTX_Scale43_(&m, 0x1000, b->mHeight, 0x1000);
    MTX_Scale43_(&n, 0x1000, c->mHeight, 0x1000);
    m.mUnk_00[3].x = b->mPos.x;
    m.mUnk_00[3].y = b->mPos.y;
    m.mUnk_00[3].z = b->mPos.z;
    n.mUnk_00[3].x = c->mPos.x;
    n.mUnk_00[3].y = c->mPos.y;
    n.mUnk_00[3].z = c->mPos.z;
    MTX_Concat43(&m, a, &m);
    MTX_Concat43(&n, a, &n);
    reg_G3_BEGIN_VTXS = 1;
    G3_LoadMtx43(&m);
    reg_G3_TEXCOORD = (u16) ((d->mUnk_1c << 8) >> 16);
    reg_G3_VTX_10 = 0x10000;
    reg_G3_TEXCOORD = 0;
    reg_G3_VTX_10 = 0xf0000;
    G3_LoadMtx43(&n);
    reg_G3_TEXCOORD = (u16) ((d->mUnk_20 << 8) >> 16) << 16;
    reg_G3_VTX_10 = 0xf0000;
    reg_G3_TEXCOORD = (u16) ((d->mUnk_1c << 8) >> 16) | (u16) ((d->mUnk_20 << 8) >> 16) << 16;
    reg_G3_VTX_10 = 0x10000;
    reg_G3_END_VTXS = 0;
}

void func_0208e808(s32 a) {
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        gPosStripDrawEnabled = a;
    }
}

void InitModelEffects(void *heap) {
    u16 i;
    void *c;
    void *d;
    void *e;
    void *f;
    ModelEffectKind *x;
    ModelEffectKind *y;

    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        heap = data_0217aa10->mExpHeap;
    }
    gModelEffects = HeapAlloc(heap, 0x60);
    NNS_FndInitList(&gModelEffects->mActiveList, 0);
    for (i = 0; i < 5; i++) {
        NNS_FndInitList(&gModelEffects->mFreeLists[i], 0);
    }
    x = gModelEffectKinds;
    y = &data_021661b8;
    if (gRaceSetup->mMode == 5) {
        x->mObjectCount = 6;
        y->mObjectCount = 4;
    } else {
        x->mObjectCount = 3;
        y->mObjectCount = 1;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        x->mObjectCount = 0x14;
    }
    SetupWaterEfctKindRow(&data_021661e4, 1);
    SetupWaterEfctKindRow(&data_0216623c, 2);
    SetupBkWaveKind();
    InitModelEffectObjects(heap);
    c = FindMainRaceOrMainEffectFile(data_02166298);
    d = FindMainRaceOrMainEffectFile(data_021662b8);
    e = FindMainRaceOrMainEffectFile(data_021662d8);
    f = FindMainRaceOrMainEffectFile(data_021662f8);
    SetupModelEffectKind(heap, 0, c, d, e, f);
    c = FindMainRaceOrMainEffectFile(data_02166318);
    d = FindMainRaceOrMainEffectFile(data_0216633c);
    e = FindMainRaceOrMainEffectFile(data_02166360);
    f = FindMainRaceOrMainEffectFile(data_02166384);
    SetupModelEffectKind(heap, 1, c, d, e, f);
    SetupModelEffectKind(heap, 2, GetWaterEfctNsbmdFile(), GetWaterEfctNsbcaFile(), GetWaterEfctNsbmaFile(), NULL);
    SetupModelEffectKind(heap, 4, GetWaterEfctNsbmdFile(), GetWaterEfctNsbcaFile(), GetWaterEfctNsbmaFile(), NULL);
    if (gRaceSetup->mCourseId == COURSE_ID_OLD_HYUDORO_64) {
        SetupModelEffectKind(heap, 3, GetWaterEfctNsbmdFile(), FindCourseFile(data_021663a8),
                             FindCourseFile(data_021663c0), NULL);
    }
    gModelEffects->mNextPolygonId = 10;
}

// Starts a pooled object of the given kind at position; startEffects goes to its start function. NULL if none is free.
ModelEffect *StartModelEffect(u32 kind, const Vec3 *position, s32 startEffects) {
    ModelEffect *p;

    p = NNS_FndGetNthListObject(&gModelEffects->mFreeLists[kind], 0);
    if (p != NULL) {
        NNS_FndRemoveListObject(&gModelEffects->mFreeLists[kind], p);
        p->mFinished = 0;
        p->mPos = *position;
        p->mSinceStartFrames = 0;
        p->mFinishFrameCount = 0;
        p->mPolygonId = gModelEffects->mNextPolygonId;
        p->mVisible = 1;
        p->mStart(p, startEffects);
        NNS_FndAppendListObject(&gModelEffects->mActiveList, p);
        gModelEffects->mNextPolygonId++;
        if (gModelEffects->mNextPolygonId > 0xd) {
            gModelEffects->mNextPolygonId = 10;
        }
    }
    return p;
}

void UpdateModelEffects(void) {
    ModelEffect *p;

    p = NNS_FndGetNextListObject(&gModelEffects->mActiveList, NULL);
    if (p == NULL) {
        return;
    }
    do {
        p->mUpdate(p);
        p->mSinceStartFrames = p->mSinceStartFrames + 1;
        if (p->mFinished == 1) {
            NNS_FndRemoveListObject(&gModelEffects->mActiveList, p);
            NNS_FndAppendListObject(&gModelEffects->mFreeLists[p->mKind], p);
        }
        p = NNS_FndGetNextListObject(&gModelEffects->mActiveList, p);
    } while (p != NULL);
}

void DrawModelEffects(void) {
    MtxFx43 m;
    ModelEffect *p;

    MTX_Identity43_(&m);
    p = NNS_FndGetNextListObject(&gModelEffects->mActiveList, NULL);
    if (p == NULL) {
        return;
    }
    do {
        if (p->mVisible != 0) {
            m.mUnk_00[3].x = p->mPos.x >> 4;
            m.mUnk_00[3].y = p->mPos.y >> 4;
            m.mUnk_00[3].z = p->mPos.z >> 4;
            SetNsbmdPolygonIdAll(&p->mNsbmd, p->mPolygonId);
            DrawNsbmdWithMatrix(&p->mNsbmd, &m, (u32 *) p->mScale);
        }
        p = NNS_FndGetNextListObject(&gModelEffects->mActiveList, p);
    } while (p != NULL);
}

// Row kindRow gets objectCount objects only when the water_efct model exists; its flags say which animations exist.
void SetupWaterEfctKindRow(ModelEffectKind *kindRow, s32 objectCount) {
    void *x;
    void *y;
    void *z;

    x = GetWaterEfctNsbmdFile();
    data_0217b07c = 0;
    if (x != 0) {
        y = GetWaterEfctNsbcaFile();
        z = GetWaterEfctNsbmaFile();
        kindRow->mObjectCount = objectCount;
        if (y != 0) {
            kindRow->mUseNsbca = TRUE;
        } else {
            kindRow->mUseNsbca = FALSE;
        }
        if (z != 0) {
            kindRow->mUseNsbma = TRUE;
        } else {
            kindRow->mUseNsbma = FALSE;
        }
    } else {
        kindRow->mObjectCount = 0;
        kindRow->mUseNsbca = FALSE;
        kindRow->mUseNsbma = FALSE;
        gKind2EffectIds[0] = -1;
        gKind2EffectIds[1] = -1;
    }
}

// Row 3 gets one object only when the water_efct model exists; its animation flags say which bk_wave files exist.
void SetupBkWaveKind(void) {
    ModelEffectKind *e;
    void *x;
    void *y;

    e = &data_02166210;
    if (GetWaterEfctNsbmdFile() != 0) {
        x = FindCourseFile(data_02166268);
        y = FindCourseFile(data_02166280);
        e->mObjectCount = 1;
        if (x != NULL) {
            e->mUseNsbca = TRUE;
        } else {
            e->mUseNsbca = FALSE;
        }
        if (y != NULL) {
            e->mUseNsbma = TRUE;
        } else {
            e->mUseNsbma = FALSE;
        }
    } else {
        e->mObjectCount = 0;
        e->mUseNsbca = FALSE;
        e->mUseNsbma = FALSE;
    }
}

void InitModelEffectObjects(void *heap) {
    u16 i;
    u16 j;
    ModelEffectKind *g;
    ModelEffect *p;
    s32 v;

    for (i = 0; i < 5; i++) {
        g = &gModelEffectKinds[i];
        if (g->mObjectCount == 0) {
            continue;
        }
        gModelEffects->mObjects[i] = HeapAlloc(heap, g->mObjectCount << 2);
        for (j = 0; j < g->mObjectCount; j++) {
            p = HeapAlloc(heap, g->mObjectSize);
            gModelEffects->mObjects[i][j] = p;
            if (g->mUseNsbca == FALSE) {
                p->mAnimations[0] = NULL;
            } else {
                p->mAnimations[0] = HeapAlloc(heap, 0x38);
            }
            if (g->mUseNsbma == FALSE) {
                p->mAnimations[1] = NULL;
            } else {
                p->mAnimations[1] = HeapAlloc(heap, 0x38);
            }
            if (g->mUseNsbta == 0) {
                p->mAnimations[2] = NULL;
            } else {
                p->mAnimations[2] = HeapAlloc(heap, 0x38);
            }
            p->mKind = i;
            p->mStart = g->mStart;
            p->mUpdate = g->mUpdate;
            NNS_FndAppendListObject(&gModelEffects->mFreeLists[i], p);
            if (i == 2) {
                v = gRaceSetup->mCourseId == COURSE_ID_OLD_KOOPA_AGB ? 0xb33 : 0x1000;
                p->mScale[0] = v;
                p->mScale[1] = v;
                p->mScale[2] = v;
            }
        }
    }
}

// Builds the model and animation objects of every pooled object of the kind from modelFile and the animation files.
void SetupModelEffectKind(void *heap, s32 kind, NNSG3dResFileHeader *modelFile, void *nsbcaFile, void *nsbmaFile,
                          void *nsbtaFile) {
    u16 i;
    u8 *t;
    ModelAnimation *o;
    NNSG3dResMdl *h;
    ModelEffect *p;
    ModelEffectKind *g;
    u32 k;

    g = &gModelEffectKinds[kind];
    k = 1;
    if (gRaceSetup->mCourseId == COURSE_ID_MANSION || gRaceSetup->mCourseId == COURSE_ID_RAINBOW) {
        k = 0;
    }
    if (g->mObjectCount == 0) {
        return;
    }
    if (kind != 3) {
        AddResFileEntry(&g->mResFileEntry, modelFile, modelFile);
    }
    if (kind == 2) {
        data_0217b07c = 1;
    }
    t = (u8 *) NNS_G3dGetMdlSet(modelFile);
    h = OFFSET_PTR(NNSG3dResMdl, t, *OFFSET_PTR(u32, t + *OFFSET_PTR(u16, t, 0xe), 0xc));
    for (i = 0; i < g->mObjectCount; i++) {
        p = gModelEffects->mObjects[kind][i];
        func_02084f10(&p->mNsbmd, h);
        NNS_G3dMdlSetMdlFogEnableFlagAll(p->mNsbmd.mResMdl, k);
        o = p->mAnimations[0];
        if (o != NULL) {
            if (nsbcaFile != NULL) {
                InitModelAnimation(0, o, &p->mNsbmd, 1, heap, modelFile);
                InitModelAnimationEntries(o, nsbcaFile, heap);
            } else {
                o->mAnmObjCount = 0;
            }
            if (kind == 2) {
                if (GetModelAnimationFrameCountFixed(p->mAnimations[0]) >> 12 == 0x20) {
                    gKind2EffectIds[0] = 0x37;
                    gKind2EffectIds[1] = 0x38;
                } else {
                    gKind2EffectIds[0] = 0x39;
                    gKind2EffectIds[1] = -1;
                }
            }
        }
        o = p->mAnimations[1];
        if (o != NULL) {
            if (nsbmaFile != NULL) {
                InitModelAnimation(4, o, &p->mNsbmd, 1, heap, modelFile);
                InitModelAnimationEntries(o, nsbmaFile, heap);
            } else {
                o->mAnmObjCount = 0;
            }
        }
        o = p->mAnimations[2];
        if (o != NULL) {
            if (nsbtaFile == NULL) {
                o->mAnmObjCount = 0;
            } else {
                InitModelAnimation(1, o, &p->mNsbmd, 1, heap, modelFile);
                InitModelAnimationEntries(o, nsbtaFile, heap);
            }
        }
    }
}

void StartModelEffectBombcore(ModelEffect *a, s32 b) {
    SetModelAnimation(a->mAnimations[0], 0);
    SetModelAnimation(a->mAnimations[1], 0);
    SetModelAnimation(a->mAnimations[2], 0);
    a->mScale[0] = 0xab8;
    a->mScale[1] = 0xab8;
    a->mScale[2] = 0xab8;
    if (b == 0) {
        return;
    }
    StartEffect(0x22, &a->mPos);
    StartEffect(1, &a->mPos);
    StartEffect(2, &a->mPos);
}

void UpdateModelEffectBombcore(ModelEffect *a) {
    if (a->mSinceStartFrames == 0x26) {
        StartEffect(3, &a->mPos);
        return;
    }
    if (a->mSinceStartFrames >= 0x37) {
        a->mFinished = 1;
        return;
    }
    AdvanceModelAnimation(a->mAnimations[0]);
    AdvanceModelAnimation(a->mAnimations[1]);
    AdvanceModelAnimation(a->mAnimations[2]);
}

void StartWaterEfctKind2(ModelEffect *a) {
    u32 x;

    x = (u32) (GetModelAnimationFrameCountFixed(a->mAnimations[0]) << 4) >> 16;
    SetModelAnimation(a->mAnimations[0], 0);
    a->mFinishFrameCount = x;
    if (a->mAnimations[1] != NULL) {
        SetModelAnimation(a->mAnimations[1], 0);
    }
}

void StartWaterEfctKind4(ModelEffect *a) {
    a->mScale[0] = 0x3d9a;
    a->mScale[1] = 0x3d9a;
    a->mScale[2] = 0x3d9a;
    SetModelAnimation(a->mAnimations[0], 0);
    a->mFinishFrameCount = 0x20;
    if (a->mAnimations[1] != NULL) {
        SetModelAnimation(a->mAnimations[1], 0);
    }
    StartEffect(0x424, &a->mPos);
    StartEffect(0x422, &a->mPos);
}

// Update of kinds 2 and 4: sets mFinished at mFinishFrameCount, else advances animations 0 and 1.
void UpdateWaterEfctKinds(ModelEffect *a) {
    if (a->mSinceStartFrames >= a->mFinishFrameCount) {
        a->mFinished = 1;
        return;
    }
    AdvanceModelAnimation(a->mAnimations[0]);
    if (a->mAnimations[1] != NULL) {
        AdvanceModelAnimation(a->mAnimations[1]);
    }
}

void StartModelEffectBkWave(ModelEffect *a, s32 b) {
    SetModelAnimation(a->mAnimations[0], 0);
    a->mScale[0] = 0x5800;
    a->mScale[1] = 0x5800;
    a->mScale[2] = 0x5800;
    a->mFinishFrameCount = 0x27;
    SetModelAnimation(a->mAnimations[1], 0);
    if (b == 0) {
        return;
    }
    StartEffect(0x40, &a->mPos);
    StartEffect(0x41, &a->mPos);
}

void UpdateModelEffectBkWave(ModelEffect *a) {
    if (a->mSinceStartFrames >= a->mFinishFrameCount) {
        a->mFinished = 1;
        return;
    }
    AdvanceModelAnimation(a->mAnimations[0]);
    AdvanceModelAnimation(a->mAnimations[1]);
}

void StartModelEffectBombcore2(ModelEffect *a, s32 b) {
    SetModelAnimation(a->mAnimations[0], 0);
    SetModelAnimation(a->mAnimations[1], 0);
    SetModelAnimation(a->mAnimations[2], 0);
    a->mScale[0] = 0x1000;
    a->mScale[1] = 0x1000;
    a->mScale[2] = 0x1000;
    if (b == 0) {
        return;
    }
    StartEffect(8, &a->mPos);
    StartEffect(9, &a->mPos);
    StartEffect(0xa, &a->mPos);
}

void UpdateModelEffectBombcore2(ModelEffect *a) {
    if (a->mSinceStartFrames >= 0x37) {
        a->mFinished = 1;
        return;
    }
    AdvanceModelAnimation(a->mAnimations[0]);
    AdvanceModelAnimation(a->mAnimations[1]);
    AdvanceModelAnimation(a->mAnimations[2]);
}

// Starts a kind 2 object at position when startModel is set, then the particle effects of gKind2EffectIds.
void func_0208d978(const Vec3 *position, s32 startModel) {
    ModelEffect *p;
    u16 i;

    if (gModelEffectKinds[2].mObjectCount == 0) {
        return;
    }
    i = 0;
    if (startModel != 0) {
        p = NNS_FndGetNthListObject(OFFSET_PTR(NNSFndList, gModelEffects->mFreeLists, 0x18), 0);
        if (p != NULL) {
            NNS_FndRemoveListObject(OFFSET_PTR(NNSFndList, gModelEffects->mFreeLists, 0x18), p);
            p->mFinished = 0;
            p->mPos = *position;
            p->mSinceStartFrames = 0;
            p->mFinishFrameCount = 0;
            p->mPolygonId = gModelEffects->mNextPolygonId;
            p->mVisible = 1;
            p->mStart(p, 0);
            NNS_FndAppendListObject(&gModelEffects->mActiveList, p);
            gModelEffects->mNextPolygonId++;
            if (gModelEffects->mNextPolygonId > 0xd) {
                gModelEffects->mNextPolygonId = 10;
            }
        }
    }
    do {
        if (gKind2EffectIds[i] >= 0) {
            StartEffect(gKind2EffectIds[i], position);
        }
        i++;
    } while (i < 2);
}

#include "Main/Unknown/code_02089d14.h"

#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02089d70.h"
#include "Main/Unknown/code_02089e10.h"
#include "registers.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/code_02089ecc.h"
#include "Main/Unknown/code_02089ef4.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02089fa0.h"
#include "Main/Unknown/code_02089f9c.h"
#include "Main/Unknown/code_02036820.h"
#include "ITCM/code_01ff8000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02010c84.h"
#include "code_02013740.h"
#include "code_02134398.h"
#include "code_02146cbc.h"
#include "g3imm.h"
#include "code_0214a748.h"
#include "code_021471bc.h"

void InitStemSets(void *a) {
    TimedQuad *p;

    gStemSets = HeapAlloc(a, 0x79c);
    InitStemSetArray(a);
    gStemSets->mShownIndex = 9;
    reg_G3_MTX_MODE = 0;
    G3i_OrthoW_(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x1000, 0x200, 1, &gStemSets->mOrthoMtx);
    p = &gStemSets->mTimedQuad;
    gStemSets->mTimedQuad.mTimer = 0;
    p->mUnk_02 = 0;
    p->mColor = 0x7fff;
    p->mEnabled = FALSE;
}

void InitNsbmdNsbcaNsbmaNsbtp(void *a, StemSet *b, const Unk02155ee8 *c, u16 d) {
    char s[0x80];
    void *n;
    u16 i;
    Nsbmd *h;
    Nsbmd *e;
    ModelAnimation *g;
    u16 j;
    Nsbmd *p;
    ModelAnimation *q;
    u16 l;
    u16 k;
    BOOL f;

    n = NULL;
    b->mNsbmdCount = c->mNsbmdCount;
    b->mNsbmds = NULL;
    b->mNsbcaNsbmaNsbtp[0] = b->mNsbcaNsbmaNsbtp[1] = b->mNsbcaNsbmaNsbtp[2] = NULL;
    f = FALSE;
    if (c->mNsbmdCount != 0) {
        b->mNsbmds = HeapAlloc(a, c->mNsbmdCount * 0x6c);
    }
    if (c->mNsbcaCount != 0) {
        b->mNsbcaNsbmaNsbtp[0] = HeapAlloc(a, c->mNsbcaCount * 0x38);
    }
    if (c->mNsbmaCount != 0) {
        b->mNsbcaNsbmaNsbtp[1] = HeapAlloc(a, c->mNsbmaCount * 0x38);
    }
    if (c->mNsbmdCount == 1 && c->mNsbtpCount > 1) {
        b->mNsbcaNsbmaNsbtp[2] = HeapAlloc(a, 0x38);
        f = TRUE;
    } else if (c->mNsbtpCount != 0) {
        b->mNsbcaNsbmaNsbtp[2] = HeapAlloc(a, c->mNsbtpCount * 0x38);
    }
    for (i = 0; i < c->mNsbmdCount; i++) {
        h = &b->mNsbmds[i];
        snprintf(s, 0x80, "%s.nsbmd", c->mStems[i]);
        n = FindSceneFile(s);
        InitNsbmdWithoutCullSwap(h, n);
    }
    for (j = 0; j < c->mNsbcaCount; j++) {
        e = &b->mNsbmds[j];
        g = &b->mNsbcaNsbmaNsbtp[0][j];
        snprintf(s, 0x80, "%s.nsbca", c->mStems[j]);
        InitModelAnimation(0, g, e, 1, a, NULL);
        InitModelAnimationEntries(g, FindSceneFile(s), a);
        SetModelAnimation(g, 0);
    }
    for (l = 0; l < c->mNsbmaCount; l++) {
        p = &b->mNsbmds[l];
        q = &b->mNsbcaNsbmaNsbtp[1][l];
        snprintf(s, 0x80, "%s.nsbma", c->mStems[l]);
        InitModelAnimation(4, q, p, 1, a, NULL);
        InitModelAnimationEntries(q, FindSceneFile(s), a);
        SetModelAnimation(q, 0);
    }
    if (f != FALSE) {
        g = b->mNsbcaNsbmaNsbtp[2];
        InitModelAnimation(2, g, b->mNsbmds, c->mNsbtpCount, a, n);
        for (k = 0; k < c->mNsbtpCount; k++) {
            snprintf(s, 0x80, "%s.nsbtp", c->mStems[k]);
            InitModelAnimationEntry(g, k, NNS_G3dGetTexPatAnmByIdx(NNS_G3dGetTexPatAnmSet(FindSceneFile(s)), 0), 0, a);
        }
        SetModelAnimation(g, 0);
    }
}

void InitStemSetArray(void *a) {
    s16 i;
    StemSet *p;
    StemSet *q;

    for (i = 0; i < 8; i++) {
        gStemSets->mSets[i] = NULL;
    }
    if (IsRaceAwardOrStaffRoll() != 0) {
        return;
    }
    for (i = 0; i <= 2; i++) {
        if (i == 2) {
            gStemSets->mSets[i] = HeapAlloc(a, 0x14);
            p = gStemSets->mSets[0];
            q = gStemSets->mSets[2];
            q->mNsbmds = p->mNsbmds;
            q->mNsbcaNsbmaNsbtp[0] = NULL;
            q->mNsbcaNsbmaNsbtp[1] = p->mNsbcaNsbmaNsbtp[1];
            q->mNsbcaNsbmaNsbtp[2] = p->mNsbcaNsbmaNsbtp[2];
            q->mNsbmdCount = p->mNsbmdCount;
        } else {
            gStemSets->mSets[i] = HeapAlloc(a, 0x14);
            InitNsbmdNsbcaNsbmaNsbtp(a, gStemSets->mSets[i], &gCountStartStems[(u32) i], i);
        }
    }
    if (gRaceSetup->mMode == MODE_BATTLE || gRaceSetup->mUnk_1c == 1) {
        gStemSets->mSets[4] = HeapAlloc(a, 0x14);
        InitNsbmdNsbcaNsbmaNsbtp(a, gStemSets->mSets[4], &gWinStems, 4);
        gStemSets->mSets[5] = HeapAlloc(a, 0x14);
        InitNsbmdNsbcaNsbmaNsbtp(a, gStemSets->mSets[5], &gLoseStems, 5);
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        gStemSets->mSets[6] = HeapAlloc(a, 0x14);
        InitNsbmdNsbcaNsbmaNsbtp(a, gStemSets->mSets[6], &gCompleteStems, 6);
        gStemSets->mSets[7] = HeapAlloc(a, 0x14);
        InitNsbmdNsbcaNsbmaNsbtp(a, gStemSets->mSets[7], &gFailedStems, 7);
    } else {
        gStemSets->mSets[3] = HeapAlloc(a, 0x14);
        InitNsbmdNsbcaNsbmaNsbtp(a, gStemSets->mSets[3], &gGoalStems, 3);
    }
}

void StartStemSet(s32 a) {
    StemSet *p;
    ModelAnimation *e;
    u16 i;
    s32 f;
    s32 v;

    gStemSets->mSets[8] = gStemSets->mSets[a];
    p = gStemSets->mSets[8];
    if (p == NULL) {
        gStemSets->mShownIndex = 9;
        return;
    }
    gStemSets->mShownIndex = a;
    for (i = 0; i < p->mNsbmdCount; i++) {
        if (p->mNsbcaNsbmaNsbtp[0] != NULL) {
            SetModelAnimation(&p->mNsbcaNsbmaNsbtp[0][i], 0);
        }
        if (p->mNsbcaNsbmaNsbtp[1] != NULL) {
            SetModelAnimation(&p->mNsbcaNsbmaNsbtp[1][i], 0);
        }
        if (a == 0 || a == 2) {
            if (a == 2) {
                f = 1;
            } else {
                f = 0;
            }
            if (a == 2) {
                v = 5;
            } else {
                v = 3;
            }
            SetModelAnimation(p->mNsbcaNsbmaNsbtp[2], (u16) f);
            e = p->mNsbcaNsbmaNsbtp[0];
            if (e != NULL) {
                e[i].mLoopMode = 2;
                e[i].mLoopCount = v;
            }
            e = p->mNsbcaNsbmaNsbtp[1];
            if (e != NULL) {
                e[i].mLoopMode = 2;
                e[i].mLoopCount = v;
            }
        }
    }
}

void UpdateStemSets(void) {
    StemSet *p;
    u16 i;

    if (gStemSets->mShownIndex == 1 || gStemSets->mShownIndex == 3) {
        gStemSets->mShownFrames++;
        if (gStemSets->mShownFrames > gStemSets->mShownFrameCount) {
            gStemSets->mShownIndex = 9;
        }
    }
    if (gStemSets->mShownIndex != 9) {
        p = gStemSets->mSets[8];
        for (i = 0; i < p->mNsbmdCount; i++) {
            if (p->mNsbcaNsbmaNsbtp[0] != NULL) {
                AdvanceModelAnimation(p->mNsbcaNsbmaNsbtp[0]);
            }
            if (p->mNsbcaNsbmaNsbtp[1] != NULL) {
                AdvanceModelAnimation(p->mNsbcaNsbmaNsbtp[1]);
            }
            if (p->mNsbcaNsbmaNsbtp[2] != NULL) {
                AdvanceModelAnimation(p->mNsbcaNsbmaNsbtp[2]);
            }
        }
    }
    if (gStemSets->mTimedQuad.mEnabled != FALSE) {
        gStemSets->mUpdateFunction(&gStemSets->mTimedQuad);
    }
}

void DrawStemSets(void) {
    MtxFx43 a;
    MtxFx43 b;
    Vec3 d;
    Vec3 *c;
    u16 i;
    Nsbmd *e;

    MTX_Identity43_(&a);
    data_0217029c.mCameraMtx = a;
    if (gRaceSetup->mRaceKind != RACE_KIND_NORMAL) {
        return;
    }
    if (gStemSets->mShownIndex != 9) {
        c = &b.mUnk_00[3];
        c->x = 0;
        c->y = 0;
        c->z = 0;
        d = data_0216608c;
        b.mUnk_00[3].y = data_02166048;
        if (gStemSets->mShownIndex == 2) {
            b.mUnk_00[3].y = 0x50000;
        }
        MTX_Identity33_(&b);
        for (i = 0; i < gStemSets->mSets[8]->mNsbmdCount; i++) {
            e = &gStemSets->mSets[8]->mNsbmds[i];
            G3i_OrthoW_(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x1000, 0x1f6, 0,
                        (Unk0214ad4c *) data_0217029c.mProjMtx);
            data_0217029c.mFlag &= ~0x50;
            NNS_G3dGlbSetBaseScale(&d);
            MI_Copy36B(&b, data_0217029c.mPrmBaseRot);
            data_0217029c.mFlag &= ~0xa4;
            NNS_G3dGlbSetBaseTrans(&b.mUnk_00[3]);
            NNS_G3dGlbFlushP();
            func_01ff8cf0(e);
        }
    }
    if (gStemSets->mTimedQuad.mEnabled != FALSE) {
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
        reg_G3_SPE_EMI = 0x4210;
        reg_G3_DIF_AMB = 0x42100000;
        reg_G3_MTX_MODE = 0;
        G3_LoadMtx44(&gStemSets->mOrthoMtx);
        reg_G3_TEXIMAGE_PARAM = 0x20000000;
        reg_G3_MTX_MODE = 2;
        reg_G3_MTX_IDENTITY = 0;
        DrawTimedQuad(&gStemSets->mTimedQuad);
    }
}

u32 func_02089f9c(u32 p0) {
    return p0;
}

void SetStemSet(s32 a) {
    if (a == 9) {
        gStemSets->mShownIndex = a;
        return;
    }
    if (gStemSets->mShownIndex != a || a == 2) {
        StartStemSet(a);
    }
    gStemSets->mShownFrames = 0;
    if (gStemSets->mShownIndex == 1 || gStemSets->mShownIndex == 3) {
        gStemSets->mShownFrameCount = GetModelAnimationFrameCountFixed(gStemSets->mSets[8]->mNsbcaNsbmaNsbtp[0]) >> 12;
    }
}

void StartTimedQuad(Unk02089ecc *p0) {
    p0->mTimer = 0xau;
    p0->mUnk_02 = 0xcu;
    p0->mColor = 0x7fffu;
    p0->mEnabled = 0x1u;
}

void UpdateTimedQuad(Unk02089e68 *a) {
    a->mUnk_02 = (s32) (((s64) ((s32) a->mTimer << 12) * 0x1333 + 0x800) >> 12) >> 12;
    a->mTimer = a->mTimer - 1;
    if (a->mTimer <= 0) {
        a->mEnabled = 0;
    }
}

void WriteQuadVertex(int a) {
    reg_G3_VTX_16 = data_02155ed0[a * 3] | data_02155ed0[a * 3 + 1] << 16;
    reg_G3_VTX_16 = data_02155ed0[a * 3 + 2];
}

void DrawTimedQuad(TimedQuad *a) {
    u32 *v1;
    u32 *v2;
    v1 = ((u32 *) &reg_G3_MTX_SCALE);
    reg_G3_POLYGON_ATTR = (0x090000c0u) | a->mUnk_02 << 0x10;
    *v1 = 0x8c000;
    *v1 = 0x6e000;
    v2 = ((u32 *) &reg_G3_BEGIN_VTXS);
    *v1 = 0xa000;
    *v2 = 1;
    reg_G3_COLOR = a->mColor;
    WriteQuadVertex(0);
    WriteQuadVertex(1);
    WriteQuadVertex(2);
    WriteQuadVertex(3);
    reg_G3_END_VTXS = 0;
}

void func_02089d14(u32 a) {
    gStemSets->mStartFunction = data_02155ec8[a];
    gStemSets->mUpdateFunction = data_02155ecc[a];
    gStemSets->mStartFunction(&gStemSets->mTimedQuad);
}

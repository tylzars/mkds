#include "Main/Unknown/code_0207ae58.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0207a14c.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02088338.h"
#include "ITCM/code_01ff8000.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/code_021112fc.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0200fe74.h"
#include "code_020109c4.h"
#include "code_02012b30.h"
#include "code_02134398.h"
#include "Main/Unknown/code_020681f0.h"

char *BuildCharacterNsbcaPath(u16 a, s32 b) {
    char *dirPath = BuildCharacterDirPath(a);
    const char *pName = LookupCharacterPOrEName(a, 1);

    snprintf(gCharacterNsbcaPathBuffer, 0x100, gCharacterNsbcaFormat, dirPath, pName, data_usa_021551b0[b].mUnk_00);
    return gCharacterNsbcaPathBuffer;
}

// Returns 0 for the driving animation and 1 for the other three (the ones that loop).
u32 GetCharacterAnimationLoopFlag(int a) {
    return data_usa_021551b4[a].mUnk_00;
}

void func_0207b8c4(struct KartModelsEntry *a) {
    CharacterAnimationState *p;

    a->mTurnFrameOffset = 0;
    p = (CharacterAnimationState *) &a->mTurnFrameOffset;
    p->mNextAnimationPending = FALSE;
    p->mNextAnimationIndex = 0;
}

// Steps the turn offset of the driving animation, or the playing animation and its hand-over to the next one.
void AdvanceKartCharacterAnimation(Kart *a) {
    s32 b;
    KartModelsEntry *q;
    CharacterAnimationState *p;
    Unk0206bcb0_590_08 *r;
    s32 c;
    u32 v;
    Unk0206bcb0_590_08 *s;

    q = a->mKartModelsEntry;
    p = (CharacterAnimationState *) &q->mTurnFrameOffset;
    r = q->mCharacterAnimation;
    c = p->mMiddleFrame;
    b = (a->mUnk_44 & KART_44_DRIFTING) != 0 ? 0x2000 : 0x1000;
    v = a->mUnk_48;
    if ((v & KART_48_TURN_LEFT) != 0) {
        if (gRaceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
            p->mTurnFrameOffset += b;
            if (p->mTurnFrameOffset > c) {
                p->mTurnFrameOffset = c;
            }
        }
    } else if ((v & KART_48_TURN_RIGHT) != 0) {
        if (gRaceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
            c *= -1;
            p->mTurnFrameOffset -= b;
            if (p->mTurnFrameOffset < c) {
                p->mTurnFrameOffset = c;
            }
        }
    } else if (p->mTurnFrameOffset != 0) {
        if (p->mTurnFrameOffset > 0) {
            p->mTurnFrameOffset -= b;
            if (p->mTurnFrameOffset < 0) {
                p->mTurnFrameOffset = 0;
            }
        } else {
            p->mTurnFrameOffset += b;
            if (p->mTurnFrameOffset > 0) {
                p->mTurnFrameOffset = 0;
            }
        }
    }
    if (r->mUnk_1a != 0) {
        AdvanceModelAnimation(r);
        if (p->mNextAnimationPending == FALSE) {
            return;
        }
        if (r->mUnk_02 != 1) {
            return;
        }
        func_02087cfc(r, r->mUnk_1a, 1);
        StartModelAnimationBlend(q->mCharacterAnimation, p->mNextAnimationIndex);
        s = q->mFaceAnimation;
        s->mUnk_0c = data_usa_021551a4[0];
        *s->mUnk_1c[s->mUnk_1a] = s->mUnk_0c;
        p->mNextAnimationPending = FALSE;
    } else {
        r->mUnk_0c = p->mTurnFrameOffset + p->mMiddleFrame;
        AdvanceModelAnimationBlend((ModelAnimation *) r);
    }
}

void SetCharacterFaceFrameIndex(struct KartModelsEntry *a, s32 b) {
    Unk0206bcb0_590_08 *p = a->mFaceAnimation;

    p->mUnk_0c = data_usa_021551a4[b];
    *p->mUnk_1c[p->mUnk_1a] = p->mUnk_0c;
}

void SetCharacterAnimation(struct KartModelsEntry *a, s32 b, s32 c) {
    if (c != 0) {
        StartModelAnimationBlend(a->mCharacterAnimation, b);
    } else {
        SetModelAnimation(a->mCharacterAnimation, (u16) b);
    }
}

static inline s32 func_0207b44c_inline(u32 i) {
    return *(vs32 *) &gRaceSetup->mCurrentEntries[i].mPlayer.mTeamIndex;
}

// Starts the win or lose animation of a kart that has finished, from the race result; nothing for the middle results.
void StartKartWinOrLoseAnimation(Kart *a) {
    u32 f;
    u16 b;
    s32 e;
    s32 m;
    BOOL c;
    s32 k;
    CharacterAnimationState *q;
    Unk020f41c4_B *r;
    u32 t;

    c = TRUE;
    f = c;
    e = 0;
    b = gRaceSetup->mKartCount;

    t = a->mUnk_7c;
    if ((t & 0x10) == 0) {
        return;
    }
    m = gRaceSetup->mMode;
    if (m == MODE_BATTLE) {
        return;
    }
    if (m == MODE_MISSION_RUN) {
        return;
    }
    if (m != MODE_BATTLE && gRaceSetup->mUnk_1c == 1) {
        b = gRaceProgress->mKartAtRank[0];
        if (gRaceSetup->mUseTeams != 0) {
            if (func_0207b44c_inline(b) != func_0207b44c_inline(a->mIndex)) {
                f = 2;
            } else {
                f = 0;
                a->mUnk_7c |= 0x2000000;
                e = c;
            }
        } else if (a->mIndex != b) {
            f = 2;
        } else {
            f = 0;
            a->mUnk_7c |= 0x2000000;
            e = c;
        }
    } else if (m == MODE_TIME_ATTACK) {
        if ((t & 4) == 0) {
            if (func_020c7148() != 0 || func_020c70ec() != 0) {
                f = 0;
            } else {
                f = 2;
            }
        }
    } else if (b > 1) {
        f = ((s16 *) &data_usa_021551dc[(b - 2) * 4])[GetKartRank(a->mIndex) - 1];
    }
    if (f == 0) {
        KartModelsEntry *s = a->mKartModelsEntry;
        q = (CharacterAnimationState *) &s->mTurnFrameOffset;
        func_02087cfc(s->mCharacterAnimation, (u16) f, 1);
        func_02068a64(a, 2, 1);
        if (e != 0) {
            a->mUnk_7c |= 0x10000;
        } else {
            q->mUnk_04 = TRUE;
            r = &gRaceProgress->mLocalRandom;
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            q->mUnk_10 = (u32) (((r->mUnk_00 >> 32) * 200) >> 32);
            q->mUnk_10 += 0x96;
        }
    } else if (f == 2) {
        a->mUnk_7c |= 0x20000;
        func_02068a64(a, 3, 1);
    }
    if ((a->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        k = 1;
        if (f != 0) {
            if (f == 2) {
                k = 2;
            }
        } else {
            k = 0;
        }
        func_021112fc(k);
    }
}

void func_0207b354(Kart *p) {
    CharacterAnimationState *q = (CharacterAnimationState *) &p->mKartModelsEntry->mTurnFrameOffset;
    Unk020f41c4_B *r;
    KartModelsEntry *s;

    if (q->mUnk_04 == FALSE) {
        return;
    }
    q->mUnk_10--;
    if (q->mUnk_10 > 0) {
        return;
    }
    s = p->mKartModelsEntry;
    if ((p->mUnk_7c & 0x40) != 0 || s->mCharacterAnimation->mUnk_1a == 2) {
        func_02068a64(p, 0, 1);
    } else if (s->mCharacterAnimation->mUnk_1a == 0) {
        func_02068a64(p, 2, 1);
    }
    r = &gRaceProgress->mLocalRandom;
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    q->mUnk_10 = (u32) (((r->mUnk_00 >> 32) * 200) >> 32);
    q->mUnk_10 += 0x96;
}

void func_0207b284(Kart *p) {
    KartModelsEntry *q = p->mKartModelsEntry;
    Nsbmd *r = q->mModels[0];
    Unk0206bcb0_590_08 *s = q->mFaceAnimation;
    NNSG3dResMdl *t = r->mResMdl;

    NNS_G3dMdlSetMdlPolygonModeAll(t, 2);
    NNS_G3dReleaseMdlTex(t);
    if (s != NULL && q->mUnk_0ac == FALSE) {
        NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *) r, (NNSG3dAnmObj *) s->mUnk_1c[0]);
        q->mUnk_0ac = TRUE;
    }
    SetKartModelMaterialColors(t, 2);
    t = q->mModels[1]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(t, 2);
    NNS_G3dReleaseMdlTex(t);
    SetKartModelMaterialColors(t, 2);
    if (q->mModels[2] != NULL) {
        t = q->mModels[2]->mResMdl;
        NNS_G3dMdlSetMdlPolygonModeAll(t, 2);
        NNS_G3dReleaseMdlTex(t);
        SetKartModelMaterialColors(t, 2);
    }
    q->mUnk_064 = TRUE;
}

void func_0207b1a8(Kart *p) {
    KartModelsEntry *q = p->mKartModelsEntry;
    Nsbmd *r = q->mModels[0];
    Unk0206bcb0_590_08 *s = q->mFaceAnimation;
    NNSG3dResMdl *t = r->mResMdl;
    Nsbmd *u;
    NNSG3dResMdl *w;
    Nsbmd *v;

    NNS_G3dMdlSetMdlPolygonModeAll(t, 0);
    NNS_G3dBindMdlTex(t, r->mResFileEntry.mTexture);
    if (s != NULL && q->mUnk_0ac != FALSE) {
        NNS_G3dRenderObjAddAnmObj((NNSG3dRenderObj *) r, (NNSG3dAnmObj *) s->mUnk_1c[0]);
        q->mUnk_0ac = FALSE;
    }
    SetKartModelMaterialColors(t, 0);
    u = q->mModels[1];
    t = u->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(t, 0);
    NNS_G3dBindMdlTex(t, u->mResFileEntry.mTexture);
    SetKartModelMaterialColors(t, 0);
    v = q->mModels[2];
    if (v != NULL) {
        w = v->mResMdl;
        NNS_G3dMdlSetMdlPolygonModeAll(w, 0);
        NNS_G3dBindMdlTex(w, v->mResFileEntry.mTexture);
        SetKartModelMaterialColors(w, 0);
    }
    q->mUnk_064 = FALSE;
}

void func_0207b13c(Kart *p) {
    KartModelsEntry *q = p->mKartModelsEntry;
    NNSG3dResMdl *r;

    if (q->mUnk_064 != FALSE) {
        return;
    }
    r = q->mModels[0]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(r, 2);
    SetKartModelMaterialColors(r, 3);
    r = q->mModels[1]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(r, 2);
    SetKartModelMaterialColors(r, 3);
}

void func_0207b0d0(Kart *p) {
    KartModelsEntry *q = p->mKartModelsEntry;
    NNSG3dResMdl *r;

    if (q->mUnk_064 != FALSE) {
        return;
    }
    r = q->mModels[0]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(r, 0);
    SetKartModelMaterialColors(r, 0);
    r = q->mModels[1]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(r, 0);
    SetKartModelMaterialColors(r, 0);
}

// Plays animation a once, then goes on to animation b.
void StartKartCharacterAnimationOnce(Kart *p, s32 a, s32 b) {
    KartModelsEntry *q = p->mKartModelsEntry;
    Unk0206bcb0_590_08 *s;
    CharacterAnimationState *r = (CharacterAnimationState *) &q->mTurnFrameOffset;

    s = q->mCharacterAnimation;
    if (r->mNextAnimationPending != FALSE && s->mUnk_1a != 0) {
        func_02087cfc(s, s->mUnk_1a, 1);
    }
    r->mNextAnimationPending = TRUE;
    r->mNextAnimationIndex = b;
    StartModelAnimationBlend(p->mKartModelsEntry->mCharacterAnimation, a);
    func_02087cfc(s, (u16) a, 0);
}

void InitShadowModelFromResMdl(Nsbmd *a, void *b, u32 c) {
    ShadowModel *p = (ShadowModel *) a;
    NNSG3dResMdl *q;

    func_02084f10(a, b);
    q = a->mResMdl;
    p->mPolygonId = c;
    p->mAlpha = 0xd;
    p->mFlags |= 1;
    NNS_G3dMdlSetMdlPolygonMode(q, 0, 3);
    NNS_G3dMdlSetMdlLightEnableFlag(q, 0, 0);
}

NNSG3dResMdl *InitShadowModel(void *param_1, NNSG3dResFileHeader *b, u32 c) {
    ShadowModel *a = param_1;
    NNSG3dResMdl *p;

    InitNsbmd(a, b);
    p = a->mNsbmd.mResMdl;
    a->mPolygonId = c;
    a->mAlpha = 0xd;
    a->mFlags |= 1;
    NNS_G3dMdlSetMdlPolygonMode(p, 0, 3);
    NNS_G3dMdlSetMdlLightEnableFlag(p, 0, 0);
    return a->mNsbmd.mResMdl;
}

// Draws the shadow with matrix b; when c is not NULL its three words are sent after the matrix.
void DrawShadowWithMatrix(void *param_1, const void *b, Vec3 *c) {
    ShadowModel *a = param_1;
    s32 v;
    Vec3 w;

    if ((a->mFlags & 1) == 0) {
        return;
    }
    v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    func_01ff9048(0x19, b, 0xc);
    if (c != NULL) {
        s32 z = c->z;
        s32 y = c->y;
        s32 x = c->x;
        w.x = x;
        w.y = y;
        w.z = z;
        func_01ff9048(0x1b, &w, 3);
    }
    func_02084ad8(a, a->mAlpha);
    data_02155a20[a->mNsbmd.mDrawKind](a);
    func_02084a88(a, a->mAlpha, a->mPolygonId);
    data_02155a20[a->mNsbmd.mDrawKind](a);
}

void func_0207ae58(ShadowModel *a) {
    if ((a->mFlags & 1) == 0) {
        return;
    }
    func_02084ad8(a, a->mAlpha);
    data_02155a20[a->mNsbmd.mDrawKind](a);
    func_02084a88(a, a->mAlpha, a->mPolygonId);
    data_02155a20[a->mNsbmd.mDrawKind](a);
}

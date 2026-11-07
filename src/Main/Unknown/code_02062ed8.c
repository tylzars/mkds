#include "Main/Unknown/code_02062ed8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0203be88.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_020649ec.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0206d000.h"
#include "Main/Unknown/code_02064000.h"
#include "Main/Unknown/code_02065000.h"
#include "Main/Unknown/code_0207a870.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02010c84.h"
#include "code_02012b30.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02147000.h"
#include "code_021471bc.h"

static inline void func_0206331c_inline(u32 a, u8 *b, Unk02084b2c *c, void *d, const char *e, const char *f, u16 *g) {
    if (f == NULL) {
        *g = 0;
    } else {
        func_0208823c(a, b, c, 1, d, e);
        func_0208805c(b, f, d);
        func_02087cfc(b, 0, 1);
        func_02087f84(b, 0);
    }
}

void func_02063880(Kart *a) {
    AdvanceKartCollision(a);
    if ((data_0217aa14->mUnk_75c & 2) != 0) {
        func_020636f8(a);
    }
    func_020641f0(a);
}

void func_02063830(Kart *a) {
    if (IsMissionRunWithKind2Shapes() != 0) {
        func_0203c1a8(&a->mPos, a->mIndex);
    }
    if ((a->mUnk_4c & 0x1000) != 0) {
        func_0206d138(a);
    }
    a->mUnk_4c = a->mUnk_4c & ~0x1000;
    AdvanceKartMotion(a);
}

void func_020637e0(Kart *a) {
    if (IsMissionRunWithKind2Shapes() != 0) {
        func_0203c1a8(&a->mPos, a->mIndex);
    }
    if ((a->mUnk_4c & 0x1000) != 0) {
        func_0206d138(a);
    }
    a->mUnk_4c = a->mUnk_4c & ~0x1000;
    func_020651fc(a);
}

void func_020637c4(Kart *a) {
    func_02064f50(a);
    func_020641f0(a);
}

void func_020636f8(Kart *a) {
    Unk0206bcb0_514 *b;
    Unk0217aa14_754_04 *c;
    Unk020636f8_B *d;

    c = &data_0217aa14->mUnk_754->mUnk_04;
    d = OFFSET_PTR(Unk020636f8_B, c, 8);
    b = a->mUnk_514;
    d->mUnk_00 = a->mPos.x >> 10;
    d->mUnk_02 = (a->mPos.y - a->mHopHeight) >> 10;
    d->mUnk_04 = a->mPos.z >> 10;
    d->mUnk_06 = a->mForwardSpeed >> 2;
    d->mUnk_0a = a->mHeadingAngle;
    d->mUnk_10 = a->mUnk_44;
    d->mUnk_10 = d->mUnk_10 | (((b->mUnk_98.x >> 6) & 0xff) << 24 | ((b->mUnk_98.y >> 6) & 0xff) << 16 |
                               ((b->mUnk_98.z >> 6) & 0xff) << 8);
    d->mUnk_14 = a->mUnk_48;
    d->mUnk_0c = b->mUnk_2c;
    d->mUnk_08 = a->mTurnAngle;
}

// Also sets the matrix and the per-course flags (CreateCourseModels would be the verb for just finding and building).
void InitCourseModels(void *a) {
    const char *b;
    const char *c;
    const char *d;
    NNSG3dResMdl *e;
    s32 f;
    s32 g[6];
    s32 i;

    b = FindCourseFile(data_usa_02165404);
    c = FindCourseFile(data_usa_02165418);
    gCourseModels.mNsbmd = HeapAlloc(a, 0x6c);
    e = func_02084b2c(a, gCourseModels.mNsbmd, (NNSG3dResFileHeader *) b, (NNSG3dResFileHeader *) c);
    d = FindCourseFile(data_usa_0216542c);
    func_0206331c_inline(2, data_usa_0217ab04, gCourseModels.mNsbmd, a, b, d, &gCourseModels.mUnk_20);
    d = FindCourseFile(data_usa_02165440);
    func_0206331c_inline(1, data_0217ab5c, gCourseModels.mNsbmd, a, b, d, &gCourseModels.mUnk_58);
    func_020849c0(gCourseModels.mNsbmd, 8);
    NNS_G3dMdlSetMdlXLDepthUpdateAll(e, 1);
    switch (data_021759c0->mCourseId) {
        case COURSE_ID_OLD_KOOPA_AGB:
            f = NNS_G3dGetResDictIdxByName((u8 *) e + e->mOfsMat + 4, data_usa_02154a00);
            if (f >= 0) {
                NNS_G3dMdlSetMdlAlpha(e, f, 0x1e);
                NNS_G3dMdlSetMdlXLDepthUpdate(e, f, 0);
            }
            break;
        case COURSE_ID_BANK:
            f = NNS_G3dGetResDictIdxByName((u8 *) e + e->mOfsMat + 4, data_usa_02154990);
            if (f >= 0) {
                NNS_G3dMdlSetMdlXLDepthUpdate(e, f, 0);
            }
            f = NNS_G3dGetResDictIdxByName((u8 *) e + e->mOfsMat + 4, data_usa_02154a10);
            if (f >= 0) {
                NNS_G3dMdlSetMdlXLDepthUpdate(e, f, 0);
            }
            break;
    }
    gCourseModels.mVNsbmd = NULL;
    b = FindCourseFile(data_usa_02165454);
    c = FindCourseFile(data_usa_0216546c);
    if (b != NULL) {
        gCourseModels.mVNsbmd = HeapAlloc(a, 0x6c);
        func_02084b2c(a, gCourseModels.mVNsbmd, (NNSG3dResFileHeader *) b, (NNSG3dResFileHeader *) c);
        func_020849c0(gCourseModels.mVNsbmd, 8);
        d = FindCourseFile(data_usa_02165484);
        func_0206331c_inline(1, data_usa_0217ab74, gCourseModels.mVNsbmd, a, b, d, &gCourseModels.mUnk_90);
    }
    g[0] = NNS_G3dGetResDictIdxByName((u8 *) e + e->mOfsMat + 4, data_usa_021549f0);
    g[1] = NNS_G3dGetResDictIdxByName((u8 *) e + e->mOfsMat + 4, data_usa_021549c0);
    g[2] = NNS_G3dGetResDictIdxByName((u8 *) e + e->mOfsMat + 4, data_usa_021549d0);
    g[3] = NNS_G3dGetResDictIdxByName((u8 *) e + e->mOfsMat + 4, data_usa_021549e0);
    g[4] = NNS_G3dGetResDictIdxByName((u8 *) e + e->mOfsMat + 4, data_usa_021549b0);
    g[5] = NNS_G3dGetResDictIdxByName((u8 *) e + e->mOfsMat + 4, data_usa_021549a0);
    for (i = 0; i < 6; i++) {
        if (g[i] >= 0) {
            NNS_G3dMdlSetMdlPolygonID(e, g[i], 7);
        }
    }
    MTX_Identity43_(&data_usa_0217abac);
    InitCourseModelsFogEnableFlags();
}

void UpdateCourseModels(void) {
    if (gCourseModels.mUnk_20 != 0) {
        func_02087de0(data_usa_0217ab04);
    }
    if (gCourseModels.mUnk_58 != 0) {
        func_02087de0(data_0217ab5c);
    }
    if (gCourseModels.mVNsbmd != NULL && gCourseModels.mUnk_90 != 0) {
        func_02087de0(data_usa_0217ab74);
    }
}

void DrawCourseModel(void) {
    func_020849f8(gCourseModels.mNsbmd, &data_usa_0217abac, data_usa_02154a20);
}

void DrawCourseModelV(void) {
    if (gCourseModels.mVNsbmd == NULL) {
        return;
    }
    func_020849f8(gCourseModels.mVNsbmd, &data_usa_0217abac, data_usa_02154a20);
}

void SetKoopaCourseLight2(void) {
    UnkVec16 a;

    if (data_021759c0->mCourseId != COURSE_ID_KOOPA) {
        return;
    }
    a = data_usa_021653fc;
    NNS_G3dGlbLightVector(2, a.x, a.y, a.z);
    NNS_G3dGlbLightColor(2, 0x7fff);
}

void InitCourseModelsFogEnableFlags(void) {
    u32 i;
    NNSG3dResMdl *b;
    u32 j;
    NNSG3dResMdl *c;

    gCourseModels.mUnk_e0 = FALSE;
    gCourseModels.mUnk_e4 = 0;
    gCourseModels.mUnk_ec = FALSE;
    gCourseModels.mUnk_f0 = 0;
    switch (data_021759c0->mCourseId) {
        case COURSE_ID_MANSION:
        case COURSE_ID_DESERT:
        case COURSE_ID_MINI_STAGE2:
            gCourseModels.mUnk_e0 = TRUE;
            break;
        case COURSE_ID_RAINBOW:
            gCourseModels.mUnk_ec = TRUE;
            break;
    }
    if (gCourseModels.mUnk_e0 != FALSE) {
        b = gCourseModels.mNsbmd->mUnk_04;
        for (i = 0; i < b->mInfo.mNumMat; i++) {
            if (NNS_G3dMdlGetMdlFogEnableFlag(b, i) != 0) {
                gCourseModels.mUnk_e4 |= (s64) (1 << i);
            }
        }
    } else {
        NNS_G3dMdlSetMdlFogEnableFlagAll(gCourseModels.mNsbmd->mUnk_04, 1);
    }
    if (gCourseModels.mVNsbmd == NULL) {
        return;
    }
    if (gCourseModels.mUnk_ec == FALSE) {
        return;
    }
    c = gCourseModels.mVNsbmd->mUnk_04;
    for (j = 0; j < c->mInfo.mNumMat; j++) {
        if (NNS_G3dMdlGetMdlFogEnableFlag(c, j) != 0) {
            gCourseModels.mUnk_f0 |= 1 << j;
        }
    }
}

void SetCourseModelsFogEnableFlags(u32 a) {
    u32 i;
    NNSG3dResMdl *b;
    u32 j;

    if (gCourseModels.mVNsbmd != NULL) {
        if (gCourseModels.mUnk_ec != FALSE && a == 0) {
            b = gCourseModels.mVNsbmd->mUnk_04;
            for (i = 0; i < b->mInfo.mNumMat; i++) {
                NNS_G3dMdlSetMdlFogEnableFlag(b, i, (gCourseModels.mUnk_f0 & (1 << i)) != 0 ? 1 : 0);
            }
        } else {
            NNS_G3dMdlSetMdlFogEnableFlagAll(gCourseModels.mVNsbmd->mUnk_04, a);
        }
    }
    if (gCourseModels.mUnk_e0 == FALSE) {
        return;
    }
    if (a != 0) {
        NNS_G3dMdlSetMdlFogEnableFlagAll(gCourseModels.mNsbmd->mUnk_04, 1);
        return;
    }
    b = gCourseModels.mNsbmd->mUnk_04;
    for (j = 0; j < b->mInfo.mNumMat; j++) {
        if ((gCourseModels.mUnk_e4 & (s64) (1 << j)) == 0) {
            NNS_G3dMdlSetMdlFogEnableFlag(b, j, 0);
        }
    }
}

s32 func_02062ed8(void) {
    if (gCourseModels.mUnk_20 != 0) {
        return gCourseModels.mUnk_14 >> 12;
    }
    return -1;
}

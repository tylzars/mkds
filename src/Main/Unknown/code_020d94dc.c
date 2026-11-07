#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020d4970.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02084000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020a02c8.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8b88.h"
#include "code_021471bc.h"

// The map object InitWater last received (type Unk020da384 is the 0x68-byte prefix view of MapObject: retype is a
// cleanup); InitWaterFields reads its x/z and DrawWater its mFlags; one water map object per course is assumed (a
// second would overwrite it).
Unk020da384 *gWaterMapObject;
WaterEfct *gWaterEfct;
Water *gWater;

// The mInitObject slot of the five water kinds (data_usa_021580a4): stores the map object in gWaterMapObject, clears
// mFlags bits 2 and 8, sets mUnk_66 to 0x1f, runs the creator the kind row holds (third argument), then loads the three
// water_efct files into gWater; once per water map object.
void InitWater(Unk020da384 *a, void *b, UnkFunc *c) {
    gWaterMapObject = a;
    a->mUnk_02 &= ~2;
    a->mUnk_02 &= ~8;
    a->mUnk_66 = 0x1f;
    c();
    gWater->mEfctNsbmdFile = FindCourseFile("MapObj/water_efct.nsbmd");
    gWater->mEfctNsbcaFile = FindCourseFile("MapObj/water_efct.nsbca");
    gWater->mEfctNsbmaFile = FindCourseFile("MapObj/water_efct.nsbma");
}

// One step per UpdateRace call while the course has water: advances the height swing (4 states) and the two circles;
// when mUnk_170 is set it also sets a value on entry 10 of data_0217c838 (func_02108e6c) every call (from func_020a02c8
// on course 0x1f, else 0x7f000) and requests sound 0x114 when state 1 ends and 0x113 when state 3 ends.
void UpdateWater(Water *a) {
    s32 v;
    NNSSndSeqPlayer **h;
    Unk0210b7a8 s1;
    Unk0210b7a8 s2;
    u16 w;
    s32 j;
    s32 k;
    h = func_02108e6c(10);
    if (a->mUnk_170 != 0) {
        if (data_021759c0->mCourseId != COURSE_ID_BEACH) {
            v = 0x7f000;
        } else {
            v = func_020a02c8();
        }
        if (v >= 0) {
            SetSndHandleTrackVolume(h, v);
        }
    }
    switch (a->mState) {
        case 0:
            a->mHeightFactor = gPairsByAngle[(a->mHeightAngle >> 4) * 2];
            a->mHeight = a->mMidHeight + (s32) (((s64) a->mHeightAmplitude * a->mHeightFactor) >> 12);
            a->mModelCY = a->mHeight;
            a->mHeightAngle = a->mHeightAngle + a->mHeightAnglePerFrame;
            a->mUnk_3a = a->mUnk_3a + a->mHeightAnglePerFrame;
            if (a->mHeightAngle > 0x3fff && a->mHeightAngle < 0x7fff) {
                a->mState = 1;
                a->mHoldFrames = 0;
                a->mUnk_3e = a->mHeightAnglePerFrame;
            }
            break;
        case 1:
            a->mHoldFrames = a->mHoldFrames + 1;
            if (a->mHoldFrames > a->mHighHoldFrameCount) {
                a->mState = 2;
                if (a->mUnk_170 != 0 && v >= 0) {
                    s1.mUnk_00 = 0x114;
                    s1.mUnk_04 = NULL;
                    s1.mUnk_08 = 4;
                    s1.mUnk_0c = func_020d4ef4(NULL);
                    func_0210b760(&s1, h);
                }
            } else if (a->mHoldFrames > (a->mHighHoldFrameCount >> 1)) {
                a->mUnk_3e = a->mUnk_3e + 1;
                a->mUnk_3a = a->mUnk_3a + a->mUnk_3e;
            } else {
                a->mUnk_3e = a->mUnk_3e - 1;
                a->mUnk_3a = a->mUnk_3a + a->mUnk_3e;
            }
            break;
        case 2:
            a->mHeightFactor = gPairsByAngle[(a->mHeightAngle >> 4) * 2];
            a->mHeight = a->mMidHeight + (s32) (((s64) a->mHeightAmplitude * a->mHeightFactor) >> 12);
            a->mModelCY = a->mHeight;
            a->mHeightAngle = a->mHeightAngle + a->mHeightAnglePerFrame;
            a->mUnk_3a = a->mUnk_3a + a->mHeightAnglePerFrame;
            if (a->mHeightAngle > 0xbfff) {
                a->mState = 3;
                a->mHoldFrames = 0;
                a->mUnk_3e = a->mHeightAnglePerFrame;
            }
            break;
        case 3:
            a->mHoldFrames = a->mHoldFrames + 1;
            if (a->mHoldFrames > a->mLowHoldFrameCount) {
                a->mState = 0;
                if (a->mUnk_170 != 0 && v >= 0) {
                    s2.mUnk_00 = 0x113;
                    s2.mUnk_04 = NULL;
                    s2.mUnk_08 = 4;
                    s2.mUnk_0c = func_020d4ef4(NULL);
                    func_0210b760(&s2, h);
                }
            } else if (a->mHoldFrames > (a->mLowHoldFrameCount >> 1)) {
                a->mUnk_3e = a->mUnk_3e + 1;
                a->mUnk_3a = a->mUnk_3a + a->mUnk_3e;
            } else {
                a->mUnk_3e = a->mUnk_3e - 1;
                a->mUnk_3a = a->mUnk_3a + a->mUnk_3e;
            }
            break;
    }
    a->mCircleAngle = a->mCircleAngle + a->mCircleAnglePerFrame;
    w = a->mCircleAngle - a->mModelCAngleOffset;
    if (a->mModelAFile != NULL) {
        j = (a->mCircleAngle >> 4) * 2;
        a->mModelAX = a->mCenterX + (s32) (((s64) a->mModelARadius * gPairsByAngle[j]) >> 12);
        a->mModelAZ = a->mCenterZ + (s32) (((s64) a->mModelARadius * gPairsByAngle[j + 1]) >> 12);
    }
    k = (w >> 4) * 2;
    a->mModelCX = a->mCenterX + (s32) (((s64) a->mModelCRadius * gPairsByAngle[k]) >> 12);
    a->mModelCZ = a->mCenterZ + (s32) (((s64) a->mModelCRadius * gPairsByAngle[k + 1]) >> 12);
}

// Draws model A (when it exists) and model C at their circle positions and mHeight, in the order of mDrawModelAFirst;
// returns at once when the water map object's mFlags has bit 0x2 or 0x10; writes only the scratch matrix mUnk_140.
void DrawWater(Water *a, struct MtxFx43 *b) {
    if ((gWaterMapObject->mUnk_02 & 0x12) != 0) {
        return;
    }
    if (a->mDrawModelAFirst != 0) {
        if (a->mModelAFile != NULL) {
            a->mUnk_140.mUnk_00[3].x = a->mModelAX >> 4;
            a->mUnk_140.mUnk_00[3].y = a->mHeight >> 4;
            a->mUnk_140.mUnk_00[3].z = a->mModelAZ >> 4;
            DrawNsbmdWithMatrix(&a->mUnk_68, &a->mUnk_140, NULL);
        }
        a->mUnk_140.mUnk_00[3].x = a->mModelCX >> 4;
        a->mUnk_140.mUnk_00[3].y = a->mModelCY >> 4;
        a->mUnk_140.mUnk_00[3].z = a->mModelCZ >> 4;
        DrawNsbmdWithMatrix(&a->mUnk_d4, &a->mUnk_140, NULL);
    } else {
        a->mUnk_140.mUnk_00[3].x = a->mModelCX >> 4;
        a->mUnk_140.mUnk_00[3].y = a->mModelCY >> 4;
        a->mUnk_140.mUnk_00[3].z = a->mModelCZ >> 4;
        DrawNsbmdWithMatrix(&a->mUnk_d4, &a->mUnk_140, NULL);
        if (a->mModelAFile != NULL) {
            a->mUnk_140.mUnk_00[3].x = a->mModelAX >> 4;
            a->mUnk_140.mUnk_00[3].y = a->mHeight >> 4;
            a->mUnk_140.mUnk_00[3].z = a->mModelAZ >> 4;
            DrawNsbmdWithMatrix(&a->mUnk_68, &a->mUnk_140, NULL);
        }
    }
}

Unk020d9de0 *func_020d9de0(void) {
    Unk020d9de0 *p;
    p = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    {
        Unk020d9de0 v = {0};
        *p = v;
    }
    return p;
}

#pragma thumb on

// Called once by each Create...Water with 15 constants; sets 28 members of gWater (heights, step sizes, radii, hold
// counts, flags) and resets the matrix mUnk_140, nothing else.
void InitWaterFields(s32 a, s32 b, s32 c, s32 d, s32 e, u16 f, u16 g, u16 h, u16 i, u16 j, u16 k, u16 l, u16 m, u16 n,
                     s32 o) {
    gWater->mMidHeight = (a + b) >> 1;
    gWater->mHeight = gWater->mMidHeight;
    gWater->mModelCY = gWater->mHeight;
    gWater->mHeightAmplitude = (a - b) >> 1;
    gWater->mHeightAngle = 0;
    gWater->mUnk_3a = 0;
    gWater->mCircleAngle = 0;
    gWater->mModelCAngleOffset = f;
    gWater->mUnk_52 = g;
    gWater->mHeightAnglePerFrame = 0x10000 / h;
    gWater->mCircleAnglePerFrame = (u32) gWater->mHeightAnglePerFrame >> 2;
    gWater->mState = 0;
    gWater->mHighHoldFrameCount = i;
    gWater->mLowHoldFrameCount = j;
    gWater->mHeightFactor = 0;
    gWater->mCenterX = gWaterMapObject->mUnk_04;
    gWater->mModelAX = gWater->mCenterX;
    gWater->mCenterZ = gWaterMapObject->mUnk_0c;
    gWater->mModelAZ = gWater->mCenterZ;
    gWater->mModelARadius = c;
    gWater->mModelCRadius = d;
    gWater->mUnk_4c = e;
    gWater->mDrawModelAFirst = k;
    gWater->mUnk_58 = l;
    gWater->mUnk_5a = m;
    gWater->mUnk_5c = n;
    MTX_Identity43_(&gWater->mUnk_140);
    gWater->mUnk_170 = o;
}

void CreateMiniStage3Water(void) {
    gWater = HeapAlloc(GetHeap(func_020364e8()), 0x180);
    InitWaterFields(0xe8000, 0xc5000, 0x50000, 0x32000, 0x3c000, 0x7fff, 0x3fff, 0x1f4, 0x12c, 0x12c, 1, 5, 0xa, 0xa,
                    1);
    gWater->mModelAFile = FindCourseMapObjFile("mini_stage3_waterA.nsbmd");
    gWater->mModelCFile = FindCourseMapObjFile("mini_stage3_waterC.nsbmd");
    SetCourseWater(gWater);
}

void CreateBeachWater(void) {
    gWater = HeapAlloc(GetHeap(func_020364e8()), 0x180);
    InitWaterFields(0x78000, 0x62000, 0x50000, 0x43000, 0x3c000, 0x7fff, 0x3fff, 0x1f4, 0x96, 0x96, 1, 6, 0xa, 0xa, 1);
    gWater->mModelAFile = FindCourseMapObjFile("beach_waterA.nsbmd");
    gWater->mModelCFile = FindCourseMapObjFile("beach_waterC.nsbmd");
    SetCourseWater(gWater);
}

void CreateTownWater(void) {
    gWater = HeapAlloc(GetHeap(func_020364e8()), 0x180);
    InitWaterFields(0, 0, 0x29000, 0x1e000, 0xb000, 0x4e20, 0x3fff, 0x12c, 0x78, 0x1e, 1, 0xd, 0x19, 0x10, 0);
    gWater->mModelAFile = FindCourseMapObjFile("town_waterA.nsbmd");
    gWater->mModelCFile = FindCourseMapObjFile("town_waterC.nsbmd");
    SetCourseWater(gWater);
}

void CreateYoshiWater(void) {
    gWater = HeapAlloc(GetHeap(func_020364e8()), 0x180);
    InitWaterFields(0, 0, 0xc8000, 0x55000, 0x3c000, 0x7fff, 0x3fff, 0x1c2, 0x78, 0x1e, 1, 0xa, 0x17, 0x10, 0);
    gWater->mModelAFile = NULL;
    gWater->mModelCFile = FindCourseMapObjFile("yoshi_waterC.nsbmd");
    SetCourseWater(gWater);
}

void CreateHyudoroWater(void) {
    gWater = HeapAlloc(GetHeap(func_020364e8()), 0x180);
    InitWaterFields(0, 0, 0x63000, 0x4d000, 0x1e000, 0x7fff, 0x3fff, 0x1c2, 0x78, 0x1e, 1, 0xf, 0x19, 0x10, 0);
    gWater->mModelAFile = FindCourseMapObjFile("hyudoro_waterA.nsbmd");
    gWater->mModelCFile = FindCourseMapObjFile("hyudoro_waterC.nsbmd");
    SetCourseWater(gWater);
}

// Once per course, from func_020d2e24 in InitMapObjects: builds the embedded model of each file (mUnk_68 only when A
// exists, mUnk_d4) and sets material values (NNS_G3dMdlSetMdlPolygonID: 1 for A, 2 for C; the two 5-bit values mUnk_58
// / mUnk_5a through NNS_G3dMdlSetMdlAlpha).
void InitWaterModels(Water *a) {
    u32 i;
    NNSG3dResMdl *p;
    NNSG3dResMdl *q;
    s32 r;
    u32 n;
    if (a->mModelAFile != NULL) {
        InitNsbmd(&a->mUnk_68, a->mModelAFile);
        i = 0;
        p = a->mUnk_68.mUnk_04;
        for (; i < p->mInfo.mNumMat; i++) {
            NNS_G3dMdlSetMdlEmi(p, i, 0x294a);
        }
        i = 0;
        p = a->mUnk_68.mUnk_04;
        for (; i < p->mInfo.mNumMat; i++) {
            NNS_G3dMdlSetMdlPolygonID(p, i, 1);
        }
    }
    InitNsbmd(&a->mUnk_d4, a->mModelCFile);
    i = 0;
    p = a->mUnk_d4.mUnk_04;
    for (; i < p->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlEmi(p, i, 0x294a);
    }
    i = 0;
    p = a->mUnk_d4.mUnk_04;
    for (; i < p->mInfo.mNumMat; i++) {
        NNS_G3dMdlSetMdlPolygonID(p, i, 2);
    }
    q = a->mUnk_d4.mUnk_04;
    r = NNS_G3dGetResDictIdxByName((u8 *) q + q->mOfsMat + 4, data_02158094);
    if (a->mModelAFile != NULL) {
        n = a->mUnk_58;
        i = 0;
        p = a->mUnk_68.mUnk_04;
        for (; i < p->mInfo.mNumMat; i++) {
            NNS_G3dMdlSetMdlAlpha(p, i, n);
        }
    }
    NNS_G3dMdlSetMdlAlpha(q, r, a->mUnk_5a);
}

void CreateWaterEfct(Unk020da384 *a) {
    WaterEfct *p;
    p = HeapAlloc(GetHeap(func_020364e8()), 0x10);
    gWaterEfct = p;
    p->mHeight = a->mUnk_08;
    gWaterEfct->mNsbmdFile = FindCourseFile("MapObj/water_efct.nsbmd");
    gWaterEfct->mNsbcaFile = FindCourseFile("MapObj/water_efct.nsbca");
    gWaterEfct->mNsbmaFile = FindCourseFile("MapObj/water_efct.nsbma");
    SetCourseWaterEfct(gWaterEfct);
}

#pragma thumb off

void func_020d9810(s32 t, s32 *a, s32 *b, s32 *c, s32 *d) {
    s32 u = 0x1000000 - t;
    s32 v = ((s64) u * u) >> 24;
    *a = ((s64) u * v) >> 24;
    *b = (s32) (((s64) u * t) >> 24) * 3;
    *c = ((s64) *b * t) >> 24;
    v = ((s64) t * t) >> 24;
    *d = ((s64) t * v) >> 24;
    *b = ((s64) *b * u) >> 24;
}

void func_020d970c(s32 t, s32 *a, s32 *b, s32 *c, s32 *d, s32 *e, s32 *f, s32 *g, s32 *h) {
    s32 u = 0x1000000 - t;
    *e = ((s64) u * u) >> 24;
    *a = ((s64) *e * u) >> 24;
    *h = ((s64) t * t) >> 24;
    *d = ((s64) *h * t) >> 24;
    *b = (s32) (((s64) u * t) >> 24) * 3;
    *e = *e * 3;
    *h = *h * 3;
    *g = *b << 1;
    *f = *e - *g;
    *g = *g - *h;
    *e = -*e;
    *c = ((s64) *b * t) >> 24;
    *b = ((s64) *b * u) >> 24;
}

void func_020d95c0(const Vec3 *p, Vec3 *o, s32 a, s32 b, s32 c, s32 d) {
    o->x = ((s64) p[0].x * a) >> 24;
    o->y = ((s64) p[0].y * a) >> 24;
    o->z = ((s64) p[0].z * a) >> 24;
    o->x = o->x + (s32) (((s64) p[1].x * b) >> 24);
    o->y = o->y + (s32) (((s64) p[1].y * b) >> 24);
    o->z = o->z + (s32) (((s64) p[1].z * b) >> 24);
    o->x = o->x + (s32) (((s64) p[2].x * c) >> 24);
    o->y = o->y + (s32) (((s64) p[2].y * c) >> 24);
    o->z = o->z + (s32) (((s64) p[2].z * c) >> 24);
    o->x = o->x + (s32) (((s64) p[3].x * d) >> 24);
    o->y = o->y + (s32) (((s64) p[3].y * d) >> 24);
    o->z = o->z + (s32) (((s64) p[3].z * d) >> 24);
}

void func_020d94dc(const Vec3 *p, Vec3 *o, s32 a, s32 b, s32 c, s32 d) {
    o->x = ((s64) p[0].x * a) >> 24;
    o->z = ((s64) p[0].z * a) >> 24;
    o->x = o->x + (s32) (((s64) p[1].x * b) >> 24);
    o->z = o->z + (s32) (((s64) p[1].z * b) >> 24);
    o->x = o->x + (s32) (((s64) p[2].x * c) >> 24);
    o->z = o->z + (s32) (((s64) p[2].z * c) >> 24);
    o->x = o->x + (s32) (((s64) p[3].x * d) >> 24);
    o->z = o->z + (s32) (((s64) p[3].z * d) >> 24);
}

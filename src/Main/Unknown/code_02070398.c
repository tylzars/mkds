#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"

#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02109000.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_02108ea0.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_0212bcac.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "code_0212df7c.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_02089d14.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210a588.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0210b564.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_0210a598.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_0210cf20.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_02036820.h"
#include "code_0201750c.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_020681f0.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_0207a104.h"
#include "Main/Unknown/code_02081338.h"
#include "Main/Unknown/code_020810e4.h"
#include "Main/Unknown/code_020815a0.h"
#include "Main/Unknown/code_0208ae60.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_0208c4e8.h"
#include "Main/Unknown/code_02089f9c.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_0210a664.h"
#include "Main/Unknown/code_0210fa40.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_0206390c.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"

void func_020732d8(Kart *p) {
    s32 i;
    enum { K0 } k;

    k = p->mEntryIndex;
    data_0217566a[k].mBitMask = 0xff7;
    if (p->mUnk_7c & 0x20) {
        func_02068b98(p);
        return;
    }
    p->mUnk_3c8 = p->mUnk_3c8 + 1;
    i = p->mUnk_3c8;
    if (i >= 0x19) {
        p->mUnk_7c &= ~0x80;
        return;
    }
    p->mScaleFactor.x = data_usa_02154de4[i];
    p->mScaleFactor.y = data_usa_02154e48[i];
    p->mScaleFactor.z = data_usa_02154eac[i];
    p->mScale.x = (s32) (((s64) p->mScaleBase.x * p->mScaleFactor.x) >> 12);
    p->mScale.y = (s32) (((s64) p->mScaleBase.y * p->mScaleFactor.y) >> 12);
    p->mScale.z = (s32) (((s64) p->mScaleBase.z * p->mScaleFactor.z) >> 12);
    p->mScale.y = (s32) (((s64) p->mScaleYFactor * p->mScale.y) >> 12);
}

void ResetKartToRespawnPoint(Kart *p) {
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Vec3 d;
    s32 m[9];
    Unk02175620_bc *r;
    s32 x;
    s32 y;
    s32 i;
    KartItems *e;
    s64 l;

    if (p->mRespawnSlot == -1) {
        i = p->mIndex;
        if (data_021759c0->mMode == MODE_BATTLE) {
            i = GetCourseMapRespawnSlot(0);
        } else {
            i = GetCourseMapRespawnSlot(gRaceProgress->mUnk_000[i].mCheckpoint);
        }
        p->mRespawnSlot = i;
    }
    i = (u16) p->mRespawnSlot;
    if (data_021759c0->mMode == MODE_BATTLE) {
        r = func_02040fd8(i, &a, &c);
    } else {
        r = func_020410a4(i, &a, &c);
    }
    i = ((u16) ((s32) (((s64) c.y * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12)) >> 4;
    Matrix3x3FromPairY(m, gPairsByAngle[i * 2], gPairsByAngle[i * 2 + 1]);
    Vec3MultiplyMatrix3x3(&data_02154f70, m, &b);
    if (data_021759c0->mMode != MODE_BATTLE && gCourseMap->mUnk_60 != 0) {
        (e = &(gKartItems)[p->mIndex])->mUnk_1f0.mUnk_00 = func_02040f78((u16) p->mRespawnSlot);
        e->mUnk_1f0.mUnk_04 = 1;
    }
    if (data_021759c0->mMode != MODE_TIME_ATTACK) {
        x = data_usa_02154d4c[p->mIndex][0];
        y = data_usa_02154d50[p->mIndex][0];
        Vec3CrossUnrounded(&data_02154f7c, &b, &d);
        Vec3AddScaled((s32) (((s64) data_usa_02165504 * x) >> 12), &d, &a, &a);
        Vec3AddScaled((s32) (((s64) data_usa_02165504 * y) >> 12), &b, &a, &a);
        if (c.x != 0 && y != 0) {
            i = ((u16) ((s32) (((s64) c.x * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12)) >> 4;
            l = gPairsByAngle[i * 2];
            i = (s32) ((l * -y + 0x800) >> 12);
            a.y += (s32) (((s64) i * data_usa_02165504 + 0x800) >> 12);
        }
        if (c.z != 0 && x != 0) {
            i = ((u16) ((s32) (((s64) c.z * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12)) >> 4;
            l = gPairsByAngle[i * 2];
            i = (s32) ((l * x + 0x800) >> 12);
            a.y += (s32) (((s64) i * data_usa_02165504 + 0x800) >> 12);
        }
    }
    a.y += 0x28000;
    x = p->mUnk_48;
    if (x & 0x800000) {
        func_02081f10(StartEffect(0x71, &a), p->mIndex, 0x32);
    } else if (x & 0x1000000) {
        func_02081f10(StartEffect(0x70, &a), p->mIndex, 0x32);
    }
    ResetKartAndSetPos(p, &a, &b, r);
    if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        GetEntryKartCounters()->mUnk_18++;
    } else {
        func_0210b850(&p->mUnk_518);
    }
    p->mUnk_4c |= 0xc00;
    p->mUnk_48 |= 0x2000000;
    if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        func_02055bd4(0x3c);
        func_02075d08(0);
    }
}

s32 func_02072d84(Kart *p, s32 *a) {
    BOOL r;
    u32 f;

    f = p->mUnk_4c;
    r = FALSE;
    if (f & 0x4000000) {
        if (p->mUnk_4bc > 0x19a) {
            p->mUnk_4bc = (s32) (((s64) p->mUnk_4bc * 0xe66LL) >> 12);
        }
        *a = p->mUnk_4bc;
    } else if (f & 0x200000) {
        if (p->mUnk_4bc > 0x666) {
            p->mUnk_4bc = (s32) (((s64) p->mUnk_4bc * 0xe66LL) >> 12);
        }
        *a = p->mUnk_4bc;
    }
    p->mUnk_3c0 = p->mUnk_3c0 + 1;
    if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (p->mUnk_3c0 == 0x16) {
            func_02055a94();
        } else if (p->mUnk_3c0 == 0x19) {
            func_02055c18(0x3c);
        }
    }
    if ((p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && p->mUnk_3c0 == 0x55) {
        func_020e7a40();
    } else if (p->mUnk_3c0 > 0x78) {
        func_02063ad0(p);
        r = TRUE;
    }
    return r;
}

void ResetKartAndSetPos(Kart *p, const Vec3 *a, const Vec3 *b, Unk02175620_bc *c) {
    Unk0206bcb0_514 *q;
    Vec3 v;

    func_02072930(p);
    func_02079c0c(p->mKartModelsEntry);
    p->mSlotFunctions[1](p);
    p->mUnk_7c &= ~0xe000;
    func_02103890(p->mIndex);
    p->mUnk_48 |= 0x240;
    p->mPos = *a;
    if (p->mUnk_7c & 0x400) {
        q = p->mUnk_514;
        q->mUnk_00 = p->mPos;
        q->mUnk_10 = q->mUnk_00;
        q->mUnk_4c = *(Vec4 *) &p->mUnk_108.z;
        q->mUnk_a8 = data_02154f94;
        q->mUnk_b4 = 0;
    }
    if (b != NULL) {
        p->mHeadingAngle = (s32) (((s64) func_02148538(b->x, b->z) * 0x28be60dLL) >> 12) >> 12;
        v = data_02165524;
        QuaternionFromAxisAngle(&v, p->mHeadingAngle, &p->mUnk_e0_m);
    }
    func_01ffcd84(&p->mUnk_120, &p->mUnk_e0_m);
    GetKartForward(p, &p->mUnk_278);
    p->mUnk_50 = p->mUnk_278;
    p->mUnk_68 = p->mUnk_50;
    p->mPrevPos = p->mPos;
    p->mUnk_98 = p->mPrevPos;
    p->mPrevCollisionCenter = p->mPos;
    p->mCollisionCenter = p->mPos;
    p->mLastGroundY = p->mPos.y;
    if (p->mUnk_7c & 2) {
        if (c != NULL) {
            func_0208c23c(p->mUnk_310, c);
        } else {
            func_0208c260(p->mUnk_310, p->mIndex);
        }
    }
    if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        ResetCameraBehind(a, &p->mUnk_e0_m);
        func_02089f9c(((u32(*)(void)) ResetCameraHalfFovAngle)());
        SetCameraHeightHold(0);
    }
}

void func_02072930(Kart *p) {
    s32 i;
    Unk02165560 v;

    func_020f0044(&(gKartItems)[p->mIndex]);
    func_02083834(p);
    func_02081768(p->mIndex);
    func_020815a0(p->mIndex);
    func_02081338(p->mIndex);
    func_020810e4(p->mIndex);
    func_02080fb8(p);
    func_02080e9c(p);
    func_0208c5d0(func_0208c5b8(p->mIndex));
    func_020719d0(p);
    if (p->mIndex == data_021759c0->mEntryIndex) {
        func_0210fa74(0);
    }
    func_0210a664(p);
    if (p->mUnk_4c & 0x2000) {
        func_0207b0d0(p);
    }
    if (p->mUnk_4c & 0x40) {
        p->mUnk_4c &= ~0x40;
        func_0207b1a8(p);
        p->mUnk_29c = 0;
        func_020817b8(p->mIndex);
        func_02068a64(p, 0, 1);
        if ((p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && data_021759c0->mUnk_00c == 0) {
            func_02106dc8();
        }
        if (p->mUnk_4c & 0x2000) {
            func_0207b13c(p);
        }
    }
    if (p->mUnk_4c & 0x10000000) {
        p->mUnk_4c &= ~0x10000000;
        func_0210515c(p->mIndex);
        if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            ResetCameraHalfFovAngleGoal();
        }
        p->mUnk_4c8 = 0x1000;
        p->mSurfaceGroup = -1;
        i = 0;
        p->mUnk_29c = 0;
        if (p->mKartModelsEntry->mUnk_058 == 0) {
            v = data_usa_02165560;
            for (i = 0; i < 3; i++) {
                func_02081f10(StartEffect(v.mUnk_00[i], &p->mPos), p->mIndex, 0x14);
            }
        }
        func_020815dc(p->mIndex);
        StartSound(&p->mSoundSource, 0xfd, 0x7f, 0);
    }
    if (p->mUnk_7c & 0x2000) {
        p->mUnk_7c &= ~0x2000;
        p->mUnk_7c &= ~0xc000;
        p->mUnk_29c = 0;
        if (!(p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            func_0208c4e8(func_0208c5b8(p->mIndex));
        } else {
            StartSound(&p->mSoundSource, 0xf9, 0x7f, 0);
        }
        func_0210fa40(0, (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    }
}

void ResetKartToStartPlacement(Kart *p) {
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Vec3 *q;

    if (!(p->mUnk_7c & 0x20)) {
        return;
    }
    GetCourseMapKartStartPlacement(&a, &c, p->mIndex);
    p->mHeadingAngle = (u32) (c.y * 0xb6) >> 12;
    QuaternionFromAxisAngle(&data_02154f7c, p->mHeadingAngle, &p->mUnk_e0_m);
    func_01ffcd84(&p->mUnk_120, &p->mUnk_e0_m);
    GetKartForward(p, &b);
    ResetKartAndSetPos(p, &a, &b, NULL);
    if (data_021759c0->mMode == 5) {
        q = &p->mUnk_1d8;
    } else {
        q = &p->mCollisionCenter;
    }
    if (p->mUnk_2c8 == -1) {
        p->mUnk_2c8 = func_020d555c(q, p->mPhysicalParam->mRadius + 0xd000, 0x8000, p);
    }
    if (p->mUnk_2ca == -1) {
        p->mUnk_2ca = func_020d555c(&p->mUnk_1f0, (s32) (((s64) p->mPhysicalParam->mRadius << 15) >> 12), 0x800, p);
    }
    p->mUnk_7c |= 0x80;
    p->mUnk_7c &= ~0x60;
    p->mScale = data_02154f94;
}

void func_020726bc(Kart *p) {
    s32 a;
    s32 b;
    s16 i;
    KartPhysicalParam *q;
    s32 *r;

    p->mPhysicalParam = GetKartPhysicalParam(p->mIndex);
    a = 0x1000;
    b = 0;
    if (func_02062eb0() == 0) {
        switch (data_021759c0->mUnk_010) {
            case 0:
                a = 0xb33;
                b = -0x28;
                break;
            case 1:
                a = 0xd9a;
                b = -0x14;
                break;
        }
    }
    p->mPhysicalParam->mBaseSpeedLimit = (s32) (((s64) p->mPhysicalParam->mBaseSpeedLimit * a) >> 12);
    p->mPhysicalParam->mUnk_32 = p->mPhysicalParam->mUnk_32 + b;
    p->mUnk_3f4 = 0x1000 - p->mPhysicalParam->mSurfaceSpeedLimitFactors[4];
    p->mUnk_3f4 = DivFixed12(p->mUnk_3f4, p->mPhysicalParam->mRadius << 1);
    p->mCharPhysicalParam = GetCharPhysicalParam(p->mIndex);
    q = p->mPhysicalParam;
    r = p->mCharPhysicalParam;
    for (i = 0; i < 12; i++) {
        a = q->mSurfaceSpeedLimitFactors[i];
        if (a < 0x1000) {
            q->mSurfaceSpeedLimitFactors[i] = (s32) (((s64) a * *r + 0x800) >> 12);
        }
    }
}

void func_02072600(Kart *p) {
    Vec3 v;

    p->mUnk_d4 = 0x1000;
    p->mUnk_d8 = 0x1000;
    p->mUnk_dc = 0x1000;
    p->mUnk_38c = 0x1000;
    v = data_02154f94;
    *(Vec3 *) &p->mUnk_25c = v;
    p->mUnk_268 = v;
    p->mUnk_274 = 0;
    p->mUnk_278 = v;
    p->mUnk_290 = v;
    p->mUnk_2d8 = v;
    p->mUnk_2e4 = v;
    p->mUnk_2f0 = v;
    *(Vec3 *) &p->mUnk_25c = v;
    p->mAirborneFrames = 0;
    p->mTurnAngle = 0;
    p->mUnk_38a = 0;
    p->mUnk_240 = 0x1000;
    p->mHeadingAnglePerFrame = 0;
}

void ResetKart(Kart *p) {
    Vec3 v;
    u16 i;

    func_0207b8c4(p->mKartModelsEntry);
    p->mUnk_44 = 0;
    p->mUnk_48 = 0;
    p->mUnk_4c = 0;
    v = data_02154f94;
    p->mUnk_98 = v;
    p->mPrevPos = p->mUnk_98;
    p->mPos = p->mPrevPos;
    p->mVelocity = v;
    p->mVelocityDirection = v;
    p->mScale.x = 0x1000;
    p->mScale.y = 0x1000;
    p->mScale.z = 0x1000;
    p->mScaleFactor.x = 0x1000;
    p->mScaleFactor.y = 0x1000;
    p->mScaleFactor.z = 0x1000;
    p->mScaleBase.x = 0x1000;
    p->mScaleBase.y = 0x1000;
    p->mScaleBase.z = 0x1000;
    p->mScaleYFactor = 0x1000;
    p->mGravity = -0x2b9;
    p->mSpeedLimitGoal = 0;
    p->mSpeedLimit = 0xd000;
    p->mUnk_d4 = 0x1000;
    p->mUnk_d8 = 0x1000;
    p->mState = 0;
    func_02071ddc(&p->mUnk_538);
    Matrix4x3Identity(&p->mUnk_120_m);
    Matrix4x3Identity(&p->mUnk_150_m);
    Matrix4x3Identity(&p->mUnk_184_m);
    p->mUnk_1d8 = v;
    p->mUnk_1e4 = p->mUnk_1d8;
    p->mPrevCollisionCenter = p->mUnk_1e4;
    p->mCollisionCenter = p->mPrevCollisionCenter;
    p->mUnk_1f0 = v;
    p->mUnk_1fc = v;
    p->mUnk_dc = 0x1000;
    p->mUnk_e0_m = data_usa_02154f14;
    *(Vec4 *) &p->mUnk_f0 = data_usa_02154f24;
    *(Vec4 *) &p->mUnk_100 = data_usa_02154f34;
    *(Vec4 *) &p->mUnk_108.z = data_usa_02154f44;
    p->mUnk_234 = 0;
    p->mHeadingAngle = 0;
    p->mUnk_238 = 0;
    p->mUnk_23a = 0;
    p->mUnk_23c = 0;
    p->mUnk_240 = 0x1000;
    p->mUnk_244 = data_02154f7c;
    p->mUnk_250 = v;
    *(Vec3 *) &p->mUnk_25c = v;
    p->mUnk_268 = v;
    p->mUnk_274 = 0;
    p->mUnk_278 = v;
    p->mUnk_290 = v;
    p->mUnk_50 = v;
    p->mUnk_68 = p->mUnk_50;
    p->mVelocityLengthRatio = 0;
    p->mVelocityLength = 0;
    p->mForwardSpeed = 0;
    p->mLastGroundY = 0;
    p->mTestedKartMask = 0;
    p->mNearKartMask = 0;
    p->mPrevNearKartMask = 0;
    p->mUnk_29c = 0;
    p->mHopSpeed = 0;
    p->mHopHeight = 0;
    p->mHopTiltAngle = 0;
    p->mTurnDirection = 0;
    p->mUnk_2d4 = 0;
    p->mUnk_2d8 = v;
    p->mUnk_334 = 0;
    p->mUnk_338 = 0;
    p->mUnk_33c = 0;
    p->mUnk_344 = 0;
    p->mUnk_340 = p->mPos.y;
    p->mUnk_348 = 0;
    p->mUnk_2fc = 0;
    p->mUnk_302 = 0;
    p->mUnk_300 = p->mUnk_302;
    p->mUnk_308 = NULL;
    p->mUnk_304 = p->mUnk_308;
    p->mUnk_30c = 0;
    p->mUnk_314 = 0;
    p->mUnk_318 = 0;
    p->mUnk_31c = v;
    p->mUnk_34c = data_usa_02154f54;
    p->mUnk_35c = 0;
    p->mUnk_360 = 0;
    p->mUnk_364 = 0;
    p->mUnk_36c = 0;
    p->mUnk_366 = 0;
    p->mUnk_368 = 0;
    p->mUnk_370 = 0;
    p->mUnk_374 = v;
    p->mAirborneFrames = 0;
    p->mVisible = 0xffff;
    p->mHeadingAnglePerFrame = 0;
    p->mTurnAngle = 0;
    p->mUnk_38a = 0;
    p->mUnk_38c = 0x1000;
    p->mUnk_394 = 0x1000;
    p->mUnk_39c = 0;
    p->mUnk_3a0 = 0;
    p->mTireSpinAngle = 0;
    p->mUnk_3a8 = 0x1ec;
    p->mUnk_3ac = 0;
    p->mVelocity = v;
    p->mUnk_3bc = 0;
    p->mUnk_3be = 0;
    p->mUnk_3c0 = 0;
    p->mRespawnSlot = -1;
    p->mUnk_3c8 = 0;
    p->mKartCollisionTimer = 0;
    p->mUnk_3d4 = 0;
    p->mSurfaceGroup = -1;
    p->mSurfaceKind = 0;
    p->mSurfaceVariant = 0;
    p->mUnk_3e8 = 0;
    p->mUnk_3ec = 0;
    p->mUnk_3f0 = 0;
    p->mUnk_3f8 = 0x1000;
    p->mUnk_3fc = 0;
    p->mUnk_3fe = 0;
    p->mUnk_400 = 0;
    p->mUnk_404 = 0x1000;
    p->mUnk_414 = 0x1000;
    p->mUnk_418 = 0x1000;
    for (i = 0; i < 2; i++) {
        p->mUnk_438[i] = NULL;
        p->mUnk_440[i] = 0;
        p->mUnk_444[i] = 0;
    }
    p->mUnk_44c = NULL;
    p->mUnk_408 = 0;
    p->mUnk_40c = 0;
    p->mUnk_410 = 0;
    p->mUnk_4bc = 0;
    p->mUnk_4c0 = 0;
    p->mUnk_4c4 = 0;
    p->mUnk_4c8 = 0x1000;
    p->mUnk_4d0 = 0;
    p->mUnk_4d4 = 0;
    p->mUnk_4d8 = -1;
    p->mUnk_4dc = 0;
    p->mUnk_4da = 0;
    p->mHeadingAngleOffset = 0;
    p->mHeadingAngleOffsetPerFrame = 0;
    p->mUnk_4e2 = 1;
    p->mUnk_4e4 = 0;
    p->mUnk_4ec = 0;
    p->mUnk_4e8 = 0x1000;
    p->mUnk_4f0 = data_usa_02154f64;
    p->mUnk_4f0.z = 0;
    p->mUnk_4fc = 0;
    p->mUnk_500 = 0;
    p->mUnk_506 = 0;
    p->mUnk_504 = p->mUnk_506;
    p->mUnk_59c = 0;
    p->mUnk_594 = p->mUnk_59c;
    p->mUnk_5a0 = 0;
    p->mUnk_3d8 = 0;
    func_02068a64(p, 0, 0);
    p->mUnk_4cc = 0;
}

void func_02071fb8(Kart *p, void *a) {
    Unk0206bcb0_514 *q;
    Vec3 v;
    u16 i;
    u8 *b;

    q = p->mUnk_514;
    if (q == NULL) {
        return;
    }
    q->mUnk_00 = p->mPos;
    q->mUnk_10 = q->mUnk_00;
    q->mUnk_0e = p->mHeadingAngle;
    q->mUnk_0c = q->mUnk_0e;
    q->mUnk_1c = 0;
    q->mUnk_20 = 0;
    q->mUnk_24 = 0;
    q->mUnk_28 = 0;
    q->mUnk_30 = 0;
    q->mUnk_2c = q->mUnk_30;
    v = data_02154f94;
    q->mUnk_34 = v;
    q->mUnk_44 = 0;
    q->mUnk_48 = 0;
    q->mUnk_40 = 0;
    q->mUnk_5c = 0;
    q->mUnk_60 = 0;
    q->mUnk_64 = 0;
    q->mUnk_98 = v;
    q->mUnk_a8 = v;
    q->mUnk_b4 = 0;
    ListInit(&q->mUnk_80, 0);
    ListInit(&q->mUnk_8c, 0);
    b = HeapAlloc(a, 0x438);
    for (i = 0; i < 0x1e; i++) {
        ListAppend(&q->mUnk_8c, b + i * 0x24);
    }
}

void func_02071f44(Kart *p) {
    Unk0206bcb0_514 *q;

    if (!(p->mUnk_7c & 0x400)) {
        return;
    }
    q = p->mUnk_514;
    q->mUnk_00 = p->mPos;
    q->mUnk_10 = q->mUnk_00;
    q->mUnk_4c = *(Vec4 *) &p->mUnk_108.z;
    q->mUnk_a8 = data_02154f94;
    q->mUnk_b4 = 0;
}

void func_02071e28(Kart *p) {
    p->mUnk_7c = 0;
    if (p->mIndex == data_021759c0->mEntryIndex) {
        p->mUnk_7c |= KART_7C_INDEX_IS_SELECTED_ENTRY;
        if (data_021759c0->mMode == 5) {
            p->mUnk_7c |= 0x200;
            if (func_0203c5e4() != 0) {
                p->mUnk_7c &= ~0x200;
                p->mUnk_7c |= 0x400;
            }
        }
    } else if (data_021759c0->mMode == 5) {
        p->mUnk_7c |= 0x400;
    }
    if (data_021759c0->mCurrentEntries[p->mIndex].mPlayer.mKind == 2) {
        p->mUnk_7c |= KART_7C_ENTRY_KIND_2;
        p->mVisible = 0;
    }
    if (p->mKartModelsEntry->mUnk_008 != NULL) {
        p->mUnk_7c |= KART_7C_MODELS_ENTRY_008_SET;
    }
    if (data_021759c0->mMode == MODE_TIME_ATTACK || func_02062eb0() != 0) {
        p->mUnk_7c |= 0x8000000;
    }
}

void func_02071ddc(Unk0206ceb4 *p0) {
    p0->mUnk_00 = 0;
    p0->mUnk_02 = 0;
    p0->mUnk_04 = 0;
    p0->mUnk_06 = 0;
    p0->mUnk_08 = 0;
    p0->mUnk_0a = 0;
    p0->mUnk_0c = 0;
    p0->mUnk_0e = 0;
    p0->mUnk_12 = 0;
    p0->mUnk_14 = 0;
    p0->mUnk_16 = 0;
    p0->mUnk_18 = 0;
    p0->mUnk_1c = 0;
    p0->mUnk_1e = 0;
    p0->mUnk_20 = 0;
    p0->mUnk_24 = FALSE;
    p0->mUnk_28 = 0;
}

void func_02071c18(Kart *p) {
    InitSoundSource(&p->mSoundSource, 0, p->mPosSource);
    func_0210a5a8(p, (Unk0210a5a8 *) &p->mUnk_450);
    func_020719d0(p);
    switch (p->mKartModelsEntry->mUnk_000) {
        case 0:
            p->mUnk_3cc = 4;
            break;
        case 1:
            p->mUnk_3cc = 0;
            break;
        case 2:
            p->mUnk_3cc = 1;
            break;
        case 3:
            p->mUnk_3cc = 2;
            break;
        case 4:
            p->mUnk_3cc = 5;
            break;
        case 5:
            p->mUnk_3cc = 6;
            break;
        case 6:
            p->mUnk_3cc = 7;
            break;
        case 7:
            p->mUnk_3cc = 3;
            break;
        case 8:
            p->mUnk_3cc = 10;
            break;
        case 9:
            p->mUnk_3cc = 8;
            break;
        case 10:
            p->mUnk_3cc = 9;
            break;
        case 11:
            p->mUnk_3cc = 11;
            break;
        case 12:
            p->mUnk_3cc = 12;
            break;
    }
    p->mUnk_3d0 = p->mKartModelsEntry->mUnk_004 % 3;
    if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (!(p->mSoundSource.mUnk_34 & 1)) {
            func_0210cfbc(&p->mSoundSource, 2, 1);
        }
        if (data_021759c0->mUnk_00c == 2) {
            func_0210b850(&p->mUnk_518);
        }
    } else {
        if (p->mSoundSource.mUnk_34 & 1) {
            func_0210cfbc(&p->mSoundSource, 2, 1);
        }
        func_0210b850(&p->mUnk_518);
    }
}

void func_020719d0(Kart *p) {
    Unk02024eec *q;
    Unk02024eec_40 t;
    s32 i;
    s32 k;
    s32 m;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 g;

    p->mUnk_450.mUnk_00 = 0xa5;
    q = (Unk02024eec *) &p->mUnk_450;
    q->mUnk_04 = 0x64;
    q->mUnk_08 = -1;
    q->mUnk_0c = 0;
    q->mUnk_10 = 0;
    q->mUnk_14 = 0;
    q->mUnk_18 = DivFixed12(0x300000, 0xd000 - p->mPhysicalParam->mBaseSpeedLimit);
    q->mUnk_1c = DivFixed12(0x580000, p->mPhysicalParam->mBaseSpeedLimit);
    q->mUnk_20 = DivFixed12(0x480000, p->mPhysicalParam->mBaseSpeedLimit);
    q->mUnk_24 = DivFixed12(0x280000, p->mPhysicalParam->mBaseSpeedLimit);
    q->mUnk_28 = 0;
    q->mUnk_2c = 0;
    q->mUnk_30 = 0;
    q->mUnk_34 = -1;
    q->mUnk_38 = -1;
    switch (p->mKartModelsEntry->mUnk_004 / 3) {
        case 0:
            k = 4;
            break;
        case 1:
            k = 0;
            break;
        case 2:
            k = 1;
            break;
        case 3:
            k = 2;
            break;
        case 4:
            k = 5;
            break;
        case 5:
            k = 6;
            break;
        case 6:
            k = 7;
            break;
        case 7:
            k = 3;
            break;
        case 8:
            k = 10;
            break;
        case 9:
            k = 8;
            break;
        case 10:
            k = 9;
            break;
        case 11:
            k = 11;
            break;
        case 12:
            k = 12;
            break;
    }
    q->mUnk_68 = k;
    i = func_0202578c(p->mKartModelsEntry->mUnk_004);
    m = i * 0x1c;
    a = *(s32 *) (data_02161ae8 + m);
    b = *(s32 *) (data_02161aec + m);
    c = *(s32 *) (data_02161af0 + m);
    d = *(s32 *) (data_02161af4 + m);
    e = *(s32 *) (data_02161af8 + m);
    f = *(s32 *) (data_02161afc + m);
    g = *(s32 *) (data_02161b00 + m);
    t.mUnk_00 = i;
    t.mUnk_04 = a;
    t.mUnk_08 = b;
    t.mUnk_0c = c;
    t.mUnk_10 = d;
    t.mUnk_14 = e;
    t.mUnk_18 = f;
    t.mUnk_1c = g;
    if (p->mIndex != data_021759c0->mEntryIndex) {
        b = c;
    }
    if (p->mIndex != data_021759c0->mEntryIndex) {
        a = c;
    }
    t.mUnk_20 = b;
    t.mUnk_24 = a;
    q->mUnk_40_m = t;
}

PlayingSound *func_020719bc(SoundSource *p, u32 a) {
    u32 value0 = (u32) p;
    u32 value1 = a;
    u32 value2;
    u32 value3;
    u32 value12;
    value12 = (u32) &StartSound;
    value2 = 0x7fu;
    value3 = 0u;
    return StartSound((SoundSource *) value0, value1, value2, value3);
}

void func_020719a8(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    u32 value12;
    value2 = 0x7fu;
    value3 = 0u;
    StartSoundWhileRequested((SoundSource *) value0, value1, value2, value3);
}

void func_02071980(void *p, int b) {
    func_0210b2a8((Kart *) p, b, ((Kart *) p)->mSurfaceKind, ((Kart *) p)->mSurfaceVariant, ((Kart *) p)->mUnk_500);
}

void func_02071958(Kart *p, s32 b) {
    func_0210b564(&p->mSoundSource, b, p->mSurfaceKind, p->mSurfaceVariant, p->mUnk_500);
}

void func_02071944(void *p, int v1) {
    SoundSource *v2 = p;
    u32 v3 = (u32) v1;
    u32 v4;
    u32 v5;
    u32 v6;
    v6 = (u32) &StartSound;
    v4 = 0x7fu;
    v5 = 0u;
    StartSound(v2, v3, v4, v5);
    return;
}

void func_02071914(void *p, int a) {
    if (StartSoundWhileRequested((SoundSource *) p, a, 0x7f, 0) != NULL) {
        ((Kart *) p)->mUnk_488 = a;
    }
}

void func_020718c8(void *p, int v1) {
    int v;

    v = func_02086080(((Kart *) p)->mIndex);
    func_0210ddf4(&data_0217d284, v + func_0210a588(), func_02071914, p, v1);
}

void func_02071894(Kart *p) {
    if (p->mUnk_48 & 0x840) {
        return;
    }
    func_0210af40(p, p->mUnk_3cc, 7);
}

void func_02071788(Kart *p) {
    p->mUnk_3fe++;
    if (p->mUnk_3fe >= p->mUnk_400) {
        p->mUnk_3fe = 0;
        p->mUnk_4c &= ~8;
        return;
    }
    if (p->mUnk_3fc == 0) {
        p->mUnk_404 = data_02154be4[p->mUnk_3fe];
        p->mUnk_408 = data_02154c20[p->mUnk_3fe];
        p->mUnk_418 = 0x1000;
        p->mUnk_414 = p->mUnk_418;
    } else if (p->mUnk_3fc == 1) {
        p->mUnk_404 = data_02154c5c[p->mUnk_3fe];
        p->mUnk_408 = data_02154c98[p->mUnk_3fe];
        p->mUnk_418 = 0x1000;
        p->mUnk_414 = p->mUnk_418;
    } else if (p->mUnk_3fc == 2) {
        p->mUnk_404 = 0x1000;
        p->mUnk_408 = data_02154c20[p->mUnk_3fe];
        p->mUnk_414 = data_02154cd4[p->mUnk_3fe];
        p->mUnk_418 = data_02154d10[p->mUnk_3fe];
    }
}

void func_02071568(Kart *p) {
    s32 f;
    u16 i;
    u16 j;
    s32 v;
    s32 s;
    s32 t;

    p->mUnk_4ec = p->mUnk_4ec + p->mUnk_4e8;
    t = p->mUnk_4ec - 0x8000;
    if (t >= 0) {
        p->mUnk_4ec = t;
    }
    f = p->mUnk_4ec & 0xfff;
    i = (u16) (p->mUnk_4ec >> 12);
    j = i + 1;
    if (j >= 8) {
        j = 0;
    }
    p->mUnk_4f0.x = data_02154b64[i] + (s32) (((s64) ((data_02154b64[j] - data_02154b64[i]) >> 1) * f) >> 12);
    p->mUnk_4f0.y = data_02154b84[i] + (s32) (((s64) ((data_02154b84[j] - data_02154b84[i]) >> 1) * f) >> 12);
    p->mUnk_4f0.z = data_02154ba4[i] + (s32) (((s64) ((data_02154ba4[j] - data_02154ba4[i]) >> 1) * f) >> 12);
    v = p->mUnk_4d4;
    s = (s32) (((s64) v * 0x333) >> 12);
    if (v > 0xf33) {
        t = (s32) (((s64) ((v - 0xf33) * 0x32) * 0x19a) >> 12);
        if (t > 0x19a) {
            t = 0x19a;
        }
        t = t + 0x333;
        s = (s32) (((s64) v * t) >> 12);
    } else if (v > 0xd9a) {
        t = (s32) (((s64) ((v - 0xd9a) * 0x32) * 0x52) >> 12);
        if (t > 0x52) {
            t = 0x52;
        }
        t = t + 0x333;
        s = (s32) (((s64) v * t) >> 12);
    }
    p->mUnk_4f0.x = p->mUnk_4f0.x + (s32) (((s64) p->mUnk_4f0.x * s) >> 12);
    p->mUnk_4f0.y = p->mUnk_4f0.y + (s32) (((s64) p->mUnk_4f0.y * s) >> 12);
    p->mUnk_4f0.z = p->mUnk_4f0.z + (s32) (((s64) p->mUnk_4f0.z * s) >> 12);
}

void func_020713a0(Kart *p) {
    s32 t;

    if (p->mUnk_4e4 <= 2) {
        p->mHeadingAngleOffsetPerFrame = p->mUnk_4e2 * 0x3c + p->mHeadingAngleOffsetPerFrame;
        if (p->mHeadingAngleOffsetPerFrame > 0x17c) {
            p->mHeadingAngleOffsetPerFrame = 0x17c;
        } else if (p->mHeadingAngleOffsetPerFrame < -0x17c) {
            p->mHeadingAngleOffsetPerFrame = -0x17c;
        }
        p->mHeadingAngleOffset = p->mHeadingAngleOffset + p->mHeadingAngleOffsetPerFrame;
        t = p->mHeadingAngleOffset;
        if ((t > 0 ? t : -t) > 0x1770) {
            if ((t > 0 && p->mUnk_4e2 > 0) || (t < 0 && p->mUnk_4e2 < 0)) {
                p->mUnk_4e2 *= -1;
                p->mUnk_4e4 = p->mUnk_4e4 + 1;
            }
        }
        p->mUnk_4d4 = 0x1000;
    } else {
        p->mHeadingAngleOffsetPerFrame = p->mUnk_4e2 * 0x3c + p->mHeadingAngleOffsetPerFrame;
        if (p->mHeadingAngleOffsetPerFrame > 0xd2) {
            p->mHeadingAngleOffsetPerFrame = 0xd2;
        } else if (p->mHeadingAngleOffsetPerFrame < -0xd2) {
            p->mHeadingAngleOffsetPerFrame = -0xd2;
        }
        p->mHeadingAngleOffset = p->mHeadingAngleOffset + p->mHeadingAngleOffsetPerFrame;
        p->mUnk_4d4 = (s32) (((s64) p->mUnk_4d4 * 0xf5c) >> 12);
        t = p->mHeadingAngleOffset;
        if ((t > 0 && p->mUnk_4e2 > 0) || (t < 0 && p->mUnk_4e2 < 0)) {
            p->mHeadingAngleOffset = 0;
            p->mUnk_4c &= ~0x20000000;
            func_02068a64(p, 0, 1);
            p->mUnk_44 |= 0x1000000;
        }
    }
}

void func_02071318(Kart *p, s32 a) {
    s32 k;

    k = p->mState;
    if (k != 0 && k != 6) {
        return;
    }
    if (a == 2) {
        p->mUnk_3fc = 2;
    } else if (p->mUnk_44 & 2) {
        p->mUnk_3fc = 1;
    } else if (p->mAirborneFrames > 0xa) {
        p->mUnk_3fc = 1;
    } else {
        p->mUnk_3fc = 0;
    }
    p->mUnk_3fe = 0;
    p->mUnk_400 = 0xf;
    p->mUnk_4c |= 8;
}

void func_020710b0(Kart *p, s32 b) {
    Unk0212c400 **h;
    PlayingSound *d;

    if (b == 0) {
        p->mUnk_48 |= 0x40000;
        p->mUnk_44 &= ~0x10;
    }
    p->mUnk_48 &= 0xdfe77fdf;
    p->mUnk_238 = 0;
    p->mUnk_538.mUnk_00 = 0;
    p->mUnk_23c = 0;
    if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (!(p->mUnk_4c & 0x10000000) && !(p->mUnk_48 & 0x4000000)) {
            ResetCameraHalfFovAngleGoal();
        }
        func_02055c5c();
    }
    if (p->mUnk_4c & 0x2000) {
        p->mUnk_4c &= ~0x2000;
        p->mUnk_d8 = 0x1000;
        if (!(p->mUnk_4c & 0x8000000)) {
            func_0207b0d0(p);
        }
        func_02080ee4(p);
    }
    func_02080fb8(p);
    p->mUnk_44 &= 0xfffff7f4;
    p->mTurnDirection = 0;
    p->mUnk_2fc = 0;
    p->mUnk_302 = 0;
    p->mUnk_300 = p->mUnk_302;
    p->mUnk_30c = 0;
    func_0208c534(func_0208c5b8(p->mIndex));
    p->mState = 0;
    p->mUnk_4c &= ~0x30;
    p->mUnk_48 &= ~0x20000;
    func_02068a64(p, 0, 1);
    p->mUnk_44 |= 0x80000000;
    func_02072600(p);
    func_02070f8c(p);
    if (!(p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        return;
    }
    func_02073f90();
    switch (data_021759c0->mCourseId) {
        case COURSE_ID_AIRSHIP:
            func_02089d14(0);
            d = StartSound((SoundSource *) p, 0x15c, 0x7f, 0);
            if (d != NULL) {
                d->mUnk_19 |= 0x10;
            }
            h = func_02108e6c(7);
            if (!(data_0217c780 & 1)) {
                return;
            }
            if (data_0217d084.mUnk_0c == 0) {
                return;
            }
            if (h[0] != NULL) {
                func_0212c6f0(h, 0);
            }
            if (h[0] != NULL) {
                func_0212c6f0(h, 0);
            }
            func_0212ecc0(h, 0, 0x1d2);
            break;
        case COURSE_ID_PINBALL:
            d = StartSound((SoundSource *) p, 0x15b, 0x7f, 0);
            if (d != NULL) {
                d->mUnk_19 |= 0x10;
            }
            break;
    }
}

void func_02070f8c(Kart *p) {
    s32 q[2];
    Vec3 v;
    Vec3 u;
    Camera *r;
    Vec3 *c;
    BOOL v1;
    s32 n;
    s32 i;
    s32 *v2;
    s32 *w;

    v = data_0216553c;
    v1 = TRUE;
    r = GetCurrentCamera();
    c = &r->mPos;
    if (c->x > -0x64f000) {
        if (c->x < -0x3cb000) {
            if (c->z > -0x1ad7000) {
                if (c->z < -0x164d000) {
                    v1 = FALSE;
                }
            }
        }
    }
    if (v1 != FALSE) {
        u = data_02165548;
        w = q;
        q[0] = data_02165510[0];
        q[1] = data_02165510[1];
        n = 3;
        v2 = (s32 *) &u;
        if (!(p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            n = 2;
            v2 = w;
        }
        for (i = 0; i < n; i++) {
            StartEffect(*v2, &v);
            v2++;
        }
    } else {
        StartEffect((p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 0x47 : 0x52, &v);
    }
}

static inline s32 func_020708a4_inline(Vec3 *v, Vec3 *n) {
    if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z < 0x10) {
        return 0;
    }
    return Vec3NormalizeAndGetLengthUnchecked(v, n);
}

void func_020708a4(Kart *p) {
    Unk0206ceb4 *s;
    u16 i;
    s32 d;
    s32 k;
    s32 t;
    u32 w;
    Vec3 a;
    Vec3 b;
    Vec3 n;
    Vec3 c;
    Vec3 e;
    Vec3 f;
    Vec3 g;
    Vec3 h;
    Vec3 l;
    Unk02012f58 m2;
    s32 m1[9];
    Vec3 q;

    b = data_02154f94;
    i = *gCourseMap->mUnk_fc;
    a.x = gCourseMap->mUnk_34[i].mPos.x;
    a.y = gCourseMap->mUnk_34[i].mPos.y;
    a.z = gCourseMap->mUnk_34[i].mPos.z;
    b.x = gCourseMap->mUnk_34[*gCourseMap->mUnk_fc].mUnk_0c.x;
    b.y = gCourseMap->mUnk_34[*gCourseMap->mUnk_fc].mUnk_0c.y;
    b.z = gCourseMap->mUnk_34[*gCourseMap->mUnk_fc].mUnk_0c.z;
    k = (u16) (((s64) b.y * 0xb60b60b60bLL + 0x80000000LL) >> 44) >> 4;
    Matrix3x3FromPairY(m1, gPairsByAngle[k * 2], gPairsByAngle[k * 2 + 1]);
    Vec3MultiplyMatrix3x3(&data_02154f70, m1, &e);
    func_021035ac(p->mIndex);

    w = p->mUnk_4c;
    if (!(w & 0x20000) && (w & 0x8000000)) {
        s = &p->mUnk_538;
        if (s->mUnk_1c <= 0x190) {
            s->mUnk_1c = 0x190;
            p->mUnk_4c |= 0x20000;
            func_02079f70(p->mKartModelsEntry, func_0207a134(), func_0207a11c(), func_0207a104());
        }
    }
    if (p->mUnk_4c & 0x8000000) {
        func_02069134(p);
    }
    w = p->mUnk_4c;
    if (w & 0x10000000) {
        func_0206938c(p);
    } else {
        if (w & 0x80) {
            func_0206a354(p);
        }
        if (p->mUnk_4c & 0x10000) {
            func_02069f6c(p);
        }
        if (p->mUnk_7c & 0x402000) {
            func_0206988c(p);
        }
    }

    if (p->mUnk_4c & 0x2000) {
        s = &p->mUnk_538;
        if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            func_0210ddf4(&data_0217d26c, func_02086080(p->mIndex), func_020718c8, p, 0xa3);
        }
        s->mUnk_0a++;
        if (s->mUnk_0a > 0xb4 && (p->mUnk_4c & 0x2000)) {
            p->mUnk_4c &= ~0x2000;
            p->mUnk_d8 = 0x1000;
            if (!(p->mUnk_4c & 0x8000000)) {
                func_0207b0d0(p);
            }
            func_02080ee4(p);
        }
    }

    if (p->mUnk_4c & 0x40) {
        s = &p->mUnk_538;
        func_0208181c(p->mIndex);
        if ((p->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) && p->mKartModelsEntry->mUnk_008->mUnk_1a == 0) {
            func_02068a64(p, 2, 1);
        }
        s->mUnk_06++;
        if (s->mUnk_06 > 0x1c2) {
            p->mUnk_4c &= ~0x40;
            func_0207b1a8(p);
            p->mUnk_29c = 0;
            func_020817b8(p->mIndex);
            func_02068a64(p, 0, 1);
            if ((p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && data_021759c0->mUnk_00c == 0) {
                func_02106dc8();
            }
            if (p->mUnk_4c & 0x2000) {
                func_0207b13c(p);
            }
        }
    }

    data_0217566a[p->mEntryIndex].mBitMask = 0xe04;
    Vec3CrossUnrounded(&data_02154f7c, &e, &f);
    Vec3Sub(&p->mPos, &a, &g);
    g.y = 0;
    Vec3AddScaled(Vec3DotUnrounded(&f, &g), &f, &a, &a);
    Vec3DotUnrounded(&f, &g);
    Vec3Sub(&a, &p->mPos, &c);
    d = func_020708a4_inline(&c, &c);

    if (Vec3DotUnrounded(&c, &e) <= 0) {
        func_02055c5c();
        p->mUnk_48 &= ~0x10000;
        func_01ffa11c(p, &p->mUnk_244);
        p->mUnk_48 &= ~0x40000;
        p->mUnk_3e8 = (s16) ((s32) (((s64) b.x * 0x4000) >> 12) >> 12) + 0x32;
        if ((p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && data_021759c0->mCourseId == COURSE_ID_AIRSHIP) {
            func_0212c6f0(func_02108e6c(7), 0x14);
        }
    } else {
        if (d > 0x64000) {
            p->mUnk_50 = c;
        }
        h = p->mUnk_50;
        h.y = 0;
        p->mUnk_3a8 = 0x1000;
        func_020708a4_inline(&h, &h);
        p->mHeadingAngle = (s32) (((s64) func_02148538(h.x, h.z) * 0x28be60d) >> 12) >> 12;
        q = data_02165524;
        QuaternionFromAxisAngle(&q, p->mHeadingAngle, (Vec4 *) &p->mUnk_e0);
        Vec3CrossUnrounded(&data_02154f7c, &p->mUnk_50, &l);
        Vec3CrossUnrounded(&p->mUnk_50, &l, &n);
        if (p->mUnk_234 > -5000) {
            p->mUnk_234 -= 300;
            if (p->mUnk_234 < -5000) {
                p->mUnk_234 = -5000;
            }
        }
        Matrix4x3FirstThreeRowsFromVec3AndPair(&m2, &p->mUnk_120, gPairsByAngle[((u16) p->mUnk_234 >> 4) * 2],
                                               gPairsByAngle[((u16) p->mUnk_234 >> 4) * 2 + 1]);
        Vec3MultiplyMatrix3x3(&n, &m2.mUnk_00[0].x, &n);
        p->mUnk_244 = n;
        func_01ff9f60(p, &n);
    }

    p->mForwardSpeed = 0x1e000;
    t = p->mForwardSpeed;
    m2.mUnk_00[3].x = ((s64) p->mUnk_50.x * t) >> 12;
    m2.mUnk_00[3].y = ((s64) p->mUnk_50.y * t) >> 12;
    m2.mUnk_00[3].z = ((s64) p->mUnk_50.z * t) >> 12;
    p->mUnk_68 = p->mUnk_50;
    if (d < 0x3e8000) {
        t = (s32) (((s64) d * 0x29) >> 12) + 0x14000;
        if (p->mForwardSpeed > t) {
            p->mForwardSpeed = t;
        }
    }
    p->mVelocity = m2.mUnk_00[3];
    Vec3Add(&p->mPos, &p->mVelocity, &p->mPos);
}

void func_020705fc(Kart *p, u32 b) {
    Vec3 a;
    Vec3 e;
    s32 m[9];
    Vec3 v;
    Vec3 w;
    Unk0212c400 **h;
    u16 i;
    s32 k;

    func_020710b0(p, 1);
    p->mVerticalSpeed = 0x3000;
    i = gCourseMap->mUnk_fc[b];
    a.x = gCourseMap->mUnk_34[i].mPos.x;
    a.y = gCourseMap->mUnk_34[i].mPos.y;
    a.z = gCourseMap->mUnk_34[i].mPos.z;
    k = (u16) (((s64) gCourseMap->mUnk_34[gCourseMap->mUnk_fc[b]].mUnk_0c.y * 0xb60b60b60bLL + 0x80000000LL) >> 44) >>
        4;
    Matrix3x3FromPairY(m, gPairsByAngle[k * 2], gPairsByAngle[k * 2 + 1]);
    Vec3MultiplyMatrix3x3(&data_02154f70, m, &e);
    if (data_021759c0->mMode == MODE_BATTLE) {
        Vec3Sub(&a, &p->mPos, &v);
        func_020a21bc(p->mIndex, (s32) &v);
    }
    p->mPos = a;
    p->mPrevPos = p->mPos;
    p->mUnk_98 = p->mPrevPos;
    p->mForwardSpeed = 0x5000;
    p->mUnk_50 = e;
    p->mUnk_68 = p->mUnk_50;
    p->mHeadingAngle = (s32) (((s64) func_02148538(e.x, e.z) * 0x28be60dLL) >> 12) >> 12;
    w = data_02165524;
    QuaternionFromAxisAngle(&w, p->mHeadingAngle, (Vec4 *) &p->mUnk_e0);
    if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        SetupCameraBehindKart();
        if (data_0217c780 & 1) {
            h = (Unk0212c400 **) func_0210e128(func_02108ea0(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (h[0] != NULL) {
                    func_0212c6f0(h, 0);
                }
                if (h[0] != NULL) {
                    func_0212c6f0(h, 0);
                }
                func_0212ecc0(h, 0, 0x159);
            }
        }
    }
    if (!(p->mUnk_7c & 2)) {
        return;
    }
    if (data_021759c0->mMode != MODE_BATTLE) {
        return;
    }
    func_02089754(p->mUnk_310, func_02040da8(b));
}

void func_02070484(Kart *p, Vec4 *q) {
    Unk02012f58 m1;
    Unk02012f58 m2;
    Vec3 v1;
    Vec3 v2;
    s32 d;
    u16 k;
    u16 t;

    if (p->mVelocityLength < 0x1000) {
        return;
    }
    if (Vec3DotUnrounded(&p->mUnk_12c, &data_02154f7c) <= 0) {
        return;
    }
    p->mUnk_234 = p->mUnk_234 + p->mUnk_3e8;
    k = p->mHeadingAngle;
    t = (u16) p->mUnk_234;
    Matrix4x3FromPairY(&m1, gPairsByAngle[(k >> 4) * 2], gPairsByAngle[(k >> 4) * 2 + 1]);
    Vec3MultiplyMatrix4x3(&data_02154f88, &m1, &v1);
    Matrix4x3FromVec3AndPair(&m2, &v1, gPairsByAngle[(t >> 4) * 2], gPairsByAngle[(t >> 4) * 2 + 1]);
    Vec3MultiplyMatrix4x3(&data_02154f7c, &m2, &v2);
    func_01ffd0e8(q, &data_02154f7c, &v2);
    if (p->mUnk_48 & 0x80000000) {
        q->x = -q->x;
        q->y = -q->y;
        q->z = -q->z;
        q->w = -q->w;
    }
    if (p->mUnk_44 & 2) {
        return;
    }
    d = Vec3DotUnrounded(&p->mVelocityDirection, &p->mUnk_138);
    if (d <= 0) {
        d = -d;
    }
    p->mUnk_3f8 = d;
    if (p->mUnk_3f8 < 0xb33) {
        p->mUnk_3f8 = 0xb33;
    }
}

BOOL func_02070398(Kart *p, u32 b, void *c) {
    u32 w;

    w = p->mUnk_44;
    if (!(w & 0xc2200) && !(p->mUnk_7c & 0x400)) {
        if (!(w & 0xc0000) && !(p->mUnk_4c & 0x100) && p->mUnk_1fc.x == 0 && p->mUnk_1fc.y == 0 && p->mUnk_1fc.z == 0 &&
            p->mUnk_274 == 0 && p->mUnk_4d0 >= 0x64) {
            p->mPos.x = p->mPrevPos.x;
            p->mPos.z = p->mPrevPos.z;
        } else {
            func_020d5aa0(c, b, (Unk020e04b0 *) p->mUnk_208, &p->mPos, NULL);
        }
        p->mVelocity = data_02154f94;
        p->mVelocityLength = 0;
        p->mUnk_44 |= 0x1000;
        return TRUE;
    }
    return FALSE;
}

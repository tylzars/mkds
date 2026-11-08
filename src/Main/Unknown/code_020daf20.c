#include "Main/Unknown/code_020daf20.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020d8b88.h"
#include "code_02146cbc.h"
#include "code_02148538.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/code_020dda38.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d8648.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d88fc.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"

#pragma thumb off

Unk020dbf2c *CreateDossunKindData(void) {
    Unk020dbf2c *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_0215828c;
    return kindData;
}

Unk020dbed0 *CreateDossunDrawList(void) {
    Unk020dbed0 *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gDossunDrawList = drawList;
    *drawList = data_02158260;
    func_020d49d8(&gDossunDrawList);
    return gDossunDrawList;
}

Unk020dbe74 *CreateDossunUpdateList(void) {
    Unk020dbe74 *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gDossunUpdateList = updateList;
    *updateList = data_02158238;
    SetUpdateListSlot(&gDossunUpdateList);
    return gDossunUpdateList;
}

void DrawDossun(void *unused0, Dossun *dossun, void *unused1, s32 maxAlpha) {
    MtxFx43 *drawMatrix;
    drawMatrix = &dossun->mUnk_00.mMatrix;
    if (dossun->mUnk_b4 != 0) {
        drawMatrix = &gDossunDrawMatrix;
        MTX_RotY33_((s32 *) &gDossunDrawMatrix, gPairsByAngle[((u16) dossun->mUnk_ba >> 4) * 2],
                    gPairsByAngle[((u16) dossun->mUnk_ba >> 4) * 2 + 1]);
        MTX_Concat33((const s32 *) &gDossunDrawMatrix, (const s32 *) &dossun->mUnk_00.mMatrix,
                     (s32 *) &gDossunDrawMatrix);
    }
    drawMatrix->mUnk_00[3].x = dossun->mUnk_00.mPos.x >> 4;
    drawMatrix->mUnk_00[3].y = dossun->mUnk_00.mPos.y >> 4;
    drawMatrix->mUnk_00[3].z = dossun->mUnk_00.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gDossun, drawMatrix, &dossun->mUnk_00.mScale, maxAlpha);
    DrawShadowWithMaxAlpha(gDossunShadow, drawMatrix, &dossun->mUnk_00.mScale, maxAlpha);
}

void UpdateDossun(void *unused, Dossun *dossun) {
    Unk0210b7a8 soundRequest;
    GroupFollower *follower;
    CourseMapGroupEntry *fromEntry;
    s32 n;
    s32 speed;
    s32 t;
    s32 sine;
    dossun->mEnteredState5 = FALSE;
    follower = &dossun->mFollower;
    if (dossun->mUnk_b4 != 0) {
        dossun->mUnk_ba += dossun->mUnk_b8;
        n = dossun->mUnk_b8;
        if (n > 0x3e8 || n < -0x3e8) {
            if (dossun->mState < 4) {
                dossun->mUnk_b8 = (n * 0xfa00) >> 16;
            } else {
                dossun->mUnk_b8 = (n * 0xf80c) >> 16;
            }
        } else if (dossun->mUnk_b4 == 2) {
            if (n * dossun->mUnk_ba <= 0) {
                return;
            }
            if (n * n <= dossun->mUnk_ba * dossun->mUnk_ba) {
                return;
            }
            dossun->mUnk_b8 = 0;
            dossun->mUnk_ba = dossun->mUnk_b8;
            dossun->mUnk_b4 = 0;
            dossun->mUnk_c0 = 0;
            dossun->mTimer = 0x1e;
            dossun->mState = 0;
            return;
        }
        if (dossun->mUnk_b4 != 1) {
            return;
        }
        speed = follower->mSpeed;
        if (dossun->mState < 4) {
            if (speed > 0x4000) {
                t = ((s64) speed * 0xf85) >> 12;
                follower->mSpeed = t;
                follower->mProgressStep =
                    ((s64) t * follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength) >> 12;
            }
        } else {
            if (speed > 0x800) {
                t = ((s64) speed * 0xe66) >> 12;
                follower->mSpeed = t;
                follower->mProgressStep =
                    ((s64) t * follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength) >> 12;
            }
        }
        if (AdvanceGroupFollower(follower) != FALSE) {
            dossun->mUnk_00.mPos = follower->mFromEntry->mPos;
            dossun->mUnk_00.mPos.y += dossun->mHeightOffset;
            if (follower->mForward != 0) {
                follower->mProgress = 0;
            } else {
                ReverseGroupFollower(follower);
                SetGroupFollowerSegmentEnd(follower);
            }
            dossun->mUnk_b4 = 2;
            return;
        }
        GetGroupFollowerLinearPosition(follower, &dossun->mUnk_00.mPos);
        dossun->mUnk_00.mPos.y += dossun->mHeightOffset;
        return;
    }
    switch (dossun->mState) {
        case 0:
            dossun->mTimer--;
            if (dossun->mTimer >= 0) {
                return;
            }
            dossun->mState++;
            t = dossun->mUnk_f0 != 0 ? 0xc00 : 0x3000;
            follower->mSpeed = t;
            follower->mProgressStep =
                ((s64) t * follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength) >> 12;
            return;
        case 1:
            if (dossun->mUnk_f0 != 0) {
                StartMapObjectSoundWhileRequested(&dossun->mUnk_00, 0x18b);
            }
            break;
        case 2:
            dossun->mTimer--;
            if (dossun->mTimer < 0 && dossun->mUnk_c2 < 0x1555) {
                dossun->mState++;
                dossun->mUnk_a8 = -dossun->mUnk_100;
                return;
            }
            dossun->mUnk_c2 += 0x1555;
            dossun->mUnk_00.mPos.y = dossun->mUnk_ac;
            sine = gPairsByAngle[(dossun->mUnk_c2 >> 4) * 2];
            dossun->mUnk_00.mPos.y += (s32) (((s64) sine * dossun->mUnk_c4) >> 12);
            return;
        case 3:
            dossun->mUnk_a8 += dossun->mUnk_104;
            dossun->mUnk_00.mPos.y -= dossun->mUnk_a8;
            if (dossun->mUnk_00.mPos.y < dossun->mUnk_ac) {
                dossun->mState++;
            }
            return;
        case 4:
            if (dossun->mUnk_a8 < 0x14000) {
                dossun->mUnk_a8 += 0x1000;
                t = dossun->mUnk_a8;
                follower->mSpeed = t;
                follower->mProgressStep =
                    ((s64) t * follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength) >> 12;
            }
            break;
        case 5:
            dossun->mTimer--;
            if (dossun->mTimer >= 0) {
                return;
            }
            dossun->mState++;
            t = dossun->mUnk_108;
            follower->mSpeed = t;
            follower->mProgressStep =
                ((s64) t * follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength) >> 12;
            return;
        case 6:
            break;
    }
    if (AdvanceGroupFollower(follower) != FALSE) {
        switch (follower->mFromEntry->mUnk_10) {
            case 0:
                n = 0;
                break;
            case 1:
                n = 2;
                break;
            case 2:
                n = 5;
                break;
            default:
                n = 0;
                break;
        }
        dossun->mState = n;
        if (dossun->mState == 2) {
            dossun->mUnk_ac = dossun->mUnk_00.mPos.y;
            dossun->mUnk_c2 = 0;
        }
        if (dossun->mState == 5) {
            fromEntry = follower->mFromEntry;
            if (func_020d4ddc(&dossun->mUnk_00) == FALSE) {
                if (dossun->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                    n = 2;
                } else if (dossun->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                    n = 3;
                } else {
                    n = 4;
                }
                soundRequest.mSoundId = 0x166;
                soundRequest.mPositionSource = &dossun->mUnk_00.mPos;
                soundRequest.mUnk_08 = n;
                soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&dossun->mUnk_00.mPos);
                func_0210b7a8(&soundRequest);
            }
            StartCameraWobbleAtDistance(dossun->mUnk_00.mDistanceSquaredAndFlags & ~0xc000001f, 0x1000);
            if ((dossun->mUnk_00.mDistanceSquaredAndFlags & 3) == 0) {
                StartEffect(0x59, &fromEntry->mPos);
                StartEffect(0x5a, &fromEntry->mPos);
            }
            dossun->mEnteredState5 = TRUE;
        }
        dossun->mTimer = follower->mFromEntry->mUnk_0e;
        if (dossun->mTimer != 0) {
            dossun->mUnk_00.mPos = follower->mPath->mSegments[follower->mSegmentIndex].mPoints[0];
            dossun->mUnk_00.mPos.y += dossun->mHeightOffset;
            follower->mProgress = 0;
            return;
        }
    }
    GetGroupFollowerLinearPosition(follower, &dossun->mUnk_00.mPos);
    dossun->mUnk_00.mPos.y += dossun->mHeightOffset;
}

u32 CollideKartWithDossun(Dossun *dossun, Kart *kart, u8 *b, u8 *c) {
    Vec3 kartOffset;
    Vec3 toNextEntry;
    Vec3 centerOffset;
    GroupFollower *follower;
    s32 speed;
    s64 m;
    s32 verticalOffset;
    s64 n;
    follower = &dossun->mFollower;
    if (*b == 1) {
        if ((dossun->mUnk_c0 & (1 << kart->mIndex)) == 0 || dossun->mUnk_bc + 0xf < GetRaceUpdateFrames()) {
            VEC_Subtract(&kart->mCollisionCenter, &dossun->mUnk_00.mPos, &kartOffset);
            VEC_Subtract(&follower->mToEntry->mPos, &dossun->mUnk_00.mPos, &toNextEntry);
            toNextEntry.y += dossun->mHeightOffset;
            if (Vec3DotUnrounded(&kartOffset, &toNextEntry) > 0) {
                ReverseGroupFollower(follower);
            }
            if (dossun->mState < 4) {
                speed = 0xa800;
            } else {
                speed = 0x8000;
            }
            speed = speed - (s32) (((s64) (0x1000 - dossun->mUnk_00.mScale.y) * 0x2000) >> 12);
            follower->mSpeed = speed;
            follower->mProgressStep =
                ((s64) speed * follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength) >> 12;
            dossun->mUnk_b4 = 1;
            dossun->mUnk_b8 = 0x1b58;
            if ((s64) kartOffset.z * kart->mVelocity.x - (s64) kartOffset.x * kart->mVelocity.z < 0) {
                dossun->mUnk_b8 = -dossun->mUnk_b8;
            }
            StartSoundIfKartStarOrKiller(&dossun->mUnk_00, kart);
            dossun->mUnk_c0 |= 1 << kart->mIndex;
            dossun->mUnk_bc = GetRaceUpdateFrames();
        }
    }
    if (dossun->mState == 4 || dossun->mEnteredState5 != FALSE) {
        VEC_Subtract(&kart->mCollisionCenter, &dossun->mUnk_00.mPos, &centerOffset);
        n = ((s64) centerOffset.x * centerOffset.x + (s64) centerOffset.z * centerOffset.z) * 5;
        verticalOffset = centerOffset.y;
        m = ((s64) verticalOffset * verticalOffset) << 2;
        if (verticalOffset < 0 && n < m) {
            return GetKartMapObjectResponseByKind(dossun->mUnk_00.mFlags & 0x800, kart->mItemEffect, 4, 4);
        }
    }
    return *c;
}

s32 func_020db4c4(Dossun *dossun) {
    s32 progress;
    s32 state;
    progress = GetGroupFollowerProgress(&dossun->mFollower);
    state = dossun->mState;
    if (state < 4) {
        if (dossun->mUnk_f0 != 0) {
            return 0;
        }
        return 0x1000;
    }
    switch (dossun->mUnk_b4) {
        case 0:
            switch (state) {
                case 4:
                    progress = 0x1000 - progress;
                    break;
                case 5:
                    progress = 0;
                    break;
                case 6:
                    break;
            }
            break;
        case 2:
            progress = 0x1000;
            break;
    }
    return progress;
}

#pragma thumb on
void func_020db430(Dossun *dossun) {
    GroupFollower *follower;
    s32 state;
    follower = &dossun->mFollower;
    SetupGroupFollowerAtEntry(follower, dossun->mStartEntryIndex, 1);
    GetGroupFollowerLinearPosition(follower, &dossun->mUnk_00.mPos);
    dossun->mUnk_00.mPos.y += dossun->mHeightOffset;
    switch (follower->mFromEntry->mUnk_10) {
        case 0:
            state = 0;
            break;
        case 1:
            state = 2;
            break;
        case 2:
            state = 5;
            break;
        default:
            state = 0;
            break;
    }
    dossun->mState = state;
    dossun->mTimer = follower->mFromEntry->mUnk_0e;
    dossun->mUnk_b4 = 0;
    dossun->mUnk_ba = 0;
    dossun->mUnk_b8 = dossun->mUnk_ba;
    dossun->mUnk_c0 = 0;
    dossun->mUnk_ac = dossun->mUnk_00.mPos.y;
    dossun->mEnteredState5 = FALSE;
}
#pragma thumb off

#pragma thumb on
void CreateDossunAndDossunShadow(void) {
    CreateNsbmd((void **) &gDossun, FindCourseMapObjFile("dossun.nsbmd"), NULL);
    CreateShadowModel((void **) &gDossunShadow, FindCourseMapObjFile("dossun_shadow.nsbmd"), 0x3f);
    func_02084968(gDossun, 0x3f, 2, 0x294a);
}
#pragma thumb off

#pragma thumb on
void InitDossun(Dossun *dossun, CourseMapRow *row) {
    dossun->mUnk_f0 = row->mUnk_28;
    InitGroupFollower(&dossun->mFollower, row, dossun->mUnk_f0 != 0 ? 0xc00 : 0x3000);
    dossun->mStartEntryIndex = row->mUnk_2a;
    dossun->mUnk_f4 = ((s64) dossun->mUnk_00.mScale.x * 0x28000) >> 12;
    dossun->mHeightOffset = ((s64) dossun->mUnk_00.mScale.y * 0x2d000) >> 12;
    dossun->mUnk_fc = ((s64) dossun->mUnk_00.mScale.z * 0x1e000) >> 12;
    dossun->mUnk_100 = ((s64) dossun->mUnk_00.mScale.y * 0xf000) >> 12;
    dossun->mUnk_104 = ((s64) dossun->mUnk_00.mScale.y * 0x1000) >> 12;
    dossun->mUnk_108 = ((s64) dossun->mUnk_00.mScale.y * 0x2000) >> 12;
    dossun->mUnk_c4 = ((s64) dossun->mUnk_00.mScale.y * 0x3000) >> 12;
    func_020db430(dossun);
    if (dossun->mUnk_f0 != 0) {
        CreateMapObjectSoundSourceFalloff3(&dossun->mUnk_00);
    } else {
        dossun->mUnk_00.mFarDistanceSquared = gSoundFalloffs[3].mUnk_20;
    }
}
#pragma thumb off

Unk020db268 *CreateKuriboKindData(void) {
    Unk020db268 *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_021581b8;
    return kindData;
}

Unk020db20c *CreateKuriboDrawList(void) {
    Unk020db20c *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gKuriboDrawList = drawList;
    *drawList = data_0215818c;
    func_020d49d8(&gKuriboDrawList);
    return gKuriboDrawList;
}

Unk020db1b0 *CreateKuriboUpdateList(void) {
    Unk020db1b0 *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gKuriboUpdateList = updateList;
    *updateList = data_02158164;
    SetUpdateListSlot(&gKuriboUpdateList);
    return gKuriboUpdateList;
}

void SetupDrawKuribo(void) {
    func_020e6a18(gKuribo);
}

void DrawKuribo(void *unused0, Kuribo *kuribo, void *unused1, u16 d) {
    Vec3 scale;
    Quaternion orientation;
    u16 e;
    NsbmdModel *model;
    if (kuribo->mUnk_cc.mGroupIndex == 0xffff) {
        func_020d7938(&kuribo->mUnk_a4, &gViewYawQuaternion, &orientation);
        Matrix3x3FromQuaternion(&kuribo->mUnk_00.mMatrix, &orientation);
    } else {
        func_020e6d34(GetGroupFollowerSegmentUp(&kuribo->mUnk_cc), &kuribo->mUnk_00.mMatrix);
    }
    scale.z = kuribo->mUnk_00.mScale.z;
    scale.y = ((s64) kuribo->mUnk_00.mScale.y * kuribo->mUnk_c4) >> 12;
    scale.x = ((s64) kuribo->mUnk_00.mScale.x * (((0x1000 - kuribo->mUnk_c4) >> 1) + 0x1000)) >> 12;
    kuribo->mUnk_00.mMatrix.mUnk_00[3].x = kuribo->mUnk_00.mPos.x >> 4;
    kuribo->mUnk_00.mMatrix.mUnk_00[3].y = kuribo->mUnk_00.mPos.y >> 4;
    kuribo->mUnk_00.mMatrix.mUnk_00[3].z = kuribo->mUnk_00.mPos.z >> 4;
    if (kuribo->mUnk_f0 < 0x14) {
        gKuribo->mFrameIndex = kuribo->mUnk_f0;
    } else {
        scale.x = -scale.x;
        gKuribo->mFrameIndex = kuribo->mUnk_f0 - 0x14;
    }
    e = kuribo->mUnk_100;
    model = gKuribo;
    model->mUnk_14 &= ~0x1f0000;
    model->mUnk_14 |= e << 16;
    func_020e67c4(gKuribo, &kuribo->mUnk_00.mMatrix, &scale, 0, d);
}

void UpdateKuribo(void *unused, Kuribo *kuribo) {
    Unk0210b7a8 soundRequest;
    RandomState64 *random;
    s32 falloffIndex;
    kuribo->mUnk_f0++;
    if (kuribo->mUnk_f0 == 0x14 || kuribo->mUnk_f0 == 0x28) {
        if ((kuribo->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
            if (kuribo->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                falloffIndex = 2;
            } else if (kuribo->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                falloffIndex = 3;
            } else {
                falloffIndex = 4;
            }
            soundRequest.mSoundId = 0x182;
            soundRequest.mPositionSource = &kuribo->mUnk_00.mPos;
            soundRequest.mUnk_08 = falloffIndex;
            soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&kuribo->mUnk_00.mPos);
            func_0210b7a8(&soundRequest);
        }
    }
    if (kuribo->mUnk_f0 >= 0x28) {
        if (kuribo->mUnk_f4 != 0) {
            kuribo->mUnk_f0 = 0;
        } else {
            random = &gRaceProgress->mRandom;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            kuribo->mUnk_f0 = ((u64) (u32) (random->mValue >> 32) * 0x28) >> 32;
            kuribo->mUnk_f4 = 1;
        }
    }
    AdvanceStateMachine(&kuribo->mUnk_00.mStateMachine);
}

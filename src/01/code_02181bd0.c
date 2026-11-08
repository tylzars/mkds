#include "01/code_02181bd0.h"

#include "01/code_02181000.h"
#include "01/code_02182000.h"
#include "01/code_02182f98.h"
#include "01/code_02183000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02108000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d8000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020d7da8.h"
#include "code_0212bcac.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"
#include "ITCM/code_01ff8000.h"

Unk0219b250 *data_ov001_021a9b98;

void func_ov001_02182f1c(Coin *coin, Kart *kart) {
    coin->mTimer = 0x1e;
    coin->mUnk_000.mPos.x = kart->mPos.x;
    coin->mUnk_000.mPos.y = kart->mPos.y + 0xc000;
    coin->mUnk_000.mPos.z = kart->mPos.z;
    coin->mUnk_000.mUnk_10.y = 0x3000;
    coin->mState = 1;
    coin->mScaleFactor = 0x99a;
    coin->mModelAlpha = 0x1f;
    coin->mUnk_000.mFlags = coin->mUnk_000.mFlags | data_ov001_021a6574;
    coin->mEffect = StartEffect(0x3f5, &coin->mUnk_000.mPos);
    coin->mEffectTimer = 0xd;
}

void func_ov001_02182eb8(Coin *coin, s32 b) {
    coin->mUnk_0a8 += b;
    if (coin->mUnk_0a8 >= 5) {
        coin->mUnk_0a8 -= 5;
        coin->mNsbtpFrameIndex += 1;
        if (coin->mNsbtpFrameIndex >= GetMapObjectModelNsbtpFrameCount(data_ov001_021a9b98)) {
            coin->mNsbtpFrameIndex -= GetMapObjectModelNsbtpFrameCount(data_ov001_021a9b98);
        }
    }
}

void func_ov001_02182e84(void) {
    Kart *kart;
    Coin *coin;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    coin = UnparkFirstParkedMapObject(func_02100138(0x68));
    if (coin != NULL) {
        func_ov001_02182f1c(coin, kart);
    }
}

void func_ov001_02182d30(void) {
    Kart *kart;
    Coin *coin;
    RandomState64 *random;
    s32 angle;
    s32 speed;
    Unk0210b7a8 soundArg;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    coin = UnparkFirstParkedMapObject(func_02100138(0x68));
    if (coin != NULL) {
        random = GetMapObjectRandom();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        angle = (u16) (((u64) (u32) (random->mValue >> 32) * 0x10000) >> 32);
        random = GetMapObjectRandom();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        speed = (u32) (((u64) (u32) (random->mValue >> 32) * 0x800) >> 32) + 0x800;
        coin->mState = 3;
        coin->mScaleFactor = 0x99a;
        coin->mModelAlpha = 0x10;
        coin->mUnk_000.mPos.x = kart->mPos.x;
        coin->mUnk_000.mPos.y = kart->mPos.y + 0x1a000;
        coin->mUnk_000.mPos.z = kart->mPos.z;
        coin->mUnk_000.mUnk_10.x = kart->mVelocity.x + (s32) (((s64) speed * gPairsByAngle[(angle >> 4) * 2]) >> 12);
        coin->mUnk_000.mUnk_10.y = kart->mVelocity.y + 0x4000;
        coin->mUnk_000.mUnk_10.z =
            kart->mVelocity.z + (s32) (((s64) speed * gPairsByAngle[(angle >> 4) * 2 + 1]) >> 12);
        coin->mUnk_000.mFlags &= ~1;
        soundArg.mSoundId = 0x1d9;
        soundArg.mPositionSource = NULL;
        soundArg.mUnk_08 = 2;
        soundArg.mDistanceSquared = GetHorizontalCameraDistanceSquared(NULL);
        func_0210b7a8(&soundArg);
    }
}

void func_ov001_02182bdc(void) {
    Kart *kart;
    Coin *coin;
    RandomState64 *random;
    s32 angle;
    s32 speed;
    u8 kartCount;
    Unk02188950 *targetObject;
    Unk0210b7a8 soundArg;

    kart = GetKart((u16) gRaceSetup->mEntryIndex);
    coin = UnparkFirstParkedMapObject(func_02100138(0x68));
    if (coin != NULL) {
        random = GetMapObjectRandom();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        angle = (u16) (((u64) (u32) (random->mValue >> 32) * 0x10000) >> 32);
        random = GetMapObjectRandom();
        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
        speed = (u32) (((u64) (u32) (random->mValue >> 32) * 0x800) >> 32) + 0x800;
        coin->mState = 5;
        coin->mScaleFactor = 0x99a;
        coin->mModelAlpha = 0x10;
        coin->mTimer = 0x1e;
        targetObject = NULL;
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            kartCount = 0;
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                kartCount = func_ov001_02181b54();
            }
            targetObject = GetMissionRunMapObject(kartCount);
        }
        coin->mTargetPos = &targetObject->mUnk_000.mPos;
        coin->mUnk_000.mPos.x = kart->mPos.x;
        coin->mUnk_000.mPos.y = kart->mPos.y + 0x1a000;
        coin->mUnk_000.mPos.z = kart->mPos.z;
        coin->mUnk_000.mUnk_10.x = (((s64) speed * gPairsByAngle[(angle >> 4) * 2]) >> 12);
        coin->mUnk_000.mUnk_10.y = 0x4000;
        coin->mUnk_000.mUnk_10.z = (((s64) speed * gPairsByAngle[(angle >> 4) * 2 + 1]) >> 12);
        soundArg.mSoundId = 0x1d9;
        soundArg.mPositionSource = NULL;
        soundArg.mUnk_08 = 2;
        soundArg.mDistanceSquared = GetHorizontalCameraDistanceSquared(NULL);
        func_0210b7a8(&soundArg);
    }
}

void func_ov001_02182bbc(u32 amount) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunPendingBossTransfer(amount);
    }
}

void func_ov001_02182a3c(s32 a) {
    int i;
    s32 foundCount;
    CoinList *coinList;
    Coin *coin;
    RandomState64 *random;
    u16 angle;
    int tableIndex;

    foundCount = 0;
    coinList = func_02100138(0x68);
    GetKart((u16) gRaceSetup->mEntryIndex);
    if (coinList != NULL) {
        for (i = 0; i < coinList->mObjectCount && (coin = coinList->mObjects[i]) != NULL; i++) {
            if (coin->mState == 7) {
                foundCount++;
                if (foundCount <= a) {
                    if (coin->mTargetPos == NULL) {
                        random = GetMapObjectRandom();
                        random->mValue = (s64) random->mMultiplier * (s64) random->mValue + random->mIncrement;
                        angle = ((u64) (u32) (random->mValue >> 32) * 0x10000) >> 32;
                        coin->mScaleFactor = 0x1000;
                        coin->mModelAlpha = 0;
                        coin->mTargetPos =
                            (Vec3 *) ((gRaceSetup->mMode == MODE_MISSION_RUN
                                           ? (u32) GetMissionRunMapObject(
                                                 gRaceSetup->mMode == MODE_MISSION_RUN ? func_ov001_02181b54() : 0)
                                           : 0) +
                                      4);
                        coin->mUnk_000.mPos.x = coin->mTargetPos->x;
                        coin->mUnk_000.mPos.y = coin->mTargetPos->y;
                        coin->mUnk_000.mPos.z = coin->mTargetPos->z;
                        coin->mUnk_000.mUnk_10.x = 0;
                        coin->mUnk_000.mUnk_10.y = 0x4cd;
                        coin->mUnk_000.mUnk_10.z = 0;
                        tableIndex = (angle >> 4) * 2;
                        coin->mUnk_0ec.x = ((s64) gPairsByAngle[tableIndex] * 0x14000) >> 12;
                        coin->mUnk_0ec.y = -0xa000;
                        coin->mUnk_0ec.z = ((s64) gPairsByAngle[tableIndex + 1] * 0x14000) >> 12;
                    }
                } else {
                    if (coin->mTargetPos != NULL) {
                        coin->mTargetPos = NULL;
                    }
                }
            }
        }
    }
}

void func_ov001_021829ac(s32 a) {
    CoinList *coinList;
    Coin *coin;
    s32 count;
    int i;

    count = 0;
    coinList = func_02100138(0x68);
    GetKart((u16) gRaceSetup->mEntryIndex);
    if (coinList != NULL) {
        for (i = 0; i < coinList->mObjectCount && (coin = coinList->mObjects[i]) != NULL; i++) {
            if (coin->mState == 7) {
                if (coin->mTargetPos != NULL) {
                    coin->mTargetPos = NULL;
                }
                count++;
                if (count <= a) {
                    if ((coin->mUnk_000.mFlags & 0x100) == 0) {
                        ParkMapObject(&coin->mUnk_000);
                    }
                    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                        func_ov001_0218155c(1);
                    }
                }
            }
        }
    }
}

void func_ov001_021828f0(void) {
    int i;
    Coin *coin;
    CoinList *coinList;
    NNSSndSeqPlayer **sndHandleSlot;

    coinList = func_02100138(0x68);
    if (coinList != NULL) {
        for (i = 0; i < coinList->mObjectCount && (coin = coinList->mObjects[i]) != NULL; i++) {
            if (coin->mState == 0 && (coin->mUnk_000.mFlags & 0x100) == 0) {
                coin->mUnk_000.mUnk_10.y = 0x5000;
                coin->mModelAlpha = 0x32;
                coin->mState = 8;
                coin->mUnk_000.mFlags |= data_ov001_021a6574;
            }
        }
    }
    sndHandleSlot = GetSndHandleSlot(2);
    if ((data_0217c780 & 1) && data_0217d084.mUnk_0c != 0) {
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        NNS_SndArcPlayerStartSeqArc(sndHandleSlot, 0, 0x233);
    }
}

void func_ov001_021827f0(void) {
    int i;
    Coin *coin;
    CoinList *coinList;
    NNSSndSeqPlayer **sndHandleSlot;

    coinList = func_02100138(0x68);
    if (coinList != NULL) {
        for (i = 0; i < coinList->mObjectCount && (coin = coinList->mObjects[i]) != NULL; i++) {
            if (coin->mState == 9 && (coin->mUnk_000.mFlags & 0x100) == 0) {
                coin->mUnk_000.mPos.x = coin->mUnk_000.mCourseMapRow->mUnk_00.x;
                coin->mUnk_000.mPos.y = coin->mUnk_000.mCourseMapRow->mUnk_00.y + 0xa000;
                coin->mUnk_000.mPos.z = coin->mUnk_000.mCourseMapRow->mUnk_00.z;
                coin->mUnk_000.mUnk_10.x = 0;
                coin->mUnk_000.mUnk_10.y = 0x5000;
                coin->mUnk_000.mUnk_10.z = 0;
                coin->mBounceY = coin->mUnk_000.mCourseMapRow->mUnk_00.y + 0xe000;
                coin->mState = 2;
                coin->mScaleFactor = 0x1000;
                coin->mModelAlpha = 0;
                coin->mUnk_000.mFlags &= ~1;
            }
        }
    }
    sndHandleSlot = GetSndHandleSlot(2);
    if ((data_0217c780 & 1) && data_0217d084.mUnk_0c != 0) {
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        if (*sndHandleSlot != 0) {
            NNS_SndPlayerStopSeq(sndHandleSlot, 0);
        }
        NNS_SndArcPlayerStartSeqArc(sndHandleSlot, 0, 0x232);
    }
}

void func_ov001_021827a4(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        func_ov001_021816a8(func_ov001_02182e84);
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        SetMissionRunDropCallback(func_ov001_02182d30);
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        SetMissionRunBossTransferCallback(func_ov001_02182bdc);
    }
}

u8 CollideKartWithCoin(Coin *coin, Kart *kart, u8 *e, u8 *f) {
    u8 a = *e;
    u8 b = *f;

    if (kart->mUnk_48 & 0x200) {
        return 0;
    }
    if (a == 1) {
        if (coin->mState != 3 && coin->mState != 5 && coin->mState != 6) {
            ParkMapObject(&coin->mUnk_000);
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                func_ov001_021815d0(1);
            }
        }
    }
    return b;
}

void LoadCoin(Unk0219b478 *a) {
    data_ov001_021a9b98 = LoadMapObjectModelAnimated(a, data_ov001_021a78c0);
    LoadMapObjectModelNsbtpAnimation(data_ov001_021a9b98, data_ov001_021a78cc);
    SetMapObjectModelPolygonId(data_ov001_021a9b98, 0x3f);
    func_0209ba08(data_ov001_021a9b98, 2);
    SetNsbmdEmiAll(data_ov001_021a9b98->mAnimatedModel, 0x294a);
    a->mUnk_1c = 1;
}

void DrawCoin(void *b, Coin *coin) {
    s32 a;
    Vec3 scale;
    u32 alpha;
    s32 scaleFactor;

    if (coin->mScaleFactor > 0 && coin->mModelAlpha != 0) {
        a = 0x1e;
        func_01ff9048(0x14, (&a), 1);
        func_01ff9048(0x19, func_020e6cbc(&coin->mUnk_000.mPos), 0xc);
        scaleFactor = coin->mScaleFactor;
        if (scaleFactor != 0x1000) {
            scale.x = scaleFactor;
            scale.y = scaleFactor;
            scale.z = scaleFactor;
            func_01ff9048(0x1b, (&scale), 3);
        }
        func_01ff9048(0x1b, (&coin->mUnk_000.mScale), 3);
        SetMapObjectModelPolygonId(data_ov001_021a9b98, AllocPolygonIdWrapping());
        alpha = coin->mModelAlpha;
        if (alpha >= 0x1f) {
            alpha = 0x1f;
        }
        SetMapObjectModelAlpha(data_ov001_021a9b98, alpha);
        SetMapObjectModelNsbtpFrameIndex(data_ov001_021a9b98, coin->mNsbtpFrameIndex);
        func_0209bbd0(b, data_ov001_021a9b98);
        DrawMapObjectModel(b, data_ov001_021a9b98, coin);
    }
}

void InitCoinObjects(CoinList *coinList) {
    int i;
    Coin *coin;
    s32 speed;

    if (coinList != NULL) {
        for (i = 0; i < coinList->mObjectCount && (coin = coinList->mObjects[i]) != NULL; i++) {
            coin->mUnk_0d8 = coin->mUnk_000.mCourseMapRow->mUnk_00;
            coin->mUnk_000.mPos = coin->mUnk_0d8;
            coin->mUnk_000.mPos.y = coin->mUnk_000.mPos.y + 0xe000;
            if (coin->mUnk_000.mCourseMapRow->mUnk_26 >= 0) {
                InitGroupFollower(&coin->mFollower, coin->mUnk_000.mCourseMapRow, 0);
                speed = (coin->mUnk_000.mCourseMapRow->mUnk_28 << 12) / 100;
                coin->mFollower.mSpeed = speed;
                coin->mFollower.mProgressStep =
                    ((s64) speed *
                     coin->mFollower.mPath->mSegments[coin->mFollower.mSegmentIndex].mInverseProgressLength) >>
                    12;
            } else {
                coin->mFollower.mGroupIndex = 0xffff;
            }
            coin->mScaleFactor = 0x1000;
            if (coin->mUnk_000.mCourseMapRow->mUnk_2a == 0) {
                coin->mModelAlpha = 0x1f;
            } else {
                coin->mModelAlpha = 0;
            }
        }
    }
}

void func_ov001_0218254c(void) {}

void UpdateCoin(void *a, Coin *coin) {
    s32 n;
    switch (coin->mState) {
        case 2:
            n = coin->mModelAlpha + 1;
            if (n >= 31) {
                n = 31;
            }
            coin->mModelAlpha = n;
            func_ov001_02182eb8(coin, 1);
            coin->mUnk_000.mUnk_10.y -= 0x333;
            VEC_Add(&coin->mUnk_000.mPos, &coin->mUnk_000.mUnk_10, &coin->mUnk_000.mPos);
            if (coin->mUnk_000.mPos.y <= coin->mBounceY) {
                coin->mUnk_000.mPos.y = coin->mBounceY;
                if (coin->mUnk_000.mUnk_10.y <= 0) {
                    coin->mUnk_000.mUnk_10.y = ((s64) coin->mUnk_000.mUnk_10.y * -0x800) >> 12;
                    if (coin->mUnk_000.mUnk_10.y < 0x1000) {
                        coin->mUnk_000.mUnk_10.x = 0;
                        coin->mUnk_000.mUnk_10.y = 0;
                        coin->mUnk_000.mUnk_10.z = 0;
                        coin->mState = 0;
                    }
                    StartSoundAtPositionIfNear(0x1d8, &coin->mUnk_000.mPos, 2);
                }
            }
            break;
        case 0: {
            u16 radius;
            s32 i;
            BOOL found;
            Vec3 *kartPos;
            s32 dx;
            s32 dz;
            func_ov001_02182eb8(coin, 1);
            if (coin->mFollower.mGroupIndex != 0xffff) {
                AdvanceGroupFollower(&coin->mFollower);
                GetGroupFollowerCurvePosStep(&coin->mFollower, &coin->mUnk_000.mPos, &coin->mUnk_000.mUnk_10);
                coin->mUnk_000.mPos.y += 0xe000;
                coin->mUnk_0d8 = coin->mUnk_000.mPos;
            } else {
                coin->mUnk_000.mUnk_10.x = 0;
                coin->mUnk_000.mUnk_10.y = 0;
                coin->mUnk_000.mUnk_10.z = 0;
            }
            if (coin->mUnk_000.mCourseMapRow->mUnk_2a != 0) {
                radius = coin->mUnk_000.mCourseMapRow->mUnk_2a;
                for (i = 0; i < gRaceSetup->mKartCount; i++) {
                    kartPos = &GetKart((u16) i)->mPos;
                    dx = kartPos->x - coin->mUnk_000.mPos.x;
                    dz = kartPos->z - coin->mUnk_000.mPos.z;
                    if ((s64) dx * dx + (s64) dz * dz < (s64) (radius << 12) * (radius << 12)) {
                        found = TRUE;
                        goto checked;
                    }
                }
                found = FALSE;
            checked:
                if (!found) {
                    goto skip;
                }
            }
            n = coin->mModelAlpha + 1;
            if (n >= 31) {
                n = 31;
            }
            coin->mModelAlpha = n;
            break;
        skip:
            coin->mModelAlpha = 0;
            break;
        }
        case 8:
            n = coin->mModelAlpha - 1;
            if (n <= 0) {
                n = 0;
            }
            coin->mModelAlpha = n;
            func_ov001_02182eb8(coin, 4);
            coin->mUnk_000.mPos.y += coin->mUnk_000.mUnk_10.y;
            coin->mUnk_000.mUnk_10.y -= 0x333;
            if (coin->mModelAlpha == 0) {
                coin->mState = 9;
            }
            break;
        case 1: {
            Kart *kart;
            n = coin->mModelAlpha - 1;
            if (n <= 0) {
                n = 0;
            }
            coin->mModelAlpha = n;
            func_ov001_02182eb8(coin, 4);
            kart = GetKart((u16) gRaceSetup->mEntryIndex);
            coin->mUnk_000.mPos.x = kart->mPos.x;
            coin->mUnk_000.mPos.y += coin->mUnk_000.mUnk_10.y;
            coin->mUnk_000.mPos.z = kart->mPos.z;
            coin->mUnk_000.mUnk_10.y -= 0x333;
            if (coin->mTimer-- <= 0) {
                ParkMapObject(&coin->mUnk_000);
            } else if (coin->mTimer == 3) {
                SetupKartFollowEffect(StartEffect(0x3f4, &kart->mPos), kart->mIndex, 0x18);
            }
            if (coin->mEffect != NULL) {
                PlaceEffect(coin->mEffect, &coin->mUnk_000.mPos);
                if (coin->mEffectTimer-- < 0) {
                    func_0208b6b0(&coin->mEffect);
                }
            }
            break;
        }
        case 3: {
            u32 flags;
            Vec3 pos;
            Vec3 delta;
            Vec3 out1;
            Vec3 out2;
            n = coin->mModelAlpha + 1;
            if (n >= 31) {
                n = 31;
            }
            coin->mModelAlpha = n;
            if (coin->mScaleFactor < 0x1000) {
                coin->mScaleFactor += 0x29;
                if (coin->mScaleFactor > 0x1000) {
                    coin->mScaleFactor = 0x1000;
                }
            }
            func_ov001_02182eb8(coin, 1);
            coin->mUnk_000.mUnk_10.y -= 0x333;
            VEC_Add(&coin->mUnk_000.mPos, &coin->mUnk_000.mUnk_10, &coin->mUnk_000.mPos);
            pos.x = coin->mUnk_000.mPos.x;
            pos.y = coin->mUnk_000.mExtent.x + (coin->mUnk_000.mPos.y - 0xe000);
            pos.z = coin->mUnk_000.mPos.z;
            if (func_020d2c2c(&pos, &coin->mUnk_000.mUnk_10, coin->mUnk_000.mExtent.x,
                              coin->mUnk_000.mCollisionSlotIndex, 2, &delta) != 0) {
                VEC_Add(&coin->mUnk_000.mPos, &delta, &coin->mUnk_000.mPos);
                if ((s64) delta.x * delta.x + (s64) delta.y * delta.y + (s64) delta.z * delta.z >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&delta, &coin->mUnk_000.mUnk_10);
                }
                coin->mUnk_000.mUnk_10.x = ((s64) coin->mUnk_000.mUnk_10.x * 0x1400) >> 12;
                coin->mUnk_000.mUnk_10.y = ((s64) coin->mUnk_000.mUnk_10.y * 0x1400) >> 12;
                coin->mUnk_000.mUnk_10.z = ((s64) coin->mUnk_000.mUnk_10.z * 0x1400) >> 12;
            }
            if (func_01ffdee4(&pos, NULL, 0, coin->mUnk_000.mExtent.x, 1, coin->mUnk_000.mCollisionSlotIndex, &delta,
                              &out1, &out2, &flags, NULL, NULL, NULL, NULL) != 0) {
                VEC_Add(&coin->mUnk_000.mPos, &delta, &coin->mUnk_000.mPos);
                if (flags & 0x214300) {
                    BounceVelocityOffSurface(&coin->mUnk_000.mUnk_10, &out2, 0x1000, 0x1000, 0xc00,
                                             &coin->mUnk_000.mUnk_10);
                    if ((s64) coin->mUnk_000.mUnk_10.x * coin->mUnk_000.mUnk_10.x +
                            (s64) coin->mUnk_000.mUnk_10.y * coin->mUnk_000.mUnk_10.y +
                            (s64) coin->mUnk_000.mUnk_10.z * coin->mUnk_000.mUnk_10.z >=
                        0x10) {
                        Vec3NormalizeAndGetLengthUnchecked(&coin->mUnk_000.mUnk_10, &coin->mUnk_000.mUnk_10);
                    }
                    coin->mUnk_000.mUnk_10.x = ((s64) coin->mUnk_000.mUnk_10.x * 0x1400) >> 12;
                    coin->mUnk_000.mUnk_10.y = ((s64) coin->mUnk_000.mUnk_10.y * 0x1400) >> 12;
                    coin->mUnk_000.mUnk_10.z = ((s64) coin->mUnk_000.mUnk_10.z * 0x1400) >> 12;
                }
                if ((flags & 0x1e34ef) && coin->mUnk_000.mUnk_10.y <= 0) {
                    coin->mUnk_000.mUnk_10.y = ((s64) coin->mUnk_000.mUnk_10.y * -0x800) >> 12;
                    if (coin->mUnk_000.mUnk_10.y < 0x1000) {
                        coin->mUnk_000.mUnk_10.x = 0;
                        coin->mUnk_000.mUnk_10.y = 0;
                        coin->mUnk_000.mUnk_10.z = 0;
                        coin->mState = 0;
                    }
                    StartSoundAtPositionIfNear(0x1d8, &coin->mUnk_000.mPos, 2);
                }
                if ((flags & 0x800) || coin->mUnk_000.mPos.y < 0) {
                    coin->mState = 4;
                }
            }
            coin->mUnk_0d8.x = coin->mUnk_000.mPos.x;
            coin->mUnk_0d8.z = coin->mUnk_000.mPos.z;
            break;
        }
        case 4:
            func_ov001_02182eb8(coin, 1);
            coin->mUnk_000.mUnk_10.y -= 0x333;
            VEC_Add(&coin->mUnk_000.mPos, &coin->mUnk_000.mUnk_10, &coin->mUnk_000.mPos);
            n = coin->mModelAlpha - 1;
            if (n > 0) {
                coin->mModelAlpha = n;
                break;
            }
            if (coin->mUnk_000.mCourseMapRow->mUnk_2c != 0) {
                coin->mState = 7;
                coin->mScaleFactor = 0x1000;
                coin->mModelAlpha = 0;
                coin->mUnk_000.mFlags |= data_ov001_021a6574;
                if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                    AddMissionRunBossCount(1);
                }
            } else {
                coin->mUnk_000.mPos.x = coin->mUnk_000.mCourseMapRow->mUnk_00.x;
                coin->mUnk_000.mPos.y = coin->mUnk_000.mCourseMapRow->mUnk_00.y + 0x64000;
                coin->mUnk_000.mPos.z = coin->mUnk_000.mCourseMapRow->mUnk_00.z;
                coin->mUnk_000.mUnk_10.x = 0;
                coin->mUnk_000.mUnk_10.y = 0;
                coin->mUnk_000.mUnk_10.z = 0;
                coin->mBounceY = coin->mUnk_000.mCourseMapRow->mUnk_00.y + 0xe000;
                coin->mState = 2;
                coin->mScaleFactor = 0x1000;
                coin->mModelAlpha = 0;
                coin->mUnk_000.mFlags &= ~1;
            }
            break;
        case 5:
            n = coin->mModelAlpha + 1;
            if (n >= 31) {
                n = 31;
            }
            coin->mModelAlpha = n;
            if (coin->mScaleFactor < 0x1000) {
                coin->mScaleFactor += 0x29;
                if (coin->mScaleFactor > 0x1000) {
                    coin->mScaleFactor = 0x1000;
                }
            }
            func_ov001_02182eb8(coin, 1);
            coin->mUnk_000.mUnk_10.y -= 0x333;
            VEC_Add(&coin->mUnk_000.mPos, &coin->mUnk_000.mUnk_10, &coin->mUnk_000.mPos);
            if (coin->mUnk_000.mUnk_10.y <= 0) {
                coin->mState = 6;
            }
            break;
        case 6:
            if (coin->mScaleFactor < 0x1000) {
                coin->mScaleFactor += 0x29;
                if (coin->mScaleFactor > 0x1000) {
                    coin->mScaleFactor = 0x1000;
                }
            }
            func_ov001_02182eb8(coin, 1);
            if (coin->mUnk_000.mPos.x < coin->mTargetPos->x) {
                coin->mUnk_000.mUnk_10.x += 0x400;
            } else if (coin->mUnk_000.mPos.x > coin->mTargetPos->x) {
                coin->mUnk_000.mUnk_10.x -= 0x400;
            }
            if (coin->mUnk_000.mPos.y < coin->mTargetPos->y) {
                coin->mUnk_000.mUnk_10.y += 0x400;
            } else if (coin->mUnk_000.mPos.y > coin->mTargetPos->y) {
                coin->mUnk_000.mUnk_10.y -= 0x400;
            }
            if (coin->mUnk_000.mPos.z < coin->mTargetPos->z) {
                coin->mUnk_000.mUnk_10.z += 0x400;
            } else if (coin->mUnk_000.mPos.z > coin->mTargetPos->z) {
                coin->mUnk_000.mUnk_10.z -= 0x400;
            }
            VEC_Add(&coin->mUnk_000.mPos, &coin->mUnk_000.mUnk_10, &coin->mUnk_000.mPos);
            if (coin->mTimer-- <= 0) {
                coin->mTimer = 0;
                n = coin->mModelAlpha - 1;
                if (n <= 0) {
                    n = 0;
                }
                coin->mModelAlpha = n;
                if (coin->mModelAlpha < 1) {
                    coin->mState = 7;
                    coin->mScaleFactor = 0x1000;
                    coin->mModelAlpha = 0;
                    coin->mTargetPos = NULL;
                    coin->mUnk_000.mFlags |= data_ov001_021a6574;
                }
            }
            break;
        case 7:
            if (coin->mTargetPos != NULL) {
                n = coin->mModelAlpha + 2;
                if (n >= 31) {
                    n = 31;
                }
                coin->mModelAlpha = n;
            } else {
                n = coin->mModelAlpha - 2;
                if (n <= 0) {
                    n = 0;
                }
                coin->mModelAlpha = n;
            }
            if (coin->mModelAlpha != 0 && coin->mTargetPos != NULL) {
                func_ov001_02182eb8(coin, 1);
                coin->mUnk_000.mUnk_10.y -= 0x14;
                VEC_Add(&coin->mUnk_0ec, &coin->mUnk_000.mUnk_10, &coin->mUnk_0ec);
                VEC_Add(&coin->mUnk_0ec, coin->mTargetPos, &coin->mUnk_000.mPos);
                if ((s64) ((const Vec3 *) &coin->mUnk_0ec)->x * ((const Vec3 *) &coin->mUnk_0ec)->x +
                        (s64) ((const Vec3 *) &coin->mUnk_0ec)->z * ((const Vec3 *) &coin->mUnk_0ec)->z >=
                    0x190000000LL) {
                    coin->mUnk_000.mUnk_10.x = ((s64) coin->mUnk_0ec.x * -0x14) >> 12;
                    coin->mUnk_000.mUnk_10.z = ((s64) coin->mUnk_0ec.z * -0x14) >> 12;
                }
                if (coin->mUnk_0ec.y < -0xa000) {
                    coin->mUnk_000.mUnk_10.y = 0x4cd;
                }
            }
            break;
        case 9:
            break;
    }
}

void CreateCoinKindData(void) {
    CreateMapObjectKindData(&CollideKartWithCoin, NULL, NULL, 1, 1);
}

void *func_ov001_02181c08(void) {
    return CreateMapObjectDrawList1(LoadCoin, DrawCoin, NULL);
}

void *func_ov001_02181bec(void) {
    return CreateMapObjectDrawList1(func_ov001_021830a8, func_ov001_02182f98, func_ov001_02183090);
}

void *func_ov001_02181bd0(void) {
    return CreateMapObjectUpdateList(InitCoinObjects, UpdateCoin, func_ov001_0218254c);
}

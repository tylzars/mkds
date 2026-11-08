#include "Main/Unknown/code_0209eb54.h"
#include "Main/Unknown/code_0209b634.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_02167000.h"

void CreatePicture1AndPicture2(void *a) {
    gPicture1 = CreateMapObjectModelAnimated(a, gPicture1NsbmdName);
    CreateMapObjectModelNsbcaAnimation(gPicture1, gPicture1NsbcaName);
    gPicture2 = CreateMapObjectModelAnimated(a, gPicture2NsbmdName);
    CreateMapObjectModelNsbcaAnimation(gPicture2, gPicture2NsbcaName);
    SetMapObjectModelPolygonId(gPicture1, 0x3f);
    SetMapObjectModelPolygonId(gPicture2, 0x3f);
}

void DrawPicture(void *a, Picture *b) {
    s32 s;

    s = 0x1e;
    func_01ff9048(0x14, &s, 1);
    b->mUnk_00.mMatrix.mUnk_00[3].x = b->mUnk_00.mPos.x >> 4;
    b->mUnk_00.mMatrix.mUnk_00[3].y = b->mUnk_00.mPos.y >> 4;
    b->mUnk_00.mMatrix.mUnk_00[3].z = b->mUnk_00.mPos.z >> 4;
    func_01ff9048(0x19, &b->mUnk_00.mMatrix, 0xc);
    func_01ff9048(0x1b, &b->mUnk_00.mScale, 3);
    switch (b->mPictureIndex) {
        case 0:
            SetMapObjectModelNsbcaFrameIndex(gPicture1, b->mNsbcaFrameIndex);
            DrawMapObjectModel(a, gPicture1, b);
            break;
        case 1:
            SetMapObjectModelNsbcaFrameIndex(gPicture2, b->mNsbcaFrameIndex);
            DrawMapObjectModel(a, gPicture2, b);
            break;
    }
}

void UpdatePicture(void *a, Picture *b) {
    Unk0210b7a8 s1;
    Unk0210b7a8 s2;
    Unk0210b7a8 s3;
    Unk0210b7a8 s4;
    RandomState64 *randomState64;
    s32 nextFrameIndex;
    s32 t;

    switch (b->mState) {
        case 1:
            if (b->mState1Timer-- <= 0) {
                b->mState = 2;
            }
            break;
        case 2:
            if (b->mPictureIndex == 0) {
                nextFrameIndex = b->mNsbcaFrameIndex + 1;
                if (nextFrameIndex >= GetMapObjectModelNsbcaFrameCount(gPicture1)) {
                    nextFrameIndex = 0;
                }
                b->mNsbcaFrameIndex = nextFrameIndex;
                if (b->mNsbcaFrameIndex == 0 || b->mNsbcaFrameIndex == 0xf || b->mNsbcaFrameIndex == 0x1f ||
                    b->mNsbcaFrameIndex == 0x37 || b->mNsbcaFrameIndex == 0x51) {
                    if (func_020d4ddc(&b->mUnk_00) == FALSE) {
                        if (b->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                            t = 2;
                        } else if (b->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s1.mSoundId = 0x116;
                        s1.mPositionSource = &b->mUnk_00.mPos;
                        s1.mUnk_08 = t;
                        s1.mDistanceSquared = GetHorizontalCameraDistanceSquared(&b->mUnk_00.mPos);
                        func_0210b7a8(&s1);
                    }
                } else if (b->mNsbcaFrameIndex == 8 || b->mNsbcaFrameIndex == 0x14 || b->mNsbcaFrameIndex == 0x2c ||
                           b->mNsbcaFrameIndex == 0x44) {
                    if (func_020d4ddc(&b->mUnk_00) == FALSE) {
                        if (b->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                            t = 2;
                        } else if (b->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s2.mSoundId = 0x117;
                        s2.mPositionSource = &b->mUnk_00.mPos;
                        s2.mUnk_08 = t;
                        s2.mDistanceSquared = GetHorizontalCameraDistanceSquared(&b->mUnk_00.mPos);
                        func_0210b7a8(&s2);
                    }
                } else if (b->mNsbcaFrameIndex == 0x78) {
                    if (func_020d4ddc(&b->mUnk_00) == FALSE) {
                        if (b->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                            t = 2;
                        } else if (b->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s3.mSoundId = 0x115;
                        s3.mPositionSource = &b->mUnk_00.mPos;
                        s3.mUnk_08 = t;
                        s3.mDistanceSquared = GetHorizontalCameraDistanceSquared(&b->mUnk_00.mPos);
                        func_0210b7a8(&s3);
                    }
                }
            } else if (b->mPictureIndex == 1) {
                nextFrameIndex = b->mNsbcaFrameIndex + 1;
                if (nextFrameIndex >= GetMapObjectModelNsbcaFrameCount(gPicture2)) {
                    nextFrameIndex = 0;
                }
                b->mNsbcaFrameIndex = nextFrameIndex;
                if (b->mNsbcaFrameIndex == 0) {
                    if (func_020d4ddc(&b->mUnk_00) == FALSE) {
                        if (b->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                            t = 2;
                        } else if (b->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s4.mSoundId = 0x118;
                        s4.mPositionSource = &b->mUnk_00.mPos;
                        s4.mUnk_08 = t;
                        s4.mDistanceSquared = GetHorizontalCameraDistanceSquared(&b->mUnk_00.mPos);
                        func_0210b7a8(&s4);
                    }
                }
            }
            if (b->mNsbcaFrameIndex != 0) {
                return;
            }
            randomState64 = &gRaceProgress->mLocalRandom;
            randomState64->mValue = randomState64->mMultiplier * randomState64->mValue + randomState64->mIncrement;
            b->mState1Timer = (u16) (((randomState64->mValue >> 32) * 0x78) >> 32) + 0x3c;
            b->mState = 1;
            break;
    }
}

void *CreatePictureDrawList(void) {
    return CreateMapObjectDrawList1(CreatePicture1AndPicture2, DrawPicture, NULL);
}

void *CreatePictureUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdatePicture, NULL);
}

void CreatePuddle(void *a) {
    gPuddle = CreateMapObjectModelNsbmd(a, gPuddleNsbmdName);
}

void SetupDrawPuddle(void *a) {
    func_0209bbd0(a, gPuddle);
}

void DrawPuddle(void *a, MapObject *b) {
    s32 s;
    s32 x;
    s32 y;
    s32 z;
    Vec3 v;

    s = 0x1e;
    func_01ff9048(0x14, &s, 1);
    z = b->mPos.z >> 4;
    y = (b->mPos.y + 0x1ccd) >> 4;
    x = b->mPos.x >> 4;
    v.x = x;
    v.y = y;
    v.z = z;
    func_01ff9048(0x1c, &v, 3);
    func_01ff9048(0x1b, &b->mScale, 3);
    func_01ff9048(0x1a, &b->mMatrix, 9);
    DrawMapObjectModel(a, gPuddle, b);
}

#include "Main/Unknown/code_020a2f30.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_0209b634.h"

#include "Main/Unknown/code_020a36a8.h"
#include "Main/Unknown/code_020a3690.h"
#include "Main/Unknown/code_020a392c.h"
#include "Main/Unknown/code_020a3948.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_0201c528.h"
#include "code_02148538.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020a3f18.h"
#include "Main/Unknown/code_02077bc0.h"

void InitBalloon(u32 balloon) {
    u32 balloonAddress = balloon;
    u32 noKartIndex;
    u32 value12;
    noKartIndex = ~(0u);
    *(u32 *) ((balloonAddress) + (164)) = noKartIndex;
    ParkMapObject((void *) balloonAddress);
}

void CreateBalloon(Unk020a3eb8 *a) {
    gBalloon = CreateMapObjectModelNsbmdNsbtp(a, gBalloonNsbmdName, gBalloonNsbtpName);
    SetMapObjectModelPolygonId(gBalloon, 0x3f);
    SetMapObjectModelAlpha(gBalloon, 0x1a);
    SetMapObjectModelFogEnabled(gBalloon, 0);
    a->mUnk_1c = 1;
}

void SetupDrawBalloon(void *mapObjectList) {
    Camera *currentCamera;

    currentCamera = GetCurrentCamera();
    data_0217b214.x = currentCamera->mPos.x >> 1;
    data_0217b214.y = currentCamera->mPos.y >> 1;
    data_0217b214.z = currentCamera->mPos.z >> 1;
    data_0217b208.x = currentCamera->mPos.x >> 3;
    data_0217b208.y = currentCamera->mPos.y >> 3;
    data_0217b208.z = currentCamera->mPos.z >> 3;
    func_0209bbd0(mapObjectList, gBalloon);
}

void DrawBalloon(void *mapObjectList, Balloon *balloon) {
    s32 j;
    s32 drawCount;
    s32 i;
    s32 k;
    s32 drawScale;
    u32 distanceSquared;
    s32 t;
    s32 w0;
    s32 w1;
    s32 w2;
    s32 m0[9];
    s32 m1[9];
    s32 f0[3];
    s32 g0[3];
    s32 f1[3];
    s32 g1[3];
    s32 h[3];
    Balloon *listBalloon;

    if (balloon->mKartIndex >= 0) {
        if (GetKart(balloon->mKartIndex)->mVisible == 0) {
            return;
        }
    }
    drawCount = balloon->mDrawCount;
    if (drawCount == 1 && balloon->mDrawList == NULL) {
        distanceSquared = balloon->mUnk_00.mDistanceSquaredAndFlags & ~0xc000001f;
        if (distanceSquared < 0x2710) {
            balloon->mDrawPos.x = data_0217b214.x + (balloon->mUnk_00.mPos.x >> 1);
            balloon->mDrawPos.y = data_0217b214.y + (balloon->mUnk_00.mPos.y >> 1);
            balloon->mDrawPos.z = data_0217b214.z + (balloon->mUnk_00.mPos.z >> 1);
            balloon->mDrawScale = 0x800;
        } else if (distanceSquared < 0x9c40) {
            balloon->mDrawPos.x = data_0217b208.x + balloon->mUnk_00.mPos.x - (balloon->mUnk_00.mPos.x >> 3);
            balloon->mDrawPos.y = data_0217b208.y + balloon->mUnk_00.mPos.y - (balloon->mUnk_00.mPos.y >> 3);
            balloon->mDrawPos.z = data_0217b208.z + balloon->mUnk_00.mPos.z - (balloon->mUnk_00.mPos.z >> 3);
            balloon->mDrawScale = 0xe00;
        } else {
            balloon->mDrawPos = balloon->mUnk_00.mPos;
            balloon->mDrawScale = 0x1000;
        }
        w0 = 0x1e;
        func_01ff9048(0x14, &w0, 1);
        func_01ff9048(0x19, SetViewTransposeMatrixPos(&balloon->mDrawPos), 12);
        if (balloon->mUnk_00.mAngle != 0) {
            i = (balloon->mUnk_00.mAngle >> 4) * 2;
            MTX_RotZ33_(m0, gPairsByAngle[i + 1], gPairsByAngle[i]);
            func_01ff9048(0x1a, m0, 9);
        }
        drawScale = balloon->mDrawScale;
        f0[0] = drawScale;
        f0[1] = drawScale;
        f0[2] = drawScale;
        func_01ff9048(0x1b, f0, 3);
        t = balloon->mScaleFactor + balloon->mUnk_d8;
        if (t != 0x1000) {
            g0[0] = t;
            g0[1] = t;
            g0[2] = t;
            func_01ff9048(0x1b, g0, 3);
        }
        SetMapObjectModelPolygonId(gBalloon, AllocPolygonIdWrapping());
        SetMapObjectModelNsbtpFrameIndex(gBalloon, balloon->mNsbtpFrameIndex);
        DrawMapObjectModel(mapObjectList, gBalloon, balloon);
    } else if (drawCount > 0) {
        distanceSquared = balloon->mUnk_00.mDistanceSquaredAndFlags & ~0xc000001f;
        if (distanceSquared < 0x2710) {
            balloon->mDrawPos.x = data_0217b214.x + (balloon->mTargetPos.x >> 1);
            balloon->mDrawPos.y = data_0217b214.y + (balloon->mTargetPos.y >> 1);
            balloon->mDrawPos.z = data_0217b214.z + (balloon->mTargetPos.z >> 1);
            balloon->mDrawScale = 0x800;
        } else if (distanceSquared < 0x9c40) {
            balloon->mDrawPos.x = data_0217b208.x + balloon->mTargetPos.x - (balloon->mTargetPos.x >> 3);
            balloon->mDrawPos.y = data_0217b208.y + balloon->mTargetPos.y - (balloon->mTargetPos.y >> 3);
            balloon->mDrawPos.z = data_0217b208.z + balloon->mTargetPos.z - (balloon->mTargetPos.z >> 3);
            balloon->mDrawScale = 0xe00;
        } else {
            balloon->mDrawPos = balloon->mTargetPos;
            balloon->mDrawScale = 0x1000;
        }
        w1 = 0x1e;
        func_01ff9048(0x14, &w1, 1);
        func_01ff9048(0x19, func_020e6cbc(&balloon->mDrawPos), 12);
        drawScale = balloon->mDrawScale;
        f1[0] = drawScale;
        f1[1] = drawScale;
        f1[2] = drawScale;
        func_01ff9048(0x1b, f1, 3);
        for (j = 0; j < drawCount; j++) {
            i = data_02156720[drawCount - 1][j];
            listBalloon = balloon->mDrawList[i];
            func_01ff9048(0x11, NULL, 0);
            k = data_02156700[drawCount - 1][i];
            MTX_RotZ33_(m1, gPairsByAngle[(k >> 4) * 2 + 1], gPairsByAngle[(k >> 4) * 2]);
            func_01ff9048(0x1a, m1, 9);
            t = listBalloon->mScaleFactor;
            if (t != 0x1000) {
                g1[0] = t;
                g1[1] = t;
                g1[2] = t;
                func_01ff9048(0x1b, g1, 3);
            }
            h[0] = 0;
            h[1] = 0xf66;
            h[2] = 0;
            func_01ff9048(0x1c, h, 3);
            SetMapObjectModelPolygonId(gBalloon, AllocPolygonIdWrapping());
            SetMapObjectModelNsbtpFrameIndex(gBalloon, listBalloon->mNsbtpFrameIndex);
            DrawMapObjectModel(mapObjectList, gBalloon, balloon);
            w2 = 1;
            func_01ff9048(0x12, &w2, 1);
        }
    }
}

void func_020a392c(Unk0201ca6c *effect, Balloon *balloon) {
    effect->mUnk_72 = func_0208606c(balloon->mNsbtpFrameIndex);
}

void func_020a36a8(Balloon *balloon) {
    Kart *kart;
    Vec3 *q;
    Vec3 v;
    s32 s;
    s32 t;
    s32 v1;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 v5;
    s32 v6;
    s32 v7;

    if (balloon->mKartIndex < 0) {
        balloon->mUnk_00.mUnk_10.y = balloon->mUnk_00.mUnk_10.y + 0x1800;
    } else {
        kart = GetKart((u16) balloon->mKartIndex);
        q = &kart->mUnk_12c;
        balloon->mUnk_00.mUnk_10.x = balloon->mUnk_00.mUnk_10.x + (q->x + (q->x >> 1));
        balloon->mUnk_00.mUnk_10.y = balloon->mUnk_00.mUnk_10.y + (q->y + (q->y >> 1));
        balloon->mUnk_00.mUnk_10.z = balloon->mUnk_00.mUnk_10.z + (q->z + (q->z >> 1));
    }
    v1 = (balloon->mUnk_00.mPos.x + balloon->mUnk_00.mUnk_10.x) - (balloon->mTargetPos.x + balloon->mTargetVelocity.x);
    v3 = (balloon->mUnk_00.mPos.z + balloon->mUnk_00.mUnk_10.z) - (balloon->mTargetPos.z + balloon->mTargetVelocity.z);
    t = ((s64) 0xa000 * (balloon->mScaleFactor + balloon->mUnk_d8)) >> 12;
    v6 = v3 < 0 ? -v3 : v3;
    v4 = v1 < 0 ? -v1 : v1;
    v7 = v4 / 2 + v6 / 2;
    if (v7 <= t) {
        balloon->mUnk_e0 = 1;
    } else if (balloon->mUnk_e0 != 0) {
        if (v7 > t) {
            s = FX_Div(v7 - t, v7);
            v.x = ((s64) v1 * s) >> 12;
            v.y = 0;
            v.z = ((s64) v3 * s) >> 12;
            VEC_Subtract(&balloon->mUnk_00.mPos, &v, &balloon->mUnk_00.mPos);
        }
    }
    v1 = (balloon->mUnk_00.mPos.x + balloon->mUnk_00.mUnk_10.x) - (balloon->mTargetPos.x + balloon->mTargetVelocity.x);
    v2 = (balloon->mUnk_00.mPos.y + balloon->mUnk_00.mUnk_10.y) - (balloon->mTargetPos.y + balloon->mTargetVelocity.y);
    v3 = (balloon->mUnk_00.mPos.z + balloon->mUnk_00.mUnk_10.z) - (balloon->mTargetPos.z + balloon->mTargetVelocity.z);
    t = (balloon->mScaleFactor + balloon->mUnk_d8) << 4;
    v5 = v2 < 0 ? -v2 : v2;
    v4 = v1 < 0 ? -v1 : v1;
    v6 = v3 < 0 ? -v3 : v3;
    v7 = v5 + (v4 >> 2) + (v6 >> 2);
    if (v7 > t) {
        s = FX_Div(v7 - t, v7);
        v.x = ((s64) v1 * s) >> 12;
        v.y = ((s64) v2 * s) >> 12;
        v.z = ((s64) v3 * s) >> 12;
        if (balloon->mKartIndex >= 0) {
            VEC_Subtract(&balloon->mUnk_00.mUnk_10, &v, &balloon->mUnk_00.mUnk_10);
        } else {
            VEC_Add(&balloon->mTargetVelocity, &v, &balloon->mTargetVelocity);
        }
    }
    VEC_Add(&balloon->mUnk_00.mPos, &balloon->mUnk_00.mUnk_10, &balloon->mUnk_00.mPos);
    VEC_Add(&balloon->mTargetPos, &balloon->mTargetVelocity, &balloon->mTargetPos);
}

u32 func_020a369c(Balloon *balloon) {
    return balloon->mUnk_00.mFlags & 0x12;
}

u32 GetBalloonDistanceSquared(Balloon *balloon) {
    return balloon->mUnk_00.mDistanceSquaredAndFlags & ~0xc000001fu;
}

void UpdateBalloonAngle(Balloon *balloon) {
    Camera *currentCamera;
    Vec3 v;
    u16 cameraAngle;
    s32 i;
    s32 s;
    s32 c;
    s32 x;
    s32 y;
    s32 u;
    s32 w;

    currentCamera = GetCurrentCamera();
    cameraAngle = FX_Atan2Idx(currentCamera->mForward.x, currentCamera->mForward.z) - 0x4000;
    VEC_Subtract(&balloon->mUnk_00.mPos, &currentCamera->mPos, &v);
    i = (cameraAngle >> 4) * 2;
    s = gPairsByAngle[i];
    c = gPairsByAngle[i + 1];
    x = ((s64) v.z * c) >> 12;
    y = ((s64) v.x * s) >> 12;
    u = v.y;
    VEC_Subtract(&balloon->mTargetPos, &currentCamera->mPos, &v);
    w = (s32) (((s64) v.x * s) >> 12) + (s32) (((s64) v.z * c) >> 12);
    balloon->mUnk_00.mAngle = FX_Atan2Idx(u - v.y, -(y + x - w));
}

void UpdateBalloon(void *mapObjectList, Balloon *balloon) {
    Kart *kart;

    if (balloon->mKartIndex >= 0) {
        switch (balloon->mState) {
            case 0:
                balloon->mUnk_d8 = balloon->mUnk_d8 + balloon->mUnk_dc;
                if (balloon->mUnk_d8 >= 0) {
                    if (balloon->mUnk_dc < 0) {
                        balloon->mUnk_dc = -50;
                    } else {
                        balloon->mUnk_dc = balloon->mUnk_dc - 10;
                    }
                } else {
                    if (balloon->mUnk_dc >= 0) {
                        balloon->mUnk_dc = 50;
                    } else {
                        balloon->mUnk_dc = balloon->mUnk_dc + 10;
                    }
                }
                if (balloon->mKartIndex == gRaceSetup->mEntryIndex) {
                    if (IsRaceStarted() == 1) {
                        kart = GetKart((u16) balloon->mKartIndex);
                        func_020249b8(kart, balloon->mScaleFactor + balloon->mUnk_d8, balloon->mUnk_d4);
                    }
                }
                if (balloon->mDrawCount == 1 && balloon->mDrawList == NULL) {
                    func_020a36a8(balloon);
                    if (func_020a369c(balloon) != 0) {
                        return;
                    }
                    if (GetBalloonDistanceSquared(balloon) >= 0x9c40) {
                        return;
                    }
                    UpdateBalloonAngle(balloon);
                } else {
                    balloon->mUnk_00.mPos.x = balloon->mTargetPos.x;
                    balloon->mUnk_00.mPos.y = balloon->mTargetPos.y + 0xf666;
                    balloon->mUnk_00.mPos.z = balloon->mTargetPos.z;
                }
                break;
            case 1:
                balloon->mUnk_d8 = 0;
                balloon->mScaleFactor = balloon->mScaleFactor + balloon->mUnk_d4;
                if (balloon->mScaleFactor >= 0x1000) {
                    balloon->mUnk_d4 = balloon->mUnk_d4 - 200;
                }
                if (balloon->mUnk_d4 < 0) {
                    if (balloon->mScaleFactor <= 0x1000) {
                        balloon->mScaleFactor = 0x1000;
                        balloon->mState = 2;
                    }
                }
                if (balloon->mDrawCount == 1 && balloon->mDrawList == NULL) {
                    func_020a36a8(balloon);
                    if (func_020a369c(balloon) != 0) {
                        return;
                    }
                    if (GetBalloonDistanceSquared(balloon) >= 0x9c40) {
                        return;
                    }
                    UpdateBalloonAngle(balloon);
                } else {
                    balloon->mUnk_00.mPos.x = balloon->mTargetPos.x;
                    balloon->mUnk_00.mPos.y = balloon->mTargetPos.y + 0xf666;
                    balloon->mUnk_00.mPos.z = balloon->mTargetPos.z;
                }
                break;
            case 2:
                balloon->mUnk_d8 = 0;
                balloon->mScaleFactor = 0x1000;
                if (balloon->mDrawCount == 1 && balloon->mDrawList == NULL) {
                    func_020a36a8(balloon);
                    if (func_020a369c(balloon) != 0) {
                        return;
                    }
                    if (GetBalloonDistanceSquared(balloon) >= 0x9c40) {
                        return;
                    }
                    UpdateBalloonAngle(balloon);
                } else {
                    balloon->mUnk_00.mPos.x = balloon->mTargetPos.x;
                    balloon->mUnk_00.mPos.y = balloon->mTargetPos.y + 0xf666;
                    balloon->mUnk_00.mPos.z = balloon->mTargetPos.z;
                }
                break;
            default:
                return;
        }
    } else {
        balloon->mUnk_d8 = 0;
        balloon->mScaleFactor = 0x1000;
        if (balloon->mNoKartTimer-- <= 0) {
            StartEffectWithCallback(0x5b, &balloon->mUnk_00.mPos, balloon, func_020a392c);
            StartEffectWithCallback(0x5c, &balloon->mUnk_00.mPos, balloon, func_020a392c);
            StartEffectWithCallback(0x5d, &balloon->mUnk_00.mPos, balloon, func_020a392c);
            func_0210b8f4(&balloon->mUnk_00.mPos, GetHorizontalCameraDistanceSquared(&balloon->mUnk_00.mPos));
            ParkMapObject(&balloon->mUnk_00);
        } else {
            balloon->mUnk_c8 = balloon->mUnk_c8 + balloon->mUnk_cc;
            if (balloon->mUnk_c8 >= 0) {
                if (balloon->mUnk_cc < 0) {
                    balloon->mUnk_cc = -0x640;
                } else {
                    balloon->mUnk_cc = balloon->mUnk_cc - 200;
                }
            } else {
                if (balloon->mUnk_cc >= 0) {
                    balloon->mUnk_cc = 0x640;
                } else {
                    balloon->mUnk_cc = balloon->mUnk_cc + 200;
                }
            }
        }
        balloon->mUnk_00.mAngle = balloon->mUnk_c8 + 0x4000;
        balloon->mUnk_00.mUnk_10.y = balloon->mUnk_00.mUnk_10.y + 0x59a;
        balloon->mTargetVelocity.y = balloon->mTargetVelocity.y - 0x2000;
        balloon->mUnk_00.mUnk_10.x = ((s64) balloon->mUnk_00.mUnk_10.x * 0xc00) >> 12;
        balloon->mUnk_00.mUnk_10.y = ((s64) balloon->mUnk_00.mUnk_10.y * 0xc00) >> 12;
        balloon->mUnk_00.mUnk_10.z = ((s64) balloon->mUnk_00.mUnk_10.z * 0xc00) >> 12;
        VEC_Add(&balloon->mUnk_00.mPos, &balloon->mUnk_00.mUnk_10, &balloon->mUnk_00.mPos);
        VEC_Add(&balloon->mTargetPos, &balloon->mTargetVelocity, &balloon->mTargetPos);
    }
}

void *CreateBalloonDrawList(void) {
    return CreateMapObjectDrawList2(CreateBalloon, DrawBalloon, SetupDrawBalloon);
}

void *CreateBalloonUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdateBalloon, NULL);
}

void func_020a305c(void) {
    s32 i;
    MapObjectList *mapObjectList;
    Balloon *balloon;

    mapObjectList = func_02100138(MAP_OBJECT_KIND_BALLOON);
    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (balloon = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if (balloon->mKartIndex >= 0) {
            balloon->mKartIndex = (u16) gRaceSetup->mEntryIndex;
            balloon->mScaleFactor = 0x1000;
            balloon->mUnk_d4 = 0;
            balloon->mUnk_d8 = 0;
            balloon->mUnk_dc = 0;
            balloon->mState = 2;
        } else if ((balloon->mUnk_00.mFlags & 0x100) == 0) {
            ParkMapObject(&balloon->mUnk_00);
        }
    }
}

Balloon *StartBalloon(u16 nsbtpFrameIndex, Vec3 *targetPos) {
    Balloon *balloon;

    balloon = UnparkFirstParkedMapObject(func_02100138(MAP_OBJECT_KIND_BALLOON));
    if (balloon == NULL) {
        return NULL;
    }
    balloon->mTargetPos = *targetPos;
    balloon->mUnk_00.mPos = balloon->mTargetPos;
    balloon->mScaleFactor = 0;
    balloon->mUnk_d4 = 0;
    balloon->mUnk_d8 = 0;
    balloon->mUnk_dc = 0;
    balloon->mUnk_e0 = 0;
    balloon->mNsbtpFrameIndex = nsbtpFrameIndex;
    balloon->mState = 0;
    return balloon;
}

void func_020a2f9c(Balloon *balloon, u16 kartIndex, s32 scaleStep) {
    balloon->mKartIndex = kartIndex;
    balloon->mUnk_d4 = scaleStep;
    balloon->mScaleFactor = balloon->mScaleFactor + balloon->mUnk_d4;
    balloon->mUnk_d8 = 0;
    balloon->mUnk_dc = 0;
    balloon->mState = 0;
    if (balloon->mScaleFactor >= 0x1000) {
        balloon->mUnk_d8 = 0;
        balloon->mUnk_d4 = 0x258;
        balloon->mState = 1;
    }
}

void func_020a2f30(Balloon *balloon, u16 kartIndex, s32 scaleStep) {
    balloon->mKartIndex = kartIndex;
    balloon->mUnk_d4 = -scaleStep;
    balloon->mScaleFactor = balloon->mScaleFactor + balloon->mUnk_d4;
    balloon->mState = 0;
    if (balloon->mScaleFactor > 0) {
        return;
    }
    balloon->mUnk_d8 = 0;
    balloon->mScaleFactor = 0;
    balloon->mKartIndex = -1;
    balloon->mDrawCount = 1;
    balloon->mDrawList = NULL;
    ParkMapObject(&balloon->mUnk_00);
}

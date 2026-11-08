#include "Main/Unknown/code_0209828c.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020d4c28.h"
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
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d9000.h"
#include "Main/Unknown/code_020d7db4.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02146cbc.h"
#include "code_02148538.h"

void *func_02099004(void) {
    return CreateMapObjectUpdateList(NULL, func_0209905c, NULL);
}

void func_02098f18(GroupFollower *groupFollower, s32 b) {
    Unk0209905c *p;
    p = UnparkFirstParkedMapObject(func_02100138(0x1ab));
    if (p == NULL) {
        return;
    }
    p->mUnk_00.mFlags = p->mUnk_00.mFlags & ~1;
    p->mUnk_00.mFlags = p->mUnk_00.mFlags & ~8;
    p->mUnk_00.mFlags = p->mUnk_00.mFlags & ~2;
    p->mUnk_00.mFlags = p->mUnk_00.mFlags & ~8;
    p->mUnk_00.mAlpha = 0x1f;
    p->mUnk_a0.mGroupIndex = groupFollower->mGroupIndex;
    p->mUnk_a0.mPath = groupFollower->mPath;
    SetupGroupFollowerAtEntry(&p->mUnk_a0, 0, 1);
    p->mUnk_a0.mSpeed = 0x7800;
    p->mUnk_a0.mProgressStep =
        ((s64) p->mUnk_a0.mPath->mSegments[p->mUnk_a0.mSegmentIndex].mInverseProgressLength * 0x7800) >> 12;
    p->mUnk_c4 = b;
    p->mUnk_c8 = -0x5000;
    p->mUnk_cc = 0;
    p->mUnk_d0 = StartEffect(0x33, &p->mUnk_00.mPos);
}

void InitPakkun(Pakkun *pakkun) {
    s32 v;
    s32 d;
    Vec3 position;
    Vec3 step;
    s32 i;
    pakkun->mUnk_1d8 =
        (u32) (((s64) pakkun->mUnk_000.mCourseMapRow->mUnk_0c.y * 0xb60b60b60bLL + 0x80000000000LL) >> 32 << 4) >> 16;
    pakkun->mUnk_1e4 = TRUE;
    pakkun->mUnk_1e8 = 0x1000;
    pakkun->mUnk_1ec = 0;
    pakkun->mUnk_1f0 = 0x1000;
    pakkun->mUnk_1f4 = 0;
    pakkun->mUnk_1f8 = 0x46000;
    for (i = 0; i < 7; i++) {
        pakkun->mFollowers[i].mGroupIndex = 0xffff;
    }
    for (i = 0; i < 7; i++) {
        if (i == 0) {
            v = pakkun->mUnk_000.mCourseMapRow->mUnk_28;
        } else if (i == 1) {
            v = pakkun->mUnk_000.mCourseMapRow->mUnk_2a;
        } else if (i == 2) {
            v = pakkun->mUnk_000.mCourseMapRow->mUnk_2c;
        } else if (i == 3) {
            v = pakkun->mUnk_000.mCourseMapRow->mUnk_2e;
        } else if (i == 4) {
            v = pakkun->mUnk_000.mCourseMapRow->mUnk_30;
        } else if (i == 5) {
            v = pakkun->mUnk_000.mCourseMapRow->mUnk_32;
        } else {
            v = pakkun->mUnk_000.mCourseMapRow->mUnk_34;
        }
        if (v >= 0) {
            InitGroupFollowerForGroup(&pakkun->mFollowers[pakkun->mFollowerCount], v, 100);
            GetGroupFollowerLinearPosStep(&pakkun->mFollowers[pakkun->mFollowerCount], &position, &step);
            d = FX_Atan2Idx(step.x, step.z) - pakkun->mUnk_1d8;
            if (d > 0x8000) {
                d -= 0x10000;
            }
            pakkun->mUnk_1bc[pakkun->mFollowerCount] = d;
            pakkun->mUnk_1fc = pakkun->mUnk_000.mPos.y - position.y;
            pakkun->mFollowerCount++;
        }
    }
    pakkun->mPolygonId = AllocPolygonId();
    CreateParkedMapObjects(0x1ab, 0x14, pakkun);
}

void CreatePakkunMouth(void *a) {
    gPakkunMouth = CreateMapObjectModelAnimated(a, "PakkunMouth.nsbmd");
    CreateMapObjectModelNsbcaAnimation(gPakkunMouth, "PakkunMouth.nsbca");
    SetMapObjectModelAlpha(gPakkunMouth, 0x1f);
}

static inline u32 func_020983c4_inline(u32 n) {
    RandomState64 *mapObjectRandom;
    u32 t;
    u32 m;
    if (n == 0x10000) {
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue =
            mapObjectRandom->mIncrement + (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue;
        return (u16) ((mapObjectRandom->mValue >> 32) * 0x10000 >> 32);
    }
    mapObjectRandom = GetMapObjectRandom();
    m = (u16) n;
    if (m == 0) {
        t = 0;
    } else {
        mapObjectRandom->mValue =
            mapObjectRandom->mIncrement + (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue;
        if (m == 0) {
            t = mapObjectRandom->mValue >> 32;
        } else {
            t = ((mapObjectRandom->mValue >> 32) * m) >> 32;
        }
    }
    return (u16) t;
}

void DrawPakkunMouth(void *a, Pakkun *pakkun) {
    s32 w;
    s32 m[9];
    s32 n[9];
    s32 f[3];
    s32 g[3];
    s32 t;
    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    pakkun->mUnk_000.mMatrix.mUnk_00[3].x = pakkun->mUnk_000.mPos.x >> 4;
    pakkun->mUnk_000.mMatrix.mUnk_00[3].y = pakkun->mUnk_000.mPos.y >> 4;
    pakkun->mUnk_000.mMatrix.mUnk_00[3].z = pakkun->mUnk_000.mPos.z >> 4;
    func_01ff9048(0x19, &pakkun->mUnk_000.mMatrix, 12);
    f[1] = pakkun->mUnk_1f8 >> 4;
    f[0] = 0;
    f[2] = 0;
    func_01ff9048(0x1c, f, 3);
    if (pakkun->mUnk_1dc != 0) {
        MTX_RotY33_(m, gPairsByAngle[((u16) pakkun->mUnk_1dc >> 4) * 2],
                    gPairsByAngle[((u16) pakkun->mUnk_1dc >> 4) * 2 + 1]);
        func_01ff9048(0x1a, m, 9);
    }
    if (pakkun->mUnk_1e0 != 0) {
        MTX_RotX33_(n, gPairsByAngle[((u16) pakkun->mUnk_1e0 >> 4) * 2],
                    gPairsByAngle[((u16) pakkun->mUnk_1e0 >> 4) * 2 + 1]);
        func_01ff9048(0x1a, n, 9);
    }
    t = pakkun->mUnk_1f0;
    g[0] = t;
    g[1] = t;
    g[2] = t;
    func_01ff9048(0x1b, g, 3);
    func_01ff9048(0x1b, &pakkun->mUnk_000.mScale, 3);
    SetMapObjectModelPolygonId(gPakkunMouth, pakkun->mPolygonId);
    SetMapObjectModelNsbcaFrameIndex(gPakkunMouth, pakkun->mUnk_0a4 >> 12);
    DrawMapObjectModel(a, gPakkunMouth, pakkun);
}

void CreatePakkunZHead(void *a) {
    gPakkunZHead = CreateMapObjectModelNsbmd(a, "PakkunZHead.nsbmd");
    SetMapObjectModelAlpha(gPakkunZHead, 0x1e);
}

void SetupDrawPakkunZHead(void *a) {
    func_0209bbd0(a, gPakkunZHead);
}

void DrawPakkunZHead(void *a, Pakkun *pakkun) {
    s32 w;
    Vec3 position;
    s32 f[3];
    s32 t;
    position.x = pakkun->mUnk_000.mPos.x;
    position.y = pakkun->mUnk_000.mPos.y + pakkun->mUnk_1f8;
    position.z = pakkun->mUnk_000.mPos.z;
    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_01ff9048(0x19, SetViewTransposeMatrixPos(&position), 12);
    t = pakkun->mUnk_1f0;
    f[0] = t;
    f[1] = t;
    f[2] = t;
    func_01ff9048(0x1b, f, 3);
    func_01ff9048(0x1b, &pakkun->mUnk_000.mScale, 3);
    SetMapObjectModelPolygonId(gPakkunZHead, pakkun->mPolygonId);
    DrawMapObjectModel(a, gPakkunZHead, pakkun);
}

void CreatePakkunBody(void *a) {
    gPakkunBody = CreateMapObjectModelNsbmd(a, "PakkunBody.nsbmd");
    SetMapObjectModelPolygonId(gPakkunBody, 0x3f);
    SetMapObjectModelAlpha(gPakkunBody, 0x1f);
}

void SetupDrawPakkunBody(void *a) {
    func_0209bbd0(a, gPakkunBody);
}

void DrawPakkunBody(void *a, Pakkun *pakkun) {
    s32 w;
    s32 v[3];
    s32 d;
    s32 y;
    s32 x;
    x = pakkun->mUnk_1e8;
    y = pakkun->mUnk_1f0;
    d = 0x3000 - x - y;
    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_01ff9048(0x19, func_020e6cbc(&pakkun->mUnk_000.mPos), 12);
    v[0] = d;
    v[1] = x + y - 0x1000;
    v[2] = d;
    func_01ff9048(0x1b, v, 3);
    func_01ff9048(0x1b, &pakkun->mUnk_000.mScale, 3);
    DrawMapObjectModel(a, gPakkunBody, pakkun);
}

void InitPakkunObjects(void) {
    s32 i;
    Pakkun *pakkun;
    float f;
    if (gPakkunUpdateList == NULL) {
        return;
    }
    for (i = 0; i < gPakkunUpdateList->mMapObjectCount && (pakkun = gPakkunUpdateList->mMapObjects[i]) != NULL; i++) {
        if (GetMapObjectModelNsbcaFrameCount(gPakkunMouth) - 1 > 0) {
            f = 0.5f + ((GetMapObjectModelNsbcaFrameCount(gPakkunMouth) - 1) << 12);
        } else {
            f = ((GetMapObjectModelNsbcaFrameCount(gPakkunMouth) - 1) << 12) - 0.5f;
        }
        pakkun->mUnk_0a4 = 0;
        pakkun->mUnk_0a8 = 0x1000;
        pakkun->mUnk_0ac = 0;
        pakkun->mUnk_0b0 = f;
        pakkun->mUnk_1e0 = -0xa4;
    }
}

void UpdatePakkun(void *a, Pakkun *pakkun) {
    BOOL f;
    s32 t;
    s32 x;
    s32 y;
    Unk0210b7a8 s;
    switch (pakkun->mState) {
        case 0:
            pakkun->mFollowerIndex += func_020983c4_inline((u16) (pakkun->mFollowerCount - 1)) + 1;
            if (pakkun->mFollowerIndex >= pakkun->mFollowerCount) {
                pakkun->mFollowerIndex -= pakkun->mFollowerCount;
            }
            pakkun->mState = 1;
        case 1:
            f = FALSE;
            if (pakkun->mUnk_1dc < pakkun->mUnk_1bc[pakkun->mFollowerIndex]) {
                pakkun->mUnk_1dc = pakkun->mUnk_1dc + 0x6d;
                if (pakkun->mUnk_1dc >= pakkun->mUnk_1bc[pakkun->mFollowerIndex]) {
                    f = TRUE;
                }
            } else {
                pakkun->mUnk_1dc = pakkun->mUnk_1dc - 0x6d;
                if (pakkun->mUnk_1dc <= pakkun->mUnk_1bc[pakkun->mFollowerIndex]) {
                    f = TRUE;
                }
            }
            if (f != FALSE) {
                if (func_020983c4_inline(2) == 0) {
                    pakkun->mState = 2;
                } else {
                    pakkun->mState = 0;
                }
            }
            break;
        case 2:
            if (pakkun->mUnk_1ec >= -4 && pakkun->mUnk_1ec <= 4) {
                pakkun->mTimer = 0x1e;
                pakkun->mState = 3;
            }
            break;
        case 3:
            if (pakkun->mTimer-- <= 0) {
                pakkun->mTimer = 0;
                if (pakkun->mUnk_1e8 >= 0xffc) {
                    pakkun->mUnk_1e8 = 0x1000;
                    pakkun->mUnk_1e4 = FALSE;
                    pakkun->mUnk_1f4 = 0x7b;
                    pakkun->mState = 4;
                }
            } else {
                pakkun->mUnk_1e0 = pakkun->mUnk_1e0 + 0xa4;
            }
            break;
        case 4:
            pakkun->mUnk_1f0 = pakkun->mUnk_1f0 + pakkun->mUnk_1f4;
            pakkun->mUnk_1f4 = pakkun->mUnk_1f4 - 8;
            if (pakkun->mUnk_1f4 <= 0) {
                if (pakkun->mUnk_1f0 <= 0x119a) {
                    pakkun->mState = 5;
                }
            }
            break;
        case 5:
            pakkun->mUnk_1f0 = pakkun->mUnk_1f0 + pakkun->mUnk_1f4;
            pakkun->mUnk_1f4 = pakkun->mUnk_1f4 - 8;
            if (pakkun->mUnk_1f0 <= 0x1000) {
                pakkun->mUnk_1f0 = 0x1000;
                pakkun->mUnk_1e4 = TRUE;
            }
            pakkun->mUnk_0a4 = pakkun->mUnk_0a4 + pakkun->mUnk_0a8;
            if (pakkun->mUnk_0a4 >= pakkun->mUnk_0b0) {
                pakkun->mUnk_0a4 = pakkun->mUnk_0ac;
            }
            if ((pakkun->mUnk_0a4 >> 12) == 10) {
                func_02098f18(&pakkun->mFollowers[pakkun->mFollowerIndex], pakkun->mUnk_1fc + 0x46000);
                if ((pakkun->mUnk_000.mDistanceSquaredAndFlags & 4) == 0) {
                    if (pakkun->mUnk_000.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                        t = 2;
                    } else if (pakkun->mUnk_000.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                        t = 3;
                    } else {
                        t = 4;
                    }
                    s.mSoundId = 0x171;
                    s.mPositionSource = &pakkun->mUnk_000.mPos;
                    s.mUnk_08 = t;
                    s.mDistanceSquared = GetHorizontalCameraDistanceSquared(&pakkun->mUnk_000.mPos);
                    func_0210b7a8(&s);
                }
            } else if (pakkun->mUnk_0a4 == 0) {
                pakkun->mTimer = 0x1e;
                pakkun->mState = 6;
            }
            break;
        case 6:
            if (pakkun->mTimer-- <= 0) {
                pakkun->mTimer = 0;
                pakkun->mState = 0;
            } else {
                pakkun->mUnk_1e0 = pakkun->mUnk_1e0 - 0xa4;
            }
            break;
    }
    if (pakkun->mUnk_1e4 != FALSE) {
        pakkun->mUnk_1e8 = pakkun->mUnk_1e8 + pakkun->mUnk_1ec;
        pakkun->mUnk_1ec = pakkun->mUnk_1ec + 4;
        if (pakkun->mUnk_1e8 >= 0x1000) {
            pakkun->mUnk_1ec = -0x52;
        }
    }
    x = ((s64) (pakkun->mUnk_1e8 + pakkun->mUnk_1f0 - 0x1000) * 0x2f000) >> 12;
    y = ((s64) pakkun->mUnk_1f0 * 0x17000) >> 12;
    pakkun->mUnk_1f8 = x + y;
}

void *CreatePakkunMouthDrawList(void) {
    gPakkunMouthDrawList = CreateMapObjectDrawList1(CreatePakkunMouth, DrawPakkunMouth, NULL);
    gPakkunMouthDrawList->mUnk_1c = TRUE;
    func_020d49d8(&gPakkunMouthDrawList);
    return gPakkunMouthDrawList;
}

void *CreatePakkunBodyDrawList(void) {
    gPakkunBodyDrawList = CreateMapObjectDrawList2(CreatePakkunBody, DrawPakkunBody, SetupDrawPakkunBody);
    func_020d49d8(&gPakkunBodyDrawList);
    return gPakkunBodyDrawList;
}

void *CreatePakkunZHeadDrawList(void) {
    gPakkunZHeadDrawList = CreateMapObjectDrawList2(CreatePakkunZHead, DrawPakkunZHead, SetupDrawPakkunZHead);
    gPakkunZHeadDrawList->mUnk_1c = TRUE;
    func_020d49d8(&gPakkunZHeadDrawList);
    return gPakkunZHeadDrawList;
}

void *CreatePakkunUpdateList(void) {
    gPakkunUpdateList = CreateMapObjectUpdateList(InitPakkunObjects, UpdatePakkun, NULL);
    SetUpdateListSlot(&gPakkunUpdateList);
    return gPakkunUpdateList;
}

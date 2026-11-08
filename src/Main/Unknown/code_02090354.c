#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_0207ffa4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_0207f000.h"
#include "Main/Unknown/code_0207ff5c.h"
#include "Main/Unknown/code_02080b1c.h"
#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020ee684.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "code_021458c4.h"
#include "code_02146cbc.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_020917d0.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_0207e654.h"

void CreateSmanTop(void *a) {
    void *p;
    p = CreateMapObjectModelNsbmd(a, gSmanTopNsbmdName);
    gSmanTop = p;
    SetMapObjectModelPolygonId(p, 0x3f);
}

void SetupDrawSmanTop(void *a) {
    func_0209bbd0(a, gSmanTop);
}

void DrawSmanTop(void *a, Sman *sman) {
    s32 c;
    s32 matrix[9];
    s32 s[3];
    c = 0x1e;
    func_01ff9048(0x14, &c, 1);
    func_01ff9048(0x19, func_020e6cbc(&sman->mUnk_00.mPos), 0xc);
    s[1] = sman->mTopHeight >> 4;
    s[0] = 0;
    s[2] = 0;
    func_01ff9048(0x1c, s, 3);
    func_01ff9048(0x1b, &sman->mUnk_00.mScale, 3);
    MTX_RotZ33_(matrix, gPairsByAngle[((u16) sman->mAngleZ >> 4) * 2],
                gPairsByAngle[((u16) sman->mAngleZ >> 4) * 2 + 1]);
    func_01ff9048(0x1a, matrix, 9);
    DrawMapObjectModel(a, gSmanTop, sman);
}

void CreateSmanBottom(void *a) {
    void *p;
    p = CreateMapObjectModelNsbmd(a, gSmanBottomNsbmdName);
    gSmanBottom = p;
    SetMapObjectModelPolygonId(p, 0x3f);
}

void SetupDrawSmanBottom(void *a) {
    func_0209bbd0(a, gSmanBottom);
}

void DrawSmanBottom(void *a, Sman *sman) {
    s32 c;
    s32 d[3];
    s32 v;
    c = 0x1e;
    func_01ff9048(0x14, &c, 1);
    func_01ff9048(0x19, func_020e6cbc(&sman->mUnk_00.mPos), 0xc);
    func_01ff9048(0x1b, &sman->mUnk_00.mScale, 3);
    v = sman->mBottomScale;
    d[0] = v;
    d[1] = v;
    d[2] = v;
    func_01ff9048(0x1b, d, 3);
    DrawMapObjectModel(a, gSmanBottom, sman);
}

void InitSmanObjects(SmanList *a) {
    s32 i;
    Sman *p;
    if (a == NULL) {
        return;
    }
    i = 0;
    while (i < a->mSmanCount && (p = a->mSmans[i]) != NULL) {
        p->mTopRiseProgress = 0x1000;
        p->mBottomScale = 0x1000;
        i++;
        p->mTopStartHeight = ((s64) p->mUnk_00.mScale.y * 0xf333) >> 12;
        p->mTopLowHeight = ((s64) p->mUnk_00.mScale.y * 0x2000) >> 12;
        p->mTopHeight = p->mTopStartHeight;
    }
}

void UpdateSman(void *a, Sman *sman) {
    Unk0210b7a8 s;
    s32 t;
    switch (sman->mState) {
        case 0:
            sman->mAngleZEnabled = 1;
            break;
        case 1:
            sman->mTopHeight = sman->mTopHeight + sman->mTopHeightPerFrame;
            sman->mTopHeightPerFrame = sman->mTopHeightPerFrame - 0x400;
            if (sman->mTopHeightPerFrame < -0x6000) {
                sman->mTopHeightPerFrame = -0x6000;
            }
            if (sman->mUnk_00.mCourseMapRow->mUnk_28 > 0) {
                if (sman->mTopHeight < 0) {
                    ParkMapObject(&sman->mUnk_00);
                }
            } else if (sman->mTopHeight < sman->mTopLowHeight) {
                sman->mTopHeight = sman->mTopLowHeight;
                sman->mTopHeightPerFrame = 0;
                sman->mState = 2;
                t = 2;
                if ((sman->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
                    if (sman->mUnk_00.mFarDistanceSquared != gSoundFalloffs[2].mUnk_20) {
                        if (sman->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                    }
                    s.mSoundId = 0x162;
                    s.mPositionSource = &sman->mUnk_00.mPos;
                    s.mUnk_08 = t;
                    s.mDistanceSquared = GetHorizontalCameraDistanceSquared(&sman->mUnk_00.mPos);
                    func_0210b7a8(&s);
                }
            }
            sman->mAngleZEnabled = 0;
            break;
        case 2:
            sman->mStateFrames = sman->mStateFrames + 1;
            if (sman->mStateFrames >= 0x12b) {
                sman->mStateFrames = 0;
                sman->mTopHeightPerFrame = ((sman->mTopStartHeight - sman->mTopLowHeight) * 0x40) / 0x1000;
                sman->mState = 3;
            }
            sman->mAngleZEnabled = 0;
            break;
        case 3:
            if (sman->mTopRiseProgress >= 0x1000) {
                sman->mTopRiseProgress = 0x1000;
                sman->mTopHeight = sman->mTopStartHeight;
            } else {
                sman->mTopRiseProgress = sman->mTopRiseProgress + 0x40;
                sman->mTopHeight = sman->mTopHeight + sman->mTopHeightPerFrame;
            }
            sman->mStateFrames = sman->mStateFrames + 1;
            if (sman->mStateFrames > 10) {
                sman->mBottomScale = sman->mBottomScale + 0x40;
                if (sman->mBottomScale >= 0x1000) {
                    sman->mStateFrames = 0;
                    sman->mBottomScale = 0x1000;
                    sman->mUnk_00.mFlags = sman->mUnk_00.mFlags & ~1;
                    sman->mState = 0;
                }
            }
            sman->mAngleZEnabled = 1;
            break;
    }
    if (sman->mAngleZEnabled == 0) {
        return;
    }
    sman->mAngleZ = sman->mAngleZ + sman->mAngleZPerFrame;
    if (sman->mAngleZ >= 0) {
        if (sman->mAngleZPerFrame < 0) {
            sman->mAngleZPerFrame = -0xf0;
        } else {
            sman->mAngleZPerFrame = sman->mAngleZPerFrame - 8;
        }
    } else {
        if (sman->mAngleZPerFrame >= 0) {
            sman->mAngleZPerFrame = 0xf0;
        } else {
            sman->mAngleZPerFrame = sman->mAngleZPerFrame + 8;
        }
    }
}

// Creates the kind record of Sman with two functions that put it into state 1 when their third argument points to 1.
void CreateSmanKindData(void) {
    func_0209bf70(func_02091828, func_020917d0, NULL, 0, 1, 0x161);
}

static inline BOOL func_02090940_inline(void) {
    BOOL r;
    enum { K0 } i;
    enum { L0 } j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (IsGrandPrixRecordFilled(i, j) != 0 && GetGrandPrixRecordCupRank(i, j) == 0) {
                r = TRUE;
            } else {
                r = FALSE;
            }
            if (r == FALSE) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

void *CreateSmanTopDrawList(void) {
    return CreateMapObjectDrawList2(CreateSmanTop, DrawSmanTop, SetupDrawSmanTop);
}

void *CreateSmanBottomDrawList(void) {
    return CreateMapObjectDrawList2(CreateSmanBottom, DrawSmanBottom, SetupDrawSmanBottom);
}

void *CreateSmanUpdateList(void) {
    return CreateMapObjectUpdateList(InitSmanObjects, UpdateSman, NULL);
}

static inline BOOL func_02090cf8_inline(s32 a, s32 b) {
    if (IsGrandPrixRecordFilled(a, b) != 0 && GetGrandPrixRecordCupRank(a, b) == 0) {
        return TRUE;
    }
    return FALSE;
}

u32 func_020911a8(void) {
    u32 r;
    r = 0;
    if (GetCurrentSceneNumber() == 10) {
        r = func_02090ff4();
        func_02056d40();
        func_02057d9c();
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    return r;
}

u32 func_0209119c(void) {
    return func_02090ff4();
}

u32 func_02090ff4(void) {
    u32 r;
    u32 q;
    BOOL t;
    r = 0;
    r = r | func_02090cf8();
    r = r | func_02090b24();
    q = 0;
    t = FALSE;
    if (func_02056d98() < 2) {
        if ((IsGrandPrixRecordFilled(3, 1) != 0 && GetGrandPrixRecordCupRank(3, 1) == 0) ? 1 : 0) {
            func_02056d54(2);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        q = 0x200;
    }
    t = FALSE;
    if (func_02056d98() < 3) {
        BOOL f;
        if (IsGrandPrixRecordFilled(3, 2) != 0 && GetGrandPrixRecordCupRank(3, 2) == 0) {
            f = TRUE;
        } else {
            f = FALSE;
        }
        if (f != FALSE) {
            goto l1;
        }
        if (IsGrandPrixRecordFilled(7, 2) != 0 && GetGrandPrixRecordCupRank(7, 2) == 0) {
            f = TRUE;
        } else {
            f = FALSE;
        }
        if (f != FALSE) {
        l1:
            func_02056d54(3);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        q = 0x400;
    }
    t = FALSE;
    if (func_02056d98() < 4) {
        if ((IsGrandPrixRecordFilled(3, 3) != 0 && GetGrandPrixRecordCupRank(3, 3) == 0) ? 1 : 0) {
            if ((IsGrandPrixRecordFilled(7, 3) != 0 && GetGrandPrixRecordCupRank(7, 3) == 0) ? 1 : 0) {
                func_02056d54(4);
                t = TRUE;
            }
        }
    }
    if (t != FALSE) {
        q = 0x800;
    }
    return r | q;
}

u32 func_02090cf8(void) {
    enum { K0 } i;
    u32 r;
    u32 q;
    u32 t;
    s32 j4;
    s32 j8;
    s32 j12;
    r = 0;
    for (i = 0; i < 4; i++) {
        t = 0;
        if (func_02056dec(i) == 0) {
            if (func_02090cf8_inline(0, i) != FALSE && func_02090cf8_inline(1, i) != FALSE) {
                func_02056e24(i);
                t = 1;
            }
        }
        r = r | t;
        t = 0;
        j4 = i + 4;
        if (func_02056dec(j4) == 0) {
            if (func_02090cf8_inline(2, i) != FALSE) {
                func_02056e24(j4);
                t = 2;
            }
        }
        r = r | t;
        t = 0;
        j8 = i + 8;
        if (func_02056dec(j8) == 0) {
            if (func_02090cf8_inline(4, i) != FALSE && func_02090cf8_inline(5, i) != FALSE) {
                func_02056e24(j8);
                t = 4;
            }
        }
        r = r | t;
        t = 0;
        j12 = i + 12;
        if (func_02056dec(j12) == 0) {
            if (func_02090cf8_inline(6, i) != FALSE) {
                func_02056e24(j12);
                t = 8;
            }
        }
        r = r | t;
    }
    q = 0;
    if (func_02056dec(0x10) == 0) {
        if (func_02090cf8_inline(3, 2) != FALSE && func_02090cf8_inline(7, 2) != FALSE) {
            func_02056e24(0x10);
            q = 0x10;
        }
    }
    return r | q;
}

u32 func_02090b24(void) {
    u32 r;
    BOOL t;
    r = 0;
    t = FALSE;
    if (func_02056dec(0x14) == 0) {
        if ((IsGrandPrixRecordFilled(3, 0) != 0 && GetGrandPrixRecordCupRank(3, 0) == 0) ? 1 : 0) {
            func_02056e24(0x14);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        r = r | 0x20;
    }
    t = FALSE;
    if (func_02056dec(0x15) == 0) {
        if ((IsGrandPrixRecordFilled(7, t) != 0 && GetGrandPrixRecordCupRank(7, t) == 0) ? 1 : 0) {
            func_02056e24(0x15);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        r = r | 0x40;
    }
    t = FALSE;
    if (func_02056dec(0x16) == 0) {
        if ((IsGrandPrixRecordFilled(7, 1) != 0 && GetGrandPrixRecordCupRank(7, 1) == 0) ? 1 : 0) {
            func_02056e24(0x16);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        r = r | 0x80;
    }
    t = FALSE;
    if (func_02056dec(0x17) == 0) {
        BOOL f;
        if (IsGrandPrixRecordFilled(3, 3) != 0 && GetGrandPrixRecordCupRank(3, 3) == 0) {
            f = TRUE;
        } else {
            f = FALSE;
        }
        if (f != FALSE) {
            goto l1;
        }
        if (IsGrandPrixRecordFilled(7, 3) != 0 && GetGrandPrixRecordCupRank(7, 3) == 0) {
            f = TRUE;
        } else {
            f = FALSE;
        }
        if (f != FALSE) {
        l1:
            func_02056e24(0x17);
            t = TRUE;
        }
    }
    if (t != FALSE) {
        r = r | 0x100;
    }
    return r;
}

s32 func_020909cc(void) {
    Unk0217b488 *p;
    s32 r;
    s32 n;
    s32 m;
    BOOL c;
    BOOL f;
    r = 0;
    p = data_0217b488;
    m = p->mEngineIndex;
    n = p->mCupIndex;
    if (p->mMirrorMode != 0) {
        m = 3;
    }
    c = FALSE;
    f = func_02090940_inline();
    if (f != FALSE) {
        if (n == 3 || n == 7) {
            if (data_0217b488->mCupRankIndex == 0) {
                c = TRUE;
            }
        }
    }
    if (c != FALSE) {
        r = 2;
    } else {
        c = FALSE;
        if (n == 3 || n == 7) {
            if (n == 7) {
                n = 3;
            } else {
                n = 7;
            }
            if (IsGrandPrixRecordFilled(n, m) != 0 && GetGrandPrixRecordCupRank(n, m) <= 2) {
                f = TRUE;
            } else {
                f = FALSE;
            }
            if (f != FALSE) {
                if (data_0217b488->mCupRankIndex <= 2) {
                    c = TRUE;
                }
            }
        }
        if (c != FALSE) {
            r = 1;
        }
    }
    return r;
}

BOOL IsAllGrandPrixRecordsTopRank(void) {
    return func_02090940_inline();
}

void LoadStaffGhostTime(void *a) {
    LoadFileIntoHeap(gStaffGhostTimeBinName, a, (void **) &gStaffGhostTime);
}

// TRUE when the time is smaller than entry a - 1 of the staff ghost times.
BOOL IsTimeLessThanStaffGhostTime(u32 a, void *c) {
    MinuteSecondMillisecondTime *b = c;
    return b->mSecond * 1000 + b->mMinute * 60000 + b->mMillisecond < gStaffGhostTime[a - 1];
}

void SetupKartKillerCursor(KartKillerCursor *a, u32 b) {
    Kart *p;
    p = GetKart(b);
    a->mKillerKartIndex = b;
    SetupPointLinkCursor(&a->mPointLinkCursor, b, (Unk02080b1c_00 *) gKartItems[b].mUnk_1f0.mLink);
    a->mUnk_26 = 0;
    a->mUnk_28 = 0;
    p->mTurnAngle = 0;
    EndKartDrift(p);
}

void ResetKartKillerCursorTo(KartKillerCursor *a, Unk02080b1c_00 *b) {
    if (b == a->mPointLinkCursor.mPreviousLink) {
        return;
    }
    SetupPointLinkCursor(&a->mPointLinkCursor, a->mKillerKartIndex, b);
}

s32 func_0209081c(KartKillerCursor *a) {
    AdvanceKartKillerAlongPointLinks(a);
    return func_020905a8(a);
}

// Holds the kart at a fixed speed, steers it toward the point link ahead, and moves the cursor on once the kart is past
// that link or close to it.
void AdvanceKartKillerAlongPointLinks(KartKillerCursor *a) {
    Kart *p;
    Vec3 v;
    s32 r;
    p = GetKart(a->mKillerKartIndex);
    v = p->mPos;
    a->mAngleToLinkDegrees =
        ComputeAngleToPositionDegrees(a->mPointLinkCursor.mLink->mUnk_18, &v, &p->mUnk_12c, &p->mUnk_138);
    if ((p->mUnk_48 & 0x40000000) != 0 && p->mSurfaceVariant == 1) {
        r = IsPastPointLink(&a->mPointLinkCursor, &v);
    } else {
        r = IsPastPointLink(&a->mPointLinkCursor, &v);
        if (r == 0) {
            r = IsWithinPointLinkDistance(&a->mPointLinkCursor, &v);
        }
    }
    p->mForwardSpeed = 0xa800;
    p->mSpeedLimitGoal = p->mForwardSpeed;
    p->mSpeedLimit = p->mSpeedLimitGoal;
    if (r != 0) {
        AdvancePointLinkCursorToFirstNext((u32) a);
    } else {
        TurnKartKillerTowardPointLink(a);
    }
}

// Turns the kart toward the point link ahead; the left and right keys first nudge the heading.
void TurnKartKillerTowardPointLink(KartKillerCursor *a) {
    Kart *p;
    s32 v;
    s32 s;
    u16 m;
    u16 w;
    s32 d;
    s32 e;
    s32 b;
    p = GetKart(a->mKillerKartIndex);
    v = a->mAngleToLinkDegrees;
    if ((p->mUnk_44 & KART_44_ON_GROUND) != 0) {
        s = 0x19a;
    } else {
        s = 0x52;
    }
    w = p->mHeadingAngle + (s16) (((s64) v * 0xb6 + 0x800) >> 12);
    b = *(volatile s32 *) &p->mEntryIndex;
    m = data_0217562a[b].mBits;
    if ((u16) (m & PAD_KEY_LEFT) != 0) {
        p->mHeadingAngle = p->mHeadingAngle + 0xa0;
    } else if ((u16) (m & PAD_KEY_RIGHT) != 0) {
        p->mHeadingAngle = p->mHeadingAngle - 0xa0;
    }
    d = w - p->mHeadingAngle;
    e = d;
    e = (e < 0) ? -e : e;
    if (e > 0x7fff) {
        if (d > 0) {
            d = -(0xffff - d);
        } else {
            d = d + 0xffff;
        }
    }
    p->mHeadingAngle = p->mHeadingAngle + (s32) (((s64) d * s) >> 12);
}

s32 func_020905a8(KartKillerCursor *a) {
    BOOL r;
    BOOL t;
    Kart *p;
    r = FALSE;
    t = FALSE;
    a->mUnk_28 = a->mUnk_28 - 1;
    if (a->mUnk_28 <= 0) {
        a->mUnk_28 = 0;
    } else {
        t = TRUE;
    }
    p = GetKart(a->mKillerKartIndex);
    if ((p->mUnk_44 & 0xc0) != 0) {
        t = TRUE;
        a->mUnk_28 = 5;
    }
    if (t != FALSE) {
        a->mUnk_26 = a->mUnk_26 + 1;
        if (a->mUnk_26 >= 0x78) {
            a->mUnk_26 = 0;
            r = TRUE;
        }
    } else if (a->mUnk_28 <= 0) {
        a->mUnk_26 = 0;
    }
    return r;
}

// Stores one of three sets of battle item entry tables and callbacks; any value other than 1 or 2 takes the third set.
void SetupBattleItemEntries(void) {
    switch (gRaceSetup->mCpuDifficulty) {
        case CPU_DIFFICULTY_EASY:
            gBattleHeldItemEntries = data_021561d0;
            gBattleItemInUseEntries = data_02155fd8;
            data_0217b0a0 = func_0208fafc;
            data_0217b090 = UseItemAfterInUse;
            data_0217b098 = func_0208f9ac;
            data_0217b094 = func_0208f6d4;
            data_0217b0ac = func_0208f4e8;
            data_0217b0a8 = UseItemBehindAfterInUseOrNearTarget;
            return;
        case CPU_DIFFICULTY_NORMAL:
            gBattleHeldItemEntries = data_021562a8;
            gBattleItemInUseEntries = data_02156128;
            data_0217b0a0 = func_0208fba0;
            data_0217b090 = func_0208f810;
            data_0217b098 = func_0208f9ac;
            data_0217b094 = func_0208f6d4;
            data_0217b0ac = func_0208f4e8;
            data_0217b0a8 = UseItemBehindAfterInUseOrNearTarget;
            return;
        case CPU_DIFFICULTY_HARD:
            gBattleHeldItemEntries = data_02156380;
            gBattleItemInUseEntries = data_02156080;
            data_0217b0a0 = ThrowItemAtNearTarget;
            data_0217b090 = func_0208f8ac;
            data_0217b098 = func_0208fa50;
            data_0217b094 = func_0208f754;
            data_0217b0ac = func_0208f5c4;
            data_0217b0a8 = func_0208f434;
            return;
        default:
            gBattleHeldItemEntries = data_02156380;
            gBattleItemInUseEntries = data_02156080;
            data_0217b0a0 = ThrowItemAtNearTarget;
            data_0217b090 = func_0208f8ac;
            data_0217b098 = func_0208fa50;
            data_0217b094 = func_0208f754;
            data_0217b0ac = func_0208f5c4;
            data_0217b0a8 = func_0208f434;
            return;
    }
}

#include "Main/Unknown/code_020c0dd8.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b1d64.h"
#include "Main/Unknown/code_020c13d0.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b1000.h"
#include "Main/Unknown/code_0203c8dc.h"

void func_020c1060(void) {
    s32 a[8];
    s32 c;
    u32 p;
    u32 r;
    u32 w;
    Unk0217aa1c_00 *s;
    s32 v;
    BOOL x0;
    s32 x1;
    BOOL x2;
    s32 x3;
    u16 i;
    u16 j;
    u16 k;
    s32 m;
    s32 n;
    s32 neg;

    neg = -1;
    x0 = FALSE;
    x1 = 0;
    x2 = FALSE;
    x3 = 0;
    {
        for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
            if (gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE) {
                v = x0;
                if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind <= 3 &&
                    ((1 << gRaceSetup->mCurrentEntries[i].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                    v = 1;
                }
                c = v != 0 ? 1 : x1;
                p = GetLowByte(i);
                r = GetCourseIndexInCup();
                w = gCupRecords->mUnk_000[r][GetLowByte(p)].mUnk_05;
                a[i] = w * 16 + c * 8 + 8 - GetKartRank(i);
            } else {
                v = x2;
                if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind <= 3 &&
                    ((1 << gRaceSetup->mCurrentEntries[i].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                    v = 1;
                }
                c = v != 0 ? 1 : x3;
                p = GetLowByte(i);
                r = GetCourseIndexInCup();
                s = &gCupRecords->mUnk_000[r][GetLowByte(p)];
                w = s->mUnk_00;
                a[i] = w * 16 + c * 8 + 8 - GetKartRank(i);
                p = GetLowByte(i);
                r = GetCourseIndexInCup();
                s = &gCupRecords->mUnk_000[r][GetLowByte(p)];
                gRaceGoalS->mShownNumbers[i] = s->mUnk_00;
            }
        }
    }
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        gRaceGoalS->mRowKartIndex[i] = i;
        a[i] = a[i] * neg;
    }
    SortIndicesByKey(gRaceGoalS->mRowKartIndex, a, gRaceSetup->mKartCount);
    for (k = 0; k < (u32) gRaceSetup->mKartCount; k++) {
        {
            for (j = 0; j < (u32) gRaceSetup->mKartCount; j++) {
                if (k == gRaceGoalS->mRowKartIndex[j]) {
                    m = j;
                    SetKartCupRank(k, (j + 1) & 0xff);
                    data_0217b488->mUnk_ec[k] = j;
                    break;
                }
            }
            for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
                if (k == gRaceGoalS->mPreviousRowKartIndex[i]) {
                    n = i;
                    break;
                }
            }
            if (m < n) {
                gRaceGoalS->mRankComparison[k] = 1;
            } else if (m > n) {
                gRaceGoalS->mRankComparison[k] = 0;
            } else {
                gRaceGoalS->mRankComparison[k] = 2;
            }
        }
    }
}

void func_020c0fd0(void) {
    s32 n;

    n = gRaceGoalS->mUpdateFrames++;
    if (n < 0x14) {
        gRaceGoalS->mOffsetX = InterpolateS16(1, 0, 0x100, n, 0x14);
    } else {
        gRaceGoalS->mOffsetX = 0x100;
        gRaceGoalS->mUpdate = func_020c0f48;
        gRaceGoalS->mUpdateFrames = 0;
        RequestRaceHudSubScreenState5();
    }
}

void func_020c0f48(void) {
    s32 n;

    n = gRaceGoalS->mUpdateFrames++;
    if (n < 0x14) {
        gRaceGoalS->mOffsetX = InterpolateS16(1, 0x80, 0, n, 0x14);
    } else {
        gRaceGoalS->mOffsetX = 0;
        gRaceGoalS->mUpdate = func_020c0f0c;
        gRaceGoalS->mUpdateFrames = 0;
    }
}

void func_020c0f0c(void) {
    func_020c1060();
    gRaceGoalS->mUpdate = func_020c0ee4;
    gRaceGoalS->mUpdateFrames = 0;
}

void func_020c0ee4(void) {
    gRaceGoalS->mUpdate = func_020c0dd8;
    gRaceGoalS->mUpdateFrames = 0;
}

static inline Unk0217aa1c_144_00 *func_020c0dd8_inline(s32 j) {
    return &gCupRecords->mUnk_144[GetCourseIndexInCup()].mUnk_00[j];
}

void func_020c0dd8(void) {
    s32 a;
    s32 b;

    if (gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE) {
        if (gRaceSetup->mUseTeams != 0) {
            a = func_020c0dd8_inline(0)->mUnk_02;
            b = func_020c0dd8_inline(1)->mUnk_02;
            if (a <= b) {
                a = b;
            }
        } else {
            a = gRaceGoalS->mShownNumbers[gRaceGoalS->mRowKartIndex[0]];
        }
        gRaceGoalS->mUnk_00b4 = a >= gRaceSetup->mCourseCount;
    } else {
        gRaceGoalS->mUnk_00b4 = gRaceSetup->mCourseNumber >= gRaceSetup->mCourseCount;
    }
    gRaceGoalS->mUpdate = func_020c13d0;
    gRaceGoalS->mUpdateFrames = 0;
}

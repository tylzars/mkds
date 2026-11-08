#include "Main/Unknown/code_020ae824.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_020b3724.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b9994.h"
#include "Main/Unknown/code_020bb5ec.h"
#include "Main/Unknown/code_020bc11c.h"
#include "Main/Unknown/code_020be950.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c2118.h"
#include "Main/Unknown/code_020c3e44.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02022030.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_020c53c4.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020d1158.h"
#include "Main/Unknown/code_020d12e0.h"
#include "Main/Unknown/code_020d1298.h"
#include "Main/Unknown/code_020d18d4.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_0200eddc.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_0203c5f8.h"

void func_020ae824(void) {
    u32 v;
    s32 subScreenState;

    v = gRaceSetup->mRaceKind;
    if (v == RACE_KIND_START_GP) {
        DrawRaceStartGp();
        return;
    }
    if (v == RACE_KIND_AWARD) {
        return;
    }
    if (v == RACE_KIND_STAFF_ROLL) {
        DrawEndingStaffRoll();
        return;
    }
    if (gRaceHud->mEnabled == FALSE) {
        return;
    }
    UpdateRaceStartSequenceSounds();
    RaceHudDrawNop();
    gRaceHud->mMainOamCount = 0;
    gRaceHud->mMainMatrixCount = 0;
    if (gRaceSetup->mRaceKind == 4) {
        func_020d1198((RaceHudOamBuffer *) gRaceHud->mMainOam);
    }
    v = gRaceSetup->mMode;
    if ((v == MODE_BATTLE        ? gRaceProgress->mRaceDone
         : v == MODE_MISSION_RUN ? IsFramesSinceFinishPastWait()
                                 : (IsKartEnded(GetFollowedKartOrEntryIndex()) != 0 && gRaceHud->mUnk_8dc == 0)) == 0) {
        DrawRaceItemSlot((RaceHudOamBuffer *) gRaceHud->mMainOam);
        DrawRaceLapAndTimeDifference((RaceHudOamBuffer *) gRaceHud->mMainOam);
        DrawRaceMNumberPair((RaceHudOamBuffer *) gRaceHud->mMainOam);
        DrawRaceGoalTimes((RaceHudOamBuffer *) gRaceHud->mMainOam);
        DrawRaceLinkLevel((Unk020c06c4 *) gRaceHud->mMainOam);
        DrawRaceModeCount((RaceHudOamBuffer *) gRaceHud->mMainOam);
        DrawRaceGoalM((Unk020c06c4 *) gRaceHud->mMainOam);
    } else {
        DrawRaceGoalTimes((RaceHudOamBuffer *) gRaceHud->mMainOam);
        DrawRaceLinkLevel((Unk020c06c4 *) gRaceHud->mMainOam);
        DrawRaceGoalM((Unk020c06c4 *) gRaceHud->mMainOam);
    }
    DC_FlushRange(gRaceHud->mMainOam, 0x400);
    MI_DmaFill32(3, gRaceHud->mMainOam + gRaceHud->mMainOamCount * 8, 0xc0, (0x80 - gRaceHud->mMainOamCount) << 3);
    gRaceHud->mSubOamCount = 0;
    gRaceHud->mSubMatrixCount = 0;
    subScreenState = gRaceHud->mSubScreenState;
    if (subScreenState != 4 && subScreenState != 5) {
        DrawRaceTimeDigits((RaceHudOamBuffer *) gRaceHud->mSubOam);
    }
    DrawRaceRankList((RaceHudOamBuffer *) gRaceHud->mSubOam);
    DC_FlushRange(gRaceHud->mSubOam, 0x400);
    MI_DmaFill32(3, gRaceHud->mSubOam + gRaceHud->mSubOamCount * 8, 0xc0, (0x80 - gRaceHud->mSubOamCount) << 3);
    switch (gRaceHud->mSubScreenState) {
        case 0:
            DrawRaceHudSubScreenCellGroups(gRaceHud->mSubOam);
            break;
        case 1:
        case 2:
        case 3:
            DrawRaceHudSubScreenCellGroups(gRaceHud->mSubOam);
            DrawRaceTaPositions((Unk020c06c4 *) gRaceHud->mSubOam);
            break;
        case 4:
        case 5:
            DrawRaceGoalS((Unk020c06c4 *) gRaceHud->mSubOam);
            break;
        case 6:
            DrawRaceNewRecordTa((Unk020c06c4 *) gRaceHud->mSubOam);
            break;
    }
}

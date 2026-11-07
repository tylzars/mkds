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
    s32 a;

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
    func_020b3410();
    func_020b3724();
    gRaceHud->mUnk_404 = 0;
    gRaceHud->mUnk_406 = 0;
    if (gRaceSetup->mRaceKind == 4) {
        func_020d1198((RaceHudOamBuffer *) gRaceHud->mUnk_004);
    }
    v = gRaceSetup->mMode;
    if ((v == MODE_BATTLE        ? gRaceProgress->mRaceDone
         : v == MODE_MISSION_RUN ? IsFramesSinceFinishPastWait()
                                 : (IsKartEnded(GetFollowedKartOrEntryIndex()) != 0 && gRaceHud->mUnk_8dc == 0)) == 0) {
        func_020ba63c((RaceHudOamBuffer *) gRaceHud->mUnk_004);
        DrawRaceLapAndTimeDifference((RaceHudOamBuffer *) gRaceHud->mUnk_004);
        DrawRaceMNumberPair((RaceHudOamBuffer *) gRaceHud->mUnk_004);
        DrawRaceGoalTimes((RaceHudOamBuffer *) gRaceHud->mUnk_004);
        DrawRaceLinkLevel((Unk020c06c4 *) gRaceHud->mUnk_004);
        func_020b9dfc((RaceHudOamBuffer *) gRaceHud->mUnk_004);
        DrawRaceGoalM((Unk020c06c4 *) gRaceHud->mUnk_004);
    } else {
        DrawRaceGoalTimes((RaceHudOamBuffer *) gRaceHud->mUnk_004);
        DrawRaceLinkLevel((Unk020c06c4 *) gRaceHud->mUnk_004);
        DrawRaceGoalM((Unk020c06c4 *) gRaceHud->mUnk_004);
    }
    DC_FlushRange(gRaceHud->mUnk_004, 0x400);
    MI_DmaFill32(3, gRaceHud->mUnk_004 + gRaceHud->mUnk_404 * 8, 0xc0, (0x80 - gRaceHud->mUnk_404) << 3);
    gRaceHud->mUnk_808 = 0;
    gRaceHud->mUnk_80a = 0;
    a = gRaceHud->mSubScreenState;
    if (a != 4 && a != 5) {
        func_020bb5ec((RaceHudOamBuffer *) gRaceHud->mUnk_408);
    }
    DrawRaceRankList((RaceHudOamBuffer *) gRaceHud->mUnk_408);
    DC_FlushRange(gRaceHud->mUnk_408, 0x400);
    MI_DmaFill32(3, gRaceHud->mUnk_408 + gRaceHud->mUnk_808 * 8, 0xc0, (0x80 - gRaceHud->mUnk_808) << 3);
    switch (gRaceHud->mSubScreenState) {
        case 0:
            DrawRaceHudSubScreenCellGroups(gRaceHud->mUnk_408);
            break;
        case 1:
        case 2:
        case 3:
            DrawRaceHudSubScreenCellGroups(gRaceHud->mUnk_408);
            DrawRaceTaPositions((Unk020c06c4 *) gRaceHud->mUnk_408);
            break;
        case 4:
        case 5:
            func_020c2118((Unk020c06c4 *) gRaceHud->mUnk_408);
            break;
        case 6:
            DrawRaceNewRecordTa((Unk020c06c4 *) gRaceHud->mUnk_408);
            break;
    }
}

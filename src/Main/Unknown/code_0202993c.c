#include "Main/Unknown/code_0202993c.h"
#include "Main/Unknown/code_02029a24.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on
u16 *func_02029a18(void) {
    return (u16 *) 0x27ffc40;
}

u32 func_020299f0(void) {
    if (*func_02029a18() == 2) {
        return 1;
    }
    return 0;
}

u32 func_020299e4(void) {
    return func_020299f0();
}

#pragma thumb on

void ResetRaceSetupCopy(void) {
    s32 entryIndex;
    func_02029a38(gRaceSetupCopy, 0x110);
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        gRaceSetupCopy->mEntries[entryIndex].mCharacterIndex = -1;
        gRaceSetupCopy->mEntries[entryIndex].mKartIndex = -1;
        gRaceSetupCopy->mEntries[entryIndex].mPlayerKind = 4;
        gRaceSetupCopy->mEntries[entryIndex].mTeamIndex = -1;
        gRaceSetupCopy->mEntries[entryIndex].mUnk_10 = 3;
    }
    gRaceSetupCopy->mMissionTableRow = 1;
    gRaceSetupCopy->mMissionTableColumn = 1;
    if (func_02029a24() == 0) {
        if (func_020299e4() == 0) {
            gRaceSetupCopy->mMissionFile = FindSceneFile(data_usa_0216212c);
        } else {
            gRaceSetupCopy->mMissionFile = NULL;
        }
        if (gRaceSetupCopy->mMissionFile != NULL) {
            gRaceSetupCopy->mMissionFileRows = (Unk02029930_f8 *) (gRaceSetupCopy->mMissionFile + 8);
        } else {
            gRaceSetupCopy->mMissionFileRows = NULL;
        }
    }
}

#include "Main/Unknown/code_020ccab0.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020ccb48.h"

#pragma optimize_for_size on
#pragma thumb on
void func_020ccab0(void) {
    u8 i;
    s32 a;

    for (i = 0; i < 8; i++) {
        if (GetRaceSetupCopy()->mUnk_c0 == 0 && GetRaceSetupCopy()->mEntries[i].mPlayerKind == 1) {
            func_020ccb48(i);
        } else {
            a = GetRaceSetupCopy()->mUseTeams != 0 ? GetRaceSetupCopy()->mEntries[i].mTeamIndex : -1;
            func_020468b0(i, GetRaceSetupCopy()->mEntries[i].mCharacterIndex,
                          GetRaceSetupCopy()->mEntries[i].mKartIndex, GetRaceSetupCopy()->mEntries[i].mPlayerKind, a,
                          GetRaceSetupCopy()->mEntries[i].mUnk_10);
        }
    }
}
#pragma thumb off

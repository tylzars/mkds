#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_0208bd20.h"
#include "Main/Unknown/code_0208bd40.h"
#include "Main/Unknown/code_0208bd44.h"
#include "Main/Unknown/code_0208bf6c.h"
#include "Main/Unknown/code_0208bfd8.h"
#include "Main/Unknown/unk_0217b000.h"

// Stores the CPU kart callbacks for Award and Mission Run, Staff Roll, Battle, or else the race ones.
void RegisterKartAiCallbacks(void) {
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD || gRaceSetup->mMode == MODE_MISSION_RUN) {
        gKartAiSetupCallback = func_0208be00;
        gKartAiResetCallback = func_0208bde0;
        gKartAiAdvanceCallback = func_0208bdc0;
        gKartAiRequestLinkCallback = RequestKartAiPointLink;
        gKartAiIsLinkRequestedCallback = IsKartAiLinkRequested;
        gKartAiLinkPosAndDirectionCallback = CopyKartAiLinkPosAndDirection;
        gKartAiSetupHeldItemEntryCallback = func_0208bfec;
        gKartAiSetupItemInUseEntryCallback = func_0208bfd8;
    } else if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        gKartAiSetupCallback = func_0208bd44;
        gKartAiResetCallback = func_0208bd40;
        gKartAiAdvanceCallback = func_0208bd20;
        gKartAiRequestLinkCallback = RequestKartAiPointLink;
        gKartAiIsLinkRequestedCallback = IsKartAiLinkRequested;
        gKartAiLinkPosAndDirectionCallback = CopyKartAiLinkPosAndDirection;
        gKartAiSetupHeldItemEntryCallback = func_0208bfec;
        gKartAiSetupItemInUseEntryCallback = func_0208bfd8;
    } else if (gRaceSetup->mMode == MODE_BATTLE) {
        gKartAiSetupCallback = SetupKartAiForBattle;
        gKartAiResetCallback = ResetKartAiForBattle;
        gKartAiAdvanceCallback = func_0208bf40;
        gKartAiRequestLinkCallback = func_0208bef4;
        gKartAiIsLinkRequestedCallback = func_0208bee0;
        gKartAiLinkPosAndDirectionCallback = func_0208bea4;
        gKartAiSetupHeldItemEntryCallback = func_0208be90;
        gKartAiSetupItemInUseEntryCallback = func_0208be7c;
    } else {
        gKartAiSetupCallback = SetupKartAiForRace;
        gKartAiResetCallback = ResetKartAiForRace;
        gKartAiAdvanceCallback = AdvanceKartAiForRace;
        gKartAiRequestLinkCallback = RequestKartAiPointLink;
        gKartAiIsLinkRequestedCallback = IsKartAiLinkRequested;
        gKartAiLinkPosAndDirectionCallback = CopyKartAiLinkPosAndDirection;
        gKartAiSetupHeldItemEntryCallback = func_0208bfec;
        gKartAiSetupItemInUseEntryCallback = func_0208bfd8;
    }
}

void CallKartAiSetup(KartAi *kartAi, s32 kartIndex) {
    gKartAiSetupCallback(kartAi, kartIndex);
}

void CallKartAiReset(KartAi *kartAi, PointLink *link) {
    gKartAiResetCallback(kartAi, link);
}

void CallKartAiAdvance(KartAi *kartAi) {
    gKartAiAdvanceCallback(kartAi);
}

void CallKartAiRequestLink(KartAi *kartAi) {
    gKartAiRequestLinkCallback(kartAi);
}

void CallKartAiLinkPosAndDirection(Vec3 *position, Vec3 *direction, KartAi *kartAi) {
    gKartAiLinkPosAndDirectionCallback(position, direction, kartAi);
}

void CallKartAiSetupHeldItemEntry(KartAi *kartAi) {
    gKartAiSetupHeldItemEntryCallback(kartAi);
}

void CallKartAiSetupItemInUseEntry(KartAi *kartAi) {
    gKartAiSetupItemInUseEntryCallback(kartAi);
}

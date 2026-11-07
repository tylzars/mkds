#include "Main/Unknown/code_020b1d64.h"
#include "Main/Unknown/unk_0217b000.h"

void RequestRaceHudSubScreenState5(void) {
    gRaceHud->mSubScreenState = 5;
    gRaceHud->mSubScreenEnabled = TRUE;
    gRaceHud->mSubScreenState5LoadPending = TRUE;
}

void RequestRaceHudSubScreenState6(void) {
    gRaceHud->mSubScreenState = 6;
    gRaceHud->mSubScreenEnabled = TRUE;
    gRaceHud->mSubScreenState6LoadPending = TRUE;
}

#include "Main/Unknown/code_020b19b4.h"
#include "Main/Unknown/unk_0217b000.h"

void GetRaceHudTimeDifference(s32 **a, TimeDigits **b) {
    *a = &gRaceHud->mTimeDifferenceSign;
    *b = &gRaceHud->mTimeDifferenceDigits;
}

#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/unk_0217b000.h"

BOOL GetShowLapTime(void) {
    return (gRaceHud->mShowLapTime);
}

u32 GetShowLapTimeFrames(void) {
    return (gRaceHud->mShowLapTimeFrames);
}

u32 GetUseTimeDifference(void) {
    return (gRaceHud->mUseTimeDifference);
}

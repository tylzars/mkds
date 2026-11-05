#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/unk_0217b000.h"

// No NULL check: only valid while gRaceHud exists (race code only).
s32 GetRaceHudUpdateFrames(void) {
    u32 value0;
    value0 = (u32) &gRaceHud;
    value0 = (u32) gRaceHud->mUpdateFrames;
    return (s32) value0;
}

// No NULL check: only valid while gRaceHud exists (race code only).
s32 GetRaceHudSubScreenState(void) {
    u32 value0;
    value0 = (u32) &gRaceHud;
    value0 = (u32) gRaceHud->mSubScreenState;
    return (s32) value0;
}

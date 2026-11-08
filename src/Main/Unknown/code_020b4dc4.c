#include "Main/Unknown/code_020b4dc4.h"
#include "Main/Unknown/code_0207a68c.h"
#include "Main/Unknown/unk_021759c0.h"

u32 RaceHudSubScreenGetCurrentMode(void) {
    return (gRaceSetup->mMode);
}

u32 func_020b4dc4(int kartIndex) {
    int currentMode;
    u32 v2;
    currentMode = RaceHudSubScreenGetCurrentMode();
    if ((currentMode == MODE_TIME_ATTACK) && (kartIndex != 0)) {
        return 1;
    }
    v2 = func_0207a68c(kartIndex);
    return v2;
}

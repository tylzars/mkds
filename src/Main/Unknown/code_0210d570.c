#include "Main/Unknown/code_0210d570.h"
#include "Main/Unknown/code_0210d0b4.h"
#include "Main/Unknown/unk_0217d000.h"

u32 func_0210d58c(Unk0217d070 *scenePlayers) {
    return (u32) scenePlayers;
}

void func_0210d570(Unk0217d070 *scenePlayers, s32 unused) {
    ReleaseAllSoundSources();
    scenePlayers->mUnk_00 = 0;
}

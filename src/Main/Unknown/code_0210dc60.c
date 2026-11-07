#include "Main/Unknown/code_0210dc60.h"
#include "Main/Unknown/unk_0217d000.h"

void SetupSoundMode(Unk0217d084 *modeHolder, Unk0217d070 *scenePlayers, u32 p2) {
    modeHolder->mMode = 0;
    modeHolder->mUnk_14 = p2;
    modeHolder->mScenePlayers = scenePlayers;
    modeHolder->mSavedMode = 0;
    modeHolder->mUnk_18 = NULL;
}

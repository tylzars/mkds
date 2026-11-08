#include "Main/Unknown/code_0210dc50.h"
#include "Main/Unknown/code_0210d9a0.h"
#include "Main/Unknown/unk_0217d000.h"

void RestoreSavedSoundMode(SoundModeHolder *modeHolder) {
    SetSoundMode(modeHolder, modeHolder->mSavedMode);
}

#include "Main/Unknown/code_0210a664.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0210a67c.h"

void func_0210a664(Kart *kart) {
    kart->mUnk_450.mUnk_34 = (~(0x0u));
    kart->mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) UpdateKartPlayingSound;
}

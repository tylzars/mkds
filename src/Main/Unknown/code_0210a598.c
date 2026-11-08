#include "Main/Unknown/code_0210a598.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0210a63c.h"
#include "Main/Unknown/code_0210aa0c.h"
#include "Main/Unknown/code_0210ab30.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_0210aa14.h"
#include "Main/Unknown/unk_021759c0.h"

void InitKartSoundCallbacks(Kart *kart, Unk0210a5a8 *b) {
    if (kart->mUnk_7c & KART_7C_ENTRY_KIND_2) {
        kart->mSoundSource.mStartSeqFunction = (void (*)(void *, void *, u32)) func_0210ab44;
    } else {
        kart->mSoundSource.mStartSeqFunction = (void (*)(void *, void *, u32)) StartKartPlayingSoundSeq;
    }
    kart->mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) UpdateKartPlayingSound;
    if (GetCurrentSceneNumber() == 2 || kart->mIndex != gRaceSetup->mEntryIndex) {
        b->mUnk_3c = func_0210a63c;
    } else {
        b->mUnk_3c = func_0210aa0c;
    }
}

void func_0210a598(Kart *kart, s32 soundIndex) {
    func_0210af40(kart, soundIndex, 8);
}

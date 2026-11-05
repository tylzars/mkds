#include "Main/Unknown/code_0210a598.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0210a63c.h"
#include "Main/Unknown/code_0210aa0c.h"
#include "Main/Unknown/code_0210ab30.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_0210aa14.h"
#include "Main/Unknown/unk_021759c0.h"

void func_0210a5a8(Kart *a, Unk0210a5a8 *b) {
    if (a->mUnk_7c & KART_7C_ENTRY_KIND_2) {
        a->mSoundSource.mUnk_2c = (void (*)(void *, void *, u32)) func_0210ab44;
    } else {
        a->mSoundSource.mUnk_2c = (void (*)(void *, void *, u32)) func_0210aa14;
    }
    a->mSoundSource.mUnk_30 = (void (*)(void *, void *, void *)) func_0210a76c;
    if (GetCurrentSceneNumber() == 2 || a->mIndex != data_021759c0->mEntryIndex) {
        b->mUnk_3c = func_0210a63c;
    } else {
        b->mUnk_3c = func_0210aa0c;
    }
}

void func_0210a598(Kart *a, s32 b) {
    func_0210af40(a, b, 8);
}

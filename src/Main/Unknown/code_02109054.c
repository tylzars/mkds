#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/unk_0217c000.h"

PlayingSound *StartSound(SoundSource *p, u32 a, u32 b, s16 c) {
    if (!(data_0217c780 & 1)) {
        return NULL;
    }
    return ((PlayingSound * (*) (SoundSource *, u32, u32, u32, s32)) StartSoundEx)(p, 0, a, b, c);
}

PlayingSound *StartSoundWhileRequested(SoundSource *p, u32 a, u32 b, s32 c) {
    if (!(data_0217c780 & 1)) {
        return NULL;
    }
    return ((PlayingSound * (*) (SoundSource *, u32, u32, u32, s32)) StartSoundWhileRequestedEx)(p, 0, a, b, c);
}

void StopSound(SoundSource *p, u32 a) {
    StopSoundEx(p, 0, a, 0);
}

void func_02109054(SoundSource *p) {
    ReleaseSoundSource(p);
}

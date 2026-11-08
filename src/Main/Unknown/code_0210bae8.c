#include "Main/Unknown/code_0210bae8.h"
#include "Main/Unknown/code_0210bcf4.h"

u32 func_0210baf8(u32 value) {
    return value;
}

void func_0210bae8(SoundSource *soundSource) {
    soundSource->mTrackParamsFunction = (void (*)(void *, void *, void *)) func_0210baf8;
}

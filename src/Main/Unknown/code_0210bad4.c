#include "Main/Unknown/code_0210bad4.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_02109000.h"

void func_0210bad4(u32 soundSource, u32 soundId) {
    u32 sourceCopy = soundSource;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 zero;
    u32 value12;
    volume = 0x7fu;
    zero = 0u;
    StartSoundWhileRequested((SoundSource *) sourceCopy, soundIdCopy, volume, zero);
}

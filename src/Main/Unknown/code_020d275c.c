#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_02109054.h"

void StartMapObjectSound(MapObject *arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    u32 value12;
    value0 = (u32) * (const u32 *) ((value0) + (148));
    value2 = 0x7fu;
    value3 = 0u;
    value0 = (u32) StartSound((void *) value0, value1, value2, value3);
}

void StartMapObjectSoundWhileRequested(MapObject *arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    u32 value12;
    value0 = (u32) * (const u32 *) ((value0) + (148));
    value2 = 0x7fu;
    value3 = 0u;
    StartSoundWhileRequested((SoundSource *) value0, value1, value2, value3);
}

#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_02109054.h"

void StartMapObjectSound(MapObject *mapObject, u32 soundId) {
    u32 value0 = (u32) mapObject;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 value3;
    u32 unused;
    value0 = *(const u32 *) ((value0) + (148));
    volume = 0x7fu;
    value3 = 0u;
    value0 = (u32) StartSound((void *) value0, soundIdCopy, volume, value3);
}

void StartMapObjectSoundWhileRequested(MapObject *mapObject, u32 soundId) {
    u32 value0 = (u32) mapObject;
    u32 soundIdCopy = soundId;
    u32 volume;
    u32 value3;
    u32 unused;
    value0 = *(const u32 *) ((value0) + (148));
    volume = 0x7fu;
    value3 = 0u;
    StartSoundWhileRequested((SoundSource *) value0, soundIdCopy, volume, value3);
}

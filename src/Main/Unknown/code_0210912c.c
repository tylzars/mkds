#include "Main/Unknown/code_0210912c.h"
#include "Main/Unknown/code_02109184.h"
#include "Main/Unknown/code_0210d020.h"
#include "Main/Unknown/code_0210d4a4.h"
#include "Main/Unknown/unk_0217c000.h"

void func_0210912c(void) {
    InitSoundFalloffs();
    InitPlayingSoundPool((PlayingSound *) data_0217c91c, 0xc);
    SetSoundPanFunction(ComputeSoundPan);
    SetSoundDistanceFunction(ComputeSoundDistanceAndOffsets);
    SetSoundVolumeFunction(ComputeSoundVolume);
}

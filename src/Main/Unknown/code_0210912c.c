#include "Main/Unknown/code_0210912c.h"
#include "Main/Unknown/code_02109184.h"
#include "Main/Unknown/code_0210d020.h"
#include "Main/Unknown/code_0210d4a4.h"
#include "Main/Unknown/unk_0217c000.h"

void func_0210912c(void) {
    InitSoundFalloffs();
    func_0210d4a4((PlayingSound *) data_0217c91c, 0xc);
    func_0210d040(ComputeSoundPan);
    func_0210d030(ComputeSoundDistanceAndOffsets);
    func_0210d020(ComputeSoundVolume);
}

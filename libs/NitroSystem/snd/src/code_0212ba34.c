#include "code_0212ba34.h"
#include "snd_interface.h"

// Centers the master pan when mono is set, otherwise resets it.
void NNS_SndSetMonoFlag(BOOL mono) {
    if (mono != 0) {
        SND_SetMasterPan(0x40);
        return;
    }
    SND_ResetMasterPan();
}

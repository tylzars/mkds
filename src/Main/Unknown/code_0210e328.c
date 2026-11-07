#include "Main/Unknown/code_0210e328.h"
#include "code_0212bcac.h"

void ResetPlayingSoundHandle(PlayingSound *sound) {
    u32 soundAddress = (u32) sound;
    u32 zero;
    u32 unused;
    zero = 0u;
    *(u32 *) ((soundAddress) + (4)) = zero;
    NNS_SndHandleInit((NNSSndSeqPlayer **) soundAddress);
}

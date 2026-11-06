#include "code_0212c7a0.h"
#include "Main/Unknown/unk_0217d000.h"

// Sets NNSSndPlayer.mVolume.
void NNS_SndPlayerSetPlayerVolume(u32 index, u32 volume) {
    data_0217d89c[index].mVolume = volume;
}

// Sets NNSSndPlayer.mPlayableSeqCount.
void NNS_SndPlayerSetPlayableSeqCount(u32 index, u32 seqCount) {
    data_0217d89c[index].mPlayableSeqCount = (u16) seqCount;
}

// Sets NNSSndPlayer.mAllocChBitFlag.
void NNS_SndPlayerSetAllocatableChannel(u32 index, u32 channels) {
    data_0217d89c[index].mAllocChBitFlag = channels;
}

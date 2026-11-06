#pragma once

#include "types.h"
#include "code_0212d214.h"

// 0x24 bytes; data_0217d89c holds an array of them. NNSSndPlayer.mPlayerList holds the sequence players of the player,
// NNSSndPlayer.mHeapList its free player heaps.
typedef struct NNSSndPlayer {
    /* 00 */ NNSFndList mPlayerList;
    /* 0c */ NNSFndList mHeapList;
    /* 18 */ u32 mPlayableSeqCount;
    /* 1c */ u32 mAllocChBitFlag;
    /* 20 */ u8 mVolume;
    /* 21 */ u8 mUnk_21[3];
} NNSSndPlayer;

void NNS_SndPlayerSetAllocatableChannel(u32 index, u32 channels);
void NNS_SndPlayerSetPlayableSeqCount(u32 index, u32 seqCount);
void NNS_SndPlayerSetPlayerVolume(u32 index, u32 volume);

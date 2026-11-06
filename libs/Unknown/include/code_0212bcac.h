#pragma once

#include "types.h"
#include "code_0212f788.h" // NNSSndFader

// 0x44 bytes; sixteen of them in data_0217d45c. Most functions take a pointer to a pointer to one (the sound handle).
typedef struct NNSSndSeqPlayer {
    /* 00 */ struct NNSSndSeqPlayer **mHandle;
    /* 04 */ struct NNSSndPlayer *mPlayer;
    /* 08 */ struct NNSSndPlayerHeap *mHeap;
    /* 0c */ u8 mPlayerLink[8];
    /* 14 */ u8 mPrioLink[8];
    /* 1c */ NNSSndFader mFader;
    /* 2c */ u8 mStatus;
    /* 2d */ u8 mStartFlag;
    /* 2e */ u8 mPauseFlag;
    /* 2f */ u8 mPrepareFlag;
    /* 30 */ u32 mCommandTag;
    /* 34 */ u16 mSeqType;
    /* 36 */ u8 mUnk_36[2];
    /* 38 */ u16 mSeqNo;
    /* 3a */ u16 mSeqArcIndex;
    /* 3c */ u8 mPlayerNo;
    /* 3d */ u8 mPrio;
    /* 3e */ s16 mVolume;
    /* 40 */ u8 mInitVolume;
    /* 41 */ u8 mExtVolume;
    /* 42 */ u8 mUnk_42[2];
} NNSSndSeqPlayer;

#include "code_0212d214.h"

// Memory NNS_SndPlayerCreateHeap gets from NNS_SndHeapAlloc: mHandle is the NNSSndHeap it sets up on mUnk_14, mPlayerNo
// the index of the data_0217d89c element whose heap list receives it.
typedef struct NNSSndPlayerHeap {
    /* 00 */ u8 mLink[8];
    /* 08 */ NNSSndHeap *mHandle;
    /* 0c */ NNSSndSeqPlayer *mPlayer;
    /* 10 */ u32 mPlayerNo;
    /* 14 */ u8 mUnk_14[1];
} NNSSndPlayerHeap;

#include "code_0212c7a0.h" // NNSSndPlayer

typedef struct Unk02021968 Unk02021968;

extern NNSFndList data_0217d444;
extern NNSFndList data_0217d450;

void SetPlayerPriority(NNSSndSeqPlayer *seq, int priority);
void PlayerHeapDisposeCallback(void *mem, u32 size, void *data1, u32 data2);
void ShutdownPlayer(NNSSndSeqPlayer *seq);
NNSSndSeqPlayer *AllocSeqPlayer(int priority);
void ForceStopSeq(NNSSndSeqPlayer *seq);
void InsertPrioList(NNSSndSeqPlayer *seq);
void InsertPlayerList(NNSSndPlayer *player, NNSSndSeqPlayer *seq);
void InitPlayer(NNSSndSeqPlayer *seq);
NNSSndHeap *NNSi_SndPlayerAllocHeap(int index, NNSSndSeqPlayer *seq);
void NNSi_SndPlayerStopSeq(NNSSndSeqPlayer *seq, int fadeSteps);
void NNSi_SndPlayerStartSeq(NNSSndSeqPlayer *seq, void *data, u32 offset, Unk02021968 *bank);
void NNSi_SndPlayerFreeSeqPlayer(NNSSndSeqPlayer *seq);
NNSSndSeqPlayer *NNSi_SndPlayerAllocSeqPlayer(NNSSndSeqPlayer **handle, int index, int priority);
void NNSi_SndPlayerMain(void);
void NNSi_SndPlayerInit(void);
BOOL NNS_SndPlayerWriteVariable(NNSSndSeqPlayer **handle, int variable, s16 value);
BOOL NNS_SndPlayerReadVariable(NNSSndSeqPlayer **handle, int variable, s16 *value);
void NNS_SndPlayerSetSeqArcNo(NNSSndSeqPlayer **handle, int archive, int index);
void NNS_SndPlayerSetSeqNo(NNSSndSeqPlayer **handle, int number);
void NNS_SndPlayerSetTempoRatio(NNSSndSeqPlayer **handle, int ratio);
void NNS_SndPlayerSetTrackModSpeed(NNSSndSeqPlayer **handle, u32 tracks, int speed);
u32 NNS_SndPlayerSetTrackPan(NNSSndSeqPlayer **handle, u32 tracks, int pan);
void NNS_SndPlayerSetTrackPitch(NNSSndSeqPlayer **handle, u32 tracks, int pitch);
void NNS_SndPlayerSetTrackVolume(NNSSndSeqPlayer **handle, u32 tracks, int volume);
void NNS_SndPlayerSetTrackMuteEx(NNSSndSeqPlayer **handle, u32 tracks, int mute);
void NNS_SndPlayerSetChannelPriority(NNSSndSeqPlayer **handle, int priority);
void NNS_SndPlayerSetPlayerPriority(NNSSndSeqPlayer **handle, int priority);
void NNS_SndPlayerMoveVolume(NNSSndSeqPlayer **handle, int target, int steps);
void NNS_SndPlayerSetInitialVolume(NNSSndSeqPlayer **handle, int volume);
NNSSndSeqPlayer *NNS_SndPlayerSetVolume(NNSSndSeqPlayer **handle, int volume);
void NNS_SndHandleReleaseSeq(NNSSndSeqPlayer **handle);
void NNS_SndHandleInit(NNSSndSeqPlayer **handle);
void NNS_SndPlayerStopSeqAll(u32 fadeSteps);
u32 NNS_SndPlayerStopSeq(NNSSndSeqPlayer **handle, u32 fadeSteps);
BOOL NNS_SndPlayerCreateHeap(int index, NNSSndHeap *heap, u32 size);

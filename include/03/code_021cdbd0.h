#pragma once

#include "types.h"
#include "code_0212bcac.h"

typedef struct NNSSndArc NNSSndArc;

typedef struct SoundData {
    /* 00 */ NNSSndArc mArc;
    /* 90 */ NNSSndSeqPlayer *mSeqPlayer;
    /* 94 */ void *mFileData;
    /* 98 */ u32 mTask;
} SoundData;

extern u8 gSoundDataSdatName[];

void StopSoundSeq(void);
void SetSoundSeqTrackPitch(u32 tracks, u32 pitch);
u32 SetSoundSeqVolume(u32 volume);
void StartSoundSeq(u32 index);
void func_ov003_021cdc28(void);
void CreateSoundData(void);

#pragma once

#include "types.h"
#include "Main/Unknown/code_0210e33c.h"

typedef struct NNSSndSeqPlayer NNSSndSeqPlayer;

// 0x08-byte entries behind data_0216c860.
typedef struct Unk0216c860 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk0216c860;

extern Unk0216c860 data_0216c860[];

// Object behind data_0216c7e0.
typedef struct Unk0216c7e0 {
    /* 00 */ u32 mUnk_00[4];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} Unk0216c7e0;

extern Unk0216c7e0 data_0216c7e0;

// Object behind data_0216c7d8.
typedef struct Unk0216c7d8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ u32 mUnk_04;
} Unk0216c7d8;

extern Unk0216c7d8 data_0216c7d8;

// 0x03-byte argument of InitSceneSoundState and InitSceneSounds.
typedef struct Unk021073ec {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
} Unk021073ec;

// Object behind data_0217c7f0.
typedef struct Unk0217c7f0 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
} Unk0217c7f0;

extern Unk0217c7f0 data_0217c7f0;

// View of data_0217c7c4; func_0210e280 takes it.
typedef struct Unk0217c7c4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ u8 *mUnk_0c;
    /* 10 */ s32 mUnk_10;
} Unk0217c7c4;

extern Unk0217c7c4 data_0217c7c4;

// The first eight bytes of each element of the table an Unk0217c7c4 describes: a handle at 0 and a word at 4.
typedef struct Unk0210e2c4 {
    /* 00 */ NNSSndSeqPlayer *mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk0210e2c4;

// Object behind gSceneSoundState.
typedef struct SceneSoundState {
    /* 00 */ u32 mRaceFrames;
    /* 04 */ u32 mSceneFrames;
    /* 08 */ NNSSndSeqPlayer *mUnk_08;
    /* 0c */ u32 mRaceState;
    /* 10 */ u32 mOnLastLap;
    /* 14 */ u8 mLapCount;
    /* 15 */ u8 mLapsDone;
    /* 16 */ u8 mUnk_16;
    /* 17 */ u8 mUnk_17;
    /* 18 */ u8 mRankIndex;
    /* 19 */ u8 mRankIndexAtSeq;
    /* 1a */ u8 mUnk_1a[2];
    /* 1c */ s32 mRankSeqFrames;
    /* 20 */ u32 mUnk_20;
} SceneSoundState;

extern SceneSoundState gSceneSoundState;

extern NNSSndSeqPlayer *data_0217c854;

// Object data_0217d060 points to.
typedef struct Unk0217d060 {
    /* 00 */ SoundSet mUnk_00;
    /* 0c */ NNSSndSeqPlayer *mUnk_0c;
    /* 10 */ LoadedSoundSet *mUnk_10;
} Unk0217d060;

extern Unk0217d060 *data_0217d060;

// Object behind gVolumeFade.
typedef struct VolumeFade {
    /* 00 */ u32 mVolumePerFrame;
    /* 04 */ s32 mVolume;
} VolumeFade;

extern VolumeFade gVolumeFade;

// Values of the two switches in InitSound.
typedef enum { E0 = 0, E1 = 1, E2 = 2 } Unk02108344;

BOOL LoadSndBanksAndWaveArcs(s32 bankMask);
BOOL LoadSndBanksAndWaveArcsIfChanged(s32 bankMask);
int GetSndHeapsBufferSize(int a);
int GetSndInitBufferSize(int a);
void ReleaseSndHeaps(void);
void CreateSndHeaps(u32 a, u32 buffer);
void InitSound(void *buffer, u32 b, u32 c);
void UpdateSounds(void);
void InitSceneSounds(s32 e);
void InitSceneSoundState(u32 a, Unk021073ec b, SceneSoundState *c);
void StartSceneSounds(void);
void StartRaceSounds(void);
void StartKartStarSeq(void);
void func_02106dc8(void);
void EndRaceSounds(void);
void AdvanceSceneSoundLap(void);
void SetSceneSoundRank(u32 a);
void UpdateRaceSounds(void);
void func_021062a8(void);
void UpdateSceneSoundState(void);
void StopSceneSounds(void);
void StopSceneSoundsAtOnce(void);

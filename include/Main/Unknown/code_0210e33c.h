#pragma once

#include "types.h"

// Three words, at 0, 4 and 8: LoadSoundSet, IsSoundSetLoaded and ReleaseSoundSet take one by value.
typedef struct SoundSet {
    /* 00 */ u32 mSeqId;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} SoundSet;

// Object data_0217c7b4, which func_02108950 returns: an SoundSet at 0 and a word at 0xc that
// SaveSndHeapState and ReleaseSoundSet write.
typedef struct LoadedSoundSet {
    /* 00 */ SoundSet mSoundSet;
    /* 0c */ u32 mHeapState;
} LoadedSoundSet;

// Four bytes at 0 to 3: GetCourseSoundRowIndex writes one, and LoadCourseSoundSet and LoadSceneSoundSet read the bytes
// at 1, 2 and 3.
typedef struct Unk0210e524 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk0210e524;

// Object data_0217d178: 16 words from 0x00 and a signed number at 0x40; LoadSndDataFromFile and func_0210ed20 add a
// word to it, ClearSndFileAddresses walks it and ClearSndFileIdList resets it.
typedef struct SndFileIdList {
    /* 00 */ u32 mFileIds[16];
    /* 40 */ s32 mCount;
} SndFileIdList;

// data_0217d134 has the same layout and goes through the same functions.
typedef SndFileIdList Unk0217d134;

extern Unk0217d134 data_0217d134;
extern SndFileIdList data_0217d178;

extern const SoundSet data_0215c380;
extern const SoundSet data_0215c38c;
extern const SoundSet data_0215c398;
extern LoadedSoundSet data_0217c7b4;

void ReleaseLoadedSoundSet(void);
u32 func_0210ed20(u32 a, u32 b);
u32 LoadSoundSetIfChanged(SoundSet v, u32 d);
void func_0210e920(void);
void func_0210e8f8(u32 a);
void LoadSceneSoundSet(Unk0210e524 a, u32 b);
u32 LoadSndDataFromFile(void);
u32 LoadCourseSoundSet(u32 a, u32 b);
u32 func_0210e524(void);
u32 LoadSndGroup(s32 a);
void ResetLoadedSoundSet(LoadedSoundSet *p);
void SaveSndHeapState(LoadedSoundSet *p);
void ReleaseSoundSet(LoadedSoundSet *p);
u32 IsSoundSetLoaded(LoadedSoundSet *p, SoundSet v);
u32 LoadSoundSet(LoadedSoundSet *p, SoundSet v);

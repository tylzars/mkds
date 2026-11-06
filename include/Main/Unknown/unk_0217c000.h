#pragma once

#include "types.h"
#include "code_0212bcac.h"
#include "code_0212d214.h"

typedef struct NNSSndSeqPlayer NNSSndSeqPlayer;
typedef struct NNSSndHeap NNSSndHeap;

// Volume curve of one kind of sound source. The volume is the maximum up to the inner distance, falls to a mid volume
// at the mid distance and to 0 at the outer distance. SoundSource.mFalloffIndex picks the element of gSoundFalloffs.
// 0x24-byte entries of the array at gSoundFalloffs; func_02109468 fills the first one.
typedef struct SoundFalloff {
    // Distance beyond which the sound is silent.
    /* 00 */ s32 mOuterDistance;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    // Distance up to which the sound has its maximum volume.
    /* 0c */ s32 mInnerDistance;
    // Highest volume of the curve.
    /* 10 */ s32 mMaxVolume;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} SoundFalloff;

// Volume curves by sound source number (SoundSource.mFalloffIndex); filled by func_02109468.
extern SoundFalloff gSoundFalloffs[];
// Volume curve of the Karts other than the selected entry whose sound source number is 0.
extern SoundFalloff gOtherKartSoundFalloff;

// Objects whose layout isn't known yet.
extern NNSSndSeqPlayer *data_0217c778;
extern u8 data_0217c784[];
extern NNSSndSeqPlayer *data_0217c788;
extern s32 data_0217c7a4;
extern NNSSndSeqPlayer *data_0217c838[];
extern u8 data_0217c83c[];
extern u8 data_0217c840[];
extern struct NNSSndArc data_0217c868;
extern u8 data_0217c91c[];
extern u32 data_0217cbec[];
extern u32 data_0217c780;
extern u32 data_0217cc6c[];
extern u8 data_0217c7fc[];
extern u8 data_0217ccac[];
extern u32 data_0217cd30[];
extern u8 data_0217c644[];
extern u8 data_0217c650[];
extern u8 data_0217c658[];
extern u8 data_0217c7c4[];
extern s32 data_0217ccb0;
extern s32 data_0217ccb4;
extern u8 data_0217ccb8[];
extern s32 data_0217ccbc;
extern u16 *data_0217c630;
extern s32 data_0217c634;
extern void *data_0217c654;
extern u16 data_0217c638;
extern u32 data_0217c64c;
extern u16 data_0217c63c;
extern u8 data_0217c6a4[];
extern u16 data_0217c640;
extern u8 data_0217c65c[];
extern u32 data_0217c6e4[];
extern u32 data_0217c704[];
extern u8 data_0217c648[];
extern u16 data_0217c76c[];
extern u16 data_0217c770[];
extern NNSSndHeap *data_0217c77c;
extern u32 data_0217c78c;
extern NNSSndHeap *data_0217c790;
extern u32 data_0217c794;
extern u32 data_0217c798[];
extern u32 data_0217c7a8;
struct NNSSndSeqPlayer;
extern struct NNSSndSeqPlayer *data_0217c7ac;
extern u32 data_0217c7b0;
extern u8 data_0217c7d8[];
extern s32 data_0217c804[];
extern u32 data_0217c80c[];
extern NNSSndSeqPlayer *data_0217c81c;
extern u32 data_0217c728;
extern u32 *data_0217c72c;
extern s32 data_0217c724;
extern u16 data_0217c774;
extern s32 data_0217c79c;
extern s32 data_0217c7a0;
extern void *gDram;

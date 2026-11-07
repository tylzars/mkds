#pragma once

#include "types.h"
#include "code_02003024.h" // FSFile
#include "code_0212f788.h" // NNSSndFader
#include "code_0214f4a4.h" // PMSleepCallbackInfo

// 0x5c bytes: a stream. mActiveFlag is set while it is set up, mStartFlag while its timers run.
typedef struct NNSSndStrm {
    /* 00 */ u8 mLink[8];
    /* 08 */ PMSleepCallbackInfo mPreSleepInfo;
    /* 14 */ PMSleepCallbackInfo mPostSleepInfo;
    /* 20 */ u32 mFormat;
    /* 24 */ s32 mActiveFlag : 1;
    /* 24 */ s32 mStartFlag : 1;
    /* 24 */ s32 mUnk_24_2 : 30;
    /* 28 */ u32 mChBufLen;
    /* 2c */ s32 mInterval;
    /* 30 */ UnkFunc *mCallback;
    /* 34 */ void *mCallbackArg;
    /* 38 */ s32 mCurBuffer;
    /* 3c */ s32 mVolume;
    /* 40 */ u32 mAlarmNo;
    /* 44 */ u32 mChBitMask;
    /* 48 */ s32 mNumChannels;
    /* 4c */ u8 mChannelNo[0x10];
} NNSSndStrm;

// 0x160 bytes; data_0217e404 holds four. Bits of mUnk_110: 0 is tested by ShutdownPlayer_, ForceStopStrm_ and
// NNSi_SndArcStrmMain, 1 by ForceStopStrm_ and NNSi_SndArcStrmMain, 2 and 3 by NNSi_SndArcStrmMain.
typedef struct Unk0212c7f0 {
    /* 00 */ NNSSndStrm mStream;
    /* 5c */ FSFile mFile;
    /* a4 */ u8 mUnk_a4[0x44];
    /* e8 */ NNSSndFader mUnk_e8;
    /* f8 */ u8 mUnk_f8[0x18];
    /* 110 */ s32 mUnk_110_0 : 1;
    /* 110 */ s32 mUnk_110_1 : 1;
    /* 110 */ s32 mUnk_110_2 : 1;
    /* 110 */ s32 mUnk_110_3 : 1;
    /* 110 */ s32 mUnk_110_4 : 28;
    /* 114 */ s32 mUnk_114;
    /* 118 */ s32 mUnk_118;
    /* 11c */ u8 mUnk_11c[4];
    /* 120 */ s32 mUnk_120;
    /* 124 */ u8 mUnk_124[0x28];
    /* 14c */ u32 *mUnk_14c;
    /* 150 */ u8 mUnk_150[4];
    /* 154 */ s32 mUnk_154;
    /* 158 */ s32 mUnk_158;
    /* 15c */ u8 mUnk_15c[4];
} Unk0212c7f0;

// 8 bytes; NNS_SndStrmSetVolume reads mVolume of the element a byte of NNSSndStrm.mChannelNo selects in data_0217dd28.
typedef struct NNSSndStrmChannel {
    /* 00 */ void *mBuffer;
    /* 04 */ s32 mVolume;
} NNSSndStrmChannel;

void ShutdownStrm(NNSSndStrm *stream);
void ForceStopStrm(NNSSndStrm *stream);
void NNS_SndStrmSetVolume(NNSSndStrm *stream, s32 volume);
void NNS_SndStrmStop(NNSSndStrm *stream);
void NNS_SndStrmStart(NNSSndStrm *stream);
void NNS_SndStrmFreeChannel(NNSSndStrm *stream);

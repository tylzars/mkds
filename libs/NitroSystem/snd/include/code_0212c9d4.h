#pragma once

#include "types.h"
#include "code_0212f788.h" // NNSSndFader

typedef void (*NNSSndCaptureCallback)(void *bufferL, void *bufferR, u32 len, u32 format, void *arg);

// 0x54 bytes, data_0217ddd0. NNSi_SndCaptureStart sets it up and passes it to AlarmCallback, which calls mCallback with
// the two buffer halves, the block size, the format and mCallbackArg.
typedef struct CaptureParam {
    /* 00 */ u32 mActiveFlag;
    /* 04 */ u32 mType;
    /* 08 */ u32 mFormat;
    /* 0c */ u8 *mBufferL;
    /* 10 */ u8 *mBufferR;
    /* 14 */ u32 mBufLen;
    /* 18 */ u32 mBlockSize;
    /* 1c */ s32 mCurBuffer;
    /* 20 */ u32 mChBitMask;
    /* 24 */ u32 mPlayChBitMask;
    /* 28 */ u32 mCapBitMask;
    /* 2c */ s32 mAlarmNo;
    /* 30 */ s32 mInterval;
    /* 34 */ NNSSndCaptureCallback mCallback;
    /* 38 */ void *mCallbackArg;
    /* 3c */ NNSSndFader mFader;
    /* 4c */ u32 mFadeOutFlag;
    /* 50 */ s32 mVolume;
} CaptureParam;

// 0x14 bytes; AlarmCallback fills the elements of data_0217de24 in turn.
typedef struct EffectInfo {
    /* 00 */ CaptureParam *mCap;
    /* 04 */ u32 mBlockSize;
    /* 08 */ u32 mOffset;
    /* 0c */ u8 *mBufferL;
    /* 10 */ u8 *mBufferR;
} EffectInfo;

s32 NNSi_SndCaptureStart(u32 type, u8 *left, u8 *right, u32 length, u32 format, u32 input, u32 output, u32 loop,
                         s32 rate, u32 volume, u32 panLeft, u32 panRight, u32 parts, NNSSndCaptureCallback callback,
                         void *callbackArg);

void AlarmCallback(void *arg);
void NNSi_SndCaptureEndSleep(void);
void NNSi_SndCaptureBeginSleep(void);
void NNSi_SndCaptureStop(void);
void NNSi_SndCaptureMain(void);
u32 NNSi_SndCaptureInit(void);
void NNS_SndCaptureStopEffect(void);
s32 NNS_SndCaptureStartEffect(void *buffer, u32 bufSize, u32 format, u32 rate, u32 interval,
                              NNSSndCaptureCallback callback, void *arg);

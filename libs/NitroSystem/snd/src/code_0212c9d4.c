#include "code_0212c9d4.h"

#include "code_0200eddc.h"
#include "snd_interface.h"
#include "snd_command.h"
#include "code_0200e77c.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0201ec30.h"
#include "Main/Unknown/code_02021000.h"
#include "resource_mgr.h"
#include "code_0212f788.h"
#include "code_0212f864.h"
#include "Main/Unknown/unk_0217d000.h"
#include "00/code_02188720.h"

// Stops any running effect capture, clears the buffer and starts a mixer capture of type 1 with callback called on
// every interval part of the buffer.
s32 NNS_SndCaptureStartEffect(void *buffer, u32 bufSize, u32 format, u32 rate, u32 interval,
                              NNSSndCaptureCallback callback, void *arg) {
    volatile u32 zero;
    u8 *a = buffer;

    NNS_SndCaptureStopEffect();
    if (data_0217ddd0.mActiveFlag != 0) {
        return 0;
    }
    zero = 0;
    MIi_CpuClear32(zero, a, bufSize);
    DC_FlushRange(a, bufSize);
    return NNSi_SndCaptureStart(1, a, a + (bufSize >> 1), bufSize >> 1, format, 0, 0, 1, rate, 0x7f, 0, 0x7f, interval,
                                callback, arg);
}

// Stops the capture when it is a running effect capture.
void NNS_SndCaptureStopEffect(void) {
    if (data_0217ddd0.mActiveFlag == 0) {
        return;
    }
    if (data_0217ddd0.mType != 1) {
        return;
    }
    NNSi_SndCaptureStop();
}

// Clears the thread flag and CaptureParam.mActiveFlag.
u32 NNSi_SndCaptureInit(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value1 = (u32) &data_0217dda8;
    value2 = 0u;
    value0 = (u32) &data_0217ddd0;
    *(u32 *) ((value1) + (0)) = value2;
    data_0217ddd0.mActiveFlag = value2;
    return value0;
}

// For a reverb capture steps the fader, stops the capture when the fade out has finished and otherwise sets the
// volume of the playback channels from the fader.
void NNSi_SndCaptureMain(void) {
    CaptureParam *capture = &data_0217ddd0;
    NNSSndFader *fader;
    s32 volume;

    if (capture->mActiveFlag == 0) {
        return;
    }
    if (capture->mType != 0) {
        return;
    }
    fader = &capture->mFader;
    NNSi_SndFaderUpdate(fader);
    if (capture->mFadeOutFlag != 0 && NNSi_SndFaderIsFinished(fader) != 0) {
        NNSi_SndCaptureStop();
        return;
    }
    volume = NNSi_SndFaderGet(fader) >> 8;
    if (volume == capture->mVolume) {
        return;
    }
    SND_SetChannelVolume(capture->mPlayChBitMask, volume, 0);
    capture->mVolume = volume;
}

// Locks two capture units, two channels and, with a callback, an alarm, sets them up on the two buffers and starts
// the timers. Returns 0 when something could not be locked.
s32 NNSi_SndCaptureStart(u32 type, u8 *left, u8 *right, u32 length, u32 format, u32 input, u32 output, u32 loop,
                         s32 rate, u32 volume, u32 panLeft, u32 panRight, u32 parts, NNSSndCaptureCallback callback,
                         void *callbackArg) {
    s32 timer;
    u32 captureFormat;
    u32 waveFormat;
    u32 playChannels;
    u32 alarmPeriod;
    s32 timerUnits;
    s32 isByteFormat;
    s32 alarm;
    u32 alarmDelay;
    u32 samples;
    CaptureParam *capture;

    timerUnits = 0;
    playChannels = 0;
    alarm = -1;
    capture = &data_0217ddd0;
    DC_FlushRange(left, length);
    DC_FlushRange(right, length);
    isByteFormat = format == 1;
    timer = 0xffb0ff / rate;
    if (callback != 0) {
        samples = length;
        if (isByteFormat == 0) {
            samples = length >> 1;
        }
        timer = (timer + 0x10) & ~0x1f;
        timerUnits = timer >> 5;
        alarmPeriod = timerUnits * (samples / parts);
        alarmDelay = 0x20;
        if (isByteFormat == 0) {
            alarmDelay = alarmDelay >> 1;
        }
        alarmDelay = alarmDelay * timerUnits;
    }
    switch (isByteFormat) {
        default:
            waveFormat = 0;
            break;
        case 0:
            waveFormat = 1;
            break;
    }
    if (isByteFormat != 0) {
        captureFormat = 1;
    } else {
        captureFormat = 0;
    }
    if (type != 2) {
        playChannels = 10;
    }
    if (callback != 0) {
        alarm = NNS_SndAllocAlarm();
        if (alarm < 0) {
            return 0;
        }
    }
    if (NNS_SndLockCapture(3) == 0) {
        if (alarm >= 0) {
            NNS_SndFreeAlarm(alarm);
        }
        return 0;
    }
    if (NNS_SndLockChannel(10) == 0) {
        if (alarm >= 0) {
            NNS_SndFreeAlarm(alarm);
        }
        NNS_SndUnlockCapture(3);
        return 0;
    }
    SND_SetupChannelPcm(1, waveFormat, left, loop != 0 ? 1 : 2, 0, length >> 2, volume, 0, timer, panLeft);
    SND_SetupCapture(0, captureFormat, left, length >> 2, loop, input, output);
    SND_SetupChannelPcm(3, waveFormat, right, loop != 0 ? 1 : 2, 0, length >> 2, volume, 0, timer, panRight);
    SND_SetupCapture(1, captureFormat, right, length >> 2, loop, input, output);
    if (alarm >= 0) {
        SND_SetupAlarm(alarm, alarmPeriod + alarmDelay, alarmPeriod, AlarmCallback, capture);
    }
    if (type == 1) {
        SND_SetOutputSelector(1, 2, 1, 1);
    }
    SND_StartTimer(playChannels, 3, alarm >= 0 ? 1 << alarm : 0, 0);
    capture->mActiveFlag = 1;
    capture->mType = type;
    capture->mChBitMask = 10;
    capture->mPlayChBitMask = playChannels;
    capture->mCapBitMask = 3;
    capture->mAlarmNo = alarm;
    capture->mFormat = format;
    capture->mBufferL = left;
    capture->mBufferR = right;
    capture->mBufLen = length;
    capture->mBlockSize = length / parts;
    capture->mCurBuffer = 0;
    capture->mInterval = parts;
    capture->mCallback = callback;
    capture->mCallbackArg = callbackArg;
    capture->mVolume = volume;
    InterpolatorInit(&capture->mFader);
    NNSi_SndFaderSet(&capture->mFader, volume << 8, 1);
    capture->mFadeOutFlag = 0;
    return 1;
}

// Stops the timers, waits for the commands, drops the alarm messages, unlocks what the capture locked and restores
// the output selector of an effect capture.
void NNSi_SndCaptureStop(void) {
    CaptureParam *capture = &data_0217ddd0;
    s32 hasAlarm;
    u32 tag;

    if (capture->mActiveFlag == 0) {
        return;
    }
    hasAlarm = capture->mAlarmNo >= 0;
    SND_StopTimer(capture->mPlayChBitMask, capture->mCapBitMask, hasAlarm != 0 ? 1 << capture->mAlarmNo : 0, 0);
    if (hasAlarm != 0) {
        tag = SND_GetCurrentCommandTag();
        SND_FlushCommand(1);
        SND_WaitForCommandProc(tag);
        while (OS_ReceiveMessage(&data_0217ddb0, 0, 0) != 0) {
        }
    }
    if (capture->mCapBitMask != 0) {
        NNS_SndUnlockCapture(capture->mCapBitMask);
    }
    if (capture->mChBitMask != 0) {
        NNS_SndUnlockChannel(capture->mChBitMask);
    }
    if (hasAlarm != 0) {
        NNS_SndFreeAlarm(capture->mAlarmNo);
    }
    if (capture->mType == 1) {
        SND_SetOutputSelector(0, 0, 0, 0);
    }
    capture->mActiveFlag = 0;
}

// Stops the capture timers and waits for the commands, for the sleep mode.
void NNSi_SndCaptureBeginSleep(void) {
    CaptureParam *capture = &data_0217ddd0;
    u32 tag;

    if (capture->mActiveFlag == 0) {
        return;
    }
    SND_StopTimer(capture->mPlayChBitMask, capture->mCapBitMask, capture->mAlarmNo >= 0 ? 1 << capture->mAlarmNo : 0, 0);
    tag = SND_GetCurrentCommandTag();
    SND_FlushCommand(1);
    SND_WaitForCommandProc(tag);
}

// Clears and flushes both buffers and restarts the capture timers after sleep mode.
void NNSi_SndCaptureEndSleep(void) {
    CaptureParam *capture = &data_0217ddd0;
    volatile u32 zeroL;
    volatile u32 zeroR;

    if (capture->mActiveFlag == 0) {
        return;
    }
    capture->mCurBuffer = 0;
    zeroL = 0;
    MIi_CpuClear32(zeroL, capture->mBufferL, capture->mBufLen);
    zeroR = 0;
    MIi_CpuClear32(zeroR, capture->mBufferR, capture->mBufLen);
    DC_FlushRange(capture->mBufferL, capture->mBufLen);
    DC_FlushRange(capture->mBufferR, capture->mBufLen);
    SND_StartTimer(capture->mPlayChBitMask, capture->mCapBitMask, capture->mAlarmNo >= 0 ? 1 << capture->mAlarmNo : 0, 0);
}

// Alarm handler: hands the current block of both buffers to the callback, directly or through the message queue
// when the thread exists, then moves to the next block.
void AlarmCallback(void *arg) {
    CaptureParam *capture = arg;
    u8 *left;
    u8 *right;
    u32 blockSize;
    u32 offset;
    EffectInfo *info;

    blockSize = capture->mBlockSize;
    offset = blockSize * capture->mCurBuffer;
    left = capture->mBufferL + offset;
    right = capture->mBufferR + offset;
    if (data_0217dda8 != 0) {
        info = &data_0217de24[data_0217ddac];
        info->mCap = capture;
        info->mBlockSize = blockSize;
        info->mOffset = offset;
        info->mBufferL = left;
        info->mBufferR = right;
        OS_SendMessage(&data_0217ddb0, info, 0);
        data_0217ddac++;
        if (data_0217ddac >= 8) {
            data_0217ddac = 0;
        }
    } else {
        DC_InvalidateRange(left, blockSize);
        DC_InvalidateRange(right, blockSize);
        capture->mCallback(left, right, blockSize, capture->mFormat, capture->mCallbackArg);
    }
    capture->mCurBuffer++;
    if (capture->mCurBuffer >= capture->mInterval) {
        capture->mCurBuffer = 0;
    }
}

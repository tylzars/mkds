#include "code_0212c7f0.h"
#include "code_020207ec.h"
#include "code_02020eb0.h"
#include "code_0214f4a4.h"
#include "Main/Unknown/code_02017000.h"
#include "code_020172d0.h"
#include "code_0201ec30.h"
#include "Main/Unknown/code_02021000.h"
#include "code_0212bb50.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_020218f4.h"

// Unlocks the channels of the stream.
void NNS_SndStrmFreeChannel(NNSSndStrm *stream) {
    if (stream->mChBitMask == 0) {
        return;
    }
    NNS_SndUnlockChannel(stream->mChBitMask);
    stream->mChBitMask = 0;
    stream->mNumChannels = 0;
}

// Starts the timers of the stream and, on the first start, adds its sleep callbacks.
void NNS_SndStrmStart(NNSSndStrm *stream) {
    SND_StartTimer(stream->mChBitMask, 0, 1 << stream->mAlarmNo, 0);
    if (stream->mStartFlag) {
        return;
    }
    PM_PrependPreSleepCallback(&stream->mPreSleepInfo);
    PM_AppendPostSleepCallback(&stream->mPostSleepInfo);
    stream->mStartFlag = 1;
}

// Stops the stream when it is set up.
void NNS_SndStrmStop(NNSSndStrm *stream) {
    if (stream->mActiveFlag) {
        ForceStopStrm(stream);
    }
}

// Sets NNSSndStrm.mVolume and the volume of every channel of the stream, added to the volume of the channel.
void NNS_SndStrmSetVolume(NNSSndStrm *stream, s32 volume) {
    u32 channel;
    s32 i;
    s32 level;

    stream->mVolume = volume;
    for (i = 0; i < stream->mNumChannels; i++) {
        channel = stream->mChannelNo[i];
        level = SND_CalcChannelVolume(stream->mVolume + data_0217dd28[channel].mVolume);
        SND_SetChannelVolume(1 << channel, level & 0xff, level >> 8);
    }
}

// Stops the timers and the sleep callbacks of a started stream, waits for the sound commands, and shuts it down.
void ForceStopStrm(NNSSndStrm *stream) {
    u32 tag;

    if (stream->mStartFlag) {
        SND_StopTimer(stream->mChBitMask, 0, 1 << stream->mAlarmNo, 0);
        PM_DeletePreSleepCallback(&stream->mPreSleepInfo);
        PM_DeletePostSleepCallback(&stream->mPostSleepInfo);
        stream->mStartFlag = 0;
        tag = SND_GetCurrentCommandTag();
        SND_FlushCommand(1);
        SND_WaitForCommandProc(tag);
    }
    ShutdownStrm(stream);
}

// Frees the alarm of the stream, removes it from the stream list and marks it not set up.
void ShutdownStrm(NNSSndStrm *stream) {
    NNS_SndFreeAlarm(stream->mAlarmNo);
    NNS_FndRemoveListObject(&data_0217dd1c, stream);
    stream->mActiveFlag = 0;
}

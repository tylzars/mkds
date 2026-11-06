#pragma once

#include "types.h"
#include "code_02020eb0.h"

void SND_StopSeq(int playerNo);
void SND_PrepareSeq(int playerNo, const void *base, u32 offset, const void *bank);
void SND_StartPreparedSeq(int playerNo);
void SND_SetPlayerTempoRatio(int playerNo, int ratio);
void SND_SetPlayerVolume(int playerNo, int volume);
void SND_SetPlayerChannelPriority(int playerNo, int prio);
void SND_SetPlayerLocalVariable(int playerNo, int varNo, int var);
void SND_SetTrackVolume(int playerNo, u32 trackBitMask, int volume);
void SND_SetTrackPitch(int playerNo, u32 trackBitMask, int pitch);
void SND_SetTrackPan(int playerNo, u32 trackBitMask, int pan);
void SND_SetTrackModSpeed(int playerNo, u32 trackBitMask, int speed);
void SND_SetTrackAllocatableChannel(int playerNo, u32 trackBitMask, u32 chBitMask);
void SND_StartTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void SND_StopTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
void SND_SetupCapture(int capture, int format, void *buffer, u32 length, u32 loopFlag, u32 in, u32 out);
void SND_SetupAlarm(int alarmNo, u32 tick, u32 period, SNDAlarmHandler handler, void *arg);
void SND_SetTrackMuteEx(int playerNo, u32 trackBitMask, int mute);
void SND_LockChannel(u32 chBitMask, u32 flags);
void SND_UnlockChannel(u32 chBitMask, u32 flags);
void SND_SetChannelVolume(u32 chBitMask, int volume, int shift);
void SND_SetupChannelPcm(int chNo, int format, const void *dataaddr, int loop, int loopStart, int loopLen, u32 volume,
                         int shift, int timer, int pan);
void SND_InvalidateSeqData(const void *start, const void *end);
void SND_InvalidateBankData(const void *start, const void *end);
void SND_InvalidateWaveData(const void *start, const void *end);
void SND_SetMasterVolume(int volume);
void SND_SetOutputSelector(int left, int right, int channel1, int channel3);
void SND_SetMasterPan(int pan);
void SND_ResetMasterPan(void);
void SNDi_SetPlayerParam(int playerNo, u32 offset, u32 data, int size);
void SNDi_SetTrackParam(int playerNo, u32 trackBitMask, u32 offset, u32 data, int size);
void SNDi_SetSurroundDecay(int decay);
void PushCommand_impl(u32 id, u32 arg0, u32 arg1, u32 arg2, u32 arg3);

#pragma once

#include "types.h"

typedef struct Unk020217b4_20 {
    /* 00 */ s16 mVariable[16];
    /* 20 */ u32 mTickCounter;
} Unk020217b4_20;

// 0x280 bytes; the shared work area that the sound processor fills in.
typedef struct Unk020217b4 {
    /* 000 */ u32 mFinishCommandTag;
    /* 004 */ u32 mPlayerStatus;
    /* 008 */ u16 mChannelStatus;
    /* 00a */ u16 mCaptureStatus;
    /* 00c */ u8 mPadding[0x14];
    /* 020 */ Unk020217b4_20 mPlayer[16];
    /* 260 */ s16 mGlobalVariable[16];
} Unk020217b4;

extern Unk020217b4 *data_02174e00;

u32 SNDi_IncAlarmId(u32 alarmNo);
void SND_AlarmInit(void);
void SNDi_InitSharedWork(Unk020217b4 *work);
u32 SNDi_GetFinishedCommandTag(void);
s16 SND_GetPlayerLocalVariable(s32 playerNo, s32 varNo);
u32 SND_GetPlayerStatus(void);

#pragma once

#include "types.h"

typedef struct Unk020217b4 Unk020217b4;

// 0x18 bytes, linked through mNext. data_021735a0 holds 256 of them; SND_CommandInit chains them and SND_AllocCommand
// takes one.
typedef struct SNDCommand {
    /* 00 */ struct SNDCommand *mNext;
    /* 04 */ u32 mId;
    /* 08 */ u32 mArg[4];
} SNDCommand;

typedef void (*SNDAlarmHandler)(void *);

// 12 bytes; SNDi_SetAlarmHandler sets mFunc and mArg and adds 1 to mId, SNDi_CallAlarmHandler calls mFunc with mArg.
typedef struct Unk02021734 {
    /* 00 */ SNDAlarmHandler mFunc;
    /* 04 */ void *mArg;
    /* 08 */ u8 mId;
} Unk02021734;

extern SNDCommand *data_021732c8;
extern u32 data_021732cc;
extern SNDCommand *data_021732d0;
extern SNDCommand *data_021732d4;
extern SNDCommand *data_021732d8;
extern s32 data_021732dc;
extern s32 data_021732e0;
extern s32 data_021732e4;
extern u32 data_021732e8;
extern SNDCommand *data_021732ec[13];
extern Unk020217b4 data_02173320;
extern SNDCommand data_021735a0[256];
extern Unk02021734 data_02174da0[8];

u32 IsCommandAvailable(void);
SNDCommand *AllocCommand(void);
void RequestCommandProc(void);
void InitPXI(void);
void PxiFifoCallback(u32 tag, u32 data);
s32 SND_CountWaitingCommand(void);
s32 SND_CountReservedCommand(void);
s32 SND_CountFreeCommand(void);
u32 SND_IsFinishedCommandTag(u32 tag);
u32 SND_GetCurrentCommandTag(void);
void SND_WaitForCommandProc(u32 tag);
u32 SND_FlushCommand(u32 flags);
void SND_PushCommand(SNDCommand *command);
SNDCommand *SND_AllocCommand(u32 flags);
const SNDCommand *SND_RecvCommandReply(u32 flags);
void SND_CommandInit(void);
void SNDi_CallAlarmHandler(int alarmNo);
u8 SNDi_SetAlarmHandler(int alarmNo, SNDAlarmHandler handler, void *arg);

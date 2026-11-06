#pragma once

#include "types.h"
#include "code_02013bdc.h"
#include "code_0200db4c.h"
#include "code_0200f790.h"

typedef struct Unk0217029c Unk0217029c;

extern OSThread data_0217002c;
extern u32 data_021701b4;
// Gate of arena index 2. Zero in this game: the only store writes 0.
extern u32 gArena2Enabled;
extern UnkFunc *OSi_UserExceptionHandler;
extern u32 OSi_UserExceptionHandlerArg;
extern u8 OSi_ExContext[];
extern UnkFunc *OSi_DebuggerHandler;
extern u16 data_02170248;
// Halfword set to 1 by OS_InitTick.
extern u16 gTickInitialized;
extern u32 data_02170250;
// 64-bit count of timer 0 wraps, added by OSi_CountUpTick, read by OS_GetTick.
extern volatile u64 gTickOverflowCount;
// Halfword set to 1 by OS_InitAlarm.
extern u16 gAlarmInitialized;
// Head and tail of the armed alarms, ordered by fire time; cleared by OS_InitAlarm.
extern OSiAlarmQueue gAlarmList;
extern u16 data_02170268;
extern u32 data_0217026c;
extern u32 data_02170270;
extern u32 data_02170274[2];
extern u8 data_02170344[];

extern Unk0217029c data_0217029c;
extern Unk02170500 *data_02170500;
// The three vectors passed to ComputeLookAtMatrix, written together before each call.
extern Vec3 data_021704dc[3];
extern Unk0201290c_1c data_usa_021704e4[];

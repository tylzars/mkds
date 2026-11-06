#pragma once

#include "types.h"

typedef void (*OSAlarmHandler)(void *);

// 0x2c bytes. Entry of a doubly linked list ordered by mFire; gAlarmList holds the first and last entry. An alarm with
// mHandler 0 is not armed.
typedef struct OSAlarm {
    /* 00 */ OSAlarmHandler mHandler; // called with mArg
    /* 04 */ void *mArg;
    /* 08 */ u32 mTag;
    /* 0c */ u64 mFire;
    /* 14 */ struct OSAlarm *mPrev;
    /* 18 */ struct OSAlarm *mNext;
    /* 1c */ u64 mPeriod;
    /* 24 */ u64 mStart;
} OSAlarm;

typedef struct OSiAlarmQueue {
    /* 00 */ OSAlarm *mHead;
    /* 04 */ OSAlarm *mTail;
} OSiAlarmQueue;

// Timer 1 handler registered by OSi_SetTimer; calls OSi_ArrangeTimer.
void OSi_AlarmHandler(void);
// Timer 1 interrupt body: stops timer 1 and clears its interrupt enable. Restarts the timer when the first alarm is not
// due yet. Otherwise unlinks that alarm, calls its handler with OSAlarm.mArg and re-inserts it when OSAlarm.mPeriod is
// set; then starts the timer for the next first alarm.
void OSi_ArrangeTimer(void);
// Does nothing when OSAlarm.mHandler is 0. Otherwise unlinks the alarm from gAlarmList (starting the timer for a new
// first alarm), then clears OSAlarm.mHandler and OSAlarm.mPeriod.
void OS_CancelAlarm(OSAlarm *alarm);
// Halts when the alarm is null or already armed. Otherwise sets a one-shot alarm that fires tick ticks from now and
// calls handler with arg.
void OS_SetAlarm(OSAlarm *alarm, u64 tick, OSAlarmHandler handler, void *arg);
// Inserts the alarm into gAlarmList in order of OSAlarm.mFire, after alarms with an equal time. A periodic alarm
// ignores fire and takes OSAlarm.mStart moved forward by whole periods to the first time after now. Starts the timer
// when the alarm became the first one.
void OSi_InsertAlarm(OSAlarm *alarm, u64 fire);
// Clears OSAlarm.mHandler and OSAlarm.mTag.
void OS_CreateAlarm(OSAlarm *alarm);
// Returns gAlarmInitialized.
u32 OS_IsAlarmAvailable(void);
// Runs once: reserves timer 1 (func_0200f580), empties gAlarmList and clears the timer 1 interrupt enable.
void OS_InitAlarm(void);
// Starts timer 1 for the alarm: stops it, registers OSi_AlarmHandler, sets the count from the time left until
// OSAlarm.mFire (the next tick when it has passed, 0 when it is 0x10000 ticks or more away), starts it and enables its
// interrupt.
void OSi_SetTimer(OSAlarm *alarm);
// Runs once: clears the vertical count alarm list (data_02170274), data_02170270 and data_0217026c and the V-count
// interrupt enable.
void OS_InitVAlarm(void);

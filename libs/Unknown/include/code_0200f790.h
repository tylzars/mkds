#pragma once

#include "types.h"

// 0x2c bytes. Entry of a doubly linked list ordered by mUnk_0c; gAlarmList holds the first and last entry.
// OS_SetAlarm stores its third and fourth arguments at mUnk_00 and mUnk_04; OS_CancelAlarm and AdvanceAlarmList clear
// mUnk_00 when they unlink the entry.
typedef struct Unk0200fb08 {
    /* 00 */ void (*mUnk_00)(void *); // called with mUnk_04
    /* 04 */ void *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u64 mUnk_0c;
    /* 14 */ struct Unk0200fb08 *mUnk_14; // previous entry
    /* 18 */ struct Unk0200fb08 *mUnk_18; // next entry
    /* 1c */ u64 mUnk_1c;
    /* 24 */ u64 mUnk_24;
} Unk0200fb08;

typedef struct Unk02170260 {
    /* 00 */ Unk0200fb08 *mUnk_00;
    /* 04 */ Unk0200fb08 *mUnk_04;
} Unk02170260;

typedef struct Unk0200fb08 Unk0200fb08;

// Registered by StartAlarmTimer as the timer 1 handler; calls AdvanceAlarmList.
void AlarmTimerCallback(void);
// Timer 1 interrupt body: stops timer 1, clears IE bit 4. When the head alarm is not yet due, restarts the timer and
// returns. Otherwise removes it, calls its handler with its argument (the handler word is cleared first unless the
// alarm is periodic), adds a periodic alarm again, and starts the timer for the next head.
void AdvanceAlarmList(void);
// Does nothing when the handler is 0. Otherwise unlinks the alarm from gAlarmList (StartAlarmTimer when a new head
// exists), then clears its handler and period.
void OS_CancelAlarm(Unk0200fb08 *a);
// Halts when the alarm is null or armed (handler nonzero). Otherwise a one-shot: clears the period, stores handler
// and argument and with interrupts off adds the alarm with fire time OS_GetTick() + n (AddAlarmToList).
void OS_SetAlarm(Unk0200fb08 *a, u64 n, void (*f)(void *), void *p);
// Adds the alarm to gAlarmList in order of fire time (after alarms with an equal time). A periodic alarm (period
// nonzero) takes as fire time its start moved forward by whole periods to the first time after now and ignores the
// argument. Calls StartAlarmTimer when the alarm became the head.
void AddAlarmToList(Unk0200fb08 *a, u64 n);
// Clears the words at +0 (handler) and +8 of the alarm object; an alarm with handler 0 is not armed.
void OS_CreateAlarm(Unk0200fb08 *a);
// Returns gAlarmInitialized.
u32 OS_IsAlarmAvailable(void);
// Runs once: marks timer slot 1 (func_0200f580), clears head and tail of gAlarmList, clears IE bit 4.
void OS_InitAlarm(void);
// Starts timer 1 for the head alarm: stops it, registers AlarmTimerCallback for slot 1, writes the count 0xfffe when
// the fire time has passed, the complement of the distance when it is under 0x10000 ticks away and 0 otherwise,
// starts it with control 0xc1 and sets IE bit 4.
void StartAlarmTimer(Unk0200fb08 *n);
// Runs once: clears the two-word list at 0x02170254, the words at 0x02170250 and 0x0217024c and IE bit 2 (the V-count
// interrupt). Nothing else in the ROM touches those words.
void OS_InitVAlarm(void);

#pragma once

#include "types.h"

// Pair of callbacks at an element of the table behind the first word of StateMachine.
typedef struct StateCallbacks {
    /* 00 */ void (*mEnter)(void *);
    /* 04 */ void (*mUpdate)(void *);
} StateCallbacks;

// Object AdvanceStateMachine and SetStateMachineState take (the code reaches it through a void pointer).
typedef struct StateMachine {
    /* 00 */ StateCallbacks *mStateTable;
    /* 04 */ s32 mStateFrames;
    /* 08 */ void *mObject;
    /* 0c */ u8 mUnk_0c[0x2];
    /* 0e */ u16 mState;
    /* 10 */ u16 mNextState;
    /* 12 */ u16 mNextStateRequested;
} StateMachine;

s32 FindCupIndexOfCourse(s32 courseId);
u32 GetCupCourseIdAtIndex(s32 courseIndex);
s32 FindCupCourseIndex();
void SetNextRaceEntry(int entryIndex, u32 characterIndex, u32 kartIndex, int playerKind, u32 teamIndex, int f);
void RefreshRaceSetupKartCounts(s32 entryCount);
void func_02046a3c(void *heap);
s32 func_02046a88(void *a);
unsigned int func_02046ad0(unsigned int value);
unsigned int func_02046ad4(unsigned int value);
void func_02046ad8(void);
void func_02046ae4(void);
void AdvanceStateMachine(void *rawStateMachine);
void SetStateMachineState(void *rawStateMachine, u16 state);

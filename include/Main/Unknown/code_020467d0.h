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

s32 FindCupIndexOfCourse(s32 a);
u32 GetCupCourseIdAtIndex(s32 a);
s32 FindCupCourseIndex();
void SetNextRaceEntry(int a, u32 b, u32 c, int d, u32 e, int f);
void RefreshRaceSetupKartCounts(s32 a);
void func_02046a3c(void *a);
s32 func_02046a88(void *a);
unsigned int func_02046ad0(unsigned int p0);
unsigned int func_02046ad4(unsigned int p0);
void func_02046ad8(void);
void func_02046ae4(void);
void AdvanceStateMachine(void *b);
void SetStateMachineState(void *b, u16 c);

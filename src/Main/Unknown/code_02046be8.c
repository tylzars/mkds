#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020e005c.h"

void InitStateMachine(void *rawStateMachine, UnkFunc *const *stateTable, s32 stateCount, void *object) {
    Unk020e005c_080 *stateMachine = rawStateMachine;
    stateMachine->mObject = object;
    stateMachine->mStateTable = stateTable;
    stateMachine->mStateCount = stateCount;
    stateMachine->mStateFrames = 0x0u;
    stateMachine->mNextStateRequested = 0x1u;
    stateMachine->mState = 0x0u;
    stateMachine->mNextState = 0x0u;
}

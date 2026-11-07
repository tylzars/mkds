#include "Main/Unknown/code_02001080.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02001290.h"
#include "Main/Unknown/code_02001294.h"
#include "Main/Unknown/code_020019ac.h"
#include "Main/Unknown/code_020019b0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126230.h"

// Initialized data kept in .text between two functions (as in the original).
#pragma define_section MAIN_TEXT ".text"                                                                               \
                                 ".bss" abs32 RWX
#pragma section MAIN_TEXT begin

UnkFunc *gLogoStateTable[24] = {
    func_02001a44,
    func_020019b0,
    func_020019ac,
    UpdateLogoState1,
    EnterLogoState2,
    UpdateLogoState2,
    EnterLogoState3,
    UpdateLogoState3,
    EnterLogoState4,
    UpdateLogoState4,
    EnterLogoState5,
    UpdateLogoState5,
    EnterLogoState6,
    UpdateLogoState6,
    EnterLogoState7,
    func_02001294,
    func_02001290,
    UpdateLogoState8,
    EnterLogoState9,
    UpdateLogoState9,
    EnterLogoState10,
    UpdateLogoState10,
    NULL,
    NULL,
};

#pragma section MAIN_TEXT end

void UpdateLogoState8(void) {
    Unk021a99c0_18 *stateMachine;
    if (data_usa_02174e54 == 3) {
        stateMachine = &gLogoScene->mStateMachine;
        stateMachine->mNextState = 9;
        stateMachine->mNextStateRequested = 1;
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = 11;
    stateMachine->mNextStateRequested = 1;
}

void EnterLogoState9(void) {
    void *message;
    message = GetBmgEntry(gLogoScene->mCommonMessages, 137);
    SetupTxtSystemSubTextButton(message, GetBmgEntry(gLogoScene->mCommonMessages, 6));
}

void UpdateLogoState9(void) {
    Unk021a99c0_18 *stateMachine;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = 10;
    stateMachine->mNextStateRequested = 1;
}

void EnterLogoState10(void) {
    void *message;
    message = GetBmgEntry(gLogoScene->mCommonMessages, 138);
    SetupTxtSystemSubTextButton(message, GetBmgEntry(gLogoScene->mCommonMessages, 4));
}

void UpdateLogoState10(void) {
    Unk021a99c0_18 *stateMachine;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = 11;
    stateMachine->mNextStateRequested = 1;
}

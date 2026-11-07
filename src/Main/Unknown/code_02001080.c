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

UnkFunc *data_02001080[24] = {
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
    func_02001238,
    func_020011f0,
    func_0200118c,
    func_02001144,
    func_020010e0,
    NULL,
    NULL,
};

#pragma section MAIN_TEXT end

void func_02001238(void) {
    Unk021a99c0_18 *v1;
    if (data_usa_02174e54 == 3) {
        v1 = &gLogoScene->mStateMachine;
        v1->mNextState = 9;
        v1->mNextStateRequested = 1;
        return;
    }
    v1 = &gLogoScene->mStateMachine;
    v1->mNextState = 11;
    v1->mNextStateRequested = 1;
}

void func_020011f0(void) {
    void *v1;
    v1 = GetBmgEntry(gLogoScene->mCommonMessages, 137);
    SetupTxtSystemSubTextButton(v1, GetBmgEntry(gLogoScene->mCommonMessages, 6));
}

void func_0200118c(void) {
    Unk021a99c0_18 *v1;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    v1 = &gLogoScene->mStateMachine;
    v1->mNextState = 10;
    v1->mNextStateRequested = 1;
}

void func_02001144(void) {
    void *v1;
    v1 = GetBmgEntry(gLogoScene->mCommonMessages, 138);
    SetupTxtSystemSubTextButton(v1, GetBmgEntry(gLogoScene->mCommonMessages, 4));
}

void func_020010e0(void) {
    Unk021a99c0_18 *v1;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    v1 = &gLogoScene->mStateMachine;
    v1->mNextState = 11;
    v1->mNextStateRequested = 1;
}

#include "Main/Unknown/code_02058efc.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02058000.h"
#include "Main/Unknown/code_02051000.h"
#include "Main/Unknown/code_02059000.h"

#include "Main/Unknown/code_0205905c.h"
#include "Main/Unknown/code_0210e33c.h"

#pragma thumb on

void func_02059034(void) {
    int v1;
    if (data_0217aa00 == NULL) {
        v1 = 0;
    } else {
        v1 = data_0217aa00->mUnk_0000;
    }
    if (v1 == 1) {
        SetMPFrequency(0);
    }
}

void UpdateMPState21(void) {
    int result;
    Unk0217aa00_1608 *stateMachine;
    result = func_0205910c();
    if (result == 1) {
        stateMachine = &data_0217aa00->mUnk_1608;
        stateMachine->mNextState = 0x14;
        stateMachine->mNextStateRequested = 1;
    }
}

void func_02058fe0(void) {
    int v1;
    if (data_0217aa00 == NULL) {
        v1 = 0;
    } else {
        v1 = data_0217aa00->mUnk_0000;
    }
    if (v1 == 1) {
        SetMPFrequency(0);
    }
}

void UpdateMPState18(void) {
    int result;
    Unk0217aa00_1608 *stateMachine;
    result = func_0205905c();
    if (result == 1) {
        stateMachine = &data_0217aa00->mUnk_1608;
        stateMachine->mNextState = 0x13;
        stateMachine->mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

void func_02058f7c(void) {
    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    data_0217aa00->mUnk_164f = 0;
}

void func_02058f58(void) {
    if (func_0210e524() == 0) {
        data_0217aa00->mUnk_164f = 1;
    }
}

#pragma thumb off

#pragma thumb on

void UpdateMPState19(void) {
    int result;
    Unk0217aa00_1608 *stateMachine;
    result = func_02058dc0(func_02058f58);
    if (result == 1) {
        stateMachine = &data_0217aa00->mUnk_1608;
        stateMachine->mNextState = 0xf;
        stateMachine->mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

s32 func_02058f20(void) {
    return func_020591cc();
}

#pragma thumb off

#pragma thumb on

void func_02058efc(void) {
    int result;
    result = LoadSndDataFromFile();
    if (result == 0) {
        data_0217aa00->mUnk_164f = 1;
    }
}

#pragma thumb off

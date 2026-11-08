#include "03/code_021c4220.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c4188.h"
#include "03/code_021c41d4.h"
#include "03/code_021c4dd4.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021d2940.h"

void func_ov003_021c42f4(void) {
    int allKeysPressed;
    allKeysPressed = AreKeysPressed(1);
    if (allKeysPressed != 0) {
        SetButtonResultIfNone((u8) 0);
    }
}

void func_ov003_021c42f0(void) {}

void func_ov003_021c42cc(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult == 0) {
        StartSoundSeq(6);
        SetUpdateFunction(func_ov003_021c42ac);
    }
}

void func_ov003_021c42ac(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(func_ov003_021c427c);
}

void func_ov003_021c427c(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartSlideButtonsOut();
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(func_ov003_021c4240);
    }
}

void func_ov003_021c4240(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(0);
    if ((v1 == 0) && (v1 = func_ov003_021bf2f0(), v1 != 0)) {
        ReleaseBgTextCanvasOfScreen(0);
        ClearDispcntBits(0, 0x15);
        func_ov003_021c2120(0, 1);
        SetUpdateFunction(func_ov003_021c5098);
    }
}

void func_ov003_021c4220(void) {
    func_ov003_021c41d4();
    PrintMessage(0x61);
    SetUpdateFunction(func_ov003_021c41ac);
}

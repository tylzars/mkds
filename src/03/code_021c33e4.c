#include "03/code_021c33e4.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021d2940.h"
#include "code_0200fc8c.h"
#include "pm.h"

void func_ov003_021c3490(void) {
    int v1;
    v1 = func_ov003_021d2b04(1);
    if (v1 != 0) {
        SetButtonResultIfNone((u8) 0);
    }
}

void func_ov003_021c348c(void) {}

void func_ov003_021c3468(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult == 0) {
        StartSoundSeq(6);
        SetUpdateFunction(func_ov003_021c3448);
    }
}

void func_ov003_021c3448(void) {
    DisableButtonTouch();
    func_ov003_021d1dd0(8);
    SetUpdateFunction(func_ov003_021c3410);
}

void func_ov003_021c3410(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021d1ee0(3, 1, 0x3f, 0x40);
        func_ov003_021d1ee0(3, 0, 0x3f, 0x40);
        SetUpdateFunction(func_ov003_021c33e4);
    }
}

void func_ov003_021c33e4(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        OS_SpinWait((0x01000000u));
        PM_ForceToPowerOff();
    }
}

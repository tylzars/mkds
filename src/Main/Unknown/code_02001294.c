#include "Main/Unknown/code_02001294.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_02126248.h"
#include "01/code_021956dc.h"

void UpdateLogoState1(void) {
    s32 v1;
    Unk021a99c0_18 *stateMachine;
    s32 v3;
    LogoScene *scene;
    if (data_0217aa08->mUnk_28 == 0) {
        if (data_021759d4->mBackupEnabled != 0) {
            v1 = data_021759d4->mUnk_10;
        } else {
            v1 = 0;
        }
    } else {
        v1 = 1;
    }
    if (v1 != 0) {
        return;
    }
    v3 = data_0217aa08->mUnk_2c;
    if (v3 != 0) {
        if (v3 == 3) {
            gLogoScene->mUnk_2c_1 = 1;
            stateMachine = &gLogoScene->mStateMachine;
            stateMachine->mNextState = 2;
            stateMachine->mNextStateRequested = 1;
        } else if ((u32) data_021759d4->mUnk_04 == 4) {
            gLogoScene->mUnk_2c_1 = 0;
            stateMachine = &gLogoScene->mStateMachine;
            stateMachine->mNextState = 6;
            stateMachine->mNextStateRequested = 1;
        } else {
            stateMachine = &gLogoScene->mStateMachine;
            stateMachine->mNextState = 8;
            stateMachine->mNextStateRequested = 1;
        }
    } else {
        scene = gLogoScene;
        if (scene->mUnk_2c_0 != 0) {
            stateMachine = &scene->mStateMachine;
            stateMachine->mNextState = 5;
            stateMachine->mNextStateRequested = 1;
        } else {
            stateMachine = &scene->mStateMachine;
            stateMachine->mNextState = 8;
            stateMachine->mNextStateRequested = 1;
        }
    }
}

void EnterLogoState2(void) {
    void *message;
    message = GetBmgEntry(gLogoScene->mCommonMessages, 125);
    SetupTxtSystemSubTextButton(message, GetBmgEntry(gLogoScene->mCommonMessages, 4));
}

void UpdateLogoState2(void) {
    Unk021a99c0_18 *stateMachine;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = 3;
    stateMachine->mNextStateRequested = 1;
}

void EnterLogoState3(void) {
    void *message;
    func_02056e48();
    message = GetBmgEntry(gLogoScene->mCommonMessages, 126);
    SetupTxtSystemSubTextEx(message, 1, 1, 1, 0, 1);
    gLogoScene->mSubTextFrames = 0;
}

void UpdateLogoState3(void) {
    s32 v1;
    Unk021a99c0_18 *stateMachine;
    gLogoScene->mSubTextFrames = gLogoScene->mSubTextFrames + 1;
    if (IsTxtSystemState2AfterState1() != 0) {
        StartSoundOncePerFrame(34);
    }
    if (data_0217aa08->mUnk_28 == 0) {
        if (data_021759d4->mBackupEnabled != 0) {
            v1 = data_021759d4->mUnk_10;
        } else {
            v1 = 0;
        }
    } else {
        v1 = 1;
    }
    if (v1 != 0) {
        return;
    }
    if (IsTxtSystemState2NoCloseRequest() == 0) {
        return;
    }
    if (gLogoScene->mSubTextFrames > 90) {
        stateMachine = &gLogoScene->mStateMachine;
        stateMachine->mNextState = 4;
        stateMachine->mNextStateRequested = 1;
    }
}

void EnterLogoState4(void) {
    void *message;
    SetTxtSystemOpenSoundId(33);
    message = GetBmgEntry(gLogoScene->mCommonMessages, 128);
    SetupTxtSystemSubTextButton(message, GetBmgEntry(gLogoScene->mCommonMessages, 4));
}

void UpdateLogoState4(void) {
    Unk021a99c0_18 *stateMachine;
    if (GetTxtSystemDone() != 0) {
        SetTxtSystemOpenSoundId(35);
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = 8;
    stateMachine->mNextStateRequested = 1;
}

void EnterLogoState5(void) {
    void *commonMessages;
    void *message;
    void *firstButtonMessage;
    void *secondButtonMessage;
    commonMessages = FindFileInLoadedArchives(data_usa_ov001_021a7680);
    message = GetBmgEntry(commonMessages, 124);
    firstButtonMessage = GetBmgEntry(commonMessages, 0);
    secondButtonMessage = GetBmgEntry(commonMessages, 1);
    SetupTxtSystemSubTextTwoButtons(message, firstButtonMessage, secondButtonMessage, 1);
}

void UpdateLogoState5(void) {
    Unk021a99c0_18 *stateMachine;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    if (GetTxtSystemSelectedIndex() == 0) {
        stateMachine = &gLogoScene->mStateMachine;
        stateMachine->mNextState = 6;
        stateMachine->mNextStateRequested = 1;
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = 8;
    stateMachine->mNextStateRequested = 1;
}

void EnterLogoState6(void) {
    void *message;
    func_02057130();
    if (gLogoScene->mUnk_2c_0 == 0) {
        return;
    }
    message = GetBmgEntry(gLogoScene->mCommonMessages, 126);
    SetupTxtSystemSubTextEx(message, 1, 1, 1, 0, 1);
    gLogoScene->mSubTextFrames = 0;
}

void UpdateLogoState6(void) {
    LogoScene *scene;
    s32 v2;
    Unk021a99c0_18 *stateMachine;
    gLogoScene->mSubTextFrames = gLogoScene->mSubTextFrames + 1;
    scene = gLogoScene;
    if (scene->mUnk_2c_0 != 0) {
        if (IsTxtSystemState2AfterState1() != 0) {
            StartSoundOncePerFrame(34);
        }
        if (data_0217aa08->mUnk_28 == 0) {
            if (data_021759d4->mBackupEnabled != 0) {
                v2 = data_021759d4->mUnk_10;
            } else {
                v2 = 0;
            }
        } else {
            v2 = 1;
        }
        if (v2 != 0) {
            return;
        }
        if (IsTxtSystemState2NoCloseRequest() == 0) {
            return;
        }
        if (gLogoScene->mSubTextFrames > 90) {
            stateMachine = &gLogoScene->mStateMachine;
            stateMachine->mNextState = 7;
            stateMachine->mNextStateRequested = 1;
        }
    } else {
        if (data_0217aa08->mUnk_28 == 0) {
            if (data_021759d4->mBackupEnabled != 0) {
                v2 = data_021759d4->mUnk_10;
            } else {
                v2 = 0;
            }
        } else {
            v2 = 1;
        }
        if (v2 == 0) {
            stateMachine = &scene->mStateMachine;
            stateMachine->mNextState = 8;
            stateMachine->mNextStateRequested = 1;
        }
    }
}

void EnterLogoState7(void) {
    void *message;
    SetTxtSystemOpenSoundId(33);
    message = GetBmgEntry(gLogoScene->mCommonMessages, 127);
    SetupTxtSystemSubTextButton(message, GetBmgEntry(gLogoScene->mCommonMessages, 4));
}

void func_02001294(void) {
    Unk021a99c0_18 *stateMachine;
    if (GetTxtSystemDone() != 0) {
        SetTxtSystemOpenSoundId(35);
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = 8;
    stateMachine->mNextStateRequested = 1;
}

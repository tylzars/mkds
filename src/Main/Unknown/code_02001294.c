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
    Unk021a99c0_18 *v2;
    s32 v3;
    LogoScene *v4;
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
            v2 = &gLogoScene->mStateMachine;
            v2->mNextState = 2;
            v2->mNextStateRequested = 1;
        } else if ((u32) data_021759d4->mUnk_04 == 4) {
            gLogoScene->mUnk_2c_1 = 0;
            v2 = &gLogoScene->mStateMachine;
            v2->mNextState = 6;
            v2->mNextStateRequested = 1;
        } else {
            v2 = &gLogoScene->mStateMachine;
            v2->mNextState = 8;
            v2->mNextStateRequested = 1;
        }
    } else {
        v4 = gLogoScene;
        if (v4->mUnk_2c_0 != 0) {
            v2 = &v4->mStateMachine;
            v2->mNextState = 5;
            v2->mNextStateRequested = 1;
        } else {
            v2 = &v4->mStateMachine;
            v2->mNextState = 8;
            v2->mNextStateRequested = 1;
        }
    }
}

void EnterLogoState2(void) {
    void *v1;
    v1 = GetBmgEntry(gLogoScene->mCommonMessages, 125);
    SetupTxtSystemSubTextButton(v1, GetBmgEntry(gLogoScene->mCommonMessages, 4));
}

void UpdateLogoState2(void) {
    Unk021a99c0_18 *v1;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    v1 = &gLogoScene->mStateMachine;
    v1->mNextState = 3;
    v1->mNextStateRequested = 1;
}

void EnterLogoState3(void) {
    void *v1;
    func_02056e48();
    v1 = GetBmgEntry(gLogoScene->mCommonMessages, 126);
    SetupTxtSystemSubTextEx(v1, 1, 1, 1, 0, 1);
    gLogoScene->mSubTextFrames = 0;
}

void UpdateLogoState3(void) {
    s32 v1;
    Unk021a99c0_18 *v2;
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
        v2 = &gLogoScene->mStateMachine;
        v2->mNextState = 4;
        v2->mNextStateRequested = 1;
    }
}

void EnterLogoState4(void) {
    void *v1;
    SetTxtSystemOpenSoundId(33);
    v1 = GetBmgEntry(gLogoScene->mCommonMessages, 128);
    SetupTxtSystemSubTextButton(v1, GetBmgEntry(gLogoScene->mCommonMessages, 4));
}

void UpdateLogoState4(void) {
    Unk021a99c0_18 *v1;
    if (GetTxtSystemDone() != 0) {
        SetTxtSystemOpenSoundId(35);
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    v1 = &gLogoScene->mStateMachine;
    v1->mNextState = 8;
    v1->mNextStateRequested = 1;
}

void EnterLogoState5(void) {
    void *v1;
    void *v2;
    void *v3;
    void *v4;
    v1 = FindFileInLoadedArchives(data_usa_ov001_021a7680);
    v2 = GetBmgEntry(v1, 124);
    v3 = GetBmgEntry(v1, 0);
    v4 = GetBmgEntry(v1, 1);
    SetupTxtSystemSubTextTwoButtons(v2, v3, v4, 1);
}

void UpdateLogoState5(void) {
    Unk021a99c0_18 *v1;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    if (GetTxtSystemSelectedIndex() == 0) {
        v1 = &gLogoScene->mStateMachine;
        v1->mNextState = 6;
        v1->mNextStateRequested = 1;
        return;
    }
    v1 = &gLogoScene->mStateMachine;
    v1->mNextState = 8;
    v1->mNextStateRequested = 1;
}

void EnterLogoState6(void) {
    void *v1;
    func_02057130();
    if (gLogoScene->mUnk_2c_0 == 0) {
        return;
    }
    v1 = GetBmgEntry(gLogoScene->mCommonMessages, 126);
    SetupTxtSystemSubTextEx(v1, 1, 1, 1, 0, 1);
    gLogoScene->mSubTextFrames = 0;
}

void UpdateLogoState6(void) {
    LogoScene *v1;
    s32 v2;
    Unk021a99c0_18 *v3;
    gLogoScene->mSubTextFrames = gLogoScene->mSubTextFrames + 1;
    v1 = gLogoScene;
    if (v1->mUnk_2c_0 != 0) {
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
            v3 = &gLogoScene->mStateMachine;
            v3->mNextState = 7;
            v3->mNextStateRequested = 1;
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
            v3 = &v1->mStateMachine;
            v3->mNextState = 8;
            v3->mNextStateRequested = 1;
        }
    }
}

void EnterLogoState7(void) {
    void *v1;
    SetTxtSystemOpenSoundId(33);
    v1 = GetBmgEntry(gLogoScene->mCommonMessages, 127);
    SetupTxtSystemSubTextButton(v1, GetBmgEntry(gLogoScene->mCommonMessages, 4));
}

void func_02001294(void) {
    Unk021a99c0_18 *v1;
    if (GetTxtSystemDone() != 0) {
        SetTxtSystemOpenSoundId(35);
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    v1 = &gLogoScene->mStateMachine;
    v1->mNextState = 8;
    v1->mNextStateRequested = 1;
}

#include "03/code_021cb4d0.h"

#include "03/code_021bf000.h"
#include "03/code_021cb000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021c209c.h"
#include "03/code_021cb11c.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/unk_021d6000.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf698.h"
#include "03/code_021d2940.h"
#include "03/code_021d254c.h"
#include "03/code_021d1440.h"
#include "03/unk_021d7000.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf410.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd2e0.h"
#include "03/code_021bf810.h"
#include "code_0214b824.h"
#include "registers.h"

void SetupWay(void) {
    Unk021cd5e0_400 *a = func_ov003_021cdb6c();
    data_ov003_021da240[0] = 0;
    if (gWaySavedIndex == 0) {
        gWaySavedIndex = 1;
    }
    if (GetLanguageIndex() != 0) {
        if (gWaySelectedIndex == 2) {
            gWaySelectedIndex = 0;
        }
        if (gWaySavedIndex == 2) {
            gWaySavedIndex = 1;
        }
    }
    LoadWayFilesAndSetBgCnt();
    LoadHlSetScr();
    func_ov003_021bf43c(0x7e, data_ov003_021d6578[GetLanguageIndex()], a->mUnk_f4 + 1);
    func_ov003_021bf5ec(1);
    PlaceSelectionCorners(data_ov003_021d65e0[func_ov003_021c20a8(1)][gWaySelectedIndex].mUnk_00,
                          data_ov003_021d65e0[func_ov003_021c20a8(1)][gWaySelectedIndex].mUnk_04,
                          data_ov003_021d65e0[func_ov003_021c20a8(1)][gWaySelectedIndex].mUnk_02,
                          data_ov003_021d65e0[func_ov003_021c20a8(1)][gWaySelectedIndex].mUnk_06);
    SetUpdateFunction(func_ov003_021cb71c);
}

void LoadWayFilesAndSetBgCnt(void) {
    Unk021d7654 a = gYbBgStep21NclName2;
    LoadFileToVram(gJbBgStep2NcgName2, GX_LoadBG2Char);
    LoadFileToVram(gYbBgStep2NclName2, GX_LoadBGPltt);
    LoadFileToVram(gJb3WayNscName, GX_LoadBG2Scr);
    gYbBgStep21Ncl = LoadFile(BuildFilePathWithLanguage((u8 *) &a), NULL, 4);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
}

void func_ov003_021cb71c(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x14, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x14);
    SetUpdateFunction(func_ov003_021cb6ec);
}

void func_ov003_021cb6ec(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(1);
    if ((v1 == 0) && (v1 = IsBlendBrightnessFadeSlotBusy(0), v1 == 0)) {
        func_ov003_021bf5c8(0);
        SetUpdateFunction(func_ov003_021cb6c8);
    }
}

void func_ov003_021cb6c8(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateWay);
    }
}

void UpdateWay(void) {
    UpdateWayInput();
    func_ov003_021cb57c();
    func_ov003_021cb538();
}

void UpdateWayInput(void) {
    u32 i;
    for (i = 0; i < 4; i++) {
        if (IsTouchPressedInRect(&gWayRects[func_ov003_021c20a8(1)][i]) != 0) {
            SetButtonResultIfNone(1);
            gWaySelectedIndex = i;
            PlaceSelectionCorners(data_ov003_021d65e0[func_ov003_021c20a8(1)][gWaySelectedIndex].mUnk_00,
                                  data_ov003_021d65e0[func_ov003_021c20a8(1)][gWaySelectedIndex].mUnk_04,
                                  data_ov003_021d65e0[func_ov003_021c20a8(1)][gWaySelectedIndex].mUnk_02,
                                  data_ov003_021d65e0[func_ov003_021c20a8(1)][gWaySelectedIndex].mUnk_06);
            return;
        }
    }
    if (AreKeysPressed(1) != 0) {
        SetButtonResultIfNone(1);
    } else if (AreKeysPressed(2) != 0) {
        SetButtonResultIfNone(0);
    } else if (AreKeysPressedOrRepeated(0x40) != 0) {
        MoveWaySelection(1);
    } else if (AreKeysPressedOrRepeated(0x80) != 0) {
        MoveWaySelection(3);
    } else if (AreKeysPressedOrRepeated(0x20) != 0) {
        MoveWaySelection(0);
    } else if (AreKeysPressedOrRepeated(0x10) != 0) {
        MoveWaySelection(2);
    }
}

void func_ov003_021cb57c(void) {}

void func_ov003_021cb538(void) {
    switch (GetButtonResult()) {
        case 0:
            StartSoundSeq(7);
            break;
        case 1:
            StartSoundSeq(6);
            func_ov003_021cb2e0();
            data_ov003_021da240[0] = 1;
            break;
        default:
            return;
    }
    SetUpdateFunction(func_ov003_021cb518);
}

void func_ov003_021cb518(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(func_ov003_021cb4d0);
}

void func_ov003_021cb4d0(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(1);
    if (v1 == 0) {
        if ((*(u8 *) &data_ov003_021da240) != 0) {
            StartSlideButtonsOut();
        }
        StartBlendBrightnessFade(3, 1, 1, 8);
        StartBlendBrightnessFade(3, 0, 0x14, 8);
        SetUpdateFunction(func_ov003_021cb3d8);
    }
}

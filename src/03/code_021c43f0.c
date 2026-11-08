#include "03/code_021c43f0.h"
#include "03/code_021bf810.h"
#include "03/code_021c391c.h"
#include "03/code_021c43a4.h"
#include "03/code_021c3000.h"
#include "03/code_021c4000.h"
#include "03/code_021c434c.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"

#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021bf098.h"
#include "03/code_021c209c.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021bf000.h"
#include "03/code_021bf4dc.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf410.h"

void func_ov003_021c4670(void) {
    data_ov003_021da1c0 = 0;
    func_ov003_021c460c();
    LoadHlScr(19);
    func_ov003_021bf43c(141, -1, 0);
    PrintMessage(93);
    SetUpdateFunction(func_ov003_021c45d0);
}

void func_ov003_021c460c(void) {
    void *nscName = &data_ov003_021d716c;
    void *loadBg2ScrFunc = &GX_LoadBG2Scr;
    u32 v4 = LoadFileToVram(nscName, loadBg2ScrFunc);
    u32 g2sDbBg0CntAddr = 0x4001008u;
    u32 g2sDbBg0CntOld = (*(u16 *) ((g2sDbBg0CntAddr) + (0)));
    u32 g2sDbBg0CntCleared = ((g2sDbBg0CntOld) & ~(0x3u));
    u32 g2sDbBg0CntNew = ((g2sDbBg0CntCleared) | (0x3u));
    u32 g2sDbBg1CntAddr;
    u32 g2sDbBg1CntOld;
    u32 g2sDbBg1CntCleared;
    u32 g2sDbBg1CntNew;
    u32 g2Bg0CntAddr;
    u32 g2Bg0CntOld;
    u32 g2Bg0CntCleared;
    u32 g2Bg0CntNew;
    u32 g2Bg1CntAddr;
    u32 g2Bg1CntOld;
    u32 g2Bg1CntCleared;
    u32 g2Bg1CntNew;
    u32 g2Bg2CntAddr;
    u32 g2Bg2CntOld;
    u32 g2Bg2CntCleared;
    u32 g2Bg2CntNew;
    *(u16 *) ((g2sDbBg0CntAddr) + (0)) = g2sDbBg0CntNew;
    g2sDbBg1CntAddr = 0x400100au;
    g2sDbBg1CntOld = (*(u16 *) ((g2sDbBg1CntAddr) + (0)));
    g2sDbBg1CntCleared = ((g2sDbBg1CntOld) & ~(0x3u));
    g2sDbBg1CntNew = ((g2sDbBg1CntCleared) | (0x3u));
    *(u16 *) ((g2sDbBg1CntAddr) + (0)) = g2sDbBg1CntNew;
    g2Bg0CntAddr = 0x4000008u;
    g2Bg0CntOld = (*(u16 *) ((g2Bg0CntAddr) + (0)));
    g2Bg0CntCleared = ((g2Bg0CntOld) & ~(0x3u));
    g2Bg0CntNew = ((g2Bg0CntCleared) | (0x3u));
    *(u16 *) ((g2Bg0CntAddr) + (0)) = g2Bg0CntNew;
    g2Bg1CntAddr = 0x400000au;
    g2Bg1CntOld = (*(u16 *) ((g2Bg1CntAddr) + (0)));
    g2Bg1CntCleared = ((g2Bg1CntOld) & ~(0x3u));
    g2Bg1CntNew = ((g2Bg1CntCleared) | (0x3u));
    *(u16 *) ((g2Bg1CntAddr) + (0)) = g2Bg1CntNew;
    g2Bg2CntAddr = 0x400000cu;
    g2Bg2CntOld = (*(u16 *) ((g2Bg2CntAddr) + (0)));
    g2Bg2CntCleared = ((g2Bg2CntOld) & ~(0x3u));
    g2Bg2CntNew = ((g2Bg2CntCleared) | (0x3u));
    *(u16 *) ((g2Bg2CntAddr) + (0)) = g2Bg2CntNew;
}

void func_ov003_021c45d0(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(func_ov003_021c45ac);
}

void func_ov003_021c45ac(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(0);
    if (fadeSlotBusy == 0) {
        func_ov003_021bf5c8(3);
        SetUpdateFunction(func_ov003_021c4588);
    }
}

void func_ov003_021c4588(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        SetUpdateFunction(func_ov003_021c4570);
    }
}

void func_ov003_021c4570(void) {
    func_ov003_021c4544();
    func_ov003_021c4540();
    func_ov003_021c4500();
}

void func_ov003_021c4544(void) {
    int v1;
    v1 = AreKeysPressed(1);
    if (v1 != 0) {
        SetButtonResultIfNone((u8) 1);
    }
    v1 = AreKeysPressed(2);
    if (v1 != 0) {
        SetButtonResultIfNone((u8) 0);
    }
}

void func_ov003_021c4540(void) {}

void func_ov003_021c4500(void) {
    switch (GetButtonResult()) {
        case 0:
            StartSoundSeq(7);
            break;
        case 1:
            StartSoundSeq(6);
            data_ov003_021da1c0 = 1;
            break;
        default:
            return;
    }
    SetUpdateFunction(func_ov003_021c44e0);
}

void func_ov003_021c44e0(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(func_ov003_021c4498);
}

void func_ov003_021c4498(void) {
    int fadeSlotBusy;
    fadeSlotBusy = IsBlendBrightnessFadeSlotBusy(1);
    if (fadeSlotBusy == 0) {
        StartSlideButtonsOut();
        if (data_ov003_021da1c0 == 0) {
            StartBlendBrightnessFade(3, 1, 1, 8);
        }
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(func_ov003_021c4410);
    }
}

void func_ov003_021c4410(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(0);
    if ((v1 == 0) && (((data_ov003_021da1c0 != 0 || (v1 = IsBlendBrightnessFadeSlotBusy(1), v1 == 0)) &&
                       (v1 = func_ov003_021bf2f0(), v1 != 0)))) {
        ReleaseBgTextCanvasOfScreen(0);
        if (data_ov003_021da1c0 == 0) {
            func_ov003_021bf410();
            ClearDispcntBits(1, 1);
        }
        ClearDispcntBits(0, 0x15);
        if (data_ov003_021da1c0 == 0) {
            func_ov003_021c2120(0, 1);
            SetUpdateFunction(SetupOptMenu);
            return;
        }
        func_ov003_021c2120(0, 1);
        SetUpdateFunction(func_ov003_021c43f0);
    }
}

void func_ov003_021c43f0(void) {
    func_ov003_021c43a4();
    PrintMessage(0x5c);
    SetUpdateFunction(func_ov003_021c437c);
}

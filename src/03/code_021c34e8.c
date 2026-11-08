#include "03/code_021c34e8.h"
#include "03/code_021bf410.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c34c4.h"
#include "03/code_021c391c.h"
#include "03/code_021cd2e0.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021d2940.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"

void UpdateJb5InfoInput(void) {
    int v1;
    v1 = AreKeysPressed(2);
    if (v1 != 0) {
        SetButtonResultIfNone((u8) 0);
    }
}

void func_ov003_021c3690(void) {}

void func_ov003_021c366c(void) {
    int buttonResult;
    buttonResult = GetButtonResult();
    if (buttonResult == 0) {
        StartSoundSeq(7);
        SetUpdateFunction(func_ov003_021c364c);
    }
}

void func_ov003_021c364c(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(func_ov003_021c3610);
}

void func_ov003_021c3610(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(1);
    if (v1 == 0) {
        StartSlideButtonsOut();
        StartBlendBrightnessFade(3, 1, 1, 8);
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(func_ov003_021c35bc);
    }
}

void func_ov003_021c35bc(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(1);
    if (((v1 == 0) && (v1 = IsBlendBrightnessFadeSlotBusy(0), v1 == 0)) && (v1 = func_ov003_021bf2f0(), v1 != 0)) {
        ReleaseBgTextCanvasOfScreen(0);
        func_ov003_021bf410();
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x15);
        func_ov003_021c2120(0, 1);
        SetUpdateFunction(SetupOptMenu);
    }
}

void func_ov003_021c3598(void) {
    func_ov003_021c3534();
    PrintMessage(0x57);
    func_ov003_021cd42c();
    SetUpdateFunction(func_ov003_021c350c);
}

void func_ov003_021c3534(void) {
    void *yb5MultiNscName2 = &gYb5MultiNscName2;
    void *loadBg2ScrFunc = &GX_LoadBG2Scr;
    u32 v4 = LoadFileToVram(yb5MultiNscName2, loadBg2ScrFunc);
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

void func_ov003_021c350c(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(func_ov003_021c34e8);
}

void func_ov003_021c34e8(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(0);
    if (v1 == 0) {
        func_ov003_021bf5c8(5);
        SetUpdateFunction(func_ov003_021c34c4);
    }
}

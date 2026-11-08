#include "03/code_021c9cf4.h"
#include "03/code_021bf810.h"
#include "03/code_021c2904.h"
#include "03/code_021be000.h"
#include "03/code_021bf000.h"
#include "03/code_021bf410.h"
#include "03/code_021c2000.h"
#include "03/code_021ca000.h"
#include "03/code_021c209c.h"
#include "03/code_021ca008.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cef90.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c9000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"
#include "03/code_021c99a8.h"
#include "03/code_021cb000.h"
#include "03/code_021cd000.h"
#include "03/code_021d2940.h"
#include "03/code_021ca20c.h"
#include "03/code_021ca028.h"

#include "03/code_021c2938.h"
#include "03/code_021c9cb0.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "os_thread.h"

void func_ov003_021c9fd4(void) {
    *(u8 *) &data_ov003_021da21c = 0;
    func_ov003_021c9f70();
    LoadHlSetScr();
    PrintMessage(0x71);
    func_ov003_021beef8(2);
    SetUpdateFunction(func_ov003_021c9f48);
}

void func_ov003_021c9f70(void) {
    void *v2 = &gXb4MultiNscName4;
    void *v3 = &GX_LoadBG2Scr;
    u32 v4 = LoadFileToVram(v2, v3);
    u32 v5 = 0x4001008u;
    u32 v6 = (*(u16 *) ((v5) + (0)));
    u32 v8 = ((v6) & ~(0x3u));
    u32 v9 = ((v8) | (0x3u));
    u32 v11;
    u32 v12;
    u32 v13;
    u32 v14;
    u32 v16;
    u32 v17;
    u32 v18;
    u32 v19;
    u32 v21;
    u32 v22;
    u32 v23;
    u32 v24;
    u32 v26;
    u32 v27;
    u32 v28;
    u32 v29;
    *(u16 *) ((v5) + (0)) = v9;
    v11 = 0x400100au;
    v12 = (*(u16 *) ((v11) + (0)));
    v13 = ((v12) & ~(0x3u));
    v14 = ((v13) | (0x3u));
    *(u16 *) ((v11) + (0)) = v14;
    v16 = 0x4000008u;
    v17 = (*(u16 *) ((v16) + (0)));
    v18 = ((v17) & ~(0x3u));
    v19 = ((v18) | (0x3u));
    *(u16 *) ((v16) + (0)) = v19;
    v21 = 0x400000au;
    v22 = (*(u16 *) ((v21) + (0)));
    v23 = ((v22) & ~(0x3u));
    v24 = ((v23) | (0x3u));
    *(u16 *) ((v21) + (0)) = v24;
    v26 = 0x400000cu;
    v27 = (*(u16 *) ((v26) + (0)));
    v28 = ((v27) & ~(0x3u));
    v29 = ((v28) | (0x3u));
    *(u16 *) ((v26) + (0)) = v29;
}

void func_ov003_021c9f48(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(func_ov003_021c9f24);
}

void func_ov003_021c9f24(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(0);
    if (v1 == 0) {
        func_ov003_021bf5c8(1);
        SetUpdateFunction(func_ov003_021c9f00);
    }
}

void func_ov003_021c9f00(void) {
    int v1;
    v1 = GetButtonResult();
    if (v1 != -2) {
        EnableButtonTouch();
        SetUpdateFunction(func_ov003_021c9ee0);
    }
}

void func_ov003_021c9ee0(void) {
    OS_Sleep(0xa);
    func_ov003_021c9cf4();
    func_ov003_021c9eb0();
    func_ov003_021c9eac();
    func_ov003_021c9e84();
}

void func_ov003_021c9eb0(void) {
    int v1;
    v1 = AreKeysPressed(2);
    if (v1 != 0) {
        SetButtonResultIfNone(0);
        return;
    }
    v1 = func_ov003_021ca008();
    if (v1 != 0) {
        SetButtonResultIfNone(0);
    }
}

void func_ov003_021c9eac(void) {}

void func_ov003_021c9e84(void) {
    int v1;
    v1 = GetButtonResult();
    if (v1 == 0) {
        StopSoundSeq();
        StartSoundSeq(7);
        SetUpdateFunction(func_ov003_021c9e64);
    }
}

void func_ov003_021c9e64(void) {
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(func_ov003_021c9e1c);
}

void func_ov003_021c9e1c(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(1);
    if (v1 == 0) {
        StartSlideButtonsOut();
        if (data_ov003_021da21c == 0) {
            StartBlendBrightnessFade(3, 1, 1, 8);
        }
        StartBlendBrightnessFade(3, 0, 0x15, 8);
        SetUpdateFunction(func_ov003_021c9d94);
    }
}

void func_ov003_021c9d94(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(0);
    if ((v1 == 0) && (((data_ov003_021da21c != 0 || (v1 = IsBlendBrightnessFadeSlotBusy(1), v1 == 0)) &&
                       (v1 = func_ov003_021bf2f0(), v1 != 0)))) {
        func_ov003_021beecc();
        ReleaseBgTextCanvasOfScreen(0);
        if (data_ov003_021da21c == 0) {
            func_ov003_021bf410();
            ClearDispcntBits(1, 1);
        }
        StopExchangeWithStatusRecord();
        if (data_ov003_021da21c == 0) {
            func_ov003_021c2120(2, 1);
            SetUpdateFunction(SetupWay);
            return;
        }
        func_ov003_021c2120(0, 0);
        SetUpdateFunction(func_ov003_021ca194);
    }
}

void func_ov003_021c9cf4(void) {
    switch (func_ov003_021c2938()) {
        case 3:
            data_ov003_021da21c = 1;
            StopSoundSeq();
            func_ov003_021c2918();
            SetUpdateFunction(func_ov003_021c9e64);
            break;
        case 4:
            data_ov003_021da21c = 0;
            StopSoundSeq();
            StartSoundSeq(9);
            func_ov003_021cefc0(0x41, 1, 1, -1, 0);
            DisableButtonTouch();
            SetUpdateFunction(func_ov003_021c9ccc);
            break;
        case 5:
            data_ov003_021da21c = 0;
            StopSoundSeq();
            StartSoundSeq(0x12);
            func_ov003_021cefc0(0x42, 1, 1, -1, 0);
            DisableButtonTouch();
            SetUpdateFunction(func_ov003_021c9ccc);
            break;
    }
}

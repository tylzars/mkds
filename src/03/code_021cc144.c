#include "03/code_021cc144.h"
#include "03/code_021bf810.h"
#include "03/code_021cb11c.h"
#include "03/code_021cb000.h"
#include "03/code_021cc000.h"
#include "03/code_021cc410.h"
#include "03/code_021cd000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"

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

void SetupXb3Multi(void) {
    data_ov003_021da254 = 0;
    LoadXb3MultiFilesAndSetBgCnt();
    LoadHlScr(8);
    func_ov003_021bf43c(0x85, -1, 0);
    func_ov003_021bf5ec(1);
    func_ov003_021bf578(0x6c);
    func_ov003_021c212c(func_ov003_021cc310);
}

void LoadXb3MultiFilesAndSetBgCnt(void) {
    void *v2 = &gJbBgStep2NcgName3;
    void *v3 = &GX_LoadBG2Char;
    u32 v4 = func_ov003_021bf620(v2, v3);
    void *v5 = &gYbBgStep2NclName3;
    void *v6 = &GX_LoadBGPltt;
    u32 v7 = func_ov003_021bf620(v5, v6);
    void *v8 = &gXb3MultiNscName;
    void *v9 = &GX_LoadBG2Scr;
    u32 v10 = func_ov003_021bf620(v8, v9);
    u32 v11 = 0x4001008u;
    u32 v12 = (*(u16 *) ((v11) + (0)));
    u32 v14 = ((v12) & ~(0x3u));
    u32 v15 = ((v14) | (0x3u));
    u32 v17;
    u32 v18;
    u32 v19;
    u32 v20;
    u32 v22;
    u32 v23;
    u32 v24;
    u32 v25;
    u32 v27;
    u32 v28;
    u32 v29;
    u32 v30;
    u32 v32;
    u32 v33;
    u32 v34;
    u32 v35;
    *(u16 *) ((v11) + (0)) = v15;
    v17 = 0x400100au;
    v18 = (*(u16 *) ((v17) + (0)));
    v19 = ((v18) & ~(0x3u));
    v20 = ((v19) | (0x3u));
    *(u16 *) ((v17) + (0)) = v20;
    v22 = 0x4000008u;
    v23 = (*(u16 *) ((v22) + (0)));
    v24 = ((v23) & ~(0x3u));
    v25 = ((v24) | (0x3u));
    *(u16 *) ((v22) + (0)) = v25;
    v27 = 0x400000au;
    v28 = (*(u16 *) ((v27) + (0)));
    v29 = ((v28) & ~(0x3u));
    v30 = ((v29) | (0x3u));
    *(u16 *) ((v27) + (0)) = v30;
    v32 = 0x400000cu;
    v33 = (*(u16 *) ((v32) + (0)));
    v34 = ((v33) & ~(0x3u));
    v35 = ((v34) | (0x3u));
    *(u16 *) ((v32) + (0)) = v35;
}

void func_ov003_021cc310(void) {
    func_ov003_021d1ee0(2, 1, 1, 8);
    func_ov003_021d1ee0(2, 0, 0x15, 8);
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x15);
    func_ov003_021c212c(func_ov003_021cc2e0);
}

void func_ov003_021cc2e0(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021bf5c8(6);
        func_ov003_021c212c(func_ov003_021cc2bc);
    }
}

void func_ov003_021cc2bc(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        func_ov003_021c212c(UpdateXb3Multi);
    }
}

void UpdateXb3Multi(void) {
    UpdateXb3MultiInput();
    func_ov003_021cc274();
    func_ov003_021cc234();
}

void UpdateXb3MultiInput(void) {
    int v1;
    v1 = func_ov003_021d2b04(1);
    if (v1 != 0) {
        SetButtonResultIfNone((u8) 1);
    }
    v1 = func_ov003_021d2b04(2);
    if (v1 != 0) {
        SetButtonResultIfNone((u8) 0);
    }
}

void func_ov003_021cc274(void) {}

void func_ov003_021cc234(void) {
    switch (GetButtonResult()) {
        case 0:
            StartSoundSeq(7);
            break;
        case 1:
            StartSoundSeq(6);
            data_ov003_021da254 = 1;
            break;
        default:
            return;
    }
    func_ov003_021c212c(func_ov003_021cc214);
}

void func_ov003_021cc214(void) {
    DisableButtonTouch();
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021cc1cc);
}

void func_ov003_021cc1cc(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        StartSlideButtonsOut();
        if (data_ov003_021da254 == 0) {
            func_ov003_021d1ee0(3, 1, 1, 8);
        }
        func_ov003_021d1ee0(3, 0, 0x15, 8);
        func_ov003_021c212c(func_ov003_021cc144);
    }
}

void func_ov003_021cc144(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if ((v1 == 0) && (((data_ov003_021da254 != 0 || (v1 = func_ov003_021d1f70(1), v1 == 0)) &&
                       (v1 = func_ov003_021bf2f0(), v1 != 0)))) {
        func_ov003_021d2168(0);
        if (data_ov003_021da254 == 0) {
            func_ov003_021bf410();
            func_ov003_021d272c(1, 1);
        }
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da254 == 0) {
            func_ov003_021c2120(2, 1);
            func_ov003_021c212c(CreateAp);
            return;
        }
        func_ov003_021c2120(2, 1);
        func_ov003_021c212c(SetupUsb);
    }
}

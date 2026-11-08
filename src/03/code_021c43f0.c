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
    void *v2 = &data_ov003_021d716c;
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

void func_ov003_021c45d0(void) {
    func_ov003_021d1ee0(2, 1, 1, 8);
    func_ov003_021d1ee0(2, 0, 0x15, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(func_ov003_021c45ac);
}

void func_ov003_021c45ac(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if (v1 == 0) {
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
    func_ov003_021d1dd0(8);
    SetUpdateFunction(func_ov003_021c4498);
}

void func_ov003_021c4498(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        StartSlideButtonsOut();
        if (data_ov003_021da1c0 == 0) {
            func_ov003_021d1ee0(3, 1, 1, 8);
        }
        func_ov003_021d1ee0(3, 0, 0x15, 8);
        SetUpdateFunction(func_ov003_021c4410);
    }
}

void func_ov003_021c4410(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if ((v1 == 0) && (((data_ov003_021da1c0 != 0 || (v1 = func_ov003_021d1f70(1), v1 == 0)) &&
                       (v1 = func_ov003_021bf2f0(), v1 != 0)))) {
        func_ov003_021d2168(0);
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

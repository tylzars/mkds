#include "03/code_021c46a8.h"
#include "03/code_021c391c.h"
#include "03/code_021bf410.h"
#include "03/code_021c3000.h"
#include "03/code_021c4000.h"
#include "03/code_021bf000.h"
#include "03/code_021bf098.h"
#include "03/code_021be000.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c209c.h"
#include "03/code_021cd000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_0214b824.h"
#include "03/code_021c4dd4.h"

#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021d3000.h"
#include "03/code_021d3488.h"
#include "03/code_021c25e0.h"

void func_ov003_021c4804(void) {
    data_ov003_021da1c4 = 0;
    func_ov003_021c47b0();
    PrintMessage(99);
    SetUpdateFunction(func_ov003_021c4788);
}

void func_ov003_021c47b0(void) {
    void *v2 = &data_ov003_021d7180;
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
    *(u16 *) ((v5) + (0)) = v9;
    v11 = 0x400100au;
    v12 = (*(u16 *) ((v11) + (0)));
    v13 = ((v12) & ~(0x3u));
    v14 = ((v13) | (0x3u));
    *(u16 *) ((v11) + (0)) = v14;
    v16 = 0x400000au;
    v17 = (*(u16 *) ((v16) + (0)));
    v18 = ((v17) & ~(0x3u));
    v19 = ((v18) | (0x3u));
    *(u16 *) ((v16) + (0)) = v19;
    v21 = 0x400000cu;
    v22 = (*(u16 *) ((v21) + (0)));
    v23 = ((v22) & ~(0x3u));
    v24 = ((v23) | (0x3u));
    *(u16 *) ((v21) + (0)) = v24;
}

void func_ov003_021c4788(void) {
    StartBlendBrightnessFade(2, 0, 0x15, 8);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(func_ov003_021c4760);
}

void func_ov003_021c4760(void) {
    if (IsBlendBrightnessFadeSlotBusy(0) == 0 && func_ov003_021c27e4() != 0) {
        SetUpdateFunction(func_ov003_021c474c);
    }
}

void func_ov003_021c474c(void) {
    func_ov003_021c46a8();
    func_ov003_021c4748();
}

void func_ov003_021c4748(void) {}

void func_ov003_021c471c(void) {
    StartBlendBrightnessFade(3, 1, 1, 8);
    StartBlendBrightnessFade(3, 0, 0x15, 8);
    SetUpdateFunction(func_ov003_021c46d0);
}

void func_ov003_021c46d0(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(1);
    if ((v1 == 0) && (v1 = IsBlendBrightnessFadeSlotBusy(0), v1 == 0)) {
        ReleaseBgTextCanvasOfScreen(0);
        func_ov003_021bf410();
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x15);
        func_ov003_021c2120(0, 1);
        SetUpdateFunction(SetupOptMenu);
    }
}

void func_ov003_021c46a8(void) {
    data_ov003_021da1c4++;
    if (data_ov003_021da1c4 >= 120) {
        SetUpdateFunction(func_ov003_021c471c);
    }
}

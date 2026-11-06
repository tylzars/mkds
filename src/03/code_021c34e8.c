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
    v1 = func_ov003_021d2b04((u32) 2);
    if (v1 != 0) {
        func_ov003_021bf31c((u8) 0);
    }
}

void func_ov003_021c3690(void) {
    return;
}

void func_ov003_021c366c(void) {
    int v1;
    v1 = func_ov003_021bf334();
    if (v1 == 0) {
        StartSoundSeq((u32) 7);
        func_ov003_021c212c(func_ov003_021c364c);
    }
}

void func_ov003_021c364c(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) 8);
    func_ov003_021c212c(func_ov003_021c3610);
}

void func_ov003_021c3610(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021bf344();
        func_ov003_021d1ee0(3, 1, (u32) 1, (u16) 8);
        func_ov003_021d1ee0(3, 0, (u32) 0x15, (u16) 8);
        func_ov003_021c212c(func_ov003_021c35bc);
    }
}

void func_ov003_021c35bc(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) && (v1 = func_ov003_021bf2f0(), v1 != 0)) {
        func_ov003_021d2168(0);
        func_ov003_021bf410();
        func_ov003_021d272c(1, (u32) 1);
        func_ov003_021d272c(0, (u32) 0x15);
        func_ov003_021c2120((u32) 0, (u32) 1);
        func_ov003_021c212c(SetupOptMenu);
    }
}

void func_ov003_021c3598(void) {
    func_ov003_021c3534();
    func_ov003_021bf578((u32) 0x57);
    func_ov003_021cd42c();
    func_ov003_021c212c(func_ov003_021c350c);
}

void func_ov003_021c3534(void) {
    void *v2 = &gYb5MultiNscName2;
    void *v3 = &GX_LoadBG2Scr;
    u32 v4 = func_ov003_021bf620(v2, v3);
    u32 v5 = 0x4001008u;
    u32 v6 = ((u32) * (u16 *) ((v5) + (0)));
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
    *(u16 *) ((v5) + (0)) = (u16) v9;
    v11 = 0x400100au;
    v12 = ((u32) * (u16 *) ((v11) + (0)));
    v13 = ((v12) & ~(0x3u));
    v14 = ((v13) | (0x3u));
    *(u16 *) ((v11) + (0)) = (u16) v14;
    v16 = 0x4000008u;
    v17 = ((u32) * (u16 *) ((v16) + (0)));
    v18 = ((v17) & ~(0x3u));
    v19 = ((v18) | (0x3u));
    *(u16 *) ((v16) + (0)) = (u16) v19;
    v21 = 0x400000au;
    v22 = ((u32) * (u16 *) ((v21) + (0)));
    v23 = ((v22) & ~(0x3u));
    v24 = ((v23) | (0x3u));
    *(u16 *) ((v21) + (0)) = (u16) v24;
    v26 = 0x400000cu;
    v27 = ((u32) * (u16 *) ((v26) + (0)));
    v28 = ((v27) & ~(0x3u));
    v29 = ((v28) | (0x3u));
    *(u16 *) ((v26) + (0)) = (u16) v29;
}

void func_ov003_021c350c(void) {
    func_ov003_021d1ee0(2, 0, (u32) 0x15, (u16) 8);
    func_ov003_021d2784(0, (u32) 0x15);
    func_ov003_021c212c(func_ov003_021c34e8);
}

void func_ov003_021c34e8(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if (v1 == 0) {
        func_ov003_021bf5c8((u32) 5);
        func_ov003_021c212c(func_ov003_021c34c4);
    }
}

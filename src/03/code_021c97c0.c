#include "03/code_021c97c0.h"
#include "03/code_021bf410.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf810.h"
#include "03/code_021c99a8.h"
#include "03/code_021cb11c.h"
#include "03/code_021cd2e0.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cea3c.h"
#include "03/code_021cef90.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"

void func_ov003_021c9980(void) {
    int v1;
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        StartSoundSeq(6);
        func_ov003_021cef90();
        func_ov003_021c212c(func_ov003_021c9964);
    }
}

void func_ov003_021c9964(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        func_ov003_021c212c(func_ov003_021c9aec);
    }
}

void func_ov003_021c9944(void) {
    func_ov003_021c98d0();
    LoadHlSetScr();
    func_ov003_021cd6d0();
    func_ov003_021c212c(func_ov003_021c9894);
}

void func_ov003_021c98d0(void) {
    void *v2 = &gJbBgStep3NcgName4;
    void *v3 = &GX_LoadBG2Char;
    u32 v4 = LoadFileToVram(v2, v3);
    void *v5 = &gYbBgStep3NclName4;
    void *v6 = &GX_LoadBGPltt;
    u32 v7 = LoadFileToVram(v5, v6);
    void *v8 = &gXb4NoneNscName;
    void *v9 = &GX_LoadBG2Scr;
    u32 v10 = LoadFileToVram(v8, v9);
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
    *(u16 *) ((v11) + (0)) = v15;
    v17 = 0x400100au;
    v18 = (*(u16 *) ((v17) + (0)));
    v19 = ((v18) & ~(0x3u));
    v20 = ((v19) | (0x3u));
    *(u16 *) ((v17) + (0)) = v20;
    v22 = 0x400000au;
    v23 = (*(u16 *) ((v22) + (0)));
    v24 = ((v23) & ~(0x3u));
    v25 = ((v24) | (0x3u));
    *(u16 *) ((v22) + (0)) = v25;
    v27 = 0x400000cu;
    v28 = (*(u16 *) ((v27) + (0)));
    v29 = ((v28) & ~(0x3u));
    v30 = ((v29) | (0x3u));
    *(u16 *) ((v27) + (0)) = v30;
}

void func_ov003_021c9894(void) {
    func_ov003_021d1ee0(2, 1, 1, 8);
    func_ov003_021d1ee0(2, 0, 0x14, 8);
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x14);
    func_ov003_021c212c(func_ov003_021c985c);
}

void func_ov003_021c985c(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021cefc0(0x96, 5, 1, 0xffffffff, 0);
        func_ov003_021c212c(func_ov003_021c9838);
    }
}

void func_ov003_021c9838(void) {
    int v1;
    func_ov003_021c9834();
    func_ov003_021c9830();
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        func_ov003_021c212c(func_ov003_021c9804);
    }
}

void func_ov003_021c9834(void) {}

void func_ov003_021c9830(void) {}

void func_ov003_021c9804(void) {
    func_ov003_021d1ee0(3, 1, 1, 8);
    func_ov003_021d1ee0(3, 0, 0x14, 8);
    func_ov003_021c212c(func_ov003_021c97c0);
}

void func_ov003_021c97c0(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021bf410();
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x14);
        func_ov003_021c2120(2, 1);
        func_ov003_021c212c(CreateAp);
    }
}

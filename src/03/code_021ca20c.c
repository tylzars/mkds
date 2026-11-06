#include "03/code_021ca20c.h"
#include "03/code_021c2904.h"
#include "03/code_021be000.h"
#include "03/code_021c9000.h"
#include "03/code_021c99a8.h"
#include "03/code_021ca54c.h"
#include "03/code_021cb000.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cef90.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"

#include "03/code_021bf098.h"
#include "03/code_021c209c.h"
#include "03/code_021c2938.h"
#include "03/code_021bf000.h"
#include "03/code_021ca000.h"
#include "03/code_021cd000.h"
#include "03/code_021ce000.h"
#include "03/code_021d1000.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"
#include "03/code_021ca028.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "code_0200db4c.h"
#include "03/code_021c2000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c29d8.h"
#include "03/code_021d1f70.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf410.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd2e0.h"
#include "03/code_021bf810.h"
#include "03/code_021be610.h"

void func_ov003_021ca504(void) {
    data_ov003_021da224 = 0;
    func_ov003_021ca480();
    LoadHlSetScr();
    func_ov003_021bf43c(0x83, -1, 0);
    func_ov003_021bf5ec(2);
    func_ov003_021bf578(0x69);
    func_ov003_021beef8(0);
    StartSoundSeq(0xb);
    func_ov003_021c212c(func_ov003_021ca444);
}

void func_ov003_021ca480(void) {
    void *v2 = &gJbBgStep3NcgName5;
    void *v3 = &GX_LoadBG2Char;
    u32 v4 = func_ov003_021bf620(v2, v3);
    void *v5 = &gYbBgStep3NclName5;
    void *v6 = &GX_LoadBGPltt;
    u32 v7 = func_ov003_021bf620(v5, v6);
    void *v8 = &gXb4MultiNscName6;
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

void func_ov003_021ca444(void) {
    func_ov003_021d1ee0(2, 1, 1, 8);
    func_ov003_021d1ee0(2, 0, 0x15, 8);
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x15);
    func_ov003_021c212c(func_ov003_021ca410);
}

void func_ov003_021ca410(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0) {
        func_ov003_021c29d8();
        func_ov003_021bf5c8(1);
        func_ov003_021c212c(func_ov003_021ca3ec);
    }
}

void func_ov003_021ca3ec(void) {
    int v1;
    v1 = func_ov003_021bf334();
    if (v1 != -2) {
        func_ov003_021bf2e0();
        func_ov003_021c212c(func_ov003_021ca3cc);
    }
    return;
}

void func_ov003_021ca3cc(void) {
    OS_Sleep(0xa);
    func_ov003_021ca20c();
    func_ov003_021ca39c();
    func_ov003_021ca398();
    func_ov003_021ca370();
}

void func_ov003_021ca39c(void) {
    int v1;
    v1 = func_ov003_021d2b04(2);
    if (v1 != 0) {
        func_ov003_021bf31c(0);
        return;
    }
    v1 = func_ov003_021ca54c();
    if (v1 != 0) {
        func_ov003_021bf31c(0);
    }
    return;
}

void func_ov003_021ca398(void) {
    return;
}

void func_ov003_021ca370(void) {
    int v1;
    v1 = func_ov003_021bf334();
    if (v1 == 0) {
        StopSoundSeq();
        StartSoundSeq(7);
        func_ov003_021c212c(func_ov003_021ca350);
    }
    return;
}

void func_ov003_021ca350(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021ca300);
    return;
}

void func_ov003_021ca300(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        if (data_ov003_021da224 == 0) {
            func_ov003_021bf344();
        }
        if (data_ov003_021da224 == 0) {
            func_ov003_021d1ee0(3, 1, 1, 8);
        }
        func_ov003_021d1ee0(3, 0, 0x14, 8);
        func_ov003_021c212c(func_ov003_021ca270);
    }
    return;
}

void func_ov003_021ca270(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if ((v1 == 0) && (((data_ov003_021da224 != 0 || (v1 = func_ov003_021d1f70(1), v1 == 0)) &&
                       (v1 = func_ov003_021bf2f0(), v1 != 0)))) {
        func_ov003_021beecc();
        func_ov003_021d2168(0);
        if (data_ov003_021da224 == 0) {
            func_ov003_021bf410();
            func_ov003_021d272c(1, 1);
        }
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da224 == 0) {
            func_ov003_021c29b8();
            func_ov003_021c2120(2, 1);
            func_ov003_021c212c(SetupWay);
            return;
        }
        func_ov003_021c2120(0, 0);
        func_ov003_021c212c(func_ov003_021c9c5c);
    }
    return;
}

void func_ov003_021ca20c(void) {
    switch (func_ov003_021c2938()) {
        case 1:
            data_ov003_021da224 = 1;
            func_ov003_021c212c(func_ov003_021ca350);
            break;
        case 4:
            data_ov003_021da224 = 0;
            StopSoundSeq();
            StartSoundSeq(9);
            func_ov003_021cefc0(0x41, 1, 1, -1, 0);
            func_ov003_021bf2d0();
            func_ov003_021c212c(func_ov003_021ca1e4);
            break;
    }
}

#include "03/code_021ca56c.h"
#include "03/code_021c5724.h"
#include "03/code_021be000.h"
#include "03/code_021bf000.h"
#include "03/code_021c2000.h"
#include "03/code_021c6000.h"
#include "03/code_021cb000.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cd000.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd2e0.h"
#include "03/code_021cef90.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"
#include "03/code_021ca000.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"
#include "03/unk_021d6000.h"
#include "03/code_021ca940.h"

#include "03/code_021cea3c.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021bf098.h"
#include "03/code_021c209c.h"
#include "03/code_021cd0d0.h"
#include "03/code_021cdbd0.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf410.h"
#include "03/code_021bf810.h"
#include "03/code_021be610.h"

void func_ov003_021ca8e8(void) {
    data_ov003_021da22c = 0;
    *(u8 *) &data_ov003_021da228 = 0;
    func_ov003_021ca864();
    func_ov003_021bf43c(0x7f, -1, 0);
    func_ov003_021bf854();
    func_ov003_021bf5ec(2);
    func_ov003_021bf578(0x7f);
    func_ov003_021beef8(0);
    func_ov003_021cd2a4();
    func_ov003_021cd1c4();
    StartSoundSeq(0xa);
    func_ov003_021c212c(func_ov003_021ca828);
}

void func_ov003_021ca864(void) {
    void *v2 = &gJbBgStep3NcgName6;
    void *v3 = &GX_LoadBG2Char;
    u32 v4 = func_ov003_021bf620(v2, v3);
    void *v5 = &gYbBgStep3NclName6;
    void *v6 = &GX_LoadBGPltt;
    u32 v7 = func_ov003_021bf620(v5, v6);
    void *v8 = &gXb4MultiNscName7;
    void *v9 = &GX_LoadBG2Scr;
    u32 v10 = func_ov003_021bf620(v8, v9);
    u32 v11 = 0x4001008u;
    u32 v12 = ((u32) * (u16 *) ((v11) + (0)));
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
    *(u16 *) ((v11) + (0)) = (u16) v15;
    v17 = 0x400100au;
    v18 = ((u32) * (u16 *) ((v17) + (0)));
    v19 = ((v18) & ~(0x3u));
    v20 = ((v19) | (0x3u));
    *(u16 *) ((v17) + (0)) = (u16) v20;
    v22 = 0x4000008u;
    v23 = ((u32) * (u16 *) ((v22) + (0)));
    v24 = ((v23) & ~(0x3u));
    v25 = ((v24) | (0x3u));
    *(u16 *) ((v22) + (0)) = (u16) v25;
    v27 = 0x400000au;
    v28 = ((u32) * (u16 *) ((v27) + (0)));
    v29 = ((v28) & ~(0x3u));
    v30 = ((v29) | (0x3u));
    *(u16 *) ((v27) + (0)) = (u16) v30;
    v32 = 0x400000cu;
    v33 = ((u32) * (u16 *) ((v32) + (0)));
    v34 = ((v33) & ~(0x3u));
    v35 = ((v34) | (0x3u));
    *(u16 *) ((v32) + (0)) = (u16) v35;
}

void func_ov003_021ca828(void) {
    func_ov003_021d1ee0(2, 1, (u32) 1, (u16) 8);
    func_ov003_021d1ee0(2, 0, (u32) 0x15, (u16) 8);
    func_ov003_021d2784(1, (u32) 1);
    func_ov003_021d2784(0, (u32) 0x15);
    func_ov003_021c212c(func_ov003_021ca7f8);
}

void func_ov003_021ca7f8(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021bf5c8((u32) 1);
        func_ov003_021c212c(func_ov003_021ca7d4);
    }
}

void func_ov003_021ca7d4(void) {
    if (func_ov003_021bf334() != -2) {
        func_ov003_021bf2e0();
        func_ov003_021c212c(func_ov003_021ca7b8);
    }
}

void func_ov003_021ca7b8(void) {
    func_ov003_021ca6d4();
    func_ov003_021ca6d0();
    func_ov003_021ca6a8();
    func_ov003_021ca6f4();
    return;
}

void func_ov003_021ca6f4(void) {
    int a;
    int b;
    int i;
    data_ov003_021da22c++;
    if (data_ov003_021da22c >= 0x12c) {
        StopSoundSeq();
        a = func_ov003_021cd0d0(&b);
        if (a == 0) {
            *(u8 *) &data_ov003_021da228 = 2;
            func_ov003_021cefc0(0x43, 1, 1, -1, 0);
            StartSoundSeq(0x12);
            func_ov003_021bf2d0();
            func_ov003_021c212c(func_ov003_021ca588);
            return;
        }
        for (i = 0; i < a; i++) {
            if (*(u8 *) (b + i * 0x2a + 0x28) != 2) {
                break;
            }
        }
        if (i == a) {
            *(u8 *) &data_ov003_021da228 = 3;
            func_ov003_021cefc0(0x42, 1, 1, -1, 0);
            StartSoundSeq(0x12);
            func_ov003_021bf2d0();
            func_ov003_021c212c(func_ov003_021ca588);
        } else {
            *(u8 *) &data_ov003_021da228 = 1;
            StartSoundSeq(0xf);
            func_ov003_021c212c(func_ov003_021ca688);
        }
    }
}

void func_ov003_021ca6d4(void) {
    int v1;
    v1 = func_ov003_021d2b04((u32) 2);
    if (v1 != 0) {
        StopSoundSeq();
        func_ov003_021bf31c((u8) 0);
    }
}

void func_ov003_021ca6d0(void) {
    return;
}

void func_ov003_021ca6a8(void) {
    int v1;
    v1 = func_ov003_021bf334();
    if (v1 == 0) {
        StopSoundSeq();
        StartSoundSeq((u32) 7);
        func_ov003_021c212c(func_ov003_021ca688);
    }
}

void func_ov003_021ca688(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) 8);
    func_ov003_021c212c(func_ov003_021ca64c);
}

void func_ov003_021ca64c(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021bf344();
        func_ov003_021d1ee0(3, 1, (u32) 1, (u16) 8);
        func_ov003_021d1ee0(3, 0, (u32) 0x15, (u16) 8);
        func_ov003_021c212c(func_ov003_021ca5b0);
    }
}

void func_ov003_021ca5b0(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) && (v1 = func_ov003_021bf2f0(), v1 != 0)) {
        do {
            v1 = func_ov003_021cd118();
        } while (v1 == 0);
        func_ov003_021beecc();
        func_ov003_021d2168(0);
        func_ov003_021bf410();
        func_ov003_021d272c(1, (u32) 1);
        func_ov003_021d272c(0, (u32) 0x15);
        if ((*(u8 *) &data_ov003_021da228) != 1) {
            func_ov003_021cd27c();
            func_ov003_021cd790(func_ov003_021cdb6c()->mUnk_f4);
            func_ov003_021c2120((u32) 2, (u32) 1);
            func_ov003_021c212c(SetupWay);
            return;
        }
        func_ov003_021c2120((u32) 0, (u32) 1);
        func_ov003_021c20f8((u32) 0, (u32) 0);
        func_ov003_021c212c(CreateApList);
    }
}

void func_ov003_021ca588(void) {
    int v1;
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        StartSoundSeq((u32) 6);
        func_ov003_021cef90();
        func_ov003_021c212c(func_ov003_021ca56c);
    }
}

void func_ov003_021ca56c(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        func_ov003_021c212c(func_ov003_021ca688);
    }
}

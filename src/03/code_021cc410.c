#include "03/code_021cc410.h"
#include "03/code_021cd000.h"
#include "03/code_021cef90.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"
#include "03/code_021c2000.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"

#include "03/code_021cea3c.h"
#include "03/code_021c209c.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021ce000.h"
#include "03/code_021bf098.h"
#include "03/code_021bf410.h"
#include "03/code_021ca000.h"
#include "03/code_021cb11c.h"
#include "03/code_021cc144.h"
#include "03/code_021cbfa4.h"
#include "03/code_021ce5b8.h"
#include "03/code_021d1f70.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021be610.h"
#include "03/code_021bf000.h"
#include "03/code_021d1000.h"
#include "03/code_021cc8b4.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1440.h"
#include "03/code_021bf810.h"
#include "03/code_021cc000.h"
#include "code_0200fc8c.h"
#include "code_0214cfe4.h"

void func_ov003_021cc83c(void) {
    u16 a[12];
    Unk0200fddc b;
    data_ov003_021da258 = 0;
    func_ov003_021cc7b8();
    func_ov003_021bf86c(8);
    func_ov003_021bf5ec(2);
    OS_GetOwnerInfo(&b);
    a[0] = 0;
    MIi_CpuClear16(a[0], &a[1], 0x16);
    MIi_CpuCopy16(b.mUnk_04, &a[1], b.mUnk_18 * 2);
    func_ov003_021bf4f4((u32) &a[1], 0x6d);
    func_ov003_021beef8(0);
    func_ov003_021ce920(func_ov003_021cc4ec);
    func_ov003_021cdc10(0xb);
    func_ov003_021c212c(func_ov003_021cc790);
}

void func_ov003_021cc7b8(void) {
    void *v2 = &data_ov003_021d7780;
    void *v3 = &GX_LoadBG2Char;
    u32 v4 = func_ov003_021bf620(v2, v3);
    void *v5 = &data_ov003_021d7798;
    void *v6 = &GX_LoadBGPltt;
    u32 v7 = func_ov003_021bf620(v5, v6);
    void *v8 = &data_ov003_021d77b0;
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

void func_ov003_021cc790(void) {
    func_ov003_021d1ee0(2, 0, (u32) 0x15, (u16) 8);
    func_ov003_021d2784(0, (u32) 0x15);
    func_ov003_021c212c(func_ov003_021cc76c);
}

void func_ov003_021cc76c(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if (v1 == 0) {
        func_ov003_021bf5c8((u32) 2);
        func_ov003_021c212c(func_ov003_021cc748);
    }
}

void func_ov003_021cc748(void) {
    if (func_ov003_021bf334() != -2) {
        func_ov003_021bf2e0();
        func_ov003_021c212c(func_ov003_021cc730);
    }
}

void func_ov003_021cc730(void) {
    func_ov003_021cc700();
    func_ov003_021cc6fc();
    func_ov003_021cc6c4();
    return;
}

void func_ov003_021cc700(void) {
    int v1;
    v1 = func_ov003_021d2b04(2);
    if (v1 != 0) {
        func_ov003_021bf31c(0);
        return;
    }
    v1 = func_ov003_021cc8b4();
    if (v1 != 0) {
        func_ov003_021bf31c(0);
    }
    return;
}

void func_ov003_021cc6fc(void) {
    return;
}

void func_ov003_021cc6c4(void) {
    int v1;
    if ((data_ov003_021da258 == 0) && (v1 = func_ov003_021bf334(), v1 == 0)) {
        data_ov003_021da258 = 2;
        func_ov003_021cdbd0();
        func_ov003_021cdc10(7);
        func_ov003_021c212c(func_ov003_021cc6a4);
    }
    return;
}

void func_ov003_021cc6a4(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021cc658);
    return;
}

void func_ov003_021cc658(void) {
    if (func_ov003_021d1f70(1) == 0) {
        func_ov003_021bf344();
        if ((u8) (data_ov003_021da258 + 0xfe) <= 1) {
            func_ov003_021d1ee0(3, 1, 1, 8);
        }
        func_ov003_021d1ee0(3, 0, 0x15, 8);
        func_ov003_021c212c(func_ov003_021cc5a8);
    }
}

void func_ov003_021cc5a8(void) {
    if (func_ov003_021d1f70(0) == 0 && (data_ov003_021da258 != 2 || func_ov003_021d1f70(1) == 0) &&
        func_ov003_021bf2f0() != 0) {
        func_ov003_021ce848();
        func_ov003_021beecc();
        func_ov003_021d2168(0);
        if (data_ov003_021da258 == 2 || data_ov003_021da258 == 3) {
            func_ov003_021bf410();
            func_ov003_021d272c(1, 1);
        }
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da258 == 2) {
            func_ov003_021c2120(2, 1);
            func_ov003_021c212c(func_ov003_021cb294);
        } else if (data_ov003_021da258 == 3) {
            func_ov003_021c2120(2, 1);
            func_ov003_021c212c(func_ov003_021cc3d0);
        } else {
            func_ov003_021c2120(0, 0);
            func_ov003_021c212c(func_ov003_021cc110);
        }
    }
}

void func_ov003_021cc4ec(u32 a) {
    if (data_ov003_021da258 == 0) {
        switch (a) {
            case 0:
                data_ov003_021da258 = 3;
                func_ov003_021cdbd0();
                func_ov003_021cdc10(0x12);
                func_ov003_021cefc0(0x45, 1, 1, -1, 0);
                func_ov003_021bf2d0();
                func_ov003_021c212c(func_ov003_021cc4c4);
                break;
            case 1:
                data_ov003_021da258 = 1;
                func_ov003_021cdbd0();
                func_ov003_021c212c(func_ov003_021cc6a4);
                break;
            case 2:
                func_ov003_021cdbd0();
                func_ov003_021ce834(0);
                func_ov003_021cefc0(0x47, 0, 1, -1, 0);
                func_ov003_021bf2d0();
                func_ov003_021c212c(func_ov003_021cc464);
                break;
            case 3:
                data_ov003_021da258 = 2;
                func_ov003_021cdbd0();
                func_ov003_021cdc10(9);
                func_ov003_021c212c(func_ov003_021cc6a4);
                break;
        }
    }
}

void func_ov003_021cc4c4(void) {
    int v1;
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        func_ov003_021cdc10(6);
        func_ov003_021cef90();
        func_ov003_021c212c(func_ov003_021cc4a8);
    }
    return;
}

void func_ov003_021cc4a8(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        func_ov003_021c212c(func_ov003_021cc6a4);
    }
    return;
}

void func_ov003_021cc464(void) {
    switch (func_ov003_021cef80()) {
        case 1:
            data_ov003_021da258 = 3;
            func_ov003_021cdc10(6);
            break;
        case 0:
            data_ov003_021da258 = 1;
            func_ov003_021cdc10(7);
            break;
        default:
            return;
    }
    func_ov003_021cef90();
    func_ov003_021c212c(func_ov003_021cc410);
}

void func_ov003_021cc410(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        if (data_ov003_021da258 == 1) {
            func_ov003_021c212c(func_ov003_021cc6a4);
            return;
        }
        func_ov003_021cdc10(0xb);
        func_ov003_021bf2e0();
        data_ov003_021da258 = 0;
        func_ov003_021ce834((u32) &func_ov003_021cc4ec);
        func_ov003_021c212c(func_ov003_021cc730);
    }
}

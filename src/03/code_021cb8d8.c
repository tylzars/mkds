#include "03/code_021cb8d8.h"
#include "03/code_021cb000.h"
#include "03/code_021d1000.h"
#include "03/code_021c2000.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021d6000.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"

#include "03/code_021d27d8.h"
#include "00/code_02188694.h"
#include "00/code_02188720.h"
#include "03/code_021bf000.h"
#include "03/code_021be610.h"
#include "03/code_021c209c.h"
#include "03/code_021c7844.h"
#include "03/code_021c7cb0.h"
#include "03/code_021cd000.h"
#include "03/code_021ce000.h"
#include "03/code_021d1f70.h"
#include "03/unk_021da000.h"
#include "03/code_021cbc00.h"
#include "03/code_021cd2e0.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021d3488.h"
#include "Main/Unknown/code_0215109c.h"
#include "code_0214d018.h"
#include "code_0200fc8c.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf410.h"
#include "03/code_021bf810.h"
#include "03/code_021bf8c0.h"

void func_ov003_021cbb98(void) {
    s32 a;
    data_ov003_021da248 = 0;
    func_ov003_021cbb14();
    func_ov003_021c20dc(NULL, &a);
    if (a == 0) {
        func_ov003_021bf43c(0x7d, -1, 0);
    }
    func_ov003_021bf5ec(2);
    if (a == 0) {
        func_ov003_021bf854();
    }
    func_ov003_021bf578(0x76);
    func_ov003_021beef8(0);
    func_ov003_021cbaa0();
    func_ov003_021bf9e8(0);
    func_ov003_021cdc10(0xc);
    func_ov003_021c212c(func_ov003_021cba54);
}

void func_ov003_021cbb14(void) {
    void *v2 = &data_ov003_021d76b0;
    void *v3 = &MemCopyWordsToG2Bg2CntBits2To5Address;
    u32 v4 = func_ov003_021bf620(v2, v3);
    void *v5 = &data_ov003_021d76c8;
    void *v6 = &GX_LoadBGPltt;
    u32 v7 = func_ov003_021bf620(v5, v6);
    void *v8 = &data_ov003_021d76e0;
    void *v9 = &MemCopyHalfwordsToG2Bg2CntBits8To12Address;
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

void func_ov003_021cbaa0(void) {
    s32 a;
    Unk02188868 b;
    Unk021cd5e0_400 *c = func_ov003_021cdb6c();
    MemCopyWords(data_ov003_021d6620, &b, 0xc);
    func_ov003_021c20dc(NULL, &a);
    if (a == 2) {
        b.mUnk_0a = 4;
    } else {
        b.mUnk_0a = c->mUnk_f4 + 1;
    }
    if (func_ov000_02188868(&b) == 0) {
        IrqDisableLoopForever();
    }
    if (a == 0) {
        func_ov000_021886fc(c->mUnk_f4, c);
    }
    func_ov003_021d3544(0, func_ov003_021cb8f0, NULL, 0x78);
}

void func_ov003_021cba54(void) {
    int v1[1];
    func_ov003_021d1ee0(2, 0, 0x15, (u16) (8));
    func_ov003_021d2784(0, 0x15);
    func_ov003_021c20dc(NULL, v1);
    if (v1[0] == 0) {
        func_ov003_021d1ee0(2, 1, 1, (u16) (8));
        func_ov003_021d2784(1, 1);
    }
    func_ov003_021c212c(func_ov003_021cba2c);
    return;
}

void func_ov003_021cba2c(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0) {
        func_ov003_021c212c(func_ov003_021cba14);
    }
}

void func_ov003_021cba14(void) {
    func_ov003_021cba10();
    func_ov003_021cba0c();
    func_ov003_021cba08();
    return;
}

void func_ov003_021cba10(void) {
    return;
}

void func_ov003_021cba0c(void) {
    return;
}

void func_ov003_021cba08(void) {
    return;
}

void func_ov003_021cb9e8(void) {
    func_ov003_021d1ee0(3, 0, 0x15, (u16) (8));
    func_ov003_021c212c(func_ov003_021cb9c8);
    return;
}

void func_ov003_021cb9c8(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if (v1 == 0) {
        func_ov003_021c212c(func_ov003_021cb948);
    }
    return;
}

void func_ov003_021cb948(void) {
    u32 a = func_ov003_021cd4dc();
    if (func_ov000_02188720() != 0) {
        MemCopy((const void *) func_0215109c(), (void *) (a + 0xf0), 0xe);
        MemCopy((const void *) func_0215109c(), (void *) (a + 0x1f0), 0xe);
        func_ov003_021beecc();
        func_ov003_021d2168(0);
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da248 == 0) {
            func_ov003_021c2120(0, 1);
            func_ov003_021c212c(func_ov003_021c7d14);
        } else {
            func_ov003_021c2120(0, 1);
            func_ov003_021c212c(func_ov003_021cbdbc);
        }
    }
}

void func_ov003_021cb8f0(u32 b) {
    s32 a = func_ov000_021887cc();
    if (a != 0) {
        func_ov003_021bf9b8();
        func_ov003_021cdbd0();
        if (a > 0) {
            data_ov003_021da248 = 1;
            func_ov003_021cdc10(0x11);
        } else {
            func_ov003_021c7844(func_ov000_02188758());
            func_ov003_021cdc10(0x12);
        }
        func_ov003_021c212c(func_ov003_021cb9e8);
        func_ov003_021d34c8(0, b);
    }
}

u32 func_ov003_021cb8e4(u32 arg0, u32 arg1) {
    u32 value0;
    u32 value1 = arg1;
    u32 value3;
    value0 = (value1) + (0u);
    value1 = 32u;
    value3 = (u32) &func_ov003_021d285c;
    value0 = (u32) func_ov003_021d285c(value0, value1);
    return value0;
}

void func_ov003_021cb8d8(void *unused, void *block) {
    func_ov003_021d27d8(block);
}

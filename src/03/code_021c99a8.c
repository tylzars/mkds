#include "03/code_021bf810.h"
#include "03/code_021c2904.h"
#include "03/code_021c99a8.h"
#include "03/code_021be000.h"
#include "03/code_021bf000.h"
#include "03/code_021bf410.h"
#include "03/code_021c2000.h"
#include "03/code_021c9000.h"
#include "03/code_021c9c90.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cef90.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c209c.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"
#include "03/code_021c9cf4.h"
#include "03/code_021cb000.h"
#include "03/code_021d2940.h"

#include "03/code_021c2938.h"
#include "03/code_021c97c0.h"
#include "03/code_021cd000.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "code_0200db4c.h"

void func_ov003_021c9c5c(void) {
    *(u8 *) &data_ov003_021da218 = 0;
    func_ov003_021c9bf8();
    func_ov003_021bf854();
    func_ov003_021bf578((u32) 0x6a);
    func_ov003_021beef8(1);
    func_ov003_021c212c(func_ov003_021c9bd0);
}

void func_ov003_021c9bf8(void) {
    void *v2 = &data_ov003_021d74fc;
    void *v3 = &MemCopyHalfwordsToG2Bg2CntBits8To12Address;
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

void func_ov003_021c9bd0(void) {
    func_ov003_021d1ee0(2, 0, (u32) 0x15, (u16) 8);
    func_ov003_021d2784(0, (u32) 0x15);
    func_ov003_021c212c(func_ov003_021c9bac);
}

void func_ov003_021c9bac(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if (v1 == 0) {
        func_ov003_021bf5c8((u32) 1);
        func_ov003_021c212c(func_ov003_021c9b88);
    }
}

void func_ov003_021c9b88(void) {
    int v1;
    v1 = func_ov003_021bf334();
    if (v1 != -2) {
        func_ov003_021bf2e0();
        func_ov003_021c212c(func_ov003_021c9b68);
    }
}

void func_ov003_021c9b68(void) {
    func_0200dc3c(0xa);
    func_ov003_021c99a8();
    func_ov003_021c9b38();
    func_ov003_021c9b34();
    func_ov003_021c9b0c();
}

void func_ov003_021c9b38(void) {
    int v1;
    v1 = func_ov003_021d2b04(2);
    if (v1 != 0) {
        func_ov003_021bf31c(0);
        return;
    }
    v1 = func_ov003_021c9c90();
    if (v1 != 0) {
        func_ov003_021bf31c(0);
    }
    return;
}

void func_ov003_021c9b34(void) {
    return;
}

void func_ov003_021c9b0c(void) {
    int v1;
    v1 = func_ov003_021bf334();
    if (v1 == 0) {
        func_ov003_021cdbd0();
        func_ov003_021cdc10(7);
        func_ov003_021c212c(func_ov003_021c9aec);
    }
    return;
}

void func_ov003_021c9aec(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021c9a9c);
    return;
}

void func_ov003_021c9a9c(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        if (data_ov003_021da218 == 0) {
            func_ov003_021bf344();
        }
        if (data_ov003_021da218 == 0) {
            func_ov003_021d1ee0(3, 1, 1, 8);
        }
        func_ov003_021d1ee0(3, 0, 0x15, 8);
        func_ov003_021c212c(func_ov003_021c9a0c);
    }
    return;
}

void func_ov003_021c9a0c(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if ((v1 == 0) && (((data_ov003_021da218 != 0 || (v1 = func_ov003_021d1f70(1), v1 == 0)) &&
                       (v1 = func_ov003_021bf2f0(), v1 != 0)))) {
        func_ov003_021beecc();
        func_ov003_021d2168(0);
        if (data_ov003_021da218 == 0) {
            func_ov003_021bf410();
            func_ov003_021d272c(1, 1);
        }
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da218 == 0) {
            func_ov003_021c29b8();
            func_ov003_021c2120(2, 1);
            func_ov003_021c212c(func_ov003_021cb7fc);
            return;
        }
        func_ov003_021c2120(0, 0);
        func_ov003_021c212c(func_ov003_021c9fd4);
    }
    return;
}

void func_ov003_021c99a8(void) {
    switch (func_ov003_021c2938()) {
        case 2:
            data_ov003_021da218 = 1;
            func_ov003_021c212c(func_ov003_021c9aec);
            break;
        case 4:
            data_ov003_021da218 = 0;
            func_ov003_021cdbd0();
            func_ov003_021cdc10(9);
            func_ov003_021cefc0(0x41, 1, 1, -1, 0);
            func_ov003_021bf2d0();
            func_ov003_021c212c(func_ov003_021c9980);
            break;
    }
}

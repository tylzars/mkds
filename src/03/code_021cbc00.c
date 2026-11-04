#include "03/code_021bf4dc.h"
#include "03/code_021c2c94.h"
#include "03/code_021c7d30.h"
#include "03/code_021cb8d8.h"
#include "03/code_021cbc00.h"
#include "03/code_021bf410.h"
#include "03/code_021c2000.h"
#include "03/code_021c3000.h"
#include "03/code_021c9000.h"
#include "03/code_021cb000.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cdd28.h"
#include "03/code_021ce000.h"
#include "03/code_021cef90.h"
#include "03/code_021d1000.h"
#include "03/code_021bf000.h"
#include "03/code_021cd000.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"

#include "03/unk_021da000.h"
#include "03/code_021c209c.h"
#include "03/code_021c2a74.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021d1f70.h"
#include "03/code_021cea3c.h"

void func_ov003_021cbe44(void) {
    int v1;
    func_ov003_021cbe40();
    func_ov003_021cbe3c();
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        func_ov003_021cdc10((u32) 6);
        func_ov003_021cef90();
        func_ov003_021cdc10((u32) 6);
        func_ov003_021c212c(func_ov003_021cbe14);
    }
}

void func_ov003_021cbe40(void) {
    return;
}

void func_ov003_021cbe3c(void) {
    return;
}

void func_ov003_021cbe14(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        func_ov003_021d1ee0(3, 0, (u32) 0x14, (u16) 8);
        func_ov003_021c212c(func_ov003_021cbde4);
    }
}

void func_ov003_021cbde4(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if (v1 == 0) {
        func_ov003_021d272c(0, (u32) 0x14);
        func_ov003_021c2120((u32) 0, (u32) 1);
        func_ov003_021c212c(func_ov003_021cbb98);
    }
}

void func_ov003_021cbdbc(void) {
    *(u8 *) &data_ov003_021da24c = 0;
    func_ov003_021cbd68();
    func_ov003_021bf578((u32) 0x77);
    func_ov003_021c212c(func_ov003_021cbd40);
}

void func_ov003_021cbd68(void) {
    void *v2 = &data_ov003_021d76f4;
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
    *(u16 *) ((v5) + (0)) = (u16) v9;
    v11 = 0x400100au;
    v12 = ((u32) * (u16 *) ((v11) + (0)));
    v13 = ((v12) & ~(0x3u));
    v14 = ((v13) | (0x3u));
    *(u16 *) ((v11) + (0)) = (u16) v14;
    v16 = 0x400000au;
    v17 = ((u32) * (u16 *) ((v16) + (0)));
    v18 = ((v17) & ~(0x3u));
    v19 = ((v18) | (0x3u));
    *(u16 *) ((v16) + (0)) = (u16) v19;
    v21 = 0x400000cu;
    v22 = ((u32) * (u16 *) ((v21) + (0)));
    v23 = ((v22) & ~(0x3u));
    v24 = ((v23) | (0x3u));
    *(u16 *) ((v21) + (0)) = (u16) v24;
}

void func_ov003_021cbd40(void) {
    func_ov003_021d1ee0(2, 0, (u32) 0x15, (u16) 8);
    func_ov003_021d2784(0, (u32) 0x15);
    func_ov003_021c212c(func_ov003_021cbd20);
}

void func_ov003_021cbd20(void) {
    if (func_ov003_021d1f70(0) == 0) {
        func_ov003_021c212c(func_ov003_021cbd0c);
    }
}

void func_ov003_021cbd0c(void) {
    func_ov003_021cbc00();
    func_ov003_021cbd08();
    return;
}

void func_ov003_021cbd08(void) {
    return;
}

void func_ov003_021cbcc8(void) {
    int v1[1];
    func_ov003_021c20dc(NULL, v1);
    if (v1[0] != 0) {
        func_ov003_021ce0c4();
    }
    func_ov003_021d1ee0(3, 1, 1, (u16) (8));
    func_ov003_021d1ee0(3, 0, 0x15, (u16) (8));
    func_ov003_021c212c(func_ov003_021cbc50);
    return;
}

void func_ov003_021cbc50(void) {
    int v1;
    int v2[1];
    v1 = func_ov003_021d1f70(1);
    if (((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) && (v1 = func_ov003_021cdd28(), v1 != 0)) {
        func_ov003_021d2168(0);
        func_ov003_021bf410();
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x15);
        func_ov003_021c2120(2, 1);
        func_ov003_021c20dc(NULL, v2);
        if (v2[0] == 0) {
            func_ov003_021c20f8(0, 0);
            func_ov003_021c212c(func_ov003_021c965c);
            return;
        }
        func_ov003_021c212c(func_ov003_021c3078);
    }
    return;
}

void func_ov003_021cbc00(void) {
    s32 a;
    data_ov003_021da24c[0]++;
    if (data_ov003_021da24c[0] >= 0xb4) {
        func_ov003_021c20dc(NULL, &a);
        switch (func_ov003_021c20c0()) {
            case 0:
                break;
            case 1:
                if (a != 0) {
                    func_ov003_021c212c(func_ov003_021c2a74);
                    return;
                }
                break;
        }
        func_ov003_021c212c(func_ov003_021cbcc8);
    }
}

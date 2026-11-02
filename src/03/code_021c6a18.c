#include "03/code_021c6a18.h"
#include "03/code_021bf000.h"
#include "03/code_021bf410.h"
#include "03/code_021c2000.h"
#include "03/code_021c6000.h"
#include "03/code_021c9000.h"
#include "03/code_021cb000.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"
#include "03/code_021cd000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021c0000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021d1440.h"
#include "03/code_021bf810.h"
#include "03/code_021cd4ac.h"
#include "03/code_021d1c18.h"
#include "03/code_021d3254.h"

#include "03/code_021d254c.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2ecc.h"
#include "03/code_021c0ca8.h"
#include "03/code_021c209c.h"
#include "03/code_021c6708.h"
#include "03/code_021c6764.h"
#include "03/code_021ce000.h"
#include "03/unk_021da000.h"

void func_ov003_021c6e38(void) {
    u8 a[2];
    s32 b;
    s32 c;
    a[0] = data_ov003_021d7278[0];
    a[1] = data_ov003_021d7278[1];
    data_ov003_021da1f8 = func_ov003_021d283c(0x2c, 4);
    func_ov003_021c20dc(&b, &c);
    if (b == 0) {
        func_ov003_021cd948((u8 *) data_ov003_021da1f8 + 8);
        data_ov003_021da1f8->mUnk_29 = func_ov003_021d3254((u8 *) data_ov003_021da1f8 + 8, 0x20);
    }
    func_ov003_021c6da4();
    func_ov003_021bf86c(b + 9);
    if (c == 1) {
        func_ov003_021bf43c(0x81, -1, 0);
    } else {
        func_ov003_021bf43c(a[b], -1, 0);
    }
    func_ov003_021bf5ec(2);
    data_ov003_021da1f8->mUnk_00 = func_ov003_021d2288(0, 0);
    data_ov003_021da1f8->mUnk_04 = func_ov003_021d1c18(0, 0x3e);
    data_ov003_021da1f8->mUnk_04->mUnk_04 = (data_ov003_021da1f8->mUnk_04->mUnk_04 & 0xfffff3ff) | 0xc00;
    func_ov003_021c6914();
    func_ov003_021c696c();
    func_ov003_021c212c(func_ov003_021c6d68);
}

void func_ov003_021c6da4(void) {
    void *v2 = &data_ov003_021d72a4;
    void *v3 = &func_0214c090;
    u32 v4 = func_ov003_021bf620(v2, v3);
    void *v5 = &data_ov003_021d72b8;
    void *v6 = &func_0214b95c;
    u32 v7 = func_ov003_021bf620(v5, v6);
    void *v8 = &data_ov003_021d72d0;
    void *v9 = &func_0214c160;
    u32 v10 = func_ov003_021bf620(v8, v9);
    void *v11 = &data_ov003_021d72e8;
    void *v12 = &func_0214bc9c;
    u32 v13 = func_ov003_021bf620(v11, v12);
    u32 v14 = 0x4001008u;
    u32 v15 = ((u32) * (u16 *) ((v14) + (0)));
    u32 v17 = ((v15) & ~(0x3u));
    u32 v18 = ((v17) | (0x3u));
    u32 v20;
    u32 v21;
    u32 v22;
    u32 v23;
    u32 v25;
    u32 v26;
    u32 v27;
    u32 v29;
    u32 v31;
    u32 v32;
    u32 v33;
    u32 v34;
    u32 v36;
    u32 v37;
    u32 v38;
    u32 v39;
    *(u16 *) ((v14) + (0)) = (u16) v18;
    v20 = 0x400100au;
    v21 = ((u32) * (u16 *) ((v20) + (0)));
    v22 = ((v21) & ~(0x3u));
    v23 = ((v22) | (0x3u));
    *(u16 *) ((v20) + (0)) = (u16) v23;
    v25 = 0x4000008u;
    v26 = ((u32) * (u16 *) ((v25) + (0)));
    v27 = ((v26) & ~(0x3u));
    v29 = ((v27) | (0x2u));
    *(u16 *) ((v25) + (0)) = (u16) v29;
    v31 = 0x400000au;
    v32 = ((u32) * (u16 *) ((v31) + (0)));
    v33 = ((v32) & ~(0x3u));
    v34 = ((v33) | (0x3u));
    *(u16 *) ((v31) + (0)) = (u16) v34;
    v36 = 0x400000cu;
    v37 = ((u32) * (u16 *) ((v36) + (0)));
    v38 = ((v37) & ~(0x3u));
    v39 = ((v38) | (0x3u));
    *(u16 *) ((v36) + (0)) = (u16) v39;
}

void func_ov003_021c6d68(void) {
    func_ov003_021d1ee0(2, 1, (u32) 1, (u16) 8);
    func_ov003_021d1ee0(2, 0, (u32) 0x15, (u16) 8);
    func_ov003_021d2784(1, (u32) 1);
    func_ov003_021d2784(0, (u32) 0x15);
    func_ov003_021c212c(func_ov003_021c6d0c);
}

void func_ov003_021c6d0c(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021c0d2c();
        func_ov003_021cdc10((u32) 0x14);
        if (data_ov003_021da1f8->mUnk_29 == 0) {
            func_ov003_021c0cd0((u8) 0);
        }
        if (data_ov003_021da1f8->mUnk_29 == ' ') {
            func_ov003_021c0cbc((u8) 0);
        }
        func_ov003_021c212c(func_ov003_021c6cf0);
    }
}

void func_ov003_021c6cf0(void) {
    if (func_ov003_021c0ce4() != 255) {
        func_ov003_021c212c(func_ov003_021c6cdc);
    }
}

void func_ov003_021c6cdc(void) {
    func_ov003_021c6ba0();
    func_ov003_021c6b9c();
    return;
}

void func_ov003_021c6ba0(void) {
    int a;
    Unk021da1f8 *b;
    a = func_ov003_021c0ce4();
    switch (a) {
        case 0x80:
            b = data_ov003_021da1f8;
            if (b->mUnk_29 != 0) {
                func_ov003_021cdc10(3);
                b = data_ov003_021da1f8;
                b->mUnk_29 = b->mUnk_29 - 1;
                b = data_ov003_021da1f8;
                b->mUnk_08[b->mUnk_29] = 0;
                if (data_ov003_021da1f8->mUnk_29 == 0) {
                    func_ov003_021c0cd0(0);
                }
                func_ov003_021c0cbc(1);
            }
            break;
        case 0x82:
            func_ov003_021cdc10(7);
            data_ov003_021da1f8->mUnk_2a = 0;
            func_ov003_021c212c(func_ov003_021c6b80);
            return;
        case 0x83:
            if (func_ov003_021c6764() != 0) {
                func_ov003_021cdc10(6);
                data_ov003_021da1f8->mUnk_2a = 1;
            } else {
                data_ov003_021da1f8->mUnk_2a = 2;
                func_ov003_021cdc10(9);
            }
            data_ov003_021da1f8->mUnk_04->mUnk_00 = (data_ov003_021da1f8->mUnk_04->mUnk_00 & 0xc1fffcff) | 0x200;
            func_ov003_021c212c(func_ov003_021c6b80);
            return;
        case 0:
            break;
        case 0xe01d:
        default:
            b = data_ov003_021da1f8;
            if (b->mUnk_29 != 0x20) {
                func_ov003_021cdc10(1);
                b = data_ov003_021da1f8;
                b->mUnk_08[b->mUnk_29] = a;
                b = data_ov003_021da1f8;
                b->mUnk_29 = b->mUnk_29 + 1;
                func_ov003_021c0cd0(1);
                if (data_ov003_021da1f8->mUnk_29 == 0x20) {
                    func_ov003_021c0cbc(0);
                }
            }
            break;
    }
    func_ov003_021c696c();
    func_ov003_021c6914();
}

void func_ov003_021c6b9c(void) {
    return;
}

void func_ov003_021c6b80(void) {
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c(func_ov003_021c6b58);
    return;
}

void func_ov003_021c6b58(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021c0cf8();
        func_ov003_021cdc10(0x15);
        func_ov003_021c212c(func_ov003_021c6acc);
    }
    return;
}

void func_ov003_021c6acc(void) {
    s32 a[2] = {0x9b, 0x9c};
    s32 b;
    if (func_ov003_021c0ca8() == 0) {
        if (data_ov003_021da1f8->mUnk_2a == 0) {
            func_ov003_021c212c(func_ov003_021c6a18);
        } else if (data_ov003_021da1f8->mUnk_2a == 2) {
            func_ov003_021cefc0(0x2f, 3, 1, -1, 0);
            func_ov003_021c212c(func_ov003_021c673c);
        } else {
            func_ov003_021c20dc(0, &b);
            func_ov003_021cefc0(a[b], 2, 1, -1, 0);
            func_ov003_021c212c(func_ov003_021c68c8);
        }
    }
}

void func_ov003_021c6a18(void) {
    s32 v1;
    int v2[1];
    func_ov003_021bf410();
    func_ov003_021d2f00((u32 *) (u32) data_ov003_021da1f8->mUnk_04);
    func_ov003_021d2168(0);
    func_ov003_021bf620(&data_ov003_021d728c, &func_0214c090);
    func_ov003_021d272c(1, (u32) 1);
    func_ov003_021d272c(0, (u32) 0x15);
    func_ov003_021c20dc(&v1, v2);
    if (v2[0] == 0) {
        func_ov003_021c2120((u32) 2, (u32) 1);
        func_ov003_021c20f8((u32) 0, (u32) v1);
        func_ov003_021c212c(func_ov003_021c965c);
    } else if (data_ov003_021da1f8->mUnk_2a == 0) {
        func_ov003_021c2120((u32) 0, (u32) 1);
        func_ov003_021c20f8((u32) 1, (u32) 0);
        func_ov003_021c212c(func_ov003_021c6668);
    } else {
        func_ov003_021c2120((u32) 0, (u32) 0);
        func_ov003_021c20f8((u32) 0, (u32) 1);
        func_ov003_021c212c(func_ov003_021cbf60);
    }
    func_ov003_021d2808((int *) &data_ov003_021da1f8);
}

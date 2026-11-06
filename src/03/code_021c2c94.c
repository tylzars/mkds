#include "03/code_021c2c94.h"
#include "03/code_021c2000.h"
#include "03/code_021bf000.h"
#include "03/code_021cb11c.h"
#include "03/code_021ce000.h"

#include "03/code_021bf410.h"
#include "03/code_021d1440.h"
#include "03/code_021bf698.h"
#include "03/code_021c209c.h"
#include "03/code_021c391c.h"
#include "03/code_021cb000.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021c2a74.h"
#include "03/code_021d2940.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf810.h"
#include "code_0214b824.h"
#include "03/code_021cc8d4.h"
#include "03/code_021cdcb8.h"

void func_ov003_021c3078(void) {
    func_ov003_021c2fd4();
    func_ov003_021bf86c(0);
    func_ov003_021bf43c(0x7a, -1, 0);
    func_ov003_021cdcf0(4);
    func_ov003_021bf6c8(data_ov003_021d6328[data_ov003_021da1a0 * 4], data_ov003_021d632c[data_ov003_021da1a0 * 4],
                        data_ov003_021d632a[data_ov003_021da1a0 * 4], data_ov003_021d632e[data_ov003_021da1a0 * 4]);
    func_ov003_021c212c(func_ov003_021c2f98);
}

void func_ov003_021c2fd4(void) {
    Unk021d6fd4 a;
    a = data_ov003_021d6fd4;
    func_ov003_021bf620(data_ov003_021d6fec, GX_LoadBG2Char);
    func_ov003_021bf620(data_ov003_021d7004, GX_LoadBGPltt);
    func_ov003_021bf620(data_ov003_021d701c, GX_LoadBG2Scr);
    data_ov003_021da1a4 = func_ov003_021d14b8(func_ov003_021bf650(a.mUnk_00), NULL, 4);
    *(u16 *) 0x4001008 = (*(u16 *) 0x4001008 & ~3) | 3;
    *(u16 *) 0x400100a = (*(u16 *) 0x400100a & ~3) | 3;
    *(u16 *) 0x400000a = (*(u16 *) 0x400000a & ~3) | 3;
    *(u16 *) 0x400000c = (*(u16 *) 0x400000c & ~3) | 3;
}

void func_ov003_021c2f98(void) {
    func_ov003_021d1ee0(2, 1, 1, (u16) (8));
    func_ov003_021d1ee0(2, 0, 0x14, (u16) (8));
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x14);
    func_ov003_021c212c(func_ov003_021c2f68);
    return;
}

void func_ov003_021c2f68(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021bf5c8(0);
        func_ov003_021c212c(func_ov003_021c2f44);
    }
    return;
}

void func_ov003_021c2f44(void) {
    if (func_ov003_021bf334() != -2) {
        func_ov003_021bf2e0();
        func_ov003_021c212c(func_ov003_021c2f2c);
    }
}

void func_ov003_021c2f2c(void) {
    func_ov003_021c2e40();
    func_ov003_021c2e3c();
    func_ov003_021c2df4();
    return;
}

void func_ov003_021c2e40(void) {
    u32 i;
    for (i = 0; i < 2; i++) {
        if (func_ov003_021d2a34(&data_ov003_021d6318[i]) != 0) {
            func_ov003_021bf31c(1);
            data_ov003_021da1a0 = i;
            func_ov003_021bf6c8(
                data_ov003_021d6328[data_ov003_021da1a0 * 4], data_ov003_021d632c[data_ov003_021da1a0 * 4],
                data_ov003_021d632a[data_ov003_021da1a0 * 4], data_ov003_021d632e[data_ov003_021da1a0 * 4]);
            return;
        }
    }
    if (func_ov003_021d2b04(1) != 0) {
        func_ov003_021bf31c(1);
    } else if (func_ov003_021d2b04(2) != 0) {
        func_ov003_021bf31c(0);
    } else if (func_ov003_021d2ae8(0x40) != 0) {
        func_ov003_021c2cc8(1);
    } else if (func_ov003_021d2ae8(0x80) != 0) {
        func_ov003_021c2cc8(3);
    } else if (func_ov003_021d2ae8(0x20) != 0) {
        func_ov003_021c2cc8(0);
    } else if (func_ov003_021d2ae8(0x10) != 0) {
        func_ov003_021c2cc8(2);
    }
}

void func_ov003_021c2e3c(void) {
    return;
}

void func_ov003_021c2df4(void) {
    switch (func_ov003_021bf334()) {
        case 0:
            func_ov003_021cdc10(7);
            func_ov003_021c212c(func_ov003_021c2a74);
            break;
        case 1:
            func_ov003_021cdc10(6);
            func_ov003_021c2c94();
            func_ov003_021c212c(func_ov003_021c2dd4);
            break;
    }
}

void func_ov003_021c2dd4(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c(func_ov003_021c2d9c);
    return;
}

void func_ov003_021c2d9c(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021d1ee0(3, 1, 1, (u16) (8));
        func_ov003_021d1ee0(3, 0, 0x14, (u16) (8));
        func_ov003_021c212c(func_ov003_021c2d18);
    }
    return;
}

void func_ov003_021c2d18(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0) {
        func_ov003_021bf698();
        func_ov003_021bf410();
        func_ov003_021d1490(data_ov003_021da1a4);
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x14);
        switch (data_ov003_021da1a0) {
            case 0:
                func_ov003_021c2120(1, 0);
                func_ov003_021c212c(func_ov003_021cb294);
                break;
            case 1:
                func_ov003_021c2120(0, 0);
                func_ov003_021c212c(func_ov003_021c3dd4);
                break;
        }
    }
}

void func_ov003_021c2cc8(s32 a) {
    if (a != 1 && a != 3) {
        data_ov003_021da1a0 ^= 1;
        func_ov003_021cdc10(8);
        func_ov003_021bf6c8(data_ov003_021d6328[data_ov003_021da1a0 * 4], data_ov003_021d632c[data_ov003_021da1a0 * 4],
                            data_ov003_021d632a[data_ov003_021da1a0 * 4], data_ov003_021d632e[data_ov003_021da1a0 * 4]);
    }
}

void func_ov003_021c2c94(void) {
    Unk021d6fd0 a;
    u8 b;
    a = data_ov003_021d6fd0;
    b = a.mUnk_00[data_ov003_021da1a0];
    func_ov003_021cc948(data_ov003_021da1a4, b, b);
}

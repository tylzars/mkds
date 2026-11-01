#include "03/code_021cb11c.h"
#include "03/code_021c5458.h"
#include "03/code_021ca504.h"
#include "03/code_021bf2d0.h"
#include "03/code_021bf410.h"
#include "03/code_021bf43c.h"
#include "03/code_021bf5c8.h"
#include "03/code_021bf620.h"
#include "03/code_021bf698.h"
#include "03/code_021bf86c.h"
#include "03/code_021c209c.h"
#include "03/code_021c20f8.h"
#include "03/code_021c2120.h"
#include "03/code_021c5000.h"
#include "03/code_021c7cb0.h"
#include "03/code_021c9000.h"
#include "03/code_021ca000.h"
#include "03/code_021ca9e8.h"
#include "03/code_021cb0b0.h"
#include "03/code_021cb000.h"
#include "03/code_021cc000.h"
#include "03/code_021cd844.h"
#include "03/code_021cdc10.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d27d8.h"
#include "code_0214b824.h"

void func_ov003_021cb11c(void) {
    s32 i;
    u32 a;
    for (i = 0; i < 3; i++) {
        a = func_ov003_021cd844(i);
        if (a == 0xff) {
            a = 3;
        } else {
            data_ov003_021da234->mUnk_10[i] = func_ov003_021d1be4(0, 0x11, 1);
            func_ov003_021d17d4(data_ov003_021da234->mUnk_10[i], -1, data_ov003_021d64f0[i + 3].mUnk_00,
                                data_ov003_021d64f0[i + 3].mUnk_02);
            func_ov003_021d1790(data_ov003_021da234->mUnk_10[i], -1, 3);
        }
        data_ov003_021da234->mUnk_04[i] = func_ov003_021d1be4(0, data_ov003_021d64e4[a], 1);
        func_ov003_021d17d4(data_ov003_021da234->mUnk_04[i], -1, data_ov003_021d64f0[i].mUnk_00,
                            data_ov003_021d64f0[i].mUnk_02);
        func_ov003_021d1790(data_ov003_021da234->mUnk_04[i], -1, 3);
    }
}

void func_ov003_021cb1d8(void) {
    Unk021d75c8 a = data_ov003_021d75c8;
    func_ov003_021bf620(data_ov003_021d75f8, func_0214c090);
    func_ov003_021bf620(data_ov003_021d760c, func_0214b95c);
    func_ov003_021bf620(data_ov003_021d7624, func_0214c160);
    func_ov003_021bf620(data_ov003_021d763c, func_0214bc9c);
    data_ov003_021da234->mUnk_00 = func_ov003_021d14b8(func_ov003_021bf650((u8 *) &a), 0, 4);
    func_ov003_021d2784(1, 0x10);
    *(u16 *) 0x4001008 = (*(u16 *) 0x4001008 & ~3) | 3;
    *(u16 *) 0x400100a = (*(u16 *) 0x400100a & ~3) | 3;
    *(u16 *) 0x400000a = (*(u16 *) 0x400000a & ~3) | 3;
    *(u16 *) 0x400000c = (*(u16 *) 0x400000c & ~3) | 3;
}

void func_ov003_021cb294(void) {
    Unk021da234 *a = func_ov003_021d283c(0x20, 4);
    data_ov003_021da234 = a;
    a->mUnk_1d = 0;
    func_ov003_021cb1d8();
    func_ov003_021bf86c(1);
    func_ov003_021bf43c(0x7b, -1, 0);
    func_ov003_021bf5ec(0);
    func_ov003_021cb11c();
    func_ov003_021caca8();
    func_ov003_021c212c(func_ov003_021cb0e0);
}

void func_ov003_021cb2e0(void) {
    Unk021d7650 a = data_ov003_021d7650;
    func_ov003_021cc948(data_ov003_021da244, a.mUnk_00[data_ov003_021da23c], a.mUnk_00[data_ov003_021da23c]);
}

void func_ov003_021cb320(int param_1) {
    s32 a = data_ov003_021da23c;
    s32 b = data_ov003_021d6580[func_ov003_021c20a8(1)][a][param_1];
    if (b == -1) {
        return;
    }
    if (b == 0) {
        data_ov003_021da238 = a;
    }
    if (b == -2) {
        data_ov003_021da23c = data_ov003_021da238;
    } else {
        data_ov003_021da23c = b;
    }
    func_ov003_021cdc10(8);
    func_ov003_021bf6c8(data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_00,
                        data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_04,
                        data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_02,
                        data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_06);
}

void func_ov003_021cb3d8(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0 && func_ov003_021bf2f0() != 0) {
        func_ov003_021bf698();
        func_ov003_021bf410();
        func_ov003_021d1490(data_ov003_021da244);
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x14);
        if (data_ov003_021da240[0] == 0) {
            func_ov003_021c2120(2, 0);
            func_ov003_021c212c(func_ov003_021cb294);
        } else {
            switch (data_ov003_021da23c) {
                case 0:
                    func_ov003_021c2120(2, 1);
                    func_ov003_021c212c(func_ov003_021ca8e8);
                    break;
                case 1:
                    func_ov003_021c2120(2, 1);
                    func_ov003_021c212c(func_ov003_021c54dc);
                    break;
                case 2:
                    func_ov003_021c2120(2, 1);
                    func_ov003_021c212c(func_ov003_021ca504);
                    break;
                case 3:
                    func_ov003_021c2120(2, 0);
                    func_ov003_021c20f8(0, 0);
                    func_ov003_021c7d30(1);
                    func_ov003_021c212c(func_ov003_021c965c);
                    break;
            }
        }
    }
}

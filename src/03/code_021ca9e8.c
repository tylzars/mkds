#include "03/code_021ca9e8.h"
#include "03/code_021c2120.h"
#include "03/code_021c20f8.h"
#include "03/code_021c3000.h"
#include "03/code_021c7cb0.h"
#include "03/code_021c9000.h"
#include "03/code_021ca9c8.h"
#include "03/code_021bf2d0.h"
#include "03/code_021bf410.h"
#include "03/code_021bf620.h"
#include "03/code_021bf698.h"
#include "03/code_021bf760.h"
#include "03/code_021bf344.h"
#include "03/code_021cb000.h"
#include "03/code_021cc3d0.h"
#include "03/code_021cd4ac.h"
#include "03/code_021cdb14.h"
#include "03/code_021cdc10.h"
#include "03/code_021cdd28.h"
#include "03/code_021ce000.h"
#include "03/code_021cef80.h"
#include "03/code_021d1000.h"
#include "03/code_021d1970.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d27d8.h"
#include "code_0214b824.h"

void func_ov003_021ca9e8(void) {
    s32 a = data_ov003_021da230[0] - 4;
    switch (func_ov003_021cef80()) {
        case 1:
            func_ov003_021cdc10(0xe);
            func_ov003_021cd4ac(a);
            func_ov003_021d1c3c(0, data_ov003_021d64e4[3],
                                (u8 *) func_ov003_021d1974((int) data_ov003_021da234->mUnk_04[a], 0));
            func_ov003_021d17d4(data_ov003_021da234->mUnk_04[a], -1, data_ov003_021d64f0[a].mUnk_00,
                                data_ov003_021d64f0[a].mUnk_02);
            func_ov003_021d1790(data_ov003_021da234->mUnk_04[a], -1, 3);
            func_ov003_021d197c(data_ov003_021da234->mUnk_10[a]);
            data_ov003_021da234->mUnk_10[a] = 0;
            break;
        case 0:
            func_ov003_021cdc10(7);
            func_ov003_021d1c3c(0, 0x11, (u8 *) func_ov003_021d1974((int) data_ov003_021da234->mUnk_10[a], 0));
            func_ov003_021d17d4(data_ov003_021da234->mUnk_10[a], -1, data_ov003_021d64f0[a + 3].mUnk_00,
                                data_ov003_021d64f0[a + 3].mUnk_02);
            func_ov003_021d1790(data_ov003_021da234->mUnk_10[a], -1, 3);
            break;
        default:
            return;
    }
    func_ov003_021cef90();
    func_ov003_021c212c(func_ov003_021ca9c8);
}

void func_ov003_021caae0(void) {
    s32 a = data_ov003_021da230[0] - 4;
    func_ov003_021d1c3c(0, 0x32, (u8 *) func_ov003_021d1974((int) data_ov003_021da234->mUnk_10[a], 0));
    func_ov003_021d17d4(data_ov003_021da234->mUnk_10[a], -1, data_ov003_021d64f0[a + 3].mUnk_00,
                        data_ov003_021d64f0[a + 3].mUnk_02);
    func_ov003_021d1790(data_ov003_021da234->mUnk_10[a], -1, 3);
}

void func_ov003_021cab4c(int param_1) {
    u32 b = 1;
    switch (data_ov003_021da230[0]) {
        case 0:
            data_ov003_021da234->mUnk_1c = 0;
            if (param_1 == 0) {
                data_ov003_021da230[0] = 2;
            } else if (param_1 == 2) {
                data_ov003_021da230[0] = 1;
            } else if (param_1 == 1) {
                data_ov003_021da230[0] = 3;
            } else {
                data_ov003_021da230[0] = 4;
            }
            break;
        case 1:
            data_ov003_021da234->mUnk_1c = 1;
            if (param_1 == 0) {
                data_ov003_021da230[0] = 0;
            } else if (param_1 == 2) {
                data_ov003_021da230[0] = 2;
            } else if (param_1 == 1) {
                data_ov003_021da230[0] = 3;
            } else {
                data_ov003_021da230[0] = 5;
            }
            break;
        case 2:
            data_ov003_021da234->mUnk_1c = 2;
            if (param_1 == 0) {
                data_ov003_021da230[0] = 1;
            } else if (param_1 == 2) {
                data_ov003_021da230[0] = 0;
            } else if (param_1 == 1) {
                data_ov003_021da230[0] = 3;
            } else {
                data_ov003_021da230[0] = 6;
            }
            break;
        case 3: {
            u8 c = data_ov003_021da234->mUnk_1c;
            s32 d = c + 4;
            if (param_1 == 1) {
                data_ov003_021da230[0] = d;
            } else if (param_1 == 3) {
                data_ov003_021da230[0] = c;
            } else {
                b = 0;
            }
            break;
        }
        case 4:
            data_ov003_021da234->mUnk_1c = 0;
            if (param_1 == 0) {
                data_ov003_021da230[0] = 6;
            } else if (param_1 == 2) {
                data_ov003_021da230[0] = 5;
            } else if (param_1 == 1) {
                data_ov003_021da230[0] = 0;
            } else {
                data_ov003_021da230[0] = 3;
            }
            break;
        case 5:
            data_ov003_021da234->mUnk_1c = 1;
            if (param_1 == 0) {
                data_ov003_021da230[0] = 4;
            } else if (param_1 == 2) {
                data_ov003_021da230[0] = 6;
            } else if (param_1 == 1) {
                data_ov003_021da230[0] = 1;
            } else {
                data_ov003_021da230[0] = 3;
            }
            break;
        case 6:
            data_ov003_021da234->mUnk_1c = 2;
            if (param_1 == 0) {
                data_ov003_021da230[0] = 5;
            } else if (param_1 == 2) {
                data_ov003_021da230[0] = 4;
            } else if (param_1 == 1) {
                data_ov003_021da230[0] = 2;
            } else {
                data_ov003_021da230[0] = 3;
            }
            break;
    }
    if (b != 0) {
        func_ov003_021cdc10(8);
        func_ov003_021caca8();
    }
}

void func_ov003_021caca8(void) {
    u8 a = data_ov003_021da230[0];
    if (a < 4) {
        func_ov003_021bf6c8(data_ov003_021d6540[a].mUnk_00, data_ov003_021d6540[a].mUnk_04,
                            data_ov003_021d6540[a].mUnk_02, data_ov003_021d6540[a].mUnk_06);
    } else {
        func_ov003_021bf760(0, data_ov003_021d6540[a].mUnk_00, data_ov003_021d6540[a].mUnk_04,
                            data_ov003_021d6540[a].mUnk_02);
    }
}

void func_ov003_021cacfc(void) {
    u32 i;
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0 && func_ov003_021cdd28() != 0 &&
        func_ov003_021bf2f0() != 0) {
        for (i = 0; i < 3; i++) {
            if (data_ov003_021da234->mUnk_04[i] != 0) {
                func_ov003_021d197c(data_ov003_021da234->mUnk_04[i]);
            }
        }
        for (i = 0; i < 3; i++) {
            if (data_ov003_021da234->mUnk_10[i] != 0) {
                func_ov003_021d197c(data_ov003_021da234->mUnk_10[i]);
            }
        }
        func_ov003_021bf698();
        func_ov003_021bf410();
        func_ov003_021d1490(data_ov003_021da234->mUnk_00);
        func_ov003_021bf620((u32) data_ov003_021d75e0, (u32) func_0214c090);
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x14);
        if (data_ov003_021da234->mUnk_1d == 2) {
            func_ov003_021c2120(0, 0);
            func_ov003_021c212c(func_ov003_021c3078);
        } else {
            switch (data_ov003_021da230[0]) {
                case 0:
                case 1:
                case 2:
                    func_ov003_021c2120(2, 0);
                    if (*(u8 *) (func_ov003_021cdb6c() + 0xe7) == 0xff) {
                        func_ov003_021c212c(func_ov003_021cb7fc);
                    } else {
                        func_ov003_021c20f8(0, 0);
                        func_ov003_021c7d30(0);
                        func_ov003_021c212c(func_ov003_021c965c);
                    }
                    break;
                case 3:
                    func_ov003_021c2120(2, 1);
                    func_ov003_021c212c(func_ov003_021cc3d0);
                    break;
            }
        }
        func_ov003_021d2808(&data_ov003_021da234);
    }
}

void func_ov003_021cae28(void) {
    if (func_ov003_021d1f70(1) == 0) {
        if (data_ov003_021da234->mUnk_1d == 1) {
            if (data_ov003_021da230[0] == 3 || *(u8 *) (func_ov003_021cdb6c() + 0xe7) != 0xff) {
                func_ov003_021bf344();
            }
        }
        func_ov003_021d1ee0(3, 1, 1, 8);
        func_ov003_021d1ee0(3, 0, 0x14, 8);
        func_ov003_021c212c(func_ov003_021cacfc);
    }
}

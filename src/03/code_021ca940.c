#include "03/code_021ca940.h"
#include "03/code_021c2c94.h"
#include "03/code_021c7d30.h"
#include "03/code_021bf000.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cdd28.h"
#include "03/code_021cef90.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/code_021d1c18.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"
#include "03/code_021c2000.h"

#include "03/unk_021d7000.h"
#include "code_0200d118.h"
#include "03/code_021cd2e0.h"
#include "03/code_021cea3c.h"
#include "03/code_021c209c.h"
#include "03/code_021c3000.h"
#include "03/code_021c9000.h"
#include "03/code_021bf098.h"
#include "03/code_021bf410.h"
#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf698.h"
#include "03/code_021cb000.h"
#include "03/code_021cc144.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021ce000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1970.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d27d8.h"
#include "code_0214b824.h"
#include "03/code_021c2a74.h"
#include "03/code_021ca000.h"
#include "03/code_021cd000.h"
#include "03/unk_021d6000.h"
#include "03/code_021cc8d4.h"

void func_ov003_021cb0e0(void) {
    func_ov003_021d1ee0(2, 1, 1, (u16) (8));
    func_ov003_021d1ee0(2, 0, 0x14, (u16) (8));
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x14);
    func_ov003_021c212c(func_ov003_021cb0b0);
    return;
}

void func_ov003_021cb0b0(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021bf5c8(0);
        func_ov003_021c212c(func_ov003_021cb084);
    }
    return;
}

void func_ov003_021cb084(void) {
    if (func_ov003_021bf334() != -2 && func_ov003_021ce00c() != 1) {
        func_ov003_021bf2e0();
        func_ov003_021c212c(func_ov003_021cb06c);
    }
}

void func_ov003_021cb06c(void) {
    func_ov003_021cafa4();
    func_ov003_021cafa0();
    func_ov003_021caeb8();
    return;
}

void func_ov003_021cafa4(void) {
    int v1;
    u32 v2;
    int v3;
    u8 *v4;
    v2 = 0;
    v4 = data_ov003_021d6508;
    do {
        v1 = func_ov003_021d2a34((const Unk021d299c *) v4);
        if (v1 != 0) {
            func_ov003_021bf31c((u8) (1));
            *(u8 *) &data_ov003_021da230 = (s8) v2;
            func_ov003_021caca8();
            return;
        }
        v4 = v4 + 8;
        v2 = v2 + 1;
    } while (v2 < 7);
    v3 = func_ov003_021d2b04(1);
    if (v3 != 0) {
        func_ov003_021bf31c((u8) (1));
        return;
    }
    v3 = func_ov003_021d2b04(2);
    if (v3 != 0) {
        func_ov003_021bf31c((u8) (0));
        return;
    }
    v3 = func_ov003_021d2ae8(0x40);
    if (v3 != 0) {
        func_ov003_021cab4c(1);
        return;
    }
    v3 = func_ov003_021d2ae8(0x80);
    if (v3 != 0) {
        func_ov003_021cab4c(3);
        return;
    }
    v3 = func_ov003_021d2ae8(0x20);
    if (v3 != 0) {
        func_ov003_021cab4c(0);
        return;
    }
    v3 = func_ov003_021d2ae8(0x10);
    if (v3 != 0) {
        func_ov003_021cab4c(2);
    }
    return;
}

void func_ov003_021cafa0(void) {
    return;
}

void func_ov003_021caeb8(void) {
    s32 a;
    u8 s;
    switch (func_ov003_021bf334()) {
        case 0:
            switch (func_ov003_021c20c0()) {
                case 0:
                    func_ov003_021cdc10(7);
                    data_ov003_021da234->mUnk_1d = 2;
                    break;
                case 1:
                    func_ov003_021bf2d0();
                    func_ov003_021c212c(func_ov003_021c2a74);
                    return;
            }
            break;
        case 1:
            data_ov003_021da234->mUnk_1d = 1;
            s = data_ov003_021da230[0];
            if (s >= 4) {
                a = s - 4;
                if (func_ov003_021cd844(a) == 0xff) {
                    func_ov003_021cdc10(9);
                    func_ov003_021bf310(-1);
                    return;
                }
                func_ov003_021cdc10(6);
                func_ov003_021cefc0(0x98, 0, 1, data_ov003_021d64e8[func_ov003_021c20d0()], a + 1);
                func_ov003_021caae0();
                func_ov003_021bf2d0();
                func_ov003_021c212c(func_ov003_021ca9e8);
                return;
            }
            if (s <= 2) {
                func_ov003_021cd790(s);
            }
            func_ov003_021cdc10(6);
            func_ov003_021ca940();
            break;
        default:
            return;
    }
    func_ov003_021c212c(func_ov003_021cae88);
}

void func_ov003_021cae88(void) {
    if (data_ov003_021da234->mUnk_1d == 2) {
        func_ov003_021ce0c4();
    }
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) 8);
    func_ov003_021c212c(func_ov003_021cae28);
}

void func_ov003_021cae28(void) {
    if (func_ov003_021d1f70(1) == 0) {
        if (data_ov003_021da234->mUnk_1d == 1) {
            if (data_ov003_021da230[0] == 3 || func_ov003_021cdb6c()->mUnk_00.mUnk_e7 != 0xff) {
                func_ov003_021bf344();
            }
        }
        func_ov003_021d1ee0(3, 1, 1, 8);
        func_ov003_021d1ee0(3, 0, 0x14, 8);
        func_ov003_021c212c(func_ov003_021cacfc);
    }
}

void func_ov003_021cacfc(void) {
    u32 i;
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0 && func_ov003_021cdd28() != 0 &&
        func_ov003_021bf2f0() != 0) {
        for (i = 0; i < 3; i++) {
            if (data_ov003_021da234->mUnk_04[i] != NULL) {
                func_ov003_021d197c(data_ov003_021da234->mUnk_04[i]);
            }
        }
        for (i = 0; i < 3; i++) {
            if (data_ov003_021da234->mUnk_10[i] != NULL) {
                func_ov003_021d197c(data_ov003_021da234->mUnk_10[i]);
            }
        }
        func_ov003_021bf698();
        func_ov003_021bf410();
        func_ov003_021d1490(data_ov003_021da234->mUnk_00);
        func_ov003_021bf620(data_ov003_021d75e0, GX_LoadOBJPltt);
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
                    if (func_ov003_021cdb6c()->mUnk_00.mUnk_e7 == 0xff) {
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

void func_ov003_021cab4c(int a) {
    u32 b = 1;
    switch (data_ov003_021da230[0]) {
        case 0:
            data_ov003_021da234->mUnk_1c = 0;
            if (a == 0) {
                data_ov003_021da230[0] = 2;
            } else if (a == 2) {
                data_ov003_021da230[0] = 1;
            } else if (a == 1) {
                data_ov003_021da230[0] = 3;
            } else {
                data_ov003_021da230[0] = 4;
            }
            break;
        case 1:
            data_ov003_021da234->mUnk_1c = 1;
            if (a == 0) {
                data_ov003_021da230[0] = 0;
            } else if (a == 2) {
                data_ov003_021da230[0] = 2;
            } else if (a == 1) {
                data_ov003_021da230[0] = 3;
            } else {
                data_ov003_021da230[0] = 5;
            }
            break;
        case 2:
            data_ov003_021da234->mUnk_1c = 2;
            if (a == 0) {
                data_ov003_021da230[0] = 1;
            } else if (a == 2) {
                data_ov003_021da230[0] = 0;
            } else if (a == 1) {
                data_ov003_021da230[0] = 3;
            } else {
                data_ov003_021da230[0] = 6;
            }
            break;
        case 3: {
            u8 c = data_ov003_021da234->mUnk_1c;
            s32 d = c + 4;
            if (a == 1) {
                data_ov003_021da230[0] = d;
            } else if (a == 3) {
                data_ov003_021da230[0] = c;
            } else {
                b = 0;
            }
            break;
        }
        case 4:
            data_ov003_021da234->mUnk_1c = 0;
            if (a == 0) {
                data_ov003_021da230[0] = 6;
            } else if (a == 2) {
                data_ov003_021da230[0] = 5;
            } else if (a == 1) {
                data_ov003_021da230[0] = 0;
            } else {
                data_ov003_021da230[0] = 3;
            }
            break;
        case 5:
            data_ov003_021da234->mUnk_1c = 1;
            if (a == 0) {
                data_ov003_021da230[0] = 4;
            } else if (a == 2) {
                data_ov003_021da230[0] = 6;
            } else if (a == 1) {
                data_ov003_021da230[0] = 1;
            } else {
                data_ov003_021da230[0] = 3;
            }
            break;
        case 6:
            data_ov003_021da234->mUnk_1c = 2;
            if (a == 0) {
                data_ov003_021da230[0] = 5;
            } else if (a == 2) {
                data_ov003_021da230[0] = 4;
            } else if (a == 1) {
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

void func_ov003_021caae0(void) {
    s32 a = data_ov003_021da230[0] - 4;
    func_ov003_021d1c3c(0, 0x32, func_ov003_021d1974(data_ov003_021da234->mUnk_10[a], 0));
    func_ov003_021d17d4(data_ov003_021da234->mUnk_10[a], -1, data_ov003_021d64f0[a + 3].mUnk_00,
                        data_ov003_021d64f0[a + 3].mUnk_02);
    func_ov003_021d1790(data_ov003_021da234->mUnk_10[a], -1, 3);
}

void func_ov003_021ca9e8(void) {
    s32 a = data_ov003_021da230[0] - 4;
    switch (func_ov003_021cef80()) {
        case 1:
            func_ov003_021cdc10(0xe);
            func_ov003_021cd4ac(a);
            func_ov003_021d1c3c(0, data_ov003_021d64e4[3], func_ov003_021d1974(data_ov003_021da234->mUnk_04[a], 0));
            func_ov003_021d17d4(data_ov003_021da234->mUnk_04[a], -1, data_ov003_021d64f0[a].mUnk_00,
                                data_ov003_021d64f0[a].mUnk_02);
            func_ov003_021d1790(data_ov003_021da234->mUnk_04[a], -1, 3);
            func_ov003_021d197c(data_ov003_021da234->mUnk_10[a]);
            data_ov003_021da234->mUnk_10[a] = NULL;
            break;
        case 0:
            func_ov003_021cdc10(7);
            func_ov003_021d1c3c(0, 0x11, func_ov003_021d1974(data_ov003_021da234->mUnk_10[a], 0));
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

void func_ov003_021ca9c8(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        func_ov003_021bf2e0();
        func_ov003_021c212c(func_ov003_021cb06c);
    }
    return;
}

void func_ov003_021ca940(void) {
    Unk021d6974 a;
    Unk021d6974 b;
    int c;
    a = data_ov003_021d75c0;
    b = data_ov003_021d75c4;
    if (*(u8 *) &data_ov003_021da230 <= 3) {
        func_ov003_021cc948(data_ov003_021da234->mUnk_00, a.mUnk_00[*(u8 *) &data_ov003_021da230],
                            a.mUnk_00[*(u8 *) &data_ov003_021da230]);
        if (*(u8 *) &data_ov003_021da230 != 3) {
            c = func_ov003_021cd844(*(u8 *) &data_ov003_021da230);
            if (c > 2) {
                c = 3;
            }
            func_ov003_021d1890(data_ov003_021da234->mUnk_04[*(u8 *) &data_ov003_021da230], -1, 0, b.mUnk_00[c]);
        }
    }
}

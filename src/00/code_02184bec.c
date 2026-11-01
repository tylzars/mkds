#include "00/code_02184bec.h"
#include "00/code_021806a0.h"
#include "00/code_021806e0.h"
#include "00/code_021804f4.h"
#include "00/code_ov000_021804e0.h"
#include "00/code_02185164.h"
#include "00/code_021850b0.h"
#include "00/code_021850d0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_0212630c.h"
#include "Main/Unknown/code_02126570.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_0201ea58.h"

void func_ov000_02184bec(void) {
    Unk021b4c84 *p;

    data_ov000_021b4c84->mUnk_00 = data_ov000_021b4c84->mUnk_04;
    switch (data_ov000_021b4c84->mUnk_00) {
        case 0:
            func_ov000_02185164();
            break;
        case 1:
            func_ov000_021850d0();
            break;
        case 2:
            func_ov000_021850b0();
            break;
        case 3:
            func_ov000_02184f1c();
            break;
        case 4:
            func_ov000_02184ed4();
            break;
        case 5:
            func_ov000_02184dbc();
            break;
        case 6:
            func_ov000_02184d4c();
            break;
        case 7:
            func_ov000_02184ce0();
            break;
    }
    func_ov000_02184c74();
    p = data_ov000_021b4c84;
    func_02124c30(p->mUnk_2c, p->mUnk_20, 0, func_ov000_021804e0(), p->mUnk_1c);
}

void func_ov000_02184c74(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        if (i == data_ov000_021b4c84->mUnk_08 && data_ov000_021b4c84->mUnk_14 != 0) {
            data_ov000_021b4c84->mUnk_1c[data_ov000_021b06c4[i]].mUnk_00 = 1;
            func_02124a20(data_ov000_021b06bc[i], 0xe, data_ov000_021b4c84->mUnk_20, data_ov000_021b4c84->mUnk_2c);
        } else {
            data_ov000_021b4c84->mUnk_1c[data_ov000_021b06c4[i]].mUnk_00 = 0;
            func_02124a20(data_ov000_021b06bc[i], 0xf, data_ov000_021b4c84->mUnk_20, data_ov000_021b4c84->mUnk_2c);
        }
    }
}

void func_ov000_02184ce0(void) {
    if (func_02125f88() != 0) {
        if (func_02125f60() == 0) {
            data_ov000_021b4c84->mUnk_10 = 0xe;
            if (func_ov000_021806c4() == -1) {
                func_ov000_021806b8(8);
            }
            data_0217b488->mUnk_50 = 1;
            return;
        }
        data_ov000_021b4c84->mUnk_04 = 1;
        data_ov000_021b4c84->mUnk_10 = -1;
        return;
    }
    if (func_02125f54() != 0) {
        func_02125fc0();
    }
}

void func_ov000_02184d4c(void) {
    void *a;
    void *b;

    if (func_02125f88() != 0 && func_02128274() != 0) {
        data_ov000_021b4c84->mUnk_04 = 7;
        a = func_020b3f7c(data_ov000_021b4c84->mUnk_38, 0x10);
        b = func_020b3f7c(data_ov000_021b4c84->mUnk_3c, 0);
        func_02126454(a, b, func_020b3f7c(data_ov000_021b4c84->mUnk_3c, 1), 0);
        return;
    }
    if (func_02125f54() != 0) {
        func_02125fc0();
    }
}

void func_ov000_02184dbc(void) {
    s32 a;
    s32 i;
    s32 j;
    s32 b;
    void *c;

    if (func_ov000_021806c4() == -1 && func_ov000_02185184() == 0 && data_ov000_021b4c84->mUnk_10 == 11) {
        func_ov000_021806b8(0xe);
    }
    data_ov000_021b4c84->mUnk_0c = data_ov000_021b4c84->mUnk_0c + 1;
    if (data_ov000_021b4c84->mUnk_0c <= 10) {
        a = func_020ae4c0(1, 0, 0xfa, data_ov000_021b4c84->mUnk_0c, 10);
    } else {
        a = 0xfa;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov000_021b06c8[i]; j++) {
            if (i == 1) {
                data_ov000_021b4c84->mUnk_1c[data_ov000_021b06d0[i][j]].mUnk_04 = a;
            } else {
                data_ov000_021b4c84->mUnk_1c[data_ov000_021b06d0[i][j]].mUnk_04 = -a;
            }
        }
    }
    if (data_ov000_021b4c84->mUnk_0c >= 10) {
        if (func_ov000_02185184() != 0 && data_ov000_021b4c84->mUnk_10 == 11) {
            data_ov000_021b4c84->mUnk_04 = 6;
            data_ov000_021b4c84->mUnk_10 = -1;
            c = func_020b3f7c(data_ov000_021b4c84->mUnk_38, 0xf);
            func_02126570(c, func_020b3f7c(data_ov000_021b4c84->mUnk_3c, 6));
            data_ov000_021b4c84->mUnk_0c = 0;
            return;
        }
        if (func_ov000_021806c4() == -1) {
            func_ov000_021806e0(data_ov000_021b4c84->mUnk_10);
        }
    }
}

void func_ov000_02184ed4(void) {
    data_ov000_021b4c84->mUnk_0c = data_ov000_021b4c84->mUnk_0c + 1;
    if (data_ov000_021b4c84->mUnk_0c >= 10) {
        data_ov000_021b4c84->mUnk_04 = 5;
        if (data_ov000_021b4c84->mUnk_10 == 11) {
            func_021282c8();
        }
        data_ov000_021b4c84->mUnk_0c = 0;
    } else if (data_ov000_021b4c84->mUnk_0c >= 5) {
        data_ov000_021b4c84->mUnk_14 = 1;
    }
}

void func_ov000_02184f1c(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    u32 a = -1;
    s32 b;
    s32 c;
    u16 d;
    s32 f;
    u32 e;
    Unk021b4c84 *p;

    b = 0;
    c = 0;
    d = data_02175628[i].mUnk_4c;
    if (d == 0 && data_02175628[i].mUnk_58 < 5) {
        c = 1;
    }
    if (c == 0 && data_02175628[i].mUnk_54 == 0 && d != 0) {
        b = 1;
    }
    if (b != 0) {
        a = func_0201ea84(data_ov000_021b4c84->mUnk_30, data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a);
    }
    if ((u16) (data_02175628[i].mUnk_00 & 2) == 0) {
        b = 0;
        c = 0;
        d = data_02175628[i].mUnk_4c;
        if (d == 0 && data_02175628[i].mUnk_58 < 5) {
            c = 1;
        }
        if (c == 0 && data_02175628[i].mUnk_54 == 0 && d != 0) {
            b = 1;
        }
        if (b == 0 || func_02128210(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
            goto next;
        }
    }
    data_ov000_021b4c84->mUnk_04 = 5;
    data_ov000_021b4c84->mUnk_10 = 1;
    func_02128310(0);
    return;
next:
    e = data_02175628[i].mUnk_00 & 1;
    if ((u16) e != 0 || a <= 1) {
        p = data_ov000_021b4c84;
        f = p->mUnk_08;
        if ((u16) e == 0) {
            switch (a) {
                case 0:
                    p->mUnk_08 = 0;
                    break;
                case 1:
                    p->mUnk_08 = 1;
                    break;
            }
        }
        data_ov000_021b4c84->mUnk_04 = 4;
        switch (data_ov000_021b4c84->mUnk_08) {
            case 0:
                data_ov000_021b4c84->mUnk_10 = 11;
                break;
            case 1:
                data_ov000_021b4c84->mUnk_10 = 9;
                break;
        }
        if (data_ov000_021b4c84->mUnk_08 == f) {
            data_ov000_021b4c84->mUnk_14 = 0;
        }
        func_02105ac0(5);
        return;
    }
    if (func_020ae408(8, 0x40) != 0 && data_ov000_021b4c84->mUnk_08 > 0) {
        data_ov000_021b4c84->mUnk_08 = data_ov000_021b4c84->mUnk_08 - 1;
        func_02105ac0(0);
        return;
    }
    if (func_020ae408(8, 0x80) != 0 && data_ov000_021b4c84->mUnk_08 < 1) {
        data_ov000_021b4c84->mUnk_08 = data_ov000_021b4c84->mUnk_08 + 1;
        func_02105ac0(0);
    }
}

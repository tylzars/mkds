#include "00/code_02184ba8.h"
#include "Main/Unknown/code_0214a000.h"
#include "00/unk_021b0000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "code_0214b824.h"

#include "00/code_02180608.h"
#include "00/unk_021b4000.h"
#include "00/code_ov000_021804e0.h"
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
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/code_020472a8.h"

void func_ov000_0218523c(void *a) {
    s32 i;
    s32 j;
    u32 b;
    void *c;

    data_ov000_021b4c84 = func_02036bec(a, 0x40);
    data_ov000_021b4c84->mUnk_18 = a;
    data_ov000_021b4c84->mUnk_00 = 0;
    data_ov000_021b4c84->mUnk_04 = 0;
    data_ov000_021b4c84->mUnk_10 = -1;
    b = func_ov000_021806d4();
    switch (b) {
        case 1:
        case 11:
            data_ov000_021b4c84->mUnk_08 = 0;
            break;
        case 9:
            data_ov000_021b4c84->mUnk_08 = 1;
            break;
    }
    data_ov000_021b4c84->mUnk_0c = 0;
    data_ov000_021b4c84->mUnk_14 = 1;
    func_ov000_021851a0();
    for (i = 0; i < 2; i++) {
        func_02124a98(data_ov000_021b06c0[i], 1, data_ov000_021b4c84->mUnk_20, data_ov000_021b4c84->mUnk_2c);
    }
    c = func_ov000_021804f4();
    func_020ae6d4(c, func_ov000_021804e0());
    func_02124ed0(a, data_ov000_021b4c84->mUnk_2c, 0, &data_ov000_021b4c84->mUnk_1c);
    data_ov000_021b4c84->mUnk_38 = FindSceneFile(data_ov000_021b0ee8);
    data_ov000_021b4c84->mUnk_3c = func_02047a28(data_ov000_021b0ef4);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov000_021b06c8[i]; j++) {
            data_ov000_021b4c84->mUnk_1c[data_ov000_021b06d0[i][j]].mUnk_04 = 0xfa;
        }
    }
    func_021281c8(0xe);
}

void func_ov000_02185230(void) {
    data_ov000_021b4c84 = 0;
}

void func_ov000_021851a0(void) {
    void *v1;
    v1 = FindSceneFile((const char *) &data_ov000_021b0e70);
    data_ov000_021b4c84->mUnk_2c = v1;
    v1 = FindSceneFile((const char *) &data_ov000_021b0e84);
    data_ov000_021b4c84->mUnk_30 = v1;
    v1 = FindSceneFile((const char *) &data_ov000_021b0e98);
    func_020b49bc(&data_ov000_021b4c84->mUnk_24, v1);
    v1 = FindSceneFile((const char *) &data_ov000_021b0eb4);
    func_020b48b4(&data_ov000_021b4c84->mUnk_20, v1);
    v1 = FindSceneFile((const char *) &data_ov000_021b0ed0);
    func_020b4a44(&data_ov000_021b4c84->mUnk_28, v1);
    func_0214bea4((const void *) data_ov000_021b4c84->mUnk_24->mUnk_14, 0,
                  (u32) (data_ov000_021b4c84->mUnk_24->mUnk_10));
    func_0214c028((const void *) data_ov000_021b4c84->mUnk_28->mUnk_0c, 0,
                  (u32) (data_ov000_021b4c84->mUnk_28->mUnk_08));
    return;
}

u32 func_ov000_02185184(void) {
    u32 v1;
    v1 = func_0205e548();
    if (60 <= v1) {
        return 1;
    }
    return 0;
}

void func_ov000_02185164(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        data_ov000_021b4c84->mUnk_04 = 1;
    }
    return;
}

void func_ov000_021850d0(void) {
    s32 a;
    s32 i;
    s32 j;

    data_ov000_021b4c84->mUnk_0c = data_ov000_021b4c84->mUnk_0c + 1;
    a = func_020ae4c0(1, 0xfa, 0, data_ov000_021b4c84->mUnk_0c, 10);
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
        data_ov000_021b4c84->mUnk_04 = 2;
        data_ov000_021b4c84->mUnk_0c = 0;
        func_02128374();
    }
}

void func_ov000_021850b0(void) {
    int v1;
    v1 = func_02128294();
    if (v1 != 0) {
        data_ov000_021b4c84->mUnk_04 = 3;
    }
    return;
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

void func_ov000_02184bcc(void) {
    func_0214a40c((u32 *) ((u32 *) (u32) (((u32) 0x04001050u))), (u32) (0), 2, (u32) (6), 10);
    return;
}

void func_ov000_02184ba8(void) {
    Unk021b0cd4 callbacks = data_ov000_021b0e60;
    func_ov000_021806ec(&callbacks);
}

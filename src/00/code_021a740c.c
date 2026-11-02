#include "00/code_021a740c.h"
#include "00/code_021a8000.h"
#include "00/code_021a6fb4.h"
#include "00/code_021a7000.h"
#include "00/unk_021b6000.h"
#include "00/code_021a8aa8.h"
#include "00/code_021ae100.h"
#include "00/code_021ae134.h"
#include "00/code_021ae1e4.h"
#include "00/code_021ae258.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "code_0200e77c.h"
#include "00/code_021a73d8.h"

s32 func_ov000_021a740c(Unk021a7064 *param_1) {
    Unk021a6fa8 *a;
    Unk021a71c0 *b;
    u16 c;
    u32 d;
    u32 e;

    a = param_1->mUnk_04;
    b = a->mUnk_64;
    func_0200ed34(&b->mUnk_00.mUnk_e0);
    func_ov000_021ae290(param_1->mUnk_10, 0, 0);
    func_ov000_021ae1e4();
    b->mUnk_f8 = 0;
    e = func_ov000_021ae100(&c, &d);
    *param_1->mUnk_14 = c;
    *param_1->mUnk_18 = e;
    a->mUnk_70 |= 4;
    func_0200ecc4(&b->mUnk_00.mUnk_e0);
    return 0;
}

s32 func_ov000_021a7468(Unk021a6fa8 *param_1, u16 *param_2, u32 *param_3) {
    Unk021a7064 *a;
    s32 b;
    s32 c;

    if (func_ov000_021a8a80(param_1) != 0) {
        return -28;
    }
    b = 0;
    if (param_1 != 0) {
        b = (param_1->mUnk_70 & 1) != 0;
    }
    if (b == 0) {
        return -39;
    }
    if (param_1->mUnk_70 & 2) {
        return -28;
    }
    b = 1;
    if (param_1->mUnk_73 != 0 && param_1->mUnk_73 != 4) {
        b = 0;
    }
    if (b == 0) {
        return -28;
    }
    if (param_1->mUnk_72 != 1) {
        return -6;
    }
    if (param_1->mUnk_74 == 0) {
        return -28;
    }
    a = func_ov000_021a7064(func_ov000_021a740c, param_1, param_1->mUnk_72);
    a->mUnk_10 = param_1->mUnk_74;
    a->mUnk_14 = param_2;
    a->mUnk_18 = param_3;
    param_1->mUnk_70 |= 2;
    return func_ov000_021a6fb4(param_1, a);
}

s32 func_ov000_021a7534(Unk021a6fa8 *param_1, u16 *param_2, u32 *param_3) {
    s32 a;
    s32 b;
    s32 c;

    if (func_ov000_021a8a80(param_1) != 0) {
        return -28;
    }
    b = 0;
    if (param_1 != 0) {
        b = (param_1->mUnk_70 & 1) != 0;
    }
    if (b == 0) {
        return -39;
    }
    if (param_1->mUnk_70 & 2) {
        return -28;
    }
    b = 1;
    if (param_1->mUnk_73 != 0 && param_1->mUnk_73 != 4) {
        b = 0;
    }
    if (b == 0) {
        return -28;
    }
    if (param_1->mUnk_72 != 1) {
        return -6;
    }
    a = func_ov000_021a73d8(&data_ov000_021b49b8);
    if (a < 0) {
        return a;
    }
    c = func_ov000_021a7824((Unk021a6fa8 *) a, param_1->mUnk_74);
    if (c < 0) {
        return c;
    }
    c = func_ov000_021a7468((Unk021a6fa8 *) a, param_2, param_3);
    if (c < 0) {
        return c;
    }
    return a;
}

s32 func_ov000_021a75f8(s32 param_1) {
    Unk021a6fa8 *a = (Unk021a6fa8 *) param_1;
    s32 b;

    if (func_ov000_021a8a80(a) != 0) {
        return -28;
    }
    b = 0;
    if (a != 0) {
        b = (a->mUnk_70 & 1) != 0;
    }
    if (b == 0) {
        return -39;
    }
    if (a->mUnk_70 & 2) {
        return -28;
    }
    b = 1;
    if (a->mUnk_73 != 0 && a->mUnk_73 != 4) {
        b = 0;
    }
    if (b == 0) {
        return -28;
    }
    if (a->mUnk_72 == 1) {
        return 0;
    }
    return -6;
}

s32 func_ov000_021a7680(Unk021a7064 *param_1) {
    Unk021a6fa8 *a;
    Unk021a71c0 *b;
    s32 c;

    a = param_1->mUnk_04;
    c = 0;
    b = a->mUnk_64;
    func_0200ed34(&b->mUnk_00.mUnk_e0);
    func_ov000_021ae290(param_1->mUnk_10, param_1->mUnk_12, (int) param_1->mUnk_14);
    b->mUnk_f8 = 0;
    if (param_1->mUnk_0c == 0 || param_1->mUnk_0c == 4) {
        c = func_ov000_021ae134();
    }
    func_0200ecc4(&b->mUnk_00.mUnk_e0);
    if (c != 0) {
        a->mUnk_70 |= 0x40;
        return -76;
    }
    a->mUnk_70 |= 4;
    return 0;
}

s32 func_ov000_021a76f4(Unk021a6fa8 *param_1) {
    Unk021a7064 *a;

    a = func_ov000_021a7064(func_ov000_021a7680, param_1, param_1->mUnk_72);
    if (a == 0) {
        return -33;
    }
    a->mUnk_10 = param_1->mUnk_74;
    a->mUnk_12 = param_1->mUnk_76;
    a->mUnk_14 = param_1->mUnk_78;
    param_1->mUnk_70 |= 2;
    return func_ov000_021a6fb4(param_1, a);
}

s32 func_ov000_021a7748(Unk021a6fa8 *param_1, u16 param_2, u16 *param_3) {
    s32 a;
    s32 b;
    volatile Unk021a6fa8 *v = param_1;

    if (func_ov000_021a8a80(param_1) != 0 || (v->mUnk_70 & 8)) {
        return -28;
    }
    b = 0;
    if (param_1 != 0) {
        b = (param_1->mUnk_70 & 1) != 0;
    }
    if (b == 0) {
        return -39;
    }
    b = 1;
    if (param_1->mUnk_73 != 0 && param_1->mUnk_73 != 4) {
        b = 0;
    }
    if (b != 0) {
        if (v->mUnk_70 & 4) {
            if (param_1->mUnk_72 == 1) {
                return -30;
            }
            return 0;
        }
        if (v->mUnk_70 & 2) {
            if (v->mUnk_70 & 0x40) {
                return param_1->mUnk_6c;
            }
            return data_ov000_021b49b4;
        }
        param_1->mUnk_76 = param_2;
        param_1->mUnk_78 = param_3;
        a = func_ov000_021a76f4(param_1);
        if (param_1->mUnk_72 == 1) {
            return a;
        }
        return -26;
    }
    param_1->mUnk_76 = param_2;
    param_1->mUnk_78 = param_3;
    return 0;
}

s32 func_ov000_021a7824(Unk021a6fa8 *param_1, u16 param_2) {
    s32 a;
    if (func_ov000_021a8a80(param_1) != 0) {
        return -28;
    }
    a = 0;
    if (param_1 != 0) {
        a = (param_1->mUnk_70 & 1) != 0;
    }
    if (a == 0) {
        return -39;
    }
    if (param_1->mUnk_70 & 2) {
        return -7;
    }
    param_1->mUnk_74 = param_2;
    if (param_1->mUnk_73 == 1) {
        return func_ov000_021a76f4(param_1);
    }
    return 0;
}

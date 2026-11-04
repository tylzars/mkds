#include "03/code_021c105c.h"
#include "03/code_021bf8c0.h"
#include "03/code_021c0fd8.h"
#include "03/code_021c0000.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1790.h"
#include "03/code_021d1970.h"
#include "03/code_021d1c18.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"
#include "03/unk_021d6000.h"
#include "03/code_021d1fd0.h"

static inline void func_ov003_021c105c_inline(Unk021bf920 *p, u32 *x, u32 *y) {
    *x = (p->mUnk_00 & 0x1ff0000) >> 16;
    *y = p->mUnk_00 & 0xff;
}

void func_ov003_021c105c(Unk021d34e0 *param_1) {
    s32 a;
    s32 b;
    func_ov003_021c105c_inline(data_ov003_021da160->mUnk_10[0], (u32 *) &a, (u32 *) &b);
    b = b + 0xc;
    func_ov003_021c1364(0, b);
    if (b >= 0xc0) {
        func_ov003_021d34e0(param_1, func_ov003_021c0fd8);
    }
}

void func_ov003_021c10a8(Unk021d34e0 *param_1) {
    s32 a;
    s32 b;
    func_ov003_021c105c_inline(data_ov003_021da160->mUnk_10[3], (u32 *) &a, (u32 *) &b);
    b = b + 0xc;
    func_ov003_021c1364(1, b);
    if (b >= 0xc0) {
        func_ov003_021d34e0(param_1, func_ov003_021c105c);
    }
}

void func_ov003_021c10f4(Unk021d34e0 *param_1) {
    s32 a;
    s32 b;
    func_ov003_021c105c_inline(data_ov003_021da160->mUnk_10[6], (u32 *) &a, (u32 *) &b);
    b = b + 0xc;
    func_ov003_021c1364(2, b);
    if (b >= 0xc0) {
        func_ov003_021d34e0(param_1, func_ov003_021c10a8);
    }
}

void func_ov003_021c1140(Unk021d34e0 *param_1) {
    s32 a;
    s32 b;
    func_ov003_021c105c_inline(data_ov003_021da160->mUnk_10[9], (u32 *) &a, (u32 *) &b);
    b = b + 0xc;
    func_ov003_021c1364(3, b);
    if (b >= 0xc0) {
        func_ov003_021d34e0(param_1, func_ov003_021c10f4);
    }
}

void func_ov003_021c118c(Unk021d34e0 *param_1) {
    s32 a;
    s32 b;
    func_ov003_021c105c_inline(func_ov003_021d1974((s32) data_ov003_021da160->mUnk_40[0], 0), (u32 *) &a, (u32 *) &b);
    b = b + 0xc;
    func_ov003_021c1364(4, b);
    if (b >= 0xc0) {
        func_ov003_021d34e0(param_1, func_ov003_021c1140);
    }
}

void func_ov003_021c11dc(u32 param_1) {
    s8 a;
    s8 b;
    a = data_ov003_021da160->mUnk_63;
    data_ov003_021da160->mUnk_63 = (data_ov003_021d62d4 + a * 4)[param_1];
    b = data_ov003_021da160->mUnk_63;
    if (b == 0xd && (param_1 == 1 || param_1 == 3)) {
        data_ov003_021da160->mUnk_64 = a;
    } else if (b == -1) {
        if (data_ov003_021da160->mUnk_64 == 1 || data_ov003_021da160->mUnk_64 == 10) {
            data_ov003_021da160->mUnk_63 = 10;
        } else {
            data_ov003_021da160->mUnk_63 = 11;
        }
    } else if (b == -2) {
        if (data_ov003_021da160->mUnk_64 == 1 || data_ov003_021da160->mUnk_64 == 10) {
            data_ov003_021da160->mUnk_63 = 1;
        } else {
            data_ov003_021da160->mUnk_63 = 2;
        }
    }
    func_ov003_021c1268();
    func_ov003_021cdc10(8);
}

void func_ov003_021c1268(void) {
    int a;
    if (data_ov003_021da160->mUnk_63 <= 11) {
        a = 0x44;
    } else {
        a = 0x45;
    }
    func_ov003_021d1c3c(0, a, func_ov003_021d1974((s32) data_ov003_021da160->mUnk_58, 0));
    func_ov003_021d1790(data_ov003_021da160->mUnk_58, -1, 2);
    func_ov003_021d17d4(data_ov003_021da160->mUnk_58, -1, data_ov003_021d629c[data_ov003_021da160->mUnk_63 * 2],
                        data_ov003_021d629e[data_ov003_021da160->mUnk_63 * 2]);
}

void func_ov003_021c12cc(int param_1, int param_2) {
    Unk021bf920 *p;
    int a;
    if (param_1 < 0) {
        return;
    }
    if (param_1 < 10) {
        p = data_ov003_021da160->mUnk_10[param_1];
        p->mUnk_00 &= 0xfffff3ff;
        p->mUnk_04 = (p->mUnk_04 & 0xffff0fff) | (data_ov003_021d6220[param_2] << 12);
        return;
    }
    a = param_1 - 10;
    if (a < 2) {
        p = data_ov003_021da160->mUnk_38[a];
        p->mUnk_00 &= 0xfffff3ff;
        p->mUnk_04 = (p->mUnk_04 & 0xffff0fff) | (data_ov003_021d6220[param_2] << 12);
        return;
    }
    func_ov003_021d1890(data_ov003_021da160->mUnk_40[param_1 - 12], -1, 0, data_ov003_021d6214[param_2]);
}

// non-matching: loop address registers are computed per iteration instead of stepped, size 0x1a8 against 0x1ac
void func_ov003_021c1364(int param_1, u32 param_2) {
    Unk021c1364 s;
    BOOL b;
    int i;
    Unk021bf920 *p;
    s.mUnk_00 = *(Unk021c1364_05 *) data_ov003_021d6dc8;
    s.mUnk_05 = *(Unk021c1364_05 *) data_ov003_021d6dd0;
    s.mUnk_0a = *(Unk021c1364_05 *) data_ov003_021d6dc0;
    for (i = 0; i < s.mUnk_00.mUnk_00[param_1]; i++) {
        p = data_ov003_021da160->mUnk_10[param_1 * 3 + i];
        p->mUnk_00 = p->mUnk_00 & 0xc1fffcff;
        p = data_ov003_021da160->mUnk_10[param_1 * 3 + i];
        p->mUnk_00 =
            ((data_ov003_021d6274[(param_1 * 3 + i) * 2] & 0x1ff) << 16) | (p->mUnk_00 & 0xfe00ff00) | (param_2 & 0xff);
    }
    if (param_1 < 4) {
        func_ov003_021d1ffc(data_ov003_021da160->mUnk_00[param_1], data_ov003_021d6274[param_1 * 3 * 2], param_2,
                            data_ov003_021da160->mUnk_48[param_1], 2);
    }
    for (i = 0; i < s.mUnk_05.mUnk_00[param_1]; i++) {
        p = data_ov003_021da160->mUnk_38[i];
        p->mUnk_00 = p->mUnk_00 & 0xc1fffcff;
        p = data_ov003_021da160->mUnk_38[i];
        p->mUnk_00 = ((data_ov003_021d623c[i * 2] & 0x1ff) << 16) | (p->mUnk_00 & 0xfe00ff00) | (param_2 & 0xff);
    }
    b = FALSE;
    for (i = 0; i < s.mUnk_0a.mUnk_00[param_1]; i++) {
        func_ov003_021d18f0(data_ov003_021da160->mUnk_40[i], -1, b, b);
        func_ov003_021d17d4(data_ov003_021da160->mUnk_40[i], -1, data_ov003_021d6244[i * 2], param_2);
    }
}

void func_ov003_021c1510(void) {
    int a;
    if (func_ov003_021d2ae8(0x20) != 0) {
        func_ov003_021c11dc(0);
    }
    if (func_ov003_021d2ae8(0x40) != 0) {
        func_ov003_021c11dc(1);
    }
    if (func_ov003_021d2ae8(0x10) != 0) {
        func_ov003_021c11dc(2);
    }
    if (func_ov003_021d2ae8(0x80) != 0) {
        func_ov003_021c11dc(3);
    }
    if (func_ov003_021d2b04(1) != 0) {
        a = data_ov003_021da160->mUnk_63;
        if (a < 10) {
            if (data_ov003_021da160->mUnk_67 != 0) {
                data_ov003_021da160->mUnk_60 = data_ov003_021d624c[a];
                return;
            }
            func_ov003_021cdc10(9);
            return;
        }
        if (a - 10 < 2) {
            if ((a - 10 == 0 && data_ov003_021da160->mUnk_66 == 0) ||
                (a - 10 == 1 && data_ov003_021da160->mUnk_68 == 0)) {
                func_ov003_021cdc10(9);
                return;
            }
            data_ov003_021da160->mUnk_60 = data_ov003_021d6228[a - 10];
            return;
        }
        data_ov003_021da160->mUnk_60 = data_ov003_021d6224[a - 12];
    }
    if (func_ov003_021d2ae8(2) != 0) {
        if (data_ov003_021da160->mUnk_66 == 0) {
            if (data_ov003_021da160->mUnk_69 == 0) {
                func_ov003_021cdc10(9);
                data_ov003_021da160->mUnk_69 = 1;
            }
        } else {
            data_ov003_021da160->mUnk_60 = 0x10;
        }
    } else if (func_ov003_021d2acc(2) != 0) {
        data_ov003_021da160->mUnk_69 = 0;
    }
}

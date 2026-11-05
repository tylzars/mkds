#include "03/code_021c0fd8.h"

#include "03/code_021d197c.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2ecc.h"
#include "03/code_021bf8c0.h"
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
#include "03/code_021c1000.h"
#include "03/code_021d250c.h"
#include "03/code_021d1770.h"
#include "03/code_021d3488.h"
#include "03/code_021c04ec.h"

void func_ov003_021c1cd8(void) {
    Unk021c0d2c s;
    Unk021da160 *p;
    int i;
    int j;
    int k;
    s.mUnk_00[0] = data_ov003_021d6dd8[0];
    s.mUnk_00[1] = data_ov003_021d6dd8[1];
    s.mUnk_00[2] = data_ov003_021d6dd8[2];
    s.mUnk_00[3] = data_ov003_021d6dd8[3];
    s.mUnk_00[2] = data_ov003_021d622c[0];
    s.mUnk_00[3] = data_ov003_021d622c[1];
    p = func_ov003_021d283c(0x6c, 4);
    data_ov003_021da160 = p;
    p->mUnk_60 = 0x1f;
    data_ov003_021da160->mUnk_63 = 0;
    data_ov003_021da160->mUnk_66 = 1;
    data_ov003_021da160->mUnk_67 = 1;
    data_ov003_021da160->mUnk_68 = 1;
    for (i = 0; i < 10; i++) {
        data_ov003_021da160->mUnk_10[i] = func_ov003_021d1c18(0, 0x36);
        data_ov003_021da160->mUnk_10[i]->mUnk_00 = (data_ov003_021da160->mUnk_10[i]->mUnk_00 & 0xc1fffcff) | 0x200;
        data_ov003_021da160->mUnk_10[i]->mUnk_04 = (data_ov003_021da160->mUnk_10[i]->mUnk_04 & 0xfffff3ff) | 0xc00;
    }
    for (i = 0; i < 2; i++) {
        data_ov003_021da160->mUnk_38[i] = func_ov003_021d1c18(0, data_ov003_021d6218[i]);
        data_ov003_021da160->mUnk_38[i]->mUnk_00 = (data_ov003_021da160->mUnk_38[i]->mUnk_00 & 0xc1fffcff) | 0x200;
        data_ov003_021da160->mUnk_38[i]->mUnk_04 = (data_ov003_021da160->mUnk_38[i]->mUnk_04 & 0xfffff3ff) | 0xc00;
    }
    for (i = 0; i < 2; i++) {
        data_ov003_021da160->mUnk_40[i] = func_ov003_021d1be4(0, data_ov003_021d621c[i], 1);
        func_ov003_021d18f0(data_ov003_021da160->mUnk_40[i], -1, 0x200, 0);
        func_ov003_021d1790(data_ov003_021da160->mUnk_40[i], -1, 3);
    }
    s.mUnk_0c[1] = 0;
    for (i = 0; i < 4; i++) {
        data_ov003_021da160->mUnk_00[i] =
            func_ov003_021d23b0(0, data_ov003_021d6230[0], data_ov003_021d6230[1], 0, &s.mUnk_08, 0);
        j = i * 3;
        for (k = 0, s.mUnk_00[0] = 0; k < 3; k++, j++, s.mUnk_00[0] += 0x20) {
            s.mUnk_0c[0] = data_ov003_021d6258[j];
            func_ov003_021d2070(data_ov003_021da160->mUnk_00[i], s.mUnk_00[0], s.mUnk_00[1], s.mUnk_00[2], s.mUnk_00[3],
                                2, 0x480, s.mUnk_0c);
        }
        data_ov003_021da160->mUnk_48[i] = func_ov003_021d19e0(0, s.mUnk_08, 0);
    }
    data_ov003_021da160->mUnk_58 = func_ov003_021d1be4(0, 0x44, 1);
    func_ov003_021d18f0(data_ov003_021da160->mUnk_58, -1, 0x200, 0);
    func_ov003_021d1790(data_ov003_021da160->mUnk_58, -1, 2);
    data_ov003_021da160->mUnk_5c = (Unk021d34e0 *) func_ov003_021d3544(0, func_ov003_021c1bf4, NULL, 0x78);
    func_ov003_021c1364(0, 0xc0);
}

void func_ov003_021c1cb0(void) {
    func_ov003_021d197c(data_ov003_021da160->mUnk_58);
    func_ov003_021d34e0(data_ov003_021da160->mUnk_5c, func_ov003_021c118c);
    return;
}

u8 func_ov003_021c1ca0(void) {
    return data_ov003_021da160->mUnk_60;
}

void func_ov003_021c1c90(u8 a) {
    data_ov003_021da160->mUnk_66 = a;
    return;
}

void func_ov003_021c1c80(u8 a) {
    data_ov003_021da160->mUnk_67 = a;
    return;
}

void func_ov003_021c1c70(u8 a) {
    data_ov003_021da160->mUnk_68 = a;
    return;
}

u32 func_ov003_021c1c5c(void) {
    if (data_ov003_021da160 != NULL) {
        return 1;
    }
    return 0;
}

static inline void func_ov003_021c1b8c_inline(Unk021bf920 *p, u32 *x, u32 *y) {
    *x = (p->mUnk_00 & 0x1ff0000) >> 16;
    *y = p->mUnk_00 & 0xff;
}

void func_ov003_021c1bf4(Unk021d34e0 *param_1) {
    s32 a;
    s32 b;
    func_ov003_021c1b8c_inline(data_ov003_021da160->mUnk_10[0], (u32 *) &a, (u32 *) &b);
    b = b - 0xc;
    if (b > data_ov003_021d6274[0][1]) {
        func_ov003_021c1364(0, b);
        return;
    }
    func_ov003_021c1364(0, data_ov003_021d6274[0][1]);
    func_ov003_021c1364(1, 0xc0);
    func_ov003_021d34e0(param_1, func_ov003_021c1b8c);
}

void func_ov003_021c1b8c(Unk021d34e0 *param_1) {
    s32 a;
    s32 b;
    func_ov003_021c1b8c_inline(data_ov003_021da160->mUnk_10[3], (u32 *) &a, (u32 *) &b);
    b = b - 0xc;
    if (b > data_ov003_021d6274[3][1]) {
        func_ov003_021c1364(1, b);
        return;
    }
    func_ov003_021c1364(1, data_ov003_021d6274[3][1]);
    func_ov003_021c1364(2, 0xc0);
    func_ov003_021d34e0(param_1, func_ov003_021c1b24);
}

void func_ov003_021c1b24(Unk021d34e0 *param_1) {
    s32 a;
    s32 b;
    func_ov003_021c1b8c_inline(data_ov003_021da160->mUnk_10[6], (u32 *) &a, (u32 *) &b);
    b = b - 0xc;
    if (b > data_ov003_021d6274[6][1]) {
        func_ov003_021c1364(2, b);
        return;
    }
    func_ov003_021c1364(2, data_ov003_021d6274[6][1]);
    func_ov003_021c1364(3, 0xc0);
    func_ov003_021d34e0(param_1, func_ov003_021c1abc);
}

void func_ov003_021c1abc(Unk021d34e0 *param_1) {
    s32 a;
    s32 b;
    func_ov003_021c1b8c_inline(data_ov003_021da160->mUnk_10[9], (u32 *) &a, (u32 *) &b);
    b = b - 0xc;
    if (b > data_ov003_021d6274[9][1]) {
        func_ov003_021c1364(3, b);
        return;
    }
    func_ov003_021c1364(3, data_ov003_021d6274[9][1]);
    func_ov003_021c1364(4, 0xc0);
    func_ov003_021d34e0(param_1, func_ov003_021c1a60);
}

void func_ov003_021c1a60(Unk021d34e0 *param_1) {
    u32 a;
    s32 b;
    func_ov003_021d1770(data_ov003_021da160->mUnk_40[0], 0, &a, &b);
    b = b - 0xc;
    if (b > data_ov003_021d6244[0][1]) {
        func_ov003_021c1364(4, b);
        return;
    }
    func_ov003_021c1364(4, data_ov003_021d6244[0][1]);
    func_ov003_021c1268();
    func_ov003_021d34e0(param_1, func_ov003_021c1a44);
}

void func_ov003_021c1a44(void) {
    func_ov003_021c1908();
    func_ov003_021c17d4();
    func_ov003_021c1680();
    func_ov003_021c1510();
    return;
}

void func_ov003_021c1908(void) {
    Unk021d299c a;
    u16 *q;
    int j;
    int i;
    u16 *p;
    if (func_ov003_021d2a34(&data_ov003_021d67e8) == 0) {
        return;
    }
    data_ov003_021da160->mUnk_61 = -1;
    for (i = 0, p = data_ov003_021d6274[0]; i < 10; p += 2, i++) {
        func_ov003_021d250c(p, data_ov003_021d622c, &a);
        if (func_ov003_021d2a34(&a) != 0) {
            if (data_ov003_021da160->mUnk_67 == 0) {
                func_ov003_021cdc10(9);
                return;
            }
            func_ov003_021cdc10(0);
            data_ov003_021da160->mUnk_61 = i;
            return;
        }
    }
    for (j = 0, q = data_ov003_021d623c[0]; j < 2; q += 2, j++) {
        func_ov003_021d250c(q, data_ov003_021d6234, &a);
        if (func_ov003_021d2a34(&a) != 0) {
            if ((j == 0 && data_ov003_021da160->mUnk_66 == 0) || (j == 1 && data_ov003_021da160->mUnk_68 == 0)) {
                func_ov003_021cdc10(9);
                return;
            }
            func_ov003_021cdc10(0);
            data_ov003_021da160->mUnk_61 = j + 10;
            return;
        }
    }
    for (j = 0, p = data_ov003_021d6244[0]; j < 2; p += 2, j++) {
        func_ov003_021d250c(p, data_ov003_021d6238, &a);
        if (func_ov003_021d2a34(&a) != 0) {
            func_ov003_021cdc10(0);
            data_ov003_021da160->mUnk_61 = j + 12;
            return;
        }
    }
}

void func_ov003_021c17d4(void) {
    Unk021d299c a;
    u16 *q;
    int j;
    int i;
    u16 *p;
    data_ov003_021da160->mUnk_60 = 0;
    if (func_ov003_021d299c(&data_ov003_021d67e8) == 0) {
        return;
    }
    for (i = 0, p = data_ov003_021d6274[0]; i < 10; p += 2, i++) {
        func_ov003_021d250c(p, data_ov003_021d622c, &a);
        if (func_ov003_021d299c(&a) != 0) {
            if (data_ov003_021da160->mUnk_61 != i) {
                return;
            }
            data_ov003_021da160->mUnk_60 = data_ov003_021d624c[i];
            data_ov003_021da160->mUnk_63 = i;
            func_ov003_021c1268();
            return;
        }
    }
    for (j = 0, q = data_ov003_021d623c[0]; j < 2; q += 2, j++) {
        func_ov003_021d250c(q, data_ov003_021d6234, &a);
        if (func_ov003_021d299c(&a) != 0) {
            if (data_ov003_021da160->mUnk_61 != j + 10) {
                return;
            }
            data_ov003_021da160->mUnk_60 = data_ov003_021d6228[j];
            data_ov003_021da160->mUnk_63 = j + 10;
            func_ov003_021c1268();
            return;
        }
    }
    for (j = 0, p = data_ov003_021d6244[0]; j < 2; p += 2, j++) {
        func_ov003_021d250c(p, data_ov003_021d6238, &a);
        if (func_ov003_021d299c(&a) != 0) {
            if (data_ov003_021da160->mUnk_61 != j + 12) {
                return;
            }
            data_ov003_021da160->mUnk_60 = data_ov003_021d6224[j];
            data_ov003_021da160->mUnk_63 = j + 12;
            func_ov003_021c1268();
            return;
        }
    }
}

void func_ov003_021c1680(void) {
    Unk021d299c a;
    u16 *q;
    int j;
    int i;
    u16 *p;
    if (func_ov003_021d2a80(&data_ov003_021d67e8) == 0) {
        goto label_1;
    }
    for (i = 0, p = data_ov003_021d6274[0]; i < 10; p += 2, i++) {
        func_ov003_021d250c(p, data_ov003_021d622c, &a);
        if (func_ov003_021d2a80(&a) != 0) {
            if (data_ov003_021da160->mUnk_61 != i) {
                goto label_1;
            }
            func_ov003_021c1648(i);
            goto label_2;
        }
    }
    for (j = 0, q = data_ov003_021d623c[0]; j < 2; q += 2, j++) {
        func_ov003_021d250c(q, data_ov003_021d6234, &a);
        if (func_ov003_021d2a80(&a) != 0) {
            if (data_ov003_021da160->mUnk_61 != j + 10) {
                goto label_1;
            }
            func_ov003_021c1648(j + 10);
            if (j != 0) {
                goto label_2;
            }
            data_ov003_021da160->mUnk_65 = data_ov003_021da160->mUnk_65 + 1;
            if (data_ov003_021da160->mUnk_65 >= 0x28) {
                if (data_ov003_021da160->mUnk_66 == 0) {
                    func_ov003_021cdc10(9);
                    data_ov003_021da160->mUnk_61 = -1;
                    return;
                }
                data_ov003_021da160->mUnk_60 = 0x10;
                data_ov003_021da160->mUnk_65 = data_ov003_021da160->mUnk_65 - 7;
                return;
            }
            return;
        }
    }
    for (j = 0, p = data_ov003_021d6244[0]; j < 2; p += 2, j++) {
        func_ov003_021d250c(p, data_ov003_021d6238, &a);
        if (func_ov003_021d2a80(&a) != 0) {
            j += 12;
            if (data_ov003_021da160->mUnk_61 != j) {
                goto label_1;
            }
            func_ov003_021c1648(j);
            goto label_2;
        }
    }
label_1:
    func_ov003_021c1648(-1);
label_2:
    data_ov003_021da160->mUnk_65 = 0;
}

void func_ov003_021c1648(int a) {
    if (a != data_ov003_021da160->mUnk_62) {
        func_ov003_021c12cc(a, 1);
        func_ov003_021c12cc(data_ov003_021da160->mUnk_62, 0);
        data_ov003_021da160->mUnk_62 = (s8) a;
    }
    return;
}

static inline void func_ov003_021c105c_inline(Unk021bf920 *p, u32 *x, u32 *y) {
    *x = (p->mUnk_00 & 0x1ff0000) >> 16;
    *y = p->mUnk_00 & 0xff;
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

void func_ov003_021c1364(int param_1, u32 param_2) {
    u8 a[5];
    u8 c[5];
    u8 d[5];
    BOOL b;
    int i;
    int j;
    Unk021bf920 *p;
    *(Unk021c1364_05 *) a = *(Unk021c1364_05 *) data_ov003_021d6dc8;
    *(Unk021c1364_05 *) c = *(Unk021c1364_05 *) data_ov003_021d6dd0;
    *(Unk021c1364_05 *) d = *(Unk021c1364_05 *) data_ov003_021d6dc0;
    j = param_1 * 3;
    for (i = 0; i < a[(u32) param_1]; i++, j++) {
        p = data_ov003_021da160->mUnk_10[j];
        p->mUnk_00 = p->mUnk_00 & 0xc1fffcff;
        p = data_ov003_021da160->mUnk_10[j];
        p->mUnk_00 = ((data_ov003_021d6274[j][0] & 0x1ff) << 16) | ((p->mUnk_00 & 0xfe00ff00) | (param_2 & 0xff));
    }
    if (param_1 < 4) {
        func_ov003_021d1ffc(data_ov003_021da160->mUnk_00[param_1], data_ov003_021d6274[param_1 * 3][0], param_2,
                            data_ov003_021da160->mUnk_48[param_1], 2);
    }
    for (i = 0; i < c[(u32) param_1]; i++) {
        p = data_ov003_021da160->mUnk_38[i];
        p->mUnk_00 = p->mUnk_00 & 0xc1fffcff;
        p = data_ov003_021da160->mUnk_38[i];
        p->mUnk_00 = ((data_ov003_021d623c[i][0] & 0x1ff) << 16) | ((p->mUnk_00 & 0xfe00ff00) | (param_2 & 0xff));
    }
    b = FALSE;
    for (i = 0; i < d[(u32) param_1]; i++) {
        func_ov003_021d18f0(data_ov003_021da160->mUnk_40[i], -1, b, b);
        func_ov003_021d17d4(data_ov003_021da160->mUnk_40[i], -1, data_ov003_021d6244[i][0], param_2);
    }
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

void func_ov003_021c1268(void) {
    int a;
    if (data_ov003_021da160->mUnk_63 <= 11) {
        a = 0x44;
    } else {
        a = 0x45;
    }
    func_ov003_021d1c3c(0, a, func_ov003_021d1974(data_ov003_021da160->mUnk_58, 0));
    func_ov003_021d1790(data_ov003_021da160->mUnk_58, -1, 2);
    func_ov003_021d17d4(data_ov003_021da160->mUnk_58, -1, data_ov003_021d629c[data_ov003_021da160->mUnk_63 * 2],
                        data_ov003_021d629e[data_ov003_021da160->mUnk_63 * 2]);
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

void func_ov003_021c118c(Unk021d34e0 *param_1) {
    s32 a;
    s32 b;
    func_ov003_021c105c_inline(func_ov003_021d1974(data_ov003_021da160->mUnk_40[0], 0), (u32 *) &a, (u32 *) &b);
    b = b + 0xc;
    func_ov003_021c1364(4, b);
    if (b >= 0xc0) {
        func_ov003_021d34e0(param_1, func_ov003_021c1140);
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

void func_ov003_021c0fd8(u32 a) {
    int v1;
    func_ov003_021d34c8(0, a);
    v1 = 0;
    do {
        func_ov003_021d197c(data_ov003_021da160->mUnk_48[v1]);
        func_ov003_021d2388(data_ov003_021da160->mUnk_00[v1]);
        v1 = v1 + 1;
    } while (v1 < 4);
    v1 = 0;
    do {
        func_ov003_021d197c(data_ov003_021da160->mUnk_40[v1]);
        v1 = v1 + 1;
    } while (v1 < 2);
    v1 = 0;
    do {
        func_ov003_021d2f00((u32 *) data_ov003_021da160->mUnk_38[v1]);
        v1 = v1 + 1;
    } while (v1 < 2);
    v1 = 0;
    do {
        func_ov003_021d2f00((u32 *) data_ov003_021da160->mUnk_10[v1]);
        v1 = v1 + 1;
    } while (v1 < 10);
    func_ov003_021d2808(&data_ov003_021da160);
    return;
}

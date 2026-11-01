#include "types.h"
#include "01/code_021a10b8.h"
#include "01/unk_021ca000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "01/code_021a165c.h"
#include "01/code_021a1820.h"
#include "01/code_021a1ba0.h"
#include "01/code_021a1bb8.h"
#include "01/code_021a64a0.h"
#include "01/code_02195a6c.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/code_021a1000.h"
#include "code_0212df7c.h"
#include "code_0201ea58.h"
#include "registers.h"

void func_ov001_021a13d8(void) {
    u32 r5 = -1;
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    s32 b1;
    s32 a1;
    s32 b2;
    s32 a2;
    u32 v;
    u32 w;
    s32 t;
    s32 s;
    Unk021ca418 *o;

    func_ov001_021a1b08();
    a1 = b1 = 0;
    v = data_02175628[idx].mUnk_4c;
    if (v == 0 && data_02175628[idx].mUnk_58 < 5) {
        a1 = 1;
    }
    if (a1 == 0 && data_02175628[idx].mUnk_54 == 0 && v != 0) {
        b1 = 1;
    }
    if (b1 != 0) {
        r5 = func_0201ea84(data_ov001_021ca418->mUnk_10, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 2) == 0) {
        a2 = b2 = 0;
        w = data_02175628[idx].mUnk_4c;
        if (w == 0 && data_02175628[idx].mUnk_58 < 5) {
            a2 = 1;
        }
        if (a2 == 0 && data_02175628[idx].mUnk_54 == 0 && w != 0) {
            b2 = 1;
        }
        if (b2 == 0 || func_02128210(data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a) == 0) {
            goto next;
        }
    }
    if (func_ov001_021a1ba0() != 0) {
        return;
    }
    func_021281c8(0xe);
    func_ov001_021a1964();
    data_ov001_021ca418->mUnk_4c = 2;
    func_02128310(0);
    return;
next:
    if (r5 <= 3) {
        s = data_ov001_021a6f80[r5];
        if (data_ov001_021ca418->mUnk_34 == s) {
            data_ov001_021ca418->mUnk_38 = 0;
        }
        data_ov001_021ca418->mUnk_34 = s;
        func_ov001_021a1978();
        return;
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 1) != 0) {
        data_ov001_021ca418->mUnk_38 = 0;
        func_ov001_021a1978();
        return;
    }
    if (func_020ae408(8, 0x40) != 0) {
        if (func_02056dec(0x10) != 0) {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f20[t];
        } else {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f40[t];
        }
        if (s != 0) {
            o->mUnk_34 = t + s;
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    } else if (func_020ae408(8, 0x80) != 0) {
        if (func_02056dec(0x10) != 0) {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f30[t];
        } else {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f48[t];
        }
        if (s != 0) {
            o->mUnk_34 = t + s;
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    } else if (func_020ae408(8, 0x20) != 0) {
        if (func_02056dec(0x10) != 0) {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f38[t];
        } else {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f50[t];
        }
        if (s != 0) {
            o->mUnk_34 = t + s;
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    } else if (func_020ae408(8, 0x10) != 0) {
        if (func_02056dec(0x10) != 0) {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f60[t];
        } else {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f58[t];
        }
        if (s != 0) {
            o->mUnk_34 = t + s;
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    }
}

void func_ov001_021a1398(void) {
    func_ov001_021a1b08();
    if (data_ov001_021ca418->mUnk_2c == 5) {
        data_ov001_021ca418->mUnk_38 = 1;
    }
    data_ov001_021ca418->mUnk_2c++;
    if (data_ov001_021ca418->mUnk_2c >= 10) {
        if (func_ov001_021a1ba0() == 0) {
            func_ov001_021a1964();
        }
    }
}

void func_ov001_021a126c(void) {
    s16 a;
    s16 b;
    s32 i;
    s32 k;

    data_ov001_021ca418->mUnk_2c++;
    a = func_020ae4c0(1, 0, 0xc0, data_ov001_021ca418->mUnk_2c, 10);
    b = func_020ae4c0(1, 0, -0xc0, data_ov001_021ca418->mUnk_2c, 10);
    data_ov001_021ca418->mUnk_30 = -b;
    for (i = 0; i < 6; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f68[i]].mUnk_06 = -b;
    }
    data_ov001_021ca418->mUnk_14[6].mUnk_06 = b;
    for (i = 0; i < 4; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[i]].mUnk_06 = -b;
        if (func_02056dec(0x10) != 0) {
            switch (i) {
                case 0:
                case 2:
                    for (k = 0; k < 3; k++) {
                        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][k]].mUnk_04 = -a;
                    }
                    break;
                case 1:
                case 3:
                    for (k = 0; k < 3; k++) {
                        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][k]].mUnk_04 = a;
                    }
                    break;
            }
        } else {
            for (k = 0; k < 3; k++) {
                data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][k]].mUnk_04 = a;
            }
        }
    }
}

int func_ov001_021a11c4(void) {
    data_ov001_021ca418->mUnk_24 = data_ov001_021ca418->mUnk_28;
    switch (data_ov001_021ca418->mUnk_24) {
        case 0:
            func_ov001_021a1820();
            break;
        case 1:
            func_ov001_021a16e4();
            break;
        case 2:
            func_ov001_021a1674();
            break;
        case 3:
            func_ov001_021a165c();
            break;
        case 4:
            func_ov001_021a13d8();
            break;
        case 5:
            func_ov001_021a1398();
            break;
        case 6:
            func_ov001_021a126c();
            break;
    }
    func_ov001_021a1c34();
    func_02124c30(data_ov001_021ca418->mUnk_04, data_ov001_021ca418->mUnk_00, 0, data_ov001_021ca418->mUnk_44,
                  data_ov001_021ca418->mUnk_14);
    func_02124c30(data_ov001_021ca418->mUnk_0c, data_ov001_021ca418->mUnk_08, 0, data_ov001_021ca418->mUnk_48,
                  data_ov001_021ca418->mUnk_18);
    if (data_ov001_021ca418->mUnk_24 == 6 && data_ov001_021ca418->mUnk_2c >= 10) {
        return data_ov001_021ca418->mUnk_4c;
    }
    return 0;
}

void func_ov001_021a11a4(void) {
    reg_G2_BG0OFS = (-data_ov001_021ca418->mUnk_30 << 16) & 0x01ff0000;
}

void func_ov001_021a10b8(void) {
    Unk020b4934 *a = 0;
    Unk02021dc8 *b = 0;
    Unk020b4a44 *c = 0;
    Unk020b4934 *d = 0;
    Unk02021dc8 *e = 0;
    Unk020b4a44 *f = 0;
    Unk020b4934 *g = 0;
    Unk020b47d8 *h = 0;
    Unk020b47d8 *i = 0;
    Unk020b4a44 *j = 0;

    func_020b496c(&g, func_0204799c(data_ov001_021a92bc));
    func_020b4a7c(&j, func_0204799c(data_ov001_021a92a8));
    func_020b4810(&h, func_0204799c(data_ov001_021a928c));
    func_020b4810(&i, func_0204799c(data_ov001_021a92c0));
    func_020b49f4(&a, func_0204799c(data_ov001_021a9278));
    func_020b48ec(&b, func_0204799c(data_ov001_021a92c4));
    func_020b4a7c(&c, func_0204799c(data_ov001_021a9298));
    func_020b49f4(&d, func_0204799c(data_ov001_021a92b0));
    func_020b48ec(&e, func_0204799c(data_ov001_021a9284));
    func_020b4a7c(&f, func_0204799c(data_ov001_021a927c));
    func_ov001_021a651c();
}

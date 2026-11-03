#include "03/code_021c1c5c.h"
#include "03/code_021c6a18.h"
#include "03/code_021c6f64.h"
#include "03/code_021c7050.h"
#include "03/code_021c70a4.h"
#include "03/code_021c722c.h"
#include "03/code_021c735c.h"
#include "03/code_021cdbd0.h"
#include "03/unk_021da000.h"
#include "code_0213a460.h"
#include "code_0214d018.h"

void func_ov003_021c73cc(void) {
    s32 a;
    u8 *b;
    s32 k;
    Unk021da1fc *h;
    Unk021da1fc **g;
    u8 e;
    a = func_ov003_021c1ca0();
    switch (a) {
        case 0:
            return;
        case 0x10:
            if (data_ov003_021da1fc->mUnk_14 == 0 && data_ov003_021da1fc->mUnk_08[2] == 0) {
                break;
            }
            func_ov003_021cdc10(3);
            if (data_ov003_021da1fc->mUnk_08[data_ov003_021da1fc->mUnk_14 * 3 + 2] == 0) {
                data_ov003_021da1fc->mUnk_14--;
            }
            func_0214d168(data_ov003_021da1fc->mUnk_08 + data_ov003_021da1fc->mUnk_14 * 3, 0, 3);
            if (data_ov003_021da1fc->mUnk_14 == 0 && data_ov003_021da1fc->mUnk_08[2] == 0) {
                func_ov003_021c1c90(0);
            }
            func_ov003_021c1c80(1);
            func_ov003_021c1c70(0);
            break;
        case 0x11:
            e = data_ov003_021da1fc->mUnk_14;
            if (e >= 3) {
                break;
            }
            if (data_ov003_021da1fc->mUnk_08[e * 3 + 2] == 0) {
                break;
            }
            func_ov003_021cdc10(1);
            data_ov003_021da1fc->mUnk_14 = data_ov003_021da1fc->mUnk_14 + 1;
            func_ov003_021c1c70(0);
            break;
        case 0x12:
            data_ov003_021da1fc->mUnk_15 = 0;
            func_ov003_021cdc10(7);
            func_ov003_021c212c(func_ov003_021c733c);
            return;
        case 0x13:
            if (func_ov003_021c6f64() != 0) {
                func_ov003_021cdc10(6);
                data_ov003_021da1fc->mUnk_15 = 1;
            } else {
                data_ov003_021da1fc->mUnk_15 = 2;
                func_ov003_021cdc10(9);
            }
            data_ov003_021da1fc->mUnk_14 = 3;
            data_ov003_021da1fc->mUnk_04->mUnk_00 = (data_ov003_021da1fc->mUnk_04->mUnk_00 & 0xc1fffcff) | 0x200;
            func_ov003_021c7160();
            func_ov003_021c7050();
            func_ov003_021c212c(func_ov003_021c733c);
            return;
        default:
            if (data_ov003_021da1fc->mUnk_14 == 3) {
                if (func_ov003_021c735c(0x1a) != 0) {
                    break;
                }
            }
            func_ov003_021cdc10(1);
            g = (Unk021da1fc **) &data_ov003_021da1fc;
            b = (*g)->mUnk_08;
            k = (*g)->mUnk_14 * 3;
            if (b[k + 2] == 0) {
                b[k + 2] = a;
            } else if (b[k + 1] == 0) {
                b[k + 1] = b[k + 2];
                b[k + 2] = a;
                if (func_ov003_021c735c(0x1a) != 0) {
                    h = data_ov003_021da1fc;
                    if (h->mUnk_14 < 3) {
                        h->mUnk_14 = h->mUnk_14 + 1;
                    }
                }
            } else {
                b[k] = b[k + 1];
                b[k + 1] = b[k + 2];
                b[k + 2] = a;
                if ((*g)->mUnk_14 < 3) {
                    (*g)->mUnk_14 = (*g)->mUnk_14 + 1;
                }
            }
            func_ov003_021c1c90(1);
            if (data_ov003_021da1fc->mUnk_14 < 3) {
                func_ov003_021c1c70(1);
            } else {
                func_ov003_021c1c70(0);
            }
            if (data_ov003_021da1fc->mUnk_14 == 3) {
                if (func_ov003_021c735c(0x1a) != 0) {
                    func_ov003_021c1c80(0);
                }
            }
            break;
    }
    func_ov003_021c71a0();
    func_ov003_021c7160();
}

u32 func_ov003_021c735c(s32 a) {
    u8 b[4];
    u8 *c;
    u8 *d;
    s32 e;
    u8 f;
    d = data_ov003_021da1fc->mUnk_08;
    c = d + data_ov003_021da1fc->mUnk_14 * 3;
    f = *c;
    if (f != 0 && f != 0x20) {
        return 1;
    }
    func_0214d1fc(c, b, 3);
    b[3] = 0;
    c = b;
    for (e = 0; e < 3; e++) {
        if (*c != 0) {
            break;
        }
        *c = 0x20;
        c++;
    }
    if (func_0213bf90((const char *) b) >= a) {
        return 1;
    }
    return 0;
}

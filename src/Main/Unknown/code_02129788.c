#include "Main/Unknown/code_02129788.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/code_020ab748.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/code_020ab798.h"
#include "Main/Unknown/code_0212898c.h"
#include "Main/Unknown/code_0212899c.h"
#include "Main/Unknown/code_02129cbc.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_0201ea58.h"
#include "code_0214a054.h"
#include "code_0214cfe4.h"

#pragma thumb on
void func_02129c18(void) {
    u32 t;
    *(vu16 *) 0x4001050 = 0;
    t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    t |= 0xc;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & ~0x1f00) | (t << 8);
    *(vu16 *) 0x400100c = (*(vu16 *) 0x400100c & 0x43) | 0x8018;
    *(vu16 *) 0x400100c = (*(vu16 *) 0x400100c & ~3) | 2;
    *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & 0x43) | 0x9010;
    *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & ~3) | 2;
    func_0214d05c_inline((void *) func_0214a214(), 0x1000);
    func_0214d05c_inline((void *) func_0214a108(), 0x1000);
}

void func_02129bdc(void) {
    if (func_02036c5c() != 0) {
        data_0217d400->mUnk_10 = 1;
        func_02126638(func_020b3f7c(data_0217d400->mUnk_c0, 7), 0, 0, 0, 0, 0, 0);
    }
}

void func_02129b60(void) {
    s32 n;
    n = data_0215d0e0[0] - 1;
    if (n == func_020ab748() && data_0217d400->mUnk_2c[data_0217d400->mUnk_04].mUnk_00[n] != 0) {
        data_0217d400->mUnk_1c[0] = 1;
    } else {
        data_0217d400->mUnk_1c[0] = 0;
    }
    if (func_020ab8c4() == 1) {
        data_0217d400->mUnk_14[0] = 1;
    } else {
        data_0217d400->mUnk_14[0] = 0;
    }
    if (func_020ab8c4() == 2) {
        data_0217d400->mUnk_14[1] = 1;
    } else {
        data_0217d400->mUnk_14[1] = 0;
    }
}

void func_02129acc(void) {
    data_0217d400->mUnk_28++;
    data_0217d400->mUnk_84 = func_020ae4c0(1, 0xc0, 0, data_0217d400->mUnk_28, 0xf);
    data_0217d400->mUnk_86[0][1] =
        func_020ae4c0(1, data_0215d108[0][1], data_0215d100[0][1], data_0217d400->mUnk_28, 0xf);
    if (data_0217d400->mUnk_28 >= 0xf) {
        data_0217d400->mUnk_28 = 0xf;
    }
    if (data_0217d400->mUnk_28 >= 0xf && func_02125fa4() != 0) {
        data_0217d400->mUnk_10 = 2;
        data_0217d400->mUnk_24 = 1;
        data_0217d400->mUnk_28 = 0;
    }
    func_02129b60();
}

void func_02129994(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    Unk0217d400 *p;
    Unk0217d400_2c *q;
    void *w;
    s32 v;
    s32 f;
    s32 g;
    u16 c;
    f = 0;
    v = -1;
    g = 0;
    c = data_02175674[i].mUnk_00;
    if (c == 0 && data_02175680[i].mUnk_00 < 5) {
        g = 1;
    }
    if (g == 0 && data_0217567c[i].mUnk_00 == 0 && c != 0) {
        f = 1;
    }
    if (f != 0) {
        v = func_0201ea84(data_0217d400->mUnk_a4[0], data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    p = data_0217d400;
    q = &p->mUnk_2c[p->mUnk_04];
    w = func_020ab798();
    func_0214cffc(w, q, 0x18);
    func_02129b60();
    if (v == 1 || (func_020ab8c4() == 1 && (u16) (data_02175628[i].mUnk_00 & 1) != 0)) {
        p = data_0217d400;
        if (p->mUnk_1c[0] != 0) {
            p->mUnk_10 = 3;
            data_0217d400->mUnk_2c[2].mUnk_10 = 1;
            func_02125fc0();
            func_020ab8cc(1);
            data_0217d400->mUnk_24 = 0;
            func_0212ecc0(&data_0217d068, 0, 4);
        } else {
            func_0212ecc0(&data_0217d068, 0, 0x16);
        }
    } else if (v == 0 || (func_020ab8c4() == 2 && (u16) (data_02175628[i].mUnk_00 & 1) != 0)) {
        data_0217d400->mUnk_10 = 3;
        data_0217d400->mUnk_2c[2].mUnk_10 = 0;
        func_02125fc0();
        func_020ab8cc(2);
        data_0217d400->mUnk_24 = 0;
        func_0212ecc0(&data_0217d068, 0, 0xe);
    }
}

void func_0212982c(void) {
    Unk0217d400 *p;
    data_0217d400->mUnk_28++;
    data_0217d400->mUnk_84 = func_020ae4c0(1, 0, 0xc0, data_0217d400->mUnk_28, 0xf);
    data_0217d400->mUnk_86[0][1] =
        func_020ae4c0(1, data_0215d100[0][1], data_0215d108[0][1], data_0217d400->mUnk_28, 0xf);
    if (data_0217d400->mUnk_28 >= 0xf) {
        data_0217d400->mUnk_28 = 0xf;
    }
    if (data_0217d400->mUnk_28 >= 0xf && func_02125f88() != 0) {
        p = data_0217d400;
        if (p->mUnk_2c[2].mUnk_10 != 0) {
            func_0212a410();
            switch (func_02061104(&data_0217d400->mUnk_2c[2])) {
                case 1:
                    data_0217d400->mUnk_10 = 4;
                    func_021262f0((u32) func_020b3f7c(data_0217d400->mUnk_c0, 0xa));
                    data_0217d400->mUnk_28 = 0;
                    return;
                case 2:
                    data_0217d400->mUnk_10 = 4;
                    func_021262f0((u32) func_020b3f7c(data_0217d400->mUnk_c0, 0xb));
                    data_0217d400->mUnk_28 = 0;
                    return;
                default:
                    data_0217d400->mUnk_10 = 6;
                    func_02126638(func_020b3f7c(data_0217d400->mUnk_c0, 8), 0, 0, 0, 0, 0, 0);
                    data_0217d400->mUnk_28 = 0;
                    data_0217d400->mUnk_04 = 1;
                    if (data_021759d0->mUnk_00 == 0) {
                        data_0217d400->mUnk_08 = 1;
                    } else {
                        data_0217d400->mUnk_08 = 2;
                    }
                    func_020ab9d0(data_0217d400->mUnk_08);
                    func_020ab758(data_0215d0e0[1]);
                    func_0212a484();
                    func_02129e78();
                    func_02128b0c();
                    return;
            }
        } else {
            p->mUnk_2c[2].mUnk_16 = 0xc;
        }
    }
}

void func_021297cc(void) {
    Unk0217d400 *p;
    data_0217d400->mUnk_28++;
    if (func_02125f6c() != 0) {
        func_0212ecc0(&data_0217d068, 0, 0x15);
    }
    p = data_0217d400;
    if (p->mUnk_28 >= 0x78) {
        p->mUnk_10 = 1;
        func_02126638(func_020b3f7c(data_0217d400->mUnk_c0, 7), 0, 0, 0, 0, 0, 0);
        data_0217d400->mUnk_28 = 0;
    }
}

void func_02129788(void) {
    if (func_02036c5c() != 0) {
        data_0217d400->mUnk_10 = 6;
        func_02126638(func_020b3f7c(data_0217d400->mUnk_c0, 0xf), 0, 0, 0, 0, 0, 0);
        data_0217d400->mUnk_2c[2].mUnk_10 = 1;
    }
}
#pragma thumb off

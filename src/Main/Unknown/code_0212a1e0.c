#include "Main/Unknown/code_0212a1e0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02128884.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_02129788.h"
#include "Main/Unknown/code_02129cbc.h"
#include "Main/Unknown/code_02129000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/code_020aba94.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_0212a700.h"
#include "Main/Unknown/code_0212a724.h"
#include "Main/Unknown/code_0212abdc.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214cfe4.h"

#pragma thumb on

void func_0212a670(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        Unk0217d400 *p = data_0217d400;
        func_0212426c(1, data_0215d0e4[i][0], data_0217d400->mUnk_ac[i], func_020b3f7c(p->mUnk_c0, 4), p->mUnk_9c[i],
                      p->mUnk_74[i][1]);
        p = data_0217d400;
        func_0212426c(1, data_0215d0e4[i][1], data_0217d400->mUnk_ac[i], func_020b3f7c(p->mUnk_c0, 5), p->mUnk_9c[i],
                      p->mUnk_74[i][1]);
    }
}

void func_0212a604(void) {
    s32 i;
    s32 j;
    s32 k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 4; k++) {
                Unk02124b1c *p = &data_0217d400->mUnk_74[i][j][data_0215d0f8[i][k]];
                p->mUnk_08 = 1;
                p->mUnk_0c = 0;
                p->mUnk_0e = 0;
            }
        }
    }
}

void func_0212a4f4(void) {
    s32 i;
    s32 j;
    s32 k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 3; k++) {
                data_0217d400->mUnk_74[i][0][data_0215d128[i][j][k]].mUnk_00 = 0;
            }
            data_0217d400->mUnk_74[i][0][data_0215d0e4[i][j] + data_0217d400->mUnk_9c[i]->mUnk_06].mUnk_00 = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_0215d0e0[i]; j++) {
            data_0217d400->mUnk_74[i][0][data_0215d14c[i][j]].mUnk_00 = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        for (k = 0; k < 4; k++) {
            data_0217d400->mUnk_74[i][0][data_0215d0f8[i][k]].mUnk_00 = 0;
        }
    }
    for (j = 0; j < 10; j++) {
        data_0217d400->mUnk_74[1][0][data_0215d110[j]].mUnk_00 = 0;
    }
}

void func_0212a4bc(void) {
    u16 a[12];
    a[0] = 0;
    func_0214cfe4(a[0], &a[1], 0x1a);
    func_0214cffc(&data_0217d400->mUnk_2c[0], &a[1], 0x18);
    func_020ab7a4(&a[1]);
}

void func_0212a484(void) {
    u16 a[12];
    a[0] = 0;
    func_0214cfe4(a[0], &a[1], 0x16);
    func_0214cffc(&data_0217d400->mUnk_2c[1], &a[1], 0x14);
    func_020ab7a4(&a[1]);
}

void func_0212a448(void) {
    u16 a[12];
    a[0] = 0;
    func_0214cfe4(a[0], &a[1], 0x16);
    func_0214cffc(data_0217aa08->mUnk_00->mUnk_0c, &a[1], 0x14);
    func_020ab7a4(&a[1]);
}

void func_0212a410(void) {
    s32 i;
    func_0214d168(&data_0217d400->mUnk_2c[2], 0, 0xd);
    for (i = 0; i < 12; i++) {
        ((u8 *) &data_0217d400->mUnk_2c[2])[i] = data_0217d400->mUnk_2c[0].mUnk_00[i];
    }
}

void func_0212a1e0(void *a, s32 b) {
    volatile u16 d;
    Unk0212a1e0 c;
    s32 i;
    s32 j;
    data_0217d400 = func_02036bec(a, 0xc4);
    data_0217d400->mUnk_00 = a;
    data_0217d400->mUnk_bc = func_021250b0(a);
    func_0212abdc(a, func_02128898());
    c.mUnk_00 = 1;
    c.mUnk_04 = func_020b403c(1);
    c.mUnk_08 = 0;
    c.mUnk_0c = 1;
    c.mUnk_10 = 0;
    c.mUnk_14 = 0;
    c.mUnk_18 = 0;
    c.mUnk_1c = 0;
    c.mUnk_20 = 1;
    if (b == 0xc) {
        c.mUnk_24 = 1;
    } else {
        c.mUnk_24 = 0;
    }
    func_02125c2c();
    func_02125de0(a, &c);
    func_02129c18();
    func_02129cbc();
    func_020ae6d4(func_02128898(), func_02128884());
    func_020abcf4(0x20, 0x40, 0xc);
    func_020ab94c(0, 0x28);
    func_0212a700();
    func_020aba94(0);
    data_0217d400->mUnk_2c[2].mUnk_14 = b;
    data_0217d400->mUnk_2c[2].mUnk_16 = -1;
    if (b == 0xc) {
        data_0217d400->mUnk_04 = 0;
        data_0217d400->mUnk_0c = 0;
        data_0217d400->mUnk_1c[0] = 0;
        data_0217d400->mUnk_1c[1] = 1;
    } else {
        data_0217d400->mUnk_04 = 1;
        data_0217d400->mUnk_0c = 5;
        data_0217d400->mUnk_1c[0] = 1;
        if (b == 0xb) {
            data_0217d400->mUnk_1c[1] = 0;
        } else {
            data_0217d400->mUnk_1c[1] = 1;
        }
        func_0212a448();
    }
    if (data_0217d400->mUnk_04 == 0) {
        data_0217d400->mUnk_08 = 0;
        func_020ab758(data_0215d0e0[0]);
    } else {
        if (data_021759d0->mUnk_00 == 0) {
            data_0217d400->mUnk_08 = 1;
        } else {
            data_0217d400->mUnk_08 = 2;
        }
        func_020ab758(data_0215d0e0[1]);
    }
    func_020ab9d0(data_0217d400->mUnk_08);
    func_02129e78();
    for (i = 0; i < 2; i++) {
        data_0217d400->mUnk_14[i] = 0;
    }
    data_0217d400->mUnk_24 = 0;
    data_0217d400->mUnk_10 = data_0217d400->mUnk_0c;
    data_0217d400->mUnk_28 = 0;
    data_0217d400->mUnk_84 = 0xc0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            data_0217d400->mUnk_86[i][j] = data_0215d108[i][j];
        }
    }
    data_0217d400->mUnk_c0 = func_02047a28(data_0216ea60);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            func_02124ed0(a, data_0217d400->mUnk_9c[i], data_0217d400->mUnk_ac[i], &data_0217d400->mUnk_74[i][j]);
        }
    }
    func_0212a604();
    for (i = 0; i < 2; i++) {
        d = 0;
        func_0214cfe4(d, &data_0217d400->mUnk_2c[i], 0x18);
    }
    func_0212a724();
    func_0212a670();
    func_0212a4f4();
    func_02129ea4();
}
#pragma thumb off

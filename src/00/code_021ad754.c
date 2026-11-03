#include "00/code_021a998c.h"
#include "00/code_021ad754.h"
#include "00/code_021b0014.h"
#include "00/unk_021b6000.h"
#include "00/code_021a91b4.h"
#include "00/code_021ad018.h"
#include "00/code_021ad3b8.h"
#include "00/code_021ad36c.h"
#include "00/code_021ae2f4.h"
#include "00/code_021ae304.h"
#include "00/code_021adbac.h"
#include "00/unk_021b6380.h"
#include "code_0200db4c.h"
#include "code_0200f5ac.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_0216f000.h"

u8 *func_ov000_021ad754(u8 *a, u8 b, u32 *c) {
    u32 d;

    func_0214d168(a, 0, 0xec);
    *(u16 *) a = 0x101;
    a[2] = 6;
    data_ov000_021b63e0[0] = (s64) data_ov000_021b63e0[1] * (s64) data_ov000_021b63e0[0] + data_ov000_021b63e0[2];
    d = data_ov000_021b63e0[0] >> 32;
    if (c != NULL) {
        *c = d;
    }
    *(u16 *) (a + 4) = (u16) (d >> 16) >> 8 | (u16) (d >> 16) << 8;
    *(u16 *) (a + 6) = (u16) d >> 8 | (u16) d << 8;
    *(u16 *) (a + 0xc) = (u16) (data_ov000_021b63b4 >> 16) >> 8 | (u16) (data_ov000_021b63b4 >> 16) << 8;
    *(u16 *) (a + 0xe) = (u16) data_ov000_021b63b4 >> 8 | (u16) data_ov000_021b63b4 << 8;
    func_0214d1fc(data_ov000_021b63d0, a + 0x1c, 6);
    *(u16 *) (a + 0xec) = 0x8263;
    *(u16 *) (a + 0xee) = 0x6353;
    *(u16 *) (a + 0xf0) = 0x135;
    a[0xf2] = b;
    a[0xf3] = 0x3d;
    a[0xf4] = 7;
    a[0xf5] = 1;
    func_0214d1fc(data_ov000_021b63d0, a + 0xf6, 6);
    a[0xfc] = 0xc;
    a[0xfd] = 10;
    func_0214d1fc(data_ov000_021b4c34, a + 0xfe, 10);
    a[0x108] = 0x37;
    a[0x109] = 3;
    a[0x10a] = 1;
    a[0x10b] = 3;
    a[0x10c] = 6;
    return a + 0x10d;
}

void func_ov000_021ad898(void) {
    u32 a;
    u32 b;
    u32 c;
    BOOL d;
    s32 e;
    s32 i;
    Unk0200db5c *f;
    Unk021a998c *g;
    Unk021b6434 *h;
    Unk021b69dc *j;

    data_ov000_021b63b0 = 0;
    func_0214d168(&data_ov000_021b6494, 0, 0x64);
    data_ov000_021b6494.mUnk_3c = 0x180;
    data_ov000_021b6494.mUnk_40 = data_ov000_021b685c;
    data_ov000_021b6494.mUnk_48 = 0x180;
    data_ov000_021b6494.mUnk_4c = data_ov000_021b66dc;
    func_ov000_021ae304(&data_ov000_021b6494);
    b = 0;
    d = TRUE;
    a = 1;
    data_ov000_021b637c = 1;
    while (1) {
        func_0200dc3c(1000);
        if (data_ov000_021b63b0 != 0) {
            break;
        }
        c = func_0200f5ac() >> 16;
        if (data_ov000_021b6388() != 0) {
            a--;
            if (a == 0) {
                if ((data_ov000_021b6398 & 1) != 0) {
                    if (b == 0) {
                        func_ov000_021adb00();
                        b = 1;
                    }
                } else {
                    switch (b) {
                        case 0:
                            if (d != FALSE) {
                                data_ov000_021b637c = 2;
                                d = FALSE;
                            }
                            if (func_ov000_021ad36c() == 0 || func_ov000_021ad2b8(&a, 0) == 0) {
                                func_ov000_021adb00();
                                b = 3;
                            } else {
                                b = 1;
                            }
                            break;
                        case 1:
                            if (func_ov000_021ad2b8(&a, 1) == 0 && a < 0x3c) {
                                b = 2;
                            }
                            break;
                        case 2:
                            if (func_ov000_021ad2b8(&a, 2) != 0) {
                                b = 1;
                            } else if (a < 0x3c) {
                                func_ov000_021b04f8(3);
                                b = 0;
                                a = 1;
                            }
                            break;
                        case 3:
                            break;
                    }
                }
            }
        } else {
            func_ov000_021b04f8(1);
            b = 0;
            a = 1;
        }
        i = 0;
        h = data_ov000_021b6434;
        for (; i < 8; i++) {
            if (h->mUnk_00 != 0 && (s16) (c - h->mUnk_0a) > 0x3bd) {
                h->mUnk_00 = 0;
            }
            h++;
        }
        f = data_0216ff5c.mUnk_08;
        if (f != NULL) {
            do {
                g = *(Unk021a998c **) f->mUnk_a4;
                if (g != NULL && g->mThread != NULL) {
                    if (g->mState == 3 && (s32) (c - g->mStateStartTime) > 0x27) {
                        g->mState = 1;
                        g->mUnk_18 = g->mUnk_1a;
                        g->mUnk_1c = g->mUnk_20;
                    } else if (g->mState == 2 && (s32) (c - g->mStateStartTime) > 0x27 && g->mUnk_04 == 1) {
                        g->mState = 0;
                        g->mUnk_04 = 0;
                        func_0200df68(g->mThread);
                    }
                }
                f = f->mUnk_68;
            } while (f != NULL);
        }
        i = 0;
        j = data_ov000_021b69dc;
        for (; i < 8; i++) {
            if (j->mUnk_04 != 0 && (s32) (c - j->mUnk_2c) > 0xef) {
                data_ov000_021b63ac(j->mUnk_34);
                j->mUnk_04 = 0;
            }
            j++;
        }
        func_ov000_021a91cc(c);
        if (data_ov000_021b63a8 != NULL) {
            data_ov000_021b63a8();
        }
    }
    if ((data_ov000_021b6398 & 1) == 0 && b != 3) {
        func_ov000_021ad264();
    }
    func_ov000_021ae2f4();
}

void func_ov000_021adb00(void) {
    s32 a;

    data_ov000_021b6384();
    if (data_ov000_021b63b4 != 0) {
        func_ov000_021afc5c(data_ov000_021b63b4);
        func_0200dc3c(100);
        func_ov000_021afc5c(data_ov000_021b63b4);
        a = func_0200f5ac() >> 16;
        while (data_ov000_021b6388() != 0 && (s32) (func_0200f5ac() >> 16) - a < 0x17) {
            if (data_ov000_021b6368 != 0) {
                func_ov000_021b04f8(4);
                return;
            }
            func_0200dc3c(100);
        }
    }
}

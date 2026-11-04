#include "00/code_021a39d8.h"
#include "00/code_0218e3c4.h"
#include "00/code_021a3000.h"
#include "00/code_021a377c.h"
#include "00/code_021a37dc.h"
#include "00/code_021a3eb0.h"
#include "00/code_021a3e5c.h"
#include "00/code_021a3f78.h"
#include "00/code_021a4000.h"
#include "00/code_021a4480.h"
#include "00/code_021a88a8.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "code_02134d30.h"
#include "code_02135014.h"
#include "code_0214d018.h"
#include "00/code_021a41dc.h"
#include "00/code_0218e8c4.h"

void func_ov000_021a39d8(Unk021b5df4 *a, u16 b, u32 c, u32 d) {
    if (data_ov000_021b5df4 == NULL) {
        MemFill(a, 0, 12);
        a->mUnk_08 = b;
        a->mUnk_0a = 1;
        a->mUnk_04 = 1;
        a->mUnk_06 = 0;
        data_ov000_021b5df4 = a;
        func_ov000_021a397c(0);
        data_ov000_021b49f4 = d;
    }
}

void func_ov000_021a3a18(Unk021a3a18 *a, s32 b) {
    Unk021a4480 k;
    char t[0x14];
    s32 i;
    k.mUnk_800 = 0;
    func_ov000_021a4480((u32) &k, 3, (u32) a->mUnk_84);
    for (i = 0; i < data_ov000_021b5df8; i++) {
        sprintf(t, data_ov000_021b4388, i);
        func_ov000_021a471c((Unk021a471c *) &k, t);
        func_ov000_021a471c((Unk021a471c *) &k, func_ov000_021a8c6c(((Unk021b5dfc *) data_ov000_021b5dfc)[i]));
    }
    func_ov000_021a471c((Unk021a471c *) &k, data_ov000_021b4394);
    func_ov000_021a4760((Unk021a471c *) &k, a->mUnk_c0);
    func_ov000_021a471c((Unk021a471c *) &k, data_ov000_021b43a0);
    func_ov000_021a471c((Unk021a471c *) &k, a->mUnk_c8 != 0 ? data_ov000_021b43a8 : data_ov000_021b43ac);
    if (b != 0) {
        func_ov000_021a471c((Unk021a471c *) &k, data_ov000_021b43b0);
        func_ov000_021a4760((Unk021a471c *) &k, b);
    }
    func_ov000_021a471c((Unk021a471c *) &k, data_ov000_021b43c0);
    func_ov000_021a471c((Unk021a471c *) &k, a->mUnk_04);
    if (a->mUnk_a8 != 0) {
        func_ov000_021a471c((Unk021a471c *) &k, data_ov000_021b43cc);
        func_ov000_021a4760((Unk021a471c *) &k, a->mUnk_104);
        func_ov000_021a471c((Unk021a471c *) &k, data_ov000_021b43d8);
        func_ov000_021a4760((Unk021a471c *) &k, a->mUnk_108);
    }
    if (b != 2) {
        func_ov000_021a41a0((Unk021a4a08 *) a, (Unk021a471c *) &k, 0xff, NULL, 0xff, NULL, 0xff, NULL);
    } else if (0x800 - k.mUnk_800 >= 1) {
        k.mUnk_000[k.mUnk_800++] = 0;
    }
    func_ov000_0218e3e4(a->mUnk_00, &k, k.mUnk_800, 0, a->mUnk_cc, 8);
    a->mUnk_ac = func_ov000_0218e8c4();
    a->mUnk_b0 = a->mUnk_ac;
    if (b != 0) {
        a->mUnk_b4 = 0;
    }
}

void func_ov000_021a3bbc(Unk021a3a18 *a) {
    Unk021a4480 k;
    k.mUnk_800 = 0;
    func_ov000_021a4480((u32) &k, 8, (u32) a->mUnk_84);
    func_ov000_0218e3e4(a->mUnk_00, &k, k.mUnk_800, 0, a->mUnk_cc, 8);
    a->mUnk_b0 = func_ov000_0218e8c4();
}

void func_ov000_021a3c14(Unk021a3a18 *a, s8 *b, s32 c, void *d) {
    Unk021a4480 k;
    s32 t;
    s32 i;
    s8 *p5;
    s8 *p6;
    k.mUnk_800 = 0;
    if (a == NULL) {
        a = (Unk021a3a18 *) data_ov000_021b426c;
    }
    if (b[0] == 0x3b) {
        if (a->mUnk_d4 != NULL) {
            a->mUnk_d4(b, c, d);
            return;
        }
    } else if (b[0] == 0x5c) {
        func_ov000_021a3f78((Unk021a4a08 *) a, (Unk021a471c *) &k);
        func_ov000_0218e3e4(a->mUnk_00, &k, k.mUnk_800, 0, d, 8);
        return;
    } else if (c >= 7) {
        if ((u8) b[0] == 0xfe) {
            if ((u8) b[1] == 0xfd) {
                if (a->mUnk_b8 > 0) {
                    a->mUnk_b8 = 0;
                }
                t = b[2];
                p5 = b + 3;
                p6 = b + 7;
                c = c - 7;
                func_ov000_021a4480((u32) &k, t, (u32) p5);
                switch (t) {
                    case 0:
                        func_ov000_021a412c((Unk021a4a08 *) a, (Unk021a471c *) &k, (u8 *) p6, c);
                        break;
                    case 1:
                        if (c >= 13 && a->mUnk_a8 != 0) {
                            func_ov000_021a438c((Unk021a4a08 *) a, (const char *) (p6 + c - 13));
                        }
                        func_ov000_021a4418((Unk021a4a08 *) a, (Unk021a471c *) &k, (const char *) p6, c);
                        break;
                    case 2:
                        if (c > 0x20) {
                            c = 0x20;
                        }
                        k.mUnk_000[0] = 5;
                        memcpy(&k.mUnk_000[k.mUnk_800], p6, c);
                        k.mUnk_800 += c;
                        break;
                    case 4:
                        if (a->mUnk_b8 == -1) {
                            return;
                        }
                        for (i = 0; i < 4; i++) {
                            if (p5[i] != a->mUnk_84[i]) {
                                return;
                            }
                        }
                        if (c < 2) {
                            return;
                        }
                        a->mUnk_b8 = -1;
                        a->mUnk_9c(p6[0], (u8 *) (p6 + 1), a->mUnk_10c);
                        return;
                    case 6:
                        for (i = 0; i < 4; i++) {
                            if (p5[i] != a->mUnk_84[i]) {
                                return;
                            }
                        }
                        if (c < 4) {
                            return;
                        }
                        k.mUnk_000[0] = 7;
                        __memcpy(&k.mUnk_000[k.mUnk_800], p6, 4);
                        k.mUnk_800 += 4;
                        __memcpy(&i, p6, 4);
                        if (func_ov000_021a3e5c(a, i) == 0) {
                            func_ov000_021a3eb0(a, (u8 *) (p6 + 4), c - 4);
                        }
                        break;
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    default:
                        return;
                }
                func_ov000_0218e3e4(a->mUnk_00, &k, k.mUnk_800, 0, d, 8);
            }
        }
    }
}

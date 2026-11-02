#include "00/code_0219bb68.h"
#include "00/code_0218eb9c.h"
#include "00/code_0219c93c.h"
#include "00/unk_021b5000.h"
#include "00/code_0219cc00.h"
#include "00/code_0219c954.h"
#include "Main/Unknown/code_02152000.h"
#include "00/code_0219c000.h"
#include "code_02139f70.h"
#include "00/code_0219d128.h"
#include "00/code_021988e8.h"
#include "00/code_0219b8a8.h"
#include "00/code_0218d000.h"
#include "00/code_0218f15c.h"
#include "00/code_021a3760.h"
#include "00/code_02198a8c.h"

#include "00/code_0219b000.h"
#include "00/code_0219b580.h"
#include "00/code_0219c384.h"
#include "00/code_0219c39c.h"
#include "00/code_0219d000.h"
#include "00/code_021a10b0.h"
#include "00/code_021a1ae0.h"
#include "00/unk_021b4000.h"
#include "code_0214d018.h"
#include "00/code_02188720.h"
#include "00/code_0219b8bc.h"
#include "00/code_02185984.h"
#include "03/code_021b94b8.h"
#include "00/code_021a369c.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a4784.h"
#include "00/code_0218a000.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/code_0218b434.h"
#include "00/code_0219caac.h"
#include "00/code_0219746c.h"
#include "00/code_021971ec.h"
#include "00/code_021a31a4.h"

void func_ov000_0219c1e4(void *a, void *b, s32 c, const char *d, const char *e, s32 f, s32 g, void *h, s32 i) {
    u32 n;
    u32 m;
    data_ov000_021b54c8 = a;
    func_ov000_0219c3b0();
    data_ov000_021b54c8->mUnk_00 = 0;
    data_ov000_021b54c8->mUnk_04 = func_ov000_021a1b2c;
    data_ov000_021b54c8->mUnk_08 = func_ov000_0219b4a4;
    data_ov000_021b54c8->mUnk_0c = (s32(*)()) func_ov000_0219b27c;
    data_ov000_021b54c8->mUnk_10 = func_ov000_0219b274;
    data_ov000_021b54c8->mUnk_14 = f == 0 ? 0x2000 : f;
    data_ov000_021b54c8->mUnk_18 = g == 0 ? 0x2000 : g;
    data_ov000_021b54c8->mUnk_1c.mUnk_00 = 0;
    data_ov000_021b54c8->mUnk_20 = b;
    data_ov000_021b54c8->mUnk_24 = 0;
    data_ov000_021b54c8->mUnk_28 = 0;
    data_ov000_021b54c8->mUnk_2c = 0;
    data_ov000_021b54c8->mUnk_2d = 0;
    data_ov000_021b54c8->mUnk_2e = 0;
    data_ov000_021b54c8->mUnk_30 = 0;
    data_ov000_021b54c8->mUnk_54 = data_ov000_021b4e84;
    data_ov000_021b54c8->mUnk_58 = data_ov000_021b4f84;
    data_ov000_021b54c8->mUnk_5c = 0;
    data_ov000_021b54c8->mUnk_60 = 0;
    data_ov000_021b54c8->mUnk_64 = 0;
    data_ov000_021b54c8->mUnk_68 = 0;
    data_ov000_021b54c8->mUnk_6c = 0;
    data_ov000_021b54c8->mUnk_70 = 0;
    data_ov000_021b54c8->mUnk_74 = 0;
    data_ov000_021b54c8->mUnk_78 = 0;
    data_ov000_021b54c8->mUnk_7c = 0;
    data_ov000_021b54c8->mUnk_80 = 0;
    func_ov000_0219b964();
    func_ov000_0219caac(&data_ov000_021b54c8->mUnk_84, b, &data_ov000_021b54c8->mUnk_1c, c,
                        ((Unk02152500 *) b)->mUnk_24, func_ov000_0219b6c0, 0);
    func_ov000_0219d8c8(&data_ov000_021b54c8->mUnk_2e8, &data_ov000_021b54c8->mUnk_1c, data_ov000_021b54c8->mUnk_34, h,
                        i);
    func_ov000_021a2870(&data_ov000_021b54c8->mUnk_33c, &data_ov000_021b54c8->mUnk_1c, &data_ov000_021b54c8->mUnk_00,
                        &data_ov000_021b54c8->mUnk_04, data_ov000_021b4e84, data_ov000_021b4f84, h, i);
    func_ov000_021a31a4(&data_ov000_021b54c8->mUnk_7a0);
    if (strlen((const u8 *) d) < 0x100) {
        n = strlen((const u8 *) d);
    } else {
        n = 0xff;
    }
    func_0214d1fc(d, data_ov000_021b4e84, n);
    data_ov000_021b4e84[n] = 0;
    if (strlen((const u8 *) e) < 0x100) {
        m = strlen((const u8 *) e);
    } else {
        m = 0xff;
    }
    func_0214d1fc(e, data_ov000_021b4f84, m);
    data_ov000_021b4f84[m] = 0;
}

void func_ov000_0219c0f4(void) {
    if (data_ov000_021b54c8 != 0) {
        if (data_ov000_021b54c8->mUnk_33c.mUnk_10 != 0) {
            func_ov000_021a47ac(data_ov000_021b54c8->mUnk_33c.mUnk_10);
            data_ov000_021b54c8->mUnk_33c.mUnk_10 = 0;
        }
        data_ov000_021b54c8->mUnk_33c.mUnk_18 = 0;
        if (data_ov000_021b54c8->mUnk_33c.mUnk_e4 != 0) {
            func_ov000_0218b64c(data_ov000_021b54c8->mUnk_33c.mUnk_e4);
            data_ov000_021b54c8->mUnk_33c.mUnk_e4 = 0;
        }
        func_ov000_0219b110();
        func_ov000_02197634();
        if (data_ov000_021b54c8->mUnk_1c.mUnk_00 != 0) {
            func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 0, 0, 0);
            func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 3, 0, 0);
            func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 1, 0, 0);
            func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 2, 0, 0);
            func_ov000_0218f268(&data_ov000_021b54c8->mUnk_1c);
            func_ov000_0218f2a0(&data_ov000_021b54c8->mUnk_1c);
            data_ov000_021b54c8->mUnk_1c.mUnk_00 = 0;
        }
        func_ov000_0219c954();
        func_ov000_0219d4f8();
        func_ov000_021a1430();
        func_ov000_021a2fec();
        if (data_ov000_021b54c8->mUnk_00 != 0) {
            func_ov000_02198ab0(data_ov000_021b54c8->mUnk_00);
            data_ov000_021b54c8->mUnk_00 = 0;
        }
        data_ov000_021b54c8 = 0;
    }
}

u32 func_ov000_0219c0c8(void) {
    int v1;
    func_ov000_021a3884();
    v1 = func_ov000_021a3760();
    if (v1 != 0) {
        func_ov000_0219c384(9, 0);
        func_ov000_021a37dc();
        return 1;
    }
    return 0;
}

void func_ov000_0219c0c4(void) {
    return;
}

void func_ov000_0219bf10(void) {
    if (func_ov000_0219c0c8() != 0) {
        func_ov000_0219c0c4();
    }
    if (data_ov000_021b54c8 == 0) {
        return;
    }
    if (data_ov000_021b54c8->mUnk_24 == 0) {
        return;
    }
    if (func_ov000_0219c39c() != 0) {
        return;
    }
    switch (data_ov000_021b54c8->mUnk_24) {
        case 1:
            switch (func_ov000_0218d574()) {
                case 1:
                    if (func_ov000_0219b77c(func_ov000_0218f2b8(&data_ov000_021b54c8->mUnk_1c,
                                                                data_ov000_021b54c8->mUnk_84.mUnk_08, 0)) != 0) {
                        return;
                    }
                    if (func_ov000_0219b77c(func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 0,
                                                                (void (*)(void *, void *, u32)) func_ov000_0219b580,
                                                                0)) != 0) {
                        return;
                    }
                    if (func_ov000_0219b77c(func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 3,
                                                                (void (*)(void *, void *, u32)) func_ov000_0219b4b4,
                                                                0)) != 0) {
                        return;
                    }
                    if (func_ov000_0219b77c(func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 1,
                                                                (void (*)(void *, void *, u32)) func_ov000_0219d708,
                                                                0)) != 0) {
                        return;
                    }
                    if (func_ov000_0219b77c(func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 2,
                                                                (void (*)(void *, void *, u32)) func_ov000_0219d674,
                                                                0)) != 0) {
                        return;
                    }
                    func_ov000_0219b8a8(2);
                    func_ov000_0219ca84();
                    break;
                case 2:
                    func_ov000_0219c990(3, -20110);
                    return;
                case 3:
                    func_ov000_0219c990(4, -20101);
                    return;
            }
            break;
        case 2:
            func_ov000_0219c9d8();
            break;
        case 3:
        case 4:
            func_ov000_0219d81c();
            func_ov000_021a1ef4(0);
            break;
        case 5:
            func_ov000_021a1ef4(1);
            func_ov000_0219d81c();
            break;
        case 6:
            func_ov000_021a3030();
            func_ov000_0219d81c();
            if (data_ov000_021b54c8->mUnk_33c.mUnk_15 == 2 || data_ov000_021b54c8->mUnk_33c.mUnk_15 == 3) {
                func_ov000_021a1ef4(1);
            } else if (data_ov000_021b54c8->mUnk_00 != 0) {
                func_ov000_021a1ef4(0);
            }
            break;
    }
    if (data_ov000_021b54c8->mUnk_33c.mUnk_18 == 1) {
        if (data_ov000_021b54c8->mUnk_33c.mUnk_10 != 0) {
            func_ov000_021a47ac(data_ov000_021b54c8->mUnk_33c.mUnk_10);
            data_ov000_021b54c8->mUnk_33c.mUnk_10 = 0;
        }
        data_ov000_021b54c8->mUnk_33c.mUnk_18 = 0;
    }
}

void func_ov000_0219bea8(u32 a, u32 b, void (*c)(s32 a), u32 d) {
    if (func_ov000_0219c39c() == 0) {
        if (data_ov000_021b54c8->mUnk_24 == 0) {
            data_ov000_021b54c8->mUnk_5c = c;
            data_ov000_021b54c8->mUnk_60 = d;
            data_ov000_021b54c8->mUnk_84.mUnk_10 = a;
            data_ov000_021b54c8->mUnk_84.mUnk_14 = b;
            if (func_ov000_021a3810() != 4) {
                func_ov000_0219c990(2, -60010);
                return;
            }
            func_ov000_0219b8a8(1);
            func_ov000_0218d6e4(data_ov000_021b54c8->mUnk_54);
        }
    }
}

s32 func_ov000_0219bdec(const s8 *a, void (*b)(s32, s32), void *c, void (*d)(u32, u8), void *e, void (*f)(u32, u32),
                        void *g) {
    Unk021b54c8 *p;
    u32 n;
    if (data_ov000_021b54c8 == 0 || func_ov000_0219c39c() != 0 || (p = data_ov000_021b54c8)->mUnk_24 < 3 ||
        p->mUnk_24 == 4) {
        return 0;
    }
    if (a == 0 || *a == 0) {
        n = 0;
    } else {
        if (strlen((const u8 *) a) < 0x20) {
            n = strlen((const u8 *) a);
        } else {
            n = 0x1f;
        }
        func_0214d1fc(a, p->mUnk_34, n);
    }
    data_ov000_021b54c8->mUnk_34[n] = 0;
    data_ov000_021b54c8->mUnk_64 = b;
    data_ov000_021b54c8->mUnk_68 = c;
    func_ov000_0219b8a8(4);
    func_ov000_0219d770((s32) data_ov000_021b54c8->mUnk_84.mUnk_4c, (const u8 *) data_ov000_021b54c8->mUnk_84.mUnk_14c,
                        (void (*)(s32, u8, void *)) func_ov000_0219b694, 0, (void (*)(s32, u8, void *, void *)) d, e,
                        (void (*)(s32, s32, void *)) f, g);
    return 1;
}

void func_ov000_0219bd90(u32 a, void *b, void *c, void *d, void *e, u32 f) {
    if (func_ov000_0219c39c() == 0 && data_ov000_021b54c8->mUnk_24 == 3) {
        func_ov000_0219b964();
        data_ov000_021b54c8->mUnk_6c = (void (*)(u32, u32, void *)) c;
        data_ov000_021b54c8->mUnk_70 = d;
        func_ov000_0219b8a8(5);
        func_ov000_021a260c((u8) (a - 1), b, (u32) func_ov000_0219b5a8, 0, (u32) e, f);
    }
}

void func_ov000_0219bc78(void *a, u32 b, u32 c, u32 d, void *e, void *f, u32 g, u32 h) {
    u8 s[0x40];
    u8 t[0x40];
    u8 i;
    u8 j;
    u8 n;
    if (func_ov000_0219c39c() == 0 && data_ov000_021b54c8->mUnk_24 == 3) {
        func_ov000_0219b964();
        data_ov000_021b54c8->mUnk_6c = (void (*)(u32, u32, void *)) e;
        data_ov000_021b54c8->mUnk_70 = f;
        func_ov000_0219b8a8(5);
        if (a != 0) {
            func_ov000_021a2468(a, b, (u8) (c - 1), d, func_ov000_0219b5a8, 0, g, h);
            return;
        }
        i = 0;
        b = 0;
        for (; i < func_ov000_0219d660(); i++) {
            t[i] = func_ov000_021a3448(0x80) + 1;
            b++;
        }
        i = 0;
        for (; i < func_ov000_0219d660(); i++) {
            if (t[i] != 0) {
                j = 0;
                n = 0;
                for (; j < func_ov000_0219d660(); j++) {
                    if (i != j && t[i] < t[j]) {
                        n++;
                    }
                }
                s[n] = i;
            }
        }
        func_ov000_021a2468(s, b, (u8) (c - 1), d, func_ov000_0219b5a8, 0, g, h);
    }
}

s32 func_ov000_0219bbfc(void) {
    Unk021b54c8 *p;
    if (data_ov000_021b54c8 == 0 || func_ov000_0219c39c() != 0 ||
        ((p = data_ov000_021b54c8)->mUnk_24 != 5 && p->mUnk_24 != 6)) {
        return -1;
    }
    if (p->mUnk_33c.mUnk_0d == 0) {
        func_ov000_0219d558(1, data_ov000_021b4054, 0);
        func_ov000_0219b110();
        func_ov000_0219b8a8(3);
        return 1;
    }
    p->mUnk_2d = 1;
    func_ov000_021988e8(data_ov000_021b54c8->mUnk_00);
    data_ov000_021b54c8->mUnk_2d = 0;
    return 0;
}

s32 func_ov000_0219bbac(s32 a) {
    u32 p;
    if (data_ov000_021b54c8 == 0 || func_ov000_0219c39c() != 0 ||
        (data_ov000_021b54c8->mUnk_24 != 5 && data_ov000_021b54c8->mUnk_24 != 6)) {
        return -1;
    }
    p = func_ov000_0219b9d4(a);
    if (p == 0) {
        return -2;
    }
    func_ov000_02198908((void *) p);
    return 0;
}

s32 func_ov000_0219bb68(void) {
    if (data_ov000_021b54c8 == 0) {
        return 0;
    }
    if (data_ov000_021b54c8->mUnk_33c.mUnk_15 == 2 || data_ov000_021b54c8->mUnk_33c.mUnk_15 == 3) {
        return func_ov000_021a15f8() + 1;
    }
    return func_ov000_021a160c() + 1;
}

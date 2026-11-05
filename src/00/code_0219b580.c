#include "00/code_0219b580.h"

#include "00/code_0219b000.h"
#include "00/code_0219c954.h"
#include "00/unk_021b5000.h"
#include "00/code_021a10b0.h"
#include "00/code_021a17bc.h"
#include "00/code_0219c000.h"
#include "00/code_021a01dc.h"
#include "00/code_0219a654.h"
#include "00/code_02188720.h"
#include "00/code_0219b1f8.h"
#include "00/code_02198a8c.h"
#include "00/code_0219887c.h"
#include "00/code_0219a000.h"
#include "00/code_021a3264.h"
#include "00/code_02198a84.h"
#include "00/code_021a1ae0.h"
#include "code_0214d018.h"
#include "00/code_0218d488.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0219c93c.h"
#include "00/code_021a3760.h"
#include "00/code_0219cc00.h"
#include "Main/Unknown/code_02152000.h"
#include "code_02139f70.h"
#include "00/code_0219d128.h"
#include "00/code_021988e8.h"
#include "00/code_0218d000.h"
#include "00/code_0218f15c.h"
#include "00/code_0219c384.h"
#include "00/code_0219d000.h"
#include "00/unk_021b4000.h"
#include "code_0200fc8c.h"
#include "00/unk_021b1000.h"
#include "code_02151868.h"
#include "code_021519d4.h"
#include "00/code_02186a9c.h"
#include "00/code_021acef8.h"
#include "00/code_021a6c08.h"
#include "00/code_0218a67c.h"
#include "00/code_021a6934.h"
#include "00/code_02185954.h"
#include "03/code_021b94b8.h"
#include "00/code_021a369c.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a3a18.h"
#include "00/code_0218a000.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/code_0218aea4.h"
#include "00/code_0219caac.h"
#include "00/code_0219742c.h"
#include "00/code_02196960.h"

void func_ov000_0219c1e4(void *a, void *b, s32 c, const char *d, const char *e, s32 f, s32 g, void *h, s32 i) {
    u32 n;
    u32 m;
    data_ov000_021b54c8 = a;
    func_ov000_0219c3b0();
    data_ov000_021b54c8->mUnk_00 = NULL;
    data_ov000_021b54c8->mUnk_04 = func_ov000_021a1b2c;
    data_ov000_021b54c8->mUnk_08 = func_ov000_0219b4a4;
    data_ov000_021b54c8->mUnk_0c = (s32(*)()) func_ov000_0219b27c;
    data_ov000_021b54c8->mUnk_10 = func_ov000_0219b274;
    data_ov000_021b54c8->mUnk_14 = f == 0 ? 0x2000 : f;
    data_ov000_021b54c8->mUnk_18 = g == 0 ? 0x2000 : g;
    data_ov000_021b54c8->mUnk_1c.mGpiConnection = NULL;
    data_ov000_021b54c8->mUnk_20 = b;
    data_ov000_021b54c8->mUnk_24 = 0;
    data_ov000_021b54c8->mUnk_28 = 0;
    data_ov000_021b54c8->mUnk_2c = 0;
    data_ov000_021b54c8->mUnk_2d = 0;
    data_ov000_021b54c8->mUnk_2e = 0;
    data_ov000_021b54c8->mUnk_30 = 0;
    data_ov000_021b54c8->mUnk_54 = data_ov000_021b4e84;
    data_ov000_021b54c8->mUnk_58 = data_ov000_021b4f84;
    data_ov000_021b54c8->mUnk_5c = NULL;
    data_ov000_021b54c8->mUnk_60 = 0;
    data_ov000_021b54c8->mUnk_64 = NULL;
    data_ov000_021b54c8->mUnk_68 = NULL;
    data_ov000_021b54c8->mUnk_6c = NULL;
    data_ov000_021b54c8->mUnk_70 = NULL;
    data_ov000_021b54c8->mUnk_74 = NULL;
    data_ov000_021b54c8->mUnk_78 = NULL;
    data_ov000_021b54c8->mUnk_7c = NULL;
    data_ov000_021b54c8->mUnk_80 = NULL;
    func_ov000_0219b964();
    func_ov000_0219caac(&data_ov000_021b54c8->mUnk_84, b, &data_ov000_021b54c8->mUnk_1c, c,
                        ((Unk02152500 *) b)->mUnk_24, func_ov000_0219b6c0, NULL);
    func_ov000_0219d8c8(&data_ov000_021b54c8->mUnk_2e8, &data_ov000_021b54c8->mUnk_1c, data_ov000_021b54c8->mUnk_34, h,
                        i);
    func_ov000_021a2870(&data_ov000_021b54c8->mUnk_33c, &data_ov000_021b54c8->mUnk_1c, &data_ov000_021b54c8->mUnk_00,
                        &data_ov000_021b54c8->mUnk_04, data_ov000_021b4e84, data_ov000_021b4f84, h, i);
    func_ov000_021a31a4(&data_ov000_021b54c8->mUnk_7a0);
    if (strlen(d) < 0x100) {
        n = strlen(d);
    } else {
        n = 0xff;
    }
    MemCopy(d, data_ov000_021b4e84, n);
    data_ov000_021b4e84[n] = 0;
    if (strlen(e) < 0x100) {
        m = strlen(e);
    } else {
        m = 0xff;
    }
    MemCopy(e, data_ov000_021b4f84, m);
    data_ov000_021b4f84[m] = 0;
}

void func_ov000_0219c0f4(void) {
    if (data_ov000_021b54c8 != NULL) {
        if (data_ov000_021b54c8->mUnk_33c.mUnk_10 != NULL) {
            func_ov000_021a47ac(data_ov000_021b54c8->mUnk_33c.mUnk_10);
            data_ov000_021b54c8->mUnk_33c.mUnk_10 = NULL;
        }
        data_ov000_021b54c8->mUnk_33c.mUnk_18 = 0;
        if (data_ov000_021b54c8->mUnk_33c.mUnk_e4 != NULL) {
            func_ov000_0218b64c(data_ov000_021b54c8->mUnk_33c.mUnk_e4);
            data_ov000_021b54c8->mUnk_33c.mUnk_e4 = NULL;
        }
        func_ov000_0219b110();
        GstatsClose();
        if (data_ov000_021b54c8->mUnk_1c.mGpiConnection != NULL) {
            func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 0, NULL, 0);
            func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 3, NULL, 0);
            func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 1, NULL, 0);
            func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 2, NULL, 0);
            GpUpdate(&data_ov000_021b54c8->mUnk_1c);
            func_ov000_0218f2a0(&data_ov000_021b54c8->mUnk_1c);
            data_ov000_021b54c8->mUnk_1c.mGpiConnection = NULL;
        }
        func_ov000_0219c954();
        func_ov000_0219d4f8();
        func_ov000_021a1430();
        func_ov000_021a2fec();
        if (data_ov000_021b54c8->mUnk_00 != NULL) {
            func_ov000_02198ab0(data_ov000_021b54c8->mUnk_00);
            data_ov000_021b54c8->mUnk_00 = NULL;
        }
        data_ov000_021b54c8 = NULL;
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
    if (data_ov000_021b54c8 == NULL) {
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
                    if (func_ov000_0219b77c(GpInitialize(&data_ov000_021b54c8->mUnk_1c,
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
            } else if (data_ov000_021b54c8->mUnk_00 != NULL) {
                func_ov000_021a1ef4(0);
            }
            break;
    }
    if (data_ov000_021b54c8->mUnk_33c.mUnk_18 == 1) {
        if (data_ov000_021b54c8->mUnk_33c.mUnk_10 != NULL) {
            func_ov000_021a47ac(data_ov000_021b54c8->mUnk_33c.mUnk_10);
            data_ov000_021b54c8->mUnk_33c.mUnk_10 = NULL;
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

BOOL func_ov000_0219bdec(const s8 *a, void (*b)(s32, s32), void *c, void (*d)(u32, u8), void *e, void (*f)(u32, u32),
                         void *g) {
    Unk021b54c8 *p;
    u32 n;
    if (data_ov000_021b54c8 == NULL || func_ov000_0219c39c() != 0 || (p = data_ov000_021b54c8)->mUnk_24 < 3 ||
        p->mUnk_24 == 4) {
        return FALSE;
    }
    if (a == NULL || *a == 0) {
        n = 0;
    } else {
        if (strlen((const char *) a) < 0x20) {
            n = strlen((const char *) a);
        } else {
            n = 0x1f;
        }
        MemCopy(a, p->mUnk_34, n);
    }
    data_ov000_021b54c8->mUnk_34[n] = 0;
    data_ov000_021b54c8->mUnk_64 = b;
    data_ov000_021b54c8->mUnk_68 = c;
    func_ov000_0219b8a8(4);
    func_ov000_0219d770((s32) data_ov000_021b54c8->mUnk_84.mUnk_4c, data_ov000_021b54c8->mUnk_84.mUnk_14c,
                        (void (*)(s32, u8, void *)) func_ov000_0219b694, NULL, (void (*)(s32, u8, void *, void *)) d, e,
                        (void (*)(s32, s32, void *)) f, g);
    return TRUE;
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
        if (a != NULL) {
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
    if (data_ov000_021b54c8 == NULL || func_ov000_0219c39c() != 0 ||
        ((p = data_ov000_021b54c8)->mUnk_24 != 5 && p->mUnk_24 != 6)) {
        return -1;
    }
    if (p->mUnk_33c.mUnk_0d == 0) {
        func_ov000_0219d558(1, data_ov000_021b4054, NULL);
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
    void *p;
    if (data_ov000_021b54c8 == NULL || func_ov000_0219c39c() != 0 ||
        (data_ov000_021b54c8->mUnk_24 != 5 && data_ov000_021b54c8->mUnk_24 != 6)) {
        return -1;
    }
    p = func_ov000_0219b9d4(a);
    if (p == NULL) {
        return -2;
    }
    func_ov000_02198908(p);
    return 0;
}

s32 func_ov000_0219bb68(void) {
    if (data_ov000_021b54c8 == NULL) {
        return 0;
    }
    if (data_ov000_021b54c8->mUnk_33c.mUnk_15 == 2 || data_ov000_021b54c8->mUnk_33c.mUnk_15 == 3) {
        return func_ov000_021a15f8() + 1;
    }
    return func_ov000_021a160c() + 1;
}

u8 func_ov000_0219bb50(void) {
    if (data_ov000_021b54c8 != NULL) {
        return data_ov000_021b54c8->mUnk_2c;
    }
    return 0;
}

s32 func_ov000_0219bb04(u8 **a) {
    if (data_ov000_021b54c8 == NULL) {
        return 0;
    }
    *a = data_ov000_021b54c8->mUnk_33c.mUnk_2b8;
    if (data_ov000_021b54c8->mUnk_33c.mUnk_15 == 2 || data_ov000_021b54c8->mUnk_33c.mUnk_15 == 3) {
        return func_ov000_021a1514((void **) a);
    }
    return func_ov000_021a158c((void **) a);
}

s32 func_ov000_0219bac8(u32 a) {
    if (data_ov000_021b54c8 == NULL) {
        return 0;
    }
    if ((data_ov000_021b54c8->mUnk_33c.mUnk_2d8 & (1 << a)) != 0) {
        return func_ov000_0219b8bc(a);
    }
    return 0;
}

u32 func_ov000_0219bab4(void) {
    if (data_ov000_021b54c8 != NULL) {
        return data_ov000_021b54c8->mUnk_24;
    }
    return 0;
}

s32 func_ov000_0219ba20(void) {
    Unk021b54c8 *p;
    u32 v;
    s32 r;
    if (data_ov000_021b54c8->mUnk_00 != NULL) {
        return 0;
    }
    v = (u16) (func_ov000_021a3448(0x4000) + 0xc000);
    p = data_ov000_021b54c8;
    r = func_ov000_02198ac4((Gt2Socket **) data_ov000_021b54c8, (const char *) Gt2FormatAddress(0, v, 0), p->mUnk_14,
                            p->mUnk_18, (u32) func_ov000_0219b240);
    if (func_ov000_0219b704(r) != 0) {
        return r;
    }
    func_ov000_02198a84(data_ov000_021b54c8->mUnk_00, func_ov000_021a1ca8);
    SetUnmatchedDataCallback(data_ov000_021b54c8->mUnk_00, (UnkWordFunc *) func_ov000_021a1e40);
    return r;
}

void *func_ov000_0219b9d4(u32 a) {
    s32 i;
    void **p;
    if (data_ov000_021b54c8 == NULL) {
        return NULL;
    }
    i = 0;
    p = data_ov000_021b54d0;
    for (; i < 32; p++, i++) {
        if (*p != NULL && a == func_ov000_0219887c(*p)[1]) {
            return data_ov000_021b54d0[i];
        }
    }
    return NULL;
}

u8 func_ov000_0219b9c4(Unk0219887c *object) {
    return func_ov000_0219887c(object)[1];
}

u32 func_ov000_0219b9b4(Unk0219887c *object) {
    return func_ov000_0219887c(object)[0];
}

s32 func_ov000_0219b998(void) {
    s32 i = 0;
    void **slot = data_ov000_021b54d0;
    for (; i < 32; slot++, i++) {
        if (*slot == NULL) {
            return i;
        }
    }
    return -1;
}

void func_ov000_0219b964(void) {
    func_0214d018_inline(data_ov000_021b54d0, 0x80);
    func_0214d018_inline(data_ov000_021b5550, 0x100);
}

void **func_ov000_0219b958(s32 index) {
    return &data_ov000_021b54d0[index];
}

void **func_ov000_0219b8fc(u32 a, s32 b) {
    u8 c;

    for (c = 0; c < b; c++) {
        if (a == data_ov000_021b54c8->mUnk_33c.mUnk_f4[c]) {
            break;
        }
    }
    if (c >= b) {
        return NULL;
    }
    return func_ov000_0219b958(func_ov000_0219b9b4(func_ov000_0219b9d4(data_ov000_021b54c8->mUnk_33c.mUnk_2b8[c])));
}

Unk021b5550 *func_ov000_0219b8f0(s32 index) {
    return &data_ov000_021b5550[index];
}

BOOL func_ov000_0219b8bc(u32 a) {
    s32 b;

    for (b = 0; b < 0x20; b++) {
        if (data_ov000_021b54d0[b] != NULL && a == func_ov000_0219887c(data_ov000_021b54d0[b])[1]) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_ov000_0219b8a8(s32 value) {
    data_ov000_021b54c8->mUnk_28 = data_ov000_021b54c8->mUnk_24;
    data_ov000_021b54c8->mUnk_24 = value;
}

u32 func_ov000_0219b868(u32 a) {
    void *b;
    s32 d;
    s32 e;

    d = func_ov000_021a158c(&b);
    for (e = 0; e < d; e++) {
        if (a == ((u8 *) b)[e]) {
            break;
        }
    }
    if (e == d) {
        return 0;
    }
    return func_ov000_021a1620(e, d);
}

u32 func_ov000_0219b844(const u8 *values, s32 count) {
    u32 mask = 0;
    s32 i;
    for (i = 0; i < count; i++) {
        mask |= 1 << values[i];
    }
    return mask;
}

int func_ov000_0219b77c(int c) {
    s32 a;
    s32 b;

    if (c == 0) {
        return 0;
    }
    switch (c) {
        case 1:
            a = 0xb;
            b = -1;
            break;
        case 2:
            a = 0xb;
            b = -2;
            break;
        case 3:
            a = 6;
            b = -10;
            break;
        case 4:
            a = 6;
            b = -20;
            break;
    }
    switch (data_ov000_021b54c8->mUnk_24) {
        case 1:
            b -= 0xee48;
            func_ov000_0219c990(a, b);
            break;
        case 2:
            b -= 0xee48;
            func_ov000_0219c990(a, b);
            break;
        case 5:
            b -= 0x13c68;
            func_ov000_021a1a38(a, b);
            break;
        case 4:
            b -= 0x11558;
            break;
        default:
            b -= 0x16378;
            break;
    }
    func_ov000_0219d734(a, b);
    return c;
}

u32 func_ov000_0219b704(u32 a) {
    s32 b;
    s32 c;

    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 0xb;
            c = -1;
            break;
        case 2:
        case 5:
            b = 0;
            c = 0;
            a = 0;
            break;
        case 3:
            b = 6;
            c = -10;
            break;
        case 4:
            b = 6;
            c = -30;
            break;
        case 6:
            b = 6;
            c = -70;
            break;
        case 7:
            b = 6;
            c = -80;
            break;
    }
    if (b != 0) {
        func_ov000_0219c990(b, c - 0x105b8);
    }
    return a;
}

void func_ov000_0219b6c0(int a, u32 b) {
    UnkFunc *v1;
    if (a == 0) {
        data_ov000_021b54c8->mUnk_30 = b;
        func_ov000_0219b8a8(3);
        func_ov000_0219d5bc();
    } else {
        func_ov000_0219b8a8(0);
    }
    v1 = data_ov000_021b54c8->mUnk_5c;
    if (v1 != NULL) {
        (*v1)(a, b, data_ov000_021b54c8->mUnk_60);
    }
    return;
}

void func_ov000_0219b694(u32 a, u32 b) {
    func_ov000_0219b8a8((u32) (data_ov000_021b54c8->mUnk_28));
    data_ov000_021b54c8->mUnk_64(a, b, data_ov000_021b54c8->mUnk_68);
    return;
}

void func_ov000_0219b5a8(u32 a, u32 b, u32 c, u32 d, u32 e) {
    s32 f;
    Unk021b54c8 *h;

    if (a == 0 && b != 0) {
        if (data_ov000_021b54c8->mUnk_33c.mUnk_198 == 0) {
            func_ov000_021a1a10();
            func_ov000_0219b8a8(3);
        }
    } else if (a == 0) {
        func_ov000_0219b8a8(6);
        for (f = 0; f <= data_ov000_021b54c8->mUnk_33c.mUnk_0d; f++) {
            if (data_ov000_021b54c8->mUnk_30 == data_ov000_021b54c8->mUnk_33c.mUnk_f4[f]) {
                data_ov000_021b54c8->mUnk_2c = data_ov000_021b54c8->mUnk_33c.mUnk_2b8[f];
                break;
            }
        }
    }
    data_ov000_021b54c8->mUnk_33c.mUnk_2d8 =
        func_ov000_0219b844(data_ov000_021b54c8->mUnk_33c.mUnk_2b8, data_ov000_021b54c8->mUnk_33c.mUnk_0d + 1);
    func_ov000_021a15b0();
    h = data_ov000_021b54c8;
    if (h->mUnk_33c.mUnk_15 == 2 || h->mUnk_33c.mUnk_15 == 3) {
        h = data_ov000_021b54c8;
        h->mUnk_74(a, b, c, d, e, h->mUnk_78);
    } else {
        h->mUnk_6c(a, b, h->mUnk_70);
    }
}

void func_ov000_0219b580(u32 a, int b) {
    if ((*(s32 *) (b + 4) != 0x603) && (*(s32 *) (b + 4) != 0x901)) {
        func_ov000_0219b77c(3);
    }
}

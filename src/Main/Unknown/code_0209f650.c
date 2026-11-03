#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209f650.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"

u16 func_02148714(s32 a, s32 b);

static inline u16 func_0209f800_inline(u32 n) {
    Unk020f41c4_B *b;
    u32 m;
    u32 r;

    if (n == 0x10000) {
        b = func_020d22d0();
        b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
        return (u16) (((b->mUnk_00 >> 32) * 0x10000) >> 32);
    } else {
        b = func_020d22d0();
        m = (u16) n;
        if (m == 0) {
            r = 0;
        } else {
            b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
            if (m == 0) {
                r = b->mUnk_00 >> 32;
            } else {
                r = ((b->mUnk_00 >> 32) * m) >> 32;
            }
        }
    }
    return (u16) r;
}

static inline void func_0209f6d8_inline(Unk0209f6d8 *p) {
    p->mUnk_a4 += p->mUnk_a8;
    p->mUnk_a8 += 0x4000;
    if (p->mUnk_a4 == 0) {
        p->mUnk_a4 += p->mUnk_a8;
        p->mUnk_a8 += 0x4000;
    } else if (p->mUnk_a4 >= 0x16c000) {
        p->mUnk_a8 = 0x4000 - p->mUnk_a8;
        p->mUnk_ac = p->mUnk_ac == 0 ? 1 : 0;
    }
}

void CreateChandelier(void *a) {
    func_0209be50(gChandelier = func_0209be84(a, gChandelierNsbmdName), gChandelierNsbcaName);
    func_0209b940(gChandelier, 0x3f);
}

void *func_0209f698(void) {
    return (void *) func_0209bf48(func_0209f800, func_0209f6d8, NULL);
}

void *func_0209f6b8(void) {
    return (void *) func_0209bef0(func_0209fbe4, func_0209fb0c, NULL);
}

void func_0209f6d8(void *a, Unk0209f6d8 *p) {
    Unk0210b7a8 s;
    s32 t;
    u16 w;

    func_0209f6d8_inline(p);
    if (p->mUnk_a2 == 0) {
        return;
    }
    if (p->mUnk_00.mUnk_9c->mUnk_28 != func_0210f744(0)) {
        return;
    }
    w = p->mUnk_a2;
    if (p->mUnk_00.mUnk_78 & 4) {
        return;
    }
    if (p->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
        t = 2;
    } else if (p->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
        t = 3;
    } else {
        t = 4;
    }
    s.mUnk_00 = w;
    s.mUnk_04 = &p->mUnk_00.mUnk_04;
    s.mUnk_08 = t;
    s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mUnk_04);
    func_0210b7a8(&s);
}

void func_0209f800(Unk0209f800 *a) {
    Unk0209f6d8 *p;
    Unk020f41c4_B *r;
    s32 i;
    s32 j;
    u32 n;
    u16 m;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != NULL; i++) {
        p->mUnk_a4 = 0;
        p->mUnk_a8 = 0;
        n = func_0209b634(gTownMonte);
        p->mUnk_a0 = func_0209f800_inline(n);
        r = func_020d22d0();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        m = (u16) (((r->mUnk_00 >> 32) * 0x1a) >> 32);
        for (j = 0; j < m; j++) {
            func_0209f6d8_inline(p);
        }
        if (p->mUnk_00.mUnk_9c->mUnk_28 != 0) {
            if (p->mUnk_a0 == 0) {
                p->mUnk_a2 = 0x1a7;
            } else if (p->mUnk_a0 == 1) {
                p->mUnk_a2 = 0x1a8;
            } else if (p->mUnk_a0 == 2) {
                r = func_020d22d0();
                r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                p->mUnk_a2 = (u16) (((r->mUnk_00 >> 32) * 2) >> 32) != 0 ? 0x1a7 : 0x1a8;
            }
        }
    }
}

void func_0209fb0c(void *a, Unk0209f6d8 *p) {
    s32 v;
    s32 d;
    Unk02012f58 *h;

    d = (0x16c000 - p->mUnk_a4) >> 12;
    v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    if (p->mUnk_ac != 0) {
        h = func_020e6c3c(&p->mUnk_00.mUnk_04, -d, d);
        func_01ff9048(0x19, h, 0xc);
    } else {
        h = func_020e6c3c(&p->mUnk_00.mUnk_04, d, d);
        func_01ff9048(0x19, h, 0xc);
    }
    func_01ff9048(0x1b, &p->mUnk_00.mUnk_1c, 3);
    func_0209b688(gTownMonte, p->mUnk_a0);
    func_0209bbd0(a, gTownMonte);
    func_0209bb2c(a, gTownMonte, p);
}

void func_0209fbe4(Unk0209bc74 *a) {
    a->mUnk_14 = (void *) func_0209fc2c;
    func_0209b940(gTownMonte = func_0209bc74(a, gTownMonteNsbmdName, gTownMonteNsbtpName), 0x3f);
}

void func_0209fc2c(void) {
    func_020e6c0c();
}

void func_0209fc38(void) {
    s32 i;

    for (i = 0; i < 19; i++) {
        data_usa_0217b18c[i] = NULL;
    }
    data_usa_0217b18c[0] = (Unk020e71a0_98 *) func_0209bf8c();
}

void func_0209fc78(Unk020e71a0 *p) {
    s32 i;

    i = p->mUnk_9c->mUnk_28;
    if (data_usa_0217b18c[i] == NULL) {
        data_usa_0217b18c[i] = func_02036bec(func_020364e0(func_020364e8()), 0x40);
        *data_usa_0217b18c[i] = *data_usa_0217b18c[0];
    }
    switch (i) {
        case 0x10:
            data_usa_0217b18c[i]->mUnk_24 = 0x127;
            break;
        case 0x11:
            data_usa_0217b18c[i]->mUnk_24 = 0x100;
            break;
        case 0x12:
            data_usa_0217b18c[i]->mUnk_24 = 0x1da;
            break;
        default:
            data_usa_0217b18c[i]->mUnk_24 = func_0210bafc(0, 8, i);
            break;
    }
    p->mUnk_98 = data_usa_0217b18c[i];
}

void *func_0209fd74(void) {
    return (void *) func_0209bf48(func_020a0064, func_0209fdb4, NULL);
}

void *func_0209fd94(void) {
    return (void *) func_0209bf1c(CreateAirship, func_020a018c, NULL);
}

static inline void func_0209fdb4_inline(Unk020a018c *p) {
    s32 t;

    p->mUnk_a8 = (u16) p->mUnk_a8 + p->mUnk_c0;
    p->mUnk_b0 = p->mUnk_b4 + func_020a0028(p->mUnk_b8 / 2, 0x1000 - func_020a0044((u16) p->mUnk_a8)) - p->mUnk_ac;
    p->mUnk_ac += p->mUnk_b0;
    if (p->mUnk_b8 > 0) {
        t = p->mUnk_b8 + p->mUnk_bc;
        if (t <= 0) {
            t = 0;
        }
        p->mUnk_b8 = t;
    } else if (p->mUnk_b8 < 0) {
        t = p->mUnk_b8 + p->mUnk_bc;
        if (t >= 0) {
            t = 0;
        }
        p->mUnk_b8 = t;
    }
    if (p->mUnk_c0 > 0) {
        t = p->mUnk_c0 + p->mUnk_c4;
        if (t <= 0) {
            t = 0;
        }
        p->mUnk_c0 = t;
    } else if (p->mUnk_c0 < 0) {
        t = p->mUnk_c0 + p->mUnk_c4;
        if (t >= 0) {
            t = 0;
        }
        p->mUnk_c0 = t;
    }
}

static inline BOOL func_0209fdb4_inline_b(void) {
    s32 i;

    for (i = 0; i < data_021759c0->mKartCount; i++) {
        if (func_0203c8c0((u16) i) >= 2) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_0209fdb4(void *a, Unk020a018c *p) {
    switch (p->mUnk_ec) {
        case 0:
            if (func_0209fdb4_inline_b() != FALSE) {
                p->mUnk_ec = 1;
            }
            break;
        case 1:
            p->mUnk_a0 += 0x1000;
            if (p->mUnk_a0 >= 0) {
                p->mUnk_a0 = 0;
                p->mUnk_ec = 2;
            }
            func_0209fdb4_inline(p);
            break;
        case 2:
            func_020d8cc8(&p->mUnk_c8);
            func_020d8bf8(&p->mUnk_c8, &p->mUnk_00.mUnk_04, &p->mUnk_00.mUnk_10);
            func_0209fdb4_inline(p);
            break;
    }
    p->mUnk_00.mUnk_7e = func_02148714(p->mUnk_00.mUnk_10.x, p->mUnk_00.mUnk_10.z);
}

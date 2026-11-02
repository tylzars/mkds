#include "Main/Unknown/code_020937c4.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0207a780.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"
#include "code_0212c6ac.h"

void func_020937c4(Vec3 *a, Vec3 *b, u16 c) {
    Unk020937c4 *o;

    o = func_0209bbfc(func_02100138(0x1a2));
    if (o == NULL) {
        return;
    }
    o->mUnk_a0 = 600;
    o->mUnk_00.mUnk_04.x = a->x;
    o->mUnk_00.mUnk_04.y = a->y + 0x2a000;
    o->mUnk_00.mUnk_04.z = a->z;
    o->mUnk_00.mUnk_28.mUnk_18.x = b->x;
    o->mUnk_00.mUnk_28.mUnk_18.y = 0;
    o->mUnk_00.mUnk_28.mUnk_18.z = b->z;
    o->mUnk_00.mUnk_10.x = ((s64) b->x * 0x6000) >> 12;
    o->mUnk_00.mUnk_10.y = 0;
    o->mUnk_00.mUnk_10.z = ((s64) b->z * 0x6000) >> 12;
    o->mUnk_00.mUnk_7e = c;
    o->mUnk_a4 = 0;
}

void func_02093884(void) {
    func_0209bf48(NULL, func_02093910, NULL);
}

void func_020938a0(void) {
    func_0209bf1c(CreateNsKiller2AndNsKiller2S, func_02093a50, NULL);
}

void func_020938c0(void) {
    Unk0209bf70 *o;

    o = func_0209bf70(func_02093b7c, NULL, NULL, 1, 1, 0x17b);
    o->mUnk_38 = 0x32000;
    o->mUnk_3c = -0x64000;
}

void func_02093910(void *a, Unk02093910 *p) {
    if ((func_0207a780() & p->mUnk_00.mUnk_74) != 0) {
        p->mUnk_00.mUnk_02 |= data_021564a8;
    } else {
        p->mUnk_00.mUnk_02 &= ~2;
    }
    switch (p->mUnk_a4) {
        case 0:
            if (p->mUnk_a0-- > 0) {
                if ((p->mUnk_00.mUnk_02 & 2) == 0 && (p->mUnk_00.mUnk_78 & 8) != 0) {
                    func_0210b7ec(p->mUnk_a8, p->mUnk_00.mUnk_78 & ~0xc000001f);
                } else {
                    func_0210b7ec(p->mUnk_a8, func_020d4ef4(&p->mUnk_00.mUnk_04));
                }
                func_02148504(&p->mUnk_00.mUnk_04, &p->mUnk_00.mUnk_10, &p->mUnk_00.mUnk_04);
                if (p->mUnk_a0 < 0x24e) {
                    func_020d275c(&p->mUnk_00, 0x17d);
                }
            } else {
                func_020d2398(&p->mUnk_00);
            }
            break;
        case 1:
            if (p->mUnk_a0-- > 0) {
                p->mUnk_00.mUnk_10.y -= 0x400;
                func_02148504(&p->mUnk_00.mUnk_04, &p->mUnk_00.mUnk_10, &p->mUnk_00.mUnk_04);
            } else {
                func_020d2398(&p->mUnk_00);
            }
            break;
    }
}

void func_02093a50(void *a, Unk02093910 *p) {
    s32 t;
    s32 m[9];
    s32 i;

    if (p->mUnk_a0 <= 0) {
        return;
    }
    t = 0x1e;
    func_01ff9048(0x14, &t, 1);
    func_01ff9048(0x19, func_020e6b58(&p->mUnk_00.mUnk_04), 12);
    i = p->mUnk_00.mUnk_7e >> 4;
    func_02146d44(m, data_0215d4b4[i * 2], data_0215d4b4[i * 2 + 1]);
    func_01ff9048(0x1a, m, 9);
    func_01ff9048(0x1b, &p->mUnk_00.mUnk_1c, 3);
    func_0209bb2c(a, gNsKiller2S, p);
    func_0209bb2c(a, gNsKiller2, p);
}

void CreateNsKiller2AndNsKiller2S(void *a) {
    gNsKiller2 = func_0209be84(a, gNsKiller2NsbmdName);
    gNsKiller2S = func_0209bd90(a, gNsKiller2SNsbmdName);
    func_0209b940(gNsKiller2S, 0x3f);
}

u8 func_02093b7c(Unk02093910 *a, Unk0206bcb0 *b, u8 *c, u8 *d) {
    u8 x;
    u8 v;

    x = *c;
    v = *d;
    if (x == 1) {
        a->mUnk_a0 = 0x78;
        a->mUnk_a4 = 1;
        a->mUnk_00.mUnk_10.x = ((s64) a->mUnk_00.mUnk_10.x << 10) >> 12;
        a->mUnk_00.mUnk_10.y = ((s64) a->mUnk_00.mUnk_10.y << 10) >> 12;
        a->mUnk_00.mUnk_10.z = ((s64) a->mUnk_00.mUnk_10.z << 10) >> 12;
        a->mUnk_00.mUnk_10.y = 0x4000;
        a->mUnk_00.mUnk_02 |= data_021564ac;
        if (b->mUnk_29c == 1 || b->mUnk_29c == 3) {
            a->mUnk_00.mUnk_78 |= data_021564b0;
        }
        func_020d26f8(&a->mUnk_00, b);
    }
    return v;
}

void func_02093c64(Unk02093910 *p) {
    p->mUnk_00.mUnk_02 |= data_021564b4;
    func_020d2398(&p->mUnk_00);
    p->mUnk_a8 = func_020d286c(&p->mUnk_00);
    func_0210b850(p->mUnk_a8);
    p->mUnk_00.mUnk_94->mUnk_00.mUnk_30 = (void (*)(void *, void *, void *)) func_0210a6b4;
}

void func_02093cb4(void) {
    func_0209bf48(func_02093eac, func_02093cf4, NULL);
}

void func_02093cd4(void) {
    func_0209bf1c(CreateNsKiller1, func_02093ee8, NULL);
}

void func_02093cf4(void *a, Unk02093cf4 *p) {
    Unk0210b7a8 s;

    switch (p->mUnk_a8) {
        case 0:
            if (p->mUnk_a0-- > 0) {
                return;
            }
            p->mUnk_ac.mUnk_04 = 0x2000;
            p->mUnk_ac.mUnk_10 = ((s64) p->mUnk_ac.mUnk_00->mUnk_00[p->mUnk_ac.mUnk_0c].mUnk_34 << 13) >> 12;
            p->mUnk_a8 = 1;
            break;
        case 1:
            if (func_020d8cc8(&p->mUnk_ac) != 0) {
                p->mUnk_a0 = 0x2d;
                p->mUnk_a8 = 2;
            }
            func_020d879c(&p->mUnk_ac, &p->mUnk_00.mUnk_04);
            break;
        case 2:
            if (p->mUnk_a0 == 0x2d) {
                if ((p->mUnk_00.mUnk_78 & 4) == 0) {
                    func_0212c6f0(func_02108e6c(8), 0);
                    s = data_0216676c;
                    s.mUnk_04 = &p->mUnk_00.mUnk_04;
                    s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mUnk_04);
                    func_0210b708(&s, func_02108e6c(8));
                }
            } else if (p->mUnk_a0 <= 0) {
                p->mUnk_a0 = 0;
                p->mUnk_a8 = 3;
            }
            p->mUnk_a0--;
            break;
        case 3:
            func_020937c4(&p->mUnk_00.mUnk_04, &p->mUnk_00.mUnk_28.mUnk_18, p->mUnk_00.mUnk_7e);
            if ((p->mUnk_00.mUnk_02 & 0x12) == 0) {
                func_0208b7bc(0x4b, &p->mUnk_00.mUnk_04);
                func_0208b7bc(0x4c, &p->mUnk_00.mUnk_04);
                func_0208b7bc(0x4d, &p->mUnk_00.mUnk_04);
            }
            p->mUnk_a0 = 0x4b;
            p->mUnk_a8 = 0;
            break;
    }
}

void func_02093eac(Unk020e6fd4 *p) {
    s32 i;
    Unk02093cf4 *e;

    if (p == NULL) {
        return;
    }
    for (i = 0; i < p->mUnk_04 && (e = p->mUnk_00[i]) != NULL; i++) {
        e->mUnk_a0 = 0;
    }
}

void func_02093ee8(void *a, Unk02093cf4 *p) {
    s32 t;

    t = 0x1e;
    func_01ff9048(0x14, &t, 1);
    func_01ff9048(0x1b, &p->mUnk_00.mUnk_1c, 3);
    p->mUnk_00.mUnk_28.mUnk_24.x = p->mUnk_00.mUnk_04.x >> 4;
    p->mUnk_00.mUnk_28.mUnk_24.y = p->mUnk_00.mUnk_04.y >> 4;
    p->mUnk_00.mUnk_28.mUnk_24.z = p->mUnk_00.mUnk_04.z >> 4;
    func_01ff9048(0x19, &p->mUnk_00.mUnk_28, 12);
    func_0209bb2c(a, gNsKiller1, p);
}

void CreateNsKiller1(void *a) {
    gNsKiller1 = func_0209be84(a, gNsKiller1NsbmdName);
}

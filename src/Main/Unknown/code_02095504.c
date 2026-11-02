#include "Main/Unknown/code_02095504.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e5668.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "code_02148538.h"

void func_02095504(void) {
    func_0209bf48(func_020957ec, func_02095544, 0);
}

void func_02095524(void) {
    func_0209bf1c(CreateBakubakuAndBakuShadow, func_02095848, 0);
}

void func_02095544(void *a, Unk02095544 *p) {
    Unk0210b7a8 s1;
    Unk0210b7a8 s2;
    Unk0206bcb0 *o;
    Vec3 *q;
    s64 d;
    s32 v1;
    s32 v2;

    switch (p->mUnk_b0) {
        case 0:
            if (func_02061818() != 2) {
                o = func_0207a974((u16) data_021759c0->mUnk_62);
                q = &o->mUnk_80;
                v2 = q->x - p->mUnk_a4.x;
                v1 = q->z - p->mUnk_a4.z;
                d = (s64) v2 * v2 + (s64) v1 * v1;
                if (d >= (s64) 0x9c4 << 32) {
                    return;
                }
            }
            p->mUnk_00.mUnk_04.x = p->mUnk_00.mUnk_9c->mUnk_00.x;
            p->mUnk_00.mUnk_04.y = p->mUnk_00.mUnk_9c->mUnk_00.y - 0x32000;
            p->mUnk_00.mUnk_04.z = p->mUnk_00.mUnk_9c->mUnk_00.z;
            p->mUnk_00.mUnk_10.x = ((s64) p->mUnk_00.mUnk_28.mUnk_18.x * 0xc000) >> 12;
            p->mUnk_00.mUnk_10.y = 0xc000;
            p->mUnk_00.mUnk_10.z = ((s64) p->mUnk_00.mUnk_28.mUnk_18.z * 0xc000) >> 12;
            p->mUnk_b0 = 1;
            break;
        case 1:
            p->mUnk_00.mUnk_10.y -= 0x400;
            func_02148504(&p->mUnk_00.mUnk_04, &p->mUnk_00.mUnk_10, &p->mUnk_00.mUnk_04);
            if (p->mUnk_00.mUnk_04.y < p->mUnk_00.mUnk_9c->mUnk_00.y) {
                return;
            }
            func_0208e490(3, &p->mUnk_00.mUnk_04, 1);
            s1.mUnk_00 = 0x186;
            s1.mUnk_04 = &p->mUnk_00.mUnk_04;
            s1.mUnk_08 = 4;
            s1.mUnk_0c = func_020d4ef4(&p->mUnk_00.mUnk_04);
            func_0210b7a8(&s1);
            p->mUnk_b0 = 2;
            break;
        case 2:
            p->mUnk_00.mUnk_10.y -= 0x400;
            func_02148504(&p->mUnk_00.mUnk_04, &p->mUnk_00.mUnk_10, &p->mUnk_00.mUnk_04);
            if (p->mUnk_00.mUnk_04.y > p->mUnk_00.mUnk_9c->mUnk_00.y) {
                return;
            }
            func_0208e490(3, &p->mUnk_00.mUnk_04, 1);
            s2.mUnk_00 = 0x187;
            s2.mUnk_04 = &p->mUnk_00.mUnk_04;
            s2.mUnk_08 = 2;
            s2.mUnk_0c = func_020d4ef4(&p->mUnk_00.mUnk_04);
            func_0210b7a8(&s2);
            p->mUnk_b0 = 3;
            break;
        case 3:
            p->mUnk_00.mUnk_10.y -= 0x400;
            func_02148504(&p->mUnk_00.mUnk_04, &p->mUnk_00.mUnk_10, &p->mUnk_00.mUnk_04);
            if (p->mUnk_00.mUnk_04.y <= p->mUnk_00.mUnk_9c->mUnk_00.y - 0x32000) {
                p->mUnk_a0 = 0x708;
                p->mUnk_b0 = 4;
            }
            break;
        case 4:
            if (p->mUnk_a0-- <= 0) {
                p->mUnk_b0 = 0;
            }
            break;
    }
}

void func_020957ec(Unk020e6fd4 *p) {
    s32 i;
    Unk02095544 *e;

    if (p == 0) {
        return;
    }
    for (i = 0; i < p->mUnk_04 && (e = p->mUnk_00[i]) != 0; i++) {
        func_02147fd8(0x320000, &e->mUnk_00.mUnk_28.mUnk_18, &e->mUnk_00.mUnk_9c->mUnk_00, &e->mUnk_a4);
    }
}

void func_02095848(void *a, Unk02095544 *p) {
    s32 t;
    s32 m[9];
    s32 i;

    if (p->mUnk_b0 != 2) {
        return;
    }
    t = 0x1e;
    func_01ff9048(0x14, &t, 1);
    p->mUnk_00.mUnk_28.mUnk_24.x = p->mUnk_00.mUnk_04.x >> 4;
    p->mUnk_00.mUnk_28.mUnk_24.y = p->mUnk_00.mUnk_04.y >> 4;
    p->mUnk_00.mUnk_28.mUnk_24.z = p->mUnk_00.mUnk_04.z >> 4;
    func_01ff9048(0x19, &p->mUnk_00.mUnk_28, 12);
    func_01ff9048(0x1b, &p->mUnk_00.mUnk_1c, 3);
    func_0209bb2c(a, gBakuShadow, p);
    i = (u16) (u32) func_02148714(-p->mUnk_00.mUnk_10.y, 0xc000) >> 4;
    func_02146d28(m, data_0215d4b4[i * 2], data_0215d4b4[i * 2 + 1]);
    func_01ff9048(0x1a, m, 9);
    func_0209bb2c(a, gBakubaku, p);
}

void CreateBakubakuAndBakuShadow(void *a) {
    gBakubaku = func_0209be84(a, gBakubakuNsbmdName);
    gBakuShadow = func_0209bd90(a, gBakuShadowNsbmdName);
    func_0209b940(gBakubaku, 0x3f);
    func_0209b940(gBakuShadow, 0x3f);
}

void func_020959bc(void) {
    func_0209bf48(func_02095d1c, func_02095a3c, 0);
}

void func_020959dc(void) {
    func_0209bf1c(CreateMoveTree, func_02095db8, 0);
}

void func_020959fc(void) {
    func_0209bf70(func_02095efc, 0, 0, 2, 1, 0x125);
}

void func_02095a3c(void *a, Unk02095a3c *p) {
    Unk0210b7a8 s1;
    Unk0210b7a8 s2;
    u32 k;
    s32 v;

    switch (p->mUnk_d8) {
        case 0:
            p->mUnk_b4.mUnk_04 = 0;
            p->mUnk_b4.mUnk_10 = 0;
            if (p->mUnk_a0-- <= 0) {
                p->mUnk_d8 = 1;
            }
            if ((s32) (p->mUnk_00.mUnk_78 & ~0xc000001f) >= 0xc5c10) {
                return;
            }
            if (p->mUnk_a4-- > 0) {
                p->mUnk_b0 = 2;
                p->mUnk_ac += p->mUnk_b0;
                if (p->mUnk_ac >= func_0209b758(gMoveTree)) {
                    p->mUnk_ac = 0;
                }
                return;
            }
            if (p->mUnk_ac == 0) {
                return;
            }
            p->mUnk_ac += p->mUnk_b0;
            if (p->mUnk_ac >= func_0209b758(gMoveTree)) {
                p->mUnk_ac = 0;
            }
            if (p->mUnk_ac != 0 && p->mUnk_ac != 0x1e) {
                return;
            }
            if ((p->mUnk_00.mUnk_78 & 4) != 0) {
                return;
            }
            if (p->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                k = 2;
            } else if (p->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                k = 3;
            } else {
                k = 4;
            }
            s1.mUnk_00 = 0x11f;
            s1.mUnk_04 = &p->mUnk_00.mUnk_04;
            s1.mUnk_08 = k;
            s1.mUnk_0c = func_020d4ef4(&p->mUnk_00.mUnk_04);
            func_0210b7a8(&s1);
            break;
        case 1:
            v = p->mUnk_a8;
            p->mUnk_b4.mUnk_04 = v;
            p->mUnk_b4.mUnk_10 = ((s64) v * p->mUnk_b4.mUnk_00->mUnk_00[p->mUnk_b4.mUnk_0c].mUnk_34) >> 12;
            if (func_020d8cc8(&p->mUnk_b4) != 0) {
                p->mUnk_a0 = (u16) p->mUnk_b4.mUnk_1c->mUnk_0e;
                p->mUnk_d8 = 0;
            }
            func_020d879c(&p->mUnk_b4, &p->mUnk_00.mUnk_04);
            if ((s32) (p->mUnk_00.mUnk_78 & ~0xc000001f) >= 0xc5c10) {
                return;
            }
            if (p->mUnk_a4-- > 0) {
                p->mUnk_b0 = 2;
            } else {
                p->mUnk_b0 = 1;
            }
            p->mUnk_ac += p->mUnk_b0;
            if (p->mUnk_ac >= func_0209b758(gMoveTree)) {
                p->mUnk_ac = 0;
            }
            if (p->mUnk_ac != 0 && p->mUnk_ac != 0x1e) {
                return;
            }
            if ((p->mUnk_00.mUnk_78 & 4) != 0) {
                return;
            }
            if (p->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                k = 2;
            } else if (p->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                k = 3;
            } else {
                k = 4;
            }
            s2.mUnk_00 = 0x11f;
            s2.mUnk_04 = &p->mUnk_00.mUnk_04;
            s2.mUnk_08 = k;
            s2.mUnk_0c = func_020d4ef4(&p->mUnk_00.mUnk_04);
            func_0210b7a8(&s2);
    }
}

void func_02095d1c(Unk020e6fd4 *p) {
    s32 i;
    Unk02095a3c *e;

    if (p == 0) {
        return;
    }
    for (i = 0; i < p->mUnk_04 && (e = p->mUnk_00[i]) != 0; i++) {
        e->mUnk_a8 = (e->mUnk_00.mUnk_9c->mUnk_28 << 12) / 100;
        func_020e516c(&e->mUnk_dc, &e->mUnk_00.mUnk_04, 0x54666, 14);
    }
}

void func_02095db8(void *a, Unk02095a3c *p, u32 c, u32 d) {
    s32 t;

    t = 0x1e;
    func_01ff9048(0x14, &t, 1);
    func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mUnk_04), 12);
    func_01ff9048(0x1b, &p->mUnk_00.mUnk_1c, 3);
    if ((s32) (p->mUnk_00.mUnk_78 & ~0xc000001f) < 0xc5c10) {
        func_0209b77c(gMoveTree, p->mUnk_ac);
        func_0209bb2c(a, gMoveTree, p);
    } else {
        func_0209ba58(a, gMoveTree, p);
    }
    if ((s32) (p->mUnk_00.mUnk_78 & ~0xc000001f) >= 0x27100) {
        return;
    }
    func_020e5668(&p->mUnk_dc, &p->mUnk_00.mUnk_04);
    func_020e53ac(&p->mUnk_dc, 0, c, d);
}

void CreateMoveTree(void *a) {
    gMoveTree = func_0209be84(a, gMoveTreeNsbmdName);
    func_0209be50(gMoveTree, gMoveTreeNsbcaName);
    func_0209b940(gMoveTree, 0x3f);
}

u8 func_02095efc(Unk02095a3c *a, Unk0206bcb0 *b, u8 *c, u8 *d) {
    u8 v;

    v = *d;
    if (a->mUnk_d8 <= 1) {
        a->mUnk_a4 = 30;
    }
    return v;
}

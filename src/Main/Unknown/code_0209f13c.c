#include "Main/Unknown/code_0209f13c.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209f5cc.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02146cbc.h"

void func_0209f514(Unk0209f514 *a) {
    s32 i;
    Unk0209f1c8 *o;
    Unk020f41c4_B *r;

    if (a == 0) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (o = a->mUnk_00[i]) != 0; i++) {
        r = &data_0217561c->mUnk_498;
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        o->mUnk_a4 = (u16) (((u64) (u32) (r->mUnk_00 >> 32) * 0x3c) >> 32) + 0x3c;
    }
}

void func_0209f338(void *a, Unk0209f1c8 *b) {
    Unk0210b7a8 s1;
    Unk0210b7a8 s2;
    Unk0210b7a8 s3;
    s32 t;
    s32 n;

    switch (b->mUnk_a8) {
        case 0:
            if (b->mUnk_a4-- <= 0) {
                b->mUnk_a8 = 1;
            }
            return;
        case 1:
            break;
        default:
            return;
    }
    if (b->mUnk_a0 == 0 || b->mUnk_a0 == 0x7d) {
        if ((b->mUnk_00.mUnk_78 & 4) == 0) {
            if (b->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                t = 2;
            } else if (b->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                t = 3;
            } else {
                t = 4;
            }
            s1.mUnk_00 = 0x11a;
            s1.mUnk_04 = &b->mUnk_00.mUnk_04;
            s1.mUnk_08 = t;
            s1.mUnk_0c = func_020d4ef4(&b->mUnk_00.mUnk_04);
            func_0210b7a8(&s1);
        }
    } else if (b->mUnk_a0 == 0x46 || b->mUnk_a0 == 0xaf) {
        if ((b->mUnk_00.mUnk_78 & 4) == 0) {
            if (b->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                t = 2;
            } else if (b->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                t = 3;
            } else {
                t = 4;
            }
            s2.mUnk_00 = 0x11b;
            s2.mUnk_04 = &b->mUnk_00.mUnk_04;
            s2.mUnk_08 = t;
            s2.mUnk_0c = func_020d4ef4(&b->mUnk_00.mUnk_04);
            func_0210b7a8(&s2);
        }
    } else if (b->mUnk_a0 == 0xfa) {
        if ((b->mUnk_00.mUnk_78 & 4) == 0) {
            if (b->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                t = 2;
            } else if (b->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                t = 3;
            } else {
                t = 4;
            }
            s3.mUnk_00 = 0x119;
            s3.mUnk_04 = &b->mUnk_00.mUnk_04;
            s3.mUnk_08 = t;
            s3.mUnk_0c = func_020d4ef4(&b->mUnk_00.mUnk_04);
            func_0210b7a8(&s3);
        }
    }
    n = b->mUnk_a0 + 1;
    if (n >= func_0209b758(gChandelier)) {
        n = 0;
    }
    b->mUnk_a0 = n;
    if (b->mUnk_a0 == 0) {
        b->mUnk_a8 = 0;
    }
}

void *func_0209f318(void) {
    return (void *) func_0209bf1c(CreateChandelier, func_0209f5cc, 0);
}

void *func_0209f2f8(void) {
    return (void *) func_0209bf48(func_0209f514, func_0209f338, 0);
}

void CreateRainStar(void *a) {
    func_0209be1c(gRainStar = func_0209be84(a, gRainStarNsbmdName), gRainStarNsbtaName);
    func_0209b940(gRainStar, 0x3f);
}

void func_0209f1c8(void *a, Unk0209f1c8 *b) {
    u32 l;
    s32 m[9];
    s32 i;

    l = 0x1e;
    func_01ff9048(0x14, &l, 1);
    b->mUnk_00.mUnk_28.mUnk_24.x = b->mUnk_00.mUnk_04.x >> 4;
    b->mUnk_00.mUnk_28.mUnk_24.y = b->mUnk_00.mUnk_04.y >> 4;
    b->mUnk_00.mUnk_28.mUnk_24.z = b->mUnk_00.mUnk_04.z >> 4;
    func_01ff9048(0x19, &b->mUnk_00.mUnk_28, 0xc);
    if (b->mUnk_00.mUnk_7e != 0) {
        i = b->mUnk_00.mUnk_7e >> 4;
        func_02146d44(m, data_0215d4b4[i * 2], data_0215d4b4[i * 2 + 1]);
        func_01ff9048(0x1a, m, 9);
    }
    func_01ff9048(0x1b, &b->mUnk_00.mUnk_1c, 3);
    func_0209b6c8(gRainStar, b->mUnk_a0);
    func_0209bb2c(a, gRainStar, b);
}

void func_0209f178(void *a, Unk0209f1c8 *b) {
    u16 n;

    n = func_0209b6ec(gRainStar);
    b->mUnk_a0 += 1;
    if (b->mUnk_a0 >= n) {
        b->mUnk_a0 = 0;
    }
    b->mUnk_00.mUnk_7e += 0x111;
}

void *func_0209f158(void) {
    return (void *) func_0209bf1c(CreateRainStar, func_0209f1c8, 0);
}

void *func_0209f13c(void) {
    return (void *) func_0209bf48(0, func_0209f178, 0);
}

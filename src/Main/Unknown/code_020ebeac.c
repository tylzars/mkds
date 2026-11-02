#include "Main/Unknown/code_020ebeac.h"

#include "Main/Unknown/code_020ebef8.h"
#include "code_02147cd8.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ec1ec.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ec000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/code_020ea670.h"
#include "01/code_0218155c.h"

const Unk021594e4 data_021594e4 = {
    0, 0, (u32) &func_020eb720, 0, (u32) &func_020ec1ec, 0, 0, 0, 0, 0,
};

const Unk0215950c data_0215950c = {
    0, 0, (u32) &func_020eb72c, 0, (u32) &func_020ec1fc, 0, 1, 0, 0, 0, 0,
};

const Unk02159538 data_02159538 = {
    (u32) &func_020eb7e0, (u32) &func_020eb760, 4, 0xa000, 0xa000, 0xa000, 0, 1, 1, 0x168, 0x169, 0, 0, 0, 0, 0,
};

s32 func_020ec450(Unk020e43a8 *a, void *b, u8 *c) {
    if (*c != 1) {
        return 0;
    }
    func_020ec6e4(a, b);
    a->mUnk_00.mUnk_80.mUnk_10 = 1;
    a->mUnk_00.mUnk_80.mUnk_12 = 1;
    return 1;
}

s32 func_020ec41c(Unk020e43a8 *a, void *b, u8 *c) {
    if (*c != 1) {
        return 0;
    }
    func_020ec538(a, b);
    a->mUnk_00.mUnk_80.mUnk_10 = 1;
    a->mUnk_00.mUnk_80.mUnk_12 = 1;
    return 1;
}

Unk02159538 *func_020ec3cc(void) {
    Unk02159538 *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    *p = data_02159538;
    return p;
}

Unk0215950c *func_020ec370(void) {
    Unk0215950c *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    data_0217bbec = p;
    *p = data_0215950c;
    func_020d49d8(&data_0217bbec);
    return data_0217bbec;
}

Unk021594e4 *func_020ec314(void) {
    Unk021594e4 *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x28);
    data_0217bbf4 = p;
    *p = data_021594e4;
    func_020e6f50(&data_0217bbf4);
    return data_0217bbf4;
}

void func_020ec1fc(void *a, Unk020e43a8 *b, void *c, u32 d) {
    u16 h;
    s32 t;
    Vec3 v;

    h = b->mUnk_00.mUnk_80.mUnk_0e;
    b->mUnk_00.mUnk_28.mUnk_24.x = b->mUnk_00.mUnk_04.x >> 4;
    b->mUnk_00.mUnk_28.mUnk_24.y = b->mUnk_00.mUnk_04.y >> 4;
    b->mUnk_00.mUnk_28.mUnk_24.z = b->mUnk_00.mUnk_04.z >> 4;
    func_020ea8a8(data_0217bbf8, &b->mUnk_00.mUnk_28, &b->mUnk_00.mUnk_1c, d);
    if (h == 0) {
        return;
    }
    t = (s32) (((s64) (0x5a000 - b->mUnk_d0) * 0x2e) >> 12);
    v.x = b->mUnk_00.mUnk_04.x;
    v.z = b->mUnk_00.mUnk_04.z;
    v.y = b->mUnk_0b4 - (s32) (((s64) b->mUnk_0bc * b->mUnk_cc) >> 12) - (s32) (((s64) b->mUnk_0c4 * b->mUnk_d4) >> 12);
    func_02147fd8(-b->mUnk_00.mUnk_58.x, (const Vec3 *) &b->mUnk_0bc, &v, &v);
    func_020e5634((Unk020e516c *) &b->mUnk_114, &v);
    func_020e53ac((Unk020e516c *) &b->mUnk_114, &t, 0, d);
}

void func_020ec1ec(u32 arg0, u32 arg1) {
    u32 value0;
    u32 value1 = arg1;
    u32 value12;
    value12 = (u32) &func_02046b40;
    value0 = (value1) + (0x80u);
    func_02046b40((void *) value0);
}

void func_020ec194(Unk020ec194 *a) {
    Vec3 v;
    Vec3 *p;

    p = &a->mUnk_010;
    p->x = 0;
    p->y = 0;
    p->z = 0;
    a->mUnk_004 = a->mUnk_0b0;
    func_020d7a3c(&a->mUnk_0bc, a->mUnk_0c8, &v);
    func_01ffccd0((int *) &a->mUnk_028, &v);
}

void func_020ebef8(Unk020ebef8 *c, Vec3 *d) {
    s32 n;
    Vec3 a;
    Vec3 b;
    Unk020f41c4_B *p;
    Unk020f41c4_A *q;
    s32 i;

    if (data_021759c0->mUnk_08 == 4) {
        func_ov001_0218175c(c->mUnk_000.mUnk_00);
    }
    c->mUnk_000.mUnk_02 |= *(u16 *) data_021594d8;
    if (data_021759c0->mUnk_08 == 5) {
        return;
    }
    p = func_020d22c0();
    p->mUnk_00 = p->mUnk_08 * p->mUnk_00 + p->mUnk_10;
    if (c->mUnk_110 <= (u16) (((u64) (u32) (p->mUnk_00 >> 32) * 100) >> 32)) {
        return;
    }
    if (c->mUnk_10e == 0) {
        return;
    }
    i = func_020f8a04(0, c->mUnk_10e, 1, 1, 0, 0x12);
    q = func_020fa3d0(data_0217bc48[i].mUnk_08, 8, &c->mUnk_000.mUnk_04, &c->mUnk_0bc);
    if (q == 0) {
        return;
    }
    if ((s64) d->x * d->x + (s64) d->y * d->y + (s64) d->z * d->z >= 16) {
        func_02039860(d, &a);
    }
    func_020397a8(&c->mUnk_0bc, &a, &b);
    p = func_020d22c0();
    p->mUnk_00 = p->mUnk_08 * p->mUnk_00 + p->mUnk_10;
    n = (s32) (((s64) (s32) ((u32) (((u64) (u32) (p->mUnk_00 >> 32) * 0x1800) >> 32) + 0x119a) << 12) >> 12);
    p = func_020d22c0();
    p->mUnk_00 = p->mUnk_08 * p->mUnk_00 + p->mUnk_10;
    q->mUnk_5c = *d;
    func_02147fd8(n, &a, &c->mUnk_000.mUnk_04, &q->mUnk_50);
    func_02147fd8(0, &b, &q->mUnk_50, &q->mUnk_50);
    q->mUnk_68.x = 0xcd;
    q->mUnk_68.y = 0xcd;
    q->mUnk_68.z = 0xcd;
    func_020f6630(q, 2, &c->mUnk_000.mUnk_04, d, &c->mUnk_0bc);
}

void func_020ebeac(Unk020ebeac *p0) {
    p0->mUnk_02 =
        (u16) (((((u32) p0->mUnk_02)) | (((u32) * (const u16 *) ((u8 *) (u32) (((u32) (&data_021594d8))) + 0)))));
    p0->mUnk_02 =
        (u16) (((((u32) p0->mUnk_02)) | (((u32) * (const u16 *) ((u8 *) (u32) (((u32) (&data_021594dc))) + 0)))));
    p0->mUnk_02 =
        (u16) (((((u32) p0->mUnk_02)) | (((u32) * (const u16 *) ((u8 *) (u32) (((u32) (&data_021594e0))) + 0)))));
}

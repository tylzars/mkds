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

s32 func_020ec450(Unk020e43a8 *param_1, void *param_2, u8 *param_3) {
    if (*param_3 != 1) {
        return 0;
    }
    func_020ec6e4(param_1, param_2);
    param_1->mUnk_00.mUnk_80.mUnk_10 = 1;
    param_1->mUnk_00.mUnk_80.mUnk_12 = 1;
    return 1;
}

s32 func_020ec41c(Unk020e43a8 *param_1, void *param_2, u8 *param_3) {
    if (*param_3 != 1) {
        return 0;
    }
    func_020ec538(param_1, param_2);
    param_1->mUnk_00.mUnk_80.mUnk_10 = 1;
    param_1->mUnk_00.mUnk_80.mUnk_12 = 1;
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

void func_020ec1fc(void *param_1, Unk020e43a8 *param_2, void *param_3, u32 param_4) {
    u16 h;
    s32 t;
    Vec3 v;

    h = param_2->mUnk_00.mUnk_80.mUnk_0e;
    param_2->mUnk_00.mUnk_28.mUnk_24.x = param_2->mUnk_00.mUnk_04.x >> 4;
    param_2->mUnk_00.mUnk_28.mUnk_24.y = param_2->mUnk_00.mUnk_04.y >> 4;
    param_2->mUnk_00.mUnk_28.mUnk_24.z = param_2->mUnk_00.mUnk_04.z >> 4;
    func_020ea8a8(data_0217bbf8, &param_2->mUnk_00.mUnk_28, &param_2->mUnk_00.mUnk_1c, param_4);
    if (h == 0) {
        return;
    }
    t = (s32) (((s64) (0x5a000 - param_2->mUnk_d0) * 0x2e) >> 12);
    v.x = param_2->mUnk_00.mUnk_04.x;
    v.z = param_2->mUnk_00.mUnk_04.z;
    v.y = param_2->mUnk_0b4 - (s32) (((s64) param_2->mUnk_0bc * param_2->mUnk_cc) >> 12) -
          (s32) (((s64) param_2->mUnk_0c4 * param_2->mUnk_d4) >> 12);
    func_02147fd8(-param_2->mUnk_00.mUnk_58.x, (const Vec3 *) &param_2->mUnk_0bc, &v, &v);
    func_020e5634((Unk020e516c *) &param_2->mUnk_114, &v);
    func_020e53ac((Unk020e516c *) &param_2->mUnk_114, &t, 0, param_4);
}

void func_020ec1ec(u32 arg0, u32 arg1) {
    u32 value0;
    u32 value1 = arg1;
    u32 value12;
    value12 = (u32) &func_02046b40;
    value0 = (value1) + (0x80u);
    func_02046b40((void *) value0);
}

void func_020ec194(Unk020ec194 *param_1) {
    Vec3 v;
    Vec3 *p;

    p = &param_1->mUnk_010;
    p->x = 0;
    p->y = 0;
    p->z = 0;
    param_1->mUnk_004 = param_1->mUnk_0b0;
    func_020d7a3c(&param_1->mUnk_0bc, param_1->mUnk_0c8, &v);
    func_01ffccd0((int *) &param_1->mUnk_028, &v);
}

void func_020ebef8(Unk020ebef8 *param_1, Vec3 *param_2) {
    s32 n;
    Vec3 a;
    Vec3 b;
    Unk020f41c4_B *p;
    Unk020f41c4_A *q;
    s32 i;

    if (data_021759c0->mUnk_08 == 4) {
        func_ov001_0218175c(param_1->mUnk_000.mUnk_00);
    }
    param_1->mUnk_000.mUnk_02 |= *(u16 *) data_021594d8;
    if (data_021759c0->mUnk_08 == 5) {
        return;
    }
    p = func_020d22c0();
    p->mUnk_00 = p->mUnk_08 * p->mUnk_00 + p->mUnk_10;
    if (param_1->mUnk_110 <= (u16) (((u64) (u32) (p->mUnk_00 >> 32) * 100) >> 32)) {
        return;
    }
    if (param_1->mUnk_10e == 0) {
        return;
    }
    i = func_020f8a04(0, param_1->mUnk_10e, 1, 1, 0, 0x12);
    q = func_020fa3d0(data_0217bc48[i].mUnk_08, 8, &param_1->mUnk_000.mUnk_04, &param_1->mUnk_0bc);
    if (q == 0) {
        return;
    }
    if ((s64) param_2->x * param_2->x + (s64) param_2->y * param_2->y + (s64) param_2->z * param_2->z >= 16) {
        func_02039860(param_2, &a);
    }
    func_020397a8(&param_1->mUnk_0bc, &a, &b);
    p = func_020d22c0();
    p->mUnk_00 = p->mUnk_08 * p->mUnk_00 + p->mUnk_10;
    n = (s32) (((s64) (s32) ((u32) (((u64) (u32) (p->mUnk_00 >> 32) * 0x1800) >> 32) + 0x119a) << 12) >> 12);
    p = func_020d22c0();
    p->mUnk_00 = p->mUnk_08 * p->mUnk_00 + p->mUnk_10;
    q->mUnk_5c = *param_2;
    func_02147fd8(n, &a, &param_1->mUnk_000.mUnk_04, &q->mUnk_50);
    func_02147fd8(0, &b, &q->mUnk_50, &q->mUnk_50);
    q->mUnk_68.x = 0xcd;
    q->mUnk_68.y = 0xcd;
    q->mUnk_68.z = 0xcd;
    func_020f6630(q, 2, &param_1->mUnk_000.mUnk_04, param_2, &param_1->mUnk_0bc);
}

void func_020ebeac(Unk020ebeac *p0) {
    p0->mUnk_02 =
        (u16) (((((u32) p0->mUnk_02)) | (((u32) * (const u16 *) ((u8 *) (u32) (((u32) (&data_021594d8))) + 0)))));
    p0->mUnk_02 =
        (u16) (((((u32) p0->mUnk_02)) | (((u32) * (const u16 *) ((u8 *) (u32) (((u32) (&data_021594dc))) + 0)))));
    p0->mUnk_02 =
        (u16) (((((u32) p0->mUnk_02)) | (((u32) * (const u16 *) ((u8 *) (u32) (((u32) (&data_021594e0))) + 0)))));
}

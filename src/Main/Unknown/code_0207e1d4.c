#include "Main/Unknown/code_0207e1d4.h"

#include "Main/Unknown/code_0207e654.h"
#include "Main/Unknown/code_0207f05c.h"
#include "Main/Unknown/code_020888b4.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020435d4.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_0207f000.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02147cd8.h"

void func_0207e594(struct Unk020888b4 *p, struct Unk0206bcb0 *q, s32 a) {
    p->mUnk_00 = q;
    p->mUnk_04 = q->mIndex;
    p->mUnk_06 = p->mUnk_04 % 4;
    p->mUnk_88 = 0x1000;
    if (data_021759c0->mUnk_00c == 5) {
        p->mUnk_8c = 0;
    } else {
        p->mUnk_8c = 0x1000;
    }
    p->mUnk_9c = (s32) (((s64) p->mUnk_00->mUnk_2cc->mUnk_10 * 0x99a + 0x800) >> 12);
    func_02080d34(&p->mUnk_08, p->mUnk_04);
    func_0207f9cc(p, 0);
    p->mUnk_cc = 1;
}

void func_0207e564(struct Unk020888b4 *p, struct Unk02175620_bc *a) {
    func_02080cd0(&p->mUnk_08.mUnk_00, a);
    func_0207f9cc(p, 1);
    func_0207f9cc(p, 1);
}

void func_0207e4a4(struct Unk020888b4 *p) {
    Vec3 a;
    Vec3 b;
    Unk0208001c *s;
    Unk0206bcb0 *q;
    Vec3 *t;
    Unk02175620_bc *r;

    if (data_021759c0->mUnk_08 == 4) {
        func_0207e668(p);
    }
    s = &p->mUnk_08.mUnk_00;
    q = p->mUnk_00;
    if (p->mUnk_90 == 2) {
        t = &q->mUnk_50;
    } else {
        t = &q->mUnk_138;
    }
    r = s->mUnk_14;
    func_0207a948(&a, p->mUnk_04);
    func_0207f6f0(p, s, q, r, &a, t);
    if (q->mState == 0) {
        func_0204360c(p->mUnk_00->mUnk_78, 1);
        func_021484d0(&p->mUnk_44, &a, &b);
        func_01ffd224(p, &b, t);
    }
    func_0207ebfc(p);
}

void func_0207e400(struct Unk020888b4 *p, struct Unk0206bcb0 *q, s32 a) {
    p->mUnk_00 = q;
    p->mUnk_04 = q->mIndex;
    p->mUnk_06 = p->mUnk_04 % 4;
    p->mUnk_88 = 0x1000;
    p->mUnk_8c = 0;
    p->mUnk_9c = (s32) (((s64) p->mUnk_00->mUnk_2cc->mUnk_10 * 0x99a + 0x800) >> 12);
    func_02080d34(&p->mUnk_08, p->mUnk_04);
    func_0207f9cc(p, 0);
    p->mUnk_cc = 1;
}

void func_0207e35c(struct Unk020888b4 *p) {
    Vec3 a;
    Vec3 b;
    Unk0208001c *s = &p->mUnk_08.mUnk_00;
    Unk0206bcb0 *q = p->mUnk_00;
    Vec3 *t;
    Unk02175620_bc *r;

    if (p->mUnk_90 == 2) {
        t = &q->mUnk_50;
    } else {
        t = &q->mUnk_138;
    }
    r = s->mUnk_14;
    func_0207a948(&a, p->mUnk_04);
    func_0207f6f0(p, s, q, r, &a, t);
    if (q->mState == 0) {
        func_0204360c(p->mUnk_00->mUnk_78, 1);
        func_021484d0(&p->mUnk_44, &a, &b);
        func_01ffd224(p, &b, t);
    }
    func_0207ebfc(p);
}

void func_0207e268(void) {
    s32 d;

    switch (func_020853dc()) {
        case 0:
            data_usa_0217ae30 = data_usa_02155630;
            data_usa_0217ae2c = data_usa_0215569c;
            break;
        case 1:
            data_usa_0217ae30 = data_usa_02155654;
            data_usa_0217ae2c = data_usa_021556c0;
            break;
        case 2:
        default:
            data_usa_0217ae30 = data_usa_02155678;
            data_usa_0217ae2c = data_usa_0215560c;
            break;
    }
    data_usa_021658f0 = 3;
    d = data_021759c0->mKartCount - data_021759c0->mUnk_3d1;
    if (d > 1) {
        if (d <= 3) {
            data_usa_021658f0 = d - 1;
        }
    }
    data_usa_0217ae34 = data_usa_02165910[d];
}

u32 func_0207e200(struct Unk02089a24 *arg0, struct Unk020888b4 *arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value4;
    value2 = (u32) * (const u32 *) ((value1) + (0));
    value4 = value0;
    value0 = (u32) * (const u32 *) ((value2) + (716));
    value0 = (u32) * (const u32 *) ((value0) + (16));
    *(u32 *) ((value4) + (0)) = value0;
    value0 = (u32) * (const u32 *) ((value4) + (0));
    *(u32 *) ((value4) + (16)) = value0;
    value0 = (u32) * (const u16 *) ((value1) + (4));
    value0 = (u32) func_020853f0(value0);
    *(u32 *) ((value4) + (28)) = value0;
    value0 = (u32) * (const u32 *) ((value4) + (28));
    value2 = 0u;
    *(u32 *) ((value4) + (32)) = value0;
    *(u32 *) ((value4) + (36)) = value2;
    value1 = (u32) * (const u32 *) ((value4) + (0));
    value0 = ~(0u);
    *(u32 *) ((value4) + (4)) = value1;
    *(u32 *) ((value4) + (8)) = value2;
    *(u32 *) ((value4) + (12)) = value2;
    value1 = (u32) * (const u32 *) ((value4) + (0));
    *(u32 *) ((value4) + (16)) = value1;
    *(u32 *) ((value4) + (20)) = value0;
    *(u32 *) ((value4) + (24)) = value2;
    return value0;
}

void func_0207e1d4(struct Unk02089a24 *p0, struct Unk020888b4 *p1) {
    p0->mUnk_04 = (u32) (((u32) p0->mUnk_00));
    p0->mUnk_08 = (u32) 0x0u;
    p0->mUnk_0c = (u32) 0x0u;
    p0->mUnk_10 = (u32) (((u32) p0->mUnk_00));
    p0->mUnk_14 = (u32) ((~(0x0u)));
    p0->mUnk_18 = (u32) 0x0u;
}

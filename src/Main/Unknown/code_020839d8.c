#include "Main/Unknown/code_020839d8.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_02081f30.h"
#include "Main/Unknown/code_02082fec.h"
#include "Main/Unknown/code_02083680.h"
#include "Main/Unknown/code_02074874.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02146d78.h"
#include "code_02147288.h"

void func_020839d8(Unk0206bcb0 *p) {
    Unk0217ae84 *e;

    e = &data_0217ae84[p->mUnk_74];
    if (e->mUnk_0c != 0) {
        e->mUnk_0c->mUnk_98_8 = 1;
        e->mUnk_0c = 0;
        e->mUnk_00 = -1;
    }
    func_02083928(p, 0);
}

s32 func_02083a24(Unk02155908_00 *a, s32 b, Unk0206bcb0 *p) {
    Unk0217ae84 *e;
    Unk0201ca6c *o;
    u16 i;

    e = &data_0217ae84[p->mUnk_74];
    if (e->mUnk_20 != 0 || e->mUnk_24 != 0) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        o = func_0208b7bc(a->mUnk_04[0], &data_02155a14);
        data_0217ae84[p->mUnk_74].mUnk_20_a[i] = o;
        o->mUnk_94 = p;
        o->mUnk_98_24 = i;
        o->mUnk_98_0 = (u8) b;
        o->mUnk_90 = func_02082fec;
    }
    return 1;
}

s32 func_02083ae0(Unk02155908_00 *a, s32 b, Unk0206bcb0 *p) {
    Unk0217ae84 *e;
    Unk0201ca6c *o;
    s32 r;
    u16 i;
    u16 j;

    r = i = 0;
    for (; i < a->mUnk_00; i++) {
        e = &data_0217ae84[p->mUnk_74];
        j = 0;
        if (a->mUnk_04[i] != e->mUnk_04[i]) {
            if (e->mUnk_10[i].mUnk_00 != 0) {
                e->mUnk_10[i].mUnk_00->mUnk_98_8 = 1;
            }
            if (e->mUnk_10[i].mUnk_04 != 0) {
                e->mUnk_10[i].mUnk_04->mUnk_98_8 = 1;
            }
            e->mUnk_04[i] = a->mUnk_04[i];
            do {
                o = func_0208b7bc(e->mUnk_04[i], &data_02155a14);
                data_0217ae84[p->mUnk_74].mUnk_10[i].mUnk_00_a[j] = o;
                o->mUnk_94 = p;
                o->mUnk_98_24 = j;
                j++;
                o->mUnk_98_0 = b;
                o->mUnk_90 = func_020831bc;
            } while (j < 2);
            r = 1;
        }
    }
    return r;
}

s32 func_02083c18(Unk02155908_00 *a, s32 b, Unk0206bcb0 *p) {
    Unk0217ae84 *e;
    Unk0201ca6c *o;
    s32 r;
    u16 i;
    u16 j;

    r = i = 0;
    for (; i < a->mUnk_00; i++) {
        e = &data_0217ae84[p->mUnk_74];
        j = 0;
        if (a->mUnk_04[i] != e->mUnk_04[i]) {
            if (e->mUnk_10[i].mUnk_00 != 0) {
                e->mUnk_10[i].mUnk_00->mUnk_98_8 = 1;
            }
            if (e->mUnk_10[i].mUnk_04 != 0) {
                e->mUnk_10[i].mUnk_04->mUnk_98_8 = 1;
            }
            e->mUnk_04[i] = a->mUnk_04[i];
            do {
                o = func_0208b7bc(e->mUnk_04[i], &data_02155a14);
                data_0217ae84[p->mUnk_74].mUnk_10[i].mUnk_00_a[j] = o;
                o->mUnk_94 = p;
                o->mUnk_98_24 = j;
                j++;
                o->mUnk_90 = func_0208335c;
            } while (j < 2);
            r = 1;
        }
    }
    return r;
}

s32 func_02083d4c(Unk02155908_00 *a, s32 b, Unk0206bcb0 *p) {
    Unk0217ae84 *e;
    Unk0201ca6c *o;

    e = &data_0217ae84[p->mUnk_74];
    if (a->mUnk_04[0] == e->mUnk_00) {
        return 0;
    }
    if (e->mUnk_0c != 0) {
        e->mUnk_0c->mUnk_98_8 = 1;
    }
    o = func_0208b7bc(a->mUnk_04[0], &data_02155a14);
    e->mUnk_0c = o;
    e->mUnk_00 = a->mUnk_04[0];
    o->mUnk_94 = p;
    o->mUnk_98_0 = b;
    o->mUnk_90 = func_02083484;
    return 1;
}

void func_02083de8(s32 a, Unk0206bcb0 *p) {
    Unk02155908 *t;
    Unk02155908_00 *n;
    Unk0217ae84 *e;
    u16 i;
    u16 j;

    t = &data_02155908[a];
    n = &t->mUnk_00[data_0217ae8c[p->mUnk_74]];
    if (t->mUnk_18(n, t->mUnk_1c, p) == 0) {
        return;
    }
    e = &data_0217ae84[p->mUnk_74];
    for (i = 0; i < n->mUnk_00; i++) {
        for (j = 0; j < 2; j++) {
            if (e->mUnk_10[i].mUnk_00_a[j] != 0) {
                e->mUnk_10[i].mUnk_00_a[j]->mUnk_72 = data_0217ae6c;
            }
        }
    }
}

void func_02083ec4(Unk0206bcb0 *p) {
    Unk0217ae84 *e;

    if (p->mUnk_4c & 0x8000) {
        func_02083a24(&data_02155968.mUnk_00[data_0217ae8c[p->mUnk_74]], 1, p);
        return;
    }
    e = &data_0217ae84[p->mUnk_74];
    if (e->mUnk_20 != 0) {
        e->mUnk_20->mUnk_98_8 = 1;
        e->mUnk_20 = 0;
    }
    if (e->mUnk_24 != 0) {
        e->mUnk_24->mUnk_98_8 = 1;
        e->mUnk_24 = 0;
    }
}

void func_02083f6c(s32 a, Unk0206bcb0 *p) {
    Unk0217ae84 *e;

    if (p->mUnk_4c & 0x8000) {
        data_02155830[a](p);
        return;
    }
    e = &data_0217ae84[p->mUnk_74];
    if (e->mUnk_0c != 0) {
        e->mUnk_0c->mUnk_98_8 = 1;
        e->mUnk_0c = 0;
        e->mUnk_00 = -1;
    }
    func_02083928(p, 0);
    e = &data_0217ae84[p->mUnk_74];
    if (e->mUnk_20 != 0) {
        e->mUnk_20->mUnk_98_8 = 1;
        e->mUnk_20 = 0;
    }
    if (e->mUnk_24 != 0) {
        e->mUnk_24->mUnk_98_8 = 1;
        e->mUnk_24 = 0;
    }
}

void func_02084034(u32 a, Unk0206bcb0 *p) {
    Unk0201ca6c *o;

    if (func_02061818() != 0) {
        return;
    }
    func_020748a8();
    if (data_0217ae80 != 0) {
        data_0217ae80->mUnk_24.mUnk_00_0 = 1;
    }
    o = func_0208b7bc(data_021557f8[a], &data_02155a14);
    o->mUnk_98 = 0;
    o->mUnk_94 = p;
    o->mUnk_90 = func_02083680;
    data_0217ae80 = o;
}

void func_020840c0(Unk0206bcb0 *p) {
    data_021559e8.mUnk_18(&data_021559e8.mUnk_00[data_0217ae8c[p->mUnk_74]], data_021559e8.mUnk_1c, p);
    func_02083928(p, 0);
}

void func_02084114(Unk0206bcb0 *p) {
    Unk0217ae84 *e;

    e = &data_0217ae84[p->mUnk_74];
    if (e->mUnk_0c != 0) {
        e->mUnk_0c->mUnk_98_8 = 1;
        e->mUnk_0c = 0;
        e->mUnk_00 = -1;
    }
    data_021559c8.mUnk_18(&data_021559c8.mUnk_00[data_0217ae8c[p->mUnk_74]], data_021559c8.mUnk_1c, p);
}

void func_0208419c(Unk0206bcb0 *p) {
    Unk0217ae84 *e;

    e = &data_0217ae84[p->mUnk_74];
    if (e->mUnk_0c != 0) {
        e->mUnk_0c->mUnk_98_8 = 1;
        e->mUnk_0c = 0;
        e->mUnk_00 = -1;
    }
    data_021559a8.mUnk_18(&data_021559a8.mUnk_00[data_0217ae8c[p->mUnk_74]], data_021559a8.mUnk_1c, p);
}

void func_02084224(Unk0206bcb0 *p) {
    Unk0217ae84 *e;

    e = &data_0217ae84[p->mUnk_74];
    if (e->mUnk_0c != 0) {
        e->mUnk_0c->mUnk_98_8 = 1;
        e->mUnk_0c = 0;
        e->mUnk_00 = -1;
    }
    data_02155988.mUnk_18(&data_02155988.mUnk_00[data_0217ae8c[p->mUnk_74]], data_02155988.mUnk_1c, p);
}

void func_020842ac(Unk0206bcb0 *p) {
    Unk0217ae84 *e;

    e = &data_0217ae84[p->mUnk_74];
    if (e->mUnk_0c != 0) {
        e->mUnk_0c->mUnk_98_8 = 1;
        e->mUnk_0c = 0;
        e->mUnk_00 = -1;
    }
    data_02155968.mUnk_18(&data_02155968.mUnk_00[data_0217ae8c[p->mUnk_74]], data_02155968.mUnk_1c, p);
}

void func_02084334(Unk0206bcb0 *p) {
    Unk0217ae84 *e;

    e = &data_0217ae84[p->mUnk_74];
    if (e->mUnk_0c != 0) {
        e->mUnk_0c->mUnk_98_8 = 1;
        e->mUnk_0c = 0;
        e->mUnk_00 = -1;
    }
    func_02083de8(2, p);
}

void func_02084384(Unk0206bcb0 *p) {
    data_02155928.mUnk_18(&data_02155928.mUnk_00[data_0217ae8c[p->mUnk_74]], data_02155928.mUnk_1c, p);
    func_02083928(p, 0);
}

void func_020843d8(Unk0206bcb0 *p) {
    data_02155908[0].mUnk_18(&data_02155908[0].mUnk_00[data_0217ae8c[p->mUnk_74]], data_02155908[0].mUnk_1c, p);
    func_02083928(p, 0);
}

void func_0208442c(Unk0206bcb0 *p) {
    Unk0217ae84 *e;

    e = &data_0217ae84[p->mUnk_74];
    if (e->mUnk_0c != 0) {
        e->mUnk_0c->mUnk_98_8 = 1;
        e->mUnk_0c = 0;
        e->mUnk_00 = -1;
    }
    func_02083928(p, 0);
}

void func_02084478(Unk0206bcb0 *p) {
    u16 i;
    Unk0217ae84 *e;
    Vec3 q;
    Vec3 w;
    Vec3 v;

    e = &data_0217ae84[p->mUnk_74];
    p->mUnk_174 = *p->mUnk_508;
    for (i = 0; i < 2; i++) {
        v = p->mUnk_590->mUnk_020->mUnk_14[i + 2];
        v.y = 0;
        v.x = v.x + data_02155800[i];
        q.x = (s32) (((s64) v.x * p->mUnk_bc.x) >> 12);
        q.y = (s32) (((s64) v.y * p->mUnk_bc.y) >> 12);
        q.z = (s32) (((s64) v.z * p->mUnk_bc.z) >> 12);
        func_02147288(&q, &p->mUnk_150_m, &e->mUnk_34[i]);
        e->mUnk_34[i].x = e->mUnk_34[i].x >> 4;
        e->mUnk_34[i].y = e->mUnk_34[i].y >> 4;
        e->mUnk_34[i].z = e->mUnk_34[i].z >> 4;
        func_02146d78(&data_02155818[i], &p->mUnk_150.x, &w);
        e->mUnk_4c[i].mUnk_00 = w.x;
        e->mUnk_4c[i].mUnk_02 = w.y;
        e->mUnk_4c[i].mUnk_04 = w.z;
    }
}

void func_020845cc(u32 a) {
    Unk0217ae84 *e;
    u16 i;
    u16 j;

    i = 0;
    data_0217ae84 = func_02036bec(func_020364e0(func_020364e8()), a * 0x58);
    data_0217ae70 = a;
    for (; i < a; i++) {
        e = &data_0217ae84[i];
        e->mUnk_0c = 0;
        e->mUnk_28 = 0;
        e->mUnk_2c = 0;
        e->mUnk_30 = 0;
        e->mUnk_00 = -1;
        e->mUnk_20 = e->mUnk_24 = 0;
        for (j = 0; j < 2; j++) {
            e->mUnk_10[j].mUnk_00 = e->mUnk_10[j].mUnk_04 = 0;
            e->mUnk_04[j] = -1;
        }
    }
    data_0217ae80 = 0;
}

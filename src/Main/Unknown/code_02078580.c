#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02076cd0.h"
#include "Main/Unknown/code_02078580.h"
#include "code_02010c84.h"
#include "code_02010fac.h"
#include "code_02012b30.h"
#include "code_02013740.h"
#include "code_02016468.h"
#include "code_02147288.h"
#include "code_0214a748.h"
#include "code_0214d018.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "code_021488e8.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "code_02010f98.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "code_020176b0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_02077c1c.h"
#include "Main/Unknown/code_02077eb4.h"
#include "Main/Unknown/code_02078ee0.h"
#include "Main/Unknown/code_02078f9c.h"
#include "Main/Unknown/code_0207adf8.h"
#include "code_02012b20.h"
#include "Main/Unknown/code_0208533c.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02088338.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_02175000.h"
#include "00/code_02182fdc.h"

#pragma thumb on

void func_02078580(Unk0217ad08_058 *param_1, Unk0217ad08_024 *param_2, s32 param_3) {
    Vec3 v;
    s32 m1[9];
    s32 m2[9];
    Unk02012f58 m3;
    Vec3 t;
    Vec3 u;
    Vec3 w;
    Vec3 *e;
    s32 k;
    u16 i;

    data_0217029c.mUnk_a0 = 0xbfff0000;
    t.x = data_usa_021656f0.x;
    t.y = data_usa_021656f0.y;
    t.z = data_usa_021656f0.z;
    k = func_021488e8(data_usa_021656e4, param_2->mUnk_08);
    v.x = k;
    v.y = k;
    v.z = k;
    func_02146d44(m1, data_0215d4b4[(param_2->mUnk_16 >> 4) * 2], data_0215d4b4[(param_2->mUnk_16 >> 4) * 2 + 1]);
    func_02146d28(m2, data_0215d4b4[(((u16) (data_usa_021656dc + param_2->mUnk_1a)) >> 4) * 2],
                  data_0215d4b4[(((u16) (data_usa_021656dc + param_2->mUnk_1a)) >> 4) * 2 + 1]);
    func_02146dfc(m1, m2, m1);
    if (param_1->mUnk_20 != NULL) {
        func_02146ce0(m1, &m3.mUnk_00[0].x);
        m3.mUnk_00[3] = t;
        func_02147914(&m3, &m3, v.x, v.y, v.z);
    } else {
        func_021471bc(&m3);
    }
    func_02010fe4(&v);
    func_0201100c(&t);
    func_0214d0fc(m2, &data_0217029c.mUnk_bc);
    data_0217029c.mUnk_fc &= ~0xa4;
    func_02011034();
    if (data_0217ad08->mUnk_1cc != NULL) {
        func_01ff8cf0(data_0217ad08->mUnk_1cc);
    }
    func_0214d0fc(m1, &data_0217029c.mUnk_bc);
    data_0217029c.mUnk_fc &= ~0xa4;
    func_0201100c(&t);
    func_02011034();
    if (param_1->mUnk_00 != -1 && param_1->mUnk_04 != -1) {
        func_02078934(param_3);
        if (param_1->mUnk_1c != NULL) {
            if (param_3 != 0) {
                param_1->mUnk_1c->mUnk_00.mUnk_54 = 1;
            } else {
                param_1->mUnk_1c->mUnk_00.mUnk_54 = 0;
            }
            ((void (*)(Unk0207adf8 *)) func_0207adf8)(param_1->mUnk_1c);
        }
        if (param_1->mUnk_14 != NULL) {
            if (param_3 != 0) {
                func_02084f68(param_1->mUnk_14);
            } else {
                func_02084f20(param_1->mUnk_14);
            }
            func_01ff8cf0(param_1->mUnk_14);
        }
        if (param_1->mUnk_18 != NULL) {
            for (i = 0; i < 4; i++) {
                if (i < 2) {
                    k = param_1->mUnk_20->mUnk_10;
                    w.x = (s32) (((s64) v.x * k) >> 12);
                    w.y = (s32) (((s64) v.y * k) >> 12);
                    w.z = (s32) (((s64) v.z * k) >> 12);
                } else {
                    w = v;
                }
                if (i != 1 || param_1->mUnk_20->mUnk_14[0].x != 0) {
                    e = &param_1->mUnk_20->mUnk_14[i];
                    u.x = e->x >> 4;
                    u.y = e->y >> 4;
                    u.z = e->z >> 4;
                    func_02147288(&u, &m3, &t);
                    func_02010fe4(&w);
                    func_0201100c(&t);
                    func_02011034();
                    if (param_3 != 0) {
                        func_02084f68(param_1->mUnk_18);
                    } else {
                        func_02084f20(param_1->mUnk_18);
                    }
                    func_01ff8cf0(param_1->mUnk_18);
                }
            }
        }
        if (param_1->mUnk_10 != NULL) {
            func_02147288(&param_1->mUnk_20->mUnk_44[param_1->mUnk_00], &m3, &t);
            func_0201100c(&t);
            func_02011034();
            if (param_3 != 0) {
                func_02084f68(param_1->mUnk_10);
            } else {
                func_02084f20(param_1->mUnk_10);
            }
            func_01ff8cf0(param_1->mUnk_10);
        }
    }
}

void func_020787f4(s32 param_1, s32 param_2) {
    Vec3 a;
    Vec3 e;
    Vec3 d;
    Vec3 b;
    Vec3 c;
    func_02011034();
    a = data_usa_02165708;
    if ((s64) a.z * a.z + ((s64) a.x * a.x + (s64) a.y * a.y) >= 0x10) {
        func_02039860(&a, &a);
    }
    func_02010fac(0, (s16) a.x, (s16) a.y, (s16) a.z);
    func_02010f98(0, (u16) (data_usa_021656d8 | (data_usa_021656d8 << 5) | (data_usa_021656d8 << 10)));
    func_02078934(0);
    b = data_usa_02155188;
    c = data_usa_021656f0;
    c.y += param_2;
    func_021484d0(&c, &data_usa_021656fc, &d);
    func_021483a0(&b, &d, &e);
    data_021704dc = data_usa_021656fc;
    data_021704e8 = e;
    data_021704f4 = c;
    func_0214abb4(&data_usa_021656fc, &e, &c, 0, &data_0217029c.mUnk_4c);
    data_0217029c.mUnk_fc &= ~0xe8;
    func_02011034();
}

void func_02078934(s32 param_1) {
    s32 e;
    s32 d;
    s32 c;
    s32 b;
    s32 a;
    a = (s32) (((s64) func_02147f34(0x579, 0xf09) * 0x200) >> 12);
    b = -a;
    c = (s32) (((s64) b * 0x1555) >> 12);
    d = -c;
    e = d;
    if (param_1 != 0) {
        e = -d;
        c = d;
    }
    func_01ff9048(0x15, NULL, 0);
    func_0214b048(a, b, c, e, 0x200, 0x64000, 0x1000, 0, (Unk0214ad4c *) data_0217029c.mUnk_08);
    data_0217029c.mUnk_fc &= ~0x50;
    func_02011034();
}

void func_020789d4(void) {
    data_0217ad08->mUnk_024.mUnk_30 = 1;
}

void func_020789e4(void) {
    data_0217ad08->mUnk_024.mUnk_30 = 0;
}

void func_020789f4(void) {
    Unk0217ad08_024 *q = &data_0217ad08->mUnk_024;
    switch (q->mUnk_30) {
        case 0:
            q->mUnk_2c += 0x15;
            if (q->mUnk_2c > -0x2e) {
                q->mUnk_2c = -0x2e;
            }
            break;
        case 1:
            q->mUnk_2c -= 0x15;
            if (q->mUnk_2c < -0xfa) {
                q->mUnk_2c = -0xfa;
            }
            break;
    }
}

void func_02078a34(s32 param_1) {
    Unk0217ad08 *d = data_0217ad08;
    Unk0217ad08_024 *q = &d->mUnk_024;
    Unk0217ad08_1f4 *t = &d->mUnk_1f4[d->mUnk_266];
    s32 a = q->mUnk_04;
    s32 c = -1;
    Unk0217ad08_058 *e;
    Unk0217ad08_058 *b;
    if (param_1 == c) {
        e = d->mUnk_058;
        b = &e[d->mUnk_264];
        q->mUnk_04 = param_1;
        b->mUnk_04 = c;
        return;
    }
    if (t->mUnk_2c == 0 && a != param_1 && param_1 <= 0x25) {
        q->mUnk_04 = param_1;
        data_0217ad08->mUnk_260 = 1;
    }
}

void func_02078a9c(s32 param_1) {
    Unk0217ad08 *d = data_0217ad08;
    Unk0217ad08_024 *q = &d->mUnk_024;
    Unk0217ad08_1f4 *t = &d->mUnk_1f4[d->mUnk_266];
    s32 a = q->mUnk_00;
    s32 c = -1;
    Unk0217ad08_058 *e;
    Unk0217ad08_058 *b;
    if (param_1 == c) {
        e = d->mUnk_058;
        b = &e[d->mUnk_264];
        q->mUnk_00 = param_1;
        b->mUnk_00 = c;
        return;
    }
    if (t->mUnk_2c == 0 && a != param_1 && param_1 <= 0xd) {
        q->mUnk_00 = param_1;
        data_0217ad08->mUnk_25c = 1;
    }
}

// non-matching: same instructions; the original keeps the global pointer variable address in r2, the object in r5 and
// computes param_2 * 2 (r3) before loading the row table, we use r5/r4 and compute it later
s16 *func_02078b04(s32 param_1, s32 param_2) {
    Unk0217ad08 *d = data_0217ad08;
    s16 *k = d->mUnk_018;
    Unk0217ad08_01c *v1 = &d->mUnk_01c[param_1];
    d->mUnk_00c[0] = v1->mUnk_00[0];
    d->mUnk_00c[1] = v1->mUnk_00[1];
    d->mUnk_00c[2] = v1->mUnk_00[2];
    d->mUnk_00c[3] = v1->mUnk_00[3];
    d->mUnk_00c[4] = v1->mUnk_00[4];
    d->mUnk_00c[5] = v1->mUnk_00[5];
    d->mUnk_00c[2] += k[param_2];
    return data_0217ad08->mUnk_00c;
}

void func_02078b48(void *param_1) {
    u32 i;
    gKartModels = NULL;
    data_0217ad08 = HeapAlloc(param_1, 0x26c);
    data_0217ad08->mUnk_264 = -1;
    data_0217ad08->mUnk_266 = 0;
    data_0217ad08->mUnk_020 = &data_0217ad08->mUnk_058[data_0217ad08->mUnk_266];
    data_0217ad08->mUnk_1d0 = NULL;
    data_0217ad08->mUnk_1dc = 0;
    data_0217ad08->mUnk_1d8 = NULL;
    data_0217ad08->mUnk_1e4 = 0;
    data_0217ad08->mUnk_018 = NULL;
    data_0217ad08->mUnk_01c = NULL;
    data_0217ad08->mUnk_25c = 0;
    data_0217ad08->mUnk_260 = 0;
    data_0217ad08->mUnk_268 = NULL;
    data_0217ad08->mUnk_1f0 = 0;
    data_0217ad08->mUnk_1ec = NULL;
    data_0217ad08->mUnk_1e8 = data_0217ad08->mUnk_1ec;
    func_02077a28(param_1);
    LoadKartModelMenuFile(param_1, data_usa_02165724, (void **) &data_0217ad08->mUnk_1c8);
    for (i = 0; i < 2; i = (u16) (i + 1)) {
        func_02078f18(param_1, (s32) &data_0217ad08->mUnk_058[i]);
    }
    func_02078ee0(&data_0217ad08->mUnk_024, 1);
    func_02047b6c(9);
}

void func_02078c58(void *param_1) {
    u32 i;
    enum { K0 } j;
    s32 a;
    func_02047b6c(1);
    func_02062860();
    func_02012b20(0);
    data_021759d0->mUnk_1c &= ~8;
    func_02077bc0(param_1);
    func_0208533c();
    SetKartModelPathPrefix(1);
    func_02078b48(param_1);
    func_020790e0(param_1, 1);
    j = 0;
    data_0217ad08->mUnk_000 = j;
    data_0217ad08->mUnk_008 = j;
    data_0217ad08->mUnk_004 = j;
    while (j < 0x24) {
        if (func_02077a70(&a, j) != 0) {
            data_0217ad08->mUnk_008++;
        }
        j++;
    }
    data_0217ad08->mUnk_024.mUnk_08 = data_usa_021656e0;
    for (i = 0; i < 2; i = (u16) (i + 1)) {
        func_02077eb4(param_1, (u32 *) &data_0217ad08->mUnk_1f4[i]);
    }
    data_0217ad08->mUnk_1f4[data_0217ad08->mUnk_266].mUnk_2c = 1;
    data_0217ad08->mUnk_024.mUnk_00 = 0;
    data_0217ad08->mUnk_024.mUnk_04 = 0;
    data_0217ad08->mUnk_020->mUnk_00 = 0;
    data_0217ad08->mUnk_020->mUnk_04 = 0;
    data_0217ad08->mUnk_020->mUnk_20 = data_0217ad08->mUnk_1c8;
    LoadKartAndCharacterFiles();
    func_02077c1c();
    func_02078ee0(&data_0217ad08->mUnk_024, 0);
    func_02047b6c(9);
}

void func_02078d64(void *param_1) {
    u32 i;
    func_02047b6c(1);
    func_02062860();
    func_02012b20(0);
    data_021759d0->mUnk_1c &= ~8;
    func_02077bc0(param_1);
    func_0208533c();
    SetKartModelPathPrefix(1);
    func_02078b48(param_1);
    func_020790e0(param_1, 0);
    LoadKartModelMenuFile(param_1, data_usa_02165738, (void **) &data_0217ad08->mUnk_018);
    LoadKartModelMenuFile(param_1, data_usa_0216574c, (void **) &data_0217ad08->mUnk_01c);
    func_02078f9c(param_1);
    for (i = 0; i < 2; i = (u16) (i + 1)) {
        func_02077eb4(param_1, (u32 *) &data_0217ad08->mUnk_1f4[i]);
    }
    if (data_0217aa08->mUnk_04->mUnk_004 != 0 && data_0217aa08->mUnk_00->mUnk_31_3 == 0) {
        data_0217ad08->mUnk_1e8 = data_0217aa08->mUnk_04->mUnk_008;
        data_0217ad08->mUnk_1ec = func_02077f00()->mData;
    }
    func_02047b6c(9);
}

void func_02078e4c(void *param_1, void *param_2) {
    Unk0201290c *e;
    u8 *t;
    u8 *u;
    u8 *w;
    s32 k;
    s32 h;
    Unk0201290c_08 *x;
    Unk0217ad08 *d = data_0217ad08;
    Unk0217ad08_1f4 *p = &d->mUnk_1f4[d->mUnk_266];
    s16 i = d->mUnk_264;
    if (i >= 0 && p->mUnk_2c == 0) {
        e = d->mUnk_058[i].mUnk_14->mUnk_04;
        k = func_02013754((u8 *) e + e->mUnk_08 + 4, data_usa_02155018);
        t = (u8 *) e + e->mUnk_08;
        u = t + 4;
        w = u + *(u16 *) (t + 0xa);
        x = (Unk0201290c_08 *) (t + *(u32 *) (w + *(u16 *) w * k + 4));
        h = x->mUnk_1c << 4;
        func_02016468(0, (x->mUnk_14 & 0xffff) << 3, param_1, 0x200);
        func_02016468(1, h, param_2, 0x20);
    }
}

#pragma thumb off

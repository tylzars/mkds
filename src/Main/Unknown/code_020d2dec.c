#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d3ae0.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_02103598.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_020e3b28.h"
#include "Main/Unknown/code_020e3618.h"
#include "Main/Unknown/code_020ff344.h"
#include "Main/Unknown/code_020e662c.h"
#include "Main/Unknown/code_020e6f58.h"
#include "Main/Unknown/code_020d49e0.h"
#include "Main/Unknown/code_020d4a18.h"
#include "Main/Unknown/code_020e6f9c.h"
#include "Main/Unknown/code_020e6fc4.h"
#include "Main/Unknown/code_020d4bf0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02059000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_020df890.h"
#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

static inline Unk0217b4d4 *func_020d34e4_inline(u16 f) {
    s32 j;
    for (j = 0; j < 1000; j++) {
        if (f == data_0217b4d4[j].mUnk_00) {
            return &data_0217b4d4[j];
        }
    }
    return NULL;
}

Unk020e71a0 *func_020d34e4(u32 param_1, Unk020fa294 *param_2, Unk020e71a0 *param_3) {
    s32 i;
    s32 j;
    Unk0216b288 *row;
    Unk021000d0 *a;
    Unk021000d0 *o;
    Unk020e71a0_98 *c;
    Unk0217b4d4 *t;
    Unk020e71a0 *p;
    s32 v;
    u32 m;
    for (i = 0; i < data_0217b4ec; i++) {
        {
            row = &data_0216b288[i];
            if (param_1 != row->mUnk_00) {
                continue;
            }
            a = row->mUnk_04;
            if (a->mUnk_00 == 0) {
                for (j = 0; j < data_0217b4ec; j++) {
                    o = data_0216b288[j].mUnk_04;
                    if (o == NULL) {
                        continue;
                    }
                    if (o->mUnk_10 == a->mUnk_10 && o->mUnk_24 != NULL) {
                        a->mUnk_24 = o->mUnk_24;
                    }
                    if (o->mUnk_10 == a->mUnk_14 && o->mUnk_24 != NULL) {
                        a->mUnk_28 = o->mUnk_24;
                    }
                    if (o->mUnk_10 == a->mUnk_18 && o->mUnk_24 != NULL) {
                        a->mUnk_2c = o->mUnk_24;
                    }
                    if (o->mUnk_14 == a->mUnk_10 && o->mUnk_28 != NULL) {
                        a->mUnk_24 = o->mUnk_28;
                    }
                    if (o->mUnk_14 == a->mUnk_14 && o->mUnk_28 != NULL) {
                        a->mUnk_28 = o->mUnk_28;
                    }
                    if (o->mUnk_14 == a->mUnk_18 && o->mUnk_28 != NULL) {
                        a->mUnk_2c = o->mUnk_28;
                    }
                    if (o->mUnk_18 == a->mUnk_10 && o->mUnk_2c != NULL) {
                        a->mUnk_24 = o->mUnk_2c;
                    }
                    if (o->mUnk_18 == a->mUnk_14 && o->mUnk_2c != NULL) {
                        a->mUnk_28 = o->mUnk_2c;
                    }
                    if (o->mUnk_18 == a->mUnk_18 && o->mUnk_2c != NULL) {
                        a->mUnk_2c = o->mUnk_2c;
                    }
                    if (o->mUnk_1c == a->mUnk_1c && o->mUnk_30 != NULL) {
                        a->mUnk_30 = o->mUnk_30;
                    }
                }
                if (a->mUnk_20 == NULL && a->mUnk_0c != NULL) {
                    a->mUnk_20 = a->mUnk_0c();
                    if (a->mUnk_20 == NULL) {
                        return NULL;
                    }
                    if (a->mUnk_20->mUnk_24 == 0) {
                        a->mUnk_20->mUnk_24 = -1;
                    }
                    if (a->mUnk_20->mUnk_28 == 0) {
                        a->mUnk_20->mUnk_28 = -1;
                    }
                    if (a->mUnk_20->mUnk_38 == 0) {
                        a->mUnk_20->mUnk_38 = 0x64000;
                    }
                    if (a->mUnk_20->mUnk_3c == 0) {
                        a->mUnk_20->mUnk_3c = -0x64000;
                    }
                    if (data_021759c0->mUnk_00c == 2) {
                        if (a->mUnk_20->mUnk_38 < 0x44c000) {
                            a->mUnk_20->mUnk_38 = 0x44c000;
                        }
                    }
                }
                t = func_020d34e4_inline(row->mUnk_00);
                if (t->mUnk_02 != 0) {
                    a->mUnk_20->mUnk_34 = t->mUnk_02 >= 2 ? 1 : 0;
                    v = t->mUnk_04;
                    a->mUnk_20->mUnk_2c = (s32) (v != 0 ? (float) (v << 12) + 0.5f : (float) (v << 12) - 0.5f);
                    v = t->mUnk_06;
                    a->mUnk_20->mUnk_30 = (s32) (v != 0 ? (float) (v << 12) + 0.5f : (float) (v << 12) - 0.5f);
                }
                if (t->mUnk_08 != 0) {
                    a->mUnk_20->mUnk_08 = t->mUnk_08;
                    v = t->mUnk_0a;
                    a->mUnk_20->mUnk_0c = (s32) (v != 0 ? (float) (v << 12) + 0.5f : (float) (v << 12) - 0.5f);
                    v = t->mUnk_0c;
                    a->mUnk_20->mUnk_10 = (s32) (v != 0 ? (float) (v << 12) + 0.5f : (float) (v << 12) - 0.5f);
                    v = t->mUnk_0e;
                    a->mUnk_20->mUnk_14 = (s32) (v != 0 ? (float) (v << 12) + 0.5f : (float) (v << 12) - 0.5f);
                }
                if (a->mUnk_24 == NULL && a->mUnk_10 != NULL) {
                    a->mUnk_24 = a->mUnk_10();
                }
                if (a->mUnk_28 == NULL && a->mUnk_14 != NULL) {
                    a->mUnk_28 = a->mUnk_14();
                }
                if (a->mUnk_2c == NULL && a->mUnk_18 != NULL) {
                    a->mUnk_2c = a->mUnk_18();
                }
                if (a->mUnk_30 == NULL && a->mUnk_1c != NULL) {
                    a->mUnk_30 = a->mUnk_1c();
                }
            }
            if (a == NULL) {
                continue;
            }
            c = a->mUnk_20;
            p = func_02036bec(func_020364e0(func_020364e8()), a->mUnk_04);
            a->mUnk_00++;
            if (param_2 != NULL) {
                p->mUnk_9c = param_2;
            } else if (param_3 != NULL) {
                p->mUnk_9c = param_3->mUnk_9c;
            }
            p->mUnk_00 = param_1;
            p->mUnk_02 = 0;
            if (data_0217b4e0 != 0) {
                p->mUnk_02 |= data_021568c8;
            }
            p->mUnk_64 = -1;
            if (param_2 != NULL) {
                p->mUnk_04.x = param_2->mUnk_00.x;
                p->mUnk_04.y = param_2->mUnk_00.y;
                p->mUnk_04.z = param_2->mUnk_00.z;
            } else if (param_3 != NULL) {
                p->mUnk_04.x = param_3->mUnk_04.x;
                p->mUnk_04.y = param_3->mUnk_04.y;
                p->mUnk_04.z = param_3->mUnk_04.z;
            }
            if (c->mUnk_20 == 0 || c->mUnk_20 == 2) {
                p->mUnk_10.x = 0;
                p->mUnk_10.y = 0;
                p->mUnk_10.z = 0;
            } else {
                p->mUnk_10.x = 0x270f000;
                p->mUnk_10.y = 0x270f000;
                p->mUnk_10.z = 0x270f000;
            }
            if (param_2 != NULL) {
                p->mUnk_7e = (u16) (((s64) param_2->mUnk_0c.y * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
                func_020d6df0(&param_2->mUnk_0c, (s32 *) &p->mUnk_28);
            } else if (param_3 != NULL) {
                p->mUnk_7e = param_3->mUnk_7e;
                p->mUnk_28 = param_3->mUnk_28;
            }
            p->mUnk_98 = c;
            if (param_2 != NULL) {
                func_020d29cc(p, &param_2->mUnk_18);
            } else {
                func_020d29cc(p, &param_3->mUnk_1c);
            }
            func_020d24d8(p, c->mUnk_30);
            p->mUnk_7c = c->mUnk_34;
            if (c->mUnk_08 != 0) {
                p->mUnk_02 &= ~1;
            } else {
                p->mUnk_02 |= data_021568cc;
            }
            if (c->mUnk_1c != 0) {
                p->mUnk_02 &= ~0x40;
            } else {
                p->mUnk_02 |= data_021568d0;
            }
            if ((a->mUnk_24 != NULL && a->mUnk_24->mUnk_10 != NULL) || (a->mUnk_28 != NULL && a->mUnk_28->mUnk_10 != NULL) ||
                (a->mUnk_2c != NULL && a->mUnk_2c->mUnk_10 != NULL)) {
                p->mUnk_02 &= ~2;
                p->mUnk_02 &= ~8;
                p->mUnk_66 = 0x1f;
            } else {
                p->mUnk_02 |= data_021568d4;
                p->mUnk_02 |= data_021568d8;
            }
            if (param_3 != NULL) {
                p->mUnk_74 = param_3->mUnk_74;
                p->mUnk_02 |= param_3->mUnk_02 & 0x80;
            } else if (param_2 != NULL) {
                if (param_2->mUnk_36 != 0) {
                    func_020d3ae0(param_2->mUnk_36, p);
                }
            }
            if (a->mUnk_30 != NULL && a->mUnk_30->mUnk_10 != NULL) {
                p->mUnk_02 &= ~4;
            } else {
                p->mUnk_02 |= data_021568dc;
            }
            p->mUnk_70 = data_0217ca6c[2].mUnk_20;
            if (param_2 != NULL) {
                if (a->mUnk_08 != NULL) {
                    a->mUnk_08(p, param_2, data_0216b288[i].mUnk_08);
                }
            } else if (param_3 != NULL) {
                if (a->mUnk_08 != NULL) {
                    a->mUnk_08(p, NULL, param_3);
                }
            }
            if (c->mUnk_08 != 0) {
                m = 0x2000;
                if (c->mUnk_20 == 0) {
                    m |= data_021568e0;
                }
                if (func_020dff70(p->mUnk_00) != 0 || func_020e4320(p->mUnk_00) != 0 ||
                    func_020e3af0(p->mUnk_00) != 0 || func_020ffabc(p->mUnk_00) != 0) {
                    m |= data_021568e4;
                }
                p->mUnk_64 = func_020d555c(&p->mUnk_04, func_020d252c(p), m, p);
            }
            j = data_0217b4f0->mUnk_004;
            data_0217b4f0->mUnk_004 = j + 1;
            data_0217b4f0->mUnk_000[j] = p;
            if (data_0217b4f0->mUnk_004 >= 0x100) {
                data_0217b4f0->mUnk_004 = 0xff;
            }
            return p;
        }
    }
    return NULL;
}

Unk020e71a0 *func_020d34d4(Unk020e71a0 *param_1, s32 param_2) {
    return func_020d34e4(param_2, NULL, param_1);
}

Unk020e71a0 *func_020d34c4(Unk020fa294 *param_1, s32 param_2) {
    return func_020d34e4(param_2, param_1, NULL);
}

void func_020d2e6c(void) {
    void *h;
    s32 i;
    s32 n;
    s32 j;
    s32 m;
    s32 c1;
    s32 c2;
    s32 s1;
    s32 s2;
    s32 k;
    s32 t;
    s32 g;
    u32 v;
    Unk0216b288 *row;
    Unk021000d0 *d;
    Unk020fa294 *e;
    Unk020e71a0 *o;
    Unk020e6fd4 *w[3];
    Unk020e6fd4 *x;
    Unk020e6fd4 **y;
    Unk0217b4f0 *q;
    h = func_020364e0(func_020364e8());
    func_020d22e0();
    data_0217b4cc = func_02061788();
    data_0217b4c0 = data_0217b4cc + 9;
    data_0217b4c8 = data_0217b4c0 + 1;
    n = gCourseMap->mUnk_04;
    data_0217b4f0 = func_02036bec(h, 0x2bc);
    data_0217b4f0->mUnk_000 = func_02036bec(h, 0x400);
    data_0217b4e8 = func_02036bec(h, 0x80);
    data_0217b4dc = func_02036bec(h, 0x180);
    data_0217b4f0->mUnk_004 = 0;
    data_0217b4f0->mUnk_130 = 0;
    data_0217b4f0->mUnk_178 = 0;
    v = 0;
    if (data_021759c0->mUnk_08 != 5) {
        v = 1;
    }
    data_0217b4f0->mUnk_2b8 = v;
    data_0217b4ec = 0;
    do {
        row = &data_0216b288[data_0217b4ec];
        d = row->mUnk_04;
        if (row->mUnk_00 == 0) {
            break;
        }
        if (data_0217aa10->mUnk_00 != 1 && func_02059c04(d) != 0) {
            break;
        }
        if (d != NULL) {
            d->mUnk_20 = NULL;
            d->mUnk_24 = NULL;
            d->mUnk_28 = NULL;
            d->mUnk_2c = NULL;
            d->mUnk_30 = NULL;
        }
        data_0217b4ec++;
    } while (data_0217b4ec < 0x85);
    data_0217b4d4 = FindMainRaceOrMainEffectFile("MapObj/grpconf.tbl");
    v = 1;
    if (data_021759c0->mUnk_08 != 1 && data_021759c0->mUnk_08 != 5) {
        v = 0;
    }
    data_0217b4e0 = v;
    data_0217b4f0->mUnk_17c = 0;
    data_0217b4f0->mUnk_180 = 0;
    data_0217b4f0->mUnk_184 = 0;
    data_0217b4f0->mUnk_188 = 0;
    data_0217b4e4 = NULL;
    data_0217b4d8 = NULL;
    func_02103598();
    func_020d7df8();
    func_020e662c();
    func_020d4bf0();
    data_0217b4c4 = data_0217b4c8;
    data_0217b4d0 = data_0217b4cc;
    for (i = 0; i < data_0217b4ec; i++) {
        if (data_0216b288[i].mUnk_04 != NULL) {
            data_0216b288[i].mUnk_04->mUnk_00 = 0;
        }
    }
    for (i = 0; i < n; i++) {
        e = (Unk020fa294 *) ((u8 *) gCourseMap->mUnk_00 + i * sizeof(Unk020fa294));
        if (data_021759c0->mUnk_08 == 1 && (e->mUnk_38 & 1) == 0) {
            continue;
        }
        func_020d34e4(e->mUnk_24, e, NULL);
        data_0217b4f0->mUnk_17c |= func_020dff70(e->mUnk_24);
        data_0217b4f0->mUnk_180 |= func_020e4320(e->mUnk_24);
        data_0217b4f0->mUnk_184 |= func_020e3af0(e->mUnk_24);
        data_0217b4f0->mUnk_188 |= func_020ffabc(e->mUnk_24);
    }
    if (data_0217b4f0->mUnk_17c != 0 || data_0217b4f0->mUnk_180 != 0 || data_0217b4f0->mUnk_184 != 0 ||
        data_0217b4f0->mUnk_188 != 0) {
        data_0217b610 = 1;
    }
    func_02105214();
    data_0217b4f0->mUnk_128 = 0;
    for (m = 0; m < 24; m++) {
        data_0217b4f0->mUnk_008[m] = NULL;
    }
    for (i = 0; i < data_0217b4ec; i++) {
        if (data_0216b288[i].mUnk_04 == NULL) {
            continue;
        }
        v = data_0216b288[i].mUnk_04->mUnk_00;
        w[0] = data_0216b288[i].mUnk_04->mUnk_24;
        w[1] = data_0216b288[i].mUnk_04->mUnk_28;
        w[2] = data_0216b288[i].mUnk_04->mUnk_2c;
        for (j = 0; j < 3; j++) {
            s32 g;
            if (w[j] == NULL) {
                continue;
            }
            g = 1;
            for (m = 0; m < data_0217b4f0->mUnk_128; m++) {
                if (data_0217b4f0->mUnk_008[m] == w[j]) {
                    func_020d4a10(w[j], v);
                    g = 0;
                }
            }
            if (g != 0) {
                func_020d4a18(w[j]);
                if (v != 0) {
                    func_020d4a10(w[j], v);
                    data_0217b4f0->mUnk_008[data_0217b4f0->mUnk_128++] = w[j];
                }
            }
        }
    }
    for (i = 0; i < data_0217b4f0->mUnk_128; i++) {
        func_020d49f0(data_0217b4f0->mUnk_008[i]);
    }
    for (i = 0; i < data_0217b4f0->mUnk_004; i++) {
        o = data_0217b4f0->mUnk_000[i];
        for (j = 0; j < data_0217b4ec; j++) {
            if (o->mUnk_00 == data_0216b288[j].mUnk_00) {
                w[0] = data_0216b288[j].mUnk_04->mUnk_24;
                w[1] = data_0216b288[j].mUnk_04->mUnk_28;
                w[2] = data_0216b288[j].mUnk_04->mUnk_2c;
                if (w[0] != NULL) {
                    func_020d49e0(w[0], o);
                }
                if (w[1] != NULL) {
                    func_020d49e0(w[1], o);
                }
                if (w[2] != NULL) {
                    func_020d49e0(w[2], o);
                }
            }
        }
    }
    for (i = 0; i < data_0217b4f0->mUnk_128; i++) {
        func_020d4990(data_0217b4f0->mUnk_008[i]);
    }
    data_0217b4f0->mUnk_130 = 1;
    func_020d2e24();
    n = data_0217b4f0->mUnk_128;
    c1 = 0;
    c2 = 0;
    s1 = 0;
    s2 = 0;
    for (t = 0; t < n; t++) {
        x = data_0217b4f0->mUnk_008[t];
        if (x->mUnk_20 != 0) {
            if (x->mUnk_18 == 1) {
                c1++;
            } else if (x->mUnk_18 == 2) {
                c2++;
            }
        }
    }
    m = 0;
    for (i = 0; i < n; i++) {
        x = data_0217b4f0->mUnk_008[i];
        if (x->mUnk_18 == 1) {
            y = data_0217b4f0->mUnk_068;
            data_0217b4f0->mUnk_12a++;
            if (x->mUnk_20 != 0) {
                k = s1++;
            } else {
                k = c1++;
            }
        } else if (x->mUnk_18 == 2) {
            y = data_0217b4f0->mUnk_0c8;
            data_0217b4f0->mUnk_12c++;
            if (x->mUnk_20 != 0) {
                k = s2++;
            } else {
                k = c2++;
            }
        }
        y[k] = x;
    }
    data_0217b4f0->mUnk_174 = 0;
    for (i = 0; i < 16; i++) {
        data_0217b4f0->mUnk_134[i] = NULL;
    }
    for (i = 0; i < data_0217b4ec; i++) {
        if (data_0216b288[i].mUnk_04 == NULL) {
            continue;
        }
        v = data_0216b288[i].mUnk_04->mUnk_00;
        x = data_0216b288[i].mUnk_04->mUnk_30;
        if (x == NULL) {
            continue;
        }
        g = 1;
        for (j = 0; j < data_0217b4f0->mUnk_174; j++) {
            if (data_0217b4f0->mUnk_134[j] == x) {
                func_020e6fc4(x, v);
                g = 0;
            }
        }
        if (g != 0) {
            func_020e6fcc(x);
            if (v != 0) {
                func_020e6fc4(x, v);
                data_0217b4f0->mUnk_134[data_0217b4f0->mUnk_174++] = x;
            }
        }
    }
    for (i = 0; i < data_0217b4f0->mUnk_174; i++) {
        func_020e6f9c(data_0217b4f0->mUnk_134[i]);
    }
    for (i = 0; i < data_0217b4f0->mUnk_004; i++) {
        o = data_0217b4f0->mUnk_000[i];
        for (j = 0; j < data_0217b4ec; j++) {
            if (o->mUnk_00 == data_0216b288[j].mUnk_00 && data_0216b288[j].mUnk_04->mUnk_30 != NULL) {
                func_020e6f58(data_0216b288[j].mUnk_04->mUnk_30, o);
            }
        }
    }
    data_0217b4f0->mUnk_178 = 1;
    func_020d2dec();
}

void func_020d2e24(void) {
    s32 i;
    s32 n;
    Unk020e6fd4 **p;
    n = data_0217b4f0->mUnk_128;
    p = data_0217b4f0->mUnk_008;
    if (data_0217b4e4 != NULL) {
        func_020d9900(data_0217b4e4);
    }
    func_020e52bc();
    for (i = 0; i < n; p++, i++) {
        if ((*p)->mUnk_08 != NULL) {
            (*p)->mUnk_08(*p);
        }
    }
}

void func_020d2dec(void) {
    s32 i;
    s32 n;
    Unk020e6fd4 **p;
    n = data_0217b4f0->mUnk_174;
    p = data_0217b4f0->mUnk_134;
    for (i = 0; i < n; p++, i++) {
        if ((*p)->mUnk_08 != NULL) {
            (*p)->mUnk_08(*p);
        }
    }
}

#pragma thumb off

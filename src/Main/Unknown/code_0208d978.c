#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_0208b000.h"
#include "code_02013730.h"
#include "Main/Unknown/code_020d2b78.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02012b30.h"
#include "code_0201750c.h"
#include "code_02147288.h"
#include "code_0214a4dc.h"
#include "code_020172d0.h"

void func_0208e99c(Unk0208ec64 *a) {
    Unk0208ec64_08 *p;
    Unk0208ec64_08 *q;
    Unk0208ec64_08 *r;
    u32 f;

    p = ListGetNext(&a->mUnk_08, NULL);
    if (p != NULL) {
        do {
            q = ListGetNext(&a->mUnk_08, p);
            p->mUnk_0c = p->mUnk_0c + 1;
            if (p->mUnk_0c > data_021663e0) {
                f = 1;
            } else {
                p->mUnk_08 = p->mUnk_08 - data_021663f0;
                f = 0;
            }
            if (f != 0) {
                ListRemove(&a->mUnk_08, p);
                ListAppend(&data_0217b08c->mUnk_00[2], p);
                if (q == NULL) {
                    break;
                }
                p = q;
            }
            p = ListGetNext(&a->mUnk_08, p);
        } while (p != NULL);
    }
    if (a->mUnk_18 == 0) {
        r = ListGetNth(&data_0217b08c->mUnk_00[2], 0);
        ListRemove(&data_0217b08c->mUnk_00[2], r);
        ListAppend(&a->mUnk_08, r);
        data_021663ec(r, a);
        return;
    }
    if (a->mUnk_08.mCount != 0) {
        return;
    }
    ListRemove(&data_0217b08c->mUnk_00[0], a);
    ListAppend(&data_0217b08c->mUnk_00[1], a);
}

void func_0208e82c(const Unk02012f58 *a, Unk0208ec64_08 *b, Unk0208ec64_08 *c, Unk021663f4 *d) {
    Unk02012f58 m;
    Unk02012f58 n;

    Matrix4x3FromDiagonal(&m, 0x1000, b->mUnk_08, 0x1000);
    Matrix4x3FromDiagonal(&n, 0x1000, c->mUnk_08, 0x1000);
    m.mUnk_00[3].x = b->mUnk_10.x;
    m.mUnk_00[3].y = b->mUnk_10.y;
    m.mUnk_00[3].z = b->mUnk_10.z;
    n.mUnk_00[3].x = c->mUnk_10.x;
    n.mUnk_00[3].y = c->mUnk_10.y;
    n.mUnk_00[3].z = c->mUnk_10.z;
    Matrix4x3Multiply(&m, a, &m);
    Matrix4x3Multiply(&n, a, &n);
    *(u32 *) 0x4000500 = 1;
    GxFifoWrite0x17Then12Words(&m);
    *(u32 *) 0x4000488 = (u16) ((d->mUnk_1c << 8) >> 16);
    *(u32 *) 0x4000490 = 0x10000;
    *(u32 *) 0x4000488 = 0;
    *(u32 *) 0x4000490 = 0xf0000;
    GxFifoWrite0x17Then12Words(&n);
    *(u32 *) 0x4000488 = (u16) ((d->mUnk_20 << 8) >> 16) << 16;
    *(u32 *) 0x4000490 = 0xf0000;
    *(u32 *) 0x4000488 = (u16) ((d->mUnk_1c << 8) >> 16) | (u16) ((d->mUnk_20 << 8) >> 16) << 16;
    *(u32 *) 0x4000490 = 0x10000;
    *(u32 *) 0x4000504 = 0;
}

void func_0208e808(s32 a) {
    if (data_021759c0->mUnk_00c == 5) {
        data_021663e8 = a;
    }
}

void func_0208e570(void *a) {
    u16 i;
    void *c;
    void *d;
    void *e;
    void *f;
    Unk0216618c *x;
    Unk0216618c *y;

    if (data_021759c0->mMode == 4) {
        a = data_0217aa10->mUnk_a4;
    }
    data_0217b080 = HeapAlloc(a, 0x60);
    ListInit(&data_0217b080->mUnk_00, 0);
    for (i = 0; i < 5; i++) {
        ListInit(&data_0217b080->mUnk_0c[i], 0);
    }
    x = data_0216618c;
    y = &data_021661b8;
    if (data_021759c0->mMode == 5) {
        x->mUnk_00 = 6;
        y->mUnk_00 = 4;
    } else {
        x->mUnk_00 = 3;
        y->mUnk_00 = 1;
    }
    if (data_021759c0->mMode == 4) {
        x->mUnk_00 = 0x14;
    }
    func_0208e2c8(&data_021661e4, 1);
    func_0208e2c8(&data_0216623c, 2);
    func_0208e23c();
    func_0208e098(a);
    c = FindMainRaceOrMainEffectFile(data_02166298);
    d = FindMainRaceOrMainEffectFile(data_021662b8);
    e = FindMainRaceOrMainEffectFile(data_021662d8);
    f = FindMainRaceOrMainEffectFile(data_021662f8);
    func_0208ddf4(a, 0, c, d, e, f);
    c = FindMainRaceOrMainEffectFile(data_02166318);
    d = FindMainRaceOrMainEffectFile(data_0216633c);
    e = FindMainRaceOrMainEffectFile(data_02166360);
    f = FindMainRaceOrMainEffectFile(data_02166384);
    func_0208ddf4(a, 1, c, d, e, f);
    func_0208ddf4(a, 2, (void *) func_020d2be8(), (void *) func_020d2bb0(), (void *) func_020d2b78(), NULL);
    func_0208ddf4(a, 4, (void *) func_020d2be8(), (void *) func_020d2bb0(), (void *) func_020d2b78(), NULL);
    if (data_021759c0->mCourseId == 0x17) {
        func_0208ddf4(a, 3, (void *) func_020d2be8(), FindCourseFile(data_021663a8), FindCourseFile(data_021663c0),
                      NULL);
    }
    data_0217b080->mUnk_5c = 10;
}

Unk0208e490 *func_0208e490(u32 a, const Vec3 *b, s32 c) {
    Unk0208e490 *p;

    p = ListGetNth(&data_0217b080->mUnk_0c[a], 0);
    if (p != NULL) {
        ListRemove(&data_0217b080->mUnk_0c[a], p);
        p->mUnk_88 = 0;
        p->mUnk_74 = *b;
        p->mUnk_a8 = 0;
        p->mUnk_ac = 0;
        p->mUnk_b0 = data_0217b080->mUnk_5c;
        p->mUnk_b4 = 1;
        p->mUnk_80(p, c);
        ListAppend(&data_0217b080->mUnk_00, p);
        data_0217b080->mUnk_5c++;
        if (data_0217b080->mUnk_5c > 0xd) {
            data_0217b080->mUnk_5c = 10;
        }
    }
    return p;
}

void func_0208e400(void) {
    Unk0208e490 *p;

    p = ListGetNext(&data_0217b080->mUnk_00, NULL);
    if (p == NULL) {
        return;
    }
    do {
        p->mUnk_84(p);
        p->mUnk_a8 = p->mUnk_a8 + 1;
        if (p->mUnk_88 == 1) {
            ListRemove(&data_0217b080->mUnk_00, p);
            ListAppend(&data_0217b080->mUnk_0c[p->mUnk_8c], p);
        }
        p = ListGetNext(&data_0217b080->mUnk_00, p);
    } while (p != NULL);
}

void func_0208e358(void) {
    Unk02012f58 m;
    Unk0208e490 *p;

    Matrix4x3Identity(&m);
    p = ListGetNext(&data_0217b080->mUnk_00, NULL);
    if (p == NULL) {
        return;
    }
    do {
        if (p->mUnk_b4 != 0) {
            m.mUnk_00[3].x = p->mUnk_74.x >> 4;
            m.mUnk_00[3].y = p->mUnk_74.y >> 4;
            m.mUnk_00[3].z = p->mUnk_74.z >> 4;
            func_020849c0(&p->mUnk_08, p->mUnk_b0);
            func_020849f8(&p->mUnk_08, &m, (u32 *) p->mUnk_9c);
        }
        p = ListGetNext(&data_0217b080->mUnk_00, p);
    } while (p != NULL);
}

void func_0208e2c8(Unk0216618c *a, s32 b) {
    u32 x;
    u32 y;
    u32 z;

    x = func_020d2be8();
    data_0217b07c = 0;
    if (x != 0) {
        y = func_020d2bb0();
        z = func_020d2b78();
        a->mUnk_00 = b;
        if (y != 0) {
            a->mUnk_04 = TRUE;
        } else {
            a->mUnk_04 = FALSE;
        }
        if (z != 0) {
            a->mUnk_08 = TRUE;
        } else {
            a->mUnk_08 = FALSE;
        }
    } else {
        a->mUnk_00 = 0;
        a->mUnk_04 = FALSE;
        a->mUnk_08 = FALSE;
        data_0217b084[0] = -1;
        data_0217b084[1] = -1;
    }
}

void func_0208e23c(void) {
    Unk0216618c *e;
    void *x;
    void *y;

    e = &data_02166210;
    if (func_020d2be8() != 0) {
        x = FindCourseFile(data_02166268);
        y = FindCourseFile(data_02166280);
        e->mUnk_00 = 1;
        if (x != NULL) {
            e->mUnk_04 = TRUE;
        } else {
            e->mUnk_04 = FALSE;
        }
        if (y != NULL) {
            e->mUnk_08 = TRUE;
        } else {
            e->mUnk_08 = FALSE;
        }
    } else {
        e->mUnk_00 = 0;
        e->mUnk_04 = FALSE;
        e->mUnk_08 = FALSE;
    }
}

void func_0208e098(void *a) {
    u16 i;
    u16 j;
    Unk0216618c *g;
    Unk0208e490 *p;
    s32 v;

    for (i = 0; i < 5; i++) {
        g = &data_0216618c[i];
        if (g->mUnk_00 == 0) {
            continue;
        }
        data_0217b080->mUnk_48[i] = HeapAlloc(a, g->mUnk_00 << 2);
        for (j = 0; j < g->mUnk_00; j++) {
            p = HeapAlloc(a, g->mUnk_18);
            data_0217b080->mUnk_48[i][j] = p;
            if (g->mUnk_04 == FALSE) {
                p->mUnk_90[0] = NULL;
            } else {
                p->mUnk_90[0] = HeapAlloc(a, 0x38);
            }
            if (g->mUnk_08 == FALSE) {
                p->mUnk_90[1] = NULL;
            } else {
                p->mUnk_90[1] = HeapAlloc(a, 0x38);
            }
            if (g->mUnk_0c == 0) {
                p->mUnk_90[2] = NULL;
            } else {
                p->mUnk_90[2] = HeapAlloc(a, 0x38);
            }
            p->mUnk_8c = i;
            p->mUnk_80 = g->mUnk_10;
            p->mUnk_84 = g->mUnk_14;
            ListAppend(&data_0217b080->mUnk_0c[i], p);
            if (i == 2) {
                v = data_021759c0->mCourseId == 0xc ? 0xb33 : 0x1000;
                p->mUnk_9c[0] = v;
                p->mUnk_9c[1] = v;
                p->mUnk_9c[2] = v;
            }
        }
    }
}

void func_0208ddf4(void *a, s32 b, Unk020136f0 *c, void *d, void *e, void *f) {
    u16 i;
    u8 *t;
    Unk02087d0c *o;
    Unk0201290c *h;
    Unk0208e490 *p;
    Unk0216618c *g;
    u32 k;

    g = &data_0216618c[b];
    k = 1;
    if (data_021759c0->mCourseId == 0x12 || data_021759c0->mCourseId == 0x1d) {
        k = 0;
    }
    if (g->mUnk_00 == 0) {
        return;
    }
    if (b != 3) {
        func_0208526c(&g->mUnk_1c, c, c);
    }
    if (b == 2) {
        data_0217b07c = 1;
    }
    t = (u8 *) func_02013730((u32) c);
    h = (Unk0201290c *) (t + *(u32 *) (t + *(u16 *) (t + 0xe) + 0xc));
    for (i = 0; i < g->mUnk_00; i++) {
        p = data_0217b080->mUnk_48[b][i];
        func_02084f10(&p->mUnk_08, h);
        func_02013044(p->mUnk_08.mUnk_04, k);
        o = p->mUnk_90[0];
        if (o != NULL) {
            if (d != NULL) {
                func_0208823c(0, o, &p->mUnk_08, 1, a, c);
                func_0208805c(o, d, a);
            } else {
                o->mUnk_18 = 0;
            }
            if (b == 2) {
                if (func_02087d0c(p->mUnk_90[0]) >> 12 == 0x20) {
                    data_0217b084[0] = 0x37;
                    data_0217b084[1] = 0x38;
                } else {
                    data_0217b084[0] = 0x39;
                    data_0217b084[1] = -1;
                }
            }
        }
        o = p->mUnk_90[1];
        if (o != NULL) {
            if (e != NULL) {
                func_0208823c(4, o, &p->mUnk_08, 1, a, c);
                func_0208805c(o, e, a);
            } else {
                o->mUnk_18 = 0;
            }
        }
        o = p->mUnk_90[2];
        if (o != NULL) {
            if (f == NULL) {
                o->mUnk_18 = 0;
            } else {
                func_0208823c(1, o, &p->mUnk_08, 1, a, c);
                func_0208805c(o, f, a);
            }
        }
    }
}

void func_0208dd6c(Unk0208e490 *a, s32 b) {
    func_02087f84(a->mUnk_90[0], 0);
    func_02087f84(a->mUnk_90[1], 0);
    func_02087f84(a->mUnk_90[2], 0);
    a->mUnk_9c[0] = 0xab8;
    a->mUnk_9c[1] = 0xab8;
    a->mUnk_9c[2] = 0xab8;
    if (b == 0) {
        return;
    }
    func_0208b7bc(0x22, &a->mUnk_74);
    func_0208b7bc(1, &a->mUnk_74);
    func_0208b7bc(2, &a->mUnk_74);
}

void func_0208dd10(Unk0208e490 *a) {
    if (a->mUnk_a8 == 0x26) {
        func_0208b7bc(3, &a->mUnk_74);
        return;
    }
    if (a->mUnk_a8 >= 0x37) {
        a->mUnk_88 = 1;
        return;
    }
    func_02087de0(a->mUnk_90[0]);
    func_02087de0(a->mUnk_90[1]);
    func_02087de0(a->mUnk_90[2]);
}

void func_0208dcbc(Unk0208e490 *a) {
    u32 x;

    x = (u32) (func_02087d0c(a->mUnk_90[0]) << 4) >> 16;
    func_02087f84(a->mUnk_90[0], 0);
    a->mUnk_ac = x;
    if (a->mUnk_90[1] != NULL) {
        func_02087f84(a->mUnk_90[1], 0);
    }
}

void func_0208dc50(Unk0208e490 *a) {
    a->mUnk_9c[0] = 0x3d9a;
    a->mUnk_9c[1] = 0x3d9a;
    a->mUnk_9c[2] = 0x3d9a;
    func_02087f84(a->mUnk_90[0], 0);
    a->mUnk_ac = 0x20;
    if (a->mUnk_90[1] != NULL) {
        func_02087f84(a->mUnk_90[1], 0);
    }
    func_0208b7bc(0x424, &a->mUnk_74);
    func_0208b7bc(0x422, &a->mUnk_74);
}

void func_0208dc08(Unk0208e490 *a) {
    if (a->mUnk_a8 >= a->mUnk_ac) {
        a->mUnk_88 = 1;
        return;
    }
    func_02087de0(a->mUnk_90[0]);
    if (a->mUnk_90[1] != NULL) {
        func_02087de0(a->mUnk_90[1]);
    }
}

void func_0208db94(Unk0208e490 *a, s32 b) {
    func_02087f84(a->mUnk_90[0], 0);
    a->mUnk_9c[0] = 0x5800;
    a->mUnk_9c[1] = 0x5800;
    a->mUnk_9c[2] = 0x5800;
    a->mUnk_ac = 0x27;
    func_02087f84(a->mUnk_90[1], 0);
    if (b == 0) {
        return;
    }
    func_0208b7bc(0x40, &a->mUnk_74);
    func_0208b7bc(0x41, &a->mUnk_74);
}

void func_0208db58(Unk0208e490 *a) {
    if (a->mUnk_a8 >= a->mUnk_ac) {
        a->mUnk_88 = 1;
        return;
    }
    func_02087de0(a->mUnk_90[0]);
    func_02087de0(a->mUnk_90[1]);
}

void func_0208dad4(Unk0208e490 *a, s32 b) {
    func_02087f84(a->mUnk_90[0], 0);
    func_02087f84(a->mUnk_90[1], 0);
    func_02087f84(a->mUnk_90[2], 0);
    a->mUnk_9c[0] = 0x1000;
    a->mUnk_9c[1] = 0x1000;
    a->mUnk_9c[2] = 0x1000;
    if (b == 0) {
        return;
    }
    func_0208b7bc(8, &a->mUnk_74);
    func_0208b7bc(9, &a->mUnk_74);
    func_0208b7bc(0xa, &a->mUnk_74);
}

void func_0208da94(Unk0208e490 *a) {
    if (a->mUnk_a8 >= 0x37) {
        a->mUnk_88 = 1;
        return;
    }
    func_02087de0(a->mUnk_90[0]);
    func_02087de0(a->mUnk_90[1]);
    func_02087de0(a->mUnk_90[2]);
}

void func_0208d978(const Vec3 *a, s32 b) {
    Unk0208e490 *p;
    u16 i;

    if (data_0216618c[2].mUnk_00 == 0) {
        return;
    }
    i = 0;
    if (b != 0) {
        p = ListGetNth((LinkedList *) ((u8 *) data_0217b080->mUnk_0c + 0x18), 0);
        if (p != NULL) {
            ListRemove((LinkedList *) ((u8 *) data_0217b080->mUnk_0c + 0x18), p);
            p->mUnk_88 = 0;
            p->mUnk_74 = *a;
            p->mUnk_a8 = 0;
            p->mUnk_ac = 0;
            p->mUnk_b0 = data_0217b080->mUnk_5c;
            p->mUnk_b4 = 1;
            p->mUnk_80(p, 0);
            ListAppend(&data_0217b080->mUnk_00, p);
            data_0217b080->mUnk_5c++;
            if (data_0217b080->mUnk_5c > 0xd) {
                data_0217b080->mUnk_5c = 10;
            }
        }
    }
    do {
        if (data_0217b084[i] >= 0) {
            func_0208b7bc(data_0217b084[i], a);
        }
        i++;
    } while (i < 2);
}

#include "Main/Unknown/code_0208eb10.h"

#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020172d0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "code_0201750c.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0208fd8c.h"
#include "Main/Unknown/code_0208ffd8.h"
#include "Main/Unknown/code_0208ffe4.h"
#include "Main/Unknown/code_02090088.h"
#include "Main/Unknown/code_02090194.h"

void func_02090194(Unk02090194 *p0) {
    p0->mUnk_10 = (u32) 0x1u;
}

void func_02090088(Unk0208fd8c *a, Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207c078(a) != 0) {
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (s16) (u16) (r->mUnk_00 >> 52);
        if (v < 0xb33) {
            func_0207c548(a, b);
        } else {
            func_0207c47c(a, b);
        }
    } else {
        if (b->mUnk_b0 == NULL) {
            return;
        }
        if (b->mUnk_b8 >= 0x15f90) {
            return;
        }
        if (b->mUnk_b4 != 0 && b->mUnk_bc > 0xb33) {
            func_0207c548(a, b);
        } else {
            func_0207c47c(a, b);
        }
    }
}

void func_0208ffe4(Unk0208fd8c *a, Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207c078(a) == 0) {
        return;
    }
    r = func_0208537c();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (s16) (u16) (r->mUnk_00 >> 52);
    if (v < 0xb33) {
        func_0207c548(a, b);
    } else {
        func_0207c47c(a, b);
    }
}

void func_0208ffd8(Unk0208ffd8 *p0) {
    p0->mUnk_10 = (u32) 0x1u;
}

void func_0208fefc(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207c078(a) != 0) {
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (s16) (u16) (r->mUnk_00 >> 52);
        if (v > 0xccd) {
            func_0207c47c(a, b);
        } else {
            func_0207c548(a, b);
        }
    } else {
        if (b->mUnk_b0 == NULL) {
            return;
        }
        if (b->mUnk_b8 >= 0x15f90) {
            return;
        }
        func_0207c47c(a, b);
    }
}

void func_0208fe58(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207c078(a) == 0) {
        return;
    }
    r = func_0208537c();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (s16) (u16) (r->mUnk_00 >> 52);
    if (v > 0xccd) {
        func_0207c47c(a, b);
    } else {
        func_0207c548(a, b);
    }
}

void func_0208fe1c(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207c078(a) == 0) {
        return;
    }
    func_0207c614(a, b);
}

void func_0208fdcc(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207c078(a) == 0) {
        return;
    }
    if (b->mUnk_70 >= 0xa000) {
        return;
    }
    func_0207c6d0(a, b);
}

void func_0208fd8c(Unk0208fd8c *a, struct Unk020888b4 *b) {
    enum { K0 } k = (data_027e00c8)[b->mIndex].mUnk_058.mUnk_000;
    Unk0208fd8c_08 *t = &data_0217b0a4[k];

    a->mUnk_08 = t;
    func_0207bfd4(a, t);
}

u32 func_0208fd88(u32 p0) {
    return p0;
}

void func_0208fd24(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (data_027e00c8[b->mIndex].mUnk_058.mUnk_008 == 4) {
        data_0217b0a0(a, b);
    } else {
        data_0217b098(a, b);
    }
}

void func_0208fcac(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 != 0 && b->mUnk_bc > 0xb33) {
        func_0207c548(a, b);
    } else {
        func_0207c47c(a, b);
    }
}

void func_0208fba0(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207bfac(a) != 0) {
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (s16) (u16) (r->mUnk_00 >> 52);
        if (v < 0xb33) {
            func_0207c548(a, b);
        } else {
            func_0207c47c(a, b);
        }
    } else {
        if (b->mUnk_b0 == NULL) {
            return;
        }
        if (b->mUnk_b8 >= 0x15f90) {
            return;
        }
        if (b->mUnk_b4 != 0 && b->mUnk_bc > 0xb33) {
            func_0207c548(a, b);
        } else {
            func_0207c47c(a, b);
        }
    }
}

void func_0208fafc(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207bfac(a) == 0) {
        return;
    }
    r = func_0208537c();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (s16) (u16) (r->mUnk_00 >> 52);
    if (v < 0xb33) {
        func_0207c548(a, b);
    } else {
        func_0207c47c(a, b);
    }
}

void func_0208fa50(Unk0208fd8c *a, struct Unk020888b4 *b) {
    a->mUnk_10 = 1;
    if (func_0207bfac(a) == 0) {
        return;
    }
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 != 0 && b->mUnk_bc > 0xb33) {
        func_0207c548(a, b);
    } else {
        func_0207c47c(a, b);
    }
}

void func_0208f9ac(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207bfac(a) == 0) {
        return;
    }
    r = func_0208537c();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (s16) (u16) (r->mUnk_00 >> 52);
    if (v < 0xb33) {
        func_0207c548(a, b);
    } else {
        func_0207c47c(a, b);
    }
}

void func_0208f948(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (data_027e00c8[b->mIndex].mUnk_058.mUnk_008 == 4) {
        data_0217b090(a, b);
    } else {
        data_0217b094(a, b);
    }
}

void func_0208f8ac(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207bfac(a) == 0) {
        return;
    }
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 == 0) {
        return;
    }
    if (b->mUnk_bc <= 0x666) {
        return;
    }
    func_0207c614(a, b);
}

void func_0208f810(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207bfac(a) == 0) {
        return;
    }
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 == 0) {
        return;
    }
    if (b->mUnk_bc <= 0x666) {
        return;
    }
    func_0207c614(a, b);
}

void func_0208f7d4(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207bfac(a) == 0) {
        return;
    }
    func_0207c614(a, b);
}

void func_0208f754(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207bfac(a) == 0) {
        return;
    }
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 == 0) {
        return;
    }
    func_0207c614(a, b);
}

void func_0208f6d4(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207bfac(a) == 0) {
        return;
    }
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 == 0) {
        return;
    }
    func_0207c614(a, b);
}

void func_0208f670(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (data_027e00c8[b->mIndex].mUnk_058.mUnk_008 == 3) {
        data_0217b0ac(a, b);
    } else {
        data_0217b0a8(a, b);
    }
}

void func_0208f5c4(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207bfac(a) == 0) {
        return;
    }
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 != 0) {
        if (b->mUnk_bc <= 0xb33) {
            return;
        }
        func_0207c548(a, b);
    } else {
        func_0207c47c(a, b);
    }
}

void func_0208f4e8(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207bfac(a) != 0) {
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (s16) (u16) (r->mUnk_00 >> 52);
        if (v > 0xb33) {
            func_0207c47c(a, b);
        } else {
            func_0207c548(a, b);
        }
    } else {
        if (b->mUnk_b0 == NULL) {
            return;
        }
        if (b->mUnk_b8 >= 0x15f90) {
            return;
        }
        func_0207c47c(a, b);
    }
}

void func_0208f434(Unk0208fd8c *a, struct Unk020888b4 *b) {
    a->mUnk_10 = 1;
    if (func_0207bfac(a) == 0) {
        return;
    }
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 != 0) {
        if (b->mUnk_bc <= 0xb33) {
            return;
        }
        func_0207c47c(a, b);
    } else {
        func_0207c47c(a, b);
    }
}

void func_0208f3d0(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207bfac(a) == 0) {
        if (b->mUnk_b0 == NULL) {
            return;
        }
        if (b->mUnk_b8 >= 0x15f90) {
            return;
        }
    }
    func_0207c47c(a, b);
}

void func_0208f0f8(void *a) {
    void *s;
    Unk0208ec64 *e;
    Unk0208ec64_08 *f;
    u16 i;
    u16 n;
    u16 m;
    Unk020850c4 *q;
    s32 t;

    s = FindMainRaceOrMainEffectFile(data_021759c0->mUnk_00c == 5 ? data_02166514 : data_02166530);
    data_021663f0 = 0x4d;
    data_021663e0 = 8;
    data_021663dc = 3;
    data_021663e4 = 0xc;
    data_021663ec = (s32(*)()) func_0208ee40;
    data_021663d8 = 0xe;
    data_021663e8 = 1;
    n = 1;
    if (data_021759c0->mMode == 5) {
        n += 3;
    } else if (data_021759c0->mUnk_00c == 5) {
        data_021663f0 = 0;
        data_021663e0 = 0xe;
        data_021663dc = 2;
        data_021663e4 = 0x1e;
        data_021663ec = (s32(*)()) func_0208ecd8;
        data_021663d8 = 4;
        data_021663e8 = 0;
        n = 6;
    }
    m = data_021663e4 * n;
    if (data_021759c0->mMode == 4) {
        a = data_0217aa10->mUnk_a4;
    }
    data_0217b08c = HeapAlloc(a, 0x38);
    e = HeapAlloc(a, n * 0x30);
    f = HeapAlloc(a, m * 0x1c);
    ListInit(&data_0217b08c->mUnk_00[0], 0);
    ListInit(&data_0217b08c->mUnk_00[1], 0);
    ListInit(&data_0217b08c->mUnk_00[2], 0);
    for (i = 0; i < n; i++) {
        ListInit(&e[i].mUnk_08, 0);
        ListAppend(&data_0217b08c->mUnk_00[1], &e[i]);
    }
    for (i = 0; i < m; i++) {
        ListAppend(&data_0217b08c->mUnk_00[2], &f[i]);
    }
    func_0208526c(&data_0217b08c->mUnk_24, s, s);
    q = data_0217b08c->mUnk_24.mUnk_0c;
    t = (q->mUnk_08 & 0xffff) << 3;
    data_021663f4.mUnk_00 = data_021663f4.mUnk_00 & 0xffff0000;
    data_021663f4.mUnk_00 = data_021663f4.mUnk_00 | (((u32) t >> 3) & 0xffff);
    data_021663f4.mUnk_18 = (q->mUnk_2c & 0xffff) << 3;
    data_021663f4.mUnk_1c = 0x10000;
    data_021663f4.mUnk_20 = 0x8000;
    data_0217b08c->mUnk_34 = data_021759c0->mCourseId == 0x1d ? 0 : 0x8000;
}

void func_0208f0a0(void) {
    void *p;
    p = ListGetNext(&data_0217b08c->mUnk_00[0], NULL);
    while (p != NULL) {
        func_0208e99c(p);
        p = ListGetNext(&data_0217b08c->mUnk_00[0], p);
    }
}

void func_0208ee7c(const Unk02012f58 *a) {
    Unk0208ec64 *p;
    Unk0208ec64_08 *r;
    Unk0208ec64_08 *q;
    s32 v;
    u8 f;
    BOOL g;

    f = data_021663d8;
    g = FALSE;
    p = ListGetNext(&data_0217b08c->mUnk_00[0], NULL);
    if (p == NULL) {
        return;
    }
    do {
        if (g == FALSE) {
            *(u16 *) 0x4000060 = (*(u16 *) 0x4000060 & ~0x3000) | 8;
            *(u32 *) 0x40004c4 = 0x7c004210;
            *(u32 *) 0x40004c0 = 0x42100000;
            *(u32 *) 0x4000440 = 3;
            *(u32 *) 0x4000454 = 0;
            *(u32 *) 0x4000440 = 2;
            *(u32 *) 0x40004a8 = data_021663f4.mUnk_00;
            *(u32 *) 0x40004ac = data_021663f4.mUnk_18 >> (4 - ((data_021663f4.mUnk_00 >> 26 & 7) == 2));
            g = TRUE;
        }
        *(u32 *) 0x4000480 = 0x7fff;
        q = ListGetNext(&p->mUnk_08, NULL);
        if (q != NULL && data_021663e8 != 0) {
            r = ListGetNext(&p->mUnk_08, NULL);
            if (r != NULL) {
                do {
                    v = 0x1f - q->mUnk_0c * data_021663dc;
                    *(u32 *) 0x40004a4 = (u32) f << 24 | (data_0217b08c->mUnk_34 | 0xc0) | v << 16;
                    func_0208e82c(a, q, r, &data_021663f4);
                    q = r;
                    r = ListGetNext(&p->mUnk_08, r);
                } while (r != NULL);
            }
        }
        f = f + 1;
        p = ListGetNext(&data_0217b08c->mUnk_00[0], p);
    } while (p != NULL);
}

void func_0208ee40(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    value3 = (u32) * (const u32 *) ((value1) + (20));
    value2 = (u32) * (const u32 *) ((value1) + (28));
    value1 = 0u;
    *(u32 *) ((value0) + (8)) = value2;
    *(u16 *) ((value0) + (12)) = (u16) value1;
    value1 = (u32) * (const u32 *) ((value3) + (0));
    value1 = ((u32) ((s32) value1 >> 4));
    *(u32 *) ((value0) + (16)) = value1;
    value1 = (u32) * (const u32 *) ((value3) + (4));
    value1 = ((u32) ((s32) value1 >> 4));
    *(u32 *) ((value0) + (20)) = value1;
    value1 = (u32) * (const u32 *) ((value3) + (8));
    value1 = ((u32) ((s32) value1 >> 4));
    *(u32 *) ((value0) + (24)) = value1;
}

void func_0208ecd8(Unk0208ec64_08 *a, Unk0208ec64 *b) {
    Kart *o;
    Vec3 v;
    Vec3 x;
    Vec3 y;
    Vec3 z;
    Vec3 *p;
    s32 k;

    o = GetKart(b->mUnk_20);
    v = o->mUnk_80;
    p = &o->mUnk_120;
    k = b->mUnk_24;
    x.x = (s32) (((s64) p->x * k) >> 12);
    x.y = (s32) (((s64) p->y * k) >> 12);
    x.z = (s32) (((s64) p->z * k) >> 12);
    p = &o->mUnk_12c;
    k = b->mUnk_28;
    y.x = (s32) (((s64) p->x * k) >> 12);
    y.y = (s32) (((s64) p->y * k) >> 12);
    y.z = (s32) (((s64) p->z * k) >> 12);
    p = &o->mUnk_138;
    k = b->mUnk_2c;
    z.x = (s32) (((s64) p->x * k) >> 12);
    z.y = (s32) (((s64) p->y * k) >> 12);
    z.z = (s32) (((s64) p->z * k) >> 12);
    Vec3Add(&v, &x, &v);
    Vec3Add(&v, &y, &v);
    Vec3Add(&v, &z, &v);
    a->mUnk_08 = b->mUnk_1c;
    a->mUnk_0c = 0;
    a->mUnk_10.x = v.x >> 4;
    a->mUnk_10.y = v.y >> 4;
    a->mUnk_10.z = v.z >> 4;
}

s32 func_0208ec64(u32 a) {
    Unk0208ec64 *p;
    p = ListGetNth(&data_0217b08c->mUnk_00[1], 0);
    if (p != NULL) {
        p->mUnk_14 = a;
        p->mUnk_18 = 0;
        p->mUnk_1c = 0x400;
        ListRemove(&data_0217b08c->mUnk_00[1], p);
        ListAppend(&data_0217b08c->mUnk_00[0], p);
    }
    return (s32) p;
}

Unk0208ec64 *func_0208eb1c(s32 a) {
    Unk0208ec64 *p;
    Kart *o;
    Unk0206bcb0_590 *t;
    Vec3 v;
    s32 h;

    if (data_021759c0->mUnk_00c == 5) {
        p = ListGetNth(&data_0217b08c->mUnk_00[1], 0);
        if (p != NULL) {
            o = GetKart(a);
            t = o->mKartModelsEntry;
            v = ((Vec3 *) &t->mUnk_020->mUnk_44)[t->mUnk_000];
            p->mUnk_14 = (u32) &o->mUnk_80;
            p->mUnk_18 = 0;
            p->mUnk_1c = 0x400;
            p->mUnk_20 = a;
            h = (v.y + (data_02166418[t->mUnk_000][0] >> 4) - data_02166480[t->mUnk_004]) / 2;
            p->mUnk_1c = h;
            p->mUnk_24 = v.x << 4;
            p->mUnk_28 = (data_02166480[t->mUnk_004] + h) << 4;
            p->mUnk_2c = data_0216641c[t->mUnk_000][0] + (v.z << 4);
            ListRemove(&data_0217b08c->mUnk_00[1], p);
            ListAppend(&data_0217b08c->mUnk_00[0], p);
        }
        return p;
    }
    return NULL;
}

void func_0208eb10(u32 p0) {
    *(u32 *) ((u8 *) p0 + 24) = (u32) 0x1u;
}

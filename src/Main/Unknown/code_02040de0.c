#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02012b30.h"
#include "code_02147288.h"
#include "code_02147cd8.h"

// non-matching: the original saves two more registers (r10, r11) and has an 8-byte larger frame; it computes the
// products of the second and third components before the first sum and the loop index is kept as a pointer step, here
// the order of the multiplies and the loop registers differ
void func_02041dc8(Vec3 *a, Vec3 *b, s32 c, s32 d, s32 e) {
    Unk02175620_34 *q = NULL;
    s32 i;
    u16 x;
    u16 y;
    u16 z;
    Unk02012f58 m1;
    Unk02012f58 m2;
    Unk02012f58 m3;
    Unk02012f58 r;
    s64 h;
    s64 k;
    s64 l;
    s64 n;

    if (gCourseMap->mUnk_018->mUnk_04 != 0) {
        d = 0x1000 - d;
    }
    if (gCourseMap->mUnk_020 > 1) {
        for (i = 0; i < gCourseMap->mUnk_020; i++) {
            if (c == (s16) ((Unk02175620_34 *) gCourseMap->mUnk_01c)[i].mUnk_1a) {
                q = &((Unk02175620_34 *) gCourseMap->mUnk_01c)[i];
                break;
            }
        }
    } else {
        q = (Unk02175620_34 *) gCourseMap->mUnk_01c;
    }
    x = (u16) ((q->mUnk_0c.x >> 12) * 0xb6);
    y = (u16) ((q->mUnk_0c.y >> 12) * 0xb6);
    z = (u16) ((q->mUnk_0c.z >> 12) * 0xb6);
    func_02147230((s32 *) &m1, data_0215d4b4[(x >> 4) * 2], data_0215d4b4[(x >> 4) * 2 + 1]);
    func_02147250(&m2, data_0215d4b4[(y >> 4) * 2], data_0215d4b4[(y >> 4) * 2 + 1]);
    func_0214726c((s32 *) &m3, data_0215d4b4[(z >> 4) * 2], data_0215d4b4[(z >> 4) * 2 + 1]);
    func_0214733c(&m1, &m3, &r);
    func_0214733c(&m2, &r, &r);
    h = (s64) -r.mUnk_00[0].z * d;
    k = (s64) -r.mUnk_00[0].y * d;
    l = (s64) -r.mUnk_00[2].y * e;
    n = (s64) -r.mUnk_00[2].z * e;
    a->x = q->mUnk_00.x + (s32) (((s64) -r.mUnk_00[0].x * d + 0x800) >> 12) +
           (s32) (((s64) -r.mUnk_00[2].x * e + 0x800) >> 12);
    a->y = q->mUnk_00.y + (s32) ((k + 0x800) >> 12) + (s32) ((l + 0x800) >> 12);
    a->z = q->mUnk_00.z + (s32) ((h + 0x800) >> 12) + (s32) ((n + 0x800) >> 12);
    b->x = q->mUnk_0c.x;
    b->y = q->mUnk_0c.y;
    b->z = q->mUnk_0c.z;
}

// non-matching: register allocation and branch layout of the switch differ (59 words), same operations
void func_02041bb0(Vec3 *a, Vec3 *b, s32 c) {
    u16 i = (u16) (data_021759c0->mKartCount - 1);
    u16 j = (u16) (func_0205d27c(c) - 1);
    s32 k;
    s32 l;
    s32 n;
    s32 t;

    if (data_021759c0->mUnk_00c == 6) {
        func_02041dc8(a, b, 0, 0, 0);
        return;
    }
    switch (data_021759c0->mUnk_08) {
        case 2:
            func_02041dc8(a, b, (u16) ((j + data_0217561c->mUnk_4f8) % 8), 0, 0);
            break;
        case 1:
            func_02041dc8(a, b, 0, 0x800, 0);
            break;
        case 4:
            if (data_021759c0->mKartCount <= 1) {
                func_02041dc8(a, b, 0, 0x800, 0);
            } else {
                func_02041dc8(a, b, c, (1 - c * 2) * 0x14000 + 0x800, 0);
            }
            break;
        default:
            k = data_0215406c[i * 2];
            n = j;
            if (j >= k) {
                l = data_0215406d[i * 2];
                n = j - k;
            } else {
                l = k;
            }
            if ((l & 1) == 1) {
                n = (n - l / 2) * 2;
            } else {
                n = n * 2 + 1 - l;
            }
            if (j >= k) {
                if (k == data_0215406d[i * 2]) {
                    n = n + 1;
                }
            }
            t = 0;
            if (j >= k) {
                t = 1;
            }
            func_02041dc8(a, b, 0, n * 0x11000, j * 0x19000 + t * 0x14000);
            break;
    }
}

BOOL func_02041a70(Vec3 *a, Unk02175620_74 *b) {
    Vec3 v;
    s32 d;
    s32 t;

    func_021484d0(a, (Vec3 *) b, &v);
    d = func_0214848c(&v, &b->mUnk_24);
    if (d > (s32) (((s64) b->mUnk_0c.y * 0x64000 + 0x800) >> 12) || d < 0) {
        return FALSE;
    }
    d = func_0214848c(&v, &b->mUnk_18);
    t = (s32) (((s64) b->mUnk_0c.x * 0x32000 + 0x800) >> 12);
    if (d < -t || d > t) {
        return FALSE;
    }
    d = func_0214848c(&v, &b->mUnk_30);
    t = (s32) (((s64) b->mUnk_0c.z * 0x32000 + 0x800) >> 12);
    if (d < -t || d > t) {
        return FALSE;
    }
    return TRUE;
}

// non-matching: the original keeps the result in r3 and reuses the zero constant of the result for the products, here
// the result lives in another register
s32 func_02041944(Vec3 *a, Unk02175620_74 *b) {
    Vec3 v;
    s32 r = 0;
    s32 x;
    s32 y;
    s32 z;

    switch (b->mUnk_42) {
        case 0:
            r = func_02041a70(a, b);
            break;
        case 1:
            func_021484d0(a, (Vec3 *) b, &v);
            if (func_0214848c(&v, &b->mUnk_24) <= (s32) (((s64) b->mUnk_0c.y * 0x32000 + 0x800) >> 12)) {
                x = func_0214848c(&v, &b->mUnk_18) >> 4;
                y = func_0214848c(&v, &b->mUnk_30) >> 4;
                z = (s32) (((s64) b->mUnk_0c.x * 0x32000 + 0x800) >> 12) >> 4;
                if ((s32) (((s64) z * z + 0x800) >> 12) >=
                    (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                    r = 1;
                }
            }
            break;
    }
    return r;
}

s32 func_0204176c(Vec3 *a, s32 *b) {
    u16 i;
    Unk02175620_74 *p;
    Vec3 v;
    BOOL r = FALSE;
    s32 x;
    s32 y;
    s32 z;
    s32 t;

    for (i = 0; i < gCourseMap->mUnk_78; i++) {
        p = func_020423fc(i);
        if (p->mUnk_44 == 2) {
            t = 0;
            switch (p->mUnk_42) {
                case 0:
                    t = func_02041a70(a, p);
                    break;
                case 1:
                    func_021484d0(a, (Vec3 *) p, &v);
                    if (func_0214848c(&v, &p->mUnk_24) <= (s32) (((s64) p->mUnk_0c.y * 0x32000 + 0x800) >> 12)) {
                        x = func_0214848c(&v, &p->mUnk_18) >> 4;
                        y = func_0214848c(&v, &p->mUnk_30) >> 4;
                        z = (s32) (((s64) p->mUnk_0c.x * 0x32000 + 0x800) >> 12) >> 4;
                        if ((s32) (((s64) z * z + 0x800) >> 12) >=
                            (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                            t = 1;
                        }
                    }
                    break;
            }
            if (t != 0) {
                if ((s16) p->mUnk_3c == 0) {
                    *b = 1;
                } else {
                    *b = 0;
                }
                r = TRUE;
                break;
            }
        }
    }
    return r;
}

void *func_02041588(Vec3 *a) {
    u16 i;
    Unk02175620_74 *p;
    Vec3 v;
    s32 x;
    s32 y;
    s32 z;
    void *r = NULL;
    s32 t;

    if (gCourseMap->mUnk_102 == 0) {
        return r;
    }
    for (i = 0; i < gCourseMap->mUnk_78; i++) {
        p = func_020423fc(i);
        if (p->mUnk_44 == 4) {
            t = 0;
            switch (p->mUnk_42) {
                case 0:
                    t = func_02041a70(a, p);
                    break;
                case 1:
                    func_021484d0(a, (Vec3 *) p, &v);
                    if (func_0214848c(&v, &p->mUnk_24) <= (s32) (((s64) p->mUnk_0c.y * 0x32000 + 0x800) >> 12)) {
                        x = func_0214848c(&v, &p->mUnk_18) >> 4;
                        y = func_0214848c(&v, &p->mUnk_30) >> 4;
                        z = (s32) (((s64) p->mUnk_0c.x * 0x32000 + 0x800) >> 12) >> 4;
                        if ((s32) (((s64) z * z + 0x800) >> 12) >=
                            (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                            t = 1;
                        }
                    }
                    break;
            }
            if (t != 0) {
                r = (u8 *) gCourseMap->mUnk_a0 + p->mUnk_40 * 0x28;
                break;
            }
        }
    }
    return r;
}

Unk02175620_bc *func_020413a4(Vec3 *a) {
    u16 i;
    Unk02175620_74 *p;
    Vec3 v;
    s32 x;
    s32 y;
    s32 z;
    Unk02175620_bc *r = NULL;
    s32 t;

    if (gCourseMap->mUnk_102 == 0) {
        return r;
    }
    for (i = 0; i < gCourseMap->mUnk_78; i++) {
        p = func_020423fc(i);
        if (p->mUnk_44 == 4) {
            t = 0;
            switch (p->mUnk_42) {
                case 0:
                    t = func_02041a70(a, p);
                    break;
                case 1:
                    func_021484d0(a, (Vec3 *) p, &v);
                    if (func_0214848c(&v, &p->mUnk_24) <= (s32) (((s64) p->mUnk_0c.y * 0x32000 + 0x800) >> 12)) {
                        x = func_0214848c(&v, &p->mUnk_18) >> 4;
                        y = func_0214848c(&v, &p->mUnk_30) >> 4;
                        z = (s32) (((s64) p->mUnk_0c.x * 0x32000 + 0x800) >> 12) >> 4;
                        if ((s32) (((s64) z * z + 0x800) >> 12) >=
                            (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                            t = 1;
                        }
                    }
                    break;
            }
            if (t != 0) {
                r = &gCourseMap->mUnk_b8[p->mUnk_40];
                break;
            }
        }
    }
    return r;
}

// non-matching: the original reloads the constants 0 and 1 from stack words, here they are constants in the arms (0xc
// bytes shorter)
s32 func_020411e4(Vec3 *a) {
    u16 i;
    Unk02175620_74 *p;
    Vec3 v;
    s32 x;
    s32 y;
    s32 z;
    s32 r = -1;
    s32 t;

    for (i = 0; i < gCourseMap->mUnk_78; i++) {
        p = func_020423fc(i);
        if (p->mUnk_44 == 1) {
            t = 0;
            switch (p->mUnk_42) {
                case 0:
                    t = func_02041a70(a, p);
                    break;
                case 1:
                    func_021484d0(a, (Vec3 *) p, &v);
                    if (func_0214848c(&v, &p->mUnk_24) <= (s32) (((s64) p->mUnk_0c.y * 0x32000 + 0x800) >> 12)) {
                        x = func_0214848c(&v, &p->mUnk_18) >> 4;
                        y = func_0214848c(&v, &p->mUnk_30) >> 4;
                        z = (s32) (((s64) p->mUnk_0c.x * 0x32000 + 0x800) >> 12) >> 4;
                        if ((s32) (((s64) z * z + 0x800) >> 12) >=
                            (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                            t = 1;
                        }
                    }
                    break;
            }
            if (t != 0) {
                r = p->mUnk_43;
                break;
            }
        }
    }
    return r;
}

u16 func_02041170(u32 a) {
    u16 r;
    Unk02175620 *p;

    if (data_021759c0->mUnk_08 == 2) {
        p = gCourseMap;
        r = p->mUnk_100;
        p->mUnk_100 = (r + 1) % p->mUnk_028;
    } else {
        r = gCourseMap->mUnk_44[a].mUnk_22;
    }
    return r;
}

void *func_020410a4(u32 a, Vec3 *b, Vec3 *c) {
    Unk02175620_24 *e;
    s32 i;

    if (gCourseMap->mUnk_44 == NULL && gCourseMap->mUnk_024 == NULL) {
        e = NULL;
    } else {
        e = &gCourseMap->mUnk_024[gCourseMap->mUnk_f8[a]];
    }
    if (e == NULL) {
        b->x = 0;
        b->y = 0;
        b->z = 0;
        c->x = 0x1000;
        c->y = 0;
        c->z = 0;
        i = -1;
    } else {
        b->x = e->mUnk_00.x;
        b->y = e->mUnk_00.y;
        b->z = e->mUnk_00.z;
        c->x = e->mUnk_0c.x;
        c->y = e->mUnk_0c.y;
        c->z = e->mUnk_0c.z;
        i = e->mUnk_18;
    }
    if (i == -1) {
        return NULL;
    }
    return (u8 *) gCourseMap->mUnk_a0 + i * 0x28;
}

Unk02175620_bc *func_02040fd8(u32 a, Vec3 *b, Vec3 *c) {
    Unk02175620_24 *e;
    s32 i;

    if (gCourseMap->mUnk_44 == NULL && gCourseMap->mUnk_024 == NULL) {
        e = NULL;
    } else {
        e = &gCourseMap->mUnk_024[gCourseMap->mUnk_f8[a]];
    }
    if (e == NULL) {
        b->x = 0;
        b->y = 0;
        b->z = 0;
        c->x = 0x1000;
        c->y = 0;
        c->z = 0;
        i = -1;
    } else {
        b->x = e->mUnk_00.x;
        b->y = e->mUnk_00.y;
        b->z = e->mUnk_00.z;
        c->x = e->mUnk_0c.x;
        c->y = e->mUnk_0c.y;
        c->z = e->mUnk_0c.z;
        i = e->mUnk_18;
    }
    if (i == -1) {
        return NULL;
    }
    return &gCourseMap->mUnk_b8[i];
}

struct Unk020f371c *func_02040f78(u32 a) {
    Unk02175620_24 *e;

    if (gCourseMap->mUnk_44 == NULL && gCourseMap->mUnk_024 == NULL) {
        e = NULL;
    } else {
        e = &gCourseMap->mUnk_024[gCourseMap->mUnk_f8[a]];
    }
    if (e == NULL) {
        return NULL;
    }
    return &gCourseMap->mUnk_ac[e->mUnk_1a];
}

s32 func_02040de0(s32 a, u32 b) {
    Unk02175620_d8 *n;
    s32 t;
    Unk02175620_74 *p;
    Vec3 v;
    Vec3 w;
    s32 x;
    s32 y;
    s32 z;
    BOOL f = FALSE;

    n = gCourseMap->mUnk_d8[b];
    func_0207a948(&v, a);
    for (; f == FALSE && n != NULL; n = n->mUnk_04) {
        p = n->mUnk_00;
        t = 0;
        switch (p->mUnk_42) {
            case 0:
                t = func_02041a70(&v, p);
                break;
            case 1:
                func_021484d0(&v, (Vec3 *) p, &w);
                if (func_0214848c(&w, &p->mUnk_24) <= (s32) (((s64) p->mUnk_0c.y * 0x32000 + 0x800) >> 12)) {
                    x = func_0214848c(&w, &p->mUnk_18) >> 4;
                    y = func_0214848c(&w, &p->mUnk_30) >> 4;
                    z = (s32) (((s64) p->mUnk_0c.x * 0x32000 + 0x800) >> 12) >> 4;
                    if ((s32) (((s64) z * z + 0x800) >> 12) >=
                        (s32) (((s64) x * x + 0x800) >> 12) + (s32) (((s64) y * y + 0x800) >> 12)) {
                        t = 1;
                    }
                }
                break;
        }
        if (t != 0) {
            f = TRUE;
        }
    }
    return f;
}

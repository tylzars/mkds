#include "Main/Unknown/code_020429b8.h"

#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f36d8.h"

#pragma thumb on

u32 func_02042fc4(u32 p0) {
    return ((u32) gCourseMap->mUnk_94) + (((p0) << 3));
}

#pragma thumb off

#pragma thumb on
void func_02042ec0(Unk020f371c *a, Unk02175620_4c *b, u16 c) {
    Unk02175620_54 *p;
    Unk020f371c *n;
    s32 i;
    s32 k;

    if (gCourseMap->mUnk_10c < 0x21) {
        p = (Unk02175620_54 *) ((Unk02175620_54_10 *) gCourseMap->mUnk_54 + c);
    } else {
        p = gCourseMap->mUnk_54 + c;
    }
    n = gCourseMap->mUnk_ac + c;
    for (k = 0; k < 3; k++) {
        if (a != NULL && n->mUnk_0c[k] == a) {
            return;
        }
    }
    n->mUnk_18 = (Vec3 *) p;
    n->mUnk_1c = p->mUnk_0c;
    if (gCourseMap->mUnk_10c < 0x21) {
        n->mUnk_20 = 0;
    } else {
        n->mUnk_20 = p->mUnk_10;
    }
    for (k = 0; k < 3; k++) {
        if (a->mUnk_00[k] == NULL) {
            a->mUnk_00[k] = n;
            a->mUnk_24++;
            break;
        }
    }
    for (k = 0; k < 3; k++) {
        if (n->mUnk_0c[k] == NULL) {
            n->mUnk_0c[k] = a;
            n->mUnk_26++;
            break;
        }
    }
    if (c < b->mUnk_00 + b->mUnk_02 - 1) {
        func_02042ec0(n, b, c + 1);
        return;
    }
    for (k = 0; k < 3; k++) {
        i = b->mUnk_04[k];
        if (i != 0xff && i != 0) {
            func_02042ec0(n, &gCourseMap->mUnk_5c[i], gCourseMap->mUnk_5c[i].mUnk_00);
        }
    }
}

void func_02042e0c(void *a) {
    Unk02175620 *g;
    Unk02175620_4c *d;
    Unk020f371c **q;
    s32 i;
    Unk020f371c *e;
    s32 k;
    s32 n;
    s32 m;
    Unk02175620_4c *t;
    Unk02175620_4c *h;

    g = gCourseMap;
    d = g->mUnk_5c;
    q = &g->mUnk_ac;
    g->mUnk_ac = HeapAlloc(a, g->mUnk_58 * 0x28);
    q[1] = g->mUnk_ac + d->mUnk_00;
    for (i = 0; i < gCourseMap->mUnk_58; i++) {
        e = q[0] + i;
        for (k = 0; k < 3; k++) {
            e->mUnk_0c[k] = NULL;
            e->mUnk_00[k] = NULL;
        }
        e->mUnk_24 = 0;
        e->mUnk_26 = 0;
        e->mUnk_18 = NULL;
        e->mUnk_20 = 0;
        e->mUnk_1c = 0;
    }
    t = gCourseMap->mUnk_5c;
    h = t + d->mUnk_07;
    m = t[d->mUnk_07].mUnk_00;
    n = m + h->mUnk_02 - 1;
    q[2] = q[0] + n;
    func_02042ec0(q[0] + n, d, d->mUnk_00);
}

void func_02042d34(Unk02175620_a0 *a, Unk02175620_4c *b, u16 c) {
    Unk02175620_a0 *n;
    s32 i;
    s32 k;
    Unk02175620_84 *p;

    p = gCourseMap->mUnk_64 + c;
    n = gCourseMap->mUnk_a0 + c;
    for (k = 0; k < 3; k++) {
        if (a != NULL && n->mUnk_0c[k] == a) {
            return;
        }
    }
    n->mUnk_18 = p;
    n->mUnk_1c = p->mUnk_0c;
    n->mUnk_20 = p->mUnk_10;
    if (a != NULL) {
        for (k = 0; k < 3; k++) {
            if (a->mUnk_00[k] == NULL) {
                a->mUnk_00[k] = n;
                a->mUnk_24++;
                break;
            }
        }
        for (k = 0; k < 3; k++) {
            if (n->mUnk_0c[k] == NULL) {
                n->mUnk_0c[k] = a;
                n->mUnk_26++;
                break;
            }
        }
    }
    if (c < b->mUnk_00 + b->mUnk_02 - 1) {
        func_02042d34(n, b, c + 1);
        return;
    }
    for (k = 0; k < 3; k++) {
        i = b->mUnk_04[k];
        if (i != 0xff) {
            func_02042d34(n, &gCourseMap->mUnk_6c[i], gCourseMap->mUnk_6c[i].mUnk_00);
        }
    }
}

void func_02042c3c(void *a) {
    Unk02175620 *g;
    Unk02175620_4c *d;
    Unk02175620_a0 **q;
    Unk02175620_4c *t;
    s32 i;
    Unk02175620_a0 *e;
    s32 k;
    s32 n;

    g = gCourseMap;
    d = g->mUnk_6c;
    q = &g->mUnk_a0;
    g->mUnk_a0 = HeapAlloc(a, g->mUnk_68 * 0x28);
    q[1] = g->mUnk_a0 + d->mUnk_00;
    for (i = 0; i < gCourseMap->mUnk_68; i++) {
        e = q[0] + i;
        for (k = 0; k < 3; k++) {
            e->mUnk_0c[k] = NULL;
            e->mUnk_00[k] = NULL;
        }
        e->mUnk_24 = 0;
        e->mUnk_26 = 0;
        e->mUnk_18 = NULL;
        e->mUnk_20 = NULL;
        e->mUnk_1c = 0;
    }
    t = gCourseMap->mUnk_6c + d->mUnk_07;
    n = t->mUnk_00 + t->mUnk_02 - 1;
    q[2] = q[0] + n;
    func_02042d34(q[0] + n, d, d->mUnk_00);
    for (i = 0; i < gCourseMap->mUnk_70; i++) {
        t = gCourseMap->mUnk_6c + (u16) i;
        if (q[0][t->mUnk_00].mUnk_24 == 0) {
            func_02042d34(NULL, t, t->mUnk_00);
        }
    }
}

void func_02042a10(void *a) {
    Unk02175620 *g;
    Unk02175620_8c *r;
    Unk02175620_8c *t;
    Unk02175620_bc **q;
    s32 i;
    Unk02175620_bc *e;
    Unk02175620_bc *d;
    s32 j;
    s32 k;
    u16 m;
    u16 n;
    u16 h;
    Unk02175620_84 *s;
    u16 b;
    u16 c;

    g = gCourseMap;
    r = g->mUnk_8c;
    q = &g->mUnk_b8;
    g->mUnk_b8 = HeapAlloc(a, g->mUnk_88 * 0x30);
    q[1] = g->mUnk_b8;
    q[2] = g->mUnk_b8 + gCourseMap->mUnk_88;
    for (i = 0; i < gCourseMap->mUnk_88; i++) {
        e = q[0] + i;
        for (k = 0; k < 8; k++) {
            e->mUnk_00[k] = NULL;
        }
        e->mUnk_2c = 0;
        e->mUnk_20 = NULL;
        e->mUnk_28 = NULL;
        e->mUnk_24 = 0;
    }
    for (j = 0; j < gCourseMap->mUnk_88; j++) {
        s = gCourseMap->mUnk_84 + (u16) j;
        d = q[0] + j;
        n = 0;
        for (m = 0; m < gCourseMap->mUnk_90; m++) {
            t = gCourseMap->mUnk_8c;
            r = t + m;
            if (j >= t[m].mUnk_00 && j < r->mUnk_00 + r->mUnk_02) {
                break;
            }
        }
        d->mUnk_2e = 0;
        h = r->mUnk_00 + r->mUnk_02 - 1;
        if (j == r->mUnk_00) {
            for (b = 0; b < 8; b++) {
                if (r->mUnk_0c[b] != 0xff) {
                    d->mUnk_2e |= 1 << n;
                    d->mUnk_00[n++] = q[0] + r->mUnk_0c[b];
                }
            }
            if (r->mUnk_02 > 1) {
                d->mUnk_00[n++] = d + 1;
            }
        }
        if (j == h) {
            for (c = 0; c < 8; c++) {
                if (r->mUnk_04[c] != 0xff) {
                    d->mUnk_2e |= 1 << n;
                    d->mUnk_00[n++] = q[0] + r->mUnk_04[c];
                }
            }
            if (r->mUnk_02 > 1) {
                d->mUnk_00[n++] = d - 1;
            }
        }
        if (j != r->mUnk_00 && j != h) {
            n = 0;
            d->mUnk_00[n++] = d + 1;
            d->mUnk_00[n++] = d - 1;
        }
        d->mUnk_20 = (Vec3 *) s;
        d->mUnk_24 = s->mUnk_0c;
        d->mUnk_28 = (s16 *) s->mUnk_10;
        d->mUnk_2c = n;
    }
}

void func_020429c8(void *a) {
    if (gCourseMap->mUnk_60 != 0) {
        func_02042e0c(a);
    }
    if (gCourseMap->mUnk_70 != 0) {
        func_02042c3c(a);
    } else if (gCourseMap->mUnk_90 != 0) {
        func_02042a10(a);
    }
}
#pragma thumb off

#pragma thumb on
u32 func_020429b8(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (value0) + (4u);
    value0 = (u32) &gCourseMap;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    *(u32 *) ((value0) + 24u) = (u32) value1;
    value0 = 1u;
    return (u32) value0;
}
#pragma thumb off

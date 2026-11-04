#include "Main/Unknown/code_020808d4.h"

#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/unk_02155000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0207ffa4.h"
#include "Main/Unknown/code_02080adc.h"
#include "Main/Unknown/code_02080b1c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_02080cc0.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02081000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0201c528.h"

void func_02081060(Unk0206bcb0 *p) {
    Unk0201ca6c *e;

    if (!(p->mUnk_7c & 1)) {
        return;
    }
    if (data_0217ae94[p->mIndex] != NULL) {
        return;
    }
    data_0217ae94[p->mIndex] = func_0208b7bc(0x80, &data_02155a14);
    e = data_0217ae94[p->mIndex];
    e->mUnk_98_24 = p->mIndex;
    e->mUnk_94 = 0;
    e->mUnk_90 = func_02081b30;
}

void func_02081000(Unk0206bcb0 *p) {
    Unk0201ca6c *e = data_0217ae94[p->mIndex];

    if (e == NULL) {
        return;
    }
    e->mUnk_98_16 = 0;
    e->mUnk_98_8 = 3;
    e->mUnk_90 = func_02081ab8;
    data_0217ae94[p->mIndex] = NULL;
}

void func_02080fb8(Unk0206bcb0 *p) {
    if (data_0217ae94[p->mIndex] == NULL) {
        return;
    }
    func_0208b710(data_0217ae94[p->mIndex]);
    data_0217ae94[p->mIndex] = NULL;
}

void func_02080f44(Unk0206bcb0 *p) {
    Unk0201ca6c *e;

    if (data_0217ae74[p->mIndex] != NULL) {
        return;
    }
    data_0217ae74[p->mIndex] = func_0208b7bc(0x7f, &data_02155a14);
    e = data_0217ae74[p->mIndex];
    e->mUnk_98_24 = p->mIndex;
    e->mUnk_94 = (void *) 1;
    e->mUnk_90 = func_02081b30;
}

void func_02080ee4(Unk0206bcb0 *p) {
    Unk0201ca6c *e = data_0217ae74[p->mIndex];

    if (e == NULL) {
        return;
    }
    e->mUnk_98_16 = 0;
    e->mUnk_98_8 = 5;
    e->mUnk_90 = func_02081ab8;
    data_0217ae74[p->mIndex] = NULL;
}

void func_02080e9c(Unk0206bcb0 *p) {
    if (data_0217ae74[p->mIndex] == NULL) {
        return;
    }
    func_0208b710(data_0217ae74[p->mIndex]);
    data_0217ae74[p->mIndex] = NULL;
}

void func_02080e88(Unk0206c1ac *p, Unk0206bcb0 *q) {
    p->mUnk_6c = (s16) q->mUnk_bc.z;
}

s32 func_02080e2c(Unk0208001c *p, Vec3 *a) {
    Vec3 v;
    s32 n;
    BOOL r = FALSE;

    n = p->mUnk_00->mUnk_24;
    Vec3Sub(p->mUnk_00->mUnk_20, a, &v);
    v.y = r;
    if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z < (s64) n * n) {
        r = TRUE;
    }
    return r;
}

s32 func_02080dbc(Unk0208001c *p, Vec3 *a) {
    Vec3 v;
    Vec3 *t = p->mUnk_00->mUnk_20;
    BOOL r = FALSE;

    if (p->mUnk_08.x != 0 || p->mUnk_08.y != 0 || p->mUnk_08.z != 0) {
        Vec3Sub(a, t, &v);
        if (func_02039828(&p->mUnk_08, &v) > 0) {
            r = TRUE;
        }
    }
    return r;
}

void func_02080d34(Unk02080d34 *p, u16 a) {
    p->mUnk_00.mUnk_00 = gCourseMap->mUnk_a4;
    p->mUnk_00.mUnk_04 = p->mUnk_00.mUnk_00->mUnk_0c;
    p->mUnk_00.mUnk_08 = data_021557ec;
    Vec3Sub(p->mUnk_00.mUnk_00->mUnk_18, p->mUnk_00.mUnk_04->mUnk_18, &p->mUnk_00.mUnk_08);
    func_02039860(&p->mUnk_00.mUnk_08, &p->mUnk_00.mUnk_08);
    p->mUnk_00.mUnk_14 = NULL;
    p->mUnk_00.mUnk_18 = 0;
    p->mUnk_1c = a;
    p->mUnk_1e = 0;
}

void func_02080cd0(Unk0208001c *p, Unk02175620_bc *a) {
    p->mUnk_00 = a;
    p->mUnk_04 = p->mUnk_00->mUnk_0c;
    p->mUnk_14 = NULL;
    p->mUnk_18 = 0;
    p->mUnk_08 = data_021557ec;
    Vec3Sub(p->mUnk_00->mUnk_18, p->mUnk_04->mUnk_18, &p->mUnk_08);
    func_02039860(&p->mUnk_08, &p->mUnk_08);
}

s16 func_02080cc0(Unk0208001c *p) {
    return *(s16 *) p->mUnk_00->mUnk_20;
}

s32 func_02080c64(Unk02080b1c *p, Vec3 *a) {
    Vec3 v;
    s32 d;
    BOOL r;
    Unk02080b1c_00 *n = p->mUnk_00;

    r = FALSE;
    d = n->mUnk_1c;
    Vec3Sub(n->mUnk_18, a, &v);
    v.y = r;
    if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z < (s64) d * d) {
        r = TRUE;
    }
    return r;
}

s32 func_02080bf4(Unk02080b1c *p, Vec3 *a) {
    Vec3 v;
    BOOL r;
    Vec3 *w = p->mUnk_00->mUnk_18;

    r = FALSE;
    if (p->mUnk_08.x != 0 || p->mUnk_08.y != 0 || p->mUnk_08.z != 0) {
        Vec3Sub(a, w, &v);
        if (func_02039828(&p->mUnk_08, &v) > 0) {
            r = TRUE;
        }
    }
    return r;
}

void func_02080b1c(Unk02080b1c *p) {
    u16 i = 0;
    u16 n;
    u32 v;
    Unk0217aebc_128 *q;

    if (!(func_0207a974(p->mUnk_1c)->mUnk_4c & 0x10000000)) {
        n = p->mUnk_00->mUnk_24;
        if (n > 1) {
            q = func_0208537c();
            if (n == 0) {
                v = 0;
            } else {
                q->mUnk_00 = (s64) q->mUnk_08 * (s64) q->mUnk_00 + q->mUnk_10;
                v = (n == 0) ? (u32) (q->mUnk_00 >> 32) : (u32) (((q->mUnk_00 >> 32) * (u32) n) >> 32);
            }
            i = (u16) v;
        }
    }
    p->mUnk_04 = p->mUnk_00;
    p->mUnk_00 = p->mUnk_00->mUnk_00[i];
    Vec3Sub(p->mUnk_00->mUnk_18, p->mUnk_04->mUnk_18, &p->mUnk_08);
    func_02039860(&p->mUnk_08, &p->mUnk_08);
}

void func_02080adc(Unk0208001c *p, Unk02175620_bc *a) {
    p->mUnk_04 = p->mUnk_00;
    p->mUnk_00 = a;
    Vec3Sub(p->mUnk_00->mUnk_18, p->mUnk_04->mUnk_18, &p->mUnk_08);
    func_02039860(&p->mUnk_08, &p->mUnk_08);
}

void func_02080ac0(Unk0208001c *p) {
    if (p->mUnk_14 == NULL) {
        p->mUnk_14 = p->mUnk_04;
        p->mUnk_18 = 0;
    }
}

void func_02080908(Unk0208001c *p, Vec3 *a, Vec3 *b, u16 c) {
    Unk02175620_bc *r = NULL;
    u16 i;
    u16 j;
    s32 k;
    s32 m;
    s32 d;
    Unk02175620_bc *v1 = gCourseMap->mUnk_bc;
    Unk02175620_bc *v2[3] = {0, 0, 0};
    s32 v3[3];
    Vec3 v;
    Vec3 w;

    v3[0] = v3[1] = v3[2] = 0xc8000;
    m = -0x1000;
    for (i = 0; i < gCourseMap->mUnk_88; i++) {
        Vec3Sub(&gCourseMap->mUnk_84[i].mUnk_00, a, &v);
        d = Vec3Length(&v);
        if (d < 0xc8000) {
            for (k = 0; k < 3; k++) {
                if (d < v3[k]) {
                    v3[k] = d;
                    v2[k] = &v1[i];
                    break;
                }
            }
        }
    }
    for (j = 0; j < 3; j++) {
        if (v2[j] != NULL) {
            Vec3Sub(v2[j]->mUnk_20, a, &w);
            if ((s64) w.x * w.x + (s64) w.y * w.y + (s64) w.z * w.z >= 0x10) {
                func_02039860(&w, &w);
            }
            d = func_02039828(&w, b);
            if (d >= m) {
                r = v2[j];
                m = d;
            }
        }
    }
    p->mUnk_00 = r;
    p->mUnk_04 = r;
    p->mUnk_08 = data_021557ec;
    p->mUnk_14 = NULL;
    p->mUnk_18 = 0;
}

void func_020808d4(Unk0208001c *p, Unk02175620_bc *a) {
    p->mUnk_04 = a;
    p->mUnk_00 = p->mUnk_04;
    p->mUnk_08 = data_021557ec;
    p->mUnk_14 = NULL;
    p->mUnk_18 = 0;
}

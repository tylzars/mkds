#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02081000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02147cd8.h"
#include "code_0201c528.h"

void func_02081060(Unk0206bcb0 *p) {
    Unk0201ca6c *e;

    if (!(p->mUnk_7c & 1)) {
        return;
    }
    if (data_0217ae94[p->mUnk_74] != NULL) {
        return;
    }
    data_0217ae94[p->mUnk_74] = func_0208b7bc(0x80, &data_02155a14);
    e = data_0217ae94[p->mUnk_74];
    e->mUnk_98_24 = p->mUnk_74;
    e->mUnk_94 = 0;
    e->mUnk_90 = func_02081b30;
}

void func_02081000(Unk0206bcb0 *p) {
    Unk0201ca6c *e = data_0217ae94[p->mUnk_74];

    if (e == NULL) {
        return;
    }
    e->mUnk_98_16 = 0;
    e->mUnk_98_8 = 3;
    e->mUnk_90 = func_02081ab8;
    data_0217ae94[p->mUnk_74] = NULL;
}

void func_02080fb8(Unk0206bcb0 *p) {
    if (data_0217ae94[p->mUnk_74] == NULL) {
        return;
    }
    func_0208b710(data_0217ae94[p->mUnk_74]);
    data_0217ae94[p->mUnk_74] = NULL;
}

void func_02080f44(Unk0206bcb0 *p) {
    Unk0201ca6c *e;

    if (data_0217ae74[p->mUnk_74] != NULL) {
        return;
    }
    data_0217ae74[p->mUnk_74] = func_0208b7bc(0x7f, &data_02155a14);
    e = data_0217ae74[p->mUnk_74];
    e->mUnk_98_24 = p->mUnk_74;
    e->mUnk_94 = (void *) 1;
    e->mUnk_90 = func_02081b30;
}

void func_02080ee4(Unk0206bcb0 *p) {
    Unk0201ca6c *e = data_0217ae74[p->mUnk_74];

    if (e == NULL) {
        return;
    }
    e->mUnk_98_16 = 0;
    e->mUnk_98_8 = 5;
    e->mUnk_90 = func_02081ab8;
    data_0217ae74[p->mUnk_74] = NULL;
}

void func_02080e9c(Unk0206bcb0 *p) {
    if (data_0217ae74[p->mUnk_74] == NULL) {
        return;
    }
    func_0208b710(data_0217ae74[p->mUnk_74]);
    data_0217ae74[p->mUnk_74] = NULL;
}

void func_02080e88(Unk0206c1ac *p, Unk0206bcb0 *q) {
    p->mUnk_6c = (s16) q->mUnk_bc.z;
}

s32 func_02080e2c(Unk0208001c *p, Vec3 *a) {
    Vec3 v;
    s32 n;
    BOOL r = FALSE;

    n = p->mUnk_00->mUnk_24;
    func_021484d0(p->mUnk_00->mUnk_20, a, &v);
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
        func_021484d0(a, t, &v);
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
    func_021484d0(p->mUnk_00.mUnk_00->mUnk_18, p->mUnk_00.mUnk_04->mUnk_18, &p->mUnk_00.mUnk_08);
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
    func_021484d0(p->mUnk_00->mUnk_18, p->mUnk_04->mUnk_18, &p->mUnk_08);
    func_02039860(&p->mUnk_08, &p->mUnk_08);
}

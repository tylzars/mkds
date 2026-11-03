#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209bc74.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_020d20a8.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020ea514.h"

#pragma thumb on
void *func_0209be84(void *a, const char *b) {
    Unk0209bc74 *o;

    o = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    if (a != NULL) {
        ((Unk0209bc74_a *) a)->mUnk_18 = 1;
    }
    o->mUnk_18 = FindCourseMapObjFile(b);
    o->mUnk_10 = func_02036bec(func_020364e0(func_020364e8()), 0x6c);
    func_02084e28(o->mUnk_10, o->mUnk_18);
    func_020849a0(o->mUnk_10, 0x294a);
    func_020849b0(o->mUnk_10, 2);
    o->mUnk_00 = data_021565c4;
    return o;
}
#pragma thumb off

#pragma thumb on
void func_0209be50(Unk0209bc74 *a, const char *b) {
    void *x;

    x = FindCourseMapObjFile(b);
    a->mUnk_1c[0] = func_02036bec(func_020364e0(func_020364e8()), 0x38);
    func_020ea514(0, a->mUnk_10, a->mUnk_1c[0], a->mUnk_18, x);
}
#pragma thumb off

#pragma thumb on
void func_0209be1c(Unk0209bc74 *a, const char *b) {
    void *x;

    x = FindCourseMapObjFile(b);
    a->mUnk_1c[3] = func_02036bec(func_020364e0(func_020364e8()), 0x38);
    func_020ea514(1, a->mUnk_10, a->mUnk_1c[3], a->mUnk_18, x);
}
#pragma thumb off

#pragma thumb on
void func_0209bde8(Unk0209bc74 *a, const char *b) {
    void *x;

    x = FindCourseMapObjFile(b);
    a->mUnk_1c[1] = func_02036bec(func_020364e0(func_020364e8()), 0x38);
    func_020ea514(2, a->mUnk_10, a->mUnk_1c[1], a->mUnk_18, x);
}
#pragma thumb off

#pragma thumb on
void *func_0209bd90(void *a, const char *b) {
    Unk0209bc74 *o;
    void *x;

    o = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    x = FindCourseMapObjFile(b);
    if (a != NULL) {
        ((Unk0209bc74_a *) a)->mUnk_18 = 1;
    }
    o->mUnk_14 = func_02036bec(func_020364e0(func_020364e8()), 0x74);
    func_0207afa8(o->mUnk_14, x, 0x3f);
    o->mUnk_00 = data_021565b8;
    return o;
}
#pragma thumb off

#pragma thumb on
void *func_0209bd08(void *a, const char *b) {
    Unk0209bc74 *o;
    void *x;
    Unk020e6488 *m;

    o = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    x = FindCourseMapObjFile(b);
    if (a != NULL) {
        ((Unk0209bc74_a *) a)->mUnk_18 = 2;
    }
    o->mUnk_0c = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    func_020e64b8(o->mUnk_0c, x, NULL, 0);
    m = o->mUnk_0c;
    m->mUnk_10 &= 0x8000ffff;
    m->mUnk_10 |= 0x294a0000;
    m = o->mUnk_0c;
    m->mUnk_14 &= ~0xf;
    m->mUnk_14 |= 2;
    o->mUnk_00 = data_021565ac;
    return o;
}
#pragma thumb off

#pragma thumb on
void *func_0209bc74(void *a, const char *b, const char *c) {
    Unk0209bc74 *o;
    void *x;
    void *y;
    Unk020e6488 *m;

    o = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    x = FindCourseMapObjFile(b);
    y = FindCourseMapObjFile(c);
    if (a != NULL) {
        ((Unk0209bc74_a *) a)->mUnk_18 = 2;
    }
    o->mUnk_0c = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    func_020e64b8(o->mUnk_0c, x, y, 0);
    m = o->mUnk_0c;
    m->mUnk_10 &= 0x8000ffff;
    m->mUnk_10 |= 0x294a0000;
    m = o->mUnk_0c;
    m->mUnk_14 &= ~0xf;
    m->mUnk_14 |= 2;
    o->mUnk_00 = data_021565a0;
    return o;
}
#pragma thumb off

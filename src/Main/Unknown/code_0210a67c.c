#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"

void func_0210a880(Unk0206bcb0 *a, Unk0210bf24 *b, s32 c) {
    s32 d;
    u32 e;
    u32 f;
    s32 g;
    s16 w;

    e = b->mUnk_1a;
    d = c + a->mUnk_48c(&a->mUnk_518);
    if (b->mUnk_18 != 2) {
        f = a->mUnk_500;
        w = 0;
        g = a->mUnk_74 == data_021759c0->mUnk_62;
        if (f > 0x11170) {
            w = 0x384;
            if (g != 0) {
                w += data_0217ccb4;
            }
        } else if (f > 0x61a8 && f <= 0x11170) {
            w = ((s32) ((((s64) data_0217ccb0 * (s32) ((f - 0x61a8) << 12)) + 0x800) >> 12)) >> 12;
            if (g != 0) {
                w += data_0217ccb4 >> 1;
            }
        }
        d -= w;
    } else {
        f = a->mUnk_500;
        w = 0;
        if (f > 0x11170) {
            w += data_0217ccb4;
        } else if (f > 0x61a8 && f <= 0x11170) {
            w += data_0217ccb4;
        }
        d -= w;
    }
    func_02105b28(&b->mUnk_00, e);
    func_02105b0c(&b->mUnk_00, b->mUnk_14 + d);
}

void func_0210a77c(Unk0206bcb0 *a, Unk0210bf24 *b) {
    Vec3 *o;
    u32 c;
    s32 v;
    s16 w;
    u32 m;
    s32 t;

    v = 0;
    c = b->mUnk_1a;
    if (a->mUnk_44 == 0) {
        o = (Vec3 *) &a->mUnk_168.y;
    } else {
        o = (Vec3 *) &a->mUnk_250.z;
    }
    v += o->z;
    t = func_020d3d48(a->mUnk_50.y);
    if (t < 0) {
        m = -t;
        w = 0;
        if (m > 0x11170) {
            w = 0x1c2;
            w += data_0217ccb4;
        } else if (m > 0x61a8 && m <= 0x11170) {
            w = ((s32) ((((s64) data_0217ccbc * (s32) ((m - 0x61a8) << 12)) + 0x800) >> 12)) >> 12;
            w += data_0217ccb4 >> 1;
        }
        v -= w;
    }
    func_02105b28(&b->mUnk_00, c);
    func_02105b0c(&b->mUnk_00, b->mUnk_14 + v);
}

void func_0210a76c(Unk0206bcb0 *a, Unk0210bf24 *b) {
    func_0210a880(a, b, 0);
}

void func_0210a724(Unk0206bcb0 *a, Unk0210bf24 *b) {
    u32 c;
    s32 v;

    c = b->mUnk_19;
    v = 0;
    if (!(c & 0x10) && data_0217c814.mUnk_00 > a->mUnk_450.mUnk_34 + 1) {
        v = 0x180;
        if (c & 0x80) {
            v += 0x100;
        }
    }
    func_0210a880(a, b, v);
}

void func_0210a6ec(Unk0206bcb0 *a, Unk0210bf24 *b) {
    u32 c;

    c = a->mUnk_4c;
    func_02105b28(&b->mUnk_00, b->mUnk_1a);
    func_02105b0c(&b->mUnk_00, b->mUnk_14 + c);
}

void func_0210a6b4(Unk0206bcb0 *a, Unk0210bf24 *b) {
    u32 c;

    c = a->mUnk_4c;
    func_02105b28(&b->mUnk_00, b->mUnk_1a);
    func_02105b0c(&b->mUnk_00, b->mUnk_14 + c);
}

void func_0210a67c(Unk0206bcb0 *a, Unk0210bf24 *b) {
    s32 c;

    c = (s32) a->mUnk_308;
    func_02105b28(&b->mUnk_00, b->mUnk_1a);
    func_02105b0c(&b->mUnk_00, b->mUnk_14 + c);
}

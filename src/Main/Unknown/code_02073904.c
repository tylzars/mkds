#include "Main/Unknown/code_02073904.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02147cd8.h"

static inline s32 func_02073904_inline(Vec3 *v, Vec3 *n) {
    if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z < 0x10) {
        return 0;
    }
    return func_02039860(v, n);
}

void func_02073904(Unk02073904 *p) {
    Unk020f41c4_B *r;
    Vec3 a;
    Vec3 b;
    Vec3 d;
    Vec3 g;
    Vec3 e;
    Vec3 f;
    s32 l;
    s32 k;
    s32 h;
    s32 m;
    s32 s;
    s32 i;

    if (func_02061f7c() == 0) {
        Vec3Sub(&p->mUnk_024, &p->mUnk_018, &d);
        l = func_02073904_inline(&d, &d);
        if (l != 0) {
            k = data_usa_021656a8;
            r = &data_0217561c->mUnk_498;
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            s = (s32) (((s64) data_usa_021656ac * l) >> 12);
            h = (s16) (u16) (r->mUnk_00 >> 52);
            s = (s32) (((s64) (s + 0x1000) * data_usa_021656c8) >> 12);
            m = (s32) (((s64) s * ((h - 0x800) * 2)) >> 12);
            a.x = (s32) (((s64) p->mUnk_00c.x * m) >> 12);
            a.y = (s32) (((s64) p->mUnk_00c.y * m) >> 12);
            a.z = (s32) (((s64) p->mUnk_00c.z * m) >> 12);
            r = &data_0217561c->mUnk_498;
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            h = (s16) (u16) (r->mUnk_00 >> 52);
            m = (s32) (((s64) s * ((h - 0x800) * 2)) >> 12);
            b.x = (s32) (((s64) p->mUnk_000.x * m) >> 12);
            b.y = (s32) (((s64) p->mUnk_000.y * m) >> 12);
            b.z = (s32) (((s64) p->mUnk_000.z * m) >> 12);
            Vec3Add(&a, &b, &p->mUnk_0f4);
            r = &data_0217561c->mUnk_498;
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            h = (s16) (u16) (r->mUnk_00 >> 52);
            m = (s32) (((s64) k * ((h - 0x800) * 2)) >> 12);
            a.x = (s32) (((s64) p->mUnk_00c.x * m) >> 12);
            a.y = (s32) (((s64) p->mUnk_00c.y * m) >> 12);
            a.z = (s32) (((s64) p->mUnk_00c.z * m) >> 12);
            r = &data_0217561c->mUnk_498;
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            h = (s16) (u16) (r->mUnk_00 >> 52);
            m = (s32) (((s64) k * ((h - 0x800) * 2)) >> 12);
            b.x = (s32) (((s64) p->mUnk_000.x * m) >> 12);
            b.y = (s32) (((s64) p->mUnk_000.y * m) >> 12);
            b.z = (s32) (((s64) p->mUnk_000.z * m) >> 12);
            Vec3Add(&a, &b, &p->mUnk_100);
        }
    }
    s = data_usa_021656b0;
    Vec3Sub(&p->mUnk_100, &p->mUnk_118, &e);
    e.x = (s32) (((s64) e.x * s) >> 12);
    e.y = (s32) (((s64) e.y * s) >> 12);
    e.z = (s32) (((s64) e.z * s) >> 12);
    Vec3Add(&p->mUnk_118, &e, &p->mUnk_118);
    s = data_usa_021656a4;
    Vec3Sub(&p->mUnk_0f4, &p->mUnk_10c, &f);
    f.x = (s32) (((s64) f.x * s) >> 12);
    f.y = (s32) (((s64) f.y * s) >> 12);
    f.z = (s32) (((s64) f.z * s) >> 12);
    Vec3Add(&p->mUnk_10c, &f, &p->mUnk_10c);
    i = -data_usa_021656cc[p->mUnk_130 - 1];
    g.x = (s32) (((s64) p->mUnk_10c.x * i) >> 12);
    g.y = (s32) (((s64) p->mUnk_10c.y * i) >> 12);
    g.z = (s32) (((s64) p->mUnk_10c.z * i) >> 12);
    Vec3Add(&g, &p->mUnk_124, &p->mUnk_124);
    s = data_usa_021656bc;
    p->mUnk_124.x = (s32) (((s64) p->mUnk_124.x * s) >> 12);
    p->mUnk_124.y = (s32) (((s64) p->mUnk_124.y * s) >> 12);
    p->mUnk_124.z = (s32) (((s64) p->mUnk_124.z * s) >> 12);
}

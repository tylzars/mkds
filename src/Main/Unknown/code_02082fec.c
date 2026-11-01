#include "Main/Unknown/code_02082fec.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02067000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02147cd8.h"

void func_02083484(Unk0201ca6c *p, s32 a) {
    Vec3 x;
    Vec3 v;
    Vec3 w;
    Unk0206bcb0 *q;
    Vec3 *s;
    u32 n;
    s32 k;
    u32 m;
    u32 f;

    if (a != 0) {
        return;
    }
    q = p->mUnk_94;
    v = q->mUnk_3b0;
    k = data_0216596c[p->mUnk_98_b.mUnk_00];
    n = p->mUnk_98_b.mUnk_02;
    m = p->mUnk_98_b.mUnk_01;
    f = 1;
    if (func_020675b4(q) == 0) {
        if (q->mUnk_2a4 >= 0x119a) {
            f = 0;
        }
    }
    p->mUnk_24.mUnk_00_1 = (f != 0);
    s = &q->mUnk_138;
    w.x = (s32) (((s64) s->x * -0x5000) >> 12);
    w.y = (s32) (((s64) s->y * -0x5000) >> 12);
    w.z = (s32) (((s64) s->z * -0x5000) >> 12);
    if (m != 0) {
        n = (u8) (n + 1);
        if (n == 10) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    }
    p->mUnk_98_b.mUnk_02 = n;
    func_02148504(q->mUnk_508, &w, &x);
    x.x = x.x >> 4;
    x.y = x.y >> 4;
    x.z = x.z >> 4;
    v.x = (s32) (((s64) v.x * k) >> 12);
    v.y = (s32) (((s64) v.y * k) >> 12);
    v.z = (s32) (((s64) v.z * k) >> 12);
    p->mUnk_28.x = x.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = x.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = x.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_40 = v;
}

void func_0208335c(Unk0201ca6c *p, s32 a) {
    s32 x;
    Unk0206bcb0 *q;
    u32 n;
    Unk0217ae84 *e;
    u32 m;
    u32 r;
    u32 f;

    if (a != 0) {
        return;
    }
    q = p->mUnk_94;
    e = &data_0217ae84[q->mUnk_74];
    n = p->mUnk_98_b.mUnk_02;
    m = p->mUnk_98_b.mUnk_01;
    r = p->mUnk_98_b.mUnk_03;
    f = 1;
    if (func_020675b4(q) == 0) {
        if (q->mUnk_2a4 >= 0x119a) {
            f = 0;
        }
    }
    p->mUnk_24.mUnk_00_1 = (f != 0);
    if (m != 0) {
        n = (u8) (n + 1);
        if (n == 10) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    }
    p->mUnk_98_b.mUnk_02 = n;
    p->mUnk_50 = e->mUnk_4c[r];
    x = e->mUnk_34[r].x;
    p->mUnk_28.x = x + p->mUnk_20->mUnk_00->mUnk_04.x;
    x = e->mUnk_34[r].y;
    p->mUnk_28.y = x + p->mUnk_20->mUnk_00->mUnk_04.y;
    x = e->mUnk_34[r].z;
    p->mUnk_28.z = x + p->mUnk_20->mUnk_00->mUnk_04.z;
}

void func_020831bc(Unk0201ca6c *p, s32 a) {
    s32 x;
    Vec3 v;
    Unk0206bcb0 *q;
    u32 n;
    Unk0217ae84 *e;
    u32 m;
    u32 r;
    s32 k;
    u32 f;

    if (a != 0) {
        return;
    }
    q = p->mUnk_94;
    e = &data_0217ae84[q->mUnk_74];
    v = q->mUnk_3b0;
    n = p->mUnk_98_b.mUnk_02;
    m = p->mUnk_98_b.mUnk_01;
    r = p->mUnk_98_b.mUnk_03;
    k = data_0216596c[p->mUnk_98_b.mUnk_00];
    f = 1;
    if (func_020675b4(q) == 0) {
        if (q->mUnk_2a4 >= 0x119a) {
            f = 0;
        }
    }
    p->mUnk_24.mUnk_00_1 = (f != 0);
    if (m != 0) {
        n = (u8) (n + 1);
        if (n == 10) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    }
    p->mUnk_98_b.mUnk_02 = n;
    p->mUnk_50 = e->mUnk_4c[r];
    x = e->mUnk_34[r].x;
    p->mUnk_28.x = x + p->mUnk_20->mUnk_00->mUnk_04.x;
    x = e->mUnk_34[r].y;
    p->mUnk_28.y = x + p->mUnk_20->mUnk_00->mUnk_04.y;
    x = e->mUnk_34[r].z;
    p->mUnk_28.z = x + p->mUnk_20->mUnk_00->mUnk_04.z;
    v.x = (s32) (((s64) v.x * k) >> 12);
    v.y = (s32) (((s64) v.y * k) >> 12);
    v.z = (s32) (((s64) v.z * k) >> 12);
    p->mUnk_40 = v;
}

void func_02082fec(Unk0201ca6c *p, s32 a) {
    s32 x;
    Vec3 v;
    u32 m;
    Unk0206bcb0 *q;
    u32 n;
    Unk0217ae84 *e;
    u32 f;
    u32 r;
    s32 k;
    u32 g;

    if (a != 0) {
        return;
    }
    q = p->mUnk_94;
    e = &data_0217ae84[q->mUnk_74];
    v = q->mUnk_3b0;
    g = 1;
    f = 1;
    n = p->mUnk_98_b.mUnk_02;
    m = p->mUnk_98_b.mUnk_01;
    r = p->mUnk_98_b.mUnk_03;
    k = data_0216596c[p->mUnk_98_b.mUnk_00];
    if (func_020675b4(q) == 0) {
        if (q->mUnk_2a4 >= 0x119a) {
            f = 0;
        }
    }
    if (f == 0) {
        if (q->mUnk_500 <= 0x5000) {
            g = 0;
        }
    }
    p->mUnk_24.mUnk_00_1 = (g != 0);
    if (m != 0) {
        n = (u8) (n + 1);
        if (n == 10) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    }
    p->mUnk_98_b.mUnk_02 = n;
    p->mUnk_50 = e->mUnk_4c[r];
    x = e->mUnk_34[r].x;
    p->mUnk_28.x = x + p->mUnk_20->mUnk_00->mUnk_04.x;
    x = e->mUnk_34[r].y;
    p->mUnk_28.y = x + p->mUnk_20->mUnk_00->mUnk_04.y;
    x = e->mUnk_34[r].z;
    p->mUnk_28.z = x + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_28.y = p->mUnk_28.y + (q->mUnk_500 >> 4);
    v.x = (s32) (((s64) v.x * k) >> 12);
    v.y = (s32) (((s64) v.y * k) >> 12);
    v.z = (s32) (((s64) v.z * k) >> 12);
    p->mUnk_40 = v;
}

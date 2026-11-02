#include "Main/Unknown/code_0207e654.h"

#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_02080cc0.h"
#include "Main/Unknown/code_020808d4.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_0206390c.h"
#include "Main/Unknown/code_020435d4.h"
#include "Main/Unknown/code_020738f4.h"
#include "Main/Unknown/unk_02155000.h"
#include "code_02147cd8.h"
#include "code_02148538.h"

void func_0207ebfc(Unk020888b4 *p) {
    Vec3 v0;
    Vec3 v1;
    Vec3 v3;
    Vec3 v5;
    Vec3 v4;
    Vec3 v2;
    Unk0206bcb0 *q;
    Unk0206bcb0 *q2;
    Vec3 *c;
    Vec3 *a;
    s32 n;
    s32 m;
    BOOL b;

    func_02080cc0(&p->mUnk_08.mUnk_00);
    q = p->mUnk_00;
    if (p->mUnk_90 == 1) {
        func_0204360c(q->mUnk_78, 0x100);
        p->mUnk_90 = 2;
    }
    if (p->mUnk_90 == 4) {
        if (q->mUnk_44 & 2) {
            if (p->mUnk_94 == 1) {
                q->mUnk_48 &= ~0x10;
                q->mUnk_48 |= 8;
            } else if (p->mUnk_94 == 2) {
                q->mUnk_48 &= ~8;
                q->mUnk_48 |= 0x10;
            }
        } else {
            p->mUnk_90 = 0;
            p->mUnk_94 = 0;
        }
    }
    if (p->mUnk_90 == 3 && (q->mUnk_44 & 0x10)) {
        a = &q->mUnk_12c;
        c = &q->mUnk_138;
        func_021484d0(&p->mUnk_44, &q->mUnk_80, &v1);
        n = func_0214848c(a, &v1);
        v1.x -= (s32) (((s64) a->x * n) >> 12);
        v1.y -= (s32) (((s64) a->y * n) >> 12);
        v1.z -= (s32) (((s64) a->z * n) >> 12);
        func_020397a8(c, &v1, &v2);
        m = func_021482cc(&v2);
        m = func_02148538(m, func_02039828(c, &v1));
        m = (s32) (((s64) m * 0x394bb834c8LL + 0x80000000LL) >> 32);
        n = func_02039828(&v2, a);
        if (n < 0) {
            n = -1;
            m = m * n;
        }
        p->mUnk_70 = func_020738f8(m);
        p->mUnk_90 = 0;
        p->mUnk_94 = 0;
        p->mUnk_98 = 0;
        p->mUnk_a0 = 0;
        func_0206cdd4(q);
        if (func_020738f8(p->mUnk_70) <= 0x32000) {
            return;
        }
        func_021484d0(&p->mUnk_44, &q->mUnk_80, &v0);
        p->mUnk_90 = 4;
        q2 = p->mUnk_00;
        func_02063b30(q2, &v3);
        n = func_0214848c(&v3, &v0);
        v4.x = v0.x - (s32) (((s64) v3.x * n) >> 12);
        v4.y = v0.y - (s32) (((s64) v3.y * n) >> 12);
        v4.z = v0.z - (s32) (((s64) v3.z * n) >> 12);
        func_020397a8(&q2->mUnk_138, &v4, &v5);
        m = func_02039828(&v3, &v5);
        if (m > 0) {
            m = 1;
        } else {
            m = -1;
        }
        if (m > 0) {
            p->mUnk_94 = 1;
        } else {
            p->mUnk_94 = 2;
        }
        q->mUnk_44 |= 0x20000000;
        return;
    }
    if (p->mUnk_90 != 2) {
        return;
    }
    if (q->mUnk_44 & 2) {
        if (p->mUnk_94 == 1) {
            q->mUnk_48 &= ~0x10;
            q->mUnk_48 |= 8;
        } else if (p->mUnk_94 == 2) {
            q->mUnk_48 &= ~8;
            q->mUnk_48 |= 0x10;
        }
    }
    func_0204360c(q->mUnk_78, 0x100);
    p->mUnk_98++;
    b = FALSE;
    if (p->mUnk_98 == 0x28 && p->mUnk_a0 != 0) {
        Unk0217aebc_128 *r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        if ((s16) (u16) (r->mUnk_00 >> 52) <= p->mUnk_8c) {
            b = TRUE;
        }
    }
    if (b != FALSE) {
        func_02068440(q, 3);
    }
    p->mUnk_60 = data_usa_021557d0;
    p->mUnk_74 = 0;
    if (!(q->mUnk_44 & 0xc00c0)) {
        n = q->mUnk_2a4;
        if (n > (s32) (((s64) q->mUnk_2cc->mUnk_10 * 0x8cd) >> 12)) {
            return;
        }
    }
    p->mUnk_90 = 0;
    p->mUnk_94 = 0;
    p->mUnk_98 = 0;
    p->mUnk_a0 = 0;
}

s32 func_0207eafc(Vec3 *a, Vec3 *b, Vec3 *c, Vec3 *d) {
    Vec3 v;
    Vec3 w;
    s32 n;
    s32 l;
    s32 r;

    func_021484d0(a, b, &v);
    n = func_0214848c(c, &v);
    v.x -= (s32) (((s64) c->x * n) >> 12);
    v.y -= (s32) (((s64) c->y * n) >> 12);
    v.z -= (s32) (((s64) c->z * n) >> 12);
    func_020397a8(d, &v, &w);
    l = func_021482cc(&w);
    r = func_02148538(l, func_02039828(d, &v));
    r = (s32) (((s64) r * 0x394bb834c8LL + 0x80000000LL) >> 32);
    n = func_02039828(&w, c);
    if (n < 0) {
        n = -1;
        r = r * n;
    }
    return r;
}

void func_0207e944(Unk020888b4 *p) {
    Vec3 v = data_usa_021557c4;
    s32 s;

    func_020397a8(&p->mUnk_08.mUnk_00.mUnk_08, &v, &p->mUnk_60);
    p->mUnk_6c++;
    if (p->mUnk_6c > p->mUnk_6e) {
        Unk0217aebc_128 *r;
        s32 t;
        s32 u;

        p->mUnk_6c = 0;
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        p->mUnk_6e = 0;
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        t = (s16) (u16) (r->mUnk_00 >> 52);
        u = p->mUnk_74 + (s32) (((s64) ((s32) (((s64) t * 0x2000) >> 12) - 0x1000) * 0x267) >> 12);
        if (func_020738f8(u) > 0xb36) {
            if (u > 0) {
                u = 0xb36;
            } else {
                u = -0xb36;
            }
        }
        p->mUnk_74 = u;
    }
    s = (s32) (((s64) p->mUnk_74 * p->mUnk_08.mUnk_00.mUnk_00->mUnk_1c) >> 12);
    p->mUnk_60.x = (s32) (((s64) p->mUnk_60.x * s) >> 12);
    p->mUnk_60.y = (s32) (((s64) p->mUnk_60.y * s) >> 12);
    p->mUnk_60.z = (s32) (((s64) p->mUnk_60.z * s) >> 12);
}

void func_0207e7f0(Unk020888b4 *p) {
    Vec3 a;
    Vec3 g;
    Vec3 b;
    Vec3 e;
    Vec3 f;
    Vec3 d;
    Vec3 c;
    s32 s;

    a = *p->mUnk_08.mUnk_00.mUnk_00->mUnk_18;
    b = *p->mUnk_08.mUnk_00.mUnk_00->mUnk_18;
    c = data_usa_021557c4;
    d = *(Vec3 *) &data_usa_021557c4;
    func_020397a8(&p->mUnk_08.mUnk_00.mUnk_08, &d, &e);
    func_021484d0(&p->mUnk_00->mUnk_80, &b, &f);
    s = func_02039828(&f, &e);
    p->mUnk_74 = func_02147f34(s, p->mUnk_08.mUnk_00.mUnk_00->mUnk_1c + 0x1000);
    if (func_020738f8(p->mUnk_74) > 0x1000) {
        if (p->mUnk_74 > 0) {
            p->mUnk_74 = 0x1000;
        }
        p->mUnk_74 = -0x1000;
    }
    g = c;
    func_020397a8(&p->mUnk_08.mUnk_00.mUnk_08, &g, &p->mUnk_60);
    s = (s32) (((s64) p->mUnk_74 * p->mUnk_08.mUnk_00.mUnk_00->mUnk_1c) >> 12);
    p->mUnk_60.x = (s32) (((s64) p->mUnk_60.x * s) >> 12);
    p->mUnk_60.y = (s32) (((s64) p->mUnk_60.y * s) >> 12);
    p->mUnk_60.z = (s32) (((s64) p->mUnk_60.z * s) >> 12);
    func_02148504(&a, &p->mUnk_60, &p->mUnk_44);
}

void func_0207e668(Unk020888b4 *p) {
    BOOL a = FALSE;
    BOOL b = FALSE;
    Unk0206bcb0 *q;

    p->mUnk_ac--;
    if (p->mUnk_ac <= 0) {
        p->mUnk_ac = 0;
    } else {
        b = TRUE;
    }
    q = p->mUnk_00;
    {
        BOOL c;
        if ((q->mUnk_44 & 0xc0) && q->mUnk_2a4 < 0x3000) {
            c = TRUE;
        } else {
            c = FALSE;
        }
        if (c != FALSE) {
            p->mUnk_ac = 10;
            b = TRUE;
        }
    }
    if (b != FALSE) {
        p->mUnk_78++;
        if (p->mUnk_78 >= p->mUnk_7a) {
            p->mUnk_78 = 0;
            a = TRUE;
        }
    } else if (p->mUnk_ac <= 0) {
        p->mUnk_78 = 0;
        p->mUnk_a8 = 0;
        p->mUnk_7a = 0x14;
    }
    if (a == FALSE) {
        return;
    }
    switch (p->mUnk_a8) {
        case 0:
            p->mUnk_a8 = 1;
            p->mUnk_7a = 0x78;
            break;
        case 1:
            if (data_021759c0->mUnk_08 == 2) {
                p->mUnk_a8 = 3;
                func_0208c1f4(p->mUnk_00->mUnk_310);
                p->mUnk_7a = 0xb4;
            } else {
                p->mUnk_a8 = 2;
                p->mUnk_7a = 0xb4;
                func_02080ac0(&p->mUnk_08.mUnk_00);
            }
            break;
        case 2:
            p->mUnk_a8 = 3;
            func_0208c1f4(p->mUnk_00->mUnk_310);
            p->mUnk_7a = 0xb4;
            break;
        case 3:
            p->mUnk_a8 = 4;
            func_02063a68(p->mUnk_00);
            break;
    }
}

BOOL func_0207e654(Unk020888b4 *p) {
    return p->mUnk_b0 != NULL;
}

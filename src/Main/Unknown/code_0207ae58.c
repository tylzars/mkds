#include "Main/Unknown/code_0207ae58.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0207a14c.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02088338.h"
#include "ITCM/code_01ff8000.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/code_021112fc.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0200fe7c.h"
#include "code_020109c4.h"
#include "code_02012b30.h"
#include "code_02135014.h"

void func_0207ae58(Unk0207adf8 *a) {
    if ((a->mUnk_70 & 1) == 0) {
        return;
    }
    func_02084ad8(a, a->mUnk_6e);
    data_02155a20[a->mUnk_00.mUnk_58](a);
    func_02084a88(a, a->mUnk_6e, a->mUnk_6c);
    data_02155a20[a->mUnk_00.mUnk_58](a);
}

void func_0207aec8(void *param_1, const void *b, Vec3 *c) {
    Unk0207adf8 *a = param_1;
    s32 v;
    Vec3 w;

    if ((a->mUnk_70 & 1) == 0) {
        return;
    }
    v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    func_01ff9048(0x19, b, 0xc);
    if (c != 0) {
        s32 z = c->z;
        s32 y = c->y;
        s32 x = c->x;
        w.x = x;
        w.y = y;
        w.z = z;
        func_01ff9048(0x1b, &w, 3);
    }
    func_02084ad8(a, a->mUnk_6e);
    data_02155a20[a->mUnk_00.mUnk_58](a);
    func_02084a88(a, a->mUnk_6e, a->mUnk_6c);
    data_02155a20[a->mUnk_00.mUnk_58](a);
}

Unk0201290c *func_0207afa8(void *param_1, Unk020136f0 *b, u32 c) {
    Unk0207adf8 *a = param_1;
    Unk0201290c *p;

    func_02084e28(a, b);
    p = a->mUnk_00.mUnk_04;
    a->mUnk_6c = c;
    a->mUnk_6e = 0xd;
    a->mUnk_70 |= 1;
    func_02013540(p, 0, 3);
    func_02013588(p, 0, 0);
    return a->mUnk_00.mUnk_04;
}

void func_0207b000(Unk02084b2c *a, void *b, u32 c) {
    Unk0207adf8 *p = (Unk0207adf8 *) a;
    Unk0201290c *q;

    func_02084f10(a, b);
    q = a->mUnk_04;
    p->mUnk_6c = c;
    p->mUnk_6e = 0xd;
    p->mUnk_70 |= 1;
    func_02013540(q, 0, 3);
    func_02013588(q, 0, 0);
}

void func_0207b054(Unk0206bcb0 *p, s32 a, s32 b) {
    Unk0206bcb0_590 *q = p->mUnk_590;
    Unk0206bcb0_590_08 *s;
    Unk0206bcb0_590_24 *r = (Unk0206bcb0_590_24 *) &q->mUnk_024;

    s = q->mUnk_008;
    if (r->mUnk_14 != 0 && s->mUnk_1a != 0) {
        func_02087cfc(s, s->mUnk_1a, 1);
    }
    r->mUnk_14 = 1;
    r->mUnk_18 = b;
    func_02087e90(p->mUnk_590->mUnk_008, a);
    func_02087cfc(s, (u16) a, 0);
}

void func_0207b0d0(Unk0206bcb0 *p) {
    Unk0206bcb0_590 *q = p->mUnk_590;
    Unk0201290c *r;

    if (q->mUnk_064 != 0) {
        return;
    }
    r = q->mUnk_010->mUnk_04;
    func_02013164(r, 0);
    func_0207a14c(r, 0);
    r = q->mUnk_014->mUnk_04;
    func_02013164(r, 0);
    func_0207a14c(r, 0);
}

void func_0207b13c(Unk0206bcb0 *p) {
    Unk0206bcb0_590 *q = p->mUnk_590;
    Unk0201290c *r;

    if (q->mUnk_064 != 0) {
        return;
    }
    r = q->mUnk_010->mUnk_04;
    func_02013164(r, 2);
    func_0207a14c(r, 3);
    r = q->mUnk_014->mUnk_04;
    func_02013164(r, 2);
    func_0207a14c(r, 3);
}

void func_0207b1a8(Unk0206bcb0 *p) {
    Unk0206bcb0_590 *q = p->mUnk_590;
    Unk02084b2c *r = q->mUnk_010;
    Unk0206bcb0_590_08 *s = q->mUnk_00c;
    Unk0201290c *t = r->mUnk_04;
    Unk02084b2c *u;
    Unk0201290c *w;
    Unk02084b2c *v;

    func_02013164(t, 0);
    func_02010584((Unk020101e8 *) t, (Unk02010294 *) r->mUnk_5c.mUnk_0c);
    if (s != 0 && q->mUnk_0ac != 0) {
        func_02010ab4((Unk02010ab4 *) r, (Unk02010b50 *) s->mUnk_1c[0]);
        q->mUnk_0ac = 0;
    }
    func_0207a14c(t, 0);
    u = q->mUnk_014;
    t = u->mUnk_04;
    func_02013164(t, 0);
    func_02010584((Unk020101e8 *) t, (Unk02010294 *) u->mUnk_5c.mUnk_0c);
    func_0207a14c(t, 0);
    v = q->mUnk_018;
    if (v != 0) {
        w = v->mUnk_04;
        func_02013164(w, 0);
        func_02010584((Unk020101e8 *) w, (Unk02010294 *) v->mUnk_5c.mUnk_0c);
        func_0207a14c(w, 0);
    }
    q->mUnk_064 = 0;
}

void func_0207b284(Unk0206bcb0 *p) {
    Unk0206bcb0_590 *q = p->mUnk_590;
    Unk02084b2c *r = q->mUnk_010;
    Unk0206bcb0_590_08 *s = q->mUnk_00c;
    Unk0201290c *t = r->mUnk_04;

    func_02013164(t, 2);
    func_020104a4((Unk020101e8 *) t);
    if (s != 0 && q->mUnk_0ac == 0) {
        func_020109d8((Unk02010ab4 *) r, (Unk02010b50 *) s->mUnk_1c[0]);
        q->mUnk_0ac = 1;
    }
    func_0207a14c(t, 2);
    t = q->mUnk_014->mUnk_04;
    func_02013164(t, 2);
    func_020104a4((Unk020101e8 *) t);
    func_0207a14c(t, 2);
    if (q->mUnk_018 != 0) {
        t = q->mUnk_018->mUnk_04;
        func_02013164(t, 2);
        func_020104a4((Unk020101e8 *) t);
        func_0207a14c(t, 2);
    }
    q->mUnk_064 = 1;
}

void func_0207b354(Unk0206bcb0 *p) {
    Unk0206bcb0_590_24 *q = (Unk0206bcb0_590_24 *) &p->mUnk_590->mUnk_024;
    Unk020f41c4_B *r;
    Unk0206bcb0_590 *s;

    if (q->mUnk_04 == 0) {
        return;
    }
    q->mUnk_10--;
    if (q->mUnk_10 > 0) {
        return;
    }
    s = p->mUnk_590;
    if ((p->mUnk_7c & 0x40) != 0 || s->mUnk_008->mUnk_1a == 2) {
        func_02068a64(p, 0, 1);
    } else if (s->mUnk_008->mUnk_1a == 0) {
        func_02068a64(p, 2, 1);
    }
    r = &data_0217561c->mUnk_498;
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    q->mUnk_10 = (u32) (((r->mUnk_00 >> 32) * 200) >> 32);
    q->mUnk_10 += 0x96;
}

// non-matching: same size; 1 word differs: the mUnk_68 compare is `cmp r0, r2` (b's word first) in the original,
// ours `cmp r2, r0`
void func_0207b44c(Unk0206bcb0 *a) {
    u32 f;
    u16 b;
    s32 e;
    s32 m;
    s32 c;
    s32 k;
    Unk0206bcb0_590_24 *q;
    Unk020f41c4_B *r;
    u32 t;

    c = 1;
    f = c;
    e = 0;
    b = data_021759c0->mUnk_3d0;

    t = a->mUnk_7c;
    if ((t & 0x10) == 0) {
        return;
    }
    m = data_021759c0->mUnk_08;
    if (m == 2) {
        return;
    }
    if (m == 4) {
        return;
    }
    if (m != 2 && data_021759c0->mUnk_1c == 1) {
        b = (u16) data_0217561c->mUnk_474[0];
        if (data_021759c0->mUnk_58 != 0) {
            enum { K0 } g = a->mUnk_74;
            if (data_021759c0->mUnk_68[g].mUnk_08.mUnk_04 != data_021759c0->mUnk_68[b].mUnk_08.mUnk_04) {
                f = 2;
            } else {
                f = 0;
                a->mUnk_7c |= 0x2000000;
                e = c;
            }
        } else if (a->mUnk_74 != b) {
            f = 2;
        } else {
            f = 0;
            a->mUnk_7c |= 0x2000000;
            e = c;
        }
    } else if (m == 1) {
        if ((t & 4) == 0) {
            if (func_020c7148() != 0 || func_020c70ec() != 0) {
                f = 0;
            } else {
                f = 2;
            }
        }
    } else if (b > 1) {
        f = ((s16 *) &data_usa_021551dc[(b - 2) * 4])[func_0203c8dc(a->mUnk_74) - 1];
    }
    if (f == 0) {
        Unk0206bcb0_590 *s = a->mUnk_590;
        q = (Unk0206bcb0_590_24 *) &s->mUnk_024;
        func_02087cfc(s->mUnk_008, (u16) f, 1);
        func_02068a64(a, 2, 1);
        if (e != 0) {
            a->mUnk_7c |= 0x10000;
        } else {
            q->mUnk_04 = 1;
            r = &data_0217561c->mUnk_498;
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            q->mUnk_10 = (u32) (((r->mUnk_00 >> 32) * 200) >> 32);
            q->mUnk_10 += 0x96;
        }
    } else if (f == 2) {
        a->mUnk_7c |= 0x20000;
        func_02068a64(a, 3, 1);
    }
    if ((a->mUnk_7c & 1) != 0) {
        k = 1;
        if (f != 0) {
            if (f == 2) {
                k = 2;
            }
        } else {
            k = 0;
        }
        func_021112fc(k);
    }
}

void func_0207b6c0(struct Unk0206bcb0_590 *a, s32 b, s32 c) {
    if (c != 0) {
        func_02087e90(a->mUnk_008, b);
    } else {
        func_02087f84(a->mUnk_008, (u16) b);
    }
}

void func_0207b708(struct Unk0206bcb0_590 *a, s32 b) {
    Unk0206bcb0_590_08 *p = a->mUnk_00c;

    p->mUnk_0c = data_usa_021551a4[b];
    *p->mUnk_1c[p->mUnk_1a] = p->mUnk_0c;
}

// non-matching: same size; 25 words differ: the original holds the word at 0x48 in r3 and c in r2 (temps in r0), ours
// has them in r2 and r0, and the original forms `add r5, r6, #36` before the step selection
void func_0207b734(Unk0206bcb0 *a) {
    s32 b;
    Unk0206bcb0_590 *q;
    Unk0206bcb0_590_24 *p;
    Unk0206bcb0_590_08 *r;
    s32 c;
    u32 v;
    Unk0206bcb0_590_08 *s;

    b = (a->mUnk_44 & 8) != 0 ? 0x2000 : 0x1000;
    q = a->mUnk_590;
    p = (Unk0206bcb0_590_24 *) &q->mUnk_024;
    r = q->mUnk_008;
    c = p->mUnk_08;
    v = a->mUnk_48;
    if ((v & 8) != 0) {
        if (data_021759c0->mUnk_00c != 6) {
            p->mUnk_00 += b;
            if (p->mUnk_00 > c) {
                p->mUnk_00 = c;
            }
        }
    } else if ((v & 0x10) != 0) {
        if (data_021759c0->mUnk_00c != 6) {
            c *= -1;
            p->mUnk_00 -= b;
            if (p->mUnk_00 < c) {
                p->mUnk_00 = c;
            }
        }
    } else if (p->mUnk_00 != 0) {
        if (p->mUnk_00 > 0) {
            p->mUnk_00 -= b;
            if (p->mUnk_00 < 0) {
                p->mUnk_00 = 0;
            }
        } else {
            p->mUnk_00 += b;
            if (p->mUnk_00 > 0) {
                p->mUnk_00 = 0;
            }
        }
    }
    if (r->mUnk_1a != 0) {
        func_02087de0(r);
        if (p->mUnk_14 == 0) {
            return;
        }
        if (r->mUnk_02 != 1) {
            return;
        }
        func_02087cfc(r, r->mUnk_1a, 1);
        func_02087e90(q->mUnk_008, p->mUnk_18);
        s = q->mUnk_00c;
        s->mUnk_0c = data_usa_021551a4[0];
        *s->mUnk_1c[s->mUnk_1a] = s->mUnk_0c;
        p->mUnk_14 = 0;
    } else {
        r->mUnk_0c = p->mUnk_00 + p->mUnk_08;
        func_02087d44((Unk02087d0c *) r);
    }
}

void func_0207b8c4(struct Unk0206bcb0_590 *a) {
    Unk0206bcb0_590_24 *p;

    a->mUnk_024 = 0;
    p = (Unk0206bcb0_590_24 *) &a->mUnk_024;
    p->mUnk_14 = 0;
    p->mUnk_18 = 0;
}

u32 func_0207b8dc(int a) {
    return data_usa_021551b4[a].mUnk_00;
}

char *func_0207b8f4(u16 a, s32 b) {
    char *p = func_02088430(a);
    const char *q = func_0208848c(a, 1);

    snprintf(data_usa_0217ad14, 0x100, data_usa_021658e0, p, q, data_usa_021551b0[b].mUnk_00);
    return data_usa_0217ad14;
}

#include "00/code_0218f15c.h"
#include "00/code_0218e8b4.h"
#include "00/code_0218e8bc.h"
#include "00/code_0218e8c4.h"
#include "00/code_0218f7f8.h"
#include "00/code_0218f808.h"
#include "00/code_0218f848.h"
#include "00/code_0218fca8.h"
#include "00/code_021906e4.h"
#include "00/code_02190ba0.h"
#include "00/code_02191200.h"
#include "00/code_02192d64.h"
#include "00/code_021919ac.h"
#include "00/code_021937c0.h"
#include "00/code_021937e8.h"
#include "00/code_02193634.h"
#include "00/code_02193818.h"
#include "00/code_02193f50.h"
#include "00/code_02194840.h"
#include "00/code_021948f8.h"
#include "00/code_02194bb8.h"
#include "00/code_02196590.h"
#include "00/code_021965a0.h"
#include "00/code_02196914.h"
#include "00/code_021967b4.h"
#include "00/code_021a3668.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/unk_021b23b0.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_021384cc.h"
#include "code_0213442c.h"
#include "code_02134d30.h"
#include "code_02139f70.h"
#include "code_0213a460.h"

u32 func_ov000_0218f15c(Unk0218f960 *a, s8 *b, s8 *c, s32 d, s32 e, Unk0218f15cCb f, u32 g) {
    Unk0218f960_00 *o;
    if (a == 0 || (o = a->mUnk_00) == 0) {
        return 2;
    }
    if (b == 0 || *b == 0) {
        return 2;
    }
    if (c == 0 || *c == 0) {
        return 2;
    }
    if (f == 0) {
        func_ov000_02196590(a, data_ov000_021b242c);
        return 2;
    }
    if (o->mUnk_108 != 0) {
        Unk0218f15cArg h = {0};
        f(a, &h, g);
        return 0;
    }
    return func_ov000_02191cb0((Unk021919ac *) a, data_ov000_021b2514, data_ov000_021b2514, data_ov000_021b2514,
                               data_ov000_021b2514, b, c, 0, d, 0, e, (s32) f, g);
}

u32 func_ov000_0218f21c(Unk0218f960 *a, s32 b, void (*c)(void *a, void *b, u32 c), u32 d) {
    Unk0218f960_00 *o;
    if (a == 0 || (o = a->mUnk_00) == 0) {
        return 2;
    }
    if (b < 0 || b >= 6) {
        func_ov000_02196590(a, data_ov000_021b2518);
        return 2;
    }
    o->mUnk_1a4[b].mUnk_00 = c;
    o->mUnk_1a4[b].mUnk_04 = d;
    return 0;
}

u32 func_ov000_0218f268(Unk0218f960 *a) {
    Unk0218f960_00 *o;
    if (a == 0 || (o = a->mUnk_00) == 0) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        return 0;
    }
    return func_ov000_0218f2e8(a, 0);
}

void func_ov000_0218f2a0(Unk0218f960 *a) {
    if (a != 0 && a->mUnk_00 != 0) {
        func_ov000_0218f808(a);
    }
}

u32 func_ov000_0218f2b8(Unk0218f960 *a, s32 b, s32 c) {
    if (data_ov000_021b4d28 != 1) {
        return 2;
    }
    if (a == 0) {
        return 2;
    }
    return func_ov000_0218f848(a, b, c);
}

int func_ov000_0218f2e8(void *a, int b) {
    Unk0218f960 *p;
    Unk0218f960_00 *o;
    Unk021937c0Node *n;
    Unk021937c0Node *m;
    u32 r;
    u32 x;
    s32 t;
    p = a;
    o = p->mUnk_00;
    r = 0;
    if ((u32) o->mUnk_1d8 > 4) {
        func_0213442c(data_ov000_021b2528, data_ov000_021b2620, 0, 0x1b5);
    }
    if (o->mUnk_1d8 == 1) {
        do {
            r = func_ov000_02191200((int *) p);
            if (r == 0 && b != 0 && o->mUnk_1d8 == 1) {
                t = 1;
            } else {
                t = 0;
            }
            if (t != 0) {
                func_ov000_0218e8bc(10);
            }
        } while (t != 0);
        if (r != 0) {
            if (func_ov000_021937e8(p, &n, 1) != 0) {
                n->mUnk_1c = 4;
            } else {
                func_0213442c(data_ov000_021b2628, data_ov000_021b2620, 0, 0x1db);
            }
        }
    }
    if ((u32) (o->mUnk_1d8 - 2) <= 1) {
        if (r == 0) {
            r = func_ov000_0218f408(p);
        }
        if (r == 0) {
            r = func_ov000_02193f50(p);
        }
    }
    if (r == 0) {
        r = func_ov000_02194bb8(p);
    }
    n = o->mUnk_424;
    if (n != 0) {
        do {
            if (n->mUnk_1c != 0) {
                func_ov000_02193954(p, n);
                m = n;
                n = n->mNext;
                func_ov000_02193818(p, m);
            } else {
                n = n->mNext;
            }
        } while (n != 0);
    }
    x = func_ov000_02190cd4(p, b);
    if (x == 0) {
        if (o->mUnk_41c != 0) {
            func_ov000_02190ff8(p, 0);
        }
        x = r;
    }
    return x;
}

u32 func_ov000_0218f408(Unk0218f960 *a) {
    Unk0218f960_00 *o;
    Unk021937c0Node *n;
    u32 r;
    s32 m;
    u8 *p;
    u8 *q;
    s32 v1;
    u32 v2;
    s32 t;
    v2 = 0;
    o = a->mUnk_00;
    do {
        func_ov000_02192d64(a, &o->mUnk_1f4);
        r = func_ov000_021906e4(a, o->mUnk_1d4, &o->mUnk_1f4, &v2, 1, (const s8 *) data_ov000_021b262c);
        if (r != 0) {
            return r;
        }
        r = func_ov000_021907e8(a, o->mUnk_1d4, (Unk021906e4 *) &o->mUnk_1dc, &v1, &v2,
                                (const s8 *) data_ov000_021b262c);
        if (r != 0) {
            if (r == 3) {
                func_ov000_021965a0(a, 5, data_ov000_021b2630);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            return r;
        }
        p = func_02139f70(o->mUnk_1dc, data_ov000_021b265c);
        while (p != 0) {
            *p = 0;
            func_ov000_0219690c(a, data_ov000_021b2664, o->mUnk_1dc);
            v1 = p - o->mUnk_1dc;
            if (v1 > o->mUnk_1f0) {
                t = v1;
                if (t < 0x800) {
                    t = 0x800;
                }
                o->mUnk_1f0 = o->mUnk_1f0 + t;
                q = func_ov000_021a3678(o->mUnk_1ec, o->mUnk_1f0 + 1);
                if (q == 0) {
                    func_ov000_02196590(a, data_ov000_021b2670);
                    return 1;
                }
                o->mUnk_1ec = q;
            }
            func_02134eb8(o->mUnk_1ec, o->mUnk_1dc, v1 + 1);
            o->mUnk_1e4 = o->mUnk_1e4 - (p + 7 - o->mUnk_1dc);
            func_02134df8(o->mUnk_1dc, p + 7, o->mUnk_1e4 + 1);
            q = o->mUnk_1ec;
            p = func_02139f70(q, data_ov000_021b2680);
            if (p != 0) {
                m = func_0213bf90(p + 4);
                if (func_ov000_021937e8(a, &n, m) == 0) {
                    func_ov000_0219690c(a, data_ov000_021b2688, m);
                } else {
                    r = func_ov000_02193748(a, n, o->mUnk_1ec);
                    if (r != 0) {
                        return r;
                    }
                }
            } else {
                if (func_ov000_02196870(a, q, 1) != 0) {
                    return 4;
                }
                q = o->mUnk_1ec;
                if (func_0213a038(q, data_ov000_021b26b0, 4) == 0) {
                    r = func_ov000_0218fca8(a, q);
                    if (r != 0) {
                        return r;
                    }
                } else if (func_0213a038(q, data_ov000_021b26b8, 10) != 0) {
                    func_ov000_0219690c(a, data_ov000_021b26c0);
                }
            }
            p = func_02139f70(o->mUnk_1dc, data_ov000_021b265c);
        }
        if (v2 != 0) {
            o->mUnk_1d8 = 4;
            func_ov000_021965a0(a, 7, data_ov000_021b26f0);
            func_ov000_02190f4c(a, 3, 1);
            return 0;
        }
        r = func_ov000_021937c0(a);
        if (r != 0) {
            func_ov000_0218e8bc(10);
        }
    } while (r != 0);
    return 0;
}

u32 func_ov000_0218f654(Unk0218f960 *a) {
    Unk0218f960_00 *o;
    Unk021937c0Node **n;
    o = a->mUnk_00;
    o->mUnk_110[0] = 0;
    o->mUnk_12f[0] = 0;
    o->mUnk_144[0] = 0;
    o->mUnk_1d4 = -1;
    o->mUnk_1d8 = 0;
    o->mUnk_1e4 = 0;
    o->mUnk_1e8 = 0;
    o->mUnk_1e0 = 0;
    func_ov000_021a3668(o->mUnk_1dc);
    o->mUnk_1dc = 0;
    o->mUnk_1dc = 0;
    o->mUnk_1f0 = 0;
    func_ov000_021a3668(o->mUnk_1ec);
    o->mUnk_1ec = 0;
    o->mUnk_1ec = 0;
    o->mUnk_1f4.mUnk_08 = 0;
    o->mUnk_1f4.mUnk_0c = 0;
    o->mUnk_1f4.mUnk_04 = 0;
    func_ov000_021a3668(o->mUnk_1f4.mUnk_00);
    o->mUnk_1f4.mUnk_00 = 0;
    o->mUnk_1f4.mUnk_00 = 0;
    o->mUnk_448 = 0;
    o->mUnk_44c = 0;
    o->mUnk_444 = 0;
    func_ov000_021a3668(o->mUnk_440);
    o->mUnk_440 = 0;
    o->mUnk_440 = 0;
    o->mUnk_458 = 0;
    o->mUnk_45c = 0;
    o->mUnk_454 = 0;
    func_ov000_021a3668(o->mUnk_450);
    o->mUnk_450 = 0;
    o->mUnk_450 = 0;
    o->mUnk_204 = -1;
    o->mUnk_20c = 2;
    n = &o->mUnk_424;
    while (*n != 0) {
        func_ov000_02193818(a, *n);
    }
    o->mUnk_424 = 0;
    o->mUnk_430 = 0;
    func_ov000_02194840(a, func_ov000_0218f7f8, 0);
    o->mUnk_19c = 0;
    o->mUnk_1a0 = 0;
    o->mUnk_198 = 0;
    o->mUnk_210 = 0;
    o->mUnk_41c = 0;
    o->mUnk_434 = 0;
    o->mUnk_214 = -1;
    o->mUnk_218[0] = 0;
    o->mUnk_318[0] = 0;
    return 0;
}

#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_02042044.h"

void func_020d9270(Unk020e0144_00_0 *a, s32 b, s32 c, Vec3 *d, Vec3 *e) {
    s32 f;
    s32 g;
    s32 h;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 m;
    func_020d970c(b, &f, &g, &h, &i, &j, &k, &l, &m);
    func_020d94dc(a->mUnk_00, d, f, g, h, i);
    func_020d94dc(a->mUnk_00, e, j, k, l, m);
    e->x = (s32) (((s64) e->x * c) >> 24);
    e->z = (s32) (((s64) e->z * c) >> 24);
}

void func_020d91dc(Unk020e0144_00_0 *a, s32 b, Vec3 *c) {
    s32 d;
    s32 e;
    s32 f;
    s32 g;
    func_020d9810(b, &d, &e, &f, &g);
    func_020d94dc(a->mUnk_00, c, d, e, f, g);
    c->y = (s32) (((s64) a->mUnk_00[0].y * (0x1000000 - b)) >> 24);
    c->y = c->y + (s32) (((s64) a->mUnk_00[3].y * b) >> 24);
}

void func_020d90a8(Unk020e0144 *a, u16 b, s32 c) {
    Unk020e0144_00 *p;
    u16 d;
    u16 e;
    s32 k;
    p = a->mUnk_00;
    if (p->mUnk_08 != 0) {
        if (b == 0 && c == 0) {
            b = (u16) p->mUnk_04;
        }
    } else if (b == 0 && c == 0) {
        c = 1;
    } else if (b == p->mUnk_04) {
        if (c != 0) {
            c = 0;
        }
    }
    a->mUnk_0c = c != 0 ? b : b - 1;
    k = p->mUnk_00[a->mUnk_0c].mUnk_34;
    a->mUnk_10 = k != 0 ? (s32) (((s64) a->mUnk_04 * k) >> 12) : 0x1000000;
    a->mUnk_14 = c != 0 ? 0 : 0x1000000;
    a->mUnk_18 = c;
    d = b;
    if (a->mUnk_18 == 0 && p->mUnk_08 != 0 && b == p->mUnk_04) {
        d = 0;
    }
    a->mUnk_1c = func_02042044(a->mUnk_08, d);
    e = (u16) (a->mUnk_18 != 0 ? b + 1 : b - 1);
    if (a->mUnk_18 != 0 && p->mUnk_08 != 0 && e == p->mUnk_04) {
        e = 0;
    }
    a->mUnk_20 = func_02042044(a->mUnk_08, e);
}

s32 func_020d8cc8(Unk020e0144 *a) {
    Unk020e0144_00 *p;
    s32 k;
    s32 r;
    p = a->mUnk_00;
    if (a->mUnk_18 != 0) {
        a->mUnk_14 = a->mUnk_14 + a->mUnk_10;
        if (a->mUnk_14 >= 0x1000000) {
            if (a->mUnk_0c == p->mUnk_04 - 1) {
                if (p->mUnk_08 != 0) {
                    a->mUnk_14 -= 0x1000000;
                    a->mUnk_14 = (s32) (((s64) a->mUnk_14 * p->mUnk_00[a->mUnk_0c].mUnk_30) >> 12);
                    a->mUnk_0c = 0;
                    a->mUnk_1c = a->mUnk_20;
                    a->mUnk_20 = func_02042044(a->mUnk_08, 1);
                    k = p->mUnk_00[a->mUnk_0c].mUnk_34;
                    if (k != 0) {
                        a->mUnk_14 = (s32) (((s64) a->mUnk_14 * k) >> 24);
                    }
                    a->mUnk_10 = k != 0 ? (s32) (((s64) a->mUnk_04 * k) >> 12) : 0x1000000;
                } else {
                    a->mUnk_18 = 0;
                    a->mUnk_14 = 0x1000000;
                    a->mUnk_1c = a->mUnk_20;
                    a->mUnk_20 = func_02042044(a->mUnk_08, (u16) a->mUnk_0c);
                }
            } else {
                a->mUnk_14 -= 0x1000000;
                a->mUnk_14 = (s32) (((s64) a->mUnk_14 * p->mUnk_00[a->mUnk_0c].mUnk_30) >> 12);
                a->mUnk_0c = a->mUnk_0c + 1;
                a->mUnk_1c = a->mUnk_20;
                if (a->mUnk_0c == p->mUnk_04 - 1 && p->mUnk_08 != 0) {
                    a->mUnk_20 = func_02042044(a->mUnk_08, 0);
                } else {
                    a->mUnk_20 = func_02042044(a->mUnk_08, (u16) (a->mUnk_0c + 1));
                }
                k = p->mUnk_00[a->mUnk_0c].mUnk_34;
                if (k != 0) {
                    a->mUnk_14 = (s32) (((s64) a->mUnk_14 * k) >> 24);
                }
                a->mUnk_10 = k != 0 ? (s32) (((s64) a->mUnk_04 * k) >> 12) : 0x1000000;
            }
            return 1;
        }
    } else {
        a->mUnk_14 = a->mUnk_14 - a->mUnk_10;
        if (a->mUnk_14 <= 0) {
            r = a->mUnk_0c;
            if (r == 0) {
                if (p->mUnk_08 != 0) {
                    a->mUnk_14 = (s32) (((s64) a->mUnk_14 * p->mUnk_00[r].mUnk_30) >> 12);
                    a->mUnk_0c = p->mUnk_04 - 1;
                    a->mUnk_1c = a->mUnk_20;
                    a->mUnk_20 = func_02042044(a->mUnk_08, (u16) (p->mUnk_04 - 1));
                    k = p->mUnk_00[a->mUnk_0c].mUnk_34;
                    if (k != 0) {
                        a->mUnk_14 = (s32) (((s64) a->mUnk_14 * k) >> 24);
                    }
                    a->mUnk_14 = a->mUnk_14 + 0x1000000;
                    a->mUnk_10 = k != 0 ? (s32) (((s64) a->mUnk_04 * k) >> 12) : 0x1000000;
                } else {
                    a->mUnk_18 = 1;
                    a->mUnk_14 = 0;
                    a->mUnk_1c = a->mUnk_20;
                    a->mUnk_20 = func_02042044(a->mUnk_08, 1);
                }
            } else {
                a->mUnk_14 = (s32) (((s64) a->mUnk_14 * p->mUnk_00[r].mUnk_30) >> 12);
                a->mUnk_0c = a->mUnk_0c - 1;
                a->mUnk_1c = a->mUnk_20;
                a->mUnk_20 = func_02042044(a->mUnk_08, (u16) a->mUnk_0c);
                k = p->mUnk_00[a->mUnk_0c].mUnk_34;
                if (k != 0) {
                    a->mUnk_14 = (s32) (((s64) a->mUnk_14 * k) >> 24);
                }
                a->mUnk_14 = a->mUnk_14 + 0x1000000;
                a->mUnk_10 = k != 0 ? (s32) (((s64) a->mUnk_04 * k) >> 12) : 0x1000000;
            }
            return 1;
        }
    }
    return 0;
}

s32 func_020d8cac(Unk020e0144 *a) {
    s32 b;
    if (a->mUnk_18 != 0) {
        b = a->mUnk_14;
    } else {
        b = 0x1000000 - a->mUnk_14;
    }
    return b >> 12;
}

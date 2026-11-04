#include "Main/Unknown/code_020f73fc.h"

#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f5d6c.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f73a4.h"
#include "Main/Unknown/code_020f7c60.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "code_02147cd8.h"

void func_020f77f8(void *a, s32 b, Vec3 *c, Vec3 *d, MapObject *e) {
    Unk020f41c4_A *p = a;
    Vec3 v;
    Vec3 v2;
    Vec3 w;
    s32 i;
    s32 n;
    s32 m;
    void (*cb)(Unk020f41c4_A *, s32);

    if (p->mUnk_74 & 0x80000) {
        return;
    }
    i = e ? e->mKindData->mUnk_28 : -1;
    switch (b) {
        case 1:
            if (p->mUnk_74 & 0x1000) {
                break;
            }
            Vec3Sub(&p->mUnk_0e4, c, &v);
            if (!(p->mUnk_74 & 0x8000) && (p->mUnk_74 & 0x1000000)) {
                func_020f7c90(p, c, &v);
                break;
            }
            p->mUnk_74 |= 0x4000000;
            if (func_02039828(&p->mUnk_5c, &v) <= 0) {
                if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
                    func_02039860(&v, &v);
                }
                p->mUnk_124(p, d, &v);
                if (p->mUnk_74 & 0x8000) {
                    break;
                }
                m = p->mUnk_e0;
                if ((s64) (c->x - p->mUnk_50.x) * (c->x - p->mUnk_50.x) +
                        (s64) (c->y - p->mUnk_50.y) * (c->y - p->mUnk_50.y) +
                        (s64) (c->z - p->mUnk_50.z) * (c->z - p->mUnk_50.z) >=
                    (s64) m * m) {
                    break;
                }
                p->mUnk_50.x = c->x + (s32) (((s64) m * v.x) >> 12);
                p->mUnk_50.z = c->z + (s32) (((s64) m * v.z) >> 12);
                break;
            }
            if (p->mUnk_74 & 0x8000) {
                break;
            }
            m = p->mUnk_e0;
            if ((s64) (c->x - p->mUnk_50.x) * (c->x - p->mUnk_50.x) +
                    (s64) (c->y - p->mUnk_50.y) * (c->y - p->mUnk_50.y) +
                    (s64) (c->z - p->mUnk_50.z) * (c->z - p->mUnk_50.z) >=
                (s64) m * m) {
                break;
            }
            if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
                func_02039860(&v, &v);
            }
            m = p->mUnk_e0;
            p->mUnk_50.x = c->x + (s32) (((s64) m * v.x) >> 12);
            p->mUnk_50.z = c->z + (s32) (((s64) m * v.z) >> 12);
            break;
        case 2:
            if (p->mUnk_74 & 0x1000) {
                func_020eda5c(&(data_027e00c8)[(u16) (p->mUnk_78 & ~0xff00)].mUnk_058, p);
            }
            n = 0;
            if ((s64) d->x * d->x + (s64) d->y * d->y + (s64) d->z * d->z >= 0x10) {
                n = func_02039860(d, &v2);
            }
            if (n != 0) {
                func_020f6be8(p, c, d, &v2);
            } else {
                Vec3Sub(&p->mUnk_50, c, &v2);
                if (v2.y < 0) {
                    v2.y = 0;
                }
                if ((s64) v2.x * v2.x + (s64) v2.y * v2.y + (s64) v2.z * v2.z >= 0x10) {
                    func_02039860(&v2, &v2);
                }
                w.x = (s32) (((s64) v2.x * 0x1800) >> 12);
                w.y = (s32) (((s64) v2.y * 0x1800) >> 12);
                w.z = (s32) (((s64) v2.z * 0x1800) >> 12);
                func_020f6be8(p, c, &w, &v2);
            }
            if (i == -1 || (p->mUnk_74 & 0x8000000)) {
                func_020f6fc4(p, 1);
            } else {
                n = p->mUnk_44;
                func_020f7104(p, 1);
                if (n == 5 || n == 9) {
                    i = -1;
                }
            }
    }
    if (i == -1) {
        return;
    }
    cb = (p->mUnk_74 & 0x400000) ? (void (*)(Unk020f41c4_A *, s32)) func_020f7c60
                                 : (void (*)(Unk020f41c4_A *, s32)) func_020f91fc;
    cb(p, i);
}

void func_020f7658(Unk020f41c4_A *b, s32 c) {
    BOOL a;
    enum { K0 } k;

    if (!(b->mUnk_74 & 0x8000000)) {
        if ((b->mUnk_74 & 0x8000000) && !(b->mUnk_74 & 0x10000000) && !(b->mUnk_74 & 0x20000000)) {
            if (b->mUnk_78 & 0xf00) {
                return;
            }
            b->mUnk_78 |= data_02159b74;
            b->mUnk_120 = NULL;
            return;
        }
        if (b->mUnk_74 & 0x180000) {
            return;
        }
        k = b->mUnk_44;
        if (data_0217bc34[k].mUnk_40 == 0 && !(b->mUnk_74 & 0x180000)) {
            b->mUnk_120 = func_020f758c;
        }
        b->mUnk_74 |= 0x100002;
        return;
    }
    if ((b->mUnk_74 & 0x8000000) && !(b->mUnk_74 & 0x10000000) && !(b->mUnk_74 & 0x20000000)) {
        if (b->mUnk_78 & 0xf00) {
            a = FALSE;
        } else {
            b->mUnk_78 |= data_02159b74;
            b->mUnk_120 = NULL;
            a = TRUE;
        }
    } else {
        if (b->mUnk_74 & 0x180000) {
            a = FALSE;
        } else {
            k = b->mUnk_44;
            if (data_0217bc34[k].mUnk_40 == 0 && !(b->mUnk_74 & 0x180000)) {
                b->mUnk_120 = func_020f758c;
            }
            b->mUnk_74 |= 0x100002;
            a = TRUE;
        }
    }
    if (a == FALSE) {
        return;
    }
    if (c == 0) {
        return;
    }
    func_020fe7a0(b->mUnk_44, 4, 8, b->mUnk_4e);
}

void func_020f7600(Unk020f41c4_A *a) {
    enum { K0 } k;

    if (a->mUnk_74 & 0x180000) {
        return;
    }
    k = a->mUnk_44;
    if (data_0217bc34[k].mUnk_40 == 0 && !(a->mUnk_74 & 0x180000)) {
        a->mUnk_120 = func_020f758c;
    }
    a->mUnk_74 |= 0x100002;
}

void func_020f758c(Unk020f41c4_A *a) {
    if (a->mUnk_74 & 0x8000) {
        func_020f68b0(a);
    }
    a->mUnk_d8--;
    if (a->mUnk_d8 <= 0) {
        func_020f0f70(&data_027e00cc[a->mUnk_44], a);
    } else {
        if (a->mUnk_d8 < 0xa) {
            func_020f9c40((s32) a);
        }
    }
}

void func_020f7430(Unk020f41c4_A *b, s32 c) {
    BOOL a;

    if (!(b->mUnk_74 & 0x8000000)) {
        if ((b->mUnk_74 & 0x8000000) && !(b->mUnk_74 & 0x10000000) && !(b->mUnk_74 & 0x20000000)) {
            if (b->mUnk_78 & 0xf00) {
                return;
            }
            b->mUnk_78 |= data_02159b70;
            b->mUnk_120 = NULL;
            return;
        }
        if (b->mUnk_74 & 0x180000) {
            return;
        }
        if (!(b->mUnk_74 & 0x180000)) {
            b->mUnk_120 = (void (*)(Unk020f41c4_A *)) func_020f73d4;
        }
        b->mUnk_74 |= 0x100002;
        return;
    }
    if ((b->mUnk_74 & 0x8000000) && !(b->mUnk_74 & 0x10000000) && !(b->mUnk_74 & 0x20000000)) {
        if (b->mUnk_78 & 0xf00) {
            a = FALSE;
        } else {
            b->mUnk_78 |= data_02159b70;
            b->mUnk_120 = NULL;
            a = TRUE;
        }
    } else {
        if (b->mUnk_74 & 0x180000) {
            a = FALSE;
        } else {
            if (!(b->mUnk_74 & 0x180000)) {
                b->mUnk_120 = (void (*)(Unk020f41c4_A *)) func_020f73d4;
            }
            b->mUnk_74 |= 0x100002;
            a = TRUE;
        }
    }
    if (a == FALSE) {
        return;
    }
    if (c == 0) {
        return;
    }
    func_020fe7a0(b->mUnk_44, 5, 8, b->mUnk_4e);
}

void func_020f73fc(Unk020f41c4_A *a) {
    if (a->mUnk_74 & 0x180000) {
        return;
    }
    if (!(a->mUnk_74 & 0x180000)) {
        a->mUnk_120 = (void (*)(Unk020f41c4_A *)) func_020f73d4;
    }
    a->mUnk_74 |= 0x100002;
}

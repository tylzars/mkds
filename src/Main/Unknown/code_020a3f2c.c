#include "Main/Unknown/code_020a3f2c.h"

#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020a3fa8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020a10d4.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2220.h"
#include "Main/Unknown/code_020a2204.h"
#include "Main/Unknown/code_020a2e4c.h"
#include "Main/Unknown/code_020a2e74.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020a2000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02074854.h"

void func_020a3fa8(void *b, Unk020a3fa8 *c) {
    Unk020a2fe4 *o;
    s32 i;
    s32 j;
    s32 n;
    s32 m;
    s32 a;
    s32 s;
    s32 d;
    Vec3 v;
    Vec3 t;
    Vec3 t2;
    Vec3 *q;

    n = data_021759c0->mUnk_3d0;
    if (c->mUnk_0a0 > 0) {
        c->mUnk_0a0--;
        if (c->mUnk_0a0 > 0) {
            return;
        }
        for (i = 0; i < n; i++) {
            Unk020a3fa8_a4 *e = &c->mUnk_0a4[i];
            func_0207a974((u16) i);
            e->mUnk_34 = 1;
            if (c->mUnk_000.mUnk_9c->mUnk_28 != 0 || c->mUnk_000.mUnk_9c->mUnk_2a != 0) {
                e->mUnk_04 = c->mUnk_000.mUnk_9c->mUnk_28;
                func_020a10ac(i, c->mUnk_000.mUnk_9c->mUnk_28 + c->mUnk_000.mUnk_9c->mUnk_2a);
            } else {
                e->mUnk_04 = 1;
                func_020a10ac(i, 5);
            }
        }
        return;
    }
    for (i = 0; i < n; i++) {
        Unk0206bcb0 *p;
        Unk020a3fa8_a4 *e = &c->mUnk_0a4[i];
        func_020748a8();
        p = func_0207a974((u16) i);
        v.x = p->mUnk_80.x;
        v.y = p->mUnk_80.y + func_020a23a0(p) - 0xf666;
        v.z = p->mUnk_80.z;
        switch (e->mUnk_34) {
            case 0:
                if (e->mUnk_00 > 0) {
                    e->mUnk_00--;
                    break;
                }
                if (func_020a10d4(i) == 0) {
                    break;
                }
                if (func_020a1154(i) >= 3) {
                    break;
                }
                if (func_020a2264(i) <= 0 && func_020a223c(i) <= 0) {
                    break;
                }
                o = func_020a2fe4(e->mUnk_30, &v);
                if (o == NULL) {
                    break;
                }
                e->mUnk_10[func_020a1154(i)] = o;
                func_020a2f9c(o, i, 0xcd);
                e->mUnk_34 = 2;
                func_020a2220(i, 1);
                func_020a10ac(i, -1);
                break;
            case 1:
                if (func_020a2204(i) != 0) {
                    func_020a2f9c(e->mUnk_10[func_020a1154(i)], i, 0x266);
                    break;
                }
                if (func_020a10d4(i) != 0 && func_020a1154(i) < 3) {
                    if (e->mUnk_04 > 0) {
                        o = func_020a2fe4(e->mUnk_30, &v);
                        if (o != NULL) {
                            e->mUnk_10[func_020a1154(i)] = o;
                            func_020a2f9c(o, i, 0x266);
                            func_020a2220(i, 1);
                            func_020a10ac(i, -1);
                            e->mUnk_04--;
                        }
                    }
                } else {
                    e->mUnk_34 = 0;
                }
                break;
            case 2:
                if (func_020a2264(i) < 0) {
                    e->mUnk_34 = 4;
                    break;
                }
                o = e->mUnk_10[func_020a1154(i)];
                func_020a2f9c(o, i, 0xcd);
                if (func_020a2e60(o) >= 0x800) {
                    e->mUnk_34 = 3;
                }
                break;
            case 3:
                if (func_020a2264(i) < 0) {
                    e->mUnk_34 = 4;
                    break;
                }
                if (func_020a223c(i) > 0) {
                    func_020a2f9c(e->mUnk_10[func_020a1154(i)], i, 0x10);
                } else if (func_020a2264(i) > 0) {
                    func_020a2f9c(e->mUnk_10[func_020a1154(i)], i, 0x29);
                } else {
                    o = e->mUnk_10[func_020a1154(i)];
                    func_020a2f30(o, i, 0xe);
                    if (func_020a2e60(o) <= 0x400) {
                        e->mUnk_34 = 4;
                    }
                }
                break;
            case 4:
                func_020a2f30(e->mUnk_10[func_020a1154(i)], i, 0x19a);
                break;
        }
        if (func_020a2204(i) != 0) {
            o = e->mUnk_10[func_020a1154(i)];
            if (func_020a2e60(o) <= 0) {
                e->mUnk_10[func_020a1154(i)] = NULL;
                func_020a2220(i, 0);
                func_020a10ac(i, 1);
                e->mUnk_00 = 0;
                e->mUnk_34 = 0;
            } else if (func_020a2e60(o) >= 0x1000) {
                func_020a2220(i, 0);
                func_020a10f0(i, 1);
                if (e->mUnk_04 <= 0) {
                    e->mUnk_00 = 30;
                    e->mUnk_34 = 0;
                }
                func_020d26ec(func_0207a974((u16) i), 0x152);
            }
        } else if (e->mUnk_04 <= 0) {
            e->mUnk_34 = 0;
        }
        if (i == data_021759c0->mUnk_62) {
            if (func_020a2264(i) > 0 || func_020a223c(i) > 0) {
                s = func_020a1154(i) >= 3 ? 600 : 300;
                d = func_020a1154(i) >= 3 ? 200 : 100;
                e->mUnk_08 += e->mUnk_0c;
                if (e->mUnk_08 >= 0) {
                    if (e->mUnk_0c < 0) {
                        e->mUnk_0c = -s;
                    } else {
                        e->mUnk_0c -= d;
                    }
                } else {
                    if (e->mUnk_0c >= 0) {
                        e->mUnk_0c = s;
                    } else {
                        e->mUnk_0c += d;
                    }
                }
            } else {
                s = func_020a1154(i) >= 3 ? 600 : 300;
                if (e->mUnk_08 >= 0) {
                    e->mUnk_08 = e->mUnk_08 < s ? 0 : e->mUnk_08 - s;
                } else {
                    e->mUnk_08 = e->mUnk_08 > -s ? 0 : e->mUnk_08 + s;
                }
            }
            m = func_020a1154(i) + (func_020a2204(i) != 0 ? 1 : 0);
            for (j = 0; j < m; j++) {
                Unk020a2fe4 *o = e->mUnk_10[j];
                a = e->mUnk_08 + c->mUnk_264[m - 1][j];
                if (a != 0) {
                    q = &p->mUnk_150;
                    t.x = (s32) (((s64) q->x * a) >> 12);
                    t.y = (s32) (((s64) q->y * a) >> 12);
                    t.z = (s32) (((s64) q->z * a) >> 12);
                    func_020a2e74(o, &t);
                }
                if ((j & 1) == 1) {
                    q = &p->mUnk_168;
                    t2.x = (s32) (((s64) q->x * -0xcd) >> 12);
                    t2.y = (s32) (((s64) q->y * -0xcd) >> 12);
                    t2.z = (s32) (((s64) q->z * -0xcd) >> 12);
                    func_020a2e74(o, &t2);
                }
                func_020a2e88(o, &v, &p->mUnk_a4);
                func_020a2e58(o, i);
                func_020a2e4c(o, 1, NULL);
                o->mUnk_00.mUnk_02 &= ~4;
                o->mUnk_00.mUnk_02 &= ~2;
                o->mUnk_00.mUnk_02 &= ~8;
                o->mUnk_00.mUnk_66 = 0x1f;
            }
        } else {
            m = func_020a1154(i) + (func_020a2204(i) != 0 ? 1 : 0);
            for (j = 0; j < m; j++) {
                o = e->mUnk_10[j];
                func_020a2e88(o, &v, &p->mUnk_a4);
                func_020a2e58(o, i);
                if (j == 0) {
                    func_020a2e4c(o, m, e->mUnk_10);
                    o->mUnk_00.mUnk_02 &= ~4;
                    o->mUnk_00.mUnk_02 &= ~2;
                    o->mUnk_00.mUnk_02 &= ~8;
                    o->mUnk_00.mUnk_66 = 0x1f;
                } else {
                    func_020a2e4c(o, 0, NULL);
                    o->mUnk_00.mUnk_02 |= data_02156794;
                    o->mUnk_00.mUnk_02 |= data_02156798;
                    o->mUnk_00.mUnk_02 |= data_0215679c;
                }
            }
        }
    }
}

u32 func_020a3f48(void) {
    Unk021759c0 *d;
    s32 k;

    d = data_021759c0;
    k = d->mUnk_08;
    if (k == 2 && d->mUnk_18 == 0) {
        return func_0209bf8c();
    }
    if (k != 4) {
        return 0;
    }
    return func_0209bf8c();
}

u32 func_020a3f2c(void) {
    return func_0209bf48(NULL, func_020a3fa8, NULL);
}

#include "Main/Unknown/code_020a2f30.h"
#include "Main/Unknown/code_020a36a8.h"
#include "Main/Unknown/code_020a3690.h"
#include "Main/Unknown/code_020a392c.h"
#include "Main/Unknown/code_020a3948.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02100094.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_02061fec.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02147cd8.h"
#include "code_02148538.h"

void func_020a2f30(Unk020a2fe4 *a, u16 b, s32 c) {
    a->mUnk_a4 = b;
    a->mUnk_d4 = -c;
    a->mUnk_d0 = a->mUnk_d0 + a->mUnk_d4;
    a->mUnk_fc = 0;
    if (a->mUnk_d0 > 0) {
        return;
    }
    a->mUnk_d8 = 0;
    a->mUnk_d0 = 0;
    a->mUnk_a4 = -1;
    a->mUnk_f4 = 1;
    a->mUnk_f8 = 0;
    func_020d2398(&a->mUnk_00);
}

void func_020a2f9c(Unk020a2fe4 *a, u16 b, s32 c) {
    a->mUnk_a4 = b;
    a->mUnk_d4 = c;
    a->mUnk_d0 = a->mUnk_d0 + a->mUnk_d4;
    a->mUnk_d8 = 0;
    a->mUnk_dc = 0;
    a->mUnk_fc = 0;
    if (a->mUnk_d0 >= 0x1000) {
        a->mUnk_d8 = 0;
        a->mUnk_d4 = 0x258;
        a->mUnk_fc = 1;
    }
}

Unk020a2fe4 *func_020a2fe4(u16 a, Vec3 *b) {
    Unk020a2fe4 *o;

    o = func_0209bbfc(func_02100138(0x6c));
    if (o == 0) {
        return 0;
    }
    o->mUnk_b0 = *b;
    o->mUnk_00.mUnk_04 = o->mUnk_b0;
    o->mUnk_d0 = 0;
    o->mUnk_d4 = 0;
    o->mUnk_d8 = 0;
    o->mUnk_dc = 0;
    o->mUnk_e0 = 0;
    o->mUnk_a8 = a;
    o->mUnk_fc = 0;
    return o;
}

void func_020a305c(void) {
    s32 i;
    Unk02100094 *v1;
    Unk020a2fe4 *e;

    v1 = func_02100138(0x6c);
    if (v1 == 0) {
        return;
    }
    for (i = 0; i < v1->mUnk_04 && (e = v1->mUnk_00[i]) != 0; i++) {
        if (e->mUnk_a4 >= 0) {
            e->mUnk_a4 = (u16) data_021759c0->mUnk_62;
            e->mUnk_d0 = 0x1000;
            e->mUnk_d4 = 0;
            e->mUnk_d8 = 0;
            e->mUnk_dc = 0;
            e->mUnk_fc = 2;
        } else if ((e->mUnk_00.mUnk_02 & 0x100) == 0) {
            func_020d2398(&e->mUnk_00);
        }
    }
}

u32 func_020a3114(void) {
    return func_0209bf48(0, func_020a3154, 0);
}

u32 func_020a3130(void) {
    return func_0209bef0(func_020a3eb8, func_020a3948, func_020a3e38);
}

void func_020a3154(void *p, Unk020a2fe4 *a) {
    Unk0206bcb0 *o;

    if (a->mUnk_a4 >= 0) {
        switch (a->mUnk_fc) {
            case 0:
                a->mUnk_d8 = a->mUnk_d8 + a->mUnk_dc;
                if (a->mUnk_d8 >= 0) {
                    if (a->mUnk_dc < 0) {
                        a->mUnk_dc = -50;
                    } else {
                        a->mUnk_dc = a->mUnk_dc - 10;
                    }
                } else {
                    if (a->mUnk_dc >= 0) {
                        a->mUnk_dc = 50;
                    } else {
                        a->mUnk_dc = a->mUnk_dc + 10;
                    }
                }
                if (a->mUnk_a4 == data_021759c0->mUnk_62) {
                    if (func_02061fec() == 1) {
                        o = func_0207a974((u16) a->mUnk_a4);
                        func_020249b8(o, a->mUnk_d0 + a->mUnk_d8, a->mUnk_d4);
                    }
                }
                if (a->mUnk_f4 == 1 && a->mUnk_f8 == 0) {
                    func_020a36a8(a);
                    if (func_020a369c(a) != 0) {
                        return;
                    }
                    if (func_020a3690(a) >= 0x9c40) {
                        return;
                    }
                    func_020a35b0(a);
                } else {
                    a->mUnk_00.mUnk_04.x = a->mUnk_b0.x;
                    a->mUnk_00.mUnk_04.y = a->mUnk_b0.y + 0xf666;
                    a->mUnk_00.mUnk_04.z = a->mUnk_b0.z;
                }
                break;
            case 1:
                a->mUnk_d8 = 0;
                a->mUnk_d0 = a->mUnk_d0 + a->mUnk_d4;
                if (a->mUnk_d0 >= 0x1000) {
                    a->mUnk_d4 = a->mUnk_d4 - 200;
                }
                if (a->mUnk_d4 < 0) {
                    if (a->mUnk_d0 <= 0x1000) {
                        a->mUnk_d0 = 0x1000;
                        a->mUnk_fc = 2;
                    }
                }
                if (a->mUnk_f4 == 1 && a->mUnk_f8 == 0) {
                    func_020a36a8(a);
                    if (func_020a369c(a) != 0) {
                        return;
                    }
                    if (func_020a3690(a) >= 0x9c40) {
                        return;
                    }
                    func_020a35b0(a);
                } else {
                    a->mUnk_00.mUnk_04.x = a->mUnk_b0.x;
                    a->mUnk_00.mUnk_04.y = a->mUnk_b0.y + 0xf666;
                    a->mUnk_00.mUnk_04.z = a->mUnk_b0.z;
                }
                break;
            case 2:
                a->mUnk_d8 = 0;
                a->mUnk_d0 = 0x1000;
                if (a->mUnk_f4 == 1 && a->mUnk_f8 == 0) {
                    func_020a36a8(a);
                    if (func_020a369c(a) != 0) {
                        return;
                    }
                    if (func_020a3690(a) >= 0x9c40) {
                        return;
                    }
                    func_020a35b0(a);
                } else {
                    a->mUnk_00.mUnk_04.x = a->mUnk_b0.x;
                    a->mUnk_00.mUnk_04.y = a->mUnk_b0.y + 0xf666;
                    a->mUnk_00.mUnk_04.z = a->mUnk_b0.z;
                }
                break;
            default:
                return;
        }
    } else {
        a->mUnk_d8 = 0;
        a->mUnk_d0 = 0x1000;
        if (a->mUnk_a0-- <= 0) {
            func_0208b748(0x5b, &a->mUnk_00.mUnk_04, a, func_020a392c);
            func_0208b748(0x5c, &a->mUnk_00.mUnk_04, a, func_020a392c);
            func_0208b748(0x5d, &a->mUnk_00.mUnk_04, a, func_020a392c);
            func_0210b8f4(&a->mUnk_00.mUnk_04, func_020d4ef4(&a->mUnk_00.mUnk_04));
            func_020d2398(&a->mUnk_00);
        } else {
            a->mUnk_c8 = a->mUnk_c8 + a->mUnk_cc;
            if (a->mUnk_c8 >= 0) {
                if (a->mUnk_cc < 0) {
                    a->mUnk_cc = -0x640;
                } else {
                    a->mUnk_cc = a->mUnk_cc - 200;
                }
            } else {
                if (a->mUnk_cc >= 0) {
                    a->mUnk_cc = 0x640;
                } else {
                    a->mUnk_cc = a->mUnk_cc + 200;
                }
            }
        }
        a->mUnk_00.mUnk_7e = a->mUnk_c8 + 0x4000;
        a->mUnk_00.mUnk_10.y = a->mUnk_00.mUnk_10.y + 0x59a;
        a->mUnk_bc.y = a->mUnk_bc.y - 0x2000;
        a->mUnk_00.mUnk_10.x = (s32) (((s64) a->mUnk_00.mUnk_10.x * 0xc00) >> 12);
        a->mUnk_00.mUnk_10.y = (s32) (((s64) a->mUnk_00.mUnk_10.y * 0xc00) >> 12);
        a->mUnk_00.mUnk_10.z = (s32) (((s64) a->mUnk_00.mUnk_10.z * 0xc00) >> 12);
        func_02148504(&a->mUnk_00.mUnk_04, &a->mUnk_00.mUnk_10, &a->mUnk_00.mUnk_04);
        func_02148504(&a->mUnk_b0, &a->mUnk_bc, &a->mUnk_b0);
    }
}

void func_020a35b0(Unk020a2fe4 *a) {
    Unk02061808 *g;
    Vec3 v;
    u16 v1;
    s32 i;
    s32 s;
    s32 c;
    s32 x;
    s32 y;
    s32 u;
    s32 w;

    g = func_02061808();
    v1 = func_02148714(g->mUnk_15c.x, g->mUnk_15c.z) - 0x4000;
    func_021484d0(&a->mUnk_00.mUnk_04, &g->mUnk_024, &v);
    i = (v1 >> 4) * 2;
    s = data_0215d4b4[i];
    c = data_0215d4b4[i + 1];
    x = (s32) (((s64) v.z * c) >> 12);
    y = (s32) (((s64) v.x * s) >> 12);
    u = v.y;
    func_021484d0(&a->mUnk_b0, &g->mUnk_024, &v);
    w = (s32) (((s64) v.x * s) >> 12) + (s32) (((s64) v.z * c) >> 12);
    a->mUnk_00.mUnk_7e = func_02148714(u - v.y, -(y + x - w));
}

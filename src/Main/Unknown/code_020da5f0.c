#include "Main/Unknown/code_020da5f0.h"

#include "Main/Unknown/code_020da628.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020ebef8.h"
#include "Main/Unknown/code_020f5d6c.h"
#include "Main/Unknown/code_020f8ddc.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020dab98.h"
#include "Main/Unknown/code_020dab9c.h"
#include "Main/Unknown/code_020dabfc.h"
#include "Main/Unknown/code_020dac00.h"
#include "Main/Unknown/code_020dac58.h"
#include "Main/Unknown/code_020dac74.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020dade8.h"
#include "Main/Unknown/code_020dadfc.h"
#include "Main/Unknown/code_020d8c74.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020daf0c.h"

void func_020daf0c(Unk020daf0c *p0) {
    p0->mUnk_c4 = 0x1000u;
    p0->mUnk_c8 = 0x0u;
}

void func_020dadfc(Unk020da494 *p) {
    if (p->mUnk_f0 >= 0xa && (p->mUnk_f0 < 0x14 || p->mUnk_f0 >= 0x1e)) {
        func_020d8cc8(&p->mUnk_cc);
    }
    func_020d8c74(&p->mUnk_cc, &p->mUnk_00.mUnk_04);
    if (p->mUnk_c4 == 0x1000 && p->mUnk_c8 == 0) {
        return;
    }
    p->mUnk_c8 += (s32) (((s64) (0x1000 - p->mUnk_c4) * 0x200) >> 12);
    p->mUnk_c8 = (s32) (((s64) p->mUnk_c8 * 0xd99) >> 12);
    p->mUnk_c4 += p->mUnk_c8;
    if (p->mUnk_c4 > 0xfd7 && p->mUnk_c4 < 0x1029 && p->mUnk_c8 > -0x29 && p->mUnk_c8 < 0x29) {
        p->mUnk_c4 = 0x1000;
        p->mUnk_c8 = 0;
    }
}

void func_020dade8(Unk020dade8 *p0) {
    p0->mUnk_c4 = 0x1000u;
    p0->mUnk_c8 = 0x0u;
}

void func_020dac74(Unk020da494 *p) {
    u32 f;
    Vec3 v;
    Vec3 w;
    Vec3 x;
    if (p->mUnk_f0 < 0xa || (p->mUnk_f0 >= 0x14 && p->mUnk_f0 < 0x1e)) {
        if (p->mUnk_f0 == 0 || p->mUnk_f0 == 0x14) {
            p->mUnk_102--;
            if (p->mUnk_102 < 0) {
                p->mUnk_102 = 3;
                p->mUnk_104 = p->mUnk_104 == 0;
            }
        }
    }
    p->mUnk_00.mUnk_10.y -= 0x400;
    p->mUnk_00.mUnk_04.y += p->mUnk_00.mUnk_10.y;
    v = p->mUnk_00.mUnk_04;
    v.y += 0xa000;
    if (func_01ffdee4(&v, 0, 0, 0xa000, 8, -2, &w, &x, 0, &f, 0, 0, 0, 0) != 0) {
        func_02148504(&p->mUnk_00.mUnk_04, &w, &p->mUnk_00.mUnk_04);
        p->mUnk_00.mUnk_10.y = 0;
        if ((f & 0x1e34ef) != 0) {
            func_020d7b88(&x, &p->mUnk_b4);
            p->mUnk_00.mUnk_02 &= ~1;
        }
    }
    func_020d759c(&p->mUnk_a4, &p->mUnk_b4, &p->mUnk_a4, p->mUnk_f8);
    if (p->mUnk_f8 > 0xb4) {
        p->mUnk_f8 = 0xb4;
    }
}

void func_020dac58(Unk020da494 *p0) {
    p0->mUnk_00.mUnk_02 = (u16) (((((u32) p0->mUnk_00.mUnk_02)) | (((u32) data_02158160))));
}

void func_020dac00(Unk020da494 *p) {
    p->mUnk_c4 = (s32) (((s64) p->mUnk_c4 * 0x1266) >> 12);
    if (p->mUnk_c4 > 0x1800) {
        p->mUnk_00.mUnk_80.mUnk_10 = 3;
        p->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}

u32 func_020dabfc(u32 p0) {
    return p0;
}

void func_020dab9c(Unk020da494 *p) {
    p->mUnk_c4 = (s32) (((s64) p->mUnk_c4 * 0xd99) >> 12);
    if (p->mUnk_c4 < 0x333) {
        p->mUnk_00.mUnk_80.mUnk_10 = 4;
        p->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}

u32 func_020dab98(u32 p0) {
    return p0;
}

void func_020dab2c(Unk020da494 *p) {
    if (p->mUnk_fc != 0) {
        if (p->mUnk_00.mUnk_80.mUnk_04 > 0x12c) {
            p->mUnk_00.mUnk_80.mUnk_10 = 5;
            p->mUnk_00.mUnk_80.mUnk_12 = 1;
        }
        return;
    }
    p->mUnk_100--;
    if (p->mUnk_100 == 0) {
        func_020d2398(&p->mUnk_00);
    }
}

void func_020daaa0(Unk020da494 *p) {
    Unk0210b7a8 s;
    s32 a;
    if ((p->mUnk_00.mUnk_78 & 4) == 0) {
        if (p->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
            a = 2;
        } else if (p->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
            a = 3;
        } else {
            a = 4;
        }
        s.mUnk_00 = 0x183;
        s.mUnk_04 = &p->mUnk_00.mUnk_04;
        s.mUnk_08 = a;
        s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mUnk_04);
        func_0210b7a8(&s);
    }
    p->mUnk_00.mUnk_02 &= ~1;
    p->mUnk_c8 = 0;
}

void func_020daa10(Unk020da494 *p) {
    p->mUnk_c8 += (s32) (((s64) (0x1000 - p->mUnk_c4) * 0x200) >> 12);
    p->mUnk_c8 = (s32) (((s64) p->mUnk_c8 * 0xd99) >> 12);
    p->mUnk_c4 += p->mUnk_c8;
    if (p->mUnk_00.mUnk_80.mUnk_04 > 0x3c) {
        p->mUnk_00.mUnk_80.mUnk_10 = 0;
        p->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}

void func_020da820(Unk020da494 *p, Vec3 *a) {
    Vec3 s;
    Unk020f41c4_A *r;
    s32 d;
    if (p->mUnk_00.mUnk_9c == 0 || p->mUnk_00.mUnk_9c->mUnk_2c != 0) {
        return;
    }
    func_021484d0(&p->mUnk_cc.mUnk_1c->mUnk_00, &p->mUnk_cc.mUnk_20->mUnk_00, &s);
    if ((s64) s.x * s.x + (s64) s.y * s.y + (s64) s.z * s.z >= 0x10) {
        func_02039860(&s, &s);
    }
    {
        Vec3 t = {0, 0, 0};
        t.x = a->x;
        t.z = a->z;
        d = func_0214848c(&s, &t);
        s.x = t.x - (s32) (((s64) s.x * d) >> 12);
        s.y = t.y - (s32) (((s64) s.y * d) >> 12);
        s.z = t.z - (s32) (((s64) s.z * d) >> 12);
    }
    if ((s64) s.x * s.x + (s64) s.y * s.y + (s64) s.z * s.z >= 0x10) {
        func_02039860(&s, &s);
    }
    r = func_020fa3d0(3, 8, &p->mUnk_00.mUnk_04, &data_021581f8);
    if (r == 0) {
        return;
    }
    r->mUnk_68.x = 0xcd;
    r->mUnk_68.y = 0xcd;
    r->mUnk_68.z = 0xcd;
    d = func_021482cc(a) + 0x5000;
    r->mUnk_5c.x = (s32) (((s64) s.x * d) >> 12);
    r->mUnk_5c.y = (s32) (((s64) s.y * d) >> 12);
    r->mUnk_5c.z = (s32) (((s64) s.z * d) >> 12);
    r->mUnk_5c.y += 0xf000;
    func_02148504(&r->mUnk_50, &r->mUnk_5c, &r->mUnk_50);
    func_020f6630(r, 0, &p->mUnk_00.mUnk_04, a, &data_021581f8);
}

u32 func_020da73c(Unk020da494 *p, Unk0206bcb0 *a, u8 *b, u8 *c) {
    switch (*b) {
        case 0:
            if (p->mUnk_c4 == 0x1000) {
                if (p->mUnk_c8 == 0) {
                    p->mUnk_c8 = (s32) (((s64) a->mUnk_2a4 * 0x52) >> 12);
                }
            }
            break;
        case 1:
            if (p->mUnk_00.mUnk_80.mUnk_0e == 0 || p->mUnk_00.mUnk_80.mUnk_0e == 5 || p->mUnk_00.mUnk_80.mUnk_0e == 1) {
                p->mUnk_00.mUnk_80.mUnk_10 = 2;
                p->mUnk_00.mUnk_80.mUnk_12 = 1;
                func_020d26ec(&a->mUnk_00, 0x185);
                func_020d26f8(&p->mUnk_00, a);
                func_020da820(p, &a->mUnk_a4);
                p->mUnk_00.mUnk_02 = p->mUnk_00.mUnk_02 | data_02158160;
            }
            break;
    }
    return *c;
}

u32 func_020da684(Unk020da494 *p, Unk0206bcb0 *a, u8 *b, u8 *c) {
    switch (*b) {
        case 0:
            if (p->mUnk_c4 == 0x1000) {
                if (p->mUnk_c8 == 0) {
                    p->mUnk_c8 = 0x19a;
                }
            }
            break;
        case 1:
            if (p->mUnk_00.mUnk_80.mUnk_0e == 0 || p->mUnk_00.mUnk_80.mUnk_0e == 5 || p->mUnk_00.mUnk_80.mUnk_0e == 1) {
                p->mUnk_00.mUnk_80.mUnk_10 = 2;
                p->mUnk_00.mUnk_80.mUnk_12 = 1;
                func_020f8ddc(a);
                if (a != 0) {
                    func_020da820(p, &a->mUnk_05c);
                }
                p->mUnk_00.mUnk_02 = p->mUnk_00.mUnk_02 | data_02158160;
            }
            break;
    }
    return *c;
}

void func_020da628(Unk020da494 *p) {
    p->mUnk_f8 = 0x1000;
    p->mUnk_a4 = data_02158140;
    p->mUnk_b4 = data_02158150;
    func_02046bcc(&p->mUnk_00.mUnk_80, 1);
    p->mUnk_00.mUnk_10.x = 0;
    p->mUnk_00.mUnk_10.y = 0;
    p->mUnk_00.mUnk_10.z = 0;
}

#pragma thumb on

void CreateKuribo(void) {
    u32 v1;
    u32 v2;
    v1 = (u32) FindCourseMapObjFile((const char *) gKuriboNsbmdName);
    v2 = (u32) FindCourseMapObjFile((const char *) gKuriboNsbtpName);
    func_020e6488((Unk020e6488 **) (((u32 *) &gKuribo)), (void *) v1, v2, (u32) 0);
    func_020e6ab8((Unk020e6488 *) gKuribo);
}

#pragma thumb off

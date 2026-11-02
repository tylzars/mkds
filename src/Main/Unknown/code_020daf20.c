#include "Main/Unknown/code_020daf20.h"
#include "Main/Unknown/code_020d8b88.h"
#include "code_02148538.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/code_020dda38.h"
#include "ITCM/code_01ffc000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d8648.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d88fc.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"

#pragma thumb off

static inline s64 func_020dc354_inline(const Vec3 *v) {
    return (s64) v->x * v->x + (s64) v->z * v->z;
}

void func_020dc354(Unk020dc474 *p) {
    p->mUnk_00.mUnk_10.x = p->mUnk_00.mUnk_04.x;
    p->mUnk_00.mUnk_10.z = p->mUnk_00.mUnk_04.z;
    func_020d84e4(&p->mUnk_1a0);
    func_020d8b88(&p->mUnk_1a0.mUnk_00, &p->mUnk_00.mUnk_04);
    p->mUnk_00.mUnk_10.x = p->mUnk_00.mUnk_04.x - p->mUnk_00.mUnk_10.x;
    p->mUnk_00.mUnk_10.z = p->mUnk_00.mUnk_04.z - p->mUnk_00.mUnk_10.z;
    if (func_020dc354_inline(&p->mUnk_00.mUnk_10) >= 0x10) {
        func_020d7b34((u16) ((((s64) func_02148538(p->mUnk_00.mUnk_10.x, p->mUnk_00.mUnk_10.z) * 0x28be60db9391LL) +
                              0x80000000000LL) >>
                             44),
                      &p->mUnk_d4);
    }
    if (p->mUnk_00.mUnk_80.mUnk_04 < 0x40) {
        p->mUnk_ec = p->mUnk_ec + 0x1c;
    }
}

#pragma thumb on
void func_020dc308(void) {
    func_020ea588((void **) &data_0217b6cc, FindCourseMapObjFile("wanwan.nsbmd"), 0);
    func_020ea55c((void **) &data_0217b6d0, FindCourseMapObjFile("rock_shadow.nsbmd"), 0x3f);
    func_02084968(data_0217b6cc, 0x3f, 2, 0x294a);
}
#pragma thumb off

#pragma thumb on
void func_020dc1d8(Unk020dc474 *p, Unk020fa294 *a) {
    p->mUnk_a0 = a->mUnk_00;
    p->mUnk_f0 = (s32) (((s64) p->mUnk_00.mUnk_1c.y * 0x1e000) >> 12);
    p->mUnk_f4 = 0xf000 - p->mUnk_f0;
    p->mUnk_f8 = (a->mUnk_28 * 0x3000) >> 2;
    p->mUnk_1dc = a->mUnk_2a << 12;
    p->mUnk_1ec = a->mUnk_28 << 12;
    p->mUnk_1fc = p->mUnk_f8 - (p->mUnk_f0 << 1);
    p->mUnk_fc = 0;
    p->mUnk_b0 = 0;
    p->mUnk_1d8 = (Unk020dc474_1d8 *) func_020d34d4(&p->mUnk_00, 0x197);
    p->mUnk_ac = p->mUnk_a0.y;
    p->mUnk_a0.y = p->mUnk_a0.y + p->mUnk_f0;
    func_02046be8(&p->mUnk_00.mUnk_80, data_0216befc, 6, p);
    func_02046bcc(&p->mUnk_00.mUnk_80, 0);
    p->mUnk_200 = p->mUnk_00.mUnk_28.mUnk_18;
    func_020dbf7c(p);
    p->mUnk_1fa = func_020d555c(&p->mUnk_00.mUnk_04, p->mUnk_1ec, 0x400, p);
    p->mUnk_00.mUnk_70 = data_0217caec[12];
}
#pragma thumb off

#pragma thumb on
void func_020dc11c(Unk020dc474 *p, Unk020fa294 *a) {
    p->mUnk_a0 = a->mUnk_00;
    p->mUnk_f0 = (s32) (((s64) p->mUnk_00.mUnk_1c.y * 0x1e000) >> 12);
    p->mUnk_f4 = 0xf000 - p->mUnk_f0;
    p->mUnk_fc = 1;
    p->mUnk_b0 = a->mUnk_2a;
    p->mUnk_ac = p->mUnk_a0.y;
    p->mUnk_a0.y = p->mUnk_a0.y + p->mUnk_f0;
    func_02046be8(&p->mUnk_00.mUnk_80, data_0216befc, 6, p);
    func_02046bcc(&p->mUnk_00.mUnk_80, 5);
    func_020d7d4c(&p->mUnk_1a0, a, data_02158908, a->mUnk_28);
    func_020dbf7c(p);
}
#pragma thumb off

#pragma thumb on
void func_020dbf7c(Unk020dc474 *p) {
    p->mUnk_00.mUnk_04 = p->mUnk_a0;
    p->mUnk_00.mUnk_10.x = 0;
    p->mUnk_00.mUnk_10.y = 0;
    p->mUnk_00.mUnk_10.z = 0;
    p->mUnk_c4 = data_0216beec;
    func_020d7b34((u16) ((((s64) func_02148538(p->mUnk_00.mUnk_10.x, p->mUnk_00.mUnk_10.z) * 0x28be60db9391LL) +
                          0x80000000000LL) >>
                         44),
                  &p->mUnk_d4);
    func_020d7938(&p->mUnk_c4, &p->mUnk_d4, &p->mUnk_b4);
    func_01ffccd0(&p->mUnk_00.mUnk_28, &p->mUnk_b4);
    p->mUnk_e4 = 0;
    if (p->mUnk_fc == 0) {
        func_020de184((Unk020de000 *) p->mUnk_1d8);
    }
    if (p->mUnk_fc == 0) {
        p->mUnk_160[0] = &p->mUnk_170[0];
        p->mUnk_160[1] = &p->mUnk_170[1];
        p->mUnk_160[2] = &p->mUnk_170[2];
        p->mUnk_160[3] = &p->mUnk_170[3];
        if (data_021759c0->mUnk_00c == 3) {
            func_02147fd8(0xf000, &p->mUnk_200, &p->mUnk_00.mUnk_04, &p->mUnk_00.mUnk_04);
            p->mUnk_00.mUnk_10.x = (s32) (((s64) p->mUnk_200.x * 0x400) >> 12);
            p->mUnk_00.mUnk_10.y = (s32) (((s64) p->mUnk_200.y * 0x400) >> 12);
            p->mUnk_00.mUnk_10.z = (s32) (((s64) p->mUnk_200.z * 0x400) >> 12);
            func_020d7b34((u16) ((((s64) func_02148538(p->mUnk_00.mUnk_10.x, p->mUnk_00.mUnk_10.z) * 0x28be60db9391LL) +
                                  0x80000000000LL) >>
                                 44),
                          &p->mUnk_d4);
            p->mUnk_00.mUnk_80.mUnk_10 = 4;
            p->mUnk_00.mUnk_80.mUnk_12 = 1;
        } else {
            p->mUnk_00.mUnk_80.mUnk_10 = 0;
            p->mUnk_00.mUnk_80.mUnk_12 = 1;
        }
    }
}
#pragma thumb off

Unk020dbf2c *func_020dbf2c(void) {
    Unk020dbf2c *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    *p = data_0215828c;
    return p;
}

Unk020dbed0 *func_020dbed0(void) {
    Unk020dbed0 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    data_0217b698 = p;
    *p = data_02158260;
    func_020d49d8(&data_0217b698);
    return data_0217b698;
}

Unk020dbe74 *func_020dbe74(void) {
    Unk020dbe74 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x28);
    data_0217b690 = p;
    *p = data_02158238;
    func_020e6f50(&data_0217b690);
    return data_0217b690;
}

void func_020dbdac(void *a, Unk020db2b8 *p, void *c, s32 d) {
    Unk02012f58 *q;
    q = &p->mUnk_00.mUnk_28;
    if (p->mUnk_b4 != 0) {
        q = &data_0217b69c;
        func_02146d44((s32 *) &data_0217b69c, data_0215d4b4[((u16) p->mUnk_ba >> 4) * 2],
                      data_0215d4b4[((u16) p->mUnk_ba >> 4) * 2 + 1]);
        func_02146dfc((const s32 *) &data_0217b69c, (const s32 *) &p->mUnk_00.mUnk_28, (s32 *) &data_0217b69c);
    }
    q->mUnk_24.x = p->mUnk_00.mUnk_04.x >> 4;
    q->mUnk_24.y = p->mUnk_00.mUnk_04.y >> 4;
    q->mUnk_24.z = p->mUnk_00.mUnk_04.z >> 4;
    func_020ea8a8(data_0217b68c, q, &p->mUnk_00.mUnk_1c, d);
    func_020ea868(data_0217b694, q, &p->mUnk_00.mUnk_1c, d);
}

void func_020db760(void *a, Unk020db2b8 *p) {
    Unk0210b7a8 s;
    Unk020e0144 *q;
    Unk02042044 *e;
    s32 n;
    s32 v;
    s32 t;
    s32 w;
    p->mUnk_b0 = 0;
    q = &p->mUnk_c8;
    if (p->mUnk_b4 != 0) {
        p->mUnk_ba += p->mUnk_b8;
        n = p->mUnk_b8;
        if (n > 0x3e8 || n < -0x3e8) {
            if (p->mUnk_a0 < 4) {
                p->mUnk_b8 = (n * 0xfa00) >> 16;
            } else {
                p->mUnk_b8 = (n * 0xf80c) >> 16;
            }
        } else if (p->mUnk_b4 == 2) {
            if (n * p->mUnk_ba <= 0) {
                return;
            }
            if (n * n <= p->mUnk_ba * p->mUnk_ba) {
                return;
            }
            p->mUnk_b8 = 0;
            p->mUnk_ba = p->mUnk_b8;
            p->mUnk_b4 = 0;
            p->mUnk_c0 = 0;
            p->mUnk_a4 = 0x1e;
            p->mUnk_a0 = 0;
            return;
        }
        if (p->mUnk_b4 != 1) {
            return;
        }
        v = q->mUnk_04;
        if (p->mUnk_a0 < 4) {
            if (v > 0x4000) {
                t = (s32) (((s64) v * 0xf85) >> 12);
                q->mUnk_04 = t;
                q->mUnk_10 = (s32) (((s64) t * q->mUnk_00->mUnk_00[q->mUnk_0c].mUnk_34) >> 12);
            }
        } else {
            if (v > 0x800) {
                t = (s32) (((s64) v * 0xe66) >> 12);
                q->mUnk_04 = t;
                q->mUnk_10 = (s32) (((s64) t * q->mUnk_00->mUnk_00[q->mUnk_0c].mUnk_34) >> 12);
            }
        }
        if (func_020d8cc8(q) != 0) {
            p->mUnk_00.mUnk_04 = q->mUnk_1c->mUnk_00;
            p->mUnk_00.mUnk_04.y += p->mUnk_f8;
            if (q->mUnk_18 != 0) {
                q->mUnk_14 = 0;
            } else {
                func_020d8620(q);
                func_020d8648(q);
            }
            p->mUnk_b4 = 2;
            return;
        }
        func_020d8a5c(q, &p->mUnk_00.mUnk_04);
        p->mUnk_00.mUnk_04.y += p->mUnk_f8;
        return;
    }
    switch (p->mUnk_a0) {
        case 0:
            p->mUnk_a4--;
            if (p->mUnk_a4 >= 0) {
                return;
            }
            p->mUnk_a0++;
            t = p->mUnk_f0 != 0 ? 0xc00 : 0x3000;
            q->mUnk_04 = t;
            q->mUnk_10 = (s32) (((s64) t * q->mUnk_00->mUnk_00[q->mUnk_0c].mUnk_34) >> 12);
            return;
        case 1:
            if (p->mUnk_f0 != 0) {
                func_020d275c(&p->mUnk_00, 0x18b);
            }
            break;
        case 2:
            p->mUnk_a4--;
            if (p->mUnk_a4 < 0 && p->mUnk_c2 < 0x1555) {
                p->mUnk_a0++;
                p->mUnk_a8 = -p->mUnk_100;
                return;
            }
            p->mUnk_c2 += 0x1555;
            p->mUnk_00.mUnk_04.y = p->mUnk_ac;
            w = data_0215d4b4[(p->mUnk_c2 >> 4) * 2];
            p->mUnk_00.mUnk_04.y += (s32) (((s64) w * p->mUnk_c4) >> 12);
            return;
        case 3:
            p->mUnk_a8 += p->mUnk_104;
            p->mUnk_00.mUnk_04.y -= p->mUnk_a8;
            if (p->mUnk_00.mUnk_04.y < p->mUnk_ac) {
                p->mUnk_a0++;
            }
            return;
        case 4:
            if (p->mUnk_a8 < 0x14000) {
                p->mUnk_a8 += 0x1000;
                t = p->mUnk_a8;
                q->mUnk_04 = t;
                q->mUnk_10 = (s32) (((s64) t * q->mUnk_00->mUnk_00[q->mUnk_0c].mUnk_34) >> 12);
            }
            break;
        case 5:
            p->mUnk_a4--;
            if (p->mUnk_a4 >= 0) {
                return;
            }
            p->mUnk_a0++;
            t = p->mUnk_108;
            q->mUnk_04 = t;
            q->mUnk_10 = (s32) (((s64) t * q->mUnk_00->mUnk_00[q->mUnk_0c].mUnk_34) >> 12);
            return;
        case 6:
            break;
    }
    if (func_020d8cc8(q) != 0) {
        switch (q->mUnk_1c->mUnk_10) {
            case 0:
                n = 0;
                break;
            case 1:
                n = 2;
                break;
            case 2:
                n = 5;
                break;
            default:
                n = 0;
                break;
        }
        p->mUnk_a0 = n;
        if (p->mUnk_a0 == 2) {
            p->mUnk_ac = p->mUnk_00.mUnk_04.y;
            p->mUnk_c2 = 0;
        }
        if (p->mUnk_a0 == 5) {
            e = q->mUnk_1c;
            if (func_020d4ddc(&p->mUnk_00) == 0) {
                if (p->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                    n = 2;
                } else if (p->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                    n = 3;
                } else {
                    n = 4;
                }
                s.mUnk_00 = 0x166;
                s.mUnk_04 = &p->mUnk_00.mUnk_04;
                s.mUnk_08 = n;
                s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mUnk_04);
                func_0210b7a8(&s);
            }
            func_02073fb0(p->mUnk_00.mUnk_78 & ~0xc000001f, 0x1000);
            if ((p->mUnk_00.mUnk_78 & 3) == 0) {
                func_0208b7bc(0x59, &e->mUnk_00);
                func_0208b7bc(0x5a, &e->mUnk_00);
            }
            p->mUnk_b0 = 1;
        }
        p->mUnk_a4 = q->mUnk_1c->mUnk_0e;
        if (p->mUnk_a4 != 0) {
            p->mUnk_00.mUnk_04 = q->mUnk_00->mUnk_00[q->mUnk_0c].mUnk_00[0];
            p->mUnk_00.mUnk_04.y += p->mUnk_f8;
            q->mUnk_14 = 0;
            return;
        }
    }
    func_020d8a5c(q, &p->mUnk_00.mUnk_04);
    p->mUnk_00.mUnk_04.y += p->mUnk_f8;
}

u32 func_020db548(Unk020db2b8 *p, Unk0206bcb0 *a, u8 *b, u8 *c) {
    Vec3 s0;
    Vec3 s1;
    Vec3 s2;
    Unk020e0144 *q;
    s32 t;
    s64 m;
    s32 y;
    s64 n;
    q = &p->mUnk_c8;
    if (*b == 1) {
        if ((p->mUnk_c0 & (1 << a->mUnk_74)) == 0 || p->mUnk_bc + 0xf < func_02061fb8()) {
            func_021484d0(&a->mUnk_1b8, &p->mUnk_00.mUnk_04, &s0);
            func_021484d0(&q->mUnk_20->mUnk_00, &p->mUnk_00.mUnk_04, &s1);
            s1.y += p->mUnk_f8;
            if (func_02039828(&s0, &s1) > 0) {
                func_020d8620(q);
            }
            if (p->mUnk_a0 < 4) {
                t = 0xa800;
            } else {
                t = 0x8000;
            }
            t = t - (s32) (((s64) (0x1000 - p->mUnk_00.mUnk_1c.y) * 0x2000) >> 12);
            q->mUnk_04 = t;
            q->mUnk_10 = (s32) (((s64) t * q->mUnk_00->mUnk_00[q->mUnk_0c].mUnk_34) >> 12);
            p->mUnk_b4 = 1;
            p->mUnk_b8 = 0x1b58;
            if ((s64) s0.z * a->mUnk_a4.x - (s64) s0.x * a->mUnk_a4.z < 0) {
                p->mUnk_b8 = -p->mUnk_b8;
            }
            func_020d26f8(&p->mUnk_00, a);
            p->mUnk_c0 |= 1 << a->mUnk_74;
            p->mUnk_bc = func_02061fb8();
        }
    }
    if (p->mUnk_a0 == 4 || p->mUnk_b0 != 0) {
        func_021484d0(&a->mUnk_1b8, &p->mUnk_00.mUnk_04, &s2);
        n = ((s64) s2.x * s2.x + (s64) s2.z * s2.z) * 5;
        y = s2.y;
        m = ((s64) y * y) << 2;
        if (y < 0 && n < m) {
            return func_020d6dc0(p->mUnk_00.mUnk_02 & 0x800, a->mUnk_29c, 4, 4);
        }
    }
    return *c;
}

s32 func_020db4c4(Unk020db2b8 *p) {
    s32 r;
    s32 n;
    r = func_020d8cac(&p->mUnk_c8);
    n = p->mUnk_a0;
    if (n < 4) {
        if (p->mUnk_f0 != 0) {
            return 0;
        }
        return 0x1000;
    }
    switch (p->mUnk_b4) {
        case 0:
            switch (n) {
                case 4:
                    r = 0x1000 - r;
                    break;
                case 5:
                    r = 0;
                    break;
                case 6:
                    break;
            }
            break;
        case 2:
            r = 0x1000;
            break;
    }
    return r;
}

#pragma thumb on
void func_020db430(Unk020db2b8 *p) {
    Unk020e0144 *q;
    s32 n;
    q = &p->mUnk_c8;
    func_020d90a8(q, p->mUnk_ec, 1);
    func_020d8a5c(q, &p->mUnk_00.mUnk_04);
    p->mUnk_00.mUnk_04.y += p->mUnk_f8;
    switch (q->mUnk_1c->mUnk_10) {
        case 0:
            n = 0;
            break;
        case 1:
            n = 2;
            break;
        case 2:
            n = 5;
            break;
        default:
            n = 0;
            break;
    }
    p->mUnk_a0 = n;
    p->mUnk_a4 = q->mUnk_1c->mUnk_0e;
    p->mUnk_b4 = 0;
    p->mUnk_ba = 0;
    p->mUnk_b8 = p->mUnk_ba;
    p->mUnk_c0 = 0;
    p->mUnk_ac = p->mUnk_00.mUnk_04.y;
    p->mUnk_b0 = 0;
}
#pragma thumb off

#pragma thumb on
void func_020db3e4(void) {
    func_020ea588((void **) &data_0217b68c, FindCourseMapObjFile("dossun.nsbmd"), 0);
    func_020ea55c((void **) &data_0217b694, FindCourseMapObjFile("dossun_shadow.nsbmd"), 0x3f);
    func_02084968(data_0217b68c, 0x3f, 2, 0x294a);
}
#pragma thumb off

#pragma thumb on
void func_020db2b8(Unk020db2b8 *p, Unk020fa294 *a) {
    p->mUnk_f0 = a->mUnk_28;
    func_020d7da8(&p->mUnk_c8, a, p->mUnk_f0 != 0 ? 0xc00 : 0x3000);
    p->mUnk_ec = a->mUnk_2a;
    p->mUnk_f4 = (s32) (((s64) p->mUnk_00.mUnk_1c.x * 0x28000) >> 12);
    p->mUnk_f8 = (s32) (((s64) p->mUnk_00.mUnk_1c.y * 0x2d000) >> 12);
    p->mUnk_fc = (s32) (((s64) p->mUnk_00.mUnk_1c.z * 0x1e000) >> 12);
    p->mUnk_100 = (s32) (((s64) p->mUnk_00.mUnk_1c.y * 0xf000) >> 12);
    p->mUnk_104 = (s32) (((s64) p->mUnk_00.mUnk_1c.y * 0x1000) >> 12);
    p->mUnk_108 = (s32) (((s64) p->mUnk_00.mUnk_1c.y * 0x2000) >> 12);
    p->mUnk_c4 = (s32) (((s64) p->mUnk_00.mUnk_1c.y * 0x3000) >> 12);
    func_020db430(p);
    if (p->mUnk_f0 != 0) {
        func_020d27fc(&p->mUnk_00);
    } else {
        p->mUnk_00.mUnk_70 = data_0217caec[3];
    }
}
#pragma thumb off

Unk020db268 *func_020db268(void) {
    Unk020db268 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    *p = data_021581b8;
    return p;
}

Unk020db20c *func_020db20c(void) {
    Unk020db20c *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    data_0217b680 = p;
    *p = data_0215818c;
    func_020d49d8(&data_0217b680);
    return data_0217b680;
}

Unk020db1b0 *func_020db1b0(void) {
    Unk020db1b0 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x28);
    data_0217b684 = p;
    *p = data_02158164;
    func_020e6f50(&data_0217b684);
    return data_0217b684;
}

void func_020db198(void) {
    func_020e6a18(data_0217b688);
}

void func_020db050(void *a, Unk020da494 *p, void *c, u16 d) {
    Vec3 s;
    Unk020d7b88 t;
    u16 e;
    Unk020e6488 *q;
    if (p->mUnk_cc.mUnk_08 == 0xffff) {
        func_020d7938(&p->mUnk_a4, &data_0217b660, &t);
        func_01ffccd0(&p->mUnk_00.mUnk_28, &t);
    } else {
        func_020e6d34(func_020d88fc(&p->mUnk_cc), &p->mUnk_00.mUnk_28);
    }
    s.z = p->mUnk_00.mUnk_1c.z;
    s.y = (s32) (((s64) p->mUnk_00.mUnk_1c.y * p->mUnk_c4) >> 12);
    s.x = (s32) (((s64) p->mUnk_00.mUnk_1c.x * (((0x1000 - p->mUnk_c4) >> 1) + 0x1000)) >> 12);
    p->mUnk_00.mUnk_28.mUnk_24.x = p->mUnk_00.mUnk_04.x >> 4;
    p->mUnk_00.mUnk_28.mUnk_24.y = p->mUnk_00.mUnk_04.y >> 4;
    p->mUnk_00.mUnk_28.mUnk_24.z = p->mUnk_00.mUnk_04.z >> 4;
    if (p->mUnk_f0 < 0x14) {
        data_0217b688->mUnk_18 = p->mUnk_f0;
    } else {
        s.x = -s.x;
        data_0217b688->mUnk_18 = p->mUnk_f0 - 0x14;
    }
    e = p->mUnk_100;
    q = data_0217b688;
    q->mUnk_14 &= ~0x1f0000;
    q->mUnk_14 |= e << 16;
    func_020e67c4(data_0217b688, &p->mUnk_00.mUnk_28, &s, 0, d);
}

void func_020daf20(void *a, Unk020da494 *p) {
    Unk0210b7a8 s;
    Unk020f41c4_B *r;
    s32 n;
    p->mUnk_f0++;
    if (p->mUnk_f0 == 0x14 || p->mUnk_f0 == 0x28) {
        if ((p->mUnk_00.mUnk_78 & 4) == 0) {
            if (p->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                n = 2;
            } else if (p->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                n = 3;
            } else {
                n = 4;
            }
            s.mUnk_00 = 0x182;
            s.mUnk_04 = &p->mUnk_00.mUnk_04;
            s.mUnk_08 = n;
            s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mUnk_04);
            func_0210b7a8(&s);
        }
    }
    if (p->mUnk_f0 >= 0x28) {
        if (p->mUnk_f4 != 0) {
            p->mUnk_f0 = 0;
        } else {
            r = &data_0217561c->mUnk_47c;
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            p->mUnk_f0 = (u16) (((u64) (u32) (r->mUnk_00 >> 32) * 0x28) >> 32);
            p->mUnk_f4 = 1;
        }
    }
    func_02046b40(&p->mUnk_00.mUnk_80);
}

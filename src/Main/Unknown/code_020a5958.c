#include "Main/Unknown/code_020a5958.h"

#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0209b000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a0ff0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02081f10.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_02039860.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020a6000.h"
#include "Main/Unknown/code_020a2000.h"
#include "Main/Unknown/code_020a0000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_02156000.h"

void func_020a5958(void *a, Unk020a5958 *p) {
    Vec3 c;
    Vec3 b;
    Vec3 d;
    Vec3 e;
    u32 f;
    Unk0206bcb0 *v;
    s32 i;
    Unk02175620_84 *q;
    s32 n;
    s32 x;
    s32 z;
    s32 t;
    u16 r;
    s32 s;
    Unk020f41c4_B *g;

    switch (p->mUnk_e0) {
    case 0:
        p->mUnk_b4 += 1;
        if (p->mUnk_b4 >= 3) {
            p->mUnk_b4 -= 3;
            p->mUnk_b0++;
            if (p->mUnk_b0 >= func_0209b634(data_0217b224)) {
                p->mUnk_b0 -= func_0209b634(data_0217b224);
            }
            p->mUnk_bc++;
            if (p->mUnk_bc >= 8) {
                p->mUnk_bc -= 8;
                p->mUnk_b8 = p->mUnk_b8 == 0;
            }
        }
        p->mUnk_a8 += 0x19a;
        if (p->mUnk_a8 >= 0x1000) {
            p->mUnk_a8 = 0x1000;
        }
        p->mUnk_00.mUnk_10.y -= 0x19a;
        func_02148504(&p->mUnk_00.mUnk_04, &p->mUnk_00.mUnk_10, &p->mUnk_00.mUnk_04);
        if (p->mUnk_00.mUnk_04.y > p->mUnk_a4) {
            return;
        }
        p->mUnk_00.mUnk_04.y = p->mUnk_a4;
        p->mUnk_00.mUnk_10.y = ((s64)p->mUnk_00.mUnk_10.y * -0x333) >> 12;
        if (p->mUnk_00.mUnk_10.y < 0x1000) {
            p->mUnk_00.mUnk_10.y = 0;
            p->mUnk_e0 = 1;
        }
        func_0210b98c(p->mUnk_00.mUnk_94, 0x139);
        return;
    case 1:
        p->mUnk_b4 += 1;
        if (p->mUnk_b4 >= 3) {
            p->mUnk_b4 -= 3;
            p->mUnk_b0++;
            if (p->mUnk_b0 >= func_0209b634(data_0217b224)) {
                p->mUnk_b0 -= func_0209b634(data_0217b224);
            }
            p->mUnk_bc++;
            if (p->mUnk_bc >= 8) {
                p->mUnk_bc -= 8;
                p->mUnk_b8 = p->mUnk_b8 == 0;
            }
        }
        p->mUnk_a8 += 0x19a;
        if (p->mUnk_a8 >= 0x1000) {
            p->mUnk_a8 = 0x1000;
        }
        func_0210ba38(p->mUnk_00.mUnk_94, 0x14e);
        return;
    case 6:
        p->mUnk_b4 += 4;
        if (p->mUnk_b4 >= 3) {
            p->mUnk_b4 -= 3;
            p->mUnk_b0++;
            if (p->mUnk_b0 >= func_0209b634(data_0217b224)) {
                p->mUnk_b0 -= func_0209b634(data_0217b224);
            }
            p->mUnk_bc++;
            if (p->mUnk_bc >= 8) {
                p->mUnk_bc -= 8;
                p->mUnk_b8 = p->mUnk_b8 == 0;
            }
        }
        p->mUnk_a8 -= 0x19a;
        if (p->mUnk_a8 > 0) {
            return;
        }
        p->mUnk_a8 = 0;
        func_020d2398(&p->mUnk_00);
        func_020a1218(-1);
        if (p->mUnk_c4 < 0) {
            return;
        }
        func_020a6cb4(p->mUnk_c4);
        return;
    case 2:
        p->mUnk_b4 += 4;
        if (p->mUnk_b4 >= 3) {
            p->mUnk_b4 -= 3;
            p->mUnk_b0++;
            if (p->mUnk_b0 >= func_0209b634(data_0217b224)) {
                p->mUnk_b0 -= func_0209b634(data_0217b224);
            }
            p->mUnk_bc++;
            if (p->mUnk_bc >= 8) {
                p->mUnk_bc -= 8;
                p->mUnk_b8 = p->mUnk_b8 == 0;
            }
        }
        v = func_0207a974(p->mUnk_c8);
        p->mUnk_a0 += p->mUnk_00.mUnk_10.y;
        p->mUnk_00.mUnk_04 = *func_020a0ff0(p->mUnk_c8);
        p->mUnk_00.mUnk_04.y += p->mUnk_a0 + (func_020a23a0(v) + 0x7800);
        p->mUnk_00.mUnk_10.y -= 0x333;
        if (p->mUnk_c0-- <= 0) {
            p->mUnk_c0 = 0;
            p->mUnk_a8 -= 0x19a;
            if (p->mUnk_a8 <= 0) {
                p->mUnk_a8 = 0;
                func_020d2398(&p->mUnk_00);
                func_020a1218(-1);
                if (p->mUnk_c4 >= 0) {
                    func_020a6cb4(p->mUnk_c4);
                }
            }
            if (p->mUnk_a8 <= 0) {
                func_02081f10(func_0208b7bc(0x7c, &v->mUnk_80), v->mUnk_74, 0x16);
            }
        } else {
            p->mUnk_a8 += 0x19a;
            if (p->mUnk_a8 >= 0x1000) {
                p->mUnk_a8 = 0x1000;
            }
        }
        if (p->mUnk_e4 == 0) {
            return;
        }
        func_0208b5b0(p->mUnk_e4, &p->mUnk_00.mUnk_04);
        p->mUnk_e8--;
        if (p->mUnk_e8 >= 0) {
            return;
        }
        func_0208b6b0(&p->mUnk_e4);
        return;
    case 3:
        p->mUnk_b4 += 4;
        if (p->mUnk_b4 >= 3) {
            p->mUnk_b4 -= 3;
            p->mUnk_b0++;
            if (p->mUnk_b0 >= func_0209b634(data_0217b224)) {
                p->mUnk_b0 -= func_0209b634(data_0217b224);
            }
            p->mUnk_bc++;
            if (p->mUnk_bc >= 8) {
                p->mUnk_bc -= 8;
                p->mUnk_b8 = p->mUnk_b8 == 0;
            }
        }
        for (i = 0; i < 2; i++) {
            q = func_020a0f0c();
            n = q->mUnk_00.y - func_020a0ff0(p->mUnk_c8)->y;
            if (n <= 0) {
                n = -n;
            }
            if (n < 0x14000) {
                x = (q->mUnk_00.x - func_020a0ff0(p->mUnk_ca)->x) >> 12;
                z = (q->mUnk_00.z - func_020a0ff0(p->mUnk_ca)->z) >> 12;
                n = x * x + z * z;
                if (p->mUnk_ca == p->mUnk_c8) {
                    if (n < 0x9c400 && n > p->mUnk_d8) {
                        p->mUnk_d8 = n;
                        p->mUnk_cc.x = q->mUnk_00.x;
                        p->mUnk_cc.y = q->mUnk_00.y;
                        p->mUnk_cc.z = q->mUnk_00.z;
                        p->mUnk_dc++;
                    }
                } else {
                    if (n < 0x9c400 && n < p->mUnk_d8) {
                        p->mUnk_d8 = n;
                        p->mUnk_cc.x = q->mUnk_00.x;
                        p->mUnk_cc.y = q->mUnk_00.y;
                        p->mUnk_cc.z = q->mUnk_00.z;
                        p->mUnk_dc++;
                    }
                }
            }
        }
        p->mUnk_a0 += p->mUnk_00.mUnk_10.y;
        p->mUnk_00.mUnk_04 = *func_020a0ff0(p->mUnk_c8);
        p->mUnk_00.mUnk_04.y += p->mUnk_a0 + (func_020a23a0(func_0207a974(p->mUnk_c8)) + 0x7800);
        p->mUnk_00.mUnk_10.y -= 0x52;
        p->mUnk_a8 += 0x19a;
        if (p->mUnk_a8 >= 0x1000) {
            p->mUnk_a8 = 0x1000;
        }
        if (p->mUnk_00.mUnk_10.y > 0) {
            return;
        }
        if (p->mUnk_dc > 0) {
            g = &data_0217561c->mUnk_47c;
            g->mUnk_00 = g->mUnk_08 * g->mUnk_00 + g->mUnk_10;
            r = (u16)(((u64)(u32)(g->mUnk_00 >> 32) * 0x10000) >> 32);
            g = &data_0217561c->mUnk_47c;
            g->mUnk_00 = g->mUnk_08 * g->mUnk_00 + g->mUnk_10;
            s = ((u64)(u32)(g->mUnk_00 >> 32) * 0x14000) >> 32;
            x = p->mUnk_cc.x + (s32)(((s64)s * data_0215d4b4[(r >> 4) * 2]) >> 12) - p->mUnk_00.mUnk_04.x;
            z = p->mUnk_cc.z + (s32)(((s64)s * data_0215d4b4[(r >> 4) * 2 + 1]) >> 12) - p->mUnk_00.mUnk_04.z;
            p->mUnk_e0 = 4;
            p->mUnk_00.mUnk_10.x = ((s64)x * 0x25) >> 12;
            p->mUnk_00.mUnk_10.y = 0x5000;
            p->mUnk_00.mUnk_10.z = ((s64)z * 0x25) >> 12;
            p->mUnk_a8 = 0x1000;
            p->mUnk_00.mUnk_02 &= ~1;
            return;
        }
        p->mUnk_e0 = 5;
        p->mUnk_00.mUnk_10.x = 0;
        p->mUnk_00.mUnk_10.y = 0x5000;
        p->mUnk_00.mUnk_10.z = 0;
        p->mUnk_a8 = 0x1000;
        p->mUnk_00.mUnk_02 &= ~1;
        return;
    case 5:
        p->mUnk_b4 += 1;
        if (p->mUnk_b4 >= 3) {
            p->mUnk_b4 -= 3;
            p->mUnk_b0++;
            if (p->mUnk_b0 >= func_0209b634(data_0217b224)) {
                p->mUnk_b0 -= func_0209b634(data_0217b224);
            }
            p->mUnk_bc++;
            if (p->mUnk_bc >= 8) {
                p->mUnk_bc -= 8;
                p->mUnk_b8 = p->mUnk_b8 == 0;
            }
        }
        p->mUnk_a8 += 0x19a;
        if (p->mUnk_a8 >= 0x1000) {
            p->mUnk_a8 = 0x1000;
        }
        p->mUnk_00.mUnk_10.y -= 0x19a;
        func_02148504(&p->mUnk_00.mUnk_04, &p->mUnk_00.mUnk_10, &p->mUnk_00.mUnk_04);
        if (p->mUnk_00.mUnk_10.y >= 0) {
            return;
        }
        p->mUnk_e0 = 6;
        p->mUnk_00.mUnk_02 |= data_021567a0;
        return;
    case 4:
        p->mUnk_b4 += 1;
        if (p->mUnk_b4 >= 3) {
            p->mUnk_b4 -= 3;
            p->mUnk_b0++;
            if (p->mUnk_b0 >= func_0209b634(data_0217b224)) {
                p->mUnk_b0 -= func_0209b634(data_0217b224);
            }
            p->mUnk_bc++;
            if (p->mUnk_bc >= 8) {
                p->mUnk_bc -= 8;
                p->mUnk_b8 = p->mUnk_b8 == 0;
            }
        }
        p->mUnk_a8 += 0x19a;
        if (p->mUnk_a8 >= 0x1000) {
            p->mUnk_a8 = 0x1000;
        }
        p->mUnk_00.mUnk_10.y -= 0x19a;
        func_02148504(&p->mUnk_00.mUnk_04, &p->mUnk_00.mUnk_10, &p->mUnk_00.mUnk_04);
        if (p->mUnk_00.mUnk_10.y < 0 && p->mUnk_00.mUnk_04.y <= p->mUnk_cc.y + p->mUnk_00.mUnk_58.x) {
            if (func_020d3c94(&p->mUnk_00, 0, &b)) {
                t = p->mUnk_00.mUnk_10.y;
                func_02148504(&p->mUnk_00.mUnk_04, &b, &p->mUnk_00.mUnk_04);
                func_020ea94c(&p->mUnk_00.mUnk_10, &b, 0x1000, 0x1000, 0x800, &p->mUnk_00.mUnk_10);
                p->mUnk_00.mUnk_10.y = 0;
                if ((s64)p->mUnk_00.mUnk_10.x * p->mUnk_00.mUnk_10.x + (s64)p->mUnk_00.mUnk_10.y * p->mUnk_00.mUnk_10.y +
                        (s64)p->mUnk_00.mUnk_10.z * p->mUnk_00.mUnk_10.z >=
                    0x10) {
                    func_02039860(&p->mUnk_00.mUnk_10, &p->mUnk_00.mUnk_10);
                }
                p->mUnk_00.mUnk_10.x = ((s64)p->mUnk_00.mUnk_10.x * 0x1000) >> 12;
                p->mUnk_00.mUnk_10.y = ((s64)p->mUnk_00.mUnk_10.y * 0x1000) >> 12;
                p->mUnk_00.mUnk_10.z = ((s64)p->mUnk_00.mUnk_10.z * 0x1000) >> 12;
                p->mUnk_00.mUnk_10.y = t;
            }
            c.x = p->mUnk_00.mUnk_04.x;
            c.y = p->mUnk_00.mUnk_58.x + (p->mUnk_00.mUnk_04.y - 0x14000);
            c.z = p->mUnk_00.mUnk_04.z;
            if (func_01ffdee4(&c, 0, 0, p->mUnk_00.mUnk_58.x, 8, -2, &b, &d, &e.x, &f, 0, 0, 0, 0)) {
                func_02148504(&p->mUnk_00.mUnk_04, &b, &p->mUnk_00.mUnk_04);
                if (f & 0x214300) {
                    t = p->mUnk_00.mUnk_10.y;
                    func_020eaa14(&p->mUnk_00.mUnk_10, &e, 0x1000, 0x1000, 0x800, &p->mUnk_00.mUnk_10);
                    p->mUnk_00.mUnk_10.y = 0;
                    if ((s64)p->mUnk_00.mUnk_10.x * p->mUnk_00.mUnk_10.x + (s64)p->mUnk_00.mUnk_10.y * p->mUnk_00.mUnk_10.y +
                            (s64)p->mUnk_00.mUnk_10.z * p->mUnk_00.mUnk_10.z >=
                        0x10) {
                        func_02039860(&p->mUnk_00.mUnk_10, &p->mUnk_00.mUnk_10);
                    }
                    p->mUnk_00.mUnk_10.x = ((s64)p->mUnk_00.mUnk_10.x * 0x1000) >> 12;
                    p->mUnk_00.mUnk_10.y = ((s64)p->mUnk_00.mUnk_10.y * 0x1000) >> 12;
                    p->mUnk_00.mUnk_10.z = ((s64)p->mUnk_00.mUnk_10.z * 0x1000) >> 12;
                    p->mUnk_00.mUnk_10.y = t;
                }
                if (f & 0x1e34ef) {
                    p->mUnk_00.mUnk_10.x = ((s64)p->mUnk_00.mUnk_10.x * 0x19a) >> 12;
                    p->mUnk_00.mUnk_10.y = ((s64)p->mUnk_00.mUnk_10.y * -0x333) >> 12;
                    p->mUnk_00.mUnk_10.z = ((s64)p->mUnk_00.mUnk_10.z * 0x19a) >> 12;
                    if (p->mUnk_00.mUnk_10.y < 0x1000) {
                        p->mUnk_00.mUnk_10.y = 0;
                        p->mUnk_e0 = 1;
                    }
                    func_0210b98c(p->mUnk_00.mUnk_94, 0x139);
                }
                if (f & 0x1000000) {
                    p->mUnk_00.mUnk_02 |= data_021567ac;
                } else {
                    p->mUnk_00.mUnk_02 &= ~0x20;
                }
            }
        }
        if (p->mUnk_00.mUnk_04.y >= 0) {
            return;
        }
        p->mUnk_e0 = 6;
        p->mUnk_00.mUnk_02 |= data_021567a0;
        return;
    }
}

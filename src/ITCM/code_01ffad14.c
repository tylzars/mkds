#include "ITCM/code_01ffad14.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_02154000.h"

void func_01ffb0cc(Kart *p) {
    p->mUnk_4fc = p->mUnk_4fc + 1;
    if (p->mUnk_4fc >= 8) {
        p->mUnk_4fc = 0;
    }
    p->mUnk_4f0.x = data_02154b64[p->mUnk_4fc];
    p->mUnk_4f0.y = data_02154b84[p->mUnk_4fc];
    p->mUnk_4f0.z = data_02154ba4[p->mUnk_4fc];
}

s32 func_01ffaf18(Kart *p) {
    BOOL v1;
    s32 a = p->mUnk_2a8;
    s32 c;
    s32 g;
    s32 b;
    u32 f = p->mUnk_48;

    v1 = a < 0;

    a = a > 0 ? a : -a;
    b = p->mUnk_274;
    c = p->mUnk_d0 - b;
    if ((f & 4) && (p->mUnk_44 & 0x100)) {
        if (c > 0x3000) {
            c = 0x3000;
        }
    }
    g = p->mUnk_39c + (b + (s32) ((s64) c * (s32) ((s64) p->mUnk_38c * p->mUnk_394 >> 12) >> 12));
    if (a > g) {
        p->mUnk_2a8 = g;
    } else {
        if (a <= (s32) (p->mUnk_38c * (s64) 0x19a >> 12) && !(p->mUnk_44 & 0x80000) && !(f & 6)) {
            p->mUnk_2a8 = 0;
        } else {
            p->mUnk_2a8 = a;
        }
    }
    if (v1) {
        p->mUnk_2a8 *= -1;
    }
    g = p->mUnk_3a0;
    if (g != 0) {
        if (g > 0) {
            a = p->mUnk_2a8;
            if (a < 0) {
                p->mUnk_2a8 = a + g;
                if (p->mUnk_2a8 > p->mUnk_3a0) {
                    p->mUnk_2a8 = p->mUnk_3a0;
                }
            } else {
                a = a > 0 ? a : -a;
                c = g > 0 ? g : -g;
                if (c > a) {
                    p->mUnk_2a8 = g;
                }
            }
        } else {
            a = p->mUnk_2a8;
            if (a > 0) {
                p->mUnk_2a8 = a + g;
                if (p->mUnk_2a8 < p->mUnk_3a0) {
                    p->mUnk_2a8 = p->mUnk_3a0;
                }
            } else {
                a = a > 0 ? a : -a;
                c = g > 0 ? g : -g;
                if (c > a) {
                    p->mUnk_2a8 = g;
                }
            }
        }
    }
    return ((s64) p->mUnk_2a8 * (0x1000 - (p->mUnk_274 >> 3)) + 0x800) >> 12;
}

void func_01ffae14(Kart *p, s32 a) {
    s32 r;

    p->mUnk_a4.x = (s64) p->mUnk_a4.x * a >> 12;
    r = 0;
    p->mUnk_a4.y = (s64) p->mUnk_a4.y * a >> 12;
    p->mUnk_a4.z = (s64) p->mUnk_a4.z * a >> 12;
    if ((s64) p->mUnk_a4.x * p->mUnk_a4.x + (s64) p->mUnk_a4.y * p->mUnk_a4.y + (s64) p->mUnk_a4.z * p->mUnk_a4.z >=
        0x10) {
        r = func_02039860(&p->mUnk_a4, &p->mUnk_b0);
    }
    p->mUnk_2a4 = r;
    if (p->mUnk_2a4 > 0xd000) {
        p->mUnk_2a4 = 0xd000;
        p->mUnk_a4.x = (s64) p->mUnk_b0.x * 0xd000 >> 12;
        p->mUnk_a4.y = (s64) p->mUnk_b0.y * 0xd000 >> 12;
        p->mUnk_a4.z = (s64) p->mUnk_b0.z * 0xd000 >> 12;
    }
}

void func_01ffad14(Kart *p, Vec3 *a) {
    Vec4 v;
    Vec4 w;
    Vec4 *q = &p->mUnk_100_q;
    s32 r;

    r = func_01ffd0e8(&v, &data_02154f7c, a);
    func_01ffd0e8(&w, &p->mUnk_244, a);
    func_01ffcebc(&w, q, q);
    if (r != 0) {
        if ((v.w < 0 && q->w > 0) || (v.w > 0 && q->w < 0)) {
            q->x = -v.x;
            q->y = 0;
            q->z = -v.z;
            q->w = -v.w;
            p->mUnk_48 = p->mUnk_48 | 0x80000000;
        } else {
            q->x = v.x;
            q->y = 0;
            q->z = v.z;
            q->w = v.w;
            p->mUnk_48 = p->mUnk_48 & ~0x80000000;
        }
    }
    func_01ffcf7c(q, q);
}

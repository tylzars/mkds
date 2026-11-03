#include "Main/Unknown/code_020641d4.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_02066000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020738f4.h"
#include "Main/Unknown/code_0207a7ec.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02147000.h"
#include "code_02147288.h"
#include "Main/Unknown/unk_0215d000.h"

void func_020641d4(Unk0206bcb0 *a) {
    func_01ffcb58(a);
    func_020641f0(a);
}

void func_020641f0(Unk0206bcb0 *a) {
    Unk0206bcb0_590 *b;
    Unk0206bcb0_590_08 *c;
    Vec3 m;
    Unk02012f58 d;
    Unk02012f58 e;
    Unk02012f58 f;
    Unk02012f58 g;
    Unk02012f58 h;
    s32 i;
    s32 j;
    s32 k;
    u16 l;
    u32 n;
    Unk02012f58 *p;
    Vec3 *q;
    Vec4 *r;
    enum { K0 } o;

    func_01ffcd84(&a->mUnk_120, a->mUnk_50c);
    n = a->mUnk_4c;
    if ((n & 0x10) != 0) {
        p = &a->mUnk_150_m;
        func_021471bc(&d);
        e = d;
        func_01ffcd84(&f, &a->mUnk_34c);
        q = &a->mUnk_12c;
        m.x = (s64) q->x * -0x5000 >> 12;
        m.y = (s64) q->y * -0x5000 >> 12;
        m.z = (s64) q->z * -0x5000 >> 12;
        d.mUnk_00[3] = m;
        m.x = -m.x;
        m.y = -m.y;
        m.z = -m.z;
        e.mUnk_00[3] = m;
        func_0214733c(&a->mUnk_120_m, &d, p);
        func_0214733c(p, &f, p);
        func_0214733c(p, &e, p);
        if ((a->mUnk_4c & 0x20) != 0) {
            i = (a->mUnk_364 >> 4) * 2;
            func_02147250(&g, data_0215d4b4[i], data_0215d4b4[i + 1]);
            func_0214733c(p, &g, p);
        }
        p->mUnk_00[3].x = p->mUnk_00[3].x + a->mUnk_508->x;
        p->mUnk_00[3].y = p->mUnk_00[3].y + a->mUnk_508->y;
        p->mUnk_00[3].z = p->mUnk_00[3].z + a->mUnk_508->z;
    } else if ((n & 0x20) != 0) {
        i = (a->mUnk_364 >> 4) * 2;
        func_02147250(&h, data_0215d4b4[i], data_0215d4b4[i + 1]);
        func_0214733c(&h, &a->mUnk_120_m, &a->mUnk_150_m);
        q = a->mUnk_508;
        a->mUnk_174.x = q->x;
        a->mUnk_174.y = q->y;
        a->mUnk_174.z = q->z;
    } else {
        a->mUnk_150_m = a->mUnk_120_m;
        q = a->mUnk_508;
        a->mUnk_174.x = q->x;
        a->mUnk_174.y = q->y;
        a->mUnk_174.z = q->z;
    }
    a->mUnk_98 = a->mUnk_174;
    a->mUnk_174.x = a->mUnk_174.x >> 4;
    a->mUnk_174.y = a->mUnk_174.y >> 4;
    a->mUnk_174.z = a->mUnk_174.z >> 4;
    if ((a->mUnk_4c & 0x2000000) == 0) {
        a->mUnk_1b4 = &a->mUnk_150_m;
    } else {
        func_02066de8(a);
        a->mUnk_1b4 = &a->mUnk_184_m;
    }
    b = a->mKartModelsEntry;
    if (b->mUnk_010[2] != NULL) {
        r = (Vec4 *) &b->mUnk_024;
        j = (s64) r->w * r->x >> 12;
        l = (s64) j * 0xce4 >> 12;
        k = a->mUnk_2a0;
        if (a->mUnk_4d4 > k) {
            a->mUnk_3a4 = a->mUnk_3a4 + (u16) ((s64) a->mUnk_4d4 * 0x7d0 >> 12);
        } else {
            k = (s64) k * 0xfa0 >> 12;
            if (func_020738f8(func_0207a7ec()) < 0x29) {
                k = 0;
                if ((u16) (data_0217562a[o = a->mUnk_78].mBits & 3) != 0 && func_02061fec() == 1) {
                    k = k + 0x190;
                }
            } else if ((a->mUnk_44 & 0x100) != 0) {
                k *= -1;
            }
            if (k > 0xfa0) {
                k = 0xfa0;
            }
            a->mUnk_3a4 = a->mUnk_3a4 + (u16) k;
        }
        a->mUnk_4cc = l;
    }
    c = a->mKartModelsEntry->mUnk_008;
    if (c != NULL && c->mUnk_18 != 0) {
        func_0207b734(a);
        if (func_0203c880(a->mIndex) != 0) {
            func_0207b354(a);
        }
        c = a->mKartModelsEntry->mUnk_008;
        *c->mUnk_1c[c->mUnk_1a] = c->mUnk_0c;
    }
    if ((a->mUnk_4c & 0x400000) != 0) {
        a->mUnk_504 = a->mUnk_504 + 1;
        a->mUnk_506 = a->mUnk_506 + 1;
        if (a->mUnk_506 > 8) {
            a->mUnk_506 = 0;
        }
        if (a->mUnk_506 >= 4) {
            a->mUnk_4c = a->mUnk_4c | 0x1000000;
        } else {
            a->mUnk_4c = a->mUnk_4c & ~0x1000000;
        }
        if (a->mUnk_504 > 0x5a) {
            a->mUnk_4c = a->mUnk_4c & ~0x1400000;
        }
    }
    func_01ff9b70(a);
}

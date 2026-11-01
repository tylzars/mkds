#include "Main/Unknown/code_020646f0.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffd000.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "code_02147cd8.h"

void func_020646f0(Unk0206bcb0 *a, s32 b) {
    Unk02012f58 *m;
    Unk02175620 *c;
    Vec3 d;
    Vec3 e;
    Vec3 f;
    Vec3 g;
    Vec3 h;
    Unk0206bcb0_590_08 *i;
    s16 j;
    s16 k;
    s16 l;
    Vec3 *n;

    if (b == 0) {
        func_02041bb0(&a->mUnk_80, &d, a->mUnk_74);
        if (data_021759c0->mUnk_00c == 5) {
            a->mUnk_80 = data_0216549c[a->mUnk_74];
        }
    } else {
        c = data_02175620;
        if (c->mUnk_3c != 0) {
            n = &a->mUnk_80;
            if (n != 0) {
                *n = c->mUnk_3c->mUnk_00;
            }
            d = c->mUnk_3c->mUnk_0c;
        }
    }
    if ((a->mUnk_7c & 0x600) != 0) {
        j = a->mUnk_80.x >> 10;
        k = a->mUnk_80.y >> 10;
        l = a->mUnk_80.z >> 10;
        a->mUnk_80.x = j << 10;
        a->mUnk_80.y = k << 10;
        a->mUnk_80.z = l << 10;
    }
    g = a->mUnk_80;
    g.y = g.y + 0x1000;
    a->mUnk_80.y = a->mUnk_80.y - 0x1400;
    if (func_01ffdee4(&a->mUnk_80, (u32 *) &g, (u32) &a->mUnk_50, 0x5000, 1, -2, &e, &f, 0, 0, 0, 0, 0, 0) != 0) {
        h.x = (s64) f.x * 0x5000 >> 12;
        h.y = (s64) f.y * 0x5000 >> 12;
        h.z = (s64) f.z * 0x5000 >> 12;
        func_021484d0(&e, &h, &e);
        func_02148504(&a->mUnk_80, &e, &a->mUnk_80);
    }
    a->mUnk_80.y = a->mUnk_80.y - 0x1000;
    a->mUnk_236 = (u32) (d.y * 0xb6) >> 12;
    func_01ffd190(&data_02154a3c, a->mUnk_236, &a->mUnk_e0_m);
    a->mUnk_110_q = a->mUnk_e0_m;
    func_01ffcd84(&a->mUnk_120, &a->mUnk_110_q);
    a->mUnk_150_m = a->mUnk_120_m;
    a->mUnk_8c = a->mUnk_80;
    a->mUnk_98 = a->mUnk_8c;
    a->mUnk_174.x = a->mUnk_98.x;
    a->mUnk_174.y = a->mUnk_98.y;
    a->mUnk_174.z = a->mUnk_98.z;
    m = &a->mUnk_120_m;
    a->mUnk_278.x = m->mUnk_18.x;
    a->mUnk_278.y = m->mUnk_18.y;
    a->mUnk_278.z = m->mUnk_18.z;
    a->mUnk_50 = a->mUnk_278;
    a->mUnk_1b4 = &a->mUnk_150_m;
    i = a->mUnk_590->mUnk_008;
    if (i == 0) {
        return;
    }
    if (i->mUnk_18 != 0) {
        i->mUnk_0c = a->mUnk_590->mUnk_02c;
    }
}

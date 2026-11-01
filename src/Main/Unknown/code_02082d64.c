#include "Main/Unknown/code_02082d64.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_0217a000.h"

void func_02082f94(Unk0201ca6c *p, s32 a) {
    if (a != 0) {
        return;
    }
    func_02082d64(p, a);
    p->mUnk_98_24 = p->mUnk_98_24 + 1;
    if (p->mUnk_98_24 >= 2) {
        p->mUnk_98_16 = (p->mUnk_98_16 == 0);
        p->mUnk_98_24 = 0;
    }
}

void func_02082e4c(s32 a) {
    Unk02155808 *e;
    s32 j;
    Unk02155888_00 *d;
    s32 k;
    u32 f;
    s32 n;
    s32 i;
    s32 m;
    Unk0201ca6c *o;

    data_0217aea0 = data_02155888[a];
    n = data_0217ae98;
    i = n;
    if (i < 4) {
        m = data_0217ae90;
        do {
            if (i != n || m == 0) {
                data_0217aea0.mUnk_00[i].mUnk_00 = -1;
            }
            data_0217aea0.mUnk_00[i].mUnk_02 = -1;
            i++;
        } while (i < 4);
    }
    e = data_02155808;
    for (j = 0; j < 2; j++) {
        f = (j != 0) ? 1 : 0;
        k = 0;
        d = data_0217aea0.mUnk_00;
        do {
            if (d->mUnk_00 < 0) {
                break;
            }
            o = func_0208b60c(e->mUnk_00, &data_02155a14);
            k++;
            o->mUnk_90 = e->mUnk_04;
            o->mUnk_98_0 = d->mUnk_00;
            o->mUnk_98_8 = (d->mUnk_02 < 0) ? 0xff : (u8) d->mUnk_02;
            d++;
            o->mUnk_98_16 = f;
            o->mUnk_98_24 = 0;
            o->mUnk_94_u = 0;
        } while (k < 4);
        e++;
    }
}

void func_02082d64(Unk0201ca6c *p, s32 a) {
    Unk0201ca6c_98 *s;
    Unk0206bcb0 *q;
    u32 n;
    u32 f;
    u32 x;
    s32 y;
    s32 v1;
    s32 v2;
    s32 v3;

    s = &p->mUnk_98_b;
    y = s->mUnk_02;
    n = p->mUnk_94_u;
    y = (y == 0) ? s->mUnk_00 : s->mUnk_01;
    x = s->mUnk_01;
    f = 1;
    if (x > 8) {
        if (y > 8) {
            f = 0;
        }
        y = s->mUnk_00;
    }
    q = func_0207a974(y);
    v1 = q->mUnk_1d8.x;
    v2 = q->mUnk_1d8.y;
    v3 = q->mUnk_1d8.z;
    p->mUnk_28.x = (v1 >> 4) + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = (v2 >> 4) + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = (v3 >> 4) + p->mUnk_20->mUnk_00->mUnk_04.z;
    if (q->mUnk_7c & 0x402000) {
        f = 0;
    }
    p->mUnk_24.mUnk_00_3 = (f == 0);
    if (n + 1 >= 0x32) {
        p->mUnk_24.mUnk_00_0 = 1;
    }
    p->mUnk_94_u = n + 1;
}

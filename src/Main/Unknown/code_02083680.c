#include "Main/Unknown/code_02083680.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_02081f30.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/code_02074874.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02147cd8.h"

void func_02083928(Unk0206bcb0 *p, s32 a) {
    u16 i;
    Unk0217ae84 *e;

    e = &data_0217ae84[p->mUnk_74];
    for (i = 0; i < 2; i++) {
        if (e->mUnk_10[i].mUnk_00 != 0 || e->mUnk_10[i].mUnk_04 != 0) {
            if (a == 0) {
                e->mUnk_10[i].mUnk_00->mUnk_98_8 = 1;
                e->mUnk_10[i].mUnk_04->mUnk_98_8 = 1;
            } else {
                func_0208b710(e->mUnk_10[i].mUnk_00);
                func_0208b710(e->mUnk_10[i].mUnk_04);
            }
            e->mUnk_10[i].mUnk_00 = e->mUnk_10[i].mUnk_04 = 0;
            e->mUnk_04[i] = -1;
        }
    }
}

void func_020838dc(Unk0206bcb0 *p) {
    Unk0217ae84 *e;

    e = &data_0217ae84[p->mUnk_74];
    if (e->mUnk_20 != 0) {
        e->mUnk_20->mUnk_98_8 = 1;
        e->mUnk_20 = 0;
    }
    if (e->mUnk_24 != 0) {
        e->mUnk_24->mUnk_98_8 = 1;
        e->mUnk_24 = 0;
    }
}

void func_02083834(Unk0206bcb0 *p) {
    Unk0217ae84 *e;

    e = &data_0217ae84[p->mUnk_74];
    if (e->mUnk_0c != 0) {
        func_0208b710(e->mUnk_0c);
        e->mUnk_0c = 0;
        e->mUnk_00 = -1;
    }
    func_02083928(p, 1);
    e = &data_0217ae84[p->mUnk_74];
    if (e->mUnk_20 != 0) {
        func_0208b710(e->mUnk_20);
        e->mUnk_20 = 0;
    }
    if (e->mUnk_24 == 0) {
        return;
    }
    func_0208b710(e->mUnk_24);
    e->mUnk_24 = 0;
}

void func_02083680(Unk0201ca6c *p, s32 a) {
    Unk02148038 h;
    Vec3 v;
    Vec3 w;
    Vec3 u;
    Unk020748a8 *g;
    Unk0206bcb0 *q;

    if (a != 0) {
        return;
    }
    g = func_020748a8();
    q = p->mUnk_94;
    if (func_02061818() != 0 || (p->mUnk_24.mUnk_00_1 != 0 && (p->mUnk_98 = p->mUnk_98 + 1, p->mUnk_98 > 5))) {
        p->mUnk_24.mUnk_00_0 = 1;
        data_0217ae80 = 0;
        return;
    }
    if (!(q->mUnk_48 & 0x20)) {
        p->mUnk_24.mUnk_00_1 = 1;
    }
    v = g->mUnk_9c;
    w.x = (s32) (((s64) g->mUnk_15c.x * 0x5000) >> 12);
    w.y = (s32) (((s64) g->mUnk_15c.y * 0x5000) >> 12);
    w.z = (s32) (((s64) g->mUnk_15c.z * 0x5000) >> 12);
    func_02148504(&w, &v, &u);
    p->mUnk_28.x = u.x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = u.y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = u.z + p->mUnk_20->mUnk_00->mUnk_04.z;
    h.mUnk_00 = -g->mUnk_15c.x;
    h.mUnk_02 = -g->mUnk_15c.y;
    h.mUnk_04 = -g->mUnk_15c.z;
    p->mUnk_50 = h;
}

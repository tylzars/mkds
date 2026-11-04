#include "Main/Unknown/code_0206390c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02012b30.h"
#include "code_02013740.h"
#include "code_02146d78.h"
#include "code_02147288.h"
#include "code_02147cd8.h"

void func_02063b30(const Unk0206bcb0 *a, Vec3 *b) {
    const Unk02012f58 *c;

    c = (const Unk02012f58 *) ((u8 *) a + 0x120);
    b->x = c->mUnk_00[1].x;
    b->y = c->mUnk_00[1].y;
    b->z = c->mUnk_00[1].z;
}

void func_02063b10(const Unk0206bcb0 *a, Vec3 *b) {
    const Unk02012f58 *c;

    c = (const Unk02012f58 *) ((u8 *) a + 0x120);
    b->x = c->mUnk_00[2].x;
    b->y = c->mUnk_00[2].y;
    b->z = c->mUnk_00[2].z;
}

void func_02063ad0(Unk0206bcb0 *a) {
    if ((a->mUnk_7c & 0x400) != 0) {
        return;
    }
    a->mUnk_20c_fn[6](a);
    if ((a->mUnk_7c & 0x200) != 0) {
        a->mUnk_514->mUnk_2c ^= 0x10000;
    }
}

void func_02063a68(Unk0206bcb0 *a) {
    u32 b;

    b = a->mUnk_7c & 0x400;
    if (b != 0) {
        return;
    }
    if (b == 0) {
        a->mUnk_20c_fn[6](a);
        if ((a->mUnk_7c & 0x200) != 0) {
            a->mUnk_514->mUnk_2c ^= 0x10000;
        }
    }
    if (data_021759c0->mUnk_08 == 2) {
        a->mUnk_48 &= ~0x200;
    }
}

void func_0206390c(Unk0206390c *a) {
    u32 b;
    Vec3 c[3];
    Unk02012f58 d;
    Vec3 f;
    Vec3 g;
    Unk02012f58 e;
    s32 h;
    Unk02012f58 *i;
    Unk0206bcb0 *j;
    s32 k;

    b = func_0207a31c();
    k = func_02013754(a->mUnk_04->mUnk_04 + 0x40, data_02154a2c);
    if (k != ((a->mUnk_08 & 0x10) != 0 ? a->mUnk_ae : -1)) {
        return;
    }
    i = func_0206182c();
    func_02012f58(&d, c);
    func_0214755c(i, &e);
    func_0214733c(&d, &e, &d);
    func_02146dfc((const s32 *) c, (const s32 *) &e, (s32 *) c);
    f = d.mUnk_00[3];
    g = c[2];
    j = func_0207a974(b);
    h = (s32) ((s64) j->mUnk_4c8 * -0xd000 + 0x800 >> 12) >> 4;
    g.x = (s64) g.x * h >> 12;
    g.y = (s64) g.y * h >> 12;
    g.z = (s64) g.z * h >> 12;
    Vec3Add(&f, &g, &f);
    func_02081618(b, &f);
    a->mUnk_24 = 0;
    a->mUnk_92 = 0;
}

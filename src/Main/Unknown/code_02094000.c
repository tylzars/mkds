#include "Main/Unknown/code_02094000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_02074874.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02148538.h"

static inline u32 func_02094000_inline(Unk020f41c4_B *b, u32 n) {
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    if (n == 0) {
        return (u32) (b->mUnk_00 >> 32);
    }
    return (u32) (((b->mUnk_00 >> 32) * n) >> 32);
}

static inline void func_02094000_inline_2(Unk02094000_bc *p, u16 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    p->mUnk_00 = a;
    p->mUnk_0c = b;
    p->mUnk_10 = c;
    p->mUnk_14 = d;
    p->mUnk_18 = e;
    p->mUnk_1c = f;
}

void func_02094000(Vec3 *a) {
    Unk02094000 *o;
    Unk020748a8 *g;
    s32 p;
    s32 q;
    s32 e;
    s16 c;
    u16 b;
    s32 k;
    s32 d;
    s32 f;

    o = func_0209bbfc(func_02100138(0x13b));
    if (o == 0) {
        return;
    }
    o->mUnk_ac = 0;
    o->mUnk_a0 = *a;
    if (func_02061818() == 0) {
        g = func_020748a8();
        e = func_02094000_inline(&data_0217561c->mUnk_498, 0x30);
        c = (u16) (func_02094000_inline(&data_0217561c->mUnk_498, 0) >> 20);
        b = func_02094000_inline(&data_0217561c->mUnk_498, 0x5555);
        k = func_02148714(g->mUnk_18.z - g->mUnk_24.z, g->mUnk_18.x - g->mUnk_24.x) + b - 0x2aaa;
        func_02094000_inline_2(&o->mUnk_bc, func_02094000_inline(&data_0217561c->mUnk_498, 0x10000), k, c + 0x1000, 0,
                               e + 0x60, 0);
    } else {
        e = func_02094000_inline(&data_0217561c->mUnk_498, 0x30);
        c = (u16) (func_02094000_inline(&data_0217561c->mUnk_498, 0) >> 20);
        func_02094000_inline_2(&o->mUnk_bc, func_02094000_inline(&data_0217561c->mUnk_498, 0x10000),
                               (u16) func_02094000_inline(&data_0217561c->mUnk_498, 0x10000), c + 0x1000, 0, e + 0x60,
                               0);
    }
    d = func_02094000_inline(&data_0217561c->mUnk_498, 0x80);
    f = func_02094000_inline(&data_0217561c->mUnk_498, 0xa000);
    func_02094000_inline_2(&o->mUnk_dc, 0, func_02094000_inline(&data_0217561c->mUnk_498, 0x19000) + 0x19000,
                           f + 0xa000, 0, d + 0x100, 0);
    o->mUnk_10c = func_02094000_inline(&data_0217561c->mUnk_498, 0x3c000) + 0x3c000;
    p = func_02094000_inline(&data_0217561c->mUnk_498, 0xc000) + 0xe000;
    q = func_02094000_inline(&data_0217561c->mUnk_498, 0x200) + 0x400;
    o->mUnk_fc = 0;
    o->mUnk_100 = q;
    o->mUnk_104 = 0x2000;
    o->mUnk_108 = p;
    if (func_02061818() == 2) {
        o->mUnk_b4 = 0;
        o->mUnk_b8 = 0xffff;
        o->mUnk_110 = 0;
    } else {
        o->mUnk_b4 = (u16) func_02094000_inline(&data_0217561c->mUnk_498, 0x4b);
        o->mUnk_b8 = (u16) func_02094000_inline(&data_0217561c->mUnk_498, 0x96) + 0x12c;
        o->mUnk_110 = 1;
    }
    data_0217b0d8++;
}

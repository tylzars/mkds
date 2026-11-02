#include "Main/Unknown/code_0209219c.h"
#include "Main/Unknown/code_020924d8.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_02156000.h"

static inline u16 func_0209219c_inline(u32 n) {
    Unk020f41c4_B *b;
    u32 m;
    u32 r;

    if (n == 0x10000) {
        b = func_020d22d0();
        b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
        return ((b->mUnk_00 >> 32) * 0x10000) >> 32;
    } else {
        b = func_020d22d0();
        m = (u16) n;
        if (m == 0) {
            r = 0;
        } else {
            b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
            if (m == 0) {
                r = b->mUnk_00 >> 32;
            } else {
                r = ((b->mUnk_00 >> 32) * m) >> 32;
            }
        }
    }
    return (u16) r;
}

void func_02092484(void) {
    func_0209bef0(CreateBasabasa, func_0209280c, func_02092928);
}

void func_02092468(void) {
    func_0209bf48(0, func_020924d8, 0);
}

void func_0209219c(u32 a, const Vec3 *b, const Vec3 *c, u32 d, s32 e, u16 f) {
    Unk0209219c *p;
    Unk020f41c4_B *r;
    u32 n;
    u16 w;

    p = func_0209bbfc(func_02100138(0x19f));
    if (p == 0) {
        return;
    }
    p->mUnk_00.mUnk_02 |= data_usa_02156460;
    p->mUnk_00.mUnk_02 |= data_usa_02156464;
    p->mUnk_00.mUnk_02 |= data_usa_02156468;
    p->mUnk_bc = e;
    p->mUnk_c0 = f;
    r = func_020d22d0();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    p->mUnk_b0 = (u16) (((r->mUnk_00 >> 32) * 30) >> 32);
    n = (d << 12) >> 16;
    w = func_0209219c_inline(n);
    p->mUnk_b4 = d + w;
    n = (a << 12) >> 16;
    w = func_0209219c_inline(n);
    p->mUnk_b8 = a + w;
    p->mUnk_00.mUnk_04 = *b;
    p->mUnk_a0 = *c;
    p->mUnk_d4 = 0;
    p->mUnk_d0 = 0;
}

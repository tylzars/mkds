#include "00/code_021a4654.h"
#include "00/code_0218e368.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "code_02134d30.h"
#include "code_02135014.h"
#include "code_02139f70.h"

static inline u16 func_ov000_021a4654_inline(u16 v1) {
    return ((v1 >> 8) & 0xff) | ((v1 << 8) & 0xff00);
}

s32 func_ov000_021a4654(const u8 *a, u32 b, Unk021a4654 *c, Unk021a8f84 **d) {
    Unk021a8f84 *e;

    e = 0;
    c->mUnk_01 = 2;
    c->mUnk_02 = func_ov000_021a4654_inline(b);
    if (a == 0) {
        c->mUnk_04 = 0;
    } else {
        c->mUnk_04 = func_ov000_0218e374((u32) a);
    }
    if (c->mUnk_04 == -1) {
        if (func_0213a074(a, data_ov000_021b4418) != 0) {
            e = func_ov000_021a8f84(a);
            if (e == 0) {
                return 0;
            }
            c->mUnk_04 = **e->mUnk_0c;
        }
    }
    if (d != 0) {
        *d = e;
    }
    return 1;
}

void func_ov000_021a46d4(void) {
    Unk021a8f84 *a;
    Unk021a46d4 *b;
    Unk021a46d4 *d;

    a = func_ov000_0218e5e4();
    if (a != 0) {
        data_ov000_021b5df8 = 0;
        d = (Unk021a46d4 *) data_ov000_021b5dfc;
        for (; data_ov000_021b5df8 < 5; data_ov000_021b5df8++) {
            b = (Unk021a46d4 *) a->mUnk_0c[data_ov000_021b5df8];
            if (b == 0) {
                break;
            }
            d[data_ov000_021b5df8] = *b;
        }
    }
}

void func_ov000_021a471c(Unk021a471c *a, const u8 *b) {
    s32 c;
    s32 d;

    c = func_0213a434(b) + 1;
    d = 0x800 - a->mUnk_800;
    if (c > d) {
        c = d;
    }
    if (c != 0) {
        func_02134eb8(&a->mUnk_000[a->mUnk_800], b, c);
        a->mUnk_800 += c;
        a->mUnk_000[a->mUnk_800 - 1] = 0;
    }
}

void func_ov000_021a4760(Unk021a471c *a, s32 b) {
    u8 c[0x18];

    func_02135014(c, data_ov000_021b4428, b);
    func_ov000_021a471c(a, c);
}

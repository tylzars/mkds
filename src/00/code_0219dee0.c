#include "00/code_0219dee0.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219eac8.h"
#include "00/code_0218b000.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/code_0218cdc4.h"
#include "00/code_0218b434.h"
#include "00/code_021a3264.h"
#include "00/code_021a2950.h"
#include "00/code_021a4654.h"

BOOL func_ov000_0219dfe4(s32 a) {
    BOOL c;
    BOOL d;
    s32 e;
    u32 f;
    u32 g;
    s32 h;
    c = FALSE;
    e = 0;
    for (; e < (s32) func_ov000_0218b474((u32) data_ov000_021b566c->mUnk_e4); e++) {
        f = func_ov000_0218b480((u32) data_ov000_021b566c->mUnk_e4, e);
        if (data_ov000_021b566c->mUnk_15 == 0) {
            g = func_ov000_0218b2a8((Unk0218af28 *) f, data_ov000_021b40c4, 0);
            d = FALSE;
            for (h = 1; h <= data_ov000_021b566c->mUnk_0d; h++) {
                if (g == data_ov000_021b566c->mUnk_f4[h]) {
                    func_ov000_0218b4d4((struct Unk0218b668 *) data_ov000_021b566c->mUnk_e4, f);
                    e--;
                    d = TRUE;
                    break;
                }
            }
            if (d != FALSE) {
                continue;
            }
        }
        if (data_ov000_021b566c->mUnk_45c != 0) {
            g = ((s32(*)(s32, u32)) data_ov000_021b566c->mUnk_45c)(e, data_ov000_021b566c->mUnk_460);
            if ((s32) g > 0) {
                if ((s32) g > 0x7fffff) {
                    g = 0x7fffff;
                }
                func_ov000_0218b358((Unk0218af28 *) f, data_ov000_021b40cc, (g << 8) | func_ov000_021a3448(0x100));
            } else {
                func_ov000_0218b4d4((struct Unk0218b668 *) data_ov000_021b566c->mUnk_e4, f);
                e--;
                c = TRUE;
            }
        } else {
            func_ov000_0218b358((Unk0218af28 *) f, data_ov000_021b40cc, func_ov000_021a3448(0x80));
        }
    }
    if (a != 0 && func_ov000_0218b474((u32) data_ov000_021b566c->mUnk_e4) != 0) {
        func_ov000_0218b464(data_ov000_021b566c->mUnk_e4, 0, data_ov000_021b40cc, 0);
    }
    if (c != FALSE && func_ov000_0218b474((u32) data_ov000_021b566c->mUnk_e4) == 0) {
        return FALSE;
    }
    return TRUE;
}

void func_ov000_0219dee0(s32 a, Unk021a471c *b, void *c) {
    s32 d;
    switch (a) {
        case 8:
            func_ov000_021a4760(b, data_ov000_021b566c->mUnk_14);
            return;
        case 0xa:
            func_ov000_021a4760(b, data_ov000_021b566c->mUnk_16);
            return;
        case 0x32:
            func_ov000_021a4760(b, data_ov000_021b566c->mUnk_1e8);
            return;
        case 0x33:
            func_ov000_021a4760(b, data_ov000_021b566c->mUnk_15);
            return;
        case 0x34:
            func_ov000_021a4760(b, data_ov000_021b566c->mUnk_20);
            return;
        case 0x35:
            func_ov000_021a4760(b, 3);
            return;
        case 0x36:
            func_ov000_021a4760(b, 1);
            return;
    }
    d = a - 100;
    if (data_ov000_021b5698[d][0] != 0) {
        if (data_ov000_021b5699[d * 12] != 0) {
            func_ov000_021a471c(b, *(const u8 **) &data_ov000_021b56a0[d * 12]);
        } else {
            func_ov000_021a4760(b, **(s32 **) &data_ov000_021b56a0[d * 12]);
        }
    }
}

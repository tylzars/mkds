#include "00/code_0218d818.h"
#include "00/code_0219981c.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_02197b34.h"
#include "00/code_02197ddc.h"
#include "00/code_02197e58.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_02199a00.h"
#include "00/code_02199a0c.h"
#include "00/code_0219a014.h"
#include "code_021382a8.h"
#include "Main/Unknown/code_02133000.h"

u32 func_ov000_021998d8(Gt2Connection *a, s32 b, u32 c, const u8 *d, s32 e, s32 *f) {
    Unk0219981cEntry g;
    s32 h;
    s32 i;
    Unk0219981cEntry *j;
    h = DarrayGetCount(a->mUnk_5c);
    for (i = 0; i < h; i++) {
        j = DarrayGetElement(a->mUnk_5c, i);
        if (j->mUnk_0c == c) {
            *f = 0;
            return 1;
        }
        if (func_ov000_0219a014(j->mUnk_0c, c) > 0) {
            break;
        }
    }
    if (GetBufferUnusedSize(&a->mUnk_44) < e) {
        *f = 1;
        return 1;
    }
    g.mUnk_00 = a->mUnk_44.mLength;
    g.mUnk_04 = e;
    g.mUnk_08 = b;
    g.mUnk_0c = c;
    DarrayInsertSorted(a->mUnk_5c, &g, func_ov000_02199a00);
    if (h + 1 != DarrayGetCount(a->mUnk_5c)) {
        *f = 1;
        return 1;
    }
    AppendBufferBytes(&a->mUnk_44, d, e);
    if (h == 0) {
        if (func_ov000_02198ba8(a, a->mUnk_66, c - 1) == FALSE) {
            return 0;
        }
    } else {
        j = DarrayGetElement(a->mUnk_5c, h);
        if (j->mUnk_0c == c) {
            j = DarrayGetElement(a->mUnk_5c, h - 1);
            if ((u16) func_ov000_0219a014(c, j->mUnk_0c) > 1) {
                if (func_ov000_02198ba8(a, j->mUnk_0c + 1, c - 1) == FALSE) {
                    return 0;
                }
            }
        }
    }
    *f = 0;
    return 1;
}

void func_ov000_02199878(Gt2Connection *a, Unk0219981cEntry *b, s32 c) {
    s32 d = 0;
    s32 e = b->mUnk_00;
    s32 f = b->mUnk_04;
    s32 g;
    s32 i;
    Unk0219981cEntry *h;
    DarrayRemove(a->mUnk_5c, c);
    g = DarrayGetCount(a->mUnk_5c);
    for (i = 0; i < g; i++) {
        h = DarrayGetElement(a->mUnk_5c, i);
        if (h->mUnk_00 > e) {
            h->mUnk_00 -= f;
            if (d <= h->mUnk_00 + h->mUnk_04) {
                d = h->mUnk_00 + h->mUnk_04;
            }
        }
    }
    RemoveBufferBytes(&a->mUnk_44, e, f);
}

u32 func_ov000_0219981c(Gt2Connection *a) {
    s32 b;
    Unk0219981cEntry *c;
top:
    for (b = DarrayGetCount(a->mUnk_5c) - 1; b >= 0; b--) {
        c = DarrayGetElement(a->mUnk_5c, b);
        if (c->mUnk_0c == a->mUnk_66) {
            if (func_ov000_02199a0c(a, c->mUnk_08, (u32) (a->mUnk_44.mData + c->mUnk_00), c->mUnk_04) == 0) {
                return 0;
            }
            func_ov000_02199878(a, c, b);
            goto top;
        }
    }
    return 1;
}

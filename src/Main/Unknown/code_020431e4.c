#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_02039708.h"
#include "Main/Unknown/code_02039520.h"
#include "Main/Unknown/code_0204a9e4.h"
#include "Main/Unknown/code_020470c4.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma opt_rebuildconditionals off

static inline s32 func_020431e4_inline(Unk0217aa00 *p) {
    s32 r = 0;
    if ((p == 0 ? 0 : p->mUnk_0000) != 0 && p->mUnk_0004 != 13) {
        r = 1;
    }
    return r;
}

void func_020431e4(void) {
    s32 i;
    s32 k;
    u16 j;
    s32 w;
    s32 t;
    Unk02175628 *p;
    Unk021759c0 *q;
    Unk0217aa00 *z;
    s32 s;

    for (i = 0; i < 10; i++) {
        p = &data_02175628[(u32) i];
        func_02039728(p);
        func_02039520(p, 0xff3, 0x1e, 0xa);
        p->mUnk_3c = 0;
        p->mUnk_40 = 0;
        p->mUnk_44 = 0;
        p->mUnk_42 = 0x2fff;
        func_0204a9e4((u32) &p->mUnk_28);
        func_020470c4((u32) &p->mUnk_48);
    }
    data_02175628[8].mUnk_3c = 5;
    data_02175628[9].mUnk_3c = 6;
    data_02175624->mUnk_08 = 0;
    data_02175624->mUnk_0c = 0;
    p = data_02175628;
    for (k = 0; k < 10; k++) {
        func_02039728(p);
        p->mUnk_40 = 0;
        func_02039520(p, 0xff3, 0x1e, 0xa);
        p++;
    }
    q = data_021759c0;
    z = data_0217aa00;
    for (j = 0; j < 8; j++) {
        s = q->mUnk_68[j].mUnk_08.mUnk_00;
        t = 0;
        w = q->mUnk_68[j].mUnk_08.mUnk_0c;
        if ((u32) s <= 3 && ((1 << s) & 0xd)) {
            t = 1;
        }
        if (t != 0) {
            if (j == q->mUnk_62) {
                if (func_020431e4_inline(z) != 0) {
                    data_02175628[w].mUnk_3c = 4;
                } else if (q->mUnk_00c == 2) {
                    data_02175628[w].mUnk_3c = 1;
                } else {
                    data_02175628[w].mUnk_3c = 2;
                }
            } else if (s == 2) {
                data_02175628[w].mUnk_3c = 1;
            } else if (q->mUnk_08 == 5) {
                data_02175628[w].mUnk_3c = 7;
            } else {
                data_02175628[w].mUnk_3c = 4;
            }
        } else if (s == 1) {
            data_02175628[w].mUnk_3c = 3;
        }
    }
}

void func_02043410(void) {
    u16 i;
    u16 j;
    Unk0217aa00 *z;
    Unk02175628 *p;

    for (i = 0; i < 8; i++) {
        p = &data_02175628[i];
        func_02039728(p);
        func_02039520(p, 0xff3, 0x1e, 0xa);
        p->mUnk_3c = 0;
        p->mUnk_40 = 0;
        p->mUnk_44 = 0;
        p->mUnk_42 = 0x2fff;
        func_0204a9e4((u32) &p->mUnk_28);
        func_020470c4((u32) &p->mUnk_48);
    }
    z = data_0217aa00;
    if (func_020431e4_inline(z) != 0) {
        for (j = 0; j < 8; j++) {
            if (z->mUnk_15f6 & (1 << z->mUnk_1e8c[j])) {
                data_02175628[j].mUnk_3c = 4;
            }
        }
    }
    data_02175624->mUnk_08 = 0;
    data_02175624->mUnk_0c = 0;
}

void func_02043544(u32 a) {
    if (func_0205e0a0() == 2 && a != 0) {
        data_02175624->mUnk_04 |= 2;
    } else {
        data_02175624->mUnk_04 &= ~2;
    }
}

u32 func_0204359c(void) {
    return (data_02175624->mUnk_04 & 1) != 0;
}

u16 func_020435bc(void) {
    return 9;
}

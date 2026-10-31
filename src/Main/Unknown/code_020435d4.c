#include "Main/Unknown/code_020435d4.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_02039520.h"
#include "Main/Unknown/code_02046c10.h"
#include "Main/Unknown/code_02050034.h"
#include "Main/Unknown/code_0204a5f8.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"

static inline s32 func_02043648_inline(Unk0217aa00 *p) {
    s32 r = 0;
    if ((p == 0 ? 0 : p->mUnk_0000) != 0 && p->mUnk_0004 != 13) {
        r = 1;
    }
    return r;
}

void func_020435d4(u32 a) {
    if (a != 0) {
        data_02175624->mUnk_04 |= 1;
        return;
    }
    data_02175624->mUnk_04 &= ~1;
}

void func_0204360c(s32 a, u32 b) {
    if (data_02175628[a].mUnk_3c == 3 || data_02175628[a].mUnk_3c == 7) {
        data_02175628[a].mUnk_40 |= b;
    }
}

void func_02043648(void) {
    u8 i;
    u16 y;
    u16 a;
    u16 b;
    u16 x;
    s32 k;
    u16 m;
    u16 t;
    s32 n;
    Unk02175628 *p;
    s32 o;
    s32 q;
    s32 c;
    s32 f;
    s32 s;
    u16 w;

    x = data_02175624->mUnk_02;
    y = func_02046c10();
    a = x;
    b = y;
    k = data_021759c4->mUnk_30_3;
    if (func_02043648_inline(data_0217aa00) != 0) {
        a = func_0204ffe8(func_02050064(data_02175624->mUnk_08));
        b = *(u16 *) &data_0217aa00->mUnk_15bc_view.mUnk_0c[func_02050064(data_02175624->mUnk_08)].mUnk_00[2];
        func_02050064(data_02175624->mUnk_08);
    }
    for (i = 0; i < 10; i++) {
        m = 0;
        n = 0xffff;
        o = m;
        f = (data_02175624->mUnk_04 & 1) ? 1 : 0;
        q = 0;
        c = (func_0205e0a0() != 2 || (data_02175624->mUnk_04 & 2)) ? 1 : 0;
        p = &data_02175628[i];
        w = data_02175624->mUnk_04;
        if (!(w & 8)) {
            s = p->mUnk_3c;
            if (f == 0) {
                f = p->mUnk_44;
            }
            switch (s) {
                case 1:
                    if (f == 0) {
                        if (c != 0) {
                            m = func_0204a664((Unk02175650 *) &p->mUnk_28);
                        }
                    } else {
                        q = 1;
                    }
                    n = 0xffff;
                    o = 0;
                    break;
                case 2:
                    if (f == 0) {
                        if (c != 0) {
                            m = x;
                            if (w & 4) {
                                m = x & 0xffcf;
                                if (x & 0x20) {
                                    m |= 0x10;
                                }
                                if (x & 0x10) {
                                    m |= 0x20;
                                }
                            }
                            func_0204a798((Unk02175650 *) &p->mUnk_28, m);
                        }
                    } else {
                        q = 1;
                    }
                    n = y;
                    o = k;
                    break;
                case 3:
                case 7:
                    if (f != 0) {
                        q = 1;
                    } else {
                        o = 0;
                        m = p->mUnk_40;
                        n = 0xffff;
                        p->mUnk_40 = o;
                    }
                    break;
                case 5:
                    m = a;
                    n = b;
                    o = 0;
                    break;
                case 4:
                    if (f == 0) {
                        if (c != 0) {
                            m = func_0204ffe8(func_02050064(i));
                            if (data_02175624->mUnk_04 & 4) {
                                t = m & 0xffcf;
                                if (m & 0x20) {
                                    t |= 0x10;
                                }
                                if (m & 0x10) {
                                    t |= 0x20;
                                }
                                m = t;
                            }
                        }
                    } else {
                        q = 1;
                    }
                    n = *(u16 *) &data_0217aa00->mUnk_15bc_view.mUnk_0c[func_02050064(i)].mUnk_00[2];
                    o = data_0217aa00->mUnk_15bc_view.mUnk_0c[func_02050064(i)].mUnk_06_7;
                    break;
                case 6:
                    m = x;
                    n = y;
                    o = k;
                    break;
                case 0:
                    m = 0;
                    n = 0xffff;
                    o = m;
                    break;
            }
        }
        t = m & p->mUnk_42;
        if (q == 0) {
            func_02039530(t, p);
        }
        func_02046ca8((Unk02175628_48 *) &p->mUnk_48, n, o);
    }
}

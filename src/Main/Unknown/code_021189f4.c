#include "Main/Unknown/code_02119e14.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/code_02119a90.h"
#include "Main/Unknown/code_021189f4.h"

#include "00/code_02182fdc.h"
#include "Main/Unknown/code_0204799c.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02029520.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_02119544.h"
#include "Main/Unknown/code_021196f4.h"
#include "Main/Unknown/code_0211952c.h"
#include "Main/Unknown/code_021196dc.h"
#include "Main/Unknown/code_02119ac4.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211de40.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_0211f2b8.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_02119dfc.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0201ea58.h"
#include "code_0212df7c.h"
#include "registers.h"

#pragma thumb on
static inline s32 func_02119340_inline(Unk02175628Index i) {
    s32 g;
    s32 f;
    u16 v;

    g = 0;
    f = 0;
    v = data_02175674[i].mUnk_00;
    if (v == 0 && data_02175680[i].mUnk_00 < 5) {
        f = 1;
    }
    if (f == 0 && data_0217567c[i].mUnk_00 == 0 && v != 0) {
        g = 1;
    }
    return g;
}

void func_02119340(void) {
    s32 a;
    Unk02175628Index i;
    s16 w;

    a = -1;
    i = UNK_02175628_INDEX_8;
    func_02119d78();
    if (func_02119340_inline(i) != 0) {
        a = func_0201ea84(data_0217d364->mUnk_14, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00 + 0x20);
    }
    if ((u16)(data_02175628[i].mUnk_00 & 2) != 0 || (func_02119340_inline(i) != 0 && func_02128210(data_02175670[i].mUnk_00, data_02175672[i].mUnk_00) != 0)) {
        if (func_02119dfc() == 0) {
            if (*(vu16 *)0x027ffc40 == 2) {
                func_021281c8(-1);
            } else {
                func_021281c8(0xe);
            }
            func_021199f8();
            data_0217d364->mUnk_6c = 2;
            func_02128310(0);
        }
        return;
    }
    if ((u32)a <= 3) {
        w = data_0215caac[a];
        if (data_0217d364->mUnk_50 == w) {
            data_0217d364->mUnk_54 = 0;
        }
        data_0217d364->mUnk_50 = w;
        func_02119ba8();
        return;
    }
    if (a == 4) {
        func_02119ba8();
        return;
    }
    if ((u16)(data_02175628[i].mUnk_00 & 1) != 0) {
        func_02119ba8();
        data_0217d364->mUnk_54 = 0;
        return;
    }
    if (func_020ae408(8, 0x40) != 0) {
        data_0217d364->mUnk_50 = data_0217d364->mUnk_50 - 1;
        if (data_0217d364->mUnk_50 < 0) {
            data_0217d364->mUnk_50 = 3;
        }
        if (*(vu16 *)0x027ffc40 != 2) {
            func_0212ecc0(&data_0217d068, 0, 0);
        }
        return;
    }
    if (func_020ae408(8, 0x80) != 0) {
        data_0217d364->mUnk_50 = data_0217d364->mUnk_50 + 1;
        if (data_0217d364->mUnk_50 >= 4) {
            data_0217d364->mUnk_50 = 0;
        }
        if (*(vu16 *)0x027ffc40 != 2) {
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    }
}

void func_021192c4(void) {
    func_02119d78();
    if (data_0217d364->mUnk_3c == 5) {
        data_0217d364->mUnk_54 = 1;
    }
    data_0217d364->mUnk_3c++;
    if (data_0217d364->mUnk_3c >= 10) {
        if (func_02119dfc() == 0) {
            if (data_0217d364->mUnk_40 == 0) {
                func_02119e14();
                if (func_0211e130() != 0) {
                    func_0211e0c4(0);
                    func_02119ac4();
                    return;
                }
                func_02119e50();
                data_0217d364->mUnk_6c = 1;
                func_021199f8();
                return;
            }
            func_02119ac4();
        }
    }
}

void func_02119260(void) {
    switch (data_0217d364->mUnk_40) {
    case 0:
    case 1:
    case 3:
        if (func_021277c8() != 0) {
            func_02119a90();
        }
        break;
    case 2:
        data_0217d364->mUnk_3c++;
        if (data_0217d364->mUnk_3c >= 0xf) {
            if (func_021277c8() != 0 || func_02127788() != 0) {
                func_02119a90();
            }
        }
        break;
    }
}

void func_02119208(void) {
    s32 v;

    if (func_02127788() != 0) {
        func_02119a38();
        if (*(vu16 *)0x027ffc40 == 2) {
            v = func_02127794();
            switch (v) {
            case 0:
                func_0212ecc0(&data_0217d068, 0, 7);
                break;
            case -1:
            case 1:
                func_0212ecc0(&data_0217d068, 0, 0x10);
                break;
            }
        }
    }
}

void func_0211913c(void) {
    s32 v;

    switch (data_0217d364->mUnk_40) {
    case 0:
    case 1:
    case 3:
        if (func_021277ac() != 0) {
            v = func_02127794();
            switch (v) {
            case 0:
                func_02119e50();
                data_0217d364->mUnk_6c = 1;
                func_021199f8();
                break;
            case -1:
            case 1:
                func_02119bdc();
                break;
            }
        }
        break;
    case 2:
        data_0217d364->mUnk_3c++;
        if (data_0217d364->mUnk_3c >= 0xf) {
            if (func_021277ac() != 0) {
                v = func_02127794();
                switch (v) {
                case 0:
                    func_02119e50();
                    data_0217d364->mUnk_6c = 1;
                    func_021199f8();
                    if (*(vu16 *)0x027ffc40 == 2) {
                        func_0211f378();
                    }
                    break;
                case -1:
                case 1:
                    func_02119bdc();
                    break;
                }
            }
        }
        break;
    }
}

void func_02118f98(void) {
    s32 a;
    s16 v;
    s32 w;
    s32 i;

    data_0217d364->mUnk_3c++;
    if (*(vu16 *)0x027ffc40 == 2) {
        return;
    }
    if (data_0217d364->mUnk_40 == 0) {
        if (data_0217d364->mUnk_6c == 1) {
            if (func_0211e130() != 0) {
                a = 1;
            } else {
                a = 0;
            }
        } else {
            a = 1;
        }
    } else {
        a = 1;
    }
    func_020ae4c0(1, 0, 0x100, data_0217d364->mUnk_3c, 10);
    v = func_020ae4c0(1, 0, -0xc0, data_0217d364->mUnk_3c, 10);
    if (a != 0) {
        w = data_0217d364->mUnk_04->mUnk_06;
        data_0217d364->mUnk_44 = v;
        data_0217d364->mUnk_1c[0].mUnk_06 = v;
        data_0217d364->mUnk_1c[2].mUnk_06 = v;
        data_0217d364->mUnk_1c[1].mUnk_06 = v;
        data_0217d364->mUnk_1c[4].mUnk_06 = v;
        data_0217d364->mUnk_1c[3].mUnk_06 = v;
        data_0217d364->mUnk_1c[5].mUnk_06 = v;
        data_0217d364->mUnk_1c[w].mUnk_06 = v;
        data_0217d364->mUnk_1c[w + 1].mUnk_06 = v;
        data_0217d364->mUnk_1c[w + 2].mUnk_06 = v;
        data_0217d364->mUnk_1c[w + 3].mUnk_06 = v;
        data_0217d364->mUnk_1c[w + 4].mUnk_06 = v;
        data_0217d364->mUnk_1c[w + 5].mUnk_06 = v;
    }
    if (data_0217d364->mUnk_6c != 2) {
        w = data_0217d364->mUnk_10->mUnk_06;
        data_0217d364->mUnk_48 = v - 0x20;
        data_0217d364->mUnk_20[0x14].mUnk_06 = v - 0x20;
        data_0217d364->mUnk_20[0x13].mUnk_06 = v - 0x20;
        data_0217d364->mUnk_20[2].mUnk_06 = v - 0x20;
        data_0217d364->mUnk_20[1].mUnk_06 = v - 0x20;
        data_0217d364->mUnk_20[0].mUnk_06 = v - 0x20;
        for (i = 0; i < 8; i++) {
            data_0217d364->mUnk_20[data_0215cacc[i]].mUnk_06 = v - 0x20;
        }
        v -= 0x20;
        for (i = 0; i < 4; i++) {
            data_0217d364->mUnk_20[data_0215caa4[i]].mUnk_06 = v;
            data_0217d364->mUnk_20[w + data_0215cab4[i]].mUnk_06 = v;
        }
    }
}

s32 func_02118e64(void) {
    s32 i;
    u16 *p;

    data_0217d364->mUnk_34 = data_0217d364->mUnk_38;
    switch (data_0217d364->mUnk_34) {
    case 0:
        func_021196dc();
        break;
    case 1:
        func_02119544();
        break;
    case 2:
        func_0211952c();
        break;
    case 3:
        func_02119340();
        break;
    case 4:
        func_021192c4();
        break;
    case 5:
        func_02119260();
        break;
    case 6:
        func_02119208();
        break;
    case 7:
        func_0211913c();
        break;
    case 8:
        func_02118f98();
        break;
    }
    func_0211a07c();
    if (*(vu16 *)0x027ffc40 != 2) {
        if (data_0217d364->mUnk_60 != 0 && func_020d0ec4() != 0) {
            p = func_020d0e58();
            func_02016468(0x1f, 0, func_020d0ea0(), 0xe0);
            func_02016468(0x17, 0x20, func_020d0e7c(), 0xdc0);
            for (i = 0; i < 11; i++) {
                func_02016468(0x1b, ((i + 8) * 0x20 + 0x16) * 2, p + ((i + 8) * 0x20 + 0x16), 0x14);
            }
            data_0217d364->mUnk_60 = 0;
        }
        func_02124c30(data_0217d364->mUnk_04, data_0217d364->mUnk_00, data_0217d364->mUnk_08, data_0217d364->mUnk_64, data_0217d364->mUnk_1c);
        func_02124c30(data_0217d364->mUnk_10, data_0217d364->mUnk_0c, data_0217d364->mUnk_18, data_0217d364->mUnk_68, data_0217d364->mUnk_20);
    } else {
        func_0211f39c();
    }
    if (data_0217d364->mUnk_34 == 8 && data_0217d364->mUnk_3c >= 10) {
        return data_0217d364->mUnk_6c;
    }
    return 0;
}

void func_02118e30(void) {
    reg_G2_BG0OFS = (-data_0217d364->mUnk_44 << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = (-data_0217d364->mUnk_48 << 16) & 0x1ff0000;
}

void func_02118d44(void) {
    Unk020b4934 *a = 0;
    Unk02021dc8 *b = 0;
    Unk020b4a44 *c = 0;
    Unk020b4934 *d = 0;
    Unk02021dc8 *e = 0;
    Unk020b4a44 *f = 0;
    Unk020b4934 *g = 0;
    Unk020b47d8 *h = 0;
    Unk020b4a44 *i = 0;

    if (*(vu16 *)0x027ffc40 != 2) {
        func_020b496c(&g, func_0204799c(data_0216d690));
        func_020b4a7c(&i, func_0204799c(data_0216d6b8));
        func_020b4810(&h, func_0204799c(data_0216d6bc));
        func_020b49f4(&a, func_0204799c(data_0216d6ac));
        func_020b48ec(&b, func_0204799c(data_0216d694));
        func_020b4a7c(&c, func_0204799c(data_0216d6a0));
        func_020b49f4(&d, func_0204799c(data_0216d69c));
        func_020b48ec(&e, func_0204799c(data_0216d6b4));
        func_020b4a7c(&f, func_0204799c(data_0216d68c));
        func_0211de98();
        func_0211e024();
        func_0211f328();
    }
}

void func_02118b48(void) {
    Unk020b4934 *a = 0;
    Unk020b4a44 *b = 0;
    Unk020b4934 *c = 0;
    Unk020b4a44 *d = 0;
    Unk020b4934 *e = 0;
    Unk020b47d8 *f = 0;
    Unk020b4a44 *g = 0;
    u16 *p;

    if (*(vu16 *)0x027ffc40 == 2) {
        data_0217d360->mUnk_14 = func_0204799c(data_0216d6a4);
        return;
    }
    func_020b4934(&e, func_0204799c(data_0216d690));
    func_020b4a44(&g, func_0204799c(data_0216d6b8));
    func_020b47d8(&f, func_0204799c(data_0216d6bc));
    data_0217d360->mUnk_20 = func_02036bec(data_0217d360->mUnk_2c, 0x800);
    data_0217d360->mUnk_04 = func_0204799c(data_0216d698);
    data_0217d360->mUnk_08 = func_0204799c(data_0216d6a8);
    func_020b49bc(&a, func_0204799c(data_0216d6ac));
    func_020b48b4(&data_0217d360->mUnk_00, func_0204799c(data_0216d694));
    func_020b4a44(&b, func_0204799c(data_0216d6a0));
    data_0217d360->mUnk_10 = func_0204799c(data_0216d6b0);
    data_0217d360->mUnk_14 = func_0204799c(data_0216d6a4);
    func_020b49bc(&c, func_0204799c(data_0216d69c));
    func_020b48b4(&data_0217d360->mUnk_0c, func_0204799c(data_0216d6b4));
    func_020b4a44(&d, func_0204799c(data_0216d68c));
    p = b->mUnk_0c;
    if (func_020cccb4() != 0x18 && func_020cccb4() != 0xc) {
        func_02016468(4, 0, e->mUnk_14, e->mUnk_10);
        func_02016468(0xf, 0, g->mUnk_0c, 0x100);
        func_02016468(8, 0, &f->mUnk_0c, f->mUnk_08);
        func_02016468(8, 0x800, data_0217d360->mUnk_20, 0x800);
    }
    func_02016468(0x13, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(0xe, 0, b->mUnk_0c, 0x1a0);
    func_02016468(0xe, 0x1c0, p + 0xe0, 0x40);
    func_02016468(0x23, 0, c->mUnk_14, c->mUnk_10);
    func_02016468(0x1e, 0, d->mUnk_0c, d->mUnk_08);
}

u32 func_021189f4(u32 a) {
    u32 r;
    s32 i;

    r = 0;
    switch (data_0217d360->mUnk_3c) {
    case 0:
    case 2:
        switch (a) {
        case 0:
        case 1:
        case 4:
        case 5:
            r = 1;
            break;
        default:
            if (func_0202967c() != 0) {
                r = func_02056dec(data_0215c8bc[a]);
            } else {
                r = func_02056dec(data_0215c95c[a][data_0215c7f0[func_0202969c()]]);
            }
            break;
        }
        break;
    case 1:
        switch (a) {
        case 0:
        case 1:
        case 4:
        case 5:
            r = 1;
            break;
        default:
            r = 0;
            for (i = 0; i < 4; i++) {
                if (i == 3) {
                    r |= func_02056dec(data_0215c8bc[a]);
                } else {
                    r |= func_02056dec(data_0215c95c[a][i]);
                }
            }
            break;
        }
        break;
    case 3:
        if (a == 0 || a == 4) {
            r = 1;
        }
        break;
    case 4:
        switch (a) {
        case 0:
        case 1:
        case 4:
        case 5:
            r = 1;
            break;
        default:
            if (func_0202967c() != 0) {
                r = func_0205fbb8(data_0215c8bc[a]);
            } else {
                r = func_0205fbb8(data_0215c95c[a][data_0215c7f0[func_0202969c()]]);
            }
            break;
        }
        break;
    }
    return r;
}
#pragma thumb off

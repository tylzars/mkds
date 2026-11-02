#include "Main/Unknown/code_0203206c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020cee0c.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_021281b4.h"
#include "code_02148ca0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02182fdc.h"
#include "code_0201ea58.h"
#include "code_0212df7c.h"

#pragma thumb on

void func_0203206c(void) {
    Unk020b4934 *a;
    Unk020b4a44 *b;
    Unk02021dc8 *c;
    Unk020b47d8 *d;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        LoadNcgrData(&a, FindSceneFile(data_021639b8));
        LoadNcgrData2(&a, FindSceneFile(data_021639d4));
        LoadNcerData(&c, FindSceneFile(data_021639f4));
        LoadNclrData(&b, FindSceneFile(data_02163a14));
        LoadNclrData(&b, FindSceneFile(data_02163a30));
        LoadNscrData(&d, FindSceneFile(data_02163a4c));
        LoadNscrData(&d, FindSceneFile(data_02163a6c));
    }
    LoadNcgrData2(&a, FindSceneFile(data_02163a90));
    LoadNcerData(&c, FindSceneFile(data_02163ab0));
    LoadNclrData(&b, FindSceneFile(data_02163ad0));
}

void func_02032138(void) {
    u32 a;
    u32 b;
    s32 y;

    a = 0x18;
    b = 0;
    if (data_02174e5c->mUnk_54 != 10) {
        a |= 2;
        b = 3;
    }
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (a << 8);
    *(vu16 *) 0x400000a = (*(vu16 *) 0x400000a & ~3) | b;
    *(vu32 *) 0x4000014 = (-data_02174e5c->mUnk_60 << 16) & 0x1ff0000;
    if (data_02174e5c->mUnk_60 != 0) {
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffff1fff) | 0x6000;
        *(vu16 *) 0x4000048 = (u32) ((*(vu16 *) 0x4000048 & ~0x3f) | 0x1f) | 0x20;
        *(vu16 *) 0x4000048 = (u32) ((*(vu16 *) 0x4000048 & 0xffffc0ff) | 0x1f00) | 0x2000;
        *(vu16 *) 0x400004a = (u32) ((*(vu16 *) 0x400004a & ~0x3f) | 0xd) | 0x20;
        y = data_02174e5c->mUnk_60 + 0xc0;
        *(vu16 *) 0x4000040 = 0xff;
        *(vu16 *) 0x4000044 = y & 0xff;
        y = data_02174e5c->mUnk_60 + 0xc0;
        *(vu16 *) 0x4000042 = 0xff00;
        *(vu16 *) 0x4000046 = y & 0xff;
    } else {
        *(vu32 *) 0x4000000 = *(vu32 *) 0x4000000 & 0xffff1fff;
    }
}

void func_0203223c(void) {
    if (data_02174e5c->mUnk_68 == 1) {
        func_0202b604();
        if (data_021759d0->mUnk_1c_2 != 0) {
            func_020cee5c();
        }
    }
    func_02036ab0(data_02174e5c->mUnk_40);
    data_02174e5c = NULL;
}

s32 func_02032280(void) {
    s32 a;
    Unk02175628Index v1;
    Unk02174e5c *o;
    Unk02174e14_00 *q;
    s32 b;
    s32 c;
    s32 d;
    BOOL f;
    BOOL e;
    s32 g;
    s32 h;
    u32 t;
    s32 i;
    const void *p;
    const void *p1;

    a = 0;
    v1 = UNK_02175628_INDEX_8;
    o = data_02174e5c;
    q = &o->mUnk_00[1];
    switch (o->mUnk_54) {
        case 3:
            func_020328c8(1);
            func_020328f8(1);
            data_02174e5c->mUnk_58 = data_02174e5c->mUnk_58 + 1;
            if (data_02174e5c->mUnk_58 < 10) {
                data_02174e5c->mUnk_5c = func_020ae4c0(1, 0xee, a, data_02174e5c->mUnk_58, 10);
                data_02174e5c->mUnk_60 = func_020ae4c0(1, -0xc0, a, data_02174e5c->mUnk_58, 10);
            } else {
                data_02174e5c->mUnk_58 = a;
                data_02174e5c->mUnk_5c = a;
                data_02174e5c->mUnk_60 = a;
                data_02174e5c->mUnk_54 = 4;
            }
            func_02032940();
            break;
        case 4:
            b = o->mUnk_44;
            d = ~a;
            c = 0;
            f = FALSE;
            e = FALSE;
            t = data_02175628[v1].mUnk_4c;
            if (t == 0 && data_02175628[v1].mUnk_58 < 5) {
                e = TRUE;
            }
            if (e == FALSE && data_02175628[v1].mUnk_54 == 0 && t != 0) {
                f = TRUE;
            }
            if (f != FALSE) {
                d = data_02175628[v1].mUnk_48;
                g = data_02175628[v1].mUnk_4a;
                c = func_02128210(d, g);
                d = func_0201ea84(q->mUnk_10, d, g);
            }
            if ((u16) (data_02175628[v1].mUnk_00 & 1) != 0) {
                func_020328f8(0);
                func_02032a20();
            } else if (d >= 0) {
                for (i = 0; i < data_02174e5c->mUnk_48; i++) {
                    if (d == data_02174e5c->mUnk_4c[i].mUnk_04) {
                        func_020328f8(data_02174e5c->mUnk_44 != i ? 1 : 0);
                        data_02174e5c->mUnk_44 = i;
                        func_02032a20();
                        break;
                    }
                }
            } else if ((u16) (data_02175628[v1].mUnk_00 & 2) != 0 || c != 0) {
                if (data_02174e5c->mUnk_68 == 0) {
                    data_02174e5c->mUnk_64 = 2;
                    data_02174e5c->mUnk_54 = 9;
                } else {
                    p = data_02163aec;
                    p1 = data_02163af0;
                    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                        p = GetBmgEntry(data_02174e5c->mUnk_50, 0x14);
                        p1 = GetBmgEntry(data_02174e5c->mUnk_50, 0x16);
                    }
                    func_021277f8(p, p1, 0);
                    data_02174e5c->mUnk_54 = 7;
                    func_020329dc(0);
                }
                func_02128310(0);
            } else if (func_020ae408(8, 0x40) != 0) {
                if (data_02174e5c->mUnk_44 == 0) {
                    if (data_02174e5c->mUnk_68 == 1) {
                        data_02174e5c->mUnk_44 = data_02174e5c->mUnk_48 - 1;
                    }
                } else {
                    data_02174e5c->mUnk_44 = data_02174e5c->mUnk_44 - 1;
                }
            } else if (func_020ae408(8, 0x80) != 0) {
                if (data_02174e5c->mUnk_44 == data_02174e5c->mUnk_48 - 1) {
                    if (data_02174e5c->mUnk_68 == 1) {
                        data_02174e5c->mUnk_44 = 0;
                    }
                } else {
                    data_02174e5c->mUnk_44 = data_02174e5c->mUnk_44 + 1;
                }
            }
            if (d < 0 && b != data_02174e5c->mUnk_44) {
                func_020328f8(1);
                func_0212ecc0(&data_0217d068, 0, 0);
            }
            break;
        case 7:
            if (func_02127788() != 0) {
                if (func_02127794() == 0 || func_02127794() == ~a) {
                    data_02174e5c->mUnk_54 = 4;
                } else {
                    data_0217aa00->mUnk_0454 |= 0x80;
                    data_02174e5c->mUnk_64 = 3;
                    data_02174e5c->mUnk_54 = 8;
                }
                func_020329dc(1);
                func_021277e4();
            }
            break;
        case 8:
            if (func_02054f58() == 1) {
                a = data_02174e5c->mUnk_64;
                data_02174e5c->mUnk_54 = 11;
            }
            break;
        case 5:
            o->mUnk_58 = o->mUnk_58 + 1;
            if (data_02174e5c->mUnk_58 >= 5) {
                data_02174e5c->mUnk_58 = a;
                data_02174e5c->mUnk_54 = 6;
                func_020328f8(1);
            }
            break;
        case 6:
            o->mUnk_58 = o->mUnk_58 + 1;
            if (data_02174e5c->mUnk_58 < 10) {
                data_02174e5c->mUnk_5c = func_020ae488(data_02174e5c->mUnk_58);
            } else {
                data_02174e5c->mUnk_58 = a;
                data_02174e5c->mUnk_54 = 9;
                if (data_02174e5c->mUnk_68 != 0) {
                    func_021282c8();
                }
            }
            func_020329a0();
            break;
        case 9:
            o->mUnk_58 = o->mUnk_58 + 1;
            if (data_02174e5c->mUnk_58 < 10) {
                data_02174e5c->mUnk_5c = func_020ae4c0(1, a, 0xee, data_02174e5c->mUnk_58, 10);
                data_02174e5c->mUnk_60 = func_020ae4c0(1, a, -0xc0, data_02174e5c->mUnk_58, 10);
            } else {
                data_02174e5c->mUnk_5c = a;
                data_02174e5c->mUnk_60 = a;
                data_02174e5c->mUnk_54 = 10;
            }
            func_02032940();
            break;
        case 10:
            a = o->mUnk_64;
            break;
    }
    if (data_02174e5c->mUnk_54 != 10) {
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
            func_02124c30(o->mUnk_00[0].mUnk_0c, o->mUnk_00[0].mUnk_08, o->mUnk_00[0].mUnk_14, data_02174e5c->mUnk_38,
                          o->mUnk_00[0].mUnk_18);
        }
        func_02124c30(q->mUnk_0c, q->mUnk_08, q->mUnk_14, data_02174e5c->mUnk_3c, q->mUnk_18);
    }
    return a;
}

void func_02032654(void *a, s32 b, void *c, void *d) {
    void *h;
    Unk02174e5c *o;
    Unk02174e14_00 *q;
    u8 v1[0x28];
    u32 k;
    s32 i;
    s32 n;
    s32 m;
    s32 j;
    s32 s;
    s32 e;
    Unk02153e20 *t;
    Unk02153e20 *g;

    h = func_02036948(a);
    data_02174e5c = func_02036bec(h, 0x6c);
    func_0214d05c_inline(data_02174e5c, 0x6c);
    data_02174e5c->mUnk_40 = h;
    data_02174e5c->mUnk_68 = b;
    data_02174e5c->mUnk_38 = c;
    data_02174e5c->mUnk_3c = d;
    data_02174e5c->mUnk_5c = 0xee;
    data_02174e5c->mUnk_60 = -0xc0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        data_02174e5c->mUnk_50 = FindSceneFile(data_02163af4);
    }
    switch (data_02174e5c->mUnk_68) {
        case 0:
            data_02174e5c->mUnk_54 = 3;
            data_02174e5c->mUnk_48 = 2;
            data_02174e5c->mUnk_4c = data_02153de8;
            break;
        case 1:
            data_02174e5c->mUnk_54 = 3;
            data_02174e5c->mUnk_48 = 3;
            data_02174e5c->mUnk_4c = data_02153df4;
            func_02050080();
            break;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_020258d4(0, v1, data_02163b00, data_02163b1c, data_02153e10[data_02174e5c->mUnk_68].mUnk_00, 1,
                      FindSceneFile);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        k = func_02148cb8();
        o = data_02174e5c;
        func_02025b20(o, data_02163b38, data_02163b58, data_02163b78, data_02163b94, data_02163bb0, NULL, FindSceneFile);
        func_02025a50(0, data_02174e5c->mUnk_40, o);
        n = o->mUnk_00[0].mUnk_0c->mUnk_06;
        m = o->mUnk_00[0].mUnk_14->mUnk_06;
        i = 0;
        if (m > 0) {
            t = data_02153e20;
            g = t;
            do {
                k -= func_02025a00(0, data_02174e5c->mUnk_40, o, t, k);
                func_0212426c(0, g->mUnk_00, o->mUnk_00[0].mUnk_14, GetBmgEntry(data_02174e5c->mUnk_50, g->mUnk_08),
                              o->mUnk_00[0].mUnk_0c, o->mUnk_00[0].mUnk_18);
                t++;
                g++;
                i++;
            } while (i < m);
        }
        if (data_02174e5c->mUnk_68 == 0) {
            s = 4;
            e = 6;
        } else {
            s = 0;
            e = 4;
        }
        for (j = s; j < s + e; j++) {
            o->mUnk_00[0].mUnk_18[j + n].mUnk_00 = 0;
        }
    }
    q = &data_02174e5c->mUnk_00[1];
    func_02025b20(q, data_02163bcc, data_02163bec, data_02163c0c, data_02153e08[data_02174e5c->mUnk_68].mUnk_00, NULL,
                  data_02153e0c[data_02174e5c->mUnk_68].mUnk_00, FindSceneFile);
    func_02025a50(1, data_02174e5c->mUnk_40, q);
    func_020328c8(0);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_021281c8(-1);
    } else {
        func_021281c8(0xe);
    }
    func_02128374();
    if (data_02174e5c->mUnk_68 == 1) {
        func_0212775c(0, 5);
        func_0212775c(1, 0xf);
    }
    data_0217b488->mUnk_08 = 0;
    func_02036820(data_02174e5c->mUnk_40);
}

void func_020328c8(s32 a) {
    s32 i;
    Unk02174e14_00 *p;

    p = &data_02174e5c->mUnk_00[1];
    for (i = 0; i < p->mUnk_0c->mUnk_06; i++) {
        p->mUnk_18[i].mUnk_00 = a;
    }
}

void func_020328f8(s32 a) {
    BOOL v;
    s32 i;
    Unk02174e14_00 *p;

    p = &data_02174e5c->mUnk_00[1];
    for (i = 0; i < data_02174e5c->mUnk_48; i++) {
        if (i == data_02174e5c->mUnk_44 && a != 0) {
            v = TRUE;
        } else {
            v = FALSE;
        }
        p->mUnk_18[data_02174e5c->mUnk_4c[i].mUnk_00].mUnk_00 = v;
    }
}

void func_02032940(void) {
    Unk02174e14_00 *p;
    s32 i;
    s32 n;
    s32 m;
    Unk02174e5c *o;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        o = data_02174e5c;
        n = o->mUnk_00[0].mUnk_0c->mUnk_06;
        m = o->mUnk_00[0].mUnk_14->mUnk_06;
        for (i = 0; i < m; i++) {
            o->mUnk_00[0].mUnk_18[i + n].mUnk_06 = data_02174e5c->mUnk_60;
        }
    }
    p = &data_02174e5c->mUnk_00[1];
    m = p->mUnk_0c->mUnk_06;
    for (i = 0; i < m; i++) {
        p->mUnk_18[i].mUnk_04 = data_02174e5c->mUnk_5c;
    }
}

void func_020329a0(void) {
    s32 i;
    Unk02174e14_00 *p;

    p = &data_02174e5c->mUnk_00[1];
    for (i = 0; i < data_02174e5c->mUnk_48; i++) {
        p->mUnk_18[data_02174e5c->mUnk_4c[i].mUnk_00].mUnk_04 = data_02174e5c->mUnk_5c;
    }
}

void func_020329dc(s32 a) {
    s32 i;
    Unk02174e14_00 *p;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        p = &data_02174e5c->mUnk_00[1];
        for (i = 0; i < data_02174e5c->mUnk_48; i++) {
            p->mUnk_18[data_02174e5c->mUnk_4c[i].mUnk_02].mUnk_00 = a;
        }
    }
}

void func_02032a20(void) {
    BOOL v;

    if (data_02174e5c->mUnk_68 == 0) {
        func_02029930()->mUnk_c8 = 2;
        switch (data_02174e5c->mUnk_44) {
            case 0:
                v = FALSE;
                break;
            default:
                v = TRUE;
                break;
        }
        func_02029930()->mUnk_e4 = v;
    } else if (data_02174e5c->mUnk_44 == 0) {
        func_02029930()->mUnk_c8 = 3;
    } else {
        func_02029930()->mUnk_c8 = 2;
        switch (data_02174e5c->mUnk_44) {
            case 1:
                v = FALSE;
                break;
            default:
                v = TRUE;
                break;
        }
        func_02029930()->mUnk_e4 = v;
    }
    data_02174e5c->mUnk_64 = 1;
    data_02174e5c->mUnk_54 = 5;
    func_0212ecc0(&data_0217d068, 0, 5);
}

#pragma thumb off

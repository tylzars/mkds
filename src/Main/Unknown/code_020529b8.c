#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_02046c10.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200f59c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02043a20.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0204a52c.h"
#include "Main/Unknown/code_0204b000.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_0204bca0.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02053000.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_02059878.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"
#include "code_021445e0.h"
#include "code_021453ec.h"
#include "code_0214d018.h"

void func_02053d00(void) {
    Unk02143a78 *p;
    Unk021438f0 *q;
    Unk0217aa00_16a0_view *v;
    Unk0217aa00_16a0 *e;
    s32 i;

    if (data_0217aa00 == NULL) {
        return;
    }
    data_0217aa00->mUnk_0000 = 0;
    data_0217aa00->mUnk_0004 = 0;
    data_0217aa00->mUnk_0008 = 9;
    data_0217aa00->mUnk_000c = 0;
    data_0217aa00->mUnk_0010 = 0;
    data_0217aa00->mUnk_0454 = 0;
    p = data_0217aa00->mUnk_001c;
    p->mUnk_00 = data_0217aa00->mUnk_0028;
    p->mUnk_04 = 0;
    p->mUnk_06 = 0;
    for (i = 0; i < 6; i++) {
        p->mUnk_08[i] = 0xff;
    }
    q = data_0217aa00->mUnk_0020;
    q->mUnk_00 = data_0217aa00->mUnk_002c;
    q->mUnk_04 = 0x400;
    q->mUnk_06 = 0;
    q->mUnk_08 = 0;
    q->mUnk_10 = 1;
    q->mUnk_12 = 0;
    for (i = 0; i < 6; i++) {
        q->mUnk_0a[i] = 0xff;
    }
    func_02053fa8();
    v = &data_0217aa00->mUnk_16a0_view;
    e = &v->mUnk_000[0];
    for (i = 0; i < 0xc; i++) {
        e->mUnk_34 = 0;
        e->mUnk_74 = NULL;
        e++;
    }
    v->mUnk_6b4 = 0;
    v->mUnk_660 = 0;
    v->mUnk_798 = 0;
    v->mUnk_79c = 0;
    func_0204e65c(&data_0217aa00->mUnk_1658_view);
    func_02059878();
    func_0204fb40(1);
}

void func_02053ab0(void) {
    Unk0217aa00_15c4 *p;
    u32 v1;
    s32 r;

    func_0204a52c();
    p = data_0217aa00->mUnk_15c4;
    if (data_0217aa00->mUnk_0004 == 8) {
        p->mUnk_05 = data_0217aa00->mUnk_15f7;
    } else {
        p->mUnk_05 = 0;
    }
    p->mUnk_04 = (data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000) == 1 ? data_0217aa00->mUnk_1eac[0] : 0;
    p->mUnk_00 = func_02043a20();
    p->mUnk_06_0 = 0;
    p->mUnk_07 = 0;
    v1 = 0;
    if (data_0217aa00->mUnk_0004 == 9) {
        if (data_0217aa00 != NULL) {
            v1 = data_0217aa00->mUnk_0000;
        }
        if (v1 == 1) {
            if (func_02055afc() != 0) {
                p->mUnk_06_0 |= 4;
            } else {
                p->mUnk_06_0 &= ~4;
            }
        }
    }
    v1 = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
    if (v1 != 1 || (data_0217aa00->mUnk_008b & 1) != 0) {
        if (data_0217aa00->mUnk_15ec == 0) {
            p->mUnk_06_0 |= 1;
            p->mUnk_06_0 &= ~2;
        } else {
            p->mUnk_06_0 |= 2;
            p->mUnk_06_0 &= ~1;
        }
    }
    p->mUnk_06_7 = data_021759c4->mUnk_30_3;
    p->mUnk_02 = func_02046c10();
    r = func_02144c6c(data_0217aa00->mUnk_15bc, p, data_0217aa00->mUnk_15c0);
    if (r == 0) {
        if (data_0217aa00->mUnk_0004 == 8) {
            data_0217aa00->mUnk_15f7 = 0;
        }
    }
    data_0217aa00->mUnk_15f0 = r;
}

BOOL func_0205373c(void) {
    Unk0217aa00_15bc *q;
    BOOL v1;
    u16 i;
    u16 j;
    u8 m;
    u8 *v2;
    u8 buf[8][8];
    u32 f;
    u32 v3;
    u16 v;

    q = &data_0217aa00->mUnk_15bc_view;
    data_0217aa00->mUnk_1606 = data_0217aa00->mUnk_15bc->mUnk_000[data_0217aa00->mUnk_15bc->mUnk_808].mUnk_02;
    data_0217aa00->mUnk_0454 &= ~0x10;
    switch (data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000) {
        case 1:
            if (data_0217aa00->mUnk_0044.mUnk_40 != 0) {
                func_02053ab0();
            } else {
                return FALSE;
            }
            break;
        case 2:
            if (data_0217aa00->mUnk_0432 != 0xffff) {
                func_02053ab0();
            } else {
                return FALSE;
            }
            break;
    }
    switch (data_0217aa00->mUnk_0004) {
        case 8:
            if (q->mUnk_34 != 0 && q->mUnk_34 == 5) {
                return FALSE;
            }
            break;
        case 9:
            if (q->mUnk_34 != 0) {
                if (q->mUnk_34 == 5) {
                    return FALSE;
                }
            } else {
                if ((data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000) == 1) {
                    for (j = 1; j < 8; j++) {
                        if ((data_0217aa00->mUnk_15f6 & (1 << j)) != 0) {
                            data_0217aa00->mUnk_15f8[j - 1] = 0;
                        }
                    }
                }
            }
            break;
    }
    v1 = TRUE;
    v2 = func_0214461c(data_0217aa00->mUnk_15bc, data_0217aa00->mUnk_15c0, 0);
    if (v2 != NULL) {
        m = v2[4];
        if (m != 0) {
            for (i = 0; i < 8; i++) {
                v3 = 1 << i;
                f = data_0217aa00->mUnk_15f6;
                v = data_0217aa00->mUnk_1e52[i].mUnk_00;
                if ((f & v3) != 0 && (m & v3) != 0) {
                    data_0217aa00->mUnk_15f6 = f & ~v3;
                    if (data_0217aa00->mUnk_0004 == 9) {
                        func_0203c2e4(v);
                    }
                    if ((data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000) == 1) {
                        data_0217aa00->mUnk_1eac[0] &= ~v3;
                    }
                }
            }
        }
        MemCopy(v2, &buf[0], 8);
    } else {
        v1 = FALSE;
    }
    if (v1 != FALSE) {
        for (i = 1; i < 8; i++) {
            if ((data_0217aa00->mUnk_15f6 & (1 << i)) != 0) {
                v2 = func_0214461c(data_0217aa00->mUnk_15bc, data_0217aa00->mUnk_15c0, i);
                if (v2 != NULL) {
                    MemCopy(v2, &buf[i], 8);
                } else {
                    v1 = FALSE;
                    break;
                }
            }
        }
    }
    for (i = 0; i < 8; i++) {
        if (v1 != FALSE && (data_0217aa00->mUnk_15f6 & (1 << i)) != 0) {
            MemCopy(&buf[i], &q->mUnk_0c[i], 8);
            q->mUnk_10[i] = 1;
        } else {
            q->mUnk_10[i] = 0;
        }
    }
    return v1 != FALSE;
}

void func_020536e0(void) {
    data_0217aa00->mUnk_000c = 1;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02143e10(data_0217aa00->mUnk_0014, func_02053664, 2) != 2) {
        data_0217aa00->mUnk_0010 = 0;
    }
}

void func_02053664(Unk021425e8 *a) {
    s32 r;

    r = func_0214358c(0xf, func_02050764, NULL);
    data_0217aa00->mUnk_0010 = 0;
    if (r != 0) {
        return;
    }
    if (a->mUnk_02 != 0) {
        return;
    }
    if (data_0217aa00->mUnk_1d00 != 0) {
        func_0214358c(1, func_0204ed04, NULL);
    }
    func_02053fa8();
}

void func_020533a0(void) {
    u32 v1;
    BOOL d;
    BOOL c;

    if ((data_0217aa00->mUnk_0454 & 0x100) != 0) {
        data_0217aa00->mUnk_000c = 0x26;
        data_0217aa00->mUnk_0010 = 1;
        d = FALSE;
        if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
            c = TRUE;
            v1 = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
            if (v1 != 1 && ((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                c = FALSE;
            }
            if (c != FALSE) {
                d = TRUE;
            }
        }
        if (d != FALSE) {
            func_0204bcec();
            data_0217aa00->mUnk_0454 &= ~0x100;
        }
        data_0217aa00->mUnk_0010 = 0;
        return;
    }
    if ((data_0217aa00->mUnk_0454 & 0x200) != 0) {
        func_0204eca0();
        return;
    }
    data_0217aa00->mUnk_000c = 2;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02143dd0(func_02053348) == 2) {
        return;
    }
    data_0217aa00->mUnk_000c = 0x15;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02143d88(func_02050e80) == 2) {
        return;
    }
    if ((data_0217aa00->mUnk_0454 & 0x100) != 0) {
        data_0217aa00->mUnk_000c = 0x26;
        data_0217aa00->mUnk_0010 = 1;
        if (func_020510e4() != 0 && (func_020510c8() == 1 || func_020510ac() != 0)) {
            c = TRUE;
        } else {
            c = FALSE;
        }
        if (c != FALSE) {
            func_0204bcec();
            data_0217aa00->mUnk_0454 &= ~0x100;
        }
        data_0217aa00->mUnk_0010 = 0;
        return;
    }
    if ((data_0217aa00->mUnk_0454 & 0x200) != 0) {
        func_0204eca0();
        return;
    }
    data_0217aa00->mUnk_000c = 2;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02143dd0(func_02053348) == 2) {
        return;
    }
    data_0217aa00->mUnk_000c = 0x15;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02143d88(func_02050e80) == 2) {
        return;
    }
    if ((data_0217aa00->mUnk_0454 & 0x100) != 0) {
        func_02052cf4();
        return;
    }
    if ((data_0217aa00->mUnk_0454 & 0x200) != 0) {
        func_0204eca0();
        return;
    }
    func_0205108c(2);
    if (func_02143dd0(func_02053348) == 2) {
        return;
    }
    func_02050ec0();
}

void func_02053348(Unk021425e8 *a) {
    data_0217aa00->mUnk_0010 = 0;
    if (a->mUnk_02 != 0) {
        data_0217aa00->mUnk_0008 = 1;
        data_0217aa00->mUnk_0010 = 0;
    } else {
        func_02053fa8();
    }
}

void func_020532dc(s32 a) {
    data_0217aa00->mUnk_000c = 3;
    data_0217aa00->mUnk_0010 = 1;
    if (func_021454c4(func_0205329c, 0xffff, a, 0xffff, 0xf) != 2) {
        func_020533a0();
    }
}

void func_0205329c(Unk021425e8 *a) {
    data_0217aa00->mUnk_0010 = 0;
    if (a->mUnk_02 != 0) {
        func_020533a0();
    }
}

void func_02053094(u16 a) {
    u16 r;
    u16 n;
    s32 i;

    data_0217aa00->mUnk_000c = 4;
    data_0217aa00->mUnk_0010 = 1;
    n = a;
    r = func_02143280();
    if (r == 0) {
        data_0217aa00->mUnk_0010 = 0;
        data_0217aa00->mUnk_0008 = 3;
        data_0217aa00->mUnk_0010 = 0;
    } else if (r == 0x8000) {
        data_0217aa00->mUnk_0010 = 0;
        data_0217aa00->mUnk_0008 = 8;
        data_0217aa00->mUnk_0010 = 0;
    }
    if (n == 0) {
        data_0217aa00->mUnk_0089_0 = 1;
        data_0217aa00->mUnk_0089_4 = 1;
        for (i = 1; i < 0xe; i++) {
            data_0217aa00->mUnk_008c[i] = -1;
        }
        n = 1;
    } else if (data_0217aa00->mUnk_0089_0 >= 7) {
        n = n + 1;
        data_0217aa00->mUnk_0089_0 = 1;
        if (((1 << (n - 1)) & r) == 0) {
            do {
                n = n + 1;
                if (n > 0xe) {
                    if (data_0217aa00->mUnk_0089_4 >= 2) {
                        data_0217aa00->mUnk_0010 = 0;
                        return;
                    }
                    data_0217aa00->mUnk_0089_4 += 1;
                    n = 1;
                    data_0217aa00->mUnk_0089_0 = 1;
                }
            } while (((1 << (n - 1)) & r) == 0);
        }
    } else {
        data_0217aa00->mUnk_0089_0 += 1;
    }
    if (func_0214544c(func_02053020, 3, 0x11, n, 0x14) != 2) {
        func_020533a0();
    }
}

void func_02053020(Unk021425e8 *a) {
    s16 *p;

    if (a->mUnk_02 != 0) {
        func_020533a0();
        return;
    }
    p = &data_0217aa00->mUnk_008c[a->mUnk_08_0];
    if (*p < 0) {
        *p = 0;
    }
    *p = *p + a->mUnk_08_2;
    func_02053094(a->mUnk_08_0);
}

void *func_02052fa4(u32 a, u32 b, void *c) {
    u32 v1;
    void *r;

    r = NULL;
    v1 = IrqDisable();
    if (c != NULL) {
        HeapFree(data_0217aa00->mHeap, c);
    } else {
        r = HeapAllocAligned(data_0217aa00->mHeap, b, -0x20);
    }
    IrqRestore(v1);
    return r;
}

void func_02052ecc(void) {
    u32 v1;
    BOOL c;
    BOOL d;

    data_0217aa00->mUnk_000c = 0x24;
    data_0217aa00->mUnk_0010 = 1;
    d = FALSE;
    if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
        c = TRUE;
        v1 = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
        if (v1 != 1 && ((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
            c = FALSE;
        }
        if (c != FALSE) {
            d = TRUE;
        }
    }
    if (d != FALSE) {
        v1 = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
        func_0204bf48(v1 == 1 ? 1 : 0, 4, 0x154, func_02052e64, func_02052fa4, 0);
    }
    data_0217aa00->mUnk_0010 = 0;
    func_0204f5e4();
}

void func_02052e64(void) {
    if (data_0217aa00->mUnk_000c == 0x24) {
        if (func_0204bcdc() == 2) {
            data_0217aa00->mUnk_0010 = 0;
            func_0204f5e4();
        }
    } else {
        data_0217aa00->mUnk_0010 = 0;
    }
}

void func_02052da4(void) {
    u32 v1;
    BOOL c;
    BOOL d;

    data_0217aa00->mUnk_000c = 0x25;
    data_0217aa00->mUnk_0010 = 1;
    d = FALSE;
    if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
        c = TRUE;
        v1 = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
        if (v1 != 1 && ((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
            c = FALSE;
        }
        if (c != FALSE) {
            d = TRUE;
        }
    }
    if (d != FALSE) {
        func_0204be0c();
        data_0217aa00->mUnk_1e34 = 0;
        data_0217aa00->mUnk_0454 |= 0x100;
    }
    data_0217aa00->mUnk_0010 = 0;
}

void func_02052cf4(void) {
    u32 v1;
    BOOL c;
    BOOL d;

    data_0217aa00->mUnk_000c = 0x26;
    data_0217aa00->mUnk_0010 = 1;
    d = FALSE;
    if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
        c = TRUE;
        v1 = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
        if (v1 != 1 && ((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
            c = FALSE;
        }
        if (c != FALSE) {
            d = TRUE;
        }
    }
    if (d != FALSE) {
        func_0204bcec();
        data_0217aa00->mUnk_0454 &= ~0x100;
    }
    data_0217aa00->mUnk_0010 = 0;
}

u16 func_02052c5c(u32 a) {
    Unk0203bfc4 t;
    u32 h;
    u16 m;
    u64 x;
    u64 y;

    func_0203bfc4(&t);
    h = t.mUnk_00;
    if (h >= 0x12) {
        h -= 0x12;
    }
    m = (h * 0x3c + t.mUnk_04) * 0x3c + t.mUnk_08;
    x = func_0200f59c() | m << 16;
    x = x * 0x5d588b656c078965ull + 0x269ec3;
    y = x >> 32;
    return (u16) (y * 0x10000 >> 32) | 0x8000;
}

void func_02052bf8(void) {
    data_0217aa00->mUnk_0000 = 1;
    data_0217aa00->mUnk_000c = 5;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02143c80(func_02052bb8, data_0217aa00->mUnk_0018) != 2) {
        func_020533a0();
    }
}

void func_02052bb8(Unk021425e8 *a) {
    data_0217aa00->mUnk_0010 = 0;
    if (a->mUnk_02 != 0) {
        func_020533a0();
    }
}

void func_02052b60(Unk021425e8Func a) {
    if (a == NULL) {
        a = func_020529b8;
    }
    data_0217aa00->mUnk_000c = 6;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02143bc4(a) != 2) {
        func_020533a0();
    }
}

void func_020529b8(Unk021425e8 *a) {
    Unk020f41c4_B *p;
    u32 v1;
    u16 v;
    u32 n;

    if (a->mUnk_02 == 0) {
        switch (a->mUnk_08_0) {
            case 7:
                func_02050d80(a->mUnk_10, &a->mUnk_0a[0], (Unk0217aa00_45c *) a->mUnk_14);
                break;
            case 0:
                MemCopy(&data_0217aa08->mUnk_00->mUnk_0c, &data_0217aa00->mUnk_045c[0], 0x14);
                MemCopy(&data_0217aa08->mUnk_00->mUnk_20, &data_0217aa00->mUnk_045c[0].mUnk_224, 4);
                v = 0;
                v1 = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
                switch (v1) {
                    case 1:
                        v = data_0217aa00->mUnk_0018->mUnk_0c;
                        break;
                    case 2:
                        v = data_0217aa00->mUnk_0024->mUnk_48;
                        break;
                }
                p = &data_0217aa00->mUnk_1ee8;
                p->mUnk_00 = (u32) (v * 3 | v << 16);
                p->mUnk_08 = 0x5d588b656c078965ull;
                p->mUnk_10 = 0x269ec3;
                data_0217aa00->mUnk_0010 = 0;
                break;
            case 9:
                func_02050b88(a->mUnk_10);
                n = a->mUnk_10;
                v1 = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
                if (v1 == 1 && data_0217aa00->mUnk_0004 == 9) {
                    data_0217aa00->mUnk_1eac[0] |= 1 << n;
                }
                break;
        }
    } else {
        func_020533a0();
    }
}

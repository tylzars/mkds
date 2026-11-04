#include "code_020245a4.h"
#include "code_0200fc8c.h"

u16 CharReadHalfword(u16 **a) {
    u16 *p;
    u16 c;

    p = *a;
    c = *p++;
    *a = p;
    return c;
}

static inline s32 func_0202469c_inline(Unk02021f9c *a) {
    if (a != 0 && a->mUnk_00 == 0x4e465452) {
        return 1;
    }
    return 0;
}

static inline s32 func_0202469c_inline2(Unk02021f9c *a, u16 v) {
    if (a != 0 && a->mUnk_06 == v) {
        return 1;
    }
    return 0;
}

static inline s32 func_0202469c_inline3(Unk02021f9c *a, u16 v) {
    if (a != 0) {
        return func_0202469c_inline(a) && func_0202469c_inline2(a, v);
    }
    return 0;
}

u16 CharReadOneToThreeBytes(u8 **a) {
    u8 *p;
    u16 c;

    p = *a;
    c = *p;
    if ((c & 0x80) == 0) {
        *a = p + 1;
    } else if ((c & 0xe0) == 0xc0) {
        c = ((c & 0x1f) << 6) | (p[1] & 0x3f);
        *a = p + 2;
    } else {
        c = ((c & 0x1f) << 12) | ((p[1] & 0x3f) << 6) | (p[2] & 0x3f);
        *a = p + 3;
    }
    return c;
}

u16 CharReadByteOrPair(u8 **a) {
    u16 c;
    u8 *p;

    p = *a;
    c = *p;
    if ((c >= 0x81 && c < 0xa0) || c >= 0xe0) {
        c = p[1] | (c << 8);
        *a = *a + 2;
    } else {
        *a = *a + 1;
    }
    return c;
}

u16 CharReadByte(u8 **a) {
    u8 *p;
    u8 c;

    p = *a;
    c = *p++;
    *a = p;
    return c;
}

u32 BitStreamReadBits(Unk020247fc *a, s32 b) {
    s32 n;
    u32 c;
    u32 r;
    u8 *p;

    n = a->mUnk_04;
    c = a->mUnk_05;
    if (n < b) {
        p = a->mUnk_00;
        a->mUnk_00 = p + 1;
        r = c << (b - n);
        a->mUnk_05 = *p;
        a->mUnk_04 = 8;
        r = BitStreamReadBits(a, b - n) | r;
    } else {
        a->mUnk_04 = n - b;
        r = c >> (n - b);
    }
    return r & (0xff >> (8 - b));
}

u32 func_0202469c(Unk02021f9c *a, Unk02022ce4 **b) {
    u32 r;
    Unk02021fd0 *p;

    if (func_0202469c_inline3(a, 0x100)) {
        r = 0;
    } else if (func_0202469c_inline3(a, 1)) {
        r = 1;
    } else {
        IrqDisableLoopForever();
    }
    func_020245a4(a);
    p = FindPartByTag(a, 0x46494e46);
    if (p == 0) {
        *b = 0;
        return 0;
    }
    *b = (Unk02022ce4 *) (p + 1);
    if (r != 0) {
        (*b)->mUnk_07 = (*b)->mUnk_04.mUnk_02;
        (*b)->mUnk_04.mUnk_02 = 0;
    }
    return r + 1;
}

void func_020245a4(Unk02021f9c *a) {
    Unk02021fd0 *p;
    s32 i;
    Unk020245a4_08 *q;

    p = (Unk02021fd0 *) ((u8 *) a + a->mUnk_0c);
    for (i = 0; i < a->mUnk_0e; i++) {
        switch (p->mUnk_00) {
            case 0x46494e46:
                q = (Unk020245a4_08 *) (p + 1);
                q->mUnk_04[1] += (u32) a;
                if (q->mUnk_04[2] != 0) {
                    q->mUnk_04[2] += (u32) a;
                }
                if (q->mUnk_04[3] != 0) {
                    q->mUnk_04[3] += (u32) a;
                }
                break;
            case 0x43574448:
                q = (Unk020245a4_08 *) (p + 1);
                if (q->mUnk_04[0] != 0) {
                    q->mUnk_04[0] += (u32) a;
                }
                break;
            case 0x434d4150:
                q = (Unk020245a4_08 *) (p + 1);
                if (q->mUnk_04[1] != 0) {
                    q->mUnk_04[1] += (u32) a;
                }
                break;
            case 0x43474c50:
                break;
        }
        p = (Unk02021fd0 *) ((u8 *) p + p->mUnk_04);
    }
}

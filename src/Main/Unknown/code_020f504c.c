#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f504c.h"

#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210a598.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/code_0210a000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f1104.h"
#include "Main/Unknown/code_020f1258.h"
#include "Main/Unknown/code_020f1a14.h"
#include "Main/Unknown/code_020f2d98.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020f5d6c.h"

// Runs the two 0x7c/0x4c checks of the object in the 0x1fc word of the 0x1c pointer, then
// one of the four func_020f14a0 calls, and stores the 0x24c/0x24e halfwords it picks.
void func_020f5824(Unk020f5d6c *a) {
    Unk020ee684 *o;
    Unk0206bcb0 *b;
    BOOL d;
    u32 c;
    s32 n;

    o = a->mUnk_228;
    b = o->mUnk_1fc;
    c = *(u32 *) &b->mUnk_7c;
    d = TRUE;
    if ((c & 0x402020) == 0) {
        if ((b->mUnk_4c & 0x800) == 0) {
            d = FALSE;
        }
    }
    if (d != FALSE) {
        func_020f1104((s32) a);
        a->mUnk_23c.mUnk_10 = 6;
        a->mUnk_23c.mUnk_12 = 1;
    } else {
        n = a->mUnk_000.mUnk_000.mUnk_000.mUnk_74;
        if (n & 0x10000000) {
            if (c & 1) {
                n = func_020f14a0(a, 0x5333, 0x19a, 1);
            } else {
                n = func_020f14a0(a, 0x4b33, 0x19a, 0);
            }
        } else {
            n = func_020f14a0(a, 0x4800, 0x19a, (n & 0x8000000) == 0);
        }
        if (n != 0) {
            func_020f1104((s32) a);
            a->mUnk_23c.mUnk_10 = 2;
            a->mUnk_23c.mUnk_12 = 1;
            a->mUnk_000.mUnk_21c.mUnk_00 = NULL;
            a->mUnk_000.mUnk_21c.mUnk_04 = 1;
        }
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1) {
        return;
    }
    func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
}

// Checks func_0206c0e0 of the 0x1fc object, then the 0x240 counter and the sum of the two
// squares of the 0x50/0x54/0x58 differences against the 0x1d0/0x1d4/0x1e0 square.
void func_020f572c(Unk020f5d6c *a) {
    Unk020ee684 *o;
    Unk0206bcb0 *k;
    s32 n;
    s32 r;
    s32 t;

    o = a->mUnk_228;
    k = o->mUnk_1fc;
    if (func_0206c0e0(k) != 0) {
        func_020f6f10(&a->mUnk_000.mUnk_000.mUnk_000, 0, 8);
    } else {
        func_020f14a0(a, 0x10000, 0x333, 0);
    }
    if ((a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1) == 0) {
        func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
    }
    if (a->mUnk_23c.mUnk_04 <= 0x14) {
        r = k->mUnk_1d0 + (s32) ((a->mUnk_000.mUnk_000.mUnk_000.mUnk_e0 * 3) >> 1);
        n = a->mUnk_000.mUnk_000.mUnk_000.mUnk_50.z - k->mUnk_1d8.z;
        t = a->mUnk_000.mUnk_000.mUnk_000.mUnk_50.x - k->mUnk_1d8.x;
        if ((s64) t * t + (s64) n * n >= (s64) r * r) {
            return;
        }
    }
    func_020f6f10(&a->mUnk_000.mUnk_000.mUnk_000, 0, 8);
}

// Runs func_020f2228 and hands func_020f5fb8 to func_0210ddf4 when the 0x74 bit 0 is clear.
void func_020f56d0(Unk020f5d6c *a) {
    func_020f2228(&a->mUnk_000.mUnk_000, 0xc000);
    if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1) {
        return;
    }
    func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
}

// Runs func_0210a598 with the 0x3bc word of the 0x1fc object when the 0x78 high bits of the
// third parameter match that object's 0x74 halfword and the 0x74/0x78/0xdc tests pass.
void func_020f5614(void *a0, s32 b, void *c0) {
    Unk020f5d6c *a;
    Unk020f41c4_A *c;
    Unk020ee684 *o;
    Unk0206bcb0 *k;
    u16 n;
    u32 f;

    a = a0;
    c = c0;
    if ((u32) (b - 1) > 1) {
        return;
    }
    o = a->mUnk_228;
    n = (u16) (!(c->mUnk_78 & 0x8000) ? (u16) (c->mUnk_78 & ~0xff00) : 8);
    if (o == NULL) {
        return;
    }
    k = o->mUnk_1fc;
    if (n != *(u16 *) &k->mUnk_74) {
        return;
    }
    f = c->mUnk_74;
    if ((f & 0x1000) == 0) {
        if ((f & 0x2000) == 0) {
            return;
        }
        if ((c->mUnk_78 & 0x1000) == 0) {
            return;
        }
        if (c->mUnk_11c >= 0x78) {
            return;
        }
    }
    func_0210a598(k, k->mUnk_3cc);
}

// Hands the 0x44 word and the 0x5c/0x130/0x250/0x254/0x60/0x54 addresses of b to
// func_020fecdc, func_020ff040, func_020ff1b8, func_020ff1a0 and func_020fe8ac.
void *func_020f5550(void *a, Unk020f5d6c *b, void *c) {
    s32 dot;
    void *p;

    if (b != NULL && c != NULL) {
        dot = func_02039828(&b->mUnk_000.mUnk_000.mUnk_000.mUnk_5c, &b->mUnk_000.mUnk_000.mUnk_130);
        func_020ff1b8(dot < 0, &b->mUnk_000.mUnk_000.mUnk_000.mUnk_5c.y);
        func_020ff1b8(b->mUnk_254, &b->mUnk_000.mUnk_000.mUnk_000.mUnk_50.y);
    }
    p = func_020fecdc(a, b, c);
    p = func_020ff040(p, b != NULL ? &b->mUnk_000.mUnk_21c : 0, c);
    if (b != NULL && c == NULL) {
        func_020ff1a0(b->mUnk_000.mUnk_000.mUnk_000.mUnk_5c.y, &b->mUnk_250);
        func_020ff1a0(b->mUnk_000.mUnk_000.mUnk_000.mUnk_50.y, &b->mUnk_254);
    }
    if (b != NULL && c != NULL) {
        return func_020fe8ac(b->mUnk_000.mUnk_000.mUnk_000.mUnk_44);
    }
    return p;
}

// Stores func_0210a77c in the 0x30 word, moves the seven words of data_0216c648 to 0x23c,
// then picks one of three calls from the 0x254/0x21c words.
void func_020f53d0(Unk020f5d6c *a) {
    u16 x;
    u32 n;
    u16 v;
    u16 i;

    func_020f8e78(a);
    func_0210b850(&a->mUnk_258);
    a->mUnk_000.mUnk_000.mUnk_000.mUnk_00.mUnk_30 = (void (*)(void *, void *, void *)) func_0210a77c;
    func_02046be8(&a->mUnk_23c, (UnkFunc *const *) data_0216c648, 7, a);
    if (a->mUnk_254 != 0) {
        if (a->mUnk_000.mUnk_21c.mUnk_00 != NULL) {
            a->mUnk_23c.mUnk_10 = 3;
            a->mUnk_23c.mUnk_12 = 1;
            x = (u16) (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & 0x8000)
                           ? (u16) (a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & ~0xff00)
                           : 8);
            if (x >= 8) {
                v = 8;
            } else {
                n = func_0203c8dc((u32) x);
                i = (u16) (n - 1);
                if (i < 1) {
                    i = (u16) data_021759c0->mKartCount;
                }
                v = (u16) data_0217561c->mUnk_474[(i & 0xff) - 1];
            }
            func_020ec8bc(&a->mUnk_000, 0x2d, 0x5b, 0, 1, a->mUnk_250, v, 0);
        } else {
            a->mUnk_23c.mUnk_10 = 2;
            a->mUnk_23c.mUnk_12 = 1;
            func_020f1ea4(a, 0, a->mUnk_250, 0);
        }
        a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 |= 0x200000;
    } else {
        a->mUnk_23c.mUnk_10 = 1;
        a->mUnk_23c.mUnk_12 = 1;
        func_020f1ea4(a, 0, a->mUnk_250, 0);
    }
    func_020f1a14((u32) a);
}

// Returns 1 while func_0207a974(b) is within the 0x1d0/0x1d4 radius of the 0x50/0x54/0x58
// words, or when the 0xda halfword is -1; otherwise sets the 0x24c/0x24e halfwords, returns 0.
BOOL func_020f5324(void *a0, s32 b) {
    Unk020f5d6c *a;
    Unk0206bcb0 *k;
    s32 n;
    s32 r;
    s32 t;

    a = a0;
    k = func_0207a974(b);
    r = k->mUnk_1d0 + (s32) ((a->mUnk_000.mUnk_000.mUnk_000.mUnk_e0 * 3) >> 1);
    n = a->mUnk_000.mUnk_000.mUnk_000.mUnk_50.z - k->mUnk_1d8.z;
    t = a->mUnk_000.mUnk_000.mUnk_000.mUnk_50.x - k->mUnk_1d8.x;
    if ((s64) t * t + (s64) n * n < (s64) r * r) {
        return TRUE;
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_da == -1) {
        return TRUE;
    }
    func_020f9c40((s32) a);
    a->mUnk_23c.mUnk_10 = 5;
    a->mUnk_23c.mUnk_12 = 1;
    func_020f112c((s32) a, b);
    return FALSE;
}

// Runs func_020f9114, ors data_02159834 into the 0x78 halfword, then makes one of two
// func_020f3150 calls depending on the 0x1ec halfword of the 0x0c pointer, and returns the
// 0x130 word it stores.
s32 func_020f5240(Unk020eda5c *a, Unk020f5240 *b) {
    Unk020ee684 *o;
    s32 n;

    func_020f9114(b);
    b->mUnk_000.mUnk_000.mUnk_78 |= data_02159834;
    o = a->mUnk_00c;
    if (o->mUnk_1ec & 0x10) {
        func_020f3150(&b->mUnk_000, a, 0, 1, 0x4000, 0x3000, 0x59a);
        func_021090c4(&b->mUnk_000.mUnk_000.mUnk_00, 0xda, 0x7f, 0);
        b->mUnk_130 = 1;
        return b->mUnk_130;
    }
    func_020f3150(&b->mUnk_000, a, 0, 0, 0x4000, 0x3000, 0x59a);
    b->mUnk_130 = 0;
    return b->mUnk_130;
}

// Calls func_020f2df0 with one of two pairs of numbers, and when the 0x74 bits allow it
// doubles the 0x60 word and runs func_02109060 and func_020f6a6c.
void func_020f518c(Unk020f5240 *a) {
    u32 v;
    u32 n;

    if (a->mUnk_130 != 0) {
        func_020f2df0(&a->mUnk_000, 0x1ec, 0xfec, 0, &v);
    } else {
        func_020f2df0(&a->mUnk_000, 0x2e1, 0xf85, 0, &v);
    }
    n = a->mUnk_000.mUnk_000.mUnk_74;
    if ((n & 8) == 0) {
        return;
    }
    if (n & 3) {
        return;
    }
    if (a->mUnk_130 != 0) {
        a->mUnk_000.mUnk_000.mUnk_5c.y = a->mUnk_000.mUnk_000.mUnk_5c.y * 2;
    }
    func_02109060(&a->mUnk_000.mUnk_000.mUnk_00, 0xda);
    func_020f6a6c(&a->mUnk_000.mUnk_000, &v);
}

// Hands the 0x130 word and the 0x60 word to func_020ff1b8/func_020ff1a0 around the
// func_020fecdc call, and returns func_020fe8ac's value when b and c are both set.
void *func_020f5108(void *a, Unk020f5240 *b, void *c) {
    void *p;

    if (b != NULL && c != NULL) {
        func_020ff1b8(b->mUnk_130, &b->mUnk_000.mUnk_000.mUnk_5c.y);
    }
    p = func_020fecdc(a, b, c);
    if (b != NULL && c == NULL) {
        func_020ff1a0(b->mUnk_000.mUnk_000.mUnk_5c.y, &b->mUnk_130);
    }
    if (b != NULL && c != NULL) {
        return func_020fe8ac(b->mUnk_000.mUnk_000.mUnk_44);
    }
    return p;
}

// Runs func_020f8e78 and func_020f2d98, then func_021090c4 when the two 0x74/0x130 tests pass.
void func_020f50b4(Unk020f5240 *a) {
    func_020f8e78(a);
    func_020f2d98((u32) a, 0);
    if ((a->mUnk_000.mUnk_000.mUnk_74 & 0x10000000) == 0) {
        return;
    }
    if (a->mUnk_130 == 0) {
        return;
    }
    func_021090c4(&a->mUnk_000.mUnk_000.mUnk_00, 0xda, 0x7f, 0);
}

// Runs func_02069db8 on the 0x1fc word of b's 0x04 object, marks b, sets the 0x204 word of
// a's 0x0c object, and runs func_020fe958 when the 0x08 word is 5.
void func_020f504c(Unk020eda5c *a, Unk020f40dc *b) {
    func_02069db8(b->mUnk_04->mUnk_1fc);
    func_020f4754(b, 1);
    a->mUnk_00c->mUnk_204 = 1;
    if (data_021759c0->mUnk_08 != 5) {
        return;
    }
    func_020fe958(3);
}

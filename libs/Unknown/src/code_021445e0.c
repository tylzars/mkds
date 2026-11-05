#include "code_021445e0.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0201ec30.h"
#include "code_0214259c.h"
#include "code_02142eac.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214cfe4.h"
#include "code_0202056c.h"
#include "code_0214d018.h"

int func_021453c0(Unk021450ec *p, u32 n) {
    return func_021450ec(p, n, 0xffff, 2, 1);
}

int func_021453b4(Unk021450ec *p) {
    return func_02145030(p);
}

// Fills in the object p (0x820 bytes) for n and stores func_02144a50 (func_02144920 when mUnk_184 is not 0) for it;
// returns 6 for bad arguments.
int func_021450ec(Unk021450ec *p, u32 n, u32 mask, u32 k, u32 flag) {
    u32 w;
    u32 u5;
    Unk02142988 *q;
    int r;
    int i;
    u16 v;
    u32 c;
    Unk0214461c *e;

    w = 1;
    q = func_02142aa8()->mUnk_004;
    r = func_02142988(2, 9, 10);
    if (r != 0) {
        return r;
    }
    func_0200ee3c(&q->mUnk_00c, 4);
    if (q->mUnk_00c == 0) {
        return 3;
    }
    if (p == 0) {
        return 6;
    }
    if (n >= 16) {
        return 6;
    }
    if (mask == 0) {
        return 6;
    }
    func_0200ee3c(&q->mUnk_184, 2);
    u5 = q->mUnk_184;
    if (u5 == 0) {
        func_0200ee3c(&q->mUnk_086, 2);
        w = q->mUnk_086;
    }
    MemFillWordsByBlock_inline(p, 0x820);
    p->mUnk_808 = 0;
    p->mUnk_80a = 0;
    p->mUnk_80c = 0;
    p->mUnk_810 = k;
    p->mUnk_816 = n;
    p->mUnk_80e = 0;
    p->mUnk_818 = flag != 0;
    v = mask | (1 << u5);
    p->mUnk_80e = v;
    c = CountSetBits(v);
    p->mUnk_812 = c;
    p->mUnk_814 = k * c;
    if (p->mUnk_814 > 0x1fc) {
        p->mUnk_80e = 0;
        return 6;
    }
    p->mUnk_814 += 4;
    p->mUnk_81c = 1;
    if (u5 == 0) {
        for (i = 0; i < 4; i++) {
            p->mUnk_000[i].mUnk_00 = p->mUnk_80e & (w | 1);
        }
        func_0214358c(n, (UnkFunc *) func_02144a50, p);
        e = p->mUnk_000;
        for (i = 0; i < (p->mUnk_818 == 1 ? 2 : 1); e++, i++) {
            p->mUnk_808 = (p->mUnk_808 + 1) & 3;
            r = func_02144048((UnkFunc *) func_02144b64, p, e, p->mUnk_814, p->mUnk_80e & w, p->mUnk_816, 1);
            if (r == 7) {
                p->mUnk_800[i] = 0xffff;
                p->mUnk_80a = (p->mUnk_80a + 1) & 3;
            } else if (r != 0 && r != 2) {
                p->mUnk_81c = 5;
                return 1;
            }
        }
    } else {
        p->mUnk_80a = 3;
        func_0214358c(n, (UnkFunc *) func_02144920, p);
    }
    return 0;
}

// Clears the object p when func_02144a50 or func_02144920 is stored for it; returns 3 otherwise.
int func_02145030(Unk021450ec *p) {
    Unk02142aa8 *pp;
    UnkFunc *f;
    int r;

    pp = func_02142aa8();
    r = func_02142988(2, 9, 10);
    if (r != 0) {
        return r;
    }
    if (p == 0) {
        return 6;
    }
    if (p->mUnk_80e == 0 ||
        ((f = pp->mUnk_0c4[p->mUnk_816]) != (UnkFunc *) func_02144a50 && f != (UnkFunc *) func_02144920)) {
        return 3;
    }
    func_0214358c(p->mUnk_816, 0, 0);
    p->mUnk_80e = 0;
    p->mUnk_81c = 0;
    return 0;
}

// Returns 1 when mUnk_81c is 5 and 3 when it is neither 1 nor 4; otherwise takes the next block into b, passes a to
// func_02144814 and returns 0.
int func_02144c6c(Unk021450ec *p, void *a, Unk0214461c *b) {
    int f2;
    int r;
    Unk02142988 *q;
    u32 w;
    u32 st;
    int f1;
    u32 u5;
    int t;
    int rr;
    u16 k;
    u8 *e7;

    q = func_02142aa8()->mUnk_004;
    r = func_02142988(2, 9, 10);
    if (r != 0) {
        return r;
    }
    func_0200ee3c(&q->mUnk_00c, 4);
    if (q->mUnk_00c == 0) {
        return 3;
    }
    if (p == 0) {
        return 6;
    }
    if (a == 0) {
        return 6;
    }
    if (b == 0) {
        return 6;
    }
    func_0200ee3c(&q->mUnk_184, 2);
    u5 = q->mUnk_184;
    if (u5 == 0) {
        func_0200ee3c(&q->mUnk_086, 2);
        w = q->mUnk_086;
    }
    st = p->mUnk_81c;
    if (st == 5) {
        return 1;
    }
    if (st != 1) {
        if (st != 4) {
            return 3;
        }
    }
    r = 5;
    if (u5 == 0) {
        f1 = 0;
        f2 = 0;
        if (st == 4) {
            p->mUnk_81c = 1;
            k = (p->mUnk_808 + 3) & 3;
            rr = func_02144048((UnkFunc *) func_02144b64, p, &p->mUnk_000[k], p->mUnk_814, p->mUnk_80e & w, p->mUnk_816,
                               1);
            if (rr == 7) {
                p->mUnk_800[k] = 0xffff;
                p->mUnk_80a = (p->mUnk_80a + 1) & 3;
            } else if (rr != 0) {
                if (rr != 2) {
                    p->mUnk_81c = r;
                    return 1;
                }
            }
        }
        if (p->mUnk_80c != p->mUnk_80a) {
            p->mUnk_000[p->mUnk_80c].mUnk_00 |= 1;
            MemCopyHalfwords(&p->mUnk_000[p->mUnk_80c], b, 0x200);
            p->mUnk_81a = p->mUnk_800[p->mUnk_80c];
            p->mUnk_80c = (p->mUnk_80c + 1) & 3;
            f1 = 1;
            r = 0;
            if (p->mUnk_818 == 0 && w != 0 && p->mUnk_000[p->mUnk_808].mUnk_00 == 1) {
                f2 = f1;
            } else {
                f2 = 0;
            }
        }
        func_02144688(p, 0);
        if (f1 != 0) {
            func_02144814(p, 0, a);
            if (p->mUnk_818 == 0) {
                func_02144688(p, f2);
            }
        }
    } else {
        t = 0;
        if (st == 4) {
            p->mUnk_81c = 1;
            t = 1;
        } else if (p->mUnk_80c != p->mUnk_808) {
            if ((p->mUnk_000[p->mUnk_80c].mUnk_00 & 1) == 0) {
                p->mUnk_000[p->mUnk_80c].mUnk_00 |= 1;
            } else {
                MemCopyHalfwords(&p->mUnk_000[p->mUnk_80c], b, 0x200);
                p->mUnk_81a = p->mUnk_800[p->mUnk_80c];
                p->mUnk_80c = (p->mUnk_80c + 1) & 3;
                t = 1;
                r = 0;
            }
        }
        if (t != 0) {
            e7 = &p->mUnk_000[p->mUnk_80a].mUnk_04[0x1c];
            MemCopyHalfwords(a, e7, p->mUnk_810);
            rr = func_02144048((UnkFunc *) func_02144b64, p, e7, p->mUnk_810, p->mUnk_80e, p->mUnk_816, 1);
            p->mUnk_80a = (p->mUnk_80a + 1) & 3;
            if (rr != 2) {
                if (rr != 0) {
                    p->mUnk_81c = 5;
                    r = 1;
                }
            }
        }
    }
    return r;
}

// Passed to func_02144048; accepts only objects that func_02144a50 or func_02144920 are stored for and records the
// result in the object at mUnk_20.
void func_02144b64(Unk02144920 *a) {
    Unk02142aa8 *pp;
    Unk02142988 *q;
    Unk021450ec *p;
    UnkFunc *f;
    u32 x;
    u32 y;

    pp = func_02142aa8();
    q = pp->mUnk_004;
    f = pp->mUnk_0c4[a->mUnk_0a];
    p = pp->mUnk_104[a->mUnk_0a];
    if (f != (UnkFunc *) func_02144a50 && f != (UnkFunc *) func_02144920) {
        return;
    }
    if (p == 0) {
        return;
    }
    if (p != a->mUnk_20) {
        return;
    }
    func_0200ee3c(&q->mUnk_184, 2);
    x = a->mUnk_02;
    y = q->mUnk_184;
    if (x == 0) {
        if (y != 0) {
            return;
        }
        p->mUnk_800[p->mUnk_80a] = a->mUnk_1a >> 1;
        p->mUnk_80a = (p->mUnk_80a + 1) & 3;
        return;
    }
    if (x == 10) {
        if (y != 0) {
            p->mUnk_80a = (p->mUnk_80a + 3) & 3;
        }
        p->mUnk_81c = 4;
        return;
    }
    p->mUnk_81c = 5;
}

// Function stored in mUnk_0c4 by func_021450ec; messages 7, 9 and 0x15 pass the object to func_02144688 (9 clears bit
// mUnk_12 first, 0x15 calls func_02144814).
void func_02144a50(Unk02144920 *a) {
    Unk021450ec *p;
    u32 s;
    enum { K0 } d;
    u32 t;
    u32 n;
    u32 m;
    u16 k;

    p = a->mUnk_1c;
    if (p == 0) {
        return;
    }
    if (a->mUnk_02 == 0) {
        switch (a->mUnk_04) {
            case 0x15:
                func_02144814(p, a->mUnk_12, a->mUnk_0c);
                func_02144688(p, 0);
                return;
            case 7:
                func_02144688(p, 0);
                return;
            case 9:
                t = a->mUnk_12;
                d = 1;
                s = IrqDisable();
                n = p->mUnk_808;
                m = ~(d << t);
                p->mUnk_000[n].mUnk_00 &= m;
                if (p->mUnk_818 == 1) {
                    k = (n + 1) & 3;
                    p->mUnk_000[k].mUnk_00 &= m;
                }
                IrqRestore(s);
                func_02144688(p, 0);
                if (p->mUnk_818 == 1) {
                    func_02144688(p, 0);
                }
                return;
        }
    } else {
        p->mUnk_81c = 5;
    }
}

// Function stored in mUnk_0c4 by func_021450ec; when a->mUnk_04 is 0x15, copies mUnk_10 bytes from mUnk_0c into the
// block at mUnk_808 and advances mUnk_808.
void func_02144920(Unk02144920 *a) {
    Unk02142988 *q;
    Unk021450ec *p;
    u32 n;
    u32 v;
    u32 g;
    u16 *d;

    q = func_02142aa8()->mUnk_004;
    p = a->mUnk_1c;
    if (p == 0) {
        return;
    }
    if (a->mUnk_02 == 0) {
        if (a->mUnk_04 == 7) {
            return;
        }
        if (a->mUnk_04 == 9) {
            return;
        }
        if (a->mUnk_04 != 0x15) {
            return;
        }
        d = a->mUnk_0c;
        v = *d;
        n = a->mUnk_10;
        func_0200ee3c(&q->mUnk_184, 2);
        g = q->mUnk_184;
        if (n != p->mUnk_814) {
            if (n > 0x200) {
                n = 0x200;
            }
        }
        if (n < 4) {
            return;
        }
        if ((v & (1 << g)) == 0) {
            return;
        }
        MemCopyHalfwords(d, &p->mUnk_000[p->mUnk_808], n);
        p->mUnk_800[p->mUnk_808] = a->mUnk_1a >> 1;
        p->mUnk_808 = (p->mUnk_808 + 1) & 3;
    } else {
        p->mUnk_81c = 5;
    }
}

// Copies mUnk_810 bytes from src (zeros when src is 0) to the data of the block that holds bit, then moves bit from
// the first mask of that block to its second mask.
void func_02144814(Unk021450ec *p, u32 bit, const void *src) {
    u32 m;
    u16 n;
    u32 s;
    u8 *dst;
    volatile u16 z;

    m = (u16) (1 << bit);
    if ((p->mUnk_80e & m) == 0) {
        return;
    }
    n = p->mUnk_808;
    if ((m & p->mUnk_000[n].mUnk_00) == 0) {
        if (p->mUnk_818 != 1) {
            return;
        }
        n = (n + 1) & 3;
        if ((m & p->mUnk_000[n].mUnk_00) == 0) {
            return;
        }
    }
    dst = func_021445e0(p, p->mUnk_80e, p->mUnk_000[n].mUnk_04, bit);
    if (src != 0) {
        MemCopyHalfwords(src, dst, p->mUnk_810);
    } else {
        z = 0;
        MemFillHalfwords(z, dst, p->mUnk_810);
    }
    s = IrqDisable();
    p->mUnk_000[n].mUnk_00 &= ~m;
    p->mUnk_000[n].mUnk_02 |= m;
    IrqRestore(s);
}

// When the block at mUnk_808 starts with 0: advances mUnk_808, clears the block two ahead (one ahead when mUnk_818
// is not 1), then passes the block to func_02144048.
void func_02144688(Unk021450ec *p, u32 f) {
    u32 s;
    u16 i;
    u32 w;
    Unk02142988 *q;
    u16 n1;
    u16 n2;
    int r;
    volatile u16 z;

    q = func_02142aa8()->mUnk_004;
    s = IrqDisable();
    if (p->mUnk_000[p->mUnk_808].mUnk_00 == 0) {
        func_0200ee3c(&q->mUnk_086, 2);
        i = p->mUnk_808;
        w = q->mUnk_086;
        n1 = (i + 1) & 3;
        if (p->mUnk_818 == 1) {
            n2 = (n1 + 1) & 3;
        } else {
            n2 = n1;
        }
        z = 0;
        MemFillHalfwords(z, &p->mUnk_000[n2], 0x200);
        p->mUnk_000[n2].mUnk_00 = p->mUnk_80e & (w | 1);
        p->mUnk_808 = n1;
        p->mUnk_000[i].mUnk_00 = p->mUnk_80e;
        if (f == 1) {
            p->mUnk_000[i].mUnk_00 &= ~1;
        }
        IrqRestore(s);
        r = func_02144048((UnkFunc *) func_02144b64, p, &p->mUnk_000[i], p->mUnk_814, p->mUnk_80e & w, p->mUnk_816, 1);
        if (r == 7) {
            p->mUnk_800[i] = 0xffff;
            p->mUnk_80a = (p->mUnk_80a + 1) & 3;
        } else if (r != 0) {
            if (r != 2) {
                p->mUnk_81c = 5;
            }
        }
    } else {
        IrqRestore(s);
    }
}

// Returns func_021445e0 for the data of q, or 0 when p or q is 0 or bit is not set in both masks of q.
u8 *func_0214461c(Unk021450ec *p, Unk0214461c *q, u32 bit) {
    u32 m;
    u32 a;
    u32 b;

    b = q->mUnk_02;
    m = 1 << bit;
    a = q->mUnk_00;
    if (p == 0) {
        return 0;
    }
    if (q == 0) {
        return 0;
    }
    if ((a & m) == 0) {
        return 0;
    }
    if ((b & m) == 0) {
        return 0;
    }
    return func_021445e0(p, a, q->mUnk_04, bit);
}

// Returns base plus mUnk_810 times the number of set bits of mask below bit.
u8 *func_021445e0(Unk021450ec *p, u32 mask, u8 *base, u32 bit) {
    return base + p->mUnk_810 * CountSetBits(mask & ((1 << bit) - 1));
}

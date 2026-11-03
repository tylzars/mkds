#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_021458c4.h"
#include "code_0200f328.h"
#include "Main/Unknown/code_02000b44.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_02000000.h"
#include "code_02145878.h"
#include "Main/Unknown/code_02145888.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146a00.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02000000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_0217f000.h"
#include "code_02145800.h"
#include "code_0200c914.h"
#include "code_0200dc3c.h"
#include "code_0200e0ec.h"
#include "code_0200fd1c.h"
#include "code_0214c778.h"
#include "code_0214d018.h"
#include "code_0214d3d8.h"
#include "code_0214d5b8.h"
#include "registers.h"

Unk021458b4 data_0217fa00;
u32 data_02180060;
Unk02146154 data_02180080;

// Loops: waits for bit 3 of mUnk_114 and calls mUnk_40.
void func_021469a4(void *a) {
    Unk021458c4 *p;
    u32 s;

    p = &data_0217fa40;
    for (;;) {
        s = func_0200fca0();
        while ((p->mUnk_114 & 8) == 0) {
            p->mUnk_104 = &p->mUnk_44;
            func_0200e01c(0);
        }
        func_0200fcb4(s);
        p->mUnk_40(p);
    }
}

// Sends command a until mUnk_00 does not hold 4 or b attempts are used; returns whether it holds 0.
int func_02146868(Unk021458c4 *p, s32 a, s32 b) {
    u32 s;
    s32 v;
    Unk021458b4 *q;

    if (!(p->mUnk_114 & 2)) {
        p->mUnk_114 |= 2;
        if (func_0214d79c(11, 1) == 0) {
            do {
                func_0200fd10(100);
            } while (func_0214d79c(11, 1) == 0);
        }
        func_02146868(p, 0, 1);
    }
    func_0200ee74(p->mUnk_00, 0x40);
    func_0200ee98();
    do {
        p->mUnk_04 = a;
        p->mUnk_114 |= 0x20;
        while (func_0214d6e8(11, a, 1) < 0) {
        }
        if (a == 0) {
            q = p->mUnk_00;
            while (func_0214d6e8(11, (u32) q, 1) < 0) {
            }
        }
        s = func_0200fca0();
        while (p->mUnk_114 & 0x20) {
            func_0200e01c(0);
        }
        func_0200fcb4(s);
        v = p->mUnk_00->mUnk_00;
    } while (v == 4 && --b > 0);
    return v == 0;
}

// Copies the part of the block that mUnk_08 of p holds from p to mUnk_20; returns whether mUnk_24 is not 0.
int func_021467d0(Unk02146154 *p) {
    Unk021458c4 *d;
    u32 a;
    u32 n;
    u32 m;

    d = &data_0217fa40;
    a = d->mUnk_1c & -0x200;
    if (a == p->mUnk_08) {
        m = d->mUnk_1c - a;
        n = 0x200 - m;
        if (n > d->mUnk_24) {
            n = d->mUnk_24;
        }
        func_0214d1fc((u8 *) p->mUnk_20 + m, (void *) d->mUnk_20, n);
        d->mUnk_1c += n;
        d->mUnk_20 += n;
        d->mUnk_24 -= n;
    }
    return d->mUnk_24 != 0;
}

// Waits for bit 31 of 0x040001a4 to clear, then writes 0xc0 and the eight bytes of a and b to 0x040001a1 and
// 0x040001a8 to 0x040001af.
void func_02146730(u32 a, u32 b) {
    while (reg_MI_MCCNT1 & 0x80000000) {
    }
    *(vu8 *) 0x040001a1 = 0xc0;
    *(vu8 *) 0x040001a8 = a >> 24;
    *(vu8 *) 0x040001a9 = a >> 16;
    *(vu8 *) 0x040001aa = a >> 8;
    *(vu8 *) 0x040001ab = a;
    *(vu8 *) 0x040001ac = b >> 24;
    *(vu8 *) 0x040001ad = b >> 16;
    *(vu8 *) 0x040001ae = b >> 8;
    *(vu8 *) 0x040001af = b;
}

// Passes the next block to func_0214d3d8, sends the command for mUnk_1c and stores mUnk_04 of data_02180080 at
// 0x040001a4.
void func_021466d8(void) {
    Unk021458c4 *d;

    d = (Unk021458c4 *) (u32) &data_0217fa40;
    func_0214d3d8(d->mUnk_28, (void *) 0x04100010, (void *) d->mUnk_20, 0x200);
    func_02146730((d->mUnk_1c >> 8) | 0xb7000000, d->mUnk_1c << 24);
    reg_MI_MCCNT1 = data_02180080.mUnk_04;
}

// Advances mUnk_1c, mUnk_20 and mUnk_24 by one block; calls mUnk_38 when nothing is left, else func_021466d8.
void func_02146600(void) {
    Unk021458c4 *p;
    UnkFunc *cb;
    u32 arg;
    u32 s;

    func_0214c89c(data_0217fa40.mUnk_28);
    data_0217fa40.mUnk_1c += 0x200;
    data_0217fa40.mUnk_20 += 0x200;
    data_0217fa40.mUnk_24 -= 0x200;
    if (data_0217fa40.mUnk_24 == 0) {
        func_0200ca9c(0x80000);
        func_0200ca68(0x80000);
        p = (Unk021458c4 *) (u32) &data_0217fa40;
        p->mUnk_00->mUnk_00 = 0;
        cb = p->mUnk_38;
        arg = p->mUnk_3c;
        s = func_0200fca0();
        p->mUnk_114 &= ~0x4c;
        func_0200df9c(&p->mUnk_10c);
        if (p->mUnk_114 & 0x10) {
            func_0200df68(&p->mUnk_44);
        }
        func_0200fcb4(s);
        if (cb != 0) {
            cb(arg);
        }
    } else {
        func_021466d8();
    }
}

// non-matching: two flags are in r1 and r3 in the original and in r3 and r1 in ours (6 instructions differ, same size)
// Returns 1 and sends the command for mUnk_1c when mUnk_20 and mUnk_24 pass the checks; returns 0 otherwise.
int func_021464a4(Unk02146154 *p) {
    Unk021458c4 *d;
    u32 addr;
    u32 len;
    int r;
    int b;
    int c;
    u32 v;
    u32 end;
    int a;
    int t;
    u32 s;
    u32 rem;

    d = &data_0217fa40;
    r = 0;
    b = 0;
    c = 0;
    addr = d->mUnk_20;
    len = d->mUnk_24;
    if ((addr & 3) == 0 && d->mUnk_28 <= 3) {
        v = func_0200f328();
        end = addr + len;
        t = 1;
        a = 0;
        if (end > 0x01ff8000) {
            a = addr < 0x02000000;
        }
        if (a == 0) {
            if (v >= end || v + 0x4000 <= addr) {
                t = 0;
            }
        }
        if (t == 0) {
            c = 1;
        }
    }
    if (c != 0) {
        if (((d->mUnk_1c | len) & 0x1ff) == 0) {
            b = 1;
        }
    }
    if (b != 0 && len != 0) {
        r = 1;
    }
    p->mUnk_04 = (*(u32 *) 0x027ffe60 & ~0x07000000) | 0xa1000000;
    if (r != 0) {
        s = func_0200fca0();
        func_0200eea4((void *) addr, len);
        rem = addr & 31;
        if (rem != 0) {
            addr -= rem;
            func_0200ee58((void *) addr, 32);
            func_0200ee58((void *) (addr + len), 32);
            len += 32;
        }
        func_0200ee3c((void *) addr, len);
        func_0200ee98();
        func_0200cc74(0x80000, func_02146600);
        func_0200ca68(0x80000);
        func_0200cae4(0x80000);
        func_0200fcb4(s);
        func_021466d8();
    }
    return r;
}

// Reads 0x200-byte blocks from the word at 0x04100010 into mUnk_20, or into the buffer of p when mUnk_20 is not usable.
void func_021463a4(Unk02146154 *p) {
    Unk021458c4 *d;
    u32 *buf;
    u32 *q;
    u32 a;
    u32 n;
    u32 s;
    u32 w;

    d = &data_0217fa40;
    q = p->mUnk_20;
    for (;;) {
        a = d->mUnk_1c & -0x200;
        if (a != d->mUnk_1c || (((u32) (buf = (u32 *) d->mUnk_20)) & 3) != 0 || d->mUnk_24 < 0x200) {
            buf = q;
            p->mUnk_08 = a;
        }
        func_02146730((a >> 8) | 0xb7000000, a << 24);
        reg_MI_MCCNT1 = p->mUnk_04;
        n = 0;
        do {
            s = reg_MI_MCCNT1;
            if (s & 0x800000) {
                w = reg_MI_MCD1;
                if (n < 0x200) {
                    buf[n] = w;
                    n++;
                }
            }
        } while (s & 0x80000000);
        if ((u32) buf == d->mUnk_20) {
            data_0217fa40.mUnk_1c += 0x200;
            data_0217fa40.mUnk_20 += 0x200;
            data_0217fa40.mUnk_24 -= 0x200;
            if (data_0217fa40.mUnk_24 == 0) {
                return;
            }
        } else if (func_021467d0(p) == 0) {
            return;
        }
    }
}

// Calls the function at data_02180080.mUnk_00 when func_021467d0 returns nonzero, then clears the word at mUnk_00 and
// calls mUnk_38 with mUnk_3c.
void func_02146300(Unk021458c4 *a) {
    Unk021458c4 *p;
    Unk02146154 *q;
    UnkFunc *cb;
    u32 arg;
    u32 s;

    q = &data_02180080;
    if (func_021467d0(q) != 0) {
        q->mUnk_00(q);
    }
    p = (Unk021458c4 *) (u32) &data_0217fa40;
    p->mUnk_00->mUnk_00 = 0;
    cb = p->mUnk_38;
    arg = p->mUnk_3c;
    s = func_0200fca0();
    p->mUnk_114 &= ~0x4c;
    func_0200df9c(&p->mUnk_10c);
    if (p->mUnk_114 & 0x10) {
        func_0200df68(&p->mUnk_44);
    }
    func_0200fcb4(s);
    if (cb != 0) {
        cb(arg);
    }
}

// Stores the arguments in mUnk_1c to mUnk_3c; when func_021464a4 returns 0 either starts func_02146300 on the object at
// mUnk_44 (g not 0) or calls it.
void func_021461d8(u32 a, u32 b, u32 c, u32 d, UnkFunc *e, u32 f, u32 g) {
    Unk021458c4 *p;
    Unk02146154 *q;
    u32 s;

    p = (Unk021458c4 *) (u32) &data_0217fa40;
    q = &data_02180080;
    func_02145888();
    s = func_0200fca0();
    while (p->mUnk_114 & 4) {
        func_0200e01c(&p->mUnk_10c);
    }
    p->mUnk_114 |= 4;
    p->mUnk_38 = e;
    p->mUnk_3c = f;
    func_0200fcb4(s);
    p->mUnk_28 = a;
    p->mUnk_1c = b + data_02180060;
    p->mUnk_20 = c;
    p->mUnk_24 = d;
    if (a <= 3) {
        func_0214c89c(a);
    }
    if (func_021464a4(q) != 0) {
        if (g == 0) {
            func_02146148();
        }
    } else if (g != 0) {
        func_02145b0c(func_02146300);
    } else {
        p->mUnk_104 = data_0216ff5c.mUnk_04;
        func_02146300(p);
    }
}

// When mUnk_114 is 0: sets it to 1, clears mUnk_1c to mUnk_24, sets mUnk_28 to -1, clears mUnk_38 and mUnk_3c and
// data_02180060, then calls func_021458c4 and func_02146b80.
void func_02146154(void) {
    Unk021458c4 *p;

    p = &data_0217fa40;
    if (p->mUnk_114 != 0) {
        return;
    }
    p->mUnk_114 = 1;
    p->mUnk_1c = p->mUnk_20 = p->mUnk_24 = 0;
    p->mUnk_28 = -1;
    p->mUnk_38 = 0;
    p->mUnk_3c = 0;
    data_02180060 = 0;
    func_021458c4();
    data_02180080.mUnk_00 = func_0214613c();
    func_02146b80();
}

int func_02146148(void) {
    return func_0214581c();
}

UnkFunc *func_0214613c(void) {
    return (UnkFunc *) func_021463a4;
}

// non-matching: three calls take the address of mUnk_120 as `add r0, sl, #288` in the original and `mov r0, r5` in ours
// (4 instructions differ) Runs the transfer described by mUnk_1c to mUnk_34 in blocks of at most 0x100 bytes, then
// calls mUnk_38 with mUnk_3c.
void func_02145f80(Unk021458c4 *p) {
    u32 a;
    u32 b;
    u32 c;
    u32 n;
    u32 *buf;
    UnkFunc *cb;
    u32 arg;
    u32 s;

    a = p->mUnk_2c;
    b = p->mUnk_34;
    c = p->mUnk_30;
    func_02000b44((u32) (BuildInfo + 0x24));
    do {
        n = p->mUnk_24;
        if (n > 0x100) {
            n = 0x100;
        }
        p->mUnk_00->mUnk_14 = n;
        if (p->mUnk_114 & 0x40) {
            p->mUnk_114 &= ~0x40;
            p->mUnk_00->mUnk_00 = 7;
            break;
        }
        if (b == 0) {
            func_0200ee3c(p->mUnk_120, n);
            p->mUnk_00->mUnk_0c = p->mUnk_1c;
            p->mUnk_00->mUnk_10 = (u32) p->mUnk_120;
        } else {
            func_0214d1fc((void *) p->mUnk_1c, p->mUnk_120, n);
            func_0200ee74(p->mUnk_120, n);
            func_0200ee98();
            p->mUnk_00->mUnk_0c = (u32) p->mUnk_120;
            p->mUnk_00->mUnk_10 = p->mUnk_20;
        }
        if (func_02146868(p, a, c) == 0) {
            break;
        }
        if (b == 2) {
            if (func_02146868(p, 9, 1) == 0) {
                break;
            }
        } else if (b == 0) {
            func_0214d1fc(p->mUnk_120, (void *) p->mUnk_20, n);
        }
        p->mUnk_1c += n;
        p->mUnk_20 += n;
        p->mUnk_24 -= n;
    } while (p->mUnk_24 != 0);
    cb = p->mUnk_38;
    arg = p->mUnk_3c;
    s = func_0200fca0();
    p->mUnk_114 &= ~0x4c;
    func_0200df9c(&p->mUnk_10c);
    if (p->mUnk_114 & 0x10) {
        func_0200df68(&p->mUnk_44);
    }
    func_0200fcb4(s);
    if (cb != 0) {
        cb(arg);
    }
}

// Stores the arguments in mUnk_1c to mUnk_3c; starts func_02145f80 on the object at mUnk_44 and returns 1 when f is
// not 0, else runs it and returns whether the word at mUnk_00 is 0.
int func_02145e8c(u32 a, u32 b, u32 c, UnkFunc *d, void *e, u32 f, u32 g, u32 h, u32 i) {
    Unk021458c4 *p;
    u32 s;

    p = (Unk021458c4 *) (u32) &data_0217fa40;
    func_02000b44((u32) (BuildInfo + 0x24));
    s = func_0200fca0();
    while (p->mUnk_114 & 4) {
        func_0200e01c(&p->mUnk_10c);
    }
    p->mUnk_114 |= 4;
    p->mUnk_38 = d;
    p->mUnk_3c = (u32) e;
    func_0200fcb4(s);
    p->mUnk_1c = a;
    p->mUnk_20 = b;
    p->mUnk_24 = c;
    p->mUnk_2c = g;
    p->mUnk_30 = h;
    p->mUnk_34 = i;
    if (f != 0) {
        func_02145b0c(func_02145f80);
        return 1;
    }
    data_0217fa40.mUnk_104 = data_0216ff5c.mUnk_04;
    func_02145f80(p);
    return p->mUnk_00->mUnk_00 == 0;
}

int func_02145d44(s32 a) {
    Unk021458c4 *p;
    UnkFunc *cb;
    u32 arg;
    u32 s;

    p = &data_0217fa40;
    func_02000b44((u32) (BuildInfo + 0x24));
    if (a == 0) {
        func_0200fd1c();
    }
    func_02145888();
    s = func_0200fca0();
    while (p->mUnk_114 & 4) {
        func_0200e01c(&p->mUnk_10c);
    }
    p->mUnk_114 |= 4;
    p->mUnk_38 = 0;
    p->mUnk_3c = 0;
    func_0200fcb4(s);
    func_02145b54(a);
    data_0217fa40.mUnk_104 = data_0216ff5c.mUnk_04;
    func_02146868(p, 2, 1);
    p->mUnk_00->mUnk_0c = 0;
    p->mUnk_00->mUnk_10 = (u32) p->mUnk_120;
    p->mUnk_00->mUnk_14 = 1;
    func_02146868(p, 6, 1);
    cb = p->mUnk_38;
    arg = p->mUnk_3c;
    s = func_0200fca0();
    p->mUnk_114 &= ~0x4c;
    func_0200df9c(&p->mUnk_10c);
    if (p->mUnk_114 & 0x10) {
        func_0200df68(&p->mUnk_44);
    }
    func_0200fcb4(s);
    if (cb != 0) {
        cb(arg);
    }
    return p->mUnk_00->mUnk_00 == 0;
}

int func_02145d38(void) {
    return func_0214581c();
}

int func_02145d2c(void) {
    return func_02145800();
}

// non-matching: scheduling of the last three statements: original stores 0 to both words before loading data_0217fa40
// (4 instructions differ) Clears the words of data_0217fa00 from mUnk_18 on and fills them for the value a; stores 3 in
// mUnk_00 when a is not one of the known values.
void func_02145b54(s32 a) {
    Unk021458b4 *p;
    u32 m;
    u32 x;

    p = data_0217fa40.mUnk_00;
    func_0214d168(&p->mUnk_18, 0, 0x28);
    p->mUnk_04 = a;
    if (a == 0) {
        return;
    }
    m = 1 << ((a >> 8) & 0xff);
    p->mUnk_18 = m;
    x = a & 0xff;
    if (x == 1) {
        switch (m) {
            case 0x200:
                p->mUnk_20 = 0x10;
                p->mUnk_24 = 1;
                p->mUnk_28 = 0x4f;
                return;
            case 0x2000:
                p->mUnk_20 = 0x20;
                p->mUnk_24 = 2;
                p->mUnk_28 = 0x4f;
                return;
            case 0x10000:
                p->mUnk_20 = 0x80;
                p->mUnk_24 = 2;
                p->mUnk_28 = 0x9e;
                return;
        }
    } else if (x == 2) {
        switch (m) {
            case 0x40000:
                p->mUnk_2c = 0x18b;
                p->mUnk_30 = 0x127f;
                p->mUnk_3c = 0x127f;
                p->mUnk_38 = 0x13435;
                p->mUnk_34 = 0x13435;
                break;
            case 0x80000:
            case 0x100000:
                p->mUnk_2c = 0x18b;
                p->mUnk_30 = 0;
                p->mUnk_3c = 0x127f;
                p->mUnk_38 = 0x13435;
                break;
            default:
                goto fail;
        }
        p->mUnk_1c = 0x10000;
        p->mUnk_20 = 0x100;
        p->mUnk_24 = 3;
        p->mUnk_28 = 0x4f;
        return;
    } else if (x == 3) {
        if (m == 0x2000 || m == 0x8000) {
            p->mUnk_20 = m;
            p->mUnk_24 = 2;
            return;
        }
    }
fail:
    p->mUnk_04 = 0;
    p->mUnk_18 = 0;
    data_0217fa40.mUnk_00->mUnk_00 = 3;
}

// Stores f in mUnk_40 and starts the object at mUnk_44.
void func_02145b0c(UnkFunc *f) {
    Unk021458c4 *p;

    p = (Unk021458c4 *) (u32) &data_0217fa40;
    func_0200dce0(&p->mUnk_44, p->mUnk_108);
    p->mUnk_104 = &p->mUnk_44;
    p->mUnk_40 = f;
    p->mUnk_114 |= 8;
    func_0200df68(&p->mUnk_44);
}

// Waits until mUnk_08 is -3, then stores a and b in mUnk_08 and mUnk_18; counts mUnk_0c up.
void func_02145a70(u32 a, u32 b) {
    Unk021458c4 *p;
    u32 s;

    p = (Unk021458c4 *) (u32) &data_0217fa40;
    s = func_0200fca0();
    if (p->mUnk_08 == a) {
        if (p->mUnk_18 != b) {
            func_0200fd1c();
        }
    } else {
        while (p->mUnk_08 != -3) {
            func_0200e01c(&p->mUnk_10);
        }
        p->mUnk_08 = a;
        p->mUnk_18 = b;
    }
    p->mUnk_0c++;
    p->mUnk_00->mUnk_00 = 0;
    func_0200fcb4(s);
}

// Counts mUnk_0c down; at 0 sets mUnk_08 to -3 and passes mUnk_10 to func_0200df9c.
void func_021459cc(u32 a, u32 b) {
    Unk021458c4 *p;
    u32 s;

    p = &data_0217fa40;
    s = func_0200fca0();
    if (p->mUnk_08 != a || p->mUnk_0c == 0) {
        func_0200fd1c();
    } else {
        if (p->mUnk_18 != b) {
            func_0200fd1c();
        }
        p->mUnk_0c--;
        if (p->mUnk_0c == 0) {
            p->mUnk_08 = -3;
            p->mUnk_18 = 0;
            func_0200df9c(&p->mUnk_10);
        }
    }
    p->mUnk_00->mUnk_00 = 0;
    func_0200fcb4(s);
}

// non-matching: scheduling of the stores to mUnk_0c, mUnk_18 and mUnk_00 around the volatile zero (7 instructions
// differ, same size) Sets up data_0217fa40 and data_0217fa00 and starts the object at mUnk_44 with func_021469a4 and
// the 0x400 bytes before data_02180060.
void func_021458c4(void) {
    Unk021458c4 *p;

    p = &data_0217fa40;
    p->mUnk_08 = -3;
    p->mUnk_0c = 0;
    p->mUnk_18 = 0;
    p->mUnk_00 = &data_0217fa00;
    func_0214d05c_inline(&data_0217fa00, 0x40);
    func_0200ee74(&data_0217fa00, 0x40);
    if (*(u16 *) 0x027ffc40 != 2) {
        func_0214d1fc((void *) 0x027ffe00, (void *) 0x027ffa80, 0x160);
    }
    p->mUnk_10.mUnk_04 = 0;
    p->mUnk_10.mUnk_00 = p->mUnk_10.mUnk_04;
    p->mUnk_10c.mUnk_04 = 0;
    p->mUnk_10c.mUnk_00 = p->mUnk_10c.mUnk_04;
    p->mUnk_108 = 4;
    func_0200e28c(&p->mUnk_44, func_021469a4, 0, (u8 *) &data_02180060, 0x400, p->mUnk_108);
    func_0200df68(&p->mUnk_44);
    func_0214d7c4(11, func_02146a00);
    if (*(u16 *) 0x027ffc40 != 2) {
        func_02145878(1);
    }
}

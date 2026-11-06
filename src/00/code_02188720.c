#include "00/code_02188720.h"
#include "00/code_021884d8.h"
#include "00/unk_021b4000.h"
#include "00/code_02188008.h"
#include "00/code_02188694.h"
#include "00/code_02189478.h"
#include "00/code_0218a658.h"
#include "00/code_0218a000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_0218a67c.h"
#include "00/code_021892f4.h"
#include "code_0200fc8c.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_021519a8.h"

void func_ov000_02188d78(Unk02188d78 *p) {
    Unk02188408 *s;

    s = (Unk02188408 *) func_ov000_02188584(0x10);
    if (p->mUnk_00 == 5) {
        if (p->mUnk_02 != 0) {
            switch (p->mUnk_08) {
                case 0xd:
                    s->mUnk_d14 = 1;
                    break;
                case 0xf:
                    s->mUnk_d14 = 2;
                    break;
                case 0x11:
                    s->mUnk_d14 = 3;
                    break;
                default:
                    s->mUnk_d14 = 4;
                    break;
            }
        }
    } else if (p->mUnk_00 == 7) {
        func_ov000_02188ca8(p->mUnk_04);
    }
}

void func_ov000_02188ca8(Unk02188408Entry0xc0 *p) {
    Unk02188408 *s;
    s32 r;
    u32 a;

    r = -1;
    s = (Unk02188408 *) func_ov000_02188584(0x10);
    ((Unk021884e4 *) func_ov000_02188584(1))->mUnk_0b = 1;
    a = func_ov000_02188528();
    switch (a) {
        case 3:
            if (p->mUnk_0a == 0 || p->mUnk_0c[0] == 0) {
                func_ov000_02189e54(p->mUnk_36);
            } else if (p->mUnk_0a == 1 || p->mUnk_0c[0] == 0x20) {
                func_ov000_02189e54(p->mUnk_36);
                r = func_ov000_02188bc0(p, s->mUnk_d10, s->mUnk_300);
            } else {
                r = func_ov000_02188bc0(p, s->mUnk_d10, s->mUnk_300);
            }
            break;
        case 4:
        case 5:
            r = func_ov000_02188bc0(p, 1, s->mUnk_300 + s->mUnk_d0f);
            if (r >= 0) {
                s->mUnk_300[s->mUnk_d0f].mUnk_00 = (s->mUnk_300[s->mUnk_d0f].mUnk_00 & ~0xf) | 1;
            }
            break;
        default:
            return;
    }
    if (r >= 0) {
        func_ov000_021889b0(func_ov000_02188b20(r, p, s), s);
    }
}

s32 func_ov000_02188c1c(Unk02188408Entry0xc0 *p) {
    Unk02188408 *s;
    u8 f;

    s = (Unk02188408 *) func_ov000_02188584(0x10);
    if (s->mUnk_d0c_0 == 0 || s->mUnk_d0c_0 == 4) {
        f = p->mUnk_2c >> 4 & 1;
        if (f == 1) {
            if (func_ov000_0218a658((const u8 *) p->mUnk_0c) == 1) {
                return 6;
            }
        }
    }
    if (s->mUnk_d0c_0 == 0 || s->mUnk_d0c_0 == 5) {
        f = p->mUnk_2c >> 4 & 1;
        if (f == 1) {
            if (func_ov000_0218a6c8((const u8 *) p->mUnk_0c) == 1) {
                return 7;
            }
        }
    }
    return -1;
}

s32 func_ov000_02188bc0(Unk02188408Entry0xc0 *p, s32 n, Unk02188408Entry24 *t) {
    s32 i;
    s32 r;
    u16 h;

    if (p->mUnk_0a == 0x20) {
        r = func_ov000_02188c1c(p);
        if (r > 0) {
            return r;
        }
    }
    i = 0;
    if (n > 0) {
        h = p->mUnk_0a;
        do {
            if ((u8) h == t->mUnk_03) {
                if (strncmp(p->mUnk_0c, t->mUnk_04, h) == 0) {
                    return t->mUnk_01;
                }
            }
            t++;
            i++;
        } while (i < n);
    }
    return -1;
}

s32 func_ov000_02188b20(u32 a, Unk02188408Entry0xc0 *p, Unk02188408 *s) {
    s32 i;
    s32 r;
    char *e;
    s32 n;

    i = 0;
    r = -1;
    n = s->mUnk_d12;
    if (n > 0) {
        e = s->mUnk_470[0].mUnk_04;
        do {
            if (p->mUnk_04[0] == e[0] && p->mUnk_04[1] == e[1] && p->mUnk_04[2] == e[2] && p->mUnk_04[3] == e[3] &&
                p->mUnk_04[4] == e[4] && p->mUnk_04[5] == e[5]) {
                r = i;
                break;
            }
            e += 0xc0;
            i++;
        } while (i < s->mUnk_d12);
    }
    if (r == -1) {
        func_ov000_02188ad4(a, p, s);
        if (s->mUnk_d12 < 10) {
            s->mUnk_d12++;
        }
        r = 10;
    } else {
        func_ov000_02188a74(r, p, s);
    }
    return r;
}

void func_ov000_02188ad4(u8 a, Unk02188408Entry0xc0 *p, Unk02188408 *s) {
    Unk02188408Entry4 *t;
    Unk02188408Entry0xc0 *e;
    u16 h;

    t = &s->mUnk_444[10];
    e = &s->mUnk_470[10];
    t->mUnk_01 = a;
    h = p->mUnk_02;
    t->mUnk_02 = (h & 2) != 0 ? (u8) (h >> 2) : (u8) ((h >> 2) + 0x19);
    t->mUnk_03 = s->mUnk_d11 + 1;
    MemCopyWords(p, e, 0xc0);
}

void func_ov000_02188a74(u32 a, Unk02188408Entry0xc0 *p, Unk02188408 *s) {
    Unk02188408Entry4 *t;
    Unk02188408Entry0xc0 *e;
    u16 h;
    u8 v;
    s32 x;

    t = &s->mUnk_444[a];
    e = &s->mUnk_470[a];
    h = p->mUnk_02;
    x = (h & 2) != 0 ? (u8) (h >> 2) : (u8) ((h >> 2) + 0x19);
    v = x;
    if (v > t->mUnk_02) {
        t->mUnk_02 = v;
        t->mUnk_03 = s->mUnk_d11 + 1;
    }
    MemCopyWords(p, e, 0xc0);
}

void func_ov000_021889b0(u32 a, Unk02188408 *s) {
    Unk02188408Entry4 *t;
    Unk02188408Entry0xc0 *e;
    Unk02188408Entry4 *u;
    Unk02188408Entry0xc0 *w;
    Unk02188408Entry4 x;
    Unk02188408Entry0xc0 y;
    s32 i;

    t = s->mUnk_444;
    e = s->mUnk_470;
    i = a - 1;
    if (i >= 0) {
        u = &t[i];
        w = &e[i];
        do {
            if (t[a].mUnk_02 < u->mUnk_02) {
                break;
            }
            MemCopyWords(u, &x, 4);
            MemCopyWords(&t[a], u, 4);
            MemCopyWords(&x, &t[a], 4);
            MemCopyWords(w, &y, 0xc0);
            MemCopyWords(&e[a], w, 0xc0);
            MemCopyWords(&y, &e[a], 0xc0);
            a = i;
            u--;
            w--;
            i--;
        } while (i >= 0);
    }
    t += 10;
    func_0214d018_inline(t, 4);
    func_0214d018_inline(e + 10, 0xc0);
}

u32 func_ov000_02188868(Unk02188868 *p) {
    Unk021884e4 *z;
    Unk02188408 *q;
    Unk02188114 *y;
    s32 r;

    data_ov000_021b4d10 = p->mUnk_00(1, 0x18);
    func_0214d018_inline(data_ov000_021b4d10, 0x18);
    z = data_ov000_021b4d10;
    z->mUnk_00 = p->mUnk_00;
    z->mUnk_04 = p->mUnk_04;
    z->mUnk_09 = 1;
    z->mUnk_16 = 1;
    z->mUnk_08 = 1;
    data_ov000_021b4d00 = func_ov000_021886c4(0x10, 0xd18);
    data_ov000_021b4d04 = func_ov000_021886c4(2, 0x2300);
    data_ov000_021b4d08 = func_ov000_021886c4(4, 0x58);
    data_ov000_021b4d0c = func_ov000_021886c4(8, 0xc);
    func_0214d018_inline(data_ov000_021b4d00, 0xd18);
    func_0214d018_inline(data_ov000_021b4d04, 0x2300);
    func_0214d018_inline(data_ov000_021b4d08, 0x58);
    func_0214d018_inline(data_ov000_021b4d0c, 0xc);
    q = data_ov000_021b4d00;
    q->mUnk_d0a = p->mUnk_08;
    q->mUnk_d0b_0 = p->mUnk_09;
    y = data_ov000_021b4d0c;
    y->mUnk_00 = p->mUnk_00;
    y->mUnk_04 = p->mUnk_04;
    y->mUnk_08 = 0;
    q->mUnk_d0c_0 = p->mUnk_0a;
    q->mUnk_d0c_4 = p->mUnk_0b;
    func_021519a8(q);
    r = func_ov000_021a6470(data_ov000_021b4d04, 0x2300);
    if (r == 1 || r >= 4) {
        func_ov000_021885ec();
        return 0;
    }
    return 1;
}

s32 func_ov000_021887cc(void) {
    u8 a;
    u32 b;
    s32 c;

    a = func_ov000_02188528();
    if (a == 1) {
        a = func_ov000_02189f00();
    } else if (a < 7) {
        b = OS_DisableInterrupts();
        a = ((u8(*)(void)) func_ov000_02189e80)();
        func_ov000_02188534(a);
        OS_RestoreInterrupts(b);
    } else if (a < 9) {
        a = ((u8(*)(void)) func_ov000_0218922c)();
    } else if (a < 10) {
        a = ((u8(*)(void)) func_ov000_021897bc)();
    } else if (a < 16) {
        a = ((u8(*)(void)) func_ov000_0218a294)();
    } else if (a == 17) {
        a = func_ov000_021894c0();
    }
    func_ov000_02188534(a);
    if (a == 16) {
        c = func_ov000_02188408();
        func_ov000_021884a8();
        return c;
    }
    if (a == 18) {
        func_ov000_021884a8();
        return -1;
    }
    return 0;
}

u32 func_ov000_02188758(void) {
    u32 a;

    a = func_ov000_02188528();
    if (a <= 1) {
        return 0;
    }
    if (a < 7) {
        return 1;
    }
    if (a == 9) {
        return 4;
    }
    if (a < 10) {
        return 2;
    }
    if (a == 11) {
        return 4;
    }
    if (a < 16) {
        return 3;
    }
    if (a == 16) {
        return 5;
    }
    if (a == 17) {
        return 4;
    }
    return func_ov000_02189478();
}

u32 func_ov000_02188720(void) {
    u8 a;

    a = func_ov000_02188528();
    if (a == 0 || a == 0x12) {
        func_ov000_021885ec();
        return 1;
    }
    func_ov000_021892f4(&a);
    func_ov000_02188534(a);
    return 0;
}

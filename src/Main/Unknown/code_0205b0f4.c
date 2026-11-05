#include "Main/Unknown/code_0205b0f4.h"

#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_0205afa8.h"
#include "Main/Unknown/code_0205b000.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_0205c000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_021201e4.h"
#include "Main/Unknown/code_0205a908.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219b580.h"
#include "00/code_021832d8.h"
#include "01/code_021956dc.h"
#include "code_0200f5ac.h"
#include "code_0202056c.h"
#include "code_021458c4.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0203d568.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020b2e34.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0211ff74.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02061654.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_0205a92c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/code_0203c25c.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"

void func_0205d07c(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        data_0217aa18->mUnk_00[i] = -1;
        data_0217aa18->mUnk_06[i] = -1;
    }
    data_0217aa18->mUnk_05 = 0;
}

void func_0205cfd4(u32 a) {
    u8 i;
    u8 n;

    for (i = 0, n = 0; i < 4; i++) {
        data_0217aa18->mUnk_06[i] = -1;
        if ((a & (1 << i)) != 0) {
            data_0217aa18->mUnk_00[n] = i;
            data_0217aa18->mUnk_06[i] = n;
            n++;
        }
    }
    data_0217aa18->mUnk_04 = a;
    while (n < 4) {
        data_0217aa18->mUnk_00[n] = -1;
        n++;
    }
}

static inline BOOL func_0205c98c_inline(void) {
    u8 i;
    Unk0217aa14 *p;
    Unk0217aa14_754_04 *q;

    p = data_0217aa14;
    q = &p->mUnk_754->mUnk_04;
    for (i = 0; i < 4; i++) {
        if (p->mUnk_014[i].mUnk_30 != FALSE) {
            MemCopy(&p->mUnk_014[i], q, 0x28);
            *(u64 *) &q->mUnk_0c[2] = func_0200f5ac();
            if (func_0205c340(i, 0, 0x28) != 0) {
                data_0217aa14->mUnk_014[i].mUnk_30 = FALSE;
            } else {
                MemFill(q, 0, 0x28);
            }
            return TRUE;
        }
    }
    return FALSE;
}

void func_0205cd24(void *a) {
    s32 i;
    s32 j;
    u8 k;
    s32 n;
    u8 m;
    Unk0217aa14 *p;

    if (data_021759c0->mMode != 5) {
        return;
    }
    data_0217aa14 = HeapAlloc(a, 0x760);
    data_0217aa14->mUnk_754 = HeapAllocAligned(a, 0x6c, 0x20);
    for (i = 0; i < 16; i++) {
        data_0217aa14->mUnk_324[i].mUnk_04 = HeapAllocAligned(a, 20, 32);
        for (j = 0; j < 4; j++) {
            data_0217aa14->mUnk_3e4[i][j].mUnk_04 = HeapAllocAligned(a, 20, 32);
        }
    }
    data_0217aa14->mUnk_0fc = data_0217aa18->mUnk_04;
    MemFill(data_0217aa14->mUnk_754, 0, 0x6c);
    for (n = 0; n < 4; n++) {
        MemFill(&data_0217aa14->mUnk_104[n], 0, 0x68);
        data_0217aa14->mUnk_104[n].mUnk_86_0 = 0;
    }
    k = data_0217aa14->mUnk_0fc;
    data_0217aa14->mUnk_748 = 0;
    data_0217aa14->mUnk_749 = k;
    for (k = 0; k < 4; k++) {
        data_0217aa14->mUnk_74a[k] = 0;
        data_0217aa14->mUnk_740[k] = 0;
    }
    func_0205ad88();
    func_0205a6b4();
    data_0217aa14->mUnk_75c |= 1;
    data_0217aa14->mUnk_75c |= 0x40;
    p = data_0217aa14;
    p->mUnk_010 = 0;
    p->mUnk_012 = 1;
    data_0217aa14->mUnk_758 = 0;
    for (m = 0; m < 4; m++) {
        j = data_0217aa18->mUnk_06[m];
        data_0217aa14->mUnk_104[m].mUnk_80 = 0;
        if (j >= 0) {
            data_0217aa14->mUnk_104[m].mUnk_86_1 = func_0205d27c((u8) j);
        } else {
            data_0217aa14->mUnk_104[m].mUnk_86_1 = 0;
        }
    }
    func_02046be8(data_0217aa14, data_02165388, 6, NULL);
}

void func_0205ccec(void) {
    Unk0217aa14 *p;

    p = data_0217aa14;
    if (p == NULL) {
        return;
    }
    switch (p->mUnk_00e) {
        case 4:
        case 5:
            p->mUnk_728++;
            break;
    }
}

void func_0205cbe4(void) {
    u8 i;
    s32 *e;
    Unk0217aa14 *b;

    for (i = 0; i < 4; i++) {
        e = &data_0217aa14->mUnk_014[i].mUnk_04;
        e[0] = 0;
        e[1] = 0;
        e[2] = 0;
        e[3] = 0;
        e[4] = 0;
        e[5] = 0;
        e[6] = 0;
        e[7] = 0;
        e[8] = 0;
        b = data_0217aa14;
        b->mUnk_014[i].mUnk_28 = 0;
        b->mUnk_014[i].mUnk_2c = 0;
        b->mUnk_014[i].mUnk_34 = 0;
        data_0217aa14->mUnk_014[i].mUnk_35 = 0;
        data_0217aa14->mUnk_014[i].mUnk_36 = 0;
    }
    data_0217aa14->mUnk_0f8 = 0;
    data_0217aa14->mUnk_0fb = 0;
    data_0217aa14->mUnk_0fd = 0;
    data_0217aa14->mUnk_0f4 = 0;
    data_0217aa14->mUnk_736 = 0x7f;
    data_0217aa14->mUnk_758 = 1;
    data_0217aa14->mUnk_75c &= ~2;
    data_0217aa14->mUnk_75c |= 0x80;
    data_0217aa14->mUnk_75c &= ~0x10;
}

void func_0205c98c(void) {
    u16 i;
    u8 m;
    u16 k;
    u8 b;
    Unk0217aa14 *p;
    Unk0217aa14_754_04 *q;
    Unk0217aa14_754 *r;

    m = 0;
    for (i = 0; i < 4; i++) {
        if (i == func_ov000_0219bb50() || data_0217aa14->mUnk_014[i].mUnk_34 >= 12) {
            m = m | (1 << i);
        }
    }
    p = data_0217aa14;
    if (p->mUnk_749 == (p->mUnk_749 & m)) {
        p->mUnk_0fb = m;
        p = data_0217aa14;
        p->mUnk_010 = 2;
        p->mUnk_012 = 1;
    }
    if (func_0205c98c_inline() != FALSE) {
        return;
    }
    p = data_0217aa14;
    k = p->mUnk_0f8;
    if (k < 4) {
        b = k;
        if ((p->mUnk_749 & (1 << b)) != 0 && b != func_ov000_0219bb50()) {
            p = data_0217aa14;
            if (p->mUnk_014[b].mUnk_34 < 12) {
                r = p->mUnk_754;
                q = &r->mUnk_04;
                r->mUnk_04.mUnk_00_h = func_ov000_0219bb50();
                *(u64 *) &q->mUnk_04 = func_0200f5ac();
                q->mUnk_0c[0] = 0;
                q->mUnk_0c[1] = 0;
                q->mUnk_0c[2] = 0;
                q->mUnk_0c[3] = 0;
                q->mUnk_0c[4] = 0;
                *(u32 *) &q->mUnk_20[0] = 0;
                func_0205c340(b, 0, 0x28);
            } else {
                if (p->mUnk_014[b].mUnk_36 == 0) {
                    func_0205c340(b, 5, 0);
                }
                data_0217aa14->mUnk_014[b].mUnk_36++;
                if (data_0217aa14->mUnk_014[b].mUnk_36 > 4) {
                    data_0217aa14->mUnk_014[b].mUnk_36 = 0;
                }
            }
        }
        data_0217aa14->mUnk_0f8++;
    } else {
        p->mUnk_0f8 = 0;
    }
}

void func_0205c898(void) {
    s32 i;
    Unk0217aa14 *p;
    u8 n;
    u64 x;

    data_0217aa14->mUnk_0fa = 1 << func_ov000_0219bb50();
    data_0217aa14->mUnk_736 = 0x7f;
    data_0217aa14->mUnk_0f8 = 0;
    for (i = 0; i < 4; i++) {
        p = data_0217aa14;
        n = p->mUnk_014[i].mUnk_34;
        x = *(u64 *) &p->mUnk_014[i].mUnk_28;
        if (n == 0) {
            p->mUnk_104[i].mUnk_84 = 0;
        } else {
            p->mUnk_104[i].mUnk_84 = (x / n * 64 / 0x82ea + 32) / 33;
        }
    }
}

void func_0205c800(u16 a, void (*b)(u32)) {
    u16 i;
    s32 r;
    u16 n;

    r = -1;
    for (i = 1; i <= 4; i++) {
        n = a + i;
        if (n >= 4) {
            n = n - 4;
        }
        if (n != func_ov000_0219bb50() && (data_0217aa14->mUnk_749 & (1 << (u8) n)) != 0) {
            r = n;
            break;
        }
    }
    if (r == -1) {
        return;
    }
    b(r);
}

void func_0205c7a0(u32 a) {
    u8 index;
    if (a == 0xffffffff) {
        return;
    }
    index = a;
    if (data_0217aa14->mUnk_749 & (1 << index)) {
        if (func_0205c340(index, 1, 8) != 0) {
            data_0217aa14->mUnk_0f8 = index;
        }
    }
}

void func_0205c6b0(void) {
    Unk0217aa14 *p;
    u8 i;
    Unk0217aa14_754_04 *q;

    p = data_0217aa14;
    q = &p->mUnk_754->mUnk_04;
    for (i = 0; i < 4; i++) {
        if (p->mUnk_014[i].mUnk_30 != FALSE) {
            MemCopy(&p->mUnk_014[i], q, 0x28);
            *(u64 *) &q->mUnk_0c[2] = func_0200f5ac();
            if (func_0205c340(i, 0, 0x28) != 0) {
                data_0217aa14->mUnk_014[i].mUnk_30 = FALSE;
            } else {
                MemFill(q, 0, 0x28);
            }
            break;
        }
    }
    p = data_0217aa14;
    if (p->mUnk_749 == (p->mUnk_749 & p->mUnk_0fa)) {
        p->mUnk_010 = 3;
        p->mUnk_012 = 1;
        return;
    }
    func_0205c800(p->mUnk_0f8, func_0205c7a0);
}

void func_0205c684(void) {
    data_0217aa14->mUnk_736 = 0xf0;
    data_0217aa14->mUnk_734 = 0;
}

void func_0205c610(u32 a) {
    Unk0217aa14_754 *q;
    Unk0217aa14_754_04 *r;

    q = data_0217aa14->mUnk_754;
    r = &q->mUnk_04;
    r->mUnk_00_h = data_0217aa14->mUnk_736 - data_0217aa14->mUnk_104[a].mUnk_84;
    r->mUnk_04_b[0] = data_0217aa14->mUnk_0fb;
    if (func_0205c340((u8) a, 2, 8) != 0) {
        data_0217aa14->mUnk_734 = a;
    }
}

void func_0205c594(void) {
    Unk0217aa14 *p;

    data_0217aa14->mUnk_736 = data_0217aa14->mUnk_736 - 1;
    if (data_0217aa14->mUnk_736 <= 0) {
        data_0217aa14->mUnk_736 = -1;
        p = data_0217aa14;
        p->mUnk_010 = 4;
        p->mUnk_012 = 1;
        return;
    }
    func_0205c800(data_0217aa14->mUnk_734, func_0205c610);
}

void func_0205c470(void) {
    u8 i;

    data_0217aa14->mUnk_75c = data_0217aa14->mUnk_75c | 2;
    data_0217aa14->mUnk_75c = data_0217aa14->mUnk_75c & ~0x20;
    data_0217aa14->mUnk_75c = data_0217aa14->mUnk_75c & ~0x200;
    data_0217aa14->mUnk_728 = 0;
    data_0217aa14->mUnk_73a = 0;
    data_0217aa14->mUnk_73d = 0;
    data_0217aa14->mUnk_73b = 0;
    data_0217aa14->mUnk_73e = 0;
    data_0217aa14->mUnk_72c = FALSE;
    data_0217aa14->mUnk_738 = 0;
    data_0217aa14->mUnk_758 = 2;
    MemFill(data_0217aa14->mUnk_754, 0, 0x6c);
    for (i = 0; i < 4; i++) {
        if ((data_0217aa14->mUnk_0fc & (1 << i)) != 0 && (data_0217aa14->mUnk_749 & (1 << i)) == 0) {
            if (data_0217aa18->mUnk_06[i] >= 0) {
                data_0217aa14->mUnk_104[i].mUnk_80 = (func_0205d27c((u8) data_0217aa18->mUnk_06[i]) - 1) | 0x700000;
            }
        }
    }
}

int func_0205c340(u8 a, u32 b, int c) {
    Unk0205b504 *m;
    int r;

    r = 1;
    if ((data_0217aa14->mUnk_75c & 4) != 0) {
        return 0;
    }
    if (a != func_ov000_0219bb50()) {
        r = c + 4;
        m = (Unk0205b504 *) data_0217aa14->mUnk_754;
        data_0217aa14->mUnk_75c = data_0217aa14->mUnk_75c | 4;
        m->mUnk_00_0 = func_ov000_0219bb50();
        m->mUnk_00_2 = a;
        m->mUnk_00_4 = (u8) b;
        m->mUnk_01 = data_0217aa14->mUnk_758;
        m->mUnk_02_0 = data_0217aa14->mUnk_748;
        func_0200ee58(m, r);
        r = func_02120340(a, m, r, func_0211ff74);
        if (r == 0) {
            data_0217aa14->mUnk_75c = data_0217aa14->mUnk_75c & ~4;
        }
    }
    return r;
}

void func_0205c234(s32 a) {
    u8 i;
    s8 j;
    s32 n;
    u8 t;

    n = 0;
    t = data_0217aa14->mUnk_73a;
    if ((t & 1) == 0) {
        data_0217aa14->mUnk_73a = t + 1;
        return;
    }
    i = t >> 1;
    j = i - 1;
    if (j < 0) {
        j = j + 4;
    }
    while (n < 1 && i != j) {
        if (i != func_ov000_0219bb50() && (data_0217aa14->mUnk_749 & (1 << i)) != 0) {
            if (func_0205c340(i, 3, a) != 0) {
                i = i + 1;
                if (i >= 4) {
                    i = 0;
                }
                n = n + 1;
            } else {
                i = i + 1;
                if (i >= 4) {
                    i = 0;
                }
            }
        } else {
            i = i + 1;
            if (i >= 4) {
                i = 0;
            }
        }
    }
    data_0217aa14->mUnk_73a = i << 1;
}

void func_0205be0c(void) {
    u32 a[4];
    u8 b[4];
    u8 i;
    u8 j;
    u8 l;
    u8 n;
    s16 m;
    u32 x;
    u32 y;
    u8 k;
    u8 z;
    u32 t;
    u32 f;
    u32 g;
    u32 h;
    u32 u;
    u32 q;
    Unk0217aa14 *d;
    u32 s;
    u8 p;
    u32 c;
    u32 r;

    x = 0xf;
    for (i = 0; i < 4; i++) {
        a[i] = -1;
        b[i] = i;
        d = data_0217aa14;
        s = 1 << i;
        t = d->mUnk_749 & s;
        if (t != 0) {
            q = 0;
            if ((d->mUnk_0fc & s) != 0) {
                q = t == 0;
            }
            if (q != 0) {
                a[i] = d->mUnk_104[i].mUnk_80 & 0x3fffff;
            } else {
                if (i == func_ov000_0219bb50()) {
                    f = func_0205afa8();
                    g = data_0217aa14->mUnk_73e;
                } else {
                    f = data_0217aa14->mUnk_104[i].mUnk_04;
                    g = (u8) ((f & 0x7800000) >> 23);
                }
                x = x & g;
                if (f == 0 && func_02061fec() == 0) {
                    if (data_0217aa18->mUnk_06[i] != -1) {
                        f = (func_0205d27c((u16) data_0217aa18->mUnk_06[i]) - 1) | 0x700000;
                    }
                }
                if (f != 0) {
                    if ((u8) ((f & 0x400000) >> 22) == 0) {
                        data_0217aa14->mUnk_73e = data_0217aa14->mUnk_73e | s;
                    }
                    data_0217aa14->mUnk_104[i].mUnk_80 = f;
                    a[i] = data_0217aa14->mUnk_104[i].mUnk_80 & 0x3fffff;
                }
            }
        }
    }
    for (i = 0; i < 4; i++) {
        d = data_0217aa14;
        s = 1 << i;
        h = *(u8 *) &data_0217aa18->mUnk_06[i];
        u = d->mUnk_104[i].mUnk_80;
        t = d->mUnk_749 & s;
        if (t != 0) {
            q = 0;
            if ((d->mUnk_0fc & s) != 0) {
                q = t == 0;
            }
            if (q == 0 && (x & s) != 0 && IsKartEnded(h) == 0) {
                func_0203e4c4(h, (u & 0x7ffff) != 0x7ffff);
            }
        }
    }
    for (l = 1; l < 4; l++) {
        n = l;
        y = a[l];
        k = b[l];
        while (n != 0 && a[n - 1] > y) {
            a[n] = a[n - 1];
            b[n] = b[n - 1];
            n--;
        }
        a[n] = y;
        b[n] = k;
    }
    for (j = 0; j < 4; j++) {
        i = b[j];
        z = 0;
        d = data_0217aa14;
        r = d->mUnk_0fc;
        if ((r & (1 << i)) != 0) {
            if ((u8) (((u32) d->mUnk_104[i].mUnk_80 & 0x400000) >> 22) == 0) {
                z = j + 1;
                for (m = j; m >= 0; m--) {
                    if ((u8) (((u32) d->mUnk_104[b[m]].mUnk_80 & 0x400000) >> 22) != 0) {
                        z = z - 1;
                    }
                }
            } else {
                u16 w;

                w = (u16) data_0217aa18->mUnk_06[i];
                c = gRaceProgress->mUnk_000[w].mUnk_50_0;
                z = c;
                for (p = 0; p < 4; p++) {
                    u32 e;

                    if ((u8) (((u32) d->mUnk_104[p].mUnk_80 & 0x400000) >> 22) == 0) {
                        e = 1;
                    } else {
                        e = 0;
                    }
                    if ((r & (1 << p)) != 0) {
                        u16 o;
                        u32 v;

                        o = data_0217aa18->mUnk_06[p];
                        o = (u16) o;
                        v = gRaceProgress->mUnk_000[o].mUnk_50_0;
                        if (gRaceProgress->mUnk_000[o].mStatus != 4 && e != 0 && v > c) {
                            z = z + 1;
                        }
                    }
                }
            }
        }
        d->mUnk_104[i].mUnk_86_1 = z;
    }
}

void func_0205bc08(void) {
    u16 v;
    u32 w;
    Unk0217aa14 *p;
    Unk0217aa14_754 *q;
    Unk0217aa14_754_04 *r;

    func_0205a908();
    func_0205a350();
    p = data_0217aa14;
    q = p->mUnk_754;
    r = &q->mUnk_04;
    v = 0x68 - p->mUnk_724;
    q->mUnk_04.mUnk_00_0 = p->mUnk_728;
    r->mUnk_00_b[3] = v;
    if (data_0217aa18->mUnk_06[func_ov000_0219bb50()] < 0) {
        r->mUnk_04 = 0;
    } else {
        w = func_0205afa8();
        r->mUnk_04 = w | ((data_0217aa14->mUnk_73e << 23) & 0x7800000);
    }
    func_0205c234(v);
    func_0205be0c();
    if (IsKartEnded(*(u8 *) &data_0217aa18->mUnk_06[func_ov000_0219bb50()]) == 0 &&
        (data_0217aa14->mUnk_75c & 0x200) == 0) {
        if (data_0217562a[func_020435bc()].mBits == 0) {
            data_0217aa14->mUnk_738 = data_0217aa14->mUnk_738 + 1;
            if (data_0217aa14->mUnk_738 > 0x708) {
                data_0217aa14->mUnk_75c = data_0217aa14->mUnk_75c | 0x200;
                func_021208e8(1);
            }
        } else {
            data_0217aa14->mUnk_738 = 0;
        }
    }
    if (data_0217aa14->mUnk_758 == 2) {
        switch (func_020b2e34()) {
            case 2:
            case 7:
                data_0217aa14->mUnk_758 = 4;
                p = data_0217aa14;
                p->mUnk_010 = 5;
                p->mUnk_012 = 1;
                break;
            case 9:
                data_0217aa14->mUnk_758 = 3;
                p = data_0217aa14;
                p->mUnk_010 = 5;
                p->mUnk_012 = 1;
                break;
        }
    }
}

u32 func_0205bbe8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa14;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (value0) + (0x700u);
    value1 = (u32) * (const u16 *) ((value0) + (92));
    value1 = (value1) & ~(0x100u);
    *(u16 *) ((value0) + (92)) = (u16) value1;
    return value0;
}

u32 func_0205bba8(void) {
    u32 r;
    Unk0217aa14 *p;

    p = data_0217aa14;
    r = 0;
    if (p->mUnk_758 != 3) {
        if (p->mUnk_758 != 5) {
            return r;
        }
        if ((p->mUnk_75c & 0x100) != 0) {
            r = 2;
        }
        return r;
    }
    return 9;
}

void func_0205ba60(void) {
    Unk0217aa14 *p;
    u8 a;
    u8 b;
    u8 i;
    enum { K0 } v1;

    a = 0;
    b = 0;
    p = data_0217aa14;
    switch (p->mUnk_758) {
        case 3:
        case 4:
            for (i = 0; i < 4; i++) {
                v1 = 1 << i;
                if ((data_0217aa14->mUnk_749 & v1) != 0 && i != func_ov000_0219bb50()) {
                    if (data_0217aa14->mUnk_74e[i] != 4 && data_0217aa14->mUnk_74e[i] != 5) {
                        a = a | v1;
                    }
                }
            }
            if (a == 0) {
                data_0217aa14->mUnk_758 = 5;
            }
            break;
        case 5:
            for (a = 0; a < 4; a++) {
                v1 = 1 << a;
                if ((p->mUnk_749 & v1) != 0 && p->mUnk_74e[a] == 5) {
                    b = b | v1;
                }
            }
            if ((p->mUnk_749 & ~b) == 0) {
                p->mUnk_75c = p->mUnk_75c | 0x100;
            }
            if ((data_0217aa14->mUnk_749 | ~b) != 0) {
                data_0217aa14->mUnk_75c = data_0217aa14->mUnk_75c | 0x100;
            }
            break;
    }
    if ((data_0217aa14->mUnk_749 & ~b) == 0) {
        data_0217aa14->mUnk_758 = 5;
    }
}

void func_0205b9a8(void) {
    u16 v;
    Unk0217aa14 *p;
    Unk0217aa14_754 *q;
    Unk0217aa14_754_04 *r;
    s32 t;

    func_0205a908();
    func_0205a350();
    p = data_0217aa14;
    q = p->mUnk_754;
    r = &q->mUnk_04;
    v = 0x68 - p->mUnk_724;
    q->mUnk_04.mUnk_00_0 = p->mUnk_728;
    r->mUnk_00_b[3] = v;
    if (data_0217aa18->mUnk_06[func_ov000_0219bb50()] < 0) {
        r->mUnk_04 = 0;
    } else {
        t = func_0205afa8();
        r->mUnk_04 = t | ((data_0217aa14->mUnk_73e << 23) & 0x7800000);
    }
    func_0205c234(v);
    func_0205be0c();
    func_0205ba60();
}

Unk0217aa14_104 *func_0205b978(s32 a, u32 b) {
    Unk0217aa14_104 *e;

    e = &data_0217aa14->mUnk_104[a];
    if (b != e->mUnk_00_0) {
        return NULL;
    }
    return e;
}

s32 func_0205b954(s32 a) {
    return data_0217aa14->mUnk_104[a].mUnk_00_0;
}

void func_0205b824(const u64 *a, s32 b) {
    u8 n;
    u64 d;
    Unk0217aa14 *p;
    BOOL f;

    p = data_0217aa14;
    n = p->mUnk_014[b].mUnk_34;
    if (n >= 12) {
        return;
    }
    if (n != 0) {
        d = (a[3] - a[0]) - (a[2] - a[1]);
        if (d * 64 / 0x82ea < 1000) {
            *(u64 *) &p->mUnk_014[b].mUnk_28 += d;
            f = TRUE;
        } else {
            f = FALSE;
            data_0217aa14->mUnk_014[b].mUnk_35++;
            if (data_0217aa14->mUnk_014[b].mUnk_35 > 0x40) {
                data_0217aa14->mUnk_748 |= 1 << b;
            }
        }
    } else {
        f = TRUE;
    }
    if (f != FALSE) {
        n = n + 1;
    }
    data_0217aa14->mUnk_014[b].mUnk_34 = n;
}

void func_0205b778(u32 a, Unk0205b504 *b, u32 c) {
    Unk0217aa14 *p;
    Unk0217aa14_104 *e;
    u8 *s;
    u32 y;
    u32 v1;
    u8 n;
    u32 x;

    v1 = b->mUnk_00_0;
    p = data_0217aa14;
    s = b->mUnk_04.mUnk_00_b;
    y = b->mUnk_04.mUnk_00_0;
    x = p->mUnk_104[v1].mUnk_00_0;
    e = &p->mUnk_104[v1];
    n = s[3];
    if (p->mUnk_00e != 4 && p->mUnk_00e != 5) {
        return;
    }
    if (x != 0 && x >= y) {
        return;
    }
    if (p->mUnk_104[v1].mUnk_86_0 == 0) {
        p->mUnk_104[v1].mUnk_86_0 = 1;
    }
    MemCopy(s, e, n);
}

void func_0205b6bc(u32 a, Unk0205b504 *b, u32 c) {
    s32 t;
    Unk0217aa14 *p;
    s16 x;
    s16 v;
    s16 d;
    u32 v1;

    x = b->mUnk_04.mUnk_00_s;
    p = data_0217aa14;
    v = p->mUnk_736;
    if (p->mUnk_00e == 2) {
        v1 = 1 << b->mUnk_00_0;
        if ((p->mUnk_0fa & v1) == 0) {
            p->mUnk_0fa |= v1;
        }
        return;
    }
    if (v < 0) {
        return;
    }
    d = x - v;
    if (d > 0) {
        d = (d + 1) >> 1;
    } else if (d < 0) {
        d = (d - 1) >> 1;
    }
    t = (d << 11) + (data_0217aa14->mUnk_0f4 >> 1);
    data_0217aa14->mUnk_0f4 = t;
    data_0217aa14->mUnk_736 += (s16) ((t + 0x800) >> 12);
}

void func_0205b504(u32 a, Unk0205b504 *b, u32 c, u32 d) {
    u32 v1;
    Unk0217aa14 *p;
    Unk0205b504_04 *m;
    Unk0217aa14_014 *e;
    u32 i;
    u64 t;
    u8 v;

    p = data_0217aa14;
    if (p == NULL) {
        return;
    }
    v1 = b->mUnk_00_0;
    if ((p->mUnk_749 & (1 << v1)) == 0) {
        return;
    }
    p->mUnk_740[v1] = 0;
    data_0217aa14->mUnk_74a[b->mUnk_00_0] = b->mUnk_02_0;
    data_0217aa14->mUnk_74e[b->mUnk_00_0] = b->mUnk_01;
    switch (((volatile Unk0205b504 *) b)->mUnk_00_4) {
        case 0:
            m = &b->mUnk_04;
            i = b->mUnk_00_0;
            v = func_ov000_0219bb50();
            if (m->mUnk_00 == v) {
                m->mUnk_04[3] = func_0200f5ac();
                func_0205b824(m->mUnk_04, i);
                return;
            }
            if (m->mUnk_00 >= 4) {
                return;
            }
            e = &data_0217aa14->mUnk_014[i];
            MemCopy(m, e, 0x28);
            t = func_0200f5ac();
            e->mUnk_0c = t;
            e->mUnk_10 = t >> 32;
            data_0217aa14->mUnk_014[i].mUnk_30 = TRUE;
            break;
        case 1:
            data_0217aa14->mUnk_0fa = data_0217aa14->mUnk_0fa | (1 << b->mUnk_00_0);
            break;
        case 2:
            func_0205b6bc(a, b, c);
            break;
        case 3:
            func_0205b778(a, b, c);
            break;
        case 4:
        case 5:
            break;
    }
}

void func_0205b32c(void) {
    s16 a[4];
    s16 v1[4];
    s32 v2;
    u8 i;
    u8 j;
    u8 k;
    u8 v3;
    s32 s;
    s8 m;
    u32 x;
    u32 y;
    s16 d;

    for (i = 0; i < 4; i++) {
        if (data_0217aa18->mUnk_06[i] == -1) {
            a[i] = 5000;
        } else {
            a[i] = func_02120220(i);
        }
    }
    for (i = 0; i < 4; i++) {
        s = data_0217aa18->mUnk_06[i];
        if (s == -1) {
            continue;
        }
        v1[i] = a[i];
        for (j = 0; j < 4; j++) {
            k = 1;
            m = data_0217aa18->mUnk_06[j];
            if (m == -1 || s == m) {
                continue;
            }
            x = GetKartRank((u16) s);
            y = GetKartRank((u16) m);
            if (x > y) {
                k = 0;
            }
            d = a[j] - a[i];
            for (v3 = 0; v3 < 9; v3++) {
                if (d > data_021548e0[v3].mUnk_00) {
                    if (k != 0) {
                        v2 = data_021548e0[v3].mUnk_02;
                    } else {
                        v2 = data_021548e0[v3].mUnk_03;
                    }
                    break;
                }
            }
            v1[i] += v2;
            if (v1[i] < 0) {
                v1[i] = 0;
                continue;
            }
            if (v1[i] > 10000) {
                v1[i] = 10000;
            }
        }
        func_02120200(i, v1[i]);
    }
}

void func_0205b0f4(void) {
    u8 i;
    u32 a;
    u32 v1;
    u32 v2;
    u8 t;
    u16 v;
    u32 n;
    Unk0217aa08_00 *q;

    for (i = 0; i < 4; i++) {
        v1 = 1 << i;
        if ((data_0217aa14->mUnk_749 & v1) != 0 && i != func_ov000_0219bb50() && (data_0217aa14->mUnk_748 & v1) == 0) {
            v2 = 300;
            if (data_0217aa14->mUnk_014[i].mUnk_34 == 0) {
                v2 = 600;
            }
            data_0217aa14->mUnk_740[i]++;
            if (data_0217aa14->mUnk_740[i] > v2) {
                data_0217aa14->mUnk_748 |= v1;
            }
        }
    }
    a = data_0217aa14->mUnk_748;
    for (i = 0; i < 4; i++) {
        if ((data_0217aa14->mUnk_749 & (1 << i)) != 0) {
            if (i != func_ov000_0219bb50()) {
                if ((data_0217aa14->mUnk_748 & (1 << i)) == 0) {
                    t = data_0217aa14->mUnk_74a[i] | (1u << i);
                    a = a & t;
                }
            }
        }
    }
    if (a == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        v1 = 1 << i;
        if ((a & v1) != 0 && (data_0217aa14->mUnk_749 & v1) != 0 && data_0217aa18->mUnk_06[i] != -1) {
            func_0203c2e4(data_0217aa18->mUnk_06[i]);
            data_0217aa14->mUnk_749 = data_0217aa14->mUnk_749 & ~v1;
        }
    }
    if (CountSetBits(data_0217aa14->mUnk_749) > 1) {
        return;
    }
    v = gWiFiSession->mUnk_0008.mState;
    q = data_0217aa08->mUnk_00;
    n = q->mUnk_34[5];
    if (v != 0) {
        s8 c = gWiFiSession->mKartCountCopy - 1;
        if (c > 0) {
            if (n < c) {
                n = 0;
            } else {
                n = n - c;
            }
        }
        q->mUnk_34[5] = n;
        func_02056d40();
        func_02057d9c();
        if (data_021759d4->mUnk_0c != 0) {
            func_02145d38();
        }
    }
    func_021208e8(2);
}

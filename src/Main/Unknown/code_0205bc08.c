#include "Main/Unknown/code_02059be4.h"
#include "Main/Unknown/code_0205bc08.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_0205a908.h"
#include "Main/Unknown/code_0205afa8.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_0205c7a0.h"
#include "Main/Unknown/code_0205c800.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0203d568.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020b2e34.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0211ff74.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_0219b580.h"
#include "code_0200eddc.h"
#include "code_0200f5ac.h"
#include "code_0214d018.h"

void func_0205c6b0(void) {
    Unk0217aa14 *p;
    u8 i;
    Unk0217aa14_754_04 *q;

    p = data_0217aa14;
    q = &p->mUnk_754->mUnk_04;
    for (i = 0; i < 4; i++) {
        if (p->mUnk_014[i].mUnk_30 != 0) {
            MemCopy(&p->mUnk_014[i], q, 0x28);
            *(u64 *) &q->mUnk_0c[2] = func_0200f5ac();
            if (func_0205c340(i, 0, 0x28) != 0) {
                data_0217aa14->mUnk_014[i].mUnk_30 = 0;
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
    data_0217aa14->mUnk_72c = 0;
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
            if (q == 0 && (x & s) != 0 && func_0203c880(h) == 0) {
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
                c = data_0217561c->mUnk_000[w].mUnk_50_0;
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
                        v = data_0217561c->mUnk_000[o].mUnk_50_0;
                        if (data_0217561c->mUnk_000[o].mUnk_14 != 4 && e != 0 && v > c) {
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
    if (func_0203c880(*(u8 *) &data_0217aa18->mUnk_06[func_ov000_0219bb50()]) == 0 &&
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

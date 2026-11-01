#include "Main/Unknown/code_020790e0.h"
#include "Main/Unknown/code_02056444.h"
#include "Main/Unknown/code_020478bc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0207a14c.h"
#include "Main/Unknown/code_020638c0.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02088430.h"
#include "Main/Unknown/code_02079988.h"
#include "Main/Unknown/code_02079a3c.h"
#include "Main/Unknown/code_02079a14.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_02088888.h"
#include "Main/Unknown/code_020883e4.h"
#include "Main/Unknown/code_02085984.h"
#include "Main/Unknown/code_020476ac.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02013740.h"
#include "code_02135014.h"
#include "code_02147cd8.h"
#include "code_0214c1bc.h"
#include "code_02133048.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02013730.h"

#pragma thumb on

void func_020790e0(void *a, s32 b) {
    if (b != 0) {
        data_0217ad08->mUnk_1e0 = 0;
        data_0217ad08->mUnk_268 = func_02056444(a);
    } else {
        data_0217ad08->mUnk_1e0 = 1;
    }
    data_0217ad08->mUnk_1d0 = func_02079478(a);
    data_0217ad08->mUnk_1cc = 0;
}

void func_0207913c(void *a, const void *b, void **c) {
    char d[0x100];
    func_02135048(d, 0x100, "/data/KartModelMenu/%s", b);
    func_02048590(d, (u32) a, c);
}

void func_0207916c(void *a) {
    void *v4 = func_02047950("character/common/KillerItem.nsbmd");
    Unk020136f0 *v6 = (Unk020136f0 *) func_020478bc((u32) "character/common/KillerItem.nsbtx");
    void *v7 = func_02047950("character/common/KillerItem_s.nsbmd");
    void *v8;
    func_0207a14c(func_02084b2c(a, &data_0217ad00->mUnk_02c, v4, v6), 0);
    func_020849c0(&data_0217ad00->mUnk_02c, 3);
    v8 = func_02047950("character/common/KillerItem.nsbca");
    func_0208823c(0, &data_0217ad00->mUnk_10c, &data_0217ad00->mUnk_02c, 1, a, v4);
    func_0208805c(&data_0217ad00->mUnk_10c, v8, a);
    func_02087f84(&data_0217ad00->mUnk_10c, 0);
    func_0207afa8(&data_0217ad00->mUnk_098, v7, 3);
    func_020638dc(&data_0217ad00->mUnk_02c);
}

void func_02079220(Unk0206bcb0_590 *a, void *b) {
    void *v6;
    u8 *p;
    v6 = func_02047950(func_020884bc((u16) a->mUnk_004));
    a->mUnk_01c = func_02036bec(b, 0x74);
    func_0208526c(&a->mUnk_01c->mUnk_00.mUnk_5c, v6, v6);
    p = (u8 *) func_02013730((u32) v6);
    func_0207b000(&a->mUnk_01c->mUnk_00, p + *(s32 *) (p + *(u16 *) (p + 0xe) + 0xc), 3);
}

void func_0207926c(Unk0206bcb0_590 *a, void *b) {
    u16 v6 = (u16) a->mUnk_004;
    void *v7;
    Unk0201290c *v4;
    Unk020136f0 *v8;
    v7 = func_02047950(func_02088574(v6, a->mUnk_020->mUnk_00));
    v8 = (Unk020136f0 *) func_020478bc((u32) func_02088518(v6, a->mUnk_020->mUnk_00));
    a->mUnk_018 = func_02036bec(b, 0x6c);
    v4 = func_02084b2c(b, a->mUnk_018, v7, v8);
    func_020849c0(a->mUnk_018, 3);
    func_0207a14c(v4, 0);
}

// non-matching: same instructions, but the second table index is kept in r3 and the entries come out in r2/r3/r0/r1
// instead of r1/r2/r3/r0 in the second lookup; 9 words differ, same size
void func_020792c8(Unk0206bcb0_590 *a, s32 b) {
    u8 *c;
    u32 k;
    u32 m;
    u8 *h;
    u8 *p;
    u8 *q;
    u8 *t;
    u8 *e;
    u8 *f;
    u8 *g;
    s32 j;
    s32 i;
    if (a->mUnk_0b0 != 0) {
        if ((u32) (a->mUnk_004 - 0x22) <= 1) {
            c = 0;
            p = (u8 *) a->mUnk_014->mUnk_04;
            switch (a->mUnk_004) {
                case 0x22:
                    c = data_usa_021550e8;
                    break;
                case 0x23:
                    c = data_usa_02155108;
                    break;
            }
            i = func_02013754(p + *(s32 *) (p + 8) + 4, data_usa_02155008);
            q = p + *(s32 *) (p + 8);
            t = q + 4 + *(u16 *) (q + 0xa);
            e = q + *(s32 *) (t + *(u16 *) t * i + 4);
            data_usa_0217acec = e;
            k = *(u16 *) (e + 0x1c) << 4;
            func_0214c48c();
            func_0214c418(c, k, 0x20);
            func_0214c3c0();
        }
        if (a->mUnk_000 == 0xb) {
            p = (u8 *) a->mUnk_010->mUnk_04;
            if (b != 0) {
                i = func_02013754(p + *(s32 *) (p + 8) + 4, data_usa_02155028);
                j = func_02013754(p + *(s32 *) (p + 8) + 4, data_usa_02155038);
                c = data_usa_02155128;
                h = data_usa_02155148;
                m = 0x40;
            } else {
                i = func_02013754(p + *(s32 *) (p + 8) + 4, data_usa_02155058);
                j = func_02013754(p + *(s32 *) (p + 8) + 4, data_usa_02155078);
                c = data_usa_021550c8;
                h = data_usa_02154fe8;
                m = 0x10;
            }
            q = p + *(s32 *) (p + 8);
            t = q + 4 + *(u16 *) (q + 0xa);
            e = q + *(s32 *) (t + *(u16 *) t * j + 4);
            f = q + *(s32 *) (t + *(u16 *) t * i + 4);
            g = (u8 *) (*(u16 *) (f + 0x1c) << 4);
            func_0214c48c();
            func_0214c418(c, (u32) g, 0x20);
            func_0214c3c0();
            g = (u8 *) (*(u16 *) (e + 0x1c) << 4);
            func_0214c48c();
            func_0214c418(h, (u32) g, m);
            func_0214c3c0();
        }
    }
}

void func_0207940c(Unk02084b2c *a, s32 b, void *c) {
    u8 *p;
    u8 *q;
    u8 *t;
    u8 *d;
    s32 i;
    u32 k;
    if (b % 3 == 0) {
        p = (u8 *) a->mUnk_04;
        d = (u8 *) c + b / 3 * 0x20;
        func_0200ee74(d, 0x10);
        i = func_02013754(p + *(s32 *) (p + 8) + 4, data_usa_02155088);
        q = p + *(s32 *) (p + 8);
        t = q + 4 + *(u16 *) (q + 0xa);
        k = *(u16 *) (q + *(s32 *) (t + *(u16 *) t * i + 4) + 0x1c) << 4;
        func_0214c48c();
        func_0214c418(d, k, 0x10);
        func_0214c3c0();
    }
}

u16 *func_02079478(void *a) {
    void *x;
    Unk020b4a44 *p;
    func_0207913c(a, "kart/palette/kart_a.NCLR", &x);
    func_020b4a7c(&p, x);
    return p->mUnk_0c;
}

u16 *func_0207949c(void) {
    Unk020b4a44 *p;
    func_020b4a7c(&p, func_02047950("/kart/palette/kart_a.NCLR"));
    return p->mUnk_0c;
}

void func_020794bc(Unk0206bcb0_590 *a, void *b, s32 c) {
    u16 v7 = (u16) a->mUnk_004;
    void *s;
    Unk020136f0 *t;
    Unk0201290c *r4;
    s32 i;
    s = func_02047950(func_0208867c(v7));
    t = (Unk020136f0 *) func_020478bc((u32) func_020885d0(v7));
    a->mUnk_014 = func_02036bec(b, 0x6c);
    r4 = func_02084b2c(b, a->mUnk_014, s, t);
    func_020849c0(a->mUnk_014, 3);
    func_0207a14c(r4, 0);
    if (c != 0) {
        i = func_02013754((u8 *) r4 + r4->mUnk_08 + 4, data_usa_021550b8);
        func_02013468(r4, i, 0);
        data_0217ad00->mUnk_00c = i;
    }
    func_0207940c(a->mUnk_014, a->mUnk_004, data_0217ad00->mUnk_010);
}

void func_0207954c(Unk0206bcb0_590 *a, void *b, s32 c) {
    u16 i;
    u16 e8;
    s32 d;
    void *v7;
    Unk020136f0 *v10;
    Unk0201290c *p;
    void *s;
    e8 = (u16) a->mUnk_000;
    v7 = func_02047950(func_020887d8(e8, c));
    v10 = (Unk020136f0 *) func_020478bc((u32) func_02088728(e8, c));
    a->mUnk_010 = func_02036bec(b, 0x6c);
    p = func_02084b2c(b, a->mUnk_010, v7, v10);
    func_020849c0(a->mUnk_010, 3);
    func_0207a14c(p, 0);
    if (c != 0) {
        i = 0;
        d = 0;
        a->mUnk_008 = func_02036bec(b, 0x38);
        func_0208823c(0, a->mUnk_008, a->mUnk_010, 4, b, 0);
        do {
            s = func_02047950(func_0207b8f4(e8, i));
            if (s != 0) {
                void *w = func_02013a4c(func_02013a30(s), 0);
                func_020881b0(a->mUnk_008, i, w, func_0207b8dc(i), b);
                if (i == 0) {
                    d = 1;
                }
            }
            i++;
        } while (i < 4);
        if (d != 0) {
            func_02087f84(a->mUnk_008, 0);
            a->mUnk_02c = (func_02087d0c(a->mUnk_008) - 0x1000) / 2;
            a->mUnk_030 = func_02147f34(0x1000, a->mUnk_02c);
        } else {
            a->mUnk_008->mUnk_18 = 0;
        }
    }
    a->mUnk_00c = func_02036bec(b, 0x38);
    func_0208823c(2, a->mUnk_00c, a->mUnk_010, 1, b, 0);
    func_0208805c(a->mUnk_00c, data_0217ad00->mUnk_028, b);
    func_02087f84(a->mUnk_00c, 0);
}

// non-matching: the original spills the loop counter (stack offset 0xc) and keeps the remainder flag in r6; ours does
// the opposite, so it is 0x170 bytes against 0x160
void func_02079678(void *a, s32 b) {
    s32 v6;
    s32 v4;
    Unk0206bcb0_590 *e;
    u16 j;
    s32 f;
    s32 g;
    s32 p;
    s32 q;
    s32 r;
    s32 s;
    u16 i;
    if (b != 0) {
        p = 0;
        q = 7;
        r = p;
        s = 0x15;
    } else {
        p = 7;
        q = 0xd;
        r = 0x15;
        s = 0x25;
    }
    for (i = 0; i < data_0217ad00->mUnk_008; i++) {
        if (b == 0) {
            g = 1;
        } else {
            g = i;
        }
        e = &data_0217ad00->mUnk_000[i];
        v4 = func_020799a0(i);
        if ((u16) e->mUnk_004 % 3 == 0) {
            v6 = 1;
        } else {
            v6 = 0;
        }
        if (v6 != 0 && g != 0) {
            f = 1;
        } else {
            f = 0;
        }
        if (e->mUnk_000 >= p && e->mUnk_000 < q) {
            func_0207954c(e, a, v4);
        }
        if (f == 0) {
            if ((v6 != 0 && b == 0) || (e->mUnk_004 >= r && e->mUnk_004 < s)) {
                func_020794bc(e, a, v4);
            }
        }
        if (b != 0) {
            if (v4 != 0) {
                j = 0;
                e->mUnk_054 = func_02036bec(a, 0x30);
                do {
                    e->mUnk_054->mUnk_v[j].x = e->mUnk_020->mUnk_14[j].x >> 4;
                    e->mUnk_054->mUnk_v[j].y = e->mUnk_020->mUnk_14[j].y >> 4;
                    e->mUnk_054->mUnk_v[j].z = e->mUnk_020->mUnk_14[j].z >> 4;
                    j++;
                } while (j < 4);
                e->mUnk_054->mUnk_v[1].x = func_02147f34(-e->mUnk_054->mUnk_v[0].x * 2, e->mUnk_020->mUnk_10);
                e->mUnk_054->mUnk_v[3].x = -e->mUnk_054->mUnk_v[2].x * 2;
                func_0207926c(e, a);
            }
            func_02079220(e, a);
        }
    }
}

void func_020797d8(void *a, u32 b) {
    u8 *v4;
    u16 i;
    Unk0206bcb0_590 *e;
    Unk0206bcb0_590 *d;
    v4 = (u8 *) func_020478bc((u32) "kartoffsetdata.bin");
    func_02088888(0);
    data_0217ad08 = 0;
    data_0217ad00 = func_02036bec(a, 0x144);
    data_0217ad00->mUnk_000 = func_02036bec(a, b * 0xb4);
    data_0217ad00->mUnk_004 = func_02047950("kartcrsmat.bin");
    data_0217ad00->mUnk_004 = data_0217ad00->mUnk_004 + (data_021759c0->mUnk_00 << 3) - 8;
    data_0217ad00->mUnk_010 = func_0207949c();
    data_0217ad00->mUnk_014 = 0;
    data_0217ad00->mUnk_028 = func_02047950((const char *) func_020883e4());
    data_0217ad00->mUnk_008 = b;
    data_0217ad00->mUnk_00c = 0;
    func_0208af40(a, b);
    func_02085fd8();
    func_0207916c(a);
    for (i = 0; i < data_0217ad00->mUnk_008; i++) {
        d = data_0217ad00->mUnk_000;
        e = &d[i];
        func_02079a3c((u32 *) e);
        e->mUnk_0b0 = data_021759c0->mUnk_68[i].mUnk_08.mUnk_25;
        func_02079a14(e);
        d[i].mUnk_000 = data_021759c0->mUnk_68[i].mUnk_00;
        e->mUnk_004 = data_021759c0->mUnk_68[i].mUnk_04;
        func_02079988((int) e, e->mUnk_004);
        e->mUnk_020 = func_02036bec(a, 0xe0);
        func_0214d1fc(v4 + e->mUnk_004 * 0xe0, e->mUnk_020, 0xe0);
        func_0208aea8(i, (u16) e->mUnk_004, (u16) d[i].mUnk_000);
    }
    func_02079678(a, 1);
    func_0204775c();
    func_02079678(a, 0);
    for (i = 0; i < data_0217ad00->mUnk_008; i++) {
        e = &data_0217ad00->mUnk_000[i];
        func_020792c8(e, func_020799a0(i));
    }
    {
        Unk020b4a44 *p;
        func_020b4a7c(&p, func_02047950("/character/heyho/HH_color.NCLR"));
        data_0217ad00->mUnk_014 = (Unk0217ad00_014 *) p->mUnk_0c;
    }
}

#pragma thumb off

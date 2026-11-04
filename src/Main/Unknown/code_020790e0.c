#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_020790e0.h"
#include "Main/Unknown/code_02056444.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0207a14c.h"
#include "Main/Unknown/code_020638c0.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02088338.h"
#include "Main/Unknown/code_02079988.h"
#include "Main/Unknown/code_02079a3c.h"
#include "Main/Unknown/code_02079a14.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_02085984.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0200eddc.h"
#include "code_02013740.h"
#include "code_02134398.h"
#include "code_02147cd8.h"
#include "code_0214c1bc.h"
#include "code_02133048.h"
#include "code_0214d018.h"
#include "code_02013730.h"

#pragma thumb on

void func_020790e0(void *a, s32 b) {
    if (b != 0) {
        data_0217ad08->mUnk_1e0 = 0;
        data_0217ad08->mUnk_268 = func_02056444(a);
    } else {
        data_0217ad08->mUnk_1e0 = 1;
    }
    data_0217ad08->mUnk_1d0 = LoadKartAPaletteFromKartModelMenu(a);
    data_0217ad08->mUnk_1cc = NULL;
}

void LoadKartModelMenuFile(void *a, const void *b, void **c) {
    char d[0x100];
    snprintf(d, 0x100, "/data/KartModelMenu/%s", b);
    func_02048590(d, (u32) a, c);
}

void CreateKillerItem(void *a) {
    void *v4 = func_02047950("character/common/KillerItem.nsbmd");
    Unk020136f0 *v6 = FindKartModelFile("character/common/KillerItem.nsbtx");
    void *v7 = func_02047950("character/common/KillerItem_s.nsbmd");
    void *v8;
    func_0207a14c(func_02084b2c(a, &gKartModels->mUnk_02c, v4, v6), 0);
    func_020849c0(&gKartModels->mUnk_02c, 3);
    v8 = func_02047950("character/common/KillerItem.nsbca");
    func_0208823c(0, &gKartModels->mUnk_10c, &gKartModels->mUnk_02c, 1, a, v4);
    func_0208805c(&gKartModels->mUnk_10c, v8, a);
    func_02087f84(&gKartModels->mUnk_10c, 0);
    func_0207afa8(&gKartModels->mUnk_098, v7, 3);
    func_020638dc(&gKartModels->mUnk_02c);
}

void CreateKartShadow(Unk0206bcb0_590 *a, void *b) {
    void *v6;
    u8 *p;
    v6 = func_02047950(BuildKartShadowNsbmdPath((u16) a->mUnk_004));
    a->mUnk_01c = HeapAlloc(b, 0x74);
    func_0208526c(&a->mUnk_01c->mUnk_00.mUnk_5c, v6, v6);
    p = (u8 *) func_02013730((u32) v6);
    func_0207b000(&a->mUnk_01c->mUnk_00, p + *(s32 *) (p + *(u16 *) (p + 0xe) + 0xc), 3);
}

void CreateTire(Unk0206bcb0_590 *a, void *b) {
    u16 v6 = (u16) a->mUnk_004;
    void *v7;
    Unk0201290c *v4;
    Unk020136f0 *v8;
    v7 = func_02047950(BuildTireNsbmdPath(v6, a->mUnk_020->mUnk_00));
    v8 = FindKartModelFile(BuildTireNsbtxPath(v6, a->mUnk_020->mUnk_00));
    a->mUnk_010[2] = HeapAlloc(b, 0x6c);
    v4 = func_02084b2c(b, a->mUnk_010[2], v7, v8);
    func_020849c0(a->mUnk_010[2], 3);
    func_0207a14c(v4, 0);
}

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
            c = NULL;
            p = (u8 *) a->mUnk_010[1]->mUnk_04;
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
            p = (u8 *) a->mUnk_010[0]->mUnk_04;
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
            t = q + 4;
            e = q + *(s32 *) ((t = t + *(u16 *) (q + 0xa)) + *(u16 *) t * j + 4);
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

u16 *LoadKartAPaletteFromKartModelMenu(void *a) {
    void *x;
    Nclr *p;
    LoadKartModelMenuFile(a, "kart/palette/kart_a.NCLR", &x);
    LoadNclrData(&p, x);
    return p->mData;
}

u16 *LoadKartAPaletteFromKartModelFile(void) {
    Nclr *p;
    LoadNclrData(&p, func_02047950("/kart/palette/kart_a.NCLR"));
    return p->mData;
}

void CreateKart(Unk0206bcb0_590 *a, void *b, s32 c) {
    u16 v7 = (u16) a->mUnk_004;
    void *s;
    Unk020136f0 *t;
    Unk0201290c *r4;
    s32 i;
    s = func_02047950(BuildKartNsbmdPath(v7));
    t = FindKartModelFile(BuildKartNsbtxPath(v7));
    a->mUnk_010[1] = HeapAlloc(b, 0x6c);
    r4 = func_02084b2c(b, a->mUnk_010[1], s, t);
    func_020849c0(a->mUnk_010[1], 3);
    func_0207a14c(r4, 0);
    if (c != 0) {
        i = func_02013754((u8 *) r4 + r4->mEntriesOffset + 4, data_usa_021550b8);
        func_02013468(r4, i, 0);
        gKartModels->mUnk_00c = i;
    }
    func_0207940c(a->mUnk_010[1], a->mUnk_004, gKartModels->mUnk_010);
}

void CreateCharacter(Unk0206bcb0_590 *a, void *b, s32 c) {
    u16 i;
    u16 e8;
    BOOL d;
    void *v7;
    Unk020136f0 *v10;
    Unk0201290c *p;
    void *s;
    e8 = (u16) a->mUnk_000;
    v7 = func_02047950(BuildCharacterNsbmdPath(e8, c));
    v10 = FindKartModelFile(BuildCharacterNsbtxPath(e8, c));
    a->mUnk_010[0] = HeapAlloc(b, 0x6c);
    p = func_02084b2c(b, a->mUnk_010[0], v7, v10);
    func_020849c0(a->mUnk_010[0], 3);
    func_0207a14c(p, 0);
    if (c != 0) {
        i = 0;
        d = FALSE;
        a->mUnk_008 = HeapAlloc(b, 0x38);
        func_0208823c(0, a->mUnk_008, a->mUnk_010[0], 4, b, NULL);
        do {
            s = func_02047950(BuildCharacterNsbcaPath(e8, i));
            if (s != NULL) {
                void *w = func_02013a4c(func_02013a30(s), 0);
                func_020881b0(a->mUnk_008, i, w, func_0207b8dc(i), b);
                if (i == 0) {
                    d = TRUE;
                }
            }
            i++;
        } while (i < 4);
        if (d != FALSE) {
            func_02087f84(a->mUnk_008, 0);
            a->mUnk_02c = (func_02087d0c(a->mUnk_008) - 0x1000) / 2;
            a->mUnk_030 = DivFixed12(0x1000, a->mUnk_02c);
        } else {
            a->mUnk_008->mUnk_18 = 0;
        }
    }
    a->mUnk_00c = HeapAlloc(b, 0x38);
    func_0208823c(2, a->mUnk_00c, a->mUnk_010[0], 1, b, NULL);
    func_0208805c(a->mUnk_00c, gKartModels->mUnk_028, b);
    func_02087f84(a->mUnk_00c, 0);
}

void func_02079678(void *a, s32 b) {
    BOOL v6;
    Unk0206bcb0_590 *e;
    s32 v4;
    u16 j;
    BOOL f;
    s32 g;
    u16 i;
    s32 p;
    s32 q;
    s32 r;
    s32 s;
    Vec3 *dst;
    Vec3 *src;
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
    i = 0;
    if (i < gKartModels->mUnk_008) {
        g = (b == 0) ? 1 : i;
        do {
            e = &gKartModels->mUnk_000[i];
            v4 = func_020799a0(i);
            if ((u16) e->mUnk_004 % 3 == 0) {
                v6 = TRUE;
            } else {
                v6 = FALSE;
            }
            f = (v6 != FALSE && g != 0) ? TRUE : FALSE;
            if (e->mUnk_000 >= p && e->mUnk_000 < q) {
                CreateCharacter(e, a, v4);
            }
            if (f == FALSE) {
                if ((v6 != FALSE && b != 0) || (e->mUnk_004 >= r && e->mUnk_004 < s)) {
                    CreateKart(e, a, v4);
                }
            }
            if (b != 0) {
                if (v4 != 0) {
                    j = 0;
                    e->mUnk_054 = HeapAlloc(a, 0x30);
                    do {
                        dst = &e->mUnk_054->mUnk_v[j];
                        src = &e->mUnk_020->mUnk_14[j];
                        dst->x = src->x >> 4;
                        dst->y = src->y >> 4;
                        dst->z = src->z >> 4;
                        j++;
                    } while (j < 4);
                    e->mUnk_054->mUnk_v[1].x = DivFixed12(-e->mUnk_054->mUnk_v[0].x * 2, e->mUnk_020->mUnk_10);
                    e->mUnk_054->mUnk_v[3].x = -e->mUnk_054->mUnk_v[2].x * 2;
                    CreateTire(e, a);
                }
                CreateKartShadow(e, a);
            }
            i++;
        } while (i < gKartModels->mUnk_008);
    }
}

void InitKartModels(void *a, u32 b) {
    u8 *v4;
    u16 i;
    Unk0206bcb0_590 *e;
    Unk0206bcb0_590 *d;
    v4 = (u8 *) FindKartModelFile("kartoffsetdata.bin");
    SetKartModelPathPrefix(0);
    data_0217ad08 = NULL;
    gKartModels = HeapAlloc(a, 0x144);
    gKartModels->mUnk_000 = HeapAlloc(a, b * 0xb4);
    gKartModels->mUnk_004 = func_02047950("kartcrsmat.bin");
    gKartModels->mUnk_004 = gKartModels->mUnk_004 + (data_021759c0->mCourseId << 3) - 8;
    gKartModels->mUnk_010 = LoadKartAPaletteFromKartModelFile();
    gKartModels->mUnk_014 = NULL;
    gKartModels->mUnk_028 = func_02047950((const char *) BuildPFaceanimNsbtpPath());
    gKartModels->mUnk_008 = b;
    gKartModels->mUnk_00c = 0;
    func_0208af40(a, b);
    func_02085fd8();
    CreateKillerItem(a);
    for (i = 0; i < gKartModels->mUnk_008; i++) {
        d = gKartModels->mUnk_000;
        e = &d[i];
        func_02079a3c((u32 *) e);
        e->mUnk_0b0 = data_021759c0->mUnk_68[i].mUnk_08.mUnk_25;
        func_02079a14(e);
        d[i].mUnk_000 = data_021759c0->mUnk_68[i].mCharacterIndex;
        e->mUnk_004 = data_021759c0->mUnk_68[i].mKartIndex;
        func_02079988((s32) e, e->mUnk_004);
        e->mUnk_020 = HeapAlloc(a, 0xe0);
        MemCopy(v4 + e->mUnk_004 * 0xe0, e->mUnk_020, 0xe0);
        func_0208aea8(i, (u16) e->mUnk_004, (u16) d[i].mUnk_000);
    }
    func_02079678(a, 1);
    func_0204775c();
    func_02079678(a, 0);
    for (i = 0; i < gKartModels->mUnk_008; i++) {
        e = &gKartModels->mUnk_000[i];
        func_020792c8(e, func_020799a0(i));
    }
    {
        Nclr *p;
        LoadNclrData(&p, func_02047950("/character/heyho/HH_color.NCLR"));
        gKartModels->mUnk_014 = (Unk0217ad00_014 *) p->mData;
    }
}

#pragma thumb off

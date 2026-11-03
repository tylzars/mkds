#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_02016468.h"

u32 func_0202578c(u32 a) {
    u32 r = 3;
    switch (a) {
        case 0:
        case 3:
        case 6:
        case 9:
        case 12:
        case 15:
        case 18:
        case 21:
        case 24:
        case 27:
        case 30:
        case 33:
        case 36:
            r = 0;
            break;
        case 2:
        case 8:
        case 13:
        case 14:
        case 20:
        case 23:
        case 25:
        case 28:
        case 31:
            r = 0;
            break;
        case 1:
        case 7:
        case 19:
        case 22:
        case 26:
        case 29:
        case 32:
        case 34:
        case 35:
            r = 1;
            break;
        case 4:
        case 5:
        case 10:
        case 11:
        case 16:
        case 17:
            r = 2;
            break;
    }
    return r;
}

#pragma thumb on

void func_02025854(u32 a, void *b, const char *c, const char *d, const char *e, s32 f, void *(*g)(const char *) ) {
    func_02025884(b, c, d, e, f, g);
    func_02025954(a, b, f);
}

void func_02025884(void *a, const char *b, const char *c, const char *d, s32 e, void *(*f)(const char *) ) {
    Unk02174e60_00 *p = a;
    if (b) {
        LoadNcgrData(&p->mUnk_00[e], f(b));
    }
    if (c) {
        LoadNclrData(&p->mUnk_10, f(c));
    }
    if (d) {
        LoadNscrData(&p->mUnk_14[e], f(d));
    }
}

void func_020258d4(u32 a, void *b, const char *c, const char *d, const char *e, s32 f, void *(*g)(const char *) ) {
    func_02025904(b, c, d, e, f, g);
    func_02025954(a, b, f);
}

void func_02025904(void *a, const char *b, const char *c, const char *d, s32 e, void *(*f)(const char *) ) {
    Unk02174e60_00 *p = a;
    if (b) {
        LocateNcgr(&p->mUnk_00[e], f(b));
    }
    if (c) {
        LocateNclr(&p->mUnk_10, f(c));
    }
    if (d) {
        LocateNscr(&p->mUnk_14[e], f(d));
    }
}

void func_02025954(u32 a, void *b, u32 c) {
    Unk02174e60_00 *p = b;
    u32 r0;
    u32 r5;
    u32 r7;
    if (a == 0) {
        r7 = 0xf;
        switch (c) {
            case 0:
                r0 = 4;
                r5 = 8;
                break;
            case 1:
                r0 = 5;
                r5 = 9;
                break;
            case 2:
                r0 = 6;
                r5 = 10;
                break;
            case 3:
                r0 = 7;
                r5 = 11;
                break;
        }
    } else {
        r7 = 0x1f;
        switch (c) {
            case 0:
                r0 = 0x14;
                r5 = 0x18;
                break;
            case 1:
                r0 = 0x15;
                r5 = 0x19;
                break;
            case 2:
                r0 = 0x16;
                r5 = 0x1a;
                break;
            case 3:
                r0 = 0x17;
                r5 = 0x1b;
                break;
        }
    }
    func_02016468(r0, 0, p->mUnk_00[c]->mUnk_14, p->mUnk_00[c]->mUnk_10);
    func_02016468(r7, 0, p->mUnk_10->mUnk_0c, 0x140);
    func_02016468(r5, 0, &p->mUnk_14[c]->mUnk_0c, p->mUnk_14[c]->mUnk_08);
}

s32 func_02025a00(u32 a, void *b, void *c, void *d, s32 e) {
    Unk02153918 *q = d;
    Unk02174e14_00 *p = c;
    s32 r;
    r = func_021243ac(b, q->mUnk_00, p->mUnk_14, q->mUnk_02, q->mUnk_04, q->mUnk_06, p->mUnk_08, p->mUnk_0c, p->mUnk_18,
                      e);
    func_021241c0(a, q->mUnk_00, p->mUnk_14, p->mUnk_0c, p->mUnk_18);
    return r;
}

void func_02025a50(u32 a, void *b, void *c) {
    Unk02174e14_00 *p = c;
    u32 r;
    func_02124ed0(b, p->mUnk_0c, p->mUnk_14, &p->mUnk_18);
    if (a == 0) {
        r = 0x13;
        func_02016468(0xe, 0, ((Unk020b4a44 *) p->mUnk_04)->mUnk_0c, 0x1a0);
        func_02016468(0xe, 0x1c0, (u8 *) ((Unk020b4a44 *) p->mUnk_04)->mUnk_0c + 0x1c0, 0x40);
    } else {
        r = 0x23;
        func_02016468(0x1e, 0, ((Unk020b4a44 *) p->mUnk_04)->mUnk_0c, ((Unk020b4a44 *) p->mUnk_04)->mUnk_08);
    }
    func_02016468(r, 0, ((Unk020b4934 *) p->mUnk_00)->mUnk_14, ((Unk020b4934 *) p->mUnk_00)->mUnk_10);
}

void func_02025abc(void *a, const char *b, const char *c, const char *d, const char *e, const char *f, const char *g,
                   void *(*h)(const char *) ) {
    Unk02174e14_00 *p = a;
    if (b) {
        LoadNcgrData2((Unk020b4934 **) &p->mUnk_00, h(b));
    }
    if (c) {
        LoadNcerData((Unk02021dc8 **) &p->mUnk_08, h(c));
    }
    if (d) {
        LoadNclrData((Unk020b4a44 **) &p->mUnk_04, h(d));
    }
    if (e) {
        p->mUnk_0c = h(e);
    }
    if (f) {
        p->mUnk_14 = h(f);
    }
    if (g) {
        p->mUnk_10 = h(g);
    }
}

void func_02025b20(void *a, const char *b, const char *c, const char *d, const char *e, const char *f, const char *g,
                   void *(*h)(const char *) ) {
    Unk02174e14_00 *p = a;
    if (b) {
        LocateNcgr2((Unk020b4934 **) &p->mUnk_00, h(b));
    }
    if (c) {
        LocateNcer((Unk02021dc8 **) &p->mUnk_08, h(c));
    }
    if (d) {
        LocateNclr((Unk020b4a44 **) &p->mUnk_04, h(d));
    }
    if (e) {
        p->mUnk_0c = h(e);
    }
    if (f) {
        p->mUnk_14 = h(f);
    }
    if (g) {
        p->mUnk_10 = h(g);
    }
}

#pragma thumb off

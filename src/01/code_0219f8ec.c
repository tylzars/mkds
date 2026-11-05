#include "01/code_0219f8ec.h"

#include "code_0200eddc.h"
#include "code_0201ea58.h"
#include "types.h"
#include "01/unk_021ca000.h"
#include "01/unk_021a6000.h"
#include "01/code_021a6430.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02105550.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_021055b0.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "01/code_021a0000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_02116000.h"
#include "Main/Unknown/code_0203b680.h"
#include "code_0212df7c.h"
#include "code_02148950.h"
#include "registers.h"
#include "Main/Unknown/code_0205f000.h"
#include "01/code_021a1000.h"
#include "01/code_021a11a4.h"
#include "01/code_021a2034.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02047104.h"

MissionRunMSsel *gMissionRunMSsel;

void func_ov001_021a10b8(void) {
    Ncgr *a = NULL;
    Unk02021dc8 *b = NULL;
    Nclr *c = NULL;
    Ncgr *d = NULL;
    Unk02021dc8 *e = NULL;
    Nclr *f = NULL;
    Ncgr *g = NULL;
    Nscr *h = NULL;
    Nscr *i = NULL;
    Nclr *j = NULL;

    LoadNcgrData(&g, FindSceneFile(data_ov001_021a92bc));
    LoadNclrData(&j, FindSceneFile(data_ov001_021a92a8));
    LoadNscrData(&h, FindSceneFile(data_ov001_021a928c));
    LoadNscrData(&i, FindSceneFile(data_ov001_021a92c0));
    LoadNcgrData2(&a, FindSceneFile(data_ov001_021a9278));
    LoadNcerData(&b, FindSceneFile(data_ov001_021a92c4));
    LoadNclrData(&c, FindSceneFile(data_ov001_021a9298));
    LoadNcgrData2(&d, FindSceneFile(data_ov001_021a92b0));
    LoadNcerData(&e, FindSceneFile(data_ov001_021a9284));
    LoadNclrData(&f, FindSceneFile(data_ov001_021a927c));
    func_ov001_021a651c();
}

void LocateAndQueueMissionRunMSsel(void) {
    Ncgr *a = NULL;
    Nclr *b = NULL;
    Ncgr *c = NULL;
    Ncgr *d = NULL;
    Nscr *e = NULL;
    Nscr *f = NULL;
    Nclr *g = NULL;
    u16 *p;

    LocateNcgr(&d, FindSceneFile(data_ov001_021a92bc));
    LocateNclr(&g, FindSceneFile(data_ov001_021a92a8));
    LocateNscr(&e, FindSceneFile(data_ov001_021a928c));
    LocateNscr(&f, FindSceneFile(data_ov001_021a92c0));
    gMissionRunMSsel->mUnk_48 = HeapAlloc(gMissionRunMSsel->mHeap, 0x800);
    gMissionRunMSsel->mMissionRunMSselMBncl = FindSceneFile(data_ov001_021a929c);
    gMissionRunMSsel->mMissionRunMSselMBnll = FindSceneFile(data_ov001_021a92ac);
    LocateNcgr2(&a, FindSceneFile(data_ov001_021a9278));
    LocateNcer(&gMissionRunMSsel->mMissionRunMSselMNcer, FindSceneFile(data_ov001_021a92c4));
    LocateNclr(&b, FindSceneFile(data_ov001_021a9298));
    gMissionRunMSsel->mMissionRunMSselSBncl = FindSceneFile(data_ov001_021a92a4);
    gMissionRunMSsel->mMissionRunMSselSBnbl = FindSceneFile(data_ov001_021a92a0);
    gMissionRunMSsel->mMissionRunMSselSBnll = FindSceneFile(data_ov001_021a9280);
    LocateNcgr2(&c, FindSceneFile(data_ov001_021a92b0));
    LocateNcer(&gMissionRunMSsel->mMissionRunMSselSNcer, FindSceneFile(data_ov001_021a9284));
    LocateNclr((Nclr **) &gMissionRunMSsel->mUnk_1c, FindSceneFile(data_ov001_021a927c));
    p = b->mData;
    CallQueueAppend(4, 0, d->mData, d->mDataSize);
    CallQueueAppend(0xf, 0, g->mData, 0x40);
    CallQueueAppend(8, 0, e->mData, e->mDataSize);
    CallQueueAppend(8, 0x800, gMissionRunMSsel->mUnk_48, 0x800);
    CallQueueAppend(8, 0x1000, gMissionRunMSsel->mUnk_48, 0x800);
    CallQueueAppend(8, 0x1800, gMissionRunMSsel->mUnk_48, 0x800);
    CallQueueAppend(9, 0, f->mData, f->mDataSize);
    CallQueueAppend(9, 0x800, gMissionRunMSsel->mUnk_48, 0x800);
    CallQueueAppend(0x13, 0, a->mData, a->mDataSize);
    CallQueueAppend(0xe, 0, b->mData, 0x1a0);
    CallQueueAppend(0xe, 0x1c0, p + 0xe0, 0x40);
    CallQueueAppend(0x23, 0, c->mData, c->mDataSize);
    CallQueueAppend(0x1e, 0, gMissionRunMSsel->mUnk_1c->mUnk_0c, gMissionRunMSsel->mUnk_1c->mUnk_08);
}

void func_ov001_021a0e34(void) {
    s32 out;
    s32 i;

    gMissionRunMSsel->mUnk_a0 = 1;
    for (i = 0; i < 8; i++) {
        gMissionRunMSsel->mUnk_a0 &= func_0205fd78((u8) func_02029608(), (u8) (i + 1), &out);
    }
}

void func_ov001_021a0e08(s32 a, u16 *b) {
    func_02124fac(func_02029608(), b);
    b[1] = 0x2d;
    func_02124fac(a + 1, b + 2);
    b[3] = 0;
}

void func_ov001_021a0b3c(void) {
    u16 cnt10;
    s32 i;
    u16 cnt04;
    s32 j;
    s32 out;
    u16 buf[18];
    cnt04 = gMissionRunMSsel->mMissionRunMSselMBncl->mUnk_06;
    cnt10 = gMissionRunMSsel->mMissionRunMSselSBncl->mUnk_06;
    for (i = 0; i < 9; i++) {
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6dd4[i]].mUnk_00 = 0;
        for (j = 0; j < 9; j++) {
            gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][j]].mUnk_00 = 0;
        }
        for (j = 0; j < 2; j++) {
            gMissionRunMSsel->mMissionRunMSselSTable[cnt10 + data_ov001_021a6e10[i][j]].mUnk_00 = 0;
        }
    }
    for (j = 0; j < 7; j++) {
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6d88[j]].mUnk_00 = 0;
    }
    gMissionRunMSsel->mMissionRunMSselMTable[cnt04].mUnk_00 = 1;
    for (i = 0; i < 9; i++) {
        if (i == 8) {
            if (gMissionRunMSsel->mUnk_a0 != 0) {
                gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][1]].mUnk_00 = 1;
                func_ov001_021a6430((s32) ((s16) (func_02029608() - 1)), 1,
                                    (void *) gMissionRunMSsel->mMissionRunMSselSNcer,
                                    (void *) gMissionRunMSsel->mMissionRunMSselSBncl, (u32) (0x2d), (u16) (8), 1);
            } else {
                gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][4]].mUnk_00 = 1;
                func_ov001_021a6430((s32) ((s16) (func_02029608() - 1)), 0,
                                    (void *) gMissionRunMSsel->mMissionRunMSselSNcer,
                                    (void *) gMissionRunMSsel->mMissionRunMSselSBncl, (u32) (0x2d), (u16) (8), 1);
            }
        } else {
            gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][1]].mUnk_00 = 1;
        }
        gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][0]].mUnk_00 = 1;
        gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][2]].mUnk_00 = 0;
        gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][3]].mUnk_00 = 0;
        if (func_0205fd78((u8) func_02029608(), (u8) (i + 1), &out)) {
            if (out <= 4) {
                gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][5]].mUnk_00 = 1;
                gMissionRunMSsel->mMissionRunMSselSTable[cnt10 + data_ov001_021a6e10[i][0]].mUnk_00 = 1;
                func_0212426c(1, data_ov001_021a6e10[i][0], gMissionRunMSsel->mMissionRunMSselSBnll,
                              data_ov001_021a92c8[out], gMissionRunMSsel->mMissionRunMSselSBncl,
                              gMissionRunMSsel->mMissionRunMSselSTable);
            } else if (out <= 7) {
                gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][out + 1]].mUnk_00 = 1;
            }
            if (i == 8) {
                gMissionRunMSsel->mUnk_a4 = TRUE;
            }
        }
        func_021057f0(0, func_02029608());
        if (i == 8) {
            func_02124a20(data_ov001_021a6e7c[i][2], 2, gMissionRunMSsel->mMissionRunMSselSNcer,
                          gMissionRunMSsel->mMissionRunMSselSBncl);
            func_02124a20(data_ov001_021a6e7c[i][1], 5, gMissionRunMSsel->mMissionRunMSselSNcer,
                          gMissionRunMSsel->mMissionRunMSselSBncl);
            if (gMissionRunMSsel->mUnk_a0 != 0) {
                if (func_020cccb4() == 0x12) {
                    gMissionRunMSsel->mIndex = 8;
                }
                if (gMissionRunMSsel->mUnk_a4 == FALSE) {
                    gMissionRunMSsel->mIndex = 8;
                    func_02124a20(data_ov001_021a6e7c[i][2], 0xb, gMissionRunMSsel->mMissionRunMSselSNcer,
                                  gMissionRunMSsel->mMissionRunMSselSBncl);
                    func_02124a20(data_ov001_021a6e7c[i][1], 0xe, gMissionRunMSsel->mMissionRunMSselSNcer,
                                  gMissionRunMSsel->mMissionRunMSselSBncl);
                    func_021057f0(3, func_02029608());
                }
            }
        }
        gMissionRunMSsel->mMissionRunMSselSTable[cnt10 + data_ov001_021a6e10[i][1]].mUnk_00 = 1;
        func_ov001_021a0e08((s32) ((s16) i), (u16 *) buf);
        func_0212426c(1, data_ov001_021a6e10[i][1], gMissionRunMSsel->mMissionRunMSselSBnll, buf,
                      gMissionRunMSsel->mMissionRunMSselSBncl, gMissionRunMSsel->mMissionRunMSselSTable);
        func_02124a98(data_ov001_021a6e7c[i][0], 1, gMissionRunMSsel->mMissionRunMSselSNcer,
                      gMissionRunMSsel->mMissionRunMSselSBncl);
    }
    gMissionRunMSsel->mMissionRunMSselSTable[45].mUnk_00 = 1;
}

void func_ov001_021a09a4(void) {
    s32 k;
    s32 ra;
    s32 ga;
    s32 ba;
    s32 rb;
    s32 gb;
    s32 bb;
    s32 c0;
    s32 c1;
    s32 c2;
    volatile u16 zero;
    u8 *pal;
    s32 col0;
    s32 col1;
    s32 cnt;
    s32 t;
    s32 d;
    s32 r;
    s32 g;
    s32 bl;

    if (gMissionRunMSsel->mUnk_a0 != 0) {
        if (gMissionRunMSsel->mUnk_a4 == FALSE) {
            gMissionRunMSsel->mUnk_a8 = gMissionRunMSsel->mUnk_a8 + 1;
            if (gMissionRunMSsel->mUnk_a8 >= 100) {
                gMissionRunMSsel->mUnk_a8 = 0;
            }
            if (gMissionRunMSsel->mIndex == 8) {
                c0 = 9;
                c1 = 10;
                c2 = 11;
            } else {
                c0 = 12;
                c1 = 13;
                c2 = 14;
            }
            zero = 0;
            MemFillHalfwords(zero, gMissionRunMSsel->mUnk_20, 0x20);
            pal = gMissionRunMSsel->mUnk_1c->mUnk_0c;
            for (k = 0; k < 16; k++) {
                col0 = ((u16 *) (pal + c0 * 32))[k];
                col1 = ((u16 *) (pal + c1 * 32))[k];
                ra = col0 & 0x1f;
                ga = (col0 & 0x3e0) >> 5;
                ba = (col0 & 0x7c00) >> 10;
                rb = col1 & 0x1f;
                gb = (col1 & 0x3e0) >> 5;
                bb = (col1 & 0x7c00) >> 10;
                cnt = gMissionRunMSsel->mUnk_a8;
                if (cnt < 50) {
                    r = ra + cnt * (rb - ra) * 2 / 100;
                    g = ga + cnt * (gb - ga) * 2 / 100;
                    bl = ba + cnt * (bb - ba) * 2 / 100;
                } else {
                    t = cnt - 50;
                    d = ra - rb;
                    r = rb + d * t * 2 / 100;
                    d = ga - gb;
                    g = gb + d * t * 2 / 100;
                    d = ba - bb;
                    bl = bb + d * t * 2 / 100;
                }
                gMissionRunMSsel->mUnk_20[k] = r | ((bl << 10) | (g << 5));
            }
            func_0200ee74(gMissionRunMSsel->mUnk_20, 0x20);
            CallQueueAppend(0x1e, c2 << 5, gMissionRunMSsel->mUnk_20, 0x20);
        }
    }
}

void func_ov001_021a08d8(void) {
    s32 i;
    s32 cnt;
    s16 n;
    for (i = 0; i < 9; i++) {
        gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][1]].mUnk_00 = 0;
        gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][2]].mUnk_00 = 0;
        gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][3]].mUnk_00 = 0;
        gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][4]].mUnk_00 = 0;
        cnt = gMissionRunMSsel->mUnk_6c[i];
        if (cnt > 0) {
            gMissionRunMSsel->mUnk_6c[i] = cnt - 1;
            gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][3]].mUnk_00 = 1;
            n = gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][2]].mUnk_06 + 1;
            gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][3]].mUnk_06 = n;
        } else if (gMissionRunMSsel->mIndex == i) {
            gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][2]].mUnk_00 = 1;
        } else if (i == 8) {
            if (gMissionRunMSsel->mUnk_a0) {
                gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][1]].mUnk_00 = 1;
            } else {
                gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][4]].mUnk_00 = 1;
            }
        } else {
            gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][1]].mUnk_00 = 1;
        }
    }
}

void func_ov001_021a0774(void) {
    MissionRunMSsel *d;
    s32 i;
    s32 out;
    s32 ret;
    gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6d88[func_02029608() - 1]].mUnk_00 = 0;
    gMissionRunMSsel->mMissionRunMSselMTable[9].mUnk_00 = 0;
    for (i = 0; i < 9; i++) {
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6dd4[i]].mUnk_00 = 0;
    }
    if (gMissionRunMSsel->mIndex == 8) {
        gMissionRunMSsel->mMissionRunMSselMTable[0].mUnk_00 = 0;
        gMissionRunMSsel->mMissionRunMSselMTable[1].mUnk_00 = 1;
    } else {
        gMissionRunMSsel->mMissionRunMSselMTable[0].mUnk_00 = 1;
        gMissionRunMSsel->mMissionRunMSselMTable[1].mUnk_00 = 0;
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6d88[func_02029608() - 1]].mUnk_00 = 1;
        gMissionRunMSsel->mMissionRunMSselMTable[9].mUnk_00 = 1;
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6dd4[gMissionRunMSsel->mIndex]].mUnk_00 = 1;
    }
    ret = func_0205fd78((u8) func_02029608(), (u8) (gMissionRunMSsel->mIndex + 1), &out);
    gMissionRunMSsel->mMissionRunMSselMTable[18].mUnk_00 = 0;
    for (i = 0; i < 6; i++) {
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6d7c[i]].mUnk_00 = 0;
    }
    if (ret != 0 && out <= 7) {
        if (out <= 4) {
            gMissionRunMSsel->mMissionRunMSselMTable[18].mUnk_00 = 1;
        }
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6d7c[out - 2]].mUnk_00 = 1;
    }
    d = gMissionRunMSsel;
    func_0212426c(
        0, 0, gMissionRunMSsel->mMissionRunMSselMBnll,
        GetBmgEntry(d->mMissionMessages, d->mUnk_50[func_0203b680((u32) (gMissionRunMSsel->mMissionTableMtbl),
                                                                  (u32) (func_02029608()), (u32) (d->mIndex + 1)) -
                                                    1]
                                             .mUnk_0c),
        d->mMissionRunMSselMBncl, d->mMissionRunMSselMTable);
}

void func_ov001_021a0734(void) {
    u32 v0;
    u32 v1;

    func_0202947c((s8) (gMissionRunMSsel->mIndex + 1));
    v0 = func_02029608();
    v1 = func_020295f8();
    func_02029468((u32) ((u16) (func_0203b680((u32) (gMissionRunMSsel->mMissionTableMtbl), v0, v1) - 1)));
}

BOOL func_ov001_021a071c(void) {
    if (gMissionRunMSsel->mUnk_ac != 0) {
        return TRUE;
    }
    return FALSE;
}

void func_ov001_021a0620(void) {
    u16 b;
    s16 v;
    s32 i;

    if (func_ov001_021a071c() != FALSE) {
        if (gMissionRunMSsel->mUnk_ac == 7) {
            gMissionRunMSsel->mUnk_b0 = gMissionRunMSsel->mIndex;
            func_ov001_021a0774();
        } else {
            b = gMissionRunMSsel->mMissionRunMSselMBncl->mUnk_06;
            v = func_02116d10(7 - gMissionRunMSsel->mUnk_ac, 1);
            gMissionRunMSsel->mBg0OffsetY = v;
            gMissionRunMSsel->mMissionRunMSselMTable[0].mUnk_06 = v;
            gMissionRunMSsel->mMissionRunMSselMTable[1].mUnk_06 = v;
            gMissionRunMSsel->mMissionRunMSselMTable[9].mUnk_06 = v;
            gMissionRunMSsel->mMissionRunMSselMTable[18].mUnk_06 = v;
            for (i = 0; i < 7; i++) {
                gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6d88[i]].mUnk_06 = v;
            }
            for (i = 0; i < 6; i++) {
                gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6d7c[i]].mUnk_06 = v;
            }
            gMissionRunMSsel->mMissionRunMSselMTable[b].mUnk_06 = v;
            for (i = 0; i < 9; i++) {
                gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6dd4[i]].mUnk_06 = v;
            }
        }
        gMissionRunMSsel->mUnk_ac = gMissionRunMSsel->mUnk_ac - 1;
    } else if (gMissionRunMSsel->mIndex != gMissionRunMSsel->mUnk_b0) {
        gMissionRunMSsel->mUnk_ac = 7;
    }
}

void func_ov001_021a04f0(void) {
    s32 i;
    s32 j;
    u16 a;
    u16 b;

    a = gMissionRunMSsel->mMissionRunMSselMBncl->mUnk_06;
    b = gMissionRunMSsel->mMissionRunMSselSBncl->mUnk_06;
    gMissionRunMSsel->mNextState = 0;
    gMissionRunMSsel->mStateFrames = 0;
    gMissionRunMSsel->mBg0OffsetX = 0x100;
    gMissionRunMSsel->mBg0OffsetY = 0;
    gMissionRunMSsel->mBg1Offset = -192;
    gMissionRunMSsel->mMissionRunMSselMTable[0].mUnk_04 = 0x100;
    gMissionRunMSsel->mMissionRunMSselMTable[1].mUnk_04 = 0x100;
    gMissionRunMSsel->mMissionRunMSselMTable[9].mUnk_04 = 0x100;
    gMissionRunMSsel->mMissionRunMSselMTable[18].mUnk_04 = 0x100;
    for (i = 0; i < 7; i++) {
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6d88[i]].mUnk_04 = 0x100;
    }
    gMissionRunMSsel->mMissionRunMSselSTable[45].mUnk_04 = 0x100;
    for (i = 0; i < 6; i++) {
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6d7c[i]].mUnk_04 = 0x100;
    }
    gMissionRunMSsel->mMissionRunMSselMTable[a].mUnk_04 = 0x100;
    for (i = 0; i < 9; i++) {
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6dd4[i]].mUnk_04 = 0x100;
        for (j = 0; j < 9; j++) {
            gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][j]].mUnk_04 = 0x100;
        }
        for (j = 0; j < 2; j++) {
            gMissionRunMSsel->mMissionRunMSselSTable[b + data_ov001_021a6e10[i][j]].mUnk_04 = 0x100;
        }
    }
}

// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next AdvanceMissionRunMSsel call copies it to
// mState and runs AdvanceMissionRunMSselState1.
void RequestMissionRunMSselState1(void) {
    gMissionRunMSsel->mNextState = 1;
    gMissionRunMSsel->mStateFrames = 0;
}

void func_ov001_021a04c0(void) {
    gMissionRunMSsel->mNextState = 2;
    gMissionRunMSsel->mStateFrames = 0;
    func_02128374();
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceMissionRunMSsel call copies it to
// mState and runs AdvanceMissionRunMSselState3.
void RequestMissionRunMSselState3(void) {
    gMissionRunMSsel->mNextState = 3;
    gMissionRunMSsel->mStateFrames = 0;
}

s32 func_ov001_021a0488(void) {
    gMissionRunMSsel->mNextState = 4;
    gMissionRunMSsel->mStateFrames = 0;
    return func_0212ecc0(&data_0217d068, 0, 5);
}

void func_ov001_021a0428(void) {
    s32 i;
    void *v0;

    gMissionRunMSsel->mNextState = 5;
    gMissionRunMSsel->mStateFrames = 0;
    v0 = GetBmgEntry(gMissionRunMSsel->mCommonMessages, 4);
    func_021277f8(v0, GetBmgEntry(gMissionRunMSsel->mCommonMessages, 2), 0);
    for (i = 0; i < 9; i++) {
        gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][0]].mUnk_00 = 0;
    }
}

// Requests state 6: stores mNextState = 6 and zeroes mStateFrames; the next AdvanceMissionRunMSsel call copies it to
// mState and runs AdvanceMissionRunMSselState6.
void RequestMissionRunMSselState6(void) {
    gMissionRunMSsel->mNextState = 6;
    gMissionRunMSsel->mStateFrames = 0;
}

void func_ov001_021a03f8(void) {
    gMissionRunMSsel->mNextState = 7;
    gMissionRunMSsel->mStateFrames = 0;
    func_021277e4();
}

void func_ov001_021a03a0(void) {
    gMissionRunMSsel->mNextState = 8;
    gMissionRunMSsel->mStateFrames = 0;
    func_021282c8();
    switch (gMissionRunMSsel->mResult) {
        case 1:
            func_02105584(4, 10, func_02029608());
            break;
        case 2:
            func_02105584(0, 10, func_02029608());
            break;
    }
}

void InitMissionRunMSsel(void *a, void *b, void *c) {
    s32 i;
    void *heap;
    s32 rem;
    u16 base;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0xd204;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x9004;
    heap = CreateFrmHeapFromMaxFree(a);
    gMissionRunMSsel = HeapAlloc(heap, 0xc0);
    gMissionRunMSsel->mHeap = heap;
    gMissionRunMSsel->mState = 0;
    gMissionRunMSsel->mIndex = func_020295f8() - 1;
    gMissionRunMSsel->mUnk_9c = 0;
    gMissionRunMSsel->mUnk_ac = 0;
    gMissionRunMSsel->mUnk_a4 = FALSE;
    gMissionRunMSsel->mUnk_b4 = b;
    gMissionRunMSsel->mUnk_b8 = c;
    gMissionRunMSsel->mResult = 0;
    for (i = 0; i < 9; i++) {
        gMissionRunMSsel->mUnk_6c[i] = 0;
    }
    func_ov001_021a0e34();
    LocateAndQueueMissionRunMSsel();
    func_020ae6d4(gMissionRunMSsel->mUnk_b4, gMissionRunMSsel->mUnk_b8);
    func_02124ed0(gMissionRunMSsel->mHeap, gMissionRunMSsel->mMissionRunMSselMBncl,
                  gMissionRunMSsel->mMissionRunMSselMBnll, &gMissionRunMSsel->mMissionRunMSselMTable);
    func_02124ed0(gMissionRunMSsel->mHeap, gMissionRunMSsel->mMissionRunMSselSBncl,
                  gMissionRunMSsel->mMissionRunMSselSBnll, &gMissionRunMSsel->mMissionRunMSselSTable);
    gMissionRunMSsel->mCommonMessages = func_02047a28(data_ov001_021a94a4);
    gMissionRunMSsel->mMissionMessages = FindSceneFile(data_ov001_021a94b0);
    gMissionRunMSsel->mMissionTableMtbl = func_02047a28(data_ov001_021a94bc);
    gMissionRunMSsel->mUnk_50 = (Unk021ca414_50 *) ((u8 *) FindSceneFile(data_ov001_021a94d0) + 8);
    func_021243ac(gMissionRunMSsel->mHeap, 0, gMissionRunMSsel->mMissionRunMSselMBnll, 0xd2, 0x46, 0,
                  gMissionRunMSsel->mMissionRunMSselMNcer, gMissionRunMSsel->mMissionRunMSselMBncl,
                  gMissionRunMSsel->mMissionRunMSselMTable, 0x8000);
    rem = func_02148ca0();
    for (i = 0; i < 9; i++) {
        rem -=
            func_021243ac(gMissionRunMSsel->mHeap, data_ov001_021a6e10[i][0], gMissionRunMSsel->mMissionRunMSselSBnll,
                          data_ov001_021a6e34[i][0], data_ov001_021a6e58[i][0], data_ov001_021a6e7c[i][5],
                          gMissionRunMSsel->mMissionRunMSselSNcer, gMissionRunMSsel->mMissionRunMSselSBncl,
                          gMissionRunMSsel->mMissionRunMSselSTable, rem);
        base = data_ov001_021a6e10[i][0];
        rem -= func_021243ac(gMissionRunMSsel->mHeap, data_ov001_021a6e10[i][1],
                             gMissionRunMSsel->mMissionRunMSselSBnll, data_ov001_021a6e34[i][1],
                             data_ov001_021a6e58[i][1], base + gMissionRunMSsel->mMissionRunMSselSBncl->mUnk_06,
                             gMissionRunMSsel->mMissionRunMSselSNcer, gMissionRunMSsel->mMissionRunMSselSBncl,
                             gMissionRunMSsel->mMissionRunMSselSTable, rem);
    }
    func_ov001_021a64ac(gMissionRunMSsel->mHeap);
    func_ov001_021a0b3c();
    gMissionRunMSsel->mUnk_b0 = gMissionRunMSsel->mIndex;
    func_ov001_021a0774();
    func_ov001_021a04f0();
    FrmHeapShrinkInParent(gMissionRunMSsel->mHeap);
}

void ReleaseMissionRunMSsel(void) {
    switch (gMissionRunMSsel->mResult) {
        case 1:
            func_02105550(4, func_02029608());
            break;
        case 2:
            func_02105550(0, func_02029608());
            break;
    }
    func_ov001_021a64a0();
    HeapDestroy(gMissionRunMSsel->mHeap);
    gMissionRunMSsel = NULL;
}

void AdvanceMissionRunMSselState0(void) {
    func_021055b0(gMissionRunMSsel->mUnk_a8);
    if (func_02036c5c() != 0) {
        RequestMissionRunMSselState1();
    }
}

void AdvanceMissionRunMSselState1(void) {
    s32 i;
    s32 j;
    u16 a;
    s16 v0;
    u16 b;
    s16 v1;

    func_021055b0(gMissionRunMSsel->mUnk_a8);
    a = gMissionRunMSsel->mMissionRunMSselMBncl->mUnk_06;
    b = gMissionRunMSsel->mMissionRunMSselSBncl->mUnk_06;
    gMissionRunMSsel->mStateFrames = gMissionRunMSsel->mStateFrames + 1;
    v0 = func_020ae4c0(1, 0x100, 0, gMissionRunMSsel->mStateFrames, 10);
    v1 = func_020ae4c0(1, -192, 0, gMissionRunMSsel->mStateFrames, 10);
    gMissionRunMSsel->mBg0OffsetX = v0;
    gMissionRunMSsel->mBg1Offset = v1;
    gMissionRunMSsel->mMissionRunMSselMTable[0].mUnk_04 = v0;
    gMissionRunMSsel->mMissionRunMSselMTable[1].mUnk_04 = v0;
    gMissionRunMSsel->mMissionRunMSselMTable[9].mUnk_04 = v0;
    gMissionRunMSsel->mMissionRunMSselMTable[18].mUnk_04 = v0;
    for (i = 0; i < 7; i++) {
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6d88[i]].mUnk_04 = v0;
    }
    gMissionRunMSsel->mMissionRunMSselSTable[45].mUnk_04 = v0;
    for (i = 0; i < 6; i++) {
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6d7c[i]].mUnk_04 = v0;
    }
    gMissionRunMSsel->mMissionRunMSselMTable[a].mUnk_04 = v0;
    for (i = 0; i < 9; i++) {
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6dd4[i]].mUnk_04 = v0;
        for (j = 0; j < 9; j++) {
            gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][j]].mUnk_04 = v0;
        }
        for (j = 0; j < 2; j++) {
            gMissionRunMSsel->mMissionRunMSselSTable[b + data_ov001_021a6e10[i][j]].mUnk_04 = v0;
        }
    }
    if (gMissionRunMSsel->mStateFrames >= 10) {
        func_ov001_021a04c0();
    }
}

void AdvanceMissionRunMSselState2(void) {
    func_021055b0(gMissionRunMSsel->mUnk_a8);
    if (IsSelectReturnState2NoState3Or4Request()) {
        RequestMissionRunMSselState3();
    }
}

void AdvanceMissionRunMSselState3(void) {
    u32 result = -1;
    Unk02175628Index slot = UNK_02175628_INDEX_8;
    BOOL flag_b;
    BOOL flag_a;
    u16 value;
    s16 current;
    s16 delta;
    s16 target;

    func_021055b0(gMissionRunMSsel->mUnk_a8);
    func_ov001_021a0620();
    flag_b = FALSE;
    flag_a = FALSE;
    value = data_02175628[slot].mHasPair;
    if (value == 0 && data_02175628[slot].mNoPairCount < 5) {
        flag_a = TRUE;
    }
    if (flag_a == FALSE && data_02175628[slot].mPrevHasPair == 0 && value != 0) {
        flag_b = TRUE;
    }
    if (flag_b) {
        result = RectTableFindContaining(gMissionRunMSsel->mMissionRunMSselSBnbl, data_02175628[slot].mUnk_48,
                                         data_02175628[slot].mUnk_4a);
    }
    if ((u16) (data_02175628[slot].mUnk_00 & 2) == 0) {
        flag_b = FALSE;
        flag_a = FALSE;
        value = data_02175628[slot].mHasPair;
        if (value == 0 && data_02175628[slot].mNoPairCount < 5) {
            flag_a = TRUE;
        }
        if (flag_a == FALSE && data_02175628[slot].mPrevHasPair == 0 && value != 0) {
            flag_b = TRUE;
        }
        if (!flag_b || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[slot].mUnk_48,
                                                                       data_02175628[slot].mUnk_4a) == FALSE) {
            goto skip;
        }
    }
    if (func_ov001_021a071c() != FALSE) {
        return;
    }
    func_021281c8(0xe);
    gMissionRunMSsel->mUnk_9c = 0x100;
    gMissionRunMSsel->mResult = 2;
    func_ov001_021a03a0();
    func_02128310(0);
    return;
skip:
    if (result <= 8) {
        target = data_ov001_021a6d98[result];
        if (target == 8 && gMissionRunMSsel->mUnk_a0 == 0) {
            func_0212ecc0(&data_0217d068, 0, 0x16);
            return;
        }
        gMissionRunMSsel->mIndex = target;
        gMissionRunMSsel->mUnk_6c[gMissionRunMSsel->mIndex] = 5;
        func_ov001_021a0488();
        return;
    }
    if ((u16) (data_02175628[slot].mUnk_00 & 1) != 0) {
        gMissionRunMSsel->mUnk_6c[gMissionRunMSsel->mIndex] = 5;
        func_ov001_021a0488();
        return;
    }
    if (func_020ae408(8, 0x40)) {
        current = gMissionRunMSsel->mIndex;
        delta = data_ov001_021a6de8[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && gMissionRunMSsel->mUnk_a0 == 0) {
            target = target + data_ov001_021a6de8[target];
        }
        gMissionRunMSsel->mIndex = target;
        gMissionRunMSsel->mUnk_6c[gMissionRunMSsel->mIndex] = 5;
        func_0212ecc0(&data_0217d068, 0, 0);
        return;
    }
    if (func_020ae408(8, 0x80)) {
        current = gMissionRunMSsel->mIndex;
        delta = data_ov001_021a6dac[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && gMissionRunMSsel->mUnk_a0 == 0) {
            target = target + data_ov001_021a6dac[target];
        }
        gMissionRunMSsel->mIndex = target;
        gMissionRunMSsel->mUnk_6c[gMissionRunMSsel->mIndex] = 5;
        func_0212ecc0(&data_0217d068, 0, 0);
        return;
    }
    if (func_020ae408(8, 0x20)) {
        current = gMissionRunMSsel->mIndex;
        delta = data_ov001_021a6dc0[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && gMissionRunMSsel->mUnk_a0 == 0) {
            target = target + data_ov001_021a6dc0[target];
        }
        gMissionRunMSsel->mIndex = target;
        gMissionRunMSsel->mUnk_6c[gMissionRunMSsel->mIndex] = 5;
        func_0212ecc0(&data_0217d068, 0, 0);
        return;
    }
    if (func_020ae408(8, 0x10)) {
        current = gMissionRunMSsel->mIndex;
        delta = data_ov001_021a6dfc[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && gMissionRunMSsel->mUnk_a0 == 0) {
            target = target + data_ov001_021a6dfc[target];
        }
        gMissionRunMSsel->mIndex = target;
        gMissionRunMSsel->mUnk_6c[gMissionRunMSsel->mIndex] = 5;
        func_0212ecc0(&data_0217d068, 0, 0);
    }
}

void AdvanceMissionRunMSselState4(void) {
    func_021055b0(gMissionRunMSsel->mUnk_a8);
    func_ov001_021a0620();
    gMissionRunMSsel->mStateFrames = gMissionRunMSsel->mStateFrames + 1;
    if (gMissionRunMSsel->mStateFrames >= 5) {
        if (func_ov001_021a071c() == FALSE) {
            func_ov001_021a0428();
        }
    }
}

void AdvanceMissionRunMSselState5(void) {
    func_021055b0(gMissionRunMSsel->mUnk_a8);
    func_ov001_021a0620();
    if (func_021277c8()) {
        RequestMissionRunMSselState6();
    }
}

void AdvanceMissionRunMSselState6(void) {
    func_021055b0(gMissionRunMSsel->mUnk_a8);
    func_ov001_021a0620();
    if (func_02127788()) {
        func_ov001_021a03f8();
    }
}

void AdvanceMissionRunMSselState7(void) {
    s32 i;
    s32 r;

    func_021055b0(gMissionRunMSsel->mUnk_a8);
    func_ov001_021a0620();
    if (func_021277ac()) {
        r = func_02127794();
        switch (r) {
            case 0:
                func_ov001_021a0734();
                gMissionRunMSsel->mResult = 1;
                gMissionRunMSsel->mUnk_9c = -0x100;
                func_ov001_021a03a0();
                break;
            case -1:
            case 1:
                RequestMissionRunMSselState3();
                break;
        }
        for (i = 0; i < 9; i++) {
            gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][0]].mUnk_00 = 1;
        }
    }
}

void AdvanceMissionRunMSselState8(void) {
    s32 i;
    s32 j;
    s16 first;
    s16 second;
    u16 a;
    u16 b;

    a = gMissionRunMSsel->mMissionRunMSselMBncl->mUnk_06;
    b = gMissionRunMSsel->mMissionRunMSselSBncl->mUnk_06;
    gMissionRunMSsel->mStateFrames = gMissionRunMSsel->mStateFrames + 1;
    first = func_020ae4c0(1, 0, gMissionRunMSsel->mUnk_9c, gMissionRunMSsel->mStateFrames, 10);
    second = func_020ae4c0(1, 0, -0xc0, gMissionRunMSsel->mStateFrames, 10);
    gMissionRunMSsel->mBg0OffsetX = first;
    gMissionRunMSsel->mBg1Offset = second;
    gMissionRunMSsel->mMissionRunMSselMTable[0].mUnk_04 = first;
    gMissionRunMSsel->mMissionRunMSselMTable[1].mUnk_04 = first;
    gMissionRunMSsel->mMissionRunMSselMTable[9].mUnk_04 = first;
    gMissionRunMSsel->mMissionRunMSselMTable[18].mUnk_04 = first;
    for (i = 0; i < 7; i++) {
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6d88[i]].mUnk_04 = first;
    }
    gMissionRunMSsel->mMissionRunMSselSTable[45].mUnk_04 = first;
    for (i = 0; i < 6; i++) {
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6d7c[i]].mUnk_04 = first;
    }
    gMissionRunMSsel->mMissionRunMSselMTable[a].mUnk_04 = first;
    for (i = 0; i < 9; i++) {
        gMissionRunMSsel->mMissionRunMSselMTable[data_ov001_021a6dd4[i]].mUnk_04 = first;
        for (j = 0; j < 9; j++) {
            gMissionRunMSsel->mMissionRunMSselSTable[data_ov001_021a6e7c[i][j]].mUnk_04 = first;
        }
        for (j = 0; j < 2; j++) {
            gMissionRunMSsel->mMissionRunMSselSTable[b + data_ov001_021a6e10[i][j]].mUnk_04 = first;
        }
    }
    if (gMissionRunMSsel->mStateFrames == 5) {
        CallQueueAppend(9, 0, gMissionRunMSsel->mUnk_48, 0x800);
    }
}

s32 AdvanceMissionRunMSsel(void) {
    gMissionRunMSsel->mState = gMissionRunMSsel->mNextState;
    switch (gMissionRunMSsel->mState) {
        case 0:
            AdvanceMissionRunMSselState0();
            break;
        case 1:
            AdvanceMissionRunMSselState1();
            break;
        case 2:
            AdvanceMissionRunMSselState2();
            break;
        case 3:
            AdvanceMissionRunMSselState3();
            break;
        case 4:
            AdvanceMissionRunMSselState4();
            break;
        case 5:
            AdvanceMissionRunMSselState5();
            break;
        case 6:
            AdvanceMissionRunMSselState6();
            break;
        case 7:
            AdvanceMissionRunMSselState7();
            break;
        case 8:
            AdvanceMissionRunMSselState8();
            break;
    }
    func_ov001_021a08d8();
    func_ov001_021a09a4();
    func_02124c30(gMissionRunMSsel->mMissionRunMSselMBncl, gMissionRunMSsel->mMissionRunMSselMNcer,
                  gMissionRunMSsel->mMissionRunMSselMBnll, gMissionRunMSsel->mUnk_b4,
                  gMissionRunMSsel->mMissionRunMSselMTable);
    func_02124c30(gMissionRunMSsel->mMissionRunMSselSBncl, gMissionRunMSsel->mMissionRunMSselSNcer,
                  gMissionRunMSsel->mMissionRunMSselSBnll, gMissionRunMSsel->mUnk_b8,
                  gMissionRunMSsel->mMissionRunMSselSTable);
    if (gMissionRunMSsel->mState == 8 && gMissionRunMSsel->mStateFrames >= 10) {
        return gMissionRunMSsel->mResult;
    }
    return 0;
}

void func_ov001_0219f8ec(void) {
    *(vu32 *) 0x4000010 =
        (-gMissionRunMSsel->mBg0OffsetX & 0x1ff) | ((-gMissionRunMSsel->mBg0OffsetY << 16) & 0x1ff0000);
    *(vu32 *) 0x4000014 = (-gMissionRunMSsel->mBg1Offset << 16) & 0x1ff0000;
}

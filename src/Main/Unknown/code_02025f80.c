#include "Main/Unknown/code_02025f80.h"
#include "registers.h"

#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025eb0.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_02027000.h"
#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae5d4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_021105a0.h"
#include "Main/Unknown/code_021106a8.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_02025f54.h"
#include "Main/Unknown/code_0202719c.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02025e28.h"

#pragma thumb on

void func_02027188(void) {
    func_0202719c();
    func_020271e8();
}

#pragma thumb off

#pragma thumb on

void func_020270fc(s32 a) {
    gSelectCharacter->mUnk_064 = a;
    switch (gSelectCharacter->mUnk_07c) {
        case 8:
            func_02027be0();
            break;
        case 9:
            func_02027a58();
            break;
        case 10:
            func_02027850();
            break;
        case 11:
            func_02027648();
            break;
        case 12:
            func_02027448();
            break;
    }
    func_02027188();
    func_0202721c();
    func_02025f54(&gSelectCharacter->mUnk_0f8[0], 0);
    gSelectCharacter->mUnk_0f0 = gSelectCharacter->mUnk_090[gSelectCharacter->mUnk_060].mUnk_00;
    gSelectCharacter->mUnk_0f4 = func_02025e60(gSelectCharacter->mUnk_0f0);
}

#pragma thumb off

#pragma thumb on

u32 func_020270d0(void) {
    int v1;
    if ((gSelectCharacter->mUnk_080 != 0) && (v1 = func_0202b8c0(), v1 != 0)) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void func_02027084(void) {
    Unk02174e14_00 *p = &gSelectCharacter->mUnk_01c;
    s32 i;
    s32 n;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        n = p->mUnk_0c->mUnk_06;
        for (i = 0; i < n; i++) {
            func_02124b1c(&p->mUnk_18[i], gSelectCharacter->mUnk_074, gSelectCharacter->mUnk_070);
        }
    }
}

#pragma thumb off

#pragma thumb on

void InitSelectCharacter(void *a, s32 b, void *c, void *d) {
    void *h;
    Unk02174e14 *p;
    Unk02174e14_00 *s;
    Unk021534bc *t;
    s32 i;
    s32 j;
    s32 k;
    BOOL f;
    Unk02174e14_00 v;
    Unk02174e14_00 w;

    h = CreateFrmHeapFromMaxFree(a);
    gSelectCharacter = HeapAlloc(h, 0x12c);
    MemFillWordsByBlock_inline(gSelectCharacter, 0x12c);
    gSelectCharacter->mHeap = h;
    gSelectCharacter->mUnk_080 = b;
    switch (GetRaceSetupCopy()->mUnk_108) {
        case 0:
            func_02025f80(&gSelectCharacter->mUnk_0f8[0], 0, 10, -0x80, 0);
            func_02025f80(&gSelectCharacter->mUnk_0f8[2], 0, 10, 0x60, 0);
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                StartKartModelMenuBg0Increase();
            }
            break;
        case 2:
            func_02025f80(&gSelectCharacter->mUnk_0f8[0], 1, 10, -0x80, 0);
            func_02025f80(&gSelectCharacter->mUnk_0f8[2], 1, 10, 0x60, 0);
            switch (gSelectCharacter->mUnk_080) {
                case 1:
                    if (data_0217aa00->mUnk_0004 == 8) {
                        data_0217aa00->mUnk_15f7 = 0xff;
                    }
                    break;
                case 2:
                    SetWiFiSessionOwnCharacterIndexNone();
                    break;
            }
            break;
    }
    func_02025f80(&gSelectCharacter->mUnk_0f8[1], 0, 10, -0x40, 0);
    gSelectCharacter->mUnk_054 = c;
    gSelectCharacter->mUnk_058 = d;
    if (gSelectCharacter->mUnk_080 != 0 || GetRaceSetupCopy()->mMode == 3 || GetRaceSetupCopy()->mMode == 2) {
        f = TRUE;
    } else {
        f = FALSE;
    }
    gSelectCharacter->mUnk_128 = f;
    if (gSelectCharacter->mUnk_128 != FALSE) {
        switch (gSelectCharacter->mUnk_080) {
            case 0:
                k = 0;
                break;
            case 1:
                k = 1;
                break;
            case 2:
                k = 2;
                break;
        }
        func_0202c0d4(k, 0);
    }
    p = gSelectCharacter;
    switch (p->mUnk_080) {
        case 0:
            p->mUnk_078 = 0;
            break;
        case 1:
            p->mUnk_078 =
                data_0217aa00->mUnk_1e52[(u16) (data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0)].mUnk_00;
            break;
        case 2:
            gSelectCharacter->mUnk_078 = func_020295e4();
            break;
    }
    p = gSelectCharacter;
    if (p->mUnk_128 == FALSE) {
        func_02025b20(&p->mUnk_000, gSelectCharacterGpMNcgrName, gSelectCharacterGpMNcerName,
                      gSelectCharacterGpMONclrName, gSelectCharacterGpMBnclName, NULL, NULL, FindFileInLoadedArchives);
        func_02025a50(0, gSelectCharacter->mHeap, &p->mUnk_000);
        func_02025b20(&v, gSelectCharacterGpTitleMNcgrName, gSelectCharacterGpTitleMNcerName, NULL,
                      gSelectCharacterGpTitleMBnclName, NULL, NULL, FindFileInLoadedArchives);
        func_02124748(0, v.mUnk_08, v.mUnk_00, v.mUnk_0c, 0, 0, p->mUnk_000.mUnk_08, p->mUnk_000.mUnk_0c);
        func_02025b20(&gSelectCharacter->mUnk_038, gSelectCharacterGpNameMNcgrName, gSelectCharacterGpNameMNcerName,
                      NULL, gSelectCharacterGpNameMBnclName, NULL, NULL, FindFileInLoadedArchives);
        p->mUnk_000.mUnk_18[9].mUnk_00 = 0;
        p->mUnk_000.mUnk_18[8].mUnk_00 = p->mUnk_000.mUnk_18[9].mUnk_00;
        p->mUnk_000.mUnk_18[7].mUnk_00 = p->mUnk_000.mUnk_18[8].mUnk_00;
        p->mUnk_000.mUnk_18[6].mUnk_00 = p->mUnk_000.mUnk_18[7].mUnk_00;
        p->mUnk_000.mUnk_18[5].mUnk_00 = p->mUnk_000.mUnk_18[6].mUnk_00;
        p->mUnk_000.mUnk_18[4].mUnk_00 = p->mUnk_000.mUnk_18[5].mUnk_00;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        s = &gSelectCharacter->mUnk_01c;
        func_02025b20(s, gSelectCharacterSNcgrName, gSelectCharacterSNcerName, gSelectCharacterSONclrName,
                      gSelectCharacterSBnclName, NULL, gSelectCharacterSBnblName, FindFileInLoadedArchives);
        func_02025a50(1, gSelectCharacter->mHeap, s);
        s->mUnk_18[24].mUnk_00 = 0;
        for (i = 0; i < 12; i++) {
            s->mUnk_18[data_usa_02153554[i].mUnk_04].mUnk_10 = 1;
            s->mUnk_18[data_usa_02153554[i].mUnk_02].mUnk_10 = s->mUnk_18[data_usa_02153554[i].mUnk_04].mUnk_10;
            s->mUnk_18[data_usa_02153554[i].mUnk_00].mUnk_10 = s->mUnk_18[data_usa_02153554[i].mUnk_02].mUnk_10;
            s->mUnk_18[data_usa_02153554[i].mUnk_04].mUnk_34 = 0;
            s->mUnk_18[data_usa_02153554[i].mUnk_02].mUnk_34 = s->mUnk_18[data_usa_02153554[i].mUnk_04].mUnk_34;
            s->mUnk_18[data_usa_02153554[i].mUnk_00].mUnk_34 = s->mUnk_18[data_usa_02153554[i].mUnk_02].mUnk_34;
        }
        s->mUnk_18[25].mUnk_10 = 1;
        s->mUnk_18[24].mUnk_10 = s->mUnk_18[25].mUnk_10;
        s->mUnk_18[25].mUnk_34 = 0;
        s->mUnk_18[24].mUnk_34 = s->mUnk_18[25].mUnk_34;
    } else if (GetRaceSetupCopy()->mMode == 2) {
        func_0211f4b0(gSelectCharacter->mHeap, gSelectCharacter->mUnk_058);
        func_0211f394();
    }
    gSelectCharacter->mUnk_07c = 8;
    for (i = 0; i < 8; i++) {
        gSelectCharacter->mUnk_090[i] = data_021535b4[i];
    }
    if (func_02056dec(0x15) != 0) {
        gSelectCharacter->mUnk_090[i] = data_021535b4[8];
        i++;
        gSelectCharacter->mUnk_07c++;
    }
    if (func_02056dec(0x14) != 0) {
        gSelectCharacter->mUnk_090[i] = data_021535b4[9];
        i++;
        gSelectCharacter->mUnk_07c++;
    }
    if (func_02056dec(0x16) != 0) {
        gSelectCharacter->mUnk_090[i] = data_021535b4[10];
        i++;
        gSelectCharacter->mUnk_07c++;
    }
    if (func_02056dec(0x17) != 0) {
        gSelectCharacter->mUnk_090[i] = data_021535b4[11];
        i++;
        gSelectCharacter->mUnk_07c++;
    }
    for (; i < 12; i++) {
        gSelectCharacter->mUnk_090[i].mUnk_00 = -1;
    }
    for (j = 0; j < gSelectCharacter->mUnk_07c; j++) {
        if (gSelectCharacter->mUnk_090[j].mUnk_00 ==
            GetRaceSetupCopy()->mEntries[gSelectCharacter->mUnk_078].mCharacterIndex) {
            gSelectCharacter->mUnk_060 = j;
        }
    }
    gSelectCharacter->mUnk_064 = gSelectCharacter->mUnk_060;
    p = gSelectCharacter;
    p->mUnk_0f0 = GetRaceSetupCopy()->mEntries[p->mUnk_078].mCharacterIndex;
    if (gSelectCharacter->mUnk_0f0 == -1) {
        gSelectCharacter->mUnk_0f0 = 0;
    }
    gSelectCharacter->mUnk_0f4 = func_02025e60(gSelectCharacter->mUnk_0f0);
    GetRaceSetupCopy()->mEntries[gSelectCharacter->mUnk_078].mCharacterIndex = -1;
    GetRaceSetupCopy()->mEntries[gSelectCharacter->mUnk_078].mKartIndex = -1;
    GetRaceSetupCopy()->mEntries[gSelectCharacter->mUnk_078].mUnk_14 = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        s = &gSelectCharacter->mUnk_01c;
        func_02025b84(0, &w);
        for (i = 0; i < gSelectCharacter->mUnk_07c; i++) {
            func_0212481c(gSelectCharacter->mUnk_090[i].mUnk_00, w.mUnk_08, w.mUnk_00, w.mUnk_04, w.mUnk_0c, 1,
                          data_usa_02153554[i].mUnk_02, s->mUnk_08, s->mUnk_0c);
        }
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        t = NULL;
        s = &gSelectCharacter->mUnk_01c;
        switch (gSelectCharacter->mUnk_07c) {
            case 8:
                t = data_021534bc;
                func_02027be0();
                break;
            case 9:
                t = data_021534dc;
                func_02027a58();
                break;
            case 10:
                t = data_02153500;
                func_02027850();
                break;
            case 11:
                t = data_02153528;
                func_02027648();
                break;
            case 12:
                func_02027448();
                break;
        }
        if (t != NULL) {
            for (i = 0; i < gSelectCharacter->mUnk_07c; i++) {
                func_02025c94(data_usa_02153554[i].mUnk_00, t[i].mUnk_00, t[i].mUnk_02, s->mUnk_0c);
                func_02025c94(data_usa_02153554[i].mUnk_02, t[i].mUnk_00, t[i].mUnk_02, s->mUnk_0c);
                RectTableSetEntryXY(data_usa_02153554[i].mRectEntryId, t[i].mUnk_00, t[i].mUnk_02, s->mUnk_10);
                func_02025c94(data_usa_02153554[i].mUnk_04, (s16) (t[i].mUnk_00 + 3), (s16) (t[i].mUnk_02 + 3),
                              s->mUnk_0c);
            }
            for (; i < 12; i++) {
                s->mUnk_18[data_usa_02153554[i].mUnk_00].mUnk_00 = 0;
                s->mUnk_18[data_usa_02153554[i].mUnk_02].mUnk_00 = 0;
                s->mUnk_18[data_usa_02153554[i].mUnk_04].mUnk_00 = 0;
                RectTableSetEntryXY(data_usa_02153554[i].mRectEntryId, 0x400, 0x400, s->mUnk_10);
            }
        }
        func_020271e8();
        func_0202721c();
    }
    if (gSelectCharacter->mUnk_080 == 0) {
        func_021170f8();
        SetSelectReturnSoundId(0xe);
        RequestSelectReturnState1();
    }
    if (AreBrightnessFadesClear() != 0) {
        gSelectCharacter->mUnk_06c = 1;
    } else {
        StartFadeToClear(10);
        func_0202734c(0);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_02077f48(0);
    }
    FrmHeapShrinkInParent(gSelectCharacter->mHeap);
}

#pragma thumb off

#pragma thumb on

static inline s32 func_02026120_inline(u16 i) {
    BOOL a = FALSE;
    if (data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) {
        a = TRUE;
    }
    return a;
}

static inline s32 func_02026120_inline_2(u16 i) {
    BOOL b = FALSE;
    if (func_02026120_inline(i) == 0 && data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0) {
        b = TRUE;
    }
    return b;
}

int AdvanceSelectCharacter(void) {
    int r;
    Unk02174e14 *g;
    Unk02174e14_00 *s;
    s32 n;
    Unk02174e14 *p;
    u16 i;
    s32 a;
    s32 j;
    s32 k;
    s32 x;
    s32 y;
    u16 v;
    u8 c;
    s16 t;
    s16 m;

    r = 0;
    i = func_020435bc();
    g = gSelectCharacter;
    s = &g->mUnk_01c;
    switch (g->mUnk_06c) {
        case 0:
            if (AreBrightnessFadesClear() != 0) {
                gSelectCharacter->mUnk_06c = 1;
            }
            break;
        case 1:
            if (g->mUnk_068 == 0) {
                func_0202734c(1);
            }
            gSelectCharacter->mUnk_068++;
            p = gSelectCharacter;
            if (p->mUnk_068 < 10) {
                p->mUnk_070 = (p->mUnk_068 << 12) / 10;
            } else {
                p->mUnk_070 = 0x1000;
                gSelectCharacter->mUnk_068 = 0;
                if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
                    a = 2;
                } else {
                    a = 3;
                }
                gSelectCharacter->mUnk_06c = a;
            }
            func_02027084();
            break;
        case 2:
            g->mUnk_0f0 = 0xc;
            gSelectCharacter->mUnk_0f4 = 0x24;
            gSelectCharacter->mUnk_068 = 0;
            gSelectCharacter->mUnk_08c = 1;
            if (GetRaceSetupCopy()->mMode == 3) {
                c = gSelectCharacter->mUnk_0f0 | 0x40;
                if (data_0217aa00->mUnk_0004 == 8) {
                    data_0217aa00->mUnk_15f7 = c;
                }
                func_02027424(1);
                gSelectCharacter->mUnk_06c = 8;
            } else if (GetRaceSetupCopy()->mMode == 2) {
                c = gSelectCharacter->mUnk_0f0 | 0xc0;
                if (data_0217aa00->mUnk_0004 == 8) {
                    data_0217aa00->mUnk_15f7 = c;
                }
                gSelectCharacter->mUnk_06c = 6;
            }
            break;
        case 3:
            n = g->mUnk_060;
            if (func_02026120_inline_2(i) != 0) {
                x = data_02175670[i].mUnk_00;
                y = data_02175672[i].mUnk_00;
                k = RectTableFindContaining(s->mUnk_10, x, y);
                if (k >= 0) {
                    for (j = 0; j < gSelectCharacter->mUnk_07c; j++) {
                        if (k == data_usa_02153554[j].mRectEntryId) {
                            gSelectCharacter->mUnk_060 = j;
                            break;
                        }
                    }
                    func_020270fc(n);
                    func_021106a8(func_02025eb0(gSelectCharacter->mUnk_0f0), 0);
                    gSelectCharacter->mUnk_068 = 0;
                    gSelectCharacter->mUnk_06c = 5;
                } else if (gSelectCharacter->mUnk_080 == 0 &&
                           IsSelectReturnState2NoState3Or4RequestAndInRect(x, y) != FALSE) {
                    StartSelectCharacterReturn();
                }
            } else if (func_020270d0() != 0) {
                gSelectCharacter->mUnk_068 = 0;
                gSelectCharacter->mUnk_08c = 3;
                gSelectCharacter->mUnk_06c = 6;
                func_021106a8(func_02025eb0(gSelectCharacter->mUnk_0f0), 0);
                func_02077f48(1);
                p = gSelectCharacter;
                switch (p->mUnk_080) {
                    case 2:
                        SetWiFiSessionOwnCharacterIndex(p->mUnk_0f0);
                        SetWiFiSessionOwnKartIndex(gSelectCharacter->mUnk_0f4);
                        break;
                    case 1:
                        c = p->mUnk_0f0 | 0xc0;
                        if (data_0217aa00->mUnk_0004 == 8) {
                            data_0217aa00->mUnk_15f7 = c;
                        }
                        break;
                }
            } else {
                v = data_02175628[i].mUnk_00;
                if ((u16) (v & PAD_KEY_A) != 0) {
                    gSelectCharacter->mUnk_068 = 0;
                    gSelectCharacter->mUnk_06c = 5;
                    func_02027188();
                    func_021106a8(func_02025eb0(gSelectCharacter->mUnk_0f0), 0);
                } else if (gSelectCharacter->mUnk_080 == 0 && (u16) (v & PAD_KEY_B) != 0) {
                    StartSelectCharacterReturn();
                } else {
                    if (GetNewOrRepeatBits(i, PAD_KEY_UP) != 0) {
                        p = gSelectCharacter;
                        t = p->mTableIndexByKey[0];
                        if (t != -1) {
                            p->mUnk_060 = t;
                        }
                    } else if (GetNewOrRepeatBits(i, PAD_KEY_DOWN) != 0) {
                        p = gSelectCharacter;
                        t = p->mTableIndexByKey[1];
                        if (t != -1) {
                            p->mUnk_060 = t;
                        }
                    } else if (GetNewOrRepeatBits(i, PAD_KEY_RIGHT) != 0) {
                        p = gSelectCharacter;
                        t = p->mTableIndexByKey[2];
                        if (t != -1) {
                            p->mUnk_060 = t;
                        }
                    } else if (GetNewOrRepeatBits(i, PAD_KEY_LEFT) != 0) {
                        p = gSelectCharacter;
                        t = p->mTableIndexByKey[3];
                        if (t != -1) {
                            p->mUnk_060 = t;
                        }
                    }
                    if (gSelectCharacter->mUnk_060 != n) {
                        func_02110698();
                        func_020270fc(n);
                        gSelectCharacter->mUnk_06c = 4;
                    }
                }
            }
            break;
        case 4:
            g->mUnk_068++;
            if (gSelectCharacter->mUnk_068 > 5) {
                func_020272ec();
                gSelectCharacter->mUnk_068 = 0;
                gSelectCharacter->mUnk_06c = 3;
            }
            break;
        case 5:
            g->mUnk_068++;
            p = gSelectCharacter;
            if (p->mUnk_068 > 5) {
                p->mUnk_068 = 0;
                gSelectCharacter->mUnk_08c = 1;
                func_020272ec();
                p = gSelectCharacter;
                switch (p->mUnk_080) {
                    case 0:
                        GetRaceSetupCopy()->mEntries[gSelectCharacter->mUnk_078].mCharacterIndex = p->mUnk_0f0;
                        GetRaceSetupCopy()->mEntries[gSelectCharacter->mUnk_078].mKartIndex =
                            gSelectCharacter->mUnk_0f4;
                        func_02116fb0();
                        if (GetRaceSetupCopy()->mMode == 2) {
                            GetRaceSetupCopy()->mEntries[gSelectCharacter->mUnk_078].mUnk_14 = 1;
                            func_02077f48(1);
                            gSelectCharacter->mUnk_06c = 7;
                            func_02117060();
                            func_02116ec0();
                        } else {
                            func_02027424(1);
                            func_02077f5c();
                            gSelectCharacter->mUnk_06c = 8;
                            func_02025f14(&gSelectCharacter->mUnk_0f8[1], 2);
                        }
                        break;
                    case 1:
                        if (GetRaceSetupCopy()->mMode == 3) {
                            c = gSelectCharacter->mUnk_0f0 | 0x40;
                            if (data_0217aa00->mUnk_0004 == 8) {
                                data_0217aa00->mUnk_15f7 = c;
                            }
                            func_02025f14(&gSelectCharacter->mUnk_0f8[1], 2);
                            func_02027424(1);
                            gSelectCharacter->mUnk_06c = 8;
                            func_02077f5c();
                        } else if (GetRaceSetupCopy()->mMode == 2) {
                            c = gSelectCharacter->mUnk_0f0 | 0xc0;
                            if (data_0217aa00->mUnk_0004 == 8) {
                                data_0217aa00->mUnk_15f7 = c;
                            }
                            func_02077f48(1);
                            gSelectCharacter->mUnk_06c = 6;
                        }
                        break;
                    case 2:
                        SetWiFiSessionOwnCharacterIndex(p->mUnk_0f0);
                        func_02025f14(&gSelectCharacter->mUnk_0f8[1], 2);
                        func_02027424(1);
                        gSelectCharacter->mUnk_06c = 8;
                        func_02077f5c();
                        break;
                }
            }
            break;
        case 6:
            if ((g->mUnk_080 == 1 && func_0202b888() != 0) ||
                (gSelectCharacter->mUnk_080 == 2 && func_02121d0c() != 0)) {
                if (gSelectCharacter->mUnk_080 == 2) {
                    func_021219cc();
                }
                if (GetRaceSetupCopy()->mMode == 2 || func_020270d0() != 0) {
                    gSelectCharacter->mUnk_06c = 7;
                } else {
                    func_02027424(1);
                    func_02025f14(&gSelectCharacter->mUnk_0f8[1], 2);
                    gSelectCharacter->mUnk_06c = 8;
                }
            }
            break;
        case 7:
            g->mUnk_068++;
            p = gSelectCharacter;
            if (p->mUnk_068 > 60) {
                if (p->mUnk_080 == 2) {
                    func_02027424(3);
                } else {
                    func_02027424(2);
                }
                func_02025f14(&gSelectCharacter->mUnk_0f8[1], 2);
                if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                    StartKartModelMenuBg0Decrease();
                } else if (GetRaceSetupCopy()->mMode == 2) {
                    func_0211f378();
                }
                gSelectCharacter->mUnk_068 = 0;
                gSelectCharacter->mUnk_06c = 8;
            }
            break;
        case 8:
            g->mUnk_068++;
            p = gSelectCharacter;
            if (p->mUnk_068 < 10) {
                p->mUnk_070 = ((10 - p->mUnk_068) << 12) / 10;
            } else {
                GetRaceSetupCopy()->mEntries[gSelectCharacter->mUnk_078].mCharacterIndex = p->mUnk_0f0;
                GetRaceSetupCopy()->mEntries[gSelectCharacter->mUnk_078].mKartIndex = gSelectCharacter->mUnk_0f4;
                gSelectCharacter->mUnk_06c = 9;
            }
            gSelectCharacter->mUnk_074 += 0x1000;
            func_02027084();
            break;
        case 9:
            r = g->mUnk_08c;
            break;
    }

    func_02025edc(&gSelectCharacter->mUnk_0f8[0]);
    func_02025edc(&gSelectCharacter->mUnk_0f8[1]);
    func_02025edc(&gSelectCharacter->mUnk_0f8[2]);
    func_0202728c(func_02025ebc(&gSelectCharacter->mUnk_0f8[0]));
    m = func_02025ebc(&gSelectCharacter->mUnk_0f8[1]);
    func_020272c0(m, func_02025ebc(&gSelectCharacter->mUnk_0f8[2]));
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        p = gSelectCharacter;
        if (p->mUnk_08c != 2) {
            RequestKartModelMenuCharacter(p->mUnk_0f0);
            RequestKartModelMenuKart(gSelectCharacter->mUnk_0f4);
        }
        AdvanceKartModelMenu(GetRaceSetupCopy()->mMirrorMode);
    }
    if (gSelectCharacter->mUnk_128 != FALSE) {
        func_0202bb80();
    } else {
        func_02124c30(g->mUnk_000.mUnk_0c, g->mUnk_000.mUnk_08, NULL, gSelectCharacter->mUnk_054, g->mUnk_000.mUnk_18);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_02124bf0(s->mUnk_0c, s->mUnk_08, NULL, gSelectCharacter->mUnk_058, s->mUnk_18);
        func_020ae5d4(gSelectCharacter->mUnk_058);
    } else if (GetRaceSetupCopy()->mMode == 2) {
        func_0211f39c();
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        DrawKartModelMenu();
    }
    switch (r) {
        case 1:
            if (GetRaceSetupCopy()->mMode == 2) {
                GetRaceSetupCopy()->mUnk_108 = 0;
            } else {
                GetRaceSetupCopy()->mUnk_108 = 1;
            }
            break;
        case 2:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                RequestKartModelMenuCharacter(-1);
                RequestKartModelMenuKart(-1);
            }
            GetRaceSetupCopy()->mUnk_108 = 0;
            break;
    }
    return r;
}

#pragma thumb off

#pragma thumb on

void func_020260e4(void) {
    if (*(vu16 *) 0x27ffc40 == 2) {
        if (GetRaceSetupCopy()->mMode == 2) {
            func_0211f498();
        }
    }
    HeapDestroy(gSelectCharacter->mHeap);
    gSelectCharacter = NULL;
}

void func_02026058(void) {
    u32 a = 0x18;

    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x3f, 6, 10);
    if (!(gSelectCharacter->mUnk_06c == 9 && gSelectCharacter->mUnk_08c == 2)) {
        a |= 1;
    }
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (a << 8);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1600;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    if (gSelectCharacter->mUnk_128 != FALSE) {
        func_0202ba14();
    }
}

void func_02025f90(void) {
    Ncgr *a = NULL;
    Nclr *b = NULL;
    Unk02021dc8 *c = NULL;

    LoadNcgrData2(&a, FindFileInLoadedArchives(data_usa_02161b3c));
    LoadNcerData(&c, FindFileInLoadedArchives(data_usa_02161b5c));
    LoadNclrData(&b, FindFileInLoadedArchives(data_usa_02161b7c));
    LoadNcgrData2(&a, FindFileInLoadedArchives(data_usa_02161b9c));
    LoadNcerData(&c, FindFileInLoadedArchives(data_usa_02161bb8));
    LoadNclrData(&b, FindFileInLoadedArchives(data_usa_02161bd4));
    LoadNcgrData2(&a, FindFileInLoadedArchives(data_usa_02161bf0));
    LoadNcerData(&c, FindFileInLoadedArchives(data_usa_02161c14));
    LoadNcgrData2(&a, FindFileInLoadedArchives(data_usa_02161c38));
    LoadNcerData(&c, FindFileInLoadedArchives(data_usa_02161c60));
}

void func_02025f80(Unk02025ebc *a, s32 b, s32 c, s16 d, s32 e) {
    a->mUnk_08 = c;
    a->mUnk_0c = d;
    a->mUnk_0e = e;
    func_02025f14(a, b);
}

#pragma thumb off

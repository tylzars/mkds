#include "Main/Unknown/code_0203206c.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020cee0c.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02181f98.h"
#include "code_0201ea58.h"
#include "code_0212df7c.h"
#include "code_0214d018.h"
#include "registers.h"

#pragma thumb on

void func_02032a20(void) {
    BOOL v;

    if (gSelectGame->mMode == 0) {
        GetRaceSetupCopy()->mMode = 2;
        switch (gSelectGame->mSelectedIndex) {
            case 0:
                v = FALSE;
                break;
            default:
                v = TRUE;
                break;
        }
        GetRaceSetupCopy()->mUnk_e4 = v;
    } else if (gSelectGame->mSelectedIndex == 0) {
        GetRaceSetupCopy()->mMode = 3;
    } else {
        GetRaceSetupCopy()->mMode = 2;
        switch (gSelectGame->mSelectedIndex) {
            case 1:
                v = FALSE;
                break;
            default:
                v = TRUE;
                break;
        }
        GetRaceSetupCopy()->mUnk_e4 = v;
    }
    gSelectGame->mResult = 1;
    gSelectGame->mState = 5;
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
}

void func_020329dc(s32 a) {
    s32 i;
    Unk02174e14_00 *p;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        p = &gSelectGame->mUnk_00[1];
        for (i = 0; i < gSelectGame->mTableCount; i++) {
            p->mUnk_18[gSelectGame->mTable[i].mUnk_02].mUnk_00 = a;
        }
    }
}

void func_020329a0(void) {
    s32 i;
    Unk02174e14_00 *p;

    p = &gSelectGame->mUnk_00[1];
    for (i = 0; i < gSelectGame->mTableCount; i++) {
        p->mUnk_18[gSelectGame->mTable[i].mUnk_00].mUnk_04 = gSelectGame->mUnk_5c;
    }
}

void func_02032940(void) {
    Unk02174e14_00 *p;
    s32 i;
    s32 n;
    s32 m;
    SelectGame *o;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        o = gSelectGame;
        n = o->mUnk_00[0].mUnk_0c->mUnk_06;
        m = o->mUnk_00[0].mUnk_14->mUnk_06;
        for (i = 0; i < m; i++) {
            o->mUnk_00[0].mUnk_18[i + n].mUnk_06 = gSelectGame->mUnk_60;
        }
    }
    p = &gSelectGame->mUnk_00[1];
    m = p->mUnk_0c->mUnk_06;
    for (i = 0; i < m; i++) {
        p->mUnk_18[i].mUnk_04 = gSelectGame->mUnk_5c;
    }
}

void func_020328f8(s32 a) {
    BOOL v;
    s32 i;
    Unk02174e14_00 *p;

    p = &gSelectGame->mUnk_00[1];
    for (i = 0; i < gSelectGame->mTableCount; i++) {
        if (i == gSelectGame->mSelectedIndex && a != 0) {
            v = TRUE;
        } else {
            v = FALSE;
        }
        p->mUnk_18[gSelectGame->mTable[i].mUnk_00].mUnk_00 = v;
    }
}

void func_020328c8(s32 a) {
    s32 i;
    Unk02174e14_00 *p;

    p = &gSelectGame->mUnk_00[1];
    for (i = 0; i < p->mUnk_0c->mUnk_06; i++) {
        p->mUnk_18[i].mUnk_00 = a;
    }
}

void InitSelectGame(void *a, s32 b, void *c, void *d) {
    void *h;
    SelectGame *o;
    Unk02174e14_00 *q;
    u8 v1[0x28];
    u32 k;
    s32 i;
    s32 n;
    s32 m;
    s32 j;
    s32 s;
    s32 e;
    Unk02153e20 *t;
    Unk02153e20 *g;

    h = CreateFrmHeapFromMaxFree(a);
    gSelectGame = HeapAlloc(h, 0x6c);
    MemFillWordsByBlock_inline(gSelectGame, 0x6c);
    gSelectGame->mHeap = h;
    gSelectGame->mMode = b;
    gSelectGame->mUnk_38 = c;
    gSelectGame->mUnk_3c = d;
    gSelectGame->mUnk_5c = 0xee;
    gSelectGame->mUnk_60 = -0xc0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        gSelectGame->mMenuMessages = FindSceneFile(gMenuBmgName);
    }
    switch (gSelectGame->mMode) {
        case 0:
            gSelectGame->mState = 3;
            gSelectGame->mTableCount = 2;
            gSelectGame->mTable = data_02153de8;
            break;
        case 1:
            gSelectGame->mState = 3;
            gSelectGame->mTableCount = 3;
            gSelectGame->mTable = data_02153df4;
            func_02050080();
            break;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_020258d4(0, v1, gSelectGameMBNcgrName2, gSelectGameMBNclrName2, data_02153e10[gSelectGame->mMode].mUnk_00,
                      1, FindSceneFile);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        k = GX_GetSizeOfOBJ();
        o = gSelectGame;
        func_02025b20(o, gSelectGameMNceNcgrName2, gSelectGameMNceNcerName2, gSelectGameMONclrName2,
                      gSelectGameMBnclName, gSelectGameMBnllName, NULL, FindSceneFile);
        func_02025a50(0, gSelectGame->mHeap, o);
        n = o->mUnk_00[0].mUnk_0c->mUnk_06;
        m = o->mUnk_00[0].mUnk_14->mUnk_06;
        i = 0;
        if (m > 0) {
            t = data_02153e20;
            g = t;
            do {
                k -= func_02025a00(0, gSelectGame->mHeap, o, t, k);
                func_0212426c(0, g->mUnk_00, o->mUnk_00[0].mUnk_14, GetBmgEntry(gSelectGame->mMenuMessages, g->mUnk_08),
                              o->mUnk_00[0].mUnk_0c, o->mUnk_00[0].mUnk_18);
                t++;
                g++;
                i++;
            } while (i < m);
        }
        if (gSelectGame->mMode == 0) {
            s = 4;
            e = 6;
        } else {
            s = 0;
            e = 4;
        }
        for (j = s; j < s + e; j++) {
            o->mUnk_00[0].mUnk_18[j + n].mUnk_00 = 0;
        }
    }
    q = &gSelectGame->mUnk_00[1];
    func_02025b20(q, gSelectGameSNceNcgrName2, gSelectGameSNceNcerName2, gSelectGameSONclrName2,
                  data_02153e08[gSelectGame->mMode].mUnk_00, NULL, data_02153e0c[gSelectGame->mMode].mUnk_00,
                  FindSceneFile);
    func_02025a50(1, gSelectGame->mHeap, q);
    func_020328c8(0);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        SetSelectReturnSoundId(-1);
    } else {
        SetSelectReturnSoundId(0xe);
    }
    RequestSelectReturnState1();
    if (gSelectGame->mMode == 1) {
        SetSelectChoisesSoundId(0, 5);
        SetSelectChoisesSoundId(1, 0xf);
    }
    data_0217b488->mUnk_08 = 0;
    FrmHeapShrinkInParent(gSelectGame->mHeap);
}

s32 AdvanceSelectGame(void) {
    s32 a;
    Unk02175628Index v1;
    SelectGame *o;
    Unk02174e14_00 *q;
    s32 b;
    s32 c;
    s32 d;
    BOOL f;
    BOOL e;
    s32 g;
    s32 h;
    u32 t;
    s32 i;
    const void *p;
    const void *p1;

    a = 0;
    v1 = UNK_02175628_INDEX_8;
    o = gSelectGame;
    q = &o->mUnk_00[1];
    switch (o->mState) {
        case 3:
            func_020328c8(1);
            func_020328f8(1);
            gSelectGame->mStateFrames = gSelectGame->mStateFrames + 1;
            if (gSelectGame->mStateFrames < 10) {
                gSelectGame->mUnk_5c = InterpolateS16(1, 0xee, a, gSelectGame->mStateFrames, 10);
                gSelectGame->mUnk_60 = InterpolateS16(1, -0xc0, a, gSelectGame->mStateFrames, 10);
            } else {
                gSelectGame->mStateFrames = a;
                gSelectGame->mUnk_5c = a;
                gSelectGame->mUnk_60 = a;
                gSelectGame->mState = 4;
            }
            func_02032940();
            break;
        case 4:
            b = o->mSelectedIndex;
            d = ~a;
            c = 0;
            f = FALSE;
            e = FALSE;
            t = data_02175628[v1].mHasPair;
            if (t == 0 && data_02175628[v1].mNoPairCount < 5) {
                e = TRUE;
            }
            if (e == FALSE && data_02175628[v1].mPrevHasPair == 0 && t != 0) {
                f = TRUE;
            }
            if (f != FALSE) {
                d = data_02175628[v1].mUnk_48;
                g = data_02175628[v1].mUnk_4a;
                c = IsSelectReturnState2NoState3Or4RequestAndInRect(d, g);
                d = RectTableFindContaining(q->mUnk_10, d, g);
            }
            if ((u16) (data_02175628[v1].mUnk_00 & 1) != 0) {
                func_020328f8(0);
                func_02032a20();
            } else if (d >= 0) {
                for (i = 0; i < gSelectGame->mTableCount; i++) {
                    if (d == gSelectGame->mTable[i].mUnk_04) {
                        func_020328f8(gSelectGame->mSelectedIndex != i ? 1 : 0);
                        gSelectGame->mSelectedIndex = i;
                        func_02032a20();
                        break;
                    }
                }
            } else if ((u16) (data_02175628[v1].mUnk_00 & 2) != 0 || c != 0) {
                if (gSelectGame->mMode == 0) {
                    gSelectGame->mResult = 2;
                    gSelectGame->mState = 9;
                } else {
                    p = data_02163aec;
                    p1 = data_02163af0;
                    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                        p = GetBmgEntry(gSelectGame->mMenuMessages, 0x14);
                        p1 = GetBmgEntry(gSelectGame->mMenuMessages, 0x16);
                    }
                    StartSelectChoises(p, p1, 0);
                    gSelectGame->mState = 7;
                    func_020329dc(0);
                }
                RequestSelectReturnState3WithSound(0);
            } else if (func_020ae408(8, 0x40) != 0) {
                if (gSelectGame->mSelectedIndex == 0) {
                    if (gSelectGame->mMode == 1) {
                        gSelectGame->mSelectedIndex = gSelectGame->mTableCount - 1;
                    }
                } else {
                    gSelectGame->mSelectedIndex = gSelectGame->mSelectedIndex - 1;
                }
            } else if (func_020ae408(8, 0x80) != 0) {
                if (gSelectGame->mSelectedIndex == gSelectGame->mTableCount - 1) {
                    if (gSelectGame->mMode == 1) {
                        gSelectGame->mSelectedIndex = 0;
                    }
                } else {
                    gSelectGame->mSelectedIndex = gSelectGame->mSelectedIndex + 1;
                }
            }
            if (d < 0 && b != gSelectGame->mSelectedIndex) {
                func_020328f8(1);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
            }
            break;
        case 7:
            if (GetSelectChoisesDone() != 0) {
                if (GetSelectChoisesIndex() == 0 || GetSelectChoisesIndex() == ~a) {
                    gSelectGame->mState = 4;
                } else {
                    data_0217aa00->mUnk_0454 |= 0x80;
                    gSelectGame->mResult = 3;
                    gSelectGame->mState = 8;
                }
                func_020329dc(1);
                RequestSelectChoisesState0();
            }
            break;
        case 8:
            if (func_02054f58() == 1) {
                a = gSelectGame->mResult;
                gSelectGame->mState = 11;
            }
            break;
        case 5:
            o->mStateFrames = o->mStateFrames + 1;
            if (gSelectGame->mStateFrames >= 5) {
                gSelectGame->mStateFrames = a;
                gSelectGame->mState = 6;
                func_020328f8(1);
            }
            break;
        case 6:
            o->mStateFrames = o->mStateFrames + 1;
            if (gSelectGame->mStateFrames < 10) {
                gSelectGame->mUnk_5c = func_020ae488(gSelectGame->mStateFrames);
            } else {
                gSelectGame->mStateFrames = a;
                gSelectGame->mState = 9;
                if (gSelectGame->mMode != 0) {
                    RequestSelectReturnState4();
                }
            }
            func_020329a0();
            break;
        case 9:
            o->mStateFrames = o->mStateFrames + 1;
            if (gSelectGame->mStateFrames < 10) {
                gSelectGame->mUnk_5c = InterpolateS16(1, a, 0xee, gSelectGame->mStateFrames, 10);
                gSelectGame->mUnk_60 = InterpolateS16(1, a, -0xc0, gSelectGame->mStateFrames, 10);
            } else {
                gSelectGame->mUnk_5c = a;
                gSelectGame->mUnk_60 = a;
                gSelectGame->mState = 10;
            }
            func_02032940();
            break;
        case 10:
            a = o->mResult;
            break;
    }
    if (gSelectGame->mState != 10) {
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
            func_02124c30(o->mUnk_00[0].mUnk_0c, o->mUnk_00[0].mUnk_08, o->mUnk_00[0].mUnk_14, gSelectGame->mUnk_38,
                          o->mUnk_00[0].mUnk_18);
        }
        func_02124c30(q->mUnk_0c, q->mUnk_08, q->mUnk_14, gSelectGame->mUnk_3c, q->mUnk_18);
    }
    return a;
}

void ReleaseSelectGame(void) {
    if (gSelectGame->mMode == 1) {
        func_0202b604();
        if (data_021759d0->mUnk_1c_2 != 0) {
            func_020cee5c();
        }
    }
    HeapDestroy(gSelectGame->mHeap);
    gSelectGame = NULL;
}

void func_02032138(void) {
    u32 a;
    u32 b;
    s32 y;

    a = 0x18;
    b = 0;
    if (gSelectGame->mState != 10) {
        a |= 2;
        b = 3;
    }
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (a << 8);
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | b;
    reg_G2_BG1OFS = (-gSelectGame->mUnk_60 << 16) & 0x1ff0000;
    if (gSelectGame->mUnk_60 != 0) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x6000;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2_WININ = (u32) ((reg_G2_WININ & 0xffffc0ff) | 0x1f00) | 0x2000;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xd) | 0x20;
        y = gSelectGame->mUnk_60 + 0xc0;
        reg_G2_WIN0H = 0xff;
        reg_G2_WIN0V = y & 0xff;
        y = gSelectGame->mUnk_60 + 0xc0;
        reg_G2_WIN1H = 0xff00;
        reg_G2_WIN1V = y & 0xff;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    }
}

void LoadSelectGameData(void) {
    Ncgr *a;
    Nclr *b;
    Unk02021dc8 *c;
    Nscr *d;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        LoadNcgrData(&a, FindSceneFile(gSelectGameMBNcgrName));
        LoadNcgrData2(&a, FindSceneFile(gSelectGameMNceNcgrName));
        LoadNcerData(&c, FindSceneFile(gSelectGameMNceNcerName));
        LoadNclrData(&b, FindSceneFile(gSelectGameMBNclrName));
        LoadNclrData(&b, FindSceneFile(gSelectGameMONclrName));
        LoadNscrData(&d, FindSceneFile(gSelectGameMMultiNscrName));
        LoadNscrData(&d, FindSceneFile(gSelectGameMSingleNscrName));
    }
    LoadNcgrData2(&a, FindSceneFile(gSelectGameSNceNcgrName));
    LoadNcerData(&c, FindSceneFile(gSelectGameSNceNcerName));
    LoadNclrData(&b, FindSceneFile(gSelectGameSONclrName));
}

#pragma thumb off

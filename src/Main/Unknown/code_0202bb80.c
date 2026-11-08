#include "Main/Unknown/code_0202bb80.h"

#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_0202cc78.h"
#include "Main/Unknown/code_0202cca0.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_02120294.h"
#include "Main/Unknown/code_02121e24.h"
#include "Main/Unknown/code_02122734.h"
#include "Main/Unknown/code_02122794.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "code_0213ecf8.h"
#include "code_02016468.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_0202056c.h"
#include "registers.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02025e28.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02025f80.h"

#pragma thumb on

void func_0202cc44(s32 a, s32 b) {
    data_02174e3c->mUnk_04c[a].mUnk_04.mUnk_00 = 10;
    data_02174e3c->mUnk_04c[a].mUnk_04.mUnk_0c = b;
    data_02174e3c->mUnk_04c[a].mUnk_04.mUnk_04 = data_02174e3c->mUnk_04c[a].mUnk_04.mUnk_0c;
    data_02174e3c->mUnk_04c[a].mUnk_04.mUnk_08 = data_02174e3c->mUnk_04c[a].mUnk_04.mUnk_04;
}

void func_0202cc18(s32 a, s32 b) {
    Unk02174e3c_4c_04 *entry;
    entry = &data_02174e3c->mUnk_04c[a].mUnk_04;
    entry->mUnk_04 = b;
    if (entry->mUnk_04 == entry->mUnk_08) {
        entry->mUnk_08 = entry->mUnk_0c;
        entry->mUnk_0c = entry->mUnk_04;
        entry->mUnk_00 = 10 - entry->mUnk_00;
    }
}

void func_0202cbf4(void) {
    s32 i;
    i = 0;
    do {
        func_0202cc44(i, 0);
        func_0202cc18(i, 1);
        i++;
    } while (i < 8);
}

#pragma thumb off

#pragma thumb on

void func_0202cba4(void) {
    s32 i;
    Unk02174e3c_4c_04 *p;
    for (i = 0; i < 8; i++) {
        p = &data_02174e3c->mUnk_04c[i].mUnk_04;
        if (p->mUnk_00 < 10) {
            p->mUnk_00++;
        } else if (p->mUnk_04 != p->mUnk_0c) {
            p->mUnk_00 = 0;
            p->mUnk_08 = p->mUnk_0c;
            if (p->mUnk_04 > p->mUnk_0c) {
                p->mUnk_0c++;
            } else {
                p->mUnk_0c--;
            }
        }
    }
}

void func_0202cb68(s32 a) {
    switch (data_02174e3c->mUnk_04c[a].mUnk_04.mUnk_04) {
        case 0:
            func_0202cc18(a, 1);
            break;
        case 3:
            func_0202cc18(a, 2);
            break;
    }
}

void func_0202cb2c(s32 a) {
    switch (data_02174e3c->mUnk_04c[a].mUnk_04.mUnk_04) {
        case 1:
            func_0202cc18(a, 0);
            break;
        case 2:
            func_0202cc18(a, 3);
            break;
    }
}

#pragma thumb off

static inline s32 func_0202bb80_inline(s32 i) {
    return data_0217b488->mShuffledIndices[i];
}

#pragma thumb on

void func_0202c960(void) {
    Unk02174e3c *p = data_02174e3c;
    Unk02174e14_00 *q = &p->mUnk_000;
    s32 i;
    s32 n = q->mCellLayout->mUnk_06;
    s32 c;
    s32 d;
    s16 w;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        AdvanceInterpolation(&data_02174e3c->mUnk_210[0]);
        q->mCellTable[25].mUnk_06 = GetInterpolatedValue(&data_02174e3c->mUnk_210[0]);
        AdvanceInterpolation(&data_02174e3c->mUnk_210[3]);
        q->mCellTable[64].mUnk_06 = GetInterpolatedValue(&data_02174e3c->mUnk_210[3]);
        q->mCellTable[63].mUnk_06 = q->mCellTable[64].mUnk_06;
        q->mCellTable[62].mUnk_06 = q->mCellTable[63].mUnk_06;
        q->mCellTable[61].mUnk_06 = q->mCellTable[62].mUnk_06;
        q->mCellTable[60].mUnk_06 = q->mCellTable[61].mUnk_06;
        q->mCellTable[59].mUnk_06 = q->mCellTable[60].mUnk_06;
    }
    AdvanceInterpolation(&data_02174e3c->mUnk_210[1]);
    w = GetInterpolatedValue(&data_02174e3c->mUnk_210[1]);
    c = func_0202cc78();
    q->mCellTable[c].mUnk_04 = w;
    q->mCellTable[func_0202cc8c()].mUnk_04 = q->mCellTable[c].mUnk_04;
    AdvanceInterpolation(&data_02174e3c->mUnk_210[2]);
    func_0202cba4();
    for (i = 0; i < 8; i++) {
        w = InterpolateS16(1, data_usa_02153aa4[data_02174e3c->mUnk_04c[i].mUnk_04.mUnk_08],
                           data_usa_02153aa4[data_02174e3c->mUnk_04c[i].mUnk_04.mUnk_0c],
                           data_02174e3c->mUnk_04c[i].mUnk_04.mUnk_00, 10);
        q->mCellTable[n + data_usa_02174e14[i].mUnk_00].mUnk_04 = w;
        q->mCellTable[data_usa_02174e0c[i].mUnk_04].mUnk_04 = q->mCellTable[n + data_usa_02174e14[i].mUnk_00].mUnk_04;
        q->mCellTable[data_usa_02174e0c[i].mUnk_02].mUnk_04 = q->mCellTable[data_usa_02174e0c[i].mUnk_04].mUnk_04;
        q->mCellTable[data_usa_02174e0c[i].mUnk_00].mUnk_04 = q->mCellTable[data_usa_02174e0c[i].mUnk_02].mUnk_04;
        if (i == data_02174e3c->mUnk_044) {
            q->mCellTable[func_0202cca0()].mUnk_04 = w;
        }
    }
}

static inline void func_0202c0d4_inline(const void *a, void *b, s32 c) {
    MIi_CpuCopy16(a, b, c);
}

void func_0202c8dc(void) {
    void *h = GetBmgEntry(func_020b47cc(data_usa_02162c58), 0x72);
    u16 u[3];
    u16 *w = &u[1];
    s32 i;
    w[0] = 0;
    w[1] = 0;
    for (i = data_02174e3c->mPlayerCount; i < 8; i++) {
        u[0] = 0;
        MIi_CpuClear16(u[0], data_02174e3c->mUnk_04c[i].mName, 0x16);
        MIi_CpuCopy16(h, data_02174e3c->mUnk_04c[i].mName, 0x14);
        u[1] = i + 0x31 - data_02174e3c->mPlayerCount;
        wcsncat(data_02174e3c->mUnk_04c[i].mName, w, 1);
    }
}

void PrintEntryName(s32 a, u16 *b) {
    Unk02174e3c *p = data_02174e3c;
    u16 v1[12];
    v1[0] = 0;
    MIi_CpuClear16(v1[0], &v1[1], 0x16);
    b[10] = 0;
    func_020adc7c(b, &v1[1]);
    func_0212426c(0, data_usa_02174e14[a].mUnk_00, p->mUnk_000.mLabelLayout, &v1[1], p->mUnk_000.mCellLayout,
                  p->mUnk_000.mCellTable);
}

void func_0202c65c(void *a, void *b) {
    void *h = CreateFrmHeapFromMaxFree(a);
    s32 r;
    Unk02174e14_00 *q;
    s32 i;
    data_02174e3c = HeapAlloc(h, 0x258);
    MemFillWordsByBlock_inline(data_02174e3c, 0x258);
    data_02174e3c->mHeap = h;
    data_02174e3c->mUnk_038 = b;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        data_usa_02174e0c = data_usa_02153b3c;
        data_usa_02174e14 = data_usa_02153bac;
        data_usa_02174e10 = data_usa_02153ad4;
        data_usa_02174e18 = data_usa_02153ac0;
    } else {
        data_usa_02174e0c = data_usa_02153b0c;
        data_usa_02174e14 = data_usa_02153b6c;
        data_usa_02174e10 = data_usa_02153af0;
        data_usa_02174e18 = data_usa_02153aac;
    }
    r = GX_GetSizeOfOBJ();
    q = &data_02174e3c->mUnk_000;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        LocateCellFileSet(q, data_usa_02162aac, data_usa_02162ad4, data_usa_02162afc, gSelectMenuEtcDownloadMBnclName,
                          gSelectMenuEtcDownloadMBnllName, NULL, FindSceneFile);
    } else {
        LocateCellFileSet(q, data_usa_02162b6c, data_usa_02162b88, data_usa_02162ba4, gSelectMenuEtcMBnclName,
                          gSelectMenuEtcMBnllName, NULL, FindFileInLoadedArchives);
    }
    InitLayoutTable(data_02174e3c->mHeap, q->mCellLayout, q->mLabelLayout, &q->mCellTable);
    for (i = 0; i < 8; i++) {
        r -= func_02025a00(0, data_02174e3c->mHeap, q, &data_usa_02174e14[i], r);
    }
    for (i = 0; i < 8; i++) {
        q->mCellTable[data_usa_02174e0c[i].mUnk_04].mUnk_00 = 0;
        q->mCellTable[data_usa_02174e0c[i].mUnk_02].mUnk_00 = q->mCellTable[data_usa_02174e0c[i].mUnk_04].mUnk_00;
    }
    func_0202cbf4();
    SetupInterpolation(&data_02174e3c->mUnk_210[0], 0, 10, -0x40, 0);
    SetupInterpolation(&data_02174e3c->mUnk_210[2], 3, 10, 0x60, 0);
    SetupInterpolation(&data_02174e3c->mUnk_210[3], 3, 10, 0x40, 0);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        LocateCellFileSet(&data_02174e3c->mUnk_01c, data_usa_02162bf0, data_usa_02162c14, NULL,
                          gSelectMenuEtcTitleMBnclName, NULL, NULL, FindFileInLoadedArchives);
    }
    data_02174e3c->mUnk_1fc = TRUE;
    FrmHeapShrinkInParent(data_02174e3c->mHeap);
}

void func_0202c0d4(s32 a, s32 b) {
    Unk02174e3c *p = data_02174e3c;
    Unk02174e14_00 *q = &p->mUnk_000;
    Unk02174e14_00 *r = &p->mUnk_01c;
    s32 n;
    s32 i;
    s32 j;
    BOOL t;
    s32 d;
    vu16 v;
    vu16 v2;
    u8 v1[0x24];
    p->mUnk_250 = a;
    data_02174e3c->mUnk_254 = b;
    if (data_02174e3c->mUnk_1fc != FALSE) {
        data_02174e3c->mTimer = 0x708;
        SetupInterpolation(&data_02174e3c->mUnk_210[1], 0, 10, 0x40, 0);
        switch (data_02174e3c->mUnk_250) {
            case 0:
                data_02174e3c->mPlayerCount = 1;
                data_02174e3c->mUnk_044 = 0;
                data_02174e3c->mUnk_208 = 1;
                MIi_CpuCopy16(data_0217aa08->mUnk_00->mUnk_0c, data_02174e3c->mUnk_04c[data_02174e3c->mUnk_044].mName,
                              0x14);
                func_0202c8dc();
                break;
            case 1:
                t = TRUE;
                if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
                    t = FALSE;
                }
                if (t != FALSE) {
                    i = CountSetBits(data_0217aa00->mParticipantMask);
                } else {
                    i = 0;
                }
                data_02174e3c->mPlayerCount = (u8) i;
                if (data_0217aa00->mUnk_0000 == 2) {
                    i = data_0217aa00->mOwnIndex;
                } else {
                    i = 0;
                }
                data_02174e3c->mUnk_044 = data_0217aa00->mUnk_1e52[(u16) i].mEntryIndex;
                for (j = 0; j < (n = data_02174e3c->mPlayerCount); j++) {
                    GetRaceSetupCopy()->mEntries[j].mPlayerKind = PLAYER_KIND_HUMAN;
                    v = 0;
                    MIi_CpuClear16(v, data_02174e3c->mUnk_04c[j].mName, 0x16);
                    func_0202c0d4_inline(data_0217aa00->mUnk_1e8c[(u16) j] == 0xffff
                                             ? (void *) 0
                                             : &data_0217aa00->mUnk_045c[data_0217aa00->mUnk_1e8c[(u16) j]],
                                         data_02174e3c->mUnk_04c[j].mName, 0x14);
                }
                for (; n < 8; n++) {
                    func_0202cc18(n, 0);
                }
                func_0202c8dc();
                for (i = 0; i < 8; i++) {
                    data_02174e3c->mUnk_1dc[i] = 0;
                    data_02174e3c->mUnk_1bc[i] = data_02174e3c->mUnk_1dc[i];
                }
                break;
            case 2:
                data_02174e3c->mPlayerCount = func_020295d0();
                data_02174e3c->mUnk_044 = func_020295e4();
                for (i = 0; i < (n = data_02174e3c->mPlayerCount); i++) {
                    v2 = 0;
                    MIi_CpuClear16(v2, data_02174e3c->mUnk_04c[i].mName, 0x16);
                    if (GetIndexOfPackedIndex(i) >= 0) {
                        func_0202c0d4_inline(func_021202b0((u8) GetIndexOfPackedIndex(i)),
                                             data_02174e3c->mUnk_04c[i].mName, 0x14);
                    }
                }
                for (; n < 8; n++) {
                    func_0202cc18(n, 0);
                }
                for (i = 0; i < 4; i++) {
                    data_02174e3c->mUnk_1ac[i] = 0;
                }
                for (i = 0; i < 8; i++) {
                    data_02174e3c->mUnk_1dc[i] = 0;
                    data_02174e3c->mUnk_1bc[i] = data_02174e3c->mUnk_1dc[i];
                }
                break;
        }
    }
    if (data_02174e3c->mUnk_254 == 2) {
        for (i = 0; i < 8; i++) {
            q->mCellTable[data_usa_02174e0c[i].mUnk_04].mUnk_00 = 0;
        }
        if (data_02174e3c->mUnk_250 == 1) {
            for (i = data_02174e3c->mPlayerCount; i < 8; i++) {
                j = GetRaceSetupCopy()->mEntries[i].mCharacterIndex;
                func_02025c48(data_usa_02174e0c[i].mUnk_02, data_usa_02174e10[j], q->mCellLayout);
                q->mCellTable[data_usa_02174e0c[i].mUnk_02].mUnk_00 = 1;
            }
        }
        reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0xd08;
        reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0xc00;
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
            func_020258d4(0, v1, data_usa_02162904, data_usa_0216292c, data_usa_02162954, 0, FindSceneFile);
            func_020258d4(0, v1, data_usa_02162980, data_usa_021629a8, data_usa_021629d0, 1, FindSceneFile);
        } else {
            func_020258d4(0, v1, data_usa_021629fc, data_usa_02162a18, data_usa_02162a34, 0, FindFileInLoadedArchives);
            func_020258d4(0, v1, data_usa_02162a54, data_usa_02162a70, data_usa_02162a8c, 1, FindFileInLoadedArchives);
        }
    } else if (data_02174e3c->mUnk_254 == 1) {
        func_02025f14(&data_02174e3c->mUnk_210[3], 0);
    }
    if (data_02174e3c->mUnk_20c != FALSE) {
        for (i = 0; i < 8; i++) {
            if (i < data_02174e3c->mPlayerCount || data_02174e3c->mUnk_208 != 0) {
                func_0202cb68(i);
            }
        }
        data_02174e3c->mUnk_20c = FALSE;
    }
    CallQueueAppend(0x13, 0, ((Unk02174e3c_00 *) data_02174e3c->mUnk_000.mChars)->mUnk_14,
                    ((Unk02174e3c_00 *) data_02174e3c->mUnk_000.mChars)->mUnk_10);
    CallQueueAppend(0xe, 0, ((Unk0212463c_d *) q->mPalette)->mUnk_0c, 0x1a0);
    CallQueueAppend(0xe, 0x1c0, ((Unk0212463c_d *) q->mPalette)->mUnk_0c + 0x1c0, 0x40);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_02124748(data_usa_02153a9c[data_02174e3c->mUnk_254], r->mCells, r->mChars, r->mCellLayout, 0, 0x19,
                      q->mCells, q->mCellLayout);
        func_02025f14(&data_02174e3c->mUnk_210[0], 0);
    }
    func_02025c6c(func_0202cca0(), data_usa_02174e0c[data_02174e3c->mUnk_044].mUnk_00, q->mCellLayout);
    for (i = 0; i < 8; i++) {
        PrintEntryName(i, data_02174e3c->mUnk_04c[i].mName);
    }
    SetupInterpolation(&data_02174e3c->mUnk_210[2], 3, 10, 0x60, 0);
    data_02174e3c->mUnk_204 = 0;
    n = 0;
    if (data_02174e3c->mUnk_254 != 2 && data_02174e3c->mUnk_250 != 0) {
        n = 1;
    }
    data_02174e3c->mUnk_200 = n;
    d = func_0202cc78();
    q->mCellTable[d].mUnk_00 = data_02174e3c->mUnk_200;
    q->mCellTable[func_0202cc8c()].mUnk_00 = q->mCellTable[d].mUnk_00;
    data_02174e3c->mUnk_1fc = FALSE;
}

void func_0202bb80(void) {
    Unk02174e14_00 *q = &data_02174e3c->mUnk_000;
    Unk02174e3c *t;
    s32 i;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    BOOL g;
    if (AreBrightnessFadesClear() == 0) {
        return;
    }
    if (data_02174e3c->mUnk_200 != 0) {
        if (data_02174e3c->mTimer != 0) {
            data_02174e3c->mTimer--;
            a = data_02174e3c->mTimer;
            b = a + 0x3c;
            c = b / 0x3c;
            if (a == 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x51);
            } else if (b % 0x3c == 0 && c <= 4) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x50);
            }
        } else {
            c = 0;
        }
        d = func_0202cc8c();
        q->mCellTable[d].mUnk_00 = c >= 10 ? 1 : 0;
        d = func_0202cc8c();
        func_02025c48(d, data_usa_02174e18[c / 10 % 10], q->mCellLayout);
        d = func_0202cc78();
        func_02025c48(d, data_usa_02174e18[c % 10], q->mCellLayout);
    }
    t = data_02174e3c;
    if (t->mUnk_254 != 2) {
        switch (t->mUnk_250) {
            case 0: {
                s32 a;
                s32 b;

                for (i = 0; i < 8; i++) {
                    a = GetRaceSetupCopy()->mEntries[i].mCharacterIndex;
                    if (a == -1) {
                        d = 0;
                    } else {
                        d = 1;
                    }
                    b = GetRaceSetupCopy()->mEntries[i].mUnk_14;
                    if (d != 0) {
                        func_02025c48(data_usa_02174e0c[i].mUnk_02, data_usa_02174e10[a], q->mCellLayout);
                    }
                    q->mCellTable[data_usa_02174e0c[i].mUnk_02].mUnk_00 = d;
                    q->mCellTable[data_usa_02174e0c[i].mUnk_04].mUnk_00 = b;
                }
            } break;
            case 1: {
                s32 d;

                for (i = 0; i < data_02174e3c->mPlayerCount; i++) {
                    if (data_0217aa00->mUnk_0004 == 8 &&
                        (data_0217aa00->mParticipantMask & (1 << data_0217aa00->mUnk_1e8c[(u16) i])) != 0) {
                        c = data_0217aa00->mUnk_15c8[data_0217aa00->mUnk_1e8c[(u16) i]].mUnk_00[5];
                    } else {
                        c = 0;
                    }
                    if (c == 0xff) {
                        q->mCellTable[data_usa_02174e0c[i].mUnk_04].mUnk_00 = 0;
                        q->mCellTable[data_usa_02174e0c[i].mUnk_02].mUnk_00 =
                            q->mCellTable[data_usa_02174e0c[i].mUnk_04].mUnk_00;
                        GetRaceSetupCopy()->mEntries[i].mCharacterIndex = -1;
                        GetRaceSetupCopy()->mEntries[i].mKartIndex = -1;
                        GetRaceSetupCopy()->mEntries[i].mUnk_14 = 0;
                        data_02174e3c->mUnk_1dc[i] = 0;
                        data_02174e3c->mUnk_1bc[i] = data_02174e3c->mUnk_1dc[i];
                    } else if ((c & 0x40) != 0) {
                        d = c & 0x3f;
                        if (d == 0xc) {
                            func_02025c48(data_usa_02174e0c[i].mUnk_02, data_usa_02174e10[d] + func_0202bb80_inline(i),
                                          q->mCellLayout);
                        } else {
                            func_02025c48(data_usa_02174e0c[i].mUnk_02, data_usa_02174e10[d], q->mCellLayout);
                        }
                        q->mCellTable[data_usa_02174e0c[i].mUnk_02].mUnk_00 = 1;
                        GetRaceSetupCopy()->mEntries[i].mCharacterIndex = d;
                        if (data_02174e3c->mUnk_044 != i && data_02174e3c->mUnk_1bc[i] == 0) {
                            func_0202cca4(d, 0);
                            data_02174e3c->mUnk_1bc[i] = 1;
                        }
                        if ((c & 0x80) != 0) {
                            e = func_02025e60(d);
                            q->mCellTable[data_usa_02174e0c[i].mUnk_04].mUnk_00 = 1;
                            GetRaceSetupCopy()->mEntries[i].mKartIndex = e;
                            GetRaceSetupCopy()->mEntries[i].mUnk_14 = 1;
                        }
                    } else if ((c & 0x80) != 0) {
                        q->mCellTable[data_usa_02174e0c[i].mUnk_04].mUnk_00 = 1;
                        GetRaceSetupCopy()->mEntries[i].mKartIndex = c & 0x3f;
                        GetRaceSetupCopy()->mEntries[i].mUnk_14 = 1;
                        if (data_02174e3c->mUnk_044 != i && data_02174e3c->mUnk_1dc[i] == 0) {
                            func_0202cca4(GetRaceSetupCopy()->mEntries[i].mCharacterIndex, 1);
                            data_02174e3c->mUnk_1dc[i] = 1;
                        }
                    }
                }
            } break;
            case 2: {
                s32 e;

                for (i = 0; i < data_02174e3c->mPlayerCount; i++) {
                    if (GetKartMaskBitOfPackedIndex(i) == 0) {
                        func_02025c48(data_usa_02174e0c[i].mUnk_02, 0x2e, q->mCellLayout);
                        q->mCellTable[data_usa_02174e0c[i].mUnk_02].mUnk_00 = 1;
                        q->mCellTable[data_usa_02174e0c[i].mUnk_04].mUnk_00 = 0;
                        if (data_02174e3c->mUnk_1ac[i] == 0) {
                            data_02174e3c->mUnk_1ac[i] = 1;
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x52);
                        }
                    } else {
                        e = GetWiFiSessionCharacterIndex((u8) GetIndexOfPackedIndex(i));
                        f = GetWiFiSessionKartIndex((u8) GetIndexOfPackedIndex(i));
                        if (e == -1) {
                            d = 0;
                        } else {
                            d = 1;
                        }
                        if (f == -1) {
                            g = FALSE;
                        } else {
                            g = TRUE;
                        }
                        if (d != 0) {
                            func_02025c48(data_usa_02174e0c[i].mUnk_02, data_usa_02174e10[e], q->mCellLayout);
                        }
                        q->mCellTable[data_usa_02174e0c[i].mUnk_02].mUnk_00 = d;
                        q->mCellTable[data_usa_02174e0c[i].mUnk_04].mUnk_00 = g;
                        if (data_02174e3c->mUnk_044 != i) {
                            if (data_02174e3c->mUnk_1bc[i] == 0 && d != 0) {
                                func_0202cca4(e, 0);
                                if (g != FALSE) {
                                    data_02174e3c->mUnk_1dc[i] = 1;
                                }
                            } else if (data_02174e3c->mUnk_1dc[i] == 0 && g != FALSE) {
                                func_0202cca4(e, 1);
                            }
                            data_02174e3c->mUnk_1bc[i] = d;
                            data_02174e3c->mUnk_1dc[i] = g;
                        }
                    }
                }
            } break;
        }
    }
    func_0202c960();
    DrawLayoutTable(q->mCellLayout, q->mCells, q->mLabelLayout, data_02174e3c->mUnk_038, q->mCellTable);
}

#pragma thumb off

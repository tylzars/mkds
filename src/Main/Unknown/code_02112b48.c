#include "Main/Unknown/code_02112b48.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02076cd0.h"

#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_021113f0.h"
#include "Main/Unknown/code_0211130c.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_02113790.h"
#include "Main/Unknown/code_0211398c.h"
#include "Main/Unknown/code_021139b4.h"
#include "Main/Unknown/code_02113f34.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0212426c.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02181f98.h"
#include "code_0212df7c.h"
#include "code_0214d018.h"
#include "registers.h"
#include "Main/Unknown/code_021137a8.h"
#include "Main/Unknown/code_02113f1c.h"
#include "Main/Unknown/code_021138e4.h"
#include "Main/Unknown/code_02113ef0.h"
#include "code_02016468.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02114504.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_021144b4.h"
#include "Main/Unknown/code_021144c0.h"
#include "01/code_021956dc.h"

#pragma thumb on

// Combines the entry's three bytes into one number to order entries by.
u16 GetRecordSortKey(u16 a) {
    DateBytes w;

    func_021142d4((u8) a, &w);
    return w.mYear * 0x1a0 + w.mMonth * 32 + w.mDay;
}

// Orders b entries from index a by descending key.
void SortRecordRange(s32 a, u16 b) {
    s32 i;
    s32 j;
    s32 n;
    u16 p;
    s32 e;
    RecordListEntry t;
    u32 m;
    u16 v;
    RecordListEntry *q;

    p = 0;
    n = a + b;
    e = n - 1;
    for (i = a; i < e; i++) {
        m = 0;
        for (j = i; j < n; j++) {
            v = GetRecordSortKey(j);
            if (m < v) {
                m = v;
                p = j;
            }
        }
        for (j = p; j > i; j--) {
            q = gRecordList->mUnk_04 + j - 1;
            t = *q;
            *q = gRecordList->mUnk_04[j];
            gRecordList->mUnk_04[j] = t;
        }
    }
}

#pragma thumb off

#pragma thumb on

void CreateRecordList(void *a) {
    int v1;
    void *v2;
    v1 = ((u32) HeapAlloc(a, 0x10));
    *(s32 *) &gRecordList = v1;
    v2 = HeapAlloc(a, 0x78);
    gRecordList->mUnk_04 = v2;
    v2 = CreateEmblemBlock(a);
    gRecordList->mEmblemBlock = v2;
    v2 = FindSceneFile(gEmblem2BinName);
    gRecordList->mUnk_0c = v2;
}

#pragma thumb off

#pragma thumb on
void ClearRecordListPointer(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &gRecordList;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on

// Fills the table with the used slots, flagged ones first, each group ordered by key.
void BuildRecordList(void) {
    s32 i;
    u16 a;
    s32 b;
    s32 c;

    a = 0;
    gRecordList->mUnk_00 = 0;
    for (i = 0; i < 0x3c; i++) {
        if (IsBuddyRecordFilled(i)) {
            gRecordList->mUnk_00++;
            if (IsBuddyRecordFlagged(i)) {
                a++;
            }
        }
    }
    if (gRecordList->mUnk_00 != 0) {
        b = 0;
        c = a;
        for (i = 0; i < 0x3c; i++) {
            if (IsBuddyRecordFilled(i)) {
                if (IsBuddyRecordFlagged(i)) {
                    gRecordList->mUnk_04[b].mUnk_00 = (u8) i;
                    b++;
                } else {
                    gRecordList->mUnk_04[c].mUnk_00 = (u8) i;
                    c++;
                }
            }
        }
        SortRecordRange(0, a);
        SortRecordRange(a, gRecordList->mUnk_00 - a);
    }
}

u16 GetRecordCount(void) {
    s32 i;
    u16 n;

    n = 0;
    if (gRecordList == NULL) {
        for (i = 0; i < 0x3c; i++) {
            if (IsBuddyRecordFilled(i)) {
                n++;
            }
        }
        return n;
    }
    return gRecordList->mUnk_00;
}

s32 IsRecordFlagged(u16 a) {
    return IsBuddyRecordFlagged(gRecordList->mUnk_04[a].mUnk_00);
}

s32 func_0211437c(u16 a) {
    return func_02060ac8(gRecordList->mUnk_04[a].mUnk_00);
}

s32 func_02114360(u16 a) {
    return func_02060a60(gRecordList->mUnk_04[a].mUnk_00);
}

s32 func_02114344(u16 a) {
    return func_020609f8(gRecordList->mUnk_04[a].mUnk_00);
}

s32 func_02114328(u16 a) {
    return func_02060a94(gRecordList->mUnk_04[a].mUnk_00);
}

s32 func_0211430c(u16 a) {
    return func_02060a2c(gRecordList->mUnk_04[a].mUnk_00);
}

s32 func_021142f0(u16 a) {
    return func_020609c4(gRecordList->mUnk_04[a].mUnk_00);
}

s32 func_021142d4(u16 a, void *b) {
    return GetBuddyRecordDate(gRecordList->mUnk_04[a].mUnk_00, b);
}

void CopyRecordText(u16 a, void *b, u32 c) {
    u8 t[0x14];

    GetBuddyRecordName(gRecordList->mUnk_04[a].mUnk_00, t);
    MI_CpuFill8(b, 0, c);
    MIi_CpuCopy16(t, b, 0x14);
}

s32 SetRecordFlag(u16 a) {
    return SetBuddyRecordFlag(gRecordList->mUnk_04[a].mUnk_00, 1);
}

s32 ClearRecordFlag(u16 a) {
    return SetBuddyRecordFlag(gRecordList->mUnk_04[a].mUnk_00, 0);
}

// Reads the slot's emblem into b, uses the emblem2.bin picture when it has none, and converts the pixels into c.
void ReadRecordEmblem(u16 a, EmblemData *b, void *c) {
    u8 d;

    SetupEmblemBlock(gRecordList->mEmblemBlock, gRecordList->mUnk_04[a].mUnk_00);
    d = data_0217aa08->mUnk_28;
    do {
    } while (d == 0 ? (data_021759d4->mBackupEnabled != 0 ? data_021759d4->mUnk_10 : 0) : 1);
    if (!CopyEmblemFromBlock(gRecordList->mEmblemBlock, gRecordList->mUnk_04[a].mUnk_00, b) || b->mUnk_200 == 0) {
        b->mUnk_200 = 1;
        MIi_CpuCopyFast(gRecordList->mUnk_0c, b, 0x200);
    }
    func_020ac2fc(b, c, 0x20);
}

// Empties the slot and rebuilds the list.
void EraseRecord(u16 a) {
    u8 d;

    RemoveBuddyRecord(gRecordList->mUnk_04[a].mUnk_00);
    d = data_0217aa08->mUnk_28;
    do {
    } while (d == 0 ? (data_021759d4->mBackupEnabled != 0 ? data_021759d4->mUnk_10 : 0) : 1);
    BuildRecordList();
}

// Writes the entry's friend key as digits into b; returns TRUE only for a used entry with valid friend data.
s32 GetRecordFriendKeyText(u16 a, void *b) {
    return GetBuddyFriendKeyText(gRecordList->mUnk_04[a].mUnk_00, b);
}

#pragma thumb off

#pragma thumb on

void LocateAndQueueRecordVS(void) {
    void *v1;
    Nclr *v2;
    u16 *v3;
    Nclr *v4;
    Ncgr *v5;
    Nscr *v6;
    Nclr *v7;
    Nclr *v8;
    v4 = NULL;
    v5 = NULL;
    v6 = NULL;
    v7 = NULL;
    v8 = NULL;
    v1 = FindSceneFile(gRecordVSMNcgrName);
    LocateNcgr2(&gRecordVS->mRecordVSMNcgr, v1);
    v1 = FindSceneFile(gRecordVSMNcerName);
    LocateNcer(&gRecordVS->mRecordVSMNcer, v1);
    v1 = FindSceneFile(gRecordVSMONclrName);
    LocateNclr(&v4, v1);
    v1 = FindSceneFile(gRecordVSMBnclName);
    gRecordVS->mRecordVSMBncl = v1;
    v1 = FindSceneFile(gRecordVSMBnllName);
    gRecordVS->mRecordVSMBnll = v1;
    v1 = FindSceneFile(gRecordVSMTransientBnclName);
    gRecordVS->mRecordVSMTransientBncl = v1;
    v1 = FindSceneFile(gRecordVSMTransientBnllName);
    gRecordVS->mRecordVSMTransientBnll = v1;
    v1 = FindSceneFile(gRecordVSSNcgrName);
    LocateNcgr2(&gRecordVS->mRecordVSSNcgr, v1);
    v1 = FindSceneFile(gRecordVSSNcerName);
    LocateNcer(&gRecordVS->mRecordVSSNcer, v1);
    v1 = FindSceneFile(gRecordVSSONclrName);
    LocateNclr(&v8, v1);
    v1 = FindSceneFile(gRecordVSSBnclName);
    gRecordVS->mRecordVSSBncl = v1;
    v1 = FindSceneFile(gRecordVSSBnblName);
    gRecordVS->mRecordVSSBnbl = v1;
    v1 = FindSceneFile(gRecordVSSBnllName);
    gRecordVS->mRecordVSSBnll = v1;
    v2 = GetEmblemSBNclr();
    v1 = FindSceneFile(gRecordVSMBNcgrName);
    LocateNcgr(&v5, v1);
    v1 = FindSceneFile(gRecordVSMNscrName);
    LocateNscr(&v6, v1);
    v1 = FindSceneFile(gRecordVSM02NscrName);
    LocateNscr(&gRecordVS->mRecordVSM02Nscr, v1);
    v1 = FindSceneFile(gRecordVSM03NscrName);
    LocateNscr(&gRecordVS->mRecordVSM03Nscr, v1);
    v1 = FindSceneFile(gRecordVSMBNclrName);
    LocateNclr(&v7, v1);
    v3 = v4->mData;
    CallQueueAppend(0x13, 0, (gRecordVS->mRecordVSMNcgr->mData), gRecordVS->mRecordVSMNcgr->mDataSize);
    CallQueueAppend(0xe, 0, v4->mData, (0x000001a0u));
    CallQueueAppend(0xe, 0x1c0, v3 + 0xe0, 0x40);
    CallQueueAppend(0x23, 0, (gRecordVS->mRecordVSSNcgr->mData), gRecordVS->mRecordVSSNcgr->mDataSize);
    CallQueueAppend(0x1e, 0, v8->mData, v8->mDataSize);
    CallQueueAppend(4, 0, v5->mData, v5->mDataSize);
    CallQueueAppend(8, 0, v6->mData, v6->mDataSize);
    CallQueueAppend(0xf, 0, v7->mData, 0x40);
    CallQueueAppend(0xe, 0x40, v2->mData, 0x20);
}

#pragma thumb off

#pragma thumb on

u16 GetRecordVSFirstRecordIndex(void) {
    return gRecordVS->mPageIndex * 5;
}

#pragma thumb off

#pragma thumb on

u32 IsRecordVSRowFilled(int a) {
    int v1;
    int v2;
    v1 = GetRecordVSFirstRecordIndex();
    v2 = GetRecordCount();
    if (v2 > v1 + a) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

// Shows or hides the objects of the five rows and of each row's flag.
void AdvanceRecordVSRowObjects(void) {
    s32 i;
    u16 a;
    u16 b;

    b = gRecordVS->mRecordVSSBncl->mUnk_06;
    a = GetRecordVSFirstRecordIndex();
    for (i = 0; i < 5; i++) {
        gRecordVS->mRecordVSSTable[data_0215c3e0[i]].mUnk_00 = 0;
        gRecordVS->mRecordVSSTable[data_0215c3ec[i]].mUnk_00 = 0;
        gRecordVS->mRecordVSSTable[data_0215c3f8[i]].mUnk_00 = 0;
        gRecordVS->mRecordVSSTable[data_0215c404[i]].mUnk_00 = 0;
        gRecordVS->mRecordVSSTable[b + data_0215c3bc[i]].mUnk_00 = 0;
    }
    for (i = 0; i < 5; i++) {
        if (IsRecordVSRowFilled((s16) i)) {
            if (gRecordVS->mIndex == i) {
                gRecordVS->mRecordVSSTable[data_0215c3ec[i]].mUnk_00 = 1;
                func_02124100(data_0215c3bc[i], 0xe, gRecordVS->mRecordVSSBnll, gRecordVS->mRecordVSSTable,
                              gRecordVS->mRecordVSSBncl);
            } else {
                gRecordVS->mRecordVSSTable[data_0215c3e0[i]].mUnk_00 = 1;
                func_02124100(data_0215c3bc[i], 0xf, gRecordVS->mRecordVSSBnll, gRecordVS->mRecordVSSTable,
                              gRecordVS->mRecordVSSBncl);
            }
            gRecordVS->mRecordVSSTable[data_0215c3f8[i]].mUnk_00 = !IsRecordFlagged(a + i);
            gRecordVS->mRecordVSSTable[data_0215c404[i]].mUnk_00 = IsRecordFlagged(a + i);
            gRecordVS->mRecordVSSTable[b + data_0215c3bc[i]].mUnk_00 = 1;
        }
    }
}

void PrintRecordVSShownRecord(void) {
    u16 buf[16];
    u32 v[3][3] = {0};
    u8 s[0x14];
    DateBytes w;
    RecordVS *d;
    s32 i;
    s32 j;
    s32 a;

    a = GetRecordVSFirstRecordIndex();
    if (GetRecordFriendKeyText(a + gRecordVS->mShownIndex, s)) {
        gRecordVS->mShowsFriendKey = 1;
        CallQueueAppend(9, 0, &gRecordVS->mRecordVSM03Nscr->mData, gRecordVS->mRecordVSM03Nscr->mDataSize);
    } else {
        gRecordVS->mShowsFriendKey = 0;
        CallQueueAppend(9, 0, &gRecordVS->mRecordVSM02Nscr->mData, gRecordVS->mRecordVSM02Nscr->mDataSize);
    }
    switch (gRecordVS->mShowsFriendKey) {
        case 0:
            CopyRecordText(a + gRecordVS->mShownIndex, buf, 0x20);
            func_0212426c(0, 0, gRecordVS->mRecordVSMBnll, buf, gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable);
            v[1][0] = func_0211437c(a + gRecordVS->mShownIndex);
            v[1][1] = func_02114360(a + gRecordVS->mShownIndex);
            v[1][2] = func_02114344(a + gRecordVS->mShownIndex);
            v[2][0] = func_02114328(a + gRecordVS->mShownIndex);
            v[2][1] = func_0211430c(a + gRecordVS->mShownIndex);
            v[2][2] = func_021142f0(a + gRecordVS->mShownIndex);
            for (i = 1; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (v[i][j] > 9999) {
                        v[i][j] = 9999;
                    }
                }
            }
            func_02124fac(v[1][0], buf);
            func_02124248(0, data_0215c410[1][0], gRecordVS->mRecordVSMBnll, buf, gRecordVS->mRecordVSMBncl,
                          gRecordVS->mRecordVSMTable, 6);
            func_02124fac(v[1][1], buf);
            func_02124248(0, data_0215c410[1][1], gRecordVS->mRecordVSMBnll, buf, gRecordVS->mRecordVSMBncl,
                          gRecordVS->mRecordVSMTable, 6);
            func_02124fac(v[1][2], buf);
            func_02124248(0, data_0215c410[1][2], gRecordVS->mRecordVSMBnll, buf, gRecordVS->mRecordVSMBncl,
                          gRecordVS->mRecordVSMTable, 6);
            func_02124fac(v[2][0], buf);
            func_02124248(0, data_0215c410[2][0], gRecordVS->mRecordVSMBnll, buf, gRecordVS->mRecordVSMBncl,
                          gRecordVS->mRecordVSMTable, 6);
            func_02124fac(v[2][1], buf);
            func_02124248(0, data_0215c410[2][1], gRecordVS->mRecordVSMBnll, buf, gRecordVS->mRecordVSMBncl,
                          gRecordVS->mRecordVSMTable, 6);
            func_02124fac(v[2][2], buf);
            func_02124248(0, data_0215c410[2][2], gRecordVS->mRecordVSMBnll, buf, gRecordVS->mRecordVSMBncl,
                          gRecordVS->mRecordVSMTable, 6);
            func_021142d4(a + gRecordVS->mShownIndex, &w);
            FormatDate(&w, buf);
            func_02124224(0, 0xc, gRecordVS->mRecordVSMBnll, buf, gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable,
                          6);
            ReadRecordEmblem(a + gRecordVS->mShownIndex, gRecordVS->mEmblem, gRecordVS->mEmblemConverted);
            d = gRecordVS;
            CallQueueAppend(0x13, func_0212497c(3, d->mRecordVSMNcer, d->mRecordVSMBncl) << 5, d->mEmblemConverted,
                            0x200);
            break;
        case 1:
            CopyRecordText(a + gRecordVS->mShownIndex, buf, 0x20);
            func_0212426c(0, 0, gRecordVS->mRecordVSMTransientBnll, buf, gRecordVS->mRecordVSMTransientBncl,
                          gRecordVS->mRecordVSMTransientTable);
            for (i = 0; i < 12; i++) {
                func_02124fac(s[i] - 0x30, buf);
                func_0212426c(0, data_0215c478[i], gRecordVS->mRecordVSMTransientBnll, buf,
                              gRecordVS->mRecordVSMTransientBncl, gRecordVS->mRecordVSMTransientTable);
            }
            ReadRecordEmblem(a + gRecordVS->mShownIndex, gRecordVS->mEmblem, gRecordVS->mEmblemConverted);
            d = gRecordVS;
            CallQueueAppend(0x13, func_0212497c(1, d->mRecordVSMNcer, d->mRecordVSMTransientBncl) << 5,
                            d->mEmblemConverted, 0x200);
            break;
    }
}

void RefreshRecordVSPage(void) {
    s32 i;
    s32 a;
    s32 b;
    u8 buf[0x20];

    a = GetRecordVSFirstRecordIndex();
    for (i = 0; i < 5; i++) {
        b = a + i;
        if (GetRecordCount() > b) {
            CopyRecordText(b, buf, 0x20);
            func_0212426c(1, data_0215c3bc[i], gRecordVS->mRecordVSSBnll, buf, gRecordVS->mRecordVSSBncl,
                          gRecordVS->mRecordVSSTable);
        }
    }
    if (GetRecordCount() <= a + gRecordVS->mIndex) {
        gRecordVS->mIndex = GetRecordCount() % 5 - 1;
        gRecordVS->mShownIndex = gRecordVS->mIndex;
    }
    PrintRecordVSShownRecord();
}

#pragma thumb off

#pragma thumb on
u32 IncrementRecordVSPageIndex(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRecordVS;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 106u;
    value0 = *(const s16 *) ((value1) + (value0));
    value0 = (value0) + (1u);
    value1 = (value1) + 106u;
    *(u16 *) ((value1) + 0u) = value0;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 DecrementRecordVSPageIndex(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRecordVS;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 106u;
    value0 = *(const s16 *) ((value1) + (value0));
    value0 = (value0) - (1u);
    value1 = (value1) + 106u;
    *(u16 *) ((value1) + 0u) = value0;
    return value0;
}
#pragma thumb off

#pragma thumb on

void IncrementRecordVSIndex(void) {
    int v1;
    int v2;
    v2 = (gRecordVS->mIndex + 1) * 0x10000 >> 0x10;
    v1 = IsRecordVSRowFilled(v2);
    if ((v1 == 0) || (5 <= v2)) {
        v2 = 0;
    }
    if (gRecordVS->mIndex != v2) {
        NNS_SndArcPlayerStartSeqArc((const void *) (((u32) ((u8 *) &data_0217d068))), 0, 0);
    }
    gRecordVS->mIndex = v2;
}

void DecrementRecordVSIndex(void) {
    int v1;
    int v2;
    int v3;
    int v4;
    v4 = (gRecordVS->mIndex + -1) * 0x10000 >> 0x10;
    if (v4 < 0) {
        v4 = 4;
        v1 = IsRecordVSRowFilled(4);
        if (v1 == 0) {
            v2 = GetRecordCount();
            v3 = (v2) % 5;
            v4 = (v3 + -1) * 0x10000 >> 0x10;
        }
    }
    if (gRecordVS->mIndex != v4) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
    }
    gRecordVS->mIndex = v4;
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSOffsetTimers(void) {
    s32 i;
    u16 a;

    a = GetRecordVSFirstRecordIndex();
    gRecordVS->mRecordVSSTable[data_0215c3ac[0]].mUnk_04 = -func_020adc64(6 - gRecordVS->mOffsetTimers[0]);
    gRecordVS->mRecordVSSTable[data_0215c3ac[1]].mUnk_04 = func_020adc64(6 - gRecordVS->mOffsetTimers[1]);
    for (i = 0; i < 2; i++) {
        if (gRecordVS->mOffsetTimers[i] > 0) {
            gRecordVS->mOffsetTimers[i]--;
            gRecordVS->mRecordVSSTable[data_0215c3b0[i]].mUnk_00 = 0;
            gRecordVS->mRecordVSSTable[data_0215c3ac[i]].mUnk_00 = 1;
        } else {
            gRecordVS->mRecordVSSTable[data_0215c3b0[i]].mUnk_00 = 1;
            gRecordVS->mRecordVSSTable[data_0215c3ac[i]].mUnk_00 = 0;
        }
    }
    if (a == 0) {
        gRecordVS->mRecordVSSTable[data_0215c3b0[0]].mUnk_00 = 0;
    }
    if (a + 5 >= GetRecordCount()) {
        gRecordVS->mRecordVSSTable[data_0215c3b0[1]].mUnk_00 = 0;
    }
}

// Flips the flag of the entry in row a of the page and plays the matching sound.
void ToggleRecordVSRowFlag(s32 a) {
    s32 b;

    b = GetRecordVSFirstRecordIndex();
    b += a;
    if (IsRecordFlagged(b)) {
        ClearRecordFlag(b);
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x25);
    } else {
        SetRecordFlag(b);
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x24);
    }
}

#pragma thumb off

#pragma thumb on

u32 IsRecordVSIndexChangeRunning(void) {
    if (gRecordVS->mIndexChangeTimer != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSIndexChange(void) {
    u16 a;
    u16 b;
    s16 v;
    if (IsRecordVSIndexChangeRunning() != 0) {
        if (gRecordVS->mIndexChangeTimer == 7) {
            gRecordVS->mShownIndex = gRecordVS->mIndex;
            PrintRecordVSShownRecord();
        } else {
            a = gRecordVS->mRecordVSMBncl->mUnk_06;
            b = gRecordVS->mRecordVSMTransientBncl->mUnk_06;
            v = LookupIndexChangeOffset(7 - gRecordVS->mIndexChangeTimer, 0);
            gRecordVS->mBg0OffsetY = v;
            gRecordVS->mRecordVSMTable[3].mUnk_06 = v;
            gRecordVS->mRecordVSMTable[a].mUnk_06 = v;
            gRecordVS->mRecordVSMTransientTable[1].mUnk_06 = v;
            gRecordVS->mRecordVSMTransientTable[b].mUnk_06 = v;
        }
        gRecordVS->mIndexChangeTimer = gRecordVS->mIndexChangeTimer - 1;
    } else {
        if (gRecordVS->mIndex != 5 && gRecordVS->mIndex != gRecordVS->mShownIndex) {
            gRecordVS->mIndexChangeTimer = 7;
        }
    }
}

void func_021134d4(void) {
    s32 i;
    u16 b;
    u16 x;
    s32 l;
    u16 a;
    s32 j;
    i = 0;
    gRecordVS->mNextState = 0;
    gRecordVS->mStateFrames = 0;
    gRecordVS->mBg0OffsetX = 0;
    gRecordVS->mBg0OffsetY = -192;
    gRecordVS->mBg1OffsetX = 0;
    gRecordVS->mBg1OffsetY = -192;
    a = gRecordVS->mRecordVSMBncl->mUnk_06;
    b = gRecordVS->mRecordVSMTransientBncl->mUnk_06;
    x = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSMTable[0].mUnk_06 = -192;
    gRecordVS->mRecordVSMTable[1].mUnk_06 = -192;
    gRecordVS->mRecordVSMTable[2].mUnk_06 = -192;
    gRecordVS->mRecordVSMTable[3].mUnk_06 = -192;
    gRecordVS->mRecordVSMTable[a].mUnk_06 = -192;
    gRecordVS->mRecordVSMTable[a + 1].mUnk_06 = -192;
    gRecordVS->mRecordVSMTable[a + 11].mUnk_06 = -192;
    gRecordVS->mRecordVSMTable[a + 12].mUnk_06 = -192;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVS->mRecordVSMTable[a + data_0215c410[i][j]].mUnk_06 = -192;
        }
    }
    gRecordVS->mRecordVSMTransientTable[1].mUnk_06 = -192;
    gRecordVS->mRecordVSMTransientTable[0].mUnk_06 = -192;
    gRecordVS->mRecordVSMTransientTable[b].mUnk_06 = -192;
    gRecordVS->mRecordVSMTransientTable[b + 1].mUnk_06 = -192;
    gRecordVS->mRecordVSMTransientTable[b + 14].mUnk_06 = -192;
    for (j = 0; j < 12; j++) {
        gRecordVS->mRecordVSMTransientTable[b + data_0215c478[j]].mUnk_06 = -192;
    }
    gRecordVS->mRecordVSSTable[20].mUnk_04 = 0x100;
    gRecordVS->mRecordVSSTable[21].mUnk_04 = 0x100;
    gRecordVS->mRecordVSSTable[24].mUnk_04 = 0x100;
    gRecordVS->mRecordVSSTable[25].mUnk_04 = 0x100;
    gRecordVS->mRecordVSSTable[25].mUnk_00 = 0;
    gRecordVS->mRecordVSSTable[26].mUnk_04 = 0x100;
    gRecordVS->mRecordVSSTable[x + 5].mUnk_04 = 0x100;
    for (l = 0; l < 5; l++) {
        gRecordVS->mRecordVSSTable[data_0215c3e0[l]].mUnk_04 = 0x100;
        gRecordVS->mRecordVSSTable[data_0215c3ec[l]].mUnk_04 = 0x100;
        gRecordVS->mRecordVSSTable[data_0215c3f8[l]].mUnk_04 = 0x100;
        gRecordVS->mRecordVSSTable[data_0215c404[l]].mUnk_04 = 0x100;
        gRecordVS->mRecordVSSTable[x + data_0215c3bc[l]].mUnk_04 = 0x100;
    }
    for (j = 0; j < 2; j++) {
        gRecordVS->mRecordVSSTable[data_0215c3ac[j]].mUnk_00 = 0;
    }
}

void RequestRecordVSState1(void) {
    gRecordVS->mNextState = 1;
    gRecordVS->mStateFrames = 0;
    PrintRecordVSShownRecord();
}

void RequestRecordVSState2AndRefreshPage(void) {
    gRecordVS->mNextState = 2;
    gRecordVS->mStateFrames = 0;
    RefreshRecordVSPage();
}

void RequestRecordVSState3(void) {
    gRecordVS->mNextState = 3;
    gRecordVS->mStateFrames = 0;
    RequestSelectReturnState1();
}

// Requests state 4: stores mNextState = 4 and zeroes mStateFrames; the next AdvanceRecordVS call copies it to mState
// and runs AdvanceRecordVSState4.
void RequestRecordVSState4(void) {
    gRecordVS->mNextState = 4;
    gRecordVS->mStateFrames = 0;
}

// Requests state 5: stores mNextState = 5 and zeroes mStateFrames; the next AdvanceRecordVS call copies it to mState
// and runs AdvanceRecordVSState5.
void RequestRecordVSState5(void) {
    gRecordVS->mNextState = 5;
    gRecordVS->mStateFrames = 0;
}

void RequestRecordVSState6AndChangePage(void) {
    gRecordVS->mNextState = 6;
    gRecordVS->mStateFrames = 0;
    switch (gRecordVS->mPageDecrement) {
        case 0:
            IncrementRecordVSPageIndex();
            break;
        case 1:
            DecrementRecordVSPageIndex();
            break;
    }
    RefreshRecordVSPage();
}

// Requests state 7: stores mNextState = 7 and zeroes mStateFrames; the next AdvanceRecordVS call copies it to mState
// and runs AdvanceRecordVSState7.
void RequestRecordVSState7(void) {
    gRecordVS->mNextState = 7;
    gRecordVS->mStateFrames = 0;
}

void func_021132e4(void) {
    s32 i;
    u16 x;
    gRecordVS->mNextState = 8;
    i = 0;
    gRecordVS->mStateFrames = 0;
    x = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSSTable[20].mUnk_04 = 0x100;
    gRecordVS->mRecordVSSTable[21].mUnk_04 = 0x100;
    gRecordVS->mRecordVSSTable[24].mUnk_04 = 0x100;
    gRecordVS->mRecordVSSTable[25].mUnk_04 = 0x100;
    gRecordVS->mRecordVSSTable[25].mUnk_00 = 0;
    gRecordVS->mRecordVSSTable[26].mUnk_04 = 0x100;
    gRecordVS->mRecordVSSTable[x + 5].mUnk_04 = 0x100;
    for (i = 0; i < 5; i++) {
        gRecordVS->mRecordVSSTable[data_0215c3e0[i]].mUnk_04 = 0x100;
        gRecordVS->mRecordVSSTable[data_0215c3ec[i]].mUnk_04 = 0x100;
        gRecordVS->mRecordVSSTable[data_0215c3f8[i]].mUnk_04 = 0x100;
        gRecordVS->mRecordVSSTable[data_0215c404[i]].mUnk_04 = 0x100;
        gRecordVS->mRecordVSSTable[x + data_0215c3bc[i]].mUnk_04 = 0x100;
    }
    for (i = 0; i < 2; i++) {
        gRecordVS->mRecordVSSTable[data_0215c3ac[i]].mUnk_00 = 0;
    }
    func_0205edf8();
}

void func_021132b4(void) {
    gRecordVS->mNextState = 9;
    gRecordVS->mStateFrames = 0;
    gRecordVS->mRecordVSSTable[25].mUnk_00 = 1;
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 4);
}

void RequestRecordVSState10(void) {
    gRecordVS->mNextState = 10;
    gRecordVS->mStateFrames = 0;
    RequestSelectReturnState4();
}

void func_02113174(void) {
    s32 i;
    u16 x;
    gRecordVS->mNextState = 11;
    i = 0;
    gRecordVS->mStateFrames = 0;
    x = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSSTable[20].mUnk_04 = 0x100;
    gRecordVS->mRecordVSSTable[21].mUnk_04 = 0x100;
    gRecordVS->mRecordVSSTable[24].mUnk_04 = -256;
    gRecordVS->mRecordVSSTable[25].mUnk_04 = -256;
    gRecordVS->mRecordVSSTable[26].mUnk_04 = -256;
    gRecordVS->mRecordVSSTable[x + 5].mUnk_04 = -256;
    for (i = 0; i < 5; i++) {
        gRecordVS->mRecordVSSTable[data_0215c3e0[i]].mUnk_04 = 0x100;
        gRecordVS->mRecordVSSTable[data_0215c3ec[i]].mUnk_04 = 0x100;
        gRecordVS->mRecordVSSTable[data_0215c3f8[i]].mUnk_04 = 0x100;
        gRecordVS->mRecordVSSTable[data_0215c404[i]].mUnk_04 = 0x100;
        gRecordVS->mRecordVSSTable[x + data_0215c3bc[i]].mUnk_04 = 0x100;
    }
    for (i = 0; i < 2; i++) {
        gRecordVS->mRecordVSSTable[data_0215c3ac[i]].mUnk_00 = 0;
    }
    RefreshRecordVSPage();
}

void InitRecordVS(void *a) {
    s32 r;
    s32 i;
    s32 j;
    u16 e;
    u16 x;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 2;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0xc800;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0xcc00;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0x1018;
    gRecordVS = HeapAlloc(a, 0x94);
    gRecordVS->mHeap = a;
    gRecordVS->mPageIndex = GetRecordScenePageIndex();
    gRecordVS->mIndex = GetRecordSceneIndex();
    gRecordVS->mPageDecrement = 0;
    gRecordVS->mIndexChangeTimer = 0;
    gRecordVS->mShownIndex = gRecordVS->mIndex;
    gRecordVS->mShowsFriendKey = 0;
    gRecordVS->mUnk_88 = FALSE;
    gRecordVS->mUnk_8c = FALSE;
    for (i = 0; i < 2; i++) {
        gRecordVS->mOffsetTimers[i] = 0;
    }
    LoadEmblemSBNclr(a);
    LocateAndQueueRecordVS();
    InitLayoutTable(a, gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMBnll, &gRecordVS->mRecordVSMTable);
    InitLayoutTable(a, gRecordVS->mRecordVSMTransientBncl, gRecordVS->mRecordVSMTransientBnll,
                    &gRecordVS->mRecordVSMTransientTable);
    InitLayoutTable(a, gRecordVS->mRecordVSSBncl, gRecordVS->mRecordVSSBnll, &gRecordVS->mRecordVSSTable);
    gRecordVS->mRecordMessages = FindSceneFile("record.bmg");
    r = 0x8000;
    r -= func_021243ac(a, 0, gRecordVS->mRecordVSMBnll, 0x8c, 0x10, 0, gRecordVS->mRecordVSMNcer,
                       gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable, r);
    r -= func_021243ac(a, 1, gRecordVS->mRecordVSMBnll, 0xaa, 0xe, 1, gRecordVS->mRecordVSMNcer,
                       gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable, r);
    func_0212426c(0, 1, gRecordVS->mRecordVSMBnll, GetBmgEntry(gRecordVS->mRecordMessages, 0),
                  gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable);
    r -= func_021243ac(a, 0xb, gRecordVS->mRecordVSMBnll, 0x96, 0xe, 2, gRecordVS->mRecordVSMNcer,
                       gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable, r);
    func_0212426c(0, 0xb, gRecordVS->mRecordVSMBnll, GetBmgEntry(gRecordVS->mRecordMessages, 1),
                  gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable);
    r -= func_021243ac(a, 0xc, gRecordVS->mRecordVSMBnll, 0x46, 0x10, 3, gRecordVS->mRecordVSMNcer,
                       gRecordVS->mRecordVSMBncl, gRecordVS->mRecordVSMTable, r);
    e = 4;
    x = gRecordVS->mRecordVSMBncl->mUnk_06;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            r -= func_021243ac(a, data_0215c410[i][j], gRecordVS->mRecordVSMBnll, data_0215c424[i][j],
                               data_0215c438[i][j], e, gRecordVS->mRecordVSMNcer, gRecordVS->mRecordVSMBncl,
                               gRecordVS->mRecordVSMTable, r);
            e = x + data_0215c410[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        func_0212426c(0, data_0215c410[0][i], gRecordVS->mRecordVSMBnll,
                      GetBmgEntry(gRecordVS->mRecordMessages, data_0215c3b4[i]), gRecordVS->mRecordVSMBncl,
                      gRecordVS->mRecordVSMTable);
    }
    r -= func_021243ac(a, 0, gRecordVS->mRecordVSMTransientBnll, 0x8c, 0x10, 0, gRecordVS->mRecordVSMNcer,
                       gRecordVS->mRecordVSMTransientBncl, gRecordVS->mRecordVSMTransientTable, r);
    r -= func_021243ac(a, 1, gRecordVS->mRecordVSMTransientBnll, 0x70, 0x10, 1, gRecordVS->mRecordVSMNcer,
                       gRecordVS->mRecordVSMTransientBncl, gRecordVS->mRecordVSMTransientTable, r);
    func_0212426c(0, 1, gRecordVS->mRecordVSMTransientBnll, GetBmgEntry(gRecordVS->mRecordMessages, 0xb),
                  gRecordVS->mRecordVSMTransientBncl, gRecordVS->mRecordVSMTransientTable);
    r -= func_021243ac(a, 0xe, gRecordVS->mRecordVSMTransientBnll, 0xe0, 0x38, 2, gRecordVS->mRecordVSMNcer,
                       gRecordVS->mRecordVSMTransientBncl, gRecordVS->mRecordVSMTransientTable, r);
    func_0212426c(0, 0xe, gRecordVS->mRecordVSMTransientBnll, GetBmgEntry(gRecordVS->mRecordMessages, 0xc),
                  gRecordVS->mRecordVSMTransientBncl, gRecordVS->mRecordVSMTransientTable);
    for (i = 0; i < 12; i++) {
        r -= func_021243ac(a, data_0215c478[i], gRecordVS->mRecordVSMTransientBnll, data_0215c490[i], data_0215c460[i],
                           i + 3, gRecordVS->mRecordVSMNcer, gRecordVS->mRecordVSMTransientBncl,
                           gRecordVS->mRecordVSMTransientTable, r);
    }
    r = GX_GetSizeOfSubOBJ();
    for (i = 0; i < 5; i++) {
        r -= func_021243ac(a, data_0215c3bc[i], gRecordVS->mRecordVSSBnll, data_0215c3c8[i], data_0215c3d4[i],
                           data_0215c3ec[i], gRecordVS->mRecordVSSNcer, gRecordVS->mRecordVSSBncl,
                           gRecordVS->mRecordVSSTable, r);
    }
    func_021243ac(a, 5, gRecordVS->mRecordVSSBnll, 0x98, 0x10, 0x19, gRecordVS->mRecordVSSNcer,
                  gRecordVS->mRecordVSSBncl, gRecordVS->mRecordVSSTable, r);
    func_0212426c(1, 5, gRecordVS->mRecordVSSBnll, GetBmgEntry(gRecordVS->mRecordMessages, 3),
                  gRecordVS->mRecordVSSBncl, gRecordVS->mRecordVSSTable);
    for (i = 0; i < 5; i++) {
        func_02124a98(data_0215c3e0[i], 0, gRecordVS->mRecordVSSNcer, gRecordVS->mRecordVSSBncl);
        func_02124a98(data_0215c3ec[i], 0, gRecordVS->mRecordVSSNcer, gRecordVS->mRecordVSSBncl);
        func_02124140(data_0215c3bc[i], 0, gRecordVS->mRecordVSSBnll, gRecordVS->mRecordVSSTable,
                      gRecordVS->mRecordVSSBncl);
    }
    func_02124a98(0x18, 0, gRecordVS->mRecordVSSNcer, gRecordVS->mRecordVSSBncl);
    func_02124a98(0x19, 0, gRecordVS->mRecordVSSNcer, gRecordVS->mRecordVSSBncl);
    func_02124140(5, 0, gRecordVS->mRecordVSSBnll, gRecordVS->mRecordVSSTable, gRecordVS->mRecordVSSBncl);
    gRecordVS->mEmblem = HeapAlloc(a, 0x201);
    gRecordVS->mEmblemConverted = HeapAlloc(a, 0x200);
    if (GetRecordPrevScreen() == 4) {
        if (GetRecordCount() != 0) {
            gRecordVS->mState = 11;
            func_02113174();
        } else {
            gRecordVS->mState = 8;
            func_021132e4();
            if (GetRecordPrevScene() == 12) {
                gRecordVS->mUnk_90 = 6;
            } else {
                gRecordVS->mUnk_90 = 0;
            }
        }
    } else {
        gRecordVS->mState = 0;
        func_021134d4();
        func_020ae6d4(GetRecordMainOam(), GetRecordSubOam());
    }
    gRecordVS->mRecordVSSTable[24].mUnk_00 = 0;
    gRecordVS->mRecordVSSTable[25].mUnk_00 = 0;
}

void ReleaseRecordVS(void) {
    u32 v;
    if (gRecordVS->mUnk_90 == 4) {
        SetRecordScenePageIndex(gRecordVS->mPageIndex);
        SetRecordSceneIndex(gRecordVS->mIndex);
    } else {
        SetRecordScenePageIndex(0);
        SetRecordSceneIndex(0);
        v = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((v & ~0x13) << 8);
    }
    gRecordVS = NULL;
}

#pragma thumb off

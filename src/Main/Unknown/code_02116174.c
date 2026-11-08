#include "Main/Unknown/code_02116174.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02114158.h"

#include "Main/Unknown/code_0211621c.h"
#include "Main/Unknown/code_02116244.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02114000.h"
#include "Main/Unknown/code_02116844.h"
#include "Main/Unknown/code_02116870.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0212426c.h"
#include "00/code_02181f98.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02116888.h"

#pragma thumb on

void LocateAndQueueRecordVSErase(void) {
    void *v2;
    Nclr *v3;
    Ncgr *v4;
    Nclr *v5;
    Nscr *v6[2];
    v4 = NULL;
    v5 = NULL;
    v6[0] = NULL;
    v2 = FindSceneFile(gRecordVSMNcgrName);
    LocateNcgr2((Ncgr **) gRecordVSErase, v2);
    v2 = FindSceneFile(gRecordVSMNcerName);
    LocateNcer(&gRecordVSErase->mRecordVSMNcer, v2);
    v2 = FindSceneFile(gRecordVSMBnclName);
    gRecordVSErase->mRecordVSMBncl = v2;
    v2 = FindSceneFile(gRecordVSMBnllName);
    gRecordVSErase->mRecordVSMBnll = v2;
    v2 = FindSceneFile(gRecordVSMTransientBnclName);
    gRecordVSErase->mRecordVSMTransientBncl = v2;
    v2 = FindSceneFile(gRecordVSMTransientBnllName);
    gRecordVSErase->mRecordVSMTransientBnll = v2;
    v2 = FindSceneFile(gRecordVSSNcgrName);
    LocateNcgr2(&gRecordVSErase->mRecordVSSNcgr, v2);
    v2 = FindSceneFile(gRecordVSSNcerName);
    LocateNcer(&gRecordVSErase->mRecordVSSNcer, v2);
    v2 = FindSceneFile(gRecordVSSEraseBnclName);
    gRecordVSErase->mRecordVSSEraseBncl = v2;
    v2 = FindSceneFile(gRecordVSSEraseBnblName);
    gRecordVSErase->mRecordVSSEraseBnbl = v2;
    v2 = FindSceneFile(gRecordVSSEraseBnllName);
    gRecordVSErase->mRecordVSSEraseBnll = v2;
    v2 = HeapAlloc(gRecordVSErase->mHeap, (0x00000800u));
    gRecordVSErase->mUnk_4c = v2;
    v2 = FindSceneFile(gRecordVSSBNcgrName);
    LocateNcgr(&v4, v2);
    v2 = FindSceneFile(gRecordVSSEraseNscrName);
    LocateNscr(v6, v2);
    v2 = FindSceneFile(gRecordVSSBNclrName);
    LocateNclr(&v5, v2);
    v2 = FindSceneFile(gRecordVSM02NscrName);
    LocateNscr(&gRecordVSErase->mRecordVSM02Nscr, v2);
    v2 = FindSceneFile(gRecordVSM03NscrName);
    LocateNscr(&gRecordVSErase->mRecordVSM03Nscr, v2);
    v3 = GetEmblemSBNclr();
    CallQueueAppend(0x17, 0, v4->mData, v4->mDataSize);
    CallQueueAppend(0x1b, 0, v6[0]->mData, v6[0]->mDataSize);
    CallQueueAppend(0x1b, (0x00000800u), gRecordVSErase->mUnk_4c, (0x00000800u));
    CallQueueAppend(0x1f, 0, v5->mData, 0x40);
    CallQueueAppend(0xe, 0x40, v3->mData, 0x20);
}

#pragma thumb off

#pragma thumb on

u16 GetRecordVSEraseFirstRecordIndex(void) {
    return gRecordVSErase->mPageIndex * 5;
}

#pragma thumb off

#pragma thumb on

u32 IsRecordVSEraseRowFilled(int a) {
    int v1;
    int v2;
    v1 = GetRecordVSEraseFirstRecordIndex();
    v2 = GetRecordCount();
    if (v2 > v1 + a) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void func_02116624(void) {
    s32 i;
    s32 n;
    s32 v;

    n = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    v = GetRecordVSEraseFirstRecordIndex();
    for (i = 0; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[n + data_0215c4b8[i]].mVisible = 0;
    }
    for (i = 0; i < 5; i++) {
        if (IsRecordVSEraseRowFilled((s16) i)) {
            if (gRecordVSErase->mIndex == i) {
                if (IsRecordFlagged(v)) {
                    gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mVisible = 1;
                    func_02124100(data_0215c4b8[i], 0xe, gRecordVSErase->mRecordVSSEraseBnll,
                                  gRecordVSErase->mRecordVSSEraseTable, gRecordVSErase->mRecordVSSEraseBncl);
                } else {
                    gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mVisible = 1;
                    func_02124100(data_0215c4b8[i], 0xe, gRecordVSErase->mRecordVSSEraseBnll,
                                  gRecordVSErase->mRecordVSSEraseTable, gRecordVSErase->mRecordVSSEraseBncl);
                }
            } else {
                if (IsRecordFlagged(v)) {
                    gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mVisible = 1;
                    func_02124100(data_0215c4b8[i], 0xe, gRecordVSErase->mRecordVSSEraseBnll,
                                  gRecordVSErase->mRecordVSSEraseTable, gRecordVSErase->mRecordVSSEraseBncl);
                } else {
                    gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mVisible = 1;
                    func_02124100(data_0215c4b8[i], 0xf, gRecordVSErase->mRecordVSSEraseBnll,
                                  gRecordVSErase->mRecordVSSEraseTable, gRecordVSErase->mRecordVSSEraseBncl);
                }
            }
            gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mVisible = IsRecordFlagged(v) ? 0 : 1;
            gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mVisible = IsRecordFlagged(v);
            gRecordVSErase->mRecordVSSEraseTable[n + data_0215c4b8[i]].mVisible = 1;
        }
        v++;
    }
}

void func_021162cc(void) {
    s32 v;
    s32 i;
    s32 j;
    BOOL z;
    u16 buf[0x10];
    u32 t[3][3] = {0};
    u8 buf3[0x14];
    DateBytes a;

    v = GetRecordVSEraseFirstRecordIndex();
    if (GetRecordFriendKeyText(v + gRecordVSErase->mShownIndex, buf3)) {
        gRecordVSErase->mTransientDrawn = 1;
        CallQueueAppend(9, 0, gRecordVSErase->mRecordVSM03Nscr->mData, gRecordVSErase->mRecordVSM03Nscr->mDataSize);
    } else {
        gRecordVSErase->mTransientDrawn = 0;
        CallQueueAppend(9, 0, gRecordVSErase->mRecordVSM02Nscr->mData, gRecordVSErase->mRecordVSM02Nscr->mDataSize);
    }
    switch (gRecordVSErase->mTransientDrawn) {
        case 0:
            CopyRecordText(v + gRecordVSErase->mShownIndex, buf, 0x20);
            func_0212426c(0, 0, gRecordVSErase->mRecordVSMBnll, buf, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable);
            t[1][0] = func_0211437c(v + gRecordVSErase->mShownIndex);
            t[1][1] = func_02114360(v + gRecordVSErase->mShownIndex);
            t[1][2] = func_02114344(v + gRecordVSErase->mShownIndex);
            t[2][0] = func_02114328(v + gRecordVSErase->mShownIndex);
            t[2][1] = func_0211430c(v + gRecordVSErase->mShownIndex);
            t[2][2] = func_021142f0(v + gRecordVSErase->mShownIndex);
            for (i = 1; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (t[i][j] > 0x270f) {
                        t[i][j] = 0x270f;
                    }
                }
            }
            func_02124fac(t[1][0], buf);
            func_02124248(0, data_0215c530[1][0], gRecordVSErase->mRecordVSMBnll, buf, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable, 6);
            func_02124fac(t[1][1], buf);
            func_02124248(0, data_0215c530[1][1], gRecordVSErase->mRecordVSMBnll, buf, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable, 6);
            func_02124fac(t[1][2], buf);
            func_02124248(0, data_0215c530[1][2], gRecordVSErase->mRecordVSMBnll, buf, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable, 6);
            func_02124fac(t[2][0], buf);
            func_02124248(0, data_0215c530[2][0], gRecordVSErase->mRecordVSMBnll, buf, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable, 6);
            func_02124fac(t[2][1], buf);
            func_02124248(0, data_0215c530[2][1], gRecordVSErase->mRecordVSMBnll, buf, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable, 6);
            func_02124fac(t[2][2], buf);
            func_02124248(0, data_0215c530[2][2], gRecordVSErase->mRecordVSMBnll, buf, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable, 6);
            func_021142d4(v + gRecordVSErase->mShownIndex, &a);
            FormatDate(&a, buf);
            func_02124224(0, 0xc, gRecordVSErase->mRecordVSMBnll, buf, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable, 6);
            ReadRecordEmblem(v + gRecordVSErase->mShownIndex, gRecordVSErase->mEmblem,
                             gRecordVSErase->mEmblemConverted);
            CallQueueAppend(0x13, func_0212497c(3, gRecordVSErase->mRecordVSMNcer, gRecordVSErase->mRecordVSMBncl) << 5,
                            gRecordVSErase->mEmblemConverted, 0x200);
            break;
        case 1:
            CopyRecordText(v + gRecordVSErase->mShownIndex, buf, 0x20);
            func_0212426c(0, 0, gRecordVSErase->mRecordVSMTransientBnll, buf, gRecordVSErase->mRecordVSMTransientBncl,
                          gRecordVSErase->mRecordVSMTransientTable);
            z = FALSE;
            for (i = 0; i < 12; i++) {
                func_02124fac(buf3[i] - 0x30, buf);
                func_0212426c(z, data_0215c584[i], gRecordVSErase->mRecordVSMTransientBnll, buf,
                              gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable);
            }
            ReadRecordEmblem(v + gRecordVSErase->mShownIndex, gRecordVSErase->mEmblem,
                             gRecordVSErase->mEmblemConverted);
            CallQueueAppend(
                0x13, func_0212497c(1, gRecordVSErase->mRecordVSMNcer, gRecordVSErase->mRecordVSMTransientBncl) << 5,
                gRecordVSErase->mEmblemConverted, 0x200);
            break;
    }
}

void func_02116244(void) {
    s32 v;
    s32 i;
    u8 buf[0x20];

    v = GetRecordVSEraseFirstRecordIndex();
    for (i = 0; i < 5; i++) {
        if (GetRecordCount() > v + i) {
            CopyRecordText(v + i, buf, 0x20);
            func_0212426c(1, data_0215c4b8[i], gRecordVSErase->mRecordVSSEraseBnll, buf,
                          gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSEraseTable);
        }
    }
    if (GetRecordCount() <= v + gRecordVSErase->mIndex) {
        gRecordVSErase->mIndex = GetRecordCount() % 5 - 1;
        gRecordVSErase->mShownIndex = gRecordVSErase->mIndex;
    }
    func_021162cc();
}

#pragma thumb off

#pragma thumb on
u32 IncrementRecordVSErasePageIndex(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRecordVSErase;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 118u;
    value0 = *(const s16 *) ((value1) + (value0));
    value0 = (value0) + (1u);
    value1 = (value1) + 118u;
    *(u16 *) ((value1) + 0u) = value0;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 DecrementRecordVSErasePageIndex(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRecordVSErase;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 118u;
    value0 = *(const s16 *) ((value1) + (value0));
    value0 = (value0) - (1u);
    value1 = (value1) + 118u;
    *(u16 *) ((value1) + 0u) = value0;
    return value0;
}
#pragma thumb off

#pragma thumb on

void IncrementRecordVSEraseIndex(void) {
    int v1;
    int v2;
    v2 = (gRecordVSErase->mIndex + 1) * 0x10000 >> 0x10;
    v1 = IsRecordVSEraseRowFilled(v2);
    if ((v1 == 0) || (5 <= v2)) {
        v2 = 0;
    }
    if (gRecordVSErase->mIndex != v2) {
        NNS_SndArcPlayerStartSeqArc((const void *) (((u32) ((u8 *) &data_0217d068))), 0, 0);
    }
    gRecordVSErase->mIndex = v2;
}

void DecrementRecordVSEraseIndex(void) {
    int v1;
    int v2;
    int v3;
    int v4;
    v4 = (gRecordVSErase->mIndex + -1) * 0x10000 >> 0x10;
    if (v4 < 0) {
        v4 = 4;
        v1 = IsRecordVSEraseRowFilled(4);
        if (v1 == 0) {
            v2 = GetRecordCount();
            v3 = (v2) % 5;
            v4 = (v3 + -1) * 0x10000 >> 0x10;
        }
    }
    if (gRecordVSErase->mIndex != v4) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
    }
    gRecordVSErase->mIndex = v4;
}

#pragma thumb off

#include "01/code_021956dc.h"

#include "01/code_02193c5c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02111428.h"
#include "Main/Unknown/code_02111494.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_021171a0.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126248.h"
#include "Main/Unknown/unk_0216c000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_02117218.h"
#include "Main/Unknown/code_02125f54.h"
#include "code_02148950.h"
#include "code_0201ea58.h"
#include "code_0214d018.h"
#include "registers.h"
#include "Main/Unknown/code_02126000.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "00/code_02181f98.h"
#include "03/code_021b94b8.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02116000.h"
#include "Main/Unknown/code_020ae408.h"
#include "01/code_02198000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02047104.h"

RecordTAtt *gRecordTAtt;

void LocateAndQueueRecordTAtt(void) {
    Nclr *l0 = NULL;
    Ncgr *l4 = NULL;
    Nclr *l8 = NULL;
    Nscr *lc = NULL;
    Nscr *l10 = NULL;
    Nclr *l14 = NULL;
    Ncgr *l18 = NULL;
    Nclr *l1c = NULL;
    Nscr *l20 = NULL;
    u16 *p;

    LocateNcgr2(&gRecordTAtt->mRecordTAttMNcgr, FindSceneFile(gRecordTAttMNcgrName));
    LocateNcer(&gRecordTAtt->mRecordTAttMNcer, FindSceneFile(gRecordTAttMNcerName));
    LocateNclr(&l0, FindSceneFile(gRecordTAttMONclrName));
    gRecordTAtt->mRecordTAttMBncl = FindSceneFile(gRecordTAttMBnclName);
    gRecordTAtt->mRecordTAttMBnll = FindSceneFile(gRecordTAttMBnllName);
    LocateNcgr2(&gRecordTAtt->mRecordTAttSNcgr, FindSceneFile(gRecordTAttSNcgrName));
    LocateNcer(&gRecordTAtt->mRecordTAttSNcer, FindSceneFile(gRecordTAttSNcerName));
    LocateNclr(&l14, FindSceneFile(gRecordTAttSONclrName));
    gRecordTAtt->mRecordTAttSBncl = FindSceneFile(gRecordTAttSBnclName);
    gRecordTAtt->mRecordTAttSBnbl = FindSceneFile(gRecordTAttSBnblName);
    gRecordTAtt->mRecordTAttSBnll = FindSceneFile(gRecordTAttSBnllName);
    gRecordTAtt->mUnk_28 = func_020b4018(0);
    gRecordTAtt->mUnk_2c = func_020b400c(0);
    gRecordTAtt->mUnk_30 = func_020b4030(0);
    gRecordTAtt->mUnk_34 = func_020b4000(0);
    LocateNcgr(&l4, FindSceneFile(gRecordTAttMBNcgrName));
    LocateNscr(&lc, FindSceneFile(gRecordTAttMNscrName));
    LocateNscr(&l10, FindSceneFile(gRecordTAttMScoreNscrName));
    LocateNclr(&l8, FindSceneFile(gRecordTAttMBNclrName));
    LocateNcgr(&l18, FindSceneFile(gRecordTAttSBNcgrName));
    LocateNclr(&l1c, FindSceneFile(gRecordTAttSBNclrName));
    LocateNscr(&l20, FindSceneFile(gRecordTAttSNscrName));
    p = l0->mData;
    CallQueueAppend(0x13, 0, gRecordTAtt->mRecordTAttMNcgr->mData, gRecordTAtt->mRecordTAttMNcgr->mDataSize);
    CallQueueAppend(0xe, 0, l0->mData, 0x1a0);
    CallQueueAppend(0xe, 0x1c0, (u8 *) p + 0x1c0, 0x40);
    CallQueueAppend(0x23, 0, gRecordTAtt->mRecordTAttSNcgr->mData, gRecordTAtt->mRecordTAttSNcgr->mDataSize);
    CallQueueAppend(0x1e, 0, l14->mData, l14->mDataSize);
    CallQueueAppend(4, 0, l4->mData, l4->mDataSize);
    CallQueueAppend(8, 0, lc->mData, lc->mDataSize);
    CallQueueAppend(9, 0, l10->mData, l10->mDataSize);
    CallQueueAppend(0xf, 0, l8->mData, 0x40);
    CallQueueAppend(0x17, 0, l18->mData, l18->mDataSize);
    CallQueueAppend(0x1f, 0, l1c->mData, 0x40);
    CallQueueAppend(0x1b, 0, l20->mData, l20->mDataSize);
}

void func_ov001_021975f4(u16 a) {
    u32 time;
    u16 str[16];
    u16 name[10];
    s32 value;
    s32 result;
    u16 tile;
    u16 index;
    u16 slot;
    u16 pal;
    u8 *palette;

    if (a == 0) {
        u16 cnt;

        value = data_ov001_021a6828[0];
        result = func_020601e4(data_ov001_021a6900[gRecordTAtt->mIndex], value);
        index = data_ov001_021a6850[0][0];
        gRecordTAtt->mRecordTAttMTable[index].mUnk_00 = 1;
        tile = data_ov001_021a6864[result];
        func_02124748(tile, gRecordTAtt->mUnk_2c, gRecordTAtt->mUnk_28, gRecordTAtt->mUnk_34, 0, index,
                      gRecordTAtt->mRecordTAttMNcer, gRecordTAtt->mRecordTAttMBncl);
        palette = (u8 *) ((Nclr *) gRecordTAtt->mUnk_30)->mData;
        CallQueueAppend(0xe, data_ov001_021a683c[0] << 5,
                        palette + (func_02124a68(tile, gRecordTAtt->mUnk_2c, gRecordTAtt->mUnk_34) << 5), 0x20);
        result = func_020601a0(data_ov001_021a6900[gRecordTAtt->mIndex], value);
        slot = data_ov001_021a6850[0][1];
        gRecordTAtt->mRecordTAttMTable[slot].mUnk_00 = 1;
        func_021171a0(result, gRecordTAtt->mRecordTAttMNcer, gRecordTAtt->mRecordTAttMBncl, slot,
                      data_ov001_021a683c[5], 0);
        cnt = gRecordTAtt->mRecordTAttMBncl->mUnk_06;
        func_02060134(data_ov001_021a6900[gRecordTAtt->mIndex], value, &time);
        func_02116b8c(&time, str);
        pal = data_ov001_021a67d4[0];
        gRecordTAtt->mRecordTAttMTable[cnt + pal].mUnk_00 = 1;
        func_02124224(0, pal, gRecordTAtt->mRecordTAttMBnll, str, gRecordTAtt->mRecordTAttMBncl,
                      gRecordTAtt->mRecordTAttMTable, 7);
        func_020600d0(data_ov001_021a6900[gRecordTAtt->mIndex], value, name);
        MemFill(str, 0, 0x20);
        MemCopyHalfwords(name, str, 0x14);
        pal = data_ov001_021a6810[0];
        gRecordTAtt->mRecordTAttMTable[cnt + pal].mUnk_00 = 1;
        func_0212426c(0, pal, gRecordTAtt->mRecordTAttMBnll, str, gRecordTAtt->mRecordTAttMBncl,
                      gRecordTAtt->mRecordTAttMTable);
    } else {
        u16 cnt;

        value = data_ov001_021a6828[a];
        result = func_020601e4(data_ov001_021a6900[gRecordTAtt->mIndex], value);
        index = data_ov001_021a6850[a][0];
        gRecordTAtt->mRecordTAttSTable[index].mUnk_00 = 1;
        tile = data_ov001_021a6864[result];
        func_02124748(tile, gRecordTAtt->mUnk_2c, gRecordTAtt->mUnk_28, gRecordTAtt->mUnk_34, 1, index,
                      gRecordTAtt->mRecordTAttSNcer, gRecordTAtt->mRecordTAttSBncl);
        palette = (u8 *) ((Nclr *) gRecordTAtt->mUnk_30)->mData;
        CallQueueAppend(0x1e, data_ov001_021a683c[a] << 5,
                        palette + (func_02124a68(tile, gRecordTAtt->mUnk_2c, gRecordTAtt->mUnk_34) << 5), 0x20);
        result = func_020601a0(data_ov001_021a6900[gRecordTAtt->mIndex], value);
        slot = data_ov001_021a6852[a][0];
        gRecordTAtt->mRecordTAttSTable[slot].mUnk_00 = 1;
        func_021171a0(result, gRecordTAtt->mRecordTAttSNcer, gRecordTAtt->mRecordTAttSBncl, slot,
                      data_ov001_021a6846[a], 1);
        cnt = gRecordTAtt->mRecordTAttSBncl->mUnk_06;
        func_02060134(data_ov001_021a6900[gRecordTAtt->mIndex], value, &time);
        func_02116b8c(&time, str);
        pal = data_ov001_021a67d4[a];
        gRecordTAtt->mRecordTAttSTable[cnt + pal].mUnk_00 = 1;
        func_02124224(1, pal, gRecordTAtt->mRecordTAttSBnll, str, gRecordTAtt->mRecordTAttSBncl,
                      gRecordTAtt->mRecordTAttSTable, 7);
        func_020600d0(data_ov001_021a6900[gRecordTAtt->mIndex], value, name);
        MemFill(str, 0, 0x20);
        MemCopyHalfwords(name, str, 0x14);
        pal = data_ov001_021a6810[a];
        gRecordTAtt->mRecordTAttSTable[cnt + pal].mUnk_00 = 1;
        func_0212426c(1, pal, gRecordTAtt->mRecordTAttSBnll, str, gRecordTAtt->mRecordTAttSBncl,
                      gRecordTAtt->mRecordTAttSTable);
    }
}

void func_ov001_0219750c(u16 a) {
    u16 cnt;

    if (a == 0) {
        gRecordTAtt->mRecordTAttMTable[data_ov001_021a6850[0][0]].mUnk_00 = 0;
        gRecordTAtt->mRecordTAttMTable[data_ov001_021a6850[0][1]].mUnk_00 = 0;
        cnt = gRecordTAtt->mRecordTAttMBncl->mUnk_06;
        gRecordTAtt->mRecordTAttMTable[cnt + data_ov001_021a67d4[0]].mUnk_00 = 1;
        func_02124224(0, data_ov001_021a67d4[0], gRecordTAtt->mRecordTAttMBnll, L"--:--:---",
                      gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, 7);
        gRecordTAtt->mRecordTAttMTable[cnt + data_ov001_021a6810[0]].mUnk_00 = 0;
    } else {
        gRecordTAtt->mRecordTAttSTable[data_ov001_021a6850[a][0]].mUnk_00 = 0;
        gRecordTAtt->mRecordTAttSTable[data_ov001_021a6852[a][0]].mUnk_00 = 0;
        cnt = gRecordTAtt->mRecordTAttSBncl->mUnk_06;
        gRecordTAtt->mRecordTAttSTable[cnt + data_ov001_021a67d4[a]].mUnk_00 = 1;
        func_02124224(1, data_ov001_021a67d4[a], gRecordTAtt->mRecordTAttSBnll, L"--:--:---",
                      gRecordTAtt->mRecordTAttSBncl, gRecordTAtt->mRecordTAttSTable, 7);
        gRecordTAtt->mRecordTAttSTable[cnt + data_ov001_021a6810[a]].mUnk_00 = 0;
    }
}

void func_ov001_021972f4(void) {
    RecordTAtt *p;
    u32 time;
    u16 str[16];
    u16 name[10];
    s32 i;
    s32 result;
    u16 tile;
    u8 *palette;
    u16 cnt;

    p = gRecordTAtt;
    func_0212426c(0, 0, gRecordTAtt->mRecordTAttMBnll, GetBmgEntry(p->mCommonMessages, data_ov001_021a6880[p->mIndex]),
                  p->mRecordTAttMBncl, p->mRecordTAttMTable);
    for (i = 0; i < 5; i++) {
        if (func_02060228(data_ov001_021a6900[gRecordTAtt->mIndex], data_ov001_021a6828[i])) {
            func_ov001_021975f4(i);
        } else {
            func_ov001_0219750c(i);
        }
    }
    cnt = gRecordTAtt->mRecordTAttMBncl->mUnk_06;
    if (func_02060228(data_ov001_021a6900[gRecordTAtt->mIndex], 5)) {
        result = func_020601e4(data_ov001_021a6900[gRecordTAtt->mIndex], 5);
        gRecordTAtt->mRecordTAttMTable[5].mUnk_00 = 1;
        tile = data_ov001_021a6864[result];
        func_02124748((u32) (tile), (void *) (gRecordTAtt->mUnk_2c), (void *) (gRecordTAtt->mUnk_28),
                      (void *) (gRecordTAtt->mUnk_34), 0, (u32) (5), (void *) (gRecordTAtt->mRecordTAttMNcer),
                      (void *) (gRecordTAtt->mRecordTAttMBncl));
        palette = (u8 *) ((Nclr *) gRecordTAtt->mUnk_30)->mData;
        CallQueueAppend(
            0xe, 0x80,
            palette +
                (func_02124a68((u32) (tile), (void *) (gRecordTAtt->mUnk_2c), (void *) (gRecordTAtt->mUnk_34)) << 5),
            0x20);
        result = func_020601a0(data_ov001_021a6900[gRecordTAtt->mIndex], 5);
        gRecordTAtt->mRecordTAttMTable[6].mUnk_00 = 1;
        func_021171a0(result, gRecordTAtt->mRecordTAttMNcer, gRecordTAtt->mRecordTAttMBncl, 6, 6, 0);
        func_02060134(data_ov001_021a6900[gRecordTAtt->mIndex], 5, &time);
        func_02116b8c(&time, str);
        gRecordTAtt->mRecordTAttMTable[cnt + 2].mUnk_00 = 1;
        func_02124224(0, 2, gRecordTAtt->mRecordTAttMBnll, str, gRecordTAtt->mRecordTAttMBncl,
                      gRecordTAtt->mRecordTAttMTable, 7);
        func_020600d0(data_ov001_021a6900[gRecordTAtt->mIndex], 5, name);
        MemFill(str, 0, 0x20);
        MemCopyHalfwords(name, str, 0x14);
        gRecordTAtt->mRecordTAttMTable[cnt + 4].mUnk_00 = 1;
        func_0212426c(0, 4, gRecordTAtt->mRecordTAttMBnll, str, gRecordTAtt->mRecordTAttMBncl,
                      gRecordTAtt->mRecordTAttMTable);
    } else {
        gRecordTAtt->mRecordTAttMTable[5].mUnk_00 = 0;
        gRecordTAtt->mRecordTAttMTable[6].mUnk_00 = 0;
        gRecordTAtt->mRecordTAttMTable[cnt + 2].mUnk_00 = 1;
        func_02124224(0, 2, gRecordTAtt->mRecordTAttMBnll, L"--:--:---", gRecordTAtt->mRecordTAttMBncl,
                      gRecordTAtt->mRecordTAttMTable, 7);
        gRecordTAtt->mRecordTAttMTable[cnt + 4].mUnk_00 = 0;
    }
}

void func_ov001_021972b4(void) {
    gRecordTAtt->mIndex++;
    if (gRecordTAtt->mIndex >= 0x20) {
        gRecordTAtt->mIndex = 0;
    }
    if (func_020600b4(data_ov001_021a6900[gRecordTAtt->mIndex]) == 0) {
        func_ov001_021972b4();
    }
}

void func_ov001_02197274(void) {
    gRecordTAtt->mIndex--;
    if (gRecordTAtt->mIndex < 0) {
        gRecordTAtt->mIndex = 0x1f;
    }
    if (func_020600b4(data_ov001_021a6900[gRecordTAtt->mIndex]) == 0) {
        func_ov001_02197274();
    }
}

BOOL func_ov001_02197210(void) {
    u8 buf[0x14];

    if (func_02060228(data_ov001_021a6900[gRecordTAtt->mIndex], data_ov001_021a6828[0]) != FALSE) {
        if (func_0205fdb4(data_ov001_021a6900[gRecordTAtt->mIndex], buf) != 0) {
            return TRUE;
        }
        func_0212ecc0(&data_0217d068, 0, 0x16);
        return FALSE;
    }
    return FALSE;
}

void func_ov001_02197058(void) {
    s32 i;
    s32 j;
    u16 n;
    u16 m;

    gRecordTAtt->mNextState = 0;
    gRecordTAtt->mStateFrames = 0;
    gRecordTAtt->mBg0Offset = -192;
    gRecordTAtt->mBg1OffsetX = -256;
    gRecordTAtt->mBg1OffsetY = -192;
    gRecordTAtt->mBg3OffsetX = -256;
    n = gRecordTAtt->mRecordTAttMBncl->mUnk_06;
    m = gRecordTAtt->mRecordTAttSBncl->mUnk_06;
    gRecordTAtt->mRecordTAttMTable[0].mUnk_06 = -192;
    gRecordTAtt->mRecordTAttMTable[0].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttMTable[1].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttMTable[2].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttMTable[3].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttMTable[4].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttMTable[5].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttMTable[6].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttMTable[n].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttMTable[n + 1].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttMTable[n + 2].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttMTable[n + 3].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttMTable[n + 4].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttSTable[15].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttSTable[16].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttSTable[12].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttSTable[13].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttSTable[14].mUnk_04 = 0x100;
    gRecordTAtt->mRecordTAttSTable[m + 8].mUnk_04 = 0x100;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[data_ov001_021a67f8[i]].mUnk_04 = 0x100;
        gRecordTAtt->mRecordTAttSTable[m + data_ov001_021a67d4[i]].mUnk_04 = 0x100;
        gRecordTAtt->mRecordTAttSTable[m + data_ov001_021a6810[i]].mUnk_04 = 0x100;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[data_ov001_021a6850[i][j]].mUnk_04 = 0x100;
        }
    }
    for (j = 0; j < 2; j++) {
        gRecordTAtt->mRecordTAttSTable[data_ov001_021a67c4[j]].mUnk_00 = 0;
    }
    gRecordTAtt->mRecordTAttSTable[13].mUnk_00 = 0;
}

void func_ov001_0219703c(void) {
    gRecordTAtt->mNextState = 1;
    gRecordTAtt->mStateFrames = 0;
    func_ov001_021972f4();
}

void func_ov001_02197024(void) {
    gRecordTAtt->mNextState = 2;
    gRecordTAtt->mStateFrames = 0;
    gRecordTAtt->mUnk_74 = FALSE;
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceRecordTAtt call copies it to mState
// and runs AdvanceRecordTAttState3.
void RequestRecordTAttState3(void) {
    gRecordTAtt->mNextState = 3;
    gRecordTAtt->mStateFrames = 0;
}

void func_ov001_02196fd8(void) {
    gRecordTAtt->mNextState = 4;
    gRecordTAtt->mStateFrames = 0;
    switch (gRecordTAtt->mUnk_70) {
        case 0:
            func_ov001_021972b4();
            break;
        case 1:
            func_ov001_02197274();
            break;
    }
    func_ov001_021972f4();
}

// Requests state 5: stores mNextState = 5 and zeroes mStateFrames; the next AdvanceRecordTAtt call copies it to mState
// and runs AdvanceRecordTAttState5.
void RequestRecordTAttState5(void) {
    gRecordTAtt->mNextState = 5;
    gRecordTAtt->mStateFrames = 0;
}

// Requests state 6: stores mNextState = 6 and zeroes mStateFrames; the next AdvanceRecordTAtt call copies it to mState
// and runs AdvanceRecordTAttState6.
void RequestRecordTAttState6(void) {
    gRecordTAtt->mNextState = 6;
    gRecordTAtt->mStateFrames = 0;
}

void func_ov001_02196f80(void) {
    gRecordTAtt->mNextState = 7;
    gRecordTAtt->mStateFrames = 0;
    gRecordTAtt->mRecordTAttSTable[13].mUnk_00 = 1;
    func_0212ecc0(&data_0217d068, 0, 4);
}

void func_ov001_02196f64(void) {
    gRecordTAtt->mNextState = 8;
    gRecordTAtt->mStateFrames = 0;
    func_021282c8();
}

void func_ov001_02196ecc(void) {
    u16 buf[0x102];
    RecordTAtt *p;
    void *a;
    void *b;

    gRecordTAtt->mNextState = 9;
    gRecordTAtt->mStateFrames = 0;
    buf[0] = 0;
    MemFillHalfwords(buf[0], &buf[1], 0x200);
    p = gRecordTAtt;
    a = GetBmgEntry(p->mGhostMessages, data_ov001_021a6980[p->mIndex]);
    func_0212513c(a, GetBmgEntry(p->mRecordMessages, 10), &buf[1], 0x200);
    a = GetBmgEntry(gRecordTAtt->mCommonMessages, 0);
    b = GetBmgEntry(gRecordTAtt->mCommonMessages, 1);
    func_02125fd4(&buf[1], a, b, 1, 0, 1, 1, 1);
}

void func_ov001_02196eb0(void) {
    gRecordTAtt->mNextState = 10;
    gRecordTAtt->mStateFrames = 0;
    func_02125ed0(0, 11);
}

void func_ov001_02196e88(void) {
    gRecordTAtt->mNextState = 11;
    gRecordTAtt->mStateFrames = 0;
    func_02125fc0();
    func_02125ed0(0, 5);
}

void func_ov001_02196e54(void) {
    gRecordTAtt->mNextState = 12;
    gRecordTAtt->mStateFrames = 0;
    func_02128374();
    func_ov001_021972f4();
    gRecordTAtt->mRecordTAttSTable[13].mUnk_00 = 0;
}

void func_ov001_02196e30(void) {
    gRecordTAtt->mNextState = 13;
    gRecordTAtt->mStateFrames = 0;
    func_0212ecc0(&data_0217d068, 0, 6);
}

void func_ov001_02196dbc(void) {
    s32 i;
    s32 n;
    s32 k;
    u8 buf[0x10];
    u16 str[0x100];

    i = 0;
    n = 0;
    k = 0;
    gRecordTAtt->mNextState = 14;
    gRecordTAtt->mStateFrames = i;
    func_0205fdb4(data_ov001_021a6900[gRecordTAtt->mIndex], buf);
    while (n < 19) {
        k++;
        if (k > 4) {
            k = 0;
            str[n] = ' ';
            n++;
        } else {
            str[n] = buf[i];
            n++;
            i++;
        }
    }
    str[n] = 0;
    func_02126248(str, 0, 1, 0, 0, 0);
}

// Requests state 15: stores mNextState = 15 and zeroes mStateFrames; the next AdvanceRecordTAtt call copies it to
// mState and runs AdvanceRecordTAttState15.
void RequestRecordTAttState15(void) {
    gRecordTAtt->mNextState = 15;
    gRecordTAtt->mStateFrames = 0;
}

void func_ov001_02196d8c(void) {
    gRecordTAtt->mNextState = 0x10;
    gRecordTAtt->mStateFrames = 0;
    func_02125fc0();
}

// Requests state 17: stores mNextState = 17 and zeroes mStateFrames; the next AdvanceRecordTAtt call copies it to
// mState and runs AdvanceRecordTAttState17.
void RequestRecordTAttState17(void) {
    gRecordTAtt->mNextState = 0x11;
    gRecordTAtt->mStateFrames = 0;
}

void func_ov001_02196cd0(void) {
    s32 i;

    gRecordTAtt->mRecordTAttSTable[data_ov001_021a67c4[0]].mUnk_04 = -func_020adc64(6 - gRecordTAtt->mUnk_78[0]);
    gRecordTAtt->mRecordTAttSTable[data_ov001_021a67c4[1]].mUnk_04 = func_020adc64(6 - gRecordTAtt->mUnk_78[1]);
    for (i = 0; i < 2; i++) {
        if (gRecordTAtt->mUnk_78[i] > 0) {
            gRecordTAtt->mUnk_78[i]--;
            gRecordTAtt->mRecordTAttSTable[data_ov001_021a67c0[i]].mUnk_00 = 0;
            gRecordTAtt->mRecordTAttSTable[data_ov001_021a67c4[i]].mUnk_00 = 1;
        } else {
            gRecordTAtt->mRecordTAttSTable[data_ov001_021a67c0[i]].mUnk_00 = 1;
            gRecordTAtt->mRecordTAttSTable[data_ov001_021a67c4[i]].mUnk_00 = 0;
        }
    }
}

BOOL func_ov001_02196c4c(void) {
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    u16 m;

    m = data_02175628[idx].mUnk_00;
    if (m != 0) {
        if (data_ov001_021a681c[0] == (data_ov001_021a681c[0] | m)) {
            gRecordTAtt->mUnk_80 = 1;
            gRecordTAtt->mUnk_84 = FALSE;
        } else if (data_ov001_021a681c[gRecordTAtt->mUnk_80] == (data_ov001_021a681c[gRecordTAtt->mUnk_80] | m)) {
            gRecordTAtt->mUnk_80++;
            gRecordTAtt->mUnk_84 = FALSE;
            if (gRecordTAtt->mUnk_80 >= 6) {
                gRecordTAtt->mUnk_80 = 0;
                return TRUE;
            }
        } else {
            gRecordTAtt->mUnk_80 = 0;
        }
    }
    return FALSE;
}

void InitRecordTAtt(void *heap) {
    s32 i;
    s32 k;
    s32 rem;
    RecordTAtt *p;

    (reg_G2_BG0CNT) = ((reg_G2_BG0CNT) & ~3) | 1;
    (reg_G2_BG1CNT) = ((reg_G2_BG1CNT) & ~3) | 1;
    (reg_G2S_DB_BG3CNT) = ((reg_G2S_DB_BG3CNT) & ~3) | 1;
    (reg_G2_BG0CNT) = ((reg_G2_BG0CNT) & 0x43) | 0x8800;
    (reg_G2_BG1CNT) = ((reg_G2_BG1CNT) & 0x43) | 0xcc00;
    (reg_G2S_DB_BG1CNT) = ((reg_G2S_DB_BG1CNT) & 0x43) | 0x1018;
    (reg_G2S_DB_BG3CNT) = ((reg_G2S_DB_BG3CNT) & 0x43) | 0x5810;
    gRecordTAtt = HeapAlloc(heap, 0x94);
    gRecordTAtt->mUnk_4c = heap;
    gRecordTAtt->mState = 0;
    gRecordTAtt->mIndex = 0;
    gRecordTAtt->mUnk_70 = 0;
    gRecordTAtt->mUnk_74 = FALSE;
    gRecordTAtt->mUnk_88 = FALSE;
    gRecordTAtt->mUnk_8c = FALSE;
    for (i = 0; i < 2; i++) {
        gRecordTAtt->mUnk_78[i] = 0;
    }
    LocateAndQueueRecordTAtt();
    func_021172a8(heap);
    func_020ae6d4(func_02111318(), func_0211130c());
    func_02124ed0(heap, gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMBnll, &gRecordTAtt->mRecordTAttMTable);
    func_02124ed0(heap, gRecordTAtt->mRecordTAttSBncl, gRecordTAtt->mRecordTAttSBnll, &gRecordTAtt->mRecordTAttSTable);
    gRecordTAtt->mCommonMessages = func_02047a28("common.bmg");
    gRecordTAtt->mGhostMessages = FindSceneFile("ghost.bmg");
    gRecordTAtt->mRecordMessages = FindSceneFile("record.bmg");
    rem = 0x8000;
    rem -= func_021243ac(heap, 0, gRecordTAtt->mRecordTAttMBnll, 0xc8, 0x10, 0, gRecordTAtt->mRecordTAttMNcer,
                         gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, rem);
    rem -= func_021243ac(heap, 1, gRecordTAtt->mRecordTAttMBnll, 0x46, 0x10, 1, gRecordTAtt->mRecordTAttMNcer,
                         gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, rem);
    rem -= func_021243ac(heap, 2, gRecordTAtt->mRecordTAttMBnll, 0x46, 0x10, 2, gRecordTAtt->mRecordTAttMNcer,
                         gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, rem);
    rem -= func_021243ac(heap, 3, gRecordTAtt->mRecordTAttMBnll, 0x7c, 0x10, 3, gRecordTAtt->mRecordTAttMNcer,
                         gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, rem);
    rem -= func_021243ac(heap, 4, gRecordTAtt->mRecordTAttMBnll, 0x64, 0x10, 4, gRecordTAtt->mRecordTAttMNcer,
                         gRecordTAtt->mRecordTAttMBncl, gRecordTAtt->mRecordTAttMTable, rem);
    rem = func_02148ca0();
    for (k = 1; k < 5; k++) {
        rem -= func_021243ac(heap, data_ov001_021a67d4[k], gRecordTAtt->mRecordTAttSBnll, data_ov001_021a67c8[k],
                             data_ov001_021a67e0[k], k, gRecordTAtt->mRecordTAttSNcer, gRecordTAtt->mRecordTAttSBncl,
                             gRecordTAtt->mRecordTAttSTable, rem);
        rem -= func_021243ac(heap, data_ov001_021a6810[k], gRecordTAtt->mRecordTAttSBnll, data_ov001_021a6804[k],
                             data_ov001_021a67ec[k], k + 5, gRecordTAtt->mRecordTAttSNcer,
                             gRecordTAtt->mRecordTAttSBncl, gRecordTAtt->mRecordTAttSTable, rem);
    }
    func_021243ac(heap, 8, gRecordTAtt->mRecordTAttSBnll, 0x98, 0x10, 0xd, gRecordTAtt->mRecordTAttSNcer,
                  gRecordTAtt->mRecordTAttSBncl, gRecordTAtt->mRecordTAttSTable, rem);
    p = gRecordTAtt;
    func_0212426c(1, 8, gRecordTAtt->mRecordTAttSBnll, GetBmgEntry(p->mRecordMessages, 3), p->mRecordTAttSBncl,
                  p->mRecordTAttSTable);
    func_ov001_02197058();
}

void func_ov001_02196904(void) {
    u32 a;
    u32 b;

    func_02117218();
    gRecordTAtt = NULL;
    a = ((reg_GX_DISPCNT) & 0x1f00) >> 8;
    (reg_GX_DISPCNT) = ((reg_GX_DISPCNT) & ~0x1f00) | ((a & ~0x13) << 8);
    b = ((reg_GXS_DB_DISPCNT) & 0x1f00) >> 8;
    (reg_GXS_DB_DISPCNT) = ((reg_GXS_DB_DISPCNT) & ~0x1f00) | ((b & ~9) << 8);
}

void AdvanceRecordTAttState0(void) {
    s16 v;

    gRecordTAtt->mStateFrames++;
    v = func_020ae4c0(1, -0xc0, 0, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg0Offset = v;
    gRecordTAtt->mBg1OffsetY = v;
    gRecordTAtt->mRecordTAttMTable[0].mUnk_06 = v;
    if (gRecordTAtt->mStateFrames >= 10) {
        func_ov001_0219703c();
    }
}

void AdvanceRecordTAttState1(void) {
    s32 i;
    u16 x;
    u16 y;
    s32 j;
    s16 v;

    gRecordTAtt->mStateFrames++;
    v = func_020ae4c0(1, 0x100, 0, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg1OffsetX = v;
    gRecordTAtt->mBg3OffsetX = v;
    x = gRecordTAtt->mRecordTAttMBncl->mUnk_06;
    y = gRecordTAtt->mRecordTAttSBncl->mUnk_06;
    gRecordTAtt->mRecordTAttMTable[0].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[1].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[2].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[3].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[4].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[5].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[6].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 1].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 2].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 3].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 4].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[15].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[16].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[12].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[13].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[14].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[y + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[y + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[y + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mStateFrames >= 10) {
        func_ov001_02197024();
    }
}

void AdvanceRecordTAttState2(void) {
    s32 a = -1;
    s32 b = -1;
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    BOOL x;
    BOOL y;
    u16 v;

    func_ov001_02196cd0();
    x = TRUE;
    y = FALSE;
    v = data_02175628[idx].mHasPair;
    if (v == 0 && data_02175628[idx].mNoPairCount < 5) {
        y = TRUE;
    }
    if (y == FALSE && v == 0) {
        x = FALSE;
    }
    if (x != FALSE) {
        a = RectTableFindContaining(gRecordTAtt->mRecordTAttSBnbl, data_02175628[idx].mUnk_48,
                                    data_02175628[idx].mUnk_4a);
    }
    x = FALSE;
    y = FALSE;
    v = data_02175628[idx].mHasPair;
    if (v == 0 && data_02175628[idx].mNoPairCount < 5) {
        y = TRUE;
    }
    if (y == FALSE && data_02175628[idx].mPrevHasPair == 0 && v != 0) {
        x = TRUE;
    }
    if (x != FALSE) {
        b = RectTableFindContaining(gRecordTAtt->mRecordTAttSBnbl, data_02175628[idx].mUnk_48,
                                    data_02175628[idx].mUnk_4a);
    }
    if (a != 0) {
        gRecordTAtt->mUnk_88 = FALSE;
    }
    if (a != 1) {
        gRecordTAtt->mUnk_8c = FALSE;
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 2) == 0) {
        x = FALSE;
        y = FALSE;
        v = data_02175628[idx].mHasPair;
        if (v == 0 && data_02175628[idx].mNoPairCount < 5) {
            y = TRUE;
        }
        if (y == FALSE && data_02175628[idx].mPrevHasPair == 0 && v != 0) {
            x = TRUE;
        }
        if (x == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[idx].mUnk_48,
                                                                          data_02175628[idx].mUnk_4a) == FALSE) {
            goto other;
        }
    }
    RequestRecordTAttState5();
    gRecordTAtt->mUnk_90 = 0;
    func_02128310(0);
    goto done;
other:
    if (b == 2 || (u16) (data_02175628[idx].mUnk_00 & 0x400) != 0) {
        func_ov001_02196f80();
    } else if ((a == 0 && gRecordTAtt->mUnk_88 != FALSE) || (b == 0 && gRecordTAtt->mUnk_88 == FALSE) ||
               (u16) (data_02175628[idx].mBits & 0x20) != 0) {
        gRecordTAtt->mUnk_70 = 1;
        gRecordTAtt->mUnk_78[0] = 6;
        gRecordTAtt->mUnk_88 = TRUE;
        RequestRecordTAttState3();
        func_0212ecc0(&data_0217d068, 0, 2);
    } else if ((a == 1 && gRecordTAtt->mUnk_8c != FALSE) || (b == 1 && gRecordTAtt->mUnk_8c == FALSE) ||
               (u16) (data_02175628[idx].mBits & 0x10) != 0) {
        gRecordTAtt->mUnk_70 = 0;
        gRecordTAtt->mUnk_78[1] = 6;
        gRecordTAtt->mUnk_8c = TRUE;
        RequestRecordTAttState3();
        func_0212ecc0(&data_0217d068, 0, 2);
    }
done:
    if (func_ov001_02196c4c() != FALSE) {
        if (func_ov001_02197210() != FALSE) {
            func_ov001_02196e30();
        }
    }
}

void AdvanceRecordTAttState3(void) {
    s32 i;
    u16 x;
    u16 y;
    s32 j;
    s16 k;
    s16 v;

    k = 0;
    func_ov001_02196cd0();
    switch (gRecordTAtt->mUnk_70) {
        case 0:
            k = -0x100;
            break;
        case 1:
            k = 0x100;
            break;
    }
    gRecordTAtt->mStateFrames++;
    v = func_020ae4c0(1, 0, k, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg1OffsetX = v;
    gRecordTAtt->mBg3OffsetX = v;
    x = gRecordTAtt->mRecordTAttMBncl->mUnk_06;
    y = gRecordTAtt->mRecordTAttSBncl->mUnk_06;
    gRecordTAtt->mRecordTAttMTable[0].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[1].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[2].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[3].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[4].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[5].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[6].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 1].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 2].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 3].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 4].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[y + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[y + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mStateFrames >= 10) {
        func_ov001_02196fd8();
    }
}

void AdvanceRecordTAttState4(void) {
    s32 i;
    u16 x;
    u16 y;
    s32 j;
    s16 k;
    s16 v;

    k = 0;
    func_ov001_02196cd0();
    switch (gRecordTAtt->mUnk_70) {
        case 0:
            k = 0x100;
            break;
        case 1:
            k = -0x100;
            break;
    }
    gRecordTAtt->mStateFrames++;
    v = func_020ae4c0(1, k, 0, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg1OffsetX = v;
    gRecordTAtt->mBg3OffsetX = v;
    x = gRecordTAtt->mRecordTAttMBncl->mUnk_06;
    y = gRecordTAtt->mRecordTAttSBncl->mUnk_06;
    gRecordTAtt->mRecordTAttMTable[0].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[1].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[2].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[3].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[4].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[5].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[6].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 1].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 2].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 3].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 4].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[y + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[y + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mStateFrames >= 10) {
        func_ov001_02197024();
    }
}

void AdvanceRecordTAttState5(void) {
    s32 i;
    u16 x;
    u16 y;
    s32 j;
    s16 v;

    gRecordTAtt->mStateFrames++;
    v = func_020ae4c0(1, 0, 0x100, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg1OffsetX = v;
    gRecordTAtt->mBg3OffsetX = v;
    x = gRecordTAtt->mRecordTAttMBncl->mUnk_06;
    y = gRecordTAtt->mRecordTAttSBncl->mUnk_06;
    gRecordTAtt->mRecordTAttMTable[0].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[1].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[2].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[3].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[4].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[5].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[6].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 1].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 2].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 3].mUnk_04 = v;
    gRecordTAtt->mRecordTAttMTable[x + 4].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[15].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[16].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[12].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[13].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[14].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[y + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[y + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[y + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mStateFrames >= 10) {
        RequestRecordTAttState6();
    }
}

void AdvanceRecordTAttState6(void) {
    s16 v;

    gRecordTAtt->mStateFrames++;
    v = func_020ae4c0(1, 0, -0xc0, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg0Offset = v;
    gRecordTAtt->mBg1OffsetY = v;
    gRecordTAtt->mRecordTAttMTable[0].mUnk_06 = v;
    if (gRecordTAtt->mStateFrames >= 10) {
        func_02111488(gRecordTAtt->mUnk_90);
    }
}

void AdvanceRecordTAttState7(void) {
    s16 v;
    u16 x;

    gRecordTAtt->mStateFrames++;
    v = func_020ae488(gRecordTAtt->mStateFrames);
    x = gRecordTAtt->mRecordTAttSBncl->mUnk_06;
    gRecordTAtt->mRecordTAttSTable[12].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[13].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[14].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[x + 8].mUnk_04 = v;
    if (gRecordTAtt->mStateFrames >= 10) {
        func_ov001_02196f64();
    }
}

void AdvanceRecordTAttState8(void) {
    s32 i;
    u16 x;
    s32 j;
    s16 v;

    gRecordTAtt->mStateFrames++;
    v = func_020ae4c0(1, 0, 0x100, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg3OffsetX = v;
    x = gRecordTAtt->mRecordTAttSBncl->mUnk_06;
    gRecordTAtt->mRecordTAttSTable[15].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[16].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[12].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[13].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[14].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[x + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[x + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[x + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mStateFrames > 10) {
        if (IsSelectReturnState0NoState1Request() != 0) {
            func_ov001_02196ecc();
        }
    }
    if (gRecordTAtt->mStateFrames == 7) {
        gRecordTAtt->mRecordTAttSTable[12].mUnk_00 = 0;
        gRecordTAtt->mRecordTAttSTable[13].mUnk_00 = 0;
    }
}

void AdvanceRecordTAttState9(void) {
    if (func_02125fa4() != 0) {
        func_ov001_02196eb0();
    }
}

void AdvanceRecordTAttState10(void) {
    if (func_02125f54() != 0) {
        if (func_02125f60() == 0) {
            if (func_02060268(data_ov001_021a6900[gRecordTAtt->mIndex]) == 0) {
                func_02060004(data_ov001_021a6900[gRecordTAtt->mIndex]);
                func_02057d9c();
                if (data_021759d4->mUnk_0c != 0) {
                    func_02145d38();
                }
            }
            gRecordTAtt->mUnk_74 = TRUE;
        }
        func_ov001_02196e88();
    }
}

void AdvanceRecordTAttState11(void) {
    s16 v;
    u16 w;

    gRecordTAtt->mStateFrames++;
    if (gRecordTAtt->mUnk_74 != FALSE) {
        v = func_020ae4c0(1, 0, 0x100, gRecordTAtt->mStateFrames, 10);
        gRecordTAtt->mBg1OffsetX = v;
        w = gRecordTAtt->mRecordTAttMBncl->mUnk_06;
        gRecordTAtt->mRecordTAttMTable[0].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[1].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[2].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[3].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[4].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[5].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[6].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[w].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[w + 1].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[w + 2].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[w + 3].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[w + 4].mUnk_04 = v;
    }
    if (gRecordTAtt->mStateFrames >= 10) {
        if (func_02125f88() != 0) {
            func_ov001_02196e54();
        }
    }
}

void AdvanceRecordTAttState12(void) {
    s32 i;
    u16 x;
    s32 j;
    s16 v;

    gRecordTAtt->mStateFrames++;
    v = func_020ae4c0(1, 0x100, 0, gRecordTAtt->mStateFrames, 10);
    if (gRecordTAtt->mUnk_74 != FALSE) {
        u16 w;

        gRecordTAtt->mBg1OffsetX = v;
        w = gRecordTAtt->mRecordTAttMBncl->mUnk_06;
        gRecordTAtt->mRecordTAttMTable[0].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[1].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[2].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[3].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[4].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[5].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[6].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[w].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[w + 1].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[w + 2].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[w + 3].mUnk_04 = v;
        gRecordTAtt->mRecordTAttMTable[w + 4].mUnk_04 = v;
    }
    gRecordTAtt->mBg3OffsetX = v;
    x = gRecordTAtt->mRecordTAttSBncl->mUnk_06;
    gRecordTAtt->mRecordTAttSTable[15].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[16].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[12].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[13].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[14].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[x + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[x + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[x + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mStateFrames > 10) {
        if (IsSelectReturnState2NoState3Or4Request() != 0) {
            func_ov001_02197024();
        }
    }
    if (gRecordTAtt->mStateFrames == 2) {
        gRecordTAtt->mRecordTAttSTable[12].mUnk_00 = 1;
    }
}

void AdvanceRecordTAttState13(void) {
    s32 i;
    u16 x;
    s32 j;
    s16 v;

    gRecordTAtt->mStateFrames++;
    v = func_020ae4c0(1, 0, 0x100, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg3OffsetX = v;
    x = gRecordTAtt->mRecordTAttSBncl->mUnk_06;
    gRecordTAtt->mRecordTAttSTable[15].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[16].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[12].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[13].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[14].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[x + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[x + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[x + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mStateFrames > 10) {
        func_ov001_02196dbc();
    }
    if (gRecordTAtt->mStateFrames == 7) {
        gRecordTAtt->mRecordTAttSTable[12].mUnk_00 = 0;
        gRecordTAtt->mRecordTAttSTable[13].mUnk_00 = 0;
    }
}

void AdvanceRecordTAttState14(void) {
    int v1;
    v1 = func_02125fa4();
    if (v1 != 0) {
        RequestRecordTAttState15();
    }
    return;
}

void AdvanceRecordTAttState15(void) {
    Unk02175628Index i;
    u16 f;
    BOOL b;

    i = UNK_02175628_INDEX_8;
    f = data_02175628[i].mUnk_00 & 2;
    if (f == 0) {
        f = 0;
        b = FALSE;
        if (data_02175628[i].mHasPair == 0 && data_02175628[i].mNoPairCount < 5) {
            b = TRUE;
        }
        if (b == FALSE && data_02175628[i].mPrevHasPair == 0 && data_02175628[i].mHasPair != 0) {
            f = 1;
        }
        if (f == 0 || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[i].mUnk_48,
                                                                      data_02175628[i].mUnk_4a) == FALSE) {
            return;
        }
    }
    func_ov001_02196d8c();
    func_02128310(0);
}

void AdvanceRecordTAttState16(void) {
    int v1;
    v1 = func_02125f88();
    if (v1 != 0) {
        RequestRecordTAttState17();
    }
    return;
}

void AdvanceRecordTAttState17(void) {
    s32 i;
    s32 j;
    u16 m;
    s16 v;

    gRecordTAtt->mStateFrames++;
    v = func_020ae4c0(1, 0x100, 0, gRecordTAtt->mStateFrames, 10);
    gRecordTAtt->mBg3OffsetX = v;
    m = gRecordTAtt->mRecordTAttSBncl->mUnk_06;
    gRecordTAtt->mRecordTAttSTable[15].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[16].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[12].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[13].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[14].mUnk_04 = v;
    gRecordTAtt->mRecordTAttSTable[m + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mRecordTAttSTable[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[m + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mRecordTAttSTable[m + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mRecordTAttSTable[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mStateFrames > 10) {
        func_ov001_02197024();
    }
    if (gRecordTAtt->mStateFrames == 2) {
        gRecordTAtt->mRecordTAttSTable[12].mUnk_00 = 1;
    }
}

void AdvanceRecordTAtt(void) {
    RecordTAtt *p;

    gRecordTAtt->mState = gRecordTAtt->mNextState;
    switch (gRecordTAtt->mState) {
        case 0:
            AdvanceRecordTAttState0();
            break;
        case 1:
            AdvanceRecordTAttState1();
            break;
        case 2:
            AdvanceRecordTAttState2();
            break;
        case 3:
            AdvanceRecordTAttState3();
            break;
        case 4:
            AdvanceRecordTAttState4();
            break;
        case 5:
            AdvanceRecordTAttState5();
            break;
        case 6:
            AdvanceRecordTAttState6();
            break;
        case 7:
            AdvanceRecordTAttState7();
            break;
        case 8:
            AdvanceRecordTAttState8();
            break;
        case 9:
            AdvanceRecordTAttState9();
            break;
        case 10:
            AdvanceRecordTAttState10();
            break;
        case 11:
            AdvanceRecordTAttState11();
            break;
        case 12:
            AdvanceRecordTAttState12();
            break;
        case 13:
            AdvanceRecordTAttState13();
            break;
        case 14:
            AdvanceRecordTAttState14();
            break;
        case 15:
            AdvanceRecordTAttState15();
            break;
        case 16:
            AdvanceRecordTAttState16();
            break;
        case 17:
            AdvanceRecordTAttState17();
            break;
    }
    p = gRecordTAtt;
    func_02124c30(p->mRecordTAttMBncl, p->mRecordTAttMNcer, p->mRecordTAttMBnll, func_02111318(), p->mRecordTAttMTable);
    p = gRecordTAtt;
    func_02124c30(p->mRecordTAttSBncl, p->mRecordTAttSNcer, p->mRecordTAttSBnll, func_0211130c(), p->mRecordTAttSTable);
}

void func_ov001_0219574c(void) {
    RecordTAtt *p;

    *(vu32 *) 0x4000010 = (-gRecordTAtt->mBg0Offset << 16) & 0x1ff0000;
    p = gRecordTAtt;
    *(vu32 *) 0x4000014 = (-p->mBg1OffsetX & 0x1ff) | ((-p->mBg1OffsetY << 16) & 0x1ff0000);
    *(vu32 *) 0x400101c = -gRecordTAtt->mBg3OffsetX & 0x1ff;
    func_02111428();
}

void func_ov001_02195704(void) {
    u32 t;
    u32 u;

    t = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
    t |= 0x13;
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (t << 8);
    u = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    u |= 9;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (u << 8);
}

void RegisterRecordTAttCallbacks(void) {
    Unk021a8294 a = gRecordTAttCallbacks;

    func_02111494(&a);
}

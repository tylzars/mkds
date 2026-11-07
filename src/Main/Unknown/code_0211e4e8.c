#include "Main/Unknown/code_0211e4e8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/code_020d0efc.h"
#include "registers.h"

#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0211d000.h"
#include "Main/Unknown/code_0211f000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0211f380.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0212426c.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"

#pragma thumb on

void LocateAndQueueSelectCupM(void) {
    Ncgr *a;
    Nclr *b;
    Ncgr *c;
    Nclr *d;
    Ncgr *e;
    Nscr *f;
    Nclr *g;
    Ncgr *h;
    Nscr *i;
    Nclr *j;
    u16 *v;

    a = NULL;
    b = NULL;
    c = NULL;
    d = NULL;
    e = NULL;
    f = NULL;
    g = NULL;
    h = NULL;
    i = NULL;
    j = NULL;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return;
    }
    LocateNcgr(&e, FindSceneFile(gSelectCupMBNcgrName3));
    LocateNclr(&g, FindSceneFile(gSelectCupMBNclrName3));
    LocateNscr(&f, FindSceneFile(gSelectCupMNscrName3));
    LocateNcgr(&h, FindSceneFile(gSelectCupMBNcgrName3));
    LocateNclr(&j, FindSceneFile(gSelectCupMBNclrName3));
    LocateNscr(&i, FindSceneFile(gSelectCupMNscrName3));
    gSelectCupM->mUnk_20 = HeapAlloc(gSelectCupM->mHeap, 0x800);
    gSelectCupM->mMainBncl = FindSceneFile(gSelectCupMBnclName3);
    gSelectCupM->mMainBnll = FindSceneFile(gSelectCupMBnllName3);
    LocateNcgr2(&a, FindSceneFile(gSelectCupMNcgrName3));
    LocateNcer(&gSelectCupM->mMainNcer, FindSceneFile(gSelectCupMNcerName3));
    LocateNclr(&b, FindSceneFile(gSelectCupMONclrName3));
    gSelectCupM->mSubBncl = FindSceneFile(gSelectCupMBnclName3);
    gSelectCupM->mSubBnll = FindSceneFile(gSelectCupMBnllName3);
    LocateNcgr2(&c, FindSceneFile(gSelectCupMNcgrName3));
    LocateNcer(&gSelectCupM->mSubNcer, FindSceneFile(gSelectCupMNcerName3));
    LocateNclr(&d, FindSceneFile(gSelectCupMONclrName3));
    v = b->mData;
    if (!(GetPreviousMenuScreenNumber() == 0x17 || GetPreviousMenuScreenNumber() == 0xb)) {
        CallQueueAppend(4, 0, e->mData, e->mDataSize);
        CallQueueAppend(0xf, 0, g->mData, 0x140);
        CallQueueAppend(8, 0, f->mData, f->mDataSize);
        CallQueueAppend(8, 0x800, gSelectCupM->mUnk_20, 0x800);
    }
    if (!(GetPreviousMenuScreenNumber() == 0x19 || GetPreviousMenuScreenNumber() == 0xd)) {
        CallQueueAppend(0x17, 0, h->mData, h->mDataSize);
        CallQueueAppend(0x1f, 0, j->mData, 0x140);
        CallQueueAppend(0x1b, 0, i->mData, i->mDataSize);
        CallQueueAppend(0x1b, 0x800, gSelectCupM->mUnk_20, 0x800);
    }
    CallQueueAppend(0x13, 0, a->mData, a->mDataSize);
    CallQueueAppend(0xe, 0, b->mData, 0x1a0);
    CallQueueAppend(0xe, 0x1c0, v + 0xe0, 0x40);
    CallQueueAppend(0x23, 0, c->mData, c->mDataSize);
    CallQueueAppend(0x1e, 0, d->mData, d->mDataSize);
}

void InitSelectCupMCellsAndRequestCupPicture(void) {
    s32 i;
    u16 c;
    u16 d;
    s32 j;
    BOOL n;
    BOOL v;
    s32 m;
    s32 a;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return;
    }
    c = gSelectCupM->mMainBncl->mUnk_06;
    d = gSelectCupM->mSubBncl->mUnk_06;
    v = FALSE;
    for (i = 0; i < 8; i++) {
        gSelectCupM->mMainTable[data_0215cf1c[i]].mUnk_00 = v;
        gSelectCupM->mSubTable[data_0215cf1c[i]].mUnk_00 = v;
    }
    for (i = 0; i < 4; i++) {
        gSelectCupM->mMainTable[data_0215cefc[i]].mUnk_00 = 0;
        gSelectCupM->mSubTable[data_0215cefc[i]].mUnk_00 = 0;
    }
    for (i = 0; i < 4; i++) {
        gSelectCupM->mMainTable[data_0215cf04[i]].mUnk_00 = 0;
        gSelectCupM->mMainTable[c + data_0215cf0c[i]].mUnk_00 = 1;
        gSelectCupM->mSubTable[data_0215cf04[i]].mUnk_00 = 0;
        gSelectCupM->mSubTable[d + data_0215cf0c[i]].mUnk_00 = 1;
    }
    gSelectCupM->mMainTable[20].mUnk_00 = 0;
    gSelectCupM->mMainTable[19].mUnk_00 = 1;
    gSelectCupM->mSubTable[20].mUnk_00 = 0;
    gSelectCupM->mSubTable[19].mUnk_00 = 1;
    QueueSelectCupNameM(data_0215cf2c[GetCupIndex()], gSelectCupM->mMainNcer, gSelectCupM->mMainBncl, 0x13, 0);
    QueueSelectCupNameM(data_0215cf2c[GetCupIndex()], gSelectCupM->mSubNcer, gSelectCupM->mSubBncl, 0x13, 1);
    n = FALSE;
    for (j = 0; j < 4; j++) {
        func_0212426c(n, data_0215cf0c[j], gSelectCupM->mMainBnll,
                      GetBmgEntry(gSelectCupM->mCommonMessages, data_0215cf4c[data_0215cf2c[GetCupIndex()]][j]),
                      gSelectCupM->mMainBncl, gSelectCupM->mMainTable);
        func_0212426c(1, data_0215cf0c[j], gSelectCupM->mSubBnll,
                      GetBmgEntry(gSelectCupM->mCommonMessages, data_0215cf4c[data_0215cf2c[GetCupIndex()]][j]),
                      gSelectCupM->mSubBncl, gSelectCupM->mSubTable);
    }
    a = data_0215cf04[0];
    gSelectCupM->mMainTable[a].mUnk_00 = 1;
    j = data_0215cf0c[0];
    func_02124100(j, 0xe, gSelectCupM->mMainBnll, gSelectCupM->mMainTable, gSelectCupM->mMainBncl);
    gSelectCupM->mSubTable[a].mUnk_00 = 1;
    func_02124100(j, 0xe, gSelectCupM->mSubBnll, gSelectCupM->mSubTable, gSelectCupM->mSubBncl);
    for (m = 1; m < 4; m++) {
        gSelectCupM->mMainTable[data_0215cf04[m]].mUnk_00 = 0;
        func_02124100(data_0215cf0c[m], 0xf, gSelectCupM->mMainBnll, gSelectCupM->mMainTable, gSelectCupM->mMainBncl);
        gSelectCupM->mSubTable[data_0215cf04[m]].mUnk_00 = 0;
        func_02124100(data_0215cf0c[m], 0xf, gSelectCupM->mSubBnll, gSelectCupM->mSubTable, gSelectCupM->mSubBncl);
    }
    TrySetCupPictureIndexAndQueueLoads(data_0215cf8c[data_0215cf2c[GetCupIndex()]][0]);
    gSelectCupM->mCupPicturePending = TRUE;
}

void StartSelectCupMState0(void) {
    s32 i;
    u16 c;
    u16 d;

    gSelectCupM->mNextState = 0;
    gSelectCupM->mStateFrames = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return;
    }
    c = gSelectCupM->mMainBncl->mUnk_06;
    d = gSelectCupM->mSubBncl->mUnk_06;
    gSelectCupM->mBg0Offset = 0;
    gSelectCupM->mMainTable[20].mUnk_06 = 0;
    gSelectCupM->mMainTable[19].mUnk_06 = 0;
    gSelectCupM->mMainTable[2].mUnk_06 = 0;
    gSelectCupM->mMainTable[1].mUnk_06 = 0;
    gSelectCupM->mMainTable[0].mUnk_06 = 0;
    for (i = 0; i < 8; i++) {
        gSelectCupM->mMainTable[data_0215cf1c[i]].mUnk_06 = 0;
    }
    for (i = 0; i < 4; i++) {
        gSelectCupM->mMainTable[data_0215cf04[i]].mUnk_06 = 0;
        gSelectCupM->mMainTable[c + data_0215cf0c[i]].mUnk_06 = 0;
    }
    gSelectCupM->mBg3Offset = ~0xbf;
    gSelectCupM->mSubTable[20].mUnk_06 = ~0xbf;
    gSelectCupM->mSubTable[19].mUnk_06 = ~0xbf;
    gSelectCupM->mSubTable[2].mUnk_06 = ~0xbf;
    gSelectCupM->mSubTable[1].mUnk_06 = ~0xbf;
    gSelectCupM->mSubTable[0].mUnk_06 = ~0xbf;
    for (i = 0; i < 8; i++) {
        gSelectCupM->mSubTable[data_0215cf1c[i]].mUnk_06 = ~0xbf;
    }
    for (i = 0; i < 4; i++) {
        gSelectCupM->mSubTable[data_0215cf04[i]].mUnk_06 = ~0xbf;
        gSelectCupM->mSubTable[d + data_0215cf0c[i]].mUnk_06 = ~0xbf;
    }
}

void StartSelectCupMState1(void) {
    s32 i;
    u16 c;
    u16 d;

    gSelectCupM->mNextState = 1;
    gSelectCupM->mStateFrames = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return;
    }
    c = gSelectCupM->mMainBncl->mUnk_06;
    d = gSelectCupM->mSubBncl->mUnk_06;
    gSelectCupM->mBg0Offset = 0xc0;
    gSelectCupM->mMainTable[20].mUnk_06 = 0xc0;
    gSelectCupM->mMainTable[19].mUnk_06 = 0xc0;
    gSelectCupM->mMainTable[2].mUnk_06 = 0xc0;
    gSelectCupM->mMainTable[1].mUnk_06 = 0xc0;
    gSelectCupM->mMainTable[0].mUnk_06 = 0xc0;
    for (i = 0; i < 8; i++) {
        gSelectCupM->mMainTable[data_0215cf1c[i]].mUnk_06 = 0xc0;
    }
    for (i = 0; i < 4; i++) {
        gSelectCupM->mMainTable[data_0215cf04[i]].mUnk_06 = 0xc0;
        gSelectCupM->mMainTable[c + data_0215cf0c[i]].mUnk_06 = 0xc0;
    }
    gSelectCupM->mBg3Offset = ~0x1f;
    gSelectCupM->mSubTable[20].mUnk_06 = ~0x1f;
    gSelectCupM->mSubTable[19].mUnk_06 = ~0x1f;
    gSelectCupM->mSubTable[2].mUnk_06 = ~0x1f;
    gSelectCupM->mSubTable[1].mUnk_06 = ~0x1f;
    gSelectCupM->mSubTable[0].mUnk_06 = ~0x1f;
    for (i = 0; i < 8; i++) {
        gSelectCupM->mSubTable[data_0215cf1c[i]].mUnk_06 = ~0x1f;
    }
    for (i = 0; i < 4; i++) {
        gSelectCupM->mSubTable[data_0215cf04[i]].mUnk_06 = ~0x1f;
        gSelectCupM->mSubTable[d + data_0215cf0c[i]].mUnk_06 = ~0x1f;
    }
}

void InitSelectCupM(void *a, void *b, void *c) {
    void *p;
    s32 i;
    s32 m;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8300;
    p = CreateFrmHeapFromMaxFree(a);
    gSelectCupM = HeapAlloc(p, 0x54);
    gSelectCupM->mHeap = p;
    gSelectCupM->mCupPicturePending = FALSE;
    gSelectCupM->mUnk_48 = b;
    gSelectCupM->mUnk_4c = c;
    gSelectCupM->mUnk_50 = 0;
    if (GetPreviousMenuScreenNumber() == 0x19 || GetPreviousMenuScreenNumber() == 0xd) {
        gSelectCupM->mState = 1;
    } else {
        gSelectCupM->mState = 0;
    }
    LocateAndQueueSelectCupM();
    gSelectCupM->mCommonMessages = FindFileInLoadedArchives(data_0216e09c);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        InitLayoutTable(gSelectCupM->mHeap, gSelectCupM->mMainBncl, gSelectCupM->mMainBnll, &gSelectCupM->mMainTable);
        InitLayoutTable(gSelectCupM->mHeap, gSelectCupM->mSubBncl, gSelectCupM->mSubBnll, &gSelectCupM->mSubTable);
        m = 0x8000;
        for (i = 0; i < 4; i++) {
            m -= func_021243ac(gSelectCupM->mHeap, data_0215cf0c[i], gSelectCupM->mMainBnll, data_0215cef4[i],
                               data_0215cf14[i], data_0215cf04[i], gSelectCupM->mMainNcer, gSelectCupM->mMainBncl,
                               gSelectCupM->mMainTable, m);
        }
        i = GX_GetSizeOfSubOBJ();
        for (m = 0; m < 4; m++) {
            i -= func_021243ac(gSelectCupM->mHeap, data_0215cf0c[m], gSelectCupM->mSubBnll, data_0215cef4[m],
                               data_0215cf14[m], data_0215cf04[m], gSelectCupM->mSubNcer, gSelectCupM->mSubBncl,
                               gSelectCupM->mSubTable, i);
        }
        CreateSelectCupNameM(gSelectCupM->mHeap);
    } else {
        func_0211f4b0(gSelectCupM->mHeap, gSelectCupM->mUnk_4c);
        func_0211f380();
    }
    InitSelectCupMCellsAndRequestCupPicture();
    if (GetPreviousMenuScreenNumber() == 0x19 || GetPreviousMenuScreenNumber() == 0xd) {
        StartSelectCupMState1();
    } else {
        StartSelectCupMState0();
    }
    FrmHeapShrinkInParent(gSelectCupM->mHeap);
}

void ReleaseSelectCupM(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_0211de34();
    } else {
        func_0211f498();
    }
    HeapDestroy(gSelectCupM->mHeap);
    gSelectCupM = NULL;
}

void AdvanceSelectCupMState0(void) {
    s32 i;
    s16 a;
    s16 b;
    u16 c;
    u16 d;

    gSelectCupM->mStateFrames++;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return;
    }
    a = InterpolateS16(1, 0, 0xc0, gSelectCupM->mStateFrames, 0xa);
    b = InterpolateS16(1, ~0xbf, ~0x1f, gSelectCupM->mStateFrames, 0xa);
    c = gSelectCupM->mMainBncl->mUnk_06;
    gSelectCupM->mBg0Offset = a;
    gSelectCupM->mMainTable[20].mUnk_06 = a;
    gSelectCupM->mMainTable[19].mUnk_06 = a;
    gSelectCupM->mMainTable[2].mUnk_06 = a;
    gSelectCupM->mMainTable[1].mUnk_06 = a;
    gSelectCupM->mMainTable[0].mUnk_06 = a;
    for (i = 0; i < 8; i++) {
        gSelectCupM->mMainTable[data_0215cf1c[i]].mUnk_06 = a;
    }
    for (i = 0; i < 4; i++) {
        gSelectCupM->mMainTable[data_0215cf04[i]].mUnk_06 = a;
        gSelectCupM->mMainTable[c + data_0215cf0c[i]].mUnk_06 = a;
    }
    d = gSelectCupM->mSubBncl->mUnk_06;
    gSelectCupM->mBg3Offset = b;
    gSelectCupM->mSubTable[20].mUnk_06 = b;
    gSelectCupM->mSubTable[19].mUnk_06 = b;
    gSelectCupM->mSubTable[2].mUnk_06 = b;
    gSelectCupM->mSubTable[1].mUnk_06 = b;
    gSelectCupM->mSubTable[0].mUnk_06 = b;
    for (i = 0; i < 8; i++) {
        gSelectCupM->mSubTable[data_0215cf1c[i]].mUnk_06 = b;
    }
    for (i = 0; i < 4; i++) {
        gSelectCupM->mSubTable[data_0215cf04[i]].mUnk_06 = b;
        gSelectCupM->mSubTable[d + data_0215cf0c[i]].mUnk_06 = b;
    }
}

void AdvanceSelectCupMState1(void) {
    s32 i;
    s16 a;
    s16 b;
    u16 c;
    u16 d;

    gSelectCupM->mStateFrames++;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return;
    }
    a = InterpolateS16(1, 0xc0, 0, gSelectCupM->mStateFrames, 0xa);
    b = InterpolateS16(1, ~0x1f, ~0xbf, gSelectCupM->mStateFrames, 0xa);
    c = gSelectCupM->mMainBncl->mUnk_06;
    gSelectCupM->mBg0Offset = a;
    gSelectCupM->mMainTable[20].mUnk_06 = a;
    gSelectCupM->mMainTable[19].mUnk_06 = a;
    gSelectCupM->mMainTable[2].mUnk_06 = a;
    gSelectCupM->mMainTable[1].mUnk_06 = a;
    gSelectCupM->mMainTable[0].mUnk_06 = a;
    for (i = 0; i < 8; i++) {
        gSelectCupM->mMainTable[data_0215cf1c[i]].mUnk_06 = a;
    }
    for (i = 0; i < 4; i++) {
        gSelectCupM->mMainTable[data_0215cf04[i]].mUnk_06 = a;
        gSelectCupM->mMainTable[c + data_0215cf0c[i]].mUnk_06 = a;
    }
    d = gSelectCupM->mSubBncl->mUnk_06;
    gSelectCupM->mBg3Offset = b;
    gSelectCupM->mSubTable[20].mUnk_06 = b;
    gSelectCupM->mSubTable[19].mUnk_06 = b;
    gSelectCupM->mSubTable[2].mUnk_06 = b;
    gSelectCupM->mSubTable[1].mUnk_06 = b;
    gSelectCupM->mSubTable[0].mUnk_06 = b;
    for (i = 0; i < 8; i++) {
        gSelectCupM->mSubTable[data_0215cf1c[i]].mUnk_06 = b;
    }
    for (i = 0; i < 4; i++) {
        gSelectCupM->mSubTable[data_0215cf04[i]].mUnk_06 = b;
        gSelectCupM->mSubTable[d + data_0215cf0c[i]].mUnk_06 = b;
    }
}

s32 AdvanceSelectCupM(void) {
    s32 i;
    u16 *p;
    s32 n;
    s32 a;
    s32 b;

    gSelectCupM->mState = gSelectCupM->mNextState;
    switch (gSelectCupM->mState) {
        case 0:
            AdvanceSelectCupMState0();
            break;
        case 1:
            AdvanceSelectCupMState1();
            break;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        if (gSelectCupM->mCupPicturePending != FALSE && func_020d0ec4() != FALSE) {
            p = GetCupPictureNscrData();
            CallQueueAppend(0xf, 0, GetCupPictureNclrData(), 0xe0);
            CallQueueAppend(4, 0x20, GetCupPictureNcgrData(), 0xdc0);
            a = 8;
            b = 0x14;
            for (i = 0; i < 0xb; i++) {
                n = ((i + 8) << 5) + 0x16;
                CallQueueAppend(a, n << 1, p + n, b);
            }
            CallQueueAppend(0x1f, 0, GetCupPictureNclrData(), 0xe0);
            CallQueueAppend(0x17, 0x20, GetCupPictureNcgrData(), 0xdc0);
            a = 0x1b;
            for (i = 0; i < 0xb; i++) {
                n = ((i + 8) << 5) + 0x16;
                CallQueueAppend(a, n << 1, p + n, b);
            }
            gSelectCupM->mCupPicturePending = FALSE;
        }
        DrawLayoutTable(gSelectCupM->mMainBncl, gSelectCupM->mMainNcer, gSelectCupM->mMainBnll, gSelectCupM->mUnk_48,
                        gSelectCupM->mMainTable);
        DrawLayoutTable(gSelectCupM->mSubBncl, gSelectCupM->mSubNcer, gSelectCupM->mSubBnll, gSelectCupM->mUnk_4c,
                        gSelectCupM->mSubTable);
    } else {
        func_0211f39c();
    }
    if (gSelectCupM->mState == 0 && gSelectCupM->mStateFrames > 0xa) {
        return 1;
    }
    if (gSelectCupM->mState == 1 && gSelectCupM->mStateFrames > 0xa) {
        return 2;
    }
    return 0;
}

void WriteSelectCupMBgOffsets(void) {
    reg_G2_BG0OFS = (-gSelectCupM->mBg0Offset << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = (-gSelectCupM->mBg3Offset << 16) & 0x1ff0000;
}

#pragma thumb off

#include "01/code_0219b540.h"

#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_02048000.h"
#include "01/unk_021a9000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "code_02134398.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_021171a0.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_0212775c.h"
#include "01/code_0219c000.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_02117218.h"
#include "registers.h"
#include "Main/Unknown/code_02116000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_0211d000.h"
#include "Main/Unknown/code_0211e000.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0211732c.h"

SelectGhost *gSelectGhost;

void LoadSelectGhostAndKartIconData(void) {
    Ncgr *p3 = NULL;
    Unk02021dc8 *p4 = NULL;
    Nclr *p5 = NULL;
    Ncgr *p0 = NULL;
    Nclr *p2 = NULL;
    Nscr *p1 = NULL;

    LoadNcgrData(&p0, FindSceneFile(gSelectGhostSBNcgrName));
    LoadNscrData(&p1, FindSceneFile(gSelectGhostSNscrName));
    LoadNclrData(&p2, FindSceneFile(gSelectGhostSBNclrName));
    LoadNcgrData2(&p3, FindSceneFile(gSelectGhostSONcgrName));
    LoadNcerData(&p4, FindSceneFile(gSelectGhostSONcerName));
    LoadNclrData(&p5, FindSceneFile(gSelectGhostSONclrName));
    LoadCommonKartIconData();
}

void LocateAndQueueSelectGhost(void) {
    Ncgr *a;
    Ncgr *b;
    Nclr *c;
    Nscr *d;

    a = NULL;
    b = NULL;
    c = NULL;
    d = NULL;
    LocateNcgr(&b, FindSceneFile(gSelectGhostSBNcgrName));
    LocateNscr(&d, FindSceneFile(gSelectGhostSNscrName));
    LocateNclr(&c, FindSceneFile(gSelectGhostSBNclrName));
    gSelectGhost->mUnk_40 = HeapAlloc(gSelectGhost->mHeap, 0x800);
    gSelectGhost->mSelectCupCourseTaMBncl = FindSceneFile(gSelectCupCourseTaMBnclName);
    gSelectGhost->mSelectCupCourseTaMBnll = FindSceneFile(gSelectCupCourseTaMBnllName);
    LocateNcer(&gSelectGhost->mSelectCupCourseMNcer, FindSceneFile(gSelectCupCourseMNcerName));
    gSelectGhost->mSelectGhostSBncl = FindSceneFile(gSelectGhostSBnclName);
    gSelectGhost->mSelectGhostSBnbl = FindSceneFile(gSelectGhostSBnblName);
    gSelectGhost->mSelectGhostSBnll = FindSceneFile(gSelectGhostSBnllName);
    LocateNcgr2(&a, FindSceneFile(gSelectGhostSONcgrName));
    LocateNcer(&gSelectGhost->mSelectGhostSONcer, FindSceneFile(gSelectGhostSONcerName));
    LocateNclr(&gSelectGhost->mSelectGhostSONclr, FindSceneFile(gSelectGhostSONclrName));
    gSelectGhost->mPlayerCharacterMNcgr = func_020b4018(0);
    gSelectGhost->mPlayerCharacterMNcer = func_020b400c(0);
    gSelectGhost->mPlayerCharacterMONclr = func_020b4030(0);
    gSelectGhost->mPlayerCharacterMBncl = func_020b4000(0);
    CallQueueAppend(0x17, 0, b->mData, b->mDataSize);
    CallQueueAppend(0x1f, 0, c->mData, 0x20);
    CallQueueAppend(0x1b, 0, d->mData, d->mDataSize);
    CallQueueAppend(0x1b, 0x800, gSelectGhost->mUnk_40, 0x800);
    CallQueueAppend(0x23, 0, a->mData, a->mDataSize);
    CallQueueAppend(0x1e, 0, gSelectGhost->mSelectGhostSONclr->mData, gSelectGhost->mSelectGhostSONclr->mDataSize);
}

void ResetSelectGhost(void) {
    u16 cnt;
    s32 i;

    gSelectGhost->mNextState = 0;
    gSelectGhost->mStateFrames = 0;
    gSelectGhost->mBg0Offset = 0;
    gSelectGhost->mBg3Offset = -0xc0;
    for (i = 0; i < 6; i++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[i]].mOffsetY = -0xc0;
    }
    gSelectGhost->mSelectGhostSTable[10].mOffsetY = -0xc0;
    gSelectGhost->mSelectGhostSTable[11].mOffsetY = -0xc0;
    cnt = gSelectGhost->mSelectGhostSBncl->mUnk_06;
    for (i = 0; i < 5; i++) {
        gSelectGhost->mSelectGhostSTable[cnt + gSelectGhostSBnllIndices[i]].mOffsetY = -0xc0;
    }
    gSelectGhost->mSelectGhostSTable[cnt + 5].mOffsetY = -0xc0;
    for (i = 0; i < 2; i++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostTimerZeroSTableIndices[i]].mOffsetY = -0xc0;
        gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[i]].mOffsetY = -0xc0;
    }
}

// Requests state 1.
void RequestSelectGhostState1(void) {
    gSelectGhost->mNextState = 1;
    gSelectGhost->mStateFrames = 0;
}

// Requests state 2.
void RequestSelectGhostState2(void) {
    gSelectGhost->mNextState = 2;
    gSelectGhost->mStateFrames = 0;
}

void RequestSelectGhostState3(void) {
    gSelectGhost->mNextState = 3;
    gSelectGhost->mStateFrames = 0;
    StopPaletteBlend();
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
}

void RequestSelectGhostState4(void) {
    gSelectGhost->mNextState = 4;
    gSelectGhost->mStateFrames = 0;
    StartSelectChoises(GetBmgEntry(gSelectGhost->mCommonMessages, 4), GetBmgEntry(gSelectGhost->mCommonMessages, 2), 0);
}

// Requests state 5.
void RequestSelectGhostState5(void) {
    gSelectGhost->mNextState = 5;
    gSelectGhost->mStateFrames = 0;
}

void RequestSelectGhostState6(void) {
    gSelectGhost->mNextState = 6;
    gSelectGhost->mStateFrames = 0;
    RequestSelectChoisesState0();
}

// Requests state 7.
void RequestSelectGhostState7(void) {
    gSelectGhost->mNextState = 7;
    gSelectGhost->mStateFrames = 0;
}

void func_ov001_0219c358(void) {
    gSelectGhost->mSelectGhostSTable[10].mVisible = 1;
    gSelectGhost->mSelectGhostSTable[11].mVisible = 0;
    gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[0]].mVisible = 1;
    gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[1]].mVisible = 0;
    gSelectGhost->mSelectGhostSTable[10].mVisible = 0;
    gSelectGhost->mSelectGhostSTable[11].mVisible = 1;
}

// Stores both offsets and steps both timers; each timer switches its rows on or off.
void AdvanceSelectGhostOffsetTimers(void) {
    s32 i;
    gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[0]].mOffsetX =
        -func_020adc64(6 - gSelectGhost->mOffsetTimers[0]);
    gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[1]].mOffsetX =
        func_020adc64(6 - gSelectGhost->mOffsetTimers[1]);
    for (i = 0; i < 2; i++) {
        if (gSelectGhost->mOffsetTimers[i] > 0) {
            gSelectGhost->mOffsetTimers[i]--;
            gSelectGhost->mSelectGhostSTable[gSelectGhostTimerZeroSTableIndices[i]].mVisible = 0;
            gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[i]].mVisible = 1;
        } else {
            gSelectGhost->mSelectGhostSTable[gSelectGhostTimerZeroSTableIndices[i]].mVisible = 1;
            gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[i]].mVisible = 0;
        }
    }
}

void RefreshSelectGhostForIndex(void) {
    SelectGhost *p = gSelectGhost;
    Unk0201ea30 *q;
    u16 n;
    u16 a;
    u16 b;
    u16 x;
    u16 y;
    u8 *blk;
    s32 r;
    s32 k;
    u8 buf14[4];
    u16 buf18[16];

    q = p->mSelectGhostSBncl;
    n = q->mUnk_06;
    func_0212426c(1, gSelectGhostSBnllIndices[4], gSelectGhost->mSelectGhostSBnll,
                  GetBmgEntry(p->mMenuMessages, gSelectGhostMenuMessageIndices[p->mIndex]), q, p->mSelectGhostSTable);
    if (gSelectGhost->mIndex == 0) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[2]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[3]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[4]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[5]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[n + gSelectGhostSBnllIndices[0]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[n + gSelectGhostSBnllIndices[1]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[n + gSelectGhostSBnllIndices[2]].mVisible = 0;
        return;
    }
    gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[2]].mVisible = 1;
    gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[3]].mVisible = 1;
    a = gSelectGhostSTableIndices[4];
    gSelectGhost->mSelectGhostSTable[a].mVisible = 1;
    b = gSelectGhostSTableIndices[5];
    gSelectGhost->mSelectGhostSTable[b].mVisible = 1;
    gSelectGhost->mSelectGhostSTable[n + gSelectGhostSBnllIndices[0]].mVisible = 1;
    y = gSelectGhostSBnllIndices[1];
    gSelectGhost->mSelectGhostSTable[n + y].mVisible = 1;
    x = gSelectGhostSBnllIndices[2];
    gSelectGhost->mSelectGhostSTable[n + x].mVisible = 1;
    r = data_ov001_021a6b88[GetGhostRecordSetCharacterIndex(data_ov001_021a6b78[gSelectGhost->mIndex])];
    QueueCellChars(r, gSelectGhost->mPlayerCharacterMNcer, gSelectGhost->mPlayerCharacterMNcgr,
                   gSelectGhost->mPlayerCharacterMBncl, 1, a, gSelectGhost->mSelectGhostSONcer,
                   gSelectGhost->mSelectGhostSBncl);
    blk = gSelectGhost->mPlayerCharacterMONclr->mUnk_0c;
    CallQueueAppend(
        0x1e, 0x100,
        blk + (GetCellPaletteIndex(r, gSelectGhost->mPlayerCharacterMNcer, gSelectGhost->mPlayerCharacterMBncl) << 5),
        0x20);
    k = GetGhostRecordSetKartIndex(data_ov001_021a6b78[gSelectGhost->mIndex]);
    QueueKartIcon(k, gSelectGhost->mSelectGhostSONcer, gSelectGhost->mSelectGhostSBncl, b, 9, 1);
    GetGhostRecordSetTime(data_ov001_021a6b78[gSelectGhost->mIndex], buf14);
    func_02116b80(buf14, buf18);
    func_02124224(1, y, gSelectGhost->mSelectGhostSBnll, buf18, gSelectGhost->mSelectGhostSBncl,
                  gSelectGhost->mSelectGhostSTable, 9);
    GetGhostRecordSetName(data_ov001_021a6b78[gSelectGhost->mIndex], buf18);
    func_0212426c(1, x, gSelectGhost->mSelectGhostSBnll, buf18, gSelectGhost->mSelectGhostSBncl,
                  gSelectGhost->mSelectGhostSTable);
}

void func_ov001_0219c058(void) {
    BOOL ok = TRUE;
    gSelectGhost->mIndex++;
    if (gSelectGhost->mIndex >= 4) {
        gSelectGhost->mIndex = 0;
    }
    if (func_0211e160(data_ov001_021a6b78[gSelectGhost->mIndex]) == 0) {
        ok = FALSE;
        func_ov001_0219c058();
    }
    gSelectGhost->mOffsetTimers[1] = 6;
    if (ok != FALSE) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 1);
        RefreshSelectGhostForIndex();
    }
}

void func_ov001_0219bff4(void) {
    BOOL ok = TRUE;
    gSelectGhost->mIndex--;
    if (gSelectGhost->mIndex < 0) {
        gSelectGhost->mIndex = 3;
    }
    if (func_0211e160(data_ov001_021a6b78[gSelectGhost->mIndex]) == 0) {
        ok = FALSE;
        func_ov001_0219bff4();
    }
    gSelectGhost->mOffsetTimers[0] = 6;
    if (ok != FALSE) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 1);
        RefreshSelectGhostForIndex();
    }
}

void func_ov001_0219bfc0(void) {
    func_0202949c(data_ov001_021a6b78[gSelectGhost->mIndex]);
    func_0211e0c4(data_ov001_021a6b78[gSelectGhost->mIndex]);
}

void func_ov001_0219be5c(void) {
    u16 n = gSelectGhost->mSelectCupCourseTaMBncl->mUnk_06;

    gSelectGhost->mSelectCupCourseTaMTable[0].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[2].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[1].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[4].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[3].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[5].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[n].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[n + 1].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[n + 2].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[n + 3].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[n + 4].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[n + 5].mVisible = 1;
    QueueSelectCupNameM(data_ov001_021a6ba4[GetCupIndex()], gSelectGhost->mSelectCupCourseMNcer,
                        gSelectGhost->mSelectCupCourseTaMBncl, 0, 0);
    QueueCupMark(data_ov001_021a6ba4[GetCupIndex()], gSelectGhost->mSelectCupCourseMNcer,
                 gSelectGhost->mSelectCupCourseTaMBncl, 5,
                 GetCellPaletteIndex(5, gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMBncl), 0);
    func_0212426c(0, 2, gSelectGhost->mSelectCupCourseTaMBnll, GetBmgEntry(gSelectGhost->mCommonMessages, 0x73),
                  gSelectGhost->mSelectCupCourseTaMBncl, gSelectGhost->mSelectCupCourseTaMTable);
    func_0212426c(0, 4, gSelectGhost->mSelectCupCourseTaMBnll, GetBmgEntry(gSelectGhost->mCommonMessages, 0x74),
                  gSelectGhost->mSelectCupCourseTaMBncl, gSelectGhost->mSelectCupCourseTaMTable);
    func_02124140(0, 0, gSelectGhost->mSelectCupCourseTaMBnll, gSelectGhost->mSelectCupCourseTaMTable,
                  gSelectGhost->mSelectCupCourseTaMBncl);
    func_02124140(1, 0, gSelectGhost->mSelectCupCourseTaMBnll, gSelectGhost->mSelectCupCourseTaMTable,
                  gSelectGhost->mSelectCupCourseTaMBncl);
    func_02124140(2, 0, gSelectGhost->mSelectCupCourseTaMBnll, gSelectGhost->mSelectCupCourseTaMTable,
                  gSelectGhost->mSelectCupCourseTaMBncl);
    func_02124140(4, 0, gSelectGhost->mSelectCupCourseTaMBnll, gSelectGhost->mSelectCupCourseTaMTable,
                  gSelectGhost->mSelectCupCourseTaMBncl);
}

void InitSelectGhost(void *a, u32 b, u32 c) {
    void *heap;
    s32 rem;
    s32 i;

    reg_G2S_DB_BG0CNT = reg_G2S_DB_BG0CNT & ~3;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8300;
    heap = CreateFrmHeapFromMaxFree(a);
    gSelectGhost = HeapAlloc(heap, 0x70);
    gSelectGhost->mHeap = heap;
    gSelectGhost->mState = 0;
    gSelectGhost->mIndex = 0;
    gSelectGhost->mUnk_64 = b;
    gSelectGhost->mUnk_68 = c;
    gSelectGhost->mResult = 0;
    LocateAndQueueSelectGhost();
    CreateCommonKartIcon(gSelectGhost->mHeap);
    InitLayoutTable(gSelectGhost->mHeap, gSelectGhost->mSelectCupCourseTaMBncl, gSelectGhost->mSelectCupCourseTaMBnll,
                    &gSelectGhost->mSelectCupCourseTaMTable);
    InitLayoutTable(gSelectGhost->mHeap, gSelectGhost->mSelectGhostSBncl, gSelectGhost->mSelectGhostSBnll,
                    &gSelectGhost->mSelectGhostSTable);
    gSelectGhost->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    gSelectGhost->mMenuMessages = FindSceneFile("menu.bmg");
    rem = 0x8000;
    rem -= InitLabelCanvas(gSelectGhost->mHeap, 0, gSelectGhost->mSelectCupCourseTaMBnll, 0xb4, 0xd, 0,
                           gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMBncl,
                           gSelectGhost->mSelectCupCourseTaMTable, rem);
    rem -= InitLabelCanvas(gSelectGhost->mHeap, 1, gSelectGhost->mSelectCupCourseTaMBnll, 0xb4, 0xd, 1,
                           gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMBncl,
                           gSelectGhost->mSelectCupCourseTaMTable, rem);
    rem -= InitLabelCanvas(gSelectGhost->mHeap, 2, gSelectGhost->mSelectCupCourseTaMBnll, 0x96, 0xd, 2,
                           gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMBncl,
                           gSelectGhost->mSelectCupCourseTaMTable, rem);
    rem -= InitLabelCanvas(gSelectGhost->mHeap, 3, gSelectGhost->mSelectCupCourseTaMBnll, 0x50, 0xd, 3,
                           gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMBncl,
                           gSelectGhost->mSelectCupCourseTaMTable, rem);
    rem -= InitLabelCanvas(gSelectGhost->mHeap, 4, gSelectGhost->mSelectCupCourseTaMBnll, 0x96, 0xd, 4,
                           gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMBncl,
                           gSelectGhost->mSelectCupCourseTaMTable, rem);
    InitLabelCanvas(gSelectGhost->mHeap, 5, gSelectGhost->mSelectCupCourseTaMBnll, 0x50, 0xd, 5,
                    gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMBncl,
                    gSelectGhost->mSelectCupCourseTaMTable, rem);
    rem = GX_GetSizeOfSubOBJ();
    for (i = 0; i < 5; i++) {
        rem -= InitLabelCanvas(gSelectGhost->mHeap, gSelectGhostSBnllIndices[i], gSelectGhost->mSelectGhostSBnll,
                               data_ov001_021a6b48[i], data_ov001_021a6b60[i], i, gSelectGhost->mSelectGhostSONcer,
                               gSelectGhost->mSelectGhostSBncl, gSelectGhost->mSelectGhostSTable, rem);
    }
    InitLabelCanvas(gSelectGhost->mHeap, 5, gSelectGhost->mSelectGhostSBnll, 0x32, 0xd, 0xb,
                    gSelectGhost->mSelectGhostSONcer, gSelectGhost->mSelectGhostSBncl, gSelectGhost->mSelectGhostSTable,
                    rem);
    func_0212426c(1, gSelectGhostSBnllIndices[0], gSelectGhost->mSelectGhostSBnll,
                  GetBmgEntry(gSelectGhost->mMenuMessages, 8), gSelectGhost->mSelectGhostSBncl,
                  gSelectGhost->mSelectGhostSTable);
    func_0212426c(1, gSelectGhostSBnllIndices[3], gSelectGhost->mSelectGhostSBnll,
                  GetBmgEntry(gSelectGhost->mMenuMessages, 9), gSelectGhost->mSelectGhostSBncl,
                  gSelectGhost->mSelectGhostSTable);
    func_0212426c(1, gSelectGhostSBnllIndices[4], gSelectGhost->mSelectGhostSBnll,
                  GetBmgEntry(gSelectGhost->mMenuMessages, gSelectGhostMenuMessageIndices[0]),
                  gSelectGhost->mSelectGhostSBncl, gSelectGhost->mSelectGhostSTable);
    func_0212426c(1, 5, gSelectGhost->mSelectGhostSBnll, GetBmgEntry(gSelectGhost->mCommonMessages, 4),
                  gSelectGhost->mSelectGhostSBncl, gSelectGhost->mSelectGhostSTable);
    CreateSelectCupNameM(gSelectGhost->mHeap);
    CreateCommonCupMark(gSelectGhost->mHeap);
    InitPaletteBlend(gSelectGhost->mHeap, gSelectGhost->mSelectGhostSONclr, 4);
    ResetPaletteBlendCycle();
    func_ov001_0219be5c();
    ResetSelectGhost();
    for (i = 3; i >= 0; i--) {
        if (func_0211e160(data_ov001_021a6b78[i]) != 0) {
            gSelectGhost->mIndex = i;
            break;
        }
    }
    RefreshSelectGhostForIndex();
    FrmHeapShrinkInParent(gSelectGhost->mHeap);
}

void ReleaseSelectGhost(void) {
    if (gSelectGhost->mResult == 1) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x1800;
    }
    func_0212b91c();
    ClearSelectCupNameMPointer();
    ClearCupMarkPointer();
    ClearKartIconPointer();
    HeapDestroy(gSelectGhost->mHeap);
    gSelectGhost = NULL;
}

void AdvanceSelectGhostState0(void) {
    u16 n;
    s16 v;
    s32 i;

    AdvanceSelectGhostOffsetTimers();
    n = gSelectGhost->mSelectGhostSBncl->mUnk_06;
    gSelectGhost->mStateFrames++;
    v = InterpolateS16(1, ~0xbf, 0, gSelectGhost->mStateFrames, 10);
    gSelectGhost->mBg3Offset = v;
    for (i = 0; i < 6; i++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[i]].mOffsetY = v;
    }
    for (i = 0; i < 5; i++) {
        gSelectGhost->mSelectGhostSTable[n + gSelectGhostSBnllIndices[i]].mOffsetY = v;
    }
    for (i = 0; i < 2; i++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostTimerZeroSTableIndices[i]].mOffsetY = v;
        gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[i]].mOffsetY = v;
    }
    if (gSelectGhost->mStateFrames >= 10) {
        RequestSelectGhostState1();
    }
}

void AdvanceSelectGhostState1(void) {
    u16 n;
    s16 w;

    AdvanceSelectGhostOffsetTimers();
    n = gSelectGhost->mSelectGhostSBncl->mUnk_06;
    gSelectGhost->mStateFrames++;
    w = -LookupSelectReturnState1Bg2Offset(gSelectGhost->mStateFrames);
    gSelectGhost->mSelectGhostSTable[10].mOffsetY = w;
    gSelectGhost->mSelectGhostSTable[11].mOffsetY = w;
    gSelectGhost->mSelectGhostSTable[n + 5].mOffsetY = w;
    if (gSelectGhost->mStateFrames >= 10) {
        RequestSelectGhostState2();
    }
}

void AdvanceSelectGhostState2(void) {
    s32 r;
    BOOL b;
    BOOL a;
    BOOL d;
    BOOL c;
    InputSlotIndex idx;

    r = -1;
    AdvanceSelectGhostOffsetTimers();
    idx = UNK_02175628_INDEX_8;
    b = FALSE;
    a = FALSE;
    if (data_02175628[idx].mHasPair == 0 && data_02175628[idx].mNoPairCount < 5) {
        a = TRUE;
    }
    if (a == FALSE && data_02175628[idx].mPrevHasPair == 0 && data_02175628[idx].mHasPair != 0) {
        b = TRUE;
    }
    if (b != FALSE) {
        r = RectTableFindContaining(gSelectGhost->mSelectGhostSBnbl, data_02175628[idx].mPairX,
                                    data_02175628[idx].mPairY);
    }
    if ((u16) (data_02175628[idx].mUnk_00 & PAD_KEY_B) == 0) {
        d = FALSE;
        c = FALSE;
        if (data_02175628[idx].mHasPair == 0 && data_02175628[idx].mNoPairCount < 5) {
            c = TRUE;
        }
        if (c == FALSE && data_02175628[idx].mPrevHasPair == 0 && data_02175628[idx].mHasPair != 0) {
            d = TRUE;
        }
        if (d == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[idx].mPairX,
                                                                          data_02175628[idx].mPairY) == FALSE) {
            goto next;
        }
    }
    SetSelectReturnSoundId(14);
    RequestSelectGhostState7();
    gSelectGhost->mResult = 2;
    RequestSelectReturnState3WithSound(0);
    return;
next:
    if (r == 0) {
        func_ov001_0219bff4();
        return;
    }
    if (r == 1) {
        func_ov001_0219c058();
        return;
    }
    if (r == 3) {
        RequestSelectGhostState3();
        return;
    }
    if (r == 2) {
        func_ov001_0219c058();
        return;
    }
    if ((u16) (data_02175628[idx].mUnk_00 & PAD_KEY_A) != 0) {
        RequestSelectGhostState3();
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        func_ov001_0219bff4();
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        func_ov001_0219c058();
    }
}

void AdvanceSelectGhostState3(void) {
    AdvanceSelectGhostOffsetTimers();
    gSelectGhost->mStateFrames++;
    if (gSelectGhost->mStateFrames >= 10) {
        RequestSelectGhostState4();
    }
}

void AdvanceSelectGhostState4(void) {
    if (IsSelectChoisesState1NoState0Request() != 0) {
        RequestSelectGhostState5();
    }
}

void AdvanceSelectGhostState5(void) {
    int v1;
    v1 = GetSelectChoisesDone();
    if (v1 != 0) {
        RequestSelectGhostState6();
    }
}

void AdvanceSelectGhostState6(void) {
    s32 r;

    if (IsSelectChoisesState0NoState1Request() == 0) {
        return;
    }
    r = GetSelectChoisesIndex();
    switch (r) {
        case 0:
            func_ov001_0219bfc0();
            gSelectGhost->mResult = 1;
            RequestSelectGhostState7();
            RequestSelectReturnState4();
            break;
        case -1:
        case 1:
            StartPaletteBlend();
            RequestSelectGhostState2();
            break;
    }
}

void AdvanceSelectGhostState7(void) {
    BOOL flag;
    s16 v;
    s16 w;
    u16 n;
    s32 i;

    flag = gSelectGhost->mResult == 1;
    gSelectGhost->mStateFrames++;
    v = InterpolateS16(1, 0, ~0xbf, gSelectGhost->mStateFrames, 10);
    if (flag) {
        n = gSelectGhost->mSelectCupCourseTaMBncl->mUnk_06;
        gSelectGhost->mBg0Offset = v;
        gSelectGhost->mSelectCupCourseTaMTable[0].mOffsetY = v;
        gSelectGhost->mSelectCupCourseTaMTable[2].mOffsetY = v;
        gSelectGhost->mSelectCupCourseTaMTable[1].mOffsetY = v;
        gSelectGhost->mSelectCupCourseTaMTable[4].mOffsetY = v;
        gSelectGhost->mSelectCupCourseTaMTable[3].mOffsetY = v;
        gSelectGhost->mSelectCupCourseTaMTable[5].mOffsetY = v;
        gSelectGhost->mSelectCupCourseTaMTable[n].mOffsetY = v;
        gSelectGhost->mSelectCupCourseTaMTable[n + 1].mOffsetY = v;
        gSelectGhost->mSelectCupCourseTaMTable[n + 2].mOffsetY = v;
        gSelectGhost->mSelectCupCourseTaMTable[n + 3].mOffsetY = v;
        gSelectGhost->mSelectCupCourseTaMTable[n + 4].mOffsetY = v;
        gSelectGhost->mSelectCupCourseTaMTable[n + 5].mOffsetY = v;
    }
    n = gSelectGhost->mSelectGhostSBncl->mUnk_06;
    w = -LookupSelectReturnState4Bg2Offset(gSelectGhost->mStateFrames);
    gSelectGhost->mBg3Offset = v;
    for (i = 0; i < 6; i++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[i]].mOffsetY = v;
    }
    gSelectGhost->mSelectGhostSTable[10].mOffsetY = w;
    gSelectGhost->mSelectGhostSTable[11].mOffsetY = w;
    for (i = 0; i < 5; i++) {
        gSelectGhost->mSelectGhostSTable[n + gSelectGhostSBnllIndices[i]].mOffsetY = v;
    }
    for (i = 0; i < 2; i++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostTimerZeroSTableIndices[i]].mOffsetY = v;
        gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[i]].mOffsetY = v;
    }
    gSelectGhost->mSelectGhostSTable[n + 5].mOffsetY = w;
}

int AdvanceSelectGhost(void) {
    gSelectGhost->mState = gSelectGhost->mNextState;
    switch (gSelectGhost->mState) {
        case 0:
            AdvanceSelectGhostState0();
            break;
        case 1:
            AdvanceSelectGhostState1();
            break;
        case 2:
            AdvanceSelectGhostState2();
            break;
        case 3:
            AdvanceSelectGhostState3();
            break;
        case 4:
            AdvanceSelectGhostState4();
            break;
        case 5:
            AdvanceSelectGhostState5();
            break;
        case 6:
            AdvanceSelectGhostState6();
            break;
        case 7:
            AdvanceSelectGhostState7();
            break;
    }
    AdvancePaletteBlend();
    func_ov001_0219c358();
    DrawLayoutTable(gSelectGhost->mSelectCupCourseTaMBncl, gSelectGhost->mSelectCupCourseMNcer,
                    gSelectGhost->mSelectCupCourseTaMBnll, (void *) gSelectGhost->mUnk_64,
                    gSelectGhost->mSelectCupCourseTaMTable);
    DrawLayoutTable(gSelectGhost->mSelectGhostSBncl, gSelectGhost->mSelectGhostSONcer, gSelectGhost->mSelectGhostSBnll,
                    (void *) gSelectGhost->mUnk_68, gSelectGhost->mSelectGhostSTable);
    if (gSelectGhost->mState == 7) {
        switch (gSelectGhost->mResult) {
            case 1:
                if (gSelectGhost->mStateFrames >= 10) {
                    if (IsSelectReturnState0NoState1Request() != 0) {
                        return 1;
                    }
                }
                break;
            case 2:
                if (gSelectGhost->mStateFrames >= 10) {
                    return 2;
                }
                break;
        }
    }
    return 0;
}

void WriteSelectGhostRegisters(void) {
    reg_G2_BG0OFS = (-gSelectGhost->mBg0Offset << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = (-gSelectGhost->mBg3Offset << 16) & 0x1ff0000;
}

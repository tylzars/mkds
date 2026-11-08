#include "Main/Unknown/code_021145b4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02076cd0.h"
#include "Main/Unknown/code_02111428.h"
#include "Main/Unknown/code_02111494.h"

#include "Main/Unknown/code_02111000.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_02114c98.h"
#include "Main/Unknown/code_02114cb0.h"
#include "Main/Unknown/code_02116244.h"
#include "Main/Unknown/code_02116870.h"
#include "Main/Unknown/code_0211568c.h"
#include "Main/Unknown/code_021156d4.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02114000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_02116084.h"
#include "Main/Unknown/code_0211606c.h"
#include "Main/Unknown/code_02116174.h"
#include "Main/Unknown/code_02116844.h"
#include "code_0212df7c.h"
#include "code_0201ea58.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02116000.h"
#include "Main/Unknown/code_021113f0.h"
#include "Main/Unknown/code_02116888.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_0211621c.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "code_02148950.h"
#include "Main/Unknown/code_02047104.h"
#include "registers.h"

#pragma thumb on

u32 IsRecordVSEraseIndexChangeRunning(void) {
    if (gRecordVSErase->mIndexChangeTimer != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseIndexChange(void) {
    s32 mainCellCount;
    s32 transientCellCount;
    s16 offsetY;

    if (IsRecordVSEraseIndexChangeRunning()) {
        if (gRecordVSErase->mIndexChangeTimer == 7) {
            gRecordVSErase->mShownIndex = gRecordVSErase->mIndex;
            PrintRecordVSEraseShownRecord();
        } else {
            mainCellCount = gRecordVSErase->mRecordVSMBncl->mUnk_06;
            transientCellCount = gRecordVSErase->mRecordVSMTransientBncl->mUnk_06;
            offsetY = LookupIndexChangeOffset(7 - gRecordVSErase->mIndexChangeTimer, 0);
            gRecordVSErase->mBg0OffsetY = offsetY;
            gRecordVSErase->mRecordVSMTable[3].mOffsetY = offsetY;
            gRecordVSErase->mRecordVSMTable[mainCellCount].mOffsetY = offsetY;
            gRecordVSErase->mRecordVSMTransientTable[1].mOffsetY = offsetY;
            gRecordVSErase->mRecordVSMTransientTable[transientCellCount].mOffsetY = offsetY;
        }
        gRecordVSErase->mIndexChangeTimer--;
    } else {
        if (gRecordVSErase->mIndex != 5 && gRecordVSErase->mIndex != gRecordVSErase->mShownIndex) {
            gRecordVSErase->mIndexChangeTimer = 7;
        }
    }
}

void RequestRecordVSEraseState0(void) {
    s32 i;
    u16 eraseCellCount;

    i = 0;
    gRecordVSErase->mNextState = 0;
    gRecordVSErase->mStateFrames = 0;
    gRecordVSErase->mBg3Offset = ~0xbf;
    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    gRecordVSErase->mRecordVSSEraseTable[30].mOffsetX = 0x100;
    gRecordVSErase->mRecordVSSEraseTable[31].mOffsetX = 0x100;
    gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + 5].mOffsetY = ~0xbf;
    for (; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mOffsetX = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mOffsetX = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mOffsetX = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mOffsetX = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mOffsetX = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mOffsetX = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + data_0215c4b8[i]].mOffsetX = 0x100;
    }
    PrintRecordVSEraseShownRecord();
    SetupTxtSystemSubTextButtonEx(GetBmgEntry(gRecordVSErase->mRecordMessages, 4),
                                  GetBmgEntry(gRecordVSErase->mCommonMessages, 6), 0, 1, 1, 1);
    for (i = 0; i < 2; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4a8[i]].mVisible = 0;
    }
}

void RequestRecordVSEraseState1(void) {
    gRecordVSErase->mNextState = 1;
    gRecordVSErase->mStateFrames = 0;
}

void RequestRecordVSEraseState2(void) {
    gRecordVSErase->mNextState = 2;
    gRecordVSErase->mStateFrames = 0;
    RequestTxtSystemClose();
}

void RequestRecordVSEraseState3(void) {
    gRecordVSErase->mNextState = 3;
    gRecordVSErase->mStateFrames = 0;
    RequestSelectReturnState1();
    func_02116244();
}

void RequestRecordVSEraseState4(void) {
    gRecordVSErase->mNextState = 4;
    gRecordVSErase->mStateFrames = 0;
}

void RequestRecordVSEraseState5(void) {
    gRecordVSErase->mNextState = 5;
    gRecordVSErase->mStateFrames = 0;
}

void RequestRecordVSEraseState6(void) {
    gRecordVSErase->mNextState = 6;
    gRecordVSErase->mStateFrames = 0;
    switch (gRecordVSErase->mPageDecrement) {
        case 0:
            IncrementRecordVSErasePageIndex();
            break;
        case 1:
            DecrementRecordVSErasePageIndex();
            break;
    }
    func_02116244();
}

void RequestRecordVSEraseState7(void) {
    gRecordVSErase->mNextState = 7;
    gRecordVSErase->mStateFrames = 0;
    RequestSelectReturnState4();
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
}

void RequestRecordVSEraseState8(void) {
    u16 recordName[0x10];
    u16 messageText[0x100];
    u16 firstRecordIndex;

    gRecordVSErase->mNextState = 8;
    gRecordVSErase->mStateFrames = 0;
    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    CopyRecordText(firstRecordIndex + gRecordVSErase->mIndex, recordName, 0x20);
    func_0212513c(recordName, GetBmgEntry(gRecordVSErase->mRecordMessages, 5), messageText, 0x200);
    SetupTxtSystemSubTextTwoButtonsEx(messageText, GetBmgEntry(gRecordVSErase->mCommonMessages, 0),
                                      GetBmgEntry(gRecordVSErase->mCommonMessages, 1), 1, 0, 1, 1, 1);
}

void RequestRecordVSEraseState9(void) {
    gRecordVSErase->mNextState = 9;
    gRecordVSErase->mStateFrames = 0;
    SetTxtSystemSoundId(0, 0xb);
}

void RequestRecordVSEraseState10(void) {
    gRecordVSErase->mNextState = 0xa;
    gRecordVSErase->mStateFrames = 0;
    RequestTxtSystemClose();
    SetTxtSystemSoundId(0, 5);
}

void RequestRecordVSEraseState11(void) {
    gRecordVSErase->mNextState = 0xb;
    gRecordVSErase->mStateFrames = 0;
    RequestSelectReturnState1();
    func_02116244();
}

void RequestRecordVSEraseState12(void) {
    gRecordVSErase->mNextState = 0xc;
    gRecordVSErase->mStateFrames = 0;
}

void InitRecordVSErase(void *heap) {
    s32 remainingSize;
    u16 *cellIndexCursor;
    s32 remainingSubSize;
    u16 mainCellCount;
    u16 cellIndex;
    s32 j;
    s32 i;
    u32 p0;
    u32 p1;
    u32 p2;
    u32 p3;
    u32 p4;

    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0x1018;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x9810;
    gRecordVSErase = HeapAlloc(heap, 0xa4);
    gRecordVSErase->mHeap = heap;
    gRecordVSErase->mState = 3;
    gRecordVSErase->mPageIndex = GetRecordScenePageIndex();
    gRecordVSErase->mIndex = GetRecordSceneIndex();
    gRecordVSErase->mPageDecrement = 0;
    gRecordVSErase->mIndexChangeTimer = 0;
    gRecordVSErase->mShownIndex = gRecordVSErase->mIndex;
    gRecordVSErase->mTransientDrawn = 0;
    gRecordVSErase->mErased = 0;
    gRecordVSErase->mUnk_98 = FALSE;
    gRecordVSErase->mUnk_9c = FALSE;
    for (i = 0; i < 2; i++) {
        gRecordVSErase->mOffsetTimers[i] = 0;
    }
    LoadEmblemSBNclr(heap);
    LocateAndQueueRecordVSErase();
    InitLayoutTable(heap, gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMBnll,
                    &gRecordVSErase->mRecordVSMTable);
    InitLayoutTable(heap, gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientBnll,
                    &gRecordVSErase->mRecordVSMTransientTable);
    InitLayoutTable(heap, gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSEraseBnll,
                    &gRecordVSErase->mRecordVSSEraseTable);
    gRecordVSErase->mCommonMessages = FindFileInLoadedArchives(data_0216d4a4);
    gRecordVSErase->mRecordMessages = FindSceneFile(data_0216d4b0);
    remainingSize = 0x8000;
    remainingSize -=
        func_021243ac(heap, 0, gRecordVSErase->mRecordVSMBnll, 0x8c, 0x10, 0, gRecordVSErase->mRecordVSMNcer,
                      gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, remainingSize);
    remainingSize -=
        func_021243ac(heap, 1, gRecordVSErase->mRecordVSMBnll, 0xaa, 0xe, 1, gRecordVSErase->mRecordVSMNcer,
                      gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, remainingSize);
    func_0212426c(0, 1, gRecordVSErase->mRecordVSMBnll, GetBmgEntry(gRecordVSErase->mRecordMessages, 0),
                  gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable);
    remainingSize -=
        func_021243ac(heap, 0xb, gRecordVSErase->mRecordVSMBnll, 0x96, 0xe, 2, gRecordVSErase->mRecordVSMNcer,
                      gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, remainingSize);
    func_0212426c(0, 0xb, gRecordVSErase->mRecordVSMBnll, GetBmgEntry(gRecordVSErase->mRecordMessages, 1),
                  gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable);
    remainingSize -=
        func_021243ac(heap, 0xc, gRecordVSErase->mRecordVSMBnll, 0x46, 0x10, 3, gRecordVSErase->mRecordVSMNcer,
                      gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, remainingSize);
    cellIndex = 4;
    mainCellCount = gRecordVSErase->mRecordVSMBncl->mUnk_06;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            remainingSize -=
                func_021243ac(heap, data_0215c530[i][j], gRecordVSErase->mRecordVSMBnll, data_0215c544[i][j],
                              data_0215c558[i][j], cellIndex, gRecordVSErase->mRecordVSMNcer,
                              gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, remainingSize);
            cellIndex = mainCellCount + data_0215c530[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        func_0212426c(0, data_0215c530[0][i], gRecordVSErase->mRecordVSMBnll,
                      GetBmgEntry(gRecordVSErase->mRecordMessages, data_0215c4b0[i]), gRecordVSErase->mRecordVSMBncl,
                      gRecordVSErase->mRecordVSMTable);
    }
    remainingSize -=
        func_021243ac(heap, 0, gRecordVSErase->mRecordVSMTransientBnll, 0x8c, 0x10, 0, gRecordVSErase->mRecordVSMNcer,
                      gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable, remainingSize);
    remainingSize -=
        func_021243ac(heap, 1, gRecordVSErase->mRecordVSMTransientBnll, 0x70, 0x10, 1, gRecordVSErase->mRecordVSMNcer,
                      gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable, remainingSize);
    func_0212426c(0, 1, gRecordVSErase->mRecordVSMTransientBnll, GetBmgEntry(gRecordVSErase->mRecordMessages, 0xb),
                  gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable);
    remainingSize -=
        func_021243ac(heap, 0xe, gRecordVSErase->mRecordVSMTransientBnll, 0xe0, 0x38, 2, gRecordVSErase->mRecordVSMNcer,
                      gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable, remainingSize);
    func_0212426c(0, 0xe, gRecordVSErase->mRecordVSMTransientBnll, GetBmgEntry(gRecordVSErase->mRecordMessages, 0xc),
                  gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable);
    for (i = 0; i < 12; i++) {
        remainingSize -= func_021243ac(heap, data_0215c584[i], gRecordVSErase->mRecordVSMTransientBnll,
                                       data_0215c59c[i], data_0215c56c[i], i + 3, gRecordVSErase->mRecordVSMNcer,
                                       gRecordVSErase->mRecordVSMTransientBncl,
                                       gRecordVSErase->mRecordVSMTransientTable, remainingSize);
    }
    remainingSubSize = GX_GetSizeOfSubOBJ();
    for (i = 0, cellIndexCursor = data_0215c50c; i < 5; i++) {
        remainingSubSize -=
            func_021243ac(heap, data_0215c4b8[i], gRecordVSErase->mRecordVSSEraseBnll, data_0215c4c4[i],
                          data_0215c4dc[i], *cellIndexCursor, gRecordVSErase->mRecordVSSNcer,
                          gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSEraseTable, remainingSubSize);
        cellIndexCursor++;
    }
    func_021243ac(heap, 5, gRecordVSErase->mRecordVSSEraseBnll, 0xfa, 0x10, 5, gRecordVSErase->mRecordVSSNcer,
                  gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSEraseTable, remainingSubSize);
    func_0212426c(1, 5, gRecordVSErase->mRecordVSSEraseBnll, GetBmgEntry(gRecordVSErase->mRecordMessages, 2),
                  gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSEraseTable);
    p0 = 0;
    p1 = 0;
    p2 = 0;
    p3 = 0;
    p4 = 0;
    for (i = 0; i < 5; i++) {
        func_02124a98(data_0215c4e8[i], p0, gRecordVSErase->mRecordVSSNcer, gRecordVSErase->mRecordVSSEraseBncl);
        func_02124a98(data_0215c4f4[i], p1, gRecordVSErase->mRecordVSSNcer, gRecordVSErase->mRecordVSSEraseBncl);
        func_02124a98(data_0215c500[i], p2, gRecordVSErase->mRecordVSSNcer, gRecordVSErase->mRecordVSSEraseBncl);
        func_02124a98(data_0215c50c[i], p3, gRecordVSErase->mRecordVSSNcer, gRecordVSErase->mRecordVSSEraseBncl);
        func_02124140(data_0215c4b8[i], p4, gRecordVSErase->mRecordVSSEraseBnll, gRecordVSErase->mRecordVSSEraseTable,
                      gRecordVSErase->mRecordVSSEraseBncl);
    }
    func_02124140(5, 0, gRecordVSErase->mRecordVSSEraseBnll, gRecordVSErase->mRecordVSSEraseTable,
                  gRecordVSErase->mRecordVSSEraseBncl);
    gRecordVSErase->mEmblem = HeapAlloc(heap, 0x201);
    gRecordVSErase->mEmblemConverted = HeapAlloc(heap, 0x200);
    RequestRecordVSEraseState0();
}

void ReleaseRecordVSErase(void) {
    u32 planeBits;

    SetRecordScenePageIndex(gRecordVSErase->mPageIndex);
    SetRecordSceneIndex(gRecordVSErase->mIndex);
    gRecordVSErase = NULL;
    planeBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    planeBits &= ~9;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (planeBits << 8);
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseState0(void) {
    int isState2NoCloseRequest;
    isState2NoCloseRequest = IsTxtSystemState2NoCloseRequest();
    if (isState2NoCloseRequest != 0) {
        RequestRecordVSEraseState1();
    }
}

void AdvanceRecordVSEraseState1(void) {
    int isDone;
    isDone = GetTxtSystemDone();
    if (isDone != 0) {
        RequestRecordVSEraseState2();
    }
}

void AdvanceRecordVSEraseState2(void) {
    int isState0NoOpenRequest;
    isState0NoOpenRequest = IsTxtSystemState0NoOpenRequest();
    if (isState0NoOpenRequest != 0) {
        RequestRecordVSEraseState3();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseState3(void) {
    s16 offsetX;
    u32 offsetY;
    u16 eraseCellCount;
    s32 i;

    AdvanceRecordVSEraseOffsetTimers();
    gRecordVSErase->mStateFrames++;
    offsetX = InterpolateS16(1, 0x100, 0, gRecordVSErase->mStateFrames, 0xa);
    offsetY = InterpolateS16(1, ~0xbf, 0, gRecordVSErase->mStateFrames, 0xa);
    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    gRecordVSErase->mBg3Offset = offsetY;
    gRecordVSErase->mRecordVSSEraseTable[30].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[31].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + 5].mOffsetY = offsetY;
    for (i = 0; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + data_0215c4b8[i]].mOffsetX = offsetX;
    }
    if (gRecordVSErase->mStateFrames >= 0xa) {
        if (IsSelectReturnState2NoState3Or4Request() != 0) {
            RequestRecordVSEraseState4();
        }
    }
}

void AdvanceRecordVSEraseState4(void) {
    s32 firstRecordIndex;
    s32 v;
    u32 w;
    Unk02175628Index i;
    BOOL n;

    v = -1;
    w = v;
    i = UNK_02175628_INDEX_8;
    AdvanceRecordVSEraseOffsetTimers();
    AdvanceRecordVSEraseIndexChange();
    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    n = (data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) || data_02175674[i].mUnk_00 != 0;
    if (n) {
        v = RectTableFindContaining(gRecordVSErase->mRecordVSSEraseBnbl, data_02175670[i].mUnk_00,
                                    data_02175672[i].mUnk_00);
    }
    n = !(data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) &&
        (data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0);
    if (n) {
        w = RectTableFindContaining(gRecordVSErase->mRecordVSSEraseBnbl, data_02175670[i].mUnk_00,
                                    data_02175672[i].mUnk_00);
    }
    if (v != 5) {
        gRecordVSErase->mUnk_98 = FALSE;
    }
    if (v != 6) {
        gRecordVSErase->mUnk_9c = FALSE;
    }
    if ((u16) (data_02175628[i].mUnk_00 & PAD_KEY_B) != 0 ||
        ((n = !(data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) &&
              (data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0)) &&
         IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[i].mUnk_00, data_02175672[i].mUnk_00) !=
             FALSE)) {
        if (IsRecordVSEraseIndexChangeRunning() != 0) {
            return;
        }
        RequestRecordVSEraseState12();
        gRecordVSErase->mNextScreen = 3;
        RequestSelectReturnState3WithSound(0);
        return;
    }
    if ((v == 5 && gRecordVSErase->mUnk_98 != FALSE) || (w == 5 && gRecordVSErase->mUnk_98 == FALSE) ||
        (u16) (data_0217562a[i].mBits & PAD_KEY_LEFT) != 0) {
        if (IsRecordVSEraseIndexChangeRunning() != 0) {
            return;
        }
        if (gRecordVSErase->mRecordVSSEraseTable[30].mVisible == 0) {
            return;
        }
        gRecordVSErase->mPageDecrement = 1;
        gRecordVSErase->mOffsetTimers[0] = 6;
        gRecordVSErase->mUnk_98 = TRUE;
        RequestRecordVSEraseState5();
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
        return;
    }
    if ((v == 6 && gRecordVSErase->mUnk_9c != FALSE) || (w == 6 && gRecordVSErase->mUnk_9c == FALSE) ||
        (u16) (data_0217562a[i].mBits & PAD_KEY_RIGHT) != 0) {
        if (IsRecordVSEraseIndexChangeRunning() != 0) {
            return;
        }
        if (gRecordVSErase->mRecordVSSEraseTable[31].mVisible == 0) {
            return;
        }
        gRecordVSErase->mPageDecrement = 0;
        gRecordVSErase->mOffsetTimers[1] = 6;
        gRecordVSErase->mUnk_9c = TRUE;
        RequestRecordVSEraseState5();
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
        return;
    }
    if (w <= 4) {
        i = data_0215c4d0[w];
        if (i == gRecordVSErase->mIndex) {
            if (IsRecordFlagged(firstRecordIndex + i) == 0) {
                if (IsRecordVSEraseIndexChangeRunning() == 0) {
                    RequestRecordVSEraseState7();
                }
                return;
            }
            if (IsRecordVSEraseIndexChangeRunning() == 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
            }
            return;
        }
        if (IsRecordVSEraseRowFilled(i) != 0) {
            gRecordVSErase->mIndex = i;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        }
    } else {
        if ((u16) (data_02175628[i].mUnk_00 & PAD_KEY_A) != 0) {
            if (IsRecordFlagged(firstRecordIndex + gRecordVSErase->mIndex) == 0) {
                if (IsRecordVSEraseIndexChangeRunning() == 0) {
                    RequestRecordVSEraseState7();
                }
                return;
            }
            if (IsRecordVSEraseIndexChangeRunning() == 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
            }
            return;
        }
        if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
            DecrementRecordVSEraseIndex();
            return;
        }
        if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
            IncrementRecordVSEraseIndex();
        }
    }
}

void AdvanceRecordVSEraseState5(void) {
    s16 targetOffsetX;
    u16 mainCellCount;
    s32 i;
    u16 transientCellCount;
    u16 eraseCellCount;
    s32 j;
    s16 offsetX;

    targetOffsetX = 0;
    AdvanceRecordVSEraseOffsetTimers();
    switch (gRecordVSErase->mPageDecrement) {
        case 0:
            targetOffsetX = ~0xff;
            break;
        case 1:
            targetOffsetX = 0x100;
            break;
    }
    gRecordVSErase->mStateFrames++;
    mainCellCount = gRecordVSErase->mRecordVSMBncl->mUnk_06;
    transientCellCount = gRecordVSErase->mRecordVSMTransientBncl->mUnk_06;
    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    offsetX = InterpolateS16(1, 0, targetOffsetX, gRecordVSErase->mStateFrames, 0xa);
    gRecordVSErase->mBg0OffsetX = offsetX;
    gRecordVSErase->mBg1OffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[2].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[3].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount + 1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount + 0xb].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount + 0xc].mOffsetX = offsetX;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVSErase->mRecordVSMTable[mainCellCount + data_0215c530[i][j]].mOffsetX = offsetX;
        }
    }
    gRecordVSErase->mRecordVSMTransientTable[1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTransientTable[transientCellCount].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 0xe].mOffsetX = offsetX;
    for (i = 0; i < 0xc; i++) {
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount + data_0215c584[i]].mOffsetX = offsetX;
    }
    for (i = 0; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + data_0215c4b8[i]].mOffsetX = offsetX;
    }
    if (gRecordVSErase->mStateFrames >= 0xa) {
        RequestRecordVSEraseState6();
    }
}

void AdvanceRecordVSEraseState6(void) {
    s16 startOffsetX;
    u16 mainCellCount;
    s32 i;
    u16 transientCellCount;
    u16 eraseCellCount;
    s32 j;
    s16 offsetX;

    startOffsetX = 0;
    AdvanceRecordVSEraseOffsetTimers();
    switch (gRecordVSErase->mPageDecrement) {
        case 0:
            startOffsetX = 0x100;
            break;
        case 1:
            startOffsetX = ~0xff;
            break;
    }
    gRecordVSErase->mStateFrames++;
    mainCellCount = gRecordVSErase->mRecordVSMBncl->mUnk_06;
    transientCellCount = gRecordVSErase->mRecordVSMTransientBncl->mUnk_06;
    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    offsetX = InterpolateS16(1, startOffsetX, 0, gRecordVSErase->mStateFrames, 0xa);
    gRecordVSErase->mBg0OffsetX = offsetX;
    gRecordVSErase->mBg1OffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[2].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[3].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount + 1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount + 0xb].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTable[mainCellCount + 0xc].mOffsetX = offsetX;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVSErase->mRecordVSMTable[mainCellCount + data_0215c530[i][j]].mOffsetX = offsetX;
        }
    }
    gRecordVSErase->mRecordVSMTransientTable[1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTransientTable[transientCellCount].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 1].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 0xe].mOffsetX = offsetX;
    for (i = 0; i < 0xc; i++) {
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount + data_0215c584[i]].mOffsetX = offsetX;
    }
    for (i = 0; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + data_0215c4b8[i]].mOffsetX = offsetX;
    }
    if (gRecordVSErase->mStateFrames >= 0xa) {
        RequestRecordVSEraseState4();
    }
}

void AdvanceRecordVSEraseState7(void) {
    s16 offsetX;
    u32 offsetY;
    u16 eraseCellCount;
    s32 i;

    gRecordVSErase->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0x100, gRecordVSErase->mStateFrames, 0xa);
    offsetY = InterpolateS16(1, 0, ~0xbf, gRecordVSErase->mStateFrames, 0xa);
    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    gRecordVSErase->mBg3Offset = offsetY;
    gRecordVSErase->mRecordVSSEraseTable[30].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[31].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + 5].mOffsetY = offsetY;
    for (i = 0; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + data_0215c4b8[i]].mOffsetX = offsetX;
    }
    if (gRecordVSErase->mStateFrames > 0xa) {
        if (IsSelectReturnState0NoState1Request() != 0) {
            RequestRecordVSEraseState8();
        }
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseState8(void) {
    int v1;
    v1 = IsTxtSystemState2NoCloseRequest();
    if (v1 != 0) {
        RequestRecordVSEraseState9();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseState9(void) {
    u16 firstRecordIndex;

    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    if (GetTxtSystemDone()) {
        if (GetTxtSystemSelectedIndex() == 0) {
            EraseRecord(firstRecordIndex + gRecordVSErase->mIndex);
            gRecordVSErase->mErased = 1;
        } else {
            gRecordVSErase->mErased = 0;
        }
        RequestRecordVSEraseState10();
    }
}

void AdvanceRecordVSEraseState10(void) {
    s32 i;
    s32 j;
    s16 offsetX;
    u16 mainCellCount;
    u16 transientCellCount;
    u16 firstRecordIndex;

    gRecordVSErase->mStateFrames++;
    offsetX = InterpolateS16(1, 0, -0x100, gRecordVSErase->mStateFrames, 10);
    mainCellCount = gRecordVSErase->mRecordVSMBncl->mUnk_06;
    transientCellCount = gRecordVSErase->mRecordVSMTransientBncl->mUnk_06;
    if (GetRecordCount() != 0 && gRecordVSErase->mErased != 0) {
        gRecordVSErase->mBg1OffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[2].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[3].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount + 1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount + 0xb].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount + 0xc].mOffsetX = offsetX;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                gRecordVSErase->mRecordVSMTable[mainCellCount + data_0215c530[i][j]].mOffsetX = offsetX;
            }
        }
        gRecordVSErase->mRecordVSMTransientTable[1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 0xe].mOffsetX = offsetX;
        for (i = 0; i < 12; i++) {
            gRecordVSErase->mRecordVSMTransientTable[transientCellCount + data_0215c584[i]].mOffsetX = offsetX;
        }
    }
    if (IsTxtSystemState0NoOpenRequest()) {
        firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
        if (GetRecordCount() <= firstRecordIndex) {
            gRecordVSErase->mPageIndex--;
        }
        if (gRecordVSErase->mPageIndex < 0) {
            gRecordVSErase->mNextScreen = 3;
            RequestRecordScreen(gRecordVSErase->mNextScreen);
        } else {
            RequestRecordVSEraseState11();
        }
    }
}

void AdvanceRecordVSEraseState11(void) {
    s32 i;
    s32 j;
    s16 offsetX;
    s16 offsetY;
    u16 mainCellCount;
    u16 transientCellCount;
    u16 eraseCellCount;

    gRecordVSErase->mStateFrames++;
    offsetX = InterpolateS16(1, 0x100, 0, gRecordVSErase->mStateFrames, 10);
    offsetY = InterpolateS16(1, -0xc0, 0, gRecordVSErase->mStateFrames, 10);
    mainCellCount = gRecordVSErase->mRecordVSMBncl->mUnk_06;
    transientCellCount = gRecordVSErase->mRecordVSMTransientBncl->mUnk_06;
    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    if (gRecordVSErase->mErased != 0) {
        gRecordVSErase->mBg1OffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[2].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[3].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount + 1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount + 0xb].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTable[mainCellCount + 0xc].mOffsetX = offsetX;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                gRecordVSErase->mRecordVSMTable[mainCellCount + data_0215c530[i][j]].mOffsetX = offsetX;
            }
        }
        gRecordVSErase->mRecordVSMTransientTable[1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 1].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSMTransientTable[transientCellCount + 0xe].mOffsetX = offsetX;
        for (i = 0; i < 12; i++) {
            gRecordVSErase->mRecordVSMTransientTable[transientCellCount + data_0215c584[i]].mOffsetX = offsetX;
        }
    }
    gRecordVSErase->mBg3Offset = offsetY;
    gRecordVSErase->mRecordVSSEraseTable[30].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[31].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + 5].mOffsetY = offsetY;
    for (i = 0; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + data_0215c4b8[i]].mOffsetX = offsetX;
    }
    if (gRecordVSErase->mStateFrames > 10) {
        if (IsSelectReturnState2NoState3Or4Request()) {
            RequestRecordVSEraseState4();
        }
    }
}

void AdvanceRecordVSEraseState12(void) {
    s32 i;
    s16 offsetX;
    s16 offsetY;
    u16 eraseCellCount;

    gRecordVSErase->mStateFrames++;
    offsetX = InterpolateS16(1, 0, 0x100, gRecordVSErase->mStateFrames, 10);
    offsetY = InterpolateS16(1, 0, -0xc0, gRecordVSErase->mStateFrames, 10);
    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    gRecordVSErase->mBg3Offset = offsetY;
    gRecordVSErase->mRecordVSSEraseTable[30].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[31].mOffsetX = offsetX;
    gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + 5].mOffsetY = offsetY;
    for (i = 0; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mOffsetX = offsetX;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + data_0215c4b8[i]].mOffsetX = offsetX;
    }
    if (gRecordVSErase->mStateFrames >= 10) {
        RequestRecordScreen(gRecordVSErase->mNextScreen);
    }
}

void AdvanceRecordVSErase(void) {
    gRecordVSErase->mState = gRecordVSErase->mNextState;
    switch (gRecordVSErase->mState) {
        case 0:
            AdvanceRecordVSEraseState0();
            break;
        case 1:
            AdvanceRecordVSEraseState1();
            break;
        case 2:
            AdvanceRecordVSEraseState2();
            break;
        case 3:
            AdvanceRecordVSEraseState3();
            break;
        case 4:
            AdvanceRecordVSEraseState4();
            break;
        case 5:
            AdvanceRecordVSEraseState5();
            break;
        case 6:
            AdvanceRecordVSEraseState6();
            break;
        case 7:
            AdvanceRecordVSEraseState7();
            break;
        case 8:
            AdvanceRecordVSEraseState8();
            break;
        case 9:
            AdvanceRecordVSEraseState9();
            break;
        case 10:
            AdvanceRecordVSEraseState10();
            break;
        case 11:
            AdvanceRecordVSEraseState11();
            break;
        case 12:
            AdvanceRecordVSEraseState12();
            break;
    }
    UpdateRecordVSEraseRows();
    switch (gRecordVSErase->mTransientDrawn) {
        case 0:
            DrawLayoutTable(gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMNcer,
                            gRecordVSErase->mRecordVSMBnll, GetRecordMainOam(), gRecordVSErase->mRecordVSMTable);
            break;
        case 1:
            DrawLayoutTable(gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMNcer,
                            gRecordVSErase->mRecordVSMTransientBnll, GetRecordMainOam(),
                            gRecordVSErase->mRecordVSMTransientTable);
            break;
    }
    DrawLayoutTable(gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSNcer,
                    gRecordVSErase->mRecordVSSEraseBnll, GetRecordSubOam(), gRecordVSErase->mRecordVSSEraseTable);
}

void WriteRecordVSEraseBgOffsets(void) {
    reg_G2_BG0OFS = (-gRecordVSErase->mBg0OffsetX & 0x1ff) | ((-gRecordVSErase->mBg0OffsetY << 16) & 0x1ff0000);
    reg_G2_BG1OFS = (-gRecordVSErase->mBg1OffsetX & 0x1ff) | ((-gRecordVSErase->mBg1OffsetY << 16) & 0x1ff0000);
    reg_G2S_DB_BG3OFS = (-gRecordVSErase->mBg3Offset << 16) & 0x1ff0000;
    AdvanceRecordSceneRegistersTimer();
}

void WriteRecordVSEraseRegisters(void) {
    u32 planeBits;

    planeBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | ((planeBits | 9) << 8);
}

void RegisterRecordVSEraseCallbacks(void) {
    void (*callbacks[5])() = {InitRecordVSErase, ReleaseRecordVSErase, AdvanceRecordVSErase,
                              WriteRecordVSEraseBgOffsets, WriteRecordVSEraseRegisters};

    SetRecordScreenCallbacks(callbacks);
}

#pragma thumb off

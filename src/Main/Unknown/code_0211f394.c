#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_02116dc8.h"

#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02116d24.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_0211f61c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02116dd4.h"
#include "code_02148950.h"
#include "Main/Unknown/code_02047104.h"

#pragma thumb on

void LocateAndQueueSelectRaceRuleWait(void) {
    void *sceneFile;
    Ncgr *cellChars;
    Nclr *cellPalette[1];
    cellChars = NULL;
    cellPalette[0] = NULL;
    sceneFile = FindSceneFile(data_0216e128);
    LocateNcer(&gSelectRaceRuleWait->mNcer, sceneFile);
    sceneFile = FindSceneFile(data_0216e134);
    LocateNcgr2(&cellChars, sceneFile);
    sceneFile = FindSceneFile(data_0216e130);
    LocateNclr(cellPalette, sceneFile);
    sceneFile = FindSceneFile(data_0216e124);
    gSelectRaceRuleWait->mBncl = sceneFile;
    sceneFile = FindSceneFile(data_0216e12c);
    gSelectRaceRuleWait->mBnll = sceneFile;
    CallQueueAppend(0x23, 0, cellChars->mData, cellChars->mDataSize);
    CallQueueAppend(0x1e, 0, cellPalette[0]->mData, cellPalette[0]->mDataSize);
}

#pragma thumb off

#pragma thumb on

void RequestSelectRaceRuleWaitState0(void) {
    u16 cellEntryCount;

    gSelectRaceRuleWait->mNextState = 0;
    gSelectRaceRuleWait->mStateFrames = 0;
    cellEntryCount = gSelectRaceRuleWait->mBncl->mUnk_06;
    gSelectRaceRuleWait->mTable[0x2a].mOffsetY = 0xc0;
    gSelectRaceRuleWait->mTable[cellEntryCount + 0xe].mOffsetY = 0xc0;
}

void RequestSelectRaceRuleWaitState1(void) {
    gSelectRaceRuleWait->mNextState = 1;
    gSelectRaceRuleWait->mStateFrames = 0;
}

void RequestSelectRaceRuleWaitState2(void) {
    u16 cellEntryCount;

    gSelectRaceRuleWait->mNextState = 2;
    gSelectRaceRuleWait->mStateFrames = 0;
    cellEntryCount = gSelectRaceRuleWait->mBncl->mUnk_06;
    gSelectRaceRuleWait->mTable[0x2a].mOffsetY = 0;
    gSelectRaceRuleWait->mTable[cellEntryCount + 0xe].mOffsetY = 0;
}

void InitSelectRaceRuleWait(void *heap, void *oamList) {
    SelectRaceRuleWait *selectRaceRuleWait;
    s32 i;
    u16 cellEntryCount;
    u32 subObjSize;

    gSelectRaceRuleWait = HeapAlloc(heap, 0x28);
    gSelectRaceRuleWait->mState = 1;
    gSelectRaceRuleWait->mOamList = oamList;
    LocateAndQueueSelectRaceRuleWait();
    InitLayoutTable(heap, gSelectRaceRuleWait->mBncl, gSelectRaceRuleWait->mBnll, &gSelectRaceRuleWait->mTable);
    gSelectRaceRuleWait->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    subObjSize = GX_GetSizeOfSubOBJ();
    InitLabelCanvas(heap, 0xe, gSelectRaceRuleWait->mBnll, 0xc8, 0xd, 0, gSelectRaceRuleWait->mNcer,
                    gSelectRaceRuleWait->mBncl, gSelectRaceRuleWait->mTable, subObjSize);
    selectRaceRuleWait = gSelectRaceRuleWait;
    func_0212426c(1, 0xe, gSelectRaceRuleWait->mBnll, GetBmgEntry(selectRaceRuleWait->mCommonMessages, 0x79),
                  selectRaceRuleWait->mBncl, selectRaceRuleWait->mTable);
    i = 0;
    cellEntryCount = gSelectRaceRuleWait->mBncl->mUnk_06;
    for (; i < cellEntryCount; i++) {
        gSelectRaceRuleWait->mTable[i].mVisible = 0;
    }
    gSelectRaceRuleWait->mTable[0x2a].mVisible = 1;
    CreateWait(heap, gSelectRaceRuleWait->mNcer, gSelectRaceRuleWait->mBncl, 0x2a, 0xe, 1);
    RequestSelectRaceRuleWaitState0();
    RequestSelectRaceRuleWaitState1();
    AdvanceSelectRaceRuleWait();
}

#pragma thumb off

#pragma thumb on

void func_0211f498(void) {
    ClearWaitPointer();
    *(u32 *) &gSelectRaceRuleWait = 0;
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectRaceRuleWaitState0(void) {
    u16 cellEntryCount;
    s16 offsetY;

    cellEntryCount = gSelectRaceRuleWait->mBncl->mUnk_06;
    gSelectRaceRuleWait->mStateFrames++;
    offsetY = InterpolateS16(1, 0xc0, 0, gSelectRaceRuleWait->mStateFrames, 10);
    gSelectRaceRuleWait->mTable[0x2a].mOffsetY = offsetY;
    gSelectRaceRuleWait->mTable[cellEntryCount + 0xe].mOffsetY = offsetY;
    if (gSelectRaceRuleWait->mStateFrames >= 10) {
        RequestSelectRaceRuleWaitState1();
    }
}

void AdvanceSelectRaceRuleWaitState2(void) {
    u16 cellEntryCount;
    s16 offsetY;

    cellEntryCount = gSelectRaceRuleWait->mBncl->mUnk_06;
    gSelectRaceRuleWait->mStateFrames++;
    offsetY = InterpolateS16(1, 0, 0xc0, gSelectRaceRuleWait->mStateFrames, 10);
    gSelectRaceRuleWait->mTable[0x2a].mOffsetY = offsetY;
    gSelectRaceRuleWait->mTable[cellEntryCount + 0xe].mOffsetY = offsetY;
    if (gSelectRaceRuleWait->mStateFrames >= 10) {
        RequestSelectRaceRuleWaitState1();
    }
}

void AdvanceSelectRaceRuleWait(void) {
    gSelectRaceRuleWait->mState = gSelectRaceRuleWait->mNextState;
    switch (gSelectRaceRuleWait->mState) {
        case 0:
            AdvanceSelectRaceRuleWaitState0();
            break;
        case 1:
            break;
        case 2:
            AdvanceSelectRaceRuleWaitState2();
            break;
    }
    AdvanceWait();
    DrawLayoutTable(gSelectRaceRuleWait->mBncl, gSelectRaceRuleWait->mNcer, gSelectRaceRuleWait->mBnll,
                    gSelectRaceRuleWait->mOamList, gSelectRaceRuleWait->mTable);
}

void func_0211f394(void) {
    RequestSelectRaceRuleWaitState0();
}

#pragma thumb off

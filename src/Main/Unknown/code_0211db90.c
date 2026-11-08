#include "Main/Unknown/code_0211db90.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02116dd4.h"
#include "Main/Unknown/unk_0216d000.h"
#include "code_02016468.h"

#pragma thumb on

void LoadSelectRaceRuleAndWaitData(void) {
    void *sceneFile;
    Ncgr *cellChars;
    Unk02021dc8 *cells;
    Nclr *cellPalette;
    Ncgr *bgChars;
    Nscr *screenMap;
    Nclr *bgPalette[1];
    cellChars = NULL;
    cells = NULL;
    cellPalette = NULL;
    bgChars = NULL;
    screenMap = NULL;
    bgPalette[0] = NULL;
    sceneFile = FindSceneFile(data_0216dbe4);
    LoadNcgrData(&bgChars, sceneFile);
    sceneFile = FindSceneFile(data_0216dbf0);
    LoadNscrData(&screenMap, sceneFile);
    sceneFile = FindSceneFile(data_0216dbd8);
    LoadNclrData(bgPalette, sceneFile);
    sceneFile = FindSceneFile(data_0216dc08);
    LoadNcgrData(&bgChars, sceneFile);
    sceneFile = FindSceneFile(data_0216dbdc);
    LoadNscrData(&screenMap, sceneFile);
    sceneFile = FindSceneFile(data_0216dbf8);
    LoadNcgrData2(&cellChars, sceneFile);
    sceneFile = FindSceneFile(data_0216dc04);
    LoadNcerData(&cells, sceneFile);
    sceneFile = FindSceneFile(data_0216dbec);
    LoadNclrData(&cellPalette, sceneFile);
    LoadWaitData();
}

void LocateAndQueueSelectRaceRule(void) {
    void *sceneFile;
    Ncgr *cellChars;
    Ncgr *bgChars;
    Nclr *bgPalette;
    cellChars = NULL;
    bgChars = NULL;
    bgPalette = NULL;
    if (gSelectRaceRule->mMode == 3) {
        sceneFile = FindSceneFile(data_0216dc08);
        LocateNcgr(&bgChars, sceneFile);
        sceneFile = FindSceneFile(data_0216dbdc);
        LocateNscr(&gSelectRaceRule->mNscr, sceneFile);
        sceneFile = FindSceneFile(data_0216dbe0);
        gSelectRaceRule->mBncl = sceneFile;
        sceneFile = FindSceneFile(data_0216dc00);
        gSelectRaceRule->mBnbl = sceneFile;
        sceneFile = FindSceneFile(data_0216dbfc);
        gSelectRaceRule->mBnll = sceneFile;
    } else {
        sceneFile = FindSceneFile(data_0216dbe4);
        LocateNcgr(&bgChars, sceneFile);
        sceneFile = FindSceneFile(data_0216dbf0);
        LocateNscr(&gSelectRaceRule->mNscr, sceneFile);
        sceneFile = FindSceneFile(data_0216dbf4);
        gSelectRaceRule->mBncl = sceneFile;
        sceneFile = FindSceneFile(data_0216dbd4);
        gSelectRaceRule->mBnbl = sceneFile;
        sceneFile = FindSceneFile(data_0216dbe8);
        gSelectRaceRule->mBnll = sceneFile;
    }
    sceneFile = FindSceneFile(data_0216dbd8);
    LocateNclr(&bgPalette, sceneFile);
    sceneFile = HeapAlloc(gSelectRaceRule->mHeap, (0x00000800u));
    gSelectRaceRule->mUnk_24 = sceneFile;
    sceneFile = FindSceneFile(data_0216dbf8);
    LocateNcgr2(&cellChars, sceneFile);
    sceneFile = FindSceneFile(data_0216dc04);
    LocateNcer(&gSelectRaceRule->mNcer, sceneFile);
    sceneFile = FindSceneFile(data_0216dbec);
    LocateNclr(&gSelectRaceRule->mNclr, sceneFile);
    CallQueueAppend(0x14, 0, bgChars->mData, bgChars->mDataSize);
    CallQueueAppend(0x1b, 0, gSelectRaceRule->mNscr->mData, gSelectRaceRule->mNscr->mDataSize);
    CallQueueAppend(0x1b, (0x00000800u), gSelectRaceRule->mUnk_24, (0x00000800u));
    CallQueueAppend(0x1f, 0, bgPalette->mData, 0x80);
    CallQueueAppend(0x23, 0, cellChars->mData, cellChars->mDataSize);
    CallQueueAppend(0x1e, 0, gSelectRaceRule->mNclr->mData, gSelectRaceRule->mNclr->mDataSize);
}

#pragma thumb off

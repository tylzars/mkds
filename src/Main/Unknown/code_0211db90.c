#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02116dd4.h"
#include "Main/Unknown/code_0211db90.h"
#include "Main/Unknown/unk_0216d000.h"
#include "code_02016468.h"

#pragma thumb on

void func_0211dd44(void) {
    void *v1;
    Ncgr *v2;
    Unk02021dc8 *v3;
    Nclr *v4;
    Ncgr *v5;
    Nscr *v6;
    Nclr *v7[1];
    v2 = NULL;
    v3 = NULL;
    v4 = NULL;
    v5 = NULL;
    v6 = NULL;
    v7[0] = NULL;
    v1 = FindSceneFile(data_0216dbe4);
    LoadNcgrData(&v5, v1);
    v1 = FindSceneFile(data_0216dbf0);
    LoadNscrData(&v6, v1);
    v1 = FindSceneFile(data_0216dbd8);
    LoadNclrData(v7, v1);
    v1 = FindSceneFile(data_0216dc08);
    LoadNcgrData(&v5, v1);
    v1 = FindSceneFile(data_0216dbdc);
    LoadNscrData(&v6, v1);
    v1 = FindSceneFile(data_0216dbf8);
    LoadNcgrData2(&v2, v1);
    v1 = FindSceneFile(data_0216dc04);
    LoadNcerData(&v3, v1);
    v1 = FindSceneFile(data_0216dbec);
    LoadNclrData(&v4, v1);
    func_02116e70();
}

void LocateAndQueueSelectRaceRule(void) {
    void *v1;
    Ncgr *v2;
    Ncgr *v3;
    Nclr *v4;
    v2 = NULL;
    v3 = NULL;
    v4 = NULL;
    if (gSelectRaceRule->mMode == 3) {
        v1 = FindSceneFile(data_0216dc08);
        LocateNcgr(&v3, v1);
        v1 = FindSceneFile(data_0216dbdc);
        LocateNscr(&gSelectRaceRule->mNscr, v1);
        v1 = FindSceneFile(data_0216dbe0);
        gSelectRaceRule->mBncl = v1;
        v1 = FindSceneFile(data_0216dc00);
        gSelectRaceRule->mBnbl = v1;
        v1 = FindSceneFile(data_0216dbfc);
        gSelectRaceRule->mBnll = v1;
    } else {
        v1 = FindSceneFile(data_0216dbe4);
        LocateNcgr(&v3, v1);
        v1 = FindSceneFile(data_0216dbf0);
        LocateNscr(&gSelectRaceRule->mNscr, v1);
        v1 = FindSceneFile(data_0216dbf4);
        gSelectRaceRule->mBncl = v1;
        v1 = FindSceneFile(data_0216dbd4);
        gSelectRaceRule->mBnbl = v1;
        v1 = FindSceneFile(data_0216dbe8);
        gSelectRaceRule->mBnll = v1;
    }
    v1 = FindSceneFile(data_0216dbd8);
    LocateNclr(&v4, v1);
    v1 = HeapAlloc((void *) gSelectRaceRule->mHeap, (u32) (((u32) 0x00000800u)));
    gSelectRaceRule->mUnk_24 = v1;
    v1 = FindSceneFile(data_0216dbf8);
    LocateNcgr2(&v2, v1);
    v1 = FindSceneFile(data_0216dc04);
    LocateNcer(&gSelectRaceRule->mNcer, v1);
    v1 = FindSceneFile(data_0216dbec);
    LocateNclr(&gSelectRaceRule->mNclr, v1);
    CallQueueAppend((u32) 0x14, (u32) 0, v3->mData, v3->mDataSize);
    CallQueueAppend((u32) 0x1b, (u32) 0, gSelectRaceRule->mNscr->mData, gSelectRaceRule->mNscr->mDataSize);
    CallQueueAppend((u32) 0x1b, (u32) (((u32) 0x00000800u)), gSelectRaceRule->mUnk_24, (u32) (((u32) 0x00000800u)));
    CallQueueAppend((u32) 0x1f, (u32) 0, v4->mData, (u32) 0x80);
    CallQueueAppend((u32) 0x23, (u32) 0, v2->mData, v2->mDataSize);
    CallQueueAppend(0x1e, 0, gSelectRaceRule->mNclr->mData, gSelectRaceRule->mNclr->mDataSize);
}

#pragma thumb off

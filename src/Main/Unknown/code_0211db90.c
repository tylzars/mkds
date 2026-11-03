#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020472a8.h"
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

void func_0211db90(void) {
    void *v1;
    Ncgr *v2;
    Ncgr *v3;
    Nclr *v4;
    v2 = NULL;
    v3 = NULL;
    v4 = NULL;
    if (data_0217d368->mUnk_2c == 3) {
        v1 = FindSceneFile(data_0216dc08);
        LocateNcgr(&v3, v1);
        v1 = FindSceneFile(data_0216dbdc);
        LocateNscr((Nscr **) &data_0217d368->mUnk_20, v1);
        v1 = FindSceneFile(data_0216dbe0);
        data_0217d368->mUnk_04 = v1;
        v1 = FindSceneFile(data_0216dc00);
        data_0217d368->mUnk_08 = v1;
        v1 = FindSceneFile(data_0216dbfc);
        data_0217d368->mUnk_0c = v1;
    } else {
        v1 = FindSceneFile(data_0216dbe4);
        LocateNcgr(&v3, v1);
        v1 = FindSceneFile(data_0216dbf0);
        LocateNscr((Nscr **) &data_0217d368->mUnk_20, v1);
        v1 = FindSceneFile(data_0216dbf4);
        data_0217d368->mUnk_04 = v1;
        v1 = FindSceneFile(data_0216dbd4);
        data_0217d368->mUnk_08 = v1;
        v1 = FindSceneFile(data_0216dbe8);
        data_0217d368->mUnk_0c = v1;
    }
    v1 = FindSceneFile(data_0216dbd8);
    LocateNclr(&v4, v1);
    v1 = HeapAlloc((void *) data_0217d368->mHeap, (u32) (((u32) 0x00000800u)));
    data_0217d368->mUnk_24 = v1;
    v1 = FindSceneFile(data_0216dbf8);
    LocateNcgr2(&v2, v1);
    v1 = FindSceneFile(data_0216dc04);
    LocateNcer(&data_0217d368->mUnk_00, v1);
    v1 = FindSceneFile(data_0216dbec);
    LocateNclr((Nclr **) &data_0217d368->mUnk_10, v1);
    func_02016468((u32) 0x14, (u32) 0, v3->mData, v3->mDataSize);
    func_02016468((u32) 0x1b, (u32) 0, (void *) &data_0217d368->mUnk_20->mUnk_0c,
                  (*(u32 *) ((s32) data_0217d368->mUnk_20 + 8)));
    func_02016468((u32) 0x1b, (u32) (((u32) 0x00000800u)), data_0217d368->mUnk_24, (u32) (((u32) 0x00000800u)));
    func_02016468((u32) 0x1f, (u32) 0, v4->mData, (u32) 0x80);
    func_02016468((u32) 0x23, (u32) 0, v2->mData, v2->mDataSize);
    func_02016468(0x1e, 0, (void *) (*(u32 *) (data_0217d368->mUnk_10 + 0xc)), (*(u32 *) (data_0217d368->mUnk_10 + 8)));
}

#pragma thumb off

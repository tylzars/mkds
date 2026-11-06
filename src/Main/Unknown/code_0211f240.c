#include "Main/Unknown/code_0211f240.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"

#include "Main/Unknown/code_0211f2ac.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0211f2b8.h"
#include "code_02016468.h"

#pragma thumb on

void LoadTrophyIconData(void) {
    void *v1;
    Ncgr *v2;
    Unk02021dc8 *v3;
    Nclr *v4[1];
    v2 = NULL;
    v3 = NULL;
    v4[0] = NULL;
    v1 = FindSceneFile(gTrophyIconNcgrName);
    LoadNcgrData(&v2, v1);
    v1 = FindSceneFile(gTrophyIconNcerName);
    LoadNcerData(&v3, v1);
    v1 = FindSceneFile(gTrophyIconNclrName);
    LoadNclrData(v4, v1);
}

void CreateTrophyIcon(void *a) {
    int v1;
    void *v2;
    v1 = ((u32) HeapAlloc(a, 0x10));
    *(s32 *) &gTrophyIcon = v1;
    v2 = FindSceneFile(gTrophyIconNcgrName);
    LocateNcgr2(&gTrophyIcon->mNcgr, v2);
    v2 = FindSceneFile(gTrophyIconNcerName);
    LocateNcer(&gTrophyIcon->mNcer, v2);
    v2 = FindSceneFile(gTrophyIconNclrName);
    LocateNclr(&gTrophyIcon->mNclr, v2);
    v2 = FindSceneFile(gTrophyIconBnclName);
    gTrophyIcon->mBncl = v2;
}

#pragma thumb off

#pragma thumb on

void func_0211f2ac(void) {
    gTrophyIcon = NULL;
}

#pragma thumb off

#pragma thumb on

void QueueTrophyIcon(int a, int b, void *c, void *d, u32 e, u16 f, int g) {
    u32 v1;
    TrophyIcon *v2;
    v1 = 0xe;
    if ((g != 0) && (g == 1)) {
        v1 = 0x1e;
    }
    v2 = gTrophyIcon;
    func_02124748(gTrophyIconBnclIndices[a], v2->mNcer, v2->mNcgr, v2->mBncl, g, e, c, d);
    CallQueueAppend(v1, f << 5, (u8 *) gTrophyIcon->mNclr->mData + gTrophyIconNclrStarts[b] * 0x20, 0x20);
}

void func_0211f240(void) {}

#pragma thumb off

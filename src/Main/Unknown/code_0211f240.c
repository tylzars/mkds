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
    void *sceneFile;
    Ncgr *chars;
    Unk02021dc8 *cells;
    Nclr *palette[1];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = FindSceneFile(gTrophyIconNcgrName);
    LoadNcgrData(&chars, sceneFile);
    sceneFile = FindSceneFile(gTrophyIconNcerName);
    LoadNcerData(&cells, sceneFile);
    sceneFile = FindSceneFile(gTrophyIconNclrName);
    LoadNclrData(palette, sceneFile);
}

void CreateTrophyIcon(void *heap) {
    int allocation;
    void *sceneFile;
    allocation = ((u32) HeapAlloc(heap, 0x10));
    *(s32 *) &gTrophyIcon = allocation;
    sceneFile = FindSceneFile(gTrophyIconNcgrName);
    LocateNcgr2(&gTrophyIcon->mNcgr, sceneFile);
    sceneFile = FindSceneFile(gTrophyIconNcerName);
    LocateNcer(&gTrophyIcon->mNcer, sceneFile);
    sceneFile = FindSceneFile(gTrophyIconNclrName);
    LocateNclr(&gTrophyIcon->mNclr, sceneFile);
    sceneFile = FindSceneFile(gTrophyIconBnclName);
    gTrophyIcon->mBncl = sceneFile;
}

#pragma thumb off

#pragma thumb on

void ClearTrophyIconPointer(void) {
    gTrophyIcon = NULL;
}

#pragma thumb off

#pragma thumb on

void QueueTrophyIcon(int iconIndex, int paletteIndex, void *cells, void *cellLayout, u32 e, u16 paletteSlot, int g) {
    u32 v1;
    TrophyIcon *trophyIcon;
    v1 = 0xe;
    if ((g != 0) && (g == 1)) {
        v1 = 0x1e;
    }
    trophyIcon = gTrophyIcon;
    func_02124748(gTrophyIconBnclIndices[iconIndex], trophyIcon->mNcer, trophyIcon->mNcgr, trophyIcon->mBncl, g, e,
                  cells, cellLayout);
    CallQueueAppend(v1, paletteSlot << 5, (u8 *) gTrophyIcon->mNclr->mData + gTrophyIconNclrStarts[paletteIndex] * 0x20,
                    0x20);
}

void func_0211f240(void) {}

#pragma thumb off

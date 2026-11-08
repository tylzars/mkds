#include "Main/Unknown/code_02116dc8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"

#include "Main/Unknown/code_02116dd4.h"
#include "Main/Unknown/unk_0216d000.h"

#pragma thumb on

void LoadWaitData(void) {
    void *sceneFile;
    Unk02021dc8 *cells;
    Ncgr *chars;
    Nclr *palette[1];
    cells = NULL;
    chars = NULL;
    palette[0] = NULL;
    sceneFile = FindSceneFile(gWaitNcerName);
    LoadNcerData(&cells, sceneFile);
    sceneFile = FindSceneFile(gWaitNcgrName);
    LoadNcgrData2(&chars, sceneFile);
    sceneFile = FindSceneFile(gWaitNclrName);
    LoadNclrData(palette, sceneFile);
}

void CreateWait(void *heap, Unk02021dc8 *destinationNcer, Unk0201ea30 *destinationBncl, u32 destinationBnclIndex,
                u16 paletteIndex, u32 f) {
    Wait *v1;
    Wait *newWait;
    void *sceneFile;
    newWait = HeapAlloc(heap, 0x2c);
    gWait = newWait;
    sceneFile = FindSceneFile(gWaitNcerName);
    LocateNcer(&gWait->mNcer, sceneFile);
    sceneFile = FindSceneFile(gWaitNcgrName);
    LocateNcgr2((Ncgr **) &gWait->mNcgr, sceneFile);
    sceneFile = FindSceneFile(gWaitNclrName);
    LocateNclr(&gWait->mNclr, sceneFile);
    sceneFile = FindSceneFile(gWaitBnclName);
    gWait->mBncl = sceneFile;
    gWait->mDestinationNcer = destinationNcer;
    gWait->mDestinationBncl = destinationBncl;
    gWait->mDestinationBnclIndex = destinationBnclIndex;
    gWait->mPaletteIndex = paletteIndex;
    gWait->mUnk_20 = f;
    gWait->mFrameIndex = 2;
    gWait->mFrameIndexFrames = 3;
}

#pragma thumb off

#pragma thumb on
void ClearWaitPointer(void) {
    u32 pointerAddress;
    u32 zero;
    zero = 0u;
    pointerAddress = (u32) &gWait;
    *(u32 *) ((pointerAddress) + 0u) = zero;
}
#pragma thumb off

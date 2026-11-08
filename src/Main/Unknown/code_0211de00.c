#include "Main/Unknown/code_0211de00.h"

#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0216d000.h"
#include "code_02016468.h"
#include "Main/Unknown/code_0211df44.h"

#pragma thumb on

void LoadCupMarkData(void) {
    void *sceneFile;
    Ncgr *chars;
    Unk02021dc8 *cells;
    Nclr *palette[1];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = FindSceneFile(gCupMarkNcgrName);
    LoadNcgrData(&chars, sceneFile);
    sceneFile = FindSceneFile(gCupMarkNcerName);
    LoadNcerData(&cells, sceneFile);
    sceneFile = FindSceneFile(gCupMarkNclrName);
    LoadNclrData(palette, sceneFile);
}

void LoadCommonCupMarkData(void) {
    void *sceneFile;
    Ncgr *chars;
    Unk02021dc8 *cells;
    Nclr *palette[1];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = FindSceneFile(gCommonCupMarkNcgrName);
    LoadNcgrData(&chars, sceneFile);
    sceneFile = FindSceneFile(gCommonCupMarkNcerName);
    LoadNcerData(&cells, sceneFile);
    sceneFile = FindSceneFile(gCommonCupMarkNclrName);
    LoadNclrData(palette, sceneFile);
}

void CreateCupMark(void *heap) {
    int allocation;
    void *sceneFile;
    allocation = ((u32) HeapAlloc(heap, 0x10));
    *(s32 *) &gCupMark = allocation;
    sceneFile = FindSceneFile(gCupMarkNcgrName);
    LocateNcgr2(&gCupMark->mNcgr, sceneFile);
    sceneFile = FindSceneFile(gCupMarkNcerName);
    LocateNcer(&gCupMark->mNcer, sceneFile);
    sceneFile = FindSceneFile(gCupMarkNclrName);
    LocateNclr(&gCupMark->mNclr, sceneFile);
    sceneFile = FindSceneFile(gCupMarkBnclName);
    gCupMark->mBncl = sceneFile;
}

void CreateCommonCupMark(void *heap) {
    int allocation;
    void *sceneFile;
    allocation = ((u32) HeapAlloc(heap, 0x10));
    *(s32 *) &gCupMark = allocation;
    sceneFile = FindSceneFile(gCommonCupMarkNcgrName);
    LocateNcgr2(&gCupMark->mNcgr, sceneFile);
    sceneFile = FindSceneFile(gCommonCupMarkNcerName);
    LocateNcer(&gCupMark->mNcer, sceneFile);
    sceneFile = FindSceneFile(gCommonCupMarkNclrName);
    LocateNclr(&gCupMark->mNclr, sceneFile);
    sceneFile = FindSceneFile(gCommonCupMarkBnclName);
    gCupMark->mBncl = sceneFile;
}

#pragma thumb off

#pragma thumb on
void ClearCupMarkPointer(void) {
    u32 pointerAddress;
    u32 zero;
    zero = 0u;
    pointerAddress = (u32) &gCupMark;
    *(u32 *) ((pointerAddress) + 0u) = zero;
}
#pragma thumb off

#pragma thumb on

void QueueCupMark(u32 cupMarkIndex, Unk02021dc8 *cells, Unk0201ea30 *cellLayout, u32 d, u16 paletteSlot, s32 f) {
    CupMark *cupMark;
    u8 *dst;
    u32 v0 = 14;
    u32 id;
    u32 paletteIndex;

    if (f != 0) {
        if (f == 1) {
            v0 = 30;
        }
    }
    id = ((u16 *) gCupMarkBnclIndices)[cupMarkIndex];
    cupMark = gCupMark;
    QueueCellChars(id, cupMark->mNcer, cupMark->mNcgr, cupMark->mBncl, f, d, cells, cellLayout);
    cupMark = gCupMark;
    dst = (u8 *) cupMark->mNclr->mData;
    paletteIndex = GetCellPaletteIndex(id, cupMark->mNcer, cupMark->mBncl);
    CallQueueAppend(v0, paletteSlot << 5, dst + (paletteIndex << 5), 32);
}

void LoadSelectCupNameMData(void) {
    void *sceneFile;
    Ncgr *chars;
    Unk02021dc8 *cells[1];
    chars = NULL;
    cells[0] = NULL;
    sceneFile = FindSceneFile(gSelectCupNameMNcgrName);
    LoadNcgrData2(&chars, sceneFile);
    sceneFile = FindSceneFile(gSelectCupNameMNcerName);
    LoadNcerData(cells, sceneFile);
}

void CreateSelectCupNameM(void *heap) {
    int allocation;
    void *sceneFile;
    allocation = ((u32) HeapAlloc(heap, 0xc));
    *(s32 *) &gSelectCupNameM = allocation;
    sceneFile = FindSceneFile(gSelectCupNameMNcgrName);
    LocateNcgr2((Ncgr **) gSelectCupNameM, sceneFile);
    sceneFile = FindSceneFile(gSelectCupNameMNcerName);
    LocateNcer(&gSelectCupNameM->mNcer, sceneFile);
    sceneFile = FindSceneFile(gSelectCupNameMBnclName);
    gSelectCupNameM->mBncl = sceneFile;
}

#pragma thumb off

#pragma thumb on
void ClearSelectCupNameMPointer(void) {
    u32 pointerAddress;
    u32 zero;
    zero = 0u;
    pointerAddress = (u32) &gSelectCupNameM;
    *(u32 *) ((pointerAddress) + 0u) = zero;
}
#pragma thumb off

#pragma thumb on

void QueueSelectCupNameM(u32 nameIndex, Unk02021dc8 *cells, Unk0201ea30 *cellLayout, u32 d, u32 e) {
    QueueCellChars(gSelectCupNameMBnclIndices[nameIndex], gSelectCupNameM->mNcer, gSelectCupNameM->mNcgr,
                   gSelectCupNameM->mBncl, e, d, cells, cellLayout);
}

#pragma thumb off

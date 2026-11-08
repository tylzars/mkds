#include "Main/Unknown/code_021171a0.h"
#include "Main/Unknown/code_02036820.h"

#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02117218.h"
#include "Main/Unknown/code_02117224.h"
#include "Main/Unknown/code_021172a8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/code_0211732c.h"
#include "Main/Unknown/code_02047104.h"

#pragma thumb on

void LoadKartIconData(void) {
    void *sceneFile;
    int paletteCount;
    const char **nclrNameCursor;
    Ncgr *chars;
    Unk02021dc8 *cells;
    Nclr *palette[2];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = FindSceneFile(gKartIconNcgrName);
    LoadNcgrData(&chars, sceneFile);
    sceneFile = FindSceneFile(gKartIconNcerName);
    LoadNcerData(&cells, sceneFile);
    paletteCount = 0;
    nclrNameCursor = gKartIconNclrNames;
    do {
        sceneFile = FindSceneFile(*nclrNameCursor);
        LoadNclrData(palette, sceneFile);
        nclrNameCursor = nclrNameCursor + 1;
        paletteCount = paletteCount + 1;
    } while (paletteCount < 3);
}

void LoadCommonKartIconData(void) {
    void *sceneFile;
    int paletteCount;
    const char **nclrNameCursor;
    Ncgr *chars;
    Unk02021dc8 *cells;
    Nclr *palette[2];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = FindSceneFile(gCommonKartIconNcgrName);
    LoadNcgrData(&chars, sceneFile);
    sceneFile = FindSceneFile(gCommonKartIconNcerName);
    LoadNcerData(&cells, sceneFile);
    paletteCount = 0;
    nclrNameCursor = gCommonKartIconNclrNames;
    do {
        sceneFile = FindSceneFile(*nclrNameCursor);
        LoadNclrData(palette, sceneFile);
        nclrNameCursor = nclrNameCursor + 1;
        paletteCount = paletteCount + 1;
    } while (paletteCount < 3);
}

#pragma thumb off

#pragma thumb on

void CreateKartIcon(void *heap) {
    int i;

    gKartIcon = HeapAlloc(heap, 0x18);
    LocateNcgr2(&gKartIcon->mNcgr, FindSceneFile(gKartIconNcgrName));
    LocateNcer(&gKartIcon->mNcer, FindSceneFile(gKartIconNcerName));
    for (i = 0; i < 3; i++) {
        LocateNclr(&gKartIcon->mNclrs[i], FindSceneFile(gKartIconNclrNames[i]));
    }
    gKartIcon->mBncl = FindSceneFile(gKartIconBnclName);
}

#pragma thumb off

#pragma thumb on

void CreateCommonKartIcon(void *heap) {
    s32 i;

    gKartIcon = HeapAlloc(heap, 0x18);
    LocateNcgr2(&gKartIcon->mNcgr, FindSceneFile(gCommonKartIconNcgrName));
    LocateNcer(&gKartIcon->mNcer, FindSceneFile(gCommonKartIconNcerName));
    for (i = 0; i < 3; i++) {
        LocateNclr(&gKartIcon->mNclrs[i], FindSceneFile(gCommonKartIconNclrNames[i]));
    }
    gKartIcon->mBncl = FindSceneFile(gCommonKartIconBnclName);
}

#pragma thumb off

#pragma thumb on
void ClearKartIconPointer(void) {
    u32 pointerAddress;
    u32 zero;
    zero = 0u;
    pointerAddress = (u32) &gKartIcon;
    *(u32 *) ((pointerAddress) + 0u) = zero;
}
#pragma thumb off

#pragma thumb on

void QueueKartIcon(s32 iconIndex, Unk02021dc8 *destinationNcer, Unk0201ea30 *destinationBncl, u32 destinationBnclIndex,
                   u16 paletteIndex, s32 f) {
    int queueKind;

    queueKind = 0x12;
    switch (f) {
        case 0:
            queueKind = 0xe;
            break;
        case 1:
            queueKind = 0x1e;
            break;
    }
    QueueCellChars(gKartIconRows[iconIndex].mBnclIndex, gKartIcon->mNcer, gKartIcon->mNcgr, gKartIcon->mBncl, f,
                   destinationBnclIndex, destinationNcer, destinationBncl);
    CallQueueAppend(
        queueKind, paletteIndex * 32,
        gKartIcon->mNclrs[gKartIconRows[iconIndex].mNclrIndex]->mData + gKartIconRows[iconIndex].mNclrStart * 16, 0x20);
}

#pragma thumb off

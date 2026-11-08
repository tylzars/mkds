#include "Main/Unknown/code_020ae630.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200eddc.h"
#include "code_0214c778.h"

#pragma optimize_for_size on

#pragma thumb on

void ResetOamLists(void *mainOam, void *subOam) {
    Unk020ae630 *mainOamList = mainOam;
    Unk020ae630 *subOamList = subOam;

    if (mainOamList != NULL) {
        mainOamList->mOamCount = 0;
        mainOamList->mMatrixCount = 0;
        MI_DmaFill32(3, mainOamList, 0xc0, 0x400);
    }
    if (subOamList != NULL) {
        subOamList->mOamCount = 0;
        subOamList->mMatrixCount = 0;
        MI_DmaFill32(3, subOamList, 0xc0, 0x400);
    }
}

void ClearOamListCounts(void *mainOam, void *subOam) {
    Unk020ae630 *mainOamList = mainOam;
    Unk020ae630 *subOamList = subOam;

    if (mainOamList != NULL) {
        mainOamList->mOamCount = 0;
        mainOamList->mMatrixCount = 0;
    }
    if (subOamList != NULL) {
        subOamList->mOamCount = 0;
        subOamList->mMatrixCount = 0;
    }
}

void func_020ae630(void *mainOam, void *subOam) {
    Unk020ae630 *mainOamList = mainOam;
    Unk020ae630 *subOamList = subOam;
    u16 usedEntryCount;
    s32 i;

    if (mainOamList != NULL) {
        usedEntryCount = mainOamList->mOamCount;
        DC_FlushRange(mainOamList, 0x400);
        for (i = 0; i < 0x80 - usedEntryCount; i++) {
            mainOamList->mUnk_00[usedEntryCount + i].mUnk_00 =
                (mainOamList->mUnk_00[usedEntryCount + i].mUnk_00 & 0xfe00ffff) | 0x1800000;
            mainOamList->mUnk_00[usedEntryCount + i].mUnk_00_0 = 0xe0;
        }
    }
    if (subOamList != NULL) {
        usedEntryCount = subOamList->mOamCount;
        DC_FlushRange(subOamList, 0x400);
        for (i = 0; i < 0x80 - usedEntryCount; i++) {
            subOamList->mUnk_00[usedEntryCount + i].mUnk_00 =
                (subOamList->mUnk_00[usedEntryCount + i].mUnk_00 & 0xfe00ffff) | 0x1800000;
            subOamList->mUnk_00[usedEntryCount + i].mUnk_00_0 = 0xe0;
        }
    }
}

#pragma thumb off

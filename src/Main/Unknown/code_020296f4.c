#include "Main/Unknown/code_020296f4.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_02122734.h"
#include "Main/Unknown/code_02122794.h"
#include "Main/Unknown/unk_02174000.h"
#include "00/code_02181f98.h"

#pragma optimize_for_size on

#pragma thumb on

void func_020297bc(void) {
    u16 packedIndex;
    u16 nextEntryIndex = 0;
    u8 kartMask;
    u8 index;
    func_0202991c(0);
    for (packedIndex = 0; packedIndex < 4; packedIndex++) {
        if (GetKartMaskBitOfPackedIndex(packedIndex) != 0) {
            SetNextRaceEntry(nextEntryIndex, gRaceSetupCopy->mEntries[packedIndex].mCharacterIndex,
                             gRaceSetupCopy->mEntries[packedIndex].mKartIndex,
                             gRaceSetupCopy->mEntries[packedIndex].mPlayerKind, -1, 3);
            nextEntryIndex++;
        }
    }
    for (; nextEntryIndex < 8; nextEntryIndex++) {
        SetNextRaceEntry(nextEntryIndex, -1, -1, PLAYER_KIND_NONE, -1, 3);
    }
    func_02029908(5);
    func_020298f4(gRaceSetupCopy->mCourseId);
    func_020298e0(1);
    func_020298cc(0);
    func_020298b8(0);
    func_020298a4(0);
    func_02029890(0);
    kartMask = 0;
    for (index = 0; index < 4; index++) {
        if (GetKartMaskBit(index) != 0) {
            kartMask |= 1 << index;
        }
    }
    func_0205cfd4(kartMask);
}

void func_02029758(void) {
    u8 packedIndex;
    s32 index;
    for (packedIndex = 0; packedIndex < 4; packedIndex++) {
        if (GetKartMaskBitOfPackedIndex(packedIndex) != 0) {
            index = GetIndexOfPackedIndex(packedIndex);
            data_0217b488->mUnk_20[index].mCharacterIndex = gRaceSetupCopy->mEntries[packedIndex].mCharacterIndex;
            data_0217b488->mUnk_20[index].mKartIndex = gRaceSetupCopy->mEntries[packedIndex].mKartIndex;
            data_0217b488->mUnk_20[index].mPlayerKind = gRaceSetupCopy->mEntries[packedIndex].mPlayerKind;
        }
    }
}

void func_020296f4(void) {
    u8 index;
    s32 packedIndex;
    for (index = 0; index < 4; index++) {
        if (GetKartMaskBit(index) != 0) {
            packedIndex = GetPackedIndex(index);
            gRaceSetupCopy->mEntries[packedIndex].mCharacterIndex = data_0217b488->mUnk_20[index].mCharacterIndex;
            gRaceSetupCopy->mEntries[packedIndex].mKartIndex = data_0217b488->mUnk_20[index].mKartIndex;
            gRaceSetupCopy->mEntries[packedIndex].mPlayerKind = data_0217b488->mUnk_20[index].mPlayerKind;
        }
    }
}

#pragma thumb off

#include "Main/Unknown/code_02116ec0.h"

#include "Main/Unknown/code_0203ba84.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203be48.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0202056c.h"
#include "Main/Unknown/code_02036820.h"

#pragma thumb on

void CreateCharacterKartPicks(void *heap) {
    u32 v1;
    v1 = ((u32) HeapAlloc(heap, 4));
    *(u32 *) &gPicksHolder = v1;
    v1 = (u32) func_0203bedc(heap);
    *(u32 *) (*(u32 *) &gPicksHolder) = v1;
}

#pragma thumb off

#pragma thumb on

void ClearPicksHolderPointer(void) {
    gPicksHolder = NULL;
}

void func_021170f8(void) {
    int n;
    BOOL isEightOrNine;
    u32 zeroValue, noIndex;

    func_0203bec0(gPicksHolder->mPicks);
    if (data_021759d0->mUnk_20 == 0) {
        n = 1;
    } else {
        isEightOrNine = TRUE;
        if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
            isEightOrNine = FALSE;
        }
        n = (u8) (isEightOrNine != FALSE ? CountSetBits(data_0217aa00->mParticipantMask) : 0);
    }
    zeroValue = 0;
    noIndex = ~0;
    for (; n < 8; n++) {
        SetCharacterIndex(n, noIndex);
        func_020294ac(n, zeroValue);
    }
}

void func_02117060(void) {
    int i;
    int n;
    BOOL isEightOrNine;
    u32 zeroValue, noIndex;

    func_0203bec0(gPicksHolder->mPicks);
    if (data_021759d0->mUnk_20 == 0) {
        n = 1;
    } else {
        isEightOrNine = TRUE;
        if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
            isEightOrNine = FALSE;
        }
        n = (u8) (isEightOrNine != FALSE ? CountSetBits(data_0217aa00->mParticipantMask) : 0);
    }
    for (i = 0; i < 8; i++) {
        func_0203bea4(gPicksHolder->mPicks, (u8) i, GetCharacterIndex(i));
    }
    zeroValue = 0;
    noIndex = ~0;
    for (; n < 8; n++) {
        SetKartIndex(n, noIndex);
        func_020294ac(n, zeroValue);
    }
}

void FillRandomCharacterIndices(void) {
    int i;
    int n;
    BOOL isEightOrNine;
    u32 pickedIndex;

    pickedIndex = ~0;
    if (data_021759d0->mUnk_20 == 0) {
        n = 1;
    } else {
        isEightOrNine = TRUE;
        if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
            isEightOrNine = FALSE;
        }
        n = (u8) (isEightOrNine != FALSE ? CountSetBits(data_0217aa00->mParticipantMask) : 0);
    }
    for (i = 0; i < n; i++) {
        func_0203bea4(gPicksHolder->mPicks, (u8) i, GetCharacterIndex(i));
    }
    PickRandomCharacters(gPicksHolder->mPicks);
    for (; n < 8; n++) {
        func_0203be48(gPicksHolder->mPicks, n, &pickedIndex, NULL);
        SetCharacterIndex(n, pickedIndex);
    }
}

void FillRandomKartIndices(void) {
    int i;
    int n;
    BOOL isEightOrNine;
    u32 pickedIndex;

    pickedIndex = ~0;
    if (data_021759d0->mUnk_20 == 0) {
        n = 1;
    } else {
        isEightOrNine = TRUE;
        if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
            isEightOrNine = FALSE;
        }
        n = (u8) (isEightOrNine != FALSE ? CountSetBits(data_0217aa00->mParticipantMask) : 0);
    }
    for (i = 0; i < n; i++) {
        func_0203be88(gPicksHolder->mPicks, (u8) i, GetKartIndex(i));
    }
    PickRandomKarts(gPicksHolder->mPicks);
    for (; n < 8; n++) {
        func_0203be48(gPicksHolder->mPicks, n, NULL, &pickedIndex);
        SetKartIndex(n, pickedIndex);
        func_020294ac(n, 1);
    }
}

void SetKartIndicesFromCharacters(void) {
    int i;

    for (i = 0; i < 8; i++) {
        SetKartIndex(i, data_0215c5d8[GetCharacterIndex(i)]);
        func_020294ac(i, 1);
    }
}

#pragma thumb off

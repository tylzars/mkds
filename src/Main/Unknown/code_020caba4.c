#include "Main/Unknown/code_020caba4.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ca984.h"
#include "Main/Unknown/code_020ca9dc.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
s32 MoveEmblemChoisesIndex(s32 step) {
    s32 previousIndex;
    s32 choisesCount;

    previousIndex = gEmblemChoises->mChoisesIndex;
    if (gEmblemChoises->mShown != 0) {
        choisesCount = gEmblemChoises->mChoisesCount;
        if (step != 0) {
            gEmblemChoises->mUnk_24 = 0;
            StartSoundOncePerFrame(0);
        }
        gEmblemChoises->mChoisesIndex = (previousIndex + step + choisesCount) % choisesCount;
    }
    return previousIndex;
}

s32 func_020cacc0(void) {
    BOOL touched;
    s32 choisesCount;
    BOOL zeroStep;
    s32 i;
    s32 j;
    PairRect choiceRects[6];

    touched = FALSE;
    if (gEmblemChoises->mShown != 0) {
        MoveEmblemChoisesIndex(touched);
        choisesCount = gEmblemChoises->mChoisesCount;
        for (i = 0; i < choisesCount; i++) {
            s32 minY;

            minY = (12 - choisesCount * 2 + i * 4) * 8 + 6;
            choiceRects[i].mMinX = 8;
            choiceRects[i].mMaxX = 0xf8;
            choiceRects[i].mMinY = minY;
            choiceRects[i].mMaxY = minY + 0x16;
        }
        zeroStep = FALSE;
        for (j = 0; j < choisesCount; j++) {
            if (IsNewPairInRect(GetEmblemChoisesInputSlot(), choiceRects[j])) {
                if (gEmblemChoises->mChoisesIndex != j) {
                    gEmblemChoises->mChoisesIndex = j;
                    MoveEmblemChoisesIndex(zeroStep);
                } else {
                    gEmblemChoises->mUnk_10 = TRUE;
                }
                switch (gEmblemChoises->mChoisesIndex) {
                    case 0:
                        StartEmblemChoisesSound(0x10);
                        break;
                    case 1:
                        StartEmblemChoisesSound(0xb);
                        break;
                    case 2:
                        StartEmblemChoisesSound(5);
                        break;
                }
                touched = TRUE;
            }
        }
    }
    return touched;
}

void ResetEmblemChoisesState(void) {
    gEmblemChoises->mResult = -1;
    gEmblemChoises->mChoisesIndex = 0;
    gEmblemChoises->mUnk_24 = 0;
    gEmblemChoises->mUnk_10 = FALSE;
    gEmblemChoises->mUnk_14 = 0;
    gEmblemChoises->mUnk_18 = 0;
}

void func_020cac68(u16 *mapData, s32 column, s32 row) {
    SetScreenMapBlockLowBits(mapData, column, row, 1, 1, 4);
    SetScreenMapBlockLowBits(mapData, column, row + 1, 1, 1, 0x24);
}

void func_020cac18(void) {
    s32 choisesCount;
    u16 *mapData;
    s32 i;

    choisesCount = gEmblemChoises->mChoisesCount;
    mapData = gEmblemChoises->mChoisesS3Nscr->mData;
    if (mapData != NULL) {
        for (i = 0; i < choisesCount; i++) {
            func_020cac68(mapData, 2, 13 - choisesCount * 2 + i * 4);
        }
        SetScreenMapBlockTopBits(mapData, 0, 0, 0x20, 0x18, 0xf);
    }
}

void func_020caba4(s32 choiceIndex) {
    EmblemChoises *emblemChoises;
    s32 choisesCount;
    u16 *mapData;
    s32 firstRow;

    emblemChoises = gEmblemChoises;
    choisesCount = emblemChoises->mChoisesCount;
    mapData = emblemChoises->mChoisesS3Nscr->mData;
    if (mapData != NULL) {
        if (emblemChoises->mUnk_10 == FALSE || emblemChoises->mUnk_14 >= 5) {
            firstRow = 13 - choisesCount * 2 + choiceIndex * 4;
            if (emblemChoises->mUnk_24 < 0x1e) {
                SetScreenMapBlockLowBits(mapData, 2, firstRow, 1, 1, 0x21);
                SetScreenMapBlockLowBits(mapData, 2, firstRow + 1, 1, 1, 0x41);
            }
            SetScreenMapBlockTopBits(mapData, 0, firstRow - 1, 0x20, 4, 0xe);
        }
    }
}
#pragma thumb off

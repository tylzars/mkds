#include "Main/Unknown/code_020bc11c.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020b19b4.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b1000.h"
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020b85dc.h"
#include "code_020222ec.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_020b6e00.h"
#include "Main/Unknown/code_020b8000.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020be7fc.h"
#include "Main/Unknown/code_020be930.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

void StopRaceRankListItemInUse(int kartIndex) {
    gRaceRankList->mItemsInUse[kartIndex].mInUseFrames = 0;
}

// Starts the 0x24-frame display of the item kart kartIndex has just put in use; its cell blinks.
void StartRaceRankListItemInUse(s32 kartIndex, s32 itemId, s32 objectCount) {
    gRaceRankList->mItemsInUse[kartIndex].mInUseFrames = 1;
    gRaceRankList->mItemsInUse[kartIndex].mItemInfoIndex = itemId;
    gRaceRankList->mItemsInUse[kartIndex].mObjectCount = objectCount;
}

void InitRaceRankList(void) {
    u8 i;

    gRaceRankList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x15c);
    for (i = 0; i < (s32) gRaceSetup->mKartCount; i++) {
        gRaceRankList->mRanks[i] = 1;
        gRaceRankList->mPrevRanks[i] = gRaceRankList->mRanks[i];
        gRaceRankList->mKartsByRank[i] = 0;
        gRaceRankList->mBalloonOrShineCounts[i] = 0;
    }
    gRaceRankList->mSlideX = 0;
    gRaceRankList->mOamMatrixIndex = 0;
    gRaceRankList->mMatrix[0] = 0xc4e;
    gRaceRankList->mMatrix[1] = 0;
    gRaceRankList->mMatrix[2] = 0;
    gRaceRankList->mMatrix[3] = 0xc4e;
    gRaceRankList->mMoveFrames = 0;
}

u32 ClearRaceRankListPointer(void) {
    u32 pointerAddress;
    u32 nullValue;
    pointerAddress = (u32) &gRaceRankList;
    nullValue = 0u;
    *(u32 *) ((pointerAddress) + (0)) = nullValue;
    return pointerAddress;
}

// Every 0x1c calls it re-reads each kart's rank and slides its row from the old rank slot to the new one.
void UpdateRaceRankList(void) {
    RaceRankListPos slotPositions[9] = {{0x1b, 0xf},  {0x1b, 0xf},  {0x1b, 0x26}, {0x1b, 0x3d}, {0x1b, 0x54},
                                        {0x1b, 0x6b}, {0x1b, 0x82}, {0x1b, 0x99}, {0x1b, 0xb0}};
    RaceRankListPos fromPosition;
    RaceRankListPos toPosition;
    RaceRankListPos position;
    s32 rankKeys[8];
    s32 moveFrames;
    s32 middleFrames;
    u8 i;
    KartItems *kartItems;

    moveFrames = gRaceRankList->mMoveFrames;
    if (GetRaceStartSequenceFrames() <= 0x188) {
        gRaceRankList->mSlideX = (0x20 - (GetRaceStartSequenceFrames() - 0x168)) * 4;
    } else {
        gRaceRankList->mSlideX = 0;
    }
    if (GetRaceStartSequenceFrames() < 0x168) {
        return;
    }
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        return;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        for (i = 0; i < (s32) gRaceSetup->mKartCount; i++) {
            gRaceRankList->mBalloonOrShineCounts[i] = GetBalloonOrShineCount(i);
        }
    }
    for (i = 0; i < (s32) gRaceSetup->mKartCount; i++) {
        kartItems = &gKartItems[i];
        gRaceRankList->mShownItems[i] =
            kartItems->mHeldItem.mItemInfoIndex == 0x13 ? kartItems->mActiveItem : kartItems->mHeldItem.mItemInfoIndex;
        if (gRaceRankList->mMoveFrames % 0x1c == 0) {
            gRaceRankList->mPrevRanks[i] = gRaceRankList->mRanks[i];
            gRaceRankList->mRanks[i] = GetKartRank(i);
        }
        fromPosition = slotPositions[gRaceRankList->mPrevRanks[i]];
        toPosition = slotPositions[gRaceRankList->mRanks[i]];
        if (gRaceRankList->mPrevRanks[i] > gRaceRankList->mRanks[i]) {
            if (moveFrames < 10) {
                position.mX = fromPosition.mX + (moveFrames * 16) / 10;
                position.mY = fromPosition.mY;
            } else if (moveFrames < 0x12) {
                middleFrames = moveFrames - 10;
                position.mX = fromPosition.mX + (toPosition.mX - fromPosition.mX) * middleFrames / 8 + 0x10;
                position.mY = fromPosition.mY + (toPosition.mY - fromPosition.mY) * middleFrames / 8;
            } else {
                position.mX = fromPosition.mX + 0x10 - ((moveFrames - 0x12) * 16) / 10;
                position.mY = toPosition.mY;
            }
        } else {
            position.mX = fromPosition.mX + moveFrames * (toPosition.mX - fromPosition.mX) / 0x1c;
            position.mY = fromPosition.mY + moveFrames * (toPosition.mY - fromPosition.mY) / 0x1c;
        }
        gRaceRankList->mRowPositions[i] = position;
    }
    for (i = 0; i < (s32) gRaceSetup->mKartCount; i++) {
        gRaceRankList->mKartsByRank[i] = i;
        rankKeys[i] = gRaceRankList->mRanks[i];
    }
    SortIndicesByKey(gRaceRankList->mKartsByRank, rankKeys, gRaceSetup->mKartCount);
    gRaceRankList->mMoveFrames++;
    if (gRaceRankList->mMoveFrames >= 0x1c) {
        gRaceRankList->mMoveFrames = 0;
    }
    for (i = 0; i < (s32) gRaceSetup->mKartCount; i++) {
        if (gRaceRankList->mItemsInUse[i].mInUseFrames != 0) {
            gRaceRankList->mItemsInUse[i].mInUseFrames++;
            if (gRaceRankList->mItemsInUse[i].mInUseFrames > 0x24) {
                gRaceRankList->mItemsInUse[i].mInUseFrames = 0;
            }
        }
    }
}

void DrawRaceRankList(RaceHudOamBuffer *oamBuffer) {
    s32 *matrix;
    GXOamAttr *oams;

    if (GetRaceStartSequenceFrames() < 0x168) {
        return;
    }
    gRaceRankList->mOamMatrixIndex = AllocOamMatrixIndex(oamBuffer);
    switch (gRaceSetup->mMode) {
        case MODE_GRAND_PRIX:
        case MODE_VS:
        case 5:
            DrawRaceRankListNonBattleRows(oamBuffer);
            break;
        case MODE_BATTLE:
            switch (GetRaceHudSubScreenState()) {
                case 0:
                    DrawRaceRankListBattleState0Rows(oamBuffer);
                    break;
                case 1:
                case 2:
                case 3:
                    DrawRaceRankListBattleState1To3Rows(oamBuffer);
                    break;
            }
            break;
    }
    matrix = gRaceRankList->mMatrix;
    oams = &oamBuffer->mOams[gRaceRankList->mOamMatrixIndex * 4];
    oams[0].mUnk_00[3] = matrix[0] >> 4;
    oams[1].mUnk_00[3] = matrix[1] >> 4;
    oams[2].mUnk_00[3] = matrix[2] >> 4;
    oams[3].mUnk_00[3] = matrix[3] >> 4;
}

// Returns the cell index beside the kart (0xc9 = none): cell 0x24 or 0x25, the item just used, the held item or 0x16.
u32 GetRaceRankListSNcerIndex(u16 kartIndex) {
    u32 cellIndex;
    RaceRankList *rankList;
    RaceRankListItemInUse *itemIndexView;
    s32 framesSinceStart;

    if (GetRaceHudKartRemoved(kartIndex) != 0) {
        cellIndex = 0x25;
    } else if (gRaceSetup->mMode == MODE_BATTLE && IsKartOnWinningTeamAtEnd(kartIndex) != 0) {
        cellIndex = 0x24;
    } else if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated(kartIndex) != FALSE) {
        cellIndex = 0xc9;
    } else if (gRaceSetup->mMode != MODE_BATTLE && IsKartEnded(kartIndex) != 0) {
        cellIndex = 0x24;
    } else if ((rankList = gRaceRankList)->mItemsInUse[kartIndex].mInUseFrames != 0) {
// itemIndexView starts at mItemsInUse[0].mItemInfoIndex, so its [k].mInUseFrames is kart k's item index.
        framesSinceStart = rankList->mItemsInUse[kartIndex].mInUseFrames - 1;
        if (framesSinceStart % 12 < 6) {
            cellIndex = 0xc9;
        } else if ((itemIndexView = (RaceRankListItemInUse *) &rankList->mItemsInUse[0].mItemInfoIndex)[kartIndex]
                       .mInUseFrames == 5) {
            switch (rankList->mItemsInUse[kartIndex].mObjectCount) {
                case 1:
                    cellIndex = 0x11;
                    break;
                case 2:
                    cellIndex = 0x12;
                    break;
                case 3:
                    cellIndex = 0x13;
                    break;
            }
        } else {
            cellIndex = LookupRaceSNcerIndex(kartIndex, itemIndexView[kartIndex].mInUseFrames);
        }
    } else if (rankList->mShownItems[kartIndex] != 0x13) {
        cellIndex = LookupRaceSNcerIndex(kartIndex, rankList->mShownItems[kartIndex]);
    } else if (gKartItems[kartIndex].mSlotState == 1) {
        cellIndex = 0x16;
    } else {
        cellIndex = 0xc9;
    }
    return cellIndex;
}

void DrawRaceRankListRankCells(RaceHudOamBuffer *oamBuffer) {
    s32 slotPositions[8][2] = {{8, 0xf}, {8, 0x26}, {8, 0x3d}, {8, 0x54}, {8, 0x6b}, {8, 0x82}, {8, 0x99}, {8, 0xb0}};
    u16 i;
    s32 slideX;
    s32 rankSlot;
    s32 markerIndex;
    s32 slotY;
    s32 rankDrawPosition[2];
    s32 markerDrawPosition[2];
    Unk020224e0_c *cell;

    slideX = gRaceRankList->mSlideX;
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        rankSlot = gRaceRankList->mPrevRanks[i] - 1;
        cell = GetRaceSNcerEntry(rankSlot + 0x35);
        rankDrawPosition[0] = (slotPositions[rankSlot][0] - slideX - 1) << 12;
        slotY = slotPositions[rankSlot][1];
        rankDrawPosition[1] = (slotY - 4) << 12;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, rankDrawPosition, 0, 1);
        markerIndex = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated(i) != FALSE) {
            markerIndex = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE && (GetRaceHudKartRemoved(i) != 0 || func_0207a84c(i) != 0)) {
            markerIndex = 1;
        }
        if (markerIndex != 0) {
            markerIndex = 3;
        } else if (i == GetFollowedKartOrEntryIndex()) {
            markerIndex = 0;
        } else if (gRaceSetup->mUseTeams != 0 && gRaceSetup->mCurrentEntries[i].mPlayer.mTeamIndex == 1) {
            markerIndex = 2;
        } else {
            markerIndex = 1;
        }
        cell = GetRaceSNcerEntry(markerIndex + 0x75);
        markerDrawPosition[0] = -slideX << 12;
        markerDrawPosition[1] = slotY << 12;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, markerDrawPosition, 0, 1);
    }
}

void DrawRaceRankListState0Rows(RaceHudOamBuffer *oamBuffer) {
    u16 i;
    s32 kartIndex;
    RaceRankListPos position;
    s32 itemCellIndex;
    u16 matrixIndex;
    s32 *matrix;
    s32 secondKartCellBase;
    s32 itemDrawPosition[2];
    s32 kartDrawPosition[2];
    s32 secondKartDrawPosition[2];
    s32 markerDrawPosition[2];
    s32 markerIndex;
    Unk020224e0_c *cell;

    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        kartIndex = gRaceRankList->mKartsByRank[i];
        position = gRaceRankList->mRowPositions[kartIndex];
        itemCellIndex = GetRaceRankListSNcerIndex(kartIndex);
        position.mX -= gRaceRankList->mSlideX;
        if (itemCellIndex != 0xc9) {
            cell = GetRaceSNcerEntry(itemCellIndex);
            itemDrawPosition[0] = (position.mX + 0x45) << 12;
            itemDrawPosition[1] = position.mY << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      itemDrawPosition, 0, 1);
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrixIndex = gRaceRankList->mOamMatrixIndex;
        } else {
            matrixIndex = 0;
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrix = gRaceRankList->mMatrix;
        } else {
            matrix = NULL;
        }
        cell = GetRaceSNcerEntry(kartIndex + 8);
        kartDrawPosition[0] = position.mX << 12;
        kartDrawPosition[1] = position.mY << 12;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, matrix,
                                  kartDrawPosition, matrixIndex, 1);
        secondKartCellBase = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) kartIndex) != FALSE) {
            secondKartCellBase = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE &&
                   (GetRaceHudKartRemoved((u16) kartIndex) != 0 || func_0207a84c((u16) kartIndex) != 0)) {
            secondKartCellBase = 1;
        }
        secondKartCellBase = secondKartCellBase != 0 ? 0x6d : 0x65;
        cell = GetRaceSNcerEntry(secondKartCellBase + kartIndex);
        secondKartDrawPosition[0] = (position.mX + 0xa) << 12;
        secondKartDrawPosition[1] = position.mY << 12;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                  secondKartDrawPosition, 0, 1);
        markerIndex = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) kartIndex) != FALSE) {
            markerIndex = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE &&
                   (GetRaceHudKartRemoved((u16) kartIndex) != 0 || func_0207a84c((u16) kartIndex) != 0)) {
            markerIndex = 1;
        }
        if (markerIndex != 0) {
            markerIndex = 3;
        } else if ((u16) kartIndex == GetFollowedKartOrEntryIndex()) {
            markerIndex = 0;
        } else if (gRaceSetup->mUseTeams != 0 && gRaceSetup->mCurrentEntries[(u16) kartIndex].mPlayer.mTeamIndex == 1) {
            markerIndex = 2;
        } else {
            markerIndex = 1;
        }
        cell = GetRaceSNcerEntry(markerIndex + 0x79);
        markerDrawPosition[0] = (position.mX - 0xb) << 12;
        markerDrawPosition[1] = position.mY << 12;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, markerDrawPosition, 0, 1);
    }
}

void DrawRaceRankListState1To3Rows(RaceHudOamBuffer *oamBuffer) {
    u16 i;
    s32 kartIndex;
    RaceRankListPos position;
    s32 itemCellIndex;
    s32 *matrix;
    u16 matrixIndex;
    s32 itemDrawPosition[2];
    s32 kartDrawPosition[2];
    s32 markerDrawPosition[2];
    s32 markerIndex;
    Unk020224e0_c *cell;

    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        kartIndex = gRaceRankList->mKartsByRank[i];
        position = gRaceRankList->mRowPositions[kartIndex];
        itemCellIndex = GetRaceRankListSNcerIndex(kartIndex);
        position.mX -= gRaceRankList->mSlideX;
        if (itemCellIndex != 0xc9) {
            cell = GetRaceSNcerEntry(itemCellIndex);
            itemDrawPosition[0] = (position.mX + 0x12) << 12;
            itemDrawPosition[1] = position.mY << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      itemDrawPosition, 0, 1);
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrixIndex = gRaceRankList->mOamMatrixIndex;
        } else {
            matrixIndex = 0;
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrix = gRaceRankList->mMatrix;
        } else {
            matrix = NULL;
        }
        cell = GetRaceSNcerEntry(kartIndex + 8);
        kartDrawPosition[0] = position.mX << 12;
        kartDrawPosition[1] = position.mY << 12;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, matrix,
                                  kartDrawPosition, matrixIndex, 1);
        markerIndex = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) kartIndex) != FALSE) {
            markerIndex = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE &&
                   (GetRaceHudKartRemoved((u16) kartIndex) != 0 || func_0207a84c((u16) kartIndex) != 0)) {
            markerIndex = 1;
        }
        if (markerIndex != 0) {
            markerIndex = 3;
        } else if ((u16) kartIndex == GetFollowedKartOrEntryIndex()) {
            markerIndex = 0;
        } else if (gRaceSetup->mUseTeams != 0 && gRaceSetup->mCurrentEntries[(u16) kartIndex].mPlayer.mTeamIndex == 1) {
            markerIndex = 2;
        } else {
            markerIndex = 1;
        }
        cell = GetRaceSNcerEntry(markerIndex + 0x7d);
        markerDrawPosition[0] = (position.mX - 0xb) << 12;
        markerDrawPosition[1] = position.mY << 12;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, markerDrawPosition, 0, 1);
    }
}

void DrawRaceRankListNonBattleRows(RaceHudOamBuffer *a) {
    switch (GetRaceHudSubScreenState()) {
        case 0:
            DrawRaceRankListRankCells(a);
            DrawRaceRankListState0Rows(a);
            break;
        case 1:
        case 2:
        case 3:
            DrawRaceRankListRankCells(a);
            DrawRaceRankListState1To3Rows(a);
            break;
    }
}

void DrawRaceRankListBattleState0Rows(RaceHudOamBuffer *oamBuffer) {
    s32 secondKartCellBase;
    u16 i;
    u16 matrixIndex;
    RaceRankListPos position;
    s32 *matrix;
    s32 kartIndex;
    s32 itemDrawPosition[2];
    s32 kartDrawPosition[2];
    s32 secondKartDrawPosition[2];
    s32 balloonCellDrawPosition[2];
    s32 itemCellIndex;
    s32 balloonCountDrawPosition[2];
    s32 shineCellDrawPosition[2];
    s32 shineTensDrawPosition[2];
    s32 shineOnesDrawPosition[2];
    s32 markerDrawPosition[2];
    s32 markerIndex;
    Unk020224e0_c *cell;

    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        kartIndex = gRaceRankList->mKartsByRank[i];
        position = gRaceRankList->mRowPositions[kartIndex];
        itemCellIndex = GetRaceRankListSNcerIndex(kartIndex);
        position.mX -= gRaceRankList->mSlideX + 0x13;
        if (itemCellIndex != 0xc9) {
            cell = GetRaceSNcerEntry(itemCellIndex);
            itemDrawPosition[0] = (position.mX + 0x45) << 12;
            itemDrawPosition[1] = position.mY << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      itemDrawPosition, 0, 1);
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrixIndex = gRaceRankList->mOamMatrixIndex;
        } else {
            matrixIndex = 0;
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrix = gRaceRankList->mMatrix;
        } else {
            matrix = NULL;
        }
        cell = GetRaceSNcerEntry(kartIndex + 8);
        kartDrawPosition[0] = (position.mX + 1) << 12;
        kartDrawPosition[1] = position.mY << 12;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, matrix,
                                  kartDrawPosition, matrixIndex, 1);
        secondKartCellBase = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) kartIndex) != FALSE) {
            secondKartCellBase = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE &&
                   (GetRaceHudKartRemoved((u16) kartIndex) != 0 || func_0207a84c((u16) kartIndex) != 0)) {
            secondKartCellBase = 1;
        }
        secondKartCellBase = secondKartCellBase != 0 ? 0x6d : 0x65;
        cell = GetRaceSNcerEntry(secondKartCellBase + kartIndex);
        secondKartDrawPosition[0] = (position.mX + 0xb) << 12;
        secondKartDrawPosition[1] = position.mY << 12;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                  secondKartDrawPosition, 0, 1);
        if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
            s32 balloonCount = gRaceRankList->mBalloonOrShineCounts[kartIndex];

            cell = GetRaceSNcerEntry(0xc3);
            balloonCellDrawPosition[0] = (position.mX + 0x57) << 12;
            balloonCellDrawPosition[1] = (position.mY - 2) << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      balloonCellDrawPosition, 0, 1);
            cell = GetRaceSNcerEntry(balloonCount + 0xb9);
            balloonCountDrawPosition[0] = (position.mX + 0x5c) << 12;
            balloonCountDrawPosition[1] = position.mY << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      balloonCountDrawPosition, 0, 1);
        } else {
            s32 shineTens = gRaceRankList->mBalloonOrShineCounts[kartIndex] / 10;
            s32 shineOnes = gRaceRankList->mBalloonOrShineCounts[kartIndex] % 10;

            cell = GetRaceSNcerEntry(0xc4);
            shineCellDrawPosition[0] = (position.mX + 0x57) << 12;
            shineCellDrawPosition[1] = (position.mY - 2) << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      shineCellDrawPosition, 0, 1);
            cell = GetRaceSNcerEntry(shineTens + 0xb9);
            shineTensDrawPosition[0] = (position.mX + 0x54) << 12;
            shineTensDrawPosition[1] = position.mY << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      shineTensDrawPosition, 0, 1);
            cell = GetRaceSNcerEntry(shineOnes + 0xb9);
            shineOnesDrawPosition[0] = (position.mX + 0x5c) << 12;
            shineOnesDrawPosition[1] = position.mY << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      shineOnesDrawPosition, 0, 1);
        }
        markerIndex = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) kartIndex) != FALSE) {
            markerIndex = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE &&
                   (GetRaceHudKartRemoved((u16) kartIndex) != 0 || func_0207a84c((u16) kartIndex) != 0)) {
            markerIndex = 1;
        }
        if (markerIndex != 0) {
            markerIndex = 3;
        } else if ((u16) kartIndex == GetFollowedKartOrEntryIndex()) {
            markerIndex = 0;
        } else if (gRaceSetup->mUseTeams != 0 && gRaceSetup->mCurrentEntries[(u16) kartIndex].mPlayer.mTeamIndex == 1) {
            markerIndex = 2;
        } else {
            markerIndex = 1;
        }
        cell = GetRaceSNcerEntry(markerIndex + 0x81);
        markerDrawPosition[0] = (position.mX - 0xb) << 12;
        markerDrawPosition[1] = position.mY << 12;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, markerDrawPosition, 0, 1);
    }
}

void DrawRaceRankListBattleState1To3Rows(RaceHudOamBuffer *oamBuffer) {
    u16 i;
    u16 matrixIndex;
    RaceRankListPos position;
    s32 *matrix;
    s32 kartIndex;
    s32 itemDrawPosition[2];
    s32 kartDrawPosition[2];
    s32 balloonCellDrawPosition[2];
    s32 balloonCountDrawPosition[2];
    s32 itemCellIndex;
    s32 shineCellDrawPosition[2];
    s32 shineTensDrawPosition[2];
    s32 shineOnesDrawPosition[2];
    s32 markerDrawPosition[2];
    s32 markerIndex;
    Unk020224e0_c *cell;

    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        kartIndex = gRaceRankList->mKartsByRank[i];
        position = gRaceRankList->mRowPositions[kartIndex];
        itemCellIndex = GetRaceRankListSNcerIndex(kartIndex);
        position.mX -= gRaceRankList->mSlideX + 0x13;
        if (itemCellIndex != 0xc9) {
            cell = GetRaceSNcerEntry(itemCellIndex);
            itemDrawPosition[0] = (position.mX + 0x12) << 12;
            itemDrawPosition[1] = position.mY << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      itemDrawPosition, 0, 1);
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrixIndex = gRaceRankList->mOamMatrixIndex;
        } else {
            matrixIndex = 0;
        }
        if (gRaceRankList->mPrevRanks[kartIndex] > gRaceRankList->mRanks[kartIndex]) {
            matrix = gRaceRankList->mMatrix;
        } else {
            matrix = NULL;
        }
        cell = GetRaceSNcerEntry(kartIndex + 8);
        kartDrawPosition[0] = (position.mX + 1) << 12;
        kartDrawPosition[1] = position.mY << 12;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, matrix,
                                  kartDrawPosition, matrixIndex, 1);
        if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
            s32 balloonCount = gRaceRankList->mBalloonOrShineCounts[kartIndex];

            cell = GetRaceSNcerEntry(0xc3);
            balloonCellDrawPosition[0] = (position.mX + 0x25) << 12;
            balloonCellDrawPosition[1] = (position.mY - 2) << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      balloonCellDrawPosition, 0, 1);
            cell = GetRaceSNcerEntry(balloonCount + 0xb9);
            balloonCountDrawPosition[0] = (position.mX + 0x2a) << 12;
            balloonCountDrawPosition[1] = position.mY << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      balloonCountDrawPosition, 0, 1);
        } else {
            s32 shineTens = gRaceRankList->mBalloonOrShineCounts[kartIndex] / 10;
            s32 shineOnes = gRaceRankList->mBalloonOrShineCounts[kartIndex] % 10;

            cell = GetRaceSNcerEntry(0xc4);
            shineCellDrawPosition[0] = (position.mX + 0x25) << 12;
            shineCellDrawPosition[1] = (position.mY - 2) << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      shineCellDrawPosition, 0, 1);
            cell = GetRaceSNcerEntry(shineTens + 0xb9);
            shineTensDrawPosition[0] = (position.mX + 0x22) << 12;
            shineTensDrawPosition[1] = position.mY << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      shineTensDrawPosition, 0, 1);
            cell = GetRaceSNcerEntry(shineOnes + 0xb9);
            shineOnesDrawPosition[0] = (position.mX + 0x2a) << 12;
            shineOnesDrawPosition[1] = position.mY << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      shineOnesDrawPosition, 0, 1);
        }
        markerIndex = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) kartIndex) != FALSE) {
            markerIndex = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE &&
                   (GetRaceHudKartRemoved((u16) kartIndex) != 0 || func_0207a84c((u16) kartIndex) != 0)) {
            markerIndex = 1;
        }
        if (markerIndex != 0) {
            markerIndex = 3;
        } else if ((u16) kartIndex == GetFollowedKartOrEntryIndex()) {
            markerIndex = 0;
        } else if (gRaceSetup->mUseTeams != 0 && gRaceSetup->mCurrentEntries[(u16) kartIndex].mPlayer.mTeamIndex == 1) {
            markerIndex = 2;
        } else {
            markerIndex = 1;
        }
        cell = GetRaceSNcerEntry(markerIndex + 0x85);
        markerDrawPosition[0] = (position.mX - 0xb) << 12;
        markerDrawPosition[1] = position.mY << 12;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, markerDrawPosition, 0, 1);
    }
}

void InitRaceLapNumber(void) {
    gRaceLapNumber = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x14);
    gRaceLapNumber->mUnk_00 = 0;
    gRaceLapNumber->mUnk_04 = 0;
    gRaceLapNumber->mUnk_08 = (u16) (GetLapCount() - 1);
    gRaceLapNumber->mUnk_0c = 0;
    gRaceLapNumber->mUnk_10 = 1;
}

u32 ClearRaceLapNumberPointer(void) {
    u32 pointerAddress;
    u32 nullValue;
    pointerAddress = (u32) &gRaceLapNumber;
    nullValue = 0u;
    *(u32 *) ((pointerAddress) + (0)) = nullValue;
    return pointerAddress;
}

// Values of the first argument DrawRaceLapAndTimeDifference passes to GetRaceTaMNcerEntry.
typedef enum { UNK_020B843C_ARG_0, UNK_020B843C_ARG_1 } Unk020b843c_Arg;

// Plays a sound when the displayed kart starts a lap before the last, and counts 0x78 frames for the lap number blink.
void UpdateRaceLapNumber(void) {
    Unk0217b3ec *lapNumber;
    NNSSndSeqPlayer **seqPlayerHandle;
    u32 seqIndex;

    if (gRaceSetup->mMode == MODE_BATTLE) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        switch (gRaceSetup->mMissionKind) {
            case 2:
            case 4:
            case 6:
            case 10:
                break;
            default:
                return;
        }
    }
    gRaceLapNumber->mUnk_04 = gRaceLapNumber->mUnk_00;
    gRaceLapNumber->mUnk_00 = GetKartHighestLap(GetFollowedKartOrEntryIndex()) - 1;
    if (gRaceLapNumber->mUnk_00 != gRaceLapNumber->mUnk_04 && gRaceLapNumber->mUnk_08 > 0) {
        if (gRaceLapNumber->mUnk_00 < gRaceLapNumber->mUnk_08) {
            seqIndex = 0x41;
            if (gRaceSetup->mCourseId == COURSE_ID_PINBALL) {
                seqIndex = 0x1c7;
            }
            if (data_0217c780 & 1) {
                seqPlayerHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
                if (data_0217d084.mUnk_0c != 0) {
                    if (*seqPlayerHandle != NULL) {
                        NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
                    }
                    if (*seqPlayerHandle != NULL) {
                        NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
                    }
                    NNS_SndArcPlayerStartSeqArc(seqPlayerHandle, 0, seqIndex);
                }
            }
        }
        gRaceLapNumber->mUnk_0c = 1;
    }
    lapNumber = gRaceLapNumber;
    if (lapNumber->mUnk_0c != 0) {
        if ((lapNumber->mUnk_0c - 1) % 12 < 8) {
            lapNumber->mUnk_10 = 1;
        } else {
            lapNumber->mUnk_10 = 0;
        }
        gRaceLapNumber->mUnk_0c++;
        if (gRaceLapNumber->mUnk_0c > 0x78) {
            gRaceLapNumber->mUnk_0c = 0;
        }
    } else {
        lapNumber->mUnk_10 = 1;
    }
}

// Draws the lap label, the lap number while the blink shows it, a cell for last lap index 2 or 4, the time difference.
void DrawRaceLapAndTimeDifference(RaceHudOamBuffer *oamBuffer) {
    s32 lapPosition[2] = {0xf8, 0x10};
    s32 *timeDifferenceSign;
    TimeDigits *timeDifferenceDigits;
    s32 lapLabelDrawPosition[2];
    s32 lapNumberDrawPosition[2];
    s32 lastLapIndexTwoDrawPosition[2];
    s32 lastLapIndexFourDrawPosition[2];
    s32 showLapTimeFrames;
    Unk020224e0_c *cell;

    if (gRaceSetup->mRaceKind == 4) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        switch (gRaceSetup->mMissionKind) {
            case 2:
            case 4:
            case 6:
            case 10:
                if (gRaceLapNumber->mUnk_08 < 2) {
                    return;
                }
                break;
            default:
                return;
        }
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        return;
    }
    cell = GetRaceMNcerEntry(0x20);
    lapLabelDrawPosition[0] = lapPosition[0] << 12;
    lapLabelDrawPosition[1] = lapPosition[1] << 12;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, lapLabelDrawPosition, 0, 1);
    if (gRaceLapNumber->mUnk_10 != 0) {
        cell = GetRaceMNcerEntry(gRaceLapNumber->mUnk_00 + 0x21);
        lapNumberDrawPosition[0] = lapPosition[0] << 12;
        lapNumberDrawPosition[1] = lapPosition[1] << 12;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                  lapNumberDrawPosition, 0, 1);
    }
    switch (gRaceLapNumber->mUnk_08) {
        case 2:
            cell = GetRaceMNcerEntry(0x26);
            lastLapIndexTwoDrawPosition[0] = lapPosition[0] << 12;
            lastLapIndexTwoDrawPosition[1] = lapPosition[1] << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      lastLapIndexTwoDrawPosition, 0, 1);
            break;
        case 4:
            cell = GetRaceMNcerEntry(0x27);
            lastLapIndexFourDrawPosition[0] = lapPosition[0] << 12;
            lastLapIndexFourDrawPosition[1] = lapPosition[1] << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      lastLapIndexFourDrawPosition, 0, 1);
            break;
    }
    if (GetUseTimeDifference() == 0) {
        return;
    }
    if (GetShowLapTime() == 0) {
        return;
    }
    showLapTimeFrames = GetShowLapTimeFrames();
    if (showLapTimeFrames % 0x24 >= 0x18) {
        return;
    }
    {
        s32 signDrawPosition[2];
        s32 digit0DrawPosition[2];
        s32 digit1DrawPosition[2];
        s32 firstSeparatorDrawPosition[2];
        s32 digit2DrawPosition[2];
        s32 digit3DrawPosition[2];
        s32 secondSeparatorDrawPosition[2];
        s32 digit4DrawPosition[2];
        s32 digit5DrawPosition[2];
        s32 digit6DrawPosition[2];
        s32 cellXs[10] = {0x57, 0x61, 0x6a, 0x72, 0x7c, 0x85, 0x8e, 0x98, 0xa1, 0xaa};

        GetRaceHudTimeDifference(&timeDifferenceSign, &timeDifferenceDigits);
        cell = GetRaceTaMNcerEntry(*timeDifferenceSign != 0 ? UNK_020B843C_ARG_0 : UNK_020B843C_ARG_1);
        signDrawPosition[0] = cellXs[0] << 12;
        signDrawPosition[1] = 0x58000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, signDrawPosition, 0, 1);
        if (timeDifferenceDigits->mDigits[0] != 0) {
            cell = GetRaceTaMNcerEntry(timeDifferenceDigits->mDigits[0] + 2);
            digit0DrawPosition[0] = cellXs[1] << 12;
            digit0DrawPosition[1] = 0x58000;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      digit0DrawPosition, 0, 1);
        }
        cell = GetRaceTaMNcerEntry(timeDifferenceDigits->mDigits[1] + 2);
        digit1DrawPosition[0] = cellXs[2] << 12;
        digit1DrawPosition[1] = 0x58000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, digit1DrawPosition, 0, 1);
        cell = GetRaceTaMNcerEntry(0xc);
        firstSeparatorDrawPosition[0] = cellXs[3] << 12;
        firstSeparatorDrawPosition[1] = 0x58000;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                  firstSeparatorDrawPosition, 0, 1);
        cell = GetRaceTaMNcerEntry(timeDifferenceDigits->mDigits[2] + 2);
        digit2DrawPosition[0] = cellXs[4] << 12;
        digit2DrawPosition[1] = 0x58000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, digit2DrawPosition, 0, 1);
        cell = GetRaceTaMNcerEntry(timeDifferenceDigits->mDigits[3] + 2);
        digit3DrawPosition[0] = cellXs[5] << 12;
        digit3DrawPosition[1] = 0x58000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, digit3DrawPosition, 0, 1);
        cell = GetRaceTaMNcerEntry(0xc);
        secondSeparatorDrawPosition[0] = cellXs[6] << 12;
        secondSeparatorDrawPosition[1] = 0x58000;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                  secondSeparatorDrawPosition, 0, 1);
        cell = GetRaceTaMNcerEntry(timeDifferenceDigits->mDigits[4] + 2);
        digit4DrawPosition[0] = cellXs[7] << 12;
        digit4DrawPosition[1] = 0x58000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, digit4DrawPosition, 0, 1);
        cell = GetRaceTaMNcerEntry(timeDifferenceDigits->mDigits[5] + 2);
        digit5DrawPosition[0] = cellXs[8] << 12;
        digit5DrawPosition[1] = 0x58000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, digit5DrawPosition, 0, 1);
        cell = GetRaceTaMNcerEntry(timeDifferenceDigits->mDigits[6] + 2);
        digit6DrawPosition[0] = cellXs[9] << 12;
        digit6DrawPosition[1] = 0x58000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, digit6DrawPosition, 0, 1);
    }
}

void InitRaceTimeDigits(void) {
    s32 i;

    gRaceTimeDigits = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x38);
    gRaceTimeDigits->mTime.mDigits[0] = 0;
    gRaceTimeDigits->mTime.mDigits[1] = 0;
    gRaceTimeDigits->mTime.mDigits[2] = 0;
    gRaceTimeDigits->mTime.mDigits[3] = 0;
    gRaceTimeDigits->mTime.mDigits[4] = 0;
    gRaceTimeDigits->mTime.mDigits[5] = 0;
    gRaceTimeDigits->mTime.mDigits[6] = 0;
    gRaceTimeDigits->mUseLastSecondsSound = FALSE;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            gRaceTimeDigits->mUseLastSecondsSound = TRUE;
        }
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        if (gRaceSetup->mMissionKind != 6) {
            gRaceTimeDigits->mUseLastSecondsSound = TRUE;
        }
    }
    for (i = 0; i < 6; i++) {
        gRaceTimeDigits->mLastSecondsReached[i] = 0;
    }
}

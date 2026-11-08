#include "Main/Unknown/code_020c214c.h"

#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020c13d0.h"
#include "Main/Unknown/code_020c13e8.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_020c3000.h"
#include "Main/Unknown/code_020c31ec.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020c0dd8.h"

// placeholder: an object of the original file that is not known yet; it only sets the order of the tables below
u8 data_020c214c_pad[12];

void func_020c3b6c(s32 row, s32 style) {
    UnkPair020b502c spans[8] = {{2, 5}, {5, 8}, {8, 10}, {10, 13}, {13, 16}, {15, 18}, {18, 21}, {21, 23}};
    UnkPair020b502c fullSpan = {0, 0x1f};
    s32 m;
    s32 copyIndex;
    u32 spanStart;
    u32 spanLength;
    u32 fullStart;
    u32 fullLength;

    m = row % 2;
    copyIndex = m != 0 ? 1 : 0;
    m = m != 0 ? 2 : 1;
    switch (style) {
        case 0:
            spanStart = spans[row].mUnk_00;
            spanLength = spans[row].mUnk_04 - spanStart + 1;
            fullStart = fullSpan.mUnk_00;
            fullLength = fullSpan.mUnk_04 - fullStart + 1;
            func_020b4520(gRaceGoalS->mRaceGoalSSpaceNscrCopies[copyIndex], fullStart, spanStart, fullLength,
                          spanLength, gRaceGoalS->mRaceGoalSNscrs[m]->mData, fullStart, spanStart);
            func_020b44a4(gRaceGoalS->mRaceGoalSNscrs[m]->mData, fullStart, spanStart, fullLength, spanLength, 9);
            break;
        case 1:
            spanStart = spans[row].mUnk_00;
            spanLength = spans[row].mUnk_04 - spanStart + 1;
            fullStart = fullSpan.mUnk_00;
            fullLength = fullSpan.mUnk_04 - fullStart + 1;
            func_020b4520(gRaceGoalS->mRaceGoalSSpaceNscrCopies[copyIndex], fullStart, spanStart, fullLength,
                          spanLength, gRaceGoalS->mRaceGoalSNscrs[m]->mData, fullStart, spanStart);
            func_020b44a4(gRaceGoalS->mRaceGoalSNscrs[m]->mData, fullStart, spanStart, fullLength, spanLength, 8);
            break;
        case 2:
            spanStart = spans[row].mUnk_00;
            spanLength = spans[row].mUnk_04 - spanStart + 1;
            fullLength = fullSpan.mUnk_04 - fullSpan.mUnk_00 + 1;
            func_020b4428(gRaceGoalS->mRaceGoalSNscrs[m]->mData, fullSpan.mUnk_00, spanStart, fullLength, spanLength,
                          0);
            break;
    }
}

void UpdateRaceGoalSOffset(void) {
    s32 frame;

    frame = gRaceGoalS->mOffsetStateFrames;
    gRaceGoalS->mOffsetStateFrames = frame + 1;
    switch (gRaceGoalS->mOffsetState) {
        case 0:
            gRaceGoalS->mOffset = -0x20;
            if (gRaceGoalS->mUpdate == SlideInRaceGoalS) {
                gRaceGoalS->mOffsetState = 1;
                gRaceGoalS->mOffsetStateFrames = 0;
            } else {
                gRaceGoalS->mOffsetState = 10;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 1:
            if (frame < 0x14) {
                gRaceGoalS->mOffset = InterpolateS16(1, -0x20, 0, frame, 0x14);
            } else {
                gRaceGoalS->mOffset = 0;
                gRaceGoalS->mOffsetState = 2;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 2:
            gRaceGoalS->mOffset = 0;
            if (gRaceSetup->mMode == 5 && func_020b32ec() != 0) {
                gRaceGoalS->mOffsetState = 3;
                gRaceGoalS->mOffsetStateFrames = 0;
                return;
            }
            if (func_020c1728 == gRaceGoalS->mUpdate) {
                gRaceGoalS->mOffsetState = 3;
                gRaceGoalS->mOffsetStateFrames = 0;
            } else if (func_020c0fd0 == gRaceGoalS->mUpdate) {
                gRaceGoalS->mOffsetState = 9;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 3:
            if (frame < 0x14) {
                gRaceGoalS->mOffset = InterpolateS16(1, 0, -0x20, frame, 0x14);
            } else {
                gRaceGoalS->mOffset = -0x20;
                if (gRaceSetup->mMode == 5 && func_020b32ec() != 0) {
                    gRaceGoalS->mOffsetState = 7;
                    gRaceGoalS->mOffsetStateFrames = 0;
                } else {
                    gRaceGoalS->mOffsetState = 4;
                    gRaceGoalS->mOffsetStateFrames = 0;
                }
            }
            break;
        case 4:
            if (frame < 0x14) {
                gRaceGoalS->mOffset = InterpolateS16(1, -0x20, 0, frame, 0x14);
            } else {
                gRaceGoalS->mOffset = 0;
                gRaceGoalS->mOffsetState = 5;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 5:
            gRaceGoalS->mOffset = 0;
            if (gRaceSetup->mMode != 5) {
                return;
            }
            if (func_020b32ec() == 0) {
                return;
            }
            gRaceGoalS->mOffsetState = 6;
            gRaceGoalS->mOffsetStateFrames = 0;
            break;
        case 6:
            if (frame < 0x14) {
                gRaceGoalS->mOffset = InterpolateS16(1, 0, -0x20, frame, 0x14);
            } else {
                gRaceGoalS->mOffset = -0x20;
                gRaceGoalS->mOffsetState = 7;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 7:
            if (frame < 0x14) {
                gRaceGoalS->mOffset = InterpolateS16(1, -0x20, 0, frame, 0x14);
            } else {
                gRaceGoalS->mOffset = 0;
                gRaceGoalS->mOffsetState = 8;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 8:
        case 10:
            gRaceGoalS->mOffset = 0;
            break;
        case 9:
            if (frame < 0x14) {
                gRaceGoalS->mOffset = InterpolateS16(1, 0, -0x20, frame, 0x14);
            } else {
                gRaceGoalS->mOffset = 0;
                gRaceGoalS->mOffsetState = 10;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
    }
}

void InitRaceGoalS(void) {
    s32 sortKeys[8];
    u16 i;
    u32 j;
    u32 g;
    s32 k;
    s32 l;
    s32 playerKind;

    gRaceGoalS = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x20e4);
    for (i = 0; i < 8; i++) {
        gRaceGoalS->mRowVisible[i] = 1;
        gRaceGoalS->mShownNumbers[i] = 0;
        gRaceGoalS->mRowKartIndex[i] = 0;
        gRaceGoalS->mRankComparison[i] = 1;
    }
    gRaceGoalS->mUnk_00a4 = 0;
    gRaceGoalS->mHiddenRowCount = 0;
    gRaceGoalS->mUpdate = func_020c1ef8;
    gRaceGoalS->mUpdateFrames = 0;
    gRaceGoalS->mUnk_00b4 = 0;
    gRaceGoalS->mOffsetX = -0x100;
    for (j = 0; j < gRaceSetup->mKartCount; j = (u16) (j + 1)) {
        if (gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE) {
            playerKind = gRaceSetup->mCurrentEntries[j].mPlayer.mKind;
            k = playerKind == PLAYER_KIND_HUMAN || playerKind == PLAYER_KIND_GHOST || playerKind == PLAYER_KIND_PEER
                    ? 1
                    : 0;
            l = GetKartPreviousWinCount(j);
            sortKeys[j] = l * 16 + k * 8;
            if (gRaceSetup->mMode == MODE_VS || gRaceSetup->mMode == 5) {
                sortKeys[j] = sortKeys[j] + (8 - GetKartStartRank(j));
            } else {
                sortKeys[j] += 8 - j;
            }
            gRaceGoalS->mShownNumbers[j] = GetKartPreviousWinCount(j);
        } else {
            playerKind = gRaceSetup->mCurrentEntries[j].mPlayer.mKind;
            l = playerKind == PLAYER_KIND_HUMAN || playerKind == PLAYER_KIND_GHOST || playerKind == PLAYER_KIND_PEER
                    ? 1
                    : 0;
            k = GetKartPreviousTotalPoints(j);
            sortKeys[j] = k * 16 + l * 8 + 8 - GetKartStartRank(j);
            gRaceGoalS->mShownNumbers[j] = GetKartPreviousTotalPoints(j);
        }
    }
    for (g = 0; g < gRaceSetup->mKartCount; g = (u16) (g + 1)) {
        gRaceGoalS->mRowKartIndex[g] = g;
        sortKeys[g] *= -1;
    }
    SortIndicesByKey(gRaceGoalS->mRowKartIndex, sortKeys, gRaceSetup->mKartCount);
    for (j = 0; j < gRaceSetup->mKartCount; j = (u16) (j + 1)) {
        gRaceGoalS->mPreviousRowKartIndex[j] = gRaceGoalS->mRowKartIndex[j];
    }
    gRaceGoalS->mOffsetState = 0;
    gRaceGoalS->mOffsetStateFrames = 0;
    gRaceGoalS->mOffset = -0x20;
    LoadNclrData(&gRaceGoalS->mRaceGoalSBNclr, FindSceneFileWrapper("race_goal_s_b.NCLR"));
    LoadNcgrData(&gRaceGoalS->mRaceGoalSBNcgr, FindSceneFileWrapper("race_goal_s_b.NCGR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[0], FindSceneFileWrapper("race_goal_s_bg.NSCR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[1], FindSceneFileWrapper("race_goal_s_space1.NSCR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[2], FindSceneFileWrapper("race_goal_s_space2.NSCR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[3], FindSceneFileWrapper("race_goal_s_team_bg.NSCR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[4], FindSceneFileWrapper("race_goal_s_teamB.NSCR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[5], FindSceneFileWrapper("race_goal_s_teamR.NSCR"));
    for (i = 0; i < 0x800; i++) {
        gRaceGoalS->mRaceGoalSSpaceNscrCopies[0][i] = gRaceGoalS->mRaceGoalSNscrs[1]->mData[i];
        gRaceGoalS->mRaceGoalSSpaceNscrCopies[1][i] = gRaceGoalS->mRaceGoalSNscrs[2]->mData[i];
    }
}

u32 ClearRaceGoalSPointer(void) {
    u32 address;
    u32 zero;
    address = (u32) &gRaceGoalS;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

void UpdateRaceGoalS(void) {
    u32 address = ((u32) (&gRaceGoalS));
    u32 goal = (*(u32 *) ((address) + (0)));
    u32 step = (*(u32 *) ((goal) + (172)));
    u32 v5 = ((u32(*)(void))(step))();
    UpdateRaceGoalSOffset();
}

void DrawRaceGoalSKarts(Unk020c06c4 *oamBuffer) {
    s32 ones;
    u16 i;
    s32 kartIndex;
    s32 number;
    s32 hundreds;
    s32 tens;
    RaceGoalS *goal = gRaceGoalS;
    s32 offsetX = goal->mOffsetX;
    s32 cycleFrame;
    s32 cellIndex;
    s32 oamIndex;
    s32 offset;
    Unk020c06c4_08 *oam;
    void *cell;
    s32 cell21Position[2];
    s32 cell22Position[2];
    s32 cell2bPosition[2];
    s32 hundredsPosition[2];
    s32 tensPosition[2];
    s32 onesPosition[2];
    s32 cell1aOr1bPosition[2];
    s32 teamPosition[2];
    s32 rankChangePosition[2];
    s32 placePosition[2];
    s32 kartPosition[2];
    s32 kartExtraPosition[2];
    s32 rowYs[8] = {0x22, 0x37, 0x4c, 0x61, 0x76, 0x8b, 0xa0, 0xb5};

    switch (goal->mOffsetState) {
        case 1:
        case 2:
        case 3:
        case 9:
            cell = GetRaceGoalSNcerEntry(0x21);
            oamIndex = oamBuffer->mUnk_400;
            cell21Position[1] = (gRaceGoalS->mOffset + 0xb) << 12;
            cell21Position[0] = 0;
            oam = &oamBuffer->mUnk_000.mUnk_00[oamIndex];
            oamBuffer->mUnk_400 +=
                NNS_G2dMakeCellToOams((GXOamAttr *) oam, 0x80 - oamIndex, cell, NULL, cell21Position, 0, 1);
            for (; oamIndex < oamBuffer->mUnk_400; oamIndex++, oam++) {
                oam->mUnk_0e = 1;
            }
            break;
        case 4:
        case 5:
        case 6:
            cell = GetRaceGoalSNcerEntry(0x22);
            oamIndex = oamBuffer->mUnk_400;
            cell22Position[1] = (gRaceGoalS->mOffset + 0xb) << 12;
            cell22Position[0] = 0;
            oam = &oamBuffer->mUnk_000.mUnk_00[oamIndex];
            oamBuffer->mUnk_400 +=
                NNS_G2dMakeCellToOams((GXOamAttr *) oam, 0x80 - oamIndex, cell, NULL, cell22Position, 0, 1);
            for (; oamIndex < oamBuffer->mUnk_400; oamIndex++, oam++) {
                oam->mUnk_0e = 1;
            }
            break;
        case 7:
        case 8:
            cycleFrame = gRaceGoalS->mOffsetStateFrames % 40;
            if (cycleFrame < 0x20) {
                cell = GetRaceGoalSNcerEntry(0x2b);
                oamIndex = oamBuffer->mUnk_400;
                offset = gRaceGoalS->mOffset;
                cell2bPosition[0] = 0x80000;
                cell2bPosition[1] = (offset + 0x60) << 12;
                oam = &oamBuffer->mUnk_000.mUnk_00[oamIndex];
                oamBuffer->mUnk_400 +=
                    NNS_G2dMakeCellToOams((GXOamAttr *) oam, 0x80 - oamIndex, cell, NULL, cell2bPosition, 0, 1);
                for (; oamIndex < oamBuffer->mUnk_400; oamIndex++, oam++) {
                    oam->mUnk_0e = 1;
                }
            }
            break;
    }
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        kartIndex = gRaceGoalS->mRowKartIndex[i];
        number = gRaceGoalS->mShownNumbers[kartIndex];
        hundreds = number / 100;
        tens = (number - hundreds * 100) / 10;
        ones = number % 10;
        if (hundreds >= 10) {
            ones = 9;
            tens = ones;
            hundreds = ones;
        }
        if (gRaceGoalS->mRowVisible[i] == 0) {
            func_020c3b6c(i, 2);
        } else if (kartIndex == GetFollowedKartOrEntryIndex()) {
            func_020c3b6c(i, 0);
        } else {
            func_020c3b6c(i, 1);
        }
        if (gRaceGoalS->mRowVisible[i] != 0) {
            if (hundreds != 0) {
                cell = GetRaceGoalSNcerEntry(hundreds + 0x10);
                hundredsPosition[0] = (offsetX + 0xba) << 12;
                hundredsPosition[1] = rowYs[i] << 12;
                oamBuffer->mUnk_400 +=
                    NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                          0x80 - oamBuffer->mUnk_400, cell, NULL, hundredsPosition, 0, 1);
            }
            if (hundreds != 0 || tens != 0) {
                cell = GetRaceGoalSNcerEntry(tens + 0x10);
                tensPosition[0] = (offsetX + 0xc3) << 12;
                tensPosition[1] = rowYs[i] << 12;
                oamBuffer->mUnk_400 +=
                    NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                          0x80 - oamBuffer->mUnk_400, cell, NULL, tensPosition, 0, 1);
            }
            cell = GetRaceGoalSNcerEntry(ones + 0x10);
            onesPosition[0] = (offsetX + 0xcc) << 12;
            onesPosition[1] = rowYs[i] << 12;
            oamBuffer->mUnk_400 +=
                NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                      0x80 - oamBuffer->mUnk_400, cell, NULL, onesPosition, 0, 1);
            if (!(gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE)) {
                cellIndex = func_020b4b98(number) != FALSE ? 0x1a : 0x1b;
                cell = GetRaceGoalSNcerEntry(cellIndex);
                cell1aOr1bPosition[0] = (offsetX + 0xd1) << 12;
                cell1aOr1bPosition[1] = rowYs[i] << 12;
                oamBuffer->mUnk_400 +=
                    NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                          0x80 - oamBuffer->mUnk_400, cell, NULL, cell1aOr1bPosition, 0, 1);
            }
            if (gRaceSetup->mUseTeams != 0) {
                cellIndex = gRaceSetup->mCurrentEntries[(u16) kartIndex].mPlayer.mTeamIndex == 0 ? 0x1f : 0x20;
                cell = GetRaceGoalSNcerEntry(cellIndex);
                teamPosition[0] = (offsetX + 0xec) << 12;
                teamPosition[1] = rowYs[i] << 12;
                oamBuffer->mUnk_400 +=
                    NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                          0x80 - oamBuffer->mUnk_400, cell, NULL, teamPosition, 0, 1);
            }
            if (!(gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE || gRaceSetup->mCourseNumber == 1)) {
                if (gRaceGoalS->mUpdate == func_020c155c || gRaceGoalS->mUpdate == func_020c13e8 ||
                    gRaceGoalS->mUpdate == func_020c13d0) {
                    cell = GetRaceGoalSNcerEntry(gRaceGoalS->mRankComparison[kartIndex] + 0x1c);
                    rankChangePosition[0] = (offsetX + 0xc) << 12;
                    rankChangePosition[1] = rowYs[i] << 12;
                    oamBuffer->mUnk_400 +=
                        NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                              0x80 - oamBuffer->mUnk_400, cell, NULL, rankChangePosition, 0, 1);
                }
            }
            cell = GetRaceGoalSNcerEntry(i + 8);
            placePosition[0] = (offsetX + 0x1d) << 12;
            placePosition[1] = rowYs[i] << 12;
            oamBuffer->mUnk_400 +=
                NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                      0x80 - oamBuffer->mUnk_400, cell, NULL, placePosition, 0, 1);
            cell = GetRaceGoalSNcerEntry(kartIndex);
            kartPosition[0] = (offsetX + 0x2e) << 12;
            kartPosition[1] = rowYs[i] << 12;
            oamBuffer->mUnk_400 +=
                NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                      0x80 - oamBuffer->mUnk_400, cell, NULL, kartPosition, 0, 1);
            cell = GetRaceGoalSNcerEntry(kartIndex + 0x23);
            kartExtraPosition[0] = (offsetX + 0x3b) << 12;
            kartExtraPosition[1] = rowYs[i] << 12;
            oamBuffer->mUnk_400 +=
                NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                      0x80 - oamBuffer->mUnk_400, cell, NULL, kartExtraPosition, 0, 1);
        }
    }
}

void DrawRaceGoalSTeamKart(Unk020c06c4 *oamBuffer, u32 kartIndex, s32 x, s32 y) {
    s32 kartPosition[2];
    s32 kartExtraPosition[2];
    s32 teamPosition[2];
    s32 hundredsPosition[2];
    s32 tensPosition[2];
    s32 onesPosition[2];
    s32 number;
    s32 hundreds;
    s32 tens;
    s32 ones;
    s32 cellIndex;
    void *cell;

    number = gRaceGoalS->mShownNumbers[kartIndex];
    hundreds = number / 100;
    tens = number / 10 % 10;
    ones = number % 10;
    cell = GetRaceGoalTeamSNcerEntry(kartIndex);
    kartPosition[0] = (x + 0xc) << 12;
    kartPosition[1] = y << 12;
    oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                                 0x80 - oamBuffer->mUnk_400, cell, NULL, kartPosition, 0, 1);
    cell = GetRaceGoalTeamSNcerEntry(kartIndex + 0x20);
    kartExtraPosition[0] = (x + 0x16) << 12;
    kartExtraPosition[1] = y << 12;
    oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                                 0x80 - oamBuffer->mUnk_400, cell, NULL, kartExtraPosition, 0, 1);
    if (kartIndex == GetFollowedKartOrEntryIndex()) {
        cellIndex = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex == 0 ? 0x1e : 0x1f;
    } else {
        cellIndex = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mTeamIndex == 0 ? 0x1c : 0x1d;
    }
    cell = GetRaceGoalTeamSNcerEntry(cellIndex);
    teamPosition[0] = x << 12;
    teamPosition[1] = y << 12;
    oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                                 0x80 - oamBuffer->mUnk_400, cell, NULL, teamPosition, 0, 1);
    if (gRaceSetup->mMode == MODE_BATTLE) {
        return;
    }
    if (hundreds >= 10) {
        ones = 9;
        hundreds = ones;
        tens = ones;
    }
    if (hundreds != 0) {
        cell = GetRaceGoalTeamSNcerEntry(hundreds + 8);
        hundredsPosition[0] = (x + 0x57) << 12;
        hundredsPosition[1] = y << 12;
        oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                                     0x80 - oamBuffer->mUnk_400, cell, NULL, hundredsPosition, 0, 1);
    }
    if (hundreds != 0 || tens != 0) {
        cell = GetRaceGoalTeamSNcerEntry(tens + 8);
        tensPosition[0] = (x + 0x60) << 12;
        tensPosition[1] = y << 12;
        oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                                     0x80 - oamBuffer->mUnk_400, cell, NULL, tensPosition, 0, 1);
    }
    cell = GetRaceGoalTeamSNcerEntry(ones + 8);
    onesPosition[0] = (x + 0x69) << 12;
    onesPosition[1] = y << 12;
    oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                                 0x80 - oamBuffer->mUnk_400, cell, NULL, onesPosition, 0, 1);
}

void DrawRaceGoalSTeamNumber(Unk020c06c4 *oamBuffer, s32 number, s32 x, s32 y) {
    s32 thousandsPosition[2];
    s32 hundredsPosition[2];
    s32 tensPosition[2];
    s32 onesPosition[2];
    s32 thousands;
    s32 hundreds;
    s32 tens;
    s32 ones;
    void *cell;

    thousands = number / 1000;
    hundreds = number / 100 % 10;
    tens = number / 10 % 10;
    ones = number % 10;
    if (thousands != 0) {
        cell = GetRaceGoalTeamSNcerEntry(thousands + 0x12);
        thousandsPosition[0] = x << 12;
        thousandsPosition[1] = y << 12;
        oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                                     0x80 - oamBuffer->mUnk_400, cell, NULL, thousandsPosition, 0, 1);
    }
    if (thousands != 0 || hundreds != 0) {
        cell = GetRaceGoalTeamSNcerEntry(hundreds + 0x12);
        hundredsPosition[0] = (x + 0xf) << 12;
        hundredsPosition[1] = y << 12;
        oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                                     0x80 - oamBuffer->mUnk_400, cell, NULL, hundredsPosition, 0, 1);
    }
    if (thousands != 0 || hundreds != 0 || tens != 0) {
        cell = GetRaceGoalTeamSNcerEntry(tens + 0x12);
        tensPosition[0] = (x + 0x1e) << 12;
        tensPosition[1] = y << 12;
        oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                                     0x80 - oamBuffer->mUnk_400, cell, NULL, tensPosition, 0, 1);
    }
    cell = GetRaceGoalTeamSNcerEntry(ones + 0x12);
    onesPosition[0] = (x + 0x2d) << 12;
    onesPosition[1] = y << 12;
    oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                                 0x80 - oamBuffer->mUnk_400, cell, NULL, onesPosition, 0, 1);
}

void DrawRaceGoalSTeams(Unk020c06c4 *oamBuffer) {
    s32 rowCounts[2];
    s32 teamX[2] = {0xa, 0x89};
    s32 numberX[2] = {0x43, 0xc2};
    s32 offsetX;
    s32 teamIndex;
    u16 i;
    BOOL f;
    s32 number;
    Unk0217aa1c_144 *courseRecords;

    offsetX = gRaceGoalS->mOffsetX;
    for (i = 0; i < 2; i++) {
        rowCounts[i] = 0;
    }
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        teamIndex = gRaceSetup->mCurrentEntries[i].mPlayer.mTeamIndex;
        DrawRaceGoalSTeamKart(oamBuffer, i, teamX[teamIndex] + (teamIndex == 0 ? -offsetX : offsetX),
                              rowCounts[teamIndex] * 0x17 + 0x11);
        rowCounts[teamIndex]++;
    }
    for (i = 0; i < 2; i++) {
        f = TRUE;
        if (!(gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE)) {
            f = FALSE;
        }
        if (f != FALSE) {
            courseRecords = &gCupRecords->mUnk_144[GetCourseIndexInCup()];
            number = courseRecords->mUnk_00[i].mUnk_02;
        } else {
            courseRecords = &gCupRecords->mUnk_144[GetCourseIndexInCup()];
            number = courseRecords->mUnk_00[i].mUnk_00;
        }
        DrawRaceGoalSTeamNumber(oamBuffer, number, numberX[i] + (i == 0 ? -offsetX : offsetX), 0xb6);
    }
}

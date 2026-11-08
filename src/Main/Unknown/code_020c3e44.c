#include "Main/Unknown/code_020c3e44.h"

#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/unk_021759c0.h"
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
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b837c.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02022030.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_02036820.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_020c4bd8.h"
#include "Main/Unknown/code_0212a724.h"
#include "g2d_CharCanvas.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020b47b4.h"
#include "g2d_NOB_load.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_0212030c.h"
#include "code_02142eac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020b85dc.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c53c4.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020c5ccc.h"
#include "Main/Unknown/code_020c5ce0.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_020c5db0.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"
#include "registers.h"

u32 func_020c5dc4(void) {
    return (gRaceGoalM->mUnk_00);
}

u32 GetRaceGoalMUpdateFrames(void) {
    return (gRaceGoalM->mUpdateFrames);
}

void InitRaceGoalM(void) {
    gRaceGoalM = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x1c);
    gRaceGoalM->mUnk_00 = 1;
    gRaceGoalM->mUpdateFrames = 0;
    gRaceGoalM->mRankIndex = 0;
    gRaceGoalM->mPointsGained = 0;
    gRaceGoalM->mFirstPlaceKartIndex = 0;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        if (GetMissionRecordValue(gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableRow : -1,
                                  gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableColumn : -1,
                                  &gRaceGoalM->mUnk_14) == 0) {
            gRaceGoalM->mUnk_14 = 9;
        }
    } else {
        gRaceGoalM->mUnk_14 = 9;
    }
    gRaceGoalM->mUnk_18 = 9;
}

u32 ClearRaceGoalMPointer(void) {
    u32 address;
    u32 zero;
    address = (u32) &gRaceGoalM;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

void UpdateRaceGoalM(void) {
    u32 kartIndex;
    s32 a;
    u16 i;
    s32 frame;
    u16 followedKartIndex;
    s32 *updateFramesPointer;
    KartCourseResult *record;

    frame = gRaceGoalM->mUpdateFrames;
    followedKartIndex = GetFollowedKartOrEntryIndex();
    if (gRaceProgress->mUnk_000[followedKartIndex].mStatus == 1 || gRaceProgress->mRaceDone != 0) {
        gRaceGoalM->mUnk_00 = 0;
    }
    if (func_020b1d0c() == 0) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        if ((IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0 ? gRaceProgress->mEntryEndKind : 6) != 0 &&
            func_0207a218() == 0 && frame == 0) {
            return;
        }
    }
    updateFramesPointer = &gRaceGoalM->mUpdateFrames;
    if (*updateFramesPointer < 0x7fffffff) {
        *updateFramesPointer = *updateFramesPointer + 1;
    }
    switch (gRaceSetup->mMode) {
        case MODE_GRAND_PRIX:
            gRaceGoalM->mRankIndex = GetKartRank(GetFollowedKartOrEntryIndex()) - 1;
            kartIndex = GetLowByte(GetFollowedKartOrEntryIndex());
            a = GetCourseIndexInCup();
            record = &gCupRecords->mUnk_000[a][GetLowByte(kartIndex)];
            a = record->mTotalPoints;
            gRaceGoalM->mPointsGained = a - GetKartPreviousTotalPoints(GetFollowedKartOrEntryIndex());
            if (frame > 0x14) {
                gRaceGoalM->mUnk_00 = 1;
            }
            break;
        case MODE_TIME_ATTACK:
            if (frame > 0x14) {
                gRaceGoalM->mUnk_00 = 1;
            }
            break;
        case MODE_VS:
        case 5:
            gRaceGoalM->mRankIndex = GetKartRank(GetFollowedKartOrEntryIndex()) - 1;
            for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
                if (GetKartRank(i) == 1) {
                    break;
                }
            }
            gRaceGoalM->mFirstPlaceKartIndex = i;
            if (frame > 0x14) {
                gRaceGoalM->mUnk_00 = 1;
            }
            break;
        case MODE_MISSION_RUN:
            if (IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0 ? gRaceProgress->mEntryEndKind : 6) {
                gRaceGoalM->mUnk_18 = 9;
            } else {
                gRaceGoalM->mUnk_18 = func_0205d140();
            }
            if ((IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0 ? gRaceProgress->mEntryEndKind : 6) == 0) {
                if (frame == 1) {
                    switch (gRaceGoalM->mUnk_18) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            break;
                        case 5:
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1b);
                            break;
                        case 6:
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1c);
                            break;
                        case 7:
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1d);
                            break;
                    }
                } else if (frame > 0x1e) {
                    gRaceGoalM->mUnk_00 = 1;
                }
            } else if (frame > 0x4b) {
                gRaceGoalM->mUnk_00 = 1;
            }
            break;
        default:
            gRaceGoalM->mUnk_00 = 1;
            break;
    }
}

void DrawRaceGoalM(Unk020c06c4 *oamBuffer) {
    s32 offsetY;
    s32 oamIndex;
    s32 position[2];
    void *cell;

    if (gRaceSetup->mRaceKind != RACE_KIND_NORMAL) {
        return;
    }
    if (func_020b1d0c() == 0) {
        return;
    }
    switch (gRaceSetup->mMode) {
        case MODE_GRAND_PRIX:
            DrawRaceGoalMGrandPrix(oamBuffer);
            break;
        case MODE_VS:
        case 5:
            offsetY = InterpolateS16(1, 0x40, 0, gRaceGoalM->mUpdateFrames, 0x14);
            cell = GetRaceGoalMNcerEntry(gRaceGoalM->mRankIndex);
            position[0] = 0x18000;
            position[1] = (offsetY + 0xa8) << 12;
            oamIndex = oamBuffer->mUnk_400;
            oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamIndex],
                                                         0x80 - oamIndex, cell, NULL, position, 0, 1);
            break;
        case MODE_MISSION_RUN:
            DrawRaceGoalMMissionRun(oamBuffer);
            break;
    }
}

void DrawRaceGoalMGrandPrix(Unk020c06c4 *oamBuffer) {
    s32 offsetY;
    s32 oamIndex;
    s32 rankPosition[2];
    s32 pointsPosition[2];
    s32 cell13Or14Position[2];
    s32 cell40Position[2];
    s32 cell41Position[2];
    s32 z;
    void *cell;

    offsetY = InterpolateS16(1, 0x40, 0, gRaceGoalM->mUpdateFrames, 0x14);
    cell = GetRaceGoalMNcerEntry(gRaceGoalM->mRankIndex);
    rankPosition[0] = 0x18000;
    rankPosition[1] = (offsetY + 0xa8) << 12;
    oamIndex = oamBuffer->mUnk_400;
    oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamIndex], 0x80 - oamIndex,
                                                 cell, NULL, rankPosition, 0, 1);

    cell = GetRaceGoalMNcerEntry(gRaceGoalM->mPointsGained + 8);
    pointsPosition[0] = 0x48000;
    pointsPosition[1] = (offsetY + 0xb0) << 12;
    oamIndex = oamBuffer->mUnk_400;
    oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamIndex], 0x80 - oamIndex,
                                                 cell, NULL, pointsPosition, 0, 1);

    cell = GetRaceGoalMNcerEntry(func_020b4b98(gRaceGoalM->mPointsGained) != FALSE ? 0x13 : 0x14);
    cell13Or14Position[0] = 0x48000;
    cell13Or14Position[1] = (offsetY + 0xb0) << 12;
    oamIndex = oamBuffer->mUnk_400;
    oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamIndex], 0x80 - oamIndex,
                                                 cell, NULL, cell13Or14Position, 0, 1);

    cell = GetRaceGoalMNcerEntry(0x40);
    cell40Position[0] = 0xda000;
    cell40Position[1] = (offsetY + 0xa6) << 12;
    oamIndex = oamBuffer->mUnk_400;
    oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamIndex], 0x80 - oamIndex,
                                                 cell, NULL, cell40Position, 0, 1);

    cell = GetRaceGoalMNcerEntry(0x41);
    cell41Position[0] = 0xda000;
    cell41Position[1] = (offsetY + 0xa6) << 12;
    oamIndex = oamBuffer->mUnk_400;
    oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamIndex], 0x80 - oamIndex,
                                                 cell, NULL, cell41Position, 0, 1);
}

void DrawRaceGoalMMissionRun(Unk020c06c4 *oamBuffer) {
    s32 n;
    s32 offsetY;
    s32 oamIndex;
    s32 cellIndex;
    s32 blinkFrame;
    s32 position[2];
    void *cell;

    n = gRaceGoalM->mUpdateFrames;
    offsetY = InterpolateS16(1, -0x80, 0, n, 0x14);
    if (gRaceGoalM->mUnk_14 != 9 && gRaceGoalM->mUnk_18 > gRaceGoalM->mUnk_14 && n >= 0x1e) {
        blinkFrame = n - 10;
        if (blinkFrame < 0x54) {
            n = blinkFrame % 12;
            if (n >= 8) {
                return;
            }
        }
    }
    switch (gRaceGoalM->mUnk_18) {
        case 0:
            cellIndex = 7;
            break;
        case 1:
            cellIndex = 6;
            break;
        case 2:
            cellIndex = 5;
            break;
        case 3:
            cellIndex = 4;
            break;
        case 4:
            cellIndex = 3;
            break;
        case 5:
            cellIndex = 2;
            break;
        case 6:
            cellIndex = 1;
            break;
        case 7:
            cellIndex = 0;
            break;
    }
    if (gRaceGoalM->mUnk_18 >= 8) {
        return;
    }
    cell = GetRaceGoalMrMNcerEntry(cellIndex);
    position[0] = (offsetY + 0x80) << 12;
    position[1] = 0x60000;
    oamIndex = oamBuffer->mUnk_400;
    oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamIndex], 0x80 - oamIndex,
                                                 cell, NULL, position, 0, 1);
}

void InitRaceLinkLevel(void) {
    gRaceLinkLevel = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x14);
    gRaceLinkLevel->mUnk_00 = 0;
    gRaceLinkLevel->mUnk_04 = 0;
    gRaceLinkLevel->mUnk_08 = 0;
    gRaceLinkLevel->mUnk_0c = 0;
    gRaceLinkLevel->mUnk_10 = 0;
}

u32 ClearRaceLinkLevelPointer(void) {
    u32 address;
    u32 zero;
    address = (u32) &gRaceLinkLevel;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

void UpdateRaceLinkLevel(void) {
    if (gRaceLinkLevel == NULL) {
        return;
    }
    if (data_021759d0->mUnk_20 == 0) {
        return;
    }
    if (gRaceSetup->mMode == 5) {
        gRaceLinkLevel->mUnk_04 = func_021205e8();
        gRaceLinkLevel->mUnk_0c = gRaceLinkLevel->mUnk_10;
        gRaceLinkLevel->mUnk_10 = func_0212a8d0();
        if (gRaceLinkLevel->mUnk_10 != 0 && gRaceLinkLevel->mUnk_0c == 0) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x26);
        }
        if (gRaceLinkLevel->mUnk_10 != 0) {
            gRaceLinkLevel->mUnk_08++;
            if (gRaceLinkLevel->mUnk_08 >= 0x78) {
                gRaceLinkLevel->mUnk_08 = 0;
            }
        } else {
            gRaceLinkLevel->mUnk_08 = 0;
            gRaceLinkLevel->mUnk_0c = 0;
            gRaceLinkLevel->mUnk_10 = 0;
        }
    } else {
        gRaceLinkLevel->mUnk_00 = data_0217aa00->mUnk_0004 == 0 ? 0 : WM_GetLinkLevel();
    }
}

void DrawRaceLinkLevel(Unk020c06c4 *oamBuffer) {
    void *levelCell = NULL;
    void *extraCell = NULL;

    if (gRaceLinkLevel == NULL) {
        return;
    }
    if (data_021759d0->mUnk_20 != 0) {
        if (func_020b1d20() == 0) {
            if (gRaceSetup->mMode == 5) {
                levelCell = GetRaceMNcerEntry(gRaceLinkLevel->mUnk_04 + 0x28);
            } else {
                levelCell = GetRaceMNcerEntry(gRaceLinkLevel->mUnk_00 + 0x28);
            }
        } else {
            if (gRaceSetup->mMode == 5) {
                levelCell = GetRaceGoalMNcerEntry(gRaceLinkLevel->mUnk_04 + 0x3c);
            } else {
                levelCell = GetRaceGoalMNcerEntry(gRaceLinkLevel->mUnk_00 + 0x3c);
            }
        }
        if (gRaceSetup->mMode == 5 && gRaceLinkLevel->mUnk_10 != 0 && gRaceLinkLevel->mUnk_08 < 0x69) {
            if (func_020b1d20() != 0) {
                extraCell = GetRaceGoalMNcerEntry(0x42);
            } else {
                extraCell = GetRaceMNcerEntry(0x2c);
            }
        }
    }
    if (levelCell != NULL) {
        s32 firstPosition[2];
        s32 secondPosition[2];
        s32 oamIndex;
        Unk020c06c4_08 *oam;

        oamIndex = oamBuffer->mUnk_400;
        firstPosition[0] = 0xf8000;
        firstPosition[1] = 0xb8000;
        oam = &oamBuffer->mUnk_000.mUnk_00[oamIndex];
        oamBuffer->mUnk_400 +=
            NNS_G2dMakeCellToOams((GXOamAttr *) oam, 0x80 - oamIndex, levelCell, NULL, firstPosition, 0, 1);
        for (; oamIndex < oamBuffer->mUnk_400; oamIndex++, oam++) {
            oam->mUnk_0a = 2;
            oam->mUnk_0e = 1;
        }
        secondPosition[0] = 0xf8000;
        secondPosition[1] = 0xb8000;
        oamIndex = oamBuffer->mUnk_400;
        oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamIndex],
                                                     0x80 - oamIndex, levelCell, NULL, secondPosition, 0, 1);
    }
    if (extraCell != NULL) {
        s32 firstPosition[2];
        s32 secondPosition[2];
        s32 oamIndex;
        Unk020c06c4_08 *oam;

        oamIndex = oamBuffer->mUnk_400;
        firstPosition[0] = 0xf8000;
        firstPosition[1] = 0xa7000;
        oam = &oamBuffer->mUnk_000.mUnk_00[oamIndex];
        oamBuffer->mUnk_400 +=
            NNS_G2dMakeCellToOams((GXOamAttr *) oam, 0x80 - oamIndex, extraCell, NULL, firstPosition, 0, 1);
        for (; oamIndex < oamBuffer->mUnk_400; oamIndex++, oam++) {
            oam->mUnk_0a = 2;
            oam->mUnk_0e = 1;
        }
        secondPosition[0] = 0xf8000;
        secondPosition[1] = 0xa7000;
        oamIndex = oamBuffer->mUnk_400;
        oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamIndex],
                                                     0x80 - oamIndex, extraCell, NULL, secondPosition, 0, 1);
    }
}

void UploadRaceStartGpOam(void) {
    u32 powerBit;
    u32 displayBits;

    DC_FlushRange(&gRaceStartGp->mMainOam, 0x400);
    GX_LoadOAM(&gRaceStartGp->mMainOam, 0, 0x400);
    powerBit = (reg_GX_POWCNT & 0x8000) >> 15;
    if (powerBit != 0) {
        if (powerBit == 1) {
            displayBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
            reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((displayBits | 0x10) << 8);
        }
    } else {
        displayBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((displayBits & ~0x10) << 8);
    }
}

void InitRaceStartGp(void) {
    Unk02021dc8 *ncer;
    u8 charCanvas[0x20];
    TextCanvas textCanvas;
    void *r;
    s32 messageIndex;
    s32 i;

    gRaceStartGp = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x41c);
    for (i = 0; i < 0x80; i++) {
        Unk020c06c4_08 *e = &gRaceStartGp->mMainOam.mUnk_000.mUnk_00[i];
        e->mUnk_0a = 3;
    }
    gRaceStartGp->mUpdateFrames = 0;
    LoadNclrData(&gRaceStartGp->mRaceStartGpMONclr, FindSceneFileWrapper("race_start_gp_m_o.NCLR"));
    LoadNcgrData2(&gRaceStartGp->mRaceStartGpMONcgr, FindSceneFileWrapper("race_start_gp_m_o.NCGR"));
    ncer = NULL;
    LoadNcerData(&ncer, FindSceneFileWrapper("race_start_gp_m.NCER"));
    for (i = 0; i < 3; i++) {
        gRaceStartGp->mRaceStartGpMNcerEntries[i] = NNS_G2dGetCellDataByIdx(ncer, (u16) i);
    }
    r = func_020b403c(2);
    messageIndex = -1;
    NNS_G2dCharCanvasInitForBG(charCanvas, gRaceStartGp->mRaceStartGpMONcgr->mData, 0x20, 4, 4);
    textCanvas.mCharCanvas = charCanvas;
    textCanvas.mFont = r;
    textCanvas.mCharSpacing = 1;
    textCanvas.mLineSpacing = 0;
    if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
        messageIndex = GetCourseMessageIndex(gRaceSetup->mCourseId);
        textCanvas.mCharSpacing = func_020b4b10();
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        messageIndex = (gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableRow : messageIndex) + 0x55;
        textCanvas.mCharSpacing = func_020b4b54();
    }
    NNSi_G2dTextCanvasDrawText(&textCanvas, 0, 9, 0xe, 0x40a, GetBmgEntry(func_020b47cc("common.bmg"), messageIndex));
    NNSi_G2dTextCanvasDrawText(&textCanvas, 0, 8, 0xe, 0x40a, GetBmgEntry(func_020b47cc("common.bmg"), messageIndex));
    DC_FlushRange(gRaceStartGp->mRaceStartGpMONcgr->mData, gRaceStartGp->mRaceStartGpMONcgr->mDataSize);
    GX_LoadOBJPltt(gRaceStartGp->mRaceStartGpMONclr->mData, 0, gRaceStartGp->mRaceStartGpMONclr->mDataSize);
    GX_LoadOBJ(gRaceStartGp->mRaceStartGpMONcgr->mData, 0, gRaceStartGp->mRaceStartGpMONcgr->mDataSize);
}

u32 ClearRaceStartGpPointer(void) {
    u32 address;
    u32 zero;
    address = (u32) &gRaceStartGp;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

u16 UpdateRaceStartGp(void) {
    u16 *powerControl;
    int *startGp;
    powerControl = ((u16 *) &reg_GX_POWCNT);
    startGp = (s32 *) gRaceStartGp;
    *startGp = (*(u32 *) startGp) + 1;
    return *powerControl;
}

const Vec3 gVec3Zero = {0, 0, 0};

void DrawRaceStartGp(void) {
    Unk020c06c4 *oamBuffer;
    Unk020224e0_c *cell;
    s32 position[2];

    gRaceStartGp->mMainOam.mUnk_400 = 0;
    cell = gRaceStartGp->mRaceStartGpMNcerEntries[0];
    oamBuffer = &gRaceStartGp->mMainOam;
    position[0] = 0x80000;
    position[1] = 0x60000;
    oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) &oamBuffer->mUnk_000.mUnk_00[oamBuffer->mUnk_400],
                                                 0x80 - oamBuffer->mUnk_400, cell, NULL, position, 0, 1);
    DC_FlushRange(&gRaceStartGp->mMainOam, 0x400);
    MI_DmaFill32(3, &gRaceStartGp->mMainOam.mUnk_000.mUnk_00[gRaceStartGp->mMainOam.mUnk_400], 0xc0,
                 (0x80 - gRaceStartGp->mMainOam.mUnk_400) * 8);
}

void HideRaceTaKartPositions(s32 kartIndex) {
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        gRaceTaPositions->mKartVisible[kartIndex] = 0;
    }
}

void ResetRaceTaKartPositions(s32 kartIndex) {
    s32 i;
    s32 j;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    for (i = 0; i < 0x28; i++) {
        gRaceTaPositions->mSamples[kartIndex][i].mKind = 0;
    }
    for (j = 0; j < gRaceTaPositions->mUnk_790[kartIndex].mUnk_00; j++) {
        gRaceTaPositions->mUnk_790[kartIndex].mUnk_34[j] = 0x28;
    }
    gRaceTaPositions->mKartVisible[kartIndex] = 1;
}

void InitRaceTaPositions(void) {
    s32 a;
    s32 j;
    Vec3 position;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    gRaceTaPositions = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x910);
    gRaceTaPositions->mVisible = 1;
    for (a = 0; a < gRaceSetup->mKartCount; a++) {
        gRaceTaPositions->mKartVisible[a] = 1;
    }
    gRaceTaPositions->mSampleFrames = 0;
    for (a = 0; a < gRaceSetup->mKartCount; a++) {
        u16 angle = (u32) func_020b6338(a);
        func_0207a91c(&position, a);
        for (j = 0; j < 0x28; j++) {
            gRaceTaPositions->mSamples[a][j].mPos = position;
            gRaceTaPositions->mSamples[a][j].mAngle = angle;
            gRaceTaPositions->mSamples[a][j].mKind = 0;
            gRaceTaPositions->mSamples[a][j].mUnk_14 = 3;
        }
    }
    a = 0;
    if (a < gRaceSetup->mKartCount) {
        Vec3 zeroVector = gVec3Zero;
        do {
            gRaceTaPositions->mUnk_790[a].mUnk_00 = 0;
            for (j = 0; j < 3; j++) {
                gRaceTaPositions->mUnk_790[a].mUnk_04[j] = zeroVector;
                gRaceTaPositions->mUnk_790[a].mUnk_34[j] = -1;
                gRaceTaPositions->mUnk_790[a].mUnk_28[j] = 3;
            }
            a++;
        } while (a < gRaceSetup->mKartCount);
    }
    for (a = 0; a < 16; a++) {
        s32 pairFirst = gPairsByAngle[((u16) (a * 0x10000 / 16) >> 4) * 2];
        s32 pairSecond = gPairsByAngle[((u16) (a * 0x10000 / 16) >> 4) * 2 + 1];
        gRaceTaPositions->mRotations[a].mUnk_00 = pairSecond;
        gRaceTaPositions->mRotations[a].mUnk_04 = pairFirst;
        gRaceTaPositions->mRotations[a].mUnk_08 = -pairFirst;
        gRaceTaPositions->mRotations[a].mUnk_0c = pairSecond;
    }
}

u32 ClearRaceTaPositionsPointer(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceTaPositions;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void UpdateRaceTaPositions(void) {
    Kart *kart;
    RaceTaPositions *positions;
    u16 j;
    s32 count;
    u32 i;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (IsRaceStartSequenceDone() == 0) {
        return;
    }
    if ((u16) (data_02175628[func_020435bc()].mPressedBits & 4) != 0) {
        gRaceTaPositions->mVisible = gRaceTaPositions->mVisible == 0 ? 1 : 0;
    }
    for (i = 0; i < gRaceSetup->mKartCount; i = (u16) (i + 1)) {
        if ((gKartItems)[i].mUnk_204 != FALSE) {
            count = gRaceTaPositions->mUnk_790[i].mUnk_00;
            gRaceTaPositions->mUnk_790[i].mUnk_00 = count + 1;
            ((void (*)(Vec3 *, s32)) func_0207a91c)(&gRaceTaPositions->mUnk_790[i].mUnk_04[count], i);
            gRaceTaPositions->mUnk_790[i].mUnk_28[count] =
                func_020b4e70(&gRaceTaPositions->mUnk_790[i].mUnk_04[count]) != 0 ? 2 : 3;
        }
    }
    gRaceTaPositions->mSampleFrames++;
    if (gRaceTaPositions->mSampleFrames > 0xf) {
        gRaceTaPositions->mSampleFrames = 0;
        for (i = 0; i < gRaceSetup->mKartCount; i = (u16) (i + 1)) {
            for (j = 0; j < gRaceTaPositions->mUnk_790[i].mUnk_00; j = j + 1) {
                if (gRaceTaPositions->mUnk_790[i].mUnk_34[j] < 0x28) {
                    gRaceTaPositions->mUnk_790[i].mUnk_34[j]++;
                }
            }
        }
        func_020b1d50();
        func_020b1d50();
        for (i = 0; i < gRaceSetup->mKartCount; i = (u16) (i + 1)) {
            kart = GetKart(i);
            positions = gRaceTaPositions;
            for (j = 0x27; j != 0; j--) {
                positions->mSamples[i][j] = positions->mSamples[i][j - 1];
            }
            func_0207a91c(&gRaceTaPositions->mSamples[i][0].mPos, i);
            gRaceTaPositions->mSamples[i][0].mUnk_14 =
                func_020b4e70(&gRaceTaPositions->mSamples[i][0].mPos) != 0 ? 2 : 3;
            gRaceTaPositions->mSamples[i][0].mAngle = func_020b6338(i);
            if ((kart->mUnk_44 & 0xa) != 0) {
                gRaceTaPositions->mSamples[i][0].mKind = 2;
            } else if ((kart->mUnk_48 & 0x80020) != 0) {
                gRaceTaPositions->mSamples[i][0].mKind = 3;
            } else {
                gRaceTaPositions->mSamples[i][0].mKind = 1;
            }
            if (gRaceProgress->mRaceDone != 0) {
                gRaceTaPositions->mSamples[i][0].mKind = 0;
                gRaceTaPositions->mKartVisible[i] = 0;
            }
        }
    }
}

void DrawRaceTaPositions(Unk020c06c4 *oamBuffer) {
    UnkPair020b502c trailPosition;
    UnkPair020b502c samplePosition;
    s32 trailCellPosition[2];
    s32 sampleCellPosition[2];
    u16 firstRotationSlot;
    void *sampleCell;
    float f;
    s32 v;
    s32 s;
    s32 i;
    s32 j;
    u32 m;
    s32 trailOamIndex;
    Unk020c06c4_08 *trailOam;
    void *trailCell;
    u32 h;
    s32 sampleOamIndex;
    Unk020c06c4_08 *sampleOam;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (gRaceTaPositions->mVisible == 0) {
        return;
    }
    firstRotationSlot = AllocOamMatrixIndex(oamBuffer);
    for (i = 1; i < 16; i++) {
        AllocOamMatrixIndex(oamBuffer);
    }
    if ((func_020b1d50() * 3) > 0) {
        f = (func_020b1d50() * 0x3000) + 0.5f;
    } else {
        f = (func_020b1d50() * 0x3000) - 0.5f;
    }
    v = f;
    s = ((s64) v * 20) >> 12;
    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        if (gRaceTaPositions->mKartVisible[i] != 0) {
            if (gRaceProgress->mRaceDone == 0) {
                for (j = 0; j < gRaceTaPositions->mUnk_790[i].mUnk_00; j++) {
                    if (gRaceTaPositions->mUnk_790[i].mUnk_34[j] < 0x28) {
                        if (ComputeRaceHudSubScreenPosition(&gRaceTaPositions->mUnk_790[i].mUnk_04[j], &trailPosition,
                                                            s, 1, 1) != FALSE) {
                            m = gRaceTaPositions->mUnk_790[i].mUnk_28[j];
                            trailCell = GetRaceSNcerEntry(0x4f);
                            trailOamIndex = oamBuffer->mUnk_400;
                            trailCellPosition[0] = trailPosition.mUnk_00 << 12;
                            trailCellPosition[1] = trailPosition.mUnk_04 << 12;
                            trailOam = &oamBuffer->mUnk_000.mUnk_00[trailOamIndex];
                            oamBuffer->mUnk_400 += NNS_G2dMakeCellToOams((GXOamAttr *) trailOam, 0x80 - trailOamIndex,
                                                                         trailCell, NULL, trailCellPosition, 0, 1);
                            for (; trailOamIndex < oamBuffer->mUnk_400; trailOamIndex++, trailOam++) {
                                if (m != -1) {
                                    trailOam->mUnk_0e = m;
                                }
                            }
                        }
                    }
                }
            }
            for (j = 0; j < 0x28; j++) {
                u16 angle = (u16) (gRaceTaPositions->mSamples[i][j].mAngle + func_020b6368()) + 0x800;
                u16 rotationIndex = ((angle << 4) / 0x10000) % 16;
                if (ComputeRaceHudSubScreenPosition(&gRaceTaPositions->mSamples[i][j].mPos, &samplePosition, s, 1, 1) !=
                    FALSE) {
                    switch (gRaceTaPositions->mSamples[i][j].mKind) {
                        case 0:
                            sampleCell = NULL;
                            break;
                        case 1:
                            sampleCell = GetRaceSNcerEntry(0x51);
                            break;
                        case 2:
                            sampleCell = GetRaceSNcerEntry(0x52);
                            break;
                        case 3:
                            sampleCell = GetRaceSNcerEntry(0x53);
                            break;
                    }
                    if (sampleCell != NULL) {
                        h = gRaceTaPositions->mSamples[i][j].mUnk_14;
                        sampleOamIndex = oamBuffer->mUnk_400;
                        sampleCellPosition[0] = samplePosition.mUnk_00 << 12;
                        sampleCellPosition[1] = samplePosition.mUnk_04 << 12;
                        sampleOam = &oamBuffer->mUnk_000.mUnk_00[sampleOamIndex];
                        oamBuffer->mUnk_400 +=
                            NNS_G2dMakeCellToOams((GXOamAttr *) sampleOam, 0x80 - sampleOamIndex, sampleCell,
                                                  &gRaceTaPositions->mRotations[rotationIndex].mUnk_00,
                                                  sampleCellPosition, rotationIndex + firstRotationSlot, 1);
                        for (; sampleOamIndex < oamBuffer->mUnk_400; sampleOamIndex++, sampleOam++) {
                            if ((i != 0 ? 1 : -1) != -1) {
                                sampleOam->mUnk_0a = i != 0 ? 1 : -1;
                            }
                            if (h != -1) {
                                sampleOam->mUnk_0e = h;
                            }
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < 16; i++) {
        Matrix2x2 *rotation = &gRaceTaPositions->mRotations[i];
        (oamBuffer->mUnk_000.mUnk_20 + firstRotationSlot)[i].mUnk_06 = rotation->mUnk_00 >> 4;
        (oamBuffer->mUnk_000.mUnk_20 + firstRotationSlot)[i].mUnk_0e = rotation->mUnk_04 >> 4;
        (oamBuffer->mUnk_000.mUnk_20 + firstRotationSlot)[i].mUnk_16 = rotation->mUnk_08 >> 4;
        (oamBuffer->mUnk_000.mUnk_20 + firstRotationSlot)[i].mUnk_1e = rotation->mUnk_0c >> 4;
    }
}

#include "Main/Unknown/code_020b9994.h"

#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_0204a550.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020b85dc.h"
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
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020a2204.h"
#include "Main/Unknown/code_020a10d4.h"
#include "Main/Unknown/code_020a1000.h"
#include "01/code_0218155c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_0204a000.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020ba50c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020b846c.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020bb530.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"

void InitRaceItemSlot(void) {
    RaceItemSlot *itemSlot;

    itemSlot = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gRaceItemSlot = itemSlot;
    itemSlot->mScrollY = 0;
    gRaceItemSlot->mSlotFrames = 0;
    gRaceItemSlot->mUpperItem = 0x13;
    gRaceItemSlot->mLowerItem = 0x13;
    gRaceItemSlot->mSlotRunning = 0;
    gRaceItemSlot->mPrevSlotRunning = 0;
    gRaceItemSlot->mScale.mScaleFrames = 0;
    gRaceItemSlot->mScale.mScaleX = 0x1000;
    gRaceItemSlot->mScale.mScaleY = 0x1000;
    gRaceItemSlot->mScale.mScaleYPerFrame = -0x666;
    gRaceItemSlot->mScale.mScaleYTarget = 0x800;
}

u32 ClearRaceItemSlotPointer(void) {
    u32 address;
    u32 zero;
    address = (u32) &gRaceItemSlot;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

static inline KartItems *GetKartItemsAtOffset(u32 offset) {
    return (KartItems *) ((u32) gKartItems + offset);
}

void UpdateRaceItemSlot(void) {
    s32 finalScrollFrameCount;
    u32 kartOffset;
    s32 slotFrames;
    s32 upperItem;
    s32 scrollY;
    u32 endSeqNo;
    NNSSndSeqPlayer **entryHandle;
    NNSSndSeqPlayer **sndHandle;
    u32 startSeqNo;
    RaceItemSlotScale *scale;
    KartItems *kartItems;

    slotFrames = gRaceItemSlot->mSlotFrames;
    kartOffset = GetFollowedKartOrEntryIndex() * 0x210;
    finalScrollFrameCount = GetKartItemsAtOffset(kartOffset)->mSlotFinalScrollFrameCount;
    gRaceItemSlot->mPrevSlotRunning = gRaceItemSlot->mSlotRunning;
    upperItem = 0x13;
    kartItems = GetKartItemsAtOffset(kartOffset);
    if (kartItems->mSlotState == 1) {
        gRaceItemSlot->mSlotFrames = kartItems->mSlotFrames;
        slotFrames = gRaceItemSlot->mSlotFrames;
        gRaceItemSlot->mSlotRunning = 1;
    } else if (slotFrames == 0) {
        gRaceItemSlot->mSlotRunning = 0;
    } else if (slotFrames > 0 && slotFrames < 0xd6) {
        gRaceItemSlot->mSlotFrames += 1;
        slotFrames = gRaceItemSlot->mSlotFrames;
        switch (slotFrames) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 8:
            case 10:
            case 12:
            case 14:
            case 16:
            case 18:
            case 22:
            case 26:
            case 30:
            case 34:
            case 38:
            case 42:
            case 46:
            case 50:
            case 54:
            case 58:
            case 62:
            case 66:
            case 70:
            case 74:
            case 78:
            case 86:
            case 94:
            case 102:
            case 110:
            case 118:
            case 134:
            case 150:
            case 166:
            case 182:
            case 198:
            case 214:

                gRaceItemSlot->mSlotFrames = 0xd6;
                slotFrames = gRaceItemSlot->mSlotFrames;
                break;
        }
        gRaceItemSlot->mSlotRunning = 1;
    } else if (slotFrames >= 0xd6 && slotFrames < finalScrollFrameCount + 0xd5) {
        gRaceItemSlot->mSlotFrames += 1;
        slotFrames = gRaceItemSlot->mSlotFrames;
        gRaceItemSlot->mSlotRunning = 1;
    } else {
        NNS_SndPlayerStopSeq(GetSndHandles(), 0);
        gRaceItemSlot->mSlotFrames = 0;
        slotFrames = gRaceItemSlot->mSlotFrames;
        if (GetKartItemsAtOffset(kartOffset)->mSlotShownItem >= 9) {
            if (gRaceSetup->mRaceKind != 2) {
                endSeqNo = 0x40;
                if (gRaceSetup->mCourseId == COURSE_ID_PINBALL) {
                    endSeqNo = 0x1c6;
                }
                if ((data_0217c780 & 1) != 0) {
                    entryHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
                    if (data_0217d084.mUnk_0c != 0) {
                        if (*entryHandle != NULL) {
                            NNS_SndPlayerStopSeq(entryHandle, 0);
                        }
                        if (*entryHandle != NULL) {
                            NNS_SndPlayerStopSeq(entryHandle, 0);
                        }
                        NNS_SndArcPlayerStartSeqArc(entryHandle, 0, endSeqNo);
                    }
                }
            }
        } else {
            if (gRaceSetup->mRaceKind != 2) {
                endSeqNo = 0x3f;
                if (gRaceSetup->mCourseId == COURSE_ID_PINBALL) {
                    endSeqNo = 0x1c5;
                }
                if ((data_0217c780 & 1) != 0) {
                    entryHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
                    if (data_0217d084.mUnk_0c != 0) {
                        if (*entryHandle != NULL) {
                            NNS_SndPlayerStopSeq(entryHandle, 0);
                        }
                        if (*entryHandle != NULL) {
                            NNS_SndPlayerStopSeq(entryHandle, 0);
                        }
                        NNS_SndArcPlayerStartSeqArc(entryHandle, 0, endSeqNo);
                    }
                }
            }
        }
        gRaceItemSlot->mSlotRunning = 0;
    }
    if (gRaceItemSlot->mPrevSlotRunning == 0 && gRaceItemSlot->mSlotRunning != 0 && gRaceSetup->mRaceKind != 2) {
        sndHandle = GetSndHandles();
        startSeqNo = 0x3e;
        if (gRaceSetup->mCourseId == COURSE_ID_PINBALL) {
            startSeqNo = 0x1c4;
        }
        if ((data_0217c780 & 1) != 0) {
            if (data_0217d084.mUnk_0c != 0) {
                if (*sndHandle != NULL) {
                    NNS_SndPlayerStopSeq(sndHandle, 0);
                }
                if (*sndHandle != NULL) {
                    NNS_SndPlayerStopSeq(sndHandle, 0);
                }
                NNS_SndArcPlayerStartSeqArc(sndHandle, 0, startSeqNo);
            }
        }
    }
    kartItems = GetKartItemsAtOffset(kartOffset);
    if (kartItems->mSlotState == 0) {
        gRaceItemSlot->mLowerItem =
            kartItems->mHeldItem.mItemInfoIndex == 0x13 ? kartItems->mActiveItem : kartItems->mHeldItem.mItemInfoIndex;
    } else {
        switch (slotFrames) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 8:
            case 10:
            case 12:
            case 14:
            case 16:
            case 18:
            case 22:
            case 26:
            case 30:
            case 34:
            case 38:
            case 42:
            case 46:
            case 50:
            case 54:
            case 58:
            case 62:
            case 66:
            case 70:
            case 74:
            case 78:
            case 86:
            case 94:
            case 102:
            case 110:
            case 118:
            case 134:
            case 150:
            case 166:
            case 182:
            case 198:
            case 214:

                gRaceItemSlot->mLowerItem = kartItems->mSlotShownItem;
                PickItemSlotShownItem(GetKartItemsAtOffset(kartOffset));
                break;
        }
        upperItem = GetKartItemsAtOffset(kartOffset)->mSlotShownItem;
        gRaceItemSlot->mScale.mScaleFrames = 0;
    }
    if (slotFrames < 6) {
        scrollY = 0;
    } else if (slotFrames < 0x12) {
        scrollY = ((slotFrames - 6) & 1) << 5 >> 1;
    } else if (slotFrames < 0x4e) {
        scrollY = ((slotFrames - 0x12) & 3) << 5 >> 2;
    } else if (slotFrames < 0x76) {
        scrollY = ((slotFrames - 0x4e) & 7) << 5 >> 3;
    } else if (slotFrames < 0xd6) {
        scrollY = ((slotFrames - 0x76) & 0xf) << 5 >> 4;
    } else if (slotFrames >= finalScrollFrameCount + 0xd6) {
        scrollY = 0;
    } else {
        scrollY = ((slotFrames - 0xd6) & ((s32) GetKartItemsAtOffset(kartOffset)->mSlotFinalScrollFrameCount - 1))
                      << 5 >>
                  GetKartItemsAtOffset(kartOffset)->mSlotFinalScrollFrameShift;
    }
    if (gRaceItemSlot->mScale.mScaleFrames != 0) {
        scale = &gRaceItemSlot->mScale;
        scale->mScaleY += scale->mScaleYPerFrame;
        scale->mScaleYPerFrame += (s32) (((s64) (scale->mScaleYTarget - scale->mScaleY) * 0x333) >> 12);
        scale->mScaleYPerFrame = ((s64) scale->mScaleYPerFrame * 0xc00) >> 12;
        scale->mScaleX = (s32) (((s64) scale->mScaleYTarget * 0x2000) >> 12) - scale->mScaleY;
        gRaceItemSlot->mScale.mScaleFrames += 1;
        if (gRaceItemSlot->mScale.mScaleYTarget == 0xb33 && gRaceItemSlot->mScale.mScaleFrames > 7) {
            gRaceItemSlot->mScale.mScaleYTarget = 0x1000;
        } else if (gRaceItemSlot->mScale.mScaleYTarget == 0x1000 && gRaceItemSlot->mScale.mScaleFrames > 10) {
            gRaceItemSlot->mScale.mScaleFrames = 0;
        }
    }
    if (GetKartItemsAtOffset(kartOffset)->mKinokoBoostStarted != FALSE) {
        s32 heldOrActiveItem;
        heldOrActiveItem = GetKartItemsAtOffset(kartOffset)->mHeldItem.mItemInfoIndex == 0x13
                               ? GetKartItemsAtOffset(kartOffset)->mActiveItem
                               : GetKartItemsAtOffset(kartOffset)->mHeldItem.mItemInfoIndex;
        if (heldOrActiveItem == 0xd) {
            gRaceItemSlot->mScale.mScaleFrames += 1;
            gRaceItemSlot->mScale.mScaleX = 0x1000;
            gRaceItemSlot->mScale.mScaleY = 0x1000;
            gRaceItemSlot->mScale.mScaleYPerFrame = -0x19a;
            gRaceItemSlot->mScale.mScaleYTarget = 0xb33;
        }
    }
    gRaceItemSlot->mScrollY = scrollY;
    gRaceItemSlot->mUpperItem = upperItem;
}

void DrawRaceItemSlot(RaceHudOamBuffer *oamBuffer) {
    s32 firstPos[2];
    s32 secondPos[2];
    s32 thirdPos[2];
    s32 upperItemPos[2];
    s32 lowerItemPos[2];
    s32 scaledUpperItemPos[2];
    s32 scaledLowerItemPos[2];
    s32 lastPos[2];
    s32 matrix[4];
    s32 scrollY;
    s32 upperItem;
    Unk020224e0_c *cell;
    Unk020224e0_c *teamCell;
    s32 oamIndex;
    GXOamAttr *oam;
    GXOamAttr *matrixOams;
    u16 matrixIndex;

    scrollY = gRaceItemSlot->mScrollY;
    upperItem = gRaceItemSlot->mUpperItem;
    teamCell =
        GetRaceMNcerEntry(gRaceSetup->mUseTeams == 0                                                           ? 8
                          : gRaceSetup->mCurrentEntries[GetFollowedKartOrEntryIndex()].mPlayer.mTeamIndex == 0 ? 9
                                                                                                               : 10);
    if (gRaceSetup->mRaceKind == 4) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    cell = GetRaceMNcerEntry(0xc);
    firstPos[0] = 0x18000;
    firstPos[1] = 0x18000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, firstPos, 0, 1);
    oamIndex = oamBuffer->mOamCount;
    secondPos[0] = 0x18000;
    secondPos[1] = 0x18000;
    oam = &oamBuffer->mOams[oamIndex];
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(oam, 0x80 - oamIndex, teamCell, NULL, secondPos, 0, 1);
    for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
        ((u32 *) oam)[0] = (((u32 *) oam)[0] & ~0xc00) | 0x800;
        ((u32 *) oam)[1] = (((u32 *) oam)[1] & ~0xc00) | 0x400;
    }
    oamIndex = oamBuffer->mOamCount;
    thirdPos[0] = 0x18000;
    thirdPos[1] = 0x18000;
    oam = &oamBuffer->mOams[oamIndex];
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(oam, 0x80 - oamIndex, teamCell, NULL, thirdPos, 0, 1);
    for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
        ((u32 *) oam)[1] = (((u32 *) oam)[1] & ~0xc00) | 0x400;
    }
    if (gRaceItemSlot->mScale.mScaleFrames == 0) {
        cell = GetRaceMNcerEntry(LookupRaceMNcerIndex(upperItem));
        upperItemPos[0] = 0x18000;
        upperItemPos[1] = (scrollY - 8) << 12;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, upperItemPos, 0, 1);
        cell = GetRaceMNcerEntry(LookupRaceMNcerIndex(gRaceItemSlot->mLowerItem));
        lowerItemPos[0] = 0x18000;
        lowerItemPos[1] = (scrollY + 0x18) << 12;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, lowerItemPos, 0, 1);
    } else {
        matrixIndex = AllocOamMatrixIndex(oamBuffer);
        matrix[0] = FX_Div(0x1000, gRaceItemSlot->mScale.mScaleX);
        matrix[1] = 0;
        matrix[2] = 0;
        matrix[3] = FX_Div(0x1000, gRaceItemSlot->mScale.mScaleY);
        cell = GetRaceMNcerEntry(LookupRaceMNcerIndex(upperItem));
        oamIndex = oamBuffer->mOamCount;
        scaledUpperItemPos[0] = 0x18000;
        scaledUpperItemPos[1] = (scrollY - 8) << 12;
        oam = &oamBuffer->mOams[oamIndex];
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(oam, 0x80 - oamIndex, cell, matrix, scaledUpperItemPos, matrixIndex, 1);
        for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
            ((u32 *) oam)[1] = (((u32 *) oam)[1] & ~0xc00) | 0x400;
        }
        cell = GetRaceMNcerEntry(LookupRaceMNcerIndex(gRaceItemSlot->mLowerItem));
        oamIndex = oamBuffer->mOamCount;
        scaledLowerItemPos[0] = 0x18000;
        scaledLowerItemPos[1] = (scrollY + 0x18) << 12;
        oam = &oamBuffer->mOams[oamIndex];
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(oam, 0x80 - oamIndex, cell, matrix, scaledLowerItemPos, matrixIndex, 1);
        for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
            ((u32 *) oam)[1] = (((u32 *) oam)[1] & ~0xc00) | 0x400;
        }
        matrixOams = &oamBuffer->mOams[matrixIndex * 4];
        matrixOams[0].mUnk_00[3] = matrix[0] >> 4;
        matrixOams[1].mUnk_00[3] = matrix[1] >> 4;
        matrixOams[2].mUnk_00[3] = matrix[2] >> 4;
        matrixOams[3].mUnk_00[3] = matrix[3] >> 4;
    }
    cell = GetRaceMNcerEntry(0xb);
    lastPos[0] = 0x18000;
    lastPos[1] = 0x18000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, lastPos, 0, 1);
}

BOOL IsRaceKeyRecordingNotFull(void) {
    if (gRaceModeCount != NULL) {
        return gRaceModeCount->mKeyRecordingNotFull;
    }
    return 0;
}

void InitRaceModeCount(void) {
    RaceModeCount *modeCount;
    s32 mode;

    modeCount = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0xc);
    gRaceModeCount = modeCount;
    mode = gRaceSetup->mMode;
    switch (mode) {
        case MODE_MISSION_RUN:
            gRaceModeCount->mNumber = mode == MODE_MISSION_RUN ? GetMissionRunCount() : 0;
            gRaceModeCount->mMissionRunCountLimit = gRaceSetup->mMissionRunCountLimit;
            break;
        case MODE_BATTLE:
            switch (gRaceSetup->mBattleKind) {
                case BATTLE_KIND_BALLOON:
                    modeCount->mNumberHalves[0] = 0;
                    gRaceModeCount->mNumberHalves[1] = GetBalloonsLeftToMake(GetFollowedKartOrEntryIndex());
                    break;
                case BATTLE_KIND_SHINE:
                default:
                    gRaceModeCount->mNumberHalves[0] = GetBalloonOrShineCount(GetFollowedKartOrEntryIndex());
                    break;
            }
            break;
        case MODE_TIME_ATTACK:
            break;
        default:
            gRaceModeCount->mNumber = GetKartRank(GetFollowedKartOrEntryIndex()) - 1;
            break;
    }
    gRaceModeCount->mKeyRecordingNotFull = 1;
}

u32 ClearRaceModeCountPointer(void) {
    u32 address;
    u32 zero;
    address = (u32) &gRaceModeCount;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

void UpdateRaceModeCount(void) {
    s32 mode;

    mode = gRaceSetup->mMode;
    switch (mode) {
        case MODE_MISSION_RUN:
            gRaceModeCount->mNumber = mode == MODE_MISSION_RUN ? GetMissionRunCount() : 0;
            break;
        case MODE_BATTLE:
            if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
                if (IsKartInflatingBalloon(GetFollowedKartOrEntryIndex()) != 0) {
                    gRaceModeCount->mNumberHalves[0] += 1;
                    if (gRaceModeCount->mNumberHalves[0] >= 9) {
                        gRaceModeCount->mNumberHalves[0] = 0;
                    }
                } else {
                    gRaceModeCount->mNumberHalves[0] = 0;
                }
                gRaceModeCount->mNumberHalves[1] = GetBalloonsLeftToMake(GetFollowedKartOrEntryIndex());
            } else {
                gRaceModeCount->mNumberHalves[0] = GetBalloonOrShineCount(GetFollowedKartOrEntryIndex());
            }
            break;
        case MODE_TIME_ATTACK:
            break;
        default:
            gRaceModeCount->mNumber = GetKartRank(GetFollowedKartOrEntryIndex()) - 1;
            break;
    }
}

void DrawRaceModeCount(RaceHudOamBuffer *oamBuffer) {
    s32 battleEndPos[2];
    s32 balloonPos[2];
    s32 inflatingBalloonPos[2];
    s32 leadingCellPos[2];
    s32 tensPos[2];
    s32 onesPos[2];
    s32 recordingFullFirstPos[2];
    s32 recordingFullSecondPos[2];
    s32 rankPos[2];
    u16 inflateFrames;
    u16 count;
    s32 i;
    s32 oamIndex;
    GXOamAttr *oam;
    Unk020224e0_c *cell;

    if (gRaceSetup->mRaceKind == 4) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    switch (gRaceSetup->mMode) {
        case MODE_MISSION_RUN:
            DrawRaceMissionRunCount(oamBuffer);
            return;
        case MODE_BATTLE:
            if (IsKartEnded(GetFollowedKartOrEntryIndex()) == 0) {
                if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
                    i = 0;
                    count = gRaceModeCount->mNumberHalves[1];
                    inflateFrames = gRaceModeCount->mNumberHalves[0];
                    for (; i < count; i++) {
                        cell = GetRaceBattleMNcerEntry(10);
                        balloonPos[0] = (0xfe - i * 0xe) << 12;
                        balloonPos[1] = 0xc000;
                        oamBuffer->mOamCount +=
                            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, balloonPos, 0, 1);
                    }
                    if (inflateFrames == 0) {
                        return;
                    }
                    if (inflateFrames >= 6) {
                        return;
                    }
                    cell = GetRaceBattleMNcerEntry(10);
                    inflatingBalloonPos[0] = (0xfe - i * 0xe) << 12;
                    inflatingBalloonPos[1] = 0xc000;
                    oamBuffer->mOamCount +=
                        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                              cell, NULL, inflatingBalloonPos, 0, 1);
                } else {
                    i = GetRaceStartSequenceFrames() % 16;
                    if (IsKartLastByBalloonOrShineCount(GetFollowedKartOrEntryIndex()) != 0 && i >= 10) {
                        return;
                    }
                    count = gRaceModeCount->mNumberHalves[0];
                    cell = GetRaceBattleMNcerEntry(0xb);
                    leadingCellPos[0] = 0xcd000;
                    leadingCellPos[1] = 0xf000;
                    oamBuffer->mOamCount +=
                        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                              cell, NULL, leadingCellPos, 0, 1);
                    cell = GetRaceBattleMNcerEntry(count / 10);
                    tensPos[0] = 0xe1000;
                    tensPos[1] = 0x10000;
                    oamBuffer->mOamCount +=
                        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                              cell, NULL, tensPos, 0, 1);
                    cell = GetRaceBattleMNcerEntry(count % 10);
                    onesPos[0] = 0xf0000;
                    onesPos[1] = 0x10000;
                    oamBuffer->mOamCount +=
                        NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                              cell, NULL, onesPos, 0, 1);
                }
            } else {
                if (gRaceProgress->mUnk_000[GetFollowedKartOrEntryIndex()].mStatus != 2) {
                    return;
                }
                if ((GetKart(GetFollowedKartOrEntryIndex())->mUnk_7c & 0x402000) == 0) {
                    return;
                }
                cell = GetRaceBattleMNcerEntry(0xc);
                battleEndPos[0] = 0x80000;
                battleEndPos[1] = 0x60000;
                oamBuffer->mOamCount +=
                    NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell,
                                          NULL, battleEndPos, 0, 1);
            }
            break;
        case MODE_TIME_ATTACK:
            if (data_02175628[0].mSourceKind != 2) {
                return;
            }
            if (IsKeyRecordingFull(&data_02175650[0]) == FALSE) {
                return;
            }
            gRaceModeCount->mKeyRecordingNotFull = 0;
            cell = GetRaceTaMNcerEntry(0xd);
            oamIndex = oamBuffer->mOamCount;
            recordingFullFirstPos[0] = 0x80000;
            recordingFullFirstPos[1] = 0x60000;
            oam = &oamBuffer->mOams[oamIndex];
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(oam, 0x80 - oamIndex, cell, NULL, recordingFullFirstPos, 0, 1);
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                ((u32 *) oam)[0] = (((u32 *) oam)[0] & ~0xc00) | 0x800;
                ((u32 *) oam)[1] = (((u32 *) oam)[1] & ~0xc00) | 0x400;
            }
            cell = GetRaceTaMNcerEntry(0xd);
            recordingFullSecondPos[0] = 0x80000;
            recordingFullSecondPos[1] = 0x60000;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                      recordingFullSecondPos, 0, 1);
            break;
        default:
            cell = GetRaceMNcerEntry(gRaceModeCount->mNumber);
            rankPos[0] = 0x18000;
            rankPos[1] = 0xa8000;
            oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                          0x80 - oamBuffer->mOamCount, cell, NULL, rankPos, 0, 1);
            break;
    }
}

void DrawRaceMissionRunCount(RaceHudOamBuffer *oamBuffer) {
    s32 leadingCellPos[2];
    s32 countTensPos[2];
    s32 countOnesPos[2];
    s32 middleCellPos[2];
    s32 limitTensPos[2];
    s32 limitOnesPos[2];
    s32 oneDigitCountPos[2];
    s32 oneDigitMiddleCellPos[2];
    s32 oneDigitLimitPos[2];
    s32 count;
    s32 countLimit;
    RaceModeCount *modeCount;
    Unk020224e0_c *cell;

    modeCount = gRaceModeCount;
    countLimit = modeCount->mMissionRunCountLimit;
    if (countLimit <= 0) {
        return;
    }
    count = modeCount->mNumber;
    if (count > countLimit) {
        count = countLimit;
    }
    cell = GetRaceMrMNcerEntry(0x15);
    leadingCellPos[0] = 0xc000;
    leadingCellPos[1] = 0xb0000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, leadingCellPos, 0, 1);
    if (gRaceModeCount->mMissionRunCountLimit >= 10) {
        cell = GetRaceMrMNcerEntry(count / 10);
        countTensPos[0] = 0x1b000;
        countTensPos[1] = 0xb4000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, countTensPos, 0, 1);
        cell = GetRaceMrMNcerEntry(count % 10);
        countOnesPos[0] = 0x2e000;
        countOnesPos[1] = 0xb4000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, countOnesPos, 0, 1);
        cell = GetRaceMrMNcerEntry(10);
        middleCellPos[0] = 0x42000;
        middleCellPos[1] = 0xb4000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, middleCellPos, 0, 1);
        cell = GetRaceMrMNcerEntry(countLimit / 10 + 0xb);
        limitTensPos[0] = 0x4d000;
        limitTensPos[1] = 0xb4000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, limitTensPos, 0, 1);
        cell = GetRaceMrMNcerEntry(countLimit % 10 + 0xb);
        limitOnesPos[0] = 0x5b000;
        limitOnesPos[1] = 0xb4000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, limitOnesPos, 0, 1);
    } else {
        cell = GetRaceMrMNcerEntry(count % 10);
        oneDigitCountPos[0] = 0x1b000;
        oneDigitCountPos[1] = 0xb4000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, oneDigitCountPos, 0, 1);
        cell = GetRaceMrMNcerEntry(10);
        oneDigitMiddleCellPos[0] = 0x2f000;
        oneDigitMiddleCellPos[1] = 0xb4000;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                  oneDigitMiddleCellPos, 0, 1);
        cell = GetRaceMrMNcerEntry(countLimit % 10 + 0xb);
        oneDigitLimitPos[0] = 0x3a000;
        oneDigitLimitPos[1] = 0xb4000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, oneDigitLimitPos, 0, 1);
    }
}

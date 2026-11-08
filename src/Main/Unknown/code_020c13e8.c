#include "Main/Unknown/code_020c13e8.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b1d64.h"
#include "Main/Unknown/code_020c0dd8.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020c13d0.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b1000.h"
#include "Main/Unknown/code_0203c8dc.h"

void func_020c1ef8(void) {
    s32 sortKeys[8];
    u32 framesSinceEntryEnd;
    s32 minusOne;
    BOOL falseValue;
    s32 zero;
    s32 isHumanGhostOrPeer;
    s32 humanGhostPeerFlag;
    u16 i;

    if (gRaceProgress->mRaceDone == 0) {
        return;
    }
    gRaceGoalS->mUnk_00a4 = 1;
    if (gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mUseTeams != 0) {
        gRaceGoalS->mUpdate = func_020c0f48;
        gRaceGoalS->mUpdateFrames = 0;
        RequestRaceHudSubScreenState5();
    } else {
        gRaceGoalS->mUpdate = SlideInRaceGoalS;
        gRaceGoalS->mUpdateFrames = 0;
    }
    minusOne = -1;
    falseValue = FALSE;
    zero = 0;
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        gRaceGoalS->mRowKartIndex[i] = i;
        if (gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE) {
            isHumanGhostOrPeer = falseValue;
            if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind <= 3 &&
                ((1 << gRaceSetup->mCurrentEntries[i].mPlayer.mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
                isHumanGhostOrPeer = 1;
            }
            humanGhostPeerFlag = isHumanGhostOrPeer != 0 ? 1 : zero;
            sortKeys[i] = humanGhostPeerFlag * 8 + 8 - GetKartRank(i);
            if (GetKartRank(i) == 1) {
                sortKeys[i] += 0x20;
            }
            sortKeys[i] = sortKeys[i] * minusOne;
        } else {
            sortKeys[i] = GetKartRank(i);
        }
    }
    SortIndicesByKey(gRaceGoalS->mRowKartIndex, sortKeys, gRaceSetup->mKartCount);
    if (gRaceSetup->mMode == MODE_VS || gRaceSetup->mMode == 5) {
        if (TryGetRaceUpdateFramesSinceEntryEnd(&framesSinceEntryEnd) != 0) {
            if (framesSinceEntryEnd >= 0xb4) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x46);
            }
        }
    }
}

void SlideInRaceGoalS(void) {
    s32 frame;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame < 0x14) {
        gRaceGoalS->mOffsetX = InterpolateS16(1, -0x100, 0, frame, 0x14);
    } else {
        gRaceGoalS->mOffsetX = 0;
        gRaceGoalS->mUpdate = func_020c1de4;
        gRaceGoalS->mUpdateFrames = 0;
    }
}

void func_020c1de4(void) {
    s32 frame;
    u16 keyABits;
    Unk02175628Index inputSlot;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame >= 0x5a) {
        gRaceGoalS->mUpdate = func_020c1bc0;
        gRaceGoalS->mUpdateFrames = 0;
    }
    inputSlot = UNK_02175628_INDEX_8;
    keyABits = data_02175628[inputSlot].mUnk_00 & PAD_KEY_A;
    if (keyABits != 0 && frame >= 0x2d) {
        gRaceGoalS->mUpdate = func_020c1bc0;
        gRaceGoalS->mUpdateFrames = 0;
    }
}

void func_020c1bc0(void) {
    s32 frame;
    u16 keyABits;
    u16 i;
    BOOL allReached;
    s32 target;
    u32 kartIndex;
    u32 courseIndex;
    Unk0217aa1c_00 *record;
    Unk02175628Index inputSlot;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame % 5 == 0) {
        allReached = TRUE;
        for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
            if (gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE) {
                kartIndex = GetLowByte(i);
                courseIndex = GetCourseIndexInCup();
                target = gCupRecords->mUnk_000[courseIndex][GetLowByte(kartIndex)].mUnk_05;
            } else {
                kartIndex = GetLowByte(i);
                courseIndex = GetCourseIndexInCup();
                record = &gCupRecords->mUnk_000[courseIndex][GetLowByte(kartIndex)];
                target = record->mUnk_00;
            }
            if (gRaceGoalS->mShownNumbers[i] < target) {
                if (gRaceGoalS->mShownNumbers[i] < 0x3e8) {
                    gRaceGoalS->mShownNumbers[i]++;
                    allReached = FALSE;
                }
            }
        }
        if (allReached != FALSE) {
            gRaceGoalS->mUpdate = func_020c195c;
            gRaceGoalS->mUpdateFrames = 0;
            gRaceGoalS->mUpdateFrames = 0;
            if (gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x29);
            }
        } else {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x29);
        }
    }
    inputSlot = UNK_02175628_INDEX_8;
    keyABits = data_02175628[inputSlot].mUnk_00 & PAD_KEY_A;
    if (keyABits != 0 && frame >= 0x2d) {
        gRaceGoalS->mUpdate = func_020c195c;
        gRaceGoalS->mUpdateFrames = 0;
    }
}

void func_020c195c(void) {
    s32 frame;
    u16 keyABits;
    u16 i;
    u32 kartIndex;
    u32 courseIndex;
    Unk0217aa1c_00 *record;
    Unk02175628Index inputSlot;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame < 0x5a) {
        for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
            if (gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE) {
                kartIndex = GetLowByte(i);
                courseIndex = GetCourseIndexInCup();
                gRaceGoalS->mShownNumbers[i] = gCupRecords->mUnk_000[courseIndex][GetLowByte(kartIndex)].mUnk_05;
            } else {
                kartIndex = GetLowByte(i);
                courseIndex = GetCourseIndexInCup();
                record = &gCupRecords->mUnk_000[courseIndex][GetLowByte(kartIndex)];
                gRaceGoalS->mShownNumbers[i] = record->mUnk_00;
            }
        }
    } else {
        if (gRaceSetup->mUseTeams != 0) {
            gRaceGoalS->mUpdate = func_020c0fd0;
            gRaceGoalS->mUpdateFrames = 0;
        } else if (gRaceSetup->mCourseNumber == 1) {
            gRaceGoalS->mUpdate = func_020c13e8;
            gRaceGoalS->mUpdateFrames = 0;
        } else {
            gRaceGoalS->mUpdate = func_020c1728;
            gRaceGoalS->mUpdateFrames = 0;
        }
    }
    inputSlot = UNK_02175628_INDEX_8;
    keyABits = data_02175628[inputSlot].mUnk_00 & PAD_KEY_A;
    if (keyABits != 0 && frame >= 0x2d) {
        if (gRaceSetup->mUseTeams != 0) {
            gRaceGoalS->mUpdate = func_020c0fd0;
            gRaceGoalS->mUpdateFrames = 0;
        } else if (gRaceSetup->mCourseNumber == 1) {
            gRaceGoalS->mUpdate = func_020c13e8;
            gRaceGoalS->mUpdateFrames = 0;
        } else {
            gRaceGoalS->mUpdate = func_020c1728;
            gRaceGoalS->mUpdateFrames = 0;
        }
    }
}

void func_020c1728(void) {
    s32 frame;
    s32 hiddenRows;
    u16 keyABits;
    u16 j;
    Unk02175628Index inputSlot;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame < 0x2d) {
        hiddenRows = gRaceGoalS->mHiddenRowCount;
        if (hiddenRows < gRaceSetup->mKartCount) {
            if (frame % 5 == 0) {
                switch (hiddenRows) {
                    case 0:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x32);
                        break;
                    case 1:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x33);
                        break;
                    case 2:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x34);
                        break;
                    case 3:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x35);
                        break;
                    case 4:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x36);
                        break;
                    case 5:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x37);
                        break;
                    case 6:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x38);
                        break;
                    case 7:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x39);
                        break;
                }
                gRaceGoalS->mRowVisible[gRaceGoalS->mHiddenRowCount++] = 0;
            }
        }
    } else {
        func_020c1060();
        gRaceGoalS->mUpdate = func_020c155c;
        gRaceGoalS->mUpdateFrames = 0;
    }
    inputSlot = UNK_02175628_INDEX_8;
    keyABits = data_02175628[inputSlot].mUnk_00 & PAD_KEY_A;
    if (keyABits != 0 && frame >= 0x2d) {
        for (j = 0; j < (u32) gRaceSetup->mKartCount; j++) {
            gRaceGoalS->mRowVisible[j] = 0;
        }
        gRaceGoalS->mHiddenRowCount = gRaceSetup->mKartCount;
        func_020c1060();
        gRaceGoalS->mUpdate = func_020c155c;
        gRaceGoalS->mUpdateFrames = 0;
    }
}

void func_020c155c(void) {
    s32 frame;
    s32 hiddenRows;
    u16 keyABits;
    Unk02175628Index inputSlot;

    frame = gRaceGoalS->mUpdateFrames++;
    hiddenRows = gRaceGoalS->mHiddenRowCount;
    if (hiddenRows > 0) {
        if (frame % 5 == 0) {
            gRaceGoalS->mHiddenRowCount = hiddenRows - 1;
            gRaceGoalS->mRowVisible[gRaceGoalS->mHiddenRowCount] = 1;
            switch (gRaceGoalS->mHiddenRowCount) {
                case 0:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2a);
                    break;
                case 1:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2b);
                    break;
                case 2:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2c);
                    break;
                case 3:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2d);
                    break;
                case 4:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2e);
                    break;
                case 5:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2f);
                    break;
                case 6:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x30);
                    break;
                case 7:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x31);
                    break;
            }
        }
    } else {
        gRaceGoalS->mUpdate = func_020c13e8;
        gRaceGoalS->mUpdateFrames = 0;
    }
    inputSlot = UNK_02175628_INDEX_8;
    keyABits = data_02175628[inputSlot].mUnk_00 & PAD_KEY_A;
    if (keyABits != 0 && frame >= 0x2d) {
        gRaceGoalS->mUpdate = func_020c13e8;
        gRaceGoalS->mUpdateFrames = 0;
    }
}

static inline Unk0217aa1c_144_00 *func_020c13e8_inline(s32 teamIndex) {
    return &gCupRecords->mUnk_144[GetCourseIndexInCup()].mUnk_00[teamIndex];
}

void func_020c13e8(void) {
    s32 frame;
    s32 i;
    s32 a;
    s32 teamOneValue;

    frame = gRaceGoalS->mUpdateFrames++;
    if (frame < 0x3c) {
        func_020c1060();
        for (i = 0; i < gRaceSetup->mKartCount; i++) {
            gRaceGoalS->mRowVisible[i] = 1;
        }
    } else {
        if (gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE) {
            if (gRaceSetup->mUseTeams != 0) {
                a = func_020c13e8_inline(0)->mUnk_02;
                teamOneValue = func_020c13e8_inline(1)->mUnk_02;
                if (a <= teamOneValue) {
                    a = teamOneValue;
                }
            } else {
                a = gRaceGoalS->mShownNumbers[gRaceGoalS->mRowKartIndex[0]];
            }
            gRaceGoalS->mUnk_00b4 = a >= gRaceSetup->mCourseCount;
        } else {
            gRaceGoalS->mUnk_00b4 = gRaceSetup->mCourseNumber >= gRaceSetup->mCourseCount;
        }
        gRaceGoalS->mUpdate = func_020c13d0;
        gRaceGoalS->mUpdateFrames = 0;
    }
}

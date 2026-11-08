#include "Main/Unknown/code_020bb5ec.h"
#include "Main/Unknown/code_02089ef4.h"

#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b837c.h"
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
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02089000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020bc108.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_0203c5f8.h"

u32 ClearRaceTimeDigitsPointer(void) {
    u32 address;
    u32 zero;
    address = (u32) &gRaceTimeDigits;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

void UpdateRaceTimeDigits(void) {
    u8 minute;
    u8 second;
    u16 millisecond;
    s32 i;
    s32 kartIndex;
    NNSSndSeqPlayer **entryHandle;

    if (GetRaceHudSubScreenState() == 6) {
        return;
    }
    if (func_020b1a20() != 0) {
        kartIndex = GetFollowedKartOrEntryIndex();
        GetKartLapTime(kartIndex, GetFollowedKartLastEndedLap(), &minute, &second, &millisecond);
    } else {
        if (gRaceSetup->mMode != MODE_BATTLE && IsKartEnded(GetFollowedKartOrEntryIndex()) != 0) {
            GetKartFinishTime(GetFollowedKartOrEntryIndex(), &minute, &second, &millisecond);
        } else {
            GetRaceClockTime(&minute, &second, &millisecond);
        }
    }
    SplitTimeDigits(minute, second, millisecond, &gRaceTimeDigits->mTime);
    if (gRaceTimeDigits->mUseLastSecondsSound == FALSE) {
        return;
    }
    if (minute == 0 && second > 6) {
        for (i = 0; i < 6; i++) {
            gRaceTimeDigits->mLastSecondsReached[i] = 0;
        }
        return;
    }
    if (minute == 0 && ((second == 5 && millisecond == 0) || second < 5) &&
        gRaceTimeDigits->mLastSecondsReached[0] == 0) {
        if (gRaceProgress->mUnk_000[GetFollowedKartOrEntryIndex()].mStatus != 2) {
            SetStemSet(2);
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
                NNS_SndArcPlayerStartSeqArc(entryHandle, 0, 0x49);
            }
        }

        gRaceTimeDigits->mLastSecondsReached[0] = 1;
        return;
    }
    if (minute == 0 && ((second == 4 && millisecond == 0) || second < 4) &&
        gRaceTimeDigits->mLastSecondsReached[1] == 0) {
        if ((data_0217c780 & 1) != 0) {
            entryHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                NNS_SndArcPlayerStartSeqArc(entryHandle, 0, 0x49);
            }
        }

        gRaceTimeDigits->mLastSecondsReached[1] = 1;
        return;
    }
    if (minute == 0 && ((second == 3 && millisecond == 0) || second < 3) &&
        gRaceTimeDigits->mLastSecondsReached[2] == 0) {
        if ((data_0217c780 & 1) != 0) {
            entryHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                NNS_SndArcPlayerStartSeqArc(entryHandle, 0, 0x49);
            }
        }

        gRaceTimeDigits->mLastSecondsReached[2] = 1;
        return;
    }
    if (minute == 0 && ((second == 2 && millisecond == 0) || second < 2) &&
        gRaceTimeDigits->mLastSecondsReached[3] == 0) {
        if ((data_0217c780 & 1) != 0) {
            entryHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                NNS_SndArcPlayerStartSeqArc(entryHandle, 0, 0x49);
            }
        }

        gRaceTimeDigits->mLastSecondsReached[3] = 1;
        return;
    }
    if (minute == 0 && ((second == 1 && millisecond == 0) || second < 1) &&
        gRaceTimeDigits->mLastSecondsReached[4] == 0) {
        if ((data_0217c780 & 1) != 0) {
            entryHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                if (*entryHandle != NULL) {
                    NNS_SndPlayerStopSeq(entryHandle, 0);
                }
                NNS_SndArcPlayerStartSeqArc(entryHandle, 0, 0x49);
            }
        }

        gRaceTimeDigits->mLastSecondsReached[4] = 1;
        return;
    }
    if (minute == 0 && second == 0 && millisecond == 0) {
        if (gRaceTimeDigits->mLastSecondsReached[5] == 0) {
            gRaceTimeDigits->mLastSecondsReached[5] = 1;
        }
    }
}

void DrawRaceTimeDigits(RaceHudOamBuffer *oamBuffer) {
    s32 lapTimeFirstCellPos[2];
    s32 firstCellPos[2];
    s32 minuteTensPos[2];
    s32 minuteOnesPos[2];
    s32 afterMinutesPos[2];
    s32 secondTensPos[2];
    s32 secondOnesPos[2];
    s32 afterSecondsPos[2];
    s32 millisecondHundredsPos[2];
    s32 millisecondTensPos[2];
    s32 millisecondOnesPos[2];
    s32 cellXs[10] = {0xa6, 0xad, 0xb6, 0xbf, 0xc8, 0xd1, 0xda, 0xe3, 0xec, 0xf5};
    u32 hasLapTime;
    s32 cellOffset;
    s32 cycleFrame;
    s32 afterCellIndex;

    hasLapTime = func_020b1a20();
    cellOffset = 0;
    if (GetRaceHudSubScreenState() == 6) {
        return;
    }
    if (gRaceSetup->mRaceKind == 4) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    if (gRaceProgress->mUnk_000[GetFollowedKartOrEntryIndex()].mStatus == 3) {
        return;
    }
    if (hasLapTime != 0) {
        cycleFrame = (s32) func_020b1a0c() % 16;
        if (cycleFrame >= 4) {
            if (cycleFrame < 8) {
                cellOffset = 0xc;
            } else if (cycleFrame < 12) {
                cellOffset = 0x18;
            } else {
                cellOffset = 0xc;
            }
        }
    }
    if (hasLapTime != 0) {
        Unk020224e0_c *cell = GetRaceSNcerEntry(cellOffset + 0x27);
        lapTimeFirstCellPos[0] = cellXs[0] << 12;
        lapTimeFirstCellPos[1] = 0xc000;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                  lapTimeFirstCellPos, 0, 1);
    } else {
        Unk020224e0_c *cell = GetRaceSNcerEntry(0x26);
        firstCellPos[0] = cellXs[0] << 12;
        firstCellPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, firstCellPos, 0, 1);
    }
    if (gRaceTimeDigits->mTime.mDigits[0] != 0) {
        Unk020224e0_c *cell = GetRaceSNcerEntry(cellOffset + 0x28 + gRaceTimeDigits->mTime.mDigits[0]);
        minuteTensPos[0] = cellXs[1] << 12;
        minuteTensPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, minuteTensPos, 0, 1);
    }
    {
        Unk020224e0_c *cell = GetRaceSNcerEntry(cellOffset + 0x28 + gRaceTimeDigits->mTime.mDigits[1]);
        minuteOnesPos[0] = cellXs[2] << 12;
        minuteOnesPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, minuteOnesPos, 0, 1);
    }
    afterCellIndex = cellOffset + 0x32;
    {
        Unk020224e0_c *cell = GetRaceSNcerEntry(afterCellIndex);
        afterMinutesPos[0] = cellXs[3] << 12;
        afterMinutesPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, afterMinutesPos, 0, 1);
    }
    {
        Unk020224e0_c *cell = GetRaceSNcerEntry(cellOffset + 0x28 + gRaceTimeDigits->mTime.mDigits[2]);
        secondTensPos[0] = cellXs[4] << 12;
        secondTensPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, secondTensPos, 0, 1);
    }
    {
        Unk020224e0_c *cell = GetRaceSNcerEntry(cellOffset + 0x28 + gRaceTimeDigits->mTime.mDigits[3]);
        secondOnesPos[0] = cellXs[5] << 12;
        secondOnesPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, secondOnesPos, 0, 1);
    }
    {
        Unk020224e0_c *cell = GetRaceSNcerEntry(afterCellIndex);
        afterSecondsPos[0] = cellXs[6] << 12;
        afterSecondsPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount],
                                                      0x80 - oamBuffer->mOamCount, cell, NULL, afterSecondsPos, 0, 1);
    }
    {
        Unk020224e0_c *cell = GetRaceSNcerEntry(cellOffset + 0x28 + gRaceTimeDigits->mTime.mDigits[4]);
        millisecondHundredsPos[0] = cellXs[7] << 12;
        millisecondHundredsPos[1] = 0xc000;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL,
                                  millisecondHundredsPos, 0, 1);
    }
    {
        Unk020224e0_c *cell = GetRaceSNcerEntry(cellOffset + 0x28 + gRaceTimeDigits->mTime.mDigits[5]);
        millisecondTensPos[0] = cellXs[8] << 12;
        millisecondTensPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, millisecondTensPos, 0, 1);
    }
    {
        Unk020224e0_c *cell = GetRaceSNcerEntry(cellOffset + 0x28 + gRaceTimeDigits->mTime.mDigits[6]);
        millisecondOnesPos[0] = cellXs[9] << 12;
        millisecondOnesPos[1] = 0xc000;
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(
            &oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, NULL, millisecondOnesPos, 0, 1);
    }
}

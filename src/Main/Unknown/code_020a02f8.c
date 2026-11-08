#include "Main/Unknown/code_020a02f8.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02068000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10d4.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02156000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020a1728.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020a2204.h"
#include "Main/Unknown/code_020a2220.h"
#include "Main/Unknown/code_020a223c.h"
#include "Main/Unknown/code_020a228c.h"
#include "Main/Unknown/code_020a22ac.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_0203ca38.h"
#include "Main/Unknown/code_02077bc0.h"

void SetStandingsKartBalloons(KartBalloons *kartBalloons) {
    gStandings->mKartBalloons = kartBalloons;
}

KartBalloons *GetStandingsKartBalloons(void) {
    return gStandings->mKartBalloons;
}

void SetStandingsKartHitByKartCallback(s32 (*callback)(s32, s32)) {
    gStandings->mKartHitByKartCallback = callback;
}

void SetStandingsKartsHitEachOtherCallback(void (*callback)(s32, s32)) {
    gStandings->mKartsHitEachOtherCallback = callback;
}

void SetStandingsKartHitCallback(s32 (*callback)(u16 a, u16 b)) {
    gStandings->mKartHitCallback = callback;
}

// Stores the kart-eliminated callback.
void SetStandingsKartEliminatedCallback(void (*callback)(u16 a)) {
    gStandings->mKartEliminatedCallback = callback;
}

// Stores the end callback.
void SetStandingsEndCallback(void (*callback)(void)) {
    gStandings->mEndCallback = callback;
}

void SetStandingsKartOffsetCallback(void (*callback)(s32, s32)) {
    gStandings->mKartOffsetCallback = callback;
}

void func_020a22ac(u16 kartIndex) {
    if (IsRaceStarted() != 1) {
        return;
    }
    if (func_01ffc67c(GetKart(kartIndex)) != FALSE) {
        return;
    }
    gStandings->mKarts[kartIndex].mUnk_64 = 10;
}

void func_020a228c(int kartIndex) {
    gStandings->mKarts[kartIndex].mUnk_64 = 0xffffffff;
}

s32 func_020a2264(u16 kartIndex) {
    if (gStandings->mWinnerTeamId >= 0) {
        return -1;
    }
    return gStandings->mKarts[kartIndex].mUnk_64;
}

s32 func_020a223c(u16 kartIndex) {
    if (gStandings->mWinnerTeamId >= 0) {
        return -1;
    }
    return gStandings->mKarts[kartIndex].mUnk_68;
}

void SetKartInflatingBalloon(u16 kartIndex, u32 inflating) {
    gStandings->mKarts[kartIndex].mInflatingBalloon = inflating;
}

u32 IsKartInflatingBalloon(u16 kartIndex) {
    return gStandings->mKarts[kartIndex].mInflatingBalloon;
}

void CallStandingsKartOffsetCallback(s32 a, s32 b) {
    if (b == 0) {
        return;
    }
    if (gStandings->mKartOffsetCallback != NULL) {
        gStandings->mKartOffsetCallback(a, b);
    }
}

s32 CallKartCollisionCallbacks(s32 firstKartIndex, s32 secondKartIndex) {
    Kart *firstKart;
    Kart *secondKart;
    KartStanding *firstStanding;
    KartStanding *secondStanding;
    BOOL f5;
    s32 f4;
    BOOL f11;
    BOOL t;

    if (gStandings->mWinnerTeamId >= 0) {
        return 0;
    }
    firstKart = GetKart(firstKartIndex);
    secondKart = GetKart(secondKartIndex);
    secondStanding = &gStandings->mKarts[secondKartIndex];
    firstStanding = &gStandings->mKarts[firstKartIndex];
    f5 = FALSE;
    if (secondStanding->mUnk_24[firstKartIndex] == 0) {
        if ((firstKart->mUnk_48 & 0x100000) != 0) {
            f5 = TRUE;
        }
    }
    f4 = 0;
    if (firstStanding->mUnk_24[secondKartIndex] == 0) {
        if ((secondKart->mUnk_48 & 0x100000) != 0) {
            f4 = 1;
        }
    }
    f11 = TRUE;
    if ((firstKart->mUnk_4c & 0x400000) == 0) {
        if (GetKartItemEffect(firstKartIndex) != 1) {
            f11 = FALSE;
        }
    }
    t = TRUE;
    if ((secondKart->mUnk_4c & 0x400000) == 0) {
        if (GetKartItemEffect(secondKartIndex) != 1) {
            t = FALSE;
        }
    }
    if (f4 != 0) {
        firstStanding->mUnk_24[secondKartIndex] = 1;
    }
    if (f5 != FALSE) {
        secondStanding->mUnk_24[firstKartIndex] = 1;
    }
    if (f11 == FALSE && t == FALSE && f5 != FALSE && f4 != 0) {
        if (gStandings->mKartsHitEachOtherCallback != NULL) {
            gStandings->mKartsHitEachOtherCallback(firstKartIndex, secondKartIndex);
            return 1;
        }
    } else if (f11 == FALSE && f4 != 0) {
        f4 = 0;
        if (GetKartItemEffect(secondKartIndex) == 1) {
            firstStanding->mUnk_20 = TRUE;
            if (gStandings->mKartHitByKartCallback != NULL) {
                f4 = gStandings->mKartHitByKartCallback(firstKartIndex, secondKartIndex);
                if ((firstKart->mUnk_4c & 0x400000) == 0) {
                    func_0206c17c(firstKart);
                }
            }
        } else if (gStandings->mKartHitByKartCallback != NULL) {
            f4 = gStandings->mKartHitByKartCallback(firstKartIndex, secondKartIndex);
            if ((firstKart->mUnk_4c & 0x400000) == 0) {
                func_0206c17c(firstKart);
            }
        }
        return f4;
    } else if (t == FALSE && f5 != FALSE) {
        f4 = 0;
        if (GetKartItemEffect(firstKartIndex) == 1) {
            secondStanding->mUnk_20 = TRUE;
            if (gStandings->mKartHitByKartCallback != NULL) {
                f4 = gStandings->mKartHitByKartCallback(secondKartIndex, firstKartIndex);
                if ((secondKart->mUnk_4c & 0x400000) == 0) {
                    func_0206c17c(secondKart);
                }
            }
        } else if (gStandings->mKartHitByKartCallback != NULL) {
            f4 = gStandings->mKartHitByKartCallback(secondKartIndex, firstKartIndex);
            if ((secondKart->mUnk_4c & 0x400000) == 0) {
                func_0206c17c(secondKart);
            }
        }
        return f4;
    }
    return 0;
}

void SetKartHitByKartIndexFromItem(s32 kartIndex, ItemObject *itemObject) {
    u16 v;

    if (gStandings->mWinnerTeamId >= 0) {
        return;
    }
    if (GetKart(kartIndex)->mState == KART_STATE_NORMAL) {
        return;
    }
    if (itemObject->mKind != 0 && itemObject->mKind != 1 && itemObject->mKind != 9) {
        return;
    }
    v = itemObject->mUnk_78;
    if ((v & 0x8000) != 0) {
        return;
    }
    gStandings->mKarts[kartIndex].mHitByKartIndex = v & ~0xff00;
}

u32 func_020a1e3c(u32 value) {
    return value;
}

void func_020a1ddc(s32 kartIndex) {
    s32 i;
    s32 kartCount;

    kartCount = gRaceSetup->mKartCount;
    for (i = 0; i < kartCount; i++) {
        gStandings->mKarts[i].mUnk_24[kartIndex] = 0;
    }
}

static inline u16 func_020a1790_inline(Standings *standings, s32 rankIndex) {
    s32 j;

    for (j = 0; j < 8; j++) {
        if ((u16) rankIndex == standings->mKarts[j].mRankIndex) {
            return j;
        }
    }
    return 0;
}

u16 GetBattleItemRank(s32 kartIndex) {
    s32 rank;
    s32 i;
    s32 highestCount;

    if (gRaceSetup->mMode == MODE_BATTLE) {
        if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
            rank = 3 - gStandings->mKarts[kartIndex].mBalloonOrShineCount;
            rank += 1;
        } else if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            highestCount = 1;
            for (i = 0; i < gRaceSetup->mKartCount; i++) {
                if (gStandings->mKarts[i].mBalloonOrShineCount > highestCount) {
                    highestCount = gStandings->mKarts[i].mBalloonOrShineCount;
                }
            }
            rank = (highestCount + 1 - gStandings->mKarts[kartIndex].mBalloonOrShineCount) / 2 + 1;
        } else {
            rank = kartIndex;
        }
    } else {
        rank = 3 - gStandings->mKarts[kartIndex].mBalloonOrShineCount;
        rank += 1;
    }
    if (rank < 1) {
        rank = 1;
    } else if (rank > 3) {
        rank = 3;
    }
    return rank;
}

void MoveKartTowardFirstRank(u16 kartIndex) {
    s32 i;
    s32 j;
    s32 kartCount;
    s32 count;
    KartStanding *ownStanding;
    u16 otherRankIndex;
    u16 ownRankIndex;
    KartStanding *otherStanding;

    for (i = gStandings->mKarts[kartIndex].mRankIndex - 1; i >= 0; i--) {
        otherStanding = &gStandings->mKarts[func_020a1790_inline(gStandings, i)];
        otherRankIndex = otherStanding->mRankIndex;
        ownRankIndex = gStandings->mKarts[kartIndex].mRankIndex;
        ownStanding = &gStandings->mKarts[kartIndex];
        if (ownRankIndex > otherRankIndex) {
            if (ownStanding->mBalloonOrShineCount > otherStanding->mBalloonOrShineCount ||
                (ownStanding->mEliminationStatus == 0 && otherStanding->mEliminationStatus != 0)) {
                otherStanding->mRankIndex = ownRankIndex;
                gStandings->mKarts[kartIndex].mRankIndex = otherRankIndex;
            }
        }
    }
    kartCount = gRaceSetup->mKartCount;
    gStandings->mLowestBalloonOrShineCount = 0xffff;
    gStandings->mHighestBalloonOrShineCount = 0;
    for (j = 0; j < kartCount; j++) {
        count = gStandings->mKarts[j].mBalloonOrShineCount;
        gStandings->mLowestBalloonOrShineCount = (count < gStandings->mLowestBalloonOrShineCount && count >= 0)
                                                     ? count
                                                     : gStandings->mLowestBalloonOrShineCount;
        count = gStandings->mKarts[j].mBalloonOrShineCount;
        gStandings->mHighestBalloonOrShineCount =
            (count > gStandings->mHighestBalloonOrShineCount) ? count : gStandings->mHighestBalloonOrShineCount;
    }
}

void MoveKartTowardLastRank(u16 kartIndex) {
    s32 i;
    s32 j;
    s32 kartCount;
    s32 count;
    KartStanding *ownStanding;
    u16 otherRankIndex;
    u16 ownRankIndex;
    KartStanding *otherStanding;

    for (i = gStandings->mKarts[kartIndex].mRankIndex + 1; i < 8; i++) {
        otherStanding = &gStandings->mKarts[func_020a1790_inline(gStandings, i)];
        otherRankIndex = otherStanding->mRankIndex;
        ownRankIndex = gStandings->mKarts[kartIndex].mRankIndex;
        ownStanding = &gStandings->mKarts[kartIndex];
        if (ownRankIndex < otherRankIndex) {
            if (ownStanding->mBalloonOrShineCount < otherStanding->mBalloonOrShineCount ||
                (ownStanding->mEliminationStatus != 0 && otherStanding->mEliminationStatus == 0)) {
                otherStanding->mRankIndex = ownRankIndex;
                gStandings->mKarts[kartIndex].mRankIndex = otherRankIndex;
            }
        }
    }
    kartCount = gRaceSetup->mKartCount;
    gStandings->mLowestBalloonOrShineCount = 0xffff;
    gStandings->mHighestBalloonOrShineCount = 0;
    for (j = 0; j < kartCount; j++) {
        count = gStandings->mKarts[j].mBalloonOrShineCount;
        gStandings->mLowestBalloonOrShineCount = (count < gStandings->mLowestBalloonOrShineCount && count >= 0)
                                                     ? count
                                                     : gStandings->mLowestBalloonOrShineCount;
        count = gStandings->mKarts[j].mBalloonOrShineCount;
        gStandings->mHighestBalloonOrShineCount =
            (count > gStandings->mHighestBalloonOrShineCount) ? count : gStandings->mHighestBalloonOrShineCount;
    }
}

// Takes one kart out of play: runs the kart-eliminated callback, sets its status to 1, in mode 2 sets its count to -1,
// re-sorts the ranks and starts the mode's out handling of the kart (mode 2: a kart handler call; mode 4: two bits in
// the kart's words).
void EliminateKart(u16 kartIndex) {
    Kart *kart;

    if (gStandings->mKartEliminatedCallback != NULL) {
        gStandings->mKartEliminatedCallback(kartIndex);
    }
    gStandings->mKarts[kartIndex].mEliminationStatus = 1;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        gStandings->mKarts[kartIndex].mBalloonOrShineCount = -1;
        gStandings->mKarts[kartIndex].mBalloonsLeftToMake = 0;
    }
    if ((u32) kartIndex >= gRaceSetup->mKartCount) {
        return;
    }
    MoveKartTowardLastRank(kartIndex);
    if (gRaceSetup->mMode == MODE_BATTLE) {
        func_02068b5c(GetKart(kartIndex));
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        kart = GetKart(kartIndex);
        kart->mUnk_48 |= 0x2000;
        kart->mUnk_7c |= 8;
    }
}

void SetWinnerIfOneTeamLeft(void) {
    s32 kartCount;
    s32 teamId;
    s32 i;
    s32 j;
    s32 entryIndex;
    s32 k;
    u16 firstRankKartIndex;
    Standings *standings;
    KartStanding *kartStanding;
    Kart *kart;

    kartCount = gRaceSetup->mKartCount;
    standings = gStandings;
    for (k = 0; k < 8; k++) {
        if (standings->mKarts[k].mRankIndex == 0) {
            firstRankKartIndex = k;
            goto found;
        }
    }
    firstRankKartIndex = 0;
found:
    teamId = standings->mKarts[firstRankKartIndex].mTeamId;
    kartStanding = standings->mKarts;
    for (j = 0; j < 8; j++, kartStanding++) {
        if (kartStanding->mEliminationStatus == 0) {
            if (teamId != kartStanding->mTeamId) {
                return;
            }
        }
    }
    for (i = 0; i < kartCount; i++) {
        kart = GetKart((u16) i);
        kart->mUnk_48 |= 0x2000;
        kart->mUnk_7c |= 8;
    }
    gStandings->mWinnerTeamId = teamId;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4a);
        }
        gStandings->mEndTimer = 0x5a;
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        entryIndex = gRaceSetup->mEntryIndex;
        if (gStandings->mWinnerTeamId == entryIndex) {
            FinishMissionRunKartWithEndKind0(entryIndex);
        } else {
            FinishRaceProgressKartWithEndKind4(entryIndex);
        }
        gStandings->mEndTimer = 0;
    }
}

void CallKartHitCallbackForSelf(u16 kartIndex) {
    KartStanding *kartStanding;

    kartStanding = &gStandings->mKarts[kartIndex];
    kartStanding->mUnk_1c = -2;
    kartStanding->mUnk_18 = -2;
    kartStanding->mHitByKartIndex = kartIndex;
    gStandings->mKartHitCallback(kartIndex, kartIndex);
}

void ClearStandingEliminationStatus(int kartIndex) {
    gStandings->mKarts[kartIndex].mEliminationStatus = 0;
}

static inline u16 func_020a12b8_inline(s32 rankIndex) {
    s32 j;

    for (j = 0; j < 8; j++) {
        if ((u16) rankIndex == gStandings->mKarts[j].mRankIndex) {
            return j;
        }
    }
    return 0;
}

void EliminateKartAndCheckWinner(u16 kartIndex) {
    if (gStandings->mWinnerTeamId >= 0) {
        return;
    }
    if (gStandings->mKarts[kartIndex].mEliminationStatus != 0) {
        return;
    }
    EliminateKart(kartIndex);
    SetWinnerIfOneTeamLeft();
}

u16 func_020a1520(void) {
    NNSSndSeqPlayer **seqPlayerHandle;
    s32 v;
    u16 kartIndex;
    s32 i;
    s32 m;
    s32 kartCount;
    s32 lowestCount;

    if (gStandings->mWinnerTeamId >= 0) {
        return 0;
    }
    v = gStandings->mUnk_3a4 + 1;
    if (v >= 3) {
        v = 3;
    }
    gStandings->mUnk_3a4 = v;
    gStandings->mUnk_3a2 = data_021565f0[gStandings->mUnk_3a4];
    lowestCount = gStandings->mLowestBalloonOrShineCount;
    if (lowestCount != gStandings->mHighestBalloonOrShineCount) {
        kartCount = gRaceSetup->mKartCount;
        for (m = 0; m <= lowestCount; m++) {
            for (i = kartCount - 1; i >= 0; i--) {
                kartIndex = func_020a12b8_inline(i);
                if (m == gStandings->mKarts[kartIndex].mBalloonOrShineCount) {
                    EliminateKart(kartIndex);
                }
            }
            SetWinnerIfOneTeamLeft();
            if (gStandings->mWinnerTeamId >= 0) {
                return 0;
            }
        }
    }
    if (data_0217c780 & 1) {
        seqPlayerHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
        if (data_0217d084.mUnk_0c != 0) {
            if (seqPlayerHandle[0] != NULL) {
                NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
            }
            if (seqPlayerHandle[0] != NULL) {
                NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArc(seqPlayerHandle, 0, 0x4b);
        }
    }
    return gStandings->mUnk_3a2;
}

void EliminateKartsUntilWinnerDecided(void) {
    s32 kartCount;
    s32 i;
    u16 kartIndex;
    s32 randomKartIndex;
    u16 randomLimit;
    RandomState64 *randomState;

    if (gStandings->mWinnerTeamId >= 0) {
        return;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        kartCount = gRaceSetup->mKartCount;
        if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
            if (gStandings->mWinnerTeamId >= 0) {
                return;
            }
            randomLimit = kartCount;
            do {
                randomState = &gRaceProgress->mRandom;
                if ((u16) kartCount == 0) {
                    randomKartIndex = 0;
                } else {
                    randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
                    if (randomLimit == 0) {
                        randomKartIndex = (u32) (randomState->mValue >> 32);
                    } else {
                        randomKartIndex = (u32) (((u64) (u32) (randomState->mValue >> 32) * (u64) randomLimit) >> 32);
                    }
                }
                kartIndex = randomKartIndex;
                if (gStandings->mKarts[kartIndex].mEliminationStatus == 0) {
                    EliminateKartAndCheckWinner(kartIndex);
                    gStandings->mKarts[kartIndex].mEliminationStatus = 2;
                }
            } while (gStandings->mWinnerTeamId < 0);
        } else if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            for (i = kartCount - 1; i >= 0; i--) {
                if (gStandings->mWinnerTeamId < 0) {
                    kartIndex = func_020a12b8_inline(i);
                    if (gStandings->mKarts[kartIndex].mEliminationStatus == 0) {
                        EliminateKartAndCheckWinner(kartIndex);
                        gStandings->mKarts[kartIndex].mEliminationStatus = 2;
                    }
                }
            }
        }
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        for (i = 7; i >= 0; i--) {
            kartIndex = func_020a12b8_inline(i);
            if (kartIndex != gRaceSetup->mEntryIndex && gStandings->mWinnerTeamId < 0) {
                EliminateKartAndCheckWinner(kartIndex);
            }
        }
    }
}

u32 IsWinnerDecidedAndEndReached(void) {
    u32 result = 0u;
    if (gStandings->mWinnerTeamId < 0) {
        return result;
    }
    if (gStandings->mEndTimer < 0) {
        result = 1u;
    }
    return result;
}

// TRUE when mWinnerTeamId is not negative.
BOOL IsWinnerDecided(void) {
    if (gStandings->mWinnerTeamId >= 0) {
        return TRUE;
    }
    return FALSE;
}

// Returns the kart's mRankIndex.
u16 GetKartStandingRankIndex(int kartIndex) {
    return gStandings->mKarts[kartIndex].mRankIndex;
}

// Returns mShineCount.
u32 GetShineCount(void) {
    return (gStandings->mShineCount);
}

// Adds its argument to mShineCount (+1 when a shine is placed, -1 when one is finished).
void AddShineCount(short amount) {
    Standings *standings;
    standings = gStandings;
    standings->mShineCount = standings->mShineCount + amount;
}

u16 GetTotalBalloonOrShineCount(void) {
    s32 i;
    s32 total;
    s32 kartCount;
    s32 count;

    total = 0;
    kartCount = gRaceSetup->mKartCount;
    for (i = 0; i < kartCount; i++) {
        count = gStandings->mKarts[(u16) i].mBalloonOrShineCount;
        if (count <= 0) {
            count = 0;
        }
        total += (u16) count;
    }
    return total;
}

u16 GetHighestBalloonOrShineCount(void) {
    return gStandings->mHighestBalloonOrShineCount;
}

// Returns the kart's count, 0 when it is negative.
u16 GetBalloonOrShineCount(u16 kartIndex) {
    s32 count;

    count = gStandings->mKarts[kartIndex].mBalloonOrShineCount;
    if (count <= 0) {
        count = 0;
    }
    return count;
}

void AddBalloonOrShineCountAndMoveRank(u16 kartIndex, s32 amount) {
    gStandings->mKarts[kartIndex].mBalloonOrShineCount += amount;
    if (amount > 0) {
        MoveKartTowardFirstRank(kartIndex);
    } else if (amount < 0) {
        MoveKartTowardLastRank(kartIndex);
    }
}

u16 GetBalloonsLeftToMake(u16 kartIndex) {
    return gStandings->mKarts[kartIndex].mBalloonsLeftToMake;
}

void AddBalloonsLeftToMake(u16 kartIndex, s32 amount) {
    gStandings->mKarts[kartIndex].mBalloonsLeftToMake += amount;
}

// TRUE when the kart's elimination status is not 0.
BOOL IsKartEliminated(int kartIndex) {
    if (gStandings->mKarts[kartIndex].mEliminationStatus != 0) {
        return TRUE;
    }
    return FALSE;
}

// TRUE when the kart has the lowest balloon or shine count (ties count) and not every kart has it.
BOOL IsKartLastByBalloonOrShineCount(u16 kartIndex) {
    Standings *standings;
    BOOL result;
    s32 count;

    standings = gStandings;
    result = FALSE;
    count = standings->mKarts[kartIndex].mBalloonOrShineCount;
    if (standings->mLowestBalloonOrShineCount == count) {
        if (standings->mHighestBalloonOrShineCount != count) {
            result = TRUE;
        }
    }
    return result;
}

BOOL IsKartOnWinningTeamAtEnd(s32 kartIndex) {
    KartStanding *kartStanding;
    BOOL result;

    kartStanding = &gStandings->mKarts[kartIndex];
    result = FALSE;
    if (gStandings->mWinnerTeamId == kartStanding->mTeamId) {
        if (gStandings->mEndTimer < 0) {
            result = TRUE;
        }
    }
    return result;
}

// Returns the address of the kart's saved position (mKarts[i].mPos), not its rank.
Vec3 *GetKartStandingPos(int kartIndex) {
    return &gStandings->mKarts[kartIndex].mPos;
}

CourseMapPoint *MoveToRandomForwardBattlePoint(void) {
    RandomState64 *randomState;
    u16 pointStep;
    s32 pointIndex;

    randomState = &gRaceProgress->mRandom;
    randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
    pointStep = (u16) (((u64) (u32) (randomState->mValue >> 32) * 5) >> 32) + 1;
    pointIndex = gStandings->mUnk_3b8 + pointStep;
    if (pointIndex >= gCourseMap->mBattlePointCount) {
        pointIndex = 0;
    }
    gStandings->mUnk_3b8 = pointIndex;
    return &gCourseMap->mBattlePoints[gStandings->mUnk_3b8];
}

// Allocates the Standings object and fills every entry (rank = own index, side id, status, count; the real karts first,
// then the unused slots) and sets the winner to -1. Called from InitRace in modes 2 and 4.
void InitStandings(void) {
    s32 i;
    KartStanding *kartStanding;

    gStandings = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x3c0);
    for (i = 0; i < 8; i++) {
        kartStanding = &gStandings->mKarts[i];
        kartStanding->mUnk_1c = -2;
        kartStanding->mUnk_18 = -2;
        kartStanding->mHitByKartIndex = i;
        kartStanding->mRankIndex = i;
        if (i < gRaceSetup->mKartCount) {
            switch (gRaceSetup->mCurrentEntries[(u16) i].mPlayer.mTeamIndex) {
                case 0:
                    kartStanding->mTeamId = 1;
                    break;
                case 1:
                    kartStanding->mTeamId = 3;
                    break;
                default:
                    kartStanding->mTeamId = i;
                    break;
            }
            kartStanding->mEliminationStatus = 0;
            kartStanding->mBalloonOrShineCount = 0;
            kartStanding->mBalloonsLeftToMake = 0;
        } else {
            kartStanding->mEliminationStatus = 2;
            kartStanding->mBalloonOrShineCount = -1;
            kartStanding->mBalloonsLeftToMake = 0;
            kartStanding->mTeamId = gRaceSetup->mKartCount;
        }
    }
    gStandings->mWinnerTeamId = -1;
}

void FinishStandings(void) {
    gStandings->mEndTimer = -1;
    if (gStandings->mEndCallback != NULL) {
        gStandings->mEndCallback();
    }
}

void UpdateStandings(void) {
    Kart *kart;
    BOOL a;
    BOOL b;
    s32 v;
    u32 f;
    s32 i;
    s32 kartCount;
    KartStanding *kartStanding = gStandings->mKarts;

    kartCount = gRaceSetup->mKartCount;
    if (gStandings->mWinnerTeamId >= 0) {
        if (gStandings->mEndTimer > 0) {
            gStandings->mEndTimer = gStandings->mEndTimer - 1;
            if (gStandings->mEndTimer <= 0) {
                gStandings->mEndTimer = -1;
                if (gStandings->mEndCallback != NULL) {
                    gStandings->mEndCallback();
                }
            }
        }
        for (i = 0; i < kartCount; i++) {
            if (gStandings->mKarts[i].mEliminationStatus == 1) {
                if (i != gRaceSetup->mEntryIndex) {
                    func_02068a00(GetKart((u16) i));
                }
                gStandings->mKarts[i].mEliminationStatus = 2;
            }
        }
        return;
    }
    for (i = kartCount - 1; i >= 0; i--) {
        kartStanding = &gStandings->mKarts[i];
        if (kartStanding->mEliminationStatus == 1) {
            func_02068a00(GetKart((u16) i));
            gStandings->mKarts[i].mEliminationStatus = 2;
        } else if (gStandings->mWinnerTeamId < 0 && kartStanding->mBalloonOrShineCount > 0) {
            kart = GetKart((u16) i);
            kartStanding = &gStandings->mKarts[i];
            v = kartStanding->mUnk_64 - 1;
            if (v <= 0) {
                v = 0;
            }
            kartStanding->mUnk_64 = v;
            gStandings->mKarts[i].mUnk_68 = -(gStandings->mKarts[i].mUnk_68 <= 0);
            if (func_01ffc67c(kart) != FALSE ||
                (u16) (data_02175628[kart->mEntryIndex].mBits & (PAD_KEY_A | PAD_KEY_B)) != 0) {
                gStandings->mKarts[i].mUnk_68 = -1;
                gStandings->mKarts[i].mUnk_64 = -1;
            } else if (IsRaceStarted() == 1) {
                if ((u16) (data_02175628[(u32) kart->mEntryIndex].mBits & 4) != 0) {
                    gStandings->mKarts[i].mUnk_68 = 1;
                } else if (data_02175628[kart->mEntryIndex].mUnk_5a != 0) {
                    gStandings->mKarts[i].mUnk_64 = 10;
                }
            }
            if (gStandings->mKartHitCallback != NULL) {
                b = TRUE;
                f = kart->mUnk_48;
                a = (f & 0x200) != 0;
                if (kart->mState == KART_STATE_NORMAL && (f & 0x4000000) == 0) {
                    b = FALSE;
                }
                if (kartStanding->mUnk_04 == FALSE && a != FALSE && (kart->mUnk_4c & 0x400000) == 0) {
                    kartStanding->mUnk_04 = TRUE;
                    kartStanding->mUnk_00 = FALSE;
                    kartStanding->mUnk_18 = -2;
                    kartStanding->mHitByKartIndex = i;
                    kartStanding->mUnk_20 = FALSE;
                    if (kartStanding->mBalloonOrShineCount <= 1) {
                        if ((gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) ||
                            gRaceSetup->mMode == MODE_MISSION_RUN) {
                            kart->mUnk_7c |= 0x20000000;
                            kart->mUnk_48 &= ~0x2000000;
                        }
                    }
                } else if (kartStanding->mUnk_04 == TRUE && (kart->mUnk_44 & 0x10000) != 0) {
                    kartStanding->mUnk_04 = FALSE;
                    kartStanding->mUnk_1c = 0;
                    if ((kart->mUnk_4c & 0x400000) == 0) {
                        func_0206c17c(kart);
                    }
                }
                if (kartStanding->mUnk_1c == 0) {
                    kartStanding->mUnk_1c = -2;
                    gStandings->mKartHitCallback(i, 8);
                    kartStanding->mHitByKartIndex = i;
                } else if (kartStanding->mUnk_1c >= 0) {
                    kartStanding->mUnk_1c = kartStanding->mUnk_1c + 1;
                }
                if (kartStanding->mUnk_00 == FALSE && b != FALSE && (kart->mUnk_4c & 0x400000) == 0) {
                    kartStanding->mUnk_00 = TRUE;
                    if (kartStanding->mBalloonOrShineCount <= 1) {
                        if ((gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) ||
                            gRaceSetup->mMode == MODE_MISSION_RUN) {
                            kart->mUnk_7c |= 0x20000000;
                        }
                    }
                } else if (kartStanding->mUnk_00 == TRUE && b == FALSE && (kart->mUnk_48 & 0x6052840) == 0) {
                    kartStanding->mUnk_00 = FALSE;
                    if (kartStanding->mUnk_20 == FALSE) {
                        kartStanding->mUnk_18 = 0;
                        if ((kart->mUnk_4c & 0x400000) == 0) {
                            func_0206c17c(kart);
                        }
                    } else {
                        kartStanding->mUnk_20 = FALSE;
                    }
                }
                if (kartStanding->mUnk_18 == 0) {
                    kartStanding->mUnk_18 = -2;
                    gStandings->mKartHitCallback(i, kartStanding->mHitByKartIndex);
                    kartStanding->mHitByKartIndex = i;
                } else if (kartStanding->mUnk_18 >= 0) {
                    kartStanding->mUnk_18 = kartStanding->mUnk_18 + 1;
                }
            }
            kartStanding->mPos = kart->mPos;
        }
    }
}

void func_020a089c(Unk020a0318 *mapObject) {
    s32 courseId;

    courseId = gRaceSetup->mCourseId;
    if (courseId == COURSE_ID_MANSION) {
        mapObject->mSoundId = 0x121;
    } else if (courseId == COURSE_ID_BEACH) {
        mapObject->mSoundId = 0x111;
        mapObject->mSecondSoundId = 0x10a;
    } else {
        mapObject->mSoundId = 0x20d;
    }
}

void func_020a066c(MapObjectList *mapObjectList) {
    s32 i;
    Unk020a0318 *mapObject;
    RandomState64 *randomState;

    if (mapObjectList == NULL) {
        return;
    }
    for (i = 0; i < mapObjectList->mMapObjectCount && (mapObject = mapObjectList->mMapObjects[i]) != NULL; i++) {
        if (gRaceSetup->mCourseId == COURSE_ID_MANSION) {
            mapObject->mRadius = 0xa28;
            mapObject->mCenterX = mapObject->mUnk_00.mPos.x + 0x73a000;
            mapObject->mCenterY = mapObject->mUnk_00.mPos.y;
            mapObject->mCenterZ = mapObject->mUnk_00.mPos.z - 0x1400000;
            mapObject->mDistanceLevelInverted = TRUE;
        } else if (gRaceSetup->mCourseId == COURSE_ID_BEACH) {
            mapObject->mRadius = 0x546;
            mapObject->mCenterX = mapObject->mUnk_00.mPos.x + 0x28a000;
            mapObject->mCenterY = mapObject->mUnk_00.mPos.y;
            mapObject->mCenterZ = mapObject->mUnk_00.mPos.z - 0x32000;
            mapObject->mDistanceLevelInverted = FALSE;
        } else {
            mapObject->mRadius = 0xa28;
            mapObject->mCenterX = mapObject->mUnk_00.mPos.x;
            mapObject->mCenterY = mapObject->mUnk_00.mPos.y;
            mapObject->mCenterZ = mapObject->mUnk_00.mPos.z;
            mapObject->mDistanceLevelInverted = FALSE;
        }
        randomState = &gRaceProgress->mLocalRandom;
        randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
        mapObject->mSoundTimer = (u16) (((u64) (u32) (randomState->mValue >> 32) * 0x3c) >> 32) + 0x258;
        mapObject->mDistanceVolumeFixed12 = 0x7f000;
        randomState = &gRaceProgress->mLocalRandom;
        randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
        mapObject->mDistanceLevelTimer = (u16) (((u64) (u32) (randomState->mValue >> 32) * 0xf) >> 32);
    }
}

void func_020a0318(void *mapObjectList, Unk020a0318 *mapObject) {
    Kart *kart;
    NNSSndSeqPlayer **sndHandleSlot;
    RandomState64 *randomState;
    Unk0210b7a8 slot8Request;
    Unk0210b7a8 slot9Request;
    s32 v;
    s32 halfRadius;
    s32 radius;
    s32 deltaZ;
    s32 deltaX;
    s64 distanceSquared;

    if (mapObject->mDistanceLevelTimer-- <= 0) {
        mapObject->mDistanceLevelTimer = 0xf;
        radius = mapObject->mRadius;
        halfRadius = radius / 2;
        kart = GetKart((u16) gRaceSetup->mEntryIndex);
        deltaX = kart->mPos.x - mapObject->mCenterX;
        deltaZ = kart->mPos.z - mapObject->mCenterZ;
        distanceSquared = (s64) deltaX * deltaX + (s64) deltaZ * deltaZ;
        if (distanceSquared < (s64) halfRadius * halfRadius) {
            v = 2;
        } else if (distanceSquared < (s64) (radius << 12) * (radius << 12)) {
            v = 1;
        } else {
            v = 0;
        }
        mapObject->mDistanceLevel = v;
        if (mapObject->mDistanceLevelInverted != FALSE) {
            mapObject->mDistanceLevel = mapObject->mDistanceLevel == 0;
        }
    }
    if (mapObject->mDistanceLevel > 1) {
        mapObject->mDistanceVolumeFixed12 = 0x7f001;
    } else if (mapObject->mDistanceLevel > 0) {
        mapObject->mDistanceVolumeFixed12 = mapObject->mDistanceVolumeFixed12 + 0x4000;
        if (mapObject->mDistanceVolumeFixed12 > 0x7f000) {
            mapObject->mDistanceVolumeFixed12 = 0x7f000;
        }
    } else {
        mapObject->mDistanceVolumeFixed12 = mapObject->mDistanceVolumeFixed12 - 0x4000;
        if (mapObject->mDistanceVolumeFixed12 < 0) {
            mapObject->mDistanceVolumeFixed12 = 0;
        }
    }
    if (mapObject->mSoundId != 0) {
        if (mapObject->mDistanceLevel != 0) {
            if (*GetSndHandleSlot(8) != NULL) {
                kart = GetKart((u16) gRaceSetup->mEntryIndex);
                mapObject->mUnk_a0 = mapObject->mUnk_a0 - (s32) (((s64) kart->mVelocityLengthRatio * 0x1000) >> 12);
                if (mapObject->mUnk_a0 < 0xc000) {
                    mapObject->mUnk_a0 = 0xc000;
                }
            } else if (mapObject->mSoundTimer-- <= 0) {
                sndHandleSlot = GetSndHandleSlot(8);
                slot8Request.mSoundId = mapObject->mSoundId;
                slot8Request.mPositionSource = NULL;
                slot8Request.mUnk_08 = 4;
                slot8Request.mDistanceSquared = GetHorizontalCameraDistanceSquared(NULL);
                func_0210b760(&slot8Request, sndHandleSlot);
                randomState = &gRaceProgress->mLocalRandom;
                randomState->mValue = randomState->mMultiplier * randomState->mValue + randomState->mIncrement;
                mapObject->mSoundTimer = (u16) (((u64) (u32) (randomState->mValue >> 32) * 0x3c) >> 32) + 0x78;
                mapObject->mUnk_a0 = 0x7f000;
            }
        } else if (mapObject->mSoundTimer > 0) {
            mapObject->mSoundTimer = mapObject->mSoundTimer - 1;
        }
        if (*GetSndHandleSlot(8) != NULL) {
            v = mapObject->mDistanceVolumeFixed12 < mapObject->mUnk_a0 ? mapObject->mDistanceVolumeFixed12
                                                                       : mapObject->mUnk_a0;
            SetSndHandleTrackVolume(GetSndHandleSlot(8), v >> 12);
        }
    }
    if (mapObject->mSecondSoundId == 0) {
        return;
    }
    if (mapObject->mDistanceLevel != 0) {
        if (*GetSndHandleSlot(9) == NULL) {
            sndHandleSlot = GetSndHandleSlot(9);
            slot9Request.mSoundId = mapObject->mSecondSoundId;
            slot9Request.mPositionSource = NULL;
            slot9Request.mUnk_08 = 4;
            slot9Request.mDistanceSquared = GetHorizontalCameraDistanceSquared(NULL);
            func_0210b760(&slot9Request, sndHandleSlot);
        }
    }
    if (*GetSndHandleSlot(9) == NULL) {
        return;
    }
    SetSndHandleTrackVolume(GetSndHandleSlot(9), mapObject->mDistanceVolumeFixed12 >> 12);
}

void *func_020a02f8(void) {
    return CreateMapObjectUpdateList(func_020a066c, func_020a0318, NULL);
}

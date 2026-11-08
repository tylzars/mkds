#include "Main/Unknown/code_0207b960.h"

#include "Main/Unknown/code_020435c4.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0207e64c.h"
#include "Main/Unknown/code_0207e654.h"
#include "Main/Unknown/code_0207fe70.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"

void func_0207d6a4(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi) {
    s32 turnSpeedLimit;
    s32 turnAngle;
    s32 limit;
    s32 x;

    if (GetRaceUpdateFramesMod8() == kartAi->mIndex) {
        raceSpeedLimit->mSpeedLimitAddition = 0;
        limit = kartAi->mKart->mSpeedLimitGoal;
        if (limit > 0xa000) {
            limit = 0xa000;
        }
        raceSpeedLimit->mTurnSpeedLimit = limit;
        turnAngle = kartAi->mTurnAngleDegrees;
        if (turnAngle > 0x5000) {
            x = ((s64) (turnAngle - 0x5000) * 0x5b) >> 12;
            if (x > 0x1000) {
                x = 0x1000;
            }
            x = ((s64) x * 0x668) >> 12;
            raceSpeedLimit->mTurnSpeedLimit = ((s64) (0x1000 - x) * 0xa000) >> 12;
        }
        turnSpeedLimit = raceSpeedLimit->mTurnSpeedLimit;
        if (turnSpeedLimit < limit) {
            limit = turnSpeedLimit;
        }
        if (limit > 0xa000) {
            limit = 0xa000;
        }
        raceSpeedLimit->mSpeedLimit = limit;
    }
    if (kartAi->mKart->mState != KART_STATE_NORMAL) {
        return;
    }
    if ((kartAi->mKart->mUnk_48 & 0x10000020) != 0) {
        return;
    }
    x = GetPointLinkSpeedRatio((PointLinkCursor *) &kartAi->mUnk_08.mUnk_00);
    kartAi->mKart->mSpeedLimitGoal = ((s64) raceSpeedLimit->mSpeedLimit * x + 0x800) >> 12;
}

void func_0207d5b8(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    timerRanOut = FALSE;
    itemUse->mHeldItemTimer--;
    if (itemUse->mHeldItemTimer <= 0) {
        itemUse->mHeldItemTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}

void UseItemAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    timerRanOut = FALSE;
    itemUse->mHeldItemTimer--;
    if (itemUse->mHeldItemTimer <= 0) {
        itemUse->mHeldItemTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}
void func_0207d474(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RaceSetup *raceSetup;
    u16 kartIndex;

    raceSetup = gRaceSetup;
    kartIndex = kartAi->mIndex;
    if ((raceSetup->mCurrentEntries[kartIndex].mPlayer.mUnk_14 & 1) != 0) {
        if (itemUse->mRandomValue <= 0xc00) {
            itemUse->mItemBitsEveryCall = 1;
            return;
        }
    }
    UseItemByTargetOrRankAfterHeld(itemUse, kartAi);
}
void func_0207d3ec(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RaceSetup *raceSetup;
    u16 kartIndex;

    raceSetup = gRaceSetup;
    kartIndex = kartAi->mIndex;
    if ((raceSetup->mCurrentEntries[kartIndex].mPlayer.mUnk_14 & 1) != 0) {
        if (itemUse->mRandomValue <= 0x400) {
            itemUse->mItemBitsEveryCall = 1;
            return;
        }
    }
    {
        BOOL timerRanOut;

        timerRanOut = FALSE;
        itemUse->mHeldItemTimer--;
        if (itemUse->mHeldItemTimer <= 0) {
            itemUse->mHeldItemTimer = 0;
            timerRanOut = TRUE;
        }
        if (timerRanOut == FALSE) {
            return;
        }
    }
    RequestItemBitsByKartRank(itemUse, kartAi);
}

void UseItemByTargetOrRankAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;

    timerRanOut = FALSE;
    itemUse->mHeldItemTimer--;
    if (itemUse->mHeldItemTimer <= 0) {
        itemUse->mHeldItemTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    UseItemByTargetOrRank(itemUse, kartAi);
}

void UseItemByRankAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;

    timerRanOut = FALSE;
    itemUse->mHeldItemTimer--;
    if (itemUse->mHeldItemTimer <= 0) {
        itemUse->mHeldItemTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    RequestItemBitsByKartRank(itemUse, kartAi);
}
void UseItemByTargetOrRank(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    if (IsTargetKartSet(kartAi) != FALSE) {
        if (GetTargetAhead(kartAi) != 0) {
            RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
            itemUse->mThrowForwardPending = 1;
            itemUse->mThrowForwardTimer = 2;
            itemUse->mItemBitsEveryCall = 0;
            if (itemUse->mItemInUseEntry == NULL) {
                return;
            }
            randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
            random = GetKartAiRandom();
            if (randomLimit == 0) {
                randomPart = 0;
            } else {
                random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                                : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
            }
            itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
            return;
        } else {
            RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
            itemUse->mThrowBehindPending = 1;
            itemUse->mThrowBehindTimer = 2;
            itemUse->mItemBitsEveryCall = 0;
            if (itemUse->mItemInUseEntry == NULL) {
                return;
            }
            randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
            random = GetKartAiRandom();
            if (randomLimit == 0) {
                randomPart = 0;
            } else {
                random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                                : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
            }
            itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
            return;
        }
    } else {
        RequestItemBitsByKartRank(itemUse, kartAi);
    }
}
// First place sends the bit 0x80, last place ITEM_THROW_FORWARD_BIT, the places between follow mThenBitKind.
void RequestItemBitsByKartRank(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    s32 rank;
    u16 randomLimit;
    u32 randomPart;

    rank = GetKartRank(kartAi->mIndex);
    if (rank == 1) {
        RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
        itemUse->mThrowBehindPending = 1;
        itemUse->mThrowBehindTimer = 2;
        itemUse->mItemBitsEveryCall = 0;
        if (itemUse->mItemInUseEntry == NULL) {
            return;
        }
        randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
        random = GetKartAiRandom();
        if (randomLimit == 0) {
            randomPart = 0;
        } else {
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                            : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
        }
        itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
        return;
    } else if ((u32) rank >= 2 && rank <= gRaceSetup->mKartCount - 1) {
        switch (itemUse->mHeldItemEntry->mThenBitKind) {
            case 0:
                RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
                itemUse->mItemBitsEveryCall = 0;
                if (itemUse->mItemInUseEntry == NULL) {
                    return;
                }
                randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
                random = GetKartAiRandom();
                if (randomLimit == 0) {
                    randomPart = 0;
                } else {
                    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                    randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                                    : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
                }
                itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
                return;
            case 1:
                RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
                itemUse->mThrowForwardPending = 1;
                itemUse->mThrowForwardTimer = 2;
                itemUse->mItemBitsEveryCall = 0;
                if (itemUse->mItemInUseEntry == NULL) {
                    return;
                }
                randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
                random = GetKartAiRandom();
                if (randomLimit == 0) {
                    randomPart = 0;
                } else {
                    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                    randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                                    : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
                }
                itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
                return;
            case 2:
                RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
                itemUse->mThrowBehindPending = 1;
                itemUse->mThrowBehindTimer = 2;
                itemUse->mItemBitsEveryCall = 0;
                if (itemUse->mItemInUseEntry == NULL) {
                    return;
                }
                randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
                random = GetKartAiRandom();
                if (randomLimit == 0) {
                    randomPart = 0;
                } else {
                    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
                    randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                                    : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
                }
                itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
                return;
            default:
                return;
        }
    } else {
        RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
        itemUse->mThrowForwardPending = 1;
        itemUse->mThrowForwardTimer = 2;
        itemUse->mItemBitsEveryCall = 0;
        if (itemUse->mItemInUseEntry == NULL) {
            return;
        }
        randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
        random = GetKartAiRandom();
        if (randomLimit == 0) {
            randomPart = 0;
        } else {
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                            : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
        }
        itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
        return;
    }
}

void UseItemAfterHeldIfTurnUnder20(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    timerRanOut = FALSE;
    itemUse->mHeldItemTimer--;
    if (itemUse->mHeldItemTimer <= 0) {
        itemUse->mHeldItemTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    if (kartAi->mTurnAngleDegrees >= 0x14000) {
        return;
    }
    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}

void func_0207cb74(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    timerRanOut = FALSE;
    itemUse->mHeldItemTimer--;
    if (itemUse->mHeldItemTimer <= 0) {
        itemUse->mHeldItemTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    if (kartAi->mTurnAngleDegrees >= 0x14000) {
        return;
    }
    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mHeldItemEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mHeldItemEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mHeldItemTimer = itemUse->mHeldItemEntry->mTimerBase + (u16) randomPart;
}

u32 func_0207cb70(u32 value) {
    return value;
// Calls one of two handlers, by whether the item in use is the circling kind.
}

void UseItemAfterInUseByCircleKind(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (gKartItems[kartAi->mIndex].mItemInUse.mUseKind == ITEM_USE_KIND_CIRCLE) {
        data_0217ae48(itemUse, kartAi);
    } else {
        data_0217ae44(itemUse, kartAi);
    }
// Calls one of two handlers, by whether the item in use is the trail kind.
}

void UseItemAfterInUseByTrailKind(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (gKartItems[kartAi->mIndex].mItemInUse.mUseKind == ITEM_USE_KIND_TRAIL) {
        data_0217ae3c(itemUse, kartAi);
    } else {
        data_0217ae40(itemUse, kartAi);
    }
}

void UseItemByTargetOrRankAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;

    timerRanOut = FALSE;
    itemUse->mItemInUseTimer--;
    if (itemUse->mItemInUseTimer <= 0) {
        itemUse->mItemInUseTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    UseItemByTargetOrRank(itemUse, kartAi);
}

void UseItemByRankAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    BOOL timerRanOut;

    timerRanOut = FALSE;
    itemUse->mItemInUseTimer--;
    if (itemUse->mItemInUseTimer <= 0) {
        itemUse->mItemInUseTimer = 0;
        timerRanOut = TRUE;
    }
    if (timerRanOut == FALSE) {
        return;
    }
    RequestItemBitsByKartRank(itemUse, kartAi);
}

void func_0207c978(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    KartItems *kartItems;
    s32 heldItemIndex;
    BOOL timerRanOut;

    kartItems = &gKartItems[kartAi->mIndex];
    heldItemIndex = kartItems->mHeldItem.mItemInfoIndex;
    if (itemUse->mItemBitsEveryCall != 0) {
        if (heldItemIndex != 0x13) {
            itemUse->mUnk_0c = 1;
        }
        if (itemUse->mUnk_0c == 0) {
            return;
        }
        timerRanOut = FALSE;
        itemUse->mItemInUseTimer--;
        if (itemUse->mItemInUseTimer <= 0) {
            itemUse->mItemInUseTimer = 0;
            timerRanOut = TRUE;
        }
        if (timerRanOut == FALSE) {
            return;
        }
        UseItemByTargetOrRank(itemUse, kartAi);
    } else {
        UseItemByTargetOrRank(itemUse, kartAi);
    }
}

void func_0207c8d8(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    KartItems *kartItems;
    s32 heldItemIndex;
    BOOL timerRanOut;

    kartItems = &gKartItems[kartAi->mIndex];
    heldItemIndex = kartItems->mHeldItem.mItemInfoIndex;
    if (itemUse->mItemBitsEveryCall != 0) {
        if (heldItemIndex != 0x13) {
            itemUse->mUnk_0c = 1;
        }
        if (itemUse->mUnk_0c == 0) {
            return;
        }
        timerRanOut = FALSE;
        itemUse->mItemInUseTimer--;
        if (itemUse->mItemInUseTimer <= 0) {
            itemUse->mItemInUseTimer = 0;
            timerRanOut = TRUE;
        }
        if (timerRanOut == FALSE) {
            return;
        }
        RequestItemBitsByKartRank(itemUse, kartAi);
    } else {
        RequestItemBitsByKartRank(itemUse, kartAi);
    }
}

void SetupRaceItemEntries(void) {
    switch (gRaceSetup->mCpuDifficulty) {
        case CPU_DIFFICULTY_EASY:
            gCurrentHeldItemEntries = gRaceEasyHeldItemEntries;
            gCurrentItemInUseEntries = gRaceItemInUseEntries;
            data_0217ae48 = UseItemByRankAfterInUse;
            data_0217ae44 = func_0207c8d8;
            data_0217ae3c = UseItemByRankAfterInUse;
            data_0217ae40 = func_0207c8d8;
            break;
        case CPU_DIFFICULTY_NORMAL:
            gCurrentHeldItemEntries = gRaceNormalHeldItemEntries;
            gCurrentItemInUseEntries = gRaceItemInUseEntries;
            data_0217ae48 = UseItemByRankAfterInUse;
            data_0217ae44 = func_0207c8d8;
            data_0217ae3c = UseItemByRankAfterInUse;
            data_0217ae40 = func_0207c8d8;
            break;
        case CPU_DIFFICULTY_HARD:
        default:
            gCurrentHeldItemEntries = gRaceHardHeldItemEntries;
            gCurrentItemInUseEntries = gRaceItemInUseEntries;
            data_0217ae48 = UseItemByTargetOrRankAfterInUse;
            data_0217ae44 = func_0207c978;
            data_0217ae3c = UseItemByTargetOrRankAfterInUse;
            data_0217ae40 = func_0207c978;
            break;
    }
}

// Also stops the every-call request of the item bits.
void UseItemAndResetHeldTimer(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mHeldItemEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mHeldItemEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mHeldItemTimer = itemUse->mHeldItemEntry->mTimerBase + (u16) randomPart;
}

// Also stops the every-call request of the item bits.
void UseItemAndResetInUseTimer(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}

// Also stops the every-call request of the item bits.
void UseItemForwardAndResetInUseTimer(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mThrowForwardPending = 1;
    itemUse->mThrowForwardTimer = 2;
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}

// Also stops the every-call request of the item bits.
void UseItemBehindAndResetInUseTimer(KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    itemUse->mThrowBehindPending = 1;
    itemUse->mThrowBehindTimer = 2;
    itemUse->mItemBitsEveryCall = 0;
    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}

void ClearKartAiItemUse(KartAiItemUse *itemUse) {
    itemUse->mHeldItemTimer = 0x0u;
    itemUse->mItemInUseTimer = 0x0u;
    itemUse->mHeldItemEntry = NULL;
    itemUse->mItemInUseEntry = NULL;
    itemUse->mUnk_0c = 0x0u;
    itemUse->mItemBitsEveryCall = 0x0u;
    itemUse->mThrowForwardPending = 0x0u;
    itemUse->mThrowBehindPending = 0x0u;
    itemUse->mThrowForwardTimer = 0x0u;
    itemUse->mThrowBehindTimer = 0x0u;
    itemUse->mRandomValue = 0x0u;
}

// On the call whose kart index matches the race frame count mod 8, runs the entry function or sends ITEM_BITS; on
// the other calls sends the pending bit 0x40 (ITEM_THROW_FORWARD_BIT) or 0x80.
void AdvanceItemBitRequests(struct KartAiItemUse *itemUse, struct KartAi *kartAi) {
    u16 kartIndex;
    KartItems *kartItems;

    if (func_01ffc67c(kartAi->mKart) != FALSE) {
        return;
    }
    kartIndex = kartAi->mIndex;
    if (kartIndex == GetRaceUpdateFramesMod8()) {
        kartItems = &gKartItems[kartIndex];
        if (kartItems->mItemInUse.mObjectKind != 0xf && itemUse->mItemInUseEntry != NULL) {
            itemUse->mItemInUseEntry->mHandler(itemUse, kartAi);
        } else if ((itemUse->mHeldItemEntry != 0) & (kartItems->mHeldItem.mItemInfoIndex != 0x13)) {
            itemUse->mHeldItemEntry->mHandler(itemUse, kartAi);
        } else {
            RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
        }
    } else if (itemUse->mThrowForwardPending != 0) {
        RequestBits(kartAi->mKart->mEntryIndex, ITEM_THROW_FORWARD_BIT);
        itemUse->mThrowForwardTimer--;
        if (itemUse->mThrowForwardTimer <= 0) {
            itemUse->mThrowForwardPending = 0;
        }
    } else if (itemUse->mThrowBehindPending != 0) {
        RequestBits(kartAi->mKart->mEntryIndex, PAD_KEY_DOWN);
        itemUse->mThrowBehindTimer--;
        if (itemUse->mThrowBehindTimer <= 0) {
            itemUse->mThrowBehindPending = 0;
        }
    }
    if (itemUse->mItemBitsEveryCall != 0) {
        RequestBits(kartAi->mKart->mEntryIndex, ITEM_BITS);
    }
}

void AdvanceRaceItemBitRequests(struct KartAiItemUse *itemUse, struct KartAi *kartAi) {
    if (IsKartEnded(kartAi->mIndex) != 0) {
        return;
    }
    if (gKartItems[kartAi->mIndex].mHeldItem.mItemInfoIndex == 0xe) {
        if (*(u16 *) &kartAi->mUnk_08.mUnk_00.mLink->mUnk_24 > 1) {
            return;
        }
    }
    AdvanceItemBitRequests(itemUse, kartAi);
}

void SetupHeldItemEntry(struct KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;
    enum { K0 } heldItemIndex;

    heldItemIndex = gKartItems[kartAi->mIndex].mHeldItem.mItemInfoIndex;
    itemUse->mHeldItemEntry = &gCurrentHeldItemEntries[heldItemIndex];
    random = GetKartAiRandom();
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    itemUse->mRandomValue = (s16) (u16) (random->mValue >> 52);
    if (itemUse->mHeldItemEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mHeldItemEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mHeldItemTimer = itemUse->mHeldItemEntry->mTimerBase + (u16) randomPart;
}

void ResetHeldItemTimer(struct KartAiItemUse *itemUse) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    if (itemUse->mHeldItemEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mHeldItemEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mHeldItemTimer = itemUse->mHeldItemEntry->mTimerBase + (u16) randomPart;
}

// Counts the held-item timer down; returns TRUE once it has run out.
s32 DecrementHeldItemTimer(struct KartAiItemUse *itemUse) {
    BOOL timerRanOut = FALSE;

    itemUse->mHeldItemTimer--;
    if (itemUse->mHeldItemTimer <= 0) {
        itemUse->mHeldItemTimer = 0;
        timerRanOut = TRUE;
    }
    return timerRanOut;
}

void ResetItemInUseTimer(struct KartAiItemUse *itemUse, struct KartAiItemUseEntry *unusedEntry) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;

    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}

// Counts the item-in-use timer down; returns TRUE once it has run out.
s32 DecrementItemInUseTimer(struct KartAiItemUse *itemUse) {
    BOOL timerRanOut = FALSE;

    itemUse->mItemInUseTimer--;
    if (itemUse->mItemInUseTimer <= 0) {
        itemUse->mItemInUseTimer = 0;
        timerRanOut = TRUE;
    }
    return timerRanOut;
}

void SetupItemInUseEntry(struct KartAiItemUse *itemUse, struct KartAi *kartAi) {
    RandomState64 *random;
    u16 randomLimit;
    u32 randomPart;
    enum { K0 } objectKind;

    objectKind = gKartItems[kartAi->mIndex].mItemInUse.mObjectKind;
    itemUse->mItemInUseEntry = &gCurrentItemInUseEntries[objectKind];
    itemUse->mUnk_0c = 0;
    if (itemUse->mItemInUseEntry == NULL) {
        return;
    }
    randomLimit = itemUse->mItemInUseEntry->mTimerRandomLimit;
    random = GetKartAiRandom();
    if (randomLimit == 0) {
        randomPart = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        randomPart = (randomLimit == 0) ? (u32) (random->mValue >> 32)
                                        : (u32) (((random->mValue >> 32) * (u32) randomLimit) >> 32);
    }
    itemUse->mItemInUseTimer = itemUse->mItemInUseEntry->mTimerBase + (u16) randomPart;
}

void SetupPosCurve(PosCurve *posCurve, struct CourseMapCamera *mapCamera) {
    CourseMapEntryGroup *entryGroup = &gCourseMap->mEntryGroups[mapCamera->mEntryGroupIndex];
    u16 i;

    posCurve->mParam = 0;
    posCurve->mUnk_34 = 0;
    posCurve->mUnk_38 = 0;
    if (entryGroup->mEntryCount < 4) {
        return;
    }
    for (i = 0; i < 4; i++) {
        posCurve->mPoints[i] = GetCourseMapGroupEntry(mapCamera->mEntryGroupIndex, i)->mPos;
        posCurve->mUnk_34 = i;
    }
}

void func_0207bd6c(PosCurve *posCurve, struct CourseMapCamera *mapCamera) {
    s16 entryIndex;
    s16 i;
    CourseMapEntryGroup *entryGroup = &gCourseMap->mEntryGroups[mapCamera->mEntryGroupIndex];

    posCurve->mParam = 0;
    posCurve->mUnk_34 = 0;
    posCurve->mUnk_38 = 0;
    if (entryGroup->mEntryCount < 4) {
        return;
    }
    posCurve->mUnk_38 = entryGroup->mEntryCount - 1;
    posCurve->mUnk_34 = 2;
    entryIndex = 2;
    for (i = 0; i < 3; i++) {
        posCurve->mPoints[(u16) i] = GetCourseMapGroupEntry(mapCamera->mEntryGroupIndex, entryIndex)->mPos;
        entryIndex--;
    }
    posCurve->mPoints[3] = GetCourseMapGroupEntry(mapCamera->mEntryGroupIndex, entryGroup->mEntryCount - 1)->mPos;
}

void UpdatePosCurve(Vec3 *point, PosCurve *posCurve, struct CourseMapCamera *mapCamera, s32 paramStep) {
    CourseMapEntryGroup *entryGroup;
    CourseMapGroupEntry *groupEntry;
    u16 i;

    entryGroup = &gCourseMap->mEntryGroups[mapCamera->mEntryGroupIndex];
    posCurve->mParam += paramStep;
    if (posCurve->mParam > 0x1000) {
        posCurve->mUnk_34++;
        if (posCurve->mUnk_34 >= entryGroup->mEntryCount) {
            posCurve->mUnk_34 = entryGroup->mEntryCount;
            posCurve->mParam = 0x1000;
        } else {
            groupEntry = GetCourseMapGroupEntry(mapCamera->mEntryGroupIndex, posCurve->mUnk_34);
            for (i = 0; i < 3; i++) {
                posCurve->mPoints[i] = posCurve->mPoints[i + 1];
            }
            posCurve->mPoints[3] = groupEntry->mPos;
            posCurve->mParam -= 0x1000;
        }
    }
    ComputePosCurvePoint(point, posCurve);
}

void ComputePosCurvePoint(Vec3 *point, PosCurve *posCurve) {
    s32 param;
    s32 paramSquared;
    s32 paramCubed;
    s32 paramRemaining;
    s32 weight0;
    s32 weight1;
    s32 weight2;
    s32 weight3;
    Vec3 *controlPoints[4];
    s32 i;

    param = posCurve->mParam;
    paramRemaining = 0x1000 - param;
    paramSquared = ((s64) param * param + 0x800) >> 12;
    paramCubed = ((s64) paramSquared * param + 0x800) >> 12;
    weight0 = ((s64) (s32) (((s64) paramRemaining * 0x2ab + 0x800) >> 12) *
                   (s32) (((s64) paramRemaining * paramRemaining + 0x800) >> 12) +
               0x800) >>
              12;
    weight1 = ((s64) ((s32) (((s64) paramCubed * 0x3000 + 0x800) >> 12) -
                      (s32) (((s64) 0x6000 * paramSquared + 0x800) >> 12) + 0x4000) *
                   0x2ab +
               0x800) >>
              12;
    weight2 = ((s64) ((s32) (((s64) (param + (paramSquared - paramCubed)) * 0x3000 + 0x800) >> 12) + 0x1000) * 0x2ab +
               0x800) >>
              12;
    weight3 = ((s64) paramCubed * 0x2ab + 0x800) >> 12;
    for (i = 0; i < 4; i++) {
        controlPoints[i] = &posCurve->mPoints[i];
    }
    point->x = (s32) (((s64) controlPoints[0]->x * weight0 + 0x800) >> 12) +
               (s32) (((s64) controlPoints[1]->x * weight1 + 0x800) >> 12) +
               (s32) (((s64) controlPoints[2]->x * weight2 + 0x800) >> 12) +
               (s32) (((s64) controlPoints[3]->x * weight3 + 0x800) >> 12);
    point->y = (s32) (((s64) controlPoints[0]->y * weight0 + 0x800) >> 12) +
               (s32) (((s64) controlPoints[1]->y * weight1 + 0x800) >> 12) +
               (s32) (((s64) controlPoints[2]->y * weight2 + 0x800) >> 12) +
               (s32) (((s64) controlPoints[3]->y * weight3 + 0x800) >> 12);
    point->z = (s32) (((s64) controlPoints[0]->z * weight0 + 0x800) >> 12) +
               (s32) (((s64) controlPoints[1]->z * weight1 + 0x800) >> 12) +
               (s32) (((s64) controlPoints[2]->z * weight2 + 0x800) >> 12) +
               (s32) (((s64) controlPoints[3]->z * weight3 + 0x800) >> 12);
}

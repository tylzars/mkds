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

void func_0207d6a4(struct Unk02089a24 *a, struct KartAi *b) {
    s32 m;
    s32 t;
    s32 v;
    s32 x;

    if (GetRaceUpdateFramesMod8() == b->mIndex) {
        a->mUnk_08 = 0;
        v = b->mKart->mSpeedLimitGoal;
        if (v > 0xa000) {
            v = 0xa000;
        }
        a->mTurnSpeedLimit = v;
        t = b->mTurnAngleDegrees;
        if (t > 0x5000) {
            x = ((s64) (t - 0x5000) * 0x5b) >> 12;
            if (x > 0x1000) {
                x = 0x1000;
            }
            x = ((s64) x * 0x668) >> 12;
            a->mTurnSpeedLimit = ((s64) (0x1000 - x) * 0xa000) >> 12;
        }
        m = a->mTurnSpeedLimit;
        if (m < v) {
            v = m;
        }
        if (v > 0xa000) {
            v = 0xa000;
        }
        a->mSpeedLimit = v;
    }
    if (b->mKart->mState != KART_STATE_NORMAL) {
        return;
    }
    if ((b->mKart->mUnk_48 & 0x10000020) != 0) {
        return;
    }
    x = func_0207fe70((Unk02080b1c *) &b->mUnk_08.mUnk_00);
    b->mKart->mSpeedLimitGoal = ((s64) a->mSpeedLimit * x + 0x800) >> 12;
}

void func_0207d5b8(KartAiItemUse *a, struct KartAi *b) {
    BOOL t;
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    t = FALSE;
    a->mHeldItemTimer--;
    if (a->mHeldItemTimer <= 0) {
        a->mHeldItemTimer = 0;
        t = TRUE;
    }
    if (t == FALSE) {
        return;
    }
    RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
    a->mItemBitsEveryCall = 0;
    if (a->mItemInUseEntry == NULL) {
        return;
    }
    n = a->mItemInUseEntry->mTimerRandomLimit;
    r = GetKartAiRandom();
    if (n == 0) {
        v = 0;
    } else {
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
    }
    a->mItemInUseTimer = a->mItemInUseEntry->mTimerBase + (u16) v;
}

void UseItemAfterHeld(KartAiItemUse *a, struct KartAi *b) {
    BOOL t;
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    t = FALSE;
    a->mHeldItemTimer--;
    if (a->mHeldItemTimer <= 0) {
        a->mHeldItemTimer = 0;
        t = TRUE;
    }
    if (t == FALSE) {
        return;
    }
    RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
    a->mItemBitsEveryCall = 0;
    if (a->mItemInUseEntry == NULL) {
        return;
    }
    n = a->mItemInUseEntry->mTimerRandomLimit;
    r = GetKartAiRandom();
    if (n == 0) {
        v = 0;
    } else {
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
    }
    a->mItemInUseTimer = a->mItemInUseEntry->mTimerBase + (u16) v;
}
void func_0207d474(KartAiItemUse *a, struct KartAi *b) {
    RaceSetup *d;
    u16 n;

    d = gRaceSetup;
    n = b->mIndex;
    if ((d->mCurrentEntries[n].mPlayer.mUnk_14 & 1) != 0) {
        if (a->mRandomValue <= 0xc00) {
            a->mItemBitsEveryCall = 1;
            return;
        }
    }
    UseItemByTargetOrRankAfterHeld(a, b);
}
void func_0207d3ec(KartAiItemUse *a, struct KartAi *b) {
    RaceSetup *d;
    u16 n;

    d = gRaceSetup;
    n = b->mIndex;
    if ((d->mCurrentEntries[n].mPlayer.mUnk_14 & 1) != 0) {
        if (a->mRandomValue <= 0x400) {
            a->mItemBitsEveryCall = 1;
            return;
        }
    }
    {
        BOOL t;

        t = FALSE;
        a->mHeldItemTimer--;
        if (a->mHeldItemTimer <= 0) {
            a->mHeldItemTimer = 0;
            t = TRUE;
        }
        if (t == FALSE) {
            return;
        }
    }
    RequestItemBitsByKartRank(a, b);
}

void UseItemByTargetOrRankAfterHeld(KartAiItemUse *a, struct KartAi *b) {
    BOOL t;

    t = FALSE;
    a->mHeldItemTimer--;
    if (a->mHeldItemTimer <= 0) {
        a->mHeldItemTimer = 0;
        t = TRUE;
    }
    if (t == FALSE) {
        return;
    }
    UseItemByTargetOrRank(a, b);
}

void UseItemByRankAfterHeld(KartAiItemUse *a, struct KartAi *b) {
    BOOL t;

    t = FALSE;
    a->mHeldItemTimer--;
    if (a->mHeldItemTimer <= 0) {
        a->mHeldItemTimer = 0;
        t = TRUE;
    }
    if (t == FALSE) {
        return;
    }
    RequestItemBitsByKartRank(a, b);
}
void UseItemByTargetOrRank(KartAiItemUse *a, struct KartAi *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    if (IsTargetKartSet(b) != FALSE) {
        if (GetTargetAhead(b) != 0) {
            RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
            a->mThrowForwardPending = 1;
            a->mThrowForwardTimer = 2;
            a->mItemBitsEveryCall = 0;
            if (a->mItemInUseEntry == NULL) {
                return;
            }
            n = a->mItemInUseEntry->mTimerRandomLimit;
            r = GetKartAiRandom();
            if (n == 0) {
                v = 0;
            } else {
                r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
                v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
            }
            a->mItemInUseTimer = a->mItemInUseEntry->mTimerBase + (u16) v;
            return;
        } else {
            RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
            a->mThrowBehindPending = 1;
            a->mThrowBehindTimer = 2;
            a->mItemBitsEveryCall = 0;
            if (a->mItemInUseEntry == NULL) {
                return;
            }
            n = a->mItemInUseEntry->mTimerRandomLimit;
            r = GetKartAiRandom();
            if (n == 0) {
                v = 0;
            } else {
                r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
                v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
            }
            a->mItemInUseTimer = a->mItemInUseEntry->mTimerBase + (u16) v;
            return;
        }
    } else {
        RequestItemBitsByKartRank(a, b);
    }
}
// First place sends the bit 0x80, last place ITEM_THROW_FORWARD_BIT, the places between follow mThenBitKind.
void RequestItemBitsByKartRank(KartAiItemUse *a, struct KartAi *b) {
    Unk0217aebc_128 *r;
    s32 rank;
    u16 n;
    u32 v;

    rank = GetKartRank(b->mIndex);
    if (rank == 1) {
        RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
        a->mThrowBehindPending = 1;
        a->mThrowBehindTimer = 2;
        a->mItemBitsEveryCall = 0;
        if (a->mItemInUseEntry == NULL) {
            return;
        }
        n = a->mItemInUseEntry->mTimerRandomLimit;
        r = GetKartAiRandom();
        if (n == 0) {
            v = 0;
        } else {
            r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
            v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
        }
        a->mItemInUseTimer = a->mItemInUseEntry->mTimerBase + (u16) v;
        return;
    } else if ((u32) rank >= 2 && rank <= gRaceSetup->mKartCount - 1) {
        switch (a->mHeldItemEntry->mThenBitKind) {
            case 0:
                RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
                a->mItemBitsEveryCall = 0;
                if (a->mItemInUseEntry == NULL) {
                    return;
                }
                n = a->mItemInUseEntry->mTimerRandomLimit;
                r = GetKartAiRandom();
                if (n == 0) {
                    v = 0;
                } else {
                    r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
                    v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
                }
                a->mItemInUseTimer = a->mItemInUseEntry->mTimerBase + (u16) v;
                return;
            case 1:
                RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
                a->mThrowForwardPending = 1;
                a->mThrowForwardTimer = 2;
                a->mItemBitsEveryCall = 0;
                if (a->mItemInUseEntry == NULL) {
                    return;
                }
                n = a->mItemInUseEntry->mTimerRandomLimit;
                r = GetKartAiRandom();
                if (n == 0) {
                    v = 0;
                } else {
                    r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
                    v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
                }
                a->mItemInUseTimer = a->mItemInUseEntry->mTimerBase + (u16) v;
                return;
            case 2:
                RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
                a->mThrowBehindPending = 1;
                a->mThrowBehindTimer = 2;
                a->mItemBitsEveryCall = 0;
                if (a->mItemInUseEntry == NULL) {
                    return;
                }
                n = a->mItemInUseEntry->mTimerRandomLimit;
                r = GetKartAiRandom();
                if (n == 0) {
                    v = 0;
                } else {
                    r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
                    v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
                }
                a->mItemInUseTimer = a->mItemInUseEntry->mTimerBase + (u16) v;
                return;
            default:
                return;
        }
    } else {
        RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
        a->mThrowForwardPending = 1;
        a->mThrowForwardTimer = 2;
        a->mItemBitsEveryCall = 0;
        if (a->mItemInUseEntry == NULL) {
            return;
        }
        n = a->mItemInUseEntry->mTimerRandomLimit;
        r = GetKartAiRandom();
        if (n == 0) {
            v = 0;
        } else {
            r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
            v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
        }
        a->mItemInUseTimer = a->mItemInUseEntry->mTimerBase + (u16) v;
        return;
    }
}

void UseItemAfterHeldIfTurnUnder20(KartAiItemUse *a, struct KartAi *b) {
    BOOL t;
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    t = FALSE;
    a->mHeldItemTimer--;
    if (a->mHeldItemTimer <= 0) {
        a->mHeldItemTimer = 0;
        t = TRUE;
    }
    if (t == FALSE) {
        return;
    }
    if (b->mTurnAngleDegrees >= 0x14000) {
        return;
    }
    RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
    a->mItemBitsEveryCall = 0;
    if (a->mItemInUseEntry == NULL) {
        return;
    }
    n = a->mItemInUseEntry->mTimerRandomLimit;
    r = GetKartAiRandom();
    if (n == 0) {
        v = 0;
    } else {
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
    }
    a->mItemInUseTimer = a->mItemInUseEntry->mTimerBase + (u16) v;
}

void func_0207cb74(KartAiItemUse *a, struct KartAi *b) {
    BOOL t;
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    t = FALSE;
    a->mHeldItemTimer--;
    if (a->mHeldItemTimer <= 0) {
        a->mHeldItemTimer = 0;
        t = TRUE;
    }
    if (t == FALSE) {
        return;
    }
    if (b->mTurnAngleDegrees >= 0x14000) {
        return;
    }
    RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
    a->mItemBitsEveryCall = 0;
    if (a->mHeldItemEntry == NULL) {
        return;
    }
    n = a->mHeldItemEntry->mTimerRandomLimit;
    r = GetKartAiRandom();
    if (n == 0) {
        v = 0;
    } else {
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
    }
    a->mHeldItemTimer = a->mHeldItemEntry->mTimerBase + (u16) v;
}

u32 func_0207cb70(u32 p0) {
    return p0;
// Calls one of two handlers, by whether the item in use is the circling kind.
}

void func_0207cb0c(KartAiItemUse *a, struct KartAi *b) {
    if (gKartItems[b->mIndex].mItemInUse.mUseKind == ITEM_USE_KIND_CIRCLE) {
        data_0217ae48(a, b);
    } else {
        data_0217ae44(a, b);
    }
// Calls one of two handlers, by whether the item in use is the trail kind.
}

void func_0207caa8(KartAiItemUse *a, struct KartAi *b) {
    if (gKartItems[b->mIndex].mItemInUse.mUseKind == ITEM_USE_KIND_TRAIL) {
        data_0217ae3c(a, b);
    } else {
        data_0217ae40(a, b);
    }
}

void UseItemByTargetOrRankAfterInUse(KartAiItemUse *a, struct KartAi *b) {
    BOOL r;

    r = FALSE;
    a->mItemInUseTimer--;
    if (a->mItemInUseTimer <= 0) {
        a->mItemInUseTimer = 0;
        r = TRUE;
    }
    if (r == FALSE) {
        return;
    }
    UseItemByTargetOrRank(a, b);
}

void UseItemByRankAfterInUse(KartAiItemUse *a, struct KartAi *b) {
    BOOL r;

    r = FALSE;
    a->mItemInUseTimer--;
    if (a->mItemInUseTimer <= 0) {
        a->mItemInUseTimer = 0;
        r = TRUE;
    }
    if (r == FALSE) {
        return;
    }
    RequestItemBitsByKartRank(a, b);
}

void func_0207c978(KartAiItemUse *a, struct KartAi *b) {
    KartItems *e;
    s32 t;
    BOOL r;

    e = &gKartItems[b->mIndex];
    t = e->mHeldItem.mItemInfoIndex;
    if (a->mItemBitsEveryCall != 0) {
        if (t != 0x13) {
            a->mUnk_0c = 1;
        }
        if (a->mUnk_0c == 0) {
            return;
        }
        r = FALSE;
        a->mItemInUseTimer--;
        if (a->mItemInUseTimer <= 0) {
            a->mItemInUseTimer = 0;
            r = TRUE;
        }
        if (r == FALSE) {
            return;
        }
        UseItemByTargetOrRank(a, b);
    } else {
        UseItemByTargetOrRank(a, b);
    }
}

void func_0207c8d8(KartAiItemUse *a, struct KartAi *b) {
    KartItems *e;
    s32 t;
    BOOL r;

    e = &gKartItems[b->mIndex];
    t = e->mHeldItem.mItemInfoIndex;
    if (a->mItemBitsEveryCall != 0) {
        if (t != 0x13) {
            a->mUnk_0c = 1;
        }
        if (a->mUnk_0c == 0) {
            return;
        }
        r = FALSE;
        a->mItemInUseTimer--;
        if (a->mItemInUseTimer <= 0) {
            a->mItemInUseTimer = 0;
            r = TRUE;
        }
        if (r == FALSE) {
            return;
        }
        RequestItemBitsByKartRank(a, b);
    } else {
        RequestItemBitsByKartRank(a, b);
    }
}

void func_0207c78c(void) {
    switch (gRaceSetup->mCpuDifficulty) {
        case CPU_DIFFICULTY_EASY:
            data_0217ae38 = data_usa_021554a4;
            data_0217ae34 = data_usa_0215524c;
            data_0217ae48 = UseItemByRankAfterInUse;
            data_0217ae44 = func_0207c8d8;
            data_0217ae3c = UseItemByRankAfterInUse;
            data_0217ae40 = func_0207c8d8;
            break;
        case CPU_DIFFICULTY_NORMAL:
            data_0217ae38 = data_usa_021552f4;
            data_0217ae34 = data_usa_0215524c;
            data_0217ae48 = UseItemByRankAfterInUse;
            data_0217ae44 = func_0207c8d8;
            data_0217ae3c = UseItemByRankAfterInUse;
            data_0217ae40 = func_0207c8d8;
            break;
        case CPU_DIFFICULTY_HARD:
        default:
            data_0217ae38 = data_usa_021553cc;
            data_0217ae34 = data_usa_0215524c;
            data_0217ae48 = UseItemByTargetOrRankAfterInUse;
            data_0217ae44 = func_0207c978;
            data_0217ae3c = UseItemByTargetOrRankAfterInUse;
            data_0217ae40 = func_0207c978;
            break;
    }
}

// Also stops the every-call request of the item bits.
void UseItemAndResetHeldTimer(KartAiItemUse *a, struct KartAi *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
    a->mItemBitsEveryCall = 0;
    if (a->mHeldItemEntry == NULL) {
        return;
    }
    n = a->mHeldItemEntry->mTimerRandomLimit;
    r = GetKartAiRandom();
    if (n == 0) {
        v = 0;
    } else {
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
    }
    a->mHeldItemTimer = a->mHeldItemEntry->mTimerBase + (u16) v;
}

// Also stops the every-call request of the item bits.
void UseItemAndResetInUseTimer(KartAiItemUse *a, struct KartAi *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
    a->mItemBitsEveryCall = 0;
    if (a->mItemInUseEntry == NULL) {
        return;
    }
    n = a->mItemInUseEntry->mTimerRandomLimit;
    r = GetKartAiRandom();
    if (n == 0) {
        v = 0;
    } else {
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
    }
    a->mItemInUseTimer = a->mItemInUseEntry->mTimerBase + (u16) v;
}

// Also stops the every-call request of the item bits.
void UseItemForwardAndResetInUseTimer(KartAiItemUse *a, struct KartAi *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
    a->mThrowForwardPending = 1;
    a->mThrowForwardTimer = 2;
    a->mItemBitsEveryCall = 0;
    if (a->mItemInUseEntry == NULL) {
        return;
    }
    n = a->mItemInUseEntry->mTimerRandomLimit;
    r = GetKartAiRandom();
    if (n == 0) {
        v = 0;
    } else {
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
    }
    a->mItemInUseTimer = a->mItemInUseEntry->mTimerBase + (u16) v;
}

// Also stops the every-call request of the item bits.
void UseItemBehindAndResetInUseTimer(KartAiItemUse *a, struct KartAi *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
    a->mThrowBehindPending = 1;
    a->mThrowBehindTimer = 2;
    a->mItemBitsEveryCall = 0;
    if (a->mItemInUseEntry == NULL) {
        return;
    }
    n = a->mItemInUseEntry->mTimerRandomLimit;
    r = GetKartAiRandom();
    if (n == 0) {
        v = 0;
    } else {
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
    }
    a->mItemInUseTimer = a->mItemInUseEntry->mTimerBase + (u16) v;
}

void func_0207c448(KartAiItemUse *p0) {
    p0->mHeldItemTimer = 0x0u;
    p0->mItemInUseTimer = 0x0u;
    p0->mHeldItemEntry = NULL;
    p0->mItemInUseEntry = NULL;
    p0->mUnk_0c = 0x0u;
    p0->mItemBitsEveryCall = 0x0u;
    p0->mThrowForwardPending = 0x0u;
    p0->mThrowBehindPending = 0x0u;
    p0->mThrowForwardTimer = 0x0u;
    p0->mThrowBehindTimer = 0x0u;
    p0->mRandomValue = 0x0u;
}

// On the call whose kart index matches the race frame count mod 8, runs the entry function or sends ITEM_BITS; on
// the other calls sends the pending bit 0x40 (ITEM_THROW_FORWARD_BIT) or 0x80.
void AdvanceItemBitRequests(struct KartAiItemUse *a, struct KartAi *b) {
    u16 v1;
    KartItems *e;

    if (func_01ffc67c(b->mKart) != FALSE) {
        return;
    }
    v1 = b->mIndex;
    if (v1 == GetRaceUpdateFramesMod8()) {
        e = &gKartItems[v1];
        if (e->mItemInUse.mObjectKind != 0xf && a->mItemInUseEntry != NULL) {
            a->mItemInUseEntry->mHandler(a, b);
        } else if ((a->mHeldItemEntry != 0) & (e->mHeldItem.mItemInfoIndex != 0x13)) {
            a->mHeldItemEntry->mHandler(a, b);
        } else {
            RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
        }
    } else if (a->mThrowForwardPending != 0) {
        RequestBits(b->mKart->mEntryIndex, ITEM_THROW_FORWARD_BIT);
        a->mThrowForwardTimer--;
        if (a->mThrowForwardTimer <= 0) {
            a->mThrowForwardPending = 0;
        }
    } else if (a->mThrowBehindPending != 0) {
        RequestBits(b->mKart->mEntryIndex, PAD_KEY_DOWN);
        a->mThrowBehindTimer--;
        if (a->mThrowBehindTimer <= 0) {
            a->mThrowBehindPending = 0;
        }
    }
    if (a->mItemBitsEveryCall != 0) {
        RequestBits(b->mKart->mEntryIndex, ITEM_BITS);
    }
}

void func_0207c270(struct KartAiItemUse *a, struct KartAi *b) {
    if (IsKartEnded(b->mIndex) != 0) {
        return;
    }
    if (gKartItems[b->mIndex].mHeldItem.mItemInfoIndex == 0xe) {
        if (*(u16 *) &b->mUnk_08.mUnk_00.mLink->mUnk_24 > 1) {
            return;
        }
    }
    AdvanceItemBitRequests(a, b);
}

void SetupHeldItemEntry(struct KartAiItemUse *a, struct KartAi *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;
    enum { K0 } k;

    k = gKartItems[b->mIndex].mHeldItem.mItemInfoIndex;
    a->mHeldItemEntry = &data_0217ae38[k];
    r = GetKartAiRandom();
    r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
    a->mRandomValue = (s16) (u16) (r->mValue >> 52);
    if (a->mHeldItemEntry == NULL) {
        return;
    }
    n = a->mHeldItemEntry->mTimerRandomLimit;
    r = GetKartAiRandom();
    if (n == 0) {
        v = 0;
    } else {
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
    }
    a->mHeldItemTimer = a->mHeldItemEntry->mTimerBase + (u16) v;
}

void ResetHeldItemTimer(struct KartAiItemUse *a) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    if (a->mHeldItemEntry == NULL) {
        return;
    }
    n = a->mHeldItemEntry->mTimerRandomLimit;
    r = GetKartAiRandom();
    if (n == 0) {
        v = 0;
    } else {
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
    }
    a->mHeldItemTimer = a->mHeldItemEntry->mTimerBase + (u16) v;
}

// Counts the held-item timer down; returns TRUE once it has run out.
s32 DecrementHeldItemTimer(struct KartAiItemUse *a) {
    BOOL r = FALSE;

    a->mHeldItemTimer--;
    if (a->mHeldItemTimer <= 0) {
        a->mHeldItemTimer = 0;
        r = TRUE;
    }
    return r;
}

void ResetItemInUseTimer(struct KartAiItemUse *a, struct KartAiItemUseEntry *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    if (a->mItemInUseEntry == NULL) {
        return;
    }
    n = a->mItemInUseEntry->mTimerRandomLimit;
    r = GetKartAiRandom();
    if (n == 0) {
        v = 0;
    } else {
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
    }
    a->mItemInUseTimer = a->mItemInUseEntry->mTimerBase + (u16) v;
}

// Counts the item-in-use timer down; returns TRUE once it has run out.
s32 DecrementItemInUseTimer(struct KartAiItemUse *a) {
    BOOL r = FALSE;

    a->mItemInUseTimer--;
    if (a->mItemInUseTimer <= 0) {
        a->mItemInUseTimer = 0;
        r = TRUE;
    }
    return r;
}

void SetupItemInUseEntry(struct KartAiItemUse *a, struct KartAi *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;
    enum { K0 } k;

    k = gKartItems[b->mIndex].mItemInUse.mObjectKind;
    a->mItemInUseEntry = &data_0217ae34[k];
    a->mUnk_0c = 0;
    if (a->mItemInUseEntry == NULL) {
        return;
    }
    n = a->mItemInUseEntry->mTimerRandomLimit;
    r = GetKartAiRandom();
    if (n == 0) {
        v = 0;
    } else {
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        v = (n == 0) ? (u32) (r->mValue >> 32) : (u32) (((r->mValue >> 32) * (u32) n) >> 32);
    }
    a->mItemInUseTimer = a->mItemInUseEntry->mTimerBase + (u16) v;
}

void SetupPosCurve(PosCurve *a, struct CourseMapCamera *b) {
    CourseMapEntryGroup *e = &gCourseMap->mEntryGroups[b->mEntryGroupIndex];
    u16 i;

    a->mParam = 0;
    a->mUnk_34 = 0;
    a->mUnk_38 = 0;
    if (e->mEntryCount < 4) {
        return;
    }
    for (i = 0; i < 4; i++) {
        a->mPoints[i] = GetCourseMapGroupEntry(b->mEntryGroupIndex, i)->mPos;
        a->mUnk_34 = i;
    }
}

void func_0207bd6c(PosCurve *a, struct CourseMapCamera *b) {
    s16 j;
    s16 i;
    CourseMapEntryGroup *e = &gCourseMap->mEntryGroups[b->mEntryGroupIndex];

    a->mParam = 0;
    a->mUnk_34 = 0;
    a->mUnk_38 = 0;
    if (e->mEntryCount < 4) {
        return;
    }
    a->mUnk_38 = e->mEntryCount - 1;
    a->mUnk_34 = 2;
    j = 2;
    for (i = 0; i < 3; i++) {
        a->mPoints[(u16) i] = GetCourseMapGroupEntry(b->mEntryGroupIndex, j)->mPos;
        j--;
    }
    a->mPoints[3] = GetCourseMapGroupEntry(b->mEntryGroupIndex, e->mEntryCount - 1)->mPos;
}

void UpdatePosCurve(Vec3 *a, PosCurve *b, struct CourseMapCamera *c, s32 d) {
    CourseMapEntryGroup *e;
    CourseMapGroupEntry *f;
    u16 i;

    e = &gCourseMap->mEntryGroups[c->mEntryGroupIndex];
    b->mParam += d;
    if (b->mParam > 0x1000) {
        b->mUnk_34++;
        if (b->mUnk_34 >= e->mEntryCount) {
            b->mUnk_34 = e->mEntryCount;
            b->mParam = 0x1000;
        } else {
            f = GetCourseMapGroupEntry(c->mEntryGroupIndex, b->mUnk_34);
            for (i = 0; i < 3; i++) {
                b->mPoints[i] = b->mPoints[i + 1];
            }
            b->mPoints[3] = f->mPos;
            b->mParam -= 0x1000;
        }
    }
    ComputePosCurvePoint(a, b);
}

void ComputePosCurvePoint(Vec3 *a, PosCurve *b) {
    s32 t;
    s32 t2;
    s32 t3;
    s32 u;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;
    Vec3 *v[4];
    s32 i;

    t = b->mParam;
    u = 0x1000 - t;
    t2 = ((s64) t * t + 0x800) >> 12;
    t3 = ((s64) t2 * t + 0x800) >> 12;
    c0 = ((s64) (s32) (((s64) u * 0x2ab + 0x800) >> 12) * (s32) (((s64) u * u + 0x800) >> 12) + 0x800) >> 12;
    c1 = ((s64) ((s32) (((s64) t3 * 0x3000 + 0x800) >> 12) - (s32) (((s64) 0x6000 * t2 + 0x800) >> 12) + 0x4000) *
              0x2ab +
          0x800) >>
         12;
    c2 = ((s64) ((s32) (((s64) (t + (t2 - t3)) * 0x3000 + 0x800) >> 12) + 0x1000) * 0x2ab + 0x800) >> 12;
    c3 = ((s64) t3 * 0x2ab + 0x800) >> 12;
    for (i = 0; i < 4; i++) {
        v[i] = &b->mPoints[i];
    }
    a->x = (s32) (((s64) v[0]->x * c0 + 0x800) >> 12) + (s32) (((s64) v[1]->x * c1 + 0x800) >> 12) +
           (s32) (((s64) v[2]->x * c2 + 0x800) >> 12) + (s32) (((s64) v[3]->x * c3 + 0x800) >> 12);
    a->y = (s32) (((s64) v[0]->y * c0 + 0x800) >> 12) + (s32) (((s64) v[1]->y * c1 + 0x800) >> 12) +
           (s32) (((s64) v[2]->y * c2 + 0x800) >> 12) + (s32) (((s64) v[3]->y * c3 + 0x800) >> 12);
    a->z = (s32) (((s64) v[0]->z * c0 + 0x800) >> 12) + (s32) (((s64) v[1]->z * c1 + 0x800) >> 12) +
           (s32) (((s64) v[2]->z * c2 + 0x800) >> 12) + (s32) (((s64) v[3]->z * c3 + 0x800) >> 12);
}

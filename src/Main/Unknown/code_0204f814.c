#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_0203be88.h"
#include "code_0200f59c.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02007624.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0204bca0.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma opt_rebuildconditionals off

static inline u32 func_0204f814_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline u32 func_0204ff14_inline(Unk0217aa00 *p) {
    if (p == NULL) {
        return 0;
    }
    return p->mUnk_0000;
}

u16 func_0204ffe8(u32 participantIndex) {
    BOOL stateMatches;
    u32 result;

    stateMatches = FALSE;
    switch (data_0217aa00->mUnk_0004) {
        case 8:
        case 9:
            stateMatches = TRUE;
            break;
    }
    if (stateMatches != FALSE) {
        result = data_0217aa00->mUnk_15c8[participantIndex].mUnk_00_0;
    } else {
        result = 0;
    }
    return result;
}

BOOL func_0204ffbc(void) {
    BOOL result;

    result = FALSE;
    switch (data_0217aa00->mUnk_0004) {
        case 8:
        case 9:
            result = TRUE;
            break;
    }
    return result;
}

BOOL func_0204ff14(u16 entryIndex, void *destination) {
    Unk0217aa00 *t;
    BOOL result;

    t = data_0217aa00;
    result = FALSE;
    if (func_0204ff14_inline(t) != 2) {
        return FALSE;
    }
    if (*(u16 *) 0x027ffc40 == 2) {
        return FALSE;
    }
    if (t->mUnk_00ac[entryIndex].mUnk_dc_0 != 0) {
        if (destination != NULL) {
            MI_CpuCopy8(t->mUnk_00ac[entryIndex].mUnk_c6, destination, 0x14);
        }
        result = TRUE;
    }
    return result;
}

BOOL func_0204fe90(u16 entryIndex) {
    BOOL result;
    BOOL entryValid;

    result = FALSE;
    entryValid = FALSE;
    if (func_0204f814_inline() != 2) {
        entryValid = FALSE;
    } else if (*(u16 *) 0x027ffc40 == 2) {
        entryValid = FALSE;
    } else if (data_0217aa00->mUnk_00ac[entryIndex].mUnk_dc_0 != 0) {
        entryValid = TRUE;
    }
    if (entryValid != FALSE) {
        if (data_0217aa00->mUnk_00ac[entryIndex].mUnk_dc_5 != 0) {
            result = TRUE;
        }
    }
    return result;
}

s32 func_0204fe1c(u16 entryIndex) {
    s32 result;
    BOOL entryValid;

    result = 0;
    entryValid = FALSE;
    if (func_0204f814_inline() != 2) {
        entryValid = FALSE;
    } else if (*(u16 *) 0x027ffc40 == 2) {
        entryValid = FALSE;
    } else if (data_0217aa00->mUnk_00ac[entryIndex].mUnk_dc_0 != 0) {
        entryValid = TRUE;
    }
    if (entryValid != FALSE) {
        result = data_0217aa00->mUnk_00ac[entryIndex].mUnk_da;
    }
    return result;
}

BOOL func_0204fcec(u16 entryIndex, void *destination) {
    BOOL result;
    void *p;

    result = FALSE;
    switch (func_0204f814_inline()) {
        case 1:
            result = FALSE;
            if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
                p = func_02007e38(entryIndex);
                if ((data_0217aa00->mUnk_1696 & (1 << entryIndex)) != 0 && p != NULL) {
                    if (destination != NULL) {
                        MI_CpuCopy8((u8 *) p + 2, destination, 0x14);
                    }
                    result = TRUE;
                }
            } else if ((data_0217aa00->mUnk_0044.mChildMask & (1 << entryIndex)) != 0) {
                if (destination != NULL) {
                    MI_CpuCopy8(&data_0217aa00->mUnk_045c[entryIndex], destination, 0x14);
                }
                result = TRUE;
            }
            break;
        case 2:
            result = FALSE;
            if ((data_0217aa00->mUnk_043d & (1 << entryIndex)) != 0) {
                if (destination != NULL) {
                    MI_CpuCopy8(&data_0217aa00->mUnk_045c[entryIndex], destination, 0x14);
                }
                result = TRUE;
            }
            break;
    }
    return result;
}

void FillParentParameter(s32 a) {
    Unk02143c30 *parentParameter;
    Unk0217aa00_24_50 *gameInfo;
    RTCTime time;
    u32 hour;
    u16 seconds;
    u64 generatorState;
    u64 highWord;

    parentParameter = data_0217aa00->mParentParameter;
    MIi_CpuCopy32(data_02154788, parentParameter, 0x40);
    gameInfo = data_0217aa00->mUnk_0044.mUnk_38;
    gameInfo->mUnk_0e.mUnk_07_0 = 0;
    gameInfo->mUnk_0e.mKartIndex = 0;
    gameInfo->mCharacterIndex = 0;
    gameInfo->mCupCourseIndex = 0;
    gameInfo->mMinute = 0;
    gameInfo->mSecond = 0;
    gameInfo->mMillisecond = 0;
    gameInfo->mUnk_0e.mUnk_06_0 = 0;
    if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
        parentParameter->mUnk_0c = (data_0217aa00->mUnk_1690 + 7) & 0x7fff;
    } else {
        GetClockTimeOrZero(&time);
        hour = time.mHour;
        if (hour >= 0x12) {
            hour -= 0x12;
        }
        seconds = (hour * 0x3c + time.mMinute) * 0x3c + time.mSecond;
        generatorState = OS_GetTickLo() | seconds << 16;
        generatorState = generatorState * 0x5d588b656c078965ull + 0x269ec3;
        highWord = generatorState >> 32;
        parentParameter->mUnk_0c = (u16) (highWord * 0x10000 >> 32) | 0x8000;
    }
    parentParameter->mUnk_32 = data_0217aa00->mUnk_0088;
    parentParameter->mUnk_18 = WM_GetDispersionBeaconPeriod();
    parentParameter->mUnk_00 = data_0217aa00->mUnk_0044.mUnk_38;
    parentParameter->mUnk_04 = 0x1c;
    parentParameter->mUnk_10 = 7;
    parentParameter->mUnk_0e = a != 0 ? 1 : 0;
}

void FillGhostParentParameter(GhostRecord *ghostRecord) {
    Unk02143c30 *parentParameter;
    Unk0217aa00_24_50 *gameInfo;
    RTCTime time;
    u32 hour;
    u16 seconds;
    u64 generatorState;
    u64 highWord;

    parentParameter = data_0217aa00->mParentParameter;
    MIi_CpuCopy32(data_02154788, parentParameter, 0x40);
    gameInfo = data_0217aa00->mUnk_0044.mUnk_38;
    gameInfo->mUnk_0e.mUnk_07_0 = 1;
    MI_CpuCopy8(ghostRecord->mName, gameInfo, 0x14);
    gameInfo->mUnk_0e.mKartIndex = ghostRecord->mKartIndex;
    gameInfo->mCharacterIndex = ghostRecord->mCharacterIndex;
    gameInfo->mCupCourseIndex = (u8) FindCupCourseIndex(ghostRecord->mCourseId);
    gameInfo->mMinute = ghostRecord->mMinute;
    gameInfo->mSecond = ghostRecord->mSecond;
    gameInfo->mMillisecond = ghostRecord->mMillisecond;
    GetClockTimeOrZero(&time);
    hour = time.mHour;
    if (hour >= 0x12) {
        hour -= 0x12;
    }
    seconds = (hour * 0x3c + time.mMinute) * 0x3c + time.mSecond;
    generatorState = OS_GetTickLo() | seconds << 16;
    generatorState = generatorState * 0x5d588b656c078965ull + 0x269ec3;
    highWord = generatorState >> 32;
    parentParameter->mUnk_0c = (u16) (highWord * 0x10000 >> 32) | 0x8000;
    parentParameter->mUnk_32 = data_0217aa00->mUnk_0088;
    parentParameter->mUnk_18 = WM_GetDispersionBeaconPeriod();
    parentParameter->mUnk_00 = data_0217aa00->mUnk_0044.mUnk_38;
    parentParameter->mUnk_04 = 0x1c;
    parentParameter->mUnk_10 = 1;
    parentParameter->mUnk_34 = 0x1b6;
    parentParameter->mUnk_36 = 0x2e;
}

void func_0204f8a0(u8 a) {
    BOOL proceed;
    BOOL allowed;

    proceed = FALSE;
    if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
        allowed = TRUE;
        if (func_0204f814_inline() != 1) {
            if (*(u16 *) 0x027ffc40 != 2) {
                allowed = FALSE;
            }
        }
        if (allowed != FALSE) {
            proceed = TRUE;
        }
    }
    if (proceed == FALSE) {
        return;
    }
    if (func_0204f814_inline() != 1) {
        return;
    }
    func_0204bcb4(a);
}

void func_0204f814(void) {
    s32 index;
    s32 lowest;
    s8 lowestIndex;
    s32 value;

    lowestIndex = -1;
    lowest = 0x7fff;
    for (index = 1; index < 14; index++) {
        value = data_0217aa00->mUnk_008c[index];
        if (value != -1 && value < lowest) {
            lowest = value;
            lowestIndex = index;
        }
    }
    if (lowestIndex != -1) {
        data_0217aa00->mUnk_0088 = lowestIndex;
        return;
    }
    data_0217aa00->mUnk_0088 = -1;
    data_0217aa00->mUnk_0008 = 3;
    data_0217aa00->mRequestPending = 0;
}

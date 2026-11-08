#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_02039708.h"
#include "Main/Unknown/code_02039520.h"
#include "Main/Unknown/code_0204a9e4.h"
#include "Main/Unknown/code_020470c4.h"
#include "Main/Unknown/code_0205e090.h"
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
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma opt_rebuildconditionals off

static inline s32 func_020431e4_inline(ConnectionWork *p) {
    BOOL r = FALSE;
    if ((p == NULL ? 0 : p->mUnk_0000) != 0 && p->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

u16 func_020435bc(void) {
    return 9;
}

u32 func_0204359c(void) {
    return (data_02175624->mFlags & INPUT_STATE_OPEN_DURING_RACE) != 0;
}

void SetReadRaceKeys(u32 enable) {
    if (GetCurrentSceneNumber() == 2 && enable != 0) {
        data_02175624->mFlags |= INPUT_STATE_READ_RACE_KEYS;
    } else {
        data_02175624->mFlags &= ~INPUT_STATE_READ_RACE_KEYS;
    }
}

void func_02043410(void) {
    u16 i;
    u16 j;
    ConnectionWork *z;
    InputSlot *inputSlot;

    for (i = 0; i < 8; i++) {
        inputSlot = &data_02175628[i];
        ResetInputSlot(inputSlot);
        SetInputSlotRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot->mSourceKind = 0;
        inputSlot->mRequestedBits = 0;
        inputSlot->mUnk_44 = 0;
        inputSlot->mBitMask = 0x2fff;
        ResetKeyRecording((KeyRecording *) &inputSlot->mUnk_28);
        ResetInputSlotPair((InputSlotPair *) &inputSlot->mPairX);
    }
    z = data_0217aa00;
    if (func_020431e4_inline(z) != 0) {
        for (j = 0; j < 8; j++) {
            if (z->mParticipantMask & (1 << z->mUnk_1e8c[j])) {
                data_02175628[j].mSourceKind = 4;
            }
        }
    }
    data_02175624->mUnk_08 = 0;
    data_02175624->mUnk_0c = FALSE;
}

void func_020431e4(void) {
    s32 i;
    s32 k;
    u16 entryIndex;
    s32 inputSlotIndex;
    BOOL t;
    InputSlot *inputSlot;
    RaceSetup *raceSetup;
    ConnectionWork *z;
    s32 playerKind;

    for (i = 0; i < 10; i++) {
        inputSlot = &data_02175628[(u32) i];
        ResetInputSlot(inputSlot);
        SetInputSlotRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot->mSourceKind = 0;
        inputSlot->mRequestedBits = 0;
        inputSlot->mUnk_44 = 0;
        inputSlot->mBitMask = 0x2fff;
        ResetKeyRecording((KeyRecording *) &inputSlot->mUnk_28);
        ResetInputSlotPair((InputSlotPair *) &inputSlot->mPairX);
    }
    data_02175628[8].mSourceKind = 5;
    data_02175628[9].mSourceKind = 6;
    data_02175624->mUnk_08 = 0;
    data_02175624->mUnk_0c = FALSE;
    inputSlot = data_02175628;
    for (k = 0; k < 10; k++) {
        ResetInputSlot(inputSlot);
        inputSlot->mRequestedBits = 0;
        SetInputSlotRepeat(inputSlot, 0xff3, 0x1e, 0xa);
        inputSlot++;
    }
    raceSetup = gRaceSetup;
    z = data_0217aa00;
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        playerKind = raceSetup->mCurrentEntries[entryIndex].mPlayer.mKind;
        t = FALSE;
        inputSlotIndex = raceSetup->mCurrentEntries[entryIndex].mPlayer.mIndex;
        if ((u32) playerKind <= 3 && ((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER)) {
            t = TRUE;
        }
        if (t != FALSE) {
            if (entryIndex == raceSetup->mEntryIndex) {
                if (func_020431e4_inline(z) != 0) {
                    data_02175628[inputSlotIndex].mSourceKind = 4;
                } else if (raceSetup->mRaceKind == 2) {
                    data_02175628[inputSlotIndex].mSourceKind = 1;
                } else {
                    data_02175628[inputSlotIndex].mSourceKind = 2;
                }
            } else if (playerKind == 2) {
                data_02175628[inputSlotIndex].mSourceKind = 1;
            } else if (raceSetup->mMode == 5) {
                data_02175628[inputSlotIndex].mSourceKind = 7;
            } else {
                data_02175628[inputSlotIndex].mSourceKind = 4;
            }
        } else if (playerKind == 1) {
            data_02175628[inputSlotIndex].mSourceKind = 3;
        }
    }
}

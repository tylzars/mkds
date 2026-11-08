#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"

#pragma opt_rebuildconditionals off

static inline u32 func_02050080_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

u32 func_020501b0(u32 entryIndex) {
    u32 result = 0;
    ScanSlot *entry;
    ConnectionWork *q;
    u32 entryValid;

    if (entryIndex >= 4) {
        return 0;
    }
    if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
        entryValid = result;
        if (func_02050080_inline() != 2) {
            entryValid = 0;
        } else if (*(u16 *) 0x027ffc40 == 2) {
            entryValid = 0;
        } else if (data_0217aa00->mUnk_00ac[entryIndex].mUnk_dc_0 != 0) {
            entryValid = 1;
        }
        if (entryValid != 0) {
            StartRequestEndScan();
            result = 1;
        }
    } else {
        data_0217aa00->mUnk_043b = 0;
        data_0217aa00->mUnk_0438 = 0;
        entry = &data_0217aa00->mUnk_00ac[entryIndex];
        data_0217aa00->mUnk_0436 &= ~1;
        if (entry->mUnk_dc_0 != 0) {
            MI_CpuCopy8(entry, data_0217aa00->mUnk_0024, 0xc0);
            DC_StoreRange(data_0217aa00->mUnk_0024, 0xc0);
            q = data_0217aa00;
            *(Unk0217aa00_42c *) &q->mUnk_042c = entry->mUnk_c0_42c;
            q->mUnk_043c = entry->mUnk_dc_1;
            result = 1;
        }
    }
    return result;
}

void func_02050080(void) {
    BOOL proceed;
    u16 index;
    u16 participantCount;

    proceed = FALSE;
    if (func_02050080_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        proceed = TRUE;
    }
    if (proceed == FALSE) {
        return;
    }
    index = 0;
    participantCount = 0;
    for (; index < 8; index++) {
        if ((data_0217aa00->mParticipantMask & (1 << index)) != 0) {
            data_0217aa00->mUnk_1e52[index].mEntryIndex = participantCount;
            data_0217aa00->mUnk_1e8c[participantCount] = index;
            data_0217aa00->mParticipantIndices[participantCount] = index;
            participantCount++;
        } else {
            data_0217aa00->mUnk_1e52[index].mEntryIndex = 0xffff;
        }
    }
    for (; participantCount < 8; participantCount++) {
        data_0217aa00->mUnk_1e8c[participantCount] = 0xffff;
        data_0217aa00->mParticipantIndices[participantCount] = 0xffff;
    }
    if (GetCurrentSceneNumber() == 2) {
        func_020431e4();
    } else {
        func_02043410();
    }
}

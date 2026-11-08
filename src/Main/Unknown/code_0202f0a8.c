#include "Main/Unknown/code_0202f0a8.h"
#include "Main/Unknown/code_0202f028.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on

#pragma thumb on

void CallScrollListCallback(s32 action, s32 slot, s32 row, s32 selectedSlot) {
    void (*callback)(int, int, int, int) = gScrollList->mCallback;
    if (callback != NULL) {
        if (action == 1) {
            if (row < 0 || row >= gScrollList->mRowCount) {
                return;
            }
        }
        callback(action, slot, row, selectedSlot);
    }
}

#pragma thumb off

u32 func_0202f0fc(InputSlotPair *pair) {
    if (pair->mPrevHasPair == 0 && pair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 func_0202f0c8(InputSlotPair *pair) {
    u32 result = 0;
    if (func_0202f028(pair) == 0 && func_0202f0fc(pair) != 0) {
        result = 1;
    }
    return result;
}

u32 func_0202f0a8(u32 slotIndex) {
    return func_0202f0c8((InputSlotPair *) &data_02175628[slotIndex].mPairX);
}

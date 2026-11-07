#include "Main/Unknown/code_0204f19c.h"
#include "Main/Unknown/code_0204f220.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void ParentBlockTransferCallback(BlockTransferRecord *record) {
    s32 callbackCode = record->mCallbackCode;
    if (callbackCode == 10) {
        func_0204f220(&record->mUnk_14, *((u8 *) &record->mUnk_1c[0] + 1));
        return;
    }
    switch (data_0217aa00->mUnk_1e46) {
        case 0:
            if (callbackCode == 2) {
                data_0217aa00->mUnk_1e46 = 1;
            }
            break;
        case 1:
            if (callbackCode == 8) {
                data_0217aa00->mUnk_1e46 = 2;
            }
            break;
        case 2:
            if (callbackCode == 8) {
                data_0217aa00->mUnk_1e44 |= 4;
                data_0217aa00->mUnk_1e46 = 0;
            }
            break;
    }
}

#pragma thumb off

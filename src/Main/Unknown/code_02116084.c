#include "Main/Unknown/code_02116084.h"
#include "Main/Unknown/code_02114158.h"

#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02114000.h"
#include "Main/Unknown/code_02116870.h"

#pragma thumb on

const u16 data_0215c4ac[2] = {0x1e, 0x1f};

void AdvanceRecordVSEraseOffsetTimers(void) {
    s32 v;
    BOOL a;
    BOOL b;
    s32 i;

    v = GetRecordVSEraseFirstRecordIndex();
    gRecordVSErase->mRecordVSSEraseTable[data_0215c4a8[0]].mOffsetX =
        -func_020adc64(6 - gRecordVSErase->mOffsetTimers[0]);
    gRecordVSErase->mRecordVSSEraseTable[data_0215c4a8[1]].mOffsetX =
        func_020adc64(6 - gRecordVSErase->mOffsetTimers[1]);
    a = FALSE;
    b = FALSE;
    for (i = 0; i < 2; i++) {
        if (gRecordVSErase->mOffsetTimers[i] > 0) {
            gRecordVSErase->mOffsetTimers[i]--;
            gRecordVSErase->mRecordVSSEraseTable[data_0215c4ac[i]].mVisible = a;
            gRecordVSErase->mRecordVSSEraseTable[data_0215c4a8[i]].mVisible = 1;
        } else {
            gRecordVSErase->mRecordVSSEraseTable[data_0215c4ac[i]].mVisible = 1;
            gRecordVSErase->mRecordVSSEraseTable[data_0215c4a8[i]].mVisible = b;
        }
    }
    if (v == 0) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4ac[0]].mVisible = 0;
    }
    if (v + 5 >= GetRecordCount()) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4ac[1]].mVisible = 0;
    }
}

#pragma thumb off

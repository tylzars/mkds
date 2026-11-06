#include "Main/Unknown/code_02108e38.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_0212bcac.h"

#pragma optimize_for_size on

void func_02108e38(void) {
    s32 i;

    for (i = 7; i < 12; i++) {
        NNS_SndPlayerStopSeq(&data_0217c838[i], 0);
    }
}

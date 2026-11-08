#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02057ca4.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on
void func_02056d40(void) {
    u32 value0;
    u32 value3;
    value0 = (u32) &data_0217aa08;
    value0 = *(const u32 *) ((value0) + 0u);
    value0 = *(const u32 *) ((value0) + 0u);
    WriteBackupFirstBlock((void *) value0);
}
#pragma thumb off

#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_020574a0.h"
#include "Main/Unknown/code_02057764.h"
#include "Main/Unknown/unk_0217a000.h"

void WriteBackupBuddyRecords(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &data_0217aa08;
    value0 = *(const u32 *) ((value0) + (0));
    value0 = *(const u32 *) ((value0) + (32));
    WriteBackupBuddyRecordBlock((void *) value0);
}

void func_0205edcc(void) {
    u32 value0;
    value0 = (u32) &data_0217aa08;
    value0 = *(const u32 *) ((value0) + (0));
    value0 = *(const u32 *) ((value0) + (32));
    WriteBackupBuddyRecordBlock((void *) value0);
    StartWriteBackupFirstBlock();
}

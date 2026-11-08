#include "Main/Unknown/code_020360d0.h"
#include "01/code_021956dc.h"

u32 IsBackupEnabled(void) {
    u32 backupEnabled;
    backupEnabled = data_021759d4->mBackupEnabled;
    return backupEnabled;
}

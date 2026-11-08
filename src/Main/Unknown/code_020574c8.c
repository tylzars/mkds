#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057ca4.h"
#include "01/code_021956dc.h"

#pragma thumb on

void func_02057514(void) {
    data_0217aa08->mUnk_28 = 1;
}

void func_02057504(void) {
    data_0217aa08->mUnk_28 = 0;
}

void func_020574c8(void) {
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    func_02057ca4(data_0217aa08->mUnk_00);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    func_02057504();
}

#pragma thumb off

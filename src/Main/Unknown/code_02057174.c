#include "Main/Unknown/code_02057174.h"
#include "Main/Unknown/code_02057244.h"
#include "Main/Unknown/code_02057260.h"
#include "Main/Unknown/code_02057294.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057764.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/code_02057ca4.h"
#include "01/code_021956dc.h"

#pragma thumb on

void func_0205721c(u32 a) {
    func_020572e8();
    func_020572cc();
    func_020572b0();
    func_02057294();
    func_02057260();
    func_02057244();
    func_02057304(a);
}

void func_02057174(void) {
    func_02057c14(data_0217aa08->mUnk_04);
    if (data_021759d4->mUnk_0c != 0) {
        CARD_WaitBackupAsync();
    }
    func_02057b84(data_0217aa08->mUnk_08);
    if (data_021759d4->mUnk_0c != 0) {
        CARD_WaitBackupAsync();
    }
    func_02057af4(data_0217aa08->mUnk_0c);
    if (data_021759d4->mUnk_0c != 0) {
        CARD_WaitBackupAsync();
    }
    func_02057a60(data_0217aa08->mUnk_10);
    if (data_021759d4->mUnk_0c != 0) {
        CARD_WaitBackupAsync();
    }
    func_020577b4(data_0217aa08->mBuddyRecordBlock);
    if (data_021759d4->mUnk_0c != 0) {
        CARD_WaitBackupAsync();
    }
    func_02057ca4(data_0217aa08->mUnk_00);
    if (data_021759d4->mUnk_0c != 0) {
        CARD_WaitBackupAsync();
    }
    func_02057504();
}

#pragma thumb off

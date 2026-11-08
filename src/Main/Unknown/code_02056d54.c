#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02057174.h"
#include "Main/Unknown/code_02057244.h"
#include "Main/Unknown/code_02057294.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057764.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/code_02057ca4.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "01/code_021956dc.h"

#pragma thumb on

void func_02057130(void) {
    ResetBackupFirstBlockAndRecords(((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        SetBackupBusy();
        QueueThreadFunction(WriteBackupFirstBlockAndRecords);
        gThreadFunctionQueue->mRunRequested = 1;
    }
}

void ReadBackupFirstBlockAndRecords(void) {
    u16 failedBlockBits;

    failedBlockBits = 0;
    data_0217aa08->mReadStatus = 0;
    ReadBackupFirstBlock(data_0217aa08->mFirstBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        if (gBackupAccess->mErrorCode == 4) {
            data_0217aa08->mFailedBlockBits = 0xffff;
            data_0217aa08->mReadStatus = 4;
            ClearBackupBusy();
            return;
        }
        failedBlockBits |= 1;
    }
    ReadBackupEmblemRecord(data_0217aa08->mEmblemRecord);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        failedBlockBits |= 2;
    }
    ReadBackupGrandPrixRecordBlock(data_0217aa08->mGrandPrixRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        failedBlockBits |= 4;
    }
    ReadBackupCourseTimeRecordBlock(data_0217aa08->mCourseTimeRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        failedBlockBits |= 8;
    }
    ReadBackupMissionRecordBlock(data_0217aa08->mMissionRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        failedBlockBits |= 0x10;
    }
    ReadBackupBuddyRecordBlock(data_0217aa08->mBuddyRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBackupAccess->mErrorCode != 0) {
        failedBlockBits |= 0x20;
    }
    if (data_0217aa08->mReadStatus == 0) {
        if (failedBlockBits != 0) {
            data_0217aa08->mReadStatus = 3;
        } else {
            data_0217aa08->mReadStatus = 0;
        }
    }
    data_0217aa08->mFailedBlockBits = failedBlockBits;
    ClearBackupBusy();
}

void StartReadBackupFirstBlockAndRecords(void) {
    data_0217aa08->mUnk_44_0 = 1;
    data_0217aa08->mUnk_3c = 0;
    data_0217aa08->mFailedBlockBits = 0;
    SetBackupBusy();
    QueueThreadFunction(ReadBackupFirstBlockAndRecords);
    gThreadFunctionQueue->mRunRequested = 1;
}

void ResetFailedBackupBlocks(void) {
    if (data_0217aa08->mFailedBlockBits & 2) {
        ClearEmblemRecord();
        WriteBackupEmblemRecord(data_0217aa08->mEmblemRecord);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (data_0217aa08->mFailedBlockBits & 4) {
        ClearGrandPrixRecordBlock();
        WriteBackupGrandPrixRecordBlock(data_0217aa08->mGrandPrixRecordBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (data_0217aa08->mFailedBlockBits & 8) {
        ClearCourseTimeRecordBlock();
        WriteBackupCourseTimeRecordBlock(data_0217aa08->mCourseTimeRecordBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (data_0217aa08->mFailedBlockBits & 0x10) {
        ClearMissionRecordBlock();
        WriteBackupMissionRecordBlock(data_0217aa08->mMissionRecordBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (data_0217aa08->mFailedBlockBits & 0x20) {
        ClearBuddyRecordBlock();
        WriteBackupBuddyRecordBlock(data_0217aa08->mBuddyRecordBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    if (data_0217aa08->mFailedBlockBits & 1) {
        ResetBackupFirstBlock(((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2);
        WriteBackupFirstBlock(data_0217aa08->mFirstBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    data_0217aa08->mFailedBlockBits = 0;
    ClearBackupBusy();
}

void StartResetFailedBackupBlocks(void) {
    SetBackupBusy();
    QueueThreadFunction(ResetFailedBackupBlocks);
    gThreadFunctionQueue->mRunRequested = 1;
}

void SetBackupFlag(s32 flagIndex) {
    u8 *flagBytes;

    flagBytes = data_0217aa08->mFirstBlock->mFlags;
    flagBytes[flagIndex >> 3] |= 1 << (flagIndex & 7);
}

BOOL func_02056e00(s32 bitIndex, u8 *bytes) {
    u32 isSet;

    isSet = 1;
    if (((1 << (bitIndex & 7)) & bytes[bitIndex >> 3]) == 0) {
        isSet = 0;
    }
    return isSet;
}

BOOL IsBackupFlagSet(u32 flagIndex) {
    return func_02056e00(flagIndex, data_0217aa08->mFirstBlock->mFlags);
}

u8 func_02056dac(u8 *bytes) {
    u8 result;

    result = 1;
    if (func_02056e00(0x13, bytes)) {
        result = 4;
    } else if (func_02056e00(0x12, bytes)) {
        result = 3;
    } else if (func_02056e00(0x11, bytes)) {
        result = 2;
    }
    return result;
}

u8 func_02056d98(void) {
    return func_02056dac(data_0217aa08->mFirstBlock->mFlags);
}

void func_02056d54(u32 value) {
    u8 *flagBytes;

    if (value > 3) {
        flagBytes = data_0217aa08->mFirstBlock->mFlags;
        flagBytes[2] |= 8;
    }
    if (value > 2) {
        flagBytes = data_0217aa08->mFirstBlock->mFlags;
        flagBytes[2] |= 4;
    }
    if (value > 1) {
        flagBytes = data_0217aa08->mFirstBlock->mFlags;
        flagBytes[2] |= 2;
    }
}

#pragma thumb off

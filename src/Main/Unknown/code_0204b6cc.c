#include "Main/Unknown/code_0204b6cc.h"
#include "Main/Unknown/code_0204b714.h"
#include "01/code_021956dc.h"

#pragma thumb on

void StartBackupReadOneCopy(u32 address, void *destination, u32 byteCount, void (*callback)(u32, u32),
                            u32 expectedFirstWord) {
    u32 v4 = expectedFirstWord;
    u32 started = StartBackupRead(address, destination, byteCount, (void (*)(u32 *, u32))(callback), 0x0u, v4, 0x0u);
}

void StartBackupReadTwoCopies(u32 firstAddress, u32 secondAddress, u32 *destination, u32 byteCount,
                              void (*callback)(u32, u32), u32 expectedFirstWord, s32 hasPrefix) {
    gBackupAccess->mSecondPassAddress = secondAddress;
    StartBackupRead(firstAddress, destination, byteCount, (void (*)(u32 *, u32)) callback, 1, expectedFirstWord,
                    hasPrefix);
}

#pragma thumb off

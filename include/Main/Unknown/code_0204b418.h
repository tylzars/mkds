#pragma once

#include "types.h"

void StartBackupWriteOneCopy(u32 address, void *source, u32 byteCount, u32 callback);
void StartBackupWriteTwoCopies(u32 firstAddress, u32 secondAddress, u32 *source, u32 byteCount,
                               void (*callback)(u32, u32), s32 hasPrefix);

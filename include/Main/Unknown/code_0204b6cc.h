#pragma once

#include "types.h"

void StartBackupReadTwoCopies(u32 firstAddress, u32 secondAddress, u32 *destination, u32 byteCount,
                              void (*callback)(u32, u32), u32 expectedFirstWord, s32 hasPrefix);
void StartBackupReadOneCopy(u32 address, void *destination, u32 byteCount, void (*callback)(u32, u32),
                            u32 expectedFirstWord);

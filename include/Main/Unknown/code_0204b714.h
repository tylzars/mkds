#pragma once

#include "types.h"

u32 StartBackupRead(u32 address, u32 *destination, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                    u32 expectedFirstWord, s32 hasPrefix);
void func_0204b7b8(void (*callback)(u32 *, u32));
BOOL CheckBackupBlockPrefix(u8 *cursor);
void InitBackupAccess(void);
void CreateBackupAccess(void *heap);
void func_0204ba7c(void);
void StopFileReadThread(void);
void StartFileReadThread(void);
void RunFileReadThread(void *a);

#pragma once

#include "types.h"

u32 StartBackupWrite(u32 address, u32 *source, u32 byteCount, void (*callback)(u32 *, u32), s32 copyPass,
                     s32 hasPrefix);
u32 func_0204b518(void);
void func_0204b574(void);
void func_0204b5dc(void (*callback)(u32 *, u32));

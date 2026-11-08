#pragma once

#include "types.h"

void func_02056d54(u32 value);
u8 func_02056d98(void);
u8 func_02056dac(u8 *bytes);
BOOL IsBackupFlagSet(u32 flagIndex);
BOOL func_02056e00(s32 bitIndex, u8 *bytes);
void SetBackupFlag(s32 flagIndex);
void StartResetFailedBackupBlocks(void);
void ResetFailedBackupBlocks(void);
void StartReadBackupFirstBlockAndRecords(void);
void ReadBackupFirstBlockAndRecords(void);
void func_02057130(void);

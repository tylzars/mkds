#pragma once

#include "types.h"

void WriteBackupFirstBlockAndWait(void);
void ClearBackupBusy(void);
void SetBackupBusy(void);

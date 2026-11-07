#pragma once

#include "types.h"

typedef struct FSFile FSFile;

void FS_InitFile(FSFile *file);
u32 FS_IsAvailable(void);

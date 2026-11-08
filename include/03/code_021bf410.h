#pragma once

#include "types.h"

typedef struct MessageFile MessageFile;

extern MessageFile *gMessages;

BOOL func_ov003_021bf410(void);
BOOL func_ov003_021bf43c(u32 message, s32 selection, u32 mode);
void func_ov003_021bf4d0(void);

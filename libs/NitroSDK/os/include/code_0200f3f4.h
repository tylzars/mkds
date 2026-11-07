#pragma once

#include "types.h"

// Object at a fixed address in OS_InitException, which sets its word at 0xfdc.
typedef struct Unk0200f4f0 {
    /* 000 */ u8 mUnk_000[0xfdc];
    /* fdc */ UnkFunc *mUnk_fdc;
} Unk0200f4f0;

void OSi_SetExContext(u32 exinfo);
void OSi_DisplayExContext(void);
// Keeps the word at 0x027ffd9c as a saved handler when it lies in 0x02600000-0x027fffff (else clears it). Stores
// OSi_ExceptionHandler at 0x027ffd9c and at 0x027e3fdc unless a saved handler exists and bit 30 of
// OS_GetConsoleType() is set.
// Clears the flag word OSi_UserExceptionHandler.
void OS_InitException(void);

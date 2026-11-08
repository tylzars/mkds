#pragma once

#include "types.h"

typedef struct Unk021da178 {
    /* 00 */ u32 mMode : 4;
} Unk021da178;

extern void (*gUpdateFunction)(void);

#include "03/unk_021da000.h"

extern Unk021da178 data_ov003_021da178;
extern s32 data_ov003_021da180[4];

void func_ov003_021c209c(void);
BOOL func_ov003_021c20a8(u32 mask);
u32 GetMode(void);
u8 GetLanguageIndex(void);
void func_ov003_021c20dc(s32 *first, s32 *second);
void func_ov003_021c20f8(u32 third, u32 fourth);
void func_ov003_021c2104(s32 *first, s32 *second);
void func_ov003_021c2120(u32 first, u32 second);
void SetUpdateFunction(void (*callback)(void));
void func_ov003_021c2138(void);
void func_ov003_021c2188(void);
void func_ov003_021c2398(void);
BOOL func_ov003_021c2440(s32 languageIndex, u32 modeAndFlags);
s32 func_ov003_021c2494(void *memoryBlock, s32 languageIndex, u32 modeAndFlags);
// Not decompiled yet.

#pragma once

#include "types.h"

extern u8 data_ov003_021da110[];

u32 GetLanguageTextFlags(void);
void PrintMessageAndText(u32 text, u32 messageIndex);
void PrintMessage(u32 messageIndex);
void func_ov003_021bf5c8(u32 variant);
void func_ov003_021bf5ec(u32 a);
unsigned int LoadFileToVram(void *path, void *loader);
u8 *BuildFilePathWithLanguage(const u8 *path);

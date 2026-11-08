#pragma once

#include "types.h"

extern const char *gBackScreenSNclrNames[1];
extern const char *gBackScreenSNcgrNames[1];
extern const char *gBackScreenSNscrNames[1];
extern const char *gBackScreenMNscrNames[2];
extern const char *gBackScreenMNcgrNames[2];
extern const char *gBackScreenMNclrNames[2];

void LoadTxtSystemAndSelectChoisesAndSelectReturnData(void);
void func_02125ba4(void);
s32 LoadBackScreen(s32 subCharOffset);

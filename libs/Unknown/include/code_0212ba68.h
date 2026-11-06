#pragma once

#include "types.h"
#include "code_0214f4a4.h" // PMSleepCallbackInfo

extern s8 data_0217d414;
extern u32 data_0217d418;
extern u32 data_0217d41c;
extern PMSleepCallbackInfo data_0217d420;
extern PMSleepCallbackInfo data_0217d42c;

void NNS_SndSetMasterVolume(int volume);
void NNS_SndMain(void);
void NNS_SndInit(void);

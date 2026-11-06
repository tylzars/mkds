#pragma once

#include "types.h"

extern u32 data_0217d438;
extern u32 data_0217d43c;
extern u32 data_0217d440;

void NNSi_SndInitResourceMgr(void);
void NNS_SndFreeAlarm(s32 alarm);
s32 NNS_SndAllocAlarm(void);
void NNS_SndUnlockCapture(u32 captures);
BOOL NNS_SndLockCapture(u32 captures);
void NNS_SndUnlockChannel(u32 channels);
BOOL NNS_SndLockChannel(u32 channels);

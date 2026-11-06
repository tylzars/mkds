#pragma once

#include "types.h"

void WvrDummyAsyncCallback(void);
void WvrReceiveCallback(u32 tag, u32 data);
s32 WVR_TerminateAsync(UnkFunc *callback, u32 arg);
s32 WVR_StartUpAsync(u32 vram, UnkFunc *callback, u32 arg);

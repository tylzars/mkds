#pragma once

#include "types.h"
#include "00/code_0218f960.h"
#include "00/code_021965a0.h"
#include "00/code_02193000.h"
#include "00/code_021a3000.h"
#include "00/code_021906e4.h"

u32 GpiCallQueuedCallbacks(GpConnection *a, s32 b);
void GpiCallAndFreeCallback(GpConnection *a, GpiQueuedCallback *data);
u32 GpiQueueCallback(GpConnection *a, GpiCallback b, void *c, GpiOperation *d, s32 e);
void GpiQueueErrorCallback(GpConnection *a, s32 result, s32 fatal);

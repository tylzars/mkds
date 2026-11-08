#pragma once

#include "types.h"
#include "Main/Unknown/code_02009928.h"
#include "Main/Unknown/code_0200a000.h"
#include "Main/Unknown/code_0200ad00.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_02142eac.h"

int SendMPData(void *data, u32 size, u32 childMask);
s32 SetMPDataToPort(Unk021425e8Func callback, void *data, s32 dataSize, u16 d, u16 e);

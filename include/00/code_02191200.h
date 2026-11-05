#pragma once

#include "types.h"
#include "00/code_02190000.h"
#include "00/code_0218f960.h"

int func_ov000_02191200(GpConnection *a);
u32 GpiProcessConnectOperation(GpConnection *a, GpiOperation *b, const char *c);
u32 GpiWriteNewuser(GpConnection *a, Unk02191284Data *b);
// Declared here until the code that defines them is decompiled.

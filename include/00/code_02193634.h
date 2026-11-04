#pragma once

#include "types.h"

// Declared here until the code that defines them is decompiled.

#include "00/code_0218f960.h"

#include "00/code_021906e4.h"
#include "00/code_021947e4.h"
#include "00/code_02196914.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "code_02135014.h"
#include "code_02139f70.h"
#include "code_02134d30.h"
#include "code_0213a460.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218d818.h"
#include "00/code_02196000.h"
#include "00/code_02190000.h"
#include "00/code_02194bb8.h"
#include "00/code_02193b88.h"
#include "00/code_021965a0.h"
#include "00/code_021967b4.h"

u32 GpiIsValidDate(int a, int b, int c);
s32 GpiProcessOperation(GpConnection *c, GpiOperation *d, const char *e);
BOOL func_ov000_021937c0(GpConnection *object);
BOOL GpiFindOperation(GpConnection *object, GpiOperation **output, u32 key);
void GpiRemoveOperation(GpConnection *param_1, GpiOperation *param_2);
void GpiDeleteOperation(GpConnection *param_1, GpiOperation *param_2);
s32 GpiQueueOperationCallback(GpConnection *connection, GpiOperation *operation);

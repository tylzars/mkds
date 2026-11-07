#pragma once

#include "types.h"
#include "Main/Unknown/code_02007148.h"
#include "Main/Unknown/code_02007624.h"
#include "Main/Unknown/code_02007ea0.h"
#include "Main/Unknown/code_02009000.h"
#include "Main/Unknown/code_02009928.h"
#include "Main/Unknown/code_02009adc.h"
#include "Main/Unknown/code_0200ad00.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_02161000.h"
#include "code_021453ec.h"
#include "code_0214c778.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"

extern u16 gWirelessDmaNo;
extern void *gWMSysBuf;
extern u16 *data_usa_021617a0;
extern u32 data_usa_021617a4;

s32 func_02009cc8(u16 a);
s32 StartParentOnChannel(u16 a);
s32 StartWirelessInitialize(void);
u32 SetMPLimits(u32 a, u32 b);
u32 IsMPSizeValid(u32 a, u32 b, u32 c);
s32 InitWirelessWork(void *a, Unk02009ff4 *b, u32 c, u32 d, u32 e);
u32 GetBeaconDispersion(void);
void ChildCallback(Unk021425e8 *a);
void ChildPortCallback(Unk021425e8 *a);
void ParentCallback(Unk021425e8 *a);

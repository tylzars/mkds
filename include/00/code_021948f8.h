#pragma once

#include "types.h"
#include "00/code_0218d000.h"
#include "00/code_0218eb9c.h"
#include "00/code_0218e0e0.h"
#include "00/code_0218f960.h"
#include "00/code_02190000.h"
#include "00/code_02193000.h"
#include "00/code_021947e4.h"
#include "00/code_0219210c.h"
#include "00/code_021a3000.h"

extern char data_ov000_021b354c[];
extern char data_ov000_021b3554[];
extern char data_ov000_021b3564[];
extern char data_ov000_021b356c[];
extern char data_ov000_021b359c[];
extern u8 data_ov000_021b35a8[];

void func_ov000_021948f8(GpConnection *a, Unk02194934 *b);
void func_ov000_0219490c(GpConnection *a, u32 b);
u32 func_ov000_02194934(GpConnection *a, u32 b, Unk02194934 **c);
Unk02194934 *func_ov000_0219496c(GpConnection *a, s32 b);
s32 func_ov000_02194a0c(GpConnection *a, Unk021937c0Node *b, const char *c);
BOOL func_ov000_02194af4(GpConnection *a);
void func_ov000_02194b4c(Unk02194934 *a);

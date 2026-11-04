#pragma once

#include "types.h"
#include "00/code_0218d000.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0218e0e0.h"
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

void GpiRemoveProfile(GpConnection *a, GpiProfile *b);
void GpiRemoveProfileById(GpConnection *a, u32 b);
u32 GpiFindProfile(GpConnection *a, u32 b, GpiProfile **c);
GpiProfile *GpiFindOrAddProfile(GpConnection *a, s32 id);
s32 func_ov000_02194a0c(GpConnection *a, GpiOperation *b, const char *c);
BOOL GpiInitProfileList(GpConnection *a);
void GpiReleaseProfile(GpiProfile *a);

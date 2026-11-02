#pragma once

#include "types.h"
#include "01/code_02185000.h"
#include "Main/Unknown/code_0209b000.h"
#include "01/code_02185ef4.h"
#include "01/code_0219b250.h"
#include "01/code_0218155c.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020e6fd4.h"

extern Unk0219b250 *gMissionGate;

void func_ov001_02185b64(void);
void func_ov001_02185b7c(void);
void func_ov001_02185b98(void);
void func_ov001_02185bb8(void *a, Unk02185bb8 *b);
void func_ov001_02185c4c(Unk02185c4c *a);
void func_ov001_02185ca0(void *a, Unk02185bb8 *b);
void func_ov001_02185d18(void);
void LoadMissionGate(void *a);
u32 func_ov001_02185d74(Unk02185bb8 *c, Unk02185d74 *d, u8 *e, u8 *f);
void func_ov001_02185dd0(Unk02185bb8 *a);

#include "01/code_0219b540.h"

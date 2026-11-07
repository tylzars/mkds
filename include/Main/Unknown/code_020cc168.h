#pragma once

#include "types.h"

typedef struct Unk02180774 Unk02180774;

s32 GetRaceSetupMissionTableRow(void);
s32 GetRaceSetupMissionTableColumn(void);
void CopyCurrentToRaceSetupCopy(void);
void CopyMenuScreenCallbacks(void);
void func_020cc36c(void);
void SetMainBg0Record(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_020cc2f4(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_020cc2c0(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_020cc28c(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void SetSubBg0Record(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void SetSubBg1Record(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_020cc1e0(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_020cc1ac(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_020cc18c(u32 a);
void SetSubDispcntBits(u32 a);

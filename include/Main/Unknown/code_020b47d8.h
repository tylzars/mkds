#pragma once

#include "types.h"
#include "Main/Unknown/code_020b4000.h" // Nscr, Ncgr, Nclr
#include "code_02021db0.h" // Unk02021dc8
#include "code_02021f9c.h" // Unk02021f9c

void LocateNscr(Nscr **out, void *a);
void LoadNscrData(Nscr **out, void *a);
void LoadNanrData(Unk02021dc8 **out, void *a);
void LocateNcer(Unk02021dc8 **out, void *a);
void LoadNcerData(Unk02021dc8 **out, void *a);
void LocateNcgr(Ncgr **out, void *a);
void LoadNcgrData(Ncgr **out, void *a);
void LocateNcgr2(Ncgr **out, void *a);
void LoadNcgrData2(Ncgr **out, void *a);
void LocateNclr(Nclr **out, void *a);
void LoadNclrData(Nclr **out, void *a);
BOOL func_020b4acc(void);
s32 func_020b4b10(void);
BOOL func_020b4b54(void);
BOOL func_020b4b98(s32 a);
void Matrix2x2RotationReciprocalScale(s32 *a, s32 b, s32 c);
void func_020b4c74(s32 *a, s32 b);
void Matrix2x2Rotation(s32 *a, s32 b);
void Matrix2x2ReciprocalScale(s32 *a, s32 b);
u16 func_020b4d2c(void);
u16 func_020b4d9c(void);

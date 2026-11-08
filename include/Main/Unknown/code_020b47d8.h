#pragma once

#include "types.h"
#include "Main/Unknown/code_020b4000.h" // Nscr, Ncgr, Nclr
#include "g2d_NAN_load.h" // Unk02021dc8
#include "g2d_NSC_load.h" // Unk02021f9c

void LocateNscr(Nscr **out, void *file);
void LoadNscrData(Nscr **out, void *file);
void LoadNanrData(Unk02021dc8 **out, void *file);
void LocateNcer(Unk02021dc8 **out, void *file);
void LoadNcerData(Unk02021dc8 **out, void *file);
void LocateNcgr(Ncgr **out, void *file);
void LoadNcgrData(Ncgr **out, void *file);
void LocateNcgr2(Ncgr **out, void *file);
void LoadNcgrData2(Ncgr **out, void *file);
void LocateNclr(Nclr **out, void *file);
void LoadNclrData(Nclr **out, void *file);
BOOL IsLanguageJa(void);
s32 GetLanguageCharSpacing(void);
BOOL RaceStartIsLanguageJa(void);
BOOL func_020b4b98(s32 number);
void Matrix2x2RotationReciprocalScale(s32 *matrix, s32 scale, s32 angle);
void Matrix2x2ReflectedRotation(s32 *matrix, s32 angle);
void Matrix2x2Rotation(s32 *matrix, s32 angle);
void Matrix2x2ReciprocalScale(s32 *matrix, s32 scale);
u16 GetFollowedKartLastEndedLap(void);
u16 GetFollowedKartOrEntryIndex(void);

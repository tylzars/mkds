#pragma once

#include "types.h"

typedef struct MissionGateObject MissionGateObject;

u16 func_ov001_02185b50(MissionGateObject *missionGateObject);
void func_ov001_02185b1c(void);
void UpdateMissionRunLVsel(void);
void func_ov001_02185ad8(u32 bits);
void func_ov001_02185abc(u32 bits);
void func_ov001_02185a88(void);
void UpdateMissionRunMSsel(void);
void func_ov001_02185a28(void);
void SetGhostSceneInitialCallbacksIndex(s32 callbacksIndex);
void UpdateTimeAttackTopMenu(void);
void func_ov001_02185980(void);
void UpdateTimeAttackSelectCharacter(void);
void func_ov001_02185928(void);
void UpdateTimeAttackSelectKart(void);
void func_ov001_021858c8(void);
void func_ov001_021858b4(s32 value);
void func_ov001_021858a0(s32 value);
void UpdateTimeAttackSelectCupGrid(void);
void func_ov001_02185828(void);
void UpdateTimeAttackSelectCupCourse(void);
void WriteMainBg1Offset(u32 offsetX, u32 offsetY);
void func_ov001_021857a4(u32 bits);

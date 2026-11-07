#pragma once

#include "types.h"

typedef struct MissionGateObject MissionGateObject;
typedef struct Unk02185d74 Unk02185d74;
typedef struct Unk02185c4c Unk02185c4c;
typedef struct Unk0219b250 Unk0219b250;

void func_ov001_02185b64(void);
void func_ov001_02185b7c(void);
void func_ov001_02185b98(void);
void UpdateMissionGate(void *a, MissionGateObject *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitMissionGateObjects(Unk02185c4c *a);
void DrawMissionGate(void *a, MissionGateObject *b);
void func_ov001_02185d18(void);
void LoadMissionGate(void *a);
u32 func_ov001_02185d74(MissionGateObject *c, Unk02185d74 *d, u8 *e, u8 *f);
void InitMissionGate(MissionGateObject *a);

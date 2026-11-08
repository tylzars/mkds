#pragma once

#include "types.h"

typedef struct MissionGateObject MissionGateObject;
typedef struct Unk02185d74 Unk02185d74;
typedef struct MissionGateList MissionGateList;
typedef struct Unk0219b250 Unk0219b250;

void CreateMissionGateUpdateList(void);
void CreateMissionGateDrawList(void);
void CreateMissionGateKindData(void);
void UpdateMissionGate(
    void *a, MissionGateObject *missionGateObject); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitMissionGateObjects(MissionGateList *missionGateList);
void DrawMissionGate(void *mapObjectList, MissionGateObject *missionGateObject);
void func_ov001_02185d18(void);
void LoadMissionGate(void *a);
u32 CollideKartWithMissionGate(MissionGateObject *missionGateObject, Unk02185d74 *kart, u8 *e, u8 *f);
void InitMissionGate(MissionGateObject *missionGateObject);

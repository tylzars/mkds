#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct MapObject MapObject;

// Collision response 7 of data_0217ac18 (indexed by the value func_020d6be0 returns for the kart and the map object):
// runs TryStartKartState3 and, when it starts, for the selected kart increments the counter of the record
// GetEntryKartCounters returns and sets bit 0x20000 of mUnk_48. Stores 7 through the second parameter and returns 2.
int CollideKartWithMapObjectResponse7(Kart *p, s32 *a);
// Collision response 5 of data_0217ac18 (indexed by the value func_020d6be0 returns for the kart and the map object):
// runs func_0206bcb0 with 2 and, when that succeeds, passes the result of StartEffect with 0x4f at mPos to
// SetupKartFollowEffectWithVelocity with the kart index and 0x46 if bit 0x10 of mUnk_7c is set and, for the selected
// kart, increments the counter of the record GetEntryKartCounters returns. Stores 5 through the second parameter and
// returns 0.
int CollideKartWithMapObjectResponse5(Kart *p, s32 *a);
// Collision response 6 of data_0217ac18 (indexed by the value func_020d6be0 returns for the kart and the map object):
// when mVelocityLength of the kart is above 0x3000 or flag 0x200 of mFlags of the object is set it runs func_0206bcb0
// with 2 and, when that succeeds, for the selected kart increments the counter of the record GetEntryKartCounters
// returns and runs func_020812d0 with the kart index; it then stores 4 through the second parameter. Otherwise it
// stores 0. Returns 0.
int CollideKartWithMapObjectResponse6(Kart *p, s32 *a, MapObject *c);
// Collision response 4 of data_0217ac18 (indexed by the value func_020d6be0 returns for the kart and the map object):
// when mVelocityLength of the kart is above 0x3000 or flag 0x200 of mFlags of the object is set it runs func_0206bcb0
// with 2 and, when that succeeds, calls StartEffect with 0xc, 0xd and 0xe at mPos unless the mUnk_058 member of
// mKartModelsEntry is non-zero and, for the selected kart, increments the counter of the record GetEntryKartCounters
// returns; it then stores 4 through the second parameter. Otherwise it stores 2. Returns 0xb.
int CollideKartWithMapObjectResponse4(Kart *p, s32 *a, MapObject *c);
// Collision response 3 of data_0217ac18 (indexed by the value func_020d6be0 returns for the kart and the map object):
// when mVelocityLength of the kart is above 0x3000 or flag 0x200 of mFlags of the object is set it runs func_0206bcb0
// with 1 and, when that succeeds, calls StartEffect with 0xc, 0xd and 0xe at mPos unless the mUnk_058 member of
// mKartModelsEntry is non-zero and, for the selected kart, increments the counter of the record GetEntryKartCounters
// returns; it then stores 3 through the second parameter. Otherwise it stores 2. Returns 0xb.
int CollideKartWithMapObjectResponse3(Kart *p, s32 *a, MapObject *c);

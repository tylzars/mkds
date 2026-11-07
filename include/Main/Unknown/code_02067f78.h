#pragma once

#include "types.h"

// Collision response 2 of data_0217ac18 (indexed by the value func_020d6be0 returns for the kart and the map object):
// stores 2 through the second parameter and returns 0xb.
u32 CollideKartWithMapObjectResponse2(u32 arg0, u32 arg1);
// Collision response 0 of data_0217ac18 (indexed by the value func_020d6be0 returns for the kart and the map object):
// stores 0 through the second parameter and returns 0. Same bytes as CollideKartWithMapObjectNoResponse, the table
// entry for index 1.
u32 CollideKartWithMapObjectResponse0(u32 arg0, u32 arg1);

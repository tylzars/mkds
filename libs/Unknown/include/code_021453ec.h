#pragma once

#include "types.h"
#include "code_02142eac.h" // Unk021425e8Func

// Copy of the game info that WM_SetGameInfo sends.
extern u8 data_0217f960[0x80];

int WM_SetEntry(Unk021425e8Func callback, BOOL enabled);
int WM_MeasureChannel(Unk021425e8Func callback, u16 ccaMode, u16 edThreshold, u16 channel, u16 measureTime);
int WM_SetLifeTime(Unk021425e8Func callback, u32 tableNumber, u32 camLifeTime, u32 frameLifeTime, u16 mpLifeTime);
int WM_SetBeaconIndication(Unk021425e8Func callback, u16 flag);
int WM_SetGameInfo(Unk021425e8Func callback, const void *userGameInfo, u16 userGameInfoSize, u32 ggid, u16 tgid,
                   u8 attr);
int WM_SetWEPKeyEx(Unk021425e8Func callback, u16 wepmode, u16 wepkeyid, void *wepkey);
int WM_SetWEPKey(Unk021425e8Func callback, u32 wepmode, void *wepkey);

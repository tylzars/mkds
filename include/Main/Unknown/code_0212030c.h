#pragma once

#include "types.h"

// Seven pairs of functions passed to func_02046be8 by InitWiFiSession.
extern UnkFunc *data_0216e21c[14];

u32 func_021205e8(void);
void InitWiFiSession(void *heap);
void CreateWiFiSessionHeap(void *heap);
void DeleteWiFiSessionHeap(void);
void func_021204d0(void);
void UpdateBuddyStatuses(void);
void UpdateWiFiSession(void);
s32 func_02120340(u32 a, void *b, s32 c, u32 (*d)(void));
void *GetWiFiSessionPlayerRecordData(u32 index);

#pragma once

#include "types.h"
#include "code_02142eac.h"
#include "code_021445e0.h"
#include "Main/Unknown/unk_0217e000.h"

Unk02142988 *WMi_GetStatusAddress(void);
void WmClearFifoRecvFlag(void);
void WmReceiveFifo(u32 tag, Unk021425e8 *callback, s32 err);
s32 WMi_CheckStateEx(s32 paramNum, ...);
s32 WMi_CheckIdle(void);
s32 WMi_CheckInitialized(void);
Unk02142aa8 *WMi_GetSystemWork(void);
s32 WMi_SendCommand(u32 id, u16 paramNum, ...);
void WMi_SetCallbackTable(u32 id, Unk021425e8Func callback);
s32 WM_Finish(void);
s32 WmInitCore(void *wmSysBuf, u16 dmaNo, u32 bufSize);
s32 WM_Init(void *wmSysBuf, u16 dmaNo);

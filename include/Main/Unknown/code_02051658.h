#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h" // ScanSlot, ScanBlockView, Unk0217aa00_24_50
#include "code_02142eac.h" // Unk021425e8

void SetGameInfo(void);
void StartDataSharing(void);
void SetEntryCallback(Unk021425e8 *event);
void SetEntry(s32 enabled);
void SetMPFrequencyCallback(Unk021425e8 *event);
void SetMPFrequency(u32 mpFreq);
void StartMPCallback(Unk021425e8 *event);
void StartMP(void);
void StartConnectCallback(Unk021425e8 *event);
void StartConnect(ScanBlockView *a, void *b, s32 (*c)(), s32 (*d)(), s32 (*e)());
void EndScanCallback(Unk021425e8 *event);
void EndScan(void);
void StartScanCallback(Unk021425e8 *event);
void FindOrAddScanSlot(ScanBlockView *scanBuffer, Unk0217aa00_42c *key, Unk0217aa00_24_50 *c);
void func_020525a8(ScanSlot *slot, ScanBlockView *scanBuffer, Unk0217aa00_42c *key, Unk0217aa00_24_50 *d, u8 e);
void StartScan(s32 a, s32 (*b)(), s32 (*c)());

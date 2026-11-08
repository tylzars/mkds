#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h" // Unk0217aa00_0ac, ScanBlockView, Unk0217aa00_24_50
#include "code_02142eac.h" // Unk021425e8

void SetGameInfo(void);
void StartDataSharing(void);
void SetEntryCallback(Unk021425e8 *a);
void SetEntry(s32 a);
void SetMPFrequencyCallback(Unk021425e8 *a);
void SetMPFrequency(u32 a);
void StartMPCallback(Unk021425e8 *a);
void StartMP(void);
void StartConnectCallback(Unk021425e8 *a);
void StartConnect(ScanBlockView *a, void *b, s32 (*c)(), s32 (*d)(), s32 (*e)());
void EndScanCallback(Unk021425e8 *a);
void EndScan(void);
void StartScanCallback(Unk021425e8 *a);
void func_02052288(ScanBlockView *a, Unk0217aa00_42c *b, Unk0217aa00_24_50 *c);
void func_020525a8(Unk0217aa00_0ac *a, ScanBlockView *b, Unk0217aa00_42c *c, Unk0217aa00_24_50 *d, u8 e);
void StartScan(s32 a, s32 (*b)(), s32 (*c)());

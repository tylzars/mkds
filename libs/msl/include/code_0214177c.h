#pragma once

#include "types.h"
#include "code_0213ee6c.h" // Unk02136638

// Byte table indexed by bytes below 0x80; read by func_02142374.
extern const u8 data_0215d184[];

void func_0214177c(Unk02136638 *out, int n);
void func_02141b5c(Unk02136638 *out, const u8 *s, int n);
void func_02141c98(Unk02136638 *out, const Unk02136638 *a, const Unk02136638 *b);
void func_02141f14(Unk02136638 *out, u64 v);
void func_021420c0(Unk02136638 *a, int n);
void func_0214214c(Unk02136638 *a, int n);
int func_02142224(const Unk02136638 *a, int n);
int func_021422a0(u32 a);
int func_02142368(const u8 *a, const u8 *b);
int func_02142374(const u8 *a, const u8 *b);

#pragma once

#include "types.h"
#include "code_0200e77c.h"
#include "code_0212c7f0.h" // Unk0212c7f0
#include "code_0212da38.h" // Unk02017328

struct Unk02005210;
struct Unk02142aa8;
struct Unk021425e8;

// The object that func_02142c98 sets up.
extern struct Unk02142aa8 *data_0217eed4;
extern u16 data_0217eed0;
extern Unk0200eb90 data_0217eed8;
// Word array that func_02142c98 gives data_0217eed8, an object func_021425e8 fills in before calling the function
// pointers, and the ten 0x100-byte buffers func_02142c98 passes to func_0200eae8.
extern void *data_0217eef8[10];
extern struct Unk021425e8 data_0217ef20;
extern u8 data_0217ef60[10][0x100];
extern struct Unk02005210 *data_0217eeb0;
// Function pointers called and cleared by func_02133e50 (data_0217e984) and func_02133f84 (data_0217e988).
extern void (*data_0217e984)(void);
extern void (*data_0217e988)(void);
// Count of the entries of data_0217e994 that func_02133e50 calls, last first.
extern int data_0217e98c;
// Set by func_02133fd8; func_02133f84 reads it.
extern int data_0217e990;
extern void (*data_0217e994[])(void);
// Word arrays; func_02133e50 uses entry 0 of each, fwrite entries 3-5, printf entry 3 and
// func_02139e20 entry 7.
extern u32 data_0217ea94[];
extern u32 data_0217eab8[];
// 0x14-byte entries passed to func_0200ec08, func_0200ecc4 and func_0200ed34; func_02133e50 uses entry 0,
// fwrite entries 3-5, printf entry 3 and func_02139e20 entry 7.
extern u8 data_0217eadc[][0x14];
extern u8 data_0217e3e0[];
extern Unk02017328 data_0217e3f8;
extern Unk0212c7f0 data_0217e404[4];

#pragma once

#include "types.h"
#include "code_0212c7f0.h" // Unk0212c7f0
#include "code_0212d214.h"

typedef struct OSMutex OSMutex;

typedef struct OSMessageQueue OSMessageQueue;

struct Unk02005210;
struct Unk02142aa8;
struct Unk021425e8;

// System work area set up by WmInitCore.
extern struct Unk02142aa8 *data_0217eed4;
// Nonzero while the library is set up.
extern u16 data_0217eed0;
// Ring of free command messages.
extern OSMessageQueue data_0217eed8;
extern void *data_0217eef8[10];
// Message WmReceiveFifo builds for the port callbacks on connect and disconnect.
extern struct Unk021425e8 data_0217ef20;
// The ten 0x100-byte command messages.
extern u8 data_0217ef60[10][0x100];
extern struct Unk02005210 *data_0217eeb0;
// Function pointers called and cleared by ExitTail (data_0217e984) and exit (data_0217e988).
extern void (*data_0217e984)(void);
extern void (*data_0217e988)(void);
// Count of the entries of gExitFunctions that ExitTail calls, last first.
extern int gExitFunctionCount;
// Set by abort; exit reads it.
extern int gAborted;
extern void (*gExitFunctions[])(void);
// Word arrays; ExitTail uses entry 0 of each, fwrite entries 3-5, printf entry 3 and
// raise entry 7.
extern u32 data_0217ea94[];
extern u32 data_0217eab8[];
// 0x14-byte entries passed to OS_TryLockMutex, OS_UnlockMutex and OS_LockMutex; ExitTail uses entry 0,
// fwrite entries 3-5, printf entry 3 and raise entry 7. An OSMutex is 0x18 bytes, so OSMutex.mPrev of one entry is
// the start of the next entry.
extern u8 data_0217eadc[][0x14];
extern OSMutex data_0217e3e0;
extern LinkedList data_0217e3f8;
extern Unk0212c7f0 data_0217e404[4];

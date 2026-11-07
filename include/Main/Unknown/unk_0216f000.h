#pragma once

#include "types.h"
#include "code_0200db4c.h"
#include "code_02142eac.h" // Unk02143a78

// Three words that func_0200c448 sets up.
typedef struct Unk0216fdf8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk0216fdf8;

// Object behind data_0216fdf4: the words from 0x1e0 on are indexed like the 0x20-byte entries before them.
typedef struct Unk0216fdf4 {
    /* 000 */ u8 mUnk_000[0x1e0];
    /* 1e0 */ u32 mUnk_1e0[15];
} Unk0216fdf4;

// Objects whose layout isn't known yet.
extern u32 data_0216f06c;
extern char data_0216f2a0[];
extern s8 data_0216f2b0[];
extern const char data_0216f2d4[];
extern u32 gBlockTransferStarted;
extern u8 data_0216f3cc[];
extern s16 gReceiveChunkSize;
extern s16 gSendChunkSize;
struct BlockListNode;
extern struct BlockListNode *data_0216f3d8;
extern u8 gBlockTransfer[];
extern u8 gNextRequest[];
struct WirelessWork;
extern struct WirelessWork *gWirelessWork;
struct Unk0216fdac;
extern struct Unk0216fdac *data_0216fdac;
struct Unk0200aeec_head;
extern struct Unk0200aeec_head *data_0216fde0;
extern u8 gScanConnectInitialized[];
struct ScanConnectWork;
extern struct ScanConnectWork *gScanConnectWork;
struct MPLink;
extern struct MPLink *gMPLink;
struct Unk0216fdf4;
extern struct Unk0216fdf4 *data_0216fdf4;
extern u8 data_0216fdf0;
extern Unk0216fdf8 data_0216fdf8;
extern u8 data_0216f2dc[];
extern u8 OverlaySignatures[][0x14];

// 1 while the main display is on; GX_DispOff clears it, GX_DispOn sets it, GX_SetGraphicsMode writes mode 0 while it is
// 0 and clears it when its first argument is 0. Initial value 1.
extern u8 gDispOn[];
extern u32 data_0216f074[];
extern void (*data_0216fc34)(void);
extern void (*data_0216fc38)(u8 *);
extern Unk02143a78 gScanParams;

extern u32 data_0216ff44;
extern u32 data_0216ff48;
// The number OSi_GetUnusedThreadId last returned.
extern u32 gThreadIdCount;
extern void (*data_0216ff50)(OSThread *, OSThread *);
extern OSThread **data_0216ff54;
extern u32 data_0216ff58;
extern ThreadSystem data_0216ff5c;
extern OSThread data_0216ff6c;

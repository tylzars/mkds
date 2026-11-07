#pragma once

#include "types.h"

// The word sent through the FIFO: tag, err flag and data.
typedef struct PxiWord {
    /* 00 */ u32 mTag : 5;
    /* 00 */ u32 mErr : 1;
    /* 00 */ u32 mData : 26;
} PxiWord;

// Callback for a FIFO tag: called with the tag, the data and the err flag. Left unprototyped because the game's
// callbacks declare fewer or different parameter types.
typedef void (*PXIFifoCallback)();

// Fixed-address object; PXI_IsCallbackReady and PXI_SetFifoRecvCallback read and write mPxiHandleChecker.
typedef struct Unk027ffc00 {
    /* 000 */ u8 mUnk_000[0x388];
    /* 388 */ u32 mPxiHandleChecker[2];
} Unk027ffc00;

extern PXIFifoCallback data_0218032c[32];
extern u16 data_02180328;

void PXI_Init(void);
void PXIi_HandlerRecvFifoNotEmpty(void);
s32 PXI_SendWordByFifo(s32 fifotag, u32 data, s32 err);
s32 PXI_IsCallbackReady(s32 fifotag, s32 proc);
void PXI_SetFifoRecvCallback(s32 fifotag, PXIFifoCallback callback);
void PXI_InitFifo(void);

#pragma once

#include "types.h"
#include "code_0200c914.h"

typedef void (*MIDmaCallback)(void *arg);

// State of the GX command transfer in progress, set up by MI_SendGXCommandAsync and MI_SendGXCommandAsyncFast.
typedef struct MIiGXDmaParams {
    /* 00 */ vu32 mIsBusy;
    /* 04 */ u32 mDmaNo;
    /* 08 */ const u8 *mSrc;
    /* 0c */ u32 mLength;
    /* 10 */ MIDmaCallback mCallback;
    /* 14 */ void *mArg;
    /* 18 */ u32 mFifoCond;
    /* 1c */ OSIrqFunction mFifoFunc;
} MIiGXDmaParams;

extern MIiGXDmaParams MIi_GXDmaParams;

// Does nothing unless the channel is 0. For channel 0 it calls OS_Terminate when the top byte of the
// source address, or of the address at the other end of the range (source + length, source - length when the mode
// word is 0x800000, the source itself for any other nonzero mode word), is 0x04 or at least 0x08.
void MIi_CheckDma0SourceAddress(u32 dmaNo, const void *src, u32 size, u32 dir);
// Looks at the control word of each of channels 0-2 other than the given one. When one is enabled (bit 31) and its
// start-timing bits (mask 0x38000000) differ from the wanted timing, it calls OS_Terminate for any nonzero
// timing; 0x08000000 and 0x10000000 count as the same timing.
void MIi_CheckAnotherAutoDMA(u32 dmaNo, u32 dmaType);
// Disables interrupts, clears bits 9, 11, 12 and 13 and then bit 15 of the control halfword of the channel
// (0x40000b0 + channel * 12 + 10), reads it twice and, for channel 0, stores the dummy transfer 0, 0, 0x81400001 in
// the channel 0 registers.
void MI_StopDma(u32 dmaNo);
// Disables interrupts, waits until bit 31 of the control word of the channel (0x40000b0 + channel * 12 + 8) is
// clear and, for channel 0, stores the dummy transfer 0, 0, 0x81400001 in the channel 0 registers.
void MI_WaitDma(u32 dmaNo);
// Checks the source range (MIi_CheckDma0SourceAddress, mode 0). With a length of 0 it only calls the callback
// when there is one. Otherwise it waits for the channel (MI_WaitDma) and starts length / 4 words with control
// 0x84000000; with a callback it registers it first (OSi_EnterDmaCallback) and uses 0xc4000000. It returns without
// waiting for the end.
void MI_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg);
// With a length of 0 it only calls the callback when there is one. Otherwise it waits for the channel (MI_WaitDma),
// then with interrupts disabled stores the fill value at 0x40000e0 + channel * 4 and starts length / 4 words from
// that address with control 0x85000000; with a callback it registers it first and uses 0xc5000000. It returns
// without waiting for the end.
void MI_DmaFill32Async(u32 dmaNo, void *dest, u32 data, u32 size, MIDmaCallback callback, void *arg);
// Returns when the length is 0. Otherwise it checks the source range (mode 0), waits until bit 31 of the control
// word of the channel is clear, starts length / 2 halfwords with control 0x80000000
// (StartDmaTransferAndChannel0Dummy) and waits until bit 31 is clear again.
void MI_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size);
// Checks the source range (mode 0) and returns when the length is 0. Otherwise it waits until bit 31 of the control
// word of the channel is clear, starts length / 4 words with control 0x84000000 (StartDmaTransferAndChannel0Dummy)
// and waits until bit 31 is clear again.
void MI_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size);
// Returns when the length is 0. Otherwise it waits until bit 31 of the control word of the channel is clear, then
// with interrupts disabled stores the fill value at 0x40000e0 + channel * 4 and starts length / 4 words from that
// address with control 0x85000000 (StartDmaTransferAndChannel0DummyWithoutIrqDisable), and waits until bit 31 is
// clear again.
void MI_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size);
void MIi_DMAFastCallback(void *arg);
void MI_SendGXCommandAsyncFast(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg);
void MIi_DMACallback(void *arg);
void MIi_FIFOCallback(void);
void MI_SendGXCommandAsync(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg);

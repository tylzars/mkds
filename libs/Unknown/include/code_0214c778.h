#pragma once

#include "types.h"

// Object at data_02180308, set up by GxFifoSendWords and GxFifoSendWordsInPieces.
typedef struct Unk0214ccd4 {
    /* 00 */ vu32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ const u8 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ UnkFunc *mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ UnkFunc *mUnk_1c;
} Unk0214ccd4;

extern Unk0214ccd4 data_02180308;

// Does nothing unless the channel is 0. For channel 0 it calls IrqDisableLoopForever when the top byte of the
// source address, or of the address at the other end of the range (source + length, source - length when the mode
// word is 0x800000, the source itself for any other nonzero mode word), is 0x04 or at least 0x08.
void CheckDma0SourceOrLoopForever(u32 a, const void *b, u32 c, u32 d);
// Looks at the control word of each of channels 0-2 other than the given one. When one is enabled (bit 31) and its
// start-timing bits (mask 0x38000000) differ from the wanted timing, it calls IrqDisableLoopForever for any nonzero
// timing; 0x08000000 and 0x10000000 count as the same timing.
void CheckDmaTimingConflictOrLoopForever(u32 a, u32 b);
// Disables interrupts, clears bits 9, 11, 12 and 13 and then bit 15 of the control halfword of the channel
// (0x40000b0 + channel * 12 + 10), reads it twice and, for channel 0, stores the dummy transfer 0, 0, 0x81400001 in
// the channel 0 registers.
void MI_StopDma(u32 a);
// Disables interrupts, waits until bit 31 of the control word of the channel (0x40000b0 + channel * 12 + 8) is
// clear and, for channel 0, stores the dummy transfer 0, 0, 0x81400001 in the channel 0 registers.
void MI_WaitDma(u32 a);
// Checks the source range (CheckDma0SourceOrLoopForever, mode 0). With a length of 0 it only calls the callback
// when there is one. Otherwise it waits for the channel (MI_WaitDma) and starts length / 4 words with control
// 0x84000000; with a callback it registers it first (OSi_EnterDmaCallback) and uses 0xc4000000. It returns without
// waiting for the end.
void MI_DmaCopy32Async(u32 a, const void *b, void *c, u32 d, UnkFunc *f, u32 arg);
// With a length of 0 it only calls the callback when there is one. Otherwise it waits for the channel (MI_WaitDma),
// then with interrupts disabled stores the fill value at 0x40000e0 + channel * 4 and starts length / 4 words from
// that address with control 0x85000000; with a callback it registers it first and uses 0xc5000000. It returns
// without waiting for the end.
void MI_DmaFill32Async(u32 a, void *b, u32 c, u32 d, UnkFunc *f, u32 arg);
// Returns when the length is 0. Otherwise it checks the source range (mode 0), waits until bit 31 of the control
// word of the channel is clear, starts length / 2 halfwords with control 0x80000000
// (StartDmaTransferAndChannel0Dummy) and waits until bit 31 is clear again.
void MI_DmaCopy16(u32 a, const void *b, void *c, u32 d);
// Checks the source range (mode 0) and returns when the length is 0. Otherwise it waits until bit 31 of the control
// word of the channel is clear, starts length / 4 words with control 0x84000000 (StartDmaTransferAndChannel0Dummy)
// and waits until bit 31 is clear again.
void MI_DmaCopy32(u32 a, const void *b, void *c, u32 d);
// Returns when the length is 0. Otherwise it waits until bit 31 of the control word of the channel is clear, then
// with interrupts disabled stores the fill value at 0x40000e0 + channel * 4 and starts length / 4 words from that
// address with control 0x85000000 (StartDmaTransferAndChannel0DummyWithoutIrqDisable), and waits until bit 31 is
// clear again.
void MI_DmaFill32(u32 a, void *b, u32 c, u32 d);
void GxFifoSendWordsDone(void);
void GxFifoSendWords(u32 a, const void *b, u32 c, UnkFunc *f, u32 arg);
void GxFifoSendWordsInPiecesDone(void);
void GxFifoSendNextPiece(void);
void GxFifoSendWordsInPieces(u32 a, const void *b, u32 c, UnkFunc *f, u32 arg);

#pragma once

#include "types.h"
#include "code_0200db4c.h"

// 0x40 bytes at gRequestBlock; InitBackupAndRomAccess clears it, SetupBackupSpec fills mUnk_04 and mUnk_18 to mUnk_3c.
typedef struct Unk021458b4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
} Unk021458b4;

// 0x620 bytes at gAccessState, set up by InitBackupAndRomAccess; mUnk_44 is started with the 0x400 bytes at mUnk_220.
typedef struct Unk021458c4 {
    /* 000 */ Unk021458b4 *mUnk_00;
    /* 004 */ s32 mUnk_04;
    /* 008 */ vs32 mUnk_08;
    /* 00c */ vs32 mUnk_0c;
    /* 010 */ OSThreadQueue mUnk_10;
    /* 018 */ u32 mUnk_18;
    /* 01c */ u32 mUnk_1c;
    /* 020 */ u32 mUnk_20;
    /* 024 */ u32 mUnk_24;
    /* 028 */ u32 mUnk_28;
    /* 02c */ u32 mUnk_2c;
    /* 030 */ u32 mUnk_30;
    /* 034 */ u32 mUnk_34;
    /* 038 */ UnkFunc *mUnk_38;
    /* 03c */ u32 mUnk_3c;
    /* 040 */ UnkFunc *mUnk_40;
    /* 044 */ OSThread mUnk_44;
    /* 0fc */ u8 mUnk_fc[8];
    /* 104 */ OSThread *mUnk_104;
    /* 108 */ u32 mUnk_108;
    /* 10c */ OSThreadQueue mUnk_10c;
    /* 114 */ vu32 mUnk_114;
    /* 118 */ u8 mUnk_118[8];
    /* 120 */ u8 mUnk_120[0x100];
    /* 220 */ u8 mUnk_220[0x400];
} Unk021458c4;

// 0x220 bytes at gRomReadState: a function pointer, two words, and the 0x200 bytes at mUnk_20 that ReadRomPagesByCpu
// fills.
typedef struct Unk02146154 {
    /* 00 */ UnkFunc *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0x14];
    /* 20 */ u32 mUnk_20[0x80];
} Unk02146154;

// In the comments below, offsets such as +0x114 are from gAccessState unless another object is named, and "the request
// block" is gRequestBlock.
// The 0x40-byte request block: the first word is the result; its address is stored at +0 of gAccessState and sent in
// command 0.
extern Unk021458b4 gRequestBlock;
// Added to the offset of every ROM read in StartRomRead; CARD_Init writes 0 and nothing else writes it.
extern u32 gRomBaseOffset;
// The 0x220-byte ROM read state: the page reader at +0, the control word at +4, the start of the buffered page at +8,
// the page buffer at +0x20.
extern Unk02146154 gRomReadState;

// Sets the lock owner to -3 (free) and the lock count and target to 0, points +0 at gRequestBlock, clears its 0x40
// bytes and flushes them. When the halfword at 0x027ffc40 is not 2, copies 0x160 bytes from 0x027ffe00 to 0x027ffa80.
// Starts the worker thread (stack of 0x400 bytes at +0x220, priority 4, entry WorkerTaskLoop), installs
// ReceiveRequestReply as the tag 11 callback and, unless that halfword is 2, calls CARD_Enable(1).
void InitBackupAndRomAccess(void);
// With interrupts off: calls OS_Terminate unless the id is the owner and the lock count is not 0, and when
// the target differs from the argument. Subtracts 1 from the count; at 0 sets the owner to -3, clears the target and
// makes the threads waiting on the queue at +0x10 runnable. Sets the first word of the request block to 0.
void UnlockAccessTarget(u32 a, u32 b);
// With interrupts off: when the owner is the id the target must equal the argument (else OS_Terminate); when
// another id owns the lock, waits on the queue at +0x10 until the owner is -3, then stores the id as owner and the
// target. Adds 1 to the lock count and sets the first word of the request block to 0.
void LockAccessTarget(u32 a, u32 b);
// Sets the sort key of the worker thread to the priority at +0x108, stores the thread at +0x104 and the task at
// +0x40, sets value 8 of the flag word and makes the thread runnable.
void StartWorkerTask(UnkFunc *f);
// Clears the 0x28 bytes from +0x18 of the request block and stores the device type at +4. For type 0 it stops there.
// Otherwise stores 1 << ((type >> 8) & 0xff) at +0x18 and fills +0x1c to +0x3c from the device kind (type & 0xff, 1
// to 3) and the size; for any other kind or size clears +4 and +0x18 and stores 3 in the first word.
void SetupBackupSpec(s32 a);
// Returns 1 when no transfer is running (value 4 of the flag word at +0x114 is clear), else 0.
int CARD_TryWaitBackupAsync(void);
// Calls WaitForTransferEnd. Called by the save-data code after its backup requests. Has the same body as
// CARD_WaitRomAsync, so only the callers tell the two apart.
int CARD_WaitBackupAsync(void);
// Takes the device type; calls OS_Terminate when it is 0. Waits until no transfer is running and marks one
// running, calls SetupBackupSpec with the type, sends request 2, then request 6 with one try for 1 byte at offset 0
// into the buffer at +0x120, ends the transfer (clears flag values 0x4, 0x8 and 0x40, wakes the waiting threads,
// wakes the worker when value 0x10 is set, calls the callback when set) and returns 1 when the first word of the
// request block is 0.
int CARD_IdentifyBackup(s32 a);
// Waits until no transfer is running and marks one running; stores the callback and its argument at +0x38 and +0x3c,
// the arguments at +0x1c, +0x20 and +0x24, and the command, tries and mode at +0x2c, +0x30 and +0x34. When async is
// not 0 queues RunBackupTransfer on the worker and returns 1; otherwise runs it and returns 1 when the first word of
// the request block is 0. The game always passes async 1.
int StartBackupTransfer(u32 a, u32 b, u32 c, UnkFunc *d, void *e, u32 f, u32 g, u32 h, u32 i);
// Moves the data in pieces of at most 0x100 bytes. Per piece: when value 0x40 of the flag word is set, clears it,
// stores 7 in the first word of the request block and stops. Mode 0 receives into the buffer at +0x120 and copies to
// the destination; other modes copy to the buffer, flush it and send it, and mode 2 then sends request 9 with 1 try.
// Advances source, destination and length; stops on a failed request or length 0. Ends the transfer (clears flag
// values 0x4, 0x8 and 0x40, wakes the waiting threads, wakes the worker when value 0x10 is set, calls the callback).
void RunBackupTransfer(Unk021458c4 *p);
// Returns ReadRomPagesByCpu.
UnkFunc *GetRomPageReader(void);
// Calls WaitForTransferEnd. Its only caller is StartRomRead, after a DMA read was started and only when the async
// argument is 0 (both callers in this game pass 1). Has the same body as CARD_WaitBackupAsync.
int CARD_WaitRomAsync(void);
// Does nothing when the word at +0x114 is not 0. Otherwise sets it to 1, clears the words at +0x1c, +0x20, +0x24,
// +0x38 and +0x3c, sets the word at +0x28 to -1, clears gRomBaseOffset, calls InitBackupAndRomAccess, stores the
// result of GetRomPageReader in gRomReadState and calls CARD_InitPulledOutCallback.
void CARD_Init(void);
// Calls CARD_CheckEnabled, waits until no transfer is running and marks one running; stores the callback and its
// argument, the offset plus gRomBaseOffset, the destination and the length, and the DMA channel at +0x28 (stopped
// with MI_StopDma when it is 0 to 3). Calls TryStartRomDmaRead; when that started and async is 0, calls
// CARD_WaitRomAsync. When it did not start, queues RunRomRead on the worker if async is not 0, else runs it. Both
// game callers pass async 1.
void StartRomRead(u32 a, u32 b, u32 c, u32 d, UnkFunc *e, u32 f, u32 g);
// Calls CopyFromRomPageBuffer and, when it returns non-zero, calls the page reader stored at the start of
// gRomReadState. Then sets the first word of the request block to 0 and ends the transfer (clears flag values 0x4,
// 0x8 and 0x40, wakes the waiting threads, wakes the worker when value 0x10 is set, calls the callback).
void RunRomRead(Unk021458c4 *a);
// Reads 0x200-byte pages with the CPU; reached through the page reader pointer that CARD_Init stores in
// gRomReadState. Per page: writes the page command for the offset with WriteRomCommandBytes, writes the control word
// at +4 to 0x040001a4, then reads words from 0x04100010 while bit 23 of 0x040001a4 is set until bit 31 clears. Reads
// into the destination when the offset and length are multiples of 0x200 and the destination is 4-byte aligned,
// otherwise into the buffer at +0x20 and then calls CopyFromRomPageBuffer. Advances by 0x200 per page.
void ReadRomPagesByCpu(Unk02146154 *p);
// Stores ((word at 0x027ffe60) & ~0x07000000) | 0xa1000000 at +4 of the argument. Starts a DMA page read and returns
// 1 when the channel is 0 to 3, the destination is 4-byte aligned and outside the window starting at the DTCM address
// and below 0x02000000 when it ends above 0x01ff8000, offset and length are multiples of 0x200 and the length is not
// 0: flushes or invalidates the destination cache lines (the first and last 32-byte lines are flushed when the
// destination is not 32-byte aligned), installs AdvanceRomDmaRead for interrupt mask 0x80000 and calls
// StartRomPageDma. Returns 0 without starting otherwise.
int TryStartRomDmaRead(Unk02146154 *p);
// Interrupt handler for mask 0x80000. Stops the DMA channel at +0x28 and advances offset, destination and length by
// 0x200. With length left, calls StartRomPageDma. Otherwise disables and acknowledges the interrupt, sets the first
// word of the request block to 0 and ends the transfer (clears flag values 0x4, 0x8 and 0x40, wakes the waiting
// threads, wakes the worker when value 0x10 is set, calls the callback).
void AdvanceRomDmaRead(void);
// Starts StartCardDmaCopy with the channel at +0x28, the data port 0x04100010, the destination at +0x20 and 0x200
// bytes, writes the page command for the offset at +0x1c with WriteRomCommandBytes, then writes the control word at
// +4 of gRomReadState to 0x040001a4.
void StartRomPageDma(void);
// Waits until bit 31 of 0x040001a4 is clear, writes 0xc0 to 0x040001a1, then writes the bytes of the first argument
// (high byte first) to 0x040001a8 to 0x040001ab and of the second to 0x040001ac to 0x040001af. Callers pass 0xb7 and
// the offset.
void WriteRomCommandBytes(u32 a, u32 b);
// When the page in the buffer (page start at +8) is the page of the current offset, copies from the buffer to the
// destination up to the end of the page or the length, and advances offset, destination and length. Returns 1 while
// length remains.
int CopyFromRomPageBuffer(Unk02146154 *p);
// Sends the command on tag 11 and waits until ReceiveRequestReply ends the wait; returns 1 when the first word of the
// request block is 0. On the first call it waits until PxiCallbackBitIsSet(11, 1) is non-zero and sends command 0
// first (command 0 also sends the address of the request block). Repeats while that word is 4 and tries remain.
int SendRequestWithRetries(Unk021458c4 *p, s32 a, s32 b);
// OSThread entry that never returns: with interrupts off, sleeps (storing its thread at +0x104) until value 8 of the
// flag word is set, then calls the task at +0x40 with the state and starts again.
void WorkerTaskLoop(void *a);

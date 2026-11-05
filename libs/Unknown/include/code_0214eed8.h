#pragma once

#include "types.h"

// The one microphone command in flight, 0x1c bytes, one instance: lock word, callback and argument, last result, a
// second callback with its argument, and a destination pointer for one halfword that nothing sets.
typedef struct MicrophoneCommand {
    /* 00 */ u32 mUnk_00;
    /* 04 */ void (*mUnk_04)();
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ void (*mUnk_10)();
    /* 14 */ u32 mUnk_14;
    /* 18 */ u16 *mUnk_18;
} MicrophoneCommand;

// Argument of MIC_StartAutoSampling and MIC_StartAutoSamplingAsync, 0x1c bytes.
typedef struct Unk0214f2a8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ void (*mUnk_14)();
    /* 18 */ u32 mUnk_18;
} Unk0214f2a8;

// Set once by MIC_Init.
extern u16 gMicrophoneInitialized;
// The microphone command in flight.
extern MicrophoneCommand gMicrophoneCommand;

// Spins while the lock word of the command object is 1.
void WaitMicrophoneIdle(void);
// Stores its argument as the result in the command object. Used as the callback of the waiting forms, which return it.
void SetMicrophoneResult(u32 arg0);
// Sends the one-word stop command (0x42) on tag 9. Returns 1 when it was accepted, otherwise 0.
s32 TrySendMicrophoneStopCommand(void);
// Sends the seven words of the start command on tag 9: command 0x41 with the flag byte d, then the buffer address, the
// size and the rate as high and low halves. Returns 0 at the first refused word, otherwise 1.
u32 TrySendMicrophoneStartCommand(u32 a, u32 b, u32 c, u32 d);
// Receive handler of PXI tag 9. Turns the reply byte into a result (0, 4, 2, 5 or 1; anything else 6). Reply 0x51 calls
// the second callback with the result and its argument and returns. Otherwise stores the halfword at 0x027fff94 through
// the destination pointer when command 0x40 arrives and one is set, clears the lock and calls the stored callback once
// with the result. An error word first clears the lock and calls the stored callback with 6.
void ReceiveMicrophoneReply(u32 a, u32 b, u32 c);
// Returns the word at 0x027fff90, which MIC_Init clears; the game treats it as the address in the sampling buffer up to
// which samples have been written.
u32 MIC_GetLastSamplingAddress(void);
// Sends the stop command and waits for the reply. Returns the result (the refusal code at once when the command was not
// sent).
u32 MIC_StopAutoSampling(void);
// Sends the stop command. Returns 1 when a command is already in flight, 3 when the command word is refused, 0 when it
// was sent. The callback is called with (result, argument) when the reply arrives. Returns at once.
u32 MIC_StopAutoSamplingAsync(void (*fn)(), u32 arg);
// Starts the sampling as MIC_StartAutoSamplingAsync does and waits for the reply. Returns the result (the refusal code
// at once when the command was not sent).
u32 MIC_StartAutoSampling(Unk0214f2a8 *p);
// Starts sampling into the buffer described by the first argument. Returns 2 when the buffer address is not 32-byte
// aligned, the size is 0 or not a multiple of 32, the rate is below 0x400 or the type is above 5; 1 when a command is
// already in flight; 3 when a command word is refused; 0 when the command was sent. The callback is called with
// (result, argument) when the reply arrives. Returns at once.
u32 MIC_StartAutoSamplingAsync(Unk0214f2a8 *p, void (*fn)(), u32 arg);
// Starts the microphone channel once. Clears the lock and the callback, waits for the other processor on PXI tag 9,
// clears the word at 0x027fff90 and installs the receive handler. Later calls return at once.
void MIC_Init(void);

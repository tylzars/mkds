#pragma once

#include "types.h"

typedef enum MICResult {
    MIC_RESULT_SUCCESS = 0,
    MIC_RESULT_BUSY,
    MIC_RESULT_ILLEGAL_PARAMETER,
    MIC_RESULT_SEND_ERROR,
    MIC_RESULT_INVALID_COMMAND,
    MIC_RESULT_ILLEGAL_STATUS,
    MIC_RESULT_FATAL_ERROR,
    MIC_RESULT_MAX
} MICResult;

typedef enum MICSamplingType {
    MIC_SAMPLING_TYPE_8BIT = 0,
    MIC_SAMPLING_TYPE_12BIT,
    MIC_SAMPLING_TYPE_SIGNED_8BIT,
    MIC_SAMPLING_TYPE_SIGNED_12BIT,
    MIC_SAMPLING_TYPE_12BIT_FILTER_OFF,
    MIC_SAMPLING_TYPE_SIGNED_12BIT_FILTER_OFF,
    MIC_SAMPLING_TYPE_MAX
} MICSamplingType;

typedef void (*MICCallback)(MICResult result, void *arg);

// Argument of MIC_StartAutoSampling and MIC_StartAutoSamplingAsync, 0x1c bytes: the sampling type, the buffer
// (32-byte aligned) with its size (a multiple of 32), the rate (at least 0x400), whether it loops, and the callback
// with its argument that runs when the buffer is full.
typedef struct MICAutoParam {
    /* 00 */ MICSamplingType mType;
    /* 04 */ void *mBuffer;
    /* 08 */ u32 mSize;
    /* 0c */ u32 mRate;
    /* 10 */ BOOL mLoopEnable;
    /* 14 */ MICCallback mFullCallback;
    /* 18 */ void *mFullArg;
} MICAutoParam;

// The one microphone command in flight, 0x1c bytes.
typedef struct MICWork {
    // Nonzero while a command is in flight.
    /* 00 */ u32 mLock;
    // Called once with the result and mCallbackArg when the reply arrives (cleared first).
    /* 04 */ MICCallback mCallback;
    /* 08 */ void *mCallbackArg;
    // Result of the last waiting call.
    /* 0c */ MICResult mCommonResult;
    // Called with the result and mFullArg when the sampling buffer is full.
    /* 10 */ MICCallback mFull;
    /* 14 */ void *mFullArg;
    // Where the halfword at 0x027fff94 goes when a single sampling reply arrives; nothing sets it.
    /* 18 */ u16 *mDstBuf;
} MICWork;

// Set once by MIC_Init.
extern u16 gMicrophoneInitialized;
// The microphone command in flight.
extern MICWork gMicrophoneCommand;

// Spins while the lock word of the command object is 1.
void MicWaitBusy(void);
// Stores the result in the command object; the callback of the waiting forms, which return it.
void MicGetResultCallback(MICResult result, void *arg);
// Sends the one-word stop command (0x42) on tag 9. Returns 1 when it was accepted, otherwise 0.
BOOL MicStopAutoSampling(void);
// Sends the seven words of the start command on tag 9: command 0x41 with the flag byte flags, then the buffer address,
// the size and the rate as high and low halves. Returns 0 at the first refused word, otherwise 1.
BOOL MicStartAutoSampling(void *buf, u32 size, u32 span, u8 flags);
// Receive handler of PXI tag 9. Turns the reply byte into a result (0, 4, 2, 5 or 1; anything else 6). Reply 0x51 calls
// mFull with the result and mFullArg and returns. Otherwise stores the halfword at 0x027fff94 through mDstBuf when
// command 0x40 arrives and one is set, clears the lock and calls the stored callback once with the result. An error
// word first clears the lock and calls the stored callback with 6.
void MicCommonCallback(u32 tag, u32 data, BOOL err);
// Returns the word at 0x027fff90, which MIC_Init clears: the address in the sampling buffer up to which samples have
// been written.
void *MIC_GetLastSamplingAddress(void);
// Sends the stop command and waits for the reply. Returns the result.
MICResult MIC_StopAutoSampling(void);
// Sends the stop command. Returns MIC_RESULT_BUSY when a command is already in flight, MIC_RESULT_SEND_ERROR when the
// command word is refused, MIC_RESULT_SUCCESS when it was sent. The callback is called with the result and arg when
// the reply arrives. Returns at once.
MICResult MIC_StopAutoSamplingAsync(MICCallback callback, void *arg);
// Starts the sampling as MIC_StartAutoSamplingAsync does and waits for the reply. Returns the result.
MICResult MIC_StartAutoSampling(const MICAutoParam *param);
// Starts sampling into the buffer described by param. Returns MIC_RESULT_ILLEGAL_PARAMETER when the buffer address is
// not 32-byte aligned, the size is 0 or not a multiple of 32, the rate is below 0x400 or the type is above 5;
// MIC_RESULT_BUSY when a command is already in flight; MIC_RESULT_SEND_ERROR when a command word is refused;
// MIC_RESULT_SUCCESS when the command was sent. The callback is called with the result and arg when the reply arrives.
// Returns at once.
MICResult MIC_StartAutoSamplingAsync(const MICAutoParam *param, MICCallback callback, void *arg);
// Starts the microphone channel once. Clears the lock and the callback, waits for the other processor on PXI tag 9,
// clears the word at 0x027fff90 and installs the receive handler. Later calls return at once.
void MIC_Init(void);

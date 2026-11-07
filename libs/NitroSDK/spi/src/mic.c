#include "mic.h"

#include "code_0214d5b8.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"

u16 gMicrophoneInitialized;

// Sets up the microphone channel on the first call only.
void MIC_Init(void) {
    if (gMicrophoneInitialized != 0) {
        return;
    }
    gMicrophoneInitialized = 1;
    gMicrophoneCommand.mLock = 0;
    gMicrophoneCommand.mCallback = 0;
    PXI_Init();
    while (!PXI_IsCallbackReady(9, 1)) {
    }
    *(u32 *) 0x27fff90 = 0;
    PXI_SetFifoRecvCallback(9, MicCommonCallback);
}

// Checks the parameters and starts sampling into the buffer; callback is called with the result and arg when the reply
// arrives.
MICResult MIC_StartAutoSamplingAsync(const MICAutoParam *param, MICCallback callback, void *arg) {
    OSIntrMode enabled;
    u32 typeFlags;
    u32 size;
    u8 flags;

    if (((u32) param->mBuffer & 0x1f) != 0) {
        return MIC_RESULT_ILLEGAL_PARAMETER;
    }
    size = param->mSize;
    if ((size & 0x1f) != 0) {
        return MIC_RESULT_ILLEGAL_PARAMETER;
    }
    if (size == 0) {
        return MIC_RESULT_ILLEGAL_PARAMETER;
    }
    if (param->mRate < 0x400) {
        return MIC_RESULT_ILLEGAL_PARAMETER;
    }
    switch (param->mType) {
        case MIC_SAMPLING_TYPE_8BIT:
            typeFlags = 0;
            break;
        case MIC_SAMPLING_TYPE_12BIT:
            typeFlags = 1;
            break;
        case MIC_SAMPLING_TYPE_SIGNED_8BIT:
            typeFlags = 2;
            break;
        case MIC_SAMPLING_TYPE_SIGNED_12BIT:
            typeFlags = 3;
            break;
        case MIC_SAMPLING_TYPE_12BIT_FILTER_OFF:
            typeFlags = 5;
            break;
        case MIC_SAMPLING_TYPE_SIGNED_12BIT_FILTER_OFF:
            typeFlags = 7;
            break;
        default:
            return MIC_RESULT_ILLEGAL_PARAMETER;
    }
    flags = param->mLoopEnable != 0 ? (typeFlags | 0x10) & 0xff : typeFlags & 0xff;
    enabled = OS_DisableInterrupts();
    if (gMicrophoneCommand.mLock != 0) {
        OS_RestoreInterrupts(enabled);
        return MIC_RESULT_BUSY;
    }
    gMicrophoneCommand.mLock = 1;
    OS_RestoreInterrupts(enabled);
    gMicrophoneCommand.mCallback = callback;
    gMicrophoneCommand.mCallbackArg = arg;
    gMicrophoneCommand.mFull = param->mFullCallback;
    gMicrophoneCommand.mFullArg = param->mFullArg;
    return MicStartAutoSampling(param->mBuffer, param->mSize, param->mRate, flags) != 0 ? MIC_RESULT_SUCCESS
                                                                                        : MIC_RESULT_SEND_ERROR;
}

// Starts sampling and waits for the reply.
MICResult MIC_StartAutoSampling(const MICAutoParam *param) {
    gMicrophoneCommand.mCommonResult = MIC_StartAutoSamplingAsync(param, MicGetResultCallback, 0);
    if (gMicrophoneCommand.mCommonResult == MIC_RESULT_SUCCESS) {
        MicWaitBusy();
    }
    return gMicrophoneCommand.mCommonResult;
}

// Sends the stop command; callback is called with the result and arg when the reply arrives.
MICResult MIC_StopAutoSamplingAsync(MICCallback callback, void *arg) {
    OSIntrMode enabled = OS_DisableInterrupts();

    if (gMicrophoneCommand.mLock != 0) {
        OS_RestoreInterrupts(enabled);
        return MIC_RESULT_BUSY;
    }
    gMicrophoneCommand.mLock = 1;
    OS_RestoreInterrupts(enabled);
    gMicrophoneCommand.mCallback = callback;
    gMicrophoneCommand.mCallbackArg = arg;
    return MicStopAutoSampling() != 0 ? MIC_RESULT_SUCCESS : MIC_RESULT_SEND_ERROR;
}

// Stops sampling and waits for the reply.
MICResult MIC_StopAutoSampling(void) {
    gMicrophoneCommand.mCommonResult = MIC_StopAutoSamplingAsync(MicGetResultCallback, 0);
    if (gMicrophoneCommand.mCommonResult == MIC_RESULT_SUCCESS) {
        MicWaitBusy();
    }
    return gMicrophoneCommand.mCommonResult;
}

// Returns the address in the sampling buffer up to which samples have been written.
void *MIC_GetLastSamplingAddress(void) {
    return *(void **) 0x27fff90;
}

// Handles a word from the other processor: turns it into a result, then finishes the command or reports a full buffer.
void MicCommonCallback(u32 tag, u32 data, BOOL err) {
    u16 status;
    u16 command;
    MICResult result;
    MICCallback callback;

    if (err != 0) {
        if (gMicrophoneCommand.mLock != 0) {
            gMicrophoneCommand.mLock = 0;
        }
        if (gMicrophoneCommand.mCallback != 0) {
            callback = gMicrophoneCommand.mCallback;
            gMicrophoneCommand.mCallback = 0;
            callback(MIC_RESULT_FATAL_ERROR, gMicrophoneCommand.mCallbackArg);
        }
    }
    status = data & 0xff;
    command = (data & 0x7f00) >> 8;
    switch (status) {
        case 0:
            result = MIC_RESULT_SUCCESS;
            break;
        case 1:
            result = MIC_RESULT_INVALID_COMMAND;
            break;
        case 2:
            result = MIC_RESULT_ILLEGAL_PARAMETER;
            break;
        case 3:
            result = MIC_RESULT_ILLEGAL_STATUS;
            break;
        case 4:
            result = MIC_RESULT_BUSY;
            break;
        default:
            result = MIC_RESULT_FATAL_ERROR;
            break;
    }
    if (command == 0x51) {
        if (gMicrophoneCommand.mFull != 0) {
            gMicrophoneCommand.mFull(result, gMicrophoneCommand.mFullArg);
        }
        return;
    }
    if (command == 0x40) {
        if (gMicrophoneCommand.mDstBuf != 0) {
            *gMicrophoneCommand.mDstBuf = *(u16 *) 0x27fff94;
        }
    }
    if (gMicrophoneCommand.mLock != 0) {
        gMicrophoneCommand.mLock = 0;
    }
    if (gMicrophoneCommand.mCallback != 0) {
        callback = gMicrophoneCommand.mCallback;
        gMicrophoneCommand.mCallback = 0;
        callback(result, gMicrophoneCommand.mCallbackArg);
    }
}

// Sends the seven words of the start command; FALSE at the first word the FIFO refuses.
BOOL MicStartAutoSampling(void *buf, u32 size, u32 span, u8 flags) {
    if (PXI_SendWordByFifo(9, flags | 0x2004100, 0) < 0) {
        return FALSE;
    }
    if (PXI_SendWordByFifo(9, ((u32) buf >> 16) | 0x10000, 0) < 0) {
        return FALSE;
    }
    if (PXI_SendWordByFifo(9, ((u32) buf & 0xffff) | 0x20000, 0) < 0) {
        return FALSE;
    }
    if (PXI_SendWordByFifo(9, (size >> 16) | 0x30000, 0) < 0) {
        return FALSE;
    }
    if (PXI_SendWordByFifo(9, (size & 0xffff) | 0x40000, 0) < 0) {
        return FALSE;
    }
    if (PXI_SendWordByFifo(9, (span >> 16) | 0x50000, 0) < 0) {
        return FALSE;
    }
    return PXI_SendWordByFifo(9, (span & 0xffff) | 0x1060000, 0) >= 0;
}

// Sends the stop command word.
BOOL MicStopAutoSampling(void) {
    return PXI_SendWordByFifo(9, 0x3004200, 0) >= 0;
}

// Stores the result of the waiting calls.
void MicGetResultCallback(MICResult result, void *arg) {
    gMicrophoneCommand.mCommonResult = result;
}

// clang-format off
// Waits while the lock word of gMicrophoneCommand is 1.
asm void MicWaitBusy(void) {
    ldr ip, =gMicrophoneCommand
wait_loop:
    ldr r0, [ip]
    cmp r0, #0x1
    beq wait_loop
    bx lr
}
// clang-format on

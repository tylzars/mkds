#include "code_0214c778.h"
#include "code_0200fc8c.h"
#include "code_0200c914.h"
#include "Main/Unknown/code_0200f000.h"
#include "ITCM/code_01fff000.h"
#include "ITCM/code_01fff95c.h"

MIiGXDmaParams MIi_GXDmaParams;

// Sends commandLength bytes of GX commands from src to the GX command FIFO by DMA channel dmaNo, a piece at a time as
// the FIFO drops below half full. Calls callback(arg) when the last piece is done, or at once when commandLength is 0.
void MI_SendGXCommandAsync(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg) {
    u32 enabled;
    vu32 *status;

    if (commandLength == 0) {
        if (callback != 0) {
            callback(arg);
        }
        return;
    }
    while (MIi_GXDmaParams.mIsBusy != 0) {
    }
    status = (vu32 *) 0x4000600;
    while ((((*status & 0x7000000) >> 0x18) & 2) == 0) {
    }
    MIi_GXDmaParams.mCallback = callback;
    MIi_GXDmaParams.mIsBusy = 1;
    MIi_GXDmaParams.mDmaNo = dmaNo;
    MIi_GXDmaParams.mSrc = src;
    MIi_GXDmaParams.mLength = commandLength;
    MIi_GXDmaParams.mArg = arg;
    MIi_CheckDma0SourceAddress(dmaNo, src, commandLength, 0);
    MI_WaitDma(dmaNo);
    enabled = OS_DisableInterrupts();
    MIi_GXDmaParams.mFifoCond = (*(u32 *) 0x4000600 & 0xc0000000) >> 0x1e;
    MIi_GXDmaParams.mFifoFunc = OS_GetIrqFunction(0x200000);
    *(u32 *) 0x4000600 = (*(u32 *) 0x4000600 & ~0xc0000000) | 0x40000000;
    OS_SetIrqFunction(0x200000, MIi_FIFOCallback);
    OS_EnableIrqMask(0x200000);
    MIi_FIFOCallback();
    OS_RestoreInterrupts(enabled);
}

// Starts the next piece (at most 0x1d8 bytes) of the transfer in MIi_GXDmaParams on its DMA channel. The last piece
// registers MIi_DMACallback and raises an interrupt when it ends.
void MIi_FIFOCallback(void) {
    const u8 *src;
    u32 length;

    length = MIi_GXDmaParams.mLength;
    if (length == 0) {
        return;
    }
    if (length >= 0x1d8) {
        length = 0x1d8;
    }
    src = MIi_GXDmaParams.mSrc;
    MIi_GXDmaParams.mLength = MIi_GXDmaParams.mLength - length;
    MIi_GXDmaParams.mSrc = src + length;
    if (MIi_GXDmaParams.mLength == 0) {
        OSi_EnterDmaCallback(MIi_GXDmaParams.mDmaNo, MIi_DMACallback, 0);
        StartDmaTransfer(MIi_GXDmaParams.mDmaNo, src, (void *) 0x4000400, 0xc4400000 | (length >> 2));
        OS_ResetRequestIrqMask(0x200000);
        return;
    }
    StartDmaTransfer(MIi_GXDmaParams.mDmaNo, src, (void *) 0x4000400, 0x84400000 | (length >> 2));
    OS_ResetRequestIrqMask(0x200000);
}

// Ends a piecewise transfer: turns the GX FIFO interrupt off, puts back the saved FIFO condition and interrupt
// handler, marks the transfer finished and calls MIi_GXDmaParams.mCallback.
void MIi_DMACallback(void *arg) {
    void *callbackArg;

    OS_DisableIrqMask(0x200000);
    *(u32 *) 0x4000600 = (MIi_GXDmaParams.mFifoCond << 0x1e) | (*(u32 *) 0x4000600 & ~0xc0000000);
    OS_SetIrqFunction(0x200000, MIi_GXDmaParams.mFifoFunc);
    MIi_GXDmaParams.mIsBusy = 0;
    callbackArg = MIi_GXDmaParams.mArg;
    if (MIi_GXDmaParams.mCallback != 0) {
        MIi_GXDmaParams.mCallback(callbackArg);
    }
}

// Sends commandLength bytes of GX commands from src to the GX command FIFO with one DMA transfer on channel dmaNo.
// Calls callback(arg) when it is done, or at once when commandLength is 0.
void MI_SendGXCommandAsyncFast(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg) {
    if (commandLength == 0) {
        if (callback != 0) {
            callback(arg);
        }
        return;
    }
    while (MIi_GXDmaParams.mIsBusy != 0) {
    }
    MIi_GXDmaParams.mIsBusy = 1;
    MIi_GXDmaParams.mDmaNo = dmaNo;
    MIi_GXDmaParams.mCallback = callback;
    MIi_GXDmaParams.mArg = arg;
    MIi_CheckAnotherAutoDMA(dmaNo, 0x38000000);
    MIi_CheckDma0SourceAddress(dmaNo, src, commandLength, 0);
    MI_WaitDma(dmaNo);
    OSi_EnterDmaCallback(dmaNo, MIi_DMAFastCallback, 0);
    StartDmaTransfer(dmaNo, src, (void *) 0x4000400, 0xfc400000 | (commandLength >> 2));
}

// Marks the transfer finished and calls MIi_GXDmaParams.mCallback.
void MIi_DMAFastCallback(void *arg) {
    void *callbackArg;

    MIi_GXDmaParams.mIsBusy = 0;
    callbackArg = MIi_GXDmaParams.mArg;
    if (MIi_GXDmaParams.mCallback != 0) {
        MIi_GXDmaParams.mCallback(callbackArg);
    }
}

void MI_DmaFill32(u32 dmaNo, void *dest, u32 data, u32 size) {
    u32 enabled;

    if (size == 0) {
        return;
    }
    while (*(vu32 *) (0x40000b0 + (dmaNo * 3 + 2) * 4) & 0x80000000) {
    }
    enabled = OS_DisableInterrupts();
    *(vu32 *) (0x4000000 + dmaNo * 4 + 0xe0) = data;
    StartDmaTransferAndChannel0DummyWithoutIrqDisable(dmaNo, (const void *) (0x40000e0 + dmaNo * 4), dest,
                                                      (size >> 2) | 0x85000000);
    OS_RestoreInterrupts(enabled);
    while (*(vu32 *) (0x40000b0 + (dmaNo * 3 + 2) * 4) & 0x80000000) {
    }
}

void MI_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size) {
    MIi_CheckDma0SourceAddress(dmaNo, src, size, 0);
    if (size == 0) {
        return;
    }
    while (*(vu32 *) (0x40000b0 + (dmaNo * 3 + 2) * 4) & 0x80000000) {
    }
    StartDmaTransferAndChannel0Dummy(dmaNo, src, dest, (size >> 2) | 0x84000000);
    while (*(vu32 *) (0x40000b0 + (dmaNo * 3 + 2) * 4) & 0x80000000) {
    }
}

void MI_DmaCopy16(u32 dmaNo, const void *src, void *dest, u32 size) {
    if (size == 0) {
        return;
    }
    MIi_CheckDma0SourceAddress(dmaNo, src, size, 0);
    while (*(vu32 *) (0x40000b0 + (dmaNo * 3 + 2) * 4) & 0x80000000) {
    }
    StartDmaTransferAndChannel0Dummy(dmaNo, src, dest, (size >> 1) | 0x80000000);
    while (*(vu32 *) (0x40000b0 + (dmaNo * 3 + 2) * 4) & 0x80000000) {
    }
}

void MI_DmaFill32Async(u32 dmaNo, void *dest, u32 data, u32 size, MIDmaCallback callback, void *arg) {
    u32 enabled;

    if (size == 0) {
        if (callback != 0) {
            callback(arg);
        }
        return;
    }
    MI_WaitDma(dmaNo);
    if (callback != 0) {
        OSi_EnterDmaCallback(dmaNo, callback, (u32) arg);
        enabled = OS_DisableInterrupts();
        *(vu32 *) (0x4000000 + dmaNo * 4 + 0xe0) = data;
        StartDmaTransferWithoutIrqDisable(dmaNo, (const void *) (0x40000e0 + dmaNo * 4), dest,
                                          (size >> 2) | 0xc5000000);
        OS_RestoreInterrupts(enabled);
    } else {
        enabled = OS_DisableInterrupts();
        *(vu32 *) (0x4000000 + dmaNo * 4 + 0xe0) = data;
        StartDmaTransferWithoutIrqDisable(dmaNo, (const void *) (0x40000e0 + dmaNo * 4), dest,
                                          (size >> 2) | 0x85000000);
        OS_RestoreInterrupts(enabled);
    }
}

void MI_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg) {
    MIi_CheckDma0SourceAddress(dmaNo, src, size, 0);
    if (size == 0) {
        if (callback != 0) {
            callback(arg);
        }
        return;
    }
    MI_WaitDma(dmaNo);
    if (callback != 0) {
        OSi_EnterDmaCallback(dmaNo, callback, (u32) arg);
        StartDmaTransfer(dmaNo, src, dest, (size >> 2) | 0xc4000000);
    } else {
        StartDmaTransfer(dmaNo, src, dest, (size >> 2) | 0x84000000);
    }
}

void MI_WaitDma(u32 dmaNo) {
    u32 enabled;
    vu32 *dmaRegs;

    enabled = OS_DisableInterrupts();
    while (*(vu32 *) (0x40000b0 + (dmaNo * 3 + 2) * 4) & 0x80000000) {
    }
    if (dmaNo == 0) {
        *(vu32 *) (0x4000000 + dmaNo * 12 + 0xb0) = 0;
        dmaRegs = (vu32 *) (0x40000b0 + dmaNo * 12);
        dmaRegs[1] = 0;
        dmaRegs[2] = 0x81400001;
    }
    OS_RestoreInterrupts(enabled);
}

void MI_StopDma(u32 dmaNo) {
    u32 enabled;
    vu32 *dmaRegs;

    enabled = OS_DisableInterrupts();
    *(vu16 *) (0x4000000 + (dmaNo * 6 + 5) * 2 + 0xb0) &= ~0x3a00;
    *(vu16 *) (0x4000000 + (dmaNo * 6 + 5) * 2 + 0xb0) &= ~0x8000;
    *(vu16 *) (0x4000000 + (dmaNo * 6 + 5) * 2 + 0xb0);
    *(vu16 *) (0x4000000 + (dmaNo * 6 + 5) * 2 + 0xb0);
    if (dmaNo == 0) {
        *(vu32 *) (0x4000000 + dmaNo * 12 + 0xb0) = 0;
        dmaRegs = (vu32 *) (0x40000b0 + dmaNo * 12);
        dmaRegs[1] = 0;
        dmaRegs[2] = 0x81400001;
    }
    OS_RestoreInterrupts(enabled);
}

void MIi_CheckAnotherAutoDMA(u32 dmaNo, u32 dmaType) {
    s32 channel;
    u32 *control;
    u32 timing;
    u32 value;

    control = (u32 *) 0x40000b8;
    for (channel = 0; channel < 3; channel++, control += 3) {
        if (channel == dmaNo) {
            continue;
        }
        value = *control;
        if ((value & 0x80000000) == 0) {
            continue;
        }
        timing = value & 0x38000000;
        if (timing == dmaType) {
            continue;
        }
        if (timing == 0x8000000 && dmaType == 0x10000000) {
            continue;
        }
        if (timing == 0x10000000 && dmaType == 0x8000000) {
            continue;
        }
        if (timing == 0x18000000 || timing == 0x20000000 || timing == 0x28000000 || timing == 0x30000000 ||
            timing == 0x38000000 || timing == 0x8000000 || timing == 0x10000000) {
            OS_Terminate();
        }
    }
}

void MIi_CheckDma0SourceAddress(u32 dmaNo, const void *src, u32 size, u32 dir) {
    u32 end;
    u32 srcTop;

    if (dmaNo != 0) {
        return;
    }
    end = (u32) src;
    srcTop = end & 0xff000000;
    if (dir != 0) {
        if (dir == 0x800000) {
            end = end - size;
        }
    } else {
        end = end + size;
    }
    if (srcTop == 0x4000000 || srcTop >= 0x8000000 || (end & 0xff000000) == 0x4000000 ||
        (end & 0xff000000) >= 0x8000000) {
        OS_Terminate();
    }
}

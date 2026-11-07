#include "code_0214d5b8.h"
#include "code_0200fc8c.h"
#include "code_0200c914.h"
#include "Main/Unknown/code_0200f000.h"
#include "registers.h"

PXIFifoCallback data_0218032c[32];
u16 data_02180328;

// Runs once: clears the handle checker word of the ARM9 and the callback table, sets up the receive interrupt for
// PXIi_HandlerRecvFifoNotEmpty, then handshakes with the other processor through the PXI interrupt flags.
void PXI_InitFifo(void) {
    u32 enabled;
    s32 i;
    s32 timeout;
    u32 c;
    s32 count;
    Unk027ffc00 *p;

    enabled = OS_DisableInterrupts();
    if (data_02180328 == 0) {
        data_02180328 = 1;
        p = (Unk027ffc00 *) 0x027ffc00;
        p->mPxiHandleChecker[0] = 0;
        for (i = 0; i < 32; i++) {
            data_0218032c[i] = 0;
        }
        reg_PXI_SUBP_FIFO_CNT = 0xc408;
        OS_ResetRequestIrqMask(0x40000);
        OS_SetIrqFunction(0x40000, PXIi_HandlerRecvFifoNotEmpty);
        OS_EnableIrqMask(0x40000);
        count = 0;
        for (;;) {
            c = reg_PXI_SUBPINTF & 0xf;
            reg_PXI_SUBPINTF = c << 8;
            if (c == 0 && count > 4) {
                break;
            }
            timeout = 1000;
            while ((reg_PXI_SUBPINTF & 0xf) == c) {
                if (timeout <= 0) {
                    count = 0;
                    break;
                }
                timeout--;
            }
            count++;
        }
    }
    OS_RestoreInterrupts(enabled);
}

// Stores callback for fifotag and sets or clears its bit in the ARM9 handle checker word.
void PXI_SetFifoRecvCallback(s32 fifotag, PXIFifoCallback callback) {
    u32 enabled;
    Unk027ffc00 *p;

    enabled = OS_DisableInterrupts();
    data_0218032c[fifotag] = callback;
    p = (Unk027ffc00 *) 0x027ffc00;
    if (callback != 0) {
        p->mPxiHandleChecker[0] |= 1 << fifotag;
    } else {
        p->mPxiHandleChecker[0] &= ~(1 << fifotag);
    }
    OS_RestoreInterrupts(enabled);
}

// Returns whether the handle checker word of processor proc has the bit of fifotag set.
s32 PXI_IsCallbackReady(s32 fifotag, s32 proc) {
    Unk027ffc00 *p;

    p = (Unk027ffc00 *) 0x027ffc00;
    return (p->mPxiHandleChecker[proc] & (1 << fifotag)) != 0;
}

// Packs fifotag (5 bits), err (1 bit) and data (26 bits) into one word and writes it to the send FIFO.
// Returns -1 when the FIFO error flag is set (cleared here), -2 when the send FIFO is full, 0 on success.
s32 PXI_SendWordByFifo(s32 fifotag, u32 data, s32 err) {
    PxiWord message;
    u32 enabled;

    message.mTag = fifotag;
    message.mErr = err;
    message.mData = data;
    if (reg_PXI_SUBP_FIFO_CNT & 0x4000) {
        reg_PXI_SUBP_FIFO_CNT |= 0xc000;
        return -1;
    }
    enabled = OS_DisableInterrupts();
    if (reg_PXI_SUBP_FIFO_CNT & 2) {
        OS_RestoreInterrupts(enabled);
        return -2;
    }
    reg_PXI_SEND_FIFO = *(u32 *) &message;
    OS_RestoreInterrupts(enabled);
    return 0;
}

// Receive interrupt handler: reads words from the receive FIFO until it is empty and calls the callback of each
// word's tag; a word with no callback and err clear is sent back with err set.
void PXIi_HandlerRecvFifoNotEmpty(void) {
    PxiWord message;
    s32 result;
    u32 enabled;
    PXIFifoCallback callback;

    for (;;) {
        if (reg_PXI_SUBP_FIFO_CNT & 0x4000) {
            reg_PXI_SUBP_FIFO_CNT |= 0xc000;
            result = -3;
        } else {
            enabled = OS_DisableInterrupts();
            if (reg_PXI_SUBP_FIFO_CNT & 0x100) {
                OS_RestoreInterrupts(enabled);
                result = -4;
            } else {
                *(u32 *) &message = reg_PXI_RECV_FIFO;
                OS_RestoreInterrupts(enabled);
                result = 0;
            }
        }
        if (result == -4) {
            return;
        }
        if (result == -3) {
            continue;
        }
        if (message.mTag == 0) {
            continue;
        }
        callback = data_0218032c[message.mTag];
        if (callback != 0) {
            callback(message.mTag, message.mData, message.mErr);
            continue;
        }
        if (message.mErr == 0) {
            message.mErr = 1;
            if (reg_PXI_SUBP_FIFO_CNT & 0x4000) {
                reg_PXI_SUBP_FIFO_CNT |= 0xc000;
                continue;
            }
            enabled = OS_DisableInterrupts();
            if (reg_PXI_SUBP_FIFO_CNT & 2) {
                OS_RestoreInterrupts(enabled);
            } else {
                reg_PXI_SEND_FIFO = *(u32 *) &message;
                OS_RestoreInterrupts(enabled);
            }
        }
    }
}

// Calls PXI_InitFifo.
void PXI_Init(void) {
    PXI_InitFifo();
}

#include "wvr.h"
#include "code_0200cd1c.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/unk_02173000.h"
#include "code_0214d5b8.h"
#include "code_0200fe74.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0200c000.h"

s32 WVR_StartUpAsync(u32 vram, UnkFunc *callback, u32 arg) {
    u32 enabled;

    PXI_Init();
    if (PXI_IsCallbackReady(0xf, 1) == 0) {
        return 2;
    }
    if (data_02173278 == 0) {
        do {
            s32 id = OS_GetLockID();

            if (id == -3) {
                return 7;
            }
            data_02173278 = id;
        } while (data_02173278 == 0);
    }
    enabled = OS_DisableInterrupts();
    if (data_02173284 != 0) {
        OS_RestoreInterrupts(enabled);
        return 5;
    }
    if (data_0217327c != 0) {
        OS_RestoreInterrupts(enabled);
        return 5;
    }
    switch (vram) {
        case 4:
            if (OSi_TryLockVram(4, data_02173278) == 0) {
                OS_RestoreInterrupts(enabled);
                return 6;
            }
            data_0217327c = 4;
            *(vu8 *) 0x4000242 = 0x82;
            break;
        case 8:
            if (OSi_TryLockVram(8, data_02173278) == 0) {
                OS_RestoreInterrupts(enabled);
                return 6;
            }
            data_0217327c = 8;
            *(vu8 *) 0x4000243 = 0x82;
            break;
        case 12:
            if (OSi_TryLockVram(12, data_02173278) == 0) {
                OS_RestoreInterrupts(enabled);
                return 6;
            }
            data_0217327c = 12;
            *(vu8 *) 0x4000242 = 0x82;
            *(vu8 *) 0x4000243 = 0x8a;
            break;
        default:
            OS_RestoreInterrupts(enabled);
            return 3;
    }
    if (PXI_IsCallbackReady(0xf, 0) == 0) {
        PXI_SetFifoRecvCallback(0xf, WvrReceiveCallback);
    }
    if (callback == 0) {
        data_02173284 = WvrDummyAsyncCallback;
    } else {
        data_02173284 = callback;
    }
    data_02173280 = arg;
    if (PXI_SendWordByFifo(0xf, 0x10000, 0) < 0) {
        OSi_UnlockVram(data_0217327c, data_02173278);
        data_0217327c = 0;
        data_02173284 = 0;
        OS_RestoreInterrupts(enabled);
        return 4;
    }
    OS_RestoreInterrupts(enabled);
    return 1;
}

s32 WVR_TerminateAsync(UnkFunc *callback, u32 arg) {
    u32 enabled;

    PXI_Init();
    if (PXI_IsCallbackReady(0xf, 1) == 0) {
        return 2;
    }
    enabled = OS_DisableInterrupts();
    if (data_02173284 != 0) {
        OS_RestoreInterrupts(enabled);
        return 5;
    }
    if (PXI_IsCallbackReady(0xf, 0) == 0) {
        PXI_SetFifoRecvCallback(0xf, WvrReceiveCallback);
    }
    if (callback == 0) {
        data_02173284 = WvrDummyAsyncCallback;
    } else {
        data_02173284 = callback;
    }
    data_02173280 = arg;
    if (PXI_SendWordByFifo(0xf, 0x20000, 0) < 0) {
        data_02173284 = 0;
        OS_RestoreInterrupts(enabled);
        return 4;
    }
    OS_RestoreInterrupts(enabled);
    return 1;
}

void WvrReceiveCallback(u32 tag, u32 data) {
    UnkFunc *callback;
    u32 callbackArg;
    u32 command;
    u32 result;

    command = data & 0xffff0000;
    result = data & 0xff;
    callback = data_02173284;
    callbackArg = data_02173280;
    switch (command) {
        case 0x10000:
            if (result == 7 && data_0217327c != 0 && data_02173278 != 0) {
                OSi_UnlockVram(data_0217327c, data_02173278);
                data_0217327c = 0;
            }
            break;
        case 0x20000:
            if (result == 0 && data_0217327c != 0 && data_02173278 != 0) {
                OSi_UnlockVram(data_0217327c, data_02173278);
                data_0217327c = 0;
            }
            PXI_SetFifoRecvCallback(0xf, 0);
            break;
    }
    if (callback != 0) {
        data_02173284 = 0;
        data_02173280 = 0;
        callback(callbackArg, result);
    }
}

void WvrDummyAsyncCallback(void) {}

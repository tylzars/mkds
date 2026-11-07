#include "code_021458c4.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_0200f328.h"
#include "Main/Unknown/code_02000b44.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_02000000.h"
#include "code_021457ec.h"
#include "Main/Unknown/code_02145888.h"
#include "Main/Unknown/code_02146000.h"
#include "card_request.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02000000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_0217f000.h"
#include "code_0200c914.h"
#include "os_thread.h"
#include "code_0214c778.h"
#include "code_0214d018.h"
#include "mi_dma_card.h"
#include "code_0214d5b8.h"
#include "registers.h"
#include "code_02146af4.h"

CARDiCommandArg gRequestBlock;
u32 gRomBaseOffset;
CARDRomStat gRomReadState;

// Worker thread: sleeps until CARDiCommon.mFlag has the task bit, then runs CARDiCommon.mTaskFunc.
void CARDi_TaskThread(void *arg) {
    CARDiCommon *p;
    u32 enabled;

    p = &gAccessState;
    for (;;) {
        enabled = OS_DisableInterrupts();
        while ((p->mFlag & 8) == 0) {
            p->mCurTh = &p->mThread;
            OS_SleepThread(0);
        }
        OS_RestoreInterrupts(enabled);
        p->mTaskFunc(p);
    }
}

// Sends a request on tag 11 and waits for the reply, trying again while the result is 4. The first call sends the init
// request with the address of CARDiCommon.mCmd. Returns 1 when CARDiCommandArg.mResult is 0.
int CARDi_Request(CARDiCommon *p, int reqType, int retryCount) {
    u32 enabled;
    s32 result;
    CARDiCommandArg *cmd;

    if (!(p->mFlag & 2)) {
        p->mFlag |= 2;
        if (PXI_IsCallbackReady(11, 1) == 0) {
            do {
                OS_SpinWait(100);
            } while (PXI_IsCallbackReady(11, 1) == 0);
        }
        CARDi_Request(p, 0, 1);
    }
    DC_FlushRange(p->mCmd, 0x40);
    DC_WaitWriteBufferEmpty();
    do {
        p->mCommand = reqType;
        p->mFlag |= 0x20;
        while (PXI_SendWordByFifo(11, reqType, 1) < 0) {
        }
        if (reqType == 0) {
            cmd = p->mCmd;
            while (PXI_SendWordByFifo(11, (u32) cmd, 1) < 0) {
            }
        }
        enabled = OS_DisableInterrupts();
        while (p->mFlag & 0x20) {
            OS_SleepThread(0);
        }
        OS_RestoreInterrupts(enabled);
        result = p->mCmd->mResult;
    } while (result == 4 && --retryCount > 0);
    return result == 0;
}

// Copies from CARDRomStat.mCacheBuf to the destination when the buffered page is the one at CARDiCommon.mSrc. Returns 1
// while CARDiCommon.mLen is not 0.
int CARDi_ReadFromCache(CARDRomStat *p) {
    CARDiCommon *c;
    u32 curPage;
    u32 len;
    u32 offset;

    c = &gAccessState;
    curPage = c->mSrc & -0x200;
    if (curPage == p->mCachePage) {
        offset = c->mSrc - curPage;
        len = 0x200 - offset;
        if (len > c->mLen) {
            len = c->mLen;
        }
        MI_CpuCopy8((u8 *) p->mCacheBuf + offset, (void *) c->mDst, len);
        c->mSrc += len;
        c->mDst += len;
        c->mLen -= len;
    }
    return c->mLen != 0;
}

// Waits for the card to be idle, then writes the 8 command bytes of a ROM operation, high byte first.
void CARDi_SetRomOp(u32 cmd1, u32 cmd2) {
    while (reg_MI_MCCNT1 & 0x80000000) {
    }
    *(vu8 *) 0x040001a1 = 0xc0;
    *(vu8 *) 0x040001a8 = cmd1 >> 24;
    *(vu8 *) 0x040001a9 = cmd1 >> 16;
    *(vu8 *) 0x040001aa = cmd1 >> 8;
    *(vu8 *) 0x040001ab = cmd1;
    *(vu8 *) 0x040001ac = cmd2 >> 24;
    *(vu8 *) 0x040001ad = cmd2 >> 16;
    *(vu8 *) 0x040001ae = cmd2 >> 8;
    *(vu8 *) 0x040001af = cmd2;
}

// Starts a DMA of one ROM page into CARDiCommon.mDst and the read command for CARDiCommon.mSrc.
void CARDi_SetCardDma(void) {
    CARDiCommon *c;

    c = (CARDiCommon *) (u32) &gAccessState;
    MIi_CardDmaCopy32(c->mDma, (void *) 0x04100010, (void *) c->mDst, 0x200);
    CARDi_SetRomOp((c->mSrc >> 8) | 0xb7000000, c->mSrc << 24);
    reg_MI_MCCNT1 = gRomReadState.mCtrl;
}

// Card DMA interrupt handler: advances one page, then starts the next page or finishes the transfer.
void CARDi_OnReadCard(void) {
    CARDiCommon *p;
    UnkFunc *callback;
    u32 callbackArg;
    u32 enabled;

    MI_StopDma(gAccessState.mDma);
    gAccessState.mSrc += 0x200;
    gAccessState.mDst += 0x200;
    gAccessState.mLen -= 0x200;
    if (gAccessState.mLen == 0) {
        OS_DisableIrqMask(0x80000);
        OS_ResetRequestIrqMask(0x80000);
        p = (CARDiCommon *) (u32) &gAccessState;
        p->mCmd->mResult = 0;
        callback = p->mCallback;
        callbackArg = p->mCallbackArg;
        enabled = OS_DisableInterrupts();
        p->mFlag &= ~0x4c;
        OS_WakeupThread(&p->mBusyQ);
        if (p->mFlag & 0x10) {
            OS_WakeupThreadDirect(&p->mThread);
        }
        OS_RestoreInterrupts(enabled);
        if (callback != 0) {
            callback(callbackArg);
        }
    } else {
        CARDi_SetCardDma();
    }
}

// Starts a ROM read by DMA when the channel, alignment, destination and length allow it and returns 1; returns 0
// otherwise. Always sets CARDRomStat.mCtrl.
int CARDi_TryReadCardDma(CARDRomStat *p) {
    u32 dtcm;
    int inTcm;
    CARDiCommon *c;
    u32 dst;
    u32 len;
    int isAsync;
    int aligned;
    int dmaUsable;
    u32 end;
    u32 enabled;
    u32 mod;

    c = &gAccessState;
    isAsync = 0;
    aligned = 0;
    dmaUsable = 0;
    dst = c->mDst;
    len = c->mLen;
    if ((dst & 3) == 0 && c->mDma <= 3) {
        int inMainRam;
        dtcm = OS_GetDTCMAddress();
        end = dst + len;
        inTcm = 1;
        inMainRam = 0;
        if (end > 0x01ff8000) {
            if (dst < 0x02000000) {
                inMainRam = 1;
            } else {
                inMainRam = 0;
            }
        }
        if (inMainRam == 0) {
            if (dtcm >= end || dtcm + 0x4000 <= dst) {
                inTcm = 0;
            }
        }
        if (inTcm == 0) {
            dmaUsable = 1;
        }
    }
    if (dmaUsable != 0) {
        if (((c->mSrc | len) & 0x1ff) == 0) {
            aligned = 1;
        }
    }
    if (aligned != 0 && len != 0) {
        isAsync = 1;
    }
    p->mCtrl = (*(u32 *) 0x027ffe60 & ~0x07000000) | 0xa1000000;
    if (isAsync != 0) {
        enabled = OS_DisableInterrupts();
        IC_InvalidateRange((void *) dst, len);
        mod = dst & 31;
        if (mod != 0) {
            dst -= mod;
            DC_StoreRange((void *) dst, 32);
            DC_StoreRange((void *) (dst + len), 32);
            len += 32;
        }
        DC_InvalidateRange((void *) dst, len);
        DC_WaitWriteBufferEmpty();
        OS_SetIrqFunction(0x80000, CARDi_OnReadCard);
        OS_ResetRequestIrqMask(0x80000);
        OS_EnableIrqMask(0x80000);
        OS_RestoreInterrupts(enabled);
        CARDi_SetCardDma();
    }
    return isAsync;
}

// Reads 0x200-byte ROM pages with the CPU, straight into the destination when it is aligned and big enough, otherwise
// through CARDRomStat.mCacheBuf.
void CARDi_ReadCard(CARDRomStat *p) {
    CARDiCommon *c;
    u32 *dst;
    u32 *cacheBuf;
    u32 page;
    u32 pos;
    u32 ctrl;
    u32 data;

    c = &gAccessState;
    cacheBuf = p->mCacheBuf;
    for (;;) {
        page = c->mSrc & -0x200;
        if (page != c->mSrc || (((u32) (dst = (u32 *) c->mDst)) & 3) != 0 || c->mLen < 0x200) {
            dst = cacheBuf;
            p->mCachePage = page;
        }
        CARDi_SetRomOp((page >> 8) | 0xb7000000, page << 24);
        reg_MI_MCCNT1 = p->mCtrl;
        pos = 0;
        do {
            ctrl = reg_MI_MCCNT1;
            if (ctrl & 0x800000) {
                data = reg_MI_MCD1;
                if (pos < 0x200) {
                    dst[pos] = data;
                    pos++;
                }
            }
        } while (ctrl & 0x80000000);
        if ((u32) dst == c->mDst) {
            gAccessState.mSrc += 0x200;
            gAccessState.mDst += 0x200;
            gAccessState.mLen -= 0x200;
            if (gAccessState.mLen == 0) {
                return;
            }
        } else if (CARDi_ReadFromCache(p) == 0) {
            return;
        }
    }
}

// Task for a ROM read the DMA path did not take: reads the rest through CARDRomStat.mReadFunc, then ends the transfer
// and calls the callback.
void CARDi_ReadRomSyncCore(CARDiCommon *c) {
    CARDiCommon *p;
    CARDRomStat *romStat;
    UnkFunc *callback;
    u32 callbackArg;
    u32 enabled;

    romStat = &gRomReadState;
    if (CARDi_ReadFromCache(romStat) != 0) {
        romStat->mReadFunc(romStat);
    }
    p = (CARDiCommon *) (u32) &gAccessState;
    p->mCmd->mResult = 0;
    callback = p->mCallback;
    callbackArg = p->mCallbackArg;
    enabled = OS_DisableInterrupts();
    p->mFlag &= ~0x4c;
    OS_WakeupThread(&p->mBusyQ);
    if (p->mFlag & 0x10) {
        OS_WakeupThreadDirect(&p->mThread);
    }
    OS_RestoreInterrupts(enabled);
    if (callback != 0) {
        callback(callbackArg);
    }
}

// Starts a ROM read of the given channel, offset, destination and length. Waits for the previous transfer first and
// adds gRomBaseOffset to the offset. Reads by DMA when possible, otherwise on the worker thread or the calling thread.
void CARDi_ReadRom(u32 dma, u32 src, u32 dst, u32 len, UnkFunc *callback, u32 callbackArg, u32 isAsync) {
    CARDiCommon *p;
    CARDRomStat *romStat;
    u32 enabled;

    p = (CARDiCommon *) (u32) &gAccessState;
    romStat = &gRomReadState;
    CARD_CheckEnabled();
    enabled = OS_DisableInterrupts();
    while (p->mFlag & 4) {
        OS_SleepThread(&p->mBusyQ);
    }
    p->mFlag |= 4;
    p->mCallback = callback;
    p->mCallbackArg = callbackArg;
    OS_RestoreInterrupts(enabled);
    p->mDma = dma;
    p->mSrc = src + gRomBaseOffset;
    p->mDst = dst;
    p->mLen = len;
    if (dma <= 3) {
        MI_StopDma(dma);
    }
    if (CARDi_TryReadCardDma(romStat) != 0) {
        if (isAsync == 0) {
            CARD_WaitRomAsync();
        }
    } else if (isAsync != 0) {
        CARDi_SetTask(CARDi_ReadRomSyncCore);
    } else {
        p->mCurTh = data_0216ff5c.mCurrentThread;
        CARDi_ReadRomSyncCore(p);
    }
}

// Sets up the card state once: clears the transfer words, CARDi_InitCommon, stores the page reader in gRomReadState and
// installs the pull-out callback.
void CARD_Init(void) {
    CARDiCommon *p;

    p = &gAccessState;
    if (p->mFlag != 0) {
        return;
    }
    p->mFlag = 1;
    p->mSrc = p->mDst = p->mLen = 0;
    p->mDma = -1;
    p->mCallback = 0;
    p->mCallbackArg = 0;
    gRomBaseOffset = 0;
    CARDi_InitCommon();
    gRomReadState.mReadFunc = CARDi_GetRomAccessor();
    CARD_InitPulledOutCallback();
}

// Waits for the running transfer to end.
int CARD_WaitRomAsync(void) {
    return CARDi_WaitAsync();
}

// Returns the CPU page reader.
UnkFunc *CARDi_GetRomAccessor(void) {
    return (UnkFunc *) CARDi_ReadCard;
}

// Task that sends the backup transfer in pieces of at most 0x100 bytes through CARDiCommon.mBackupCachePageBuf, then
// ends the transfer and calls the callback.
void CARDi_RequestStreamCommandCore(CARDiCommon *p) {
    u32 reqType;
    u32 reqMode;
    u32 retryCount;
    u32 len;
    u32 *buf;
    UnkFunc *callback;
    u32 callbackArg;
    u32 enabled;

    reqType = p->mReqType;
    reqMode = p->mReqMode;
    retryCount = p->mReqRetry;
    func_02000b44((u32) (BuildInfo + 0x24));
    do {
        len = p->mLen;
        if (len > 0x100) {
            len = 0x100;
        }
        p->mCmd->mLen = len;
        if (p->mFlag & 0x40) {
            p->mFlag &= ~0x40;
            p->mCmd->mResult = 7;
            break;
        }
        if (reqMode == 0) {
            DC_InvalidateRange(p->mBackupCachePageBuf, len);
            p->mCmd->mSrc = p->mSrc;
            p->mCmd->mDst = (u32) p->mBackupCachePageBuf;
        } else {
            MI_CpuCopy8((void *) p->mSrc, p->mBackupCachePageBuf, len);
            DC_FlushRange(p->mBackupCachePageBuf, len);
            DC_WaitWriteBufferEmpty();
            p->mCmd->mSrc = (s32) p->mBackupCachePageBuf;
            p->mCmd->mDst = p->mDst;
        }
        if (CARDi_Request(p, reqType, retryCount) == 0) {
            break;
        }
        if (reqMode == 2) {
            if (CARDi_Request(p, 9, 1) == 0) {
                break;
            }
        } else if (reqMode == 0) {
            MI_CpuCopy8(p->mBackupCachePageBuf, (void *) p->mDst, len);
        }
        p->mSrc += len;
        p->mDst += len;
        p->mLen -= len;
    } while (p->mLen != 0);
    callback = p->mCallback;
    callbackArg = p->mCallbackArg;
    enabled = OS_DisableInterrupts();
    p->mFlag &= ~0x4c;
    OS_WakeupThread(&p->mBusyQ);
    if (p->mFlag & 0x10) {
        OS_WakeupThreadDirect(&p->mThread);
    }
    OS_RestoreInterrupts(enabled);
    if (callback != 0) {
        callback(callbackArg);
    }
}

// Starts a backup transfer of the given source, destination and length. Waits for the previous transfer first. The
// game always passes isAsync 1, which queues CARDi_RequestStreamCommandCore on the worker thread.
int CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, UnkFunc *callback, void *callbackArg, u32 isAsync,
                               u32 reqType, u32 reqRetry, u32 reqMode) {
    CARDiCommon *p;
    u32 enabled;

    p = (CARDiCommon *) (u32) &gAccessState;
    func_02000b44((u32) (BuildInfo + 0x24));
    enabled = OS_DisableInterrupts();
    while (p->mFlag & 4) {
        OS_SleepThread(&p->mBusyQ);
    }
    p->mFlag |= 4;
    p->mCallback = callback;
    p->mCallbackArg = (u32) callbackArg;
    OS_RestoreInterrupts(enabled);
    p->mSrc = src;
    p->mDst = dst;
    p->mLen = len;
    p->mReqType = reqType;
    p->mReqRetry = reqRetry;
    p->mReqMode = reqMode;
    if (isAsync != 0) {
        CARDi_SetTask(CARDi_RequestStreamCommandCore);
        return 1;
    }
    gAccessState.mCurTh = data_0216ff5c.mCurrentThread;
    CARDi_RequestStreamCommandCore(p);
    return p->mCmd->mResult == 0;
}

// Sets the backup type, then reads one byte of the backup to identify it. Returns 1 when CARDiCommandArg.mResult is 0.
int CARD_IdentifyBackup(s32 type) {
    CARDiCommon *p;
    UnkFunc *callback;
    u32 callbackArg;
    u32 enabled;

    p = &gAccessState;
    func_02000b44((u32) (BuildInfo + 0x24));
    if (type == 0) {
        OS_Terminate();
    }
    CARD_CheckEnabled();
    enabled = OS_DisableInterrupts();
    while (p->mFlag & 4) {
        OS_SleepThread(&p->mBusyQ);
    }
    p->mFlag |= 4;
    p->mCallback = 0;
    p->mCallbackArg = 0;
    OS_RestoreInterrupts(enabled);
    CARDi_IdentifyBackupCore(type);
    gAccessState.mCurTh = data_0216ff5c.mCurrentThread;
    CARDi_Request(p, 2, 1);
    p->mCmd->mSrc = 0;
    p->mCmd->mDst = (u32) p->mBackupCachePageBuf;
    p->mCmd->mLen = 1;
    CARDi_Request(p, 6, 1);
    callback = p->mCallback;
    callbackArg = p->mCallbackArg;
    enabled = OS_DisableInterrupts();
    p->mFlag &= ~0x4c;
    OS_WakeupThread(&p->mBusyQ);
    if (p->mFlag & 0x10) {
        OS_WakeupThreadDirect(&p->mThread);
    }
    OS_RestoreInterrupts(enabled);
    if (callback != 0) {
        callback(callbackArg);
    }
    return p->mCmd->mResult == 0;
}

// Waits for the running transfer to end.
int CARD_WaitBackupAsync(void) {
    return CARDi_WaitAsync();
}

// Returns 1 when no transfer is running.
int CARD_TryWaitBackupAsync(void) {
    return CARDi_TryWaitAsync();
}

// Fills CARDiCommandArg.mType and the device description (size, page size, address width, timings) for a backup type.
// An unknown type clears them and stores 3 in CARDiCommandArg.mResult.
void CARDi_IdentifyBackupCore(s32 type) {
    CARDiCommandArg *p;
    u32 size;
    u32 device;

    p = gAccessState.mCmd;
    MI_CpuFill8(&p->mTotalSize, 0, 0x28);
    p->mType = type;
    if (type == 0) {
        return;
    }
    size = 1 << ((type >> 8) & 0xff);
    p->mTotalSize = size;
    device = type & 0xff;
    if (device == 1) {
        switch (size) {
            case 0x200:
                p->mPageSize = 0x10;
                p->mAddrWidth = 1;
                p->mProgramPage = 0x4f;
                break;
            case 0x2000:
                p->mPageSize = 0x20;
                p->mAddrWidth = 2;
                p->mProgramPage = 0x4f;
                break;
            case 0x10000:
                p->mPageSize = 0x80;
                p->mAddrWidth = 2;
                p->mProgramPage = 0x9e;
                break;
            default:
                goto fail;
        }
    } else if (device == 2) {
        switch (size) {
            case 0x40000:
                p->mWritePage = 0x18b;
                p->mWritePageTotal = 0x127f;
                p->mUnk_3c = 0x127f;
                p->mUnk_38 = 0x13435;
                p->mUnk_34 = 0x13435;
                break;
            case 0x80000:
            case 0x100000:
                p->mWritePage = 0x18b;
                p->mWritePageTotal = 0;
                p->mUnk_3c = 0x127f;
                p->mUnk_38 = 0x13435;
                break;
            default:
                goto fail;
        }
        p->mSectSize = 0x10000;
        p->mPageSize = 0x100;
        p->mAddrWidth = 3;
        p->mProgramPage = 0x4f;
    } else if (device == 3 && (size == 0x2000 || size == 0x8000)) {
        p->mPageSize = size;
        p->mAddrWidth = 2;
    } else {
    fail:
        p->mType = 0;
        p->mTotalSize = 0;
        gAccessState.mCmd->mResult = 3;
        return;
    }
}

// Makes the worker thread run the task: sets its priority, CARDiCommon.mCurTh and CARDiCommon.mTaskFunc, sets the task
// bit of CARDiCommon.mFlag and wakes the thread.
void CARDi_SetTask(void (*task)(CARDiCommon *)) {
    CARDiCommon *p;

    p = (CARDiCommon *) (u32) &gAccessState;
    OS_SetThreadPriority(&p->mThread, p->mPriority);
    p->mCurTh = &p->mThread;
    p->mTaskFunc = task;
    p->mFlag |= 8;
    OS_WakeupThreadDirect(&p->mThread);
}

// Takes the lock for the owner and target, waiting while another owner holds it. Reusing an owner with a different
// target ends in OS_Terminate.
void CARDi_LockResource(u32 owner, u32 target) {
    CARDiCommon *p;
    u32 enabled;

    p = (CARDiCommon *) (u32) &gAccessState;
    enabled = OS_DisableInterrupts();
    if (p->mLockOwner == owner) {
        if (p->mLockTarget != target) {
            OS_Terminate();
        }
    } else {
        while (p->mLockOwner != -3) {
            OS_SleepThread(&p->mLockQueue);
        }
        p->mLockOwner = owner;
        p->mLockTarget = target;
    }
    p->mLockRef++;
    p->mCmd->mResult = 0;
    OS_RestoreInterrupts(enabled);
}

// Gives the lock back. At a count of 0 the owner becomes -3 and the waiting threads wake up. A wrong owner or target
// ends in OS_Terminate.
void CARDi_UnlockResource(u32 owner, u32 target) {
    CARDiCommon *p;
    u32 enabled;

    p = &gAccessState;
    enabled = OS_DisableInterrupts();
    if (p->mLockOwner != owner || p->mLockRef == 0) {
        OS_Terminate();
    } else {
        if (p->mLockTarget != target) {
            OS_Terminate();
        }
        p->mLockRef--;
        if (p->mLockRef == 0) {
            p->mLockOwner = -3;
            p->mLockTarget = 0;
            OS_WakeupThread(&p->mLockQueue);
        }
    }
    p->mCmd->mResult = 0;
    OS_RestoreInterrupts(enabled);
}

// Sets up the lock and the command block, creates the worker thread and installs the tag 11 reply callback. Enables
// card access unless the halfword at 0x027ffc40 is 2.
void CARDi_InitCommon(void) {
    CARDiCommon *p;

    p = &gAccessState;
    p->mLockOwner = -3;
    p->mLockRef = 0;
    p->mLockTarget = 0;
    p->mCmd = &gRequestBlock;
    MemFillWordsByBlock_inline(&gRequestBlock, 0x40);
    DC_FlushRange(&gRequestBlock, 0x40);
    if (*(u16 *) 0x027ffc40 != 2) {
        MI_CpuCopy8((void *) 0x027ffe00, (void *) 0x027ffa80, 0x160);
    }
    p->mLockQueue.mTail = 0;
    p->mLockQueue.mHead = p->mLockQueue.mTail;
    p->mBusyQ.mTail = 0;
    p->mBusyQ.mHead = p->mBusyQ.mTail;
    p->mPriority = 4;
    OS_CreateThread(&p->mThread, CARDi_TaskThread, 0, (u8 *) &gRomBaseOffset, 0x400, p->mPriority);
    OS_WakeupThreadDirect(&p->mThread);
    PXI_SetFifoRecvCallback(11, CARDi_OnFifoRecv);
    if (*(u16 *) 0x027ffc40 != 2) {
        CARD_Enable(1);
    }
}

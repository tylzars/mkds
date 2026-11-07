#pragma once

#include "types.h"
#include "os_thread.h"

// The command block: mResult is the result of the last request.
typedef struct CARDiCommandArg {
    /* 00 */ u32 mResult;
    /* 04 */ s32 mType;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mSrc;
    /* 10 */ u32 mDst;
    /* 14 */ u32 mLen;
    /* 18 */ u32 mTotalSize;
    /* 1c */ u32 mSectSize;
    /* 20 */ u32 mPageSize;
    /* 24 */ u32 mAddrWidth;
    /* 28 */ u32 mProgramPage;
    /* 2c */ u32 mWritePage;
    /* 30 */ u32 mWritePageTotal;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
} CARDiCommandArg;

// 0x620 bytes at gAccessState; mThread is started with the 0x400 bytes at mUnk_220 as its stack.
typedef struct CARDiCommon {
    /* 000 */ CARDiCommandArg *mCmd;
    /* 004 */ s32 mCommand;
    /* 008 */ vs32 mLockOwner;
    /* 00c */ vs32 mLockRef;
    /* 010 */ OSThreadQueue mLockQueue;
    /* 018 */ u32 mLockTarget;
    /* 01c */ u32 mSrc;
    /* 020 */ u32 mDst;
    /* 024 */ u32 mLen;
    /* 028 */ u32 mDma;
    /* 02c */ u32 mReqType;
    /* 030 */ u32 mReqRetry;
    /* 034 */ u32 mReqMode;
    /* 038 */ UnkFunc *mCallback;
    /* 03c */ u32 mCallbackArg;
    /* 040 */ void (*mTaskFunc)(struct CARDiCommon *);
    /* 044 */ OSThread mThread;
    /* 0fc */ u8 mUnk_fc[8];
    /* 104 */ OSThread *mCurTh;
    /* 108 */ u32 mPriority;
    /* 10c */ OSThreadQueue mBusyQ;
    /* 114 */ vu32 mFlag;
    /* 118 */ u8 mUnk_118[8];
    /* 120 */ u8 mBackupCachePageBuf[0x100];
    /* 220 */ u8 mUnk_220[0x400];
} CARDiCommon;

// The ROM read state: the page reader, the control word, the page held in the cache buffer and the cache buffer.
typedef struct CARDRomStat {
    /* 00 */ void (*mReadFunc)(struct CARDRomStat *);
    /* 04 */ u32 mCtrl;
    /* 08 */ u32 mCachePage;
    /* 0c */ u8 mUnk_0c[0x14];
    /* 20 */ u32 mCacheBuf[0x80];
} CARDRomStat;

// The command block that CARDiCommon.mCmd points to.
extern CARDiCommandArg gRequestBlock;
// Added to the offset of every ROM read in CARDi_ReadRom; CARD_Init writes 0 and nothing else writes it.
extern u32 gRomBaseOffset;
extern CARDRomStat gRomReadState;

void CARDi_InitCommon(void);
void CARDi_UnlockResource(u32 owner, u32 target);
void CARDi_LockResource(u32 owner, u32 target);
void CARDi_SetTask(void (*task)(CARDiCommon *));
void CARDi_IdentifyBackupCore(s32 type);
int CARD_TryWaitBackupAsync(void);
int CARD_WaitBackupAsync(void);
int CARD_IdentifyBackup(s32 type);
int CARDi_RequestStreamCommand(u32 src, u32 dst, u32 len, UnkFunc *callback, void *callbackArg, u32 isAsync,
                               u32 reqType, u32 reqRetry, u32 reqMode);
void CARDi_RequestStreamCommandCore(CARDiCommon *p);
UnkFunc *CARDi_GetRomAccessor(void);
int CARD_WaitRomAsync(void);
void CARD_Init(void);
void CARDi_ReadRom(u32 dma, u32 src, u32 dst, u32 len, UnkFunc *callback, u32 callbackArg, u32 isAsync);
void CARDi_ReadRomSyncCore(CARDiCommon *c);
void CARDi_ReadCard(CARDRomStat *p);
int CARDi_TryReadCardDma(CARDRomStat *p);
void CARDi_OnReadCard(void);
void CARDi_SetCardDma(void);
void CARDi_SetRomOp(u32 cmd1, u32 cmd2);
int CARDi_ReadFromCache(CARDRomStat *p);
int CARDi_Request(CARDiCommon *p, int reqType, int retryCount);
void CARDi_TaskThread(void *arg);

#pragma once

#include "types.h"
#include "Main/Unknown/code_02124094.h" // Unk02124b1c, Unk0201ea30

struct Unk02021dc8;
struct Ncgr;
struct Nclr;

// Object behind gWiFiAikotobaCheck; LocateAndUploadWiFiAikotobaCheck fills 0x34 to 0x48.
typedef struct WiFiAikotobaCheck {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* 08 */ s32 mStateFrames;
    /* 0c */ s16 mOffset;
    /* 0e */ u16 mDigits[12];
    /* 26 */ u8 pad_26[2];
    /* 28 */ s32 mPendingWiFiState;
    /* 2c */ void *mHeap;
    // Table of cells built from the Bncl / Bnll by InitLayoutTable.
    /* 30 */ Unk02124b1c *mWiFiAikotobaCheckTable;
    /* 34 */ struct Unk02021dc8 *mWiFiAikotobaCheckMNcer;
    /* 38 */ struct Ncgr *mWiFiAikotobaCheckMNcgr;
    /* 3c */ struct Nclr *mWiFiAikotobaCheckMONclr;
    /* 40 */ Unk0201ea30 *mWiFiAikotobaCheckBncl;
    /* 44 */ u8 mUnk_44[4];
    /* 48 */ struct Unk0201ea30 *mWiFiAikotobaCheckBnll;
    /* 4c */ void *mWiFiMessages;
    /* 50 */ void *mCommonMessages;
} WiFiAikotobaCheck;

#include "00/code_02180608.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02047104.h"

extern WiFiStateCallbacks gWiFiAikotobaCheckCallbacks;
extern char data_ov000_021b0fc0[];
extern char data_ov000_021b0fcc[];
extern WiFiAikotobaCheck *gWiFiAikotobaCheck;

void RegisterWiFiAikotobaCheckCallbacks(void);
void func_ov000_02185368(void);
void AdvanceWiFiAikotobaCheck(void);
void AdvanceWiFiAikotobaCheckState2(void);
void AdvanceWiFiAikotobaCheckState1(void);
void AdvanceWiFiAikotobaCheckState0(void);
void func_ov000_021854f8(void);
void LocateAndUploadWiFiAikotobaCheck(void);
void func_ov000_021855f8(void);
void InitWiFiAikotobaCheck(void *a);
void func_ov000_021856a8(void);
void SetWiFiAikotobaCheckDigits(void);

#include "00/code_021832d8.h"

#pragma once

#include "types.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

// Object behind data_ov000_021b4c68 (0x40 bytes).
typedef struct Unk021b4c68 {
    /* 00 */ u32 mState;
    /* 04 */ u32 mNextState;
    /* 08 */ s32 mUnk_08;
    // Usually passed to RequestWiFiState right after it is stored; -1 until set.
    /* 0c */ s32 mPendingWiFiState;
    /* 10 */ s32 mUnk_10;
    /* 14 */ BOOL mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ void *mHeap;
    /* 20 */ u8 pad_20[0x18];
    /* 38 */ void *mWiFiMessages;
    /* 3c */ void *mCommonMessages;
} Unk021b4c68;

extern WiFiStateCallbacks data_ov000_021b0a98;
extern Unk021b4c68 *data_ov000_021b4c68;

void func_ov000_02180c04(void);
u32 func_ov000_02180c28(void);
void func_ov000_02180c3c(void);
void func_ov000_02180cdc(void);
void func_ov000_02180d94(void);
void func_ov000_02180e58(void);
void func_ov000_02180f80(void);
void func_ov000_02180ffc(void);
void func_ov000_021810dc(void);
void func_ov000_021811ec(void);
void func_ov000_021812f4(void);
void func_ov000_0218134c(void);
void func_ov000_02181458(void);
s32 func_ov000_0218151c(s32 a, s32 b, s32 *c);
u32 func_ov000_02181674(void);
s32 func_ov000_0218167c(void);
BOOL func_ov000_02181684(void);
void func_ov000_021816a0(void);
void func_ov000_021816a4(void);
void func_ov000_021816b0(void *heap);

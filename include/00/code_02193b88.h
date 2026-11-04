#pragma once

#include "types.h"
#include "00/code_0218f960.h"

// Payload at 0x04 of a GpiOperation whose 0x00 is 3.
typedef struct Unk02193858 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ void *mUnk_18;
} Unk02193858;

// Buffers made by GpiQueueOperationCallback, one for each request type; the first word is taken from the request.
typedef struct Unk02193954_0 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x18];
} Unk02193954_0;

typedef struct Unk02193954_1 {
    /* 0 */ s32 mUnk_00;
    /* 4 */ u8 mUnk_04[4];
} Unk02193954_1;

typedef struct Unk02193954_3 {
    /* 0 */ s32 mUnk_00;
    /* 4 */ u8 mUnk_04[8];
    /* c */ u32 mUnk_0c;
} Unk02193954_3;

typedef struct Unk02193954_4 {
    /* 0 */ s32 mUnk_00;
} Unk02193954_4;

// Three words printed by GpiPeerSendXfer.
typedef struct GpiTransferId {
    /* 0 */ u32 mUnk_00;
    /* 4 */ u32 mUnk_04;
    /* 8 */ u32 mUnk_08;
} GpiTransferId;

// Output buffer description built by GpiPeerQueueMessage.
typedef struct Unk02193c74 {
    /* 00 */ u32 mBuffer;
    /* 04 */ u32 mCapacity;
    /* 08 */ u32 mLength;
    /* 0c */ u32 mPos;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} Unk02193c74;

// Address passed to func_ov000_0218e4b4 by GpiPeerConnect.
typedef struct Unk02193d64 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk02193d64;

u32 GpiCreateOperation(GpConnection *param_1, int param_2, int param_3, int *param_4, int param_5, int param_6,
                       int param_7);

#include "00/code_021965a0.h"
#include "00/code_02196594.h"
#include "00/code_0218e2dc.h"

// Entry of the list behind GpiPeer.mUnk_38.
typedef struct Unk0219405c {
    /* 00 */ u32 mBuffer;
    /* 04 */ u8 mUnk_04[0xc];
    /* 10 */ s32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} Unk0219405c;

// Message handed to GpiQueueCallback by func_ov000_021941c4.
typedef struct Unk021941c4Msg {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} Unk021941c4Msg;

// Entry of the list at 0x38 of GpiPeer.
typedef struct Unk02194370Entry {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mLength;
    /* 0c */ u32 mPos;
} Unk02194370Entry;

extern char data_ov000_021b333c[];
extern u8 data_ov000_021b33a0[];
extern char data_ov000_021b3440[];
extern s8 data_ov000_021b3490[];
extern u8 data_ov000_021b3494[];
extern char data_ov000_021b34a4[];
extern char data_ov000_021b34a8[];
extern char data_ov000_021b34c8[];
extern char data_ov000_021b34d0[];
extern char data_ov000_021b34d8[];
extern char data_ov000_021b34e0[];
extern char data_ov000_021b34e8[];
extern char data_ov000_021b34f0[];
extern char data_ov000_021b34f8[];
extern char data_ov000_021b3500[];
extern u8 data_ov000_021b3508[];
extern u8 data_ov000_021b352c[];

s32 GpiPeerSendLenMsg(GpConnection *param_1, GpiPeer *peer, const char *param_3, s32 param_4);
u32 GpiPeerSendXfer(GpConnection *param_1, GpiPeer *param_2, u32 param_3, GpiTransferId *transferID);
s32 GpiPeerQueueMessage(GpConnection *param_1, GpiPeer *peer, u32 param_3, const char *message);
s32 GpiPeerConnect(GpConnection *param_1, GpiPeer *param_2);
int func_ov000_02193e70(GpConnection *a, GpiPeer *b);
GpiPeer *GpiPeerCreate(GpConnection *c, u32 d, u32 e);
void func_ov000_02193f18(u32 *a);
GpiPeer *func_ov000_02193f2c(GpConnection *object, u32 key);
s32 GpiUpdatePeers(GpConnection *e);
void func_ov000_02193ff4(s32 a);
void GpiPeerRemoveAndWriteQueuedMessages(GpConnection *f, GpiPeer *g);
void GpiPeerDelete(GpConnection *a, GpiPeer *b);
s32 GpiPeerUpdate(GpConnection *b, GpiPeer *c);
s32 func_ov000_021941c4(GpConnection *param_1, GpiPeer *param_2);
s32 func_ov000_02194370(GpConnection *a, GpiPeer *b);
s32 GpiPeerUpdateWaiting(GpConnection *param_1, GpiPeer *param_2);
// Declared here until the code that defines them is decompiled.
s32 func_ov000_02194590(GpConnection *param_1, GpiPeer *param_2);

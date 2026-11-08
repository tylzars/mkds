#pragma once

#include "types.h"

// 0x18-byte object whose first halfword selects what ProcessMPData does with the rest.
typedef struct MPMessage {
    /* 00 */ u16 mKind;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[2];
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b[0xb];
    /* 16 */ u8 mUnk_16;
    /* 17 */ u8 mUnk_17;
} MPMessage;

typedef struct Unk02050320 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mUnk_04;
} Unk02050320;

typedef struct Unk020503cc {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[4];
    /* 06 */ u8 mUnk_06[4];
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b[7];
} Unk020503cc;

typedef struct Unk020504a4 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[0x14];
    /* 16 */ u8 mUnk_16;
    /* 17 */ u8 mUnk_17;
} Unk020504a4;

#include "Main/Unknown/unk_02165000.h" // QueueMPDataToPortParams
#include "code_02142eac.h" // Unk021425e8

typedef struct Unk0217aa00_45c Unk0217aa00_45c;

u32 QueueMPDataToPortCallback(void);
BOOL QueueMPDataHalfwordAndWord(s32 kind, u16 destBitmap, s32 word);
BOOL func_020503cc(s32 playerIndex, u16 destBitmap);
BOOL func_020504a4(s32 playerIndex, u16 destBitmap);
BOOL QueueMPDataHalfword(s32 kind, u16 destBitmap);
BOOL QueueMPDataToPort(void *data, s32 dataSize, u16 destBitmap, void *sendBuffer, QueueMPDataToPortParams *params);
void MPDataPortCallback(Unk021425e8 *event);
void ProcessMPData(u32 aid, MPMessage *message);
void RemoveChild(u32 aid);
void AddChild(u32 aid, u8 *b, Unk0217aa00_45c *playerEntry);
void func_02050e60(s32 a);
void EndCallback(Unk021425e8 *event);
void End(void);
void SetStepAndRequestPending(s32 a);
BOOL func_020510ac(void);
s32 func_020510c8(void);
BOOL func_020510e4(void);
void DisconnectCallback(Unk021425e8 *event);
void Disconnect(void);
void EndParentCallback(Unk021425e8 *event);
void EndParent(void);
void EndMPCallback(Unk021425e8 *event);
void EndMP(void);
void EndDataSharing(void);
void DisconnectChildrenCallback(Unk021425e8 *event);
void DisconnectChildren(u32 aidBitmap);

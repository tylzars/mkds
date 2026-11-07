#pragma once

#include "types.h"

// 0x18-byte object whose first halfword selects what ProcessMPData does with the rest.
typedef struct Unk0205081c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[2];
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b[0xb];
    /* 16 */ u8 mUnk_16;
    /* 17 */ u8 mUnk_17;
} Unk0205081c;

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

u32 func_02050300(void);
BOOL QueueMPDataHalfwordAndWord(s32 a, u16 b, s32 c);
BOOL func_020503cc(s32 a, u16 b);
BOOL func_020504a4(s32 a, u16 b);
BOOL QueueMPDataHalfword(s32 a, u16 b);
BOOL QueueMPDataToPort(void *a, s32 b, u16 c, void *d, QueueMPDataToPortParams *e);
void MPDataPortCallback(Unk021425e8 *a);
void ProcessMPData(u32 a, Unk0205081c *b);
void RemoveChild(u32 a);
void AddChild(u32 a, u8 *b, Unk0217aa00_45c *c);
void func_02050e60(s32 a);
void EndCallback(Unk021425e8 *a);
void End(void);
void func_0205108c(s32 a);
BOOL func_020510ac(void);
s32 func_020510c8(void);
BOOL func_020510e4(void);
void DisconnectCallback(Unk021425e8 *a);
void Disconnect(void);
void EndParentCallback(Unk021425e8 *a);
void EndParent(void);
void EndMPCallback(Unk021425e8 *a);
void EndMP(void);
void EndDataSharing(void);
void DisconnectChildrenCallback(Unk021425e8 *a);
void DisconnectChildren(u32 a);

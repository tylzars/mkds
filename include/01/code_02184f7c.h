#pragma once

#include "types.h"
#include "01/code_021a5140.h"
#include "01/code_021a59cc.h"
#include "01/code_02188950.h" // Unk02188950

// Data that CreateLld gets for the name it is given.
typedef struct LldRecord {
    /* 0 */ u16 mUnk_00;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u16 mUnk_04;
    /* 6 */ u16 mUnk_06;
} LldRecord;

typedef struct LldData {
    /* 00 */ u16 mEntryCount;
    /* 02 */ LldRecord mRecords[1];
} LldData;

// Group of 0x20 bytes at Unk0218516c.mUnk_000.
typedef struct Unk0218516c_000 {
    /* 00 */ u8 mUnk_00[0x6];
    /* 06 */ s16 mUnk_06;
    /* 08 */ u8 mUnk_08[0x6];
    /* 0e */ s16 mUnk_0e;
    /* 10 */ u8 mUnk_10[0x6];
    /* 16 */ s16 mUnk_16;
    /* 18 */ u8 mUnk_18[0x6];
    /* 1e */ s16 mUnk_1e;
} Unk0218516c_000;

void func_ov001_02184f7c(Unk02188950 *mapObject);
void func_ov001_02184f8c(Unk02188950 *mapObject);
void SetLldEntryBounds(LldEntry *entry, s32 left, s32 top, s32 right, s32 bottom);
s32 GetLldEntryScale(LldEntry *entry);
void SetLldEntryScale(LldEntry *entry, s32 scale);
s32 GetLldEntryY(LldEntry *entry);
s32 GetLldEntryX(LldEntry *entry);
void SetLldEntryPos(LldEntry *entry, s32 screenX, s32 screenY);
s32 GetLldEntryFrameIndex(LldEntry *entry);
void func_ov001_02185018(LldEntry *entry, s32 frameOrCommand);
void func_ov001_021850a4(LldEntry *entry, s32 (*callback)(LldEntry *));
s32 FindLldEntryAtPoint(Lld *lld, s32 startIndex, s32 pointX, s32 pointY);
LldEntry *GetLldEntry(Lld *lld, s32 index);
void AdvanceLld(Lld *lld, Unk0218516c *oamBuffer);
Lld *CreateLld(const char *fileName, void *cells, void *cellAnims);

#include "01/code_021a6430.h"

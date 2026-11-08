#pragma once

#include "types.h"

// An emblem's 0x200 bytes of pixels and a byte that is 1 once the pixels are filled in.
typedef struct EmblemData {
    /* 000 */ u8 mPixels[0x200];
    /* 200 */ u8 mUnk_200;
} EmblemData;

void BuildRecordList(void);
u16 GetRecordCount(void);
s32 IsRecordFlagged(u16 listIndex);
s32 func_0211437c(u16 listIndex);
s32 func_02114360(u16 listIndex);
s32 func_02114344(u16 listIndex);
s32 func_02114328(u16 listIndex);
s32 func_0211430c(u16 listIndex);
s32 func_021142f0(u16 listIndex);
s32 GetRecordDate(u16 listIndex, void *dateBytes);
void CopyRecordText(u16 listIndex, void *buffer, u32 bufferSize);
s32 SetRecordFlag(u16 listIndex);
s32 ClearRecordFlag(u16 listIndex);
void ReadRecordEmblem(u16 listIndex, EmblemData *emblem, void *tiles);
void EraseRecord(u16 listIndex);
s32 GetRecordFriendKeyText(u16 listIndex, void *text);

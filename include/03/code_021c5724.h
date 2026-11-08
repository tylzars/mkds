#pragma once

#include "types.h"
#include "03/types_021d299c.h"

typedef struct OamEntry OamEntry;
typedef struct BgTextCanvas BgTextCanvas;
typedef struct Rect Rect;

// 0x5c bytes.
typedef struct ApList {
    /* 00 */ u8 *mEntries;
    /* 04 */ void *mXb4ApListBackNsc;
    /* 08 */ void *mYbBgStep31Ncl;
    /* 0c */ BgTextCanvas *mUnk_0c;
    /* 10 */ OamEntry *mUnk_10[5];
    /* 24 */ OamEntry *mUnk_24[5];
    /* 38 */ u32 mScrollTask;
    /* 3c */ u32 mBgOffsetTask;
    /* 40 */ u16 mScrollYMax;
    /* 42 */ u16 mUnk_42[3];
    /* 48 */ u16 mUnk_48[4];
    /* 50 */ s8 mHitRow;
    /* 51 */ u8 mEntryCount;
    /* 52 */ u8 mEntryIndex;
    /* 53 */ u8 mUnk_53;
    /* 54 */ u8 mUnk_54;
    /* 55 */ u8 mScrollTimer;
    /* 56 */ u8 mBgOffsetPending;
    /* 57 */ u8 mUnk_57;
    /* 58 */ u8 mUnk_58;
    /* 59 */ u8 mUnk_59;
} ApList;

extern const u8 data_ov003_021d6388[];
extern const u8 data_ov003_021d638c[];
extern Rect gApListRowRects[];
extern u16 data_ov003_021d63b8[];
extern u16 data_ov003_021d63ba[];
extern u16 data_ov003_021d63bc[];
extern u8 data_ov003_021d7228[];
extern u8 gJb4ApListNscName[];
extern u8 gApListSelectedRow;

void func_ov003_021c5724(void);
void StartApListScrollYIncrease(void);
void StartApListScrollYDecrease(void);
void MoveApListSelectedRow(int param_0);
void func_ov003_021c590c(void);
void WriteApListBgOffset(void);
void AdvanceApListScrollYIncrease(u32 param_0);
void AdvanceApListScrollYDecrease(u32 param_0);
void RefreshApListRowPositions(void);
void func_ov003_021c5b34(int param_0, int param_1);
void PrintApListEntryText(int param_0, int param_1);
void RefreshApList(void);
void func_ov003_021c5cdc(void);
void func_ov003_021c5e54(void);
void func_ov003_021c5ea4(void);
void func_ov003_021c5ec4(void);
void func_ov003_021c5f9c(void);
void func_ov003_021c6184(void);
void UpdateApList(void);
void func_ov003_021c6370(void);
void func_ov003_021c6394(void);
void func_ov003_021c63c4(void);
void func_ov003_021c6400(void);
void func_ov003_021c6508(void);
void LoadApListFilesAndSetBgCnt(void);
void CreateApList(void);
// Declared here until the code that defines them is decompiled.
// Declared here until the code that defines them is decompiled.

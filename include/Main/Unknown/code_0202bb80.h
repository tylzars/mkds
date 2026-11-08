#pragma once

#include "types.h"

typedef struct CellFileSet CellFileSet;
typedef struct PlayerEntryList PlayerEntryList;

// 6-byte elements of the table behind gEntryCellIndices: three indices into the arrays at member 0x18 of
// CellFileSet.
typedef struct EntryCellIndices {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mCharacterCellIndex;
    /* 04 */ u16 mKartCellIndex;
} EntryCellIndices;

// 8-byte elements of the table behind gEntryLabelTextRows.
typedef struct EntryLabelTextRow {
    /* 00 */ s16 mUnk_00;
    /* 02 */ u8 mUnk_02[6];
} EntryLabelTextRow;

// What the first member of PlayerEntryList points to.
typedef struct Unk02174e3c_00 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ u32 mUnk_10;
    /* 14 */ void *mUnk_14;
} Unk02174e3c_00;

extern u16 gTitleCellIndices[];
extern s16 gEntrySlotOffsetsX[];
extern u16 gNormalTimerDigitCellIndices[];
extern u16 gDownloadTimerDigitCellIndices[];
extern u16 gDownloadCharacterCellIndices[];
extern u16 gNormalCharacterCellIndices[];
extern EntryCellIndices gNormalEntryCellIndices[];
extern EntryCellIndices gDownloadEntryCellIndices[];
extern EntryLabelTextRow gNormalEntryLabelTextRows[];
extern EntryLabelTextRow gDownloadEntryLabelTextRows[];
extern const char data_usa_02162904[];
extern const char data_usa_0216292c[];
extern const char data_usa_02162954[];
extern const char data_usa_02162980[];
extern const char data_usa_021629a8[];
extern const char data_usa_021629d0[];
extern const char data_usa_021629fc[];
extern const char data_usa_02162a18[];
extern const char data_usa_02162a34[];
extern const char data_usa_02162a54[];
extern const char data_usa_02162a70[];
extern const char data_usa_02162a8c[];
extern const char data_usa_02162aac[];
extern const char data_usa_02162ad4[];
extern const char data_usa_02162afc[];
extern const char gSelectMenuEtcDownloadMBnclName[];
extern const char gSelectMenuEtcDownloadMBnllName[];
extern const char data_usa_02162b6c[];
extern const char data_usa_02162b88[];
extern const char data_usa_02162ba4[];
extern const char gSelectMenuEtcMBnclName[];
extern const char gSelectMenuEtcMBnllName[];
extern const char data_usa_02162bf0[];
extern const char data_usa_02162c14[];
extern const char gSelectMenuEtcTitleMBnclName[];
extern const char data_usa_02162c58[];
extern EntryCellIndices *gEntryCellIndices;
extern u16 *gCharacterCellIndices;
extern EntryLabelTextRow *gEntryLabelTextRows;
extern u16 *gTimerDigitCellIndices;

void AdvancePlayerEntryList(void);
void SetupPlayerEntryList(s32 mode, s32 screenKind);
void InitPlayerEntryList(void *parentHeap, void *mainOam);
void PrintEntryName(s32 entryIndex, u16 *name);
void func_0202c8dc(void);
void AdvancePlayerEntryListOffsets(void);
void func_0202cb2c(s32 entryIndex);
void func_0202cb68(s32 entryIndex);
void AdvanceEntrySlots(void);
void ResetEntrySlots(void);
void SetEntryTargetSlot(s32 entryIndex, s32 slot);
void SetEntrySlot(s32 entryIndex, s32 slot);

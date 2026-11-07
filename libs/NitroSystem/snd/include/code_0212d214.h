#pragma once

#include "types.h"
#include "code_02003024.h"

// Playback settings of a sequence: bank, volume, priorities and player number.
typedef struct NNSSndSeqParam {
    /* 0 */ u16 mBankNo;
    /* 2 */ u8 mVolume;
    /* 3 */ u8 mChannelPrio;
    /* 4 */ u8 mPlayerPrio;
    /* 5 */ u8 mPlayerNo;
    /* 6 */ u16 mReserved;
} NNSSndSeqParam;

// 12-byte records at 0x20 of Unk0212f788; NNSi_SndSeqArcGetSeqInfo returns one unless its first word is -1.
typedef struct Unk0212f788 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c; // number of records
    /* 20 */ u32 mUnk_20[3];
} Unk0212f788;

// File table entry: offset and size in the archive file, and the address it is loaded at.
typedef struct NNSSndArcFileInfo {
    /* 00 */ u32 mOffset;
    /* 04 */ u32 mSize;
    /* 08 */ void *mMem;
    /* 0c */ u32 mReserved;
} NNSSndArcFileInfo;

// File table of a sound archive: mCount entries from 0x0c.
typedef struct NNSSndArcFat {
    /* 00 */ u8 mBlockHeader[8];
    /* 08 */ u32 mCount;
    /* 0c */ NNSSndArcFileInfo mFiles[1];
} NNSSndArcFat;

// Table in the info block: mCount offsets from the start of the block.
typedef struct NNSSndArcOffsetTable {
    /* 00 */ u32 mCount;
    /* 04 */ u32 mOffset[1];
} NNSSndArcOffsetTable;

// Info block: offsets of the sequence, sequence archive, bank, wave archive, player and group tables.
typedef struct NNSSndArcInfo {
    /* 00 */ u8 mBlockHeader[8];
    /* 08 */ u32 mSeqOffset;
    /* 0c */ u32 mSeqArcOffset;
    /* 10 */ u32 mBankOffset;
    /* 14 */ u32 mWaveArcOffset;
    /* 18 */ u32 mPlayerInfoOffset;
    /* 1c */ u32 mGroupInfoOffset;
} NNSSndArcInfo;

// Symbol block of a sound archive; only a pointer to it is kept.
typedef struct NNSSndArcSymbol NNSSndArcSymbol;

// First 0x30 bytes of a sound archive file: where the symbol, info, FAT and file image blocks are.
typedef struct NNSSndArcHeader {
    /* 00 */ u8 mFileHeader[0x10];
    /* 10 */ u32 mSymbolDataOffset;
    /* 14 */ u32 mSymbolDataSize;
    /* 18 */ u32 mInfoOffset;
    /* 1c */ u32 mInfoSize;
    /* 20 */ u32 mFatOffset;
    /* 24 */ u32 mFatSize;
    /* 28 */ u32 mFileImageOffset;
    /* 2c */ u32 mFileImageSize;
} NNSSndArcHeader;

// Sequence entry of the info block: the file holding the sequence data and its playback settings.
typedef struct NNSSndArcSeqInfo {
    /* 00 */ u32 mFileId;
    /* 04 */ NNSSndSeqParam mParam;
} NNSSndArcSeqInfo;

// Entry of the info block for a sequence archive: the file that holds it.
typedef struct NNSSndArcSeqArcInfo {
    /* 0 */ u32 mFileId;
} NNSSndArcSeqArcInfo;

// Entry of a sequence archive: where the sequence data starts and its playback settings.
typedef struct NNSSndSeqArcSeqInfo {
    /* 00 */ u32 mOffset;
    /* 04 */ NNSSndSeqParam mParam;
} NNSSndSeqArcSeqInfo;

// Bank entry of the info block: the file and the wave archives (0xffff for none) the bank uses.
typedef struct NNSSndArcBankInfo {
    /* 00 */ u32 mFileId;
    /* 04 */ u16 mWaveArcNo[4];
} NNSSndArcBankInfo;

// Wave archive entry of the info block: the file in the low 24 bits and the flags (bit 0 loads single waves).
typedef struct NNSSndArcWaveArcInfo {
    /* 00 */ u32 mFileId : 24;
    /* 03 */ u32 mFlags : 8;
} NNSSndArcWaveArcInfo;

// Player entry of the info block: playable sequences, allocatable channels and heap size.
typedef struct NNSSndArcPlayerInfo {
    /* 00 */ u8 mSeqMax;
    /* 01 */ u8 mPadding;
    /* 02 */ u16 mAllocChBitFlag;
    /* 04 */ u32 mHeapSize;
} NNSSndArcPlayerInfo;

// Item of a group: type (0 sequence, 1 bank, 2 wave archive, 3 sequence archive), load flags and number.
typedef struct NNSSndArcGroupItem {
    /* 00 */ u8 mType;
    /* 01 */ u8 mLoadFlag;
    /* 02 */ u16 mPadding;
    /* 04 */ u32 mIndex;
} NNSSndArcGroupItem;

// Group entry of the info block: mCount items.
typedef struct NNSSndArcGroupInfo {
    /* 00 */ u32 mCount;
    /* 04 */ NNSSndArcGroupItem mItem[1];
} NNSSndArcGroupInfo;

// Sound archive.
typedef struct NNSSndArc {
    /* 00 */ NNSSndArcHeader mHeader;
    /* 30 */ u32 mFileOpen;
    /* 34 */ FSFile mFile;
    /* 7c */ FSFileID mFileId;
    /* 84 */ NNSSndArcFat *mFat;
    /* 88 */ NNSSndArcSymbol *mSymbol;
    /* 8c */ NNSSndArcInfo *mInfo;
} NNSSndArc;

// Links of an element in an NNSFndList: previous and next element.
typedef struct NNSFndLink {
    /* 0 */ void *mPrevObject;
    /* 4 */ void *mNextObject;
} NNSFndLink;

// List header of 12 bytes: first and last element, number of elements, and the offset of the links in an element.
typedef struct NNSFndList {
    /* 00 */ void *mHead;
    /* 04 */ void *mTail;
    /* 08 */ u16 mCount;
    /* 0a */ u16 mLinkOffset;
} NNSFndList;

// Called with the memory of a block, its size and the two values given to NNS_SndHeapAlloc when the heap frees it.
typedef void (*NNSSndHeapDisposeCallback)(void *mem, u32 size, void *data1, u32 data2);

// One section of a sound heap: the blocks allocated since the previous state was saved.
typedef struct NNSSndHeapSection {
    /* 00 */ NNSFndList mBlockList;
    /* 0c */ NNSFndLink mLink;
} NNSSndHeapSection;

// Sound heap: a frame heap and a list of sections.
typedef struct NNSSndHeap {
    /* 00 */ void *mHandle;
    /* 04 */ NNSFndList mSectionList;
} NNSSndHeap;

// Header of 0x20 bytes before each block NNS_SndHeapAlloc returns.
typedef struct NNSSndHeapBlock {
    /* 00 */ NNSFndLink mLink;
    /* 08 */ u32 mSize;
    /* 0c */ NNSSndHeapDisposeCallback mCallback;
    /* 10 */ void *mData1;
    /* 14 */ u32 mData2;
    /* 18 */ u8 mPadding[8];
} NNSSndHeapBlock;

// Position in the entries of an Unk02021968, set by SND_GetFirstInstDataPos and advanced by SND_GetNextInstData.
typedef struct Unk02021bc8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk02021bc8;

// Record SND_GetNextInstData writes.
typedef struct Unk020219f0 {
    /* 00 */ u8 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
} Unk020219f0;

// Entry of 8 bytes in the table at 0x18 of an Unk02021968: SND_DestroyWaveArc clears the entries of a chain linked
// through mUnk_04, SND_DestroyBank and SND_AssignWaveArc move entries between the chains of two objects.
typedef struct Unk02021be8 {
    /* 00 */ void *mUnk_00;
    /* 04 */ struct Unk02021be8 *mUnk_04;
} Unk02021be8;

// Object with two tables of mUnk_38 words from 0x3c. SND_GetWaveDataAddress and SND_SetWaveDataAddress read and write
// the first; LoadSingleWave reads the second, whose words b and b + 1 bound a block (the last block ends at mUnk_08).
typedef struct Unk02021968 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ Unk02021be8 mUnk_18[4];
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c[1];
} Unk02021968;

void NNS_SndHeapLoadState(NNSSndHeap *heap, s32 level);
s32 NNS_SndHeapSaveState(NNSSndHeap *heap);
void *NNS_SndHeapAlloc(NNSSndHeap *heap, u32 size, NNSSndHeapDisposeCallback callback, void *data1, u32 data2);
void NNS_SndHeapClear(NNSSndHeap *heap);
void NNS_SndHeapDestroy(NNSSndHeap *heap);
NNSSndHeap *NNS_SndHeapCreate(void *startAddress, u32 size);

void SymbolDisposeCallback(void *mem, u32 size, void *data1, u32 data2);
void FatDisposeCallback(void *mem, u32 size, void *data1, u32 data2);
void InfoDisposeCallback(void *mem, u32 size, void *data1, u32 data2);
void NNS_SndArcSetFileAddress(u32 fileId, void *address);
void *NNS_SndArcGetFileAddress(u32 fileId);
s32 NNS_SndArcReadFile(u32 fileId, void *buffer, u32 size, u32 offset);
u32 NNS_SndArcGetFileSize(u32 fileId);
NNSSndArcGroupInfo *NNS_SndArcGetGroupInfo(s32 groupNo);
NNSSndArcPlayerInfo *NNS_SndArcGetPlayerInfo(s32 playerNo);
NNSSndArcWaveArcInfo *NNS_SndArcGetWaveArcInfo(s32 waveArcNo);
NNSSndArcBankInfo *NNS_SndArcGetBankInfo(s32 bankNo);
NNSSndArcSeqArcInfo *NNS_SndArcGetSeqArcInfo(s32 seqArcNo);
NNSSndArcSeqInfo *NNS_SndArcGetSeqInfo(s32 seqNo);
NNSSndSeqParam *NNS_SndArcGetSeqArcParam(s32 seqArcNo, s32 index);
NNSSndArc *NNS_SndArcGetCurrent(void);
NNSSndArc *NNS_SndArcSetCurrent(NNSSndArc *arc);
void NNS_SndArcInitOnMemory(NNSSndArc *arc, void *data);
BOOL NNS_SndArcSetup(NNSSndArc *arc, NNSSndHeap *heap, BOOL symbolLoadFlag);
void NNS_SndArcInit(NNSSndArc *arc, const u8 *filePath, NNSSndHeap *heap, BOOL symbolLoadFlag);
void InitHeapSection(NNSSndHeapSection *section);
BOOL LoadSingleWaves(Unk02021968 *waveArc, Unk02021968 *bank, s32 waveArcNo, u32 fileId, NNSSndHeap *heap);
BOOL LoadSingleWave(Unk02021968 *waveArc, s32 waveNo, u32 fileId, NNSSndHeap *heap);
void SingleWaveDisposeCallback(void *mem, u32 size, void *data1, u32 data2);

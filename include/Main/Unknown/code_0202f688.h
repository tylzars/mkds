#pragma once

#include "types.h"
#include "Main/Unknown/code_020b3f7c.h" // Bmg
#include "code_0201ea58.h" // Unk0201ea30
#include "Main/Unknown/code_02124094.h" // Unk02124b1c

// Seven words at 0x24 of MultiSelectMemberGroup, passed by address to func_02025b20, func_02025a50 and func_02025a00.
typedef struct Unk02174e50_24 {
    /* 00 */ void *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ struct Unk02021dc8 *mUnk_08;
    /* 0c */ struct Unk0201ea30 *mUnk_0c;
    /* 10 */ Unk0201ea30 *mUnk_10;
    /* 14 */ struct Unk0201ea30 *mUnk_14;
    /* 18 */ Unk02124b1c *mUnk_18;
} Unk02174e50_24;

// 12-byte entries at 0x58 of MultiSelectMemberGroup.
typedef struct Unk02174e50_58 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk02174e50_58;

// 0xa8 bytes.
typedef struct MultiSelectMemberGroup {
    /* 00 */ u8 mUnk_00[0x24];
    /* 24 */ Unk02174e50_24 mGroupSParts;
    /* 40 */ void *mUnk_40;
    /* 44 */ void *mUnk_44;
    /* 48 */ s32 mUnk_48;
    /* 4c */ s32 mState;
    /* 50 */ s32 mUnk_50;
    /* 54 */ s32 mUnk_54;
    /* 58 */ Unk02174e50_58 mUnk_58[4];
    /* 88 */ BOOL mUnk_88;
    /* 8c */ s32 mUnk_8c;
    /* 90 */ s32 mBg3Offset;
    /* 94 */ s32 mUnk_94;
    /* 98 */ s32 mUnk_98;
    /* 9c */ BOOL mUnk_9c;
    /* a0 */ Bmg *mBannerMessages;
    /* a4 */ void *mHeap;
} MultiSelectMemberGroup;

// Argument of AdvanceMultiSelectMemberGroup: a halfword at 4.
typedef struct Unk0202f764 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk0202f764;

#include "Main/Unknown/code_020b4000.h" // Ncgr, Nclr

// 0x40 bytes.
typedef struct MultiSelectNS {
    /* 00 */ Ncgr *mNcgr;
    /* 04 */ Nclr *mNclr;
    /* 08 */ struct Unk02021dc8 *mNcer;
    /* 0c */ Unk0201ea30 *mBncl;
    /* 10 */ void *mBnbl;
    /* 14 */ Unk0201ea30 *mBnll;
    /* 18 */ Unk02124b1c *mUnk_18;
    /* 1c */ void *mUnk_1c;
    /* 20 */ void *mUnk_20;
    /* 24 */ void *mBannerMessages;
    /* 28 */ s32 mIndex;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mState;
    /* 34 */ s32 mStateFrames;
    /* 38 */ s32 mOffset;
    /* 3c */ void *mHeap;
} MultiSelectNS;

void func_0202f688(void);
void ReleaseMultiSelectMemberGroup(void);
s32 AdvanceMultiSelectMemberGroup(Unk0202f764 *a);
void InitMultiSelectMemberGroup(void *a, void *b, void *c);
void func_0202fd2c(void);
void func_0203003c(s32 a);
void func_02030200(void);
s32 func_0203023c(void);
s32 func_02030274(s32 a, s32 b);

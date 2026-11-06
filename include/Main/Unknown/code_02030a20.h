#pragma once

#include "types.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b4000.h"

// 0x1c-byte elements from 0x24 of MultiSelectMember; the buffer at 0x18 holds 0x40-byte elements.
typedef struct Unk02174e58_24 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Nclr *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ Unk0201ea30 *mUnk_0c;
    /* 10 */ Unk0201ea30 *mUnk_10;
    /* 14 */ Unk0201ea30 *mUnk_14;
    /* 18 */ Unk02124b1c *mUnk_18;
} Unk02174e58_24;

// 0xc-byte elements from 0xe0 of MultiSelectMember.
typedef struct Unk02174e58_e0 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
} Unk02174e58_e0;

// 0x154 bytes.
typedef struct MultiSelectMember {
    /* 00 */ u8 mUnk_00[0x24];
    /* 24 */ Unk02174e58_24 mUnk_24[2];
    /* 5c */ void *mUnk_5c;
    /* 60 */ void *mUnk_60;
    /* 64 */ Bmg *mBannerMessages;
    /* 68 */ Bmg *mCommonMessages;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ s32 mUnk_74;
    /* 78 */ BOOL mUnk_78;
    /* 7c */ BOOL mUnk_7c;
    /* 80 */ BOOL mUnk_80;
    /* 84 */ s32 mUnk_84;
    /* 88 */ BOOL mUnk_88;
    /* 8c */ BOOL mUnk_8c;
    /* 90 */ s32 mUnk_90;
    /* 94 */ s32 mState;
    /* 98 */ s32 mUnk_98;
    /* 9c */ s32 mTimer;
    /* a0 */ Unk02025ebc mUnk_a0[4];
    /* e0 */ Unk02174e58_e0 mUnk_e0[8];
    /* 140 */ s32 mUnk_140;
    /* 144 */ s32 mUnk_144;
    /* 148 */ BOOL mUnk_148;
    /* 14c */ s32 mUnk_14c;
    /* 150 */ void *mHeap;
} MultiSelectMember;

// Object whose u16 at 4 func_02030b18 and func_02030ea4 set.
typedef struct Unk02030b18 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk02030b18;

#include "Main/Unknown/unk_02174000.h"

void func_02030a20(void);
void ReleaseMultiSelectMember(void);
s32 func_02030b18(Unk02030b18 *a);
s32 func_02030ea4(Unk02030b18 *a);
void func_02031208(void);
u32 func_02031250(void);
u32 func_02031268(void);
void func_02031280(void *a, void *b, void *c);
void func_0203147c(void *a, void *b, void *c);
void InitMultiSelectMember(void *a, void *b, void *c);
void func_020317a0(void);
void func_02031960(void);
void func_02031b30(s32 a);
void func_02031b6c(void);
void func_02031ba4(void);
void func_02031e80(void);
void func_02031f5c(void);
s32 func_02032000(void);
void func_02032028(void);

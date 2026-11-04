#pragma once

#include "types.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02117224.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0201ea58.h"
#include "code_0212df7c.h"

// Object with a pointer at offset 0xc.
typedef struct Unk021a9bf4Block {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 *mUnk_0c;
} Unk021a9bf4Block;

// Object behind gSelectGhost.
typedef struct SelectGhost {
    /* 00 */ struct Unk02021dc8 *mSelectCupCourseMNcer;
    /* 04 */ Unk0201ea30 *mSelectCupCourseTaMBncl;
    /* 08 */ void *mSelectCupCourseTaMBnll;
    /* 0c */ struct Unk02021dc8 *mSelectGhostSONcer;
    /* 10 */ Unk0201ea30 *mSelectGhostSBncl;
    /* 14 */ void *mSelectGhostSBnbl;
    /* 18 */ void *mSelectGhostSBnll;
    /* 1c */ Nclr *mSelectGhostSONclr;
    /* 20 */ void *mPlayerCharacterMNcgr;
    /* 24 */ void *mPlayerCharacterMNcer;
    /* 28 */ Unk021a9bf4Block *mPlayerCharacterMONclr;
    /* 2c */ void *mPlayerCharacterMBncl;
    /* 30 */ Unk02124b1c *mSelectCupCourseTaMTable;
    /* 34 */ Unk02124b1c *mSelectGhostSTable;
    /* 38 */ void *mCommonMessages;
    /* 3c */ void *mMenuMessages;
    /* 40 */ void *mUnk_40;
    /* 44 */ void *mHeap;
    /* 48 */ s32 mState;
    /* 4c */ s32 mNextState;
    /* 50 */ s32 mStateFrames;
    // Set to 6 by the index steps, counts down to 0; 6 - timer indexes data_02156868 through func_020adc64.
    /* 54 */ s16 mOffsetTimers[2];
    // Negated and shifted into the upper half-word of the BG0 offset register.
    /* 58 */ s32 mBg0Offset;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mIndex;
    /* 64 */ u32 mUnk_64;
    /* 68 */ u32 mUnk_68;
    /* 6c */ s32 mResult;
} SelectGhost;

#include "01/code_0219c000.h"
#include "Main/Unknown/code_0212775c.h"
#include "01/code_021956dc.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0211d000.h"
#include "Main/Unknown/code_0212b000.h"
#include "00/code_02181f98.h"
#include "01/unk_021a8000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"

extern u16 data_ov001_021a6b38[];
extern u16 data_ov001_021a6b3c[];
extern u16 data_ov001_021a6b40[];
extern u16 data_ov001_021a6b48[];
extern u16 data_ov001_021a6b54[];
extern u16 data_ov001_021a6b60[];
extern u16 data_ov001_021a6b6c[];
extern u32 data_ov001_021a6b78[];
extern u16 data_ov001_021a6b88[];
extern u32 data_ov001_021a6ba4[];

void func_ov001_0219b540(void);
int AdvanceSelectGhost(void);
void AdvanceSelectGhostState7(void);
void AdvanceSelectGhostState6(void);
void AdvanceSelectGhostState5(void);
void AdvanceSelectGhostState4(void);
void AdvanceSelectGhostState3(void);
void AdvanceSelectGhostState2(void);
void AdvanceSelectGhostState1(void);
void AdvanceSelectGhostState0(void);
void func_ov001_0219baf4(void);
void InitSelectGhost(u32 a, u32 b, u32 c);
void func_ov001_0219be5c(void);
void func_ov001_0219bfc0(void);
void func_ov001_0219bff4(void);
void func_ov001_0219c058(void);
void func_ov001_0219c0bc(void);
void AdvanceSelectGhostOffsetTimers(void);
void func_ov001_0219c358(void);
void func_ov001_0219c3a8(void);
void func_ov001_0219c3bc(void);
void func_ov001_0219c3d8(void);
void func_ov001_0219c3ec(void);
void func_ov001_0219c428(void);
void func_ov001_0219c458(void);
void func_ov001_0219c46c(void);
void func_ov001_0219c480(void);
void func_ov001_0219c544(void);
void LoadSelectGhostAndKartIconData(void);

#include "00/code_021832d8.h"

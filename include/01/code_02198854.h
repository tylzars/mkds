#pragma once

#include "types.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02125de0.h"

// An s16 pair of OptionSelectMenu.
typedef struct Unk021a9be8Pair {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
} Unk021a9be8Pair;

// Object behind gOptionSelectMenu.
typedef struct OptionSelectMenu {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* 08 */ s32 mIndex; /* 0 and 1 are the two setting rows, 2 is the OK entry */
    /* 0c */ s32 mUnk_0c[2];
    /* 14 */ s32 mUnk_14[2];
    /* 1c */ BOOL mUnk_1c;
    /* counted only in states 0, 1, 3, 4; zeroed when 0, 1, 3 hand over and when 4 hands over to 5 (OK path); on
       the Back path state 4 keeps counting while it requests the next option state */
    /* 20 */ s32 mStateFrames;
    /* 24 */ s16 mBg0Bg1Offset;
    /* 26 */ Unk021a9be8Pair mUnk_26[3];
    /* 32 */ u8 mUnk_32[2];
    /* 34 */ s32 mNextOptionState; /* only ever 0 (the top menu state), passed to RequestOptionState */
    /* 38 */ BOOL mUnk_38;
    /* 3c */ BOOL mUnk_3c;
    /* 40 */ s32 mOffsetTimers[2][2];
    /* 50 */ void *mHeap;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by func_02124ed0; indexed with an offset
    // added
    /* 54 */ Unk02124b1c *mOptionSelectMenuMTable;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by func_02124ed0; indexed with an offset
    // added
    /* 58 */ Unk02124b1c *mOptionSelectMenuSTable;
    /* 5c */ struct Unk02021dc8 *mOptionSelectMenuMNcer;
    /* 60 */ struct Unk02021dc8 *mOptionSelectMenuSNcer;
    /* 64 */ Ncgr *mOptionSelectMenuMNcgr;
    /* 68 */ Ncgr *mOptionSelectMenuSNcgr;
    /* 6c */ Nclr *mOptionSelectMenuMONclr;
    /* 70 */ Nclr *mOptionSelectMenuSONclr;
    /* 74 */ Unk0201ea30 *mOptionSelectMenuMBncl;
    /* 78 */ Unk0201ea30 *mOptionSelectMenuSBncl;
    /* 7c */ void *mOptionSelectMenuSBnbl;
    /* 80 */ struct Unk0201ea30 *mOptionSelectMenuMBnll;
    /* 84 */ struct Unk0201ea30 *mOptionSelectMenuSBnll;
    /* 88 */ struct Bmg *mOptionMessages;
    /* 8c */ void *mCommonMessages;
} OptionSelectMenu;

// Object behind data_0217aa08; the byte at 0x31 of the object at its first member holds flags.
extern u8 data_ov001_021a6a20[];
extern u8 data_ov001_021a6a24[];
extern u8 gOptionSelectMenuValueCounts[];
extern u8 data_ov001_021a6a30[];
extern u8 data_ov001_021a6a34[];
extern u8 gOptionSelectMenuValueSTableIndices[][3];
extern s32 gOptionSelectMenuGroupSTableCounts[];
extern u8 gOptionSelectMenuTimerSTableIndices[][3][2];
extern u8 gOptionSelectMenuGroupSTableIndices[][12];

void RegisterOptionSelectMenuCallbacks(void);
void WriteOptionSelectMenuRegisters(void);
void AdvanceOptionSelectMenu(void);
void AdvanceOptionSelectMenuOffsetTimers(void);
void SetOptionSelectMenuRowsOnOff(void);
void SetOptionSelectMenuValuesOnOff(void);
void WriteOptionSelectMenuTableOffsets(void);
void AdvanceOptionSelectMenuState5(void);
void AdvanceOptionSelectMenuState4(void);
void AdvanceOptionSelectMenuState3(void);
void AdvanceOptionSelectMenuState2(void);
void AdvanceOptionSelectMenuState1(void);
void AdvanceOptionSelectMenuState0(void);
void func_ov001_02199374(void);
void func_ov001_021993b8(void);
void func_ov001_02199420(void);
void LocateAndQueueOptionSelectMenu(void);
/* slot mRelease of OptionStateCallbacks; clears the global and undoes the display setup (DISPCNT bit 1 cleared),
   the state heap is destroyed by AdvanceOptionStates after it returns */
void ReleaseOptionSelectMenu(void);
void InitOptionSelectMenu(void *a);
void InitOptionSelectMenuTexts(void);

#include "00/code_021832d8.h"

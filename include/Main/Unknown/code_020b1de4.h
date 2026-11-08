#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02024000.h"

// Seven words: six values and the number of values set.
typedef struct ChoisesSList {
    /* 00 */ s32 mValues[6];
    /* 18 */ s32 mValueCount;
} ChoisesSList;

// Object behind gChoisesS, 0x1a4 bytes allocated by InitChoisesS.
typedef struct ChoisesS {
    // Non-zero from opening the list screen in the race until it is closed there; other race code stops meanwhile.
    /* 000 */ s32 mOpenDuringRace;
    /* 004 */ s32 mPrevOpenDuringRace;
    /* 008 */ s32 mUnk_008;
    // Set once a non-zero pick is stored (not by the auto pick); open and close requests and list input are ignored.
    /* 00c */ s32 mPickLocked;
    /* 010 */ BOOL mUnk_010;
    // Calls since a list entry was picked, 0 when none; past 0xf mPickedValue is latched and this goes back to 0.
    /* 014 */ s32 mPickFrames;
    // Calls since a close was asked for, 0 when none; past 4 the close is requested and this goes back to 0.
    /* 018 */ s32 mCloseFrames;
    // Calls counted in mode 5 near the end of the race; past 0x384 mPickedValue is set with no input.
    /* 01c */ s32 mAutoPickFrames;
    /* 020 */ BOOL mUnk_020;
    // The value handed to the race scene, 0 = none; usually copied from mSelectedValue when a pick completes.
    /* 024 */ s32 mPickedValue;
    /* 028 */ s32 mSelectedValue;
    /* 02c */ s32 mUnk_02c;
    /* 030 */ s32 mUnk_030;
    // Counts calls and wraps at 0x32; zeroed when the selection steps; the list draw writes two tiles below 0x1e.
    /* 034 */ s32 mCycleFrames;
    /* 038 */ ChoisesSList mLists[4];
    /* 0a8 */ void *mFont;
    /* 0ac */ u8 mCharCanvases[4][0x20];
    /* 12c */ TextCanvas mTextCanvases[4];
    /* 16c */ Nclr *mChoisesSBNclr;
    /* 170 */ Ncgr *mChoisesSBNcgr;
    /* 174 */ u16 *mList1Chars;
    /* 178 */ u16 *mList2Chars;
    /* 17c */ Nscr *mList0Nscr;
    /* 180 */ Nscr *mList1Nscr;
    /* 184 */ Nscr *mList2Nscr;
    /* 188 */ Nscr *mList3Nscr;
    /* 18c */ Nscr *mChoisesSNscrs[6];
} ChoisesS;

void func_020b24cc(TextCanvas *a, void *b, void *c, s32 d, s32 e);
u32 func_020b24a4(TextCanvas *a, s32 b, s32 c, u32 d, u32 e, void *f);
void InitChoisesS(void);
void ClearChoisesSPointer(void);

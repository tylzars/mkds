#pragma once

#include "types.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_021114cc.h" // RecordScreenCallbacks

// Object behind gOptionTopMenu.
typedef struct OptionTopMenu {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* Init leaves it unset when the previous option state is not 1, 2 or 4 (1, 4 -> 0, 2 -> 1) */
    /* 08 */ s32 mIndex;
    /* counted only in states 1, 4, 5; zeroed when 1 and 4 hand over and 5 hands over to 6; state 5 keeps counting
       while it requests the next option state */
    /* 0c */ s32 mStateFrames;
    /* option state passed to RequestOptionState (1, 2 or 4); no initial store, set by the input handler (state 3,
       also state 9), not set for entry 2 (dialog path); also tested inside the screen */
    /* 10 */ s32 mNextOptionState;
    /* 14 */ BOOL mUnk_14;
    /* stored to reg_G2_BG0OFS without negation (the other mBg0Offset members are stored negated) */
    /* 18 */ s32 mBg0Offset;
    /* 1c */ void *mUnk_1c;
    // one 0x40-byte record per cell of the Bncl member, built by InitLayoutTable
    /* 20 */ LayoutTableEntry *mOptionTopMenuSTable;
    /* 24 */ struct Unk02021dc8 *mOptionTopMenuSNcer;
    /* 28 */ Ncgr *mOptionTopMenuSNcgr;
    /* 2c */ Nclr *mOptionTopMenuSONclr;
    /* 30 */ struct Unk0201ea30 *mOptionTopMenuSBncl;
    /* 34 */ void *mOptionTopMenuSBnbl;
    /* 38 */ struct Bmg *mOptionMessages;
    /* 3c */ struct Bmg *mCommonMessages;
} OptionTopMenu;

// Object behind RecordGpx.mPlayerCharacterMONclr.
typedef struct Unk021a9bd8_40 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 *mUnk_0c;
} Unk021a9bd8_40;

// Object behind gRecordGpx.
typedef struct RecordGpx {
    /* 00 */ Ncgr *mRecordGpxMNcgr;
    /* 04 */ struct Unk02021dc8 *mRecordGpxMNcer;
    /* 08 */ Unk0201ea30 *mRecordGpxMBncl;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ Unk0201ea30 *mRecordGpxMBnll;
    /* 14 */ Ncgr *mRecordGpxSNcgr;
    /* 18 */ struct Unk02021dc8 *mRecordGpxSNcer;
    /* 1c */ Unk0201ea30 *mRecordGpxSBncl;
    /* 20 */ struct Unk0201ea30 *mRecordGpxSBnbl;
    /* 24 */ Unk0201ea30 *mRecordGpxSBnll;
    /* 28 */ Ncgr *mRecordTrophyONcgr;
    /* 2c */ struct Unk02021dc8 *mRecordTrophyONcer;
    /* 30 */ Nclr *mRecordTrophySONclr;
    /* 34 */ void *mRecordTrophySOBncl;
    /* 38 */ void *mPlayerCharacterMNcgr;
    /* 3c */ struct Unk02021dc8 *mPlayerCharacterMNcer;
    /* 40 */ Unk021a9bd8_40 *mPlayerCharacterMONclr;
    /* 44 */ struct Unk0201ea30 *mPlayerCharacterMBncl;
    /* 48 */ Nscr *mRecordGpxSNscr;
    /* 4c */ void *mZeroBuffer;
    /* 50 */ LayoutTableEntry *mRecordGpxMTable;
    /* 54 */ LayoutTableEntry *mRecordGpxSTable;
    /* 58 */ void *mCommonMessages;
    /* 5c */ void *mHeap;
    /* 60 */ s32 mState;
    /* 64 */ s32 mNextState;
    /* 68 */ s32 mStateFrames;
    // The register receives the negation of this value in its upper half-word.
    /* 6c */ s32 mBg0Offset;
    // X half of reg_G2S_DB_BG3OFS (0x0400101c): the SUB engine's BG3, stored negated; the Y half is mUnk_74 (also the y
    // of the S cells)
    /* 70 */ s32 mBg3OffsetX;
    /* 74 */ s32 mBg3OffsetY;
    /* 78 */ s32 mIndex;
    /* 7c */ s32 mUnk_7c;
    // Set to 6, counted down while above 0; the row member is set to -func_020adc64(6 - timer) for [0] and
    // +func_020adc64(6 - timer) for [1] (stored, not added).
    /* 80 */ s32 mOffsetTimers[2];
    /* 88 */ BOOL mUnk_88;
    /* 8c */ BOOL mUnk_8c;
    /* 90 */ s32 mUnk_90;
} RecordGpx;

extern u8 data_ov001_021a65f0[][4];
extern const u16 data_ov001_021a66cc[4][3];
extern const u16 data_ov001_021a66b4[4][3];
extern const u16 data_ov001_021a6674[4][2];

#include "01/code_02192e78.h"
#include "01/code_021932e4.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/code_02194000.h"
#include "01/code_0219e000.h"
#include "Main/Unknown/code_02111000.h"

#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0212426c.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0211d000.h"
#include "Main/Unknown/code_02047104.h"

extern const u16 data_ov001_021a6614[4];
extern const u16 data_ov001_021a662c[4];
extern const u16 data_ov001_021a663c[4];
extern const u16 data_ov001_021a6654[4];
extern const u16 data_ov001_021a665c[4];
extern const u16 data_ov001_021a666c[4];
// Objects whose layout isn't known yet.
extern const RecordScreenCallbacks gRecordGpxCallbacks;
extern const RecordScreenCallbacks gRecordTAttCallbacks;

void RegisterRecordGpxCallbacks(void);
void func_ov001_02193c84(void);
void func_ov001_02193ccc(void);
void AdvanceRecordGpx(void);
void AdvanceRecordGpxState6(void);
void AdvanceRecordGpxState5(void);
void AdvanceRecordGpxState4(void);
void AdvanceRecordGpxState3(void);
void AdvanceRecordGpxState2(void);
void AdvanceRecordGpxState1(void);
void AdvanceRecordGpxState0(void);
void func_ov001_021946d0(void);
void InitRecordGpx(void *heap);
void RequestRecordGpxState6(void);
void RequestRecordGpxState5(void);
void func_ov001_021949d4(void);
void RequestRecordGpxState3(void);
void RequestRecordGpxState2(void);
void RequestRecordGpxState1AndSetup(void);
void func_ov001_02194a50(void);
u32 func_ov001_02194c9c(u32 a);
u32 func_ov001_02194d04(s32 a);
void func_ov001_02194d18(void);
void func_ov001_02194d48(void);
void SetupRecordGpx(void);
void AdvanceRecordGpxOffsetTimers(void);
void SetupRecordGpxDashes(s32 a);
void SetupRecordGpxValues(s32 a);
void LocateAndQueueRecordGpx(void);

#include "00/code_021832d8.h"

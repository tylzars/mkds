#pragma once

#include "types.h"
#include "Main/Unknown/code_02124094.h" // Unk02124b1c, Unk0201ea30

typedef struct RecordTopMenu {
    /* 0x00 */ struct Unk02021dc8 *mRecordTopMenuMNcer;
    /* 0x04 */ Unk0201ea30 *mRecordTopMenuMBncl;
    /* 0x08 */ struct Unk0201ea30 *mRecordTopMenuMBnll;
    /* 0x0c */ struct Unk02021dc8 *mRecordTopMenuSNcer;
    /* 0x10 */ struct Unk0201ea30 *mRecordTopMenuSBncl;
    /* 0x14 */ struct Unk0201ea30 *mRecordTopMenuSBnbl;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by func_02124ed0
    /* 0x18 */ Unk02124b1c *mRecordTopMenuMTable;
    // one 0x40-byte record per cell of the Bncl (plus Bnll) members, built by func_02124ed0
    /* 0x1c */ Unk02124b1c *mRecordTopMenuSTable;
    /* 0x20 */ void *mUnk_20;
    /* 0x24 */ struct Bmg *mRecordMessages;
    /* 0x28 */ void *mUnk_28;
    /* 0x2c */ void *mHeap;
    /* 0x30 */ s32 mState;
    /* 0x34 */ s32 mNextState;
    /* 0x38 */ s32 mStateFrames; /* counted only in states 1, 2, 5, 6, 7, 11 */
    /* 0x3c */ s32 mBg0Offset;
    /* 0x40 */ s32 mIndex;
    /* 0x44 */ s32 mUnk_44;
} RecordTopMenu;

#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02111000.h"
#include "01/code_021956dc.h"
#include "00/code_02181f98.h"
#include "01/code_0219a000.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02036c5c.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_02047104.h"

void RegisterRecordTopMenuCallbacks(void);
void WriteRecordTopMenuRegisters(void);
void func_ov001_0219a0c0(void);
void AdvanceRecordTopMenu(void);
void AdvanceRecordTopMenuState11(void);
void AdvanceRecordTopMenuState10(void);
void AdvanceRecordTopMenuState9(void);
void AdvanceRecordTopMenuState8(void);
void AdvanceRecordTopMenuState7(void);
void AdvanceRecordTopMenuState6(void);
void AdvanceRecordTopMenuState5(void);
void AdvanceRecordTopMenuState4(void);
void AdvanceRecordTopMenuState3(void);
void AdvanceRecordTopMenuState2(void);
void AdvanceRecordTopMenuState1(void);
void AdvanceRecordTopMenuState0(void);
void ReleaseRecordTopMenu(void);
void InitRecordTopMenu(void *heap);
void func_ov001_0219ac98(void);
void DecrementRecordTopMenuIndexAndStartSound(void);
void IncrementRecordTopMenuIndexAndStartSound(void);
void RequestRecordTopMenuState11(void);
void RequestRecordTopMenuState10AndRequestTxtSystemClose(void);
void RequestRecordTopMenuState9AndStartSound(void);
void RequestRecordTopMenuState8AndSetupTxtSystemSubText(void);
void RequestRecordTopMenuState7(void);
void RequestRecordTopMenuState6(void);
void RequestRecordTopMenuState5AndStartSound(void);
void RequestRecordTopMenuState4(void);
void func_ov001_0219ae44(void);
void RequestRecordTopMenuState2(void);
void RequestRecordTopMenuState1(void);
void ResetRecordTopMenu(void);
void SetRecordTopMenuRowOff(s32 a);
void SetRecordTopMenuRowOn(s32 a);
void LocateAndQueueRecordTopMenu(void);

#include "00/code_021832d8.h"

#pragma once

#include "types.h"
#include "Main/Unknown/code_02124094.h" // Unk02124b1c, Unk0201ea30

typedef struct RecordTopMenu {
    /* 0x00 */ struct Unk02021dc8 *mUnk_00;
    /* 0x04 */ Unk0201ea30 *mUnk_04;
    /* 0x08 */ void *mUnk_08;
    /* 0x0c */ struct Unk02021dc8 *mUnk_0c;
    /* 0x10 */ void *mUnk_10;
    /* 0x14 */ void *mUnk_14;
    /* 0x18 */ Unk02124b1c *mUnk_18;
    /* 0x1c */ Unk02124b1c *mUnk_1c;
    /* 0x20 */ void *mUnk_20;
    /* 0x24 */ void *mUnk_24;
    /* 0x28 */ void *mUnk_28;
    /* 0x2c */ void *mHeap;
    /* 0x30 */ s32 mUnk_30;
    /* 0x34 */ s32 mUnk_34;
    /* 0x38 */ s32 mUnk_38;
    /* 0x3c */ s32 mUnk_3c;
    /* 0x40 */ s32 mUnk_40;
    /* 0x44 */ s32 mUnk_44;
} RecordTopMenu;

#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02111000.h"
#include "01/code_021956dc.h"
#include "00/code_02182fdc.h"
#include "01/code_0219a000.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02036c5c.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020472a8.h"

extern RecordTopMenu *gRecordTopMenu;

void RegisterRecordTopMenuCallbacks(void);
void func_ov001_0219a078(void);
void func_ov001_0219a0c0(void);
void AdvanceRecordTopMenu(void);
void func_ov001_0219a1a4(void);
void func_ov001_0219a240(void);
void func_ov001_0219a258(void);
void func_ov001_0219a2ec(void);
void func_ov001_0219a304(void);
void func_ov001_0219a3a0(void);
void func_ov001_0219a4fc(void);
void func_ov001_0219a5bc(void);
void func_ov001_0219a764(void);
void func_ov001_0219a77c(void);
void func_ov001_0219a80c(void);
void func_ov001_0219a938(void);
void func_ov001_0219a950(void);
void InitRecordTopMenu(void *heap);
void func_ov001_0219ac98(void);
void func_ov001_0219ad10(void);
void func_ov001_0219ad3c(void);
void func_ov001_0219ad68(void);
void func_ov001_0219ad7c(void);
void func_ov001_0219ad98(void);
void func_ov001_0219adbc(void);
void func_ov001_0219ade8(void);
void func_ov001_0219adfc(void);
void func_ov001_0219ae10(void);
void func_ov001_0219ae30(void);
void func_ov001_0219ae44(void);
void func_ov001_0219ae60(void);
void func_ov001_0219ae74(void);
void func_ov001_0219ae88(void);
void func_ov001_0219af90(s32 a);
void func_ov001_0219afc8(s32 a);
void func_ov001_0219b000(void);

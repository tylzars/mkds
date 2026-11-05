#pragma once

#include "types.h"

extern u8 data_ov000_021b05d8[][5];

#include "code_0201ea58.h"
#include "Main/Unknown/code_02124094.h"

struct Unk02021dc8;
struct Ncgr;
struct Nclr;

// Object behind gWiFiTopMenu; LocateAndQueueWiFiTopMenu fills 0x20 to 0x30.
typedef struct WiFiTopMenu {
    /* 00 */ s32 mState;
    /* 04 */ u32 mNextState;
    /* 08 */ s32 mIndex;
    /* 0c */ s32 mStateFrames;
    /* 10 */ s32 mPendingWiFiState;
    /* 14 */ void *mHeap;
    /* 18 */ s32 mUnk_18;
    /* 1c */ Unk02124b1c *mUnk_1c;
    /* 20 */ struct Unk02021dc8 *mUnk_20;
    /* 24 */ struct Ncgr *mUnk_24;
    /* 28 */ struct Nclr *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ Unk0201ea30 *mUnk_30;
    /* 34 */ u8 pad_34[4];
    /* 38 */ void *mUnk_38;
    /* 3c */ void *mUnk_3c;
} WiFiTopMenu;

#include "00/code_02180608.h"
#include "00/unk_021b4000.h"
#include "00/code_02181f98.h"
#include "code_02021db0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02047104.h"

// Objects whose layout isn't known yet.
extern u8 data_ov000_021b05c0[];
extern const u8 data_ov000_021b05c4[];
extern const u8 data_ov000_021b05c8[];
// Objects whose layout isn't known yet.
extern s32 data_ov000_021b05cc[];
extern Unk021b0cd4 gWiFiTopMenuCallbacks;
extern WiFiTopMenu *gWiFiTopMenu;

void RegisterWiFiTopMenuCallbacks(void);
void func_ov000_02181738(void);
void AdvanceWiFiTopMenu(void);
void func_ov000_021817e8(void);
void AdvanceWiFiTopMenuState8(void);
void AdvanceWiFiTopMenuState7(void);
void AdvanceWiFiTopMenuState6(void);
void AdvanceWiFiTopMenuState5(void);
// Declared here until the code that defines them is decompiled.
void AdvanceWiFiTopMenuState4(void);
void AdvanceWiFiTopMenuState3(void);
void AdvanceWiFiTopMenuState2(void);
void AdvanceWiFiTopMenuState1(void);
void AdvanceWiFiTopMenuState0(void);
s32 func_ov000_02181df0(void);
void LocateAndQueueWiFiTopMenu(void);
void func_ov000_02181e8c(void);
void InitWiFiTopMenu(void *heap);

#include "00/code_021832d8.h"

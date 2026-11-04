#pragma once

#include "types.h"

extern u8 data_ov000_021b06d0[2][4];

#include "Main/Unknown/code_02124094.h" // Unk02124b1c

struct Unk02021dc8;
struct Ncgr;
struct Nclr;

// Object behind gWiFiAikotoba; func_ov000_021851a0 fills 0x20 to 0x30.
typedef struct Unk021b4c84 {
    /* 00 */ s32 mState;
    /* 04 */ s32 mNextState;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ Unk02124b1c *mUnk_1c;
    /* 20 */ struct Unk02021dc8 *mUnk_20;
    /* 24 */ struct Ncgr *mUnk_24;
    /* 28 */ struct Nclr *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ void *mUnk_30;
    /* 34 */ u8 pad_34[4];
    /* 38 */ void *mUnk_38;
    /* 3c */ void *mUnk_3c;
} Unk021b4c84;

#include "00/code_02180608.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02047104.h"

extern u8 data_ov000_021b06bc[2];
extern u8 data_ov000_021b06c0[2];
extern u8 data_ov000_021b06c4[2];
extern s32 data_ov000_021b06c8[2];
extern u8 data_ov000_021b06d8[2];
extern u8 data_ov000_021b06dc[12];
extern Unk021b0cd4 gWiFiAikotobaCallbacks;
extern char data_ov000_021b0ee8[];
extern char data_ov000_021b0ef4[];
extern Unk021b4c84 *gWiFiAikotoba;

void RegisterWiFiAikotobaCallbacks(void);
void func_ov000_02184bcc(void);
void AdvanceWiFiAikotoba(void);
void func_ov000_02184c74(void);
void AdvanceWiFiAikotobaState7(void);
void AdvanceWiFiAikotobaState6(void);
void AdvanceWiFiAikotobaState5(void);
void AdvanceWiFiAikotobaState4(void);
void AdvanceWiFiAikotobaState3(void);
void AdvanceWiFiAikotobaState2(void);
void AdvanceWiFiAikotobaState1(void);
void AdvanceWiFiAikotobaState0(void);
u32 func_ov000_02185184(void);
void func_ov000_021851a0(void);
void func_ov000_02185230(void);
void InitWiFiAikotoba(void *a);

#include "00/code_021832d8.h"

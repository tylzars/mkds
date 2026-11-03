#pragma once

#include "types.h"
#include "Main/Unknown/code_02124094.h" // Unk02124b1c, Unk0201ea30

struct Unk02021dc8;
struct Ncgr;
struct Nclr;

// Object behind gWiFiAikotobaCheck; func_ov000_0218554c fills 0x34 to 0x48.
typedef struct Unk021b4c88 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s16 mUnk_0c;
    /* 0e */ u16 mUnk_0e[12];
    /* 26 */ u8 pad_26[2];
    /* 28 */ s32 mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ Unk02124b1c *mUnk_30;
    /* 34 */ struct Unk02021dc8 *mUnk_34;
    /* 38 */ struct Ncgr *mUnk_38;
    /* 3c */ struct Nclr *mUnk_3c;
    /* 40 */ Unk0201ea30 *mUnk_40;
    /* 44 */ u8 mUnk_44[4];
    /* 48 */ void *mUnk_48;
    /* 4c */ void *mUnk_4c;
    /* 50 */ void *mUnk_50;
} Unk021b4c88;

#include "00/code_02180608.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_020472a8.h"

extern Unk021b0cd4 gWiFiAikotobaCheckCallbacks;
extern char data_ov000_021b0fc0[];
extern char data_ov000_021b0fcc[];
extern Unk021b4c88 *gWiFiAikotobaCheck;

void RegisterWiFiAikotobaCheckCallbacks(void);
void func_ov000_02185368(void);
void AdvanceWiFiAikotobaCheck(void);
void func_ov000_021853c4(void);
void func_ov000_02185418(void);
void func_ov000_021854a8(void);
void func_ov000_021854f8(void);
void func_ov000_0218554c(void);
void func_ov000_021855f8(void);
void InitWiFiAikotobaCheck(void *a);
void func_ov000_021856a8(void);
void func_ov000_02185788(void);

#pragma once

#include "types.h"

typedef struct Unk021b0cd4 {
    /* 00 */ void (*mUnk_00)(void *);
    /* 04 */ void (*mUnk_04)(void);
    /* 08 */ void (*mUnk_08)(void);
    /* 0c */ void (*mUnk_0c)(void);
} Unk021b0cd4;

typedef struct Unk021b4c64 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s16 mUnk_18;
    /* 1a */ u8 pad_1a[2];
    /* 1c */ Unk021b0cd4 mUnk_1c;
    /* 2c */ void *mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ u8 pad_38[4];
} Unk021b4c64;

#include "Main/Unknown/code_021258f0.h"

extern Unk021b4c64 *gWiFiStates;

BOOL func_ov000_02180608(void);
void func_ov000_02180638(s32 arg0);
s32 func_ov000_02180644(void);
void SetWiFiVSSettingIndex(unsigned int settingIndex);
unsigned int GetWiFiVSSettingIndex(void);
u32 LookupWiFiVSSettingMessageIndex(u32 settingIndex);
u32 func_ov000_021806a0(void);
void func_ov000_021806b8(unsigned int p0);
unsigned int func_ov000_021806c4(void);
s32 GetWiFiPrevState(void);
void RequestWiFiState(s32 nextState);
void SetWiFiStateCallbacks(const Unk021b0cd4 *callbacks);
void func_ov000_02180704(void);
void AdvanceWiFiStates(void);
void InitWiFiStates(void *heap, s32 b);
void func_ov000_02180a54(void);
void ClearWiFiStateCallbacks(void);

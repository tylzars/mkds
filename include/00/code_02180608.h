#pragma once

#include "types.h"

// Four callbacks of a WiFi state: mInit gets WiFiStates::mStateHeap, mAdvance runs every frame.
typedef struct WiFiStateCallbacks {
    /* 00 */ void (*mInit)(void *);
    /* 04 */ void (*mUnk_04)(void);
    /* 08 */ void (*mAdvance)(void);
    /* 0c */ void (*mUnk_0c)(void);
} WiFiStateCallbacks;

typedef struct WiFiStates {
    /* 00 */ void *mHeap;
    /* 04 */ void *mStateHeap;
    /* 08 */ u32 mState;
    /* 0c */ s32 mNextState;
    /* 10 */ u32 mPrevState;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s16 mUnk_18;
    /* 1a */ u8 pad_1a[2];
    /* 1c */ WiFiStateCallbacks mCallbacks;
    /* 2c */ void *mUnk_2c;
    /* 30 */ u32 mWiFiVSSettingIndex;
    /* 34 */ s32 mUnk_34;
    /* 38 */ u8 pad_38[4];
} WiFiStates;

extern WiFiStates *gWiFiStates;

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
void SetWiFiStateCallbacks(const WiFiStateCallbacks *callbacks);
void func_ov000_02180704(void);
void AdvanceWiFiStates(void);
void InitWiFiStates(void *heap, s32 b);
void func_ov000_02180a54(void);
void ClearWiFiStateCallbacks(void);

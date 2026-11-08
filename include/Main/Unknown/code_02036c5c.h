#pragma once

#include "types.h"

// Halfwords of Bg23Cnt after the mode.
typedef struct Bg23CntFields {
    /* 00 */ u16 mBgCntLow2;
    /* 02 */ u16 mBgCntBit6;
    /* 04 */ u16 mBgCntVal14;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mBgCntVal8;
    /* 0a */ u16 mBgCntVal2;
} Bg23CntFields;

// Argument of ApplyBg3Cnt and ApplyBg2Cnt.
typedef struct Bg23Cnt {
    /* 00 */ s32 mMode;
    /* 04 */ Bg23CntFields mFields;
} Bg23Cnt;

typedef struct DisplaySettings DisplaySettings;

// The 0xdc-byte object CreateDisplaySettings returns is an DisplaySettings (unk_02175000.h). Member 0x28 and member
// 0x70 of it are each followed by 0x44 bytes of the layout below.
typedef struct DisplayBgRecords {
    /* 00 */ u16 mBg0CntLow2;
    /* 02 */ u16 mBg0CntBit6;
    /* 04 */ u16 mBg0CntVal14;
    /* 06 */ u16 mBg0CntVal7;
    /* 08 */ u16 mBg0CntVal8;
    /* 0a */ u16 mBg0CntVal2;
    /* 0c */ u16 mBg0CntVal13;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mBg1CntLow2;
    /* 12 */ u16 mBg1CntBit6;
    /* 14 */ u16 mBg1CntVal14;
    /* 16 */ u16 mBg1CntVal7;
    /* 18 */ u16 mBg1CntVal8;
    /* 1a */ u16 mBg1CntVal2;
    /* 1c */ u16 mBg1CntVal13;
    /* 1e */ u16 mUnk_1e;
    /* 20 */ u32 mBg2Mode;
    /* 24 */ u16 mBg2CntLow2;
    /* 26 */ u16 mBg2CntBit6;
    /* 28 */ u16 mBg2CntVal14;
    /* 2a */ u16 mUnk_2a;
    /* 2c */ u16 mBg2CntVal8;
    /* 2e */ u16 mBg2CntVal2;
    /* 30 */ u32 mBg3Mode;
    /* 34 */ u16 mBg3CntLow2;
    /* 36 */ u16 mBg3CntBit6;
    /* 38 */ u16 mBg3CntVal14;
    /* 3a */ u16 mUnk_3a;
    /* 3c */ u16 mBg3CntVal8;
    /* 3e */ u16 mBg3CntVal2;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u16 mUnk_42;
} DisplayBgRecords;

// The 0x28 bytes InitDisplaySettings copies to the start of an DisplaySettings.
typedef struct DisplaySettingsDesc {
    /* 00 */ u16 mUnk_00[4];
    /* 08 */ u16 mMainBgMode;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mSubBgMode;
    /* 0e */ u16 mUnk_0e[13];
} DisplaySettingsDesc;

// Two of these sit at gSubBrightnessFade and gMainBrightnessFade; UpdateBrightnessFade steps one.
typedef struct BrightnessFade {
    /* 00 */ u16 mState;
    /* 02 */ u16 mPositive;
    /* 04 */ s16 mFadeFrames;
    /* 06 */ s16 mFadeFrameCount;
    /* 08 */ s16 mBrightness;
    /* 0a */ u16 mUnk_0a;
} BrightnessFade;

extern BrightnessFade gSubBrightnessFade;
extern BrightnessFade gMainBrightnessFade;

u32 AreBrightnessFadesClear(void);
void SetBrightnessFadesClear(void);
u32 AreBrightnessFadesFaded(void);
void StartFadeToFadedPositive(s16 frameCount);
void StartFadeToFadedPositiveOneScreen(s16 frameCount, s32 isMainScreen);
void StartFadeToFadedNegative(s16 frameCount);
void StartFadeToFadedNegativeOneScreen(s32 frameCount, s32 isMainScreen);
void StartFadeToClearNegative(s16 frameCount);
void StartFadeToClearNegativeOneScreen(s32 frameCount, s32 isMainScreen);
void StartFadeToClear(s16 frameCount);
void StartFadeToClearOneScreen(s16 frameCount, s32 isMainScreen);
void RecordFrameTimes(void);
void FinishDisplayFrameSwapIf(s32 doSwap);
void func_02037658(s32 a);
void FinishDisplayFrame(void);
u32 ClearFrameFinishedFlag(void);
u32 func_02037a20(void);
void PrepareDisplayFrame(void);
void DisableAllBanksAndNullDisplaySettings(void);
void InitDisplayFromSettings(void *settingsPtr);
void ApplyBg3Cnt(Bg23Cnt *cnt, s32 isMainScreen);
void ApplyBg2Cnt(Bg23Cnt *cnt, s32 isMainScreen);
void func_02038c94(DisplaySettings *settings, unsigned int value);
u32 SetG3xSwapBits(DisplaySettings *settings, u32 swapBit0, u32 swapBit1);
void SetBg2RecordMode5(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8);
void SetBg3RecordParams(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8, u32 cntVal2);
void SetBg2RecordParams(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8, u32 cntVal2);
void SetBg1Record(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8, u32 cntVal2,
                  u32 cntVal13);
void SetBg0Record(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8, u32 cntVal2,
                  u32 cntVal13);
void *CreateDisplaySettings(void *heap, void *descriptor);
void InitDisplaySettings(DisplaySettings *settings, void *descriptorBase);
void InitDisplayBgRecords(void *recordsBase, u32 bgMode);
void WaitIrqAndTurnOnDisplays(void);
void InitBrightnessFades(void);
void UpdateBrightnessFade(BrightnessFade *fade);

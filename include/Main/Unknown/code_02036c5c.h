#pragma once

#include "types.h"

// Halfwords of Bg23Cnt after the mode.
typedef struct Bg23CntFields {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
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
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u16 mUnk_1c;
    /* 1e */ u16 mUnk_1e;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u16 mUnk_24;
    /* 26 */ u16 mUnk_26;
    /* 28 */ u16 mUnk_28;
    /* 2a */ u16 mUnk_2a;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u16 mUnk_34;
    /* 36 */ u16 mUnk_36;
    /* 38 */ u16 mUnk_38;
    /* 3a */ u16 mUnk_3a;
    /* 3c */ u16 mUnk_3c;
    /* 3e */ u16 mUnk_3e;
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
void StartFadeToFadedPositive(s16 a);
void StartFadeToFadedPositiveOneScreen(s16 a, s32 b);
void StartFadeToFadedNegative(s16 a);
void StartFadeToFadedNegativeOneScreen(s32 a, s32 b);
void StartFadeToClearNegative(s16 a);
void StartFadeToClearNegativeOneScreen(s32 a, s32 b);
void StartFadeToClear(s16 a);
void StartFadeToClearOneScreen(s16 a, s32 b);
void RecordFrameTimes(void);
void FinishDisplayFrameSwapIf(s32 a);
void func_02037658(s32 a);
void FinishDisplayFrame(void);
u32 ClearFrameFinishedFlag(void);
u32 func_02037a20(void);
void PrepareDisplayFrame(void);
void DisableAllBanksAndNullDisplaySettings(void);
void InitDisplayFromSettings(void *a);
void ApplyBg3Cnt(Bg23Cnt *a, s32 b);
void ApplyBg2Cnt(Bg23Cnt *a, s32 b);
void func_02038c94(DisplaySettings *p0, unsigned int p1);
u32 SetG3xSwapBits(DisplaySettings *arg0, u32 arg1, u32 arg2);
void SetBg2RecordMode5(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
void SetBg3RecordParams(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void SetBg2RecordParams(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void SetBg1Record(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void SetBg0Record(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void *CreateDisplaySettings(void *a, void *b);
void InitDisplaySettings(DisplaySettings *a, void *b);
void InitDisplayBgRecords(void *a, u32 b);
void WaitIrqAndTurnOnDisplays(void);
void InitBrightnessFades(void);
void UpdateBrightnessFade(BrightnessFade *a);

#pragma once

#include "types.h"

// Compared with three values by func_02121990.
typedef struct Unk02121990 {
    /* 0 */ s32 mKind;
    /* 4 */ s32 mSize;
    /* 8 */ u8 mFromIndex;
    /* 9 */ u8 mToIndex;
} Unk02121990;

void func_02121dec(u32 a);
s32 func_02121d94(void);
BOOL func_02121d48(void);
s32 func_02121d0c(void);
s32 func_02121cd0(void);
s32 func_02121c78(void);
void TallyPickedCourse(void);
void func_021219cc(void);
BOOL func_02121990(Unk02121990 *a, u32 b, u32 c, u32 d);
BOOL IsWiFiSessionMessageKindAllowed(u32 a);
u8 func_021216a8(void);
BOOL func_02121580(void);
void func_0212145c(u32 a);
BOOL func_02121434(void);
u8 func_02121418(void);
BOOL func_021213f4(void);
u32 func_021213e8(void);
BOOL func_021213a0(void);
BOOL func_0212137c(void);
void func_02121190(u32 kartType, s32 b, s32 c);
s32 func_0212111c(void);
void RegisterKartKeysAndStart(void);
BOOL func_02120d14(void);
s32 ComputeEloEval(u32 a);
BOOL ComputeRegionEval(u32 a);
s32 ComputeRegionEloEval(u32 a);
void KartKeysStartCallback(u32 a, s32 b);
void func_021208e8(s32 a);
void ResetWiFiSession(void);
u32 func_02120644(void);
void func_02120610(void);

#pragma once

#include "types.h"

typedef struct WiFiSessionMessageHeader WiFiSessionMessageHeader;

void func_02121dec(u32 a);
s32 GetWiFiSessionCourseId(void);
BOOL func_02121d48(void);
s32 func_02121d0c(void);
s32 func_02121cd0(void);
s32 func_02121c78(void);
void TallyPickedCourse(void);
void func_021219cc(void);
BOOL DoesMessageHeaderMatch(WiFiSessionMessageHeader *header, u32 size, u32 fromIndex, u32 toIndex);
BOOL IsWiFiSessionMessageKindAllowed(u32 kind);
u8 func_021216a8(void);
BOOL func_02121580(void);
void EndWiFiSessionOnPicksMismatch(u32 index);
BOOL func_02121434(void);
u8 func_02121418(void);
BOOL func_021213f4(void);
u32 func_021213e8(void);
BOOL func_021213a0(void);
BOOL IsKartKeysStartStatus2(void);
void func_02121190(u32 kartType, s32 b, s32 c);
s32 func_0212111c(void);
void RegisterKartKeysAndStart(void);
BOOL IsKartKeysStartStatus3(void);
s32 ComputeEloEval(u32 a);
BOOL ComputeRegionEval(u32 a);
s32 ComputeRegionEloEval(u32 a);
void KartKeysStartCallback(u32 a, s32 b);
void func_021208e8(s32 a);
void ResetWiFiSession(void);
u32 func_02120644(void);
void func_02120610(void);

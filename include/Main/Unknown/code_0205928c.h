#pragma once

#include "types.h"

void UpdateMPState20(void);
void EnterMPState20(void);
void UpdateMPState17(void);
void func_02059304(void);
void func_0205933c(void);
void UpdateMPState16(void);
void EnterMPState16(void);
u32 func_020593dc(void);
void RequestMPState21(void);
void RequestMPState18(void);
void RequestMPState16(void *a, void *b);
u32 func_0205955c(void);
s32 func_020595e8(s32 a, void *b, void *c);
s32 func_02059700(void);
s32 IsAllMPChildSharedDataCopied(void);
void func_020597d0(const void *a, s32 b, s32 c, s32 d);
void InitMPChunkBuffers(void *a);

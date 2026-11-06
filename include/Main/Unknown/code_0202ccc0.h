#pragma once

#include "types.h"

// Argument of AdvanceTimeAttackGhostSend: a halfword is set at 4.
typedef struct Unk0202cdf4 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk0202cdf4;

void func_0202ccc0(void);
void ReleaseTimeAttackGhostSend(void);
s32 AdvanceTimeAttackGhostSend(Unk0202cdf4 *p);
void InitTimeAttackGhostSend(void *a, void *b, void *c);
void func_0202d554(void);
void func_0202d5c0(void);
void func_0202d5f8(s32 a, s32 b);
void func_0202d674(void);
void func_0202d6a0(void);
void func_0202d720(void);
void func_0202d82c(void);
void func_0202d868(s32 a, s32 b, s32 c, s32 d);

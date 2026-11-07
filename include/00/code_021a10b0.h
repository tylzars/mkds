#pragma once

#include "types.h"

void SetupMatching(u8 a, u8 b, UnkFunc *c, u32 d);
void ResetMatching(s32 level);
u32 IsMatchingPointerNull(void);
u32 func_ov000_021a1488(void);
u32 GetMatchingMaskedParticipantIndices(void **a);
u32 GetMatchingParticipantIndices(void **output);
void RefreshMatchingLastMaskedParticipantPos(void);
u8 GetMatchingLastMaskedParticipantPos(void);
u8 GetMatchingLastParticipantPos(void);
u32 RemoveMatchingParticipant(s32 position, s32 count);
u32 RemoveMatchingParticipantByProfileId(int profileId, int count);
void func_ov000_021a1798(u32 value);

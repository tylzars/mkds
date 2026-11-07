#pragma once

#include "types.h"

// Declared here until the code that defines them is decompiled.
extern char gNumPlayersKey[];
extern char gMaxPlayersKey[];

u32 func_ov000_0219e4e8(u32 a);
u32 ReportMatchingServerListResult(u32 result);
u32 ReportMatchingGpResult(u32 result);
void func_ov000_0219e668(void);
void func_ov000_0219e8b8(s32 a);
u32 GetMatchingParticipantMaskExceptFirst(s32 a);
s32 GetMatchingParticipantIndexByProfileId(u32 profileId, s32 b);
s32 GetSbServerProfileIdIfComplete(u32 server);
u8 FindFreeMatchingParticipantIndex(void);
void ReleaseMatchingKeys(void);

#pragma once

#include "types.h"

// The first 0x14 bytes of each record ParseMatchingRecords walks; MatchingSendHeader is the same layout on the send
// side.
typedef struct MatchingReceiveHeader {
    /* 00 */ char mSignature[4];
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mCommand;
    /* 09 */ u8 mValuesSize;
    /* 0a */ u16 mPort;
    /* 0c */ u32 mAddress;
    /* 10 */ u32 mProfileId;
} MatchingReceiveHeader;

void ParseMatchingRecords(const void *a, u32 b);
void func_ov000_0219ddbc(u32 a);
u32 func_ov000_0219edb0(u32 a, u32 b);
void ReleaseMatching(void);
void ReportMatchingError(s32 a, s32 b);

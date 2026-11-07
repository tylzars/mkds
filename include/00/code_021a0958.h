#pragma once

#include "types.h"
#include "00/code_0218f960.h"

typedef struct WiFiMatching WiFiMatching;

// The five characters at gMatchingSignature, copied into the first member of MatchingSendHeader.
typedef struct MatchingSignatureText {
    /* 0 */ char mText[5];
} MatchingSignatureText;

// The 0x14-byte header SendMatchingCommandToAddress sends in front of the values.
typedef struct MatchingSendHeader {
    /* 00 */ char mSignature[4];
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mCommand;
    /* 09 */ u8 mValuesSize;
    /* 0a */ u16 mPort;
    /* 0c */ void *mAddress;
    /* 10 */ u32 mProfileId;
} MatchingSendHeader;

// The twelve bytes at WiFiMatching.mUnk_18c.
typedef struct Unk021a0c30 {
    /* 00 */ u8 mUnk_00;
    /* 02 */ u16 mPort;
    /* 04 */ u32 mAddress;
    /* 08 */ u32 mUnk_08;
} Unk021a0c30;

s32 CopyNthSlashField(char *out, const char *text, s32 index);
s32 SendMatchingCommandToProfile(struct GpConnection *gpConnection, u32 command, u32 profileId, const char *text);
u32 SendMatchingCommandToAddress(u32 command, u32 address, u32 port, u32 *values, u32 valueCount);
u32 SendMatchingCommand(u32 command, u32 profileId, u32 address, u32 port, void *values, s32 valueCount);
u32 func_ov000_021a0c30(Unk021a0c30 *a);
u32 func_ov000_021a0cac(s32 a, s32 b, u32 c);
s32 BuildMatchingFilter(char *buffer, s32 profileId, s32 c, s32 mode);
u32 StartMatchingServerList(u32 a);
void StopMatching(void);

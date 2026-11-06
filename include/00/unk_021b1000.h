#pragma once

#include "types.h"

typedef struct Unk021b4cb4 {
    /* 00 */ char *mUnk_00;
    /* 04 */ BOOL mUnk_04;
    /* 08 */ char *mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ void *(*mUnk_10)();
    /* 14 */ void (*mUnk_14)();
    /* 18 */ BOOL mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk021b4cb4;

// Objects whose layout isn't known yet.
extern char *data_ov000_021b1004[];
extern Unk021b4cb4 data_ov000_021b1040;
extern u8 gHttpBufferName[];
extern u8 gHttpLowReceiveBufferName[];
extern u8 gHttpLowSendBufferName[];

// Strings.
extern char data_ov000_021b1020[];
extern char data_ov000_021b1060[];
extern char data_ov000_021b1068[];
extern char data_ov000_021b1074[];
extern char gActionPairName[];
extern char gAcctcreatePairValue[];
extern char gLoginPairValue[];
extern char gGsbrcdPairName[];
extern char gIngamesnPairName[];
extern char gSdkverPairName[];
extern char gSdkverPairValue[];
extern char data_ov000_021b10d0[];
extern char gUseridPairName[];
extern char data_ov000_021b10e0[];
extern char gPasswdPairName[];
extern char data_ov000_021b10f0[];
extern char data_ov000_021b110c[];
extern char gGamecdPairName[];
extern char gMakercdPairName[];
extern char gUnitcdPairName[];
extern char gUnitcdPairValue[];
extern char gMacadrPairName[];
extern char gLangPairName[];
extern char gBirthPairName[];
extern char gDevtimePairName[];
extern char gBssidPairName[];
extern char gApinfoPairName[];
extern char gUserAgentHeaderName[];
extern char gUserAgentHeaderValue[];
extern char gHttpXGamecdHeaderName[];
extern char gDevnamePairName[];
extern char gHttpresultPairName2[];
extern char gReturncdPairName[];
extern char gTokenPairName[];
extern char gLocatorPairName[];
extern char gChallengePairName[];
extern char gDatetimePairName[];
extern char gSetCookieHeaderName[];
extern char gBmworkName[];
extern char gAuthFreeName[];
extern char gAuthAllocName[];
extern char data_ov000_021b1230[];
extern char data_ov000_021b1238[];
extern char gHttpresultPairName[];
extern char data_ov000_021b1248[];
extern char gHttpbodyPairName[];
extern char data_ov000_021b1258[];
extern char data_ov000_021b125c[];
extern char data_ov000_021b1260[];
extern char data_ov000_021b1264[];
extern char data_ov000_021b1268[];
extern char data_ov000_021b1270[];
extern char data_ov000_021b127c[];
extern char data_ov000_021b1290[];
extern char data_ov000_021b1294[];
extern char data_ov000_021b1298[];
extern char data_ov000_021b12a0[];
extern char data_ov000_021b12ac[];
extern char data_ov000_021b1300[];
extern char gNetcheckBody302Name[];
extern char gNetcheckBodyWayportName[];

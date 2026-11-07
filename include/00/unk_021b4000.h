#pragma once

#include "00/code_02180608.h"
#include "00/code_021acef8.h"
#include "00/code_021ad734.h"
#include "00/code_02186d04.h"
#include "00/code_02187484.h"
#include "00/code_02188008.h"
#include "00/code_021884d8.h"
#include "00/code_0218e2dc.h"
#include "00/code_021a3a18.h"

#include "types.h"
#include "00/code_021a6fa8.h"

// Settings func_ov000_021a72c4 reads and func_ov000_021a71c0 applies.
typedef struct Unk021b49b8 {
    /* 00 */ s8 mUnk_00;
    /* 01 */ s8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ Unk021a72a4 mUnk_10;
    /* 14 */ Unk021a72a4 mUnk_14;
} Unk021b49b8;

// Objects whose layout isn't known yet.
extern u32 data_ov000_021b49b4;
extern Unk021b49b8 data_ov000_021b49b8;
extern Unk021b49b8 data_ov000_021b49d0;
extern char data_ov000_021b4078[];
extern char data_ov000_021b40b0[];
extern char data_ov000_021b40b4[];
extern char gMatchingSignature[];
extern char gUnsignedFormat[];
extern char gDwcPidKey[];
extern char gDwcEvalKey[];
extern char gDwcMtypeKey[];
extern char gDwcMresvKey[];
extern char gDwcMverKey[];
extern char gVerKey[];
extern u8 gScmKey[];
extern u8 gScnKey[];
extern char data_ov000_021b41f0[];
extern u8 data_ov000_021b4200[];
extern u8 data_ov000_021b4228[];
extern u8 data_ov000_021b424c[];
extern u32 data_ov000_021b49f4;
extern char data_ov000_021b4388[];
extern char data_ov000_021b4394[];
extern char data_ov000_021b43a0[];
extern char data_ov000_021b43a8[];
extern char data_ov000_021b43ac[];
extern char data_ov000_021b43b0[];
extern char data_ov000_021b43c0[];
extern char data_ov000_021b43cc[];
extern char data_ov000_021b43d8[];
extern char data_ov000_021b41f4[];
extern Unk021a3eb0 data_ov000_021b4270;
extern Unk021a4a08 *data_ov000_021b426c;
extern char data_ov000_021b43f8[];
extern char data_ov000_021b4400[];
extern char data_ov000_021b4404[];
extern char data_ov000_021b440c[];
extern char data_ov000_021b4418[];
extern char data_ov000_021b4428[];
extern u8 data_ov000_021b442c[];
extern char data_ov000_021b4464[];
extern char data_ov000_021b43e4[];
extern u8 gSrvrText[];
extern u8 gClntText[];
extern u16 gOfferedValues[2];
extern const char *data_ov000_021b4a30[];
extern u8 gLabelAText[];
extern u8 gLabelBBText[];
extern u8 gLabelCCCText[];
extern u8 data_ov000_021b4be4[];
extern u8 data_ov000_021b4be5[];
extern u8 gWiFiVSCourseSelectState[];
extern Http *gHttp;
extern DWCNetcheck *gNetcheck;
extern Unk02188408 *data_ov000_021b4d00;
extern void *data_ov000_021b4d04;
extern void *data_ov000_021b4d08;
extern Unk02188114 *data_ov000_021b4d0c;
extern Unk021884e4 *data_ov000_021b4d10;
extern struct Hashtable *data_ov000_021b4d18;
extern struct SbServer *data_ov000_021b4d1c;
// Objects behind gWiFiSelectCharacterState and gWiFiSelectKartState.
typedef struct Unk021b4c78 {
    /* 0 */ void *mHeap;
} Unk021b4c78;

extern Unk021b4c78 *gWiFiSelectCharacterState;
extern Unk021b4c78 *gWiFiSelectKartState;

// Object behind data_ov000_021b4d24; the 0x5d8 bytes at offset 0x4c of a Unk0218b668.
typedef struct SbServerList {
    /* 000 */ s32 mState;
    /* 004 */ struct Darray *mUnk_004;
    /* 008 */ struct Darray *mUnk_008;
    /* 00c */ char mUnk_00c[0x24];
    /* 030 */ char mUnk_030[0x24];
    /* 054 */ char mUnk_054[0x20];
    /* 074 */ s8 mUnk_074[8];
    /* 07c */ u8 *mInBuffer;
    /* 080 */ s32 mInBufferLength;
    /* 084 */ char *mUnk_084[0xff];
    /* 480 */ s32 mUnk_480;
    /* 484 */ s32 mUnk_484;
    /* 488 */ UnkFunc *mCallback;
    /* 48c */ UnkFunc *mUnk_48c;
    /* 490 */ UnkFunc *mUnk_490;
    /* 494 */ void *mUnk_494;
    /* 498 */ const char *mUnk_498;
    /* 49c */ s32 mUnk_49c;
    /* 4a0 */ s32 mUnk_4a0;
    /* 4a4 */ u32 mUnk_4a4;
    /* 4a8 */ u16 mUnk_4a8;
    /* 4aa */ u8 mUnk_4aa[2];
    /* 4ac */ char *mUnk_4ac;
    /* 4b0 */ s32 mUnk_4b0;
    /* 4b4 */ u32 mUnk_4b4;
    /* 4b8 */ u32 mUnk_4b8;
    /* 4bc */ u8 mUnk_4bc[0x108];
    /* 5c4 */ u32 mUnk_5c4;
    /* 5c8 */ s32 mUnk_5c8;
    /* 5cc */ s32 mUnk_5cc;
    /* 5d0 */ int mUnk_5d0;
} SbServerList;

extern SbServerList *data_ov000_021b4d24;
extern s32 data_ov000_021b4d28;
extern const char *data_ov000_021b4d20;
extern char data_ov000_021b4d2c[];

// Object behind data_ov000_021b4dac.
typedef struct Unk021b4dac {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[2];
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d[0x3f];
    /* 4c */ s32 mUnk_4c;
    /* 50 */ u32 mUnk_50;
    /* 54 */ s32 mUnk_54;
} Unk021b4dac;

extern Unk021b4dac data_ov000_021b4dac;
extern u8 data_ov000_021b4db0[];
extern u8 data_ov000_021b4db4[];
extern u8 data_ov000_021b4db8[];
extern u8 data_ov000_021b4dbd[];
extern char data_ov000_021b4d6c[];
extern u8 data_ov000_021b4e50[];
extern u8 data_ov000_021b400c[];
extern u8 gEmptyString[];
extern char gFmeKey[];
extern char gMdfKey[];
extern u8 gInitStateString[];
extern u8 gServerFullString[];
extern u8 gUnexpectedConnectAttemptString[];
extern u8 gYString[];
extern u8 gNString[];
extern char gAndEmptyParensString[];
extern char data_ov000_021b3fcc[];
extern char data_ov000_021b3fec[];
extern char data_ov000_021b3ffc[];
extern char data_ov000_021b4004[];
extern char data_ov000_021b4008[];
extern char data_ov000_021b4014[];
extern char data_ov000_021b4030[];
extern char data_ov000_021b404c[];
extern char data_ov000_021b4054[];
extern char data_ov000_021b4058[];
extern char data_ov000_021b4060[];
extern u8 data_ov000_021b4064[];
extern char data_ov000_021b4068[];

extern char gGpMessagePrefixFormat[];
extern char gGpcmPrefix[];
extern char gMatTag[];
extern char gSlashUnsignedFormat[];
extern char gMatchingFilterFormat[];
extern char gAndParenFormat[];
extern char gKeyEqualsUnsignedFormat[];

#include "00/code_021a3760.h"

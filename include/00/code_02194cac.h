#pragma once

#include "types.h"
#include "00/code_0218f960.h"
#include "00/code_0218e368.h"
#include "00/code_02196000.h"
#include "00/code_02196590.h"
#include "00/code_021a3678.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "code_02134d30.h"
#include "00/code_0218e3c4.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218dc44.h"
#include "00/code_021965a0.h"
#include "00/code_02190ba0.h"
#include "code_02135014.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_021947e4.h"
#include "00/code_02196914.h"
#include "00/code_021a3690.h"
#include "code_0213a460.h"
#include "00/code_021919ac.h"
#include "00/code_02193818.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_021967b4.h"
#include "00/code_02191200.h"
#include "00/code_021965c8.h"

// Object at 0x04 of Unk02194cac.
typedef struct Unk02194cac_04 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ u32 mUnk_004;
    /* 008 */ u8 *mUnk_008;
    /* 00c */ u8 mUnk_00c[0xc];
    /* 018 */ u8 mUnk_018[0x10];
    /* 028 */ s8 mUnk_028[0x1f];
    /* 047 */ s8 mUnk_047[0x15];
    /* 05c */ s8 mUnk_05c[0x33];
    /* 08f */ s8 mUnk_08f[0x1f];
    /* 0ae */ s8 mUnk_0ae[0x1f];
    /* 0cd */ s8 mUnk_0cd[0x1f];
    /* 0ec */ s8 mUnk_0ec[0x44];
    /* 130 */ s32 mUnk_130;
    /* 134 */ s32 mUnk_134;
    /* 138 */ s32 mUnk_138;
    /* 13c */ u8 mUnk_13c[4];
    /* 140 */ s32 mUnk_140;
} Unk02194cac_04;

// Object func_ov000_02194cac takes as its second argument.
typedef struct Unk02194cac {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Unk02194cac_04 *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ Unk02190ed4Cb mUnk_0c;
    /* 14 */ s32 mUnk_14;
} Unk02194cac;

// 0xac-byte array element func_ov000_02194cac fills.
typedef struct Unk02194cac_ac {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s8 mUnk_04[0x1f];
    /* 23 */ s8 mUnk_23[0x15];
    /* 38 */ s8 mUnk_38[0x1f];
    /* 57 */ s8 mUnk_57[0x1f];
    /* 76 */ s8 mUnk_76[0x36];
} Unk02194cac_ac;

// 0x128-byte array element func_ov000_02194cac fills.
typedef struct Unk02194cac_128 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s8 mUnk_004[0x20];
    /* 024 */ s32 mUnk_024;
    /* 028 */ s8 mUnk_028[0x100];
} Unk02194cac_128;

// 0x10-byte local of func_ov000_02194cac passed to Unk02190ed4Cb.mUnk_00.
typedef struct Unk02194cac_10 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ Unk02194cac_ac *mUnk_0c;
} Unk02194cac_10;

// Objects func_ov000_02194cac allocates and passes to func_ov000_02190ed4.
typedef struct Unk02194cac_08 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk02194cac_08;

typedef struct Unk02194cac_0c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ Unk02194cac_ac *mUnk_08;
} Unk02194cac_0c;

typedef struct Unk02194cac_0c2 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 **mUnk_08;
} Unk02194cac_0c2;

typedef struct Unk02194cac_102 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ Unk02194cac_128 *mUnk_0c;
} Unk02194cac_102;

typedef struct Unk02194cac_3c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s8 mUnk_04[0x34];
    /* 38 */ s32 mUnk_38;
} Unk02194cac_3c;

typedef struct Unk02194cac_44 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ char mUnk_04[0x34];
    /* 38 */ s32 mUnk_38;
    /* 3c */ u8 **mUnk_3c;
    /* 40 */ u8 **mUnk_40;
} Unk02194cac_44;

extern u8 data_ov000_021b35f8[];
extern u8 data_ov000_021b3628[];
extern s8 data_ov000_021b3634[];
extern u8 data_ov000_021b3638[];
extern u8 data_ov000_021b3664[];
extern u8 data_ov000_021b3670[];
extern u8 data_ov000_021b367c[];
extern u8 data_ov000_021b3688[];
extern u8 data_ov000_021b3698[];
extern u8 data_ov000_021b36a0[];
extern u8 data_ov000_021b36b0[];
extern u8 data_ov000_021b36b8[];
extern u8 data_ov000_021b36c4[];
extern u8 data_ov000_021b36d0[];
extern u8 data_ov000_021b36dc[];
extern u8 data_ov000_021b36e4[];
extern u8 data_ov000_021b36ec[];
extern u8 data_ov000_021b36f4[];
extern u8 data_ov000_021b36fc[];
extern u8 data_ov000_021b3708[];
extern u8 data_ov000_021b3714[];
extern u8 data_ov000_021b371c[];
extern u8 data_ov000_021b3728[];
extern u8 data_ov000_021b3734[];
extern u8 data_ov000_021b373c[];
extern u8 data_ov000_021b3748[];
extern u8 data_ov000_021b3758[];
extern u8 data_ov000_021b3768[];
extern u8 data_ov000_021b376c[];
extern u8 data_ov000_021b3778[];
extern u8 data_ov000_021b3780[];
extern u8 data_ov000_021b37ac[];
extern u8 data_ov000_021b37b4[];
extern u8 data_ov000_021b37bc[];
extern u8 data_ov000_021b37c0[];
extern u8 data_ov000_021b37c8[];
extern u8 data_ov000_021b37d4[];
extern u8 data_ov000_021b37e0[];
extern u8 data_ov000_021b37ec[];
extern u8 data_ov000_021b37f4[];
extern u8 data_ov000_021b381c[];
extern u8 data_ov000_021b3820[];
extern u8 data_ov000_021b3824[];
extern u8 data_ov000_021b382c[];
extern u8 data_ov000_021b3834[];
extern u8 data_ov000_021b3838[];
extern u8 data_ov000_021b3840[];
extern u8 data_ov000_021b384c[];
extern u8 data_ov000_021b3850[];
extern u8 data_ov000_021b3858[];
extern u8 data_ov000_021b385c[];
extern u8 data_ov000_021b3864[];
extern u8 data_ov000_021b386c[];
extern u8 data_ov000_021b3870[];
extern u8 data_ov000_021b3878[];
extern u8 data_ov000_021b3880[];
extern u8 data_ov000_021b3884[];
extern u8 data_ov000_021b388c[];
extern u8 data_ov000_021b4d6c[];

s32 func_ov000_02194cac(GpConnection *a, Unk02194cac *b);

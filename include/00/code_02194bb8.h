#pragma once

#include "types.h"
#include "00/code_0218f960.h"

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
    /* 140 */ BOOL mUnk_140;
} Unk02194cac_04;

// Object GpiUpdateSearch takes as its second argument.
typedef struct Unk02194cac {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Unk02194cac_04 *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ GpiCallback mUnk_0c;
    /* 14 */ s32 mUnk_14;
} Unk02194cac;

// 0xac-byte array element GpiUpdateSearch fills.
typedef struct Unk02194cac_ac {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s8 mUnk_04[0x1f];
    /* 23 */ s8 mUnk_23[0x15];
    /* 38 */ s8 mUnk_38[0x1f];
    /* 57 */ s8 mUnk_57[0x1f];
    /* 76 */ s8 mUnk_76[0x36];
} Unk02194cac_ac;

// 0x128-byte array element GpiUpdateSearch fills.
typedef struct Unk02194cac_128 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s8 mUnk_004[0x20];
    /* 024 */ s32 mUnk_024;
    /* 028 */ s8 mUnk_028[0x100];
} Unk02194cac_128;

// 0x10-byte local of GpiUpdateSearch passed to GpiCallback.mUnk_00.
typedef struct Unk02194cac_10 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ Unk02194cac_ac *mUnk_0c;
} Unk02194cac_10;

// Objects GpiUpdateSearch allocates and passes to GpiQueueCallback.
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
    /* 08 */ char **mUnk_08;
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
    /* 38 */ BOOL mUnk_38;
} Unk02194cac_3c;

typedef struct Unk02194cac_44 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ char mUnk_04[0x34];
    /* 38 */ s32 mUnk_38;
    /* 3c */ char **mUnk_3c;
    /* 40 */ char **mUnk_40;
} Unk02194cac_44;

extern char data_ov000_021b35b8[];
extern u8 data_ov000_021b35f8[];
extern char data_ov000_021b3608[];
extern char data_ov000_021b3628[];
extern s8 data_ov000_021b3634[];
extern char data_ov000_021b3638[];
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
extern char data_ov000_021b3768[];
extern u8 data_ov000_021b376c[];
extern char data_ov000_021b3778[];
extern char data_ov000_021b3780[];
extern char data_ov000_021b37ac[];
extern char data_ov000_021b37b4[];
extern char data_ov000_021b37bc[];
extern char data_ov000_021b37c0[];
extern char data_ov000_021b37c8[];
extern char data_ov000_021b37d4[];
extern char data_ov000_021b37e0[];
extern char data_ov000_021b37ec[];
extern char data_ov000_021b37f4[];
extern char data_ov000_021b381c[];
extern char data_ov000_021b3820[];
extern char data_ov000_021b3824[];
extern char data_ov000_021b382c[];
extern char data_ov000_021b3834[];
extern char data_ov000_021b3838[];
extern char data_ov000_021b3840[];
extern char data_ov000_021b384c[];
extern char data_ov000_021b3850[];
extern char data_ov000_021b3858[];
extern char data_ov000_021b385c[];
extern char data_ov000_021b3864[];
extern char data_ov000_021b386c[];
extern char data_ov000_021b3870[];
extern char data_ov000_021b3878[];
extern char data_ov000_021b3880[];
extern char data_ov000_021b3884[];
extern char data_ov000_021b388c[];
extern char data_ov000_021b38c0[];
extern char data_ov000_021b38e8[];
extern char data_ov000_021b391c[];
extern char data_ov000_021b394c[];
extern char data_ov000_021b396c[];
extern char data_ov000_021b3994[];
extern char data_ov000_021b399c[];
extern char data_ov000_021b4d6c[];

BOOL GpiUpdateSearches(GpConnection *a);
s32 GpiUpdateSearch(GpConnection *a, Unk02194cac *b);
int func_ov000_021960a4(GpConnection *a, s8 *b, s8 *c, s8 *d, s8 *e, s8 *f, int g, int h, u32 l, u32 m, u32 n);
int func_ov000_021961e8(GpConnection *a, u32 b, u32 c, u32 d, u32 e);
BOOL GpiCreateSearch(GpConnection *a, Unk02196240 **b, u32 c);
s32 GpiOpenSearchSocket(GpConnection *a, GpiOperation *b);
void func_ov000_02196434(GpConnection *a, GpiPeer *b, s32 c, const char *d, s32 e, s32 f);

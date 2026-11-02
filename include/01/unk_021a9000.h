#pragma once

#include "types.h"
#include "01/code_02188e88.h"
#include "01/code_0219b250.h"
#include "01/code_0219853c.h"
#include "01/code_02198854.h"
#include "01/code_0219a050.h"
#include "01/code_0219b540.h"
#include "01/code_02193c5c.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/types_02180728.h" // Unk02180728

// Four callbacks; the first receives Unk021a9bd0::mUnk_04.
typedef struct Unk021a9bd0_18 {
    /* 00 */ void (*mUnk_00)(void *);
    /* 04 */ UnkFunc *mUnk_04;
    /* 08 */ UnkFunc *mUnk_08;
    /* 0c */ UnkFunc *mUnk_0c;
} Unk021a9bd0_18;

extern const Unk021a9bd0_18 data_ov001_021a8170;

// Object behind data_ov001_021a9bec.
typedef struct Unk021a9bec {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ Unk02124b1c *mUnk_1c;
    /* 20 */ struct Unk02021dc8 *mUnk_20;
    /* 24 */ Unk020b4934 *mUnk_24;
    /* 28 */ Unk020b4a44 *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ void *mUnk_30;
} Unk021a9bec;

// Allocated by func_ov001_02192fb8 and held in data_ov001_021a9bd0.
typedef struct Unk021a9bd0 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s16 mUnk_14;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ Unk021a9bd0_18 mUnk_18;
    /* 28 */ void *mUnk_28;
} Unk021a9bd0;

// Object behind data_ov001_021a9b90.
typedef struct Unk021a9b90 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ UnkFunc *mUnk_18;
    /* 1c */ UnkFunc *mUnk_1c;
    /* 20 */ UnkFunc *mUnk_20;
    /* 24 */ UnkFunc *mUnk_24;
    /* 28 */ Vec3 mUnk_28;
    /* 34 */ Vec3 mUnk_34;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u16 mUnk_42;
    /* 44 */ s32 mUnk_44;
    /* 48 */ struct Unk02188950 *mUnk_48[8];
} Unk021a9b90;

// Object behind data_ov001_021a9b88: a square grid of mUnk_00 by mUnk_00 cells.
typedef struct Unk021a9b88 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u16 *mUnk_18;
    /* 1c */ u8 *mUnk_1c;
    /* 20 */ u8 *mUnk_20;
    /* 24 */ u8 *mUnk_24;
    /* 28 */ u8 *mUnk_28;
    /* 2c */ u8 *mUnk_2c;
} Unk021a9b88;

// Allocated by InitSelectBattleStage and held in gSelectBattleStage.
typedef struct Unk021a9bf8 {
    /* 0000 */ s32 mUnk_00;
    /* 0004 */ s32 mUnk_04;
    /* 0008 */ s32 mUnk_08;
    /* 000c */ s32 mUnk_0c;
    /* 0010 */ s32 mUnk_10;
    /* 0014 */ s32 mUnk_14;
    /* 0018 */ s32 mUnk_18;
    /* 001c */ s32 mUnk_1c;
    /* 0020 */ s32 mUnk_20;
    /* 0024 */ s32 mUnk_24;
    /* 0028 */ s32 mUnk_28;
    /* 002c */ s32 mUnk_2c;
    /* 0030 */ u16 mUnk_30[64][32];
    /* 1030 */ void *mUnk_1030;
    /* 1034 */ Unk02124b1c *mUnk_1034[2];
    /* 103c */ struct Unk02021dc8 *mUnk_103c;
    /* 1040 */ struct Unk02021dc8 *mUnk_1040;
    /* 1044 */ Unk020b4934 *mUnk_1044;
    /* 1048 */ Unk020b4934 *mUnk_1048;
    /* 104c */ u8 pad_104c[8];
    /* 1054 */ Unk0201ea30 *mUnk_1054[2];
    /* 105c */ void *mUnk_105c[2];
    /* 1064 */ void *mUnk_1064[2];
    /* 106c */ Unk020b47d8 *mUnk_106c[3];
    /* 1078 */ void *mUnk_1078;
    /* 107c */ void *mUnk_107c;
    /* 1080 */ void *mUnk_1080;
    /* 1084 */ void *mUnk_1084;
} Unk021a9bf8;

// Object that func_ov001_02180610 allocates and data_ov001_021a99e4 points to.
typedef struct Unk021a99e4 {
    /* 0000 */ s32 mUnk_0000;
    /* 0004 */ s32 mUnk_0004;
    /* 0008 */ s32 mUnk_0008;
    /* 000c */ void *mUnk_000c[3];
    /* 0018 */ u8 mUnk_0018[3][0x20];
    /* 0078 */ Unk02180728 mUnk_0078[3];
    /* 00a8 */ u16 mUnk_00a8[0x3000];
    /* 60a8 */ u16 mUnk_60a8[0x300];
} Unk021a99e4;

// Objects whose layout isn't known yet.
extern const char *data_ov001_021a9278;
extern const char *data_ov001_021a927c;
extern const char *data_ov001_021a9280;
extern const char *data_ov001_021a9284;
extern const char *data_ov001_021a928c;
extern const char *data_ov001_021a9298;
extern const char *data_ov001_021a929c;
extern const char *data_ov001_021a92a0;
extern const char *data_ov001_021a92a4;
extern const char *data_ov001_021a92a8;
extern const char *data_ov001_021a92ac;
extern const char *data_ov001_021a92b0;
extern const char *data_ov001_021a92bc;
extern const char *data_ov001_021a92c0;
extern const char *data_ov001_021a92c4;
extern const char *data_ov001_021a9938;
extern const char *data_ov001_021a993c;
extern const char *data_ov001_021a9940;
extern const char *data_ov001_021a9944;
extern Unk021a99e4 *data_ov001_021a99e4;
extern Unk021a9b88 *data_ov001_021a9b88;
extern u16 data_ov001_021a9ba0;
extern Unk021a9b90 *data_ov001_021a9b90;
extern Unk021a9bd0 *data_ov001_021a9bd0;
extern Unk021a9bec *data_ov001_021a9bec;
extern Unk021a9bf8 *gSelectBattleStage;
// One pair of halfwords of the object behind data_ov001_021a9bfc.
typedef struct Unk021a9bfc_18 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
} Unk021a9bfc_18;

// Object behind data_ov001_021a9bfc.
typedef struct Unk021a9bfc {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ Unk021a9bfc_18 mUnk_18[2];
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28[2];
    /* 30 */ void *mUnk_30;
    /* 34 */ Unk02124b1c *mUnk_34;
    /* 38 */ struct Unk02021dc8 *mUnk_38;
    /* 3c */ Unk020b4934 *mUnk_3c;
    /* 40 */ Unk020b4a44 *mUnk_40;
    /* 44 */ Unk0201ea30 *mUnk_44;
    /* 48 */ void *mUnk_48;
    /* 4c */ void *mUnk_4c;
    /* 50 */ void *mUnk_50;
    /* 54 */ void *mUnk_54;
} Unk021a9bfc;

extern Unk021a9bfc *data_ov001_021a9bfc;
extern const char *data_ov001_021a90a8;
extern const char *data_ov001_021a90e4;
extern const char *data_ov001_021a90cc;
extern const char *data_ov001_021a90dc;
extern const char *data_ov001_021a90b8;
extern const char *data_ov001_021a90bc;
extern const char *data_ov001_021a90c8;
extern const char *data_ov001_021a90a4;
extern const char *data_ov001_021a90d8;
extern const char *data_ov001_021a90d4;
extern const char *data_ov001_021a90c4;
extern const char *data_ov001_021a90c0;
extern const char *data_ov001_021a94dc;
extern const char *data_ov001_021a94e0;
extern const char *data_ov001_021a94e4;
extern const char *data_ov001_021a94e8;
extern const char *data_ov001_021a94ec;
extern const char *data_ov001_021a94f0;
extern const char *data_ov001_021a94f4;
extern const char *data_ov001_021a94f8;
extern const char *data_ov001_021a94fc;
extern const char *data_ov001_021a9500;
extern const char *data_ov001_021a9504;
extern const char *data_ov001_021a9508;
extern const char *data_ov001_021a950c;
extern const char *data_ov001_021a9510;
extern s32 data_ov001_021a99e8;
extern u16 data_ov001_021a99ec[];
extern char data_ov001_021a94a4[];
extern char data_ov001_021a94b0[];
extern char data_ov001_021a94bc[];
extern char data_ov001_021a94d0[];
typedef struct Unk021a9be0 {
    /* 00 */ struct Unk02021dc8 *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ Unk02124b1c *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
} Unk021a9be0;

extern Unk021a9be0 *data_ov001_021a9be0;
extern Unk0219b250 *data_ov001_021a9b98;
extern Unk0217b498 *data_ov001_021a9bac;
extern Unk0217b498 *data_ov001_021a9bb0;
extern Unk0217b498 *data_ov001_021a9bb4;
extern Unk0217b498 *data_ov001_021a9bb8;
extern Unk0217b498 *data_ov001_021a9bbc;
extern Unk0217b498 *data_ov001_021a9bc0;
extern Unk0219b250 *gStopSign;
extern Unk0217b498 *data_ov001_021a9b8c;
extern Unk0217b498 *data_ov001_021a9bc4;
extern u16 data_ov001_021a9b94;
extern const char *data_ov001_021a90e8[5];
extern const char *data_ov001_021a92c8[5];

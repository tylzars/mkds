#pragma once

#include "types.h"
#include "Main/Unknown/unk_02029930.h" // Unk02029930_f8
#include "Main/Unknown/code_02025ebc.h" // Unk02025ebc
#include "Main/Unknown/code_02036588.h" // Unk02036590
#include "Main/Unknown/unk_02153000.h" // Unk021535b4
#include "Main/Unknown/code_020b4000.h" // Ncgr, Nscr, Nclr
#include "Main/Unknown/code_02124094.h" // Unk02124b1c, Unk0201ea30
#include "Main/Unknown/code_020b3f7c.h" // Unk020b3fb0
#include "Main/Unknown/code_0202f688.h"
#include "Main/Unknown/code_0205ee14.h" // Unk0205fd2c

// 0x18-byte elements of the table at member 0 of Unk02029930.
typedef struct Unk02029930_00 {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s32 mKartIndex;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mTeamIndex;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
} Unk02029930_00;

// Object behind data_02174e1c, returned by func_02029930.
typedef struct Unk02029930 {
    /* 00 */ Unk02029930_00 mUnk_00[8];
    /* c0 */ s32 mUnk_c0;
    /* c4 */ s32 mKartCount;
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mUnk_cc;
    /* d0 */ s32 mCourseId;
    /* d4 */ s32 mUnk_d4;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUseTeams;
    /* e0 */ s32 mUnk_e0;
    /* e4 */ s32 mUnk_e4;
    /* e8 */ u16 mUnk_e8;
    /* ea */ u8 mUnk_ea[2];
    /* ec */ s32 mUnk_ec;
    /* f0 */ s32 mCourseListMode;
    /* f4 */ u8 *mMissionFile;
    /* f8 */ Unk02029930_f8 *mMissionFileRows;
    /* fc */ s8 mMissionTableRow;
    /* fd */ s8 mMissionTableColumn;
    /* fe */ u8 mUnk_fe[6];
    // Set by func_02029468 from the mission table cell value minus 1: a 0-based position in mMissionFileRows.
    /* 104 */ u16 mMissionFileRowIndex;
    /* 106 */ u8 mUnk_106[2];
    /* 108 */ s32 mUnk_108;
    /* 10c */ u8 mUnk_10c;
    /* 10d */ u8 mUnk_10d;
} Unk02029930;

extern Unk02029930 *data_02174e1c;

// 0x118-byte object that gSelectKart points to.
typedef struct SelectKart {
    /* 000 */ u8 mUnk_000[0x24];
    /* 024 */ Unk02174e50_24 mUnk_024;
    /* 040 */ u8 mUnk_040[8];
    /* 048 */ Unk02174e50_24 mUnk_048;
    /* 064 */ Unk02174e50_24 mUnk_064;
    /* 080 */ void *mUnk_080;
    /* 084 */ void *mUnk_084;
    /* 088 */ void *mUnk_088;
    /* 08c */ void *mHeap;
    /* 090 */ s32 mStateFrames; /* counts only in states 3, 4 and 6 */
    /* 094 */ s32 mState;
    /* 098 */ Unk0205fd2c *mUnk_098;
    /* 09c */ s32 mUnk_09c;
    /* 0a0 */ s32 mUnk_0a0;
    /* 0a4 */ s32 mCharacterIndex;
    /* 0a8 */ s32 mKartIndex;
    /* ac */ Unk02025ebc mUnk_0ac[5];
    /* 0fc */ s32 mMode;
    /* 100 */ s32 mResult;
    /* 104 */ BOOL mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ s32 mUnk_10c;
    /* 110 */ s32 mUnk_110;
    /* 114 */ u16 mUnk_114;
    /* 116 */ u8 mUnk_116[2];
} SelectKart;

extern SelectKart *gSelectKart;

// Four words at 0x04 of Unk02174e3c_4c.
typedef struct Unk02174e3c_4c_04 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk02174e3c_4c_04;

// 0x2c-byte entries from 0x4c of Unk02174e3c.
typedef struct Unk02174e3c_4c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Unk02174e3c_4c_04 mUnk_04;
    /* 14 */ u16 mUnk_14[0xc];
} Unk02174e3c_4c;

extern Unk02036590 data_02174e88;

// 0x1c-byte part of Unk02174e14, at 0x00, 0x1c and 0x38; InitSelectCharacter has two on the stack, one filled by
// func_02025b84. Unk02174e60 has four from 0x48.
typedef struct Unk02174e14_00 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ Unk0201ea30 *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ Unk0201ea30 *mUnk_14;
    /* 18 */ Unk02124b1c *mUnk_18;
} Unk02174e14_00;

// Object behind data_02174e3c.
// Object behind gSelectCharacter.
typedef struct Unk02174e14 {
    /* 000 */ Unk02174e14_00 mUnk_000;
    /* 01c */ Unk02174e14_00 mUnk_01c;
    /* 038 */ Unk02174e14_00 mUnk_038;
    /* 054 */ void *mUnk_054;
    /* 058 */ void *mUnk_058;
    /* 05c */ void *mHeap;
    /* 060 */ s32 mUnk_060;
    /* 064 */ s32 mUnk_064;
    /* 068 */ s32 mUnk_068;
    /* 06c */ s32 mUnk_06c;
    /* 070 */ s32 mUnk_070;
    /* 074 */ u16 mUnk_074;
    /* 076 */ u8 mUnk_076[2];
    /* 078 */ s32 mUnk_078;
    /* 07c */ s32 mUnk_07c;
    /* 080 */ s32 mUnk_080;
    /* 84 */ s16 mUnk_084[4];
    /* 08c */ s32 mUnk_08c;
    /* 090 */ Unk021535b4 mUnk_090[12];
    /* 0f0 */ s32 mUnk_0f0;
    /* 0f4 */ s32 mUnk_0f4;
    /* f8 */ Unk02025ebc mUnk_0f8[3];
    /* 128 */ BOOL mUnk_128;
} Unk02174e14;

extern Unk02174e14 *gSelectCharacter;

// Object behind data_02174e3c, 0x258 bytes (func_0202c65c allocates it).
typedef struct Unk02174e3c {
    /* 000 */ Unk02174e14_00 mUnk_000;
    /* 01c */ Unk02174e14_00 mUnk_01c;
    /* 038 */ void *mUnk_038;
    /* 03c */ void *mHeap;
    /* 040 */ s32 mUnk_040;
    /* 044 */ s32 mUnk_044;
    /* 048 */ s32 mUnk_048;
    /* 04c */ Unk02174e3c_4c mUnk_04c[8];
    /* 1ac */ s32 mUnk_1ac[4];
    /* 1bc */ s32 mUnk_1bc[8];
    /* 1dc */ s32 mUnk_1dc[8];
    /* 1fc */ s32 mUnk_1fc;
    /* 200 */ s32 mUnk_200;
    /* 204 */ s32 mUnk_204;
    /* 208 */ s32 mUnk_208;
    /* 20c */ s32 mUnk_20c;
    /* 210 */ Unk02025ebc mUnk_210[4];
    /* 250 */ s32 mUnk_250;
    /* 254 */ s32 mUnk_254;
} Unk02174e3c;

extern Unk02174e3c *data_02174e3c;

// 0x24-byte part of Unk02174e60, at 0x00 and 0x24, filled by func_02025884.
typedef struct Unk02174e60_00 {
    /* 00 */ Ncgr *mUnk_00[4];
    /* 10 */ Nclr *mUnk_10;
    /* 14 */ Nscr *mUnk_14[4];
} Unk02174e60_00;

// 0xc-byte entries from 0xe4 of Unk02174e60.
typedef struct Unk02174e60_e4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk02174e60_e4;

// Object behind data_02174e60: 0x154 bytes allocated by func_02032f94.
typedef struct Unk02174e60 {
    /* 000 */ Unk02174e60_00 mUnk_000[2];
    /* 048 */ Unk02174e14_00 mUnk_048[4];
    /* 0b8 */ s32 mUnk_0b8[2];
    /* 0c0 */ u32 mUnk_0c0;
    /* 0c4 */ u32 mUnk_0c4;
    /* 0c8 */ void *mUnk_0c8;
    /* 0cc */ u16 mUnk_0cc;
    /* 0ce */ u16 mUnk_0ce;
    /* 0d0 */ s32 mUnk_0d0;
    /* 0d4 */ s32 mUnk_0d4;
    /* 0d8 */ s32 mUnk_0d8;
    /* 0dc */ s32 mUnk_0dc;
    /* 0e0 */ s32 mUnk_0e0;
    /* 0e4 */ Unk02174e60_e4 mUnk_0e4[8];
    /* 144 */ s32 mUnk_144;
    /* 148 */ s32 mUnk_148;
    /* 14c */ s32 mUnk_14c;
    /* 150 */ s32 mUnk_150;
} Unk02174e60;

extern Unk02174e60 *data_02174e60;

// 0x28-byte part of the entries from 0x9c of Unk02174e64; func_02034370 fills one on the stack through
// func_0204ebb8 and func_02034e68 compares two.
typedef struct Unk02174e64_9c_00 {
    /* 00 */ u16 mUnk_00[11];
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ s32 mUnk_18[3];
    /* 24 */ u16 mUnk_24;
    /* 26 */ u8 mUnk_26;
    /* 27 */ u8 mUnk_27;
} Unk02174e64_9c_00;

// 0x3c-byte entries from 0x9c of Unk02174e64.
typedef struct Unk02174e64_9c {
    /* 00 */ Unk02174e64_9c_00 mUnk_00;
    /* 28 */ s32 mUnk_28;
    /* 2c */ Unk02025ebc mUnk_2c;
} Unk02174e64_9c;

// Object behind data_02174e64.
typedef struct Unk02174e64 {
    /* 000 */ u8 mUnk_000[0x24];
    /* 024 */ void *mUnk_024[2];
    /* 02c */ Unk02174e14_00 mUnk_02c[2];
    /* 064 */ u8 mUnk_064[0x1c];
    /* 080 */ s32 mUnk_080;
    /* 084 */ Unk020b3fb0 *mUnk_084;
    /* 088 */ Unk020b3fb0 *mUnk_088;
    /* 08c */ s32 mUnk_08c;
    /* 090 */ s32 mUnk_090;
    /* 094 */ s32 mUnk_094;
    /* 098 */ s32 mUnk_098;
    /* 09c */ Unk02174e64_9c mUnk_09c[4];
    /* 18c */ s32 mUnk_18c;
    /* 190 */ s32 mUnk_190;
    /* 194 */ Unk02025ebc mUnk_194;
    /* 1a4 */ void *mHeap;
} Unk02174e64;

extern Unk02174e64 *data_02174e64;

// Objects whose layout isn't known yet.
extern struct Unk0202a658 *data_02174e24;
extern struct WiFiVSCourseSelect *gWiFiVSCourseSelect;
// 0x20 bytes, then the word at 0x44 the code addresses 0xc past.
typedef struct Unk02174e40_24 {
    /* 00 */ u8 mUnk_00[0x20];
    /* 20 */ u8 *mUnk_20;
} Unk02174e40_24;

// Object behind data_02174e40, 0xe0 bytes.
typedef struct Unk02174e40 {
    /* 000 */ u8 mUnk_000[0x24];
    /* 024 */ Unk02174e40_24 mUnk_024;
    /* 048 */ void *mUnk_048[2];
    /* 050 */ Unk02174e14_00 mUnk_050[3];
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ Unk020b3fb0 *mUnk_0a8;
    /* 0ac */ Unk020b3fb0 *mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ s32 mUnk_0b4;
    /* 0b8 */ u8 mUnk_0b8[0x14];
    /* 0cc */ Unk02025ebc mUnk_0cc;
    /* 0dc */ void *mHeap;
} Unk02174e40;

extern Unk02174e40 *data_02174e40;

struct Unk02174e44;

// Entry of the table at data_usa_02162f4c: four function pointers.
typedef struct Unk02162f4c {
    /* 00 */ void (*mUnk_00)(void *a, struct Unk02174e44 *b, void *c);
    /* 04 */ s32 (*mUnk_04)(u32 a);
    /* 08 */ void (*mUnk_08)(void);
    /* 0c */ void (*mUnk_0c)(void);
} Unk02162f4c;

// Object behind data_02174e44, 0x8dc bytes.
typedef struct Unk02174e44 {
    /* 000 */ u8 mUnk_000[0x404];
    /* 404 */ u8 mUnk_404[0x404];
    /* 808 */ s32 mUnk_808;
    /* 80c */ s32 mUnk_80c;
    /* 810 */ s32 mUnk_810;
    /* 814 */ s32 mUnk_814[0x20];
    /* 894 */ s32 mUnk_894[10];
    /* 8bc */ u8 *mUnk_8bc;
    /* 8c0 */ u8 *mUnk_8c0;
    /* 8c4 */ Unk02162f4c *mUnk_8c4;
    /* 8c8 */ s32 mUnk_8c8;
    /* 8cc */ s32 mUnk_8cc;
    /* 8d0 */ void *mUnk_8d0;
    /* 8d4 */ void *mUnk_8d4;
    /* 8d8 */ void *mUnk_8d8;
} Unk02174e44;

extern Unk02174e44 *data_02174e44;
typedef struct Unk02174e48 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ u16 *mUnk_004;
    /* 008 */ Unk02124b1c *mUnk_008;
    /* 00c */ void *mUnk_00c;
    /* 010 */ s32 mUnk_010;
    /* 014 */ s32 mUnk_014;
    /* 018 */ s32 mUnk_018;
    /* 01c */ s32 mUnk_01c;
    /* 020 */ s32 mUnk_020;
    /* 024 */ s32 mUnk_024;
    /* 028 */ void (*mUnk_028)(int a, int b, int c, int d);
    /* 02c */ u16 mUnk_02c;
    /* 02e */ u16 mUnk_02e;
    /* 030 */ s32 mUnk_030;
    /* 034 */ s32 mUnk_034;
    /* 038 */ s32 mUnk_038;
    /* 03c */ s32 mUnk_03c;
    /* 040 */ s32 mUnk_040;
    /* 044 */ s32 mUnk_044;
    /* 048 */ s32 mUnk_048;
    /* 04c */ s32 mUnk_04c;
    /* 050 */ s32 mUnk_050;
    /* 054 */ s32 mUnk_054;
    /* 058 */ u16 mUnk_058[0x300];
    /* 658 */ s32 mUnk_658;
    /* 65c */ s32 mUnk_65c;
    /* 660 */ s32 mUnk_660;
    /* 664 */ s32 mUnk_664;
    /* 668 */ s32 mUnk_668;
    /* 66c */ s32 mUnk_66c;
    /* 670 */ s32 mUnk_670;
} Unk02174e48;

extern Unk02174e48 *data_02174e48;
extern struct Unk02174e4c *data_02174e4c;
extern struct Unk02174e50 *data_02174e50;
extern struct Unk02174e54 *data_02174e54;
struct Unk02174e58;
extern struct Unk02174e58 *data_02174e58;
// Object behind data_02174e68, 0xa8 bytes.
typedef struct Unk02174e68 {
    /* 00 */ u8 mUnk_00[0x20];
    /* 20 */ u8 *mUnk_20;
    /* 24 */ void *mUnk_24[2];
    /* 2c */ Unk02174e14_00 mUnk_2c[2];
    /* 64 */ u8 mUnk_64[0x1c];
    /* 80 */ s32 mUnk_80;
    /* 84 */ Unk020b3fb0 *mUnk_84;
    /* 88 */ Unk020b3fb0 *mUnk_88;
    /* 8c */ s32 mUnk_8c;
    /* 90 */ Unk02025ebc mUnk_90;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ void *mHeap;
} Unk02174e68;

extern Unk02174e68 *data_02174e68;
struct Unk02174e6c;
extern struct Unk02174e6c *data_02174e6c;
extern Unk02036590 *data_02174e70;

// Object at data_02174e78: mUnk_0c is the pointer func_020365ac returns; mUnk_10 overlaps the first member of
// data_02174e88.
typedef struct Unk02174e78 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ void *mHeap;
    /* 10 */ const char *mUnk_10;
} Unk02174e78;

extern Unk02174e78 data_02174e78;
extern u8 data_usa_02174e80[];

extern u8 data_02174e04[];
extern u8 data_02174e08[];
extern u8 data_02174e0c[];
extern u8 data_02174e10[];

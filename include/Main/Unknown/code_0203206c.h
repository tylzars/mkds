#pragma once

#include "types.h"
#include "Main/Unknown/unk_02174000.h"

// 6-byte entries of the tables data_02153de8 and data_02153df4, at 0x4c of Unk02174e5c.
typedef struct Unk02174e5c_4c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
} Unk02174e5c_4c;

// Object behind data_02174e5c, 0x6c bytes (func_02032654 allocates it).
typedef struct Unk02174e5c {
    /* 00 */ Unk02174e14_00 mUnk_00[2];
    /* 38 */ void *mUnk_38;
    /* 3c */ void *mUnk_3c;
    /* 40 */ void *mHeap;
    /* 44 */ s32 mUnk_44;
    /* 48 */ s32 mUnk_48;
    /* 4c */ Unk02174e5c_4c *mUnk_4c;
    /* 50 */ void *mUnk_50;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68;
} Unk02174e5c;

extern Unk02174e5c *data_02174e5c;

// 12-byte entries of the tables data_02153e08, data_02153e0c and data_02153e10.
typedef struct Unk02153e08 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ const char *mUnk_04;
    /* 08 */ const char *mUnk_08;
} Unk02153e08;

// 12-byte entries of the table data_02153e20.
typedef struct Unk02153e20 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ u8 mUnk_02[6];
    /* 08 */ s32 mUnk_08;
} Unk02153e20;

extern Unk02174e5c_4c data_02153de8[];
extern Unk02174e5c_4c data_02153df4[];
extern Unk02153e08 data_02153e08[];
extern Unk02153e08 data_02153e0c[];
extern Unk02153e08 data_02153e10[];
extern Unk02153e20 data_02153e20[];

extern const char data_021639b8[];
extern const char data_021639d4[];
extern const char data_021639f4[];
extern const char data_02163a14[];
extern const char data_02163a30[];
extern const char data_02163a4c[];
extern const char data_02163a6c[];
extern const char data_02163a90[];
extern const char data_02163ab0[];
extern const char data_02163ad0[];
extern u8 data_02163aec[];
extern u8 data_02163af0[];
extern const char data_02163af4[];
extern const char data_02163b00[];
extern const char data_02163b1c[];
extern const char data_02163b38[];
extern const char data_02163b58[];
extern const char data_02163b78[];
extern const char data_02163b94[];
extern const char data_02163bb0[];
extern const char data_02163bcc[];
extern const char data_02163bec[];
extern const char data_02163c0c[];

void func_02032138(void);
void func_0203206c(void);
void func_0203223c(void);
s32 func_02032280(void);
void func_02032654(void *a, s32 b, void *c, void *d);
void func_020328c8(s32 a);
void func_020328f8(s32 a);
void func_02032940(void);
void func_020329a0(void);
void func_020329dc(s32 a);
void func_02032a20(void);

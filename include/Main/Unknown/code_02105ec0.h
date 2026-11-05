#pragma once

#include "types.h"
#include "Main/Unknown/code_0210e33c.h"

typedef struct Unk0212c400 Unk0212c400;

// 0x08-byte entries behind data_0216c860.
typedef struct Unk0216c860 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk0216c860;

extern Unk0216c860 data_0216c860[];

// Object behind data_0216c7e0.
typedef struct Unk0216c7e0 {
    /* 00 */ u32 mUnk_00[4];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} Unk0216c7e0;

extern Unk0216c7e0 data_0216c7e0;

// Object behind data_0216c7d8.
typedef struct Unk0216c7d8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ u32 mUnk_04;
} Unk0216c7d8;

extern Unk0216c7d8 data_0216c7d8;

// 0x03-byte argument of func_021073ec and func_021074ac.
typedef struct Unk021073ec {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
} Unk021073ec;

// Object behind data_0217c7f0.
typedef struct Unk0217c7f0 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
} Unk0217c7f0;

extern Unk0217c7f0 data_0217c7f0;

// View of data_0217c7c4; func_0210e280 takes it.
typedef struct Unk0217c7c4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ u8 *mUnk_0c;
    /* 10 */ s32 mUnk_10;
} Unk0217c7c4;

// The first eight bytes of each element of the table an Unk0217c7c4 describes: a handle at 0 and a word at 4.
typedef struct Unk0210e2c4 {
    /* 00 */ Unk0212c400 *mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk0210e2c4;

// Object behind data_0217c814.
typedef struct Unk0217c814 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u8 mUnk_14;
    /* 15 */ u8 mUnk_15;
    /* 16 */ u8 mUnk_16;
    /* 17 */ u8 mUnk_17;
    /* 18 */ u8 mUnk_18;
    /* 19 */ u8 mUnk_19;
    /* 1a */ u8 mUnk_1a[2];
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
} Unk0217c814;

extern Unk0217c814 data_0217c814;

// Object data_0217c854 points to.
typedef struct Unk0217c854 {
    /* 00 */ u8 mUnk_00[0x38];
    /* 38 */ u16 mUnk_38;
    /* 3a */ u16 mUnk_3a;
} Unk0217c854;

extern Unk0217c854 *data_0217c854;

// Object data_0217d060 points to.
typedef struct Unk0217d060 {
    /* 00 */ Unk0215c380 mUnk_00;
    /* 0c */ Unk0212c400 *mUnk_0c;
    /* 10 */ Unk0217c7b4 *mUnk_10;
} Unk0217d060;

extern Unk0217d060 *data_0217d060;

// Object behind data_0217d234.
typedef struct Unk0217d234 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk0217d234;

extern Unk0217d234 data_0217d234;

// Values of the two switches in func_02108344.
typedef enum { E0 = 0, E1 = 1, E2 = 2 } Unk02108344;

BOOL func_0210887c(s32 a);
BOOL func_021087f4(s32 a);
int func_021087d4(int a);
int func_021087c4(int a);
void func_02108720(void);
void func_02108598(u32 a, u32 b);
void func_02108344(void *a, u32 b, u32 c);
void func_0210823c(void);
void func_021074ac(s32 e);
void func_021073ec(u32 a, Unk021073ec b, Unk0217c814 *c);
void func_02107010(void);
void func_02106efc(void);
void func_02106e78(void);
void func_02106dc8(void);
void func_02106c64(void);
void func_02106ab8(void);
void func_0210689c(u32 a);
void func_02106580(void);
void func_021062a8(void);
void func_021060dc(void);
void func_02105fcc(void);
void func_02105ec0(void);

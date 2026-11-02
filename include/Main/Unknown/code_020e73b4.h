#pragma once

#include "types.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_0210b000.h"

// 0x40-byte block that func_020e7410 takes from data_02159370.
typedef struct Unk020e7410 {
    /* 00 */ u32 mUnk_00[0x10];
} Unk020e7410;

// Filled in by func_020e7760; func_020e84b0 stores func_020d4ef4's return value
// at 0x0c and hands it to func_0210b760.
extern Unk0210b7a8 data_0217b9dc;

// Source rows read by the second loop of func_020e7460, 0x0c bytes each; a
// row's non-zero words are names looked up by FindSceneFile.
typedef struct Unk0216c324 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ const char *mUnk_04;
    /* 08 */ const char *mUnk_08;
} Unk0216c324;

extern Unk0216c324 data_0216c324[];

// 0x10-byte rows of the table at data_0217bae8: the second loop of func_020e7460
// writes three objects allocated through func_02036bec into the rows from
// data_0217bb08 on, and the word at 0x0c of the first two rows receives the
// object func_020e6488 creates. func_020e9810 reads the words at 0x0c through
// data_0217baf4.
typedef struct Unk0217bb08 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ Unk020e6488 *mUnk_0c;
} Unk0217bb08;

extern Unk0217bb08 data_0217bb08[];

extern Unk0217bb08 data_0217bae8[];

extern Unk0217bb08 data_0217baf4[];

Unk020e6fd4 *func_020e73b4(void);
Unk020e7410 *func_020e7410(void);
void func_020e7460(void);
void func_020e7760(void);
void func_020e79c4(void);
void func_020e7a18(void);

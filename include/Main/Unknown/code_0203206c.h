#pragma once

#include "types.h"
#include "Main/Unknown/unk_02174000.h"

// 6-byte entries of mTable (data_02153de8 and data_02153df4).
typedef struct Unk02174e5c_4c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
} Unk02174e5c_4c;

// 0x6c bytes.
typedef struct SelectGame {
    /* 00 */ Unk02174e14_00 mUnk_00[2];
    /* 38 */ void *mUnk_38;
    /* 3c */ void *mUnk_3c;
    /* 40 */ void *mHeap;
    /* 44 */ s32 mSelectedIndex;
    /* 48 */ s32 mTableCount;
    /* 4c */ Unk02174e5c_4c *mTable;
    /* 50 */ struct Bmg *mMenuMessages;
    /* 54 */ s32 mState;
    /* 58 */ s32 mStateFrames;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mResult;
    /* 68 */ s32 mMode;
} SelectGame;

extern SelectGame *gSelectGame;

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

extern const char gSelectGameMBNcgrName[];
extern const char gSelectGameMNceNcgrName[];
extern const char gSelectGameMNceNcerName[];
extern const char gSelectGameMBNclrName[];
extern const char gSelectGameMONclrName[];
extern const char gSelectGameMMultiNscrName[];
extern const char gSelectGameMSingleNscrName[];
extern const char gSelectGameSNceNcgrName[];
extern const char gSelectGameSNceNcerName[];
extern const char gSelectGameSONclrName[];
extern u8 data_02163aec[];
extern u8 data_02163af0[];
extern const char gMenuBmgName[];
extern const char gSelectGameMBNcgrName2[];
extern const char gSelectGameMBNclrName2[];
extern const char gSelectGameMNceNcgrName2[];
extern const char gSelectGameMNceNcerName2[];
extern const char gSelectGameMONclrName2[];
extern const char gSelectGameMBnclName[];
extern const char gSelectGameMBnllName[];
extern const char gSelectGameSNceNcgrName2[];
extern const char gSelectGameSNceNcerName2[];
extern const char gSelectGameSONclrName2[];

void func_02032138(void);
void LoadSelectGameData(void);
void ReleaseSelectGame(void);
s32 AdvanceSelectGame(void);
void InitSelectGame(void *a, s32 b, void *c, void *d);
void func_020328c8(s32 a);
void func_020328f8(s32 a);
void func_02032940(void);
void func_020329a0(void);
void func_020329dc(s32 a);
void func_02032a20(void);

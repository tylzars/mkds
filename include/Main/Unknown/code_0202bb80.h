#pragma once

#include "types.h"

typedef struct CellFileSet CellFileSet;
typedef struct Unk02174e3c Unk02174e3c;

// 6-byte elements of the table behind data_usa_02174e0c: three indices into the arrays at member 0x18 of
// CellFileSet.
typedef struct Unk02174e0c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
} Unk02174e0c;

// 8-byte elements of the table behind data_usa_02174e14.
typedef struct Unk02174e14_8 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ u8 mUnk_02[6];
} Unk02174e14_8;

// What the first member of Unk02174e3c points to.
typedef struct Unk02174e3c_00 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ u32 mUnk_10;
    /* 14 */ void *mUnk_14;
} Unk02174e3c_00;

extern u16 data_usa_02153a9c[];
extern s16 data_usa_02153aa4[];
extern u16 data_usa_02153aac[];
extern u16 data_usa_02153ac0[];
extern u16 data_usa_02153ad4[];
extern u16 data_usa_02153af0[];
extern Unk02174e0c data_usa_02153b0c[];
extern Unk02174e0c data_usa_02153b3c[];
extern Unk02174e14_8 data_usa_02153b6c[];
extern Unk02174e14_8 data_usa_02153bac[];
extern const char data_usa_02162904[];
extern const char data_usa_0216292c[];
extern const char data_usa_02162954[];
extern const char data_usa_02162980[];
extern const char data_usa_021629a8[];
extern const char data_usa_021629d0[];
extern const char data_usa_021629fc[];
extern const char data_usa_02162a18[];
extern const char data_usa_02162a34[];
extern const char data_usa_02162a54[];
extern const char data_usa_02162a70[];
extern const char data_usa_02162a8c[];
extern const char data_usa_02162aac[];
extern const char data_usa_02162ad4[];
extern const char data_usa_02162afc[];
extern const char gSelectMenuEtcDownloadMBnclName[];
extern const char gSelectMenuEtcDownloadMBnllName[];
extern const char data_usa_02162b6c[];
extern const char data_usa_02162b88[];
extern const char data_usa_02162ba4[];
extern const char gSelectMenuEtcMBnclName[];
extern const char gSelectMenuEtcMBnllName[];
extern const char data_usa_02162bf0[];
extern const char data_usa_02162c14[];
extern const char gSelectMenuEtcTitleMBnclName[];
extern const char data_usa_02162c58[];
extern Unk02174e0c *data_usa_02174e0c;
extern u16 *data_usa_02174e10;
extern Unk02174e14_8 *data_usa_02174e14;
extern u16 *data_usa_02174e18;

void func_0202bb80(void);
void func_0202c0d4(s32 a, s32 b);
void func_0202c65c(void *a, void *b);
void PrintEntryName(s32 a, u16 *b);
void func_0202c8dc(void);
void func_0202c960(void);
void func_0202cb2c(s32 a);
void func_0202cb68(s32 a);
void func_0202cba4(void);
void func_0202cbf4(void);
void func_0202cc18(s32 a, s32 b);
void func_0202cc44(s32 a, s32 b);

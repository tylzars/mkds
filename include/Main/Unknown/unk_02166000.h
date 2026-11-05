#pragma once

#include "types.h"
#include "Main/Unknown/unk_02165000.h" // Unk02165ff0
#include "Main/Unknown/code_020846c0.h" // Unk0208526c
#include "Main/Unknown/code_0210b000.h" // Unk0210b7a8

struct Unk0208e490;

// 0x2c-byte entries from data_0216618c; the objects func_0208e098 makes from an entry have its functions at 0x80 and
// 0x84 and its size at 0x18, mUnk_04, mUnk_08 and mUnk_0c select the objects at 0x90, 0x94 and 0x98.
typedef struct Unk0216618c {
    /* 00 */ u16 mUnk_00;
    /* 04 */ BOOL mUnk_04;
    /* 08 */ BOOL mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ void (*mUnk_10)(struct Unk0208e490 *, s32);
    /* 14 */ void (*mUnk_14)(struct Unk0208e490 *);
    /* 18 */ u32 mUnk_18;
    /* 1c */ Unk0208526c mUnk_1c;
} Unk0216618c;

extern Unk0216618c data_0216618c[5];
extern Unk0216618c data_021661b8;
extern Unk0216618c data_021661e4;
extern Unk0216618c data_02166210;
extern Unk0216618c data_0216623c;
extern const char data_02166268[];
extern const char data_02166280[];
extern const char data_02166298[];
extern const char data_021662b8[];
extern const char data_021662d8[];
extern const char data_021662f8[];
extern const char data_02166318[];
extern const char data_0216633c[];
extern const char data_02166360[];
extern const char data_02166384[];
extern const char data_021663a8[];
extern const char data_021663c0[];

extern u8 data_021663d8;
extern u8 data_021663dc;
extern u16 data_021663e0;
extern u16 data_021663e4;
extern s32 data_021663e8;
extern s32 (*data_021663ec)();
extern s32 data_021663f0;
// Object at data_021663f4.
typedef struct Unk021663f4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0x14];
    /* 18 */ u32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} Unk021663f4;

extern Unk021663f4 data_021663f4;
extern s32 data_02166418[][2];
extern s32 data_0216641c[][2];
extern s32 data_02166480[];
extern const char data_02166514[];
extern const char data_02166530[];
extern Unk02165ff0 data_0216600c;
extern Unk02165ff0 data_02166028;

extern const char gBasabasaNsbmdName[];
extern const char gBasabasaNsbtpName[];
extern const char gCowNsbmdName[];
extern const char gCowNsbtpName[];
extern const char gTeresaNsbmdName[];
extern const char gTeresaNsbtpName[];
extern const char gKanoke64NsbmdName[];
extern const char gKanoke64NsbcaName[];
extern const char gMkdEfBurnerNsbmdName[];
extern const char gMkdEfBurnerNsbtaName[];
extern const char gNsKiller2NsbmdName[];
extern const char gNsKiller2SNsbmdName[];
extern Unk0210b7a8 data_0216676c;
extern const char gNsKiller1NsbmdName[];
extern const char gBakubakuNsbmdName[];
extern const char gBakuShadowNsbmdName[];
extern const char gMoveTreeNsbmdName[];
extern const char gMoveTreeNsbcaName[];
extern char data_02166548[];
extern char gSmanBottomNsbmdName[];
extern char gSmanTopNsbmdName[];
extern char gFlipperNsbmdName[];
extern char gFlipperNsbtpName[];
extern char gFlipperNsbtaName[];

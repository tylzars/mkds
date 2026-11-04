#pragma once

#include "types.h"
#include "Main/Unknown/unk_02175000.h" // Unk021a9034
#include "Main/Unknown/code_02086058.h"

extern const char gArchiveColonFormat[];
extern const char gCharacterNsbcaFormat[];
extern u16 data_usa_021656d8;
extern u16 data_usa_021656dc;
extern s32 data_usa_021656e0;
extern s32 data_usa_021656e4;
extern u32 data_usa_021656e8;
extern s32 data_usa_021656ec;
extern Vec3 data_usa_021656f0;
extern Vec3 data_usa_021656fc;
extern Vec3 data_usa_02165708;
extern u8 data_usa_02165724[];
extern u8 data_usa_02165738[];
extern u8 data_usa_0216574c[];
extern u8 data_usa_02165760[];
extern u8 data_usa_0216577c[];
extern const char gArchiveColonSlashFormat[];
extern const u8 data_usa_021651d0[];

// Objects whose layout isn't known yet.
// A function and three numbers; func_02050650 takes the address of data_021652a0.
typedef struct Unk021652a0 {
    /* 00 */ void (*mUnk_00)();
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ s32 mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e[2];
} Unk021652a0;

extern Unk021652a0 data_0216523c;
extern const s32 data_02165510[2];
extern const Vec3 data_02165524;
extern const Vec3 data_0216553c;
extern const Vec3 data_02165548;
extern const Unk021a9034 data_0216524c;
extern const Unk021a9034 data_02164838;
extern const Unk021a9034 data_02165190;
extern const Unk021a9034 data_02165280;
extern Unk021652a0 data_021652a0;
extern u16 data_usa_02165228;
extern Unk021652a0 data_usa_0216522c;
extern UnkFunc *const data_021652b0[];
extern UnkFunc *const data_02165388[];
struct Kart;
extern void (*const gKartStateFunctions[])(struct Kart *);
extern const Unk021a9034 data_02165368;
extern const Unk021a9034 data_usa_021651b0;
extern const char data_02165074[];
extern const char data_02165080[];
extern u8 data_02165098[];
extern const char data_021650a0[];
extern u8 data_021650b4[];
extern const char data_021650bc[];
extern u8 data_021650d8[];
extern const char data_0216512c[];
extern u8 data_02165140[];
extern const char data_02165148[];
extern u8 data_0216515c[];
extern const char data_0216526c[];
extern const char *gCharacterDirName;
extern const char *gKartDirName;
extern const char *gCharacterSubDirNames[13];
extern u16 data_021659d4[12];
extern Unk02086098 data_021659ec;
extern Unk02086098 data_02165a10;
extern Unk02086098 data_02165a34;
extern Unk02086098 data_02165a58;
extern const char gCommonPFaceanimNsbtpFormat[];
extern const char gKartModelMenuPrefix[];
extern const char gKartModelSlashPrefix[];

extern s16 data_021653b8[];
extern const Unk021a9034 data_021653c0;
extern u16 data_0216569c;
extern u16 data_usa_021656a0;
extern s32 data_usa_021656b4;
extern s32 data_usa_021656c0;
extern Vec3 data_02165530;
extern s32 data_02165948;
extern s32 data_0216593c;
extern s32 data_02165944;
extern s32 data_0216594c;
extern s32 data_02165950;
extern u32 data_02165978[];

// Three words, three more words and two halfwords; data_02165ff0, data_0216600c and data_02166028 are one each.
typedef struct Unk02165ff0 {
    /* 00 */ s32 mUnk_00[3];
    /* 0c */ s32 mUnk_0c[3];
    /* 18 */ s16 mUnk_18;
    /* 1a */ s16 mUnk_1a;
} Unk02165ff0;

extern Unk02165ff0 data_02165ff0;

extern u8 data_021651d4[];
extern const s32 data_02166048;
extern const Vec3 data_0216608c;
extern u8 data_021651d8[];
extern const char data_usa_02165990[];
extern const char *const gTeamEmblemNames[];
extern const char gTeamEmblemNsbtxFormat[];
extern const char gEmblemNsbtxFormat[];
extern s32 data_021659a0;
extern s32 data_021659a4;
extern s32 data_021659a8;
extern s32 data_021659ac;
extern s32 data_021659b0;
extern s32 data_021659b4;
extern s32 data_021659b8;
extern s32 data_021659bc;
extern s32 data_021659c0;
extern s32 data_021659c4;
extern s32 data_021659c8;
extern s32 data_021659cc;
extern s32 data_021659d0;
extern const char gEmblemSBNclrName[];
extern s32 data_usa_021654ec;
extern s32 data_021654f4;
// Three words.
typedef struct Unk02165560 {
    /* 00 */ u32 mUnk_00[3];
} Unk02165560;

extern const Unk02165560 data_usa_02165560;

// Eight halfwords.
typedef struct Unk0216557c {
    /* 00 */ s16 mUnk_00[8];
} Unk0216557c;

extern const Unk0216557c data_usa_0216557c;
extern s32 data_usa_021654dc;
extern const Vec3 data_usa_02165554;
// 37 words.
typedef struct Unk02165608 {
    /* 00 */ s32 mUnk_00[37];
} Unk02165608;

extern const Unk02165608 data_usa_02165608;
extern s32 data_usa_02165504;
extern const s32 data_usa_02165500;
extern const s16 data_usa_021654c0;

extern u16 data_usa_021658f0;
extern const s32 *data_usa_021658f4;
extern const u16 data_usa_021658f8[3];
extern const u16 data_usa_02165900[3];
extern const u16 data_usa_02165908[3];
extern const s32 *const data_usa_02165910[];
extern s32 data_usa_021654d8;

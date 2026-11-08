#pragma once

#include "types.h"
#include "code_02022aa8.h"

// 12-byte entries of the table at gMemberGroupLabelMessageRows.
typedef struct LabelMessageRow {
    /* 00 */ s16 mLabelIndex;
    /* 02 */ s16 mWidth;
    /* 04 */ s16 mHeight;
    /* 06 */ s16 mCellIndex;
    /* 08 */ s32 mMessageIndex;
} LabelMessageRow;

// 0x32-byte entries of the table at gMemberRowCellIndices.
typedef struct MemberRowCellIndices {
    /* 00 */ u16 mCellIndices[0x18];
    /* 30 */ u16 mLabelIndex;
} MemberRowCellIndices;

// 8-byte entries of the table at data_usa_02153554.
typedef struct Unk02153554 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mRectEntryId;
} Unk02153554;

// 8-byte entries at 0x90 of Unk02174e14, filled from data_021535b4.
typedef struct Unk021535b4 {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s32 mUnk_04;
} Unk021535b4;

// 4-byte entries of the table at gSoundRowTable.
typedef struct SoundRow {
    /* 00 */ u8 mUnk_00[4];
} SoundRow;

// 4-byte entries of the tables at data_021534bc, data_021534dc, data_02153500 and data_02153528.
typedef struct Unk021534bc {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
} Unk021534bc;

extern LabelMessageRow gMemberGroupLabelMessageRows[];
extern Unk02153554 data_usa_02153554[];
extern Unk021534bc data_021534bc[];
extern Unk021534bc data_021534dc[];
extern Unk021534bc data_02153500[];
extern Unk021534bc data_02153528[];
extern Unk021535b4 data_021535b4[];
extern MemberRowCellIndices gMemberRowCellIndices[];
extern u16 gMemberRowRectIndices[][3];

// Rows of nine words; each name starts at one word of the first row.
extern const char *data_02153f80[][9];
extern const char *data_02153f84[][9];
extern const char *data_02153f88[][9];
extern const char *data_02153f8c[][9];
extern const char *data_02153f90[][9];
extern const char *data_02153f94[][9];
extern const char *data_02153f98[][9];
extern const char *data_02153f9c[][9];
extern const char *data_02153fa0[][9];
extern u16 data_02153f00[][4];
extern SoundRow gSoundRowTable[];

// Objects whose layout isn't known yet.
extern u8 gCourseMessageIndexTable[];
extern u8 data_02153158[];

extern u8 data_021532a8[];
extern u8 gKartMessageIndexTable[];
extern u32 gKartIndexTable[];
extern s32 data_usa_02153240[];
extern s32 data_usa_02153274[];

// 12-byte entries of data_usa_021537f4: a halfword value and a word at 8.
typedef struct Unk021537f4 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ u8 mUnk_02[6];
    /* 08 */ s32 mUnk_08;
} Unk021537f4;

extern u16 data_usa_021537dc[];
extern Unk021537f4 data_usa_021537f4[];
extern s16 data_usa_02153834[];
extern u16 data_021530b8[4][4];
extern u16 data_021530d0[4][4];
extern Unk02022aa8_f *data_021530e8[];
extern u32 data_02153118[][4];
extern u8 data_usa_021530f8[4][4][2];

extern u16 data_02153d20[][3];

typedef struct Unk02153d2c {
    /* 00 */ s16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ s32 mUnk_08;
} Unk02153d2c;

extern Unk02153d2c data_02153d2c[];
extern s16 data_02154034[][4];
extern s16 data_0215404c[][4];

// Tables of 12-byte entries (data_usa_02153d7c is the third entry of data_usa_02153d64) and of u16 pairs.
extern LabelMessageRow data_usa_02153d64[];
extern LabelMessageRow data_usa_02153d7c[];
extern LabelMessageRow data_usa_02153d88[];
extern u16 data_usa_02153d44[][2];
extern u16 data_usa_02153d46[][2];
extern u16 data_usa_02153d54[];
extern s16 data_usa_02153dbc[];

// Tables of four u16, written to mUnk_084 of Unk02174e14.
extern u16 data_usa_02153614[4];
extern u16 data_usa_0215361c[4];
extern u16 data_usa_02153624[4];
extern u16 data_usa_0215362c[4];
extern u16 data_usa_02153634[4];
extern u16 data_usa_0215363c[4];
extern u16 data_usa_02153644[4];
extern u16 data_usa_0215364c[4];
extern u16 data_usa_02153654[4];
extern u16 data_usa_0215365c[4];
extern u16 data_usa_02153664[4];
extern u16 data_usa_0215366c[4];
extern u16 data_usa_02153674[4];
extern u16 data_usa_0215367c[4];
extern u16 data_usa_02153684[4];
extern u16 data_usa_0215368c[4];
extern u16 data_usa_02153694[4];
extern u16 data_usa_0215369c[4];
extern u16 data_usa_021536a4[4];
extern u16 data_usa_021536ac[4];
extern u16 data_usa_021536b4[4];
extern u16 data_usa_021536bc[4];
extern u16 data_usa_021536c4[4];
extern u16 data_usa_021536cc[4];
extern u16 data_usa_021536d4[4];
extern u16 data_usa_021536dc[4];
extern u16 data_usa_021536e4[4];
extern u16 data_usa_021536ec[4];
extern u16 data_usa_021536f4[4];
extern u16 data_usa_021536fc[4];
extern u16 data_usa_02153704[4];
extern u16 data_usa_0215370c[4];
extern u16 data_usa_02153714[4];
extern u16 data_usa_0215371c[4];
extern u16 data_usa_02153724[4];
extern u16 data_usa_0215372c[4];
extern u16 data_usa_02153734[4];
extern u16 data_usa_0215373c[4];
extern u16 data_usa_02153744[4];
extern u16 data_usa_0215374c[4];
extern u16 data_usa_02153754[4];
extern u16 data_usa_0215375c[4];
extern u16 data_usa_02153764[4];
extern u16 data_usa_0215376c[4];
extern u16 data_usa_02153774[4];
extern u16 data_usa_0215377c[4];
extern u16 data_usa_02153784[4];
extern u16 data_usa_0215378c[4];
extern u16 data_usa_02153794[4];
extern u16 data_usa_0215379c[4];
extern u16 data_usa_021537a4[4];
extern u16 data_usa_021537ac[4];
extern u16 data_usa_021537b4[4];
extern u16 data_usa_021537bc[4];
extern u16 data_usa_021537c4[4];
extern u16 data_usa_021537cc[4];
extern u16 data_usa_021537d4[4];

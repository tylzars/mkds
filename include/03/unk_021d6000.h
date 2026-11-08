#pragma once

#include "types.h"
#include "03/types_021d299c.h"

typedef struct Rect Rect;

// Seven bytes moved as one value.
typedef struct Bytes7 {
    /* 0 */ u8 mBytes[7];
} Bytes7;

// Entry of data_ov003_021d64f0, two halfwords.
typedef struct Unk021d64f0 {
    /* 0 */ u16 mUnk_00;
    /* 2 */ u16 mUnk_02;
} Unk021d64f0;

// Four bytes moved as one value.
typedef struct Unk021d6974 {
    /* 0 */ u8 mUnk_00[4];
} Unk021d6974;

// 0x44 bytes moved as one value.
typedef struct Unk021d66d0 {
    /* 00 */ u32 mUnk_00[0x11];
} Unk021d66d0;

// Objects whose layout isn't known yet.
extern s8 data_ov003_021d6434[];
extern Rect gJb3ListCellRect;
extern Rect data_ov003_021d6444;
extern Rect data_ov003_021d644c;
extern u8 gJb3ListIdByEntryIndex[];
extern const u8 data_ov003_021d6478[][3];
extern u8 gJb3ListEntryIndexById[];
extern u16 data_ov003_021d6488[];
extern u8 data_ov003_021d64e4[];
extern s8 data_ov003_021d64e8[];
extern Unk021d64f0 data_ov003_021d64f0[];
extern u8 gApRects[];
extern Rect data_ov003_021d6540[];
extern s8 data_ov003_021d6578[];
extern s8 gWayMoveTargets[][4][4];
extern Rect gWayRects[][4];
extern Rect data_ov003_021d65e0[][4];
extern u8 data_ov003_021d6620[];
extern u8 data_ov003_021d6630[];
extern u8 data_ov003_021d6638[];
extern u8 data_ov003_021d66bc[];
extern u8 data_ov003_021d66c4[];
extern Unk021d66d0 data_ov003_021d66d0;
extern u8 data_ov003_021d6720[];
extern u16 data_ov003_021d6714[2];
extern u8 data_ov003_021d6718[];
extern u8 data_ov003_021d6728[];
extern s8 data_ov003_021d673c[][2];
extern u8 data_ov003_021d6730[][2];
extern u8 data_ov003_021d6748[][2];
extern u16 data_ov003_021d6754[][2];
extern u16 data_ov003_021d6768[][2];
extern u16 data_ov003_021d6780[][2];
extern u16 data_ov003_021d6798[][2];
extern u16 data_ov003_021d67b0[][2][2];
extern u32 gThreadStackSize;
extern s32 gTimeoutAtMs;
extern s32 data_ov003_021d68bc;
extern u8 *data_ov003_021d68ac;
extern u32 data_ov003_021d68b0;
extern char gSixAsterisksString[];
extern Bytes7 gKind2Item3Bytes;
extern Unk021d6974 data_ov003_021d6974;
extern u8 data_ov003_021d691c[];
extern u8 data_ov003_021d697c[];
extern u8 data_ov003_021d67f0[];
extern u8 data_ov003_021d6214[];
extern u8 data_ov003_021d6218[];
extern u8 data_ov003_021d621c[];
extern u8 data_ov003_021d6220[];
extern u8 gEditAddrKeyboardRow4KeyInputs[];
extern u8 gEditAddrKeyboardExtraKeyInputs[];
extern u16 gEditAddrKeyboardDigitKeySize[];
extern const u16 data_ov003_021d6230[];
extern u16 gEditAddrKeyboardExtraKeySize[];
extern u16 gEditAddrKeyboardRow4KeySize[];
extern u16 gEditAddrKeyboardExtraKeyPositions[][2];
extern u16 gEditAddrKeyboardRow4KeyPositions[][2];
extern u8 gEditAddrKeyboardDigitInputs[];
extern u16 gEditAddrKeyboardKeyTexts[];
extern u16 gEditAddrKeyboardDigitKeyPositions[][2];
extern u16 gEditAddrKeyboardCursorX[];
extern u16 gEditAddrKeyboardCursorY[];
extern s8 gEditAddrKeyboardCursorMoves[];
extern u8 gNintendoDsItemBytes[];
extern Rect data_ov003_021d67e8;
extern u16 *data_ov003_021d6be8[3];
extern u8 gEditAddrKeyboardRow4KeyCounts[];
extern u8 gEditAddrKeyboardDigitKeyCounts[];
extern u8 gEditAddrKeyboardExtraKeyCounts[];
extern u16 data_ov003_021d6dd8[];

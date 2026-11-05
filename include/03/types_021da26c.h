#pragma once

#include "types.h"
#include "code_02142eac.h"

// Entry of the table at offset 0x1300 of an Unk021da26c.
typedef struct Unk021ccf30_1300 {
    /* 00 */ u8 mUnk_00[0x20];
    /* 20 */ u8 mUnk_20[6];
    /* 26 */ u16 mUnk_26;
    /* 28 */ u8 mUnk_28;
} Unk021ccf30_1300;

// 0x44 bytes: func_ov003_021cd1c4 copies them from data_ov003_021d6640; the first 0x38 bytes are the object
// WM_StartScanEx takes.
typedef struct Unk021da26c_1648 {
    /* 00 */ Unk021438f0 mUnk_00;
    /* 38 */ u8 mUnk_38[0xc];
} Unk021da26c_1648;

// Buffer func_02143520 fills; mUnk_00 is the value func_ov003_021cd118 waits for.
typedef struct Unk021da26c_168c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[0x7ba];
} Unk021da26c_168c;

// Object that data_ov003_021da26c points to (0x1e60 bytes).
typedef struct Unk021da26c {
    /* 0000 */ u8 mUnk_0000[0xf00];
    /* 0f00 */ u8 mUnk_0f00[0x400];
    /* 1300 */ Unk021ccf30_1300 mUnk_1300[0x14];
    /* 1648 */ Unk021da26c_1648 mUnk_1648;
    /* 168c */ Unk021da26c_168c mUnk_168c;
    /* 1e48 */ u8 mUnk_1e48;
    /* 1e49 */ u8 mUnk_1e49[0x17];
} Unk021da26c;

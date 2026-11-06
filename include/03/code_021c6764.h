#pragma once

#include "types.h"

typedef struct Unk021d2188 Unk021d2188;

// Object at 0x04 of Edit.
typedef struct Unk021da1f8_04 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk021da1f8_04;

typedef struct Edit {
    /* 00 */ Unk021d2188 *mUnk_00;
    /* 04 */ Unk021da1f8_04 *mUnk_04;
    /* 08 */ u8 mText[0x20];
    /* 28 */ u8 mUnk_28;
    /* 29 */ u8 mCharCount;
    /* 2a */ u8 mUnk_2a;
} Edit;

extern u8 gEditLineY[];
extern u16 data_ov003_021d63e4[];
extern u8 gEditColumnX[];
extern u8 data_ov003_021d7278[];

BOOL func_ov003_021c6764(void);
void func_ov003_021c6854(void);
void func_ov003_021c68c8(void);
void func_ov003_021c6914(void);
void PrintEditText(void);
void func_ov003_021c6a18(void);
void func_ov003_021c6acc(void);
void func_ov003_021c6b58(void);
void func_ov003_021c6b80(void);
void func_ov003_021c6b9c(void);
void UpdateEditInput(void);
void UpdateEdit(void);
void func_ov003_021c6cf0(void);
void func_ov003_021c6d0c(void);
void func_ov003_021c6d68(void);
void LoadEditFilesAndSetBgCnt(void);
void CreateEdit(void);

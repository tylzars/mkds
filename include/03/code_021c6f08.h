#pragma once

#include "types.h"

typedef struct Unk021d2188 Unk021d2188;
typedef struct Unk021da1f8_04 Unk021da1f8_04;

typedef struct EditAddr {
    /* 00 */ Unk021d2188 *mUnk_00;
    /* 04 */ Unk021da1f8_04 *mUnk_04;
    /* 08 */ u8 mText[0xc];
    /* 14 */ u8 mGroupIndex;
    /* 15 */ u8 mUnk_15;
} EditAddr;

// Five functions called with the object at 0x08.
typedef struct Unk021d7324 {
    /* 00 */ void (*mUnk_00[5])(u8 *);
} Unk021d7324;

// Five functions called with the object at 0x08.
typedef struct Unk021d7310 {
    /* 00 */ void (*mUnk_00[5])(u8 *);
} Unk021d7310;

extern u16 data_ov003_021d63f8[];
extern u8 gEditAddrCharX[];
extern u8 gEditAddrGroupMax[];
extern u8 data_ov003_021d7300[];
extern u16 data_ov003_021d7308[];
extern Unk021d7310 data_ov003_021d7310;
extern Unk021d7324 data_ov003_021d7324;
extern u8 data_ov003_021d73ac[];

void func_ov003_021c6f08(void);
void func_ov003_021c6f3c(void);
BOOL func_ov003_021c6f64(void);
void func_ov003_021c7050(void);
void func_ov003_021c70a4(void);
void func_ov003_021c7118(void);
void func_ov003_021c7160(void);
void PrintEditAddrText(void);
void func_ov003_021c722c(void);
void func_ov003_021c72a4(void);
void func_ov003_021c7314(void);
void func_ov003_021c733c(void);
void func_ov003_021c7358(void);
u32 func_ov003_021c735c(s32 param_0);
void UpdateEditAddrInput(void);
void UpdateEditAddr(void);
void func_ov003_021c75f8(void);
void func_ov003_021c7614(void);
void func_ov003_021c7678(void);
void LoadEditAddrFilesAndSetBgCnt(void);
void CreateEditAddr(void);

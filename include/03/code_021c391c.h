#pragma once

#include "types.h"

typedef struct Unk021da104_04 Unk021da104_04;
typedef struct Unk021d299c Unk021d299c;

typedef struct Unk021d70f8 {
    /* 00 */ u8 mUnk_00[0x16];
} Unk021d70f8;

typedef struct Unk021d7110 {
    /* 00 */ u8 mUnk_00[0x17];
} Unk021d7110;

extern u8 data_ov003_021d6348[];
extern u16 data_ov003_021d634c[];
extern Unk021d299c gOptMenuRects[];
extern u16 data_ov003_021d6368[];
extern u16 data_ov003_021d636a[];
extern u16 data_ov003_021d636c[];
extern u16 data_ov003_021d636e[];
extern Unk021d70f8 gYbBgOptionNclName;
extern Unk021d7110 gYbBgOption1NclName;
extern u8 gJbBgOptionNcgName[];
extern u8 gJb5OptMenuNscName[];
extern u8 gOptMenuSelectedIndex;
extern void *gYbBgOption1Ncl;
extern Unk021da104_04 *data_ov003_021da1b8;

void func_ov003_021c391c(void);
void MoveOptMenuSelection(s32 a);
void func_ov003_021c39a4(void);
void func_ov003_021c3a7c(void);
void func_ov003_021c3ac4(void);
void func_ov003_021c3ae4(void);
void func_ov003_021c3b5c(void);
void UpdateOptMenuInput(void);
void UpdateOptMenu(void);
void func_ov003_021c3c34(void);
void func_ov003_021c3c58(void);
void func_ov003_021c3c88(void);
void LoadOptMenuFilesAndSetBgCnt(void);
void SetupOptMenu(void);

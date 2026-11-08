#pragma once

#include "types.h"
#include "03/types_021d299c.h"

typedef struct Rect Rect;

typedef struct Unk021d6fd0 {
    /* 0 */ u8 mUnk_00[2];
} Unk021d6fd0;

typedef struct Unk021d6fd4 {
    /* 00 */ u8 mUnk_00[0x16];
} Unk021d6fd4;

extern Rect gJb2MenuRects[];
extern u16 data_ov003_021d6328[];
extern u16 data_ov003_021d632a[];
extern u16 data_ov003_021d632c[];
extern u16 data_ov003_021d632e[];
extern Unk021d6fd0 data_ov003_021d6fd0;
extern Unk021d6fd4 gYbBgStep11NclName;
extern u8 gJbBgStep1NcgName2[];
extern u8 gJbBgStep1NclName2[];
extern u8 gJb2MenuNscName[];
extern u8 gJb2MenuSelectedIndex;
extern void *gYbBgStep11Ncl;

// Not decompiled yet.
void func_ov003_021c2c94(void);
void MoveJb2MenuSelection(s32 a);
void func_ov003_021c2d18(void);
void func_ov003_021c2d9c(void);
void func_ov003_021c2dd4(void);
void func_ov003_021c2df4(void);
void func_ov003_021c2e3c(void);
void UpdateJb2MenuInput(void);
void UpdateJb2Menu(void);
void func_ov003_021c2f44(void);
void func_ov003_021c2f68(void);
void func_ov003_021c2f98(void);
void LoadJb2MenuFilesAndSetBgCnt(void);
void SetupJb2Menu(void);
// Not decompiled yet.

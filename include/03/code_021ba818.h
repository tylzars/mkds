#pragma once

#include "types.h"
#include "03/code_021b94b8.h"
#include "00/unk_021b5000.h"
#include "00/code_021a574c.h"
#include "00/code_021a5b3c.h"
#include "00/code_02188de4.h"

typedef s32 Unk021ba818Func();

extern u8 *data_ov003_021d8b80;
extern u32 data_ov003_021d8b84;
extern Unk021a5a78 *data_ov003_021d8b88;
extern u32 data_ov003_021d8b8c;
extern const u8 *data_ov003_021d8b90;
extern const u8 *data_ov003_021d8b94;
extern s32 data_ov003_021d8b98;
extern Unk021ba818Func *data_ov003_021d8b9c;
extern Unk021a5e84 *data_ov003_021d8ba0;
extern Unk02188de4 *data_ov003_021d8ba4;
extern u8 data_ov003_021d8ba8[6];
extern u8 data_ov003_021d8bb0[0x20];

BOOL func_ov003_021ba818(Unk021ba818Func *callback, u8 *buffer, s32 size);
BOOL func_ov003_021ba910(Unk021ba778Src *record, MelcoBlock *melcoBlock, u32 flags);
BOOL func_ov003_021ba9c0(void);
BOOL func_ov003_021baa28(void);
BOOL func_ov003_021baa68(void);
BOOL func_ov003_021baaac(const u8 *addressBytes, const u8 *essidBytes, s32 essidLength, u32 d);
s32 func_ov003_021babc0(Unk021ba778Src *records, s32 maxCount);
BOOL func_ov003_021bac0c(void);
void func_ov003_021bac90(s16 *event);

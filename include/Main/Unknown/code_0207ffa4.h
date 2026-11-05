#pragma once

#include "types.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h" // Unk02175620_bc

// Two entries of the table at CourseMap::mUnk_bc (the current one at 0x00 and the previous one at 0x04), a vector at
// 0x08, a third entry at 0x14 and a word at 0x18.
typedef struct Unk0208001c {
    /* 00 */ Unk02175620_bc *mUnk_00;
    /* 04 */ Unk02175620_bc *mUnk_04;
    /* 08 */ Vec3 mUnk_08;
    /* 14 */ Unk02175620_bc *mUnk_14;
    /* 18 */ BOOL mUnk_18;
} Unk0208001c;

#include "Main/Unknown/code_02080b1c.h"

void func_0207ffa4(Unk02080b1c *a, u32 b, Unk02080b1c_00 *c);
void func_0208001c(Unk0208001c *p, Unk02175620_bc *a);
s32 func_020800a0(Unk0208001c *p);

#pragma once

#include "types.h"

// Header of the file returned by FindCourseFile in CreateCourseMap: a word array at 0x08 holds offsets from 0x06's
// value.
typedef struct {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mBaseOffset;
    /* 08 */ s32 mSectionOffsets[1];
} Unk02042064;

extern s32 (*data_usa_0215407c[17])(void *a, ...);

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
#include "Main/Unknown/code_020b502c.h"

void CreateCourseMap(void *a);

typedef struct Unk020f41c4_B Unk020f41c4_B;

typedef struct Unk02175620_4c Unk02175620_4c;
typedef struct Unk02175620_a0 Unk02175620_a0;
typedef struct Unk020f371c Unk020f371c;

s32 func_02042170(void *a, ...);
s32 func_02042280(void *a, ...);
void func_020422c4(void);
void func_02042320(void);
void func_0204236c(void);
Unk02175620_74 *func_020423fc(u32 a);
s32 func_02042410(void *a, ...);
s32 func_02042498(void *a, ...);
s32 func_02042520(void *a, ...);
s32 func_02042558(void *a, ...);
s32 func_02042590(void *a, ...);
s32 func_02042628(void *a, ...);
s32 func_020426ac(void *a, ...);
s32 func_02042708(void *a, ...);
void func_0204274c(void);
s32 func_020427ac(void *a, ...);
void func_020427d4(Unk020f41c4_B *a);
s32 func_02042894(void *a, ...);
s32 func_02042990(void *a, ...);
u32 func_020429b8(u32 arg0);
void func_020429c8(void *a);
void func_02042a10(void *a);
void func_02042c3c(void *a);
void func_02042d34(Unk02175620_a0 *a, Unk02175620_4c *b, u16 c);
void func_02042e0c(void *a);
void func_02042ec0(Unk020f371c *a, Unk02175620_4c *b, u16 c);
unsigned int func_02042fc4(unsigned int p0);
void func_02042fd8(void *a);
void func_02043038(void);
s32 func_02043078(u16 a);
s32 func_02043108(void *a, ...);
s32 func_0204313c(void *a, ...);
s32 func_02043170(void *a, ...);
u16 func_020431a4(void **a);

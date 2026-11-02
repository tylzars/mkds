#pragma once

#include "types.h"
#include "code_02012b30.h" // Unk020136f0
#include "Main/Unknown/code_020846c0.h" // Unk02084b2c
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_020ed5c0.h" // Unk0206bcb0_590
#include "Main/Unknown/code_020799a0.h"

extern u32 data_usa_02155008[];
extern u32 data_usa_02155028[];
extern u32 data_usa_02155038[];
extern u32 data_usa_02155058[];
extern u32 data_usa_02155078[];
extern u32 data_usa_02155088[];
extern u32 data_usa_021550b8[];
extern u8 data_usa_021550c8[];
extern u8 data_usa_021550e8[];
extern u8 data_usa_02155108[];
extern u8 data_usa_02155128[];
extern u8 data_usa_02155148[];
extern u8 data_usa_02154fe8[];
extern u8 *data_usa_0217acec;

void func_020790e0(void *a, s32 b);
void LoadKartModelMenuFile(void *a, const void *b, void **c);
void func_0207916c(void *a);
void func_02079220(Unk0206bcb0_590 *a, void *b);
void func_0207926c(Unk0206bcb0_590 *a, void *b);
void func_020792c8(Unk0206bcb0_590 *a, s32 b);
void func_0207940c(Unk02084b2c *a, s32 b, void *c);
u16 *LoadKartAPaletteFromKartModelMenu(void *a);
u16 *LoadKartAPaletteFromKartModelFile(void);
void func_020794bc(Unk0206bcb0_590 *a, void *b, s32 c);
void func_0207954c(Unk0206bcb0_590 *a, void *b, s32 c);
void func_02079678(void *a, s32 b);
void func_020797d8(void *a, u32 b);

// Declared here until the code that defines them is decompiled.
#include "Main/Unknown/code_0207ae58.h"

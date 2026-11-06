#pragma once

#include "types.h"

// Declared here until the code that defines them is decompiled.

#include "code_020184e4.h"

extern Vec3 data_usa_021660fc;
extern char data_usa_02166138[];
extern char data_usa_02166148[];
extern char data_usa_02166168[];

u32 func_0208b484(u32 arg0, u32 arg1);
void *func_0208b498(u32 a, Vec3 *b, u32 c, s32 d);
void func_0208b5b0(void *a, const Vec3 *b);
Unk0201ca6c *func_0208b60c(s32 a, Vec3 *b);
void func_0208b6b0(void **p0);
void func_0208b6d0(Unk0201ca6c **a);
void func_0208b710(Unk0201ca6c *a);
// Starts effect a at the position b and returns the effect object (NULL when none is made).
void *StartEffect(u32 a, const Vec3 *b);
void func_0208b870(MtxFx43 *a);
void func_0208b8c8(void);
void func_0208b934(void *a);
u32 func_0208bd04(u32 arg0);

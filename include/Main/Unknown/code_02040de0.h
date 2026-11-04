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
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"

extern u8 data_0215406c[];
extern u8 data_0215406d[];

s32 func_02040de0(s32 a, u32 b);
struct Unk020f371c *func_02040f78(u32 a);
Unk02175620_bc *func_02040fd8(u32 a, Vec3 *b, Vec3 *c);
void *func_020410a4(u32 a, Vec3 *b, Vec3 *c);
u16 func_02041170(u32 a);
s32 func_020411e4(Vec3 *a);
Unk02175620_bc *func_020413a4(Vec3 *a);
void *func_02041588(Vec3 *a);
s32 func_0204176c(Vec3 *a, s32 *b);
s32 IsPosInCourseMapShape(Vec3 *a, CourseMapShape *b);
BOOL IsPosInCourseMapShapeBox(Vec3 *a, CourseMapShape *b);
void func_02041bb0(Vec3 *a, Vec3 *b, s32 c);
void func_02041dc8(Vec3 *a, Vec3 *b, s32 c, s32 d, s32 e);

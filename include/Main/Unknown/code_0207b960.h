#pragma once

#include "types.h"

typedef struct Unk0208fd8c_08 Unk0208fd8c_08;
typedef struct Unk0208fd8c Unk0208fd8c;

struct CourseMapCamera;
struct Unk0208fd8c;
struct Unk020888b4;
struct Unk0208fd8c_08;

// Four vectors and words at 0x30, 0x34 and 0x38.
typedef struct Unk0207b960 {
    /* 00 */ Vec3 mUnk_00[4];
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
} Unk0207b960;

struct Unk020888b4;

extern void (*data_0217ae3c)(Unk0208fd8c *a, struct Unk020888b4 *b);
extern void (*data_0217ae40)(Unk0208fd8c *a, struct Unk020888b4 *b);
extern void (*data_0217ae44)(Unk0208fd8c *a, struct Unk020888b4 *b);
extern void (*data_0217ae48)(Unk0208fd8c *a, struct Unk020888b4 *b);

typedef struct Unk0208fd8c Unk0208fd8c;

struct Unk02089a24;
struct Unk020888b4;

extern Unk0208fd8c_08 data_usa_0215524c[];
extern Unk0208fd8c_08 data_usa_021552f4[];
extern Unk0208fd8c_08 data_usa_021553cc[];
extern Unk0208fd8c_08 data_usa_021554a4[];

void func_0207b960(Vec3 *a, Unk0207b960 *b);
void func_0207bc9c(Vec3 *a, Unk0207b960 *b, struct CourseMapCamera *c, s32 d);
void func_0207bd6c(Unk0207b960 *a, struct CourseMapCamera *b);
void func_0207be40(Unk0207b960 *a, struct CourseMapCamera *b);
void func_0207becc(struct Unk0208fd8c *a, struct Unk020888b4 *b);
s32 func_0207bfac(struct Unk0208fd8c *a);
void func_0207bfd4(struct Unk0208fd8c *a, struct Unk0208fd8c_08 *b);
s32 func_0207c078(struct Unk0208fd8c *a);
void func_0207c0a0(struct Unk0208fd8c *a);
void func_0207c144(struct Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c270(struct Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c2ec(struct Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c448(Unk0208fd8c *p0);
void func_0207c47c(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c548(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c614(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c6d0(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c78c(void);
void func_0207c8d8(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c978(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207ca18(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207ca60(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207caa8(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207cb0c(Unk0208fd8c *a, struct Unk020888b4 *b);
unsigned int func_0207cb70(unsigned int p0);
void func_0207cb74(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207cc74(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207cd74(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d194(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d35c(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d3a4(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d3ec(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d474(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d4cc(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d5b8(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d6a4(struct Unk02089a24 *a, struct Unk020888b4 *b);

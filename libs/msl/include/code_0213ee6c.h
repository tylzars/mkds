#pragma once

#include "types.h"

// 0x26 bytes. Filled by func_02140c28 (which caps mUnk_04 at 32) and func_02141b5c (at most 32 bytes);
// mUnk_04 counts the bytes used in mUnk_05. Read by func_02136638, func_0213dcd4 and func_0214049c
// (func_0214049c copies it as a whole).
typedef struct Unk02136638 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ s16 mUnk_02;
    /* 04 */ u8 mUnk_04;
    /* 05 */ char mUnk_05[32];
} Unk02136638;

// First argument of func_02140c28 (reads mUnk_02).
typedef struct Unk02140c28 {
    /* 00 */ u8 mUnk_00;
    /* 02 */ s16 mUnk_02;
} Unk02140c28;

// Read as a float by func_0214049c.
extern float data_0216ec98;
// Read as a float by func_0213ee6c and nan.
extern float data_0216ec9c;

// Two doubles each, indexed 0/1 by func_0213ee6c.
extern const double data_0215d484[2];
extern const double data_0215d494[2];
extern const double data_0215d4a4[2];
// Indexed 0-7 by func_0214049c.
extern double data_0216ef30[];
// Passed by func_0214049c to func_02141b5c.
extern char data_0216ef70[];

double func_0213ee6c(double a, double b);
double copysign(double a, double b);
double fabs(double a);
double frexp(double a, int *e);
double ldexp(double a, int n);
double pow(double a, double b);
double func_0214049c(const Unk02136638 *d);
void func_02140c28(Unk02140c28 *a, double v, Unk02136638 *b);
void func_02140d74(Unk02136638 *out, double a);
void func_021410bc(Unk02136638 *out, const Unk02136638 *a, const Unk02136638 *b);
int func_02141538(const Unk02136638 *a, const Unk02136638 *b);
int func_0214166c(const Unk02136638 *a, const Unk02136638 *b);

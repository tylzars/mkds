#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct Unk0207adf8 Unk0207adf8;

extern void (*data_usa_021655e4[])(Kart *a);

void func_0207a8c4(Vec3 *a, s32 b);
void GetKartPrevPos(Vec3 *a, s32 b);
void func_0207a91c(Vec3 *a, u8 b);
void func_0207a948(Vec3 *a, s32 b);
Kart *GetKart(s32 a);
void func_0207a990(void);
void func_0207a9f4(void);
void func_0207aa7c(void);
void func_0207aaec(void);
void func_0207abec(u32 a);
void func_0207ad88(Unk0207adf8 *a, u32 b, u32 c);

void func_01ffcac0(Kart *a);

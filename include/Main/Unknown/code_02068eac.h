#pragma once

#include "types.h"

typedef struct Kart Kart;

BOOL func_02068eac(Kart *kart);
s32 func_02068ec0(Kart *kart, s32 a);
void func_02069044(Kart *kart);
void func_02069068(Kart *kart);
void AdvanceKartGesso(Kart *kart);
void StartKartGesso(Kart *kart, u32 orthoQuadCount);
void AdvanceKartKiller(Kart *kart);
void StartKartKiller(Kart *kart);
void AdvanceKartTeresa(Kart *kart);
void StartKartTeresa(Kart *kart);
void StartKartStar(Kart *kart);
void StartKartKinokoBoost(Kart *kart);
void StartKartThunder(Kart *kart);
void func_02069ea8(Kart *kart);
void func_02069f6c(Kart *kart);
BOOL func_0206a24c(Kart *kart);

#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct Kuribo Kuribo;

void UpdateKuriboState4(Kuribo *kuribo);
void EnterKuriboState5(Kuribo *kuribo);
void UpdateKuriboState5(Kuribo *kuribo);
void func_020da820(Kuribo *kuribo, Vec3 *hitVector);
u32 func_020da73c(Kuribo *kuribo, Kart *kart, u8 *b, u8 *c);
u32 func_020da684(Kuribo *kuribo, Kart *kart, u8 *b, u8 *c);
void func_020da628(Kuribo *kuribo);

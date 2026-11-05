#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct Kuribo Kuribo;

void UpdateKuriboState4(Kuribo *p);
void EnterKuriboState5(Kuribo *p);
void UpdateKuriboState5(Kuribo *p);
void func_020da820(Kuribo *p, Vec3 *a);
u32 func_020da73c(Kuribo *p, Kart *a, u8 *b, u8 *c);
u32 func_020da684(Kuribo *p, Kart *a, u8 *b, u8 *c);
void func_020da628(Kuribo *p);

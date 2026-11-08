#pragma once

#include "types.h"
#include "Main/Unknown/code_020a7000.h"
#include "Main/Unknown/code_020f36d8.h"

void CreateSanboHAndSanboB(void *a);
u8 CollideItemObjectWithSanbo(Sanbo *p, ItemObject *a, u8 *b, u8 *c);
u8 CollideKartWithSanbo(Sanbo *p, Kart *a, u8 *b, u8 *c);

#pragma once

#include "types.h"
#include "Main/Unknown/code_020e0680.h"

void UpdateChoropuState7(Unk020e1e98 *choropu);
u8 CollideKartWithChoropu(Unk020e1e98 *choropu, Kart *kart, u8 *c, u8 *d);
u8 CollideItemObjectWithChoropu(Unk020e1e98 *choropu, Unk020e246c *itemObject, u8 *c, u8 *d);

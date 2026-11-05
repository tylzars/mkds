#pragma once

#include "types.h"
#include "Main/Unknown/code_020ee684.h" // KartItems

void func_01fff434(s32 a, s32 b, s32 c, Vec3 *d, const Vec3 *e, const Vec3 *f, s64 *g);
void func_01fff524(KartItems *p);
// Per-frame step of one record: flags, the roulette, the use of the held item on the button bits, the held item, the
// course reference; early return for a kart in a special state
void UpdateKartItems(KartItems *p);

#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct ShadowModel ShadowModel;

// The functions every Kart starts with, copied into Kart.mSlotFunctions by InitKart. Slots 0, 1, 6, 7 and 8 keep these;
// slots 2 to 5 are zero here and always replaced by InitKart.
extern void (*gKartDefaultSlotFunctions[])(Kart *a);

void func_0207ad88(ShadowModel *a, u32 b, u32 c);

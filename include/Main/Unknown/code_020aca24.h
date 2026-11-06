#pragma once

#include "types.h"

typedef struct Unk020aca24 {
    /* 00 */ u8 pad_00[4];
    /* 04 */ u16 mNextScene;
} Unk020aca24;

void UpdateTitleState5(Unk020aca24 *a);

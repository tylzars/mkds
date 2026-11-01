#pragma once

#include "types.h"

typedef struct Unk020882fc_08 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk020882fc_08;

typedef struct Unk020882fc {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Unk020882fc_08 *mUnk_08;
} Unk020882fc;

unsigned int func_020882fc(Unk020882fc *p0);
unsigned int func_02088308(Unk020882fc *p0);
unsigned int func_02088314(Unk020882fc *p0);
unsigned int func_02088320(Unk020882fc *p0);
unsigned int func_0208832c(Unk020882fc *p0);

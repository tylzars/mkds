#pragma once

#include "types.h"
#include "03/unk_021d8000.h"

// Five, thirteen and sixteen bytes moved as one value.
typedef struct Unk021bd338_5 {
    /* 0 */ u8 mUnk_00[5];
} Unk021bd338_5;

typedef struct Unk021bd338_13 {
    /* 0 */ u8 mUnk_00[13];
} Unk021bd338_13;

typedef struct Unk021bd338_16 {
    /* 0 */ u8 mUnk_00[16];
} Unk021bd338_16;

s32 func_ov003_021bcf1c(void);
s32 func_ov003_021bd338(void);
BOOL func_ov003_021bd4cc(u8 *a, const s8 *b, s32 c);
s32 func_ov003_021bd59c(u8 *p);
s32 func_ov003_021bd768(u8 *a, void *b);

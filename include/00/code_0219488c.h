#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

// Argument block of the search of func_ov000_021948bc.
typedef struct Unk0219488cArg {
    /* 00 */ const char *mUnk_00;
    /* 04 */ const char *mUnk_04;
    /* 08 */ void **mUnk_08;
    /* 0c */ BOOL mUnk_0c;
} Unk0219488cArg;

s32 func_ov000_0219488c(GpConnection *a, const char *b, const char *c, void **d);

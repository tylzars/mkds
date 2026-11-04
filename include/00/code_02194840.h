#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

// Argument block of the walk over the list at 0x428: the object, the function to call and its argument.
typedef struct Unk02194840Arg {
    /* 00 */ GpConnection *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
} Unk02194840Arg;

BOOL GpiForEachProfileWhileNonZero(GpConnection *a, void *b, void *c);

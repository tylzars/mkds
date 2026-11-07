#pragma once

#include "types.h"

// The registers at 0x04000280-0x040002bf: divider operands, square root operand and the two mode halfwords.
typedef struct CPContext {
    /* 00 */ u64 mDivNumer;
    /* 08 */ u64 mDivDenom;
    /* 10 */ u64 mSqrt;
    /* 18 */ u16 mDivMode;
    /* 1a */ u16 mSqrtMode;
} CPContext;

void CPi_RestoreContext(const CPContext *context);
void CP_SaveContext(CPContext *context);

#pragma once

#include "types.h"

// Words and halfwords that DivSqrtRegistersSave reads from, and DivSqrtRegistersRestore writes to,
// 0x04000280-0x040002bf.
typedef struct DivSqrtRegisters {
    /* 00 */ u64 mDivNumer;
    /* 08 */ u64 mDivDenom;
    /* 10 */ u64 mSqrtParam;
    /* 18 */ u16 mDivCnt;
    /* 1a */ u16 mSqrtCnt;
} DivSqrtRegisters;

void DivSqrtRegistersRestore(const DivSqrtRegisters *a);
void DivSqrtRegistersSave(DivSqrtRegisters *a);

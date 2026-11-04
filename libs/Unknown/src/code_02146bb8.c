#include "code_02146bb8.h"
#include "registers.h"

void DivSqrtRegistersSave(DivSqrtRegisters *a) {
    a->mDivNumer = reg_CP_DIV_NUMER;
    a->mDivDenom = reg_CP_DIV_DENOM;
    a->mDivCnt = reg_CP_DIVCNT & 3;
    a->mSqrtParam = reg_CP_SQRT_PARAM;
    a->mSqrtCnt = reg_CP_SQRTCNT & 1;
}

void DivSqrtRegistersRestore(const DivSqrtRegisters *a) {
    reg_CP_DIV_NUMER = a->mDivNumer;
    reg_CP_DIV_DENOM = a->mDivDenom;
    reg_CP_DIVCNT = a->mDivCnt;
    reg_CP_SQRT_PARAM = a->mSqrtParam;
    reg_CP_SQRTCNT = a->mSqrtCnt;
}

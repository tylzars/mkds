#include "code_02146bb8.h"
#include "registers.h"

// Reads the divider and square root registers into the context.
void CP_SaveContext(CPContext *context) {
    context->mDivNumer = reg_CP_DIV_NUMER;
    context->mDivDenom = reg_CP_DIV_DENOM;
    context->mDivMode = reg_CP_DIVCNT & 3;
    context->mSqrt = reg_CP_SQRT_PARAM;
    context->mSqrtMode = reg_CP_SQRTCNT & 1;
}

// Writes the context back to the divider and square root registers.
void CPi_RestoreContext(const CPContext *context) {
    reg_CP_DIV_NUMER = context->mDivNumer;
    reg_CP_DIV_DENOM = context->mDivDenom;
    reg_CP_DIVCNT = context->mDivMode;
    reg_CP_SQRT_PARAM = context->mSqrt;
    reg_CP_SQRTCNT = context->mSqrtMode;
}

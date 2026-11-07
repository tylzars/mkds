#include "Main/Unknown/code_020ca69c.h"

#include "Main/Unknown/code_020ca6a8.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020ca6b8.h"

#pragma thumb on
void ClearEmblemChoisesPointer(void) {
    u32 value0;
    u32 zero;
    zero = 0u;
    value0 = (u32) &gEmblemChoises;
    *(u32 *) ((value0) + 0u) = zero;
}
#pragma thumb off

#pragma thumb on
void RequestEmblemChoisesGraphicsUpload(void) {
    gEmblemChoises->mUnk_08 = TRUE;
}
#pragma thumb off

#pragma thumb on

u32 GetEmblemChoisesResult(void) {
    return (gEmblemChoises->mUnk_1c);
}

#pragma thumb off

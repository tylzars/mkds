#include "Main/Unknown/code_0205a50c.h"
#include "Main/Unknown/unk_0217a000.h"

s32 func_0205a50c(s32 a) {
    BOOL r;

    r = TRUE;
    if (!(data_0217aa14->mUnk_749 & (1 << a))) {
        r = FALSE;
    }
    return r;
}

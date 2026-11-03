#include "00/code_0219488c.h"
#include "00/code_02194840.h"
#include "00/code_021948bc.h"

s32 func_ov000_0219488c(GpConnection *a, const char *b, const char *c, void **d) {
    Unk0219488cArg e;

    e.mUnk_00 = b;
    e.mUnk_04 = c;
    e.mUnk_08 = d;
    e.mUnk_0c = 0;
    func_ov000_02194840(a, func_ov000_021948bc, &e);
    if (e.mUnk_0c == 0) {
        *d = NULL;
    }
    return 0;
}

#include "00/code_02194840.h"
#include "00/code_02194874.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dd8c.h"

s32 func_ov000_02194840(Unk0218f960 *a, void *b, void *c) {
    Unk0218f960_00 *r;
    Unk02194840Arg d;

    r = a->mUnk_00;
    d.mUnk_00 = a;
    d.mUnk_04 = b;
    d.mUnk_08 = c;
    if (func_ov000_0218dd8c(r->mUnk_428.mUnk_00, (int) func_ov000_02194874, (u32) &d) == 0) {
        return 1;
    }
    return 0;
}

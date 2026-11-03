#include "00/code_02188ec0.h"
#include "00/code_0218a130.h"
#include "00/code_02187484.h"
#include "00/code_021874c0.h"
#include "00/code_02188000.h"
#include "00/code_021884d8.h"
#include "00/unk_021b4000.h"
#include "00/code_021884fc.h"
#include "00/code_02189350.h"

u32 func_ov000_0218a130(Unk02188ec0 *v1) {
    Unk02189350 *p;
    u32 s;

    p = (Unk02189350 *) func_ov000_02188584(1);
    s = func_ov000_021874c0();
    if (s != 0) {
        if (p->mUnk_15 == func_ov000_021884d8(v1->mUnk_d0d)) {
            p->mUnk_10 = func_ov000_02187484();
        }
        func_ov000_02188068();
        if (s != 0xb) {
            v1->mUnk_444[v1->mUnk_d13].mUnk_00 = 1;
            return 0xb;
        }
        return 0xf;
    }
    return 0xe;
}

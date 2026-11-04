#include "00/code_0218a064.h"
#include "00/code_021884d8.h"
#include "00/code_021898dc.h"
#include "00/code_0218a018.h"
#include "00/unk_021b0000.h"
#include "code_0214d018.h"

void func_ov000_0218a064(const u32 *a, Unk02188ec0 *v1, Unk0218a064 *v2) {
    Unk02188db0 *e;

    MemCopy(data_ov000_021b0738, v2, 0x58);
    v2->mUnk_04 = a[0];
    v2->mUnk_08 = a[1];
    if (v1->mUnk_d0d < 6) {
        e = &v1->mUnk_000[func_ov000_021884d8(v1->mUnk_d0d)];
        if (e->mUnk_c0[0] != 0) {
            v2->mUnk_0c = 0;
            v2->mUnk_10 = func_ov000_0218a018(e->mUnk_c0);
            v2->mUnk_14 = func_ov000_02189fd0(e->mUnk_d0);
            v2->mUnk_18 = func_ov000_0218a018(e->mUnk_c4);
            v2->mUnk_1c = func_ov000_0218a018(e->mUnk_c8);
            v2->mUnk_20 = func_ov000_0218a018(e->mUnk_cc);
        } else {
            v2->mUnk_0c = 1;
            v2->mUnk_10 = 0;
            v2->mUnk_14 = 0;
            v2->mUnk_18 = 0;
            v2->mUnk_1c = 0;
            v2->mUnk_20 = 0;
        }
    }
}

#include "00/code_0218973c.h"
#include "00/code_021894e4.h"
#include "00/code_021898dc.h"
#include "00/unk_021b4000.h"
#include "00/code_021884fc.h"
#include "00/code_02188ee0.h"
#include "00/unk_021b0000.h"
#include "code_0214d018.h"

void func_ov000_02189868(const u8 *a, const u8 *b, s32 c, u32 d) {
    if (c > 12) {
        c = 12;
    }
    func_ov000_021a61c4(a, b, d | data_ov000_021b0704[c]);
}

u32 func_ov000_021897bc(void) {
    Unk02188ec0 *v1;
    u32 r;

    v1 = (Unk02188ec0 *) func_ov000_02188584(0x10);
    r = 9;
    switch (func_ov000_021a5bfc()) {
        case 3:
            r = v1->mUnk_d0e;
            if (v1->mUnk_d0c_6 == 1) {
                v1->mUnk_444[v1->mUnk_d13].mUnk_00 = 0;
                r = 7;
            } else if (r >= 3 && r <= 5) {
                func_ov000_02189d2c(r);
            }
            break;
        case 6:
            func_ov000_021a6024();
            break;
        case 9:
            func_ov000_021a5db0();
            break;
        case 12:
            func_ov000_021a5c24();
            func_ov000_02188508(4);
            r = 0x11;
            break;
        case 11:
            func_ov000_02188508(0);
            r = 0x11;
            break;
    }
    return r;
}

u8 func_ov000_0218973c(u32 a) {
    Unk02188ec0 *v1;
    volatile u32 z;

    v1 = (Unk02188ec0 *) func_ov000_02188584(0x10);
    z = 0;
    MemFillWords(z, v1->mUnk_300, 0x144);
    switch (a) {
        case 0:
            v1->mUnk_d10 = func_ov000_021896c4(v1);
            break;
        case 1:
            v1->mUnk_d10 = func_ov000_021894e4(v1->mUnk_d12, v1->mUnk_444, v1->mUnk_300, v1->mUnk_470);
            break;
        case 2:
            v1->mUnk_d10 = func_ov000_02189614(v1);
            break;
    }
    return v1->mUnk_d10;
}

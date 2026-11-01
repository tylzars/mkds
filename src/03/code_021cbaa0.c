#include "03/code_021cbaa0.h"
#include "00/code_02188694.h"
#include "00/code_02188720.h"
#include "03/code_021c20dc.h"
#include "03/code_021cb8f0.h"
#include "03/code_021cdb14.h"
#include "03/code_021d3544.h"
#include "code_0200fd1c.h"
#include "code_0214d018.h"

void func_ov003_021cbaa0(void) {
    s32 a;
    Unk02188868 b;
    int c = func_ov003_021cdb6c();
    func_0214d02c(data_ov003_021d6620, &b, 0xc);
    func_ov003_021c20dc(0, &a);
    if (a == 2) {
        b.mUnk_0a = 4;
    } else {
        b.mUnk_0a = *(u8 *) (c + 0xf4) + 1;
    }
    if (func_ov000_02188868(&b) == 0) {
        func_0200fd1c();
    }
    if (a == 0) {
        func_ov000_021886fc(*(u8 *) (c + 0xf4), c);
    }
    func_ov003_021d3544(0, func_ov003_021cb8f0, 0, 0x78);
}

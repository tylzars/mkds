#include "00/code_0219c9d8.h"
#include "00/code_0219c000.h"
#include "00/code_0219c39c.h"
#include "00/code_0219c400.h"
#include "00/code_0219c93c.h"
#include "00/code_0219c0f4.h"
#include "00/code_0219c79c.h"
#include "code_0200f5ac.h"

void func_ov000_0219c9d8(void) {
    Unk021b565c *p;
    if (data_ov000_021b565c == 0 || func_ov000_0219c39c() != 0) {
        return;
    }
    p = data_ov000_021b565c;
    switch (p->mUnk_04) {
        case 1:
            func_ov000_0219c524();
            break;
        case 2:
        case 3:
        case 4:
            if (p->mUnk_00 != 0 && p->mUnk_00->mUnk_00 != 0) {
                func_ov000_0218f268(p->mUnk_00);
            }
            if (data_ov000_021b565c->mUnk_34 != 0) {
                if ((((u64) func_0200f5ac() - data_ov000_021b565c->mUnk_38) << 6) / 0x82ea > 0xea60) {
                    func_ov000_0219c990(6, -61070);
                    data_ov000_021b565c->mUnk_34 = 0;
                }
            }
            break;
        case 5:
            break;
    }
}

void func_ov000_0219ca84(void) {
    func_ov000_0219c67c(func_ov000_0219c80c, 0);
    data_ov000_021b565c->mUnk_04 = 1;
    data_ov000_021b565c->mUnk_34 = 0;
}

#include "00/code_0219c954.h"
#include "00/code_02185984.h"
#include "00/unk_021b5000.h"
#include "03/code_021b94b8.h"
#include "00/code_021a369c.h"

#include "00/code_0219c384.h"
#include "00/code_0219c000.h"
#include "00/code_0219c39c.h"
#include "00/code_0219c93c.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200f5ac.h"
#include "code_02139f70.h"
#include "00/code_0219c3e4.h"
#include "00/code_02198a8c.h"
#include "00/code_0218f15c.h"
#include "00/code_0219b580.h"

void func_ov000_0219ca84(void) {
    func_ov000_0219c67c(func_ov000_0219c80c, NULL);
    data_ov000_021b565c->mUnk_04 = 1;
    data_ov000_021b565c->mUnk_34 = 0;
}

void func_ov000_0219c9d8(void) {
    Unk021b565c *p;
    if (data_ov000_021b565c == NULL || func_ov000_0219c39c() != 0) {
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
            if (p->mUnk_00 != NULL && p->mUnk_00->mGpiConnection != NULL) {
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

Unk02152500 *func_ov000_0219c9c4(void) {
    if (data_ov000_021b565c != NULL) {
        return data_ov000_021b565c->mUnk_20;
    }
    return NULL;
}

void func_ov000_0219c990(s32 a, s32 b) {
    if (data_ov000_021b565c != NULL && a != 0) {
        func_ov000_0219c384(a, b);
        if (data_ov000_021b565c->mUnk_18 != NULL) {
            data_ov000_021b565c->mUnk_18(a, 0, data_ov000_021b565c->mUnk_1c);
        }
        func_ov000_0219c93c();
    }
}

void func_ov000_0219c954(void) {
    if (data_ov000_021b565c->mUnk_28 != NULL) {
        func_ov000_02186474();
        func_ov000_02186430();
        func_ov000_021a3704((u32) 0, (u32) ((u32) data_ov000_021b565c->mUnk_28), (u32) 0);
        data_ov000_021b565c->mUnk_28 = NULL;
    }
    *(s32 *) &data_ov000_021b565c = 0;
}

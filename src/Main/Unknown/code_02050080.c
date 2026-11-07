#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"

#pragma opt_rebuildconditionals off

static inline u32 func_02050080_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

u32 func_020501b0(u32 a) {
    u32 r = 0;
    Unk0217aa00_0ac *e;
    Unk0217aa00 *q;
    u32 b;

    if (a >= 4) {
        return 0;
    }
    if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
        b = r;
        if (func_02050080_inline() != 2) {
            b = 0;
        } else if (*(u16 *) 0x027ffc40 == 2) {
            b = 0;
        } else if (data_0217aa00->mUnk_00ac[a].mUnk_dc_0 != 0) {
            b = 1;
        }
        if (b != 0) {
            StartRequestEndScan();
            r = 1;
        }
    } else {
        data_0217aa00->mUnk_043b = 0;
        data_0217aa00->mUnk_0438 = 0;
        e = &data_0217aa00->mUnk_00ac[a];
        data_0217aa00->mUnk_0436 &= ~1;
        if (e->mUnk_dc_0 != 0) {
            MI_CpuCopy8(e, data_0217aa00->mUnk_0024, 0xc0);
            DC_StoreRange(data_0217aa00->mUnk_0024, 0xc0);
            q = data_0217aa00;
            *(Unk0217aa00_42c *) &q->mUnk_042c = e->mUnk_c0_42c;
            q->mUnk_043c = e->mUnk_dc_1;
            r = 1;
        }
    }
    return r;
}

void func_02050080(void) {
    BOOL r;
    u16 i;
    u16 n;

    r = FALSE;
    if (func_02050080_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = TRUE;
    }
    if (r == FALSE) {
        return;
    }
    i = 0;
    n = 0;
    for (; i < 8; i++) {
        if ((data_0217aa00->mUnk_15f6 & (1 << i)) != 0) {
            data_0217aa00->mUnk_1e52[i].mUnk_00 = n;
            data_0217aa00->mUnk_1e8c[n] = i;
            data_0217aa00->mUnk_1e9c[n] = i;
            n++;
        } else {
            data_0217aa00->mUnk_1e52[i].mUnk_00 = 0xffff;
        }
    }
    for (; n < 8; n++) {
        data_0217aa00->mUnk_1e8c[n] = 0xffff;
        data_0217aa00->mUnk_1e9c[n] = 0xffff;
    }
    if (GetCurrentSceneNumber() == 2) {
        func_020431e4();
    } else {
        func_02043410();
    }
}

#include "03/code_021d197c.h"
#include "03/code_021d1970.h"
#include "03/unk_021da000.h"
#include "03/code_021d1c18.h"
#include "03/code_021d1cd4.h"
#include "03/code_021d1d4c.h"
#include "03/code_021d1d60.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2e50.h"
#include "03/code_021d2e68.h"
#include "03/code_021d2eb8.h"
#include "03/code_021d2ecc.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"

Unk021d1770 *func_ov003_021d1be4(u32 b, u32 c, s32 d) {
    Unk021d1770 *a = func_ov003_021d19e0(b, data_ov003_021da2b8[b][c].mUnk_00, d);

    func_ov003_021d1c3c(b, c, func_ov003_021d1974(a, 0));
    return a;
}

void func_ov003_021d1b3c(void) {
    s32 i;

    data_ov003_021da2b4 = AllocZeroedExpHeapBlock(0x450, 4);
    for (i = 0; i < 2; i++) {
        data_ov003_021da2b4[i].mUnk_224 = func_ov003_021d1d60(0x20, &data_ov003_021da2b4[i], 0x10);
        data_ov003_021da2b4[i].mUnk_220 = func_ov003_021d2ecc();
        data_ov003_021da2b4[i].mUnk_200.mUnk_08 = func_ov003_021d2eec(i, 0x40);
        data_ov003_021da2b4[i].mUnk_210.mUnk_08 = func_ov003_021d2eec(i, 0x7f) + 1;
        func_ov003_021d2e50(data_ov003_021da2b4[i].mUnk_220, &data_ov003_021da2b4[i].mUnk_200);
        func_ov003_021d2e5c(data_ov003_021da2b4[i].mUnk_220, &data_ov003_021da2b4[i].mUnk_210);
    }
}

void func_ov003_021d1af0(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        func_ov003_021d2eb8(data_ov003_021da2b4[i].mUnk_220);
        func_ov003_021d1d4c(data_ov003_021da2b4[i].mUnk_224);
    }
    FreeExpHeapBlockAndClearPointer(&data_ov003_021da2b4);
}

Unk021d1770 *func_ov003_021d19e0(u32 f, s32 g, s32 h) {
    Unk021d1770 *a;
    u32 b;
    Unk021d1770 *c;
    Unk021d1770 *d;
    Unk021d1770_08 *e;

    a = func_ov003_021d1cd4(data_ov003_021da2b4[f].mUnk_224);
    b = OS_DisableIrqMask(1);
    if (h != 0) {
        c = &data_ov003_021da2b4[f].mUnk_200;
        if (c != &data_ov003_021da2b4[f].mUnk_210) {
            do {
                d = c->mUnk_04;
                e = c->mUnk_08 + c->mUnk_0c;
                if (e + g <= d->mUnk_08) {
                    a->mUnk_08 = e;
                    AddNodeBefore((u32) d, (u32) a);
                    break;
                }
                c = d;
            } while (c != &data_ov003_021da2b4[f].mUnk_210);
        }
        if (c == &data_ov003_021da2b4[f].mUnk_210) {
            OS_Terminate();
        }
    } else {
        c = &data_ov003_021da2b4[f].mUnk_210;
        if (c != &data_ov003_021da2b4[f].mUnk_200) {
            do {
                d = c->mUnk_00;
                e = c->mUnk_08 - g;
                if (e >= d->mUnk_08 + d->mUnk_0c) {
                    a->mUnk_08 = e;
                    AddNodeBefore((u32) c, (u32) a);
                    break;
                }
                c = d;
            } while (c != &data_ov003_021da2b4[f].mUnk_200);
        }
        if (c == &data_ov003_021da2b4[f].mUnk_200) {
            OS_Terminate();
        }
    }
    OS_EnableIrqMask(b);
    a->mUnk_0c = g;
    return a;
}

void func_ov003_021d197c(Unk021d1770 *b) {
    Unk021d1770_08 *a = b->mUnk_08;
    u32 k = 0;
    s32 i;

    for (i = 0; i < b->mUnk_0c; i++, a++) {
        a->mUnk_00 = (a->mUnk_00 & 0xc1fffcff) | 0x200;
    }
    RemoveNodeFromList((u32) b);
    if (b >= (Unk021d1770 *) &data_ov003_021da2b4[1]) {
        k = 1;
    }
    func_ov003_021d1d0c(data_ov003_021da2b4[k].mUnk_224, b);
}

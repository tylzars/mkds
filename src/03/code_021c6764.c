#include "03/code_021c6764.h"
#include "03/code_021cef90.h"
#include "03/types_021d299c.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/code_021bf410.h"
#include "03/code_021c209c.h"
#include "03/code_021c6a18.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd2e0.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021ce000.h"
#include "03/code_021cea3c.h"
#include "03/code_021d3254.h"

void func_ov003_021c696c(void) {
    Unk021d299c b = {0, 0, 0, 0};
    u16 c[2];
    int k;
    int i;
    u8 t;
    b.mUnk_02 = data_ov003_021d63e0[0];
    b.mUnk_04 = data_ov003_021d63e4[0];
    b.mUnk_06 = data_ov003_021d63e4[1];
    func_ov003_021d2060(data_ov003_021da1f8->mUnk_00, 0);
    c[1] = 0;
    i = 0;
    k = i;
    t = data_ov003_021d63e0[1];
    for (; i < 0x20; i++, k++) {
        Unk021da1f8 *s;
        if (i == 0x10) {
            b.mUnk_02 = t;
            k = 0;
        }
        s = data_ov003_021da1f8;
        if (s->mUnk_08[i] == 0x20) {
            c[0] = 0xe01d;
        } else {
            c[0] = s->mUnk_08[i];
        }
        b.mUnk_00 = data_ov003_021d63e8[k];
        func_ov003_021d2070(s->mUnk_00, b.mUnk_00, b.mUnk_02, b.mUnk_04, b.mUnk_06, 2, 0x480, c);
    }
    func_ov003_021d1fd0(data_ov003_021da1f8->mUnk_00);
}

void func_ov003_021c6914(void) {
    int v1;
    int v2;
    u8 a;
    Unk021da1f8 *s;
    s = data_ov003_021da1f8;
    a = s->mUnk_29;
    v1 = a & 0xf;
    v2 = a >> 4;
    if (a >= 0x20u) {
        v1 = 0xf;
        v2 = 1;
    }
    s->mUnk_04->mUnk_00 = ((data_ov003_021d63e8[v1] & 0x1ff) << 16) |
                          ((s->mUnk_04->mUnk_00 & 0xfe00ff00) | (data_ov003_021d63e0[v2] & 0xff));
}

void func_ov003_021c68c8(void) {
    data_ov003_021da1f8->mUnk_2a = func_ov003_021cef80();
    switch (data_ov003_021da1f8->mUnk_2a) {
        case 0:
            func_ov003_021cdc10(7);
            break;
        case 1:
            func_ov003_021cdc10(0xe);
            break;
        default:
            return;
    }
    func_ov003_021cef90();
    func_ov003_021c212c(func_ov003_021c6854);
}

void func_ov003_021c6854(void) {
    void (*a[2])(const u8 *) = {func_ov003_021cdb14, func_ov003_021cd9dc};
    s32 b;
    if (func_ov003_021cef6c() == 0) {
        if (data_ov003_021da1f8->mUnk_2a == 0) {
            data_ov003_021da1f8->mUnk_04->mUnk_00 = data_ov003_021da1f8->mUnk_04->mUnk_00 & 0xc1fffcff;
            func_ov003_021c212c(func_ov003_021c6d0c);
            return;
        }
        func_ov003_021c20dc(&b, NULL);
        a[b](data_ov003_021da1f8->mUnk_08);
        func_ov003_021c212c(func_ov003_021c6a18);
    }
}

BOOL func_ov003_021c6764(void) {
    s32 a;
    s32 b;
    int v1;
    int i;
    func_ov003_021c20dc(&a, &b);
    if (b == 1) {
        func_ov003_021bf43c(0x81, -1, 0);
    }
    func_ov003_021c20dc(&a, &b);
    if (a == 0) {
        if (data_ov003_021da1f8->mUnk_08[0] != 0) {
            return TRUE;
        }
        return FALSE;
    }
    if (b == 1 && data_ov003_021da1f8->mUnk_08[0] == 0) {
        return FALSE;
    }
    v1 = func_ov003_021d3254(data_ov003_021da1f8->mUnk_08, 0x20);
    switch (v1) {
        case 0:
        case 5:
        case 0xd:
        case 0x10:
            return TRUE;
        case 0xa:
        case 0x1a:
        case 0x20:
            for (i = 0; i < v1; i++) {
                u8 c = data_ov003_021da1f8->mUnk_08[i];
                if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))) {
                    return FALSE;
                }
            }
            return TRUE;
        default:
            return FALSE;
    }
}

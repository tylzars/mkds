#include "00/code_02196960.h"
#include "00/code_021971ec.h"
#include "00/code_0218da04.h"

void func_ov000_02196960(void) {
    s32 i;
    Unk02196960Key k;

    if (data_ov000_021b4e5c != 0) {
        for (i = func_ov000_0218dc44(data_ov000_021b4e5c) - 1; i >= 0; i--) {
            k = data_ov000_021b3b78;
            data_ov000_021b3b30 = data_ov000_021b3b98;
            func_ov000_021971ec((s8 *) k.mUnk_00, 0xf);
            func_ov000_021969d8(i, 0, 0, k.mUnk_00, 0);
        }
        func_ov000_0218dc48(data_ov000_021b4e5c);
        data_ov000_021b4e5c = 0;
    }
}

void func_ov000_021969d8(s32 a, s32 b, s32 c, const u8 *d, s32 e) {
    Unk021969d8Entry *p;

    if (a >= 0 && a < func_ov000_0218dc44(data_ov000_021b4e5c)) {
        p = func_ov000_0218dbf8(data_ov000_021b4e5c, a);
        if (p->mUnk_18.mUnk_00 != 0) {
            switch (p->mUnk_00) {
                case 0:
                    p->mUnk_18.mUnk_00(p->mUnk_04, p->mUnk_08, b, d, p->mUnk_14);
                    break;
                case 1:
                    p->mUnk_18.mUnk_01(p->mUnk_04, p->mUnk_08, p->mUnk_0c, p->mUnk_10, b, c, d, e, p->mUnk_14);
                    break;
                case 2:
                    p->mUnk_18.mUnk_02(p->mUnk_04, p->mUnk_08, p->mUnk_0c, p->mUnk_10, b, c, p->mUnk_14);
                    break;
                case 3:
                    p->mUnk_18.mUnk_03(p->mUnk_04, p->mUnk_08, b, p->mUnk_14);
                    break;
            }
        }
        func_ov000_0218da5c(data_ov000_021b4e5c, a);
    }
}

s32 func_ov000_02196a84(u8 *a, s32 b) {
    u8 *p;
    s32 c;
    s32 n;

    c = b;
    p = (u8 *) func_ov000_02196df0((const s8 *) a, b);
    while (b > 0 && p != 0) {
        data_ov000_021b3b30 = data_ov000_021b3b88;
        n = p - a;
        func_ov000_021971ec((s8 *) a, n);
        func_ov000_02196ae0(a, n);
        b = b - (n + 7);
        a = p + 7;
        if (b > 0) {
            p = (u8 *) func_ov000_02196df0((const s8 *) a, b);
        }
    }
    return c - b;
}

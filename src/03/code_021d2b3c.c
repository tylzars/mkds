#include "03/code_021d2b3c.h"
#include "03/code_021d250c.h"
#include "03/types_021d299c.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_0214e6d4.h"
#include "code_02147cd8.h"
#include "code_0214e308.h"

void func_ov003_021d2b3c(void) {
    u8 b;
    u32 a;
    u32 c;
    s32 i;
    u16 d[4];
    Unk021da2d4Input *g;

    if (data_ov003_021da2d4->mBits.mBit_0 != 0) {
        a = 1;
    } else {
        a = 0;
    }
    b = 0;
    c = func_0214e6d4();
    g = data_ov003_021da2d4;
    g->mUnk_2c = g->mUnk_28;
    g->mUnk_2e = g->mUnk_2a;
    i = 0;
    do {
        Unk0214e788 *e = &data_ov003_021da2d4->mUnk_00[c];

        if (e->mUnk_04 == 1 && e->mUnk_06 == 0) {
            b = 1;
            func_0214e334((Unk0214e334 *) d, (Unk0214e334_b *) e);
            func_ov003_021d2544(d[0], d[1], &data_ov003_021da2d4->mUnk_28);
            break;
        }
        i++;
        c = func_02147cd8(c + 4, 5);
    } while (i < 4);
    c = b ^ a;
    data_ov003_021da2d4->mBits.mBit_1 = b & c;
    data_ov003_021da2d4->mBits.mBit_3 = a & c;
    data_ov003_021da2d4->mBits.mBit_0 = b;
    data_ov003_021da2d4->mBits.mBit_2 = data_ov003_021da2d4->mBits.mBit_1;
    if (b == 0) {
        data_ov003_021da2d0 = 0;
        return;
    }
    data_ov003_021da2d0++;
    if (data_ov003_021da2d0 == 0x28) {
        data_ov003_021da2d4->mBits.mBit_2 = 1;
    } else if (data_ov003_021da2d0 == 0x2f) {
        data_ov003_021da2d4->mBits.mBit_2 = 1;
        data_ov003_021da2d0 = 0x28;
    }
}

void func_ov003_021d2c78(void) {
    Unk021da2d4Input *a = data_ov003_021da2d4;
    u16 b = ((*(u16 *) 0x4000130 | *(u16 *) 0x27fffa8) ^ 0x2fff) & 0x2fff;
    s32 i;
    u16 c;

    a->mUnk_32 = b & (b ^ a->mUnk_30);
    data_ov003_021da2d4->mUnk_36 = a->mUnk_30 & (b ^ a->mUnk_30);
    data_ov003_021da2d4->mUnk_30 = b;
    data_ov003_021da2d4->mUnk_34 = data_ov003_021da2d4->mUnk_32;
    for (i = 0; i < 14; i++) {
        c = 1 << i;
        if ((b & c) == 0) {
            data_ov003_021da2d8[i] = 0;
        } else {
            data_ov003_021da2d8[i]++;
            if (data_ov003_021da2d8[i] == 0x28) {
                data_ov003_021da2d4->mUnk_34 |= c;
            } else if (data_ov003_021da2d8[i] == 0x2f) {
                data_ov003_021da2d4->mUnk_34 |= c;
                data_ov003_021da2d8[i] = 0x28;
            }
        }
    }
}

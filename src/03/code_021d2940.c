#include "03/code_021d2940.h"

#include "03/unk_021da000.h"
#include "03/code_021d250c.h"
#include "03/types_021d299c.h"
#include "tp.h"
#include "code_02147cd8.h"
#include "03/code_021d2c78.h"
#include "03/code_021d27d8.h"

void func_ov003_021d2d28(void) {
    do {
        TP_RequestAutoSamplingStopAsync();
        TP_WaitBusy(4);
    } while (TP_CheckError(4) != 0);
    func_ov003_021d2808(&data_ov003_021da2d4);
}

void func_ov003_021d2d14(void) {
    func_ov003_021d2c78();
    func_ov003_021d2b3c();
}

void func_ov003_021d2c78(void) {
    KeyTouchInput *a = data_ov003_021da2d4;
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

void func_ov003_021d2b3c(void) {
    u8 b;
    u32 a;
    u32 c;
    s32 i;
    TPData d;
    KeyTouchInput *g;

    if (data_ov003_021da2d4->mBits.mBit_0 != 0) {
        a = 1;
    } else {
        a = 0;
    }
    b = 0;
    c = TP_GetLatestIndexInAuto();
    g = data_ov003_021da2d4;
    g->mUnk_2c = g->mUnk_28;
    g->mUnk_2e = g->mUnk_2a;
    i = 0;
    do {
        TPData *e = &data_ov003_021da2d4->mUnk_00[c];

        if (e->mTouch == 1 && e->mValidity == 0) {
            b = 1;
            TP_GetCalibratedPoint(&d, e);
            func_ov003_021d2544(d.mX, d.mY, &data_ov003_021da2d4->mUnk_28);
            break;
        }
        i++;
        c = FX_ModS32(c + 4, 5);
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

u32 func_ov003_021d2b20(u32 a) {
    if (a == (a & data_ov003_021da2d4->mUnk_30)) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021d2b04(u32 a) {
    if (a == (a & data_ov003_021da2d4->mUnk_32)) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021d2ae8(u32 a) {
    if (a == (a & data_ov003_021da2d4->mUnk_34)) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021d2acc(u32 a) {
    if (a == (a & data_ov003_021da2d4->mUnk_36)) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021d2a80(const Rect *v1) {
    KeyTouchInput *v2 = data_ov003_021da2d4;
    if (v2->mBits.mBit_0 == 0) {
        return 0;
    }
    if (v1->mUnk_00 > v2->mUnk_28) {
        return 0;
    }
    if (v1->mUnk_04 < v2->mUnk_28) {
        return 0;
    }
    if (v1->mUnk_02 > v2->mUnk_2a) {
        return 0;
    }
    if (v1->mUnk_06 >= v2->mUnk_2a) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021d2a34(const Rect *rect) {
    KeyTouchInput *input = data_ov003_021da2d4;
    if ((((u32) input->mUnk_38 << 30) >> 31) == 0) {
        return 0;
    }
    if (rect->mUnk_00 > input->mUnk_28) {
        return 0;
    }
    if (rect->mUnk_04 < input->mUnk_28) {
        return 0;
    }
    if (rect->mUnk_02 > input->mUnk_2a) {
        return 0;
    }
    if (rect->mUnk_06 >= input->mUnk_2a) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021d29e8(const Rect *rect) {
    KeyTouchInput *input = data_ov003_021da2d4;
    if ((((u32) input->mUnk_38 << 29) >> 31) == 0) {
        return 0;
    }
    if (rect->mUnk_00 > input->mUnk_28) {
        return 0;
    }
    if (rect->mUnk_04 < input->mUnk_28) {
        return 0;
    }
    if (rect->mUnk_02 > input->mUnk_2a) {
        return 0;
    }
    if (rect->mUnk_06 >= input->mUnk_2a) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021d299c(const Rect *rect) {
    KeyTouchInput *input = data_ov003_021da2d4;
    if ((((u32) input->mUnk_38 << 28) >> 31) == 0) {
        return 0;
    }
    if (rect->mUnk_00 > input->mUnk_28) {
        return 0;
    }
    if (rect->mUnk_04 < input->mUnk_28) {
        return 0;
    }
    if (rect->mUnk_02 > input->mUnk_2a) {
        return 0;
    }
    if (rect->mUnk_06 >= input->mUnk_2a) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021d2970(const Rect *input) {
    Rect rect;
    rect.mUnk_00 = input->mUnk_00;
    rect.mUnk_02 = input->mUnk_02;
    rect.mUnk_04 = input->mUnk_00 + input->mUnk_04;
    rect.mUnk_06 = input->mUnk_02 + input->mUnk_06;
    return func_ov003_021d2a34(&rect);
}

BOOL func_ov003_021d2940(u16 *output) {
    KeyTouchInput *state = data_ov003_021da2d4;
    if (state->mBits.mBit_0 == 0) {
        output[0] = state->mUnk_2c;
        output[1] = state->mUnk_2e;
        return FALSE;
    }
    output[0] = state->mUnk_28;
    output[1] = state->mUnk_2a;
    return TRUE;
}

#include "00/code_021884fc.h"
#include "00/unk_021b4000.h"

#include "00/code_021884d8.h"
#include "00/code_02188008.h"
#include "00/code_021884e4.h"

void func_ov000_021885ec(void) {
    Unk021884e4 *p;
    void *q;

    p = (Unk021884e4 *) func_ov000_02188584(1);
    if ((p->mUnk_08 & 0x10) != 0) {
        q = (void *) func_ov000_02188584(0x10);
        p->mUnk_08 &= ~0x10;
        p->mUnk_04(0x10, q, 0xd18);
    }
    if ((p->mUnk_08 & 8) != 0) {
        q = (void *) func_ov000_02188584(8);
        p->mUnk_08 &= ~8;
        p->mUnk_04(8, q, 0xc);
    }
    if ((p->mUnk_08 & 4) != 0) {
        q = (void *) func_ov000_02188584(4);
        p->mUnk_08 &= ~4;
        p->mUnk_04(4, q, 0x58);
    }
    if ((p->mUnk_08 & 2) != 0) {
        q = (void *) func_ov000_02188584(2);
        p->mUnk_08 &= ~2;
        p->mUnk_04(2, q, 0x2300);
    }
    if ((p->mUnk_08 & 1) != 0) {
        p->mUnk_08 &= ~1;
        p->mUnk_04(1, p, 0x18);
    }
}

u32 func_ov000_02188584(u32 param_1) {
    if ((param_1 & 1) != 0) {
        return (u32) data_ov000_021b4d10;
    }
    if ((param_1 & 2) != 0) {
        return *(u32 *) &data_ov000_021b4d04;
    }
    if ((param_1 & 4) != 0) {
        return *(u32 *) &data_ov000_021b4d08;
    }
    if ((param_1 & 8) != 0) {
        return *(u32 *) &data_ov000_021b4d0c;
    }
    if ((param_1 & 0x10) != 0) {
        return *(u32 *) &data_ov000_021b4d00;
    }
    return 0;
}

void func_ov000_02188534(u8 a) {
    Unk021884e4 *p;
    Unk02188408 *q;

    p = (Unk021884e4 *) func_ov000_02188584(1);
    q = (Unk02188408 *) func_ov000_02188584(0x10);
    p->mUnk_09 = a;
    if (a < 0x10) {
        if (a > p->mUnk_16) {
            p->mUnk_16 = a;
            if (a > 7) {
                p->mUnk_15 = func_ov000_021884d8(q->mUnk_d0d);
                p->mUnk_14 = q->mUnk_444[q->mUnk_d13].mUnk_00;
            }
        }
    }
}

u8 func_ov000_02188528(void) {
    u32 value0;
    value0 = (u32) &data_ov000_021b4d10;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = (u32) * (const u8 *) ((value0) + 9u);
    return value0;
}

void func_ov000_02188508(u32 arg0) {
    u32 value0 = arg0;
    u32 value4;
    u32 value5;
    value5 = (value0) + (0u);
    value0 = 1u;
    value0 = (u32) func_ov000_02188584(value0);
    value4 = (value0) + (0u);
    *(u32 *) ((value4) + 12u) = value5;
    value0 = (u32) func_ov000_02188528();
    *(u8 *) ((value4) + 10u) = (u8) value0;
    return;
}

u32 func_ov000_021884fc(void) {
    u32 value0;
    value0 = (u32) &data_ov000_021b4d10;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = (u32) * (const u32 *) ((value0) + 12u);
    return value0;
}

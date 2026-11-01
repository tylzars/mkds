#include "Main/Unknown/code_020c0dd8.h"
#include "Main/Unknown/code_020c13d0.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b1000.h"

void func_020c1060(void) {
    s32 a[8];
    s32 c;
    u32 p;
    u32 r;
    u32 w;
    Unk0217aa1c_00 *s;
    s32 v;
    s32 x0;
    s32 x1;
    s32 x2;
    s32 x3;
    u16 i;
    u16 j;
    u16 k;
    s32 m;
    s32 n;
    s32 neg;

    neg = -1;
    x0 = 0;
    x1 = 0;
    x2 = 0;
    x3 = 0;
    {
        for (i = 0; (u32) i < (u32) data_021759c0->mUnk_3d0; i++) {
            if (data_021759c0->mUnk_1c == 1 || data_021759c0->mUnk_08 == 2) {
                v = x0;
                if ((u32) data_021759c0->mUnk_68[i].mUnk_08.mUnk_00 <= 3 &&
                    ((1 << data_021759c0->mUnk_68[i].mUnk_08.mUnk_00) & 0xd)) {
                    v = 1;
                }
                c = v != 0 ? 1 : x1;
                p = func_0205dc7c(i);
                r = func_0205db28();
                w = data_0217aa1c->mUnk_000[r][func_0205dc7c(p)].mUnk_05;
                a[i] = w * 16 + c * 8 + 8 - func_0203c8dc(i);
            } else {
                v = x2;
                if ((u32) data_021759c0->mUnk_68[i].mUnk_08.mUnk_00 <= 3 &&
                    ((1 << data_021759c0->mUnk_68[i].mUnk_08.mUnk_00) & 0xd)) {
                    v = 1;
                }
                c = v != 0 ? 1 : x3;
                p = func_0205dc7c(i);
                r = func_0205db28();
                s = &data_0217aa1c->mUnk_000[r][func_0205dc7c(p)];
                w = s->mUnk_00;
                a[i] = w * 16 + c * 8 + 8 - func_0203c8dc(i);
                p = func_0205dc7c(i);
                r = func_0205db28();
                s = &data_0217aa1c->mUnk_000[r][func_0205dc7c(p)];
                data_0217b3e0->mUnk_0020[i] = s->mUnk_00;
            }
        }
    }
    for (i = 0; (u32) i < (u32) data_021759c0->mUnk_3d0; i++) {
        data_0217b3e0->mUnk_0040[i] = i;
        a[i] = a[i] * neg;
    }
    func_020ae770(data_0217b3e0->mUnk_0040, a, data_021759c0->mUnk_3d0);
    for (k = 0; (u32) k < (u32) data_021759c0->mUnk_3d0; k++) {
        {
            for (j = 0; (u32) j < (u32) data_021759c0->mUnk_3d0; j++) {
                if (k == data_0217b3e0->mUnk_0040[j]) {
                    m = j;
                    func_0205d76c(k, (j + 1) & 0xff);
                    data_0217b488->mUnk_ec[k] = j;
                    break;
                }
            }
            for (i = 0; (u32) i < (u32) data_021759c0->mUnk_3d0; i++) {
                if (k == data_0217b3e0->mUnk_0060[i]) {
                    n = i;
                    break;
                }
            }
            if (m < n) {
                data_0217b3e0->mUnk_0080[k] = 1;
            } else if (m > n) {
                data_0217b3e0->mUnk_0080[k] = 0;
            } else {
                data_0217b3e0->mUnk_0080[k] = 2;
            }
        }
    }
}

void func_020c0fd0(void) {
    s32 n;

    n = data_0217b3e0->mUnk_00b0++;
    if (n < 0x14) {
        data_0217b3e0->mUnk_00a0 = func_020ae4c0(1, 0, 0x100, n, 0x14);
    } else {
        data_0217b3e0->mUnk_00a0 = 0x100;
        data_0217b3e0->mUnk_00ac = func_020c0f48;
        data_0217b3e0->mUnk_00b0 = 0;
        func_020b1d90();
    }
}

void func_020c0f48(void) {
    s32 n;

    n = data_0217b3e0->mUnk_00b0++;
    if (n < 0x14) {
        data_0217b3e0->mUnk_00a0 = func_020ae4c0(1, 0x80, 0, n, 0x14);
    } else {
        data_0217b3e0->mUnk_00a0 = 0;
        data_0217b3e0->mUnk_00ac = func_020c0f0c;
        data_0217b3e0->mUnk_00b0 = 0;
    }
}

void func_020c0f0c(void) {
    func_020c1060();
    data_0217b3e0->mUnk_00ac = func_020c0ee4;
    data_0217b3e0->mUnk_00b0 = 0;
}

void func_020c0ee4(void) {
    data_0217b3e0->mUnk_00ac = func_020c0dd8;
    data_0217b3e0->mUnk_00b0 = 0;
}

static inline Unk0217aa1c_144_00 *func_020c0dd8_inline(s32 j) {
    return &data_0217aa1c->mUnk_144[func_0205db28()].mUnk_00[j];
}

void func_020c0dd8(void) {
    s32 a;
    s32 b;

    if (data_021759c0->mUnk_1c == 1 || data_021759c0->mUnk_08 == 2) {
        if (data_021759c0->mUnk_58 != 0) {
            a = func_020c0dd8_inline(0)->mUnk_02;
            b = func_020c0dd8_inline(1)->mUnk_02;
            if (a <= b) {
                a = b;
            }
        } else {
            a = data_0217b3e0->mUnk_0020[data_0217b3e0->mUnk_0040[0]];
        }
        data_0217b3e0->mUnk_00b4 = a >= data_021759c0->mUnk_3d8;
    } else {
        data_0217b3e0->mUnk_00b4 = (u32) data_021759c0->mUnk_60 >= data_021759c0->mUnk_3d8;
    }
    data_0217b3e0->mUnk_00ac = func_020c13d0;
    data_0217b3e0->mUnk_00b0 = 0;
}

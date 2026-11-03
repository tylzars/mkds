#include "Main/Unknown/code_02079c0c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02012b30.h"

void func_02079f70(struct Unk0206bcb0_590 *a, u16 b, u16 c, u16 d) {
    Unk0206bcb0_590_6a *q;

    q = &a->mUnk_06a;
    q->mUnk_06 = a->mUnk_06a.mUnk_00 & 0x1f;
    q->mUnk_0c = (s16) (b & 0x1f) - q->mUnk_06;
    q->mUnk_08 = (a->mUnk_06a.mUnk_00 >> 5) & 0x1f;
    q->mUnk_0e = (s16) ((b >> 5) & 0x1f) - q->mUnk_08;
    q->mUnk_0a = (a->mUnk_06a.mUnk_00 >> 10) & 0x1f;
    q->mUnk_10 = (s16) ((b >> 10) & 0x1f) - q->mUnk_0a;
    q->mUnk_12 = q->mUnk_02 & 0x1f;
    q->mUnk_18 = (s16) (c & 0x1f) - q->mUnk_12;
    q->mUnk_14 = (q->mUnk_02 >> 5) & 0x1f;
    q->mUnk_1a = (s16) ((c >> 5) & 0x1f) - q->mUnk_14;
    q->mUnk_16 = (q->mUnk_02 >> 10) & 0x1f;
    q->mUnk_1c = (s16) ((c >> 10) & 0x1f) - q->mUnk_16;
    q->mUnk_1e = q->mUnk_04 & 0x1f;
    q->mUnk_24 = (s16) (d & 0x1f) - q->mUnk_1e;
    q->mUnk_20 = (q->mUnk_04 >> 5) & 0x1f;
    q->mUnk_26 = (s16) ((d >> 5) & 0x1f) - q->mUnk_20;
    q->mUnk_22 = (q->mUnk_04 >> 10) & 0x1f;
    q->mUnk_28 = (s16) ((d >> 10) & 0x1f) - q->mUnk_22;
    q->mUnk_2a = 0;
}

s32 func_02079ce0(struct Unk0206bcb0_590 *a, s32 b) {
    Unk0206bcb0_590_6a *q = &a->mUnk_06a;
    BOOL r = FALSE;

    if (q->mUnk_2a < 0x1000) {
        q->mUnk_2a += b;
        if (q->mUnk_2a >= 0x1000) {
            q->mUnk_2a = 0x1000;
            r = TRUE;
        }
        q->mUnk_00 = (s16) (q->mUnk_06 + (s32) (((s64) q->mUnk_0c * q->mUnk_2a + 0x800) >> 12)) +
                     ((s16) (q->mUnk_08 + (s32) (((s64) q->mUnk_0e * q->mUnk_2a + 0x800) >> 12)) << 5) +
                     ((s16) (q->mUnk_0a + (s32) (((s64) q->mUnk_10 * q->mUnk_2a + 0x800) >> 12)) << 10);
        func_020132cc(a->mUnk_010[0]->mUnk_04, q->mUnk_00);
        func_020132cc(a->mUnk_010[1]->mUnk_04, q->mUnk_00);
        if (a->mUnk_010[2] != NULL) {
            func_020132cc(a->mUnk_010[2]->mUnk_04, q->mUnk_00);
        }
        q->mUnk_02 = (s16) (q->mUnk_12 + (s32) (((s64) q->mUnk_18 * q->mUnk_2a + 0x800) >> 12)) +
                     ((s16) (q->mUnk_14 + (s32) (((s64) q->mUnk_1a * q->mUnk_2a + 0x800) >> 12)) << 5) +
                     ((s16) (q->mUnk_16 + (s32) (((s64) q->mUnk_1c * q->mUnk_2a + 0x800) >> 12)) << 10);
        func_020131f4(a->mUnk_010[0]->mUnk_04, q->mUnk_02);
        func_020131f4(a->mUnk_010[1]->mUnk_04, q->mUnk_02);
        if (a->mUnk_010[2] != NULL) {
            func_020131f4(a->mUnk_010[2]->mUnk_04, q->mUnk_02);
        }
        {
            s16 x = q->mUnk_1e + (s32) (((s64) q->mUnk_24 * q->mUnk_2a + 0x800) >> 12);
            s16 y = q->mUnk_20 + (s32) (((s64) q->mUnk_26 * q->mUnk_2a + 0x800) >> 12);
            s16 z = q->mUnk_22 + (s32) (((s64) q->mUnk_28 * q->mUnk_2a + 0x800) >> 12);
            func_02013284(a->mUnk_010[0]->mUnk_04, q->mUnk_04);
            func_02013284(a->mUnk_010[1]->mUnk_04, q->mUnk_04);
            if (a->mUnk_010[2] != NULL) {
                func_02013284(a->mUnk_010[2]->mUnk_04, q->mUnk_04);
            }
            q->mUnk_04 = x + (y << 5) + (z << 10);
        }
    } else {
        r = TRUE;
    }
    return r;
}

void func_02079c0c(struct Unk0206bcb0_590 *a) {
    u16 *p = (u16 *) gKartModels->mUnk_004;
    u32 b;
    u32 c;
    u32 d;

    b = p[0];
    c = p[3];
    d = p[1];
    func_020132cc(a->mUnk_010[0]->mUnk_04, b);
    func_020132cc(a->mUnk_010[1]->mUnk_04, b);
    func_020131f4(a->mUnk_010[0]->mUnk_04, c);
    func_020131f4(a->mUnk_010[1]->mUnk_04, c);
    func_02013284(a->mUnk_010[0]->mUnk_04, d);
    func_02013284(a->mUnk_010[1]->mUnk_04, d);
    if (a->mUnk_010[2] != NULL) {
        func_020132cc(a->mUnk_010[2]->mUnk_04, b);
        func_020131f4(a->mUnk_010[2]->mUnk_04, c);
        func_02013284(a->mUnk_010[2]->mUnk_04, d);
    }
}

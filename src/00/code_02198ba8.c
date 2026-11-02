#include "00/code_02198ba8.h"
#include "00/code_02197000.h"
#include "00/code_02197ddc.h"
#include "00/code_02198714.h"
#include "00/code_0219a01c.h"
#include "code_02134d30.h"

static inline void func_ov000_02198ba8_inline(void *a, const void *b) {
    u8 *p = (u8 *) a;
    const u8 *q = b;
    p[0] = q[0];
    p[1] = q[1];
}

BOOL func_ov000_02198ba8(Unk02197fe8 *a, u16 b, u16 c) {
    u8 d[7];
    int e;
    e = 0;
    func_ov000_02198ba8_inline(d, data_ov000_021b3fa4);
    d[2] = 0x65;
    func_ov000_0219a01c(d, 3, b);
    e += 5;
    if (b != c) {
        func_ov000_0219a01c(d, e, c);
        e += 2;
    }
    if (func_ov000_02198714((u32 *) a, (u32) d, e) == 0) {
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov000_02198c08(Unk02197fe8 *a) {
    u8 b[3];
    func_ov000_02198ba8_inline(b, data_ov000_021b3fa4);
    b[2] = 0x64;
    func_ov000_0219a01c(b, 3, a->mUnk_66);
    if (func_ov000_02198714((u32 *) a, (u32) b, 5) == 0) {
        return FALSE;
    }
    a->mUnk_90 = 0;
    return TRUE;
}

BOOL func_ov000_02198c58(Unk02197fe8 *a, u8 *b, int c) {
    int d;
    u8 *e;
    if (c < 2 || memcmp(b, data_ov000_021b3fa4, 2) != 0) {
        if (func_ov000_02198714((u32 *) a, (u32) b, c) == 0) {
            return FALSE;
        }
        return TRUE;
    }
    d = c + 2;
    if (func_ov000_02197e58((s32) &a->mUnk_50) < d) {
        return TRUE;
    }
    e = a->mUnk_50.mUnk_00 + a->mUnk_50.mUnk_08;
    func_ov000_02197d84((s32 *) &a->mUnk_50, (u32) data_ov000_021b3fa4, 2);
    func_ov000_02197d84((s32 *) &a->mUnk_50, (u32) b, c);
    if (func_ov000_02198714((u32 *) a, (u32) e, d) == 0) {
        return FALSE;
    }
    func_ov000_02197d20((s32 *) &a->mUnk_50, -1, d);
    return TRUE;
}

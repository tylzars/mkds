#include "Main/Unknown/code_020918a8.h"
#include "Main/Unknown/code_02092b3c.h"
#include "Main/Unknown/code_020ac000.h"

#include "Main/Unknown/code_0209219c.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02045874.h"

void func_02093190(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value12 = (u32) &func_020ac588;
    value2 = value0;
    value0 = 0x19fu;
    value1 = 8u;
    func_020ac588(value0, value1, (void *) value2);
}

static inline u32 func_02092b5c_inline(u32 n) {
    Unk020f41c4_B *b;

    b = func_020d22d0();
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    return (u32) (((b->mUnk_00 >> 32) * n) >> 32);
}

static inline u16 func_02092b5c_inline_2(u32 n) {
    Unk020f41c4_B *b;

    b = func_020d22d0();
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    return (u32) (((b->mUnk_00 >> 32) * n) >> 32);
}

void func_020930c8(Unk020e6fd4 *a) {
    s32 i;
    Unk020919e8 *p;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (p = (Unk020919e8 *) a->mUnk_00[i]) != NULL; i++) {
        if (p->mUnk_00.mFlags & 0x800) {
            p->mUnk_a4 = (u16) (func_02092b5c_inline_2(25) + 200);
        }
    }
}

static inline s64 func_02092b5c_inline_4(const Vec3 *a, const Vec3 *b) {
    s32 v1;
    s32 v2;

    v1 = a->x - b->x;
    v2 = a->z - b->z;
    return (s64) v1 * v1 + (s64) v2 * v2;
}

static inline BOOL func_02092b5c_inline_3(Unk020919e8 *p, s32 k) {
    s32 i;
    BOOL f;
    s32 d;
    Unk0206bcb0 *o;

    for (i = 0; i < data_021759c0->mKartCount; i++) {
        f = FALSE;
        if ((u32) data_021759c0->mUnk_68[(u16) i].mUnk_08.mUnk_00 <= 3 &&
            ((1 << data_021759c0->mUnk_68[(u16) i].mUnk_08.mUnk_00) & 0xd)) {
            f = TRUE;
        }
        if (f == FALSE && i != data_021759c0->mUnk_62) {
            continue;
        }
        o = func_0207a974((u16) i);
        if (func_02092b5c_inline_4(&o->mUnk_80, &p->mUnk_00.mPos) >= 0x15f900000000LL) {
            continue;
        }
        d = AngleFromPair(o->mUnk_80.x - p->mUnk_00.mPos.x, o->mUnk_80.z - p->mUnk_00.mPos.z) - k;
        if (d < -0x1f40) {
            continue;
        }
        if (d <= 0x1f40) {
            return TRUE;
        }
    }
    return FALSE;
}

static inline void func_02092b5c_inline_5(Vec3 *v, s32 x, s32 y, s32 z) {
    v->x = x - 0x5000 + func_02092b5c_inline(0xa000);
    v->y = y - 0x5000 + func_02092b5c_inline(0xa000);
    v->z = z - 0x28000 + func_02092b5c_inline(0x50000);
}

s16 func_020930b0(s32 a) {
    return data_0215d4b4[(a >> 4) * 2];
}

s32 func_020930a0(s32 a, s32 b) {
    return (s32) (((s64) a * b) >> 12);
}

s16 func_02093080(s32 a) {
    return data_0215d4b4[(a >> 4) * 2 + 1];
}

void func_02092b5c(void *a, Unk020919e8 *p) {
    s32 i;
    s32 r;
    u16 k;
    s32 n;
    Vec3 v3;
    Vec3 v4;

    switch (p->mUnk_ac) {
        case 0:
            if (func_02061818() == 2) {
                p->mUnk_ac = 1;
                return;
            }
            if (p->mUnk_00.mFlags & 0x800) {
                if (p->mUnk_a4-- <= 0) {
                    p->mUnk_a4 = 4;
                    p->mUnk_ac = 1;
                }
                return;
            }
            if (func_02092b5c_inline_3(p, p->mUnk_00.mUnk_7e) != FALSE) {
                p->mUnk_a4 = 4;
                p->mUnk_ac = 1;
            }
            return;
        case 1:
            break;
        default:
            return;
    }
    if (p->mUnk_a0 == 0x14) {
        for (i = 0; i < 2; i++) {
            func_02092b5c_inline_5(&v3, p->mUnk_00.mPos.x, p->mUnk_00.mPos.y + 0x23000, p->mUnk_00.mPos.z);
            k = p->mUnk_00.mUnk_7e;
            r = func_02091f6c(func_020d22d0(), 0x1000) + 0x2000;
            k = k - 0xbb8 + func_02046524(func_020d22d0(), 0x1770);
            v4.x = func_020930a0(r, func_020930b0(k));
            v4.y = func_02091f6c(func_020d22d0(), 0x400) - 0xa00;
            v4.z = func_020930a0(r, func_02093080(k));
            if (i == 0 && p->mUnk_a8 == 0) {
                func_0209219c(0x8c, &v3, &v4, 0xf, 1, i == 0 ? 2 : 0);
            } else {
                func_0209219c(0x8c, &v3, &v4, 0xf, 0, i == 0 ? 2 : 0);
            }
        }
        p->mUnk_a8 += 1;
        if (p->mUnk_a8 >= 3) {
            p->mUnk_a8 = 0;
        }
    }
    n = p->mUnk_a0 + 1;
    if (n >= 0x32) {
        n = 0;
    }
    p->mUnk_a0 = n;
    if (p->mUnk_a0 != 0) {
        return;
    }
    if (p->mUnk_a4-- > 0) {
        return;
    }
    p->mUnk_a8 = 0;
    p->mUnk_ac = 0;
    if (p->mUnk_00.mFlags & 0x800) {
        p->mUnk_a4 = (u16) (func_02092b5c_inline_2(25) + 200);
    }
}

void func_02092b3c(void) {
    func_0209bf48(func_020930c8, func_02092b5c, NULL);
}

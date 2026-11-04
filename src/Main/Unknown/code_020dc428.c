#include "Main/Unknown/code_020dc428.h"

#include "Main/Unknown/code_020dc448.h"
#include "Main/Unknown/code_020dc474.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020dc5dc.h"

u32 func_020dc5dc(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = 0x555u;
    value1 = 0x1c2u;
    *(u32 *) ((value0) + (232)) = value2;
    *(u32 *) ((value0) + (236)) = value1;
    value0 = (u32) * (const u32 *) ((value0) + (472));
    value1 = 0x599u;
    *(u32 *) ((value0) + (168)) = value1;
    return value0;
}

static inline s64 func_020dc474_inline(const Vec3 *v) {
    return (s64) v->x * v->x + (s64) v->z * v->z;
}

void func_020dc474(Unk020dc474 *p) {
    Vec3 a;
    s32 k;

    k = p->mUnk_1fc;
    if ((s64) (p->mUnk_00.mPos.x - p->mUnk_a0.x) * (p->mUnk_00.mPos.x - p->mUnk_a0.x) +
            (s64) (p->mUnk_00.mPos.z - p->mUnk_a0.z) * (p->mUnk_00.mPos.z - p->mUnk_a0.z) >=
        (s64) k * k) {
        Vec3Sub(&p->mUnk_a0, &p->mUnk_00.mPos, &a);
        p->mUnk_00.mUnk_10.x += (s32) (((s64) a.x << 2) >> 12);
        p->mUnk_00.mUnk_10.z += (s32) (((s64) a.z << 2) >> 12);
        if (func_020dc474_inline(&p->mUnk_00.mUnk_10) >= 0x1000000) {
            p->mUnk_00.mUnk_10.x -= (s32) (((s64) p->mUnk_00.mUnk_10.x * 0x199) >> 12);
            p->mUnk_00.mUnk_10.z -= (s32) (((s64) p->mUnk_00.mUnk_10.z * 0x199) >> 12);
        }
        p->mUnk_00.mPos.x += p->mUnk_00.mUnk_10.x;
        p->mUnk_00.mPos.z += p->mUnk_00.mUnk_10.z;
    }
    if (p->mUnk_00.mUnk_80.mUnk_04 >= 0xb4) {
        p->mUnk_00.mUnk_80.mUnk_10 = 0;
        p->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}

u32 func_020dc448(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = 0x555u;
    value1 = 0x1c2u;
    *(u32 *) ((value0) + (232)) = value2;
    *(u32 *) ((value0) + (236)) = value1;
    value0 = (u32) * (const u32 *) ((value0) + (472));
    value1 = 0x599u;
    *(u32 *) ((value0) + (168)) = value1;
    return value0;
}

u32 func_020dc444(u32 p0) {
    return p0;
}

void func_020dc428(Unk020dc428 *p0) {
    p0->mUnk_e8 = 0x555u;
    p0->mUnk_ec = 0x1c2u;
}

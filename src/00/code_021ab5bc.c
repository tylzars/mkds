#include "00/code_021ab5bc.h"
#include "00/types_021ab5e4.h"
#include "00/unk_021b6000.h"
#include "code_0200f5ac.h"
#include "code_02134d30.h"
#include "code_0214d018.h"
#include "code_0214d964.h"
#include "code_0214e1e0.h"

Unk021ab5e4 *func_ov000_021ab684(const u8 *a) {
    s32 i;
    Unk021ab5e4 *e;
    i = 0;
    e = data_ov000_021b61f4;
    for (; i < 4; i++) {
        if (e->mUnk_5a != 0 && memcmp(e->mUnk_00, a, 0x20) == 0) {
            e->mUnk_50 = func_0200f5ac() >> 16;
            return e;
        }
        e++;
    }
    return NULL;
}

Unk021ab5e4 *func_ov000_021ab63c(u32 a, u32 b) {
    Unk021ab5e4 *e;
    s32 i;
    i = 0;
    e = data_ov000_021b61f4;
    for (; i < 4; i++) {
        if (e->mUnk_5a != 0 && e->mUnk_54 == a && e->mUnk_58 == b) {
            e->mUnk_50 = func_0200f5ac() >> 16;
            return e;
        }
        e++;
    }
    return NULL;
}

Unk021ab5e4 *func_ov000_021ab5e4(const u8 *a) {
    Unk021ab5e4 *v1;
    u32 t;
    s32 i;
    u32 v2;
    u32 v3;
    Unk021ab5e4 *e;
    t = func_0200f5ac() >> 16;
    v3 = 0;
    v1 = data_ov000_021b61f4;
    i = 0;
    e = v1;
    for (; i < 4; i++) {
        if (e->mUnk_5a == 0) {
            v1 = e;
            break;
        }
        v2 = t - e->mUnk_50;
        if (v2 > v3) {
            v3 = v2;
            v1 = e;
        }
        e++;
    }
    func_0214d1fc(a, v1, 0x20);
    v1->mUnk_50 = t;
    v1->mUnk_5a = 1;
    return v1;
}

u32 func_ov000_021ab5bc(void) {
    Unk0214e1e0 a;
    u32 b[3];
    func_0214e038((u32 *) &a);
    func_0214df78(b);
    return (u32) func_0214e1e0(&a, (const Unk0214e1e0 *) b) + 0x386d4380;
}

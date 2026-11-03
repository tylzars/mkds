#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_021052f0.h"

#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_021053d8.h"

void func_021053d8(u32 arg0) {
    u32 value0 = arg0;
    u32 value12;
    value12 = (u32) &func_020d2398;
    func_020d2398((void *) value0);
}

void func_02105338(Unk021052fc *p, s32 a, Vec3 *v) {
    p->mUnk_00.mUnk_04 = *p->mUnk_fc;
    if (a < 1) {
        a = 1;
    }
    p->mUnk_00.mUnk_66 = a;
    p->mUnk_00.mUnk_1c.x = (s32) (((s64) v->x * 0x666) >> 12);
    p->mUnk_00.mUnk_1c.y = (s32) (((s64) v->y * 0x666) >> 12);
    p->mUnk_00.mUnk_1c.z = (s32) (((s64) v->z * 0x666) >> 12);
}

void func_021052fc(Unk021052fc *p) {
    p->mUnk_a0 = p->mUnk_a0 + 1;
    if (p->mUnk_a0 >= 0x12c) {
        p->mUnk_a0 = 0;
    }
    p->mUnk_a2 = p->mUnk_a2 + 1;
    if (p->mUnk_a2 >= 0x82) {
        p->mUnk_a2 = 0;
    }
}

void func_021052f0(Unk021052fc *p0, void *p1, void *p2) {
    *(u32 *) ((u8 *) p0 + 256) = (u32) p1;
    *(u32 *) ((u8 *) p0 + 260) = (u32) p2;
}

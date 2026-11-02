#include "Main/Unknown/code_020e516c.h"

#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_020ea588.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e55b4.h"

void func_020e55b4(void) {
    u32 value;
    value = data_0217b814->mUnk_01c;
    func_01ff9048(0x2b, &value, 1);
    func_01ff9048(0x2a, &data_0217b814->mUnk_014, 1);
    func_01ff9048(0x30, &data_0217b814->mUnk_004, 1);
    func_01ff9048(0x31, &data_0217b814->mUnk_008, 1);
}

void func_020e54e4(void *d, void *e, u32 f, u32 g) {
    u32 a;
    u32 b;
    u32 c[3];

    b = 0x1e;
    func_01ff9048(0x14, &b, 1);
    func_01ff9048(0x19, d, 0xc);
    if (e != 0) {
        u32 w;
        w = *(u32 *) e;
        c[0] = w;
        c[1] = w;
        c[2] = w;
        func_01ff9048(0x1b, c, 3);
    }
    a = data_0217b814->mUnk_00c;
    g = g < ((Unk020e516c *) d)->mUnk_030 ? g : ((Unk020e516c *) d)->mUnk_030;
    a = a & ~0x1f0000;
    a = a | (g << 16);
    func_01ff9048(0x29, &a, 1);
    func_01ff9144(&data_0217b818->mUnk_000[data_0217b818->mUnk_008], data_0217b818->mUnk_00c);
}

void func_020e53ac(Unk020e516c *p, void *d, u32 e, u32 f) {
    u32 x;
    u32 a;
    u32 b;
    u32 c[3];

    x = data_0217b814->mUnk_01c;
    func_01ff9048(0x2b, &x, 1);
    func_01ff9048(0x2a, &data_0217b814->mUnk_014, 1);
    func_01ff9048(0x30, &data_0217b814->mUnk_004, 1);
    func_01ff9048(0x31, &data_0217b814->mUnk_008, 1);
    b = 0x1e;
    func_01ff9048(0x14, &b, 1);
    func_01ff9048(0x19, p, 0xc);
    if (d != 0) {
        u32 w;
        w = *(u32 *) d;
        c[0] = w;
        c[1] = w;
        c[2] = w;
        func_01ff9048(0x1b, c, 3);
    }
    a = data_0217b814->mUnk_00c;
    f = f < p->mUnk_030 ? f : p->mUnk_030;
    a = a & ~0x1f0000;
    a = a | (f << 16);
    func_01ff9048(0x29, &a, 1);
    func_01ff9144(&data_0217b818->mUnk_000[data_0217b818->mUnk_008], data_0217b818->mUnk_00c);
}

void func_020e5370(void *a, void *b, u32 c, u32 d) {
    gJgShadow->mUnk_06e = c < d ? c : d;
    func_0207aec8(gJgShadow, b, a);
}

void func_020e5348(u32 a, u32 b) {
    gJgShadow->mUnk_06e = a < b ? a : b;
    func_0207ad88(gJgShadow);
}

#pragma thumb on

void func_020e52bc(void) {
    Unk020e52bc_4 *a;
    Unk020e52bc_8 *b;
    Unk020e52bc_c *c;

    func_020ea588((void **) &gObjShadow,
                  (void *) FindMainRaceOrMainEffectMapObjFile(gObjShadowNsbmdName), 0);
    func_020849c0(gObjShadow, 0x3f);
    func_020849b0(gObjShadow, 0);
    a = gObjShadow->mUnk_004;
    b = (Unk020e52bc_8 *) &a->mUnk_000[a->mUnk_008];
    data_0217b814 = (Unk020e53ac *) &b->mUnk_000[((u32 *) &b->mUnk_000[b->mUnk_00a])[2]];
    a = gObjShadow->mUnk_004;
    c = (Unk020e52bc_c *) &a->mUnk_000[a->mUnk_00c];
    data_0217b818 = (Unk020e54e4 *) &c->mUnk_000[((u32 *) &c->mUnk_000[c->mUnk_006])[1]];
    if (data_021759c0->mUnk_00c != 6) {
        func_020ea55c((void **) &gJgShadow, (void *) FindSceneFile(gJgShadowNsbmdName), 0x3f);
    }
}

s32 func_020e516c(void *a, Vec3 *v, s32 b, u32 c) {
    Unk020d7b88 buf2;
    Vec3 buf1;
    Vec3 s;
    s32 d;
    s32 r;

    s = *v;
    r = 0;
    s.y = s.y + 0x1999;
    if (func_01ffdee4((int *) &s, 0, 0, 0xa000, 8, -2, 0, (int *) &buf1, 0, 0, 0, 0, 0, 0) != 0) {
        r = 1;
        func_020d7b88((Vec3 *) &buf1, &buf2);
        func_01ffccd0((int *) a, &buf2);
        d = b / 10;
        ((Unk020e516c *) a)->mUnk_000 = (s32) (((s64) ((Unk020e516c *) a)->mUnk_000 * d) >> 12);
        ((Unk020e516c *) a)->mUnk_004 = (s32) (((s64) ((Unk020e516c *) a)->mUnk_004 * d) >> 12);
        ((Unk020e516c *) a)->mUnk_008 = (s32) (((s64) ((Unk020e516c *) a)->mUnk_008 * d) >> 12);
        ((Unk020e516c *) a)->mUnk_00c = (s32) (((s64) ((Unk020e516c *) a)->mUnk_00c * d) >> 12);
        ((Unk020e516c *) a)->mUnk_010 = (s32) (((s64) ((Unk020e516c *) a)->mUnk_010 * d) >> 12);
        ((Unk020e516c *) a)->mUnk_014 = (s32) (((s64) ((Unk020e516c *) a)->mUnk_014 * d) >> 12);
        ((Unk020e516c *) a)->mUnk_018 = (s32) (((s64) ((Unk020e516c *) a)->mUnk_018 * d) >> 12);
        ((Unk020e516c *) a)->mUnk_01c = (s32) (((s64) ((Unk020e516c *) a)->mUnk_01c * d) >> 12);
        ((Unk020e516c *) a)->mUnk_020 = (s32) (((s64) ((Unk020e516c *) a)->mUnk_020 * d) >> 12);
    } else {
        func_02146cbc((Unk02012f58 *) a);
    }
    ((Unk020e516c *) a)->mUnk_024 = s.x >> 4;
    ((Unk020e516c *) a)->mUnk_028 = s.y >> 4;
    ((Unk020e516c *) a)->mUnk_02c = s.z >> 4;
    ((Unk020e516c *) a)->mUnk_030 = c;
    return r;
}

#pragma thumb off

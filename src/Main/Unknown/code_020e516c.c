#include "Main/Unknown/code_020e516c.h"

#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_020ea588.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e55b4.h"
#include "code_02146cbc.h"

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
    Unk020e516c *m = d;

    b = 0x1e;
    func_01ff9048(0x14, &b, 1);
    func_01ff9048(0x19, d, 0xc);
    if (e != NULL) {
        u32 w;
        w = *(u32 *) e;
        c[0] = w;
        c[1] = w;
        c[2] = w;
        func_01ff9048(0x1b, c, 3);
    }
    a = data_0217b814->mUnk_00c;
    g = g < m->mUnk_030 ? g : m->mUnk_030;
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
    if (d != NULL) {
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

void func_020e5370(Vec3 *a, MtxFx43 *b, u32 c, u32 d) {
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

    func_020ea588((void **) &gObjShadow, FindMainRaceOrMainEffectMapObjFile(gObjShadowNsbmdName), NULL);
    func_020849c0(gObjShadow, 0x3f);
    func_020849b0(gObjShadow, 0);
    a = gObjShadow->mUnk_004;
    b = (Unk020e52bc_8 *) &a->mUnk_000[a->mUnk_008];
    data_0217b814 = (Unk020e53ac *) &b->mUnk_000[((u32 *) &b->mUnk_000[b->mUnk_00a])[2]];
    a = gObjShadow->mUnk_004;
    c = (Unk020e52bc_c *) &a->mUnk_000[a->mUnk_00c];
    data_0217b818 = (Unk020e54e4 *) &c->mUnk_000[((u32 *) &c->mUnk_000[c->mUnk_006])[1]];
    if (data_021759c0->mUnk_00c != 6) {
        func_020ea55c((void **) &gJgShadow, FindSceneFile(gJgShadowNsbmdName), 0x3f);
    }
}

s32 func_020e516c(void *a, Vec3 *v, s32 b, u32 c) {
    Unk020d7b88 buf2;
    Vec3 buf1;
    Vec3 s;
    s32 d;
    BOOL r;
    Unk020e516c *m = a;

    s = *v;
    r = FALSE;
    s.y = s.y + 0x1999;
    if (func_01ffdee4(&s, NULL, 0, 0xa000, 8, -2, NULL, &buf1, NULL, NULL, NULL, NULL, NULL, NULL) != 0) {
        r = TRUE;
        func_020d7b88(&buf1, &buf2);
        Matrix3x3FromQuaternion(a, &buf2);
        d = b / 10;
        m->mUnk_000[0] = ((s64) m->mUnk_000[0] * d) >> 12;
        m->mUnk_000[1] = ((s64) m->mUnk_000[1] * d) >> 12;
        m->mUnk_000[2] = ((s64) m->mUnk_000[2] * d) >> 12;
        m->mUnk_000[3] = ((s64) m->mUnk_000[3] * d) >> 12;
        m->mUnk_000[4] = ((s64) m->mUnk_000[4] * d) >> 12;
        m->mUnk_000[5] = ((s64) m->mUnk_000[5] * d) >> 12;
        m->mUnk_000[6] = ((s64) m->mUnk_000[6] * d) >> 12;
        m->mUnk_000[7] = ((s64) m->mUnk_000[7] * d) >> 12;
        m->mUnk_000[8] = ((s64) m->mUnk_000[8] * d) >> 12;
    } else {
        MTX_Identity33_(a);
    }
    m->mUnk_000[9] = s.x >> 4;
    m->mUnk_000[10] = s.y >> 4;
    m->mUnk_000[11] = s.z >> 4;
    m->mUnk_030 = c;
    return r;
}

#pragma thumb off

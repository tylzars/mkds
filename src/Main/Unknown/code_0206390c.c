#include "Main/Unknown/code_0206390c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02012b30.h"
#include "code_02013740.h"
#include "code_02146d78.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02077bc0.h"

// Copies row 1 of the matrix at 0x120 (mUnk_120_m), the kart's up direction, to the out vector. The camera takes it as
// its up while bit 0x40000000 of mUnk_48 is set and the world up (0, 0x1000, 0) otherwise; the steering code removes
// this component from vectors. The kart has two more matrices (0x150 and 0x184), built from this one for drawing.
void GetKartUp(const Kart *a, Vec3 *b) {
    const Unk02012f58 *c;

    c = (const Unk02012f58 *) ((u8 *) a + 0x120);
    b->x = c->mUnk_00[1].x;
    b->y = c->mUnk_00[1].y;
    b->z = c->mUnk_00[1].z;
}

// Copies row 2 of the matrix at 0x120 (mUnk_120_m), the kart's forward direction, to the out vector. The camera follows
// it, and its mSavedKartForward holds a copy taken when the camera is set up. The kart has two more matrices (0x150 and
// 0x184), built from this one for drawing.
void GetKartForward(const Kart *a, Vec3 *b) {
    const Unk02012f58 *c;

    c = (const Unk02012f58 *) ((u8 *) a + 0x120);
    b->x = c->mUnk_00[2].x;
    b->y = c->mUnk_00[2].y;
    b->z = c->mUnk_00[2].z;
}

void func_02063ad0(Kart *a) {
    if ((a->mUnk_7c & 0x400) != 0) {
        return;
    }
    a->mUnk_20c_fn[6](a);
    if ((a->mUnk_7c & 0x200) != 0) {
        a->mUnk_514->mUnk_2c ^= 0x10000;
    }
}

void func_02063a68(Kart *a) {
    u32 b;

    b = a->mUnk_7c & 0x400;
    if (b != 0) {
        return;
    }
    if (b == 0) {
        a->mUnk_20c_fn[6](a);
        if ((a->mUnk_7c & 0x200) != 0) {
            a->mUnk_514->mUnk_2c ^= 0x10000;
        }
    }
    if (data_021759c0->mMode == MODE_BATTLE) {
        a->mUnk_48 &= ~0x200;
    }
}

void func_0206390c(Unk0206390c *a) {
    u32 b;
    Vec3 c[3];
    Unk02012f58 d;
    Vec3 f;
    Vec3 g;
    Unk02012f58 e;
    s32 h;
    Unk02012f58 *i;
    Kart *j;
    s32 k;

    b = func_0207a31c();
    k = func_02013754(a->mUnk_04->mUnk_04 + 0x40, data_02154a2c);
    if (k != ((a->mUnk_08 & 0x10) != 0 ? a->mUnk_ae : -1)) {
        return;
    }
    i = func_0206182c();
    func_02012f58(&d, c);
    Matrix4x3Invert(i, &e);
    Matrix4x3Multiply(&d, &e, &d);
    Matrix3x3Multiply((const s32 *) c, (const s32 *) &e, (s32 *) c);
    f = d.mUnk_00[3];
    g = c[2];
    j = GetKart(b);
    h = (s32) ((s64) j->mUnk_4c8 * -0xd000 + 0x800 >> 12) >> 4;
    g.x = (s64) g.x * h >> 12;
    g.y = (s64) g.y * h >> 12;
    g.z = (s64) g.z * h >> 12;
    Vec3Add(&f, &g, &f);
    func_02081618(b, &f);
    a->mUnk_24 = 0;
    a->mUnk_92 = 0;
}

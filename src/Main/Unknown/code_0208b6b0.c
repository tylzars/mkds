#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02047104.h"

#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0208d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"

u32 func_0208bd04(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_0217b040;
    value12 = (u32) &HeapAlloc;
    value1 = value0;
    value0 = (u32) * (const u32 *) ((value2) + (0));
    value0 = (u32) HeapAlloc((void *) value0, value1);
    return value0;
}

void func_0208b934(void *a) {
    s32 e = 0x78;
    s32 f = 0x28;
    void *c = a;
    void *g;
    void *h;
    void *t;
    u8 j;
    Vec3 w;
    Vec3 v;
    Unk021759c0 *d;
    Vec3 *q;

    *(u32 *) &data_0217b050 = (u32) func_0208b484;
    if (func_0205e0a0() == 2) {
        d = data_021759c0;
        if (d->mUnk_08 == 4) {
            *(u32 *) &data_0217b050 = (u32) func_0208b458;
            c = data_0217aa10->mUnk_a4;
            e = 0x96;
        }
        if (d->mCourseId == 0x34) {
            e = 0x12c;
            f = 0x32;
        }
    }
    data_0217b040 = c;
    data_0217b044 = func_02018d94((void *(*) (u32)) func_0208bd04, f, e, 3, 0xe, func_02061768());
    g = FindMainRaceOrMainEffectFile(data_usa_02166138);
    func_02018a1c(data_0217b044, g);
    func_02018888(data_0217b044);
    func_02018874(data_0217b044);
    func_02047220(g, *(u32 *) ((u8 *) g + 0x18));
    data_0217b04c = func_02018d94((void *(*) (u32)) func_0208bd04, 0x1e, 0x64, 3, 0xe, 0x1e);
    h = FindMainRaceOrMainEffectFile(data_usa_02166148);
    func_02018a1c(data_0217b04c, h);
    func_02018888(data_0217b04c);
    func_02018874(data_0217b04c);
    data_0217b03c = NULL;
    data_0217b054 = NULL;
    data_0217b048 = NULL;
    if (func_0205e0a0() != 2) {
        return;
    }
    if (data_021759c0->mUnk_08 == 4) {
        t = NULL;
        data_0217b03c = func_02018d94((void *(*) (u32)) func_0208bd04, 0x32, 0xc8, 3, 0xe, 0x1e);
        func_02048590(data_usa_02166168, (u32) c, &t);
        func_02018a1c(data_0217b03c, t);
        func_02018888(data_0217b03c);
        func_02018874(data_0217b03c);
        data_0217b03c->mUnk_3c = 0x8000;
    }
    data_0217b044->mUnk_38_24 = 1;
    data_0217b04c->mUnk_38_24 = 1;
    if (data_0217b03c != NULL) {
        data_0217b03c->mUnk_38_24 = 1;
    }
    func_0208d758(a);
    if (data_021759c0->mCourseId != 0x1d) {
        data_0217b044->mUnk_3c = 0x8000;
    } else {
        data_0217b044->mUnk_3c = 0;
    }
    func_02082aec();
    switch (data_021759c0->mCourseId) {
        case 0x22:
            w = data_usa_021660fc;
            data_0217b048 = HeapAlloc(c, 0x64);
            for (j = 0; j < 6; j++) {
                data_0217b048->mUnk_48[j] = NULL;
                func_021484d0(&data_usa_02155f78[j], &w, &v);
                q = &data_0217b048->mUnk_00[j];
                if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
                    func_02039860(&v, q);
                }
            }
            data_0217b048->mUnk_60 = 1;
            data_0217b054 = (UnkFunc *) func_0208b190;
            break;
        case 0x34:
            func_0208afe4();
            break;
    }
}

void func_0208b8c8(void) {
    if (data_0217b054 != NULL) {
        data_0217b054();
    }
    func_0201873c(data_0217b044);
    func_0201873c(data_0217b04c);
    if (data_0217b03c != NULL) {
        func_0201873c(data_0217b03c);
    }
}

void func_0208b870(Unk02012f58 *a) {
    func_02018674(data_0217b044, a);
    func_02018674(data_0217b04c, a);
    if (data_0217b03c != NULL) {
        func_02018674(data_0217b03c, a);
    }
}

void *func_0208b7bc(u32 a, const Vec3 *b) {
    s32 e;
    Vec3 v;
    Unk0201ca6c *q;
    Unk020184e4 *p = data_0217b050(&e, a);
    v.x = b->x >> 4;
    v.y = b->y >> 4;
    v.z = b->z >> 4;
    q = func_02018600(p, e, &v);
    if (q != NULL) {
        if (q->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
            q->mUnk_80_16 = 1;
        } else if (q->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
            q->mUnk_80_16 = 2;
        }
    }
    return q;
}

void func_0208b748(u32 a, const Vec3 *b, void *c, void (*d)()) {
    s32 e;
    Vec3 v;
    Unk020184e4 *p = data_0217b050(&e, a);
    v.x = b->x >> 4;
    v.y = b->y >> 4;
    v.z = b->z >> 4;
    func_02018578(p, e, &v, (s32) c, (void (*)(Unk0201ca6c *, s32)) d);
}

void func_0208b710(Unk0201ca6c *a) {
    u32 v1;
    u8 v2[8];
    v1 = (*(UnkWordFunc *) (u32) data_0217b050)(v2, 0);
    func_020184e4((Unk020184e4 *) v1, a);
}

void func_0208b6d0(Unk0201ca6c **a) {
    u32 v1;
    u8 v2[8];
    v1 = (*(UnkWordFunc *) (u32) data_0217b050)(v2, 0);
    func_020184e4((Unk020184e4 *) v1, *a);
    *a = NULL;
}

void func_0208b6b0(void **p0) {
    *(u32 *) ((u8 *) *p0 + 36) = (*(u32 *) ((u8 *) *p0 + 36) & ~0x1u) | 0x1u;
    *p0 = NULL;
}

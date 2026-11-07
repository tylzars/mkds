#include "Main/Unknown/code_02081120.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02083000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02077bc0.h"

void func_020812d0(s32 a) {
    Kart *q = GetKart(a);
    Unk0201ca6c *p;
    u16 i;

    if (!(q->mUnk_4c & 0x8000)) {
        return;
    }
    i = 0;
    do {
        p = StartEffect(0x58, &data_02155a14);
        p->mUnk_94 = q;
        p->mUnk_98_24 = i;
        i = i + 1;
        p->mUnk_90 = func_02081298;
    } while (i < 2);
}

void func_02081298(Unk0201ca6c *p, s32 a) {
    if (a != 0) {
        return;
    }
    AdvanceKartSideEffect(p, a);
    if (p->mUnk_98_0 >= 7) {
        p->mUnk_98_8 = 1;
    } else {
        p->mUnk_98_0 = p->mUnk_98_0 + 1;
    }
}

void func_02081224(u32 a) {
    KartEffects *e = &gKartEffects[a];
    Unk0201ca6c *p;

    if (e->mUnk_30 != NULL) {
        func_0208b710(e->mUnk_30);
    }
    e->mUnk_30 = StartEffect(0x5e, &data_02155a14);
    p = e->mUnk_30;
    p->mUnk_98_16 = 0;
    p->mUnk_98_8 = 0x78;
    p->mUnk_98_24 = a;
    p->mUnk_90 = func_02081120;
}

void func_02081120(Unk0201ca6c *p, s32 a) {
    u32 v1;
    u8 j;
    u8 i;
    Vec3 *v;
    s32 x;
    s32 y;
    s32 z;

    if (a != 0) {
        return;
    }
    i = p->mUnk_98_24;
    j = p->mUnk_98_16;
    v1 = 0;
    v = GetKart(i)->mPosSource;
    x = v->x;
    y = v->y;
    z = v->z;
    p->mUnk_28.x = (x >> 4) + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = (y >> 4) + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = (z >> 4) + p->mUnk_20->mUnk_00->mUnk_04.z;
    if (j >= p->mUnk_98_8) {
        if (j == p->mUnk_98_8) {
            v1 = 1;
            p->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        p->mUnk_98_16 = j + 1;
    }
    if (v1 != 0) {
        gKartEffects[i].mUnk_30 = NULL;
        return;
    }
    p->mUnk_6c = (s16) GetKart(i)->mScale.z;
}

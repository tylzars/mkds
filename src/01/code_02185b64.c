#include "01/code_02185b64.h"

#include "Main/Unknown/code_0209bef0.h"
#include "01/callees_0219b000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02147cd8.h"
#include "code_02146d78.h"

void func_ov001_02185dd0(Unk02185bb8 *a) {
    s32 mtx[9];
    s32 r4;
    s32 r6;
    s16 saved;

    func_020d2450(a);
    a->mUnk_000.mUnk_7e = (s32) (((s64) a->mUnk_000.mUnk_9c->mUnk_0c.y * 0xB60B60B60BLL + 0x80000000000LL) >> 44);
    func_02146d44(mtx, data_0215d4b4[(a->mUnk_000.mUnk_7e >> 4) * 2],
                  data_0215d4b4[(a->mUnk_000.mUnk_7e >> 4) * 2 + 1]);
    func_02146dfc(mtx, &a->mUnk_000.mUnk_28.mUnk_00[0].x, &a->mUnk_000.mUnk_28.mUnk_00[0].x);
    r4 = (s32) (((s64) a->mUnk_000.mUnk_1c.x * 0xA000LL) >> 12);
    r6 = (s32) (((s64) a->mUnk_000.mUnk_1c.y * 0xF000LL) >> 12);
    saved = a->mUnk_000.mUnk_9c->mUnk_28;
    a->mUnk_000.mUnk_9c->mUnk_28 = 0x12;
    a->mUnk_0a0 = func_020d34d4(&a->mUnk_000, 0x66);
    a->mUnk_0a4 = func_020d34d4(&a->mUnk_000, 0x66);
    a->mUnk_000.mUnk_9c->mUnk_28 = saved;
    func_02147fd8(-(a->mUnk_000.mUnk_58.x + r4), &a->mUnk_000.mUnk_28.mUnk_00[0], &a->mUnk_000.mUnk_04,
                  &a->mUnk_0a0->mUnk_04);
    func_02147fd8(a->mUnk_000.mUnk_58.x + r4, &a->mUnk_000.mUnk_28.mUnk_00[0], &a->mUnk_000.mUnk_04,
                  &a->mUnk_0a4->mUnk_04);
    func_020d2950(a->mUnk_0a0, r4);
    func_020d2950(a->mUnk_0a4, r4);
    func_020d2584(a->mUnk_0a0, r6);
    func_020d2584(a->mUnk_0a4, r6);
}

u32 func_ov001_02185d74(Unk02185bb8 *c, Unk02185d74 *d, u8 *e, u8 *f) {
    u32 a = *e;
    u32 b = *f;

    if ((d->mUnk_48 & 0x200) != 0 || (data_021759c0->mUnk_08 == 4 ? func_020a1084(d->mUnk_74) : 0) != 0) {
        return 0;
    }
    if (a == 1) {
        c->mUnk_000.mUnk_02 |= data_ov001_021a6580;
        c->mUnk_0ac = 2;
    }
    return b;
}

void LoadMissionGate(void *a) {
    gMissionGate = func_ov001_0219b478(a, "MissionGate.nsbmd");
    func_ov001_0219b2e8(gMissionGate, "MissionGate.nsbtp");
    func_ov001_0219b380(gMissionGate, "MissionGate.nsbma");
    func_0209b940(gMissionGate, 0x3f);
    func_0209ba08(gMissionGate, 2);
    func_020849a0(gMissionGate->mUnk_10, 0x294a);
}

void func_ov001_02185d18(void) {}

void func_ov001_02185ca0(void *a, Unk02185bb8 *b) {
    s32 buf;

    buf = 0x1e;
    func_01ff9048((u32) (0x14), (void *) ((u32) &buf), 1);
    b->mUnk_000.mUnk_28.mUnk_00[3].x = b->mUnk_000.mUnk_04.x >> 4;
    b->mUnk_000.mUnk_28.mUnk_00[3].y = b->mUnk_000.mUnk_04.y >> 4;
    b->mUnk_000.mUnk_28.mUnk_00[3].z = b->mUnk_000.mUnk_04.z >> 4;
    func_01ff9048((u32) (0x19), (void *) ((u32) &b->mUnk_000.mUnk_28), 0xc);
    func_01ff9048((u32) (0x1b), (void *) ((u32) &b->mUnk_000.mUnk_1c), 3);
    func_0209b688((void *) (gMissionGate), (u16) b->mUnk_000.mUnk_9c->mUnk_28);
    func_0209b734(gMissionGate, b->mUnk_0a8);
    func_0209bb2c(a, gMissionGate, b);
}

void func_ov001_02185c4c(Unk02185c4c *a) {
    s32 i;
    Unk02185bb8 *e;

    if (a) {
        for (i = 0; i < a->mUnk_04 && (e = a->mUnk_00[i]) != NULL; i++) {
            if (e->mUnk_000.mUnk_9c->mUnk_28 != 0) {
                e->mUnk_000.mUnk_02 |= data_ov001_021a6580;
                e->mUnk_0ac = 0;
            } else {
                e->mUnk_000.mUnk_02 &= ~1;
                e->mUnk_0ac = 1;
            }
        }
    }
}

void func_ov001_02185bb8(void *a, Unk02185bb8 *b) {
    s32 pos;

    switch (b->mUnk_0ac) {
        case 0:
            pos = data_021759c0->mUnk_08 == 4 ? func_ov001_02181820() : 0;
            if (pos >= b->mUnk_000.mUnk_9c->mUnk_28 - 1) {
                b->mUnk_000.mUnk_02 &= ~1;
                b->mUnk_0ac = 1;
            }
            break;
        case 2:
            pos = func_0209b710(gMissionGate);
            b->mUnk_0a8++;
            if (b->mUnk_0a8 >= pos - 1) {
                b->mUnk_0a8 = func_0209b710(gMissionGate) - 1;
                b->mUnk_0ac = 1;
            }
            break;
    }
}

void func_ov001_02185b98(void) {
    func_0209bfa8(&func_ov001_02185d74, NULL, NULL, (u32) (0), (u16) (1));
    return;
}

void func_ov001_02185b7c(void) {
    func_0209bf1c(LoadMissionGate, func_ov001_02185ca0, func_ov001_02185d18);
}

void func_ov001_02185b64(void) {
    func_0209bf48(func_ov001_02185c4c, func_ov001_02185bb8, NULL);
}

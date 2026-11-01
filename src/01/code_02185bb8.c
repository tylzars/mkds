#include "01/code_02185bb8.h"
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
#include "Main/Unknown/code_0209bef0.h"

void *func_ov001_02185ef4(void) {
    return (void *) func_0209bf48((u32) ((UnkFunc *) (0)), (u32) ((UnkFunc *) (0)), (u32) ((UnkFunc *) (0)));
}

void func_ov001_02185dd0(Unk02185bb8 *param_1) {
    s32 mtx[9];
    s32 r4;
    s32 r6;
    s16 saved;

    func_020d2450(param_1);
    param_1->mUnk_000.mUnk_7e =
        (s32) (((s64) param_1->mUnk_000.mUnk_9c->mUnk_0c.y * 0xB60B60B60BLL + 0x80000000000LL) >> 44);
    func_02146d44(mtx, data_0215d4b4[(param_1->mUnk_000.mUnk_7e >> 4) * 2],
                  data_0215d4b4[(param_1->mUnk_000.mUnk_7e >> 4) * 2 + 1]);
    func_02146dfc(mtx, &param_1->mUnk_000.mUnk_28.mUnk_00.x, &param_1->mUnk_000.mUnk_28.mUnk_00.x);
    r4 = (s32) (((s64) param_1->mUnk_000.mUnk_1c.x * 0xA000LL) >> 12);
    r6 = (s32) (((s64) param_1->mUnk_000.mUnk_1c.y * 0xF000LL) >> 12);
    saved = param_1->mUnk_000.mUnk_9c->mUnk_28;
    param_1->mUnk_000.mUnk_9c->mUnk_28 = 0x12;
    param_1->mUnk_0a0 = func_020d34d4(&param_1->mUnk_000, 0x66);
    param_1->mUnk_0a4 = func_020d34d4(&param_1->mUnk_000, 0x66);
    param_1->mUnk_000.mUnk_9c->mUnk_28 = saved;
    func_02147fd8(-(param_1->mUnk_000.mUnk_58.x + r4), &param_1->mUnk_000.mUnk_28.mUnk_00, &param_1->mUnk_000.mUnk_04,
                  &param_1->mUnk_0a0->mUnk_04);
    func_02147fd8(param_1->mUnk_000.mUnk_58.x + r4, &param_1->mUnk_000.mUnk_28.mUnk_00, &param_1->mUnk_000.mUnk_04,
                  &param_1->mUnk_0a4->mUnk_04);
    func_020d2950(param_1->mUnk_0a0, r4);
    func_020d2950(param_1->mUnk_0a4, r4);
    func_020d2584(param_1->mUnk_0a0, r6);
    func_020d2584(param_1->mUnk_0a4, r6);
}

u32 func_ov001_02185d74(Unk02185bb8 *param_1, Unk02185d74 *param_2, u8 *param_3, u8 *param_4) {
    u32 a = *param_3;
    u32 b = *param_4;

    if ((param_2->mUnk_48 & 0x200) != 0 || (data_021759c0->mUnk_08 == 4 ? func_020a1084(param_2->mUnk_74) : 0) != 0) {
        return 0;
    }
    if (a == 1) {
        param_1->mUnk_000.mUnk_02 |= data_ov001_021a6580;
        param_1->mUnk_0ac = 2;
    }
    return b;
}

void func_ov001_02185d1c(void *param_1) {
    data_ov001_021a9b9c = func_ov001_0219b478(param_1, "MissionGate.nsbmd");
    func_ov001_0219b2e8(data_ov001_021a9b9c, "MissionGate.nsbtp");
    func_ov001_0219b380(data_ov001_021a9b9c, "MissionGate.nsbma");
    func_0209b940(data_ov001_021a9b9c, 0x3f);
    func_0209ba08(data_ov001_021a9b9c, 2);
    func_020849a0(data_ov001_021a9b9c->mUnk_10, 0x294a);
}

void func_ov001_02185d18(void) {}

void func_ov001_02185ca0(void *param_1, Unk02185bb8 *param_2) {
    s32 buf;

    buf = 0x1e;
    func_01ff9048((u32) (0x14), (void *) ((u32) &buf), 1);
    param_2->mUnk_000.mUnk_28.mUnk_24.x = param_2->mUnk_000.mUnk_04.x >> 4;
    param_2->mUnk_000.mUnk_28.mUnk_24.y = param_2->mUnk_000.mUnk_04.y >> 4;
    param_2->mUnk_000.mUnk_28.mUnk_24.z = param_2->mUnk_000.mUnk_04.z >> 4;
    func_01ff9048((u32) (0x19), (void *) ((u32) &param_2->mUnk_000.mUnk_28), 0xc);
    func_01ff9048((u32) (0x1b), (void *) ((u32) &param_2->mUnk_000.mUnk_1c), 3);
    func_0209b688((void *) (data_ov001_021a9b9c), (u16) param_2->mUnk_000.mUnk_9c->mUnk_28);
    func_0209b734(data_ov001_021a9b9c, param_2->mUnk_0a8);
    func_0209bb2c((void *) ((u32) param_1), (void *) ((int) data_ov001_021a9b9c), (void *) ((int) param_2));
}

void func_ov001_02185c4c(Unk02185c4c *param_1) {
    s32 i;
    Unk02185bb8 *e;

    if (param_1) {
        for (i = 0; i < param_1->mUnk_04 && (e = param_1->mUnk_00[i]) != 0; i++) {
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

void func_ov001_02185bb8(void *param_1, Unk02185bb8 *param_2) {
    s32 pos;

    switch (param_2->mUnk_0ac) {
        case 0:
            pos = data_021759c0->mUnk_08 == 4 ? func_ov001_02181820() : 0;
            if (pos >= param_2->mUnk_000.mUnk_9c->mUnk_28 - 1) {
                param_2->mUnk_000.mUnk_02 &= ~1;
                param_2->mUnk_0ac = 1;
            }
            break;
        case 2:
            pos = func_0209b710(data_ov001_021a9b9c);
            param_2->mUnk_0a8++;
            if (param_2->mUnk_0a8 >= pos - 1) {
                param_2->mUnk_0a8 = func_0209b710(data_ov001_021a9b9c) - 1;
                param_2->mUnk_0ac = 1;
            }
            break;
    }
}

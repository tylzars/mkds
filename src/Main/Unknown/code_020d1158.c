#include "Main/Unknown/code_020d1158.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020b837c.h"
#include "code_020222ec.h"

void func_020d1198(Unk020d029c *a) {
    Unk020224e0_c *c;
    s32 q[2][2];

    *(vu32 *) 0x4000000 = *(vu32 *) 0x4000000 & ~0xe000;
    c = GetRaceStartBattleMNcerEntry(data_021759c0->mUnk_18 == 0 ? VALUE_0 : VALUE_1);
    q[0][0] = 0x80000;
    q[0][1] = 0x60000;
    a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q[0], 0, 1);
    c = GetRaceStartBattleMNcerEntry(2);
    q[1][0] = 0x80000;
    q[1][1] = 0x60000;
    a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q[1], 0, 1);
}

u16 *func_020d118c(void) {
    return (u16 *) 0x27ffc40;
}

u32 func_020d1164(void) {
    return *func_020d118c() == 2;
}

u32 func_020d1158(void) {
    return func_020d1164();
}

#include "Main/Unknown/code_020a8098.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020a826c.h"
#include "Main/Unknown/code_020a8a6c.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_0215d000.h"

u32 func_020a824c(void) {
    return func_0209bf48(func_020a8a6c, func_020a826c, NULL);
}

void func_020a8098(Unk020a7f18 *p) {
    s32 i;
    Unk020f41c4_B *r;
    u16 v1;
    u16 v2;

    for (i = 0; i < p->mUnk_1d0; i++) {
        r = func_020d22d0();
        r->mUnk_00 = (s64) r->mUnk_08 * (s64) r->mUnk_00 + r->mUnk_10;
        v1 = (u16) (((u64) (u32) (r->mUnk_00 >> 32) * 0x10000) >> 32);
        p->mUnk_0b0[i].mUnk_00.x = p->mUnk_000.mPos.x;
        p->mUnk_0b0[i].mUnk_00.y = p->mUnk_000.mPos.y + i * 0x14000;
        p->mUnk_0b0[i].mUnk_00.z = p->mUnk_000.mPos.z;
        p->mUnk_0b0[i].mUnk_0c.x = (s32) (((s64) gPairsByAngle[(v1 >> 4) * 2] * 0x2000) >> 12);
        p->mUnk_0b0[i].mUnk_0c.y = 0x4000;
        p->mUnk_0b0[i].mUnk_0c.z = (s32) (((s64) gPairsByAngle[(v1 >> 4) * 2 + 1] * 0x2000) >> 12);
        r = func_020d22d0();
        r->mUnk_00 = (s64) r->mUnk_08 * (s64) r->mUnk_00 + r->mUnk_10;
        v2 = (u16) (((u64) (u32) (r->mUnk_00 >> 32) * 2) >> 32);
        p->mUnk_0b0[i].mUnk_40 = (v2 != 0 ? 1 : -1) * 0xaab;
    }
    p->mUnk_0a8 = 300;
    p->mUnk_1fc = 2;
}

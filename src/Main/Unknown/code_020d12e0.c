#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c90.h"
#include "Main/Unknown/code_020d12e0.h"

#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "code_0200eddc.h"
#include "code_020222ec.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_020d1450.h"
#include "Main/Unknown/code_020d1464.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b47b4.h"
#include "code_02021e8c.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02037000.h"

void func_020d159c(void) {
    func_0200ee74(&gEndingStaffRoll->mUnk_10, 0x400);
    func_0214bfcc(&gEndingStaffRoll->mUnk_10, 0, 0x400);
    if (gEndingStaffRoll->mUnk_00 == 0x1a4) {
        func_02036fec(0x78, 1);
        return;
    }
    if (gEndingStaffRoll->mUnk_00 != 0x77a) {
        return;
    }
    func_020371a8(0x78, 1);
}

void InitEndingStaffRoll(void) {
    s32 i;
    Unk02021dc8 *a;
    u32 *w;

    gEndingStaffRoll = func_02036bec(func_020364e0(func_020364e8()), 0x414);
    for (i = 0; i < 0x80; i++) {
        w = (u32 *) &gEndingStaffRoll->mUnk_10.mUnk_000[i];
        w[0] = (w[0] & ~0xc00) | 0xc00;
    }
    gEndingStaffRoll->mUnk_00 = 0;
    LoadNclrData(&gEndingStaffRoll->mEndingStaffRollMO00Nclr, FindSceneFileWrapper("ending_staffRoll_m_o_00.NCLR"));
    LoadNcgrData2(&gEndingStaffRoll->mEndingStaffRollM00Ncgr, FindSceneFileWrapper("ending_staffRoll_m_00.nce.ncgr"));
    a = NULL;
    LoadNcerData(&a, FindSceneFileWrapper("ending_staffRoll_m_00.nce.ncer"));
    gEndingStaffRoll->mUnk_0c = (Unk020224e0_c *) func_02021f1c(a, 0);
    func_0214c090(gEndingStaffRoll->mEndingStaffRollMO00Nclr->mUnk_0c, 0,
                  gEndingStaffRoll->mEndingStaffRollMO00Nclr->mUnk_08);
    func_0214bf04(gEndingStaffRoll->mEndingStaffRollM00Ncgr->mUnk_14, 0,
                  gEndingStaffRoll->mEndingStaffRollM00Ncgr->mUnk_10);
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffcfffef) | 0x10;
}

u32 func_020d1450(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gEndingStaffRoll;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

u16 func_020d13f8(void) {
    if (gEndingStaffRoll->mUnk_00 < 0x7fffffff) {
        gEndingStaffRoll->mUnk_00++;
    }
    if (gEndingStaffRoll->mUnk_00 == 0x30c) {
        func_0212b1a8();
    }
    return *(vu16 *) 0x4000304;
}

void func_020d12e0(void) {
    Unk020d029c *b;
    s32 i;
    Unk020224e0_o *e;
    Unk0217b4ac *a;
    Unk020224e0_c *c;
    u32 *w;
    s32 q[2];

    gEndingStaffRoll->mUnk_10.mUnk_400 = 0;
    a = gEndingStaffRoll;
    if (a->mUnk_00 < 0x21c) {
        b = &a->mUnk_10;
        i = b->mUnk_400;
        c = a->mUnk_0c;
        q[0] = 0x80000;
        q[1] = 0x60000;
        e = &b->mUnk_000[i];
        b->mUnk_400 += func_020224e0(e, 0x80 - i, c, NULL, q, 0, 1);
        w = (u32 *) e;
        for (; i < b->mUnk_400; i++) {
            w[0] = (w[0] & ~0xc00) | 0x400;
            w[1] = (w[1] & ~0xc00) | 0x400;
            w += 2;
        }
    }
    func_0200ee74(&gEndingStaffRoll->mUnk_10, 0x400);
    func_0214cc04(3, &gEndingStaffRoll->mUnk_10.mUnk_000[gEndingStaffRoll->mUnk_10.mUnk_400], 0xc0,
                  (0x80 - gEndingStaffRoll->mUnk_10.mUnk_400) << 3);
}

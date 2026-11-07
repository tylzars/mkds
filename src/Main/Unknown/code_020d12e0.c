#include "Main/Unknown/code_020d12e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"

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
#include "g2d_NOB_load.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02037000.h"
#include "registers.h"

void func_020d159c(void) {
    DC_FlushRange(&gEndingStaffRoll->mUnk_10, 0x400);
    GX_LoadOAM(&gEndingStaffRoll->mUnk_10, 0, 0x400);
    if (gEndingStaffRoll->mUnk_00 == 0x1a4) {
        StartFadeToFadedNegativeOneScreen(0x78, 1);
        return;
    }
    if (gEndingStaffRoll->mUnk_00 != 0x77a) {
        return;
    }
    StartFadeToClearNegativeOneScreen(0x78, 1);
}

void InitEndingStaffRoll(void) {
    s32 i;
    Unk02021dc8 *a;
    u32 *w;

    gEndingStaffRoll = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x414);
    for (i = 0; i < 0x80; i++) {
        w = (u32 *) &gEndingStaffRoll->mUnk_10.mOams[i];
        w[0] = (w[0] & ~0xc00) | 0xc00;
    }
    gEndingStaffRoll->mUnk_00 = 0;
    LoadNclrData(&gEndingStaffRoll->mEndingStaffRollMO00Nclr, FindSceneFileWrapper("ending_staffRoll_m_o_00.NCLR"));
    LoadNcgrData2(&gEndingStaffRoll->mEndingStaffRollM00Ncgr, FindSceneFileWrapper("ending_staffRoll_m_00.nce.ncgr"));
    a = NULL;
    LoadNcerData(&a, FindSceneFileWrapper("ending_staffRoll_m_00.nce.ncer"));
    gEndingStaffRoll->mUnk_0c = NNS_G2dGetCellDataByIdx(a, 0);
    GX_LoadOBJPltt(gEndingStaffRoll->mEndingStaffRollMO00Nclr->mData, 0,
                   gEndingStaffRoll->mEndingStaffRollMO00Nclr->mDataSize);
    GX_LoadOBJ(gEndingStaffRoll->mEndingStaffRollM00Ncgr->mData, 0,
               gEndingStaffRoll->mEndingStaffRollM00Ncgr->mDataSize);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
}

u32 func_020d1450(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gEndingStaffRoll;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

u16 UpdateEndingStaffRoll(void) {
    if (gEndingStaffRoll->mUnk_00 < 0x7fffffff) {
        gEndingStaffRoll->mUnk_00++;
    }
    if (gEndingStaffRoll->mUnk_00 == 0x30c) {
        StartStaffRollText();
    }
    return reg_GX_POWCNT;
}

void DrawEndingStaffRoll(void) {
    RaceHudOamBuffer *b;
    s32 i;
    GXOamAttr *e;
    Unk0217b4ac *a;
    Unk020224e0_c *c;
    u32 *w;
    s32 q[2];

    gEndingStaffRoll->mUnk_10.mOamCount = 0;
    a = gEndingStaffRoll;
    if (a->mUnk_00 < 0x21c) {
        b = &a->mUnk_10;
        i = b->mOamCount;
        c = a->mUnk_0c;
        q[0] = 0x80000;
        q[1] = 0x60000;
        e = &b->mOams[i];
        b->mOamCount += NNS_G2dMakeCellToOams(e, 0x80 - i, c, NULL, q, 0, 1);
        w = (u32 *) e;
        for (; i < b->mOamCount; i++) {
            w[0] = (w[0] & ~0xc00) | 0x400;
            w[1] = (w[1] & ~0xc00) | 0x400;
            w += 2;
        }
    }
    DC_FlushRange(&gEndingStaffRoll->mUnk_10, 0x400);
    MI_DmaFill32(3, &gEndingStaffRoll->mUnk_10.mOams[gEndingStaffRoll->mUnk_10.mOamCount], 0xc0,
                 (0x80 - gEndingStaffRoll->mUnk_10.mOamCount) << 3);
}

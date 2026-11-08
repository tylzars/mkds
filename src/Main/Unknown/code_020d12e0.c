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
    DC_FlushRange(&gEndingStaffRoll->mOamBuffer, 0x400);
    GX_LoadOAM(&gEndingStaffRoll->mOamBuffer, 0, 0x400);
    if (gEndingStaffRoll->mStaffRollFrames == 0x1a4) {
        StartFadeToFadedNegativeOneScreen(0x78, 1);
        return;
    }
    if (gEndingStaffRoll->mStaffRollFrames != 0x77a) {
        return;
    }
    StartFadeToClearNegativeOneScreen(0x78, 1);
}

void InitEndingStaffRoll(void) {
    s32 i;
    Unk02021dc8 *cells;
    u32 *oamWords;

    gEndingStaffRoll = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x414);
    for (i = 0; i < 0x80; i++) {
        oamWords = (u32 *) &gEndingStaffRoll->mOamBuffer.mOams[i];
        oamWords[0] = (oamWords[0] & ~0xc00) | 0xc00;
    }
    gEndingStaffRoll->mStaffRollFrames = 0;
    LoadNclrData(&gEndingStaffRoll->mEndingStaffRollMO00Nclr, FindSceneFileWrapper("ending_staffRoll_m_o_00.NCLR"));
    LoadNcgrData2(&gEndingStaffRoll->mEndingStaffRollM00Ncgr, FindSceneFileWrapper("ending_staffRoll_m_00.nce.ncgr"));
    cells = NULL;
    LoadNcerData(&cells, FindSceneFileWrapper("ending_staffRoll_m_00.nce.ncer"));
    gEndingStaffRoll->mCell = NNS_G2dGetCellDataByIdx(cells, 0);
    GX_LoadOBJPltt(gEndingStaffRoll->mEndingStaffRollMO00Nclr->mData, 0,
                   gEndingStaffRoll->mEndingStaffRollMO00Nclr->mDataSize);
    GX_LoadOBJ(gEndingStaffRoll->mEndingStaffRollM00Ncgr->mData, 0,
               gEndingStaffRoll->mEndingStaffRollM00Ncgr->mDataSize);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
}

u32 ClearEndingStaffRollPointer(void) {
    u32 address;
    u32 zero;
    address = (u32) &gEndingStaffRoll;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

u16 UpdateEndingStaffRoll(void) {
    if (gEndingStaffRoll->mStaffRollFrames < 0x7fffffff) {
        gEndingStaffRoll->mStaffRollFrames++;
    }
    if (gEndingStaffRoll->mStaffRollFrames == 0x30c) {
        StartStaffRollText();
    }
    return reg_GX_POWCNT;
}

void DrawEndingStaffRoll(void) {
    RaceHudOamBuffer *oamBuffer;
    s32 i;
    GXOamAttr *firstNewOam;
    EndingStaffRollObject *staffRoll;
    Unk020224e0_c *cell;
    u32 *oamWords;
    s32 position[2];

    gEndingStaffRoll->mOamBuffer.mOamCount = 0;
    staffRoll = gEndingStaffRoll;
    if (staffRoll->mStaffRollFrames < 0x21c) {
        oamBuffer = &staffRoll->mOamBuffer;
        i = oamBuffer->mOamCount;
        cell = staffRoll->mCell;
        position[0] = 0x80000;
        position[1] = 0x60000;
        firstNewOam = &oamBuffer->mOams[i];
        oamBuffer->mOamCount += NNS_G2dMakeCellToOams(firstNewOam, 0x80 - i, cell, NULL, position, 0, 1);
        oamWords = (u32 *) firstNewOam;
        for (; i < oamBuffer->mOamCount; i++) {
            oamWords[0] = (oamWords[0] & ~0xc00) | 0x400;
            oamWords[1] = (oamWords[1] & ~0xc00) | 0x400;
            oamWords += 2;
        }
    }
    DC_FlushRange(&gEndingStaffRoll->mOamBuffer, 0x400);
    MI_DmaFill32(3, &gEndingStaffRoll->mOamBuffer.mOams[gEndingStaffRoll->mOamBuffer.mOamCount], 0xc0,
                 (0x80 - gEndingStaffRoll->mOamBuffer.mOamCount) << 3);
}

#include "Main/Unknown/code_02029008.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02028724.h"
#include "Main/Unknown/code_02028774.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_020291f0.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on
#pragma thumb on
s32 UpdateSelectKartTouchHold(void) {
    s32 result = -1;
    Unk02174e50_24 *p = &gSelectKart->mSelectKartSParts;
    u16 slotIndex = func_020435bc();
    s32 pairX;
    s32 pairY;
    s32 rectIndex;
    if (gSelectKart->mTouchHeld != FALSE) {
        if (func_020291f0(slotIndex) != 0) {
            pairX = func_0202874c(slotIndex);
            pairY = func_02028724(slotIndex);
            rectIndex = FindRectContainingPoint(pairX, pairY, p->mUnk_10);
            if (rectIndex != gSelectKart->mTouchRect) {
                gSelectKart->mTouchHeld = FALSE;
                gSelectKart->mTouchHeldFrames = 0;
            } else {
                gSelectKart->mTouchHeldFrames++;
                result = rectIndex;
            }
        } else {
            gSelectKart->mTouchHeld = FALSE;
            gSelectKart->mTouchHeldFrames = 0;
        }
    } else if (func_02028774(slotIndex) != 0) {
        result = FindRectContainingPoint(func_0202874c(slotIndex), func_02028724(slotIndex), p->mUnk_10);
        gSelectKart->mTouchHeld = TRUE;
        gSelectKart->mTouchHeldFrames = 0;
    }
    return result;
}

u32 IsSelectKartTouchRepeat(s32 rectIndex) {
    u32 result = 0;
    u32 repeatDue;
    SelectKart *d = gSelectKart;
    s32 heldFrames;
    if (d->mTouchRect == rectIndex) {
        heldFrames = d->mTouchHeldFrames;
        result |= (heldFrames == 0);
        repeatDue = 0;
        if (heldFrames >= 0x3c) {
            if ((heldFrames - 0x3c) % 0xf == 0) {
                repeatDue = 1;
            }
        }
        result |= repeatDue;
    }
    return result;
}

void func_02029008(void) {
    SelectKart *d = gSelectKart;
    Unk02174e50_24 *p;
    if (d->mUnk_104 == FALSE) {
        p = &d->mSelectCharacterGpMParts;
        p->mUnk_18[1].mUnk_04 = func_02025ebc(&d->mUnk_0ac[0]);
        p->mUnk_18[2].mUnk_04 = p->mUnk_18[1].mUnk_04;
        p->mUnk_18[0].mUnk_06 = func_02025ebc(&gSelectKart->mUnk_0ac[1]);
        p->mUnk_18[3].mUnk_06 = func_02025ebc(&gSelectKart->mUnk_0ac[2]);
        p->mUnk_18[9].mUnk_06 = func_02025ebc(&gSelectKart->mUnk_0ac[3]);
        p->mUnk_18[8].mUnk_06 = p->mUnk_18[9].mUnk_06;
        p->mUnk_18[7].mUnk_06 = p->mUnk_18[8].mUnk_06;
        p->mUnk_18[6].mUnk_06 = p->mUnk_18[7].mUnk_06;
        p->mUnk_18[5].mUnk_06 = p->mUnk_18[6].mUnk_06;
        p->mUnk_18[4].mUnk_06 = p->mUnk_18[5].mUnk_06;
    }
}
#pragma thumb off

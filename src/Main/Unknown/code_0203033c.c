#include "Main/Unknown/code_0203033c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02030000.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

#include "Main/Unknown/code_020302a0.h"
#include "Main/Unknown/code_0202f688.h"
#include "Main/Unknown/code_02030708.h"
#include "Main/Unknown/code_020307b8.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_020ade08.h"
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
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_02174000.h"

u32 func_02030700(u32 p0) {
    return (*OFFSET_PTR(const u16, p0, 0));
}

u32 func_020306e0(u32 slotIndex) {
    u32 value0 = slotIndex;
    u32 value1;
    u32 slotsAddress;
    u32 calleeAddress;
    slotsAddress = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (slotsAddress);
    calleeAddress = (u32) &func_02030700;
    value0 = (value1) + (0x48u);
    value0 = func_02030700(value0);
    return value0;
}

u32 func_020306d8(u32 p0) {
    return (*OFFSET_PTR(const u16, p0, 2));
}

u32 func_020306b8(u32 slotIndex) {
    u32 value0 = slotIndex;
    u32 value1;
    u32 slotsAddress;
    u32 calleeAddress;
    slotsAddress = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (slotsAddress);
    calleeAddress = (u32) &func_020306d8;
    value0 = (value1) + (0x48u);
    value0 = func_020306d8(value0);
    return value0;
}

u16 func_020306a4(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u32 func_02030688(u32 slotIndex, u32 mask) {
    return func_020306a4(&data_02175628[slotIndex], mask);
}

void func_02030654(u32 index) {
    NNS_SndArcSetCurrent((NNSSndArc *) (((u32) (&data_0217c868))));
    func_0203063c(index, 0);
    NNS_SndArcSetCurrent((NNSSndArc *) (((u32) (&data_0217d0a0))));
}

void func_0203063c(u32 index, u32 seqArcNo) {
    u32 value0 = index;
    u32 value1 = seqArcNo;
    u32 indexCopy;
    u32 value12;
    indexCopy = value0;
    value0 = (u32) &data_0217d068;
    value0 = NNS_SndArcPlayerStartSeqArc((const void *) value0, value1, indexCopy);
}

void func_0203062c(u32 index) {
    u32 value0 = index;
    u32 value1;
    u32 value12;
    value1 = 0u;
    func_0203063c(value0, value1);
}

#pragma thumb on

s32 AdvanceMultiSelectNS(void) {
    MultiSelectNS *multiSelectNS;
    s32 result;
    s32 touchInReturnRect;
    s32 b;
    s32 pairY;
    u16 slotIndex;

    result = -1;
    slotIndex = func_020435bc();
    multiSelectNS = gMultiSelectNS;
    switch (multiSelectNS->mState) {
        case 0:
            multiSelectNS->mStateFrames++;
            if (gMultiSelectNS->mStateFrames < 10) {
                gMultiSelectNS->mOffset = InterpolateS16(1, -0xc0, 0, gMultiSelectNS->mStateFrames, 10);
            } else {
                gMultiSelectNS->mStateFrames = 0;
                gMultiSelectNS->mOffset = 0;
                gMultiSelectNS->mState = 1;
            }
            SetMultiSelectNSCellTableOffsetY();
            break;
        case 1:
            touchInReturnRect = 0;
            b = -1;
            if (func_02030708(slotIndex) != 0) {
                b = func_020306e0(slotIndex);
                pairY = func_020306b8(slotIndex);
                touchInReturnRect = IsSelectReturnState2NoState3Or4RequestAndInRect(b, pairY);
                b = FindRectContainingPoint(b, pairY, multiSelectNS->mBnbl);
            }
            if (func_02030688(slotIndex, PAD_KEY_A) != 0) {
                func_0204aa28(gMultiSelectNS->mIndex == 1 ? 1 : 0);
                gMultiSelectNS->mNextCallbacksIndex = 2;
                gMultiSelectNS->mState = 2;
                RefreshMultiSelectNS(0);
                func_02030654(4);
            } else if (func_02030688(slotIndex, PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                gMultiSelectNS->mNextCallbacksIndex = 0;
                gMultiSelectNS->mState = 3;
                RequestSelectReturnState3WithSound(0);
            } else if (func_02030688(slotIndex, PAD_KEY_UP) != 0 && gMultiSelectNS->mIndex > 0) {
                gMultiSelectNS->mIndex--;
                RefreshMultiSelectNS(1);
                func_0203062c(0);
            } else if (func_02030688(slotIndex, PAD_KEY_DOWN) != 0 && gMultiSelectNS->mIndex < 1) {
                gMultiSelectNS->mIndex++;
                RefreshMultiSelectNS(1);
                func_0203062c(0);
            } else if (b == 0) {
                gMultiSelectNS->mState = 2;
                RefreshMultiSelectNS(gMultiSelectNS->mIndex != 0 ? 1 : 0);
                func_02030654(4);
                gMultiSelectNS->mIndex = 0;
                func_0204aa28(0);
                gMultiSelectNS->mNextCallbacksIndex = 2;
            } else if (b == 1) {
                gMultiSelectNS->mState = 2;
                RefreshMultiSelectNS(gMultiSelectNS->mIndex != 1 ? 1 : 0);
                func_02030654(4);
                gMultiSelectNS->mIndex = 1;
                func_0204aa28(1);
                gMultiSelectNS->mNextCallbacksIndex = 2;
            }
            break;
        case 2:
            multiSelectNS->mStateFrames++;
            if (gMultiSelectNS->mStateFrames >= 5) {
                gMultiSelectNS->mStateFrames = 0;
                gMultiSelectNS->mState = 3;
                RefreshMultiSelectNS(1);
            }
            break;
        case 3:
            multiSelectNS->mStateFrames++;
            if (gMultiSelectNS->mStateFrames < 10) {
                gMultiSelectNS->mOffset = InterpolateS16(1, 0, -0xc0, gMultiSelectNS->mStateFrames, 10);
            } else {
                gMultiSelectNS->mOffset = 0;
                gMultiSelectNS->mState = 4;
            }
            SetMultiSelectNSCellTableOffsetY();
            break;
        case 4:
            result = multiSelectNS->mNextCallbacksIndex;
            break;
    }
    if (gMultiSelectNS->mState != 4) {
        DrawLayoutTable(multiSelectNS->mBncl, multiSelectNS->mNcer, multiSelectNS->mBnll, gMultiSelectNS->mOamList,
                        multiSelectNS->mCellTable);
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseMultiSelectNS(void) {
    func_0204f7f4();
    HeapDestroy(gMultiSelectNS->mHeap);
    gMultiSelectNS = NULL;
}

#pragma thumb off

u32 func_020303a8(u32 bits) {
    u32 value0 = bits;
    u32 maskedRegister;
    u32 registerAddress;
    registerAddress = 0x4001000u;
    maskedRegister = *(const u32 *) ((registerAddress) + (0));
    maskedRegister = (maskedRegister) & ~(0x1f00u);
    value0 = (maskedRegister) | ((value0 << 8));
    *(u32 *) ((registerAddress) + (0)) = value0;
    return value0;
}

u32 func_0203038c(u32 bits) {
    u32 value0 = bits;
    u32 maskedRegister;
    u32 registerAddress;
    registerAddress = 0x4001000u;
    maskedRegister = *(const u32 *) ((registerAddress) + (0));
    maskedRegister = (maskedRegister) & ~(0xe000u);
    value0 = (maskedRegister) | ((value0 << 13));
    *(u32 *) ((registerAddress) + (0)) = value0;
    return value0;
}

u32 func_02030364(u32 lowBits, u32 extraBitFlag) {
    u32 value0 = lowBits;
    u32 value1 = extraBitFlag;
    u32 registerAddress;
    u32 flagCopy;
    u32 zero;
    registerAddress = 0x4001048u;
    flagCopy = value1;
    zero = 0u;
    value1 = *(const u16 *) ((registerAddress) + (0));
    value1 = (value1) & ~(0x3fu);
    value1 = (value1) | (value0);
    value0 = 0x4001048u;
    if (flagCopy != zero) {
        value1 = (value1) | (0x20u);
    }
    *(u16 *) ((value0) + (0)) = value1;
    return value0;
}

u32 func_0203033c(u32 lowBits, u32 extraBitFlag) {
    u32 value0 = lowBits;
    u32 value1 = extraBitFlag;
    u32 registerAddress;
    u32 flagCopy;
    u32 zero;
    registerAddress = 0x400104au;
    flagCopy = value1;
    zero = 0u;
    value1 = *(const u16 *) ((registerAddress) + (0));
    value1 = (value1) & ~(0x3fu);
    value1 = (value1) | (value0);
    value0 = 0x400104au;
    if (flagCopy != zero) {
        value1 = (value1) | (0x20u);
    }
    *(u16 *) ((value0) + (0)) = value1;
    return value0;
}

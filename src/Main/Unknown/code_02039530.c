#include "Main/Unknown/code_02039530.h"
#include "Main/Unknown/code_02039230.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_0200f5ac.h"

void func_02039530(u32 a, InputSlot *b) {
    u16 c;
    if (b->mUnk_20 != 0) {
        func_020392c8(a);
    }
    b->mUnk_00 = a & (a ^ b->mBits);
    b->mClearedBits = (a ^ 0xffff) & (a ^ b->mBits);
    b->mBits = a;
    b->mRepeatBits = 0;
    switch (b->mRepeatState) {
        case 0:
            if (a & b->mRepeatMask) {
                b->mRepeatState = 1;
                b->mRepeatCallCount = 0;
                b->mRepeatBits = a & b->mRepeatMask;
            }
            break;
        case 1:
            if (a & b->mRepeatMask) {
                b->mRepeatCallCount++;
                if (b->mRepeatCallCount >= b->mRepeatDelayLimit) {
                    b->mRepeatState = 2;
                    b->mRepeatCallCount = 0;
                    b->mRepeatBits = a & b->mRepeatMask;
                }
            } else {
                b->mRepeatState = 0;
            }
            break;
        case 2:
            if (a & b->mRepeatMask) {
                b->mRepeatCallCount++;
                if (b->mRepeatCallCount >= b->mRepeatIntervalLimit) {
                    b->mRepeatCallCount = 0;
                    b->mRepeatBits = a & b->mRepeatMask;
                }
            } else {
                b->mRepeatState = 0;
            }
            break;
    }
    c = b->mBits & 0x30c;
    if (b->mUnk_14 != 0 && c == 0x30c) {
        if (b->mUnk_00 & 0x30c) {
            b->mUnk_18 = OS_GetTick();
            b->mUnk_12 = 0;
            return;
        }
        if (b->mUnk_12 != 0) {
            return;
        }
        if ((u32) (OS_GetTick() - b->mUnk_18) > 0x3fec4) {
            b->mUnk_12 = 1;
        }
        return;
    }
    if (c != 0x30c) {
        b->mUnk_14 = 1;
    }
    b->mUnk_12 = 0;
}

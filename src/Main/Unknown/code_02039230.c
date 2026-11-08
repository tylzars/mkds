#include "Main/Unknown/code_02039230.h"
#include "Main/Unknown/code_02039530.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/unk_02175000.h"

void func_020394cc(void) {
    data_021755dc.mUnk_00 = 0;
    data_021755dc.mBits = 0;
    data_021755dc.mClearedBits = 0;
    data_021755dc.mRepeatBits = 0;
    data_021755dc.mRepeatState = 0;
    data_021755dc.mRepeatCallCount = 0;
    data_021755dc.mRepeatMask = 0;
    data_021755dc.mRepeatDelayLimit = 0x14;
    data_021755dc.mRepeatIntervalLimit = 8;
    data_021755dc.mHoldLong = 0;
    data_021755dc.mUnk_14 = 0;
    data_021755dc.mHoldStartTick = 0;
    data_021755dc.mUnk_20 = 0;
    data_021755dc.mUnk_24 = 0;
}

void func_02039478(void) {
    data_021755dc.mUnk_00 = 0;
    data_021755dc.mBits = 0;
    data_021755dc.mClearedBits = 0;
    data_021755dc.mRepeatBits = 0;
    data_021755dc.mRepeatState = 0;
    data_021755dc.mRepeatCallCount = 0;
    data_021755dc.mRepeatMask = 0;
    data_021755dc.mRepeatDelayLimit = 0x14;
    data_021755dc.mRepeatIntervalLimit = 8;
    data_021755dc.mHoldLong = 0;
    data_021755dc.mUnk_14 = 0;
    data_021755dc.mHoldStartTick = 0;
    data_021755dc.mUnk_20 = 0;
    data_021755dc.mUnk_24 = 0;
}

void ReadKeysIntoInputSlot(void) {
    u32 keys;
    if (data_021755dc.mUnk_24 != 0) {
        keys = ReadKeyBitsFromStream();
    } else {
        keys = (u16) (((*(vu16 *) 0x4000130 | *(vu16 *) 0x27fffa8) ^ 0x2fff) & 0x2fff);
    }
    UpdateInputSlot(keys, &data_021755dc);
}

void SeekKeyStream(u32 count, u32 origin) {
    u32 elementSize = gKeyStream.mElementSize;
    u8 *newPosition;
    u8 *start;
    switch (origin) {
        case 2:
            newPosition = gKeyStream.mHighestWritten - count * elementSize;
            break;
        case 0:
            newPosition = gKeyStream.mStart + count * elementSize;
            break;
        case 1:
            newPosition = gKeyStream.mPosition + count * elementSize;
            break;
    }
    start = gKeyStream.mStart;
    if (newPosition < start) {
        newPosition = start;
    }
    if (gKeyStream.mEnd < newPosition + elementSize) {
        newPosition = start + elementSize * ((u32) (gKeyStream.mEnd - start) / elementSize);
    }
    gKeyStream.mPosition = newPosition;
}

void WriteKeyBitsToStream(u32 keys) {
    u32 elementSize = gKeyStream.mElementSize;
    u32 keyBit;
    u32 packedBit;
    u8 *position = gKeyStream.mPosition;
    u16 keyMask;
    u16 keyBitCopy;
    u32 packed;
    if (position + elementSize > gKeyStream.mEnd) {
        return;
    }
    if (elementSize == 1) {
        keyMask = gKeyStream.mKeyMask;
        keyBit = 1;
        packedBit = 1;
        packed = 0;
        for (; keyBit < 0x10000; keyBit <<= 1) {
            keyBitCopy = keyBit;
            if (keyBitCopy & keyMask) {
                if (keyBitCopy & keys) {
                    packed |= packedBit;
                }
                packedBit = (packedBit << 1) & 0xff;
                if (packedBit == 0) {
                    break;
                }
            }
        }
        *position = packed;
    } else {
        *(u16 *) position = keys;
    }
    SeekKeyStream(1, 1);
    if (gKeyStream.mPosition > gKeyStream.mHighestWritten) {
        gKeyStream.mHighestWritten = gKeyStream.mPosition;
    }
}

u32 ReadKeyBitsFromStream(void) {
    u32 keys;
    u32 keyBit;
    u32 packedBit;
    s32 packed;
    u16 keyBitCopy;
    u16 keyMask;
    if (gKeyStream.mPosition + gKeyStream.mElementSize > gKeyStream.mEnd) {
        return 0;
    }
    if (gKeyStream.mElementSize == 1) {
        packed = *gKeyStream.mPosition;
        keyBit = 1;
        keyMask = gKeyStream.mKeyMask;
        packedBit = 1;
        keys = 0;
        for (; keyBit < 0x10000; keyBit <<= 1) {
            keyBitCopy = keyBit;
            if (keyBitCopy & keyMask) {
                if (packedBit & packed) {
                    keys |= keyBitCopy;
                }
                packedBit = (packedBit << 1) & 0xff;
                if (packedBit == 0) {
                    break;
                }
            }
        }
    } else {
        keys = *(u16 *) gKeyStream.mPosition;
    }
    SeekKeyStream(1, 1);
    return keys;
}

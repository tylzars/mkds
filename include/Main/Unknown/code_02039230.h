#pragma once

#include "types.h"

// Byte stream at gKeyStream: mUnk_00 to mUnk_04 bound the buffer, mUnk_08 is the position, mUnk_0c the highest
// position written, mUnk_14 the element size, mUnk_18 the mask of bits ReadKeyBitsFromStream and WriteKeyBitsToStream
// move.
typedef struct KeyStream {
    /* 00 */ u8 *mStart;
    /* 04 */ u8 *mEnd;
    /* 08 */ u8 *mPosition;
    /* 0c */ u8 *mHighestWritten;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mElementSize;
    /* 18 */ u16 mKeyMask;
} KeyStream;

extern KeyStream gKeyStream;

u32 ReadKeyBitsFromStream(void);
void WriteKeyBitsToStream(u32 keys);
void SeekKeyStream(u32 count, u32 origin);
void ReadKeysIntoInputSlot(void);
void func_02039478(void);
void func_020394cc(void);

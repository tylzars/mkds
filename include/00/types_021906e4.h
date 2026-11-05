#pragma once

#include "types.h"

// Growable byte buffer: 0x00 data, 0x04 capacity, 0x08 length, 0x0c read position.
typedef struct GpiBuffer {
    /* 00 */ u8 *mBuffer;
    /* 04 */ s32 mCapacity;
    /* 08 */ s32 mLength;
    /* 0c */ s32 mPos;
} GpiBuffer;

// Callback and its argument, as stored in the object at 0x1a4 and passed by value to GpiQueueCallback.
typedef struct GpiCallback {
    /* 00 */ void (*mCallback)(void *a, void *b, u32 c);
    /* 04 */ u32 mUnk_04;
} GpiCallback;

// Data behind GpiQueuedCallback.mArg: the members freed depend on the value at 0x0c.
typedef struct Unk02190da0Data {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s32 mUnk_04;
    /* 08 */ void **mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ u8 mUnk_14[0x24];
    /* 38 */ s32 mUnk_38;
    /* 3c */ void **mUnk_3c;
    /* 40 */ void **mUnk_40;
} Unk02190da0Data;

// Entry of the list whose head and tail are at 0x438 and 0x43c of the object.
typedef struct GpiQueuedCallback {
    /* 00 */ GpiCallback mCallback;
    /* 08 */ struct Unk02190da0Data *mArg;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ struct GpiQueuedCallback *mNext;
} GpiQueuedCallback;

// Object whose 0x28 member is a buffer; 0x08 is the descriptor written to.
typedef struct Unk02190988 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ s32 mSocket;
    /* 0c */ u8 mUnk_0c[0x1c];
    /* 28 */ GpiBuffer mOutputBuffer;
    /* 38 */ u32 *mQueuedMessages;
} Unk02190988;

// Object at 0x04 of GpiOperation.
typedef struct Unk02191284Data {
    /* 000 */ char mUnk_000[0x80];
    /* 080 */ char mUnk_80[0x21];
    /* 0a1 */ char mUnk_a1[0x21];
    /* 0c2 */ s8 mUnk_c2[0x200];
    /* 2c2 */ s8 mUnk_2c2[0x42];
    /* 304 */ s32 mUnk_304;
} Unk02191284Data;

// Object GpiQueueErrorCallback allocates and hands to GpiQueueCallback.
typedef struct Unk02190f4c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk02190f4c;

// Object GpiProcessConnectOperation allocates and hands to GpiQueueCallback.
typedef struct Unk02191284Node {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ char mUnk_08[0x18];
} Unk02191284Node;

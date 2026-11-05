#pragma once

#include "types.h"
#include "code_0200db4c.h"

typedef struct Http Http;
typedef struct ThreadLock ThreadLock;

// Block of four words: mStart is the first byte, mCursor the cursor, mEnd the end, mSize the size.
typedef struct Unk02186d7cBuf {
    /* 00 */ char *mStart;
    /* 04 */ char *mCursor;
    /* 08 */ char *mEnd;
    /* 0c */ u32 mSize;
} Unk02186d7cBuf;

// Object at p + 0x118 of an Unk02186d7c.
typedef struct Unk02186d7c118 {
    /* 000 */ u8 pad_000[0x7d4];
    /* 7d4 */ u32 mUnk_7d4;
    /* 7d8 */ u8 pad_7d8[0xc];
    /* 7e4 */ u32 (*mUnk_7e4)(u32);
    /* 7e8 */ u8 pad_7e8[0x1c];
} Unk02186d7c118;

// Object at p + 0xb4 of an Unk02186d7c.
typedef struct Unk02186d7cB4 {
    /* 00 */ u8 pad_00[0xc];
    /* 0c */ Unk02186d7c118 *mUnk_0c;
    /* 10 */ u8 pad_10[0x2c];
    /* 3c */ u32 mReceiveBufferSize;
    /* 40 */ void *mReceiveBuffer;
    /* 44 */ u8 pad_44[4];
    /* 48 */ u32 mSendBufferSize;
    /* 4c */ void *mSendBuffer;
    /* 50 */ u8 pad_50[0x14];
} Unk02186d7cB4;

// Written to mUnk_04 of an Unk02186d7c by func_ov000_021873d4.
typedef struct Unk021873d4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ char *mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ void *(*mUnk_10)();
    /* 14 */ void (*mUnk_14)();
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk021873d4;

typedef struct Unk02186d7c {
    /* 000 */ u8 mUnk_00;
    /* 004 */ Unk021873d4 mUnk_04;
    /* 024 */ s32 mResult;
    /* 028 */ u8 pad_028[0x80];
    /* 0a8 */ u32 mHost;
    /* 0ac */ u8 pad_0ac[4];
    /* 0b0 */ s32 mUseHttps;
    /* 0b4 */ Unk02186d7cB4 mUnk_b4;
    /* 118 */ Unk02186d7c118 mUnk_118;
    /* 91c */ void *mLowReceiveBuffer;
    /* 920 */ void *mLowSendBuffer;
    /* 924 */ u8 pad_924[4];
    /* 928 */ Unk02186d7cBuf mSendBuffer;
    /* 938 */ Unk02186d7cBuf mReceiveBuffer;
    /* 948 */ ThreadLock mUnk_948;
    /* 960 */ s32 mContentLength;
    /* 964 */ const char *mBodyStart;
    /* 968 */ Thread mThread;
    /* a20 */ u8 pad_a20[8];
    /* a28 */ ThreadLock mUnk_a28;
    /* a40 */ BOOL mUnk_a40;
    /* a44 */ u8 pad_a44[0x101c];
    /* 1a60 */ u8 mUnk_1a60[0x1000];
} Unk02186d7c;

extern char data_ov000_021b1204[];
extern char data_ov000_021b1230[];
extern char data_ov000_021b1258[];
extern char data_ov000_021b1348[];
extern char data_ov000_021b135c[];
extern char data_ov000_021b1368[];
extern const char data_ov000_021b1370[];
extern char data_ov000_021b1374[];
extern u32 data_ov000_021b4ca8;

void ReleaseHttp(Http *a);
void func_ov000_02186d7c(void *l);
u32 func_ov000_02187230(Unk02186d7c *a);
void func_ov000_02187274(Unk02186d7c *p);
void func_ov000_021872bc(Unk02186d7c *p);
u32 func_ov000_0218735c(Unk02186d7c *p);
s32 func_ov000_021873d4(Unk02186d7c *p, const Unk021873d4 *q);

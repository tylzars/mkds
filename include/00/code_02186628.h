#pragma once

#include "types.h"

// Declared here until the code that defines them is decompiled.

typedef struct Unk021868a4Entry {
    /* 00 */ void *mFirst;
    /* 04 */ void *mSecond;
} Unk021868a4Entry;

typedef struct Unk021868a4 {
    /* 00 */ Unk021868a4Entry *mEntries;
    /* 04 */ s32 mCapacity;
    /* 08 */ s32 mCount;
} Unk021868a4;

#include "code_0200db4c.h"

// Growing buffer: mUnk_00 is its start, mUnk_04 the write position, mUnk_08 the end and mUnk_0c the size.
typedef struct HttpBuffer {
    /* 00 */ char *mStart;
    /* 04 */ char *mCursor;
    /* 08 */ char *mEnd;
    /* 0c */ s32 mSize;
} HttpBuffer;

// 0x1a60 bytes; mUnk_014 and mUnk_018 allocate and release the memory of its buffers.
typedef struct Http {
    /* 000 */ u8 mUnk_000[8];
    /* 008 */ s32 mUseGet;
    /* 00c */ s32 mGivenReceiveBuffer;
    /* 010 */ u8 mUnk_010[4];
    /* 014 */ void *(*mAllocate)(const void *, s32);
    /* 018 */ void (*mFree)(const void *, void *, s32);
    /* 01c */ u8 mUnk_01c[8];
    /* 024 */ s32 mResult;
    /* 028 */ char mUnk_028[0x80];
    /* 0a8 */ char *mHost;
    /* 0ac */ char *mPath;
    /* 0b0 */ s32 mUseHttps;
    /* 0b4 */ u8 mUnk_0b4[0x868];
    /* 91c */ void *mLowReceiveBuffer;
    /* 920 */ void *mLowSendBuffer;
    /* 924 */ s32 mPairCount;
    /* 928 */ HttpBuffer mSendBuffer;
    /* 938 */ HttpBuffer mReceiveBuffer;
    /* 948 */ u8 mUnk_948[0x20];
    /* 968 */ Unk0200db5c mThread;
    /* a20 */ u8 mUnk_a20[0x1040];
} Http;

void func_ov000_02186628(const void *a);
BOOL func_ov000_02186634(Unk021868a4Entry *a, s32 b, const char *c, char *d, s32 e);
s32 func_ov000_02186674(Unk021868a4Entry *a, s32 b, const char *c, char *d, s32 e);
void *func_ov000_021866b8(Unk021868a4Entry *a, s32 b, const char *c);
BOOL func_ov000_021866fc(Unk021868a4Entry *a, s32 b, s32 c, const char *d);
BOOL func_ov000_021868a4(Unk021868a4 *list, void *first, void *second);
BOOL func_ov000_021868d0(Http *a, const char *b);
u32 GrowHttpBuffer(Http *a, HttpBuffer *b, int c);
void FreeHttpBuffer(Http *a, HttpBuffer *b);
u32 InitHttpBuffer(Http *a, HttpBuffer *b, int c);
u32 func_ov000_02186a84(u32 value);

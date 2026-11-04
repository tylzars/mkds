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

u32 GrowHttpBuffer(Http *a, HttpBuffer *b, int c);
void FreeHttpBuffer(Http *a, HttpBuffer *b);
u32 InitHttpBuffer(Http *a, HttpBuffer *b, int c);

// Object behind data_ov000_021b4c90; the bytes at 0x3bc are passed to ThreadLockWait and ThreadLockUnlock.
typedef struct Unk021b4c90 {
    /* 000 */ u8 pad_000[4];
    /* 004 */ s32 mUnk_004;
    /* 008 */ u8 pad_008[0x3b4];
    /* 3bc */ u8 mUnk_3bc[4];
} Unk021b4c90;

#include "00/code_02186d04.h"

// Written into Unk02185984 at 0x1cc; mUnk_24 and mUnk_28 allocate and release the 0x13e0 bytes of the object and the
// buffers.
typedef struct Unk02186560 {
    /* 00 */ char mUnk_00[0x15];
    /* 15 */ char mUnk_15[0xc];
    /* 21 */ u8 pad_21[3];
    /* 24 */ void *(*mUnk_24)(const void *, u32);
    /* 28 */ void (*mUnk_28)(const void *, void *, u32);
} Unk02186560;

// 0x13e0 bytes, held in data_ov000_021b4c90; the stack of its thread is the last 0x1000 bytes.
typedef struct Unk02185984 {
    /* 000 */ u32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ char mUnk_00c[4];
    /* 010 */ char mUnk_010[0xf];
    /* 01f */ char mUnk_01f[0x33];
    /* 052 */ char mUnk_052[0x12d];
    /* 17f */ char mUnk_17f[9];
    /* 188 */ char mUnk_188[0x41];
    /* 1c9 */ u8 pad_1c9[3];
    /* 1cc */ Unk02186560 mUnk_1cc;
    /* 1f8 */ Unk021868a4Entry mUnk_1f8[0x20];
    /* 2f8 */ Http *mUnk_2f8;
    /* 2fc */ Unk0200db5c mUnk_2fc;
    /* 3b4 */ u8 pad_3b4[8];
    /* 3bc */ ThreadLock mUnk_3bc;
    /* 3d4 */ s32 mUnk_3d4;
    /* 3d8 */ u8 pad_3d8[8];
    /* 3e0 */ u8 mUnk_3e0[0x1000];
} Unk02185984;

// Some of the locals of func_ov000_02185984.
typedef struct Unk02185984Data {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[6];
    /* 08 */ u8 mUnk_08[6];
    /* 0e */ char mUnk_0e[5];
    /* 13 */ char mUnk_13[3];
    /* 16 */ char mUnk_16[5];
    /* 1b */ char mUnk_1b[4];
} Unk02185984Data;

// 0x12 bytes at data_ov000_021b4c94.
typedef struct Unk021b4c94 {
    /* 00 */ u64 mUnk_00;
    /* 08 */ u64 mUnk_08;
    /* 10 */ u16 mUnk_10;
} Unk021b4c94;

#include "00/code_021ad734.h"

extern Unk02185984 *data_ov000_021b4c90;
extern Unk021b4c94 data_ov000_021b4c94;

void func_ov000_02185954(s32 a);
u32 func_ov000_02185984(Http *a, const char *b, const char *c, Unk021868a4Entry *d, s32 e, s32 f);
s32 func_ov000_02185d54(void);
s32 func_ov000_02185ef4(void);
void func_ov000_021860ac(void *param_1);
s32 func_ov000_02186298(s32 a);
void func_ov000_0218635c(s32 *a);
s32 func_ov000_021863cc(void);
void func_ov000_02186404(void);
void func_ov000_02186430(void);
void func_ov000_02186474(void);
void func_ov000_021864e0(void);
s32 func_ov000_02186560(Unk02186560 *a, Http *b);
void func_ov000_02186628(const void *a);
BOOL func_ov000_02186634(Unk021868a4Entry *a, s32 b, const char *c, char *d, s32 e);
s32 func_ov000_02186674(Unk021868a4Entry *a, s32 b, const char *c, char *d, s32 e);
void *func_ov000_021866b8(Unk021868a4Entry *a, s32 b, const char *c);
BOOL func_ov000_021866fc(Unk021868a4Entry *a, s32 b, s32 c, const char *d);
BOOL func_ov000_021868a4(Unk021868a4 *list, void *first, void *second);
BOOL func_ov000_021868d0(Http *a, const char *b);
u32 func_ov000_02186a84(u32 value);

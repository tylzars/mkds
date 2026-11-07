#pragma once

#include "types.h"

// Declared here until the code that defines them is decompiled.

typedef struct DWCHttpLabelValue {
    /* 00 */ void *mFirst;
    /* 04 */ void *mSecond;
} DWCHttpLabelValue;

typedef struct DWCHttpParseResult {
    /* 00 */ DWCHttpLabelValue *mEntries;
    /* 04 */ s32 mCapacity;
    /* 08 */ s32 mCount;
} DWCHttpParseResult;

#include "os_thread.h"
#include "00/unk_021b1000.h"
#include "code_021510a4.h"

// Growing buffer: mStart is its start, mCursor the write position, mEnd the end and mSize the size.
typedef struct HttpBuffer {
    /* 00 */ char *mStart;
    /* 04 */ char *mCursor;
    /* 08 */ char *mEnd;
    /* 0c */ s32 mSize;
} HttpBuffer;

// Object at p + 0x118 of an Http.
typedef struct Http118 {
    /* 000 */ u8 pad_000[0x7d4];
    /* 7d4 */ char *mUnk_7d4;
    /* 7d8 */ u8 pad_7d8[0xc];
    /* 7e4 */ u32 (*mUnk_7e4)(u32);
    /* 7e8 */ u8 pad_7e8[0x1c];
} Http118;

// Object at p + 0xb4 of an Http.
typedef struct HttpB4 {
    /* 00 */ u8 pad_00[0xc];
    /* 0c */ Http118 *mUnk_0c;
    /* 10 */ u8 pad_10[0x2c];
    /* 3c */ u32 mReceiveBufferSize;
    /* 40 */ void *mReceiveBuffer;
    /* 44 */ u8 pad_44[4];
    /* 48 */ u32 mSendBufferSize;
    /* 4c */ void *mSendBuffer;
    /* 50 */ u8 pad_50[0x14];
} HttpB4;

// 0x1a60 bytes; the stack of its thread ends at mUnk_1a60. mUnk_04 holds the setup it was created with; its allocate
// and free functions allocate and release the memory of the buffers.
typedef struct Http {
    /* 000 */ u8 mUnk_00;
    /* 004 */ Unk021b4cb4 mUnk_04;
    /* 024 */ s32 mResult;
    /* 028 */ char mUnk_028[0x80];
    /* 0a8 */ char *mHost;
    /* 0ac */ char *mPath;
    /* 0b0 */ BOOL mUseHttps;
    /* 0b4 */ HttpB4 mUnk_b4;
    /* 118 */ Http118 mUnk_118;
    /* 91c */ void *mLowReceiveBuffer;
    /* 920 */ void *mLowSendBuffer;
    /* 924 */ s32 mPairCount;
    /* 928 */ HttpBuffer mSendBuffer;
    /* 938 */ HttpBuffer mReceiveBuffer;
    /* 948 */ OSMutex mUnk_948;
    /* 960 */ s32 mContentLength;
    /* 964 */ const char *mBodyStart;
    /* 968 */ OSThread mThread;
    /* a20 */ u8 pad_a20[8];
    /* a28 */ OSMutex mUnk_a28;
    /* a40 */ BOOL mUnk_a40;
    /* a44 */ u8 pad_a44[0x101c];
    /* 1a60 */ u8 mUnk_1a60[];
} Http;

u32 GrowHttpBuffer(Http *a, HttpBuffer *b, int c);
void FreeHttpBuffer(Http *a, HttpBuffer *b);
u32 InitHttpBuffer(Http *a, HttpBuffer *b, int c);

#include "00/code_02186d04.h"

// Written into DWCAuth at 0x1cc; mUnk_24 and mUnk_28 allocate and release the 0x13e0 bytes of the object and the
// buffers.
typedef struct Unk02186560 {
    /* 00 */ char mIngamesn[0x15];
    /* 15 */ char mGsbrcd[0xc];
    /* 21 */ u8 pad_21[3];
    /* 24 */ void *(*mAlloc)(const void *, u32);
    /* 28 */ void (*mFree)(const void *, void *, u32);
} Unk02186560;

// 0x13e0 bytes, held in gAuth; the stack of its thread is the last 0x1000 bytes.
typedef struct DWCAuth {
    /* 000 */ u32 mUnk_000;
    /* 004 */ s32 mError;
    /* 008 */ s32 mUnk_008;
    /* 00c */ char mRetcode[4];
    /* 010 */ char mDatetime[0xf];
    /* 01f */ char mLocator[0x33];
    /* 052 */ char mToken[0x12d];
    /* 17f */ char mChallenge[9];
    /* 188 */ char mCookie[0x41];
    /* 1c9 */ u8 pad_1c9[3];
    /* 1cc */ Unk02186560 mUnk_1cc;
    /* 1f8 */ DWCHttpLabelValue mHttpLabelvalue[0x20];
    /* 2f8 */ Http *mHttp;
    /* 2fc */ OSThread mThread;
    /* 3b4 */ u8 pad_3b4[8];
    /* 3bc */ OSMutex mMutex;
    /* 3d4 */ BOOL mAbort;
    /* 3d8 */ u8 pad_3d8[8];
    /* 3e0 */ u8 mStack[0x1000];
} DWCAuth;

// Some of the locals of DWCi_Auth_Prepare_FirstPost.
typedef struct Unk02185984Data {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[6];
    /* 08 */ u8 mUnk_08[6];
    /* 0e */ char mUnk_0e[5];
    /* 13 */ char mUnk_13[3];
    /* 16 */ char mUnk_16[5];
    /* 1b */ char mUnk_1b[4];
} Unk02185984Data;

#include "00/code_021ad734.h"

extern DWCAuth *gAuth;
extern DWCWiFiInfo data_ov000_021b4c94;

void DWCi_Auth_SetError(s32 a);
u32 DWCi_Auth_Prepare_FirstPost(Http *a, const char *b, const char *c, DWCHttpLabelValue *d, s32 e, s32 f);
s32 DWCi_Auth_FillResult(void);
s32 func_ov000_02185ef4(void);
void DWCi_Auth_Thread(void *param_1);
s32 DWCi_Auth_Start(s32 a);
void func_ov000_0218635c(s32 *a);
s32 DWC_Auth_GetError(void);
void DWC_Auth_Join(void);
void DWC_Auth_Destroy(void);
void DWC_Auth_Abort(void);
void DWCi_Auth_StartThread(void);
s32 DWC_Auth_Create(Unk02186560 *a, Http *b);
void func_ov000_02186628(const void *a);
BOOL DWC_Http_GetRawResult(DWCHttpLabelValue *a, s32 b, const char *c, char *d, s32 e);
s32 DWC_Http_GetBase64DecodedResult(DWCHttpLabelValue *a, s32 b, const char *c, char *d, s32 e);
void *DWC_Http_GetResult(DWCHttpLabelValue *a, s32 b, const char *c);
BOOL DWC_Http_ParseResult(DWCHttpLabelValue *a, s32 b, s32 c, const char *d);
BOOL DWCi_Http_AddResult(DWCHttpParseResult *list, void *first, void *second);
BOOL DWCi_Http_SetHostinfo(Http *a, const char *b);
u32 func_ov000_02186a84(u32 value);

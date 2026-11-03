#pragma once

#include "types.h"

struct Unk02197e8c;
struct Gt2Connection;

typedef struct Gt2ConnectionCallbacks {
    /* 00 */ void (*mResultCallback)(struct Gt2Connection *a, int b, void *c, int d);
    /* 04 */ void (*mDataCallback)(struct Gt2Connection *a, void *b, int c, int d);
    /* 08 */ void (*mUnk_08)(struct Gt2Connection *a, void *b);
    /* 0c */ UnkWordFunc *mElapsedTimeCallback;
} Gt2ConnectionCallbacks;

// Object with the callbacks that the functions of this file call.
typedef struct Unk02197e8c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ void (*mUnk_20)(struct Unk02197e8c *a, struct Gt2Connection *b, int c, int d, int e, int f, int g);
    /* 24 */ void (*mUnk_24)(struct Unk02197e8c *a);
    /* 28 */ UnkWordFunc *mUnk_28;
    /* 2c */ UnkWordFunc *mUnk_2c;
    /* 30 */ UnkWordFunc *mUnk_30;
    /* 34 */ UnkWordFunc *mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
    /* 40 */ u8 mUnk_40[4];
} Unk02197e8c;

typedef struct Unk02197fe8Entry {
    /* 00 */ UnkWordFunc *mUnk_00;
} Unk02197fe8Entry;

typedef struct Gt2Buffer {
    /* 0 */ u8 *mData;
    /* 4 */ s32 mSize;
    /* 8 */ s32 mLength;
} Gt2Buffer;

typedef struct Gt2Connection {
    /* 00 */ u32 mAddress;
    /* 04 */ u16 mPort;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ Unk02197e8c *mSocket;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mResult;
    /* 1c */ u32 mCreateTime;
    /* 20 */ u32 mTimeSinceCreateLimit;
    /* 24 */ s32 mUnk_24;
    /* 28 */ Gt2ConnectionCallbacks mCallbacks;
    /* 38 */ Gt2Buffer mUnk_38;
    /* 44 */ Gt2Buffer mUnk_44;
    /* 50 */ Gt2Buffer mSendBuffer;
    /* 5c */ void *mUnk_5c;
    /* 60 */ void *mUnk_60;
    /* 64 */ u16 mUnk_64;
    /* 66 */ u16 mUnk_66;
    /* 68 */ u8 mUnk_68[0x20];
    /* 88 */ u32 mLastSendTime;
    /* 8c */ u32 mUnk_8c;
    /* 90 */ u32 mUnk_90;
    /* 94 */ u32 mUnk_94;
    /* 98 */ void *mUnk_98;
    /* 9c */ void *mUnk_9c;
} Gt2Connection;

extern const u8 data_ov000_021b3f50[];
extern const u8 data_ov000_021b3f58[];
extern const u8 data_ov000_021b3f68[];

BOOL func_ov000_02197e8c(Unk02197e8c *a, s32 b, s32 c, void *d, s32 e, s32 *f);
u32 func_ov000_02197f28(Unk02197e8c *a, int e, u32 f, u32 g, u32 h, int l, int m, int n);
BOOL func_ov000_02197fe8(Gt2Connection *a, s32 b, void *c, s32 d, s32 e);
BOOL func_ov000_02198098(Gt2Connection *a, s32 b, s32 c, void *d, s32 e);
BOOL func_ov000_02198148(Gt2Connection *a, s32 b);

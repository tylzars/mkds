#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

u32 GpSendMessage(GpConnection *a, s32 b, const char *c);
u32 GpSetStatus(GpConnection *a, s32 b, const char *c, const char *d);

// Output of GpGetBuddyStatus: a copy of the entry's fields, two 0x100-byte strings included.
typedef struct GpBuddyStatus {
    /* 000 */ u32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ char mUnk_008[0x100];
    /* 108 */ char mUnk_108[0x100];
    /* 208 */ u32 mUnk_208;
    /* 20c */ s32 mUnk_20c;
} GpBuddyStatus;

// Element of the array behind Unk0218eff8Arg.mUnk_0c, 0xac bytes.
typedef struct Unk0219c400Entry {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 pad_04[0xa8];
} Unk0219c400Entry;

// Zeroed by func_ov000_0218eff8 and passed to the callback (0x204 bytes); the callbacks name it Unk0219c400.
typedef struct Unk0218eff8Arg {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ Unk0219c400Entry *mUnk_0c;
    /* 10 */ u8 pad_10[0x7e];
    /* 8e */ s8 mUnk_8e[0x20];
    /* ae */ u8 pad_ae[0x156];
} Unk0218eff8Arg;

// Zeroed by func_ov000_0218f0a8 (0x08 set to 0x601) and passed to the callback.
typedef struct Unk0218f0a8Arg {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0218f0a8Arg;

typedef void (*Unk0218eff8Cb)(GpConnection *a, Unk0218eff8Arg *b, u32 c);
typedef void (*Unk0218f0a8Cb)(GpConnection *a, Unk0218f0a8Arg *b, u32 c);

u32 GpIsBuddy(GpConnection *a, u32 b);
u32 GpGetBuddyIndex(GpConnection *a, u32 b, s32 *c);
u32 GpGetBuddyStatus(GpConnection *a, s32 b, GpBuddyStatus *c);
s32 GpGetBuddyCount(GpConnection *object, s32 *output);
u32 GpWriteAddbuddy(GpConnection *a, u32 b, const char *c);
void GpDisconnect(GpConnection *a);

u32 func_ov000_0218eb44(GpConnection *a, u32 b);
u32 func_ov000_0218ed74(GpConnection *b, int c);
u32 func_ov000_0218ee1c(GpConnection *a, u32 b);
u32 func_ov000_0218efa8(GpConnection *a, s32 b, const s8 *c);
u32 func_ov000_0218eff8(GpConnection *a, u32 b, s32 c, u32 d, Unk0218eff8Cb e, u32 f);
u32 func_ov000_0218f0a8(GpConnection *a, s8 *b, s8 *c, s8 *d, s8 *e, s8 *f, s32 g, u32 h, Unk0218f0a8Cb i, u32 j);

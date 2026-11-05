#pragma once

#include "types.h"

typedef struct ThreadLock ThreadLock;

// CallbackListRun calls mCallback with mArg and follows mNext; CallbackListRemove, CallbackListAppend and
// CallbackListPrepend link and unlink objects through mNext.
typedef struct CallbackEntry {
    /* 00 */ void (*mCallback)(void *);
    /* 04 */ void *mArg;
    /* 08 */ struct CallbackEntry *mNext;
} CallbackEntry;

// 0x10 bytes. func_021501d8 sets mUnk_00 to 1 when it was 0, func_02150164 clears it and func_021501c0 loops until it
// is 0. func_02150164 calls mUnk_04 with a word and mUnk_08. func_0214f630 sets mUnk_0c and func_0214ffb4 stores a
// word through it.
typedef struct Unk0214f630 {
    /* 00 */ vu32 mUnk_00;
    /* 04 */ void (*mUnk_04)(u32 a, u32 *b);
    /* 08 */ u32 *mUnk_08;
    /* 0c */ u32 *mUnk_0c;
} Unk0214f630;

// Eight bytes; indexed by func_0214fe10 and func_0214ffb4.
typedef struct Unk0214fe10 {
    /* 00 */ u16 mUnk_00;
    /* 04 */ u16 *mUnk_04;
} Unk0214fe10;

extern u16 data_02180430;
extern vu32 data_02180434;
extern vu32 data_02180438;
extern CallbackEntry *data_0218043c;
extern u32 data_02180440;
extern CallbackEntry *data_02180444;
extern Unk0214f630 data_02180448;
extern ThreadLock data_02180458;
extern Unk0214fe10 data_02180470[4];

void func_0214f4a4(CallbackEntry *p);
void func_0214f4bc(CallbackEntry *p);
void func_0214f4d4(CallbackEntry *p);
void func_0214f4ec(CallbackEntry *p);
void func_0214f504(CallbackEntry *p);
void CallbackListRun(CallbackEntry *p);
void CallbackListRemove(CallbackEntry **pp, CallbackEntry *p);
void CallbackListAppend(CallbackEntry **pp, CallbackEntry *p);
void CallbackListPrepend(CallbackEntry **pp, CallbackEntry *p);
int func_0214f5f4(u32 *p);
int func_0214f630(u32 *p, void (*fn)(u32 a, u32 *b), u32 *arg);
int func_0214f680(u32 a);
int func_0214f6bc(u32 a, void (*fn)(u32 a, u32 *b), u32 *arg);
int func_0214f710(void);
int func_0214f72c(u32 a);
int func_0214f74c(u32 a, u32 b, u32 c, u32 d);
void func_0214f83c(u32 a, u32 b, u32 c);
void func_0214fa7c(u32 a);
int func_0214faac(u32 *a, u32 *b);
int func_0214fb24(u32 a);
int func_0214fb3c(u32 a);
int func_0214fb54(void);
int func_0214fb90(void (*fn)(u32 a, u32 *b), u32 *arg);
int func_0214fba8(u32 a, u32 b);
int func_0214fbe4(u32 a, u32 b, void (*fn)(u32 a, u32 *b), u32 *arg);
int func_0214fc74(u32 a);
int func_0214fcb0(u32 a, void (*fn)(u32 a, u32 *b), u32 *arg);
int func_0214fd18(u32 a, u16 b);
int func_0214fd54(u32 a, u16 b, void (*fn)(u32 a, u32 *b), u32 *arg);
int func_0214fdd4(u32 a, u16 *p);
int func_0214fe10(u32 a, u16 *p, void (*fn)(u32 a, u32 *b), u32 *arg);
int func_0214fe88(u32 a, void (*fn)(u32 a, u32 *b), u32 *arg);
int func_0214fefc(u32 a, u16 b);
void func_0214ffb4(u32 a, u32 b, u32 c);
void func_021500a0(void);
void func_02150164(u32 a);
void WordStore(u32 a, u32 *p);
void func_021501c0(void);
int func_021501d8(void);

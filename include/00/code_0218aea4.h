#pragma once

#include "types.h"

typedef struct SbServerList SbServerList;
typedef struct SbServer SbServer;
typedef struct Unk0218ae68 Unk0218ae68;

typedef struct Unk0218afac {
    /* 00 */ const s8 *mName;
} Unk0218afac;

typedef struct SbServer SbServer;

typedef struct Unk021b21ac {
    /* 0 */ const char *mUnk_00[2];
} Unk021b21ac;

typedef struct Unk0218b010 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ char mUnk_02[0x86];
} Unk0218b010;

typedef struct SbServer SbServer;

typedef struct Unk0218b30c {
    /* 0 */ const char *mUnk_00;
} Unk0218b30c;

// Declared here until the code that defines it is decompiled.

double SbServerGetDouble(SbServer *e, const char *key, double d);
s32 SbServerGetInt(SbServer *e, const char *key, s32 d);
char *SbServerGetValue(SbServer *server, const char *key, char *d);
void SbServerSetInt(SbServer *e, const char *key, u32 c);
void SbServerSetValue(SbServer *e, const char *key, const char *value);

typedef struct SbServerList SbServerList;

typedef struct SbServer SbServer;
typedef struct Unk0218b668 Unk0218b668;
typedef struct SbServerList SbServerList;

// Object func_ov000_0218ba88 builds.
typedef struct Unk0218ba88 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05[4];
    /* 09 */ u8 mUnk_09[2];
    /* 0b */ u8 mUnk_0b[8];
} Unk0218ba88;

typedef struct SbServerList SbServerList;

typedef struct SbServerList SbServerList;

// Four bytes copied byte by byte (func_ov000_0218ce14_inline in code_0218cdd8.c); the target may be unaligned.
typedef struct Unk0218cd94 {
    /* 0 */ u8 mUnk_00[4];
} Unk0218cd94;

typedef struct SbServerList SbServerList;

// Object func_ov000_0218ce14 builds.
typedef struct Unk0218ce14 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk0218ce14;

// Declared here until the code that defines it is decompiled.

void SbServerListInit(SbServerList *slist, const char *a, const char *b, const char *c, u32 d, s32 e, UnkFunc *callback,
                      void *g);

unsigned int func_ov000_0218b570(Unk0218b668 *p0, unsigned int p1, unsigned int p2, u8 *p3, unsigned int p4,
                                 unsigned int p5, unsigned int p6);

#include "00/unk_021b4000.h"
#include "00/code_0218a9bc.h"

// Object of 0x638 bytes func_ov000_0218b668 allocates. func_ov000_0218acb0 passes 0x20 to func_ov000_0218e53c and
// the addresses of 0x14 and 0x08 to func_ov000_0218ae5c.
typedef struct Unk0218b668 {
    /* 000 */ Unk0218a9bc mUnk_000;
    /* 04c */ SbServerList mUnk_04c;
    /* 620 */ u32 mUnk_620;
    /* 624 */ u32 mUnk_624;
    /* 628 */ u32 mUnk_628;
    /* 62c */ u16 mUnk_62c;
    /* 62e */ u8 mUnk_62e[2];
    /* 630 */ UnkFunc *mUnk_630;
    /* 634 */ u32 mUnk_634;
} Unk0218b668;

struct Unk0218b668;

// Declared here until the code that defines them is decompiled.

#include "00/code_0218acb0.h"

extern Unk021b21ac data_ov000_021b21ac;
extern char data_ov000_021b21bc[];
extern s8 data_ov000_021b21c4[];
extern char data_ov000_021b21c8[];
extern char data_ov000_021b21d0[];
extern char data_ov000_021b21d8[];
extern char data_ov000_021b21e4[];
extern s8 *data_ov000_021b4d14;

SbServer *func_ov000_0218aea4(Unk0218ae68 *a);
void func_ov000_0218aec4(Unk0218ae68 *a, SbServer *b);
void func_ov000_0218aedc(Unk0218ae68 *a, SbServer *b);
u32 func_ov000_0218aefc(SbServer *a);
u8 func_ov000_0218af10(SbServer *a);
void func_ov000_0218af14(SbServer *a, u8 b);
void func_ov000_0218af18(SbServer *a, u32 b);
void func_ov000_0218af1c(SbServer *a, u32 b, u16 c);
void func_ov000_0218af24(SbServer *a, s32 b);
SbServer *func_ov000_0218af28(SbServerList *a, u32 b, u16 c);
u32 func_ov000_0218af9c(SbServer *a);
s32 func_ov000_0218afa0(const char *const *first, const char *const *second);
u32 func_ov000_0218afac(Unk0218afac *entry, u32 modulus);
void func_ov000_0218afb8(u32 *a);
u32 func_ov000_0218afd4(const s8 *name, u32 modulus);
void func_ov000_0218b010(SbServer *e, s8 *buf, s32 n);
void func_ov000_0218b148(SbServer *e, s8 *buf);
s8 *func_ov000_0218b19c(s8 *s, s32 c);
u32 func_ov000_0218b1e0(const char *s);
u32 func_ov000_0218b220(int a);
void func_ov000_0218b224(int a, u32 b);
u32 func_ov000_0218b228(u32 arg0);
u32 func_ov000_0218b244(int a);
u32 func_ov000_0218b248(int a);
u16 func_ov000_0218b25c(int a);
u32 func_ov000_0218b260(u32 arg0);
u32 func_ov000_0218b27c(u32 *a);
void func_ov000_0218b3ac(int *a);
void func_ov000_0218b3c8(void *a);
struct Hashtable *func_ov000_0218b3f4(struct SbServerList *p);
void func_ov000_0218b434(u32 arg0);
s32 func_ov000_0218b440(const char *const *first, const char *const *second);
u32 func_ov000_0218b44c(Unk0218afac *entry, u32 modulus);
u32 func_ov000_0218b458(Unk0218b668 *a);
void func_ov000_0218b464(Unk0218b668 *p0, unsigned int p1, const char *p2, unsigned int p3);
u32 func_ov000_0218b474(Unk0218b668 *arg0);
u32 func_ov000_0218b480(Unk0218b668 *arg0, u32 arg1);
void func_ov000_0218b48c(struct Unk0218b668 *p);
void func_ov000_0218b4a4(struct Unk0218b668 *p);
s32 func_ov000_0218b4bc(struct Unk0218b668 *p);
void func_ov000_0218b4d4(struct Unk0218b668 *p, s32 a);
s32 func_ov000_0218b4f8(Unk0218b668 *a, u32 b, s32 c, u32 d);
s32 func_ov000_0218b530(Unk0218b668 *a, u32 b, s32 c, u8 *d, s32 e);
s32 func_ov000_0218b590(Unk0218b668 *a, s32 b, u32 c, u8 *d, s32 e, const char *f, u32 g, u32 h);
void func_ov000_0218b64c(Unk0218b668 *p);
Unk0218b668 *func_ov000_0218b668(const char *a, const char *b, const char *c, u32 d, u32 e, u32 f, s32 g, UnkFunc *h,
                                 u32 l);
void func_ov000_0218b708(void *a, s32 b, SbServer *c, Unk0218b668 *d);
void func_ov000_0218b780(SbServerList *a, s32 b, SbServer *c, Unk0218b668 *d);
s32 func_ov000_0218b8e4(SbServerList *a);
s32 func_ov000_0218b928(SbServerList *a);
s32 func_ov000_0218ba10(SbServerList *a, u32 b, u16 c, u32 d);
s32 func_ov000_0218ba88(SbServerList *a, u32 b, u16 c, u8 *d, s32 e);
s32 func_ov000_0218bb44(SbServerList *a);
s32 func_ov000_0218bc08(SbServerList *slist);
s32 func_ov000_0218bd5c(SbServerList *a, u8 *b, s32 c);
s32 func_ov000_0218be10(SbServerList *a, u8 *b, s32 c);
s32 func_ov000_0218be68(SbServerList *a, u8 *b, s32 c);
s32 func_ov000_0218bf78(SbServerList *a, u8 *b, s32 c);
s32 func_ov000_0218c0bc(SbServerList *a, u8 *b, s32 c);
s32 func_ov000_0218c15c(SbServerList *a);
void func_ov000_0218c45c(SbServerList *a, char *b);
s32 func_ov000_0218c468(SbServerList *a, u8 *b, s32 c);
s32 func_ov000_0218c550(SbServerList *a, void *b, u8 *c, s32 d, s32 e);
void func_ov000_0218c744(SbServerList *a, u8 *b, s32 c, u8 *d, u16 *e);
BOOL func_ov000_0218c794(SbServerList *a, u8 *b, s32 c);
BOOL func_ov000_0218c84c(u8 *a, s32 b);
s32 func_ov000_0218c8ac(u32 a);
void func_ov000_0218c8e0(SbServerList *a, s8 *b, s32 c);
void func_ov000_0218c958(SbServerList *p);
void func_ov000_0218c980(SbServerList *p);
void func_ov000_0218c9d4(SbServerList *p);
void func_ov000_0218ca1c(SbServerList *p);
s32 func_ov000_0218ca58(SbServerList *p, const char *a, const char *b, u32 c, u32 d);
s32 func_ov000_0218cc48(SbServerList *p, void *a, s32 b);
void func_ov000_0218ccbc(SbServerList *p);
void func_ov000_0218cd74(u8 **arg0, const void *arg1, s32 arg2, s32 *arg3);
void func_ov000_0218cd94(u8 **a, u32 b, s32 *c);
void func_ov000_0218cdc4(u8 **a, u8 b, s32 *c);
void func_ov000_0218cdd8(u8 **a, const char *b, s32 *c);
s32 func_ov000_0218ce14(SbServerList *p);
u32 func_ov000_0218cef4(const s8 *a, u32 b);
void func_ov000_0218cf30(SbServerList *p);
int func_ov000_0218d0c8(const void *a, int b);
void func_ov000_0218d0e4(SbServerList *p, u32 key);
void *func_ov000_0218d134(SbServerList *p, const char *key);
void func_ov000_0218d180(unsigned int p0);
void func_ov000_0218d1a0(SbServerList *a);
void func_ov000_0218d1dc(SbServerList *p);
u32 func_ov000_0218d218(SbServerList *a, u32 b);
u32 func_ov000_0218d22c(SbServerList *a);
void func_ov000_0218d238(SbServerList *p, s32 a);
void func_ov000_0218d278(SbServerList *p, u32 key);
int func_ov000_0218d2a8(SbServerList *a, int b, int c);
int func_ov000_0218d300(SbServerList *a, int b);
void func_ov000_0218d340(SbServerList *p, u32 a);
void func_ov000_0218d374(SbServerList *p, s32 a, const char *b, u32 c);
s32 func_ov000_0218d3d8(u32 *a, u32 *b);
s32 func_ov000_0218d430(u32 *c, u32 *d);

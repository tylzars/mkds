#pragma once

#include "types.h"

static inline u16 func_ov003_021b7c44_inline(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}

typedef struct Unk021d6810 {
    /* 00 */ u8 pad_00[0x10];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
} Unk021d6810;

#include "03/code_021b94b8.h"

typedef struct Unk021b916c Unk021b916c;
typedef struct Unk021b86e4 Unk021b86e4;

typedef struct Unk021b807c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk021b807c;

typedef struct Unk021b8340 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ u8 mUnk_04[1];
} Unk021b8340;

typedef struct Unk021b82e0 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ s8 mUnk_0e;
    /* 0f */ s8 mUnk_0f;
    /* 10 */ u8 mUnk_10[8];
} Unk021b82e0;

typedef struct Unk021b839c {
    /* 00 */ s8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[1];
} Unk021b839c;

typedef struct Unk021b858c {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 pad_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[1];
} Unk021b858c;

typedef struct Unk021b8498 {
    /* 00 */ s8 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ u8 mUnk_06[8];
} Unk021b8498;

typedef struct Unk021b8760 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 pad_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[1];
} Unk021b8760;

typedef struct Unk021b88c0 {
    /* 00 */ u8 pad_00[4];
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x28];
    /* 30 */ u8 mUnk_30[0x40];
} Unk021b88c0;

typedef struct Unk021b8990 {
    /* 000 */ u8 pad_000[4];
    /* 004 */ u32 mUnk_004;
    /* 008 */ u8 mUnk_008[0x28];
    /* 030 */ u8 mUnk_030[0x40];
    /* 070 */ u8 mUnk_070[0x40];
    /* 0b0 */ u8 mUnk_0b0[0x40];
    /* 0f0 */ u8 mUnk_0f0[0x40];
} Unk021b8990;

typedef struct Unk021b8758 {
    /* 000 */ u8 pad_000[8];
    /* 008 */ Unk021b8990 mUnk_008;
    /* 138 */ Unk021b8990 mUnk_138;
    /* 268 */ Unk021b88c0 mUnk_268;
    /* 2d8 */ Unk021b88c0 mUnk_2d8;
    /* 348 */ u8 pad_348[8];
} Unk021b8758;

typedef struct Unk021ba734 Unk021ba734;
typedef struct Unk021ba1b0 Unk021ba1b0;
typedef struct Unk021b916c Unk021b916c;
typedef struct Unk021d7c54 Unk021d7c54;

typedef struct Unk021b8c8c {
    /* 00 */ u8 pad_00[6];
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 pad_08[2];
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e;
    /* 0f */ u8 mUnk_0f;
    /* 10 */ Unk021b916c mUnk_10;
    /* 18 */ u8 mUnk_18[1];
} Unk021b8c8c;

typedef struct Unk021d8374 {
    /* 00 */ u8 pad_00[4];
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x28];
    /* 30 */ u8 mUnk_30[0x40];
    /* 70 */ u8 mUnk_70[0x40];
    /* b0 */ u8 mUnk_b0[0x40];
    /* f0 */ u8 mUnk_f0[0x40];
} Unk021d8374;

extern u8 data_ov003_021d6800[];
extern s32 data_ov003_021d680c;
extern Unk021d6810 data_ov003_021d6810;
extern s8 data_ov003_021d6868[];
extern u8 data_ov003_021d6870[];
extern s32 data_ov003_021d7c40;
extern s32 data_ov003_021d7c48;
extern u32 data_ov003_021d7c60[3];
extern u8 data_ov003_021d7c88[2];
extern u8 data_ov003_021d7c8a[];
extern u8 data_ov003_021d7cec[];
extern Unk021b8758 data_ov003_021d836c[2];
extern Unk021d8374 data_ov003_021d8374;
extern Unk021d8374 data_ov003_021d84a4;
extern Unk021d8374 data_ov003_021d85d4;
extern Unk021d8374 data_ov003_021d8644;

u16 func_ov003_021b7bb4(void);
int func_ov003_021b7c30(const void *a);
u16 func_ov003_021b7c44(u16 value);
u32 func_ov003_021b7c5c(u32 arg0);
u16 func_ov003_021b7c94(u16 value);
u32 func_ov003_021b7cac(u32 arg0);
s32 func_ov003_021b7ce4(s32 descriptor);
s32 func_ov003_021b7cec(s32 id, Unk021b7cec *addr, u32 length);
s32 func_ov003_021b7cf8(s32 domain, s32 type, s32 protocol);
s32 func_ov003_021b7d00(s32 id, s32 arg1, s32 arg2, void *value, s32 length);
s32 func_ov003_021b7d04(s32 a, void *b, s32 c, s32 d, Unk021b7cec *e, u32 f);
s32 func_ov003_021b7d1c(s32 count, Unk021b7ba0 *set, void *arg2, void *arg3, Unk021b7d1c *arg4);
s32 func_ov003_021b7d68(s32 id, void *buffer, s32 length, s32 flags, Unk021b7cec *out, s32 *outLength);
void func_ov003_021b7d84(void *arg0, s32 arg1, u32 arg2);
void func_ov003_021b7d90(void *arg0, const void *arg1, u32 arg2);
s32 func_ov003_021b7da0(const u8 *left, const u8 *right, s32 count);
s32 func_ov003_021b7dc8(void);
s32 func_ov003_021b7df4(u32 a, u32 b, u32 c);
void func_ov003_021b7e58(u32 a, u32 b);
u32 func_ov003_021b7e70(u32 a, int b);
void func_ov003_021b7e94(u8 *a, u32 b, u8 *c);
void func_ov003_021b7ed0(const s8 *key, u8 *buffer, s32 size);
void func_ov003_021b7efc(s32 a, s8 *b, s32 c, const s8 *d, s32 e);
s32 func_ov003_021b7f48(u8 *a, s32 b, const s8 *c, s32 d);
void func_ov003_021b7fd4(s32 a, u32 *b);
u32 func_ov003_021b8010(u32 a, const u8 *b, s32 c, s32 d, u32 *e);
u8 func_ov003_021b8050(const u8 *p0, s32 p1);
u32 func_ov003_021b807c(Unk021b807c *p);
void func_ov003_021b80c4(Unk021b807c *p, u8 *dst, const u8 *src, u32 n);
void func_ov003_021b80f4(Unk021b807c *p, const u8 *key, u32 keyLength, u32 n);
s32 func_ov003_021b8160(const u8 *a, u8 *b, s32 c, u32 d, const u8 *e, const u8 *f, s32 g);
s32 func_ov003_021b81f4(const u8 *a, u8 *b, s32 c, s8 *d, u8 *e, const u8 *f, s32 g);
s32 func_ov003_021b8278(void *a, s32 b, u32 c, s32 d);
void func_ov003_021b82e0(void *p, s32 b, s32 c, s32 d, s8 e, s8 f, const u8 *g);
void func_ov003_021b8340(s32 a, void *b, const void *c, s16 *d, s16 *e, s8 *f);
s16 func_ov003_021b839c(void *a);
s32 func_ov003_021b8428(Unk021b86e4 *a, Unk021b916c *b, s32 c);
s32 func_ov003_021b8498(Unk021b86e4 *a, Unk021b916c *b, s32 c);
s32 func_ov003_021b858c(Unk021b86e4 *a, Unk021b916c *b, s32 c);
s32 func_ov003_021b86e4(s32 mode, Unk021b86e4 *buf, Unk021b916c *list, s32 id);
s32 func_ov003_021b8748(u32 value);
s32 func_ov003_021b8758(s32 a, Unk021b8760 *b, s32 c, Unk021b8758 *d, u8 *e);
s32 func_ov003_021b887c(Unk021b8760 *a, u8 *b);
s32 func_ov003_021b88c0(Unk021b8760 *a, Unk021b88c0 *b);
s32 func_ov003_021b8990(Unk021b8760 *a, Unk021b8990 *b);
u32 func_ov003_021b8af4(const u8 *bytes, s32 count);
s32 func_ov003_021b8b18(Unk021b8760 *a, u8 *b);
s32 func_ov003_021b8bf0(Unk021b916c *a, Unk021b916c *b);
s32 func_ov003_021b8c44(s32 a, const u8 *b);
s32 func_ov003_021b8c8c(Unk021b8c8c *a);
s32 func_ov003_021b8d9c(s32 mode, Unk021d7c54 *buffer, s32 *attempts, Unk021b916c *list);
s32 func_ov003_021b8e60(s32 mode, Unk021d7c54 *buffer, s32 *attempts, Unk021b916c *list);
s32 func_ov003_021b8f68(s32 mode, Unk021d7c54 *buffer, s32 *attempts, Unk021b916c *list);
s32 func_ov003_021b9078(s32 a, Unk021d7c54 *b, s32 *c, Unk021b916c *d, s32 e);
s32 func_ov003_021b9134(s32 a);
void func_ov003_021b916c(s32 a, Unk021b916c *b, const u8 *c);
s32 func_ov003_021b91a4(Unk021ba1b0 *a);
s32 func_ov003_021b91f0(Unk021ba734 *a);
s32 func_ov003_021b9278(const u8 *bytes, s32 count);
s32 func_ov003_021b929c(Unk021b94c4 *a);
s32 func_ov003_021b94ac(void);

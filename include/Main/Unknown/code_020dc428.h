#pragma once

#include "types.h"

typedef struct Wanwan Wanwan;

// Object of func_020dd7a8: a function at 0x10 and the address of the pointer that holds it at 0x24.
typedef struct Unk020dd7a8 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ void (*mUnk_10)(void *, Wanwan *);
    /* 14 */ u8 mUnk_14[0x10];
    /* 24 */ struct Unk020dd7a8 **mUnk_24;
} Unk020dd7a8;

// Object of func_020dd804: functions at 0x08 and 0x10, a word at 0x18 and the address of the pointer that holds it at
// 0x28.
typedef struct Unk020dd804 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ void (*mUnk_08)(void);
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ void (*mUnk_10)(void *, Wanwan *, void *, u32);
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ s32 mUnk_18;
    /* 1c */ u8 mUnk_1c[0xc];
    /* 28 */ struct Unk020dd804 **mUnk_28;
} Unk020dd804;

// Object of func_020dd860: two functions and words at 0x08, 0x0c, 0x1c, 0x20 and 0x24.
typedef struct Unk020dd860 {
    /* 00 */ u8 (*mUnk_00)(Wanwan *, void *, u8 *, u8 *);
    /* 04 */ u8 (*mUnk_04)(Wanwan *, void *, u8 *, u8 *);
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0xc];
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ u8 mUnk_28[0x18];
} Unk020dd860;

extern const Unk020dd7a8 data_02158334;
extern const Unk020dd804 data_0215835c;
extern const Unk020dd860 data_02158388;
extern Unk020dd7a8 *data_0217b6d4;
extern Unk020dd804 *data_0217b6d8;

void func_020dc428(Wanwan *p);
void func_020dc444(Wanwan *p);
void func_020dc608(Wanwan *p);
void func_020dc788(Wanwan *p);
void func_020dc7c0(Wanwan *p);
void func_020dcc0c(Wanwan *p);
void func_020dccc8(Wanwan *p);
void func_020dd0d8(Wanwan *p);
u8 func_020dd1f4(Wanwan *p, void *a, u8 *b, u8 *c);
u8 func_020dd230(Wanwan *p, void *a, u8 *b, u8 *c);
void UpdateWanwan(void *a, Wanwan *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
void func_020dd6c8(void *a, Wanwan *p, void *b, u32 c);
Unk020dd7a8 *func_020dd7a8(void);
Unk020dd804 *func_020dd804(void);
Unk020dd860 *func_020dd860(void);

#pragma once

#include "types.h"

typedef struct Wanwan Wanwan;

// Object of CreateWanwanUpdateList: a function at 0x10 and the address of the pointer that holds it at 0x24.
typedef struct Unk020dd7a8 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ void (*mUnk_10)(void *, Wanwan *);
    /* 14 */ u8 mUnk_14[0x10];
    /* 24 */ struct Unk020dd7a8 **mUnk_24;
} Unk020dd7a8;

// Object of CreateWanwanDrawList: functions at 0x08 and 0x10, a word at 0x18 and the address of the pointer that holds
// it at 0x28.
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

// Object of CreateWanwanKindData: two functions and words at 0x08, 0x0c, 0x1c, 0x20 and 0x24.
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
extern Unk020dd7a8 *gWanwanUpdateList;
extern Unk020dd804 *gWanwanDrawList;

void EnterWanwanState5(Wanwan *wanwan);
void func_020dc444(Wanwan *wanwan);
void UpdateWanwanState2(Wanwan *wanwan);
void EnterWanwanState2(Wanwan *wanwan);
void UpdateWanwanState1(Wanwan *wanwan);
void EnterWanwanState1(Wanwan *wanwan);
void UpdateWanwanState0(Wanwan *wanwan);
void EnterWanwanState0(Wanwan *wanwan);
u8 func_020dd1f4(Wanwan *wanwan, void *kart, u8 *b, u8 *c);
u8 func_020dd230(Wanwan *wanwan, void *kart, u8 *b, u8 *c);
void UpdateWanwan(void *unused, Wanwan *wanwan); /* skipped for objects with mFlags & 4 (parked pool objects) */
void func_020dd6c8(void *unused0, Wanwan *wanwan, void *unused1, u32 maxAlpha);
Unk020dd7a8 *CreateWanwanUpdateList(void);
Unk020dd804 *CreateWanwanDrawList(void);
Unk020dd860 *CreateWanwanKindData(void);

#pragma once

#include "types.h"

typedef struct Kart Kart;

// Object read by TryStartKartState4: vectors at 0x04, 0x28, 0x34 and 0x40.
typedef struct Unk0206b020 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ u8 mUnk_10[0x18];
    /* 28 */ Vec3 mUnk_28;
    /* 34 */ Vec3 mUnk_34;
    /* 40 */ Vec3 mUnk_40;
} Unk0206b020;

extern const s16 data_usa_02154a54[];
extern const s16 data_usa_021654c4;
extern const s32 data_usa_021654d0;
extern const s32 data_usa_021654d4;
extern const s32 data_usa_021654e0;
extern const s32 data_usa_021654e4;
extern const s32 data_usa_021654e8;
extern const s32 data_usa_021654f0;
extern const s32 data_usa_02165508;
extern const s32 data_usa_0216550c;
extern const Vec4 data_usa_0216556c;

void AdvanceKartThunderShrink(Kart *p);
void StartKartThunderShrink(Kart *p);
void AdvanceKartState5(Kart *p);
s32 StartKartState5(Kart *p, const Vec3 *a, s32 b);
void AdvanceKartState4(Kart *p);
void StartKartState4(Kart *p, const Vec3 *a, s32 b);
BOOL TryStartKartState4(Kart *p, Unk0206b020 *a);
void AdvanceKartState3(Kart *p);
void StartKartState3(Kart *p);
BOOL TryStartKartState3(Kart *p);
void AdvanceKartState6(Kart *p);
void StartKartState6(Kart *p);
BOOL TryStartKartState6(Kart *p);
void AdvanceKartState1And2(Kart *p);
void StartKartState2(Kart *p, int a, int b);

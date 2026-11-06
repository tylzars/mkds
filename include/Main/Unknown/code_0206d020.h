#pragma once

#include "types.h"

typedef struct Kart Kart;

// The kind passed to StartKartBoost.
typedef enum {
    // The mushroom and the boost surfaces.
    KART_BOOST_ITEM_OR_SURFACE,
    // The release of a fully charged drift.
    KART_BOOST_MINI_TURBO,
    // At the end of the race start sequence.
    KART_BOOST_RACE_START,
    // On landing after a respawn.
    KART_BOOST_RESPAWN
} KartBoostKind;

void StartKartBoost(Kart *p, KartBoostKind a, int b);
void func_0206d138(Kart *p);
void func_0206d18c(Kart *p);
void func_0206d578(Kart *p);
void func_0206d7c8(Kart *p, Kart *q, const Vec3 *v, s32 c, Vec3 *out);
BOOL func_0206dbf8(Kart *p, Kart *q);
BOOL func_0206de18(Kart *p, Kart *q, const Vec3 *v);

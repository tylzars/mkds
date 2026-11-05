#pragma once

#include "types.h"

typedef struct MapObjectKindData MapObjectKindData;
typedef struct MapObject MapObject;
typedef struct Unk020e6fd4 Unk020e6fd4;

struct Unk021000d0;

// Row of the table searched by func_021000d0 and func_02100138.
typedef struct MapObjectKindRow {
    /* 00 */ u32 mKind;
    /* 04 */ struct Unk021000d0 *mUnk_04;
    /* 08 */ void *mUnk_08;
} MapObjectKindRow;

extern MapObjectKindRow data_0216b288[];

// Object behind MapObjectKindRow.mUnk_04.
typedef struct Unk021000d0 {
    /* 00 */ u16 mObjectCount;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mObjectSize;
    /* 08 */ void (*mInitObject)(MapObject *a, struct CourseMapRow *b, void *c);
    /* 0c */ MapObjectKindData *(*mCreateKindData)(void);
    /* 10 */ Unk020e6fd4 *(*mUnk_10)(void);
    /* 14 */ Unk020e6fd4 *(*mUnk_14)(void);
    /* 18 */ Unk020e6fd4 *(*mUnk_18)(void);
    /* 1c */ Unk020e6fd4 *(*mUnk_1c)(void);
    /* 20 */ MapObjectKindData *mKindData;
    /* 24 */ Unk020e6fd4 *mUnk_24[4];
} Unk021000d0;

void *func_02100138(u32 a);
void *func_021000d0(u32 a);

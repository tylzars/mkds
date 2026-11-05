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

// Kind numbers (the mKind member of MapObjectKindRow) of rows whose class the tree names: the Init function in the
// row's descriptor (CreateCream and CreateBerry, the model loaders, for the last two rows) carries the class name. The
// other rows of the table stay literals.
#define MAP_OBJECT_KIND_SHINE16 0x6a
#define MAP_OBJECT_KIND_BALLOON 0x6c
#define MAP_OBJECT_KIND_SHINE_BALLOON 0x70
#define MAP_OBJECT_KIND_TERESA 0x13b
#define MAP_OBJECT_KIND_KURIBO 0x191
#define MAP_OBJECT_KIND_SMAN 0x19d
#define MAP_OBJECT_KIND_BASABASA 0x19f
#define MAP_OBJECT_KIND_NS_KILLER2 0x1a2
#define MAP_OBJECT_KIND_MOVE_TREE 0x1a3
#define MAP_OBJECT_KIND_MKD_EF_BURNER 0x1a4
#define MAP_OBJECT_KIND_FLIPPER 0x1a9
#define MAP_OBJECT_KIND_CRAB 0x1ac
#define MAP_OBJECT_KIND_FIREBALL2 0x1af
// The class IronBall also has kind 0x1b3 (Init and Draw only), which stays a literal.
#define MAP_OBJECT_KIND_IRON_BALL 0x1b0
#define MAP_OBJECT_KIND_SANBO 0x1b2
#define MAP_OBJECT_KIND_CREAM 0x1b4
#define MAP_OBJECT_KIND_BERRY 0x1b5

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

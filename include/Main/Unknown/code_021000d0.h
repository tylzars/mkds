#pragma once

#include "types.h"

typedef struct MapObjectKindData MapObjectKindData;
typedef struct MapObject MapObject;
typedef struct MapObjectList MapObjectList;

struct MapObjectKindDescriptor;

// Row of the table searched by func_021000d0 and func_02100138.
typedef struct MapObjectKindRow {
    /* 00 */ u32 mKind;
    /* 04 */ struct MapObjectKindDescriptor *mUnk_04;
    /* 08 */ void *mUnk_08;
} MapObjectKindRow;

extern MapObjectKindRow data_0216b288[];

// Kind numbers (the mKind member of MapObjectKindRow) of rows whose class the tree names: the Init function in the
// row's descriptor (CreateCream and CreateBerry, the model loaders, for the last two rows) carries the class name; for
// RainStar, Rock, Rock2, ObPakkunSf and Pendulum it is a function of the lists the row builds. Other rows stay
// literals. CarA, BusA and TruckA share one Init: their CreateKindData function carries the class name.
// The class ItemBox also has kind 0xc9 (own Init and update list), which stays a literal.
#define MAP_OBJECT_KIND_ITEM_BOX 0x65
#define MAP_OBJECT_KIND_WOODBOX1 0x67
#define MAP_OBJECT_KIND_SHINE16 0x6a
#define MAP_OBJECT_KIND_BALLOON 0x6c
#define MAP_OBJECT_KIND_MISSION_GATE 0x6e
#define MAP_OBJECT_KIND_SHINE_BALLOON 0x70
#define MAP_OBJECT_KIND_KOOPA_BLOCK 0xca
#define MAP_OBJECT_KIND_BRIDGE 0xcc
#define MAP_OBJECT_KIND_SECOND_HAND 0xcd
#define MAP_OBJECT_KIND_PENDULUM 0xcf
#define MAP_OBJECT_KIND_EARTHEN_PIPE 0x12f
#define MAP_OBJECT_KIND_TERESA 0x13b
#define MAP_OBJECT_KIND_RAIN_STAR 0x154
#define MAP_OBJECT_KIND_STOP_SIGN 0x159
#define MAP_OBJECT_KIND_KURIBO 0x191
#define MAP_OBJECT_KIND_ROCK 0x192
#define MAP_OBJECT_KIND_DOSSUN 0x193
#define MAP_OBJECT_KIND_BUS_A 0x195
#define MAP_OBJECT_KIND_MKD_EF_BUBBLE 0x198
#define MAP_OBJECT_KIND_CAR_A 0x19a
#define MAP_OBJECT_KIND_CHOROPU 0x199
#define MAP_OBJECT_KIND_PUKUPUKU 0x19b
#define MAP_OBJECT_KIND_TRUCK_A 0x19c
#define MAP_OBJECT_KIND_SMAN 0x19d
#define MAP_OBJECT_KIND_BASABASA 0x19f
#define MAP_OBJECT_KIND_NS_KILLER2 0x1a2
#define MAP_OBJECT_KIND_MOVE_TREE 0x1a3
#define MAP_OBJECT_KIND_MKD_EF_BURNER 0x1a4
#define MAP_OBJECT_KIND_OB_PAKKUN_SF 0x1a6
#define MAP_OBJECT_KIND_COVER_POO_HOLE 0x1a7
#define MAP_OBJECT_KIND_BOUND 0x1a8
#define MAP_OBJECT_KIND_FLIPPER 0x1a9
#define MAP_OBJECT_KIND_CRAB 0x1ac
// InitSun creates 30 objects of the pool kind 0x1ae (not named), which stays a literal.
#define MAP_OBJECT_KIND_SUN 0x1ad
#define MAP_OBJECT_KIND_FIREBALL2 0x1af
// The class IronBall also has kind 0x1b3 (Init and Draw only), which stays a literal.
#define MAP_OBJECT_KIND_IRON_BALL 0x1b0
#define MAP_OBJECT_KIND_ROCK2 0x1b1
#define MAP_OBJECT_KIND_SANBO 0x1b2
#define MAP_OBJECT_KIND_CREAM 0x1b4
// Mission Run boss kind: Boss Donketu.
#define MAP_OBJECT_KIND_BOSS_DONKETU 0x1f5
// Mission Run boss kind: King Ice Donketu.
#define MAP_OBJECT_KIND_KING_ICE_DONKETU 0x1f6
#define MAP_OBJECT_KIND_BOMB_KING 0x1f8
#define MAP_OBJECT_KIND_HANACHAN 0x1fc
#define MAP_OBJECT_KIND_IWANTE 0x1fb
#define MAP_OBJECT_KIND_KURIKING 0x1f7
#define MAP_OBJECT_KIND_BERRY 0x1b5

// Object behind MapObjectKindRow.mUnk_04.
typedef struct MapObjectKindDescriptor {
    /* 00 */ u16 mObjectCount;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mObjectSize;
    /* 08 */ void (*mInitObject)(MapObject *a, struct CourseMapRow *b, void *c);
    /* 0c */ MapObjectKindData *(*mCreateKindData)(void);
    /* 10 */ MapObjectList *(*mCreateDrawList0)(void);
    /* 14 */ MapObjectList *(*mCreateDrawList1)(void);
    /* 18 */ MapObjectList *(*mCreateDrawList2)(void);
    /* 1c */ MapObjectList *(*mCreateUpdateList)(void);
    /* 20 */ MapObjectKindData *mKindData;
    /* 24 */ MapObjectList *mLists[4];
} MapObjectKindDescriptor;

void *func_02100138(u32 a);
void *func_021000d0(u32 a);

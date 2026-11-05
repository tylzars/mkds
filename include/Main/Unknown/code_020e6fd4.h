#pragma once

#include "types.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_020e005c.h" // Unk020e005c_080
#include "Main/Unknown/code_0210b000.h" // Unk0210b7ec

struct MapObject;
struct CourseMapRow;

// Object behind MapObject.mUnk_94, passed to func_0210cfbc (which reads its halfword at 0x34).
typedef struct Unk020e71a0_94 {
    /* 00 */ Unk0210bfbc mUnk_00;
    /* 44 */ Unk0210b7ec mUnk_44;
    /* 54 */ u8 mUnk_54[0xc];
} Unk020e71a0_94;

// Object behind MapObject.mKindData, built once per Unk021000d0 (row->mUnk_04): kinds whose rows point at the same
// record share it (e.g. kinds 0x01/0x03/0x06/0x09/0x0c; 0x05/0x0e/0x0f). AddMapObjectToUpdateList copies its 0x04 into
// the callback slot at 0x1c of a Unk020e6fd4 and its 0x20 into the word at 0x18; func_020d6968 reads 0x20 and
// func_020f944c reads 0x28.
typedef struct MapObjectKindData {
    /* 00 */ s32 (*mUnk_00)(struct MapObject *e, void *a, s32 *b, s32 *c);
    /* 04 */ s32 (*mUnk_04)(struct MapObject *e, void *a, void *b, void *c);
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 (*mUnk_18)(struct MapObject *a, Vec3 *b, s32 c, Vec3 *d);
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
} MapObjectKindData;

// Element object up to 0xa0, which every kind shares: func_020e705c and func_020e71a0 read 0x78 and 0x94 of every
// object, func_020d6968 reads 0x00, 0x02 and 0x98. InitKuribo and InitDram pass the Unk020e005c_080 at 0x80 to
// func_02046be8.
// From 0xa0 on, the objects of func_020e72cc (Unk020e730c), InitDram (Dram), func_020ff97c (Unk020ff97c)
// and func_021052fc (Unk021052fc) use the bytes in different ways.
typedef struct MapObject {
    /* 00 */ u16 mKind;
    /* 02 */ u16 mFlags;
    /* 04 */ Vec3 mPos;
    /* 10 */ Vec3 mUnk_10;
    /* 1c */ Vec3 mScale;
    /* 28 */ Unk02012f58 mMatrix;
    /* 58 */ Vec3 mUnk_58;
    /* 64 */ s16 mUnk_64;
    /* 66 */ u16 mUnk_66;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ u32 mUnk_74;
    /* 78 */ u32 mUnk_78;
    /* 7c */ u16 mUnk_7c;
    /* 7e */ u16 mAngle;
    /* 80 */ Unk020e005c_080 mUnk_80;
    /* 94 */ Unk020e71a0_94 *mUnk_94;
    /* 98 */ MapObjectKindData *mKindData;
    /* 9c */ struct CourseMapRow *mCourseMapRow;
} MapObject;

// Object of func_020e72cc and func_020e730c: two u16s after the shared part.
typedef struct Unk020e730c {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u16 mUnk_a0;
    /* a2 */ u16 mUnk_a2;
} Unk020e730c;

// Container of MapObject objects: the pointer array at 0x00 and its count at 0x04; func_020e6fd4 calls 0x1c for
// each object, func_020e705c calls 0x10, AddMapObjectToUpdateList adds an object, func_020e6fc4 and func_020e6fcc
// change the count.
typedef struct Unk020e6fd4 {
    /* 00 */ void **mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ void (*mUnk_08)(struct Unk020e6fd4 *p);
    /* 0c */ void (*mUnk_0c)(struct Unk020e6fd4 *p);
    /* 10 */ UnkFunc *mUnk_10;
    /* 14 */ void (*mUnk_14)(struct Unk020e6fd4 *p);
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 (*mUnk_1c)(MapObject *e, void *a, void *b, void *c);
    /* 20 */ s32 mUnk_20;
    /* 24 */ void **mUnk_24;
} Unk020e6fd4;

typedef struct Unk020e6488 Unk020e6488;
typedef struct Unk020e6fd4 Unk020e6fd4;
typedef struct Unk0210b7a8 Unk0210b7a8;

// 0x40-byte block that func_020e7410 takes from data_02159370.
typedef struct Unk020e7410 {
    /* 00 */ u32 mUnk_00[0x10];
} Unk020e7410;

// Source rows read by the second loop of func_020e7460, 0x0c bytes each; a
// row's non-zero words are names looked up by FindSceneFile.
typedef struct Unk0216c324 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ const char *mUnk_04;
    /* 08 */ const char *mUnk_08;
} Unk0216c324;

// 0x10-byte rows of the table at data_0217bae8: the second loop of func_020e7460
// writes three objects allocated through HeapAlloc into the rows from
// data_0217bb08 on, and the word at 0x0c of the first two rows receives the
// object func_020e6488 creates. func_020e9810 reads the words at 0x0c through
// data_0217baf4.
typedef struct Unk0217bb08 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ Unk020e6488 *mUnk_0c;
} Unk0217bb08;

extern Unk0216c324 data_0216c324[];
// Filled in by func_020e7760; func_020e84b0 stores func_020d4ef4's return value
// at 0x0c and hands it to func_0210b760.
extern Unk0210b7a8 data_0217b9dc;
extern Unk0217bb08 data_0217bae8[];
extern Unk0217bb08 data_0217baf4[];
extern Unk0217bb08 data_0217bb08[];

void func_020e6fd4(Unk020e6fd4 *p);
void func_020e705c(Unk020e6fd4 *p);
void func_020e71a0(MapObject *p);
void func_020e72cc(Unk020e730c *p, struct CourseMapRow *q);
void func_020e730c(void);
u16 func_020e7388(int arg0);
Unk020e6fd4 *func_020e73b4(void);
Unk020e7410 *func_020e7410(void);
void func_020e7460(void);
void func_020e7760(void);
void func_020e79c4(void);
void func_020e7a18(void);
void func_020e7a40(void);

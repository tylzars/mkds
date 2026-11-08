#pragma once

#include "types.h"
#include "Main/Unknown/code_020de214.h" // MapObjectDrawList
#include "Main/Unknown/code_02067cb0.h" // MapObject

typedef struct PooledMapObject PooledMapObject;

// 0x40-byte object behind data_0215a680.
typedef struct Unk0215a680 {
    /* 00 */ u32 mUnk_00[0x10];
} Unk0215a680;

// 0x34 bytes: a word at 0x04 and five functions from 0x08.
typedef struct Unk0215a64c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ void (*mUnk_08)(void *, void *);
    /* 0c */ Unk0215a680 *(*mUnk_0c)(void);
    /* 10 */ MapObjectDrawList *(*mUnk_10)(void);
    /* 14 */ MapObjectDrawList *(*mUnk_14)(void);
    /* 18 */ MapObjectDrawList *(*mUnk_18)(void);
    /* 1c */ u8 mUnk_1c[0x18];
} Unk0215a64c;

extern const Unk0215a64c data_usa_0215a64c;
extern const Unk0215a680 data_0215a680;

u32 func_02105504(void);
u32 func_021054d0(void);
Unk0215a680 *func_02105480(void);
void func_02105464(void *mapObject, void *q);
MapObject *AllocPooledMapObject(void);
void ResetPooledMapObject(PooledMapObject *pooledObject);

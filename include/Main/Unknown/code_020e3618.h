#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e0680.h"

// Block of eleven words.
typedef struct Unk020e039c {
    /* 00 */ u32 mUnk_00[11];
} Unk020e039c;

// Object of kind 0xcc (Bridge) that InitBridge fills. Its draw callback func_020e3b4c is typed Unk020e3ef4 (the family
// layout of kinds 0xcb, 0xce, 0xd0 and 0xd1); the model pointer at +0x140, written by func_020e1dc0, lies inside
// mUnk_13c.
typedef struct Bridge {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ Unk020e38a0_28 mUnk_0a0;
    /* 0c4 */ Unk020e38a0_28 mUnk_0c4;
    /* 0e8 */ Vec3 mUnk_0e8;
    /* 0f4 */ Vec3 mUnk_0f4;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ s32 mUnk_10c;
    /* 110 */ s32 mUnk_110;
    /* 114 */ Vec3 mUnk_114;
    /* 120 */ s32 mUnk_120;
    /* 124 */ Vec3 mUnk_124;
    /* 130 */ s32 mUnk_130;
    /* 134 */ s32 mUnk_134;
    /* 138 */ s32 mUnk_138;
    /* 13c */ u8 mUnk_13c[0x8];
    /* 144 */ u16 mUnk_144;
    /* 146 */ u16 mUnk_146;
    /* 148 */ u16 mUnk_148;
    /* 14a */ u16 mUnk_14a;
    /* 14c */ u16 mUnk_14c;
    /* 14e */ u16 mUnk_14e;
    /* 150 */ u16 mUnk_150;
    /* 152 */ u8 mUnk_152[0x2];
    /* 154 */ s32 mUnk_154;
} Bridge;

BOOL func_020e3af0(u32 a);
void CreateBridge(void); /* no argument; also gives the model to the registered objects (func_020e1dc0) */
void InitBridge(Bridge *a, struct CourseMapRow *b);
void *func_020e3850(void);
void *func_020e37f4(void);
void *func_020e3798(void);
void *func_020e373c(void);
void SetupDrawChoropu(void);
void DrawChoropu(s32 a, Unk020e1e98 *b, s32 c, u16 d);

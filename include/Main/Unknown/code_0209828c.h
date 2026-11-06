#pragma once

#include "types.h"
#include "Main/Unknown/code_02099020.h"
#include "Main/Unknown/code_0209bc74.h" // MapObjectModel
#include "Main/Unknown/code_020e005c.h" // Unk020e0144
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList

// Object up to 0x200 bytes: the shared part, a counter at 0xa4 that cycles between 0xac and 0xb0, a state at 0xb4,
// seven Unk020e0144 from 0xb8, then a count and an index at 0x1b8 and 0x1ba and seven values at 0x1bc.
typedef struct Pakkun {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ u16 mUnk_0a0;
    /* 0a2 */ u8 mUnk_0a2[2];
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ s32 mState;
    /* 0b8 */ Unk020e0144 mUnk_0b8[7];
    /* 1b4 */ s32 mTimer;
    /* 1b8 */ u16 mUnk_1b8;
    /* 1ba */ u16 mUnk_1ba;
    /* 1bc */ s32 mUnk_1bc[7];
    /* 1d8 */ s32 mUnk_1d8;
    /* 1dc */ s32 mUnk_1dc;
    /* 1e0 */ s32 mUnk_1e0;
    /* 1e4 */ BOOL mUnk_1e4;
    /* 1e8 */ s32 mUnk_1e8;
    /* 1ec */ s32 mUnk_1ec;
    /* 1f0 */ s32 mUnk_1f0;
    /* 1f4 */ s32 mUnk_1f4;
    /* 1f8 */ s32 mUnk_1f8;
    /* 1fc */ s32 mUnk_1fc;
} Pakkun;

// Object returned by func_0209bef0 and func_0209bf1c here: a word at 0x1c is set to 1.
typedef struct Unk020982d4 {
    /* 00 */ u8 mUnk_00[0x1c];
    /* 1c */ BOOL mUnk_1c;
} Unk020982d4;

extern MapObjectList *data_usa_0217b0dc;
extern MapObjectModel *gPakkunMouth;
extern void *gPakkunZHead;
extern void *data_usa_0217b0e8;
extern void *gPakkunBody;
extern Unk020982d4 *data_usa_0217b0f0;
extern Unk020982d4 *data_usa_0217b0f4;

void *func_0209828c(void);
void *func_020982d4(void);
void *func_02098328(void);
void *func_02098374(void);
void UpdatePakkun(void *a, Pakkun *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
void func_0209886c(void);
void DrawPakkunBody(void *a, Pakkun *p);
void func_020989fc(void *a);
void CreatePakkunBody(void *a);
void DrawPakkunZHead(void *a, Pakkun *p);
void func_02098b1c(void *a);
void CreatePakkunZHead(void *a);
void DrawPakkunMouth(void *a, Pakkun *p);
void CreatePakkunMouth(void *a);
void InitPakkun(Pakkun *p);
void func_02098f18(Unk020e0144 *a, s32 b);
void *func_02099004(void);

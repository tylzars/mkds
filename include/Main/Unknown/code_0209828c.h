#pragma once

#include "types.h"
#include "Main/Unknown/code_02099020.h"
#include "Main/Unknown/code_0209bc74.h" // MapObjectModel
#include "Main/Unknown/code_020e005c.h" // GroupFollower
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList

// Object up to 0x200 bytes: the shared part, a counter at 0xa4 that cycles between 0xac and 0xb0, a state at 0xb4,
// seven GroupFollower from 0xb8, then a count and an index at 0x1b8 and 0x1ba and seven values at 0x1bc.
typedef struct Pakkun {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ u16 mPolygonId;
    /* 0a2 */ u8 mUnk_0a2[2];
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ s32 mState;
    /* 0b8 */ GroupFollower mFollowers[7];
    /* 1b4 */ s32 mTimer;
    /* 1b8 */ u16 mFollowerIndex;
    /* 1ba */ u16 mFollowerCount;
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

// Object returned by CreateMapObjectDrawList2 and CreateMapObjectDrawList1 here: a word at 0x1c is set to 1.
typedef struct Unk020982d4 {
    /* 00 */ u8 mUnk_00[0x1c];
    /* 1c */ BOOL mUnk_1c;
} Unk020982d4;

extern MapObjectList *gPakkunUpdateList;
extern MapObjectModel *gPakkunMouth;
extern void *gPakkunZHead;
extern void *gPakkunBodyDrawList;
extern void *gPakkunBody;
extern Unk020982d4 *gPakkunZHeadDrawList;
extern Unk020982d4 *gPakkunMouthDrawList;

void *CreatePakkunUpdateList(void);
void *CreatePakkunZHeadDrawList(void);
void *CreatePakkunBodyDrawList(void);
void *CreatePakkunMouthDrawList(void);
void UpdatePakkun(void *a, Pakkun *pakkun); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitPakkunObjects(void);
void DrawPakkunBody(void *a, Pakkun *pakkun);
void SetupDrawPakkunBody(void *a);
void CreatePakkunBody(void *a);
void DrawPakkunZHead(void *a, Pakkun *pakkun);
void SetupDrawPakkunZHead(void *a);
void CreatePakkunZHead(void *a);
void DrawPakkunMouth(void *a, Pakkun *pakkun);
void CreatePakkunMouth(void *a);
void InitPakkun(Pakkun *pakkun);
void func_02098f18(GroupFollower *groupFollower, s32 b);
void *func_02099004(void);

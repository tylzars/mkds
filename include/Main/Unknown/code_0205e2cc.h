#pragma once

#include "types.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02114158.h"

// Five emblems of the saved data: the index of the block (emblem number / 5, -1 for none) and the saved block.
// 0xb04 bytes: a signed byte at 0x00 and, from 0x04, an EmblemBlockData.
typedef struct EmblemBlock {
    /* 00 */ s8 mBlockIndex;
    /* 01 */ u8 mUnk_01[3];
    /* 04 */ EmblemBlockData mUnk_04;
} EmblemBlock;

void func_0205e2cc(void *a);
// Scene function of gSceneFuncs[13] (scene 'Ghost' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunGhostScene(SceneNumbers *a);
void func_0205e518(u32 a);
void func_0205e520(void);
void func_0205e528(void);
void func_0205e530(void);
u8 CountEmblemEntries(void);
void func_0205e5c4(s32 a);
void CopyWiFiOtherEmblemsToBlocks(void);
void CopyOtherPlayerEmblemsToBlocks(void);
void SetupEmblemBlock(EmblemBlock *a, u8 b);
BOOL CopyEmblemFromBlock(EmblemBlock *a, u8 b, EmblemData *c);
EmblemBlock *CreateEmblemBlock(void *a);

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

void CreateShapeMapObjectCountList(void *heap);
// Scene function of gSceneFuncs[13] (scene 'Ghost' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunGhostScene(SceneNumbers *sceneNumbers);
void func_0205e518(u32 sceneNumbers);
void func_0205e520(void);
void func_0205e528(void);
void func_0205e530(void);
u8 CountEmblemEntries(void);
void StartCopyOtherEmblems(s32 useConnection);
void CopyWiFiOtherEmblemsToBlocks(void);
void CopyOtherPlayerEmblemsToBlocks(void);
void SetupEmblemBlock(EmblemBlock *emblemBlock, u8 buddyIndex);
BOOL CopyEmblemFromBlock(EmblemBlock *emblemBlock, u8 buddyIndex, EmblemData *emblemData);
EmblemBlock *CreateEmblemBlock(void *heap);

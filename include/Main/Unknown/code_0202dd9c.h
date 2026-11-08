#pragma once

#include "types.h"

typedef struct Unk02174e14 Unk02174e14;

// Halfword, hour and minute, as GetListedGhostTime fills them.
typedef struct Unk0202de00_g {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk0202de00_g;

unsigned int GetSlotGhostCount(void);
unsigned int GetCourseGhostCount(void);
unsigned int GetGhostCount(void);
unsigned int GetSlotGhostBuffer(void);
void *GetCourseGhostBuffer(void);
void PrintGhostRecordInfo(Unk02174e14 *fileSets, s16 (*labelRows)[4], void *name, s32 characterIndex, s32 kartIndex,
                          s32 courseId, Unk0202de00_g *time);
void func_0202dec8(void);
void ReleaseGhostScene(void);
void AdvanceGhostScene(s32 sceneNumbers);
void InitGhostScene(void *heap);

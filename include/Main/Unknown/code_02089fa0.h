#pragma once

#include "types.h"
#include "Main/Unknown/code_020846c0.h" // Nsbmd
#include "Main/Unknown/code_02087d0c.h" // ModelAnimation
#include "Main/Unknown/unk_02155000.h" // StemSetParams

// 0x14 bytes: a table of 0x6c-byte objects at 0x00, three tables of 0x38-byte objects at 0x04, 0x08 and 0x0c, and the
// number of entries of the first table at 0x10.
typedef struct StemSet {
    /* 00 */ Nsbmd *mNsbmds;
    /* 04 */ ModelAnimation *mNsbcaNsbmaNsbtp[3];
    /* 10 */ u16 mNsbmdCount;
} StemSet;

void DrawStemSets(void);
void UpdateStemSets(void);
void StartStemSet(s32 setIndex);
void InitStemSetArray(void *heap);
void InitNsbmdNsbcaNsbmaNsbtp(void *heap, StemSet *stemSet, const StemSetParams *stemSetParams, u16 setIndex);
void InitStemSets(void *heap);

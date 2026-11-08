#pragma once

#include "types.h"

typedef struct Unk0217c7c4 Unk0217c7c4;
typedef struct SoundSetPlayer SoundSetPlayer;
typedef struct LoadedSoundSet LoadedSoundSet;
typedef struct SoundRequestQueue SoundRequestQueue;
typedef struct NNSSndHeap NNSSndHeap;

void *TakeSoundHandleEntry(Unk0217c7c4 *pool);
void IncrementSoundHandleAges(Unk0217c7c4 *pool);
void InitSoundHandlePool(Unk0217c7c4 *pool, void *entries, s32 count, s32 entrySize);
void InitSoundRequestQueue(SoundRequestQueue *queue, s32 count, NNSSndHeap *heap);
void ResetSoundRequestQueue(SoundRequestQueue *queue);
void RunSoundRequests(SoundRequestQueue *queue);
void AddSoundRequest(SoundRequestQueue *queue, int sortKey, void (*function)(void *, int), void *firstArgument,
                     int secondArgument);
u32 InitSoundSetPlayer(SoundSetPlayer *player, u32 seqId, u32 firstBankId, u32 secondBankId, LoadedSoundSet *loadedSet);
void StartSoundSetSeq(SoundSetPlayer *player, u32 volume);
void StopSoundSetSeq(SoundSetPlayer *player, u32 fadeSteps);
void ReleaseSoundSetPlayer(SoundSetPlayer *player);

#include "Main/Unknown/code_0200635c.h"
#include "Main/Unknown/code_0200589c.h"

#pragma thumb on

void func_0200635c(ChunkReceiveState *a, u32 b) {
    a->mReceivedChunkCount = a->mReceivedChunkCount + 1;
    a->mLastReceivedChunkIndex = b;
    a->mChunkBitmap[(s32) b >> 5] = a->mChunkBitmap[(s32) b >> 5] | 1 << (b & 0x1f);
}

#pragma thumb off

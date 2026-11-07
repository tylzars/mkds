#pragma once

#include "types.h"

typedef struct ChunkReceiveState ChunkReceiveState;

void MarkChunkReceived(ChunkReceiveState *a, u32 b);

#pragma once

#include "types.h"

typedef struct ChunkReceiveState ChunkReceiveState;

BOOL IsChunkReceived(ChunkReceiveState *state, s32 chunkIndex);
void SetupChunkReceiveState(ChunkReceiveState *state, s32 size, void *chunkBitmap, u32 buffer);
u32 GetBlockChunkAddress(u32 blockIdOrPosition, u32 chunkIndex);
s32 PickSendChunkIndex(u32 blockId, s32 chunkIndex);
s32 WriteBytesReplyPacket(u8 *buffer, u16 indexMask, u8 requestId);
s32 WriteBytesPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 *bytes, u32 byteCount);
s32 WriteNoMissingChunkReplyPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 blockId);
s32 WriteNoMissingChunkPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 blockId);
s32 WriteBlockNodePacket(u8 *buffer, u32 indexMask, u8 requestId, u32 blockId, u32 chunkIndex, u32 data, u32 dataSize);
s32 WriteBlockNodeRequestPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 blockId, u32 chunkIndex);
s32 WriteBlockDataPacket(u8 *buffer, u32 indexMask, u8 requestId, u32 blockId, u32 chunkIndex, u32 data, s32 dataSize);
s32 WriteBlockDataRequestPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 blockId, u32 chunkIndex);
s32 WriteBlockCountReplyPacket(u8 *buffer, u16 indexMask, u8 requestId, s16 blockCount, u32 sendChunkSize,
                               u32 receiveChunkSize);
s32 WriteBlockCountRequestPacket(u8 *buffer, u16 indexMask, u8 requestId, u32 sendChunkSize, u32 receiveChunkSize);
s32 WriteEmptyPacket(u8 *buffer, u16 indexMask, u8 requestId);
void ReceiveParentPacketChecked(const u8 *packet, u32 size);
u32 BuildChildPacket(u8 *buffer, s32 bufferSize);

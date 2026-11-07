#pragma once

#include "types.h"

typedef struct ChunkReceiveState ChunkReceiveState;

BOOL IsChunkReceived(ChunkReceiveState *a, s32 b);
void SetupChunkReceiveState(ChunkReceiveState *a, s32 b, void *c, u32 d);
u32 GetBlockChunkAddress(u32 a, u32 b);
s32 PickSendChunkIndex(u32 a, s32 b);
s32 WriteBytesReplyPacket(u8 *a, u16 b, u8 c);
s32 WriteBytesPacket(u8 *a, u16 b, u8 c, u32 *d, u32 e);
s32 func_020065a8(u8 *a, u16 b, u8 c, u32 d);
s32 func_020065f8(u8 *a, u16 b, u8 c, u32 d);
s32 WriteBlockNodePacket(u8 *a, u32 b, u8 c, u32 d, u32 e, u32 f, u32 g);
s32 WriteBlockNodeRequestPacket(u8 *a, u16 b, u8 c, u32 d, u32 e);
s32 WriteBlockDataPacket(u8 *a, u32 b, u8 c, u32 d, u32 e, u32 f, s32 g);
s32 WriteBlockDataRequestPacket(u8 *a, u16 b, u8 c, u32 d, u32 e);
s32 WriteBlockCountReplyPacket(u8 *a, u16 b, u8 c, s16 d, u32 e, u32 f);
s32 WriteBlockCountRequestPacket(u8 *a, u16 b, u8 c, u32 d, u32 e);
s32 WriteEmptyPacket(u8 *a, u16 b, u8 c);
void ReceiveParentPacketChecked(const u8 *a, u32 b);
u32 BuildChildPacket(u8 *a, s32 b);

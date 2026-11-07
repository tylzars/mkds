#pragma once

#include "types.h"

// Six bytes that ReadParentMessage fills and WriteParentMessage writes out.
typedef struct ParentMessage {
    /* 0 */ u8 mKind;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u16 mUnk_04;
} ParentMessage;

// 0x14 bytes that WriteChildMessage writes out and ReadChildMessage fills; the bytes from 3 or 4 on are moved from or
// to the entry in the word at gPieceSizes.
typedef struct ChildMessage {
    /* 00 */ u8 mKind;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[0x10];
} ChildMessage;

// 0x20-byte entry that CopyNextPiece copies.
typedef struct Unk0200c12c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0x16];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u8 mUnk_1c;
    /* 1d */ u8 mUnk_1d[3];
} Unk0200c12c;

u8 *ReadParentMessage(ParentMessage *message, u8 *buffer);
u8 CopyNextPiece(void *output, void *pieces);
u8 *WriteChildMessage(ChildMessage *message, u8 *buffer);
u32 AreAllPiecesReceived(u32 child);
u8 *StorePiece(ChildMessage *message, u32 child);
u8 *ReadChildMessage(u8 *bytes, ChildMessage *message, u32 child);
u8 *WriteParentMessage(u8 *input, u8 *output);
void ClearChildPieces(s32 child);
void SetupPieceBuffer(u32 buffer);
void SetupPieceSizes(s32 packetSize);

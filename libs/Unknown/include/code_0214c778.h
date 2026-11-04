#pragma once

#include "types.h"

// Object at data_02180308, set up by GxFifoSendWords and GxFifoSendWordsInPieces.
typedef struct Unk0214ccd4 {
    /* 00 */ vu32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ const u8 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ UnkFunc *mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ UnkFunc *mUnk_1c;
} Unk0214ccd4;

extern Unk0214ccd4 data_02180308;

void func_0214c778(u32 a, const void *b, u32 c, u32 d);
void func_0214c7e8(u32 a, u32 b);
void func_0214c89c(u32 a);
void func_0214c920(u32 a);
void func_0214c990(u32 a, const void *b, void *c, u32 d, UnkFunc *f, u32 arg);
void func_0214ca38(u32 a, void *b, u32 c, u32 d, UnkFunc *f, u32 arg);
void func_0214cb10(u32 a, const void *b, void *c, u32 d);
void func_0214cb88(u32 a, const void *b, void *c, u32 d);
void func_0214cc04(u32 a, void *b, u32 c, u32 d);
void GxFifoSendWordsDone(void);
void GxFifoSendWords(u32 a, const void *b, u32 c, UnkFunc *f, u32 arg);
void GxFifoSendWordsInPiecesDone(void);
void GxFifoSendNextPiece(void);
void GxFifoSendWordsInPieces(u32 a, const void *b, u32 c, UnkFunc *f, u32 arg);

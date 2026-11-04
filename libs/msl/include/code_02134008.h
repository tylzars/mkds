#pragma once

#include "types.h"

// Two words passed and returned by value.
typedef struct WordPair {
    /* 00 */ u32 mLow;
    /* 04 */ u32 mHigh;
} WordPair;

typedef WordPair (*Unk02134008Func)(WordPair a, WordPair b, u32 c);

// Returned by GetFloatTrapTable; FloatTrapDispatch calls one of the function pointers at 0x04-0x14.
typedef struct FloatTrapTable {
    /* 00 */ u32 mUnk_00;
    /* 04 */ Unk02134008Func mHandlers[5];
} FloatTrapTable;

u32 FloatTrapPairPairToWord(u32 a, u32 b, u32 c, u32 d, u32 e);
u64 FloatTrapPairPairToPair(u32 a, u32 b, u32 c, u32 d, u32 e);
u32 FloatTrapWordWordToWord(u32 a, u32 b, u32 c);
u64 FloatTrapPairToPair(u32 a, u32 b, u32 c);
u64 FloatTrapWordToPair(u32 a, u32 b);
u32 FloatTrapPairToWord(u32 a, u32 b, u32 c);
u32 FloatTrapWordToWord(u32 a, u32 b);
WordPair FloatTrapDispatch(WordPair a, WordPair b, u32 c);

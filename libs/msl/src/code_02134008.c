#include "code_02133da8.h"
#include "code_021423e4.h"
#pragma avoid_byte all

#include "code_02134008.h"
#include "code_02139e20.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/code_02142000.h"

WordPair FloatTrapDispatch(WordPair a, WordPair b, u32 c) {
    FloatTrapTable *t;
    Unk02134008Func fn;

    t = GetFloatTrapTable();
    if ((c & 0xc00000) == 0) {
        c |= FloatStatusClearXor(0, 0) & 0xc00000;
    }
    switch (c & 0x7c000000) {
        case 0x40000000:
            fn = t->mHandlers[4];
            break;
        case 0x04000000:
            fn = t->mHandlers[0];
            break;
        case 0x10000000:
            fn = t->mHandlers[2];
            break;
        case 0x20000000:
            fn = t->mHandlers[3];
            break;
        case 0x08000000:
            fn = t->mHandlers[1];
            break;
        default:
            fn = 0;
            break;
    }
    if (fn == 0) {
        raise(2);
    }
    return fn(a, b, c);
}

u32 FloatTrapWordToWord(u32 a, u32 b) {
    WordPair s;
    WordPair r;

    s.mLow = a;
    r = FloatTrapDispatch(s, s, b);
    return r.mLow;
}

u32 FloatTrapPairToWord(u32 a, u32 b, u32 c) {
    WordPair s;
    WordPair r;

    s.mLow = a;
    s.mHigh = b;
    r = FloatTrapDispatch(s, s, c);
    return r.mLow;
}

u64 FloatTrapWordToPair(u32 a, u32 b) {
    WordPair s;
    WordPair r;

    s.mLow = a;
    r = FloatTrapDispatch(s, s, b);
    return *(u64 *) &r;
}

u64 FloatTrapPairToPair(u32 a, u32 b, u32 c) {
    WordPair s;
    WordPair r;

    s.mLow = a;
    s.mHigh = b;
    r = FloatTrapDispatch(s, s, c);
    return *(u64 *) &r;
}

u32 FloatTrapWordWordToWord(u32 a, u32 b, u32 c) {
    WordPair s;
    WordPair t;
    WordPair r;

    s.mLow = a;
    t.mLow = b;
    r = FloatTrapDispatch(s, t, c);
    return r.mLow;
}

u64 FloatTrapPairPairToPair(u32 a, u32 b, u32 c, u32 d, u32 e) {
    WordPair s;
    WordPair t;
    WordPair r;

    s.mLow = a;
    s.mHigh = b;
    t.mLow = c;
    t.mHigh = d;
    r = FloatTrapDispatch(s, t, e);
    return *(u64 *) &r;
}

u32 FloatTrapPairPairToWord(u32 a, u32 b, u32 c, u32 d, u32 e) {
    WordPair s;
    WordPair t;
    WordPair r;

    s.mLow = a;
    s.mHigh = b;
    t.mLow = c;
    t.mHigh = d;
    r = FloatTrapDispatch(s, t, e);
    return r.mLow;
}

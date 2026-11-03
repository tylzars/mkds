#include "00/code_02186a9c.h"
#include "03/code_021b94b8.h"
#include "00/code_02188008.h"
#include "00/unk_021b1000.h"
#include "00/code_02186628.h"
#include "code_0200d118.h"
#include "code_02134d30.h"
#include "code_02139f70.h"

#pragma opt_lifetimes off

BOOL func_ov000_02186a9c(Http *a, const u8 *b) {
    s32 d;
    HttpBuffer *c;
    s32 e;
    s32 f;
    c = &a->mSendBuffer;
    d = strlen(b);
    e = c->mEnd - c->mCursor;
    if (d > e) {
        if (GrowHttpBuffer(a, c, d - e + 1) == 0) {
            return TRUE;
        }
        e = c->mEnd - c->mCursor;
    }
    f = func_0200d9e0(c->mCursor, e, data_ov000_021b1290, b);
    if (f != d) {
        return TRUE;
    }
    c->mCursor = c->mCursor + f;
    return FALSE;
}

BOOL func_ov000_02186b0c(Http *a, const u8 *b, const void *c, s32 d) {
    HttpBuffer *e = &a->mSendBuffer;
    char *f;
    s32 g;
    s32 h;
    s32 i;
    s32 j;
    if (a->mPairCount == 0) {
        f = data_ov000_021b1294;
    } else {
        f = data_ov000_021b1298;
    }
    a->mPairCount = a->mPairCount + 1;
    g = func_ov000_021882f8(c, d, NULL, 0);
    h = strlen((const u8 *) f);
    i = g + (h - 2 + strlen(b));
    j = e->mEnd - e->mCursor;
    if (i > j) {
        if (GrowHttpBuffer(a, e, i - j + 1) == 0) {
            return TRUE;
        }
        j = e->mEnd - e->mCursor;
    }
    e->mCursor = e->mCursor + func_0200d9e0(e->mCursor, j, f, b);
    if (func_ov000_021882f8(c, d, (s8 *) e->mCursor, e->mEnd - e->mCursor - 1) < 0) {
        return TRUE;
    }
    e->mCursor = e->mCursor + g;
    *e->mCursor = 0;
    return FALSE;
}

BOOL func_ov000_02186bd4(Http *a, const u8 *b, const u8 *c) {
    s32 e;
    HttpBuffer *d;
    s32 f;
    char *g;
    s8 *p;
    s8 h;
    s32 i;
    d = &a->mSendBuffer;
    e = strlen(c);
    f = strlen((const u8 *) data_ov000_021b12a0);
    e = e + (f - 4 + strlen(b));
    i = d->mEnd - d->mCursor;
    if (e + 1 > i) {
        if (GrowHttpBuffer(a, d, e - i + 1) == 0) {
            return TRUE;
        }
    }
    p = (s8 *) strstr((const u8 *) d->mStart, data_ov000_021b1230);
    g = (char *) p + 2;
    h = p[2];
    memmove(g + e, g, strlen((const u8 *) g) + 1);
    i = func_0200d9e0(g, e + 1, data_ov000_021b12a0, b, c);
    g[i] = h;
    d->mCursor = d->mCursor + e;
    return FALSE;
}

BOOL func_ov000_02186c74(Http *a) {
    HttpBuffer *b = &a->mSendBuffer;
    char *c;
    s32 d;
    s32 e;
    s32 f;
    if (a->mUseGet == 0) {
        c = data_ov000_021b12ac;
    } else {
        c = data_ov000_021b1300;
    }
    d = strlen(a->mHost);
    e = strlen((const u8 *) c);
    f = d + (e - 4 + strlen(a->mPath));
    if (InitHttpBuffer(a, &a->mSendBuffer, f + 0x400) != 1) {
        return TRUE;
    }
    b->mCursor = b->mCursor + func_0200d9e0(b->mCursor, b->mSize, c, a->mPath, a->mHost);
    return FALSE;
}

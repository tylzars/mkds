#include "Main/Unknown/code_020a9ed8.h"

#include "Main/Unknown/code_020a9f20.h"
#include "Main/Unknown/code_020a9f40.h"
#include "Main/Unknown/code_020a9ff4.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ab604.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "code_0213ecf8.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/code_020aa810.h"

#pragma thumb on
u32 GetKeyboardKeyValue(void) {
    u32 value0;
    value0 = gKeyboardKeys.mKeyValue;
    return value0;
}
#pragma thumb off

#pragma thumb on

u16 ConvertCharPair1(u16 a) {
    u16 r;
    u16 t;

    if (a == 0 || a == 0x3000) {
        return a;
    }
    if (IsCharInTable2(a) != 0) {
        r = ConvertCharPair2(a);
        t = LookupCharInTablePair(gCharTablePair1, r);
        if (t != r) {
            return t;
        }
        return a;
    }
    if (IsCharInTable3(a) != 0) {
        r = ConvertCharPair3(a);
        t = LookupCharInTablePair(gCharTablePair1, r);
        if (t != r) {
            return t;
        }
        return a;
    }
    return LookupCharInTablePair(gCharTablePair1, a);
}

u16 ConvertCharPair2(u16 a) {
    u16 r;
    u16 t;

    if (a == 0 || a == 0x3000) {
        return a;
    }
    if (IsCharInTable1(a) != 0) {
        r = ConvertCharPair1(a);
        t = LookupCharInTablePair(gCharTablePair2, r);
        if (t != r) {
            return t;
        }
        return a;
    }
    return LookupCharInTablePair(gCharTablePair2, a);
}

u16 ConvertCharPair3(u16 a) {
    u16 r;
    u16 t;

    if (a == 0 || a == 0x3000) {
        return a;
    }
    if (IsCharInTable1(a) != 0) {
        r = ConvertCharPair1(a);
        t = LookupCharInTablePair(gCharTablePair3, r);
        if (t != r) {
            return t;
        }
        return a;
    }
    return LookupCharInTablePair(gCharTablePair3, a);
}

u16 CycleCharTables(u16 a) {
    s32 i;
    s32 j;
    s32 n;
    u16 **p;
    u16 *q;
    u16 *s;

    if (a == 0 || a == 0x3000) {
        return a;
    }
    for (i = 0, p = gCharTables; i < 4; p++, i++) {
        q = wcschr(*p, a);
        if (q != NULL) {
            n = q - gCharTables[i];
            break;
        }
    }
    if (i < 4) {
        for (j = 1; j < 4; j++) {
            s = gCharTables[(i + j) % 4];
            if (s[n] != 0x3000) {
                return s[n];
            }
        }
    } else {
        return a;
    }
    return a;
}

u32 IsCharInTable1(u16 a) {
    if (wcschr(gCharTablePair1[1], a) != NULL) {
        return 1;
    }
    return 0;
}

u32 IsCharInTable2(u16 a) {
    if (wcschr(gCharTablePair2[1], a) != NULL) {
        return 1;
    }
    return 0;
}

u32 IsCharInTable3(u16 a) {
    if (wcschr(gCharTablePair3[1], a) != NULL) {
        return 1;
    }
    return 0;
}

void AddToNonzeroNibblesInTile(u32 *a, u32 b, s32 c, s32 d, s32 e, s32 f) {
    u32 v1;
    u32 m;
    u32 *p;
    u32 w;
    s32 i;

    v1 = 0;
    for (i = 0; i < e - c; i++) {
        v1 |= b << (i * 4);
    }
    v1 <<= c * 4;
    if (d < f) {
        p = a + d;
        do {
            m = v1;
            w = *p;
            if ((w & 0xf0000000) == 0) {
                m &= 0xfffffff;
            }
            if ((w & 0xf000000) == 0) {
                m &= 0xf0ffffff;
            }
            if ((w & 0xf00000) == 0) {
                m &= 0xff0fffff;
            }
            if ((w & 0xf0000) == 0) {
                m &= 0xfff0ffff;
            }
            if ((w & 0xf000) == 0) {
                m &= 0xffff0fff;
            }
            if ((w & 0xf00) == 0) {
                m &= 0xfffff0ff;
            }
            if ((w & 0xf0) == 0) {
                m &= ~0xf0;
            }
            if ((w & 0xf) == 0) {
                m &= ~0xf;
            }
            *p += m;
            p++;
            d++;
        } while (d < f);
    }
}

void AddToNonzeroNibblesOnRectEdge(u32 (*a)[8], s32 b, u32 c, s32 d, s32 e, s32 f, s32 g) {
    AddToNonzeroNibblesInRect(a, b, c, d, e, f, e + 1);
    AddToNonzeroNibblesInRect(a, b, c, d, g - 1, f, g);
    AddToNonzeroNibblesInRect(a, b, c, d, e + 1, d + 1, g - 1);
    AddToNonzeroNibblesInRect(a, b, c, f - 1, e + 1, f, g - 1);
}

void AddToNonzeroNibblesInRect(u32 (*a)[8], s32 b, u32 c, s32 d, s32 e, s32 f, s32 g) {
    s32 y;
    s32 x0;
    s32 x1;
    s32 y1;
    s32 v1;
    s32 v2;
    s32 w;

    if (d < f && e < g) {
        x0 = d >> 3;
        x1 = ((f - 1) >> 3) + 1;
        y1 = ((g - 1) >> 3) + 1;
        y = e >> 3;
        if (y < y1) {
            v1 = y << 3;
            w = b >> 3;
            v2 = y * w;
            do {
                s32 x;
                x = x0;
                for (; x < x1; x++) {
                    s32 s;
                    s32 t;
                    s32 u;
                    s32 v;

                    s = d - (x << 3);
                    if (s < 0) {
                        s = 0;
                    }
                    t = e - v1 < 0 ? 0 : e - v1;
                    u = f - (x << 3);
                    if (u > 8) {
                        u = 8;
                    }
                    v = g - v1 > 8 ? 8 : g - v1;
                    AddToNonzeroNibblesInTile(a[x + v2], c, s, t, u, v);
                }
                v1 += 8;
                v2 += w;
                y++;
            } while (y < y1);
        }
    }
}

void RefreshKeyboardCursor(KeyboardKeys *a) {
    KeyboardRect *q;
    KeyboardRect *r;
    s32 x;
    s32 y;

    q = a->mCursorRect;
    if (q == NULL) {
        a->mCursorRect = a->mCurrentLayout->mRects + a->mCurrentLayout->mFixedKeyCount;
        return;
    }
    if (q->mKeyId <= 0xff) {
        x = gKeyboardOffsetX + ((q->mX << 1) + q->mWidth) / 2 + 3;
        y = gKeyboardOffsetY + ((q->mY << 1) + q->mHeight) / 2 - 3;
    } else {
        x = ((q->mX << 1) + q->mWidth) / 2 + 3;
        y = ((q->mY << 1) + q->mHeight) / 2 - 3;
    }
    r = FindKeyboardRectAt(a, x, y);
    if (r != NULL) {
        a->mCursorRect = r;
        return;
    }
    a->mCursorRect = a->mCurrentLayout->mRects + a->mCurrentLayout->mFixedKeyCount;
}

KeyboardRect *FindKeyboardRectInDirection(u32 a, KeyboardRect *b, KeyboardRect *c) {
    s32 x0;
    s32 x1;
    s32 y0;
    s32 y1;
    s32 v1;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 x;
    s32 x2;
    s32 y2;
    s32 v5;
    s32 v6;
    s32 k;
    s32 m;
    s32 h8;
    s32 w8;
    u16 r;
    KeyboardRect *q;
    KeyboardRect *e;
    Ncgr *g;

    if (gKeyboardKeys.mCursorCallback != NULL) {
        r = gKeyboardKeys.mCursorCallback(GetKeyboardRectValue(b), a);
        if (r != 0) {
            q = FindKeyboardRectByValue(r);
            if (q != NULL) {
                return q;
            }
        }
    }
    if (b->mKeyId <= 0xff) {
        v3 = gKeyboardOffsetX;
        v4 = gKeyboardOffsetY;
    } else {
        v3 = 0;
        v4 = 0;
    }
    if ((a & 0x40) != 0) {
        v1 = -8;
        v2 = -8;
        x0 = x1 = v3 + (b->mX + b->mX + b->mWidth) / 2;
        x1 -= 0x10;
        y0 = v4 + b->mY;
        y1 = y0 - 0x120;
    } else if ((a & 0x80) != 0) {
        v1 = 8;
        v2 = 8;
        x0 = x1 = v3 + (b->mX + b->mX + b->mWidth) / 2;
        x1 += 0x10;
        y0 = v4 + (b->mY + b->mHeight);
        y1 = y0 + 0x120;
    } else if ((a & 0x20) != 0) {
        v1 = -8;
        v2 = 8;
        x0 = v3 + b->mX;
        x1 = x0 - 0x120;
        y0 = y1 = v4 + (b->mY + b->mY + b->mHeight) / 2;
        y1 += 0x10;
    } else if ((a & 0x10) != 0) {
        v1 = 8;
        v2 = 8;
        x0 = v3 + (b->mX + b->mWidth);
        x1 = x0 + 0x120;
        y0 = y1 = v4 + (b->mY + b->mY + b->mHeight) / 2;
        y1 += 0x10;
    }
    for (; y0 != y1; y0 += v2) {
        x = x0;
        if (x != x1) {
            v6 = y0 - v4;
            do {
                x2 = x;
                y2 = y0;
                g = gKeyboardKeys.mCurrentLayout->mNcgr;
                h8 = g->mUnk_02 << 3;
                w8 = g->mUnk_00 << 3;
                v5 = x - v3;
                k = data_usa_021679f8;
                m = -k;
                if (v5 < m) {
                    x2 = x + (h8 + k * 2);
                } else if (v5 > h8 + k) {
                    x2 = x - (h8 + k * 2);
                }
                if (v6 < m) {
                    y2 = y2 + (w8 + k * 2);
                } else if (v6 > w8 + k) {
                    y2 = y2 - (w8 + k * 2);
                }
                e = FindKeyboardRectAt(&gKeyboardKeys, x2, y2);
                if (e != NULL && e != b) {
                    return e;
                }
                x += v1;
            } while (x != x1);
        }
    }
    return b;
}

u16 LookupCharInTablePair(u16 **a, u16 b) {
    s32 i;
    u16 *p;
    u16 r;

    for (i = 0; i < 2; i++) {
        p = wcschr(a[i], b);
        if (p != NULL) {
            r = a[1 - i][p - a[i]];
            if (r != 0x3000) {
                return r;
            }
            return b;
        }
    }
    return b;
}

void SetupKeyboardLayout(KeyboardRect *a, Ncgr *b, void (*c)(KeyboardKeys *), s32 d, u32 e, u16 *f) {
    u32 x;
    u32 y;

    gKeyboardKeys.mCurrentLayout = &data_0217b294;
    gKeyboardKeys.mCurrentLayout->mRects = a;
    gKeyboardKeys.mCurrentLayout->mNcgr = b;
    gKeyboardKeys.mCurrentLayout->mCallback = c;
    gKeyboardKeys.mCurrentLayout->mFixedKeyCount = d - 1;
    gKeyboardKeys.mCurrentLayout->mRectCount = e;
    gKeyboardKeys.mCharMap = f + 1;
    if (gKeyboardKeys.mTouchStartRect != NULL) {
        x = GetKeyboardLastTouchX();
        y = GetKeyboardLastTouchY();
        gKeyboardKeys.mTouchStartRect = FindKeyboardRectAt(&gKeyboardKeys, x, y);
    }
    FillKeyboardBg2Scr(&gKeyboardKeys);
    DrawKeyboardGlyphs(&gKeyboardKeys);
    MarkKeyboardRects(&gKeyboardKeys);
    RefreshKeyboardCursor(&gKeyboardKeys);
}

void SetupKeyboardLayoutHiragana(KeyboardRect *a, Ncgr *b, u32 c) {
    data_0217b2b8[0] = 4;
    data_0217b2b8[1] = 0;
    SetupKeyboardLayout(a, b, HiraganaKatakanaLayoutCallback, 9, c, gKbdmapHiragana);
}

#pragma thumb off

#pragma thumb on

void SetupKeyboardLayoutAscii(KeyboardRect *a, struct Ncgr *b, u32 c) {
    u16 *v1;
    v1 = (u16 *) &data_0217b2b8;
    *(u16 *) &data_0217b2b8 = 0;
    v1[1] = 0;
    SetupKeyboardLayout(a, b, AsciiLayoutCallback, 6, c, gKbdmapAscii);
}

void SetupKeyboardLayoutOther1(KeyboardRect *a, struct Ncgr *b, u32 c) {
    u16 *v1;
    v1 = (u16 *) &data_0217b2b8;
    *(u16 *) &data_0217b2b8 = 0;
    v1[1] = 0;
    SetupKeyboardLayout(a, b, NULL, 4, c, gKbdmapOther1);
}

void SetupKeyboardLayoutOther2(KeyboardRect *a, struct Ncgr *b, u32 c) {
    u16 *v1;
    v1 = (u16 *) &data_0217b2b8;
    *(u16 *) &data_0217b2b8 = 0;
    v1[1] = 0;
    SetupKeyboardLayout(a, b, NULL, 4, c, gKbdmapOther2);
}

void SetupKeyboardLayoutOther3(KeyboardRect *a, struct Ncgr *b, u32 c) {
    u16 *v1;
    v1 = (u16 *) &data_0217b2b8;
    *(u16 *) &data_0217b2b8 = 0;
    v1[1] = 0;
    SetupKeyboardLayout(a, b, NULL, 4, c, gKbdmapOther3);
}

#pragma thumb off

#pragma thumb on

void SetKeyboardRect(KeyboardRect *p, u32 a, u32 b, u32 c, u32 d) {
    if (p != NULL) {
        p->mX = a;
        p->mY = b;
        p->mWidth = c - a;
        p->mHeight = d - b;
        p->mNextRectOffset = 0;
        p->mKeyId = 0xff00;
    }
}

#pragma thumb off

#pragma thumb on

void SetKeyboardButton0Rect(u32 a, u32 b, u32 c, u32 d) {
    SetKeyboardRect(&gKeyboardKeys.mButton0Rect, a, b, c, d);
}

void SetKeyboardButton1Rect(u32 a, u32 b, u32 c, u32 d) {
    SetKeyboardRect(&gKeyboardKeys.mButton1Rect, a, b, c, d);
}

#pragma thumb off

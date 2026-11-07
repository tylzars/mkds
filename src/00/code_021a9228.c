#include "00/code_021a9228.h"

#include "00/code_021ab6d4.h"
#include "00/code_021abd2c.h"
#include "00/code_021ad734.h"
#include "00/types_021a998c.h"
#include "00/types_021ab5e4.h"
#include "00/unk_021b6000.h"
#include "code_0214d018.h"
#include "00/code_021abca0.h"
#include "os_thread.h"
#include "00/code_021abc24.h"
#include "code_0200fc8c.h"
#include "00/code_021ac3e4.h"
#include "00/code_021ab000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/unk_021b4000.h"
#include "code_02139f70.h"
#include "00/code_021acbf8.h"
#include "00/code_021acc8c.h"
#include "code_0214d93c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200f5ac.h"
#include "code_0214e1e0.h"

HttpsEntry *FindEntryByBytesAndSetLastUseTime(const u8 *a) {
    s32 i;
    HttpsEntry *e;
    i = 0;
    e = data_ov000_021b61f4;
    for (; i < 4; i++) {
        if (e->mInUse != 0 && memcmp(e->mUnk_00, a, 0x20) == 0) {
            e->mLastUseTime = OS_GetTick() >> 16;
            return e;
        }
        e++;
    }
    return NULL;
}

HttpsEntry *FindEntryByValuePairAndSetLastUseTime(u32 a, u32 b) {
    HttpsEntry *e;
    s32 i;
    i = 0;
    e = data_ov000_021b61f4;
    for (; i < 4; i++) {
        if (e->mInUse != 0 && e->mUnk_54 == a && e->mUnk_58 == b) {
            e->mLastUseTime = OS_GetTick() >> 16;
            return e;
        }
        e++;
    }
    return NULL;
}

// Takes the first free entry, else the one stamped longest ago; copies the 0x20 bytes in, stamps it and marks it in
// use.
HttpsEntry *AddEntryOrReplaceLongestUnused(const u8 *a) {
    HttpsEntry *v1;
    u32 t;
    s32 i;
    u32 v2;
    u32 v3;
    HttpsEntry *e;
    t = OS_GetTick() >> 16;
    v3 = 0;
    v1 = data_ov000_021b61f4;
    i = 0;
    e = v1;
    for (; i < 4; i++) {
        if (e->mInUse == 0) {
            v1 = e;
            break;
        }
        v2 = t - e->mLastUseTime;
        if (v2 > v3) {
            v3 = v2;
            v1 = e;
        }
        e++;
    }
    MI_CpuCopy8(a, v1, 0x20);
    v1->mLastUseTime = t;
    v1->mInUse = 1;
    return v1;
}

// The clock's date and time as seconds, plus 0x386d4380.
u32 GetRtcSecondsPlusFixedOffset(void) {
    RTCDate a;
    RTCTime b;
    RTC_GetDate(&a);
    RTC_GetTime(&b);
    return (u32) RTC_ConvertDateTimeToSecond(&a, &b) + 0x386d4380;
}

void SetAuthorityTable(u32 table, u32 count) {
    Unk021a998c *v1;
    HttpsState *v2;
    v1 = data_0216ff5c.mCurrentThread->mUnk_a4[0];
    if ((v1 != NULL) && (v2 = v1->mHttpsState, v2 != NULL)) {
        v2->mAuthorities = table;
        v2->mAuthorityCount = count;
    }
}

u32 FindAuthorityByName(HttpsState *a, const s8 *b) {
    int v1;
    int v2;
    u32 *v3;
    u32 *v4;
    int v5;
    v2 = 0;
    v1 = a->mAuthorityCount;
    if (0 < v1) {
        v4 = (u32 *) a->mAuthorities;
        v3 = v4;
        do {
            v5 = strcmp((const char *) (*(u32 *) *v3), (const char *) b);
            if (v5 == 0) {
                return v4[v2];
            }
            v3 = v3 + 1;
            v2 = v2 + 1;
        } while (v2 < v1);
    }
    return 0;
}

// Reads a length (one byte below 0x80, else 0x80 + n followed by n big-endian bytes) and moves *a past it; -1 when the
// value would not fit in 32 bits.
s32 ReadLengthAndAdvance(u8 **a) {
    u8 *p;
    s32 x;
    u32 k;
    p = *a;
    x = *p++;
    if ((x & 0x80) != 0) {
        k = x & 0x7f;
        x = 0;
        while (k-- != 0) {
            if ((x & 0xff000000) != 0) {
                return -1;
            }
            x = (x << 8) + *p++;
        }
    }
    *a = p;
    return x;
}

void AppendCommaSeparatedText(s8 *dest, const s8 *source, s32 count) {
    s8 *d;
    d = dest;
    if (*dest != 0) {
        do {
            dest++;
        } while (*dest != 0);
        if (dest - d >= 0xff) {
            return;
        }
        *dest++ = ',';
        *dest++ = ' ';
    }
    while (count-- != 0 && dest - d < 0xff) {
        *dest++ = *source++;
    }
    *dest = 0;
}

// Returns year << 16 | month << 8 | day from digit text; a tag of 0x17 means a two-digit year, else four digits.
u32 ParseDateText(const u8 *digits, u32 tag) {
    u32 x;
    u32 y;
    x = digits[1] + digits[0] * 10 - 0x210;
    digits += 2;
    if (tag == 0x17) {
        if (x < 0x32) {
            y = x + 0x7d0;
        } else {
            y = x + 0x76c;
        }
    } else {
        y = x * 100 + (digits[1] + digits[0] * 10 - 0x210);
        digits += 2;
    }
    return (y << 16) + ((digits[1] + digits[0] * 10 - 0x210) << 8) + (digits[3] + digits[2] * 10 - 0x210);
}

// Parses one tag-length-value item and the items inside the container tags; returns TRUE on a bad length or a failed
// inner item.
BOOL ParseTaggedItem(HttpsState *a, u8 **b, s32 depth, s32 index, s32 mode) {
    u8 *p;
    u32 t;
    u32 k;
    s32 n;
    u8 *v1;
    s32 i;
    u8 *q;
    const char *s;
    const char **v2;
    u32 v;
    p = *b;
    t = *p++;
    n = ReadLengthAndAdvance(&p);
    if (n < 0 || n > 0x7d0) {
        return TRUE;
    }
    k = t & 0x1f;
    switch (k) {
        case 2:
            if (a->mCaptureValues != 0) {
                if (index == 0) {
                    while (*p == 0) {
                        p++;
                        n--;
                    }
                    switch (mode) {
                        case 0:
                            if (n <= 0x100) {
                                MI_CpuCopy8(p, a->mFirstValue, n);
                                a->mFirstValueLength = n;
                            }
                            break;
                        case 2:
                            a->mItemRecord.mFirstLength = n;
                            a->mItemRecord.mFirstBytes = p;
                            break;
                    }
                } else if (index == 1) {
                    while (*p == 0) {
                        p++;
                        n--;
                    }
                    switch (mode) {
                        case 0:
                            if (n <= 8) {
                                MI_CpuCopy8(p, a->mSecondValue, n);
                                a->mSecondValueLength = n;
                            }
                            break;
                        case 2:
                            a->mItemRecord.mSecondLength = n;
                            a->mItemRecord.mSecondBytes = p;
                            break;
                    }
                }
            }
            p += n;
            break;
        case 3:
            if (depth == 1 && mode != 2) {
                a->mCheckedBytes = p + 1;
                a->mCheckedBytesLength = n - 1;
            }
            if (a->mCaptureValues != 0) {
                p++;
                if (ParseTaggedItem(a, &p, depth, 0, mode) != FALSE) {
                    return TRUE;
                }
                a->mCaptureValues = 0;
            } else {
                p += n;
            }
            break;
        case 6:
            i = 0;
            v2 = data_ov000_021b4a30;
            q = p;
            do {
                s = *v2;
                if (memcmp(q, s, strlen(s)) == 0) {
                    switch (i) {
                        case 1:
                        case 2:
                            if (mode == 0) {
                                a->mUnk_430 = i;
                            }
                            a->mCaptureValues = i;
                            break;
                        case 3:
                        case 4:
                            if (mode != 2) {
                                a->mDigestKind = i;
                            }
                            break;
                        case 5:
                            if (mode != 2) {
                                a->mCopyNextText = i;
                            }
                            break;
                    }
                    break;
                }
                v2++;
                i++;
            } while (i < 6);
            p += n;
            break;
        case 0xc:
        case 0x13:
        case 0x14:
        case 0x16:
            if (mode != 2) {
                if (a->mDatesSeen != 0) {
                    AppendCommaSeparatedText(a->mUnk_684, (const s8 *) p, n);
                    if (a->mCopyNextText == 5 && n <= 0x4f) {
                        MI_CpuCopy8(p, a->mHostPattern, n);
                        a->mHostPattern[n] = 0;
                    }
                } else {
                    AppendCommaSeparatedText(a->mAuthorityName, (const s8 *) p, n);
                }
            }
            a->mCopyNextText = 0;
            p += n;
            break;
        case 0x17:
        case 0x18:
            if (mode != 2) {
                v = ParseDateText(p, k);
                if (index == 0) {
                    if (a->mCurrentDate >= v) {
                        a->mDateInRange = 1;
                    }
                } else {
                    if (a->mCurrentDate > v) {
                        a->mDateInRange = 0;
                    }
                }
            }
            p += n;
            a->mDatesSeen = 1;
            break;
        case 0x10:
            if (depth == 0 && index == 0 && mode != 2) {
                a->mDigestStart = p;
            }
            v1 = p + n;
            n = 0;
            if (p < v1) {
                do {
                    i = ParseTaggedItem(a, &p, depth + 1, n, mode);
                    n++;
                    if (i != 0) {
                        return TRUE;
                    }
                } while (p < v1);
            }
            if (depth == 1 && index == 0 && mode != 2) {
                a->mDigestEnd = p;
            }
            break;
        case 0x11:
            v1 = p + n;
            if (p < v1) {
                do {
                    if (ParseTaggedItem(a, &p, depth + 1, 0, mode) != FALSE) {
                        return TRUE;
                    }
                } while (p < v1);
            }
            break;
        default:
            if (t == 0xa0) {
                v1 = p + n;
                if (p < v1) {
                    do {
                        if (ParseTaggedItem(a, &p, depth + 1, 0, mode) != FALSE) {
                            return TRUE;
                        }
                    } while (p < v1);
                }
            } else {
                p += n;
            }
            break;
    }
    *b = p;
    return FALSE;
}

// Returns 0 when the bytes, run through the two values of the authority record, start 00 01, a run of 0xff, 00, 30 and
// end with mRangeDigest, else 2.
u32 CheckTransformedBytesHoldPaddedDigest(HttpsState *a, Unk021aaf38 *b) {
    s32 n;
    u16 *c;
    u16 *d;
    u16 *e;
    u16 *f;
    u32 g;
    OSThread *t;
    u32 r;
    enum { K0 } i;
    if (a->mCheckedBytes == NULL || a->mCheckedBytesLength == 0 || b->mSecondBytes == NULL || b->mSecondLength == 0 ||
        b->mFirstBytes == NULL || b->mFirstLength == 0) {
        return 2;
    }
    n = b->mFirstLength * 2;
    n = n / 2;
    c = (u16 *) data_ov000_021b63a4(n * 8);
    if (c == NULL) {
        return 2;
    }
    d = c + n;
    e = d + n;
    f = e + n;
    func_ov000_021ac4b8(d, a->mCheckedBytes, a->mCheckedBytesLength, n);
    func_ov000_021ac4b8(e, b->mSecondBytes, b->mSecondLength, n);
    func_ov000_021ac4b8(f, b->mFirstBytes, b->mFirstLength, n);
    if (data_ov000_021b49f4 < 0x20) {
        t = data_0216ff5c.mCurrentThread;
        g = OS_GetThreadPriority(t);
        OS_SetThreadPriority(t, data_ov000_021b49f4);
        func_ov000_021ac7e8(c, d, e, n, f);
        OS_SetThreadPriority(t, g);
    } else {
        func_ov000_021ac7e8(c, d, e, n, f);
    }
    func_ov000_021ac488((u8 *) d, c, b->mFirstLength, n);
    r = 0;
    if (((u8 *) d)[0] != 0 || ((u8 *) d)[1] != 1) {
        r = 2;
    } else {
        i = 2;
        if (b->mFirstLength > 2) {
            do {
                if (((u8 *) d)[i] != 0xff) {
                    break;
                }
                i++;
            } while (i < b->mFirstLength);
        }
        if (i + 1 >= b->mFirstLength || ((u8 *) d)[i] != 0 || ((u8 *) d)[i + 1] != 0x30 ||
            memcmp(a->mRangeDigest, (u8 *) d + b->mFirstLength - a->mRangeDigestLength, a->mRangeDigestLength) != 0) {
            r = 2;
        }
    }
    data_ov000_021b63ac(c);
    return r;
}

// Flags: 0x8000 when mDateInRange is clear; low byte 1 no authority found, 2 check failed, 3 unknown digest kind, 4
// mUnk_430 is -1.
u32 ComputeParsedItemCheckFlags(HttpsState *a) {
    u32 f;
    Unk021ab728 *h;
    Unk021abca0 *g;
    u32 r;
    if (a->mDateInRange != 0) {
        f = 0;
    } else {
        f = 0x8000;
    }
    if (a->mUnk_430 == -1) {
        f |= 4;
        return f;
    }
    switch (a->mDigestKind) {
        case 3:
            h = &a->mScratchHash16;
            func_ov000_021ab7b4(h);
            func_ov000_021ab728(h, a->mDigestStart, a->mDigestEnd - a->mDigestStart);
            func_ov000_021ab6d4(h, a->mRangeDigest);
            a->mRangeDigestLength = 0x10;
            break;
        case 4:
            g = &a->mScratchHash20;
            func_ov000_021abd2c(g);
            func_ov000_021abca0(g, a->mDigestStart, a->mDigestEnd - a->mDigestStart);
            func_ov000_021abc4c(g, a->mRangeDigest);
            a->mRangeDigestLength = 0x14;
            break;
        default:
            f |= 3;
            return f;
    }
    r = FindAuthorityByName(a, a->mAuthorityName);
    if (r == 0) {
        f |= 1;
        return f;
    }
    f |= CheckTransformedBytesHoldPaddedDigest(a, (Unk021aaf38 *) r);
    return f;
}

s32 GetTextLengthUpToDot(const s8 *text) {
    const s8 *start = text;
    while (*text != '.' && *text != 0) {
        text++;
    }
    return text - start;
}

// Returns FALSE when the texts match; a '*' in the second matches the first characters of one dot-separated part of the
// first.
BOOL CompareTextWithWildcard(const s8 *text, const s8 *pattern) {
    s32 x;
    s32 y;
    s8 c;
    s8 d;
    for (;;) {
        while ((d = *text++) == (c = *pattern++)) {
            if (d == 0) {
                return FALSE;
            }
        }
        if (c != '*') {
            return TRUE;
        }
        text--;
        x = GetTextLengthUpToDot(text);
        y = GetTextLengthUpToDot(pattern);
        if (y > x) {
            return TRUE;
        }
        text += x - y;
    }
}

// Parses and checks each item of the list message in turn, passing the flags to mCheckFlagsCallback; mSetupState
// becomes 3 when the last result is 0, else 9.
void ParseAndCheckItemListMessage(HttpsState *a, u8 *b) {
    s32 i;
    s32 n;
    u32 f;
    u32 t;
    BOOL m;
    s32 k;
    u8 *q;
    RTCDate d;
    n = (((b[0] << 8) + b[1]) << 8) + b[2];
    b += 3;
    a->mUnk_430 = -1;
    RTC_GetDate(&d);
    a->mCurrentDate = d.mDay + (((d.mYear + 0x7d0) << 16) + (d.mMonth << 8));
    a->mUnk_684[0] = 0;
    a->mFirstValueLength = a->mSecondValueLength = 0;
    m = FALSE;
    i = m;
    for (;;) {
        k = (((b[0] << 8) + b[1]) << 8) + b[2];
        b += 3;
        n -= k + 3;
        a->mDigestKind = -1;
        a->mCaptureValues = 0;
        a->mDatesSeen = 0;
        a->mDateInRange = 0;
        a->mUnk_684[0] = 0;
        a->mAuthorityName[0] = 0;
        a->mHostPattern[0] = 0;
        a->mItemBytes = b;
        a->mItemLength = k;
        if (ParseTaggedItem(a, &b, 0, 0, m) != 0 || a->mFirstValueLength < 0x33 || a->mSecondValueLength == 0) {
            a->mSetupState = 9;
            return;
        }
        f = ComputeParsedItemCheckFlags(a);
        if (i == 0 && a->mHost != NULL && CompareTextWithWildcard(a->mHost, a->mHostPattern) != 0) {
            f |= 0x4000;
        }
        t = f & 0xff;
        if (t == 1 && n != 0) {
            q = b + 3;
            a->mCaptureValues = 0;
            if (ParseTaggedItem(a, &q, 0, 0, 2) != 0) {
                a->mSetupState = 9;
                return;
            }
            f = (f & ~0xff) | CheckTransformedBytesHoldPaddedDigest(a, &a->mItemRecord);
        }
        if (a->mCheckFlagsCallback != NULL) {
            f = a->mCheckFlagsCallback(f, a, i);
        }
        i++;
        if (t != 0 && f == 0 && n != 0) {
            m = TRUE;
            continue;
        }
        break;
    }
    if (f == 0) {
        a->mSetupState = 3;
    } else {
        a->mSetupState = 9;
    }
}

void ParseKind2Message(HttpsState *a, u8 *b) {
    u8 n;
    u8 *p;
    u8 *q;
    HttpsEntry *s;
    MI_CpuCopy8(b + 2, a->mKind2Block, 0x20);
    q = b + 0x22;
    b = (u8 *) b + 0x23;
    n = *q;
    s = a->mEntry;
    if (s != NULL && n == 0x20 && memcmp(s->mUnk_00, b, 0x20) == 0) {
        a->mReusedEntry = 1;
    } else {
        if (s != NULL) {
            s->mInUse = 0;
        }
        if (n == 0) {
            a->mEntry = &data_ov000_021b6198;
        } else {
            a->mEntry = AddEntryOrReplaceLongestUnused(b);
        }
        a->mReusedEntry = 0;
    }
    p = b + n;
    a->mCommonValue = (p[0] << 8) + p[1];
    a->mSetupState = 2;
}

BOOL IsBigEndianValueInList(const u8 *list, s32 count, s32 width, u32 value) {
    s32 i;
    u32 e;
    for (i = 0; i < count; i++) {
        e = (list[0] << 8) + list[1];
        if (width == 3) {
            e = (e << 8) + list[2];
        }
        if (e == value) {
            return TRUE;
        }
        list += width;
    }
    return FALSE;
}

u32 FindOfferedValueInList(const u8 *list, s32 count, s32 width) {
    u32 i;
    const u16 *p;
    for (i = 0, p = gOfferedValues; i < 2; p++, i++) {
        if (IsBigEndianValueInList(list, count, width, *p) != 0) {
            return gOfferedValues[i];
        }
    }
    return 0;
}

u32 IsFirstArgumentThree(int a, int b) {
    if (a == 3) {
        return 1;
    }
    return 0;
}

void ParseKind1MessageWithThreeByteValues(HttpsState *a, u8 *b) {
    s32 n;
    u16 m;
    s32 x;
    s32 y;
    if (IsFirstArgumentThree(b[0], b[1]) != 0) {
        n = (b[2] << 8) + b[3];
        m = FindOfferedValueInList(b + 8, n / 3, 3);
        if (m != 0) {
            a->mCommonValue = m;
            x = (b[4] << 8) + b[5];
            y = (b[6] << 8) + b[7];
            a->mEntry = NULL;
            b += n + 8 + x;
            if (y >= 0x20) {
                MI_CpuCopy8(b, a->mKind1Block, 0x20);
            } else {
                MI_CpuFill8(a->mKind1Block, 0, 0x20 - y);
                MI_CpuCopy8(b, a->mKind2Block - y, y);
            }
            a->mSetupState = 1;
        }
    }
}

void ParseKind1Message(HttpsState *a, const u8 *b) {
    u8 n;
    u16 m;
    const u8 *c;
    if (IsFirstArgumentThree(b[0], b[1]) != 0) {
        MI_CpuCopy8(b + 2, a->mKind1Block, 0x20);
        n = b[0x22];
        c = b + 0x23;
        if (n != 0x20) {
            a->mEntry = NULL;
        } else {
            a->mEntry = FindEntryByBytesAndSetLastUseTime(c);
        }
        c += n;
        m = FindOfferedValueInList(c + 2, ((c[0] << 8) + c[1]) / 2, 2);
        a->mCommonValue = m;
        if (m != 0) {
            a->mSetupState = 1;
        }
    }
}

// Transforms the bytes in b with the six length and pointer pairs of c and writes 0x30 bytes to a.
void func_ov000_021aa880(u8 *a, const u8 *b, Unk021aa880 *c) {
    u16 *d;
    u16 *e;
    u16 *f;
    u16 *g;
    u16 *h;
    u16 *i;
    u16 *j;
    u16 *k;
    s32 n;
    if (c == NULL || c->mUnk_00 == 0) {
        return;
    }
    n = c->mUnk_00 * 2;
    n = n / 2 + 1;
    d = (u16 *) data_ov000_021b63a4(n * 0x14);
    if (d == NULL) {
        return;
    }
    e = d + n;
    f = e + n;
    g = f + n;
    h = g + n;
    i = h + n;
    j = i + n;
    k = j + n;
    func_ov000_021ac4b8(d, b, c->mUnk_00, n);
    func_ov000_021ac4b8(e, c->mUnk_1c, c->mUnk_18, n);
    func_ov000_021ac4b8(i, c->mUnk_0c, c->mUnk_08, n);
    func_ov000_021ac4f4(g, d, e, n, i);
    func_ov000_021ac4b8(e, c->mUnk_24, c->mUnk_20, n);
    func_ov000_021ac4b8(i, c->mUnk_14, c->mUnk_10, n);
    func_ov000_021ac4f4(h, d, e, n, i);
    func_ov000_021acd24(d, g, h, n);
    func_ov000_021ac4b8(e, c->mUnk_2c, c->mUnk_28, n);
    func_ov000_021acbf8(f, d, e, n);
    func_ov000_021ac4b8(e, c->mUnk_14, c->mUnk_10, n);
    func_ov000_021acbf8(d, f, e, n);
    func_ov000_021ace14(f, d, h, n);
    func_ov000_021ac4b8(e, c->mUnk_04, c->mUnk_00, n);
    if (func_ov000_021ace90(f, n) < 0) {
        func_ov000_021acda8(f, n);
        func_ov000_021ac900(NULL, f, e, j, n, k);
        func_ov000_021acd24(j, e, j, n);
    } else {
        func_ov000_021ac900(NULL, f, e, j, n, k);
    }
    func_ov000_021ac488(a, j, 0x30, n);
    data_ov000_021b63ac(d);
}

void ComputeLabeledDigest16(u8 *a, const u8 *b, HttpsState *c) {
    u8 d[0x14];
    Unk021abca0 *e;
    Unk021ab728 *g;
    e = &c->mScratchHash20;
    func_ov000_021abd2c(e);
    func_ov000_021abca0(e, b, strlen((const char *) b));
    func_ov000_021abca0(e, c->mEntry->mUnk_20, 0x30);
    func_ov000_021abca0(e, c->mKind1Block, 0x20);
    func_ov000_021abca0(e, c->mKind2Block, 0x20);
    func_ov000_021abc4c(e, d);
    g = &c->mScratchHash16;
    func_ov000_021ab7b4(g);
    func_ov000_021ab728(g, c->mEntry->mUnk_20, 0x30);
    func_ov000_021ab728(g, d, 0x14);
    func_ov000_021ab6d4(g, a);
}

void ReplaceEntryBytesWithLabeledDigests(HttpsState *a) {
    u8 v1[16];
    u8 v2[16];
    u8 v3[16];
    ComputeLabeledDigest16(v1, gLabelAText, a);
    ComputeLabeledDigest16(v2, gLabelBBText, a);
    ComputeLabeledDigest16(v3, gLabelCCCText, a);
    MI_CpuCopy8(v1, a->mEntry->mUnk_20, 0x30);
}

// Fills mDerivedBytes from digests, splits it between the send and receive members and seeds the two key stream states.
void DeriveBytesAndInitKeyStreamStates(HttpsState *a) {
    s32 x;
    s32 y;
    s32 z;
    s32 n;
    s32 o;
    s32 i;
    s32 j;
    u8 c[0x15];
    void *h;
    switch (a->mCommonValue) {
        case 4:
            x = 0x10;
            y = 0x10;
            z = 0;
            break;
        case 5:
            x = 0x14;
            y = 0x10;
            z = 0;
            break;
    }
    n = (x + y + z) * 2;
    i = 0;
    if (n > 0) {
        o = 0;
        do {
            h = &a->mScratchHash20;
            func_ov000_021abd2c(h);
            c[0] = i + 0x41;
            for (j = 0; j < i + 1; j++) {
                func_ov000_021abca0(h, c, 1);
            }
            func_ov000_021abca0(h, a->mEntry->mUnk_20, 0x30);
            func_ov000_021abca0(h, a->mKind2Block, 0x20);
            func_ov000_021abca0(h, a->mKind1Block, 0x20);
            func_ov000_021abc4c(h, c + 1);
            h = &a->mScratchHash16;
            func_ov000_021ab7b4(h);
            func_ov000_021ab728(h, a->mEntry->mUnk_20, 0x30);
            func_ov000_021ab728(h, c + 1, 0x14);
            func_ov000_021ab6d4(h, a->mDerivedBytes + o);
            o += 0x10;
            i++;
        } while (o < n);
    }
    if (a->mReceivesKind1Record != 0) {
        a->mReceiveDigestBytes = a->mDerivedBytes;
        a->mReceiveKeyStreamBytes = a->mReceiveDigestBytes + x * 2;
        a->mUnk_1b0 = a->mReceiveKeyStreamBytes + y * 2;
        a->mSendDigestBytes = a->mDerivedBytes + x;
        a->mSendKeyStreamBytes = a->mSendDigestBytes + x + y;
        a->mUnk_098 = a->mSendKeyStreamBytes + y + z;
    } else {
        a->mSendDigestBytes = a->mDerivedBytes;
        a->mSendKeyStreamBytes = a->mSendDigestBytes + x * 2;
        a->mUnk_098 = a->mSendKeyStreamBytes + y * 2;
        a->mReceiveDigestBytes = a->mDerivedBytes + x;
        a->mReceiveKeyStreamBytes = a->mReceiveDigestBytes + x + y;
        a->mUnk_1b0 = a->mReceiveKeyStreamBytes + y + z;
    }
    func_ov000_021ac434(a->mReceiveKeyStreamState, a->mReceiveKeyStreamBytes, 0x10);
    func_ov000_021ac434(a->mSendKeyStreamState, a->mSendKeyStreamBytes, 0x10);
}

// Recovers the entry's 0x30 bytes from b, derives the key bytes and sets mSetupState to 5.
void func_ov000_021aa5b0(HttpsState *a, const u8 *b) {
    func_ov000_021aa880(a->mEntry->mUnk_20, b, a->mUnk_7f0);
    ReplaceEntryBytesWithLabeledDigests(a);
    DeriveBytesAndInitKeyStreamStates(a);
    a->mSetupState = 5;
}

void ComputeLabeledMessageDigest16(HttpsState *a, u8 *b, u32 c) {
    u8 d[0x30];
    Unk021ab728 *e;
    e = &a->mMessageHash16;
    if ((a->mReceivesKind1Record ^ c) != 0) {
        func_ov000_021ab728(e, gSrvrText, 4);
    } else {
        func_ov000_021ab728(e, gClntText, 4);
    }
    func_ov000_021ab728(e, a->mEntry->mUnk_20, 0x30);
    MI_CpuFill8(d, 0x36, 0x30);
    func_ov000_021ab728(e, d, 0x30);
    func_ov000_021ab6d4(e, b);
    func_ov000_021ab7b4(e);
    func_ov000_021ab728(e, a->mEntry->mUnk_20, 0x30);
    MI_CpuFill8(d, 0x5c, 0x30);
    func_ov000_021ab728(e, d, 0x30);
    func_ov000_021ab728(e, b, 0x10);
    func_ov000_021ab6d4(e, b);
}

void ComputeLabeledMessageDigest20(HttpsState *a, u8 *b, u32 c) {
    u8 d[0x28];
    Unk021abca0 *e;
    e = &a->mMessageHash20;
    if ((a->mReceivesKind1Record ^ c) != 0) {
        func_ov000_021abca0(e, gSrvrText, 4);
    } else {
        func_ov000_021abca0(e, gClntText, 4);
    }
    func_ov000_021abca0(e, a->mEntry->mUnk_20, 0x30);
    MI_CpuFill8(d, 0x36, 0x28);
    func_ov000_021abca0(e, d, 0x28);
    func_ov000_021abc4c(e, b);
    func_ov000_021abd2c(e);
    func_ov000_021abca0(e, a->mEntry->mUnk_20, 0x30);
    MI_CpuFill8(d, 0x5c, 0x28);
    func_ov000_021abca0(e, d, 0x28);
    func_ov000_021abca0(e, b, 0x14);
    func_ov000_021abc4c(e, b);
}

void CheckMessageDigestsAndSetState(HttpsState *a, u8 *b) {
    int v1;
    u8 v2[20];
    MI_CpuCopy8(&a->mMessageHash16, &a->mScratchHash16, 0x58);
    ComputeLabeledMessageDigest16(a, v2, 1);
    MI_CpuCopy8(&a->mScratchHash16, &a->mMessageHash16, 0x58);
    v1 = memcmp(b, v2, 0x10);
    if (v1 != 0) {
        a->mSetupState = 9;
        return;
    }
    MI_CpuCopy8(&a->mMessageHash20, &a->mScratchHash20, 0x5c);
    ComputeLabeledMessageDigest20(a, v2, 1);
    MI_CpuCopy8(&a->mScratchHash20, &a->mMessageHash20, 0x5c);
    v1 = memcmp(b + 0x10, v2, 0x14);
    if (v1 != 0) {
        a->mSetupState = 9;
        return;
    }
    a->mSetupState = 6;
}

void IncrementBigEndianBytes(u8 *bytes, s32 count) {
    s32 i;
    bytes += count;
    for (i = 0; i < count; i++) {
        bytes--;
        (*bytes)++;
        if (*bytes != 0) {
            break;
        }
    }
}

u32 XorReceivedBytesWithKeyStream(u32 p0, u8 *bytes, u32 count) {
    u32 v1 = ((count) + (0x0u));
    u32 v2 = 0x1b4u;
    u32 v3 = ((p0) + (v2));
    u32 v5;
    func_ov000_021ac3e4((u8 *) v3, bytes, count);
    v5 = ((v1) + (0x0u));
    return v5;
}

s32 XorReceivedRecordWithKeyStreamAndCheckDigest(HttpsState *a, u8 *b) {
    u8 c[0x14];
    u8 d[0x30];
    s32 e;
    u32 f;
    Unk021ab728 *g;
    Unk021abca0 *h;
    e = XorReceivedBytesWithKeyStream((u32) a, (b + 5), (b[3] << 8) + b[4]);
    switch (a->mCommonValue) {
        case 4:
            e -= 0x10;
            b[3] = e >> 8;
            b[4] = e;
            g = &a->mScratchHash16;
            func_ov000_021ab7b4(g);
            func_ov000_021ab728(g, a->mReceiveDigestBytes, 0x10);
            MI_CpuFill8(d, 0x36, 0x30);
            func_ov000_021ab728(g, d, 0x30);
            func_ov000_021ab728(g, a->mReceiveRecordCount, 8);
            func_ov000_021ab728(g, b, 1);
            func_ov000_021ab728(g, b + 3, 2);
            func_ov000_021ab728(g, b + 5, e);
            func_ov000_021ab6d4(g, c);
            func_ov000_021ab7b4(g);
            func_ov000_021ab728(g, a->mReceiveDigestBytes, 0x10);
            MI_CpuFill8(d, 0x5c, 0x30);
            func_ov000_021ab728(g, d, 0x30);
            func_ov000_021ab728(g, c, 0x10);
            func_ov000_021ab6d4(g, c);
            f = 0x10;
            break;
        case 5:
            e -= 0x14;
            b[3] = e >> 8;
            b[4] = e;
            h = &a->mScratchHash20;
            func_ov000_021abd2c(h);
            func_ov000_021abca0(h, a->mReceiveDigestBytes, 0x14);
            MI_CpuFill8(d, 0x36, 0x28);
            func_ov000_021abca0(h, d, 0x28);
            func_ov000_021abca0(h, a->mReceiveRecordCount, 8);
            func_ov000_021abca0(h, b, 1);
            func_ov000_021abca0(h, b + 3, 2);
            func_ov000_021abca0(h, b + 5, e);
            func_ov000_021abc4c(h, c);
            func_ov000_021abd2c(h);
            func_ov000_021abca0(h, a->mReceiveDigestBytes, 0x14);
            MI_CpuFill8(d, 0x5c, 0x28);
            func_ov000_021abca0(h, d, 0x28);
            func_ov000_021abca0(h, c, 0x14);
            func_ov000_021abc4c(h, c);
            f = 0x14;
            break;
    }
    if (memcmp(b + 5 + e, c, f) != 0) {
        a->mSetupState = 9;
    }
    IncrementBigEndianBytes(a->mReceiveRecordCount, 8);
    return e + 5;
}

s32 AppendDigestAndXorSentRecordWithKeyStream(void *g, u8 *h) {
    HttpsState *a = g;
    u8 *b = h;
    s32 c = (b[3] << 8) + b[4];
    u8 *d = b + 5 + c;
    u8 e[0x30];
    Unk021ab728 *f;
    Unk021abca0 *g2;
    switch (a->mCommonValue) {
        case 4:
            f = &a->mScratchHash16;
            func_ov000_021ab7b4(f);
            func_ov000_021ab728(f, a->mSendDigestBytes, 0x10);
            MI_CpuFill8(e, 0x36, 0x30);
            func_ov000_021ab728(f, e, 0x30);
            func_ov000_021ab728(f, a->mSendRecordCount, 8);
            func_ov000_021ab728(f, b, 1);
            func_ov000_021ab728(f, b + 3, 2);
            func_ov000_021ab728(f, b + 5, c);
            func_ov000_021ab6d4(f, d);
            func_ov000_021ab7b4(f);
            func_ov000_021ab728(f, a->mSendDigestBytes, 0x10);
            MI_CpuFill8(e, 0x5c, 0x30);
            func_ov000_021ab728(f, e, 0x30);
            func_ov000_021ab728(f, d, 0x10);
            func_ov000_021ab6d4(f, d);
            c += 0x10;
            break;
        case 5:
            g2 = &a->mScratchHash20;
            func_ov000_021abd2c(g2);
            func_ov000_021abca0(g2, a->mSendDigestBytes, 0x14);
            MI_CpuFill8(e, 0x36, 0x28);
            func_ov000_021abca0(g2, e, 0x28);
            func_ov000_021abca0(g2, a->mSendRecordCount, 8);
            func_ov000_021abca0(g2, b, 1);
            func_ov000_021abca0(g2, b + 3, 2);
            func_ov000_021abca0(g2, b + 5, c);
            func_ov000_021abc4c(g2, d);
            func_ov000_021abd2c(g2);
            func_ov000_021abca0(g2, a->mSendDigestBytes, 0x14);
            MI_CpuFill8(e, 0x5c, 0x28);
            func_ov000_021abca0(g2, e, 0x28);
            func_ov000_021abca0(g2, d, 0x14);
            func_ov000_021abc4c(g2, d);
            c += 0x14;
            break;
    }
    b[3] = c >> 8;
    b[4] = c;
    func_ov000_021ac3e4(a->mSendKeyStreamState, (b + 5), c);
    IncrementBigEndianBytes(a->mSendRecordCount, 8);
    return c + 5;
}

u32 ReadExactReceivedBytes(u8 *dest, s32 count, Unk021a998c *c) {
    u8 *v1;
    u32 v2;
    do {
        v1 = func_ov000_021adfc8(&v2, c);
        if (v2 == 0) {
            return 0xffffffff;
        }
        if (v2 > count) {
            v2 = count;
        }
        MI_CpuCopy8(v1, dest, v2);
        func_ov000_021adf30(v2, c);
        dest = dest + v2;
        count = count - v2;
    } while (0 < count);
    return 0;
}

// Reads one record, checks and xors it when mSetupState is 7 or 8, runs the handler of its kind and returns
// mSetupState.
u8 ReadHttpsRecordAndSetState(Unk021a998c *a) {
    HttpsState *c = a->mHttpsState;
    u32 n;
    u8 *p;
    u8 *q;
    u8 *r;
    u8 v1;
    u8 v2;
    s32 v3;
    do {
        p = func_ov000_021adfc8(&n, a);
        if (n == 0) {
            c->mSetupState = 9;
            return c->mSetupState;
        }
    } while (n < 5);
    v1 = p[0];
    if (v1 == 0x80) {
        if (c->mReceivesKind1Record != 0 && c->mSetupState == 0) {
            n = p[1];
            func_ov000_021adf30(2, a);
            q = data_ov000_021b63a4(n);
            if (q == NULL) {
                c->mSetupState = 9;
                return c->mSetupState;
            }
            if (ReadExactReceivedBytes(q, n, a) == 0 && q[0] == 1) {
                ParseKind1MessageWithThreeByteValues(c, q + 1);
            } else {
                c->mSetupState = 9;
            }
            func_ov000_021abca0(&c->mMessageHash20, q, n);
            func_ov000_021ab728(&c->mMessageHash16, q, n);
            data_ov000_021b63ac(q);
        } else {
            c->mSetupState = 9;
        }
    } else {
        n = ((p[3] << 8) + p[4]) + 5;
        q = data_ov000_021b63a4(n);
        if (q == NULL) {
            c->mSetupState = 9;
            return c->mSetupState;
        }
        if (ReadExactReceivedBytes(q, n, a) != 0) {
            data_ov000_021b63ac(q);
            c->mSetupState = 9;
            return c->mSetupState;
        }
        if (((u8) (c->mSetupState + 0xf9) <= 1 && v1 != 0x15) || (v1 == 0x15 && n > 7)) {
            n = XorReceivedRecordWithKeyStreamAndCheckDigest(c, q);
        }
        r = q + 5;
        n -= 5;
        switch (v1) {
            case 0x14:
                MI_CpuFill8(c->mReceiveRecordCount, 0, 8);
                c->mSetupState = 7;
                break;
            case 0x15:
                if (r[0] == 2) {
                    c->mSetupState = 9;
                }
                break;
            case 0x16:
                do {
                    v2 = r[0];
                    v3 = r[3] + ((r[1] << 16) + (r[2] << 8));
                    r += 4;
                    switch (v2) {
                        case 1:
                            if (c->mReceivesKind1Record != 0 && c->mSetupState == 0) {
                                ParseKind1Message(c, r);
                            }
                            break;
                        case 0x10:
                            func_ov000_021aa5b0(c, r);
                            break;
                        case 2:
                            ParseKind2Message(c, r);
                            break;
                        case 0xb:
                            ParseAndCheckItemListMessage(c, r);
                            break;
                        case 0xe:
                            c->mSetupState = 4;
                            break;
                        case 0x14:
                            CheckMessageDigestsAndSetState(c, r);
                            break;
                        default:
                            c->mSetupState = 9;
                            break;
                    }
                    func_ov000_021abca0(&c->mMessageHash20, r - 4, v3 + 4);
                    func_ov000_021ab728(&c->mMessageHash16, r - 4, v3 + 4);
                    r += v3;
                    n -= (v3 + 4);
                    if (n == 0) {
                        break;
                    }
                } while (c->mSetupState != 9);
                break;
            case 0x17:
                c->mReceivedBlock = q;
                c->mReceivedBlockOffset = 5;
                c->mReceivedBlockEnd = n + 5;
                return c->mSetupState;
        }
        data_ov000_021b63ac(q);
    }
    return c->mSetupState;
}

// Writes n bytes taken from digests of gRandomByteState, skipping zero bytes.
void FillNonzeroRandomBytes(u8 *out, s32 count) {
    u8 b[0x14];
    u8 d[0x5c];
    u32 c;
    s32 i;
    s32 j;
    s32 k;
    u32 h;
    u8 *e;
    u8 *f;
    u32 g;
    u32 q;
    u64 *l;
    u64 m;
    if (gRandomByteStateMixed == 0) {
        l = data_ov000_021b63e0;
        m = l[1] * l[0] + l[2];
        l[0] = m;
        c = m >> 32;
        MixBytesIntoRandomState(&c, 4);
    }
    i = 0x14;
    j = 0;
    while (j < count) {
        if (i == 0x14) {
            func_ov000_021abd2c((Unk021abca0 *) d);
            g = OS_DisableInterrupts();
            func_ov000_021abca0(d, gRandomByteState, 0x14);
            func_ov000_021abc24((Unk021abca0 *) d, b);
            h = 1;
            k = 0x13;
            e = b + 0x13;
            f = &gRandomByteStateLast;
            for (; k >= 0; k--) {
                q = *f + *e + h;
                *f = q;
                h = q >> 8;
                e--;
                f--;
            }
            c = q;
            OS_RestoreInterrupts(g);
            i = 0;
        }
        if (b[i] != 0) {
            out[j] = b[i];
            j++;
        }
        i++;
    }
}

void MixBytesIntoRandomState(void *bytes, u32 n) {
    u8 b[0x60];
    u32 c;
    func_ov000_021abd2c((Unk021abca0 *) b);
    c = OS_DisableInterrupts();
    func_ov000_021abca0(b, gRandomByteState, 0x14);
    func_ov000_021abca0(b, bytes, n);
    func_ov000_021abc4c((Unk021abca0 *) b, gRandomByteState);
    OS_RestoreInterrupts(c);
    gRandomByteStateMixed = 1;
}

u8 SendKind2Record(Unk021a998c *a) {
    HttpsState *c = a->mHttpsState;
    Unk021a998c_0c_7f4 *d = c->mItemList;
    s32 e;
    u32 f;
    u8 *g;
    u8 *h;
    s32 i;
    if (d != NULL) {
        e = d->mLength;
    } else {
        e = 0;
    }
    f = GetRtcSecondsPlusFixedOffset();
    c->mKind2Block[0] = f >> 24;
    c->mKind2Block[1] = f >> 16;
    c->mKind2Block[2] = f >> 8;
    c->mKind2Block[3] = f;
    FillNonzeroRandomBytes(&c->mKind2Block[4], 0x1c);
    g = data_ov000_021b63a4(e + 0x9d);
    if (g == NULL) {
        c->mSetupState = 9;
        return 1;
    }
    h = g + 5;
    g[5] = 2;
    h[1] = 0;
    h[2] = 0;
    h[3] = 0x46;
    h[4] = 3;
    h[5] = 0;
    MI_CpuCopy8(c->mKind2Block, h + 6, 0x20);
    h[0x26] = 0x20;
    if (c->mEntry != NULL) {
        MI_CpuCopy8(c->mEntry, h + 0x27, 0x20);
        h += 0x47;
        c->mReusedEntry = 1;
    } else {
        FillNonzeroRandomBytes(h + 0x27, 0x1c);
        f = gKind2NewEntryCount;
        h[0x43] = f >> 24;
        h[0x44] = f >> 16;
        h[0x45] = f >> 8;
        h += 0x46;
        *h++ = f;
        c->mEntry = AddEntryOrReplaceLongestUnused(h - 0x20);
        gKind2NewEntryCount = gKind2NewEntryCount + 1;
        c->mReusedEntry = 0;
    }
    h[0] = c->mCommonValue >> 8;
    h[1] = c->mCommonValue;
    h += 2;
    *h++ = 0;
    if (c->mReusedEntry == 0) {
        if (e != 0) {
            h[0] = 0xb;
            i = e + 6;
            h[1] = i >> 16;
            h[2] = i >> 8;
            h[3] = i;
            i = e + 3;
            h[4] = i >> 16;
            h[5] = i >> 8;
            h[6] = i;
            h[7] = e >> 16;
            h[8] = e >> 8;
            h += 9;
            *h++ = e;
            MI_CpuCopy8(d->mBytes, h, e);
            h += e;
        }
        h[0] = 0xe;
        h[1] = 0;
        h[2] = 0;
        h += 3;
        *h++ = 0;
    }
    i = h - g - 5;
    g[0] = 0x16;
    g[1] = 3;
    g[2] = 0;
    g[3] = i >> 8;
    g[4] = i;
    func_ov000_021abca0(&c->mMessageHash20, g + 5, i);
    func_ov000_021ab728(&c->mMessageHash16, g + 5, i);
    func_ov000_021adcec(g, i + 5, NULL, 0, a);
    data_ov000_021b63ac(g);
    return c->mReusedEntry;
}

void SendOneByteRecordAndMessageDigests(Unk021a998c *a) {
    u8 *msg;
    HttpsState *obj;
    obj = a->mHttpsState;
    msg = data_ov000_021b63a4(0x83);
    if (msg == NULL) {
        obj->mSetupState = 9;
        return;
    }
    msg[0] = 0x14;
    msg[1] = 3;
    msg[2] = 0;
    msg[3] = 0;
    msg[4] = 1;
    msg[5] = 1;
    MI_CpuFill8(obj->mSendRecordCount, 0, 8);
    msg[6] = 0x16;
    msg[7] = 3;
    msg[8] = 0;
    msg[9] = 0;
    msg[10] = 0x28;
    msg[11] = 0x14;
    msg[12] = 0;
    msg[13] = 0;
    msg[14] = 0x24;
    MI_CpuCopy8(&obj->mMessageHash16, &obj->mScratchHash16, 0x58);
    ComputeLabeledMessageDigest16(obj, msg + 0xf, 0);
    MI_CpuCopy8(&obj->mScratchHash16, &obj->mMessageHash16, 0x58);
    MI_CpuCopy8(&obj->mMessageHash20, &obj->mScratchHash20, 0x5c);
    ComputeLabeledMessageDigest20(obj, msg + 0x1f, 0);
    MI_CpuCopy8(&obj->mScratchHash20, &obj->mMessageHash20, 0x5c);
    func_ov000_021abca0(&obj->mMessageHash20, msg + 0xb, 0x28);
    func_ov000_021ab728(&obj->mMessageHash16, msg + 0xb, 0x28);
    func_ov000_021adcec(msg, AppendDigestAndXorSentRecordWithKeyStream(obj, msg + 6) + 6, NULL, 0, a);
    data_ov000_021b63ac(msg);
}

void SendKind1Record(Unk021a998c *a) {
    HttpsState *c = a->mHttpsState;
    u8 *b;
    u8 *d;
    u8 *e;
    u32 f;
    s32 g;
    u32 i;
    u16 *h;
    b = data_ov000_021b63a4(0x98);
    if (b == NULL) {
        c->mSetupState = 9;
        return;
    }
    d = b + 9;
    b[9] = 3;
    d[1] = 0;
    f = GetRtcSecondsPlusFixedOffset();
    c->mKind1Block[0] = f >> 24;
    c->mKind1Block[1] = f >> 16;
    c->mKind1Block[2] = f >> 8;
    c->mKind1Block[3] = f;
    FillNonzeroRandomBytes(&c->mKind1Block[4], 0x1c);
    MI_CpuCopy8(c->mKind1Block, d + 2, 0x20);
    c->mEntry = FindEntryByValuePairAndSetLastUseTime(a->mUnk_1c, a->mUnk_18);
    if (c->mEntry != NULL) {
        d[0x22] = 0x20;
        MI_CpuCopy8(c->mEntry, d + 0x23, 0x20);
        d += 0x43;
    } else {
        e = d + 0x22;
        d += 0x23;
        *e = 0;
    }
    i = 0;
    *d = 0;
    e = d + 1;
    d += 2;
    *e = 4;
    h = gOfferedValues;
    for (; i < 2; i++) {
        *d = *h >> 8;
        e = d + 1;
        d += 2;
        *e = *h;
        h++;
    }
    *d = 1;
    d[1] = 0;
    e = d + 2;
    g = e - b - 5;
    b[0] = 0x16;
    b[1] = 3;
    b[2] = 0;
    b[3] = g >> 8;
    b[4] = g;
    b[5] = 1;
    b[6] = (g - 4) >> 16;
    b[7] = (g - 4) >> 8;
    b[8] = g - 4;
    func_ov000_021adcec(b, g + 5, NULL, 0, a);
    func_ov000_021ab728(&c->mMessageHash16, b + 5, g);
    func_ov000_021abca0(&c->mMessageHash20, b + 5, g);
    data_ov000_021b63ac(b);
}

// Fills mEntry's 0x30 bytes (3, 0, then random bytes), pads them with random bytes, transforms them with mFirstValue
// and mSecondValue and sends the result.
void func_ov000_021a9640(Unk021a998c *a) {
    HttpsState *c = a->mHttpsState;
    s32 b;
    s32 d;
    u16 *f;
    u16 *g;
    u16 *h;
    u16 *i;
    u8 *e;
    u8 *j;
    s32 m;
    u8 *p;
    u8 *k;
    c->mEntry->mUnk_20[0] = 3;
    c->mEntry->mUnk_20[1] = 0;
    FillNonzeroRandomBytes(&c->mEntry->mUnk_20[2], 0x2e);
    b = c->mFirstValueLength;
    d = (b * 2) / 2;
    e = data_ov000_021b63a4(b);
    if (e == NULL) {
        c->mSetupState = 9;
        return;
    }
    e[0] = 0;
    e[1] = 2;
    FillNonzeroRandomBytes(e + 2, b - 0x33);
    e[b - 0x31] = 0;
    MI_CpuCopy8(c->mEntry->mUnk_20, e + b - 0x30, 0x30);
    f = (u16 *) data_ov000_021b63a4(d * 8);
    if (f == NULL) {
        data_ov000_021b63ac(e);
        c->mSetupState = 9;
        return;
    }
    g = f + d;
    h = g + d;
    i = h + d;
    func_ov000_021ac4b8(g, e, b, d);
    func_ov000_021ac4b8(h, c->mSecondValue, c->mSecondValueLength, d);
    func_ov000_021ac4b8(i, c->mFirstValue, b, d);
    if (data_ov000_021b49f4 < 0x20) {
        OSThread *n = data_0216ff5c.mCurrentThread;
        u32 o = OS_GetThreadPriority(n);
        OS_SetThreadPriority(n, data_ov000_021b49f4);
        func_ov000_021ac7e8(f, g, h, d, i);
        OS_SetThreadPriority(n, o);
    } else {
        func_ov000_021ac7e8(f, g, h, d, i);
    }
    j = data_ov000_021b63a4(b + 0x49);
    if (j == NULL) {
        data_ov000_021b63ac(e);
        data_ov000_021b63ac(f);
        c->mSetupState = 9;
        return;
    }
    j[0] = 0x16;
    j[1] = 3;
    j[2] = 0;
    j[3] = (b + 4) >> 8;
    j[4] = b + 4;
    j[5] = 0x10;
    j[6] = b >> 16;
    j[7] = b >> 8;
    p = j + 9;
    j[8] = b;
    if (b & 1) {
        *p = f[b / 2];
        p += 1;
    }
    for (m = b / 2 - 1; m >= 0; m--) {
        *p = f[m] >> 8;
        k = p + 1;
        p += 2;
        *k = f[m];
    }
    func_ov000_021adcec(j, b + 9, NULL, 0, a);
    func_ov000_021ab728(&c->mMessageHash16, j + 5, (u32) b + 4);
    func_ov000_021abca0(&c->mMessageHash20, j + 5, b + 4);
    data_ov000_021b63ac(j);
    data_ov000_021b63ac(f);
    data_ov000_021b63ac(e);
}

u32 ReadRecordsExpectingStates7And6(Unk021a998c *a) {
    int v1;
    v1 = ReadHttpsRecordAndSetState(a);
    if (v1 != 7) {
        return 1;
    }
    v1 = ReadHttpsRecordAndSetState(a);
    if (v1 != 6) {
        return 1;
    }
    return 0;
}

BOOL RunSetupAfterReadingKind1Record(Unk021a998c *a) {
    if (ReadHttpsRecordAndSetState(a) != 1) {
        return TRUE;
    }
    if (SendKind2Record(a) != 0) {
        DeriveBytesAndInitKeyStreamStates(a->mHttpsState);
        SendOneByteRecordAndMessageDigests(a);
        if (ReadRecordsExpectingStates7And6(a) != 0) {
            return TRUE;
        }
    } else {
        if (ReadHttpsRecordAndSetState(a) != 5) {
            return TRUE;
        }
        if (ReadRecordsExpectingStates7And6(a) != 0) {
            return TRUE;
        }
        SendOneByteRecordAndMessageDigests(a);
    }
    return FALSE;
}

void RunSetupAfterReadingKind1RecordUntilDone(Unk021a998c *a) {
    HttpsState *c = a->mHttpsState;
    while (1) {
        func_ov000_021ae228(a);
        c->mSetupState = 0;
        c->mReceivesKind1Record = 1;
        func_ov000_021abd2c(&c->mMessageHash20);
        func_ov000_021ab7b4(&c->mMessageHash16);
        if (RunSetupAfterReadingKind1Record(a) == 0) {
            c->mSetupState = 8;
            return;
        }
        func_ov000_021ae0c4(a);
        a->mUnk_18 = a->mUnk_1a;
        a->mUnk_1c = a->mUnk_20;
    }
}

BOOL RunSetupAfterSendingKind1Record(Unk021a998c *a) {
    HttpsState *c = a->mHttpsState;
    u8 b;
    SendKind1Record(a);
    while (1) {
        b = ReadHttpsRecordAndSetState(a);
        if (b == 9) {
            return TRUE;
        }
        if (b == 4 || c->mReusedEntry != 0) {
            break;
        }
    }
    if (c->mReusedEntry != 0) {
        DeriveBytesAndInitKeyStreamStates(c);
        if (ReadRecordsExpectingStates7And6(a) != 0) {
            return TRUE;
        }
        SendOneByteRecordAndMessageDigests(a);
    } else {
        c->mEntry->mUnk_54 = a->mUnk_1c;
        c->mEntry->mUnk_58 = a->mUnk_18;
        func_ov000_021a9640(a);
        ReplaceEntryBytesWithLabeledDigests(c);
        DeriveBytesAndInitKeyStreamStates(c);
        SendOneByteRecordAndMessageDigests(a);
        if (ReadRecordsExpectingStates7And6(a) != 0) {
            return TRUE;
        }
    }
    c->mSetupState = 8;
    return FALSE;
}

BOOL func_ov000_021a943c(Unk021a998c *a) {
    HttpsState *c = a->mHttpsState;
    if (a->mState != 4 && func_ov000_021ae16c(a) != 0) {
        return TRUE;
    }
    c->mSetupState = 0;
    c->mReceivesKind1Record = 0;
    func_ov000_021abd2c(&c->mMessageHash20);
    func_ov000_021ab7b4(&c->mMessageHash16);
    return RunSetupAfterSendingKind1Record(a);
}

u8 *ReadHttpsRecordsUntilBytesReceived(s32 *unreadCount, Unk021a998c *b) {
    HttpsState *c = b->mHttpsState;
    while (c->mReceivedBlock == NULL) {
        if (ReadHttpsRecordAndSetState(b) == 9) {
            *unreadCount = 0;
            return NULL;
        }
    }
    *unreadCount = c->mReceivedBlockEnd - c->mReceivedBlockOffset;
    return c->mReceivedBlock + c->mReceivedBlockOffset;
}

void SkipHttpsReceivedBytes(u32 count, Unk021a998c *b) {
    HttpsState *c = b->mHttpsState;
    if (count >= c->mReceivedBlockEnd - c->mReceivedBlockOffset) {
        data_ov000_021b63ac(c->mReceivedBlock);
        c->mReceivedBlock = NULL;
        c->mReceivedBlockOffset = c->mReceivedBlockEnd;
    } else {
        c->mReceivedBlockOffset += count;
    }
}

s32 ReadHttpsRecordIfBufferedAndGetUnreadByteCount(Unk021a998c *a) {
    HttpsState *c = a->mHttpsState;
    if (c->mReceivedBlock == NULL) {
        if (a->mReceiveBufferLength == 0) {
            return 0;
        }
        ReadHttpsRecordAndSetState(a);
    }
    return c->mReceivedBlockEnd - c->mReceivedBlockOffset;
}

s32 SendHttpsBytesInChunks(u8 *a, u32 b, u8 *c, u32 d, Unk021a998c *e) {
    HttpsState *f = e->mHttpsState;
    s32 g = b + d;
    u8 *l;
    s32 i;
    u32 j;
    u32 k;
    s32 h = 0;
    u8 m = 0;
    s32 n = 0;
    BOOL p = FALSE;
    while (1) {
        if (g > 0xb4f) {
            i = 0xb4f;
        } else {
            i = g;
        }
        l = data_ov000_021b63a4(i + 0x19);
        if (l == NULL) {
            break;
        }
        if (b >= i) {
            j = i;
        } else {
            j = b;
        }
        k = i - j;
        MI_CpuCopy8(a, l + 5, j);
        a += j;
        b -= j;
        MI_CpuCopy8(c, l + 5 + j, k);
        c += k;
        l[0] = 0x17;
        l[1] = 3;
        l[2] = m;
        l[3] = i >> 8;
        l[4] = i;
        j = AppendDigestAndXorSentRecordWithKeyStream(f, l);
        if (func_ov000_021adcec(l, j, (const u8 *) n, n, e) < j) {
            i = p;
        }
        data_ov000_021b63ac(l);
        g -= i;
        h += i;
        if (g == 0) {
            break;
        }
        if (i == 0) {
            break;
        }
    }
    return h;
}

// When mSetupState is 8 sends the 7-byte record that ends with 1, 0, then runs func_ov000_021ae0c4 and clears
// mSetupState.
void func_ov000_021a9228(Unk021a998c *a) {
    HttpsState *c = a->mHttpsState;
    u8 b[0x20];
    if (c->mSetupState == 8) {
        b[0] = 0x15;
        b[1] = 3;
        b[2] = 0;
        b[3] = 0;
        b[4] = 2;
        b[5] = 1;
        b[6] = 0;
        func_ov000_021adcec(b, AppendDigestAndXorSentRecordWithKeyStream(c, b), NULL, 0, a);
    }
    func_ov000_021ae0c4(a);
    c->mSetupState = 0;
}

#include "03/code_021b7bb4.h"
#include "03/code_021b7000.h"
#include "03/unk_021d8000.h"
#include "Main/Unknown/code_02133000.h"

#include "code_02133048.h"
#include "code_0214d018.h"
#include "code_0214d93c.h"
#include "00/code_021ad734.h"
#include "03/code_021b94b8.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b6000.h"
#include "03/unk_021d7000.h"
#include "00/code_021a6d5c.h"

s32 func_ov003_021b94ac(void) {
    u32 value0;
    value0 = (u32) &data_ov003_021d7c50;
    value0 = *(const u32 *) ((value0) + 0u);
    return value0;
}

s32 CheckAndCopyValueRecordsToRequest(Unk021b94c4 *a) {
    u8 *p = (u8 *) a + 0x117;
    ParsedRecordView *b = &gParsedFourValueRecord0;
    ParsedRecordView *c = &gParsedFourValueRecord1;
    ParsedRecordView *d = &gParsedSingleValueRecord0;
    ParsedRecordView *e = &gParsedSingleValueRecord1;
    if (p == NULL) {
        return -1;
    }
    a->mUnk_000 = data_ov003_021d7c6c.mUnk_08 & data_ov003_021d7c6c.mUnk_0c;
    FillBytes(p, 0, 0x154);
    if (a->mUnk_000 & 1) {
        CopyBytes(p, b->mValue0, b->mValueLength);
        CopyBytes(p + 6, b->mValue1, b->mValueLength);
        CopyBytes(p + 0xc, b->mValue2, b->mValueLength);
        CopyBytes(p + 0x12, b->mValue3, b->mValueLength);
        if (CheckBytesInRange0x20To0x7f(b->mString, GetStringLength(b->mString)) != 0) {
            goto fail;
        }
        CopyBytes(p + 0x18, b->mString, GetStringLength(b->mString));
    }
    if (a->mUnk_000 & 2) {
        CopyBytes(p + 0x39, c->mValue0, c->mValueLength);
        CopyBytes(p + 0x47, c->mValue1, c->mValueLength);
        CopyBytes(p + 0x55, c->mValue2, c->mValueLength);
        CopyBytes(p + 0x63, c->mValue3, c->mValueLength);
        if (CheckBytesInRange0x20To0x7f(c->mString, GetStringLength(c->mString)) != 0) {
            goto fail;
        }
        CopyBytes(p + 0x71, c->mString, GetStringLength(c->mString));
    }
    if (a->mUnk_000 & 4) {
        if (CheckBytesInRange0x20To0x7f(d->mValue0, d->mValueLength - 1) != 0) {
            goto fail;
        }
        CopyBytes(p + 0x92, d->mValue0, d->mValueLength);
        if (CheckBytesInRange0x20To0x7f(d->mString, GetStringLength(d->mString)) != 0) {
            goto fail;
        }
        CopyBytes(p + 0xd2, d->mString, GetStringLength(d->mString));
    }
    if (a->mUnk_000 & 8) {
        if (CheckBytesInRange0x20To0x7f(e->mValue0, e->mValueLength - 1) != 0) {
            goto fail;
        }
        CopyBytes(p + 0xf3, e->mValue0, e->mValueLength);
        if (CheckBytesInRange0x20To0x7f(e->mString, GetStringLength(e->mString)) != 0) {
            goto fail;
        }
        CopyBytes(p + 0x133, e->mString, GetStringLength(e->mString));
    }
    a->mUnk_116 = 0;
    return 0;
fail:
    FillBytes(p, 0, 0x154);
    return -1;
}

s32 CheckBytesInRange0x20To0x7f(const u8 *bytes, s32 count) {
    s32 i;
    for (i = 0; i < count; i++) {
        u32 value = *bytes++;
        if (value < 0x20 || value > 0x7f) {
            return -1;
        }
    }
    return 0;
}

typedef struct PacketHeaderPrefix {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 pad_02[4];
    /* 06 */ u16 mKind;
    /* 08 */ u8 pad_08[7];
    /* 0f */ u8 mUnk_0f;
} PacketHeaderPrefix;

// Returns 0 when exactly one entry with bit 0 of mUnk_50 holds the gEssidAossString bytes, 4 for several, 5 for none.
s32 CheckSingleEssidAossEntry(EssidEntryList *a) {
    s32 m;
    s32 r;
    s32 i;
    s32 n;
    r = 0;
    n = 0;
    m = a->mUnk_00;
    if (m == 0) {
        return 5;
    }
    if ((u32) m > 0x40) {
        m = 0x40;
    }
    for (i = 0; i < m; i++) {
        if (a->mUnk_04[i].mUnk_50 & 1) {
            if (a->mUnk_04[i].mUnk_00 == GetStringLength(gEssidAossString)) {
                if (CompareBytes(a->mUnk_04[i].mUnk_04, gEssidAossString, GetStringLength(gEssidAossString)) == 0) {
                    n++;
                }
            }
        }
    }
    if (n > 1) {
        r = 4;
    }
    if (n == 0) {
        r = 5;
    }
    return r;
}

s32 FillEssidAossAndMelcoRequest(EssidMelcoRequest *a) {
    a->mUnk_00 = GetStringLength(gEssidAossString);
    CopyBytes(a->mUnk_04, gEssidAossString, a->mUnk_00);
    a->mUnk_24 = TRUE;
    a->mUnk_28 = GetStringLength(gMelcoString);
    if ((u32) a->mUnk_28 > 0xd) {
        return -1;
    }
    CopyBytes(a->mUnk_2c, gMelcoString, a->mUnk_28);
    return 0;
}

void FillPacketTags(s32 a, PacketTag *b, const u8 *c) {
    s32 i;
    for (i = 0; i < a; i++) {
        CopyBytes(b, c, 6);
        b->mUnk_06 = NextRandomValue();
        b->mUnk_06 = func_ov003_021b7c94(b->mUnk_06);
        b++;
    }
}

s32 ReportStateChange(s32 a) {
    BOOL r = FALSE;
    if (a == -1) {
        gReportedState = a;
        return r;
    }
    if (gReportedState != a) {
        gReportedState = a;
        return func_ov003_021ba18c(a);
    }
    return r;
}

s32 AdvanceStepByKind(s32 a, PacketBuffer *b, s32 *c, PacketTag *d, s32 e) {
    PacketHeaderPrefix *p = (PacketHeaderPrefix *) b->mUnk_0c;
    u32 v;
    if (SwapBytes16(p->mUnk_00) < 1) {
        *c = *c + 1;
        return a;
    }
    if (p->mUnk_0f != 0x11) {
        *c = *c + 1;
        return a;
    }
    if (CheckPacketAndXorPayload((Packet *) b->mUnk_0c) > 0) {
        *c = *c + 1;
        return a;
    }
    v = SwapBytes16(p->mKind);
    switch (v) {
        case 0x1010:
            a = AdvanceStepForKind1010(a, b, c, d);
            break;
        case 0x2010:
            a = AdvanceStepForKind2010(a, b, c, d);
            break;
        case 0x3010:
            a = AdvanceStepForKind3010(a, b, c, d);
            break;
    }
    return a;
}

s32 AdvanceStepForKind1010(s32 v1, PacketBuffer *v2, s32 *v3, PacketTag *v4) {
    Packet *a;
    Unk021b7cec *b;
    u32 *p;
    s32 c;
    if (v1 != 0) {
        (*v3)++;
        return v1;
    }
    a = (Packet *) v2->mUnk_0c;
    b = (Unk021b7cec *) &v2->mUnk_0c[0x18];
    c = XorSwapAndCheckTag(&v4[0], &a->mTag);
    if (c < 0) {
        (*v3)++;
        return v1;
    }
    if (SwapBytes16(b->mUnk_02) == 0) {
        (*v3)++;
        return v1;
    }
    if (b->mUnk_00 == 7) {
        p = &b->mUnk_04;
        if (func_ov003_021b7c5c(b->mUnk_04) == -2) {
            func_ov003_021b94b8(0x14);
        } else if (func_ov003_021b7c5c(*p) == -3) {
            func_ov003_021b94b8(0x15);
        } else {
            func_ov003_021b94b8(0x18);
        }
        return -1;
    }
    if (b->mUnk_00 != 1) {
        (*v3)++;
        return v1;
    }
    c = ParseItemChain((PacketItem *) &b->mUnk_04, gItemSlots);
    if (c < 0) {
        if (c == -2) {
            func_ov003_021b94b8(0x16);
            return -1;
        }
        (*v3)++;
        return v1;
    }
    gFlagBit4OfKind1010Packet = IsBit4Set(SwapBytes16(a->mFlags));
    *v3 = 0;
    return 1;
}

s32 AdvanceStepForKind2010(s32 v1, PacketBuffer *v2, s32 *v3, PacketTag *v4) {
    Packet *a;
    Unk021b7cec *b;
    s32 c;
    if (v1 != 1) {
        (*v3)++;
        return v1;
    }
    a = (Packet *) v2->mUnk_0c;
    b = (Unk021b7cec *) &v2->mUnk_0c[0x18];
    c = XorSwapAndCheckTag(&v4[1], &a->mTag);
    if (c < 0) {
        (*v3)++;
        return v1;
    }
    if (SwapBytes16(b->mUnk_02) == 0) {
        (*v3)++;
        return v1;
    }
    if (b->mUnk_00 == 7) {
        if (func_ov003_021b7c5c(b->mUnk_04) == -2) {
            func_ov003_021b94b8(0x14);
        } else if (func_ov003_021b7c5c(b->mUnk_04) == -3) {
            func_ov003_021b94b8(0x15);
        } else {
            func_ov003_021b94b8(0x18);
        }
        return -1;
    }
    FillBytes(gParsedItems, 0, 0x6a0);
    c = FindItemAndParseSubItems(0, (PacketItem *) b, SwapBytes16(a->mPayloadLength), gParsedItems, gItemSlots);
    if (c < 0) {
        (*v3)++;
        return v1;
    }
    if ((data_ov003_021d7c6c.mUnk_0c & data_ov003_021d7c6c.mUnk_08) == 0) {
        return v1;
    }
    *v3 = 0;
    return 2;
}

s32 AdvanceStepForKind3010(s32 v1, PacketBuffer *v2, s32 *v3, PacketTag *v4) {
    Packet *a;
    Unk021b7cec *b;
    s32 c;
    if (v1 != 2) {
        (*v3)++;
        return v1;
    }
    a = (Packet *) v2->mUnk_0c;
    b = (Unk021b7cec *) &v2->mUnk_0c[0x18];
    c = XorSwapAndCheckTag(&v4[2], &a->mTag);
    if (c < 0) {
        (*v3)++;
        return v1;
    }
    if (b->mUnk_00 != 7) {
        (*v3)++;
        return v1;
    }
    if (SwapBytes16(b->mUnk_02) == 0) {
        (*v3)++;
        return v1;
    }
    if (func_ov003_021b7c5c(b->mUnk_04) == 0) {
        return 0x64;
    }
    if (func_ov003_021b7c5c(b->mUnk_04) == -2) {
        func_ov003_021b94b8(0x14);
        return -1;
    }
    if (func_ov003_021b7c5c(b->mUnk_04) == -3) {
        func_ov003_021b94b8(0x15);
        return -1;
    }
    func_ov003_021b94b8(0x18);
    return -1;
}

// Checks the tag against the saved bytes; when mFlags & 0xf is set, xors the payload back in place.
s32 CheckPacketAndXorPayload(Packet *a) {
    PayloadRecord *payload;
    u8 tag[8];
    s32 d;
    u32 length;
    u8 *copy;
    payload = (PayloadRecord *) a->mPayload;
    CopyBytes(tag, &a->mTag, 8);
    d = XorAndSwapBytesWithKey(tag, 8, gMelcoString, GetStringLength(gMelcoString));
    if (d == -1) {
        func_ov003_021b94b8(2);
        return -100;
    }
    d = CheckTagAgainstSavedBytesOrKind1000(SwapBytes16(a->mKind), tag);
    if (d != 0) {
        return d;
    }
    if (SwapBytes16(a->mKind) == 0x1000) {
        CopyBytes(data_ov003_021d7c58, tag, 8);
    }
    if ((SwapBytes16(a->mFlags) & 0xf) == 0) {
        return 0;
    }
    length = SwapBytes16(payload->mLength);
    copy = func_ov003_021ba178(length);
    if (copy == NULL) {
        func_ov003_021b94b8(2);
        return 100;
    }
    if (XorBytesWithKeyStreamAndCheckCrc(payload->mBytes, copy, length, a->mPayloadCrc, payload->mKeyPrefix,
                                         data_ov003_021d7c58, 8) < 0) {
        func_ov003_021ba164(copy);
        if (func_ov003_021b94ac() == 2) {
            return 100;
        }
        return 200;
    }
    CopyBytes(payload, copy, length);
    a->mPayloadLength = func_ov003_021b7c94(length);
    func_ov003_021ba164(copy);
    return 0;
}

s32 CheckTagAgainstSavedBytesOrKind1000(s32 a, const u8 *b) {
    s32 c;
    s32 i;
    BOOL found;
    u8 *cursor;
    c = 0;
    found = FALSE;
    i = 0;
    cursor = data_ov003_021d7c58;
    do {
        if (*cursor != 0) {
            found = TRUE;
            break;
        }
        cursor++;
        i++;
    } while (i < 6);
    if (found != FALSE) {
        if (CompareBytes(data_ov003_021d7c58, b, 6) != 0) {
            c = 1;
        }
    } else if (a != 0x1000) {
        c = 2;
    }
    return c;
}

s32 XorSwapAndCheckTag(PacketTag *a, PacketTag *b) {
    s32 c;
    c = 0;
    XorAndSwapBytesWithKey(b->mUnk_00, 8, gMelcoString, GetStringLength(gMelcoString));
    if (CompareBytes(a->mUnk_00, b->mUnk_00, 6) != 0) {
        c = -1;
    } else if (SwapBytes16(a->mUnk_06) + 1 != SwapBytes16(b->mUnk_06)) {
        c = -2;
    }
    return c;
}

s32 ParseItemChain(PacketItem *a, u8 *b) {
    PacketItem *c;
    s32 d;
    s32 e;
    FillBytes(b, 0, 0x104);
    c = a;
    while (1) {
        d = SwapBytes16(c->mLength);
        if (d <= 0) {
            return -1;
        }
        switch (c->mType) {
            case 0:
                CopyBytes(b, c->mValue, d);
                break;
            case 1:
                CopyBytes(b + 0x80, c->mValue, d);
                break;
            case 2:
                CopyBytes(b + 0x100, c->mValue, d);
                break;
            case 3:
            case 4:
                e = SwapBytes16(c->mValue[0]);
                if (e <= 0) {
                    return -2;
                }
                break;
            case 5:
                data_ov003_021d7c6c.mUnk_10 = func_ov003_021b7c5c(ReadLittleEndianValue(c->mValue, d));
                break;
            case 6:
                data_ov003_021d7c6c.mUnk_14 = func_ov003_021b7c5c(ReadLittleEndianValue(c->mValue, d));
                break;
            default:
                return -1;
        }
        if (c->mNextOffset != 0) {
            c = OFFSET_PTR(PacketItem, a, SwapBytes16(c->mNextOffset));
            continue;
        }
        return 0;
    }
}

u32 ReadLittleEndianValue(const u8 *bytes, s32 count) {
    u32 value = 0;
    s32 i;
    const u8 *cursor = bytes + (count - 1);
    for (i = 0; i < count; i++) {
        value = (value << 8) + *cursor--;
    }
    return value;
}

s32 ParseFourValueItems(PacketItem *a, FourValueRecord *b) {
    PacketItem *c = OFFSET_PTR(PacketItem, a, 6);
    u32 d;
    while (1) {
        d = SwapBytes16(c->mLength);
        switch (c->mType) {
            case 0x10:
            case 0x11:
            case 0x12:
            case 0x13:
                if (d > 5) {
                    return -1;
                }
                break;
            case 0x20:
            case 0x21:
            case 0x22:
            case 0x23:
                if (d > 0xd) {
                    return -1;
                }
                break;
            case 0x15:
            case 0x25:
                if (d > 0x21) {
                    return -1;
                }
                break;
        }
        switch (c->mType) {
            case 0x10:
            case 0x20:
                CopyBytes(b->mValue0, c->mValue, d);
                b->mValueLength = d;
                break;
            case 0x11:
            case 0x21:
                CopyBytes(b->mValue1, c->mValue, d);
                b->mValueLength = d;
                break;
            case 0x12:
            case 0x22:
                CopyBytes(b->mValue2, c->mValue, d);
                b->mValueLength = d;
                break;
            case 0x13:
            case 0x23:
                CopyBytes(b->mValue3, c->mValue, d);
                b->mValueLength = d;
                break;
            case 0x15:
            case 0x25:
                if (d != 0 && c->mValue[d - 1] != 0) {
                    return -1;
                }
                CopyBytes(b->mString, c->mValue, d);
                break;
            default:
                return -1;
        }
        if (c->mNextOffset != 0) {
            c = (PacketItem *) ((u8 *) a + 6 + SwapBytes16(c->mNextOffset));
            continue;
        }
        return 0;
    }
}

s32 ParseSingleValueItems(PacketItem *a, SingleValueRecord *b) {
    PacketItem *c = OFFSET_PTR(PacketItem, a, 6);
    u32 d;
    while (1) {
        d = SwapBytes16(c->mLength);
        switch (c->mType) {
            case 0x30:
            case 0x40:
                if (d > 0x40) {
                    return -1;
                }
                break;
            case 0x35:
            case 0x45:
                if (d > 0x21) {
                    return -1;
                }
                break;
        }
        switch (c->mType) {
            case 0x30:
            case 0x40:
                CopyBytes(b->mValue, c->mValue, d);
                b->mValueLength = d;
                break;
            case 0x35:
            case 0x45:
                if (d != 0 && c->mValue[d - 1] != 0) {
                    return -1;
                }
                CopyBytes(b->mString, c->mValue, d);
                break;
            default:
                return -1;
        }
        if (c->mNextOffset != 0) {
            c = (PacketItem *) ((u8 *) a + 6 + SwapBytes16(c->mNextOffset));
            continue;
        }
        return 0;
    }
}

s32 CopyFirstItemValueIfType0x70(PacketItem *a, u8 *b) {
    PacketItem *c = OFFSET_PTR(PacketItem, a, 6);
    s32 d;
    d = SwapBytes16(c->mLength);
    if (d <= 0) {
        return -1;
    }
    if (c->mType != 0x70) {
        return -1;
    }
    CopyBytes(b, c->mValue, d);
    return 0;
}

// Skips to the top-level item of type gItemTypesToFind[a], then stores its sub-items by type.
s32 FindItemAndParseSubItems(s32 a, PacketItem *b, s32 c, ParsedItems *d, u8 *e) {
    u32 f;
    s32 g;
    u32 h;
    u8 *i;
    ParsedItems *j;
    u8 *k;
    s32 l;
    PacketItem *m;
    f = 0;
    if (c <= 0) {
        return -2;
    }
    i = gItemTypesToFind + a;
    for (;;) {
        m = b;
        if (b->mType == *i) {
            break;
        }
        g = SwapBytes16(b->mLength) + 4;
        b = OFFSET_PTR(PacketItem, b, g);
        c -= g;
        if (c <= 0) {
            return -4;
        }
    }
    b = OFFSET_PTR(PacketItem, b, 4);
    h = SwapBytes16(m->mLength);
    j = d + a;
    k = e + (a + 3) * 0x80;
    l = -3;
    do {
        switch (b->mType) {
            case 3:
                l = ParseFourValueItems(b, &j->mFourValueRecord0);
                f |= 1;
                break;
            case 4:
                l = ParseFourValueItems(b, &j->mFourValueRecord1);
                f |= 2;
                break;
            case 5:
                l = ParseSingleValueItems(b, &j->mSingleValueRecord0);
                f |= 4;
                break;
            case 6:
                l = ParseSingleValueItems(b, &j->mSingleValueRecord1);
                f |= 8;
                break;
            case 10:
                l = CopyFirstItemValueIfType0x70(b, k);
                break;
            default:
                l = -3;
                break;
        }
        if (l != 0) {
            return l;
        }
        g = SwapBytes16(b->mLength) + 4;
        b = OFFSET_PTR(PacketItem, b, g);
        h -= g;
    } while ((s32) h > 0);
    data_ov003_021d7c6c.mUnk_0c |= f;
    return 0;
}

s32 IsBit4Set(u32 value) {
    BOOL result = FALSE;
    if (value & 0x10) {
        result = TRUE;
    }
    return result;
}

// Reports state 2, 3 or 5 and sends the packet of kind 0x1000, 0x2000 or 0x3000 for mode 0, 1 or 2.
s32 ReportStateAndSendPacketForMode(s32 v1, Unk021b86e4 *v2, PacketTag *v3, s32 v4) {
    switch (v1) {
        case 0:
            ReportStateChange(2);
            return SendPacketKind1000(v2, v3, v4);
        case 1:
            ReportStateChange(3);
            return SendPacketKind2000(v2, v3, v4);
        case 2:
            ReportStateChange(5);
            return SendPacketKind3000(v2, v3, v4);
    }
    return -1;
}

s32 SendPacketKind1000(Unk021b86e4 *a, PacketTag *b, s32 c) {
    PacketFieldValues d;
    PacketBuffer *e;
    ItemContainer *f;
    u8 *g;
    d.mPayloadCrc = 0;
    d.mPayloadLength = 0;
    d.mFlags = 0;
    e = data_ov003_021d7c54;
    FillBytes(e, 0, 0x5dc);
    f = func_ov003_021ba178(0x210);
    if (f == NULL) {
        func_ov003_021b94b8(2);
        return -1;
    }
    FillBytes(f, 0, 0x210);
    g = &e->mUnk_0c[12];
    CopyBytes(data_ov003_021d7c58, b, 8);
    CopyBytes(d.mTag, data_ov003_021d7c58, 8);
    d.mPayloadLength = BuildTwoItemChain(f->mItems);
    if (d.mPayloadLength < 0) {
        func_ov003_021b94b8(3);
        if (f != NULL) {
            func_ov003_021ba164(f);
        }
        return -1;
    }
    f->mUnk_00 = 0;
    f->mLength = func_ov003_021b7c94(d.mPayloadLength);
    d.mPayloadLength += 4;
    FillPayloadRecord(0, g, f, &d.mPayloadLength, &d.mFlags, &d.mPayloadCrc);
    d.mFlags |= 0x10;
    if (XorAndSwapBytesWithKey(d.mTag, 8, gMelcoString, 6) != 0) {
        func_ov003_021b94b8(2);
        if (f != NULL) {
            func_ov003_021ba164(f);
        }
        return -1;
    }
    FillPacketHeader(e, 0x1000, d.mPayloadLength, d.mFlags, d.mPayloadCrc, 0x11, d.mTag);
    d.mPayloadLength += 0x18;
    SendPacket(e, d.mPayloadLength, 0xff, c);
    if (f != NULL) {
        func_ov003_021ba164(f);
    }
    return 0;
}

s32 SendPacketKind2000(Unk021b86e4 *a, PacketTag *b, s32 c) {
    s8 d;
    s16 g;
    s16 h;
    u8 k[8];
    Unk021b7cec e;
    PacketBuffer *f;
    d = 0;
    g = 0;
    h = 0;
    f = data_ov003_021d7c54;
    FillBytes(&e, 0, 8);
    FillBytes(f, 0, 0x5dc);
    e.mUnk_00 = 2;
    e.mUnk_01 = 0;
    e.mUnk_02 = func_ov003_021b7c94(4);
    e.mUnk_04 = data_ov003_021d7c6c.mUnk_08;
    e.mUnk_04 = SwapBytes32(e.mUnk_04);
    g = 8;
    FillPayloadRecord(gFlagBit4OfKind1010Packet, &f->mUnk_0c[12], &e, &g, &h, &d);
    CopyBytes(k, &b[1], 8);
    if (XorAndSwapBytesWithKey(k, 8, gMelcoString, 6) != 0) {
        func_ov003_021b94b8(2);
        return -1;
    }
    FillPacketHeader(f, 0x2000, g, h, d, 0x11, k);
    g += 0x18;
    SendPacket(f, g, 0, c);
    return 0;
}

s32 SendPacketKind3000(Unk021b86e4 *a, PacketTag *b, s32 c) {
    PacketBuffer *d;
    u8 e[8];
    d = data_ov003_021d7c54;
    FillBytes(d, 0, 0x5dc);
    CopyBytes(e, &b[2], 8);
    XorAndSwapBytesWithKey(e, 8, gMelcoString, GetStringLength(gMelcoString));
    FillPacketHeader(d, 0x3000, 0, 0, 0, 0x11, e);
    SendPacket(d, 0x18, 0, c);
    return 0;
}

s16 BuildTwoItemChain(void *a) {
    OutgoingPacketItem *b = a;
    OutgoingPacketItem *c;
    s16 d;
    s16 e;
    s16 f;
    u32 g;
    f = 0;
    b->mType = data_ov003_021d7c6c.mUnk_19;
    b->mUnk_01 = 1;
    d = data_ov003_021d7c6c.mUnk_04;
    CopyBytes(b->mValue, data_ov003_021d7c6c.mUnk_00, d);
    b->mLength = func_ov003_021b7c94(d);
    d += 6;
    e = (d + 1) / 2 * 2;
    b->mNextOffset = func_ov003_021b7c94(e);
    f += e;
    c = OFFSET_PTR(OutgoingPacketItem, b, e);
    ((u8 *) b)[e] = 0x60;
    c->mUnk_01 = 0;
    c->mNextOffset = func_ov003_021b7c94(0);
    g = SwapBytes32(0xe);
    CopyBytes(c->mValue, &g, 4);
    c->mLength = func_ov003_021b7c94(4);
    f += 0xa;
    return f;
}

void FillPayloadRecord(s32 a, void *b, const void *c, s16 *d, s16 *e, s8 *f) {
    PayloadRecord *g = b;
    if (a == 1) {
        *e = 1;
        XorBytesWithRandomKeyStreamAndComputeCrc(c, g->mBytes, *d, f, g->mKeyPrefix, data_ov003_021d7c58, 8);
        g->mLength = func_ov003_021b7c94(*d);
        *d += 4;
    } else {
        CopyBytes(g, c, *d);
    }
}

void FillPacketHeader(void *p, s32 b, s32 c, s32 d, s8 e, s8 f, const u8 *g) {
    PacketHeader *h = p;
    h->mUnk_00 = func_ov003_021b7c94(1);
    h->mUnk_02 = 0;
    h->mUnk_04 = 0;
    h->mKind = func_ov003_021b7c94(b);
    h->mUnk_08 = 0;
    h->mPayloadLength = func_ov003_021b7c94(c);
    h->mFlags = func_ov003_021b7c94(d);
    h->mPayloadCrc = e;
    h->mUnk_0f = f;
    CopyBytes(h->mTag, g, 8);
}

s32 SendPacket(void *a, s32 b, u32 c, s32 d) {
    Unk021b7cec t;
    FillBytes(&t, 0, 8);
    t.mUnk_01 = 2;
    t.mUnk_02 = func_ov003_021b7c94(0x5790);
    t.mUnk_04 = SwapBytes32(data_ov003_021d7c6c.mUnk_10);
    if (c == 0xff || data_ov003_021d7c6c.mUnk_18 == 0) {
        t.mUnk_04 = -1;
    }
    return func_ov003_021b7d04(d, a, b, 0, &t, 8);
}

s32 XorBytesWithRandomKeyStreamAndComputeCrc(const u8 *a, u8 *b, s32 c, s8 *d, u8 *e, const u8 *f, s32 g) {
    u16 random;
    KeyStreamState state;
    *d = ComputeCrcLowByte(a, c);
    state.mTable = func_ov003_021ba178(c);
    if (state.mTable == NULL) {
        return -1;
    }
    random = NextRandomValue();
    CopyBytes(e, &random, 2);
    CopyBytes(gKeyStreamKeyPrefix, e, 2);
    CopyBytes(gKeyStreamKeyTail, f, g);
    InitKeyStream(&state, gKeyStreamKeyPrefix, g + 2, c);
    XorWithKeyStream(&state, b, a, c);
    func_ov003_021ba164(state.mTable);
    return 0;
}

s32 XorBytesWithKeyStreamAndCheckCrc(const u8 *a, u8 *b, s32 c, u32 d, const u8 *e, const u8 *f, s32 g) {
    KeyStreamState state;
    u8 crc;
    state.mTable = func_ov003_021ba178(c);
    if (state.mTable == NULL) {
        func_ov003_021b94b8(2);
        return -1;
    }
    CopyBytes(gKeyStreamKeyPrefix, e, 2);
    CopyBytes(gKeyStreamKeyTail, f, g);
    InitKeyStream(&state, gKeyStreamKeyPrefix, g + 2, c);
    XorWithKeyStream(&state, b, a, c);
    crc = ComputeCrcLowByte(b, c);
    if (crc != d) {
        func_ov003_021b94b8(0x12);
        func_ov003_021ba164(state.mTable);
        return -1;
    }
    func_ov003_021ba164(state.mTable);
    return 0;
}

// Fills the table with 0..n-1, then permutes it using the key bytes.
void InitKeyStream(KeyStreamState *p, const u8 *key, u32 keyLength, u32 n) {
    u8 *s;
    u32 i;
    u32 j;
    u32 k;
    u8 a;
    u8 t;
    s = p->mTable;
    p->mSwapIndex = 0;
    p->mIndex = p->mSwapIndex;
    p->mTableCount = n;
    for (i = 0; i < n; i++) {
        s[i] = i;
    }
    j = 0;
    k = 0;
    for (i = 0; i < n; i++) {
        a = s[i];
        j = (j + key[k] + a) % p->mTableCount;
        t = s[j];
        s[j] = a;
        s[i] = t;
        k++;
        if (k >= keyLength) {
            k = 0;
        }
    }
}

void XorWithKeyStream(KeyStreamState *p, u8 *dst, const u8 *src, u32 n) {
    u32 i;
    u8 a;
    for (i = 0; i < n; i++) {
        a = NextKeyStreamByte(p);
        dst[i] = a ^ src[i];
    }
}

u32 NextKeyStreamByte(KeyStreamState *p) {
    u8 *s;
    u32 n;
    u8 i;
    u8 j;
    u8 a;
    u8 b;
    s = p->mTable;
    n = p->mTableCount;
    i = (p->mIndex + 1) % n;
    a = s[i];
    j = (a + p->mSwapIndex) % n;
    b = s[j];
    p->mIndex = i;
    p->mSwapIndex = j;
    s[j] = a;
    s[i] = b;
    return s[(a + b) % p->mTableCount];
}

u8 ComputeCrcLowByte(const u8 *p0, s32 p1) {
    return ComputeCrc(~0, p0, p1, 0, (u32 *) data_ov003_021d7f6c) ^ ~0;
}

u32 ComputeCrc(u32 a, const u8 *b, s32 c, s32 d, u32 *e) {
    s32 i;
    if (d == 0) {
        InitCrcTable(d, e);
    }
    for (i = 0; i < c; i++) {
        a = (a >> 8) ^ e[(a ^ b[i]) & 0xff];
    }
    return a;
}

void InitCrcTable(s32 a, u32 *b) {
    u32 c;
    s32 i;
    s32 j;
    for (i = 0; i < 0x100; i++) {
        c = i;
        for (j = 0; j < 8; j++) {
            if (c & 1) {
                c = (c >> 1) ^ 0xedb88320;
            } else {
                c = c >> 1;
            }
        }
        *b++ = c;
    }
}

// Two passes of xor-ing the second half with key bytes and swapping the halves.
s32 XorAndSwapBytesWithKey(u8 *a, s32 b, const s8 *c, s32 d) {
    s8 *e;
    u8 *f;
    s32 i;
    e = func_ov003_021ba178(b / 2);
    if (e == NULL) {
        return -1;
    }
    f = func_ov003_021ba178(b);
    if (f == NULL) {
        func_ov003_021ba164(e);
        return -1;
    }
    for (i = 0; i < 2; i++) {
        FillIndexXorKeyBytes(i, e, b, c, d);
        XorSecondHalf(e, a, b);
        SwapBufferHalves(a, b, f);
    }
    func_ov003_021ba164(e);
    func_ov003_021ba164(f);
    return 0;
}

void FillIndexXorKeyBytes(s32 a, s8 *b, s32 c, const s8 *d, s32 e) {
    s32 f = c / 2;
    s32 g = a % e;
    s32 i;
    for (i = 0; i < f; i++) {
        b[i] = i;
        b[i] ^= d[g++];
        if (g >= e) {
            g = 0;
        }
    }
}

void XorSecondHalf(const s8 *key, u8 *buffer, s32 size) {
    s32 half = size / 2;
    s32 i;
    for (i = 0; i < half; i++) {
        buffer[half + i] ^= key[i];
    }
}

void SwapBufferHalves(u8 *a, u32 b, u8 *c) {
    int v1;
    v1 = _s32_div_f(b, 2);
    CopyBytes(c, (a + v1), v1);
    CopyBytes((c + v1), a, v1);
    CopyBytes(a, c, b);
}

u32 func_ov003_021b7e70(u32 a, int b) {
    u32 v1;
    if (0 < b) {
        v1 = (*(UnkWordFunc *) (*(u32 *) &data_ov003_021d8a0c))(b);
        return v1;
    }
    return 0;
}

void func_ov003_021b7e58(u32 a, u32 b) {
    (*(UnkFunc *) (*(u32 *) &data_ov003_021d8a18))(b);
}

s32 func_ov003_021b7df4(u32 a, u32 b, u32 c) {
    data_ov003_021d6810.mUnk_10 = SwapBytes32(a);
    data_ov003_021d6810.mUnk_14 = SwapBytes32(b);
    data_ov003_021d6810.mUnk_18 = SwapBytes32(c);
    if (func_ov000_021a8c94(&data_ov003_021d6810) < 0) {
        return -1;
    }
    while (data_ov000_021b63b4 == 0) {
        OS_Sleep(100);
    }
    return 0;
}

s32 func_ov003_021b7dc8(void) {
    if (func_ov000_021a8c8c() < 0) {
        return -1;
    }
    return -(func_ov003_021ba524() != 0);
}

s32 CompareBytes(const u8 *left, const u8 *right, s32 count) {
    s32 difference = 0;
    while (count-- > 0 && (difference = *left - *right) == 0) {
        left++;
        right++;
    }
    return difference;
}

void CopyBytes(void *arg0, const void *arg1, u32 arg2) {
    MI_CpuCopy8(arg1, arg0, arg2);
}

void FillBytes(void *arg0, s32 arg1, u32 arg2) {
    void *value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value3;
    value1 = (value1 << 24);
    value1 = (value1 >> 24);
    MI_CpuFill8(value0, value1, value2);
}

s32 func_ov003_021b7d68(s32 v1, void *v2, s32 v3, s32 v4, Unk021b7cec *v5, s32 *v6) {
    v5->mUnk_00 = *v6;
    return func_ov000_021a90a0(v1, v2, v3, v4, v5);
}

s32 func_ov003_021b7d1c(s32 v1, Unk021b7ba0 *v2, void *v3, void *v4, Unk021b7d1c *v5) {
    Unk021b7ba0 t;
    s64 s;
    s = 0;
    t = *v2;
    s += v5->mUnk_00 * 0x1ff6210 / 0x40;
    s += v5->mUnk_04 * 0x1ff6210 / 0x40;
    return func_ov000_021a8b20(&t, 1, s);
}

s32 func_ov003_021b7d04(s32 a, void *b, s32 c, s32 d, Unk021b7cec *e, u32 f) {
    e->mUnk_00 = f;
    return func_ov000_021a9018(a, b, c, d, e);
}

s32 func_ov003_021b7d00(s32 id, s32 arg1, s32 arg2, void *value, s32 length) {
    return id;
}

s32 func_ov003_021b7cf8(s32 domain, s32 type, s32 protocol) {
    return func_ov000_021a918c(domain, type, protocol);
}

s32 func_ov003_021b7cec(s32 v1, Unk021b7cec *v2, u32 v3) {
    v2->mUnk_00 = v3;
    return func_ov000_021a916c(v1, v2);
}

s32 func_ov003_021b7ce4(s32 descriptor) {
    return func_ov000_021a9008(descriptor);
}

u32 SwapBytes32(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    value1 = (value0 << 24);
    value2 = 0xff000000u;
    value1 = (value1) & (value2);
    value4 = (value0 << 8);
    value2 = 0xff0000u;
    value4 = (value4) & (value2);
    value3 = (value0 >> 24);
    value2 = 255u;
    value3 = (value3) & (value2);
    value2 = (value0 >> 8);
    value0 = 0xff00u;
    value2 = (value2) & (value0);
    value3 = (value3) | (value2);
    value4 = (value4) | (value3);
    value1 = (value1) | (value4);
    value0 = (value1) + (0u);
    return value0;
}

u16 func_ov003_021b7c94(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}

u32 func_ov003_021b7c5c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    value1 = (value0 << 24);
    value2 = 0xff000000u;
    value1 = (value1) & (value2);
    value4 = (value0 << 8);
    value2 = 0xff0000u;
    value4 = (value4) & (value2);
    value3 = (value0 >> 24);
    value2 = 255u;
    value3 = (value3) & (value2);
    value2 = (value0 >> 8);
    value0 = 0xff00u;
    value2 = (value2) & (value0);
    value3 = (value3) | (value2);
    value4 = (value4) | (value3);
    value1 = (value1) | (value4);
    value0 = (value1) + (0u);
    return value0;
}

u16 SwapBytes16(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}

int GetStringLength(const void *a) {
    const s8 *p = a;
    int i = 0;
    while (p[i] != 0) {
        i++;
    }
    return i;
}

// Multiply-add generator, seeded from the clock on the first call; returns a value below 0x7fff.
u16 NextRandomValue(void) {
    s32 seed;
    RTCTime time;
    u32 *c;
    if (gRandomSeeded == 0) {
        seed = 0;
        FillBytes(&time, 0, 12);
        if (RTC_GetTime(&time) == 0) {
            seed += time.mHour << 10;
            seed += time.mMinute << 3;
            seed += time.mSecond;
        }
        gRandomState[0] = seed;
        gRandomState[1] = 0x5d588b65;
        gRandomState[2] = 0x269ec3;
        gRandomSeeded = 1;
    }
    gRandomState[0] = gRandomState[2] + gRandomState[1] * gRandomState[0];
    return ((gRandomState[0] >> 16) * 0x7fff) >> 16;
}

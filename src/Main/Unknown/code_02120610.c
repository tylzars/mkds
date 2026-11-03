#include "Main/Unknown/code_02056464.h"
#include "Main/Unknown/code_02120610.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02122b14.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02123000.h"
#include "00/code_0219b000.h"
#include "00/code_0219bb50.h"
#include "00/code_0219bb68.h"
#include "00/code_021a2000.h"
#include "00/code_021a2950.h"
#include "00/code_021a2cac.h"
#include "00/code_021a2ccc.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02029890.h"
#include "code_02135014.h"
#include "code_0214d018.h"

#pragma opt_arithtransformation off

void func_02121dec(u32 a) {
    data_0217d384->mUnk_1e10[func_ov000_0219bb50()].mUnk_40 = a != 0 ? 1 : 2;
}

s32 func_02121d94(void) {
    if (func_02029930()->mCourseId == 0) {
        return data_0217d384->mUnk_1e10[func_ov000_0219bb50()].mPickedCourseId;
    }
    return func_02029930()->mCourseId;
}

BOOL func_02121d48(void) {
    if (data_0217d384->mStep >= 5) {
        if (func_02120644() == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_02121d0c(void) {
    BOOL r = TRUE;
    Unk0217d384 *d = data_0217d384;
    s32 v = d->mStep;

    if (v < 7) {
        if (d->mUnk_19ad != 1 || v != 0xc) {
            r = FALSE;
        }
    }
    return r;
}

s32 func_02121cd0(void) {
    BOOL r = TRUE;
    Unk0217d384 *d = data_0217d384;
    s32 v = d->mStep;

    if (v < 10) {
        if (d->mUnk_19ad != 1 || v != 0xc) {
            r = FALSE;
        }
    }
    return r;
}

s32 func_02121c78(void) {
    s32 v;

    v = data_0217d384->mStep;
    if (v >= 5) {
        if (data_0217d384->mKartCount > 1) {
            return 1;
        }
        return 2;
    }
    if (data_0217d384->mUnk_19ad == 1) {
        if (v == 0xc) {
            return 2;
        }
    }
    if (v == 0xc) {
        return 2;
    }
    return 0;
}

void func_02121af4(void) {
    u8 i;
    u8 mx = 0;
    u8 n = 0;
    u32 c[4] = {0, 0, 0, 0};
    u8 b[0x37] = {0};
    u8 j;
    Unk0217d384 *d;
    Unk0217d384_1954 *r;
    u32 v;
    u32 w;

    d = data_0217d384;
    for (i = 0; i < d->mStartKartCount; i++) {
        if (d->mKartMask & (1 << i)) {
            b[d->mUnk_1e10[i].mPickedCourseId]++;
            if (mx < b[d->mUnk_1e10[i].mPickedCourseId]) {
                mx = b[d->mUnk_1e10[i].mPickedCourseId];
            }
        }
    }
    for (j = 0; j < 0x37; j++) {
        if (mx == b[j]) {
            c[n++] = j;
        }
    }
    r = &d->mUnk_1954;
    if (n == 0) {
        v = 0;
    } else {
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        if (n == 0) {
            v = (u32) (r->mValue >> 32);
        } else {
            v = (u32) (((r->mValue >> 32) * (u32) n) >> 32);
        }
    }
    w = c[(u16) v];
    func_02029930()->mCourseId = w;
}

void func_021219cc(void) {
    BOOL z = FALSE;
    u8 i;

    for (i = 0; i < data_0217d384->mStartKartCount; i++) {
        if (data_0217d384->mKartMask & (1 << i)) {
            if (i == func_ov000_0219bb50()) {
                s8 x;

                x = data_0217d384->mUnk_1f4e[i];
                func_02029930()->mUnk_00[x].mUnk_08 = z;
            } else {
                s8 x;

                x = data_0217d384->mUnk_1f4e[i];
                func_02029930()->mUnk_00[x].mUnk_08 = 3;
            }
            {
                Unk0217d384 *d;
                s8 x;

                d = data_0217d384;
                x = d->mUnk_1f4e[i];
                func_02029930()->mUnk_00[x].mCharacterIndex = d->mUnk_1e10[i].mCharacterIndex;
            }
            {
                Unk0217d384 *d;
                s8 x;

                d = data_0217d384;
                x = d->mUnk_1f4e[i];
                func_02029930()->mUnk_00[x].mKartIndex = d->mUnk_1e10[i].mKartIndex;
            }
        }
    }
}

BOOL func_02121990(Unk02121990 *a, u32 b, u32 c, u32 d) {
    if (a->mKind < 10) {
        if (a->mSize == b) {
            if (a->mFromIndex == c) {
                if (a->mToIndex == d) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

BOOL func_021217e8(u32 a) {
    switch (a) {
        case 0:
            if (data_0217d384->mStep == 0 || data_0217d384->mStep == 1) {
                return TRUE;
            }
            break;
        case 1:
            if (data_0217d384->mStep == 0) {
                return TRUE;
            }
            break;
        case 2:
            if (data_0217d384->mStep == 0 || data_0217d384->mStep == 1) {
                return TRUE;
            }
            break;
        case 8:
            if ((u32) (data_0217d384->mStep - 3) <= 1) {
                return TRUE;
            }
            break;
        case 9:
            if ((u32) (data_0217d384->mStep - 3) <= 2) {
                return TRUE;
            }
            break;
        case 3:
            if (data_0217d384->mStep == 1 || (u32) (data_0217d384->mStep - 4) <= 2) {
                return TRUE;
            }
            break;
        case 4:
            if ((u32) (data_0217d384->mStep - 5) <= 1) {
                return TRUE;
            }
            break;
        case 5:
            if ((u32) (data_0217d384->mStep - 6) <= 1) {
                return TRUE;
            }
            break;
        case 6:
            if ((u32) (data_0217d384->mStep - 7) <= 1) {
                return TRUE;
            }
            break;
        case 7:
            if ((u32) (data_0217d384->mStep - 8) <= 1) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

u8 func_021216a8(void) {
    u8 i;
    u8 x;

    x = data_0217d384->mUnk_19ac;
    if (x < 2) {
        data_0217d384->mUnk_19ac = x + 1;
        return data_0217d384->mStartKartCount;
    }
    for (i = data_0217d384->mUnk_1999; i < data_0217d384->mStartKartCount; i++) {
        if (i != func_ov000_0219bb50()) {
            if (data_0217d384->mKartMask & (1 << i)) {
                break;
            }
        }
    }
    if (data_0217d384->mUnk_1999 >= data_0217d384->mStartKartCount) {
        for (i = 0; i < data_0217d384->mUnk_1999; i++) {
            if (i != func_ov000_0219bb50()) {
                if (data_0217d384->mKartMask & (1 << i)) {
                    break;
                }
            }
        }
        if (i >= data_0217d384->mUnk_1999) {
            return data_0217d384->mStartKartCount;
        }
    }
    data_0217d384->mUnk_1999 = i + 1;
    data_0217d384->mUnk_19ac = 0;
    return i;
}

BOOL func_02121580(void) {
    u8 i;
    u8 a = 0;
    u8 b = 0;
    u8 n;
    u8 j;
    u8 c;
    u8 m;

    for (i = 0; i < data_0217d384->mStartKartCount; i++) {
        if (i != func_ov000_0219bb50()) {
            if (data_0217d384->mKartMask & (1 << i)) {
                b++;
                if ((data_0217d384->mUnk_19ab & (1 << i)) == 0) {
                    break;
                }
                a++;
            }
        }
    }
    if (b == 0) {
        data_0217d384->mUnk_19ad = 1;
        func_ov000_021a2ccc();
        func_ov000_0219bbfc();
        data_0217d384->mStep = 0xb;
        return FALSE;
    }
    c = 0;
    n = data_0217d384->mStartKartCount;
    m = data_0217d384->mKartMask;
    for (j = 0; j < n; j++) {
        if (m & (1 << j)) {
            c++;
        }
    }
    return a == c - 1;
}

void func_0212145c(u32 a) {
    u8 i;
    u8 f = 0;
    u8 k;

    for (i = 0; i < data_0217d384->mStartKartCount; i++) {
        if ((k = func_ov000_0219bb50(), data_0217d384->mUnk_1e10[k].mKartIndices[i]) !=
                data_0217d384->mUnk_1d00[a].mKartIndices[i] ||
            (k = func_ov000_0219bb50(), data_0217d384->mUnk_1e10[k].mCharacterIndices[i]) !=
                data_0217d384->mUnk_1d00[a].mCharacterIndices[i]) {
            f = 1;
        }
    }
    k = func_ov000_0219bb50();
    if (data_0217d384->mUnk_1d00[a].mTalliedCourseId != data_0217d384->mUnk_1e10[k].mTalliedCourseId) {
        f = 1;
    }
    if (f == 0) {
        return;
    }
    data_0217d384->mUnk_19ad = 1;
    func_ov000_021a2ccc();
    func_ov000_0219bbfc();
    data_0217d384->mStep = 0xb;
}

BOOL func_02121434(void) {
    return func_ov000_021a2950(NULL) == 0;
}

u8 func_02121418(void) {
    return func_ov000_0219bb68();
}

BOOL func_021213f4(void) {
    return data_0217d384->mUnk_194d != 0;
}

u32 func_021213e8(void) {
    return func_ov000_021a2cac();
}

BOOL func_021213a0(void) {
    if (func_ov000_021a2c64() != 0) {
        if (data_0217d384->mUnk_0008.mState == 3) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL func_0212137c(void) {
    return data_0217d384->mStartStatus == 2;
}

void func_02121190(u32 kartType, s32 b, s32 c) {
    Unk0217d384_08 *p;

    func_ov000_0219bbfc();
    func_0214d168(&data_0217d384->mKeys[0], 0, 0x18);
    func_0214d168(&data_0217d384->mKeys[1], 0, 0x18);
    func_0214d168(&data_0217d384->mKeys[2], 0, 0x18);
    func_0214d168(&data_0217d384->mKeys[3], 0, 0x18);
    data_0217d384->mUnk_194e = 0;
    data_0217d384->mUnk_194c = 0;
    data_0217d384->mUnk_194d = 0;
    data_0217d384->mKartCount = 0;
    data_0217d384->mStartKartCount = 0;
    data_0217d384->mKartCountCopy = 0;
    data_0217d384->mKartMask = 0;
    data_0217d384->mKartRemoveMask = 0;
    func_0214d168(&data_0217d384->mStep, 0, 0x60);
    data_0217d384->mKeys[1].mValue = kartType;
    data_0217d384->mUnk_194c = 4;
    if (b == 0) {
        data_0217d384->mUnk_18e0.mUnk_00 = 1;
        data_0217d384->mUnk_18e0.mUnk_01 = 2;
        data_0217d384->mUnk_18e0.mUnk_04 = 1;
    } else {
        data_0217d384->mUnk_18e0.mUnk_00 = 1;
        data_0217d384->mUnk_18e0.mUnk_01 = 2;
        data_0217d384->mUnk_18e0.mUnk_04 = 0xea60;
    }
    func_ov000_021a299c(0, &data_0217d384->mUnk_18e0, 0);
    p = &data_0217d384->mUnk_0008;
    p->mNextState = 3;
    p->mNextStateRequested = 1;
}

s32 func_0212111c(void) {
    if ((data_0217d384->mUnk_194e != 0 && func_ov000_0219bb68() <= 1) || data_0217d384->mUnk_1f44 == 7) {
        return -1;
    }
    return func_02121d48() != FALSE;
}

void RegisterKartKeysAndStart(void) {
    s32 eloHigh;
    s32 eloLow;

    func_02120610();
    func_0214d168(data_0217d384->mUnk_021c, 0, 0x910);
    func_02056464((Unk0217aa00_45c *) &data_0217d384->mUnk_021c[0].mUnk_00c);
    data_0217d384->mKeys[0].mValue = data_0217d384->mUnk_021c[0].mRegion;
    data_0217d384->mKeys[3].mValue = data_0217d384->mUnk_021c[0].mElo;
    __memcpy(data_0217d384->mKeys[2].mName, "kart_filter", 12);
    data_0217d384->mKeys[2].mId =
        func_ov000_021a2ad0(data_0217d384->mKeys[2].mId, data_0217d384->mKeys[2].mName, "ds_mario_kart_product");
    __memcpy(data_0217d384->mKeys[1].mName, "kart_type", 10);
    data_0217d384->mKeys[1].mId =
        func_ov000_021a2b9c(data_0217d384->mKeys[1].mId, data_0217d384->mKeys[1].mName, &data_0217d384->mKeys[1]);
    __memcpy(data_0217d384->mKeys[3].mName, "kart_elo", 9);
    data_0217d384->mKeys[3].mId =
        func_ov000_021a2b9c(data_0217d384->mKeys[3].mId, data_0217d384->mKeys[3].mName, &data_0217d384->mKeys[3]);
    __memcpy(data_0217d384->mKeys[0].mName, "kart_region", 12);
    data_0217d384->mKeys[0].mId =
        func_ov000_021a2b9c(data_0217d384->mKeys[0].mId, data_0217d384->mKeys[0].mName, &data_0217d384->mKeys[0]);
    eloLow = data_0217d384->mUnk_021c[0].mElo - 0x3e8;
    if (eloLow <= 0) {
        eloLow = 0;
    }
    eloHigh = data_0217d384->mUnk_021c[0].mElo + 0x3e8;
    if (eloHigh > 0x2710) {
        eloHigh = 0x2710;
    }
    func_0214d168(gKartFilterString, 0, 0x64);
    if (data_0217d384->mKeys[1].mValue == 1) {
        sprintf(gKartFilterString, (const u8 *) "%s = '%s' and %s > %d and %s < %d", "kart_filter",
                "ds_mario_kart_product", "kart_elo", eloLow, "kart_elo", eloHigh);
    } else {
        sprintf(gKartFilterString, (const u8 *) "%s = '%s'", "kart_filter", "ds_mario_kart_product");
    }
    switch (data_0217d384->mKeys[1].mValue) {
        case 3:
            func_ov000_0219bd90(data_0217d384->mUnk_194c, gKartFilterString, KartKeysStartCallback, NULL,
                                ComputeRegionEval, 0);
            break;
        case 4:
            func_ov000_0219bd90(data_0217d384->mUnk_194c, gKartFilterString, KartKeysStartCallback, NULL,
                                ComputeRegionEloEval, 0);
            break;
        case 0:
            func_ov000_0219bc78(NULL, 0, data_0217d384->mUnk_194c, 1, KartKeysStartCallback, NULL, 0, 0);
            break;
        case 1:
            func_ov000_0219bd90(data_0217d384->mUnk_194c, gKartFilterString, KartKeysStartCallback, NULL,
                                ComputeEloEval, 0);
            break;
    }
    data_0217d384->mStartStatus = 1;
}

BOOL func_02120d14(void) {
    s32 v;

    v = data_0217d384->mStartStatus;
    switch (v) {
        case 1:
            break;
        case 3:
            return TRUE;
        case 4:
            break;
    }
    return FALSE;
}

s32 ComputeEloEval(u32 a) {
    s32 kartType;
    s32 kartRegion;
    s32 z;
    Unk0217d384 *d;

    kartType = func_ov000_021a2a88(a, data_0217d384->mKeys[1].mName, 5);
    kartRegion = func_ov000_021a2a88(a, data_0217d384->mKeys[0].mName, 3);
    z = func_ov000_021a2a88(a, data_0217d384->mKeys[3].mName, -1);
    if (kartType == 5 || kartRegion == 3 || z < 0) {
        return 0;
    }
    d = data_0217d384;
    if (d->mUnk_021c[0].mElo > z) {
        z = d->mUnk_021c[0].mElo - z;
    } else {
        z = z - d->mUnk_021c[0].mElo;
    }
    if (z < 0x3e8) {
        if (kartType == 1) {
            return 0x7d0 - z;
        }
        if (kartType == 4) {
            return 0x3e8 - z;
        }
    }
    return 0;
}

BOOL ComputeRegionEval(u32 a) {
    s32 kartType;
    s32 kartRegion;

    kartType = func_ov000_021a2a88(a, data_0217d384->mKeys[1].mName, 5);
    kartRegion = func_ov000_021a2a88(a, data_0217d384->mKeys[0].mName, 3);
    if (kartType == 5 || kartRegion == 3) {
        return FALSE;
    }
    if (kartType == 3) {
        if (data_0217d384->mUnk_021c[0].mRegion == kartRegion) {
            return TRUE;
        }
    }
    return FALSE;
}

s32 ComputeRegionEloEval(u32 a) {
    s32 kartType;
    s32 kartRegion;
    s32 z;
    Unk0217d384 *d;

    kartType = func_ov000_021a2a88(a, data_0217d384->mKeys[1].mName, 5);
    kartRegion = func_ov000_021a2a88(a, data_0217d384->mKeys[0].mName, 3);
    z = func_ov000_021a2a88(a, data_0217d384->mKeys[3].mName, -1);
    if (kartType == 5 || kartRegion == 3 || z < 0) {
        return 0;
    }
    if (kartType == 4) {
        return (kartRegion != data_0217d384->mUnk_021c[0].mRegion ? 2 : 1) * 0x7d0;
    }
    if (kartType == 1) {
        d = data_0217d384;
        if (d->mUnk_021c[0].mElo > z) {
            z = d->mUnk_021c[0].mElo - z;
        } else {
            z = z - d->mUnk_021c[0].mElo;
        }
        if (z < 0x3e8) {
            if (kartRegion != d->mUnk_021c[0].mRegion) {
                return 0x7d0 - z;
            }
            return 0x3e8 - z;
        }
    }
    return 0;
}

void KartKeysStartCallback(u32 a, s32 b) {
    Unk0217d384 *d;
    u8 i;

    if (a == 0) {
        if (b != 0) {
            data_0217d384->mStartStatus = 2;
            return;
        }
        data_0217d384->mKartMask = 0;
        data_0217d384->mKartCount = func_ov000_0219bb68();
        data_0217d384->mStartKartCount = data_0217d384->mKartCount;
        d = data_0217d384;
        i = 0;
        while (i < d->mStartKartCount) {
            d->mKartMask |= 1 << i;
            d = data_0217d384;
            i++;
        }
        func_0214d168(d->mUnk_021c, 0, 0x910);
        func_02056464((Unk0217aa00_45c *) &data_0217d384->mUnk_021c[func_ov000_0219bb50()].mUnk_00c);
        func_02123a48(0);
        data_0217d384->mStartStatus = 3;
    } else {
        data_0217d384->mStartStatus = 4;
    }
}

void func_021208e8(s32 a) {
    data_0217d384->mUnk_1f40 = a;
    if (data_0217d384->mUnk_1f40 != 2) {
        return;
    }
    func_ov000_021a2ccc();
    func_ov000_0219bbfc();
}

void func_02120714(void) {
    func_0214d168(data_0217d384->mUnk_001c, 0, 0x200);
    func_0214d168(data_0217d384->mUnk_021c, 0, 0x910);
    func_0214d168(data_0217d384->mUnk_0b2c, 0, 0xe24);
    func_0214d168(&data_0217d384->mStep, 0, 0x60);
    func_0214d168(data_0217d384->mUnk_19b0, 0, 0x350);
    func_0214d168(data_0217d384->mUnk_1d00, 0, 0x110);
    func_0214d168(data_0217d384->mUnk_1e10, 0, 0x110);
    func_0214d168(&data_0217d384->mUnk_1f20, 0, 0x10);
    data_0217d384->mUnk_1f34 = 0;
    data_0217d384->mUnk_1f38 = 0;
    data_0217d384->mUnk_1f3c = 0;
    data_0217d384->mUnk_1f40 = 0;
    data_0217d384->mUnk_1f44 = 0;
    data_0217d384->mUnk_1f48 = 0;
    data_0217d384->mUnk_1f4c = 0;
    data_0217d384->mUnk_1f4d = 0;
    func_0214d168(data_0217d384->mUnk_1f4e, 0, 4);
    data_0217d384->mKartCount = 0;
    data_0217d384->mStartKartCount = 0;
    data_0217d384->mKartCountCopy = 0;
    data_0217d384->mKartMask = 0;
    data_0217d384->mKartRemoveMask = 0;
    data_0217d384->mUnk_1f57 = 0;
}

u32 func_02120644(void) {
    Unk0217d384 *d;
    Unk0217d384_08 *p;
    s32 v;

    d = data_0217d384;
    if (d->mUnk_0008.mState != 0) {
        v = d->mUnk_1f44;
        if (v == 6 || v == 3 || v == 4 || v == 0xb) {
            return 3;
        }
        if (d->mUnk_1f40 == 2) {
            if (func_ov000_0219bb68() <= 1) {
                p = &data_0217d384->mUnk_0008;
                p->mNextState = 2;
                p->mNextStateRequested = 1;
                return 2;
            }
        } else if (d->mUnk_1f40 == 1) {
            p = &d->mUnk_0008;
            p->mNextState = 2;
            p->mNextStateRequested = 1;
            return 1;
        }
    }
    return 0;
}

void func_02120610(void) {
    data_0217d384->mUnk_1f44 = 0;
    data_0217d384->mUnk_1f40 = 0;
    data_0217d384->mUnk_1f48 = 0;
}

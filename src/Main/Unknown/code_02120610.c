#include "Main/Unknown/code_02120610.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02123000.h"
#include "00/code_0219b000.h"
#include "00/code_0219bb50.h"
#include "00/code_021a2000.h"
#include "00/code_021a2cac.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02029890.h"
#include "code_02135014.h"

#pragma opt_arithtransformation off

void func_02121dec(u32 a) {
    data_0217d384->mUnk_1e10[func_ov000_0219bb50()].mUnk_40 = a != 0 ? 1 : 2;
}

s32 func_02121d94(void) {
    if (func_02029930()->mUnk_d0 == 0) {
        return data_0217d384->mUnk_1e10[func_ov000_0219bb50()].mUnk_38;
    }
    return func_02029930()->mUnk_d0;
}

s32 func_02121d48(void) {
    if (data_0217d384->mUnk_1950 >= 5) {
        if (func_02120644() == 0) {
            return 1;
        }
    }
    return 0;
}

s32 func_02121d0c(void) {
    s32 r = 1;
    Unk0217d384 *d = data_0217d384;
    s32 v = d->mUnk_1950;

    if (v < 7) {
        if (d->mUnk_19ad != 1 || v != 0xc) {
            r = 0;
        }
    }
    return r;
}

s32 func_02121cd0(void) {
    s32 r = 1;
    Unk0217d384 *d = data_0217d384;
    s32 v = d->mUnk_1950;

    if (v < 10) {
        if (d->mUnk_19ad != 1 || v != 0xc) {
            r = 0;
        }
    }
    return r;
}

s32 func_02121c78(void) {
    s32 v;

    v = data_0217d384->mUnk_1950;
    if (v >= 5) {
        if (data_0217d384->mUnk_1f52 > 1) {
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
    for (i = 0; i < d->mUnk_1f53; i++) {
        if (d->mUnk_1f55 & (1 << i)) {
            b[d->mUnk_1e10[i].mUnk_38]++;
            if (mx < b[d->mUnk_1e10[i].mUnk_38]) {
                mx = b[d->mUnk_1e10[i].mUnk_38];
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
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        if (n == 0) {
            v = (u32) (r->mUnk_00 >> 32);
        } else {
            v = (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
        }
    }
    w = c[(u16) v];
    func_02029930()->mUnk_d0 = w;
}

void func_021219cc(void) {
    s32 z = 0;
    u8 i;

    for (i = 0; i < data_0217d384->mUnk_1f53; i++) {
        if (data_0217d384->mUnk_1f55 & (1 << i)) {
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
                func_02029930()->mUnk_00[x].mUnk_00 = d->mUnk_1e10[i].mUnk_30;
            }
            {
                Unk0217d384 *d;
                s8 x;

                d = data_0217d384;
                x = d->mUnk_1f4e[i];
                func_02029930()->mUnk_00[x].mUnk_04 = d->mUnk_1e10[i].mUnk_34;
            }
        }
    }
}

s32 func_02121990(Unk02121990 *a, u32 b, u32 c, u32 d) {
    if (a->mUnk_00 < 10) {
        if (a->mUnk_04 == b) {
            if (a->mUnk_08 == c) {
                if (a->mUnk_09 == d) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 func_021217e8(u32 a) {
    switch (a) {
        case 0:
            if (data_0217d384->mUnk_1950 == 0 || data_0217d384->mUnk_1950 == 1) {
                return 1;
            }
            break;
        case 1:
            if (data_0217d384->mUnk_1950 == 0) {
                return 1;
            }
            break;
        case 2:
            if (data_0217d384->mUnk_1950 == 0 || data_0217d384->mUnk_1950 == 1) {
                return 1;
            }
            break;
        case 8:
            if ((u32) (data_0217d384->mUnk_1950 - 3) <= 1) {
                return 1;
            }
            break;
        case 9:
            if ((u32) (data_0217d384->mUnk_1950 - 3) <= 2) {
                return 1;
            }
            break;
        case 3:
            if (data_0217d384->mUnk_1950 == 1 || (u32) (data_0217d384->mUnk_1950 - 4) <= 2) {
                return 1;
            }
            break;
        case 4:
            if ((u32) (data_0217d384->mUnk_1950 - 5) <= 1) {
                return 1;
            }
            break;
        case 5:
            if ((u32) (data_0217d384->mUnk_1950 - 6) <= 1) {
                return 1;
            }
            break;
        case 6:
            if ((u32) (data_0217d384->mUnk_1950 - 7) <= 1) {
                return 1;
            }
            break;
        case 7:
            if ((u32) (data_0217d384->mUnk_1950 - 8) <= 1) {
                return 1;
            }
            break;
    }
    return 0;
}

u8 func_021216a8(void) {
    u8 i;
    u8 x;

    x = data_0217d384->mUnk_19ac;
    if (x < 2) {
        data_0217d384->mUnk_19ac = x + 1;
        return data_0217d384->mUnk_1f53;
    }
    for (i = data_0217d384->mUnk_1999; i < data_0217d384->mUnk_1f53; i++) {
        if (i != func_ov000_0219bb50()) {
            if (data_0217d384->mUnk_1f55 & (1 << i)) {
                break;
            }
        }
    }
    if (data_0217d384->mUnk_1999 >= data_0217d384->mUnk_1f53) {
        for (i = 0; i < data_0217d384->mUnk_1999; i++) {
            if (i != func_ov000_0219bb50()) {
                if (data_0217d384->mUnk_1f55 & (1 << i)) {
                    break;
                }
            }
        }
        if (i >= data_0217d384->mUnk_1999) {
            return data_0217d384->mUnk_1f53;
        }
    }
    data_0217d384->mUnk_1999 = i + 1;
    data_0217d384->mUnk_19ac = 0;
    return i;
}

s32 func_02121580(void) {
    u8 i;
    u8 a = 0;
    u8 b = 0;
    u8 n;
    u8 j;
    u8 c;
    u8 m;

    for (i = 0; i < data_0217d384->mUnk_1f53; i++) {
        if (i != func_ov000_0219bb50()) {
            if (data_0217d384->mUnk_1f55 & (1 << i)) {
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
        data_0217d384->mUnk_1950 = 0xb;
        return 0;
    }
    c = 0;
    n = data_0217d384->mUnk_1f53;
    m = data_0217d384->mUnk_1f55;
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

    for (i = 0; i < data_0217d384->mUnk_1f53; i++) {
        if ((k = func_ov000_0219bb50(), data_0217d384->mUnk_1e10[k].mUnk_1c[i]) !=
                data_0217d384->mUnk_1d00[a].mUnk_1c[i] ||
            (k = func_ov000_0219bb50(), data_0217d384->mUnk_1e10[k].mUnk_0c[i]) !=
                data_0217d384->mUnk_1d00[a].mUnk_0c[i]) {
            f = 1;
        }
    }
    k = func_ov000_0219bb50();
    if (data_0217d384->mUnk_1d00[a].mUnk_2c != data_0217d384->mUnk_1e10[k].mUnk_2c) {
        f = 1;
    }
    if (f == 0) {
        return;
    }
    data_0217d384->mUnk_19ad = 1;
    func_ov000_021a2ccc();
    func_ov000_0219bbfc();
    data_0217d384->mUnk_1950 = 0xb;
}

s32 func_02121434(void) {
    return func_ov000_021a2950(0) == 0;
}

u8 func_02121418(void) {
    return func_ov000_0219bb68();
}

s32 func_021213f4(void) {
    return data_0217d384->mUnk_194d != 0;
}

u32 func_021213e8(void) {
    return func_ov000_021a2cac();
}

s32 func_021213a0(void) {
    if (func_ov000_021a2c64() != 0) {
        if (data_0217d384->mUnk_0008.mUnk_0e == 3) {
            return 1;
        }
    }
    return 0;
}

s32 func_0212137c(void) {
    return data_0217d384->mUnk_18e8 == 2;
}

void func_02121190(u32 kartType, s32 b, s32 c) {
    Unk0217d384_08 *p;

    func_ov000_0219bbfc();
    func_0214d168(&data_0217d384->mUnk_18ec[0], 0, 0x18);
    func_0214d168(&data_0217d384->mUnk_18ec[1], 0, 0x18);
    func_0214d168(&data_0217d384->mUnk_18ec[2], 0, 0x18);
    func_0214d168(&data_0217d384->mUnk_18ec[3], 0, 0x18);
    data_0217d384->mUnk_194e = 0;
    data_0217d384->mUnk_194c = 0;
    data_0217d384->mUnk_194d = 0;
    data_0217d384->mUnk_1f52 = 0;
    data_0217d384->mUnk_1f53 = 0;
    data_0217d384->mUnk_1f54 = 0;
    data_0217d384->mUnk_1f55 = 0;
    data_0217d384->mUnk_1f56 = 0;
    func_0214d168(&data_0217d384->mUnk_1950, 0, 0x60);
    data_0217d384->mUnk_18ec[1].mUnk_00 = kartType;
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
    p->mUnk_10 = 3;
    p->mUnk_12 = 1;
}

s32 func_0212111c(void) {
    if ((data_0217d384->mUnk_194e != 0 && func_ov000_0219bb68() <= 1) || data_0217d384->mUnk_1f44 == 7) {
        return -1;
    }
    return func_02121d48() != 0;
}

void RegisterKartKeysAndStart(void) {
    s32 eloHigh;
    s32 eloLow;

    func_02120610();
    func_0214d168(data_0217d384->mUnk_021c, 0, 0x910);
    func_02056464((Unk0217aa00_45c *) &data_0217d384->mUnk_021c[0].mUnk_00c);
    data_0217d384->mUnk_18ec[0].mUnk_00 = data_0217d384->mUnk_021c[0].mUnk_234;
    data_0217d384->mUnk_18ec[3].mUnk_00 = data_0217d384->mUnk_021c[0].mUnk_222;
    __memcpy(data_0217d384->mUnk_18ec[2].mUnk_04, "kart_filter", 12);
    data_0217d384->mUnk_18ec[2].mUnk_14 = func_ov000_021a2ad0(
        data_0217d384->mUnk_18ec[2].mUnk_14, data_0217d384->mUnk_18ec[2].mUnk_04, "ds_mario_kart_product");
    __memcpy(data_0217d384->mUnk_18ec[1].mUnk_04, "kart_type", 10);
    data_0217d384->mUnk_18ec[1].mUnk_14 = func_ov000_021a2b9c(
        data_0217d384->mUnk_18ec[1].mUnk_14, data_0217d384->mUnk_18ec[1].mUnk_04, &data_0217d384->mUnk_18ec[1]);
    __memcpy(data_0217d384->mUnk_18ec[3].mUnk_04, "kart_elo", 9);
    data_0217d384->mUnk_18ec[3].mUnk_14 = func_ov000_021a2b9c(
        data_0217d384->mUnk_18ec[3].mUnk_14, data_0217d384->mUnk_18ec[3].mUnk_04, &data_0217d384->mUnk_18ec[3]);
    __memcpy(data_0217d384->mUnk_18ec[0].mUnk_04, "kart_region", 12);
    data_0217d384->mUnk_18ec[0].mUnk_14 = func_ov000_021a2b9c(
        data_0217d384->mUnk_18ec[0].mUnk_14, data_0217d384->mUnk_18ec[0].mUnk_04, &data_0217d384->mUnk_18ec[0]);
    eloLow = data_0217d384->mUnk_021c[0].mUnk_222 - 0x3e8;
    if (eloLow <= 0) {
        eloLow = 0;
    }
    eloHigh = data_0217d384->mUnk_021c[0].mUnk_222 + 0x3e8;
    if (eloHigh > 0x2710) {
        eloHigh = 0x2710;
    }
    func_0214d168(gKartFilterString, 0, 0x64);
    if (data_0217d384->mUnk_18ec[1].mUnk_00 == 1) {
        sprintf(gKartFilterString, (const u8 *) "%s = '%s' and %s > %d and %s < %d", "kart_filter",
                "ds_mario_kart_product", "kart_elo", eloLow, "kart_elo", eloHigh);
    } else {
        sprintf(gKartFilterString, (const u8 *) "%s = '%s'", "kart_filter", "ds_mario_kart_product");
    }
    switch (data_0217d384->mUnk_18ec[1].mUnk_00) {
        case 3:
            func_ov000_0219bd90(data_0217d384->mUnk_194c, gKartFilterString, KartKeysStartCallback, 0,
                                ComputeRegionEval, 0);
            break;
        case 4:
            func_ov000_0219bd90(data_0217d384->mUnk_194c, gKartFilterString, KartKeysStartCallback, 0,
                                ComputeRegionEloEval, 0);
            break;
        case 0:
            func_ov000_0219bc78(0, 0, data_0217d384->mUnk_194c, 1, KartKeysStartCallback, 0, 0, 0);
            break;
        case 1:
            func_ov000_0219bd90(data_0217d384->mUnk_194c, gKartFilterString, KartKeysStartCallback, 0, ComputeEloEval,
                                0);
            break;
    }
    data_0217d384->mUnk_18e8 = 1;
}

s32 func_02120d14(void) {
    s32 v;

    v = data_0217d384->mUnk_18e8;
    switch (v) {
        case 1:
            break;
        case 3:
            return 1;
        case 4:
            break;
    }
    return 0;
}

s32 ComputeEloEval(u32 a) {
    s32 kartType;
    s32 kartRegion;
    s32 z;
    Unk0217d384 *d;

    kartType = func_ov000_021a2a88(a, data_0217d384->mUnk_18ec[1].mUnk_04, 5);
    kartRegion = func_ov000_021a2a88(a, data_0217d384->mUnk_18ec[0].mUnk_04, 3);
    z = func_ov000_021a2a88(a, data_0217d384->mUnk_18ec[3].mUnk_04, -1);
    if (kartType == 5 || kartRegion == 3 || z < 0) {
        return 0;
    }
    d = data_0217d384;
    if (d->mUnk_021c[0].mUnk_222 > z) {
        z = d->mUnk_021c[0].mUnk_222 - z;
    } else {
        z = z - d->mUnk_021c[0].mUnk_222;
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

s32 ComputeRegionEval(u32 a) {
    s32 kartType;
    s32 kartRegion;

    kartType = func_ov000_021a2a88(a, data_0217d384->mUnk_18ec[1].mUnk_04, 5);
    kartRegion = func_ov000_021a2a88(a, data_0217d384->mUnk_18ec[0].mUnk_04, 3);
    if (kartType == 5 || kartRegion == 3) {
        return 0;
    }
    if (kartType == 3) {
        if (data_0217d384->mUnk_021c[0].mUnk_234 == kartRegion) {
            return 1;
        }
    }
    return 0;
}

s32 ComputeRegionEloEval(u32 a) {
    s32 kartType;
    s32 kartRegion;
    s32 z;
    Unk0217d384 *d;

    kartType = func_ov000_021a2a88(a, data_0217d384->mUnk_18ec[1].mUnk_04, 5);
    kartRegion = func_ov000_021a2a88(a, data_0217d384->mUnk_18ec[0].mUnk_04, 3);
    z = func_ov000_021a2a88(a, data_0217d384->mUnk_18ec[3].mUnk_04, -1);
    if (kartType == 5 || kartRegion == 3 || z < 0) {
        return 0;
    }
    if (kartType == 4) {
        return (kartRegion != data_0217d384->mUnk_021c[0].mUnk_234 ? 2 : 1) * 0x7d0;
    }
    if (kartType == 1) {
        d = data_0217d384;
        if (d->mUnk_021c[0].mUnk_222 > z) {
            z = d->mUnk_021c[0].mUnk_222 - z;
        } else {
            z = z - d->mUnk_021c[0].mUnk_222;
        }
        if (z < 0x3e8) {
            if (kartRegion != d->mUnk_021c[0].mUnk_234) {
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
            data_0217d384->mUnk_18e8 = 2;
            return;
        }
        data_0217d384->mUnk_1f55 = 0;
        data_0217d384->mUnk_1f52 = func_ov000_0219bb68();
        data_0217d384->mUnk_1f53 = data_0217d384->mUnk_1f52;
        d = data_0217d384;
        i = 0;
        while (i < d->mUnk_1f53) {
            d->mUnk_1f55 |= 1 << i;
            d = data_0217d384;
            i++;
        }
        func_0214d168(d->mUnk_021c, 0, 0x910);
        func_02056464((Unk0217aa00_45c *) &data_0217d384->mUnk_021c[func_ov000_0219bb50()].mUnk_00c);
        func_02123a48(0);
        data_0217d384->mUnk_18e8 = 3;
    } else {
        data_0217d384->mUnk_18e8 = 4;
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
    func_0214d168(&data_0217d384->mUnk_1950, 0, 0x60);
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
    data_0217d384->mUnk_1f52 = 0;
    data_0217d384->mUnk_1f53 = 0;
    data_0217d384->mUnk_1f54 = 0;
    data_0217d384->mUnk_1f55 = 0;
    data_0217d384->mUnk_1f56 = 0;
    data_0217d384->mUnk_1f57 = 0;
}

u32 func_02120644(void) {
    Unk0217d384 *d;
    Unk0217d384_08 *p;
    s32 v;

    d = data_0217d384;
    if (d->mUnk_0008.mUnk_0e != 0) {
        v = d->mUnk_1f44;
        if (v == 6 || v == 3 || v == 4 || v == 0xb) {
            return 3;
        }
        if (d->mUnk_1f40 == 2) {
            if (func_ov000_0219bb68() <= 1) {
                p = &data_0217d384->mUnk_0008;
                p->mUnk_10 = 2;
                p->mUnk_12 = 1;
                return 2;
            }
        } else if (d->mUnk_1f40 == 1) {
            p = &d->mUnk_0008;
            p->mUnk_10 = 2;
            p->mUnk_12 = 1;
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

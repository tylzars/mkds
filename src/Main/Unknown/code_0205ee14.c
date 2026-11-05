#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_0203b0a0.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0204b03c.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_02057624.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0204b000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_021201e4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "00/code_021832d8.h"
#include "00/code_0219b580.h"
#include "code_0214d018.h"

#pragma opt_rebuildconditionals off

static inline BOOL func_0205f218_inline(void) {
    Unk0217aa00 *p;

    p = data_0217aa00;
    return (p == NULL ? 0 : p->mUnk_0000) != 0 && p->mUnk_0004 != 13;
}

u32 func_0205fe1c(u8 *a, Unk02056bc0 *b, s32 c) {
    u8 d[10] = {0};
    u32 e;
    s32 f;
    u32 g;
    u8 m;
    s32 i;
    u16 k;
    u8 j;
    u32 n;
    s32 h;
    u8 q;
    s32 x;

    e = b->mUnk_00 + (b->mUnk_03 * 1000 + b->mUnk_02 * 60000);
    if (e >= 240000) {
        return 0;
    }
    f = func_0204684c(c);
    if (f < 0 || f >= 32) {
        return 0;
    }
    g = b->mUnk_19 * 37 + b->mUnk_1a;
    if (g >= 0x200) {
        return 0;
    }
    e = ((e & 0x3ffff) << 14) | ((f & 0x1f) << 9);
    *(u32 *) &d[0] = e | (g & 0x1ff);
    MemCopy(&b->mUnk_04, &d[4], 4);
    *(u16 *) &d[8] = 0;
    func_0204b284(d, 10, 1);
    x = 0xc3;
    for (h = 9; h >= 0; h--) {
        d[h] ^= x;
        x = d[h];
    }
    for (i = 0, n = 0; i < 16; i++) {
        k = 0;
        for (j = 0; j < 5; j++) {
            q = n;
            m = q + j;
            k = (u16) (k | ((d[(u8) (m / 8)] >> (u8) (7 - m % 8)) & 1)) << 1;
        }
        a[i] = data_usa_0215494c[(u8) (k / 2)];
        n += 5;
    }
    return 1;
}

s32 func_0205fdb4(s32 a, void *b) {
    Unk02056bc0 c;
    BOOL d;

    d = FALSE;
    if (func_02056bc0(a, 0, &c) != 0 && c.mUnk_18 != 0) {
        d = TRUE;
    }
    if (d == FALSE) {
        return 0;
    }
    return func_0205fe1c(b, &c, a);
}

s32 func_0205fd78(s32 a, s32 b, s32 *v1) {
    Unk02056a2c c;
    BOOL d;

    d = FALSE;
    func_020569dc(a, b, &c);
    if (c.mUnk_00 == 1) {
        d = TRUE;
        *v1 = c.mUnk_01;
    }
    return d;
}

u32 func_0205fd2c(Unk0205fd2c *a, u32 b, u32 c) {
    u8 d;
    u8 e;

    d = func_02056d98();
    e = a->mUnk_00->mUnk_06[c][b];
    if (e != 0 && e <= d) {
        return 1;
    }
    return 0;
}

BOOL func_0205fc98(Unk0205fd2c *a, u32 b, u32 c) {
    u8 d;
    u8 e;

    if (func_0205f218_inline() != FALSE) {
        d = data_0217aa08->mUnk_39;
    } else {
        d = func_02056d98();
    }
    e = a->mUnk_00->mUnk_06[c][b];
    if (e != 0 && e <= d) {
        return TRUE;
    }
    return FALSE;
}

s32 func_0205fc28(s32 a) {
    if (func_0205f218_inline() == FALSE) {
        return func_02056dec(a);
    }
    return func_02056e00(a, data_0217aa08->mUnk_30);
}

s32 func_0205fbb8(s32 a) {
    if (func_0205f218_inline() == FALSE) {
        return func_02056dec(a);
    }
    return func_02056e00(a, data_0217aa08->mUnk_34);
}

void func_0205fa00(u32 a, s32 *b, u32 c, u32 d) {
    Unk021759c0 *p;
    Unk0217aa08_20_04 e;
    u16 *f;
    u16 *g;
    u8 h;
    s32 r;

    p = data_021759c0;
    if (a == p->mEntryIndex) {
        return;
    }
    if (p->mCurrentEntries[a].mPlayer.mUnk_20 == 0) {
        return;
    }
    r = func_0206105c((const void *) p->mCurrentEntries[a].mPlayer.mUnk_20);
    if (r == -1) {
        return;
    }
    h = r;
    func_0205ee14(h, &e);
    if (e.mUnk_22_0 == 0) {
        func_02057624((u32) &e);
    }
    if (data_021759c0->mCurrentEntries[a].mPlayer.mName != NULL) {
        MemCopy(data_021759c0->mCurrentEntries[a].mPlayer.mName, e.mUnk_0e, 0x14);
    }
    switch (c) {
        case 0:
            f = &e.mUnk_00[0][0];
            g = &e.mUnk_00[0][1];
            break;
        case 1:
            f = &e.mUnk_00[1][0];
            g = &e.mUnk_00[1][1];
            break;
        case 2:
            f = &e.mUnk_00[2][0];
            g = &e.mUnk_00[2][1];
            break;
    }
    switch (d) {
        case 0:
            if (*f < 0xffff) {
                *f = *f + 1;
            }
            break;
        case 1:
            if (*g < 0xffff) {
                *g = *g + 1;
            }
            break;
    }
    e.mUnk_0c_0 = b[0];
    e.mUnk_0c_7 = b[1];
    e.mUnk_0c_11 = b[2];
    e.mUnk_22_0 = 1;
    func_0205ee74(h, &e);
}

static inline u32 func_0205f700_inline(u16 i, u32 a) {
    if (GetKartRank(i) > a) {
        return 0;
    }
    return 1;
}

void func_0205f700(void) {
    BOOL v1;
    u32 t;
    u16 i;
    u32 a;
    u32 d;
    u32 e;
    s32 c;
    s32 r;
    s32 v2[3];

    v1 = FALSE;
    c = -1;
    if (func_0205f218_inline() == FALSE) {
        return;
    }
    if (data_021759c0->mEntryIndex == -1) {
        return;
    }
    if (gRaceProgress->mUnk_000[(u16) data_021759c0->mEntryIndex].mStatus == 4) {
        return;
    }
    if (gRaceProgress->mRaceDone == 0) {
        return;
    }
    func_0203bfec(v2);
    a = GetKartRank((u16) data_021759c0->mEntryIndex);
    if (data_021759c0->mUseTeams != 0) {
        c = data_021759c0->mCurrentEntries[(u16) data_021759c0->mEntryIndex].mPlayer.mTeamIndex;
    }
    d = data_0217aa08->mUnk_00->mUnk_34[0];
    e = data_0217aa08->mUnk_00->mUnk_34[1];
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        if (i == data_021759c0->mEntryIndex) {
            continue;
        }
        r = data_021759c0->mCurrentEntries[i].mPlayer.mKind;
        if (r == 1 || r == 4 || r == 2) {
            continue;
        }
        if (data_021759c0->mUseTeams != 0) {
            if (c == data_021759c0->mCurrentEntries[i].mPlayer.mTeamIndex) {
                t = 2;
            } else {
                switch (data_021759c0->mUnk_1c) {
                    case 0:
                    case 2:
                        t = func_0205f700_inline(i, a);
                        break;
                    case 1:
                        if (c == func_0205d480()) {
                            t = 0;
                        } else if (gRaceProgress->mUnk_000[i].mStatus == 4) {
                            t = 2;
                        } else {
                            t = 1;
                        }
                        break;
                }
            }
        } else {
            t = func_0205f700_inline(i, a);
        }
        if ((data_0217aa00->mUnk_0457 & (1 << data_0217aa00->mUnk_1e8c[data_0217aa00->mUnk_1e8c[i]])) == 0) {
            func_0205fa00(i, v2, 0, t);
        }
        if (t == 0) {
            if (d < data_usa_021653e0) {
                d++;
                v1 = TRUE;
            }
        } else if (t == 1) {
            if (e < data_usa_021653e0) {
                e++;
                v1 = TRUE;
            }
        }
    }
    if (v1 != FALSE) {
        data_0217aa08->mUnk_00->mUnk_34[0] = d;
        data_0217aa08->mUnk_00->mUnk_34[1] = e;
        func_0205edcc();
    } else {
        func_0205edf8();
    }
}

void func_0205f498(void) {
    u16 i;
    u32 a;
    u32 b;
    BOOL v1;
    u32 t;
    s32 r;
    s32 v2[5];

    v1 = FALSE;
    if (func_0205f218_inline() == FALSE) {
        return;
    }
    if (data_021759c0->mEntryIndex == -1) {
        return;
    }
    if (gRaceProgress->mUnk_000[(u16) data_021759c0->mEntryIndex].mStatus == 4) {
        return;
    }
    if (func_020a128c() == 0) {
        return;
    }
    func_0203bfec(v2);
    a = data_0217aa08->mUnk_00->mUnk_34[2];
    b = data_0217aa08->mUnk_00->mUnk_34[3];
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        if (i == data_021759c0->mEntryIndex) {
            continue;
        }
        r = data_021759c0->mCurrentEntries[i].mPlayer.mKind;
        if (r == 1 || r == 4 || r == 2) {
            continue;
        }
        t = 2;
        if (func_020a100c((u16) data_021759c0->mEntryIndex) != 0) {
            if (func_020a100c(i) == 0) {
                t = 0;
            }
        } else if (func_020a100c(i) != 0) {
            if (gRaceProgress->mUnk_000[i].mStatus != 4) {
                t = 1;
            }
        }
        if ((data_0217aa00->mUnk_0457 & (1 << data_0217aa00->mUnk_1e8c[data_0217aa00->mUnk_1e8c[i]])) == 0) {
            func_0205fa00(i, v2, 1, t);
        }
        if (t == 0) {
            if (a < data_usa_021653e0) {
                v1 = TRUE;
                a++;
            }
        } else if (t == 1) {
            if (b < data_usa_021653e0) {
                v1 = TRUE;
                b++;
            }
        }
    }
    if (v1 != FALSE) {
        data_0217aa08->mUnk_00->mUnk_34[2] = a;
        data_0217aa08->mUnk_00->mUnk_34[3] = b;
        func_0205edcc();
    } else {
        func_0205edf8();
    }
}

void func_0205f218(void) {
    u16 i;
    u32 a;
    u32 b;
    BOOL v1;
    u32 t;
    s32 r;
    s32 v2[5];

    v1 = FALSE;
    if (func_0205f218_inline() == FALSE) {
        return;
    }
    if (data_021759c0->mEntryIndex == -1) {
        return;
    }
    if (gRaceProgress->mUnk_000[(u16) data_021759c0->mEntryIndex].mStatus == 4) {
        return;
    }
    if (func_020a128c() == 0) {
        return;
    }
    func_0203bfec(v2);
    GetKartRank((u16) data_021759c0->mEntryIndex);
    a = data_0217aa08->mUnk_00->mUnk_34[2];
    b = data_0217aa08->mUnk_00->mUnk_34[3];
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        if (i == data_021759c0->mEntryIndex) {
            continue;
        }
        r = data_021759c0->mCurrentEntries[i].mPlayer.mKind;
        if (r == 1 || r == 4 || r == 2) {
            continue;
        }
        t = 2;
        if (func_020a100c((u16) data_021759c0->mEntryIndex) != 0) {
            if (func_020a100c(i) == 0) {
                t = 0;
            }
        } else if (func_020a100c(i) != 0) {
            if (gRaceProgress->mUnk_000[i].mStatus != 4) {
                t = 1;
            }
        }
        if ((data_0217aa00->mUnk_0457 & (1 << data_0217aa00->mUnk_1e8c[data_0217aa00->mUnk_1e8c[i]])) == 0) {
            func_0205fa00(i, v2, 1, t);
        }
        if (t == 0) {
            if (a < data_usa_021653e0) {
                v1 = TRUE;
                a++;
            }
        } else if (t == 1) {
            if (b < data_usa_021653e0) {
                v1 = TRUE;
                b++;
            }
        }
    }
    if (v1 != FALSE) {
        data_0217aa08->mUnk_00->mUnk_34[2] = a;
        data_0217aa08->mUnk_00->mUnk_34[3] = b;
        func_0205edcc();
    } else {
        func_0205edf8();
    }
}

static inline u16 func_0205ef70_inline(u16 a) {
    s32 b;
    s32 c;
    s32 d;
    Unk0217aa1c_00 *p;

    b = func_0205dc7c(a);
    c = func_0205db28();
    d = func_0205dc7c(b);
    p = &data_0217aa1c->mUnk_000[c][0];
    p += d;
    return p->mUnk_00;
}

void func_0205ef70(void) {
    u16 i;
    s32 c;
    u32 a;
    u32 b;
    u32 g;
    u16 h;
    u32 t;
    s8 m;
    s32 v1[3];

    a = data_0217aa08->mUnk_00->mUnk_34[4];
    b = data_0217aa08->mUnk_00->mUnk_34[5];
    func_0205b32c();
    if (data_021759c0->mCourseNumber <= 3) {
        return;
    }
    if (gRaceProgress->mRaceDone == 0) {
        return;
    }
    if (gRaceProgress->mUnk_000[(u16) data_021759c0->mEntryIndex].mStatus == 4) {
        return;
    }
    func_0203bfec(v1);
    c = func_0205d4e8((u16) data_021759c0->mEntryIndex);
    h = func_0205ef70_inline(data_021759c0->mEntryIndex);
    m = gWiFiSession->mKartCountCopy - 1;
    g = gWiFiSession->mKartCountCopy;
    if (m > 0) {
        if (b < m) {
            b = 0;
        } else {
            b -= m;
        }
    }
    if ((s16) (g - data_021759c0->mKartCount) > 0) {
        a += (s16) (g - data_021759c0->mKartCount);
        if (a > data_usa_021653e0) {
            a = data_usa_021653e0;
        }
    }
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        t = 2;
        if (i != data_021759c0->mEntryIndex) {
            if (c < func_0205d4e8(i)) {
                t = 0;
            } else if (c > func_0205d4e8(i)) {
                t = 1;
            }
            if (h == func_0205ef70_inline(i)) {
                t = 2;
            }
            func_0205fa00(i, v1, 2, t);
            if (t == 0) {
                if (a < data_usa_021653e0) {
                    a++;
                }
            } else if (t == 1) {
                if (b < data_usa_021653e0) {
                    b++;
                }
            }
        }
    }
    data_0217aa08->mUnk_00->mUnk_24 = func_02120220(func_ov000_0219bb50());
    data_0217aa08->mUnk_00->mUnk_34[4] = a;
    data_0217aa08->mUnk_00->mUnk_34[5] = b;
    func_0205edcc();
}

void func_0205eeb0(void) {
    if (data_021759c0->mUnk_00c == 0) {
        switch (data_021759c0->mMode) {
            case 3:
                func_0205f700();
                break;
            case 4:
                func_0203b230();
                break;
            case 2:
                switch (data_021759c0->mUnk_18) {
                    case 0:
                        func_0205f498();
                        break;
                    case 1:
                        func_0205f218();
                        break;
                }
                break;
            case 5:
                func_0205ef70();
                break;
        }
    }
}

void func_0205ee74(u32 a, void *b) {
    MemCopy(b, &data_0217aa08->mUnk_20->mUnk_04[a], 0x24);
}

u32 func_0205ee14(u32 a, void *b) {
    if (b != NULL) {
        MemCopy(&data_0217aa08->mUnk_20->mUnk_04[a], b, 0x24);
    }
    return data_0217aa08->mUnk_20->mUnk_04[a].mUnk_22_0 != 0;
}

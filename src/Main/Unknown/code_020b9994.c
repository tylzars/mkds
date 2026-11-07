#include "Main/Unknown/code_020b9994.h"

#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_0204a550.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020b85dc.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020a2204.h"
#include "Main/Unknown/code_020a10d4.h"
#include "Main/Unknown/code_020a1000.h"
#include "01/code_0218155c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_0204a000.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020ba50c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020b846c.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020bb530.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"

void func_020bb530(void) {
    Unk0217b3cc *p;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x2c);
    data_0217b3cc = p;
    p->mUnk_00 = 0;
    data_0217b3cc->mUnk_04 = 0;
    data_0217b3cc->mUnk_08 = 0x13;
    data_0217b3cc->mUnk_0c = 0x13;
    data_0217b3cc->mUnk_10 = 0;
    data_0217b3cc->mUnk_14 = 0;
    data_0217b3cc->mUnk_18.mUnk_00 = 0;
    data_0217b3cc->mUnk_18.mUnk_04 = 0x1000;
    data_0217b3cc->mUnk_18.mUnk_08 = 0x1000;
    data_0217b3cc->mUnk_18.mUnk_0c = -0x666;
    data_0217b3cc->mUnk_18.mUnk_10 = 0x800;
}

u32 func_020bb51c(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b3cc;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

static inline KartItems *func_020bab54_inline(u32 o) {
    return (KartItems *) ((u32) gKartItems + o);
}

void func_020bab54(void) {
    s32 e;
    u32 i;
    s32 n;
    s32 v;
    s32 s;
    u32 k;
    NNSSndSeqPlayer **r;
    NNSSndSeqPlayer **r2;
    u32 k2;
    Unk0217b3cc_18 *w;
    KartItems *c;

    n = data_0217b3cc->mUnk_04;
    i = GetFollowedKartOrEntryIndex() * 0x210;
    e = func_020bab54_inline(i)->mUnk_028;
    data_0217b3cc->mUnk_14 = data_0217b3cc->mUnk_10;
    v = 0x13;
    c = func_020bab54_inline(i);
    if (c->mSlotState == 1) {
        data_0217b3cc->mUnk_04 = c->mSlotFrames;
        n = data_0217b3cc->mUnk_04;
        data_0217b3cc->mUnk_10 = 1;
    } else if (n == 0) {
        data_0217b3cc->mUnk_10 = 0;
    } else if (n > 0 && n < 0xd6) {
        data_0217b3cc->mUnk_04 += 1;
        n = data_0217b3cc->mUnk_04;
        switch (n) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 8:
            case 10:
            case 12:
            case 14:
            case 16:
            case 18:
            case 22:
            case 26:
            case 30:
            case 34:
            case 38:
            case 42:
            case 46:
            case 50:
            case 54:
            case 58:
            case 62:
            case 66:
            case 70:
            case 74:
            case 78:
            case 86:
            case 94:
            case 102:
            case 110:
            case 118:
            case 134:
            case 150:
            case 166:
            case 182:
            case 198:
            case 214:

                data_0217b3cc->mUnk_04 = 0xd6;
                n = data_0217b3cc->mUnk_04;
                break;
        }
        data_0217b3cc->mUnk_10 = 1;
    } else if (n >= 0xd6 && n < e + 0xd5) {
        data_0217b3cc->mUnk_04 += 1;
        n = data_0217b3cc->mUnk_04;
        data_0217b3cc->mUnk_10 = 1;
    } else {
        NNS_SndPlayerStopSeq(func_02108e88(), 0);
        data_0217b3cc->mUnk_04 = 0;
        n = data_0217b3cc->mUnk_04;
        if (func_020bab54_inline(i)->mSlotShownItem >= 9) {
            if (gRaceSetup->mRaceKind != 2) {
                k = 0x40;
                if (gRaceSetup->mCourseId == COURSE_ID_PINBALL) {
                    k = 0x1c6;
                }
                if ((data_0217c780 & 1) != 0) {
                    r = func_0210e128(func_02108ea0(0));
                    if (data_0217d084.mUnk_0c != 0) {
                        if (*r != NULL) {
                            NNS_SndPlayerStopSeq(r, 0);
                        }
                        if (*r != NULL) {
                            NNS_SndPlayerStopSeq(r, 0);
                        }
                        NNS_SndArcPlayerStartSeqArc(r, 0, k);
                    }
                }
            }
        } else {
            if (gRaceSetup->mRaceKind != 2) {
                k = 0x3f;
                if (gRaceSetup->mCourseId == COURSE_ID_PINBALL) {
                    k = 0x1c5;
                }
                if ((data_0217c780 & 1) != 0) {
                    r = func_0210e128(func_02108ea0(0));
                    if (data_0217d084.mUnk_0c != 0) {
                        if (*r != NULL) {
                            NNS_SndPlayerStopSeq(r, 0);
                        }
                        if (*r != NULL) {
                            NNS_SndPlayerStopSeq(r, 0);
                        }
                        NNS_SndArcPlayerStartSeqArc(r, 0, k);
                    }
                }
            }
        }
        data_0217b3cc->mUnk_10 = 0;
    }
    if (data_0217b3cc->mUnk_14 == 0 && data_0217b3cc->mUnk_10 != 0 && gRaceSetup->mRaceKind != 2) {
        r2 = func_02108e88();
        k2 = 0x3e;
        if (gRaceSetup->mCourseId == COURSE_ID_PINBALL) {
            k2 = 0x1c4;
        }
        if ((data_0217c780 & 1) != 0) {
            if (data_0217d084.mUnk_0c != 0) {
                if (*r2 != NULL) {
                    NNS_SndPlayerStopSeq(r2, 0);
                }
                if (*r2 != NULL) {
                    NNS_SndPlayerStopSeq(r2, 0);
                }
                NNS_SndArcPlayerStartSeqArc(r2, 0, k2);
            }
        }
    }
    c = func_020bab54_inline(i);
    if (c->mSlotState == 0) {
        data_0217b3cc->mUnk_0c = c->mHeldItem.mUnk_00 == 0x13 ? c->mActiveItem : c->mHeldItem.mUnk_00;
    } else {
        switch (n) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 8:
            case 10:
            case 12:
            case 14:
            case 16:
            case 18:
            case 22:
            case 26:
            case 30:
            case 34:
            case 38:
            case 42:
            case 46:
            case 50:
            case 54:
            case 58:
            case 62:
            case 66:
            case 70:
            case 74:
            case 78:
            case 86:
            case 94:
            case 102:
            case 110:
            case 118:
            case 134:
            case 150:
            case 166:
            case 182:
            case 198:
            case 214:

                data_0217b3cc->mUnk_0c = c->mSlotShownItem;
                PickItemSlotShownItem(func_020bab54_inline(i));
                break;
        }
        v = func_020bab54_inline(i)->mSlotShownItem;
        data_0217b3cc->mUnk_18.mUnk_00 = 0;
    }
    if (n < 6) {
        s = 0;
    } else if (n < 0x12) {
        s = ((n - 6) & 1) << 5 >> 1;
    } else if (n < 0x4e) {
        s = ((n - 0x12) & 3) << 5 >> 2;
    } else if (n < 0x76) {
        s = ((n - 0x4e) & 7) << 5 >> 3;
    } else if (n < 0xd6) {
        s = ((n - 0x76) & 0xf) << 5 >> 4;
    } else if (n >= e + 0xd6) {
        s = 0;
    } else {
        s = ((n - 0xd6) & ((s32) func_020bab54_inline(i)->mUnk_028 - 1)) << 5 >> func_020bab54_inline(i)->mUnk_02c;
    }
    if (data_0217b3cc->mUnk_18.mUnk_00 != 0) {
        w = &data_0217b3cc->mUnk_18;
        w->mUnk_08 += w->mUnk_0c;
        w->mUnk_0c += (s32) (((s64) (w->mUnk_10 - w->mUnk_08) * 0x333) >> 12);
        w->mUnk_0c = ((s64) w->mUnk_0c * 0xc00) >> 12;
        w->mUnk_04 = (s32) (((s64) w->mUnk_10 * 0x2000) >> 12) - w->mUnk_08;
        data_0217b3cc->mUnk_18.mUnk_00 += 1;
        if (data_0217b3cc->mUnk_18.mUnk_10 == 0xb33 && data_0217b3cc->mUnk_18.mUnk_00 > 7) {
            data_0217b3cc->mUnk_18.mUnk_10 = 0x1000;
        } else if (data_0217b3cc->mUnk_18.mUnk_10 == 0x1000 && data_0217b3cc->mUnk_18.mUnk_00 > 10) {
            data_0217b3cc->mUnk_18.mUnk_00 = 0;
        }
    }
    if (func_020bab54_inline(i)->mUnk_204 != FALSE) {
        s32 q;
        q = func_020bab54_inline(i)->mHeldItem.mUnk_00 == 0x13 ? func_020bab54_inline(i)->mActiveItem
                                                               : func_020bab54_inline(i)->mHeldItem.mUnk_00;
        if (q == 0xd) {
            data_0217b3cc->mUnk_18.mUnk_00 += 1;
            data_0217b3cc->mUnk_18.mUnk_04 = 0x1000;
            data_0217b3cc->mUnk_18.mUnk_08 = 0x1000;
            data_0217b3cc->mUnk_18.mUnk_0c = -0x19a;
            data_0217b3cc->mUnk_18.mUnk_10 = 0xb33;
        }
    }
    data_0217b3cc->mUnk_00 = s;
    data_0217b3cc->mUnk_08 = v;
}

void func_020ba63c(Unk020d029c *p) {
    s32 a[2];
    s32 b[2];
    s32 c[2];
    s32 d[2];
    s32 e[2];
    s32 f[2];
    s32 g[2];
    s32 h[2];
    s32 w[4];
    s32 x;
    s32 y;
    Unk020224e0_c *t;
    Unk020224e0_c *r;
    s32 l;
    Unk020224e0_o *q;
    Unk020224e0_o *o;
    u16 k;

    x = data_0217b3cc->mUnk_00;
    y = data_0217b3cc->mUnk_08;
    r = GetRaceMNcerEntry(gRaceSetup->mUseTeams == 0                                                           ? 8
                          : gRaceSetup->mCurrentEntries[GetFollowedKartOrEntryIndex()].mPlayer.mTeamIndex == 0 ? 9
                                                                                                               : 10);
    if (gRaceSetup->mRaceKind == 4) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    t = GetRaceMNcerEntry(0xc);
    a[0] = 0x18000;
    a[1] = 0x18000;
    p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, a, 0, 1);
    l = p->mUnk_400;
    b[0] = 0x18000;
    b[1] = 0x18000;
    q = &p->mUnk_000[l];
    p->mUnk_400 += NNS_G2dMakeCellToOams(q, 0x80 - l, r, NULL, b, 0, 1);
    for (; l < p->mUnk_400; l++, q++) {
        ((u32 *) q)[0] = (((u32 *) q)[0] & ~0xc00) | 0x800;
        ((u32 *) q)[1] = (((u32 *) q)[1] & ~0xc00) | 0x400;
    }
    l = p->mUnk_400;
    c[0] = 0x18000;
    c[1] = 0x18000;
    q = &p->mUnk_000[l];
    p->mUnk_400 += NNS_G2dMakeCellToOams(q, 0x80 - l, r, NULL, c, 0, 1);
    for (; l < p->mUnk_400; l++, q++) {
        ((u32 *) q)[1] = (((u32 *) q)[1] & ~0xc00) | 0x400;
    }
    if (data_0217b3cc->mUnk_18.mUnk_00 == 0) {
        t = GetRaceMNcerEntry(LookupRaceMNcerIndex(y));
        d[0] = 0x18000;
        d[1] = (x - 8) << 12;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, d, 0, 1);
        t = GetRaceMNcerEntry(LookupRaceMNcerIndex(data_0217b3cc->mUnk_0c));
        e[0] = 0x18000;
        e[1] = (x + 0x18) << 12;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, e, 0, 1);
    } else {
        k = func_020ae5c4(p);
        w[0] = FX_Div(0x1000, data_0217b3cc->mUnk_18.mUnk_04);
        w[1] = 0;
        w[2] = 0;
        w[3] = FX_Div(0x1000, data_0217b3cc->mUnk_18.mUnk_08);
        t = GetRaceMNcerEntry(LookupRaceMNcerIndex(y));
        l = p->mUnk_400;
        f[0] = 0x18000;
        f[1] = (x - 8) << 12;
        q = &p->mUnk_000[l];
        p->mUnk_400 += NNS_G2dMakeCellToOams(q, 0x80 - l, t, w, f, k, 1);
        for (; l < p->mUnk_400; l++, q++) {
            ((u32 *) q)[1] = (((u32 *) q)[1] & ~0xc00) | 0x400;
        }
        t = GetRaceMNcerEntry(LookupRaceMNcerIndex(data_0217b3cc->mUnk_0c));
        l = p->mUnk_400;
        g[0] = 0x18000;
        g[1] = (x + 0x18) << 12;
        q = &p->mUnk_000[l];
        p->mUnk_400 += NNS_G2dMakeCellToOams(q, 0x80 - l, t, w, g, k, 1);
        for (; l < p->mUnk_400; l++, q++) {
            ((u32 *) q)[1] = (((u32 *) q)[1] & ~0xc00) | 0x400;
        }
        o = &p->mUnk_000[k * 4];
        o[0].mUnk_00[3] = w[0] >> 4;
        o[1].mUnk_00[3] = w[1] >> 4;
        o[2].mUnk_00[3] = w[2] >> 4;
        o[3].mUnk_00[3] = w[3] >> 4;
    }
    t = GetRaceMNcerEntry(0xb);
    h[0] = 0x18000;
    h[1] = 0x18000;
    p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, h, 0, 1);
}

s32 func_020ba620(void) {
    if (data_0217b3c8 != NULL) {
        return data_0217b3c8->mUnk_08;
    }
    return 0;
}

void func_020ba520(void) {
    Unk0217b3c8 *q;
    s32 v;

    q = HeapAlloc(GetHeap(func_020364e8()), 0xc);
    data_0217b3c8 = q;
    v = gRaceSetup->mMode;
    switch (v) {
        case MODE_MISSION_RUN:
            data_0217b3c8->mUnk_00 = v == MODE_MISSION_RUN ? GetMissionRunCount() : 0;
            data_0217b3c8->mUnk_04 = gRaceSetup->mUnk_37;
            break;
        case MODE_BATTLE:
            switch (gRaceSetup->mBattleKind) {
                case BATTLE_KIND_BALLOON:
                    q->mUnk_00_h[0] = 0;
                    data_0217b3c8->mUnk_00_h[1] = func_020a10d4(GetFollowedKartOrEntryIndex());
                    break;
                case BATTLE_KIND_SHINE:
                default:
                    data_0217b3c8->mUnk_00_h[0] = GetBalloonOrShineCount(GetFollowedKartOrEntryIndex());
                    break;
            }
            break;
        case MODE_TIME_ATTACK:
            break;
        default:
            data_0217b3c8->mUnk_00 = GetKartRank(GetFollowedKartOrEntryIndex()) - 1;
            break;
    }
    data_0217b3c8->mUnk_08 = 1;
}

u32 func_020ba50c(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b3c8;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_020ba3ec(void) {
    s32 v;

    v = gRaceSetup->mMode;
    switch (v) {
        case MODE_MISSION_RUN:
            data_0217b3c8->mUnk_00 = v == MODE_MISSION_RUN ? GetMissionRunCount() : 0;
            break;
        case MODE_BATTLE:
            if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
                if (func_020a2204(GetFollowedKartOrEntryIndex()) != 0) {
                    data_0217b3c8->mUnk_00_h[0] += 1;
                    if (data_0217b3c8->mUnk_00_h[0] >= 9) {
                        data_0217b3c8->mUnk_00_h[0] = 0;
                    }
                } else {
                    data_0217b3c8->mUnk_00_h[0] = 0;
                }
                data_0217b3c8->mUnk_00_h[1] = func_020a10d4(GetFollowedKartOrEntryIndex());
            } else {
                data_0217b3c8->mUnk_00_h[0] = GetBalloonOrShineCount(GetFollowedKartOrEntryIndex());
            }
            break;
        case MODE_TIME_ATTACK:
            break;
        default:
            data_0217b3c8->mUnk_00 = GetKartRank(GetFollowedKartOrEntryIndex()) - 1;
            break;
    }
}

void func_020b9dfc(Unk020d029c *p) {
    s32 a[2];
    s32 b[2];
    s32 c[2];
    s32 d[2];
    s32 e[2];
    s32 f[2];
    s32 g[2];
    s32 h[2];
    s32 j[2];
    u16 k;
    u16 n;
    s32 i;
    s32 l;
    Unk020224e0_o *q;
    Unk020224e0_c *t;

    if (gRaceSetup->mRaceKind == 4) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    switch (gRaceSetup->mMode) {
        case MODE_MISSION_RUN:
            func_020b9994(p);
            return;
        case MODE_BATTLE:
            if (IsKartEnded(GetFollowedKartOrEntryIndex()) == 0) {
                if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
                    i = 0;
                    n = data_0217b3c8->mUnk_00_h[1];
                    k = data_0217b3c8->mUnk_00_h[0];
                    for (; i < n; i++) {
                        t = GetRaceBattleMNcerEntry(10);
                        b[0] = (0xfe - i * 0xe) << 12;
                        b[1] = 0xc000;
                        p->mUnk_400 +=
                            NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, b, 0, 1);
                    }
                    if (k == 0) {
                        return;
                    }
                    if (k >= 6) {
                        return;
                    }
                    t = GetRaceBattleMNcerEntry(10);
                    c[0] = (0xfe - i * 0xe) << 12;
                    c[1] = 0xc000;
                    p->mUnk_400 +=
                        NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, c, 0, 1);
                } else {
                    i = GetRaceStartSequenceFrames() % 16;
                    if (func_020a1048(GetFollowedKartOrEntryIndex()) != 0 && i >= 10) {
                        return;
                    }
                    n = data_0217b3c8->mUnk_00_h[0];
                    t = GetRaceBattleMNcerEntry(0xb);
                    d[0] = 0xcd000;
                    d[1] = 0xf000;
                    p->mUnk_400 +=
                        NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, d, 0, 1);
                    t = GetRaceBattleMNcerEntry(n / 10);
                    e[0] = 0xe1000;
                    e[1] = 0x10000;
                    p->mUnk_400 +=
                        NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, e, 0, 1);
                    t = GetRaceBattleMNcerEntry(n % 10);
                    f[0] = 0xf0000;
                    f[1] = 0x10000;
                    p->mUnk_400 +=
                        NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, f, 0, 1);
                }
            } else {
                if (gRaceProgress->mUnk_000[GetFollowedKartOrEntryIndex()].mStatus != 2) {
                    return;
                }
                if ((GetKart(GetFollowedKartOrEntryIndex())->mUnk_7c & 0x402000) == 0) {
                    return;
                }
                t = GetRaceBattleMNcerEntry(0xc);
                a[0] = 0x80000;
                a[1] = 0x60000;
                p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, a, 0, 1);
            }
            break;
        case MODE_TIME_ATTACK:
            if (data_02175628[0].mSourceKind != 2) {
                return;
            }
            if (func_0204a650(&data_02175650[0]) == FALSE) {
                return;
            }
            data_0217b3c8->mUnk_08 = 0;
            t = GetRaceTaMNcerEntry(0xd);
            l = p->mUnk_400;
            g[0] = 0x80000;
            g[1] = 0x60000;
            q = &p->mUnk_000[l];
            p->mUnk_400 += NNS_G2dMakeCellToOams(q, 0x80 - l, t, NULL, g, 0, 1);
            for (; l < p->mUnk_400; l++, q++) {
                ((u32 *) q)[0] = (((u32 *) q)[0] & ~0xc00) | 0x800;
                ((u32 *) q)[1] = (((u32 *) q)[1] & ~0xc00) | 0x400;
            }
            t = GetRaceTaMNcerEntry(0xd);
            h[0] = 0x80000;
            h[1] = 0x60000;
            p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, h, 0, 1);
            break;
        default:
            t = GetRaceMNcerEntry(data_0217b3c8->mUnk_00);
            j[0] = 0x18000;
            j[1] = 0xa8000;
            p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, j, 0, 1);
            break;
    }
}

void func_020b9994(Unk020d029c *p) {
    s32 a[2];
    s32 b[2];
    s32 c[2];
    s32 d[2];
    s32 e[2];
    s32 f[2];
    s32 g[2];
    s32 h[2];
    s32 i[2];
    s32 m;
    s32 n;
    Unk0217b3c8 *q;
    Unk020224e0_c *t;

    q = data_0217b3c8;
    n = q->mUnk_04;
    if (n <= 0) {
        return;
    }
    m = q->mUnk_00;
    if (m > n) {
        m = n;
    }
    t = GetRaceMrMNcerEntry(0x15);
    a[0] = 0xc000;
    a[1] = 0xb0000;
    p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, a, 0, 1);
    if (data_0217b3c8->mUnk_04 >= 10) {
        t = GetRaceMrMNcerEntry(m / 10);
        b[0] = 0x1b000;
        b[1] = 0xb4000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, b, 0, 1);
        t = GetRaceMrMNcerEntry(m % 10);
        c[0] = 0x2e000;
        c[1] = 0xb4000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, c, 0, 1);
        t = GetRaceMrMNcerEntry(10);
        d[0] = 0x42000;
        d[1] = 0xb4000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, d, 0, 1);
        t = GetRaceMrMNcerEntry(n / 10 + 0xb);
        e[0] = 0x4d000;
        e[1] = 0xb4000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, e, 0, 1);
        t = GetRaceMrMNcerEntry(n % 10 + 0xb);
        f[0] = 0x5b000;
        f[1] = 0xb4000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, f, 0, 1);
    } else {
        t = GetRaceMrMNcerEntry(m % 10);
        g[0] = 0x1b000;
        g[1] = 0xb4000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, g, 0, 1);
        t = GetRaceMrMNcerEntry(10);
        h[0] = 0x2f000;
        h[1] = 0xb4000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, h, 0, 1);
        t = GetRaceMrMNcerEntry(n % 10 + 0xb);
        i[0] = 0x3a000;
        i[1] = 0xb4000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, i, 0, 1);
    }
}

#include "Main/Unknown/code_020c7464.h"

#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020daf20.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_02100094.h"
#include "code_020222ec.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b4dc4.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020fd83c.h"
#include "Main/Unknown/code_021001a0.h"
#include "Main/Unknown/code_02100de4.h"
#include "Main/Unknown/unk_02169000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

// Indices into gItemKinds and gItemPools.
s32 gRaceHudSubScreenItemPoolIndices[10] = {0, 1, 2, 3, 4, 5, 9, 7, 8, 11};

void UpdateRaceHudSubScreenCrabCells(void) {
    s32 i;
    s32 n;
    u32 v;

    n = 0;
    v = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenCrabCells->mObjectCount; i++) {
        Unk0217b498_00 *p;

        p = gRaceHudSubScreenCrabCells->mObjects[i];
        if (!(p->mFlags & 1)) {
            if (ComputeRaceHudSubScreenPosition(&p->mPos, &gRaceHudSubScreenCrabCells->mCells[n].mDrawPos, v, 1, 1)) {
                gRaceHudSubScreenCrabCells->mCells[n].mCell = GetRaceSNcerEntry(0x8a);
                gRaceHudSubScreenCrabCells->mCells[n].mUnk_0c = 2;
                n++;
            }
        }
    }
    gRaceHudSubScreenCrabCells->mCellCount = n;
}

void DrawRaceHudSubScreenCrabCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenCrabCells, 0);
}

s32 CreateRaceHudSubScreenItemCells(void) {
    s32 a;
    s32 i;

    a = 0;
    for (i = 0; i < 10; i++) {
        a += gItemKinds[gRaceHudSubScreenItemPoolIndices[i]].mObjectCount;
    }
    return CreateRaceHudSubScreenCellsWithCount(&gRaceHudSubScreenItemCells, a);
}

void ClearRaceHudSubScreenItemCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenItemCells);
}

void UpdateRaceHudSubScreenItemCells(void) {
    enum { K0 } t;
    s32 n;
    s32 a;
    s32 k;
    s32 j;
    ItemPool *e;
    ItemObject **v1;
    s32 v2;
    Unk020224e0_c *c;
    ItemObject *p;
    Vec3 *q;
    s32 v;

    n = 0;
    a = func_020c0db0();
    for (k = 0; k < 10; k++) {
        t = gRaceHudSubScreenItemPoolIndices[k];
        e = &gItemPools[t];
        v1 = e->mObjects;
        v2 = e->mActiveCount;
        {
            s32 v3[10] = {0x4c, 0x4d, 0x4b, 0x4f, 0x50, 0x56, 0x55, 0x54, 0x4e, 0x57};

            c = GetRaceSNcerEntry(v3[k]);
        }
        for (j = 0; j < v2; j++) {
            p = v1[j];
            if ((p->mFlags & 0x80000) != 0) {
                q = NULL;
            } else {
                q = &p->mPos;
            }
            if (k == 9) {
                if (q != NULL) {
                    if (ComputeRaceHudSubScreenPosition(q, &gRaceHudSubScreenItemCells->mCells[n].mDrawPos, a, 1, 1) !=
                        FALSE) {
                        if (p->mUnk_d8 > 0) {
                            v = ((ItemTeresa *) p)->mUnk_170;
                            gRaceHudSubScreenItemCells->mCells[n].mDrawPos.mUnk_04 -= 0x88 * v / func_021001a0();
                            if (gRaceHudSubScreenItemCells->mCells[n].mDrawPos.mUnk_04 > 0) {
                                gRaceHudSubScreenItemCells->mCells[n].mCell = c;
                                gRaceHudSubScreenItemCells->mCells[n].mUnk_0c = func_020b4e70(q) != 0 ? 2 : 3;
                                gRaceHudSubScreenItemCells->mCells[n].mUnk_0e = 0;
                                n++;
                            }
                        }
                    }
                }
            } else if (k == 6) {
                if (((ItemBomb *) p)->mUnk_1a0 != FALSE && q != NULL) {
                    if (ComputeRaceHudSubScreenPosition(q, &gRaceHudSubScreenItemCells->mCells[n].mDrawPos, a, 1, 1) !=
                        FALSE) {
                        if (func_020d3d10(q->y) == 0) {
                            gRaceHudSubScreenItemCells->mCells[n].mCell = c;
                            gRaceHudSubScreenItemCells->mCells[n].mUnk_0c = func_020b4e70(q) != 0 ? 2 : 3;
                            gRaceHudSubScreenItemCells->mCells[n].mUnk_0e = (p->mFlags & 0x40000) != 0 ? 1 : 0;
                            n++;
                        }
                    }
                }
            } else {
                if (q != NULL) {
                    if (ComputeRaceHudSubScreenPosition(q, &gRaceHudSubScreenItemCells->mCells[n].mDrawPos, a, 1, 1) !=
                        FALSE) {
                        if (func_020d3d10(q->y) == 0) {
                            gRaceHudSubScreenItemCells->mCells[n].mCell = c;
                            gRaceHudSubScreenItemCells->mCells[n].mUnk_0c = func_020b4e70(q) != 0 ? 2 : 3;
                            gRaceHudSubScreenItemCells->mCells[n].mUnk_0e = (p->mFlags & 0x40000) != 0 ? 1 : 0;
                            n++;
                        }
                    }
                }
            }
        }
    }
    gRaceHudSubScreenItemCells->mCellCount = n;
}

void DrawRaceHudSubScreenItemCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenItemCells, 0);
}

s32 CreateRaceHudSubScreenKarts(void) {
    s32 i;

    gRaceHudSubScreenKarts = HeapAlloc(GetHeap(func_020364e8()), 0x194);
    CreateRaceHudSubScreenCellsWithCount(&gRaceHudSubScreenKarts->mUnk_190, 0x18);
    for (i = 0; i < 8; i++) {
        gRaceHudSubScreenKarts->mUnk_000[i] = 0;
        gRaceHudSubScreenKarts->mUnk_020[i] = 0;
        gRaceHudSubScreenKarts->mUnk_060[i].mUnk_00 = 0;
        gRaceHudSubScreenKarts->mUnk_060[i].mUnk_04 = 0;
        gRaceHudSubScreenKarts->mUnk_100[i] = 0;
        gRaceHudSubScreenKarts->mUnk_130[i] = 0;
    }
    return 1;
}

void ClearRaceHudSubScreenKarts(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenKarts->mUnk_190);
    gRaceHudSubScreenKarts = NULL;
}

void UpdateRaceHudSubScreenKarts(void) {
    s32 v1[8];
    u32 a;
    u16 i;
    Vec3 v;
    Vec3 w;
    Vec3 t;
    ItemObject **v2;
    s32 v3;
    s32 m;
    s32 j;
    s32 f;
    ItemObject *o;
    Vec3 *q;
    u32 b;
    ItemInUse *s;
    s32 x;
    s32 y;

    a = func_020c0db0();
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        gRaceHudSubScreenKarts->mUnk_000[i] = 0;
        gRaceHudSubScreenKarts->mUnk_130[i] = i;
        v1[i] = GetKartRank(i & 0xff);
    }
    switch (GetRaceHudSubScreenState()) {
        case 0:
            for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
                func_020b6078(i, &gRaceHudSubScreenKarts->mUnk_060[i]);
                x = gRaceHudSubScreenKarts->mUnk_060[i].mUnk_00;
                y = gRaceHudSubScreenKarts->mUnk_060[i].mUnk_04;
                if (x > -0x10 && x < 0x110 && y > -0x10 && y < 0xd0 && func_0207a84c(i) == 0) {
                    gRaceHudSubScreenKarts->mUnk_000[i] = 1;
                    if (gRaceSetup->mMode == MODE_TIME_ATTACK && gRaceSetup->mCurrentEntries[i].mPlayer.mKind == 2) {
                        gRaceHudSubScreenKarts->mUnk_040[i] = 1;
                    } else {
                        gRaceHudSubScreenKarts->mUnk_040[i] = 0;
                    }
                    GetKartScale(&gRaceHudSubScreenKarts->mUnk_0a0[i], i);
                    if (GetKart(i)->mState != KART_STATE_NORMAL) {
                        gRaceHudSubScreenKarts->mUnk_110[i]++;
                        gRaceHudSubScreenKarts->mUnk_100[i] = (gRaceHudSubScreenKarts->mUnk_110[i] << 12) % 0x10000;
                    } else {
                        gRaceHudSubScreenKarts->mUnk_100[i] = 0;
                        gRaceHudSubScreenKarts->mUnk_110[i] = 0;
                    }
                }
            }
            break;
        case 1:
        case 2:
        case 3:
            gRaceHudSubScreenKarts->mUnk_190->mCellCount = 0;
            for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
                GetKartPos(&v, i & 0xff);
                ComputeRaceHudSubScreenKartPosition(i, &gRaceHudSubScreenKarts->mUnk_060[i], a);
                x = gRaceHudSubScreenKarts->mUnk_060[i].mUnk_00;
                y = gRaceHudSubScreenKarts->mUnk_060[i].mUnk_04;
                if (x > -0x10 && x < 0x110 && y > -0x10 && y < 0xd0 && func_0207a84c(i) == 0) {
                    gRaceHudSubScreenKarts->mUnk_000[i] = 1;
                    gRaceHudSubScreenKarts->mUnk_040[i] = func_020b4dc4(i);
                    GetKartScale(&gRaceHudSubScreenKarts->mUnk_0a0[i], i);
                    if (GetKart(i)->mState != KART_STATE_NORMAL) {
                        gRaceHudSubScreenKarts->mUnk_110[i]++;
                        gRaceHudSubScreenKarts->mUnk_100[i] = (gRaceHudSubScreenKarts->mUnk_110[i] << 12) % 0x10000;
                    } else {
                        gRaceHudSubScreenKarts->mUnk_100[i] = 0;
                        gRaceHudSubScreenKarts->mUnk_110[i] = 0;
                    }
                    gRaceHudSubScreenKarts->mUnk_150[i] = func_020b4e70(&v) != 0 ? 2 : 3;
                    s = &gKartItems[i].mItemInUse;
                    v2 = s->mObjects;
                    v3 = s->mObjectCount;
                    m = gRaceHudSubScreenKarts->mUnk_190->mCellCount;
                    b = func_020c0db0();
                    for (j = 0; j < v3; j++) {
                        o = v2[j];
                        if ((o->mFlags & 0x80000) != 0) {
                            q = NULL;
                        } else {
                            q = &o->mPos;
                        }
                        f = func_020f91e0(o);
                        if (q != NULL && f != 0) {
                            func_020b4f64(&t, &v, q);
                            w = t;
                            if (ComputeRaceHudSubScreenPosition(
                                    &w, &gRaceHudSubScreenKarts->mUnk_190->mCells[m].mDrawPos, b, 0, 1) != FALSE) {
                                switch (o->mKind) {
                                    case 0:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[m].mCell = GetRaceSNcerEntry(0x4c);
                                        break;
                                    case 1:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[m].mCell = GetRaceSNcerEntry(0x4d);
                                        break;
                                    case 2:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[m].mCell = GetRaceSNcerEntry(0x4b);
                                        break;
                                    case 5:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[m].mCell = GetRaceSNcerEntry(0x56);
                                        break;
                                    case 9:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[m].mCell = GetRaceSNcerEntry(0x55);
                                        break;
                                    case 7:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[m].mCell = GetRaceSNcerEntry(0x54);
                                        break;
                                    case 8:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[m].mCell = GetRaceSNcerEntry(0x4e);
                                        break;
                                    default:
                                        gRaceHudSubScreenKarts->mUnk_190->mCells[m].mCell = GetRaceSNcerEntry(0x4c);
                                        break;
                                }
                                gRaceHudSubScreenKarts->mUnk_190->mCells[m].mUnk_0c = func_020b4e70(&w) != 0 ? 2 : 3;
                                gRaceHudSubScreenKarts->mUnk_190->mCells[m].mUnk_0e =
                                    (o->mFlags & 0x40000) != 0 ? 1 : 0;
                                m++;
                            }
                        }
                    }
                    gRaceHudSubScreenKarts->mUnk_190->mCellCount = m;
                }
            }
            break;
    }
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        if (GetKartItemEffect(i) == 1) {
            gRaceHudSubScreenKarts->mUnk_170[i]++;
        } else {
            gRaceHudSubScreenKarts->mUnk_170[i] = 0;
        }
        if (i != GetFollowedKartOrEntryIndex() && (GetKart(i)->mUnk_7c & 0x402000) != 0) {
            gRaceHudSubScreenKarts->mUnk_020[i] = 1;
        } else {
            gRaceHudSubScreenKarts->mUnk_020[i] = 0;
        }
    }
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        if (gRaceHudSubScreenKarts->mUnk_040[i] == 0) {
            v1[i] -= 0x20;
        }
        if (i == GetFollowedKartOrEntryIndex()) {
            v1[i] -= 0x10;
        }
    }
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        return;
    }
    SortIndicesByKey(gRaceHudSubScreenKarts->mUnk_130, v1, gRaceSetup->mKartCount);
}

static inline void func_020c8dbc_inline(Unk020c06c4 *p, Unk020224e0_c *c, s32 *r, s32 x, s32 y, u16 v, s32 s, s32 g) {
    s32 q[2];
    s32 e;
    Unk020c06c4_08 *t;

    e = p->mUnk_400;
    q[0] = x << 12;
    q[1] = y << 12;
    t = &p->mUnk_000.mUnk_00[e];
    p->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) t, 0x80 - e, c, r, q, v, 1);
    for (; e < p->mUnk_400; e++) {
        if (s != -1) {
            t->mUnk_0a = s;
        }
        if (g != -1) {
            t->mUnk_0e = g;
        }
        t++;
    }
}

static inline void func_020c8dbc_inline2(Unk020c06c4 *p, Unk020224e0_c *c, s32 x, s32 y) {
    s32 q[2];
    s32 e;

    q[0] = x << 12;
    q[1] = y << 12;
    e = p->mUnk_400;
    p->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &p->mUnk_000.mUnk_00[e], 0x80 - e, c, NULL, q, 0, 1);
}

static inline void func_020c8dbc_inline3(Unk020c06c4 *p, s32 i, s32 h) {
    s32 j;
    s32 x;
    s32 v3;
    s32 v4;
    Unk020224e0_c *c;

    for (j = 0; j < 3; j++) {
        x = (u16) (((h + 12 - j * 4) << 16) / 64) >> 4;
        v3 = (s16) gPairsByAngle[x * 2 + 1] * 11 >> 12;
        v4 = (s16) gPairsByAngle[x * 2] * 11 >> 12;
        c = GetRaceSNcerEntry(h % 12 < 6 ? 93 + j * 2 : 94 + j * 2);
        func_020c8dbc_inline2(p, c, gRaceHudSubScreenKarts->mUnk_060[i].mUnk_00 + v3,
                              gRaceHudSubScreenKarts->mUnk_060[i].mUnk_04 + v4);
    }
}

void DrawRaceHudSubScreenKarts(Unk020c06c4 *p) {
    s32 i;
    s32 f;
    Unk020224e0_c *c;
    s32 r0[4];
    s32 r1[4];
    s32 k;
    s32 g;
    s32 b;
    u16 v1;
    u16 v5;
    s32 a;
    u16 n;
    s32 v6;
    s32 v7;

    switch (GetRaceHudSubScreenState()) {
        case 0:
            for (k = 0; k < gRaceSetup->mKartCount; k++) {
                i = gRaceHudSubScreenKarts->mUnk_130[k];
                if (gRaceHudSubScreenKarts->mUnk_000[i] != 0) {
                    f = gRaceHudSubScreenKarts->mUnk_040[i];
                    if (gRaceHudSubScreenKarts->mUnk_020[i] == 0) {
                        if (gRaceHudSubScreenKarts->mUnk_0a0[i].y != 0x1000 ||
                            gRaceHudSubScreenKarts->mUnk_110[i] != 0) {
                            v1 = func_020ae5c4(p);
                            Matrix2x2RotationReciprocalScale(r0, gRaceHudSubScreenKarts->mUnk_0a0[i].y,
                                                             gRaceHudSubScreenKarts->mUnk_100[i]);
                            if (GetKartItemEffect((u16) i) == 3) {
                                c = GetRaceSNcerEntry(0x10);
                            } else {
                                c = GetRaceSNcerEntry(i);
                            }
                            func_020c8dbc_inline(p, c, r0, gRaceHudSubScreenKarts->mUnk_060[i].mUnk_00,
                                                 gRaceHudSubScreenKarts->mUnk_060[i].mUnk_04, v1, f != 0 ? 1 : -1, -1);
                            p->mUnk_000.mUnk_20[v1].mUnk_06 = r0[0] >> 4;
                            p->mUnk_000.mUnk_20[v1].mUnk_0e = r0[1] >> 4;
                            p->mUnk_000.mUnk_20[v1].mUnk_16 = r0[2] >> 4;
                            p->mUnk_000.mUnk_20[v1].mUnk_1e = r0[3] >> 4;
                        } else {
                            if (GetKartItemEffect((u16) i) == 3) {
                                c = GetRaceSNcerEntry(0x10);
                            } else {
                                c = GetRaceSNcerEntry(i);
                            }
                            func_020c8dbc_inline(p, c, NULL, gRaceHudSubScreenKarts->mUnk_060[i].mUnk_00,
                                                 gRaceHudSubScreenKarts->mUnk_060[i].mUnk_04, 0, f != 0 ? 1 : -1, -1);
                        }
                    }
                    if (gRaceHudSubScreenKarts->mUnk_170[i] != 0) {
                        func_020c8dbc_inline3(p, i, gRaceHudSubScreenKarts->mUnk_170[i]);
                    }
                }
            }
            break;
        case 1:
        case 2:
        case 3:
            a = func_020c0dc4();
            for (k = 0; k < gRaceSetup->mKartCount; k++) {
                i = gRaceHudSubScreenKarts->mUnk_130[k];
                g = gRaceHudSubScreenKarts->mUnk_150[i];
                if (gRaceHudSubScreenKarts->mUnk_000[i] != 0 && a <= g) {
                    if (gRaceHudSubScreenKarts->mUnk_020[i] == 0) {
                        v6 = gRaceHudSubScreenKarts->mUnk_060[i].mUnk_00;
                        v7 = gRaceHudSubScreenKarts->mUnk_060[i].mUnk_04;
                        b = gRaceHudSubScreenKarts->mUnk_040[i];
                        if (gRaceHudSubScreenKarts->mUnk_0a0[i].y != 0x1000 ||
                            gRaceHudSubScreenKarts->mUnk_110[i] != 0) {
                            n = func_020ae5c4(p);
                            if (gRaceHudSubScreenKarts->mUnk_110[i] != 0) {
                                v5 = gRaceHudSubScreenKarts->mUnk_100[i] + func_020b6368();
                            } else {
                                v5 = 0;
                            }
                            Matrix2x2RotationReciprocalScale(r1, gRaceHudSubScreenKarts->mUnk_0a0[i].y, v5);
                            if (GetKartItemEffect((u16) i) == 3) {
                                c = GetRaceSNcerEntry(0x10);
                            } else {
                                c = GetRaceSNcerEntry(i);
                            }
                            func_020c8dbc_inline(p, c, r1, v6, v7, n, b != 0 ? 1 : -1, g);
                            p->mUnk_000.mUnk_20[n].mUnk_06 = r1[0] >> 4;
                            p->mUnk_000.mUnk_20[n].mUnk_0e = r1[1] >> 4;
                            p->mUnk_000.mUnk_20[n].mUnk_16 = r1[2] >> 4;
                            p->mUnk_000.mUnk_20[n].mUnk_1e = r1[3] >> 4;
                        } else {
                            if (GetKartItemEffect((u16) i) == 3) {
                                c = GetRaceSNcerEntry(0x10);
                            } else {
                                c = GetRaceSNcerEntry(i);
                            }
                            func_020c8dbc_inline(p, c, NULL, v6, v7, 0, b != 0 ? 1 : -1, g);
                        }
                    }
                    if (gRaceHudSubScreenKarts->mUnk_170[i] != 0) {
                        func_020c8dbc_inline3(p, i, gRaceHudSubScreenKarts->mUnk_170[i]);
                    }
                }
            }
            DrawRaceHudSubScreenCells(p, gRaceHudSubScreenKarts->mUnk_190, 0);
            break;
    }
}

BOOL func_020c8d30(void) {
    Unk02100094 *a;
    s32 n;

    a = func_021000d0(0xcd);
    if (a == NULL) {
        return FALSE;
    }
    n = func_02100094(a);
    if (n == 0) {
        return FALSE;
    }
    data_0217b424 = HeapAlloc(GetHeap(func_020364e8()), 0x44);
    data_0217b424->mObjects = func_02100084(a);
    data_0217b424->mUnk_04 = n;
    data_0217b424->mObjectCount = n;
    return TRUE;
}

u32 func_020c8d1c(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b424;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_020c8bdc(void) {
    s32 i;
    u32 a;
    Unk020e1e98 *p;
    s32 s;
    Vec3 *v;
    s32 x;
    s32 y;
    Vec3 w;

    a = func_020c0db0();
    for (i = 0; i < data_0217b424->mObjectCount; i++) {
        p = data_0217b424->mObjects[i];
        s = p->mUnk_000.mExtent.z;
        v = &p->mUnk_000.mPos;
        x = (s64) p->mUnk_000.mMatrix.mUnk_00[2].x * s >> 12;
        y = (s64) p->mUnk_000.mMatrix.mUnk_00[2].z * s >> 12;
        if (gRaceSetup->mMirrorMode != 0) {
            data_0217b424->mAngles[i] = FX_Atan2Idx(-y, x) + 0x8000;
        } else {
            data_0217b424->mAngles[i] = FX_Atan2Idx(y, x);
        }
        ComputeRaceHudSubScreenPosition(v, &data_0217b424->mDrawPositions[i], a, 0, 0);
        w.x = v->x + x;
        w.z = v->z + y;
        ComputeRaceHudSubScreenPosition(&w, &data_0217b424->mUnk_2c[i], a, 0, 0);
    }
}

void func_020c82dc(Unk020c06c4 *p) {
    Unk020224e0_c *c;
    s32 r[4];
    u32 a;
    u16 v1;
    u16 v2;
    u16 v3;
    u16 t;
    s32 x;
    s32 y;
    s32 v4;
    s32 v5;
    s32 v6;
    s32 v7;
    s32 j;
    u16 v8;
    s32 v9;
    s32 v10;
    s32 v11;
    s32 v12;
    s32 v13;
    s32 v14;
    s32 v15;
    u16 v16;
    s32 v17;
    s32 v18;
    s32 v19;
    s32 v20;
    s32 v21;
    s32 v22;
    s32 v23;
    s32 q0[2];
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];
    s32 q5[2];
    s32 q6[2];
    s32 q7[2];
    s32 q8[2];

    a = func_020c0dc4();
    if (data_0217b424->mUnk_04 <= 0) {
        return;
    }
    if (a == 0) {
        if (gRaceSetup->mMirrorMode != 0) {
            t = data_0217b424->mAngles[0] - func_020b6368();
        } else {
            t = data_0217b424->mAngles[0] + func_020b6368();
        }
        v1 = func_020ae5c4(p);
        Matrix2x2Rotation(r, t);
        x = data_0217b424->mUnk_2c[0].mUnk_00;
        y = data_0217b424->mUnk_2c[0].mUnk_04;
        if (x > -32 && x < 288 && y > -32 && y < 224) {
            c = GetRaceSNcerEntry(156);
            q0[0] = x << 12;
            q0[1] = y << 12;
            p->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400],
                                                 0x80 - p->mUnk_400, c, r, q0, v1, 1);
        }
        v4 = data_0217b424->mDrawPositions[0].mUnk_00 - data_0217b424->mUnk_2c[0].mUnk_00;
        v5 = data_0217b424->mDrawPositions[0].mUnk_04 - data_0217b424->mUnk_2c[0].mUnk_04;
        for (j = 0, v6 = 0, v7 = 0; j < 3; j++) {
            x = data_0217b424->mUnk_2c[0].mUnk_00 + (v6 + v4) / 4;
            y = data_0217b424->mUnk_2c[0].mUnk_04 + (v7 + v5) / 4;
            if (x > -32 && x < 288 && y > -32 && y < 224) {
                c = GetRaceSNcerEntry(155);
                q1[0] = x << 12;
                q1[1] = y << 12;
                p->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400],
                                                     0x80 - p->mUnk_400, c, r, q1, v1, 1);
            }
            v6 += v4;
            v7 += v5;
        }
        x = data_0217b424->mDrawPositions[0].mUnk_00;
        y = data_0217b424->mDrawPositions[0].mUnk_04;
        if (x > -32 && x < 288 && y > -32 && y < 224) {
            c = GetRaceSNcerEntry(154);
            q2[0] = x << 12;
            q2[1] = y << 12;
            p->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400],
                                                 0x80 - p->mUnk_400, c, r, q2, v1, 1);
        }
        p->mUnk_000.mUnk_20[v1].mUnk_06 = r[0] >> 4;
        p->mUnk_000.mUnk_20[v1].mUnk_0e = r[1] >> 4;
        p->mUnk_000.mUnk_20[v1].mUnk_16 = r[2] >> 4;
        p->mUnk_000.mUnk_20[v1].mUnk_1e = r[3] >> 4;
    }
    if (data_0217b424->mObjectCount == 3 && a == 0) {
        if (gRaceSetup->mMirrorMode != 0) {
            v8 = data_0217b424->mAngles[2] - func_020b6368();
        } else {
            v8 = data_0217b424->mAngles[2] + func_020b6368();
        }
        v3 = func_020ae5c4(p);
        Matrix2x2Rotation(r, v8);
        v9 = data_0217b424->mUnk_2c[2].mUnk_00;
        v10 = data_0217b424->mUnk_2c[2].mUnk_04;
        if (v9 > -32 && v9 < 288 && v10 > -32 && v10 < 224) {
            c = GetRaceSNcerEntry(156);
            q3[0] = v9 << 12;
            q3[1] = v10 << 12;
            p->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400],
                                                 0x80 - p->mUnk_400, c, r, q3, v3, 1);
        }
        v11 = data_0217b424->mDrawPositions[2].mUnk_00 - data_0217b424->mUnk_2c[2].mUnk_00;
        v12 = data_0217b424->mDrawPositions[2].mUnk_04 - data_0217b424->mUnk_2c[2].mUnk_04;
        for (v15 = 0, v13 = 0, v14 = 0; v15 < 2; v15++) {
            v9 = data_0217b424->mUnk_2c[2].mUnk_00 + (v13 + v11) / 3;
            v10 = data_0217b424->mUnk_2c[2].mUnk_04 + (v14 + v12) / 3;
            if (v9 > -32 && v9 < 288 && v10 > -32 && v10 < 224) {
                c = GetRaceSNcerEntry(155);
                q4[0] = v9 << 12;
                q4[1] = v10 << 12;
                p->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400],
                                                     0x80 - p->mUnk_400, c, r, q4, v3, 1);
            }
            v13 += v11;
            v14 += v12;
        }
        v9 = data_0217b424->mDrawPositions[2].mUnk_00;
        v10 = data_0217b424->mDrawPositions[2].mUnk_04;
        if (v9 > -32 && v9 < 288 && v10 > -32 && v10 < 224) {
            c = GetRaceSNcerEntry(154);
            q5[0] = v9 << 12;
            q5[1] = v10 << 12;
            p->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400],
                                                 0x80 - p->mUnk_400, c, r, q5, v3, 1);
        }
        p->mUnk_000.mUnk_20[v3].mUnk_06 = r[0] >> 4;
        p->mUnk_000.mUnk_20[v3].mUnk_0e = r[1] >> 4;
        p->mUnk_000.mUnk_20[v3].mUnk_16 = r[2] >> 4;
        p->mUnk_000.mUnk_20[v3].mUnk_1e = r[3] >> 4;
    }
    if (gRaceSetup->mMirrorMode != 0) {
        v16 = data_0217b424->mAngles[1] - func_020b6368();
    } else {
        v16 = data_0217b424->mAngles[1] + func_020b6368();
    }
    v2 = func_020ae5c4(p);
    Matrix2x2Rotation(r, v16);
    v17 = data_0217b424->mUnk_2c[1].mUnk_00;
    v18 = data_0217b424->mUnk_2c[1].mUnk_04;
    if (v17 > -16 && v17 < 272 && v18 > -16 && v18 < 208) {
        c = GetRaceSNcerEntry(159);
        q6[0] = v17 << 12;
        q6[1] = v18 << 12;
        p->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c,
                                             r, q6, v2, 1);
    }
    v19 = data_0217b424->mDrawPositions[1].mUnk_00 - data_0217b424->mUnk_2c[1].mUnk_00;
    v20 = data_0217b424->mDrawPositions[1].mUnk_04 - data_0217b424->mUnk_2c[1].mUnk_04;
    for (v23 = 0, v21 = 0, v22 = 0; v23 < 3; v23++) {
        v17 = data_0217b424->mUnk_2c[1].mUnk_00 + (v21 + v19) / 4;
        v18 = data_0217b424->mUnk_2c[1].mUnk_04 + (v22 + v20) / 4;
        if (v17 > -16 && v17 < 272 && v18 > -16 && v18 < 208) {
            c = GetRaceSNcerEntry(158);
            q7[0] = v17 << 12;
            q7[1] = v18 << 12;
            p->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400],
                                                 0x80 - p->mUnk_400, c, r, q7, v2, 1);
        }
        v21 += v19;
        v22 += v20;
    }
    v17 = data_0217b424->mDrawPositions[1].mUnk_00;
    v18 = data_0217b424->mDrawPositions[1].mUnk_04;
    if (v17 > -16 && v17 < 272 && v18 > -16 && v18 < 208) {
        c = GetRaceSNcerEntry(157);
        q8[0] = v17 << 12;
        q8[1] = v18 << 12;
        p->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c,
                                             r, q8, v2, 1);
    }
    p->mUnk_000.mUnk_20[v2].mUnk_06 = r[0] >> 4;
    p->mUnk_000.mUnk_20[v2].mUnk_0e = r[1] >> 4;
    p->mUnk_000.mUnk_20[v2].mUnk_16 = r[2] >> 4;
    p->mUnk_000.mUnk_20[v2].mUnk_1e = r[3] >> 4;
}

BOOL func_020c8254(void) {
    u16 a[3] = {0x19a, 0x195, 0x19c};
    u16 i;
    u16 b;

    for (i = 0; i < 3; i++) {
        b = a[i];
        if (func_021000d0(b) != NULL) {
            return CreateRaceHudSubScreenCells(&data_0217b420, b);
        }
    }
    return FALSE;
}

void func_020c8240(void) {
    ClearRaceHudSubScreenCells(&data_0217b420);
}

void func_020c80cc(void) {
    s32 i;
    s32 n;
    Unk020e1e98 *p;
    Vec3 *v;
    u32 a;
    u16 t;
    u16 w;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b420->mObjectCount; i++) {
        p = (Unk020e1e98 *) data_0217b420->mObjects[i];
        v = &p->mUnk_000.mPos;
        if (ComputeRaceHudSubScreenPosition(&p->mUnk_000.mPos, &data_0217b420->mCells[n].mDrawPos, a, 1, 1) != FALSE) {
            t = p->mUnk_000.mKind;
            w = p->mUnk_000.mAngle;
            switch (t) {
                case 0x19a:
                    data_0217b420->mCells[n].mCell = GetRaceSNcerEntry(p->mUnk_130 + 0x95);
                    break;
                case 0x195:
                    data_0217b420->mCells[n].mCell = GetRaceSNcerEntry(0x93);
                    break;
                case 0x19c:
                    data_0217b420->mCells[n].mCell = GetRaceSNcerEntry(0x94);
                    break;
            }
            data_0217b420->mCells[n].mUnk_0c = func_020b4e70((Vec3 *) &v) != 0 ? 2 : 3;
            data_0217b420->mCells[n].mUnk_10 = w;
            n++;
        }
    }
    data_0217b420->mCellCount = n;
}

void func_020c80b0(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, data_0217b420, 1);
}

s32 CreateRaceHudSubScreenKoopaBlockCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenKoopaBlockCells, 0xca);
}

void ClearRaceHudSubScreenKoopaBlockCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenKoopaBlockCells);
}

void UpdateRaceHudSubScreenKoopaBlockCells(void) {
    s32 i;
    s32 n;
    u32 a;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenKoopaBlockCells->mObjectCount; i++) {
        if (ComputeRaceHudSubScreenPosition(&gRaceHudSubScreenKoopaBlockCells->mObjects[i]->mPos,
                                            &gRaceHudSubScreenKoopaBlockCells->mCells[n].mDrawPos, a, 1, 0) != FALSE) {
            gRaceHudSubScreenKoopaBlockCells->mCells[n].mCell = GetRaceSNcerEntry(0x25);
            gRaceHudSubScreenKoopaBlockCells->mCells[n].mUnk_0c = 2;
            n++;
        }
    }
    gRaceHudSubScreenKoopaBlockCells->mCellCount = n;
}

void DrawRaceHudSubScreenKoopaBlockCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenKoopaBlockCells, 0);
}

s32 CreateRaceHudSubScreenChoropuCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenChoropuCells, 0x199);
}

void ClearRaceHudSubScreenChoropuCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenChoropuCells);
}

void UpdateRaceHudSubScreenChoropuCells(void) {
    s32 i;
    s32 n;
    Unk0217b498_00 *p;
    u32 a;
    s32 v;
    s32 w;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenChoropuCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenChoropuCells->mUnk_0c[i]) != FALSE) {
            p = gRaceHudSubScreenChoropuCells->mObjects[i];
            if (ComputeRaceHudSubScreenPosition(&p->mPos, &gRaceHudSubScreenChoropuCells->mCells[n].mDrawPos, a, 0,
                                                0) != FALSE) {
                v = p->mPos.y - p->mUnk_a8;
                if (v >= -0x9000) {
                    w = v > 0 ? 1 : 0;
                    gRaceHudSubScreenChoropuCells->mCells[n].mCell = GetRaceSNcerEntry(w != 0 ? 0xa7 : 0xa8);
                    gRaceHudSubScreenChoropuCells->mCells[n].mUnk_0c = w != 0 ? 1 : 2;
                    gRaceHudSubScreenChoropuCells->mCells[n + 1].mDrawPos =
                        gRaceHudSubScreenChoropuCells->mCells[n].mDrawPos;
                    gRaceHudSubScreenChoropuCells->mCells[n + 1].mCell = GetRaceSNcerEntry(0xa9);
                    gRaceHudSubScreenChoropuCells->mCells[n + 1].mUnk_0c = 2;
                    n += 2;
                    gRaceHudSubScreenChoropuCells->mCells[n - 2].mDrawPos.mUnk_04 -= v >> 14;
                } else {
                    gRaceHudSubScreenChoropuCells->mCells[n].mCell = GetRaceSNcerEntry(0xa9);
                    gRaceHudSubScreenChoropuCells->mCells[n].mUnk_0c = 2;
                    n++;
                }
            }
        }
    }
    gRaceHudSubScreenChoropuCells->mCellCount = n;
}

void DrawRaceHudSubScreenChoropuCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenChoropuCells, 0);
}

s32 func_020c7d54(void) {
    return CreateRaceHudSubScreenCells(&data_0217b414, 0x19b);
}

void func_020c7d40(void) {
    ClearRaceHudSubScreenCells(&data_0217b414);
}

void func_020c7c54(void) {
    s32 i;
    s32 n;
    Unk0217b498_00 *p;
    u32 a;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b414->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&data_0217b414->mUnk_0c[i]) != FALSE) {
            p = data_0217b414->mObjects[i];
            if ((p->mFlags & 2) == 0) {
                if (ComputeRaceHudSubScreenPosition(&p->mPos, &data_0217b414->mCells[n].mDrawPos, a, 0, 0) != FALSE) {
                    data_0217b414->mCells[n].mCell = GetRaceSNcerEntry(0x89);
                    data_0217b414->mCells[n].mUnk_0c = 2;
                    n++;
                }
            }
        }
    }
    data_0217b414->mCellCount = n;
}

void func_020c7c38(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, data_0217b414, 0);
}

s32 CreateRaceHudSubScreenMoveTreeCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenMoveTreeCells, MAP_OBJECT_KIND_MOVE_TREE);
}

void ClearRaceHudSubScreenMoveTreeCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenMoveTreeCells);
}

void UpdateRaceHudSubScreenMoveTreeCells(void) {
    s32 i;
    s32 n;
    u32 a;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenMoveTreeCells->mObjectCount; i++) {
        if (ComputeRaceHudSubScreenPosition(&gRaceHudSubScreenMoveTreeCells->mObjects[i]->mPos,
                                            &gRaceHudSubScreenMoveTreeCells->mCells[n].mDrawPos, a, 1, 1) != FALSE) {
            gRaceHudSubScreenMoveTreeCells->mCells[n].mCell = GetRaceSNcerEntry(0x8b);
            gRaceHudSubScreenMoveTreeCells->mCells[n].mUnk_0c = 2;
            n++;
        }
    }
    gRaceHudSubScreenMoveTreeCells->mCellCount = n;
}

void DrawRaceHudSubScreenMoveTreeCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenMoveTreeCells, 0);
}

s32 CreateRaceHudSubScreenSmanCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenSmanCells, MAP_OBJECT_KIND_SMAN);
}

void ClearRaceHudSubScreenSmanCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenSmanCells);
}

void UpdateRaceHudSubScreenSmanCells(void) {
    s32 i;
    s32 n;
    Unk0217b498_00 *p;
    u32 a;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenSmanCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenSmanCells->mUnk_0c[i]) != FALSE) {
            p = gRaceHudSubScreenSmanCells->mObjects[i];
            if ((p->mFlags & 1) == 0) {
                if (ComputeRaceHudSubScreenPosition(&p->mPos, &gRaceHudSubScreenSmanCells->mCells[n].mDrawPos, a, 0,
                                                    0) != FALSE) {
                    gRaceHudSubScreenSmanCells->mCells[n].mCell = GetRaceSNcerEntry(0x98);
                    gRaceHudSubScreenSmanCells->mCells[n].mUnk_0c = 2;
                    n++;
                }
            }
        }
    }
    gRaceHudSubScreenSmanCells->mCellCount = n;
}

void DrawRaceHudSubScreenSmanCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenSmanCells, 0);
}

s32 CreateRaceHudSubScreenDossunCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenDossunCells, MAP_OBJECT_KIND_DOSSUN);
}

void ClearRaceHudSubScreenDossunCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenDossunCells);
}

void UpdateRaceHudSubScreenDossunCells(void) {
    s32 i;
    s32 n;
    Unk0217b498_00 *p;
    u32 a;
    s32 t;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenDossunCells->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&gRaceHudSubScreenDossunCells->mUnk_0c[i]) != FALSE) {
            p = gRaceHudSubScreenDossunCells->mObjects[i];
            if (ComputeRaceHudSubScreenPosition(&p->mPos, &gRaceHudSubScreenDossunCells->mCells[n].mDrawPos, a, 0, 0) !=
                FALSE) {
                gRaceHudSubScreenDossunCells->mCells[n].mCell = GetRaceSNcerEntry(0xaf);
                gRaceHudSubScreenDossunCells->mCells[n].mUnk_0c = 1;
                gRaceHudSubScreenDossunCells->mCells[n + 1].mDrawPos =
                    gRaceHudSubScreenDossunCells->mCells[(u32) n].mDrawPos;
                gRaceHudSubScreenDossunCells->mCells[n + 1].mCell = GetRaceSNcerEntry(0xb0);
                gRaceHudSubScreenDossunCells->mCells[n + 1].mUnk_0c = 2;
                n += 2;
                t = func_020db4c4((Dossun *) p) * 16 >> 12;
                gRaceHudSubScreenDossunCells->mCells[n - 2].mDrawPos.mUnk_04 -= t;
            }
        }
    }
    gRaceHudSubScreenDossunCells->mCellCount = n;
}

void DrawRaceHudSubScreenDossunCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenDossunCells, 0);
}

BOOL CreateRaceHudSubScreenWanwanCells(void) {
    u16 a[2] = {0x196, 0x1a5};
    u16 i;
    u16 b;

    for (i = 0; i < 2; i++) {
        b = a[i];
        if (func_021000d0(b) != NULL) {
            return CreateRaceHudSubScreenCells(&gRaceHudSubScreenWanwanCells, b);
        }
    }
    return FALSE;
}

void ClearRaceHudSubScreenWanwanCells(void) {
    ClearRaceHudSubScreenCells(&gRaceHudSubScreenWanwanCells);
}

void UpdateRaceHudSubScreenWanwanCells(void) {
    s32 i;
    s32 n;
    u32 a;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < gRaceHudSubScreenWanwanCells->mObjectCount; i++) {
        if (ComputeRaceHudSubScreenPosition(&gRaceHudSubScreenWanwanCells->mObjects[i]->mPos,
                                            &gRaceHudSubScreenWanwanCells->mCells[n].mDrawPos, a, 1, 0) != FALSE) {
            gRaceHudSubScreenWanwanCells->mCells[n].mCell = GetRaceSNcerEntry(0xac);
            gRaceHudSubScreenWanwanCells->mCells[n].mUnk_0c = 1;
            n++;
        }
    }
    gRaceHudSubScreenWanwanCells->mCellCount = n;
}

void DrawRaceHudSubScreenWanwanCells(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, gRaceHudSubScreenWanwanCells, 0);
}

s32 func_020c7690(void) {
    return CreateRaceHudSubScreenCells(&data_0217b400, 0x12f);
}

void func_020c767c(void) {
    ClearRaceHudSubScreenCells(&data_0217b400);
}

void func_020c756c(void) {
    s32 i;
    s32 n;
    Unk0217b498_00 *p;
    Vec3 *v;
    u32 a;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b400->mObjectCount; i++) {
        if (IsRaceHudSubScreenPairNearCenter(&data_0217b400->mUnk_0c[i]) != FALSE) {
            p = data_0217b400->mObjects[i];
            if ((p->mFlags & 1) == 0) {
                v = &p->mPos;
                if (ComputeRaceHudSubScreenPosition(v, &data_0217b400->mCells[n].mDrawPos, a, 0, 0) != FALSE) {
                    data_0217b400->mCells[n].mCell = GetRaceSNcerEntry(0x8c);
                    data_0217b400->mCells[n].mUnk_0c = func_020b4e70(v) != 0 ? 2 : 3;
                    n++;
                }
            }
        }
    }
    data_0217b400->mCellCount = n;
}

void func_020c7550(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, data_0217b400, 0);
}

s32 func_020c7464(void) {
    u16 a[2] = {0x65, 0xc9};
    u16 i;
    u16 b;
    s32 n;
    s32 m;
    s32 j;

    for (i = 0; i < 2; i++) {
        b = a[i];
        if (func_021000d0(b) != NULL) {
            n = CreateRaceHudSubScreenCells(&data_0217b3fc, b);
            m = 0;
            for (j = 0; j < data_0217b3fc->mObjectCount; j++) {
                s32 v = func_020de9f8((Unk020de6a8 *) data_0217b3fc->mObjects[j]);
                if (v > m) {
                    m = v;
                }
            }
            if (m < 0x3e8000) {
                data_0217b3f8 = 1;
            } else {
                data_0217b3f8 = 0;
            }
            return n;
        }
    }
    return 0;
}
